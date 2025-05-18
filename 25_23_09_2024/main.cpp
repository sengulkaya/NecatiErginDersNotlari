/*

VIRTUAL FUNCTION TABLE POINTER(virtual pointer)
	sınıf polimorfik hale gelince derleyici taban sınıf nesnesi içine bir pointer gömüyor bir önceki derste fonksiyonları virtual yaptığımızda sınıfın sizeof değerinin
	artması bu yüzden oluyor

	derleyicinin ürettiği kodla programın çalışma zamanında kalıtım hiyerarşisindeki her sınıf için run time da bir veri yapısı oluşturuyor bu veri yapısana virtual function table pointer deniliyor

	her sınıf için bir sanal fonksiyon tablosu var sanal fonksiyon tablosu indexle fonksiyon adreslerine erişebileceğimiz bir veri yapısı(görseli inceleyiniz)
	görselde dikkat etmemiz gereken nokta her farklı vtable da aynı indekste aynı fonksiyonların bulunması
	
	derleyici run time'da oluşturulacak sanal fonksiyon tablosunun örneğin 1.indeksinde hangi sınıf olursa olsun run fonksiyonunun override'ının adresinin olacağını biliyor
	
	her sınıf başına virtual function table pointer var

	polymorphic sınıf nesnesi oluşturulduğunda derleyicinin ürettiği kodda onun taban sınıf nesnesinin içindeki virtual pointer ilgili sınıfın sanal fonksiyonunun adresini tutuyor onunla initialize ediliyor
	Toyota class'ının içindeki taban sınıf nesnesi olan Car nesnesinin içindeki vptr Toyota sınıfının sanal fonksiyon tablosunun adresini tutuyor

	SORU:her sınıf nesnesinin içinde bir vptr var mı? EVET 

	SORU:carptr->run() çağrısı
		
		derleyici isim aramayı compile time'da yapıyor ok operatörünün sağ operandı olan run ismini Car sınıfında compile time'da arıyor Car sınıfı içinde bulduğu run isminin
		virtual functiona ait oldğunu compile time'da anlıyor derleyici run fonksiyonun sanal fonksiyon olduğunu anladığınnda compile time'da indeks elde edebilir 

		derleyici sembolik olarak böyle bir fonksiyon oluşturuyor -> carptr->vptr[idx]() hangi türemiş sınıf nesnesini adresini tutuyor olursa olsun onun içindeki Car nesnesinin adresini tutuyor
		vptr elemanına erişiyor bu adresten sanal fonksiyon tablosunun adresini elde ediyor ve compile time'da elde ettiği indeksi kullanarak o indeksteki fonksiyon adresine erişiyor ve
		o adresteki fonksiyonu çağırıyor
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
VIRTUAL FUNCTION TABLE POINTERIN MALİYETİ
		1)işlemsel maliyet
			2 ilave dereferencing var
				1)sınıf nesnesinin içindeki vptr'a erişmek için bir dereferencing
				2)tablonun belirli indeksindeki fonksiyon adresine erişim

		2)kullanılan bellek alanı(storage)
		
		3)sanal fonksiyon tablolarının oluşturulması maliyeti

		4)her polimorfik nesne için vptr'ın initalize edilmesi maliyeti

		5)büyük çoğunlukla virtual dispatch dinamik ömürlü nesneleri gerektiyor
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
RTTI(RUN TIME TYPE INFORMATION)

		programın çalışma zamanında türün ne olduğunun belirlenmesi

		polimorfik bir nesnenin dinamik türünün ne olduğunu anlayabilmemiz için 2 tane operatör var 
			1)dynamic_cast
			2)typeid 

		void car_game(Car* p)
		{
			// örneğin run time'da buraya gelen nesnesin Mercedes mi yada Renault mu olduğunu sınamamız gerekebilir
		}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
VARIANT RETURN TYPE(covariance)

		Türetilmiş bir sınıfta, bir sanal fonksiyonu override ederken dönüş türü, taban sınıftaki dönüş türünün bir alt türü (türetilmişi) olabilir
		covariance olması için geri dönüş değeri pointer yada referans olmak zorunda

		class Base {
		public:
			virtual Base* foo() { std::cout << "Base::foo()\n"; return this; }
		};

		class Der : public Base{
		public:
			Der* foo() override { std::cout << "Der::foo()\n"; return this; }
		};

		virtual ctor idioamda da covarianca return type kullanılıyor
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
VIRTUAL DESTRUCTOR
		
		Eğer bir nesne, türetilmiş bir sınıfın nesnesi ama base sınıfın pointer'ı ile siliniyorsa destructor'ı virtual değilse türetilmiş sınıfın yıkıcısı çalışmaz
		Bu da Bellek sızıntısına ve kaynak sızıntısına neden olur
		
		sınıfta bir tane bile virtual fonksiyonumuz varsa dtoru virtual yapmamız gerekir
		
		class Base {
		public:
			virtual ~Base() { std::cout << "Base destructor\n"; }
		};

		class Der : public Base {
		public:
			~Der() { std::cout << "Der destructor\n"; }
		};

		int main() {
			Base* ptr = new Der;
			delete ptr;  // Hem Der hem Base destructor çağrılır
		}

		ÇIKTI:
		Der destructor
		Base destructor
		
		ÖRNEK:
			
			class Base {
			public:
				~Base() { std::cout << "Base destructor\n"; }
			};

			class Der : public Base {
			public:
				~Der() { std::cout << "Der destructor\n"; }
			};

			int main() {
				Base* ptr = new Der;
				delete ptr;  // Sadece Base::~Base() çağrılır UNDEFINED BEHAVIOUR
			}
			
			ÇIKTI:
			Base destructor // Der::~Der() çağrılmaz → UB kaynak sızıntısı ve bellek sızıntısı olur.

		virtual dtor kullanmamızı gerektirecek 2 durum var
			1)türemiş sınıf nesnelerini taban sınıf pointeri ile delete edersek kullanmalıyız
				Base* ptr = new Der;
				delete ptr;  

			2)taban sınıf en az bir tane virtual fonksiyon içeriyorsa 
	
		polimorfik taban sınıfların dtoru
			a)ya public virtual olmalı
				yukarıda verilen örnekler gibi
			b)yada protected non-virtual olmalı
				
				taban sınıf pointerı ile türemiş sınıf nesnesini delete etmeyeceksek dtoru protected yapabiliriz
				
				class Base {
				protected:
					~Base() { std::cout << "Base destructor\n"; }
				};

				class Der : public Base {
				public:
					~Der() { std::cout << "Der destructor\n"; }
				};

			int main() {
				// Base* ptr = new Der;
				// delete ptr;  // artık taban sınıf nesnesiyle türemiş sınıf ile delete etmek sentaks hatası olur
					
				Der* derptr = new Der;

				delete derptr; // geçerli çünkü türemiş sınıfın dtoru public ve türemiş sınıf taban sınıfın protected bölümüne erişebiliyor
			}

			ÇIKTI:
			Derived destructor
			Base destructor
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NON VIRTUAL IDIOM(https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface)

		### 📌 **Amacı:**

		Bir sınıf hiyerarşisinin tümünde tekrarlanan kod parçalarını (örn: ön koşul/son koşul kontrolleri, kilit alma/bırakma gibi) **tek bir noktada modülerleştirmek/refactor etmek**.

		### 🔁 **Diğer Adı:**

		* **Template Method** – Bu desen, Gang of Four’un *Design Patterns* kitabında geçen daha genel bir kalıptır.

		### 🧠 **Motivasyon:**

		Geliştirme sırasında **ön koşul ve son koşul kontrolleri** yapmak, nesne yönelimli programlamada oldukça faydalıdır.
		Bunlar, bir sınıf hiyerarşisinin kurallarının (invariant'ların) bozulmadığından emin olmak için kullanılır.
		Örneğin:

		* Sınıfın iç tutarlılığını kontrol etmek
		* Ortak kaynakları güvenli şekilde kullanmak

		Bu tür kontrollerin tüm hiyerarşi boyunca **tutarlı ve merkezi bir noktadan yapılması** bakım ve sürdürülebilirlik açısından önemlidir.

		Aynı şekilde, **bir veri yapısına erişmeden önce kilit almak ve sonra bırakmak** gibi işlemler de bu tür “ön-son koşul” davranışlarıdır ve üretim ortamında bile garanti edilmelidir.

		### 🛠️ **Çözüm – NVI Yöntemi:**

		**NVI (Non-Virtual Interface)** yöntemi, bu ortak işlemleri taban sınıfta merkezi olarak tanımlamak için kullanılır.

		#### 💡 Temel Kurallar (Herb Sutter'dan alıntıyla):

		1. **Sanal olmayan arayüzler tercih edilmelidir.** (Template Method deseni ile)
		2. **Sanal fonksiyonlar private olmalıdır.**
		3. **Eğer türetilmiş sınıflar, taban sınıf fonksiyonlarını çağırmak zorundaysa → `protected` olmalıdır.**
		4. **Taban sınıf yıkıcısı ya `public virtual` ya da `protected non-virtual` olmalıdır.**

		### ✅ **Örnek Kod (NVI Uygulaması):**

		class Base {
		private:
			ReaderWriterLock lock_;
			SomeComplexDataType data_;
		public:
			void read_from(std::istream & i) {  // non-virtual arayüz
				lock_.acquire();
				assert(data_.check_invariants());

				read_from_impl(i);  // sanal çağrı

				assert(data_.check_invariants());
				lock_.release();
			}

			void write_to(std::ostream & o) const {
				lock_.acquire();
				write_to_impl(o);  // sanal çağrı
				lock_.release();
			}

			virtual ~Base() {}  // çünkü sınıf polimorfik
		private:
			virtual void read_from_impl(std::istream&) = 0;
			virtual void write_to_impl(std::ostream&) const = 0;
		};

		### 🧩 **Türetilmiş Sınıf:**

		class XMLReaderWriter : public Base {
		private:
			void read_from_impl(std::istream &) override {
				// XML okuma
			}

			void write_to_impl(std::ostream &) const override {
				// XML yazma
			}
		};

		* Türetilmiş sınıflar sadece `*_impl` fonksiyonlarını override eder.
		* `read_from()` ve `write_to()` sadece taban sınıftan erişilir → **arayüz değişmez**.

		### ✅ **Avantajlar:**

		* Taban sınıf:

		  * **kilit alıp bırakma**, **invariant kontrolü**, **loglama**, **hata işleme** gibi işlemleri kendi içinde yapar.
		
		* Türetilmiş sınıflar:

		  * Sadece özelleştirilecek olan kodu yazar.
		* **Arayüz sabit kalır**, **hata riski azalır**, **bakım kolaylaşır**.

		### ⚠️ **Dikkat: Fragile Base Class Sorunu**

		Eğer taban sınıfın içinde, türetilmiş sınıfın override ettiği fonksiyonları yanlışlıkla çağırırsan:

		* Aynı işlem iki kez yapılabilir.
		* Bu da **hatalara** ve **türetilmiş sınıfın bozulmasına** neden olur.

		**Öneri:**
		➡️ Her public non-virtual fonksiyon sadece \**bir tane virtual extension point (örneğin *\_impl)** çağırmalıdır.

		### 🔄 **IoC (Inversion of Control – Kontrolün Taban Sınıfa Geçmesi)**

		* **NVI bir tür mini framework gibi davranır.**
		* Taban sınıf tüm akışı kontrol eder.
		* Türetilmiş sınıflar sadece gerekli kısmı sağlar.

		### 📌 **Sonuç:**

		* **NVI**, sanal fonksiyonları doğrudan açmak yerine, onları korumalı (private/protected) yapar ve **sanal olmayan bir arayüz sunar**.
		* Bu sayede:

		  * Kod daha güvenli ve tahmin edilebilir olur.
		  * Bakımı kolaylaşır.
		  * Ortak işlemler merkezi bir yerde tutulur.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Global fonksiyonlar virtual yapılamıyor ama bazen global bir fonksiyonu virtual gibi kullanmamız gerekebiliyor

	class Car {
	public:
		virtual ~Car() = default;
		virtual void start() { std::cout << "Car::start()\n"; }
		virtual void run() { std::cout << "Car::run()\n"; }
		virtual void stop() { std::cout << "Car::stop ()\n"; }
		virtual std::ostream& print(std::ostream&) const = 0;
		friend std::ostream& operator<<(std::ostream& os, const Car& c)
		{
			return c.print(os);
		}
	};

	class Volvo : public Car {
	public:
		void start() override { std::cout << "Volvo::start()\n"; }
		void run() override { std::cout << "Volvo::run()\n"; }
		void stop()override { std::cout << "Volvo::stop ()\n"; }
		std::ostream& print(std::ostream& os) const override {
			return os << "I am a Volvo";
		}
	};

	class Renault : public Car {
	public:
		void start() override { std::cout << "Renault::start()\n"; }
		void run() override { std::cout << "Renault::run()\n"; }
		void stop() override { std::cout << "Renault::stop ()\n"; }
		std::ostream& print(std::ostream& os) const override {
			return os << "I am a Renault";
		}
	};

	class Mercedes : public Car {
	public:
		void start() override { std::cout << "Mercedes::start()\n"; }
		void run() override { std::cout << "Mercedes::run()\n"; }
		void stop()override { std::cout << "Mercedes::stop ()\n"; }
		std::ostream& print(std::ostream& os) const override {
			return os << "I am a Mercedes";
		}
	};
	Car* create_random_car()
	{
		static std::mt19937 eng;
		static std::uniform_int_distribution dist{0,2};

		switch (dist(eng))
		{
		case 0:  return new Volvo;
		case 1:  return new Renault;
		case 2:  return new Mercedes;
		default: return nullptr;
			break;
		}
	}

	void car_game(Car& c)

	{
		c.start();
		c.run();
		c.stop();
	}

	int main()
	{

		for (int i = 0; i < 10; ++i)
		{
			Car* p = create_random_car(); 
			std::cout << *p << '\n'; // hangi sınıfın fonksiyonunun çağırıldığı run time'da belli olur
			p->start(); 
			p->run();
			delete p;
			(void)getchar;
		}
	}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
FINAL CONTEXTUAL KEYWORD
	2 farklı şekilde kullanılıyor

	1)Bir sınıfın final class yapılması(FINAL CLASS)
		class Nec final { } // bu sınıftan kalıtım yapılmayacak demiş oluyoruz taban sınıf olamaz

	2)Bir polimorfik sınıfın sanal fonksiyonunun final yapılması(FINAL OVERRIDE)
		taban sınıfın sanal fonksiyonunu override ediyoruz ama o classtan kalıtım alan sınıflar benim override fonksiyonumu kullanacaklar demiş oluyoruz  

		class Base{
			public:
				virtual void foo();
		};

		class Der: public Base{
		public:
			void foo() final override;
			
			override ve final yazımı bu şekildede olabilir
				// void foo() override final; 
			ama const olsaydı imzanın parçası olduğu için const başta olması gerek
				// void foo() const override final;

		}

		class Sder : public Der {
			public:
				// void foo() override; // Sder sınıfı foo fonksiyonunu override edemez
				cannot override 'final' function "Der::foo"
		};
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
PRIVATE INHERITANCE(daha çok has-a-relationship ile ilgili is-a-relationship sadece türemiş sınıfların üye fonksiyonlarına ve türemiş sınıfların friendlerine var)

	taban sınıfın public memberları türemiş sınıfın private bölümüne ekleniyor

	class Car {
	public:
		void foo_public();
	protected:
		void bar_protected();
	private:
		void bom_private();
	};

	class Mercedes : private Car {
	public:
		void der_func() 
		{
			foo_public(); // geçerli taban sınıfın foo_public fonksiyonunu çağırabilir çünkü foo_public fonksiyonu Mercedes sınıfınıın private elemanıymış gibi ele alınacak
			bar_protected(); // geçerli
			// bom_private(); // sentaks hatası bütün kalıtım biçimlerinde taban sınıfın private bölümü kapalı
		}
	};


	int main()
	{
		Mercedes m;

		m.foo_public(); // sentaks hatası çünkü Base sınıfının public bölümü Mercedes sınıfının private bölümüne ekleniyor yani foo_public() fonksiyonu
		artık Mercedes sınıfının private bölümünde olmuş oluyor
	}

	private kalıtımda clientlar için artık is-a-relationship ilişkisi yok 

		int main()
		{
			Mercedes m;
			Car* car = &m; // geçersiz
		}

	DİKKAT:ama türemiş sınıfın üye fonksiyonları için hala is-a-relationship var

		class Mercedes : private Car {
	public:
		void mercedes_func() 
		{
			Mercedes m;
			Car* car = &m; // geçerli is-a-relationship türemiş sınıfların üye fonksiyonlarına ve türemiş sınıfların friendlerine var 
		}					  yani türemiş sınıfın fonksiyonları içinde ve friendleri içinde her Mercedes bir Car olmaya devam ediyor UP CASTING olabiliyor 

		friend void gf(); // global function
	};


	void gf()
	{
		Mercedes m;
		Car* car = &m; // geçerli
	}

	PRIVATE KALITIMININ KULLANILDIĞI SENARYOLAR

		1)türemiş sınıfın fonksiyonlarının içinde ve friendlerinin içinde UP CASTING'den faydalanmak istememiz
		2)C++20 ile talep azalmış olsada EMPTY BASE OPTIMIZATION içinde kullanılıyor

		private kalıtımı composition'a alternatif olarak kullanılıyor private kalıtımı yapmakla composition yapmak arasında bazı farklılıklar var

			1)compositionda UP CASTINGDEN faydalanamamak
				class Car {};
				class Mercedes {
				private:
					Car c;
				};

				int main()
				{
					Mercedes m;
					Car* c = &m; // geçersiz
				}
			2)compositionda virtual fonksiyonları override edememek

				class Car {
				public:
					virtual void foo();
				};

				class Mercedes {
				public:
					void foo() override; // geçersiz
				private:
					Car c;
				};

			3)compositionda member'ın protected elemanlarını kullanamıyoruz

				class Car {
				protected:
					void foo();
				};

				class Mercedes {
				public:
					void start()
					{
						c.foo(); // geçersiz
					}
				private:
					Car c;
				};

	ÖRNEK:

		class Base{
			public:
				void foo();
		};

		class Der : private Base{
			void derfoo()
			{
				foo();
			}
		};

		class SDer : public Der{
			void bar()
			{
				foo(); // geçersiz çünkü foo fonksiyonu artık Der'in private fonksiyonu olarak ele alınıyor
			} function "Base::foo" is inaccessible

		};

	multi level inheritance olmadığı sürece private ve protected kalıtımı arasında hiç bir fark yok
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EMPTY BASE OPTIMIZATION(EBO)https://en.cppreference.com/w/cpp/language/ebo
		Empty Base Optimization, boş sınıfların base class olarak kullanıldığında nesne boyutunu artırmamasına olanak tanır.
		 Bu optimizasyon, **bellek verimliliği sağlar
		
		bir nesnenin ya da bir veri üyesi alt nesnesinin türü boş bir sınıf (yani, hiçbir non-static veri üyesi olmayan bir `class` ya da `struct`) olsa bile, 
		bu nesnenin boyutu en az 1 olmalıdır**.Bu kural, **aynı türden iki nesnenin adreslerinin birbirinden farklı olmasını garanti etmek** içindir.

		Ancak bu kural, base class alt nesneleri için geçerli değildir. Dolayısıyla derleyici, bir nesnenin içine gömülü boş bir base class’ı tamamen optimize ederek yer 
		kaplamamasını sağlayabilir.

		struct Base {}; // boş sınıf

		struct Derived1 : Base {
			int i;
		};

		int main() {
			static_assert(sizeof(Base) >= 1);            // Boş sınıf bile olsa boyut ≥ 1
			static_assert(sizeof(Derived1) == sizeof(int));  // EBO uygulandı → sadece int kadar yer kaplar
		}
			Ne zaman EBO uygulanmaz?

				Eğer Boş bir base class,Aynı zamanda ilk non-static veri üyesinin türüyle aynı türse veya onun base class’ıysa, o zaman EBO uygulanamaz. Çünkü bir nesne içinde aynı türden 
				iki base alt nesneye sahip olamazsın. Derleyici, her alt nesnenin adresini ayırt edebilmek zorundadır.

					struct Base {};

					struct Derived2 : Base {
						Base c; // base class ile aynı türde veri üyesi → EBO olmaz
						int i;
					};

					struct Derived3 : Base {
						Derived1 c; // Derived1 zaten Base'ten türemiş → çakışma
						int i;
					};

					int main() {
						static_assert(sizeof(Derived2) == 2 * sizeof(int));  // EBO uygulanmaz → 2 int boyutu olur
						static_assert(sizeof(Derived3) == 3 * sizeof(int));  // EBO uygulanmaz → 3 int boyutu olur
					}

			Standard Layout Kısıtlamaları (C++11):

				Tüm non-static veri üyeleri aynı sınıf içinde tanımlanmalı (yani ya hepsi base class’ta ya da hepsi türetilmiş sınıfta),
				Ve ilk veri üyesiyle aynı türde bir base class bulunmamalıdır.

				Bu kurallar, `reinterpret_cast` ile yapılan dönüşümlerde doğru çalışmayı sağlamak için konmuştur.

				C++20 ile Gelen Özellik – [[no_unique_address]]

				[[no_unique_address]]` özniteliği sayesinde, **boş veri üyeleri de (yalnızca base değil) optimize edilebilir.
				Böylece onların adresleri, aynı nesnedeki başka veri üyeleriyle **çakışabilir.

				struct Empty {};

				struct X {
					int i;
					[[no_unique_address]] Empty e;
				};

				int main() {
					static_assert(sizeof(Empty) >= 1);   // hâlâ ≥ 1
					static_assert(sizeof(X) == sizeof(int));  // Empty optimize edildi
				}

		MSVC Notu:

			Microsoft’un derleyicisi (MSVC), **Empty Base Optimization konusunda C++ standardına tamamen uyumlu değildir.**
			Yani bazı durumlarda EBO MSVC’de **uygulanmayabilir.**
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
POLİMORFİK LİSTELER

	farklı türden nesneleri ortak bir interface'e sahip olduğunu bilerek onları aynı türdenmiş gibi bir containerda tutmak

	int main()
	{
		std::vector<Car*> carvec;

		for (int i = 0; i < 50; ++i)
		{
			carvec.push_back(create_random_car());
		}
		for (auto cp : carvec)
		{
			std::cout << *cp<<'\n';
			cp->start();
			cp->run();
			cp->stop();
		}
		for (auto car : carvec)
			delete car;
	}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
RESTRICTED POLYMORPHISM(kısıtlı polimorfizm)
	
	fonksiyonlardan seçtiğimiz özel fonksiyonlara polimorfizimden faydalanma olanağı vermek istiyoruz ama tüm fonksiyonlara değil

	class Base{
		public:
			virtual void vfunc();
	};

	class Der : private Base{ // private kalıtımı olduğu için sadece sınıfın üye fonksiyonları içinde ve friend fonksiyonları içinde is-a-relationship var
		public:
			void vfunc() override;
			friend void f1(); // f1 fonksiyonu polimorfizimden faydalanıyor
	};

	void foo(Base& baseref)
	{
		baseref.vfunc();
	}

	void f1()
	{
		Der myder;
		foo(myder); // is-a-relationship'ten yararlanabiliyor ve UP CASTING oluyor
	}

	void f2() // f2 fonksiyonu polimorfizimden faydalanamıyor
	{
		Der myder;
		foo(myder); // sentaks hatası
	}
*/