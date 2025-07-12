/*
exception handling konusundan devam ediyoruz

bir fonksiyonun noexcept ile nitelenmesine raðmen exception fýrlatmasý durumunda terminate fonksiyonu çaðýrýlýr ve program sonlandýrýlýr

	void bar()
	{
		throw std::runtime_error{ "error" };
	}

	void foo()noexcept
	{
		bar();
	}


	int main()
	{
		try
		{
			foo(); // terminate fonksiyonu çaðýrýlýr exception yakalanmaz
		}
		catch (const std::exception&)
		{

		}
	}

bir sýnýfýn destructor'ý default olarak noexcept garantisi verir
	
	class Nec {
	public:
		~Nec()
		{
		 
		}
	};

	int main()
	{
	
		constexpr auto b = noexcept(Nec{}.~Nec()); // TRUE deðeri üretir noexcept operatörünün operandý olan ifade uneveluated context olduðu için böyle bir ifade yazmamýz sorun olmuyor 

	}

dtor exception throw etmemeli yada dtor exception throw ederse exception dýþarý sýzmamalý yani programýn akýþý kesinlikle dtor'dan çýkmamalý

	class Nec {
	public:
		~Nec()
		{
			if(1)
			{
				throw std::runtime_error{ "error from dtor" };
			}
		}
	};

	void myterminate()
	{
		std::cout << "myterminate called\n";
		std::abort();
	}

	int main()
	{
		set_terminate(&myterminate);
		try
		{
			Nec mynec; // mynec için dtor çaðýrýldýðýnda dtor excetpion throw edicek ve terminate fonksiyonu çaðýrýlacak
		}
		catch (const std::exception&)
		{
			std::cout << "exception caught ";
		}
	}

	SORU:dtor neden exception throw etmemeli? ÇÜNKÜ DEFAULT OLARAK NOEXCEPT OLARAK BÝLDÝRÝLÝYOR
		bir exception handle edildiðinde stack unwinding sürecinde bir sýnýfýn herhangi bir kodu excetpion throw ederse terminate çaðýrýlýyor eðer buna müsade edilseydi excetpion throw edildiðinde ve
		exception yakalandýðýnda stack unwinding sýrasýnda nesnelerin dtoru çaðýrýldýktan sonra yine terminate fonksiyonu çaðýrýlacaktý

	move ctor ve move assignment'ýn noexcept olmasý gerekiyor ama move ctor ve move assignment default olarak noexcept deðil
	bütün swap fonksiyonlarýnýn da noexcept olmasý gerekiyor 
	memory de-allocation fonksiyonlarýnýn noexcept olmasý gerekiyor

	hoca noexcept specifier ile ilgili bir kaç yere daha deðiniyor
		1)function overriding
			
			class Base{
				public:
					virtual void foo()noexcept;
			};

			class Der : public Base{
				public:
					virtual void foo()override; // foo fonksiyonu noexcept garantisi vermediði için sentaks hatasý olur
			};

			SORU:tam tersi olsaydý Der sýnýfýnýn foo fonksiyonu noexcept olsaydý Base class'ýn noexcept garantisi olmasaydý ne olurdu?
				Der sýnýfýnýn foo fonksiyonu exception throw etmeme garantisi olurdu ama Base class'ýn foo fonksiyonu için böyle bir garanti olmazdý
			
			class Base{
				public:
					virtual void foo();
			};

			class Der : public Base{
				public:
					virtual void foo()noexcept override; 
			};

		2)function pointers
			modern C++ dan önce function pointerlarda noexcept anahtar kelimesini kullanamýyorduk

			int foo(int);
			int bar(int)noexcept;

			int main()
			{
				int (*fp1)(int)noexcept; = &foo; // fp1 ile yapacaðýmýz fonksiyon çaðrýsýnda exception throw etmeme garantisi vermiþ oluyoruz ama foo fonksiyonu bu garantiyi vermediði için sentaks hatasý
				
				int (*fp2)(int); = &bar; // fp2 noexcept garantisi vermese dahi bu kod geçerli		
			
			}

	SORU:noexcept overloadingte kullanýlýyor mu? 
		HAYIR imzanýn bir parçasý ama overloadingte kullanýlmýyor sentaks hatasý olur
		
		int foo(int);
		int foo(int)noexcept;

	ÖRNEK:N.Jossutis'in kitabýndan hoca örnek veriyor
		class Base{
			public
				virtual void func() noxcept(sizeof(int) < 8); // might throw if sizeof(int) >= 8
				
		};

		class Derived : public Base{
			public:
				void func() noexcept(sizeof(int) < 4 ) override; // might throw if sizeof(int) >= 4
		}

		sizeof(int)'in 8 den küçük olmasý durumunda Base class'ýn noexcept garantisine uyuyor ama türemiþ sýnýfýn noexcept garantisine uymuyor türemiþ sýnýfýn override fonksiyonu 
		Base class'ýn verdiði garantiden daha azýný vermiyor oluyor bu yüzden sentaks hatasý oluyor

	ÖRNEK:generic programlama tarafýnda noexcept garatisi verip vermediðini sýnamaya yarayan çok sayýda meta functionlar var
		meta functionlar compile time'da hesaplama yapan yapýlara deniliyor
		
		#include <type_traits>
			
		1)
			class Myclass{};

			int main()
			{
				constexpr auto b = std::is_nothrow_default_constructible_v<Myclass>; // TRUE deðeri üretilir yani default ctor noexcept 
			}

		2)
			class Myclass{
				public:
					Myclass();
			};

			int main()
			{
				constexpr auto b = std::is_nothrow_default_constructible_v<Myclass>; // FALSE deðeri üretilir yani default ctor noexcept deðil
			}

		3)
			template<typename T>
			void func(T) noexcept(std::is_nothrow_copy_constructible_v<T>) // T türünden bir sýnýfýn copy ctoru exception throw etmeme garantisi veriyorsa 
																			  true deðere sahip olacak ve bu fonksiyon noexcept olacak
			{

			}

		4)

			class Myclass{};

			template<typename T>
			void func(T) noexcept(std::is_nothrow_default_constructible_v<T>) // default ctor derleyici tarafýndan yazýldýðý için default olarak noexcept garantisi oluyor böylelikle 
																				 func fonksiyonu noexcept olacak
			{}

			int main()
			{

				constexpr auto b = noexcept(func(Myclass{})); // TRUE

			}

		5)
			class Myclass{
			public:
				Myclass(const Myclass&)noexcept = default;
			private:
				std::vector<int> mvec;
			};

			int main()
			{
				std::is_nothrow_copy_constructible_v<Myclass>; // TRUE

			}

	her hangi bir þekilde exception gönderilmediði zaman exception handling kodlarýnýn maliyeti zero'ya yakýn

	ÖRNEK:move ctorun noexcept olmasýnýn önemi
		class Nec {
			public:
				Nec() : ms(2'000,'A'){}
				Nec(const Nec& other) : ms{ other.ms } { std::cout << "copy ctor\n"; }
				Nec(Nec&& other) : ms{std::move(other.ms)} {std::cout << "move ctor\n";} // move ctor noexcept olmadýðý için copy ctor çaðýrýlýyor 
				// Nec(Nec&& other) noexcept : ms{ std::move(other.ms) } { std::cout << "noexcept move ctor\n"; } 
		private:
			std::string ms;
		};

		int main()
		{
			using namespace std::chrono;
			using namespace std;
			vector<Nec> vec(100'000);

			auto start = steady_clock::now();

			vec.resize(vec.capacity() + 1);
			auto end = steady_clock::now();

			std::cout << duration<double,milli>(end - start).count() << "ms\n";

		}
		
		ÇIKTI: 229.928ms

		class Nec {
		public:
			Nec() : ms(2'000,'A'){}
			Nec(const Nec& other) : ms{ other.ms } { std::cout << "copy ctor\n"; }
			// Nec(Nec&& other) : ms{std::move(other.ms)} {std::cout << "move ctor\n";} 
			Nec(Nec&& other) noexcept : ms{ std::move(other.ms) } { std::cout << "noexcept move ctor\n"; } // kopyalama yerine taþýma daha iyi olduðu için ve move ctor noexcept olduðu 
			için move ctor çaðýrýlýyor
		private:
			std::string ms;
		};

		int main()
		{
			using namespace std::chrono;
			using namespace std;
			vector<Nec> vec(100'000);

			auto start = steady_clock::now();

			vec.resize(vec.capacity() + 1);
			auto end = steady_clock::now();

			std::cout << duration<double,milli>(end - start).count() << "ms\n";

		}

		ÇIKTI: 60.0461ms

EXCEPTION_PTR
	bazen yakaladýðýmýz bir exceptionu bulunduðu yerde deðilde baþka bir yerde handle etmek istiyoruz bunun için exception_ptr sýnýfýný kullanýyoruz
	poineter like bir sýnýf polimorfik bir pointer gibi davranýyor bu sýnýf türünden bir nesnede bi excetpion nesnesini polimorfik olarak tutabiliyoruz yani exception belirli bir hiyerarþide
	o hiyerarþideki türemiþ sýnýflardan birinde exception_ptr sýnýfý türünden bir nesneyle o exceptionu tutarsak baþka bir contexte dinamik türü koruyabiliyoruz bu sýnýfýn önemi daha çok concurrency tarafýnda 

	void handle_exception(std::exception_ptr eptr)
	{
		try
		{
			if(eptr)
			{
				std::rethrow_exception(eptr);
			}
		}
		catch(const std::exception& ex)
		{
			std::cout<<"exception caught : " << ex.what() << '\n';
		}
	}

	int main()
	{
		std::exception_ptr ep;

		try{
			std::string str{"cengizhan"};
			auto c = str.at(36);
		}
		catch(...)
		{
			ep = std::current_exception(); // exceptionu ep nesnesinde tutuyoruz current exception fonksiyonu hangi hata yakalanmýþsa o hata nesnesini polimorfik oalrak tutan bir exception ptr nesnesi veriyor
			handle_exception(ep);
		}
	}

MÜLAKAT SORUSUNA ÖRNEK:polimorfik exception idiom
	
	class EBase{
		public:
			virtual ~EBase() = default;
			virtual void raise()
			{
				throw *this;
			}
	};

	class Der1: public EBase
	{
		public:
			virtual void raise() override
			{
				throw* this;
			}
	};

	class Der2: public EBase
	{
		public:
			virtual void raise() override
			{
				throw* this;
			}
	};

	void foo(EBase& ex)
	{
		ex.raise(); // hangi sýnýf nesnesini gönderirsek o sýnýf türünden exception gönderir
	}

	int main()
	{
		try
		{
			Der1 der1;
			foo(der1);
		}
		catch(Der1&) { std::cout<<"Der1 caught\n"; }
		catch(Der2&) { std::cout<<"Der2 caught\n"; }
		catch(...){
			std::cout<<"other exception type\n";
		}
	}

MÜLAKAT SORUSUNA ÖRNEK:exception dispatcher

	class NecException{};
	class ErgException{};

	void handle_exception()
	{
		try{
			throw;
		}
		catch(NecException&){}
		catch(ErgException&){}
	}

	void func()
	{
		try{
			
		}
		catch(...)
		{
			handle_exception();
		}
	}	

NESTED EXCEPTION
	bir exceptionu yakalýyoruz fakat yakaladýðýmýz expcetionun kendisiyle birlikte ayrý bir exception göndermek istiyoruz yani daha yukarýdaki katmanlar yakaladýðýmýz expceptiona ve gönderdiðimiz exception
	hakkýnda bilgi sahibi olacaklar
	
		void print_exception(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			try {
				std::rethrow_if_nested(e); // std::exceptionu alýyor ve sarmalanan bir exception varsa onuda yakalýyor
			}
			catch (const std::exception& nested)
			{
				std::cerr << "nested: ";
				print_exception(nested);
			}
		}

		void baz()
		{
			throw std::runtime_error("exception from baz");
		}

		void bar()
		{
			try {
				baz();
			}
			catch (const std::exception&)
			{
				std::throw_with_nested(std::runtime_error("exception from bar")); // göndermek istediðimiz exceptionu argüman olarak geçtik
			}
		}

		void foo()
		{
			try {
				bar();
			}
			catch (const std::exception&)
			{
				std::throw_with_nested(std::runtime_error("exception from foo")); // göndermek istediðimiz exceptionu argüman olarak geçtik
			}
		}

		int main()
		{
			try {
				foo();
			}
			catch (std::exception& e)
			{
				print_exception(e);
			}
		}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
GENERIC PROGRAMMING(türden baðýmsýz programlama) TMP(template meta programmin'de denilebiliyor)
	
	Derleyicinin compile time'da belirli tür yada türlere yönelik kod yazmasý

	C++ kodlarýný 2 kategoriye ayýrabiliriz
		1)derleyicinin derlediði kod
		2)varlýk nedeni derleyiciye kod yazdýrmak olan kod
	
	standart kütüphanenin en önemli akronimi STL(standart template library) standart kütüphanenin kendisi deðil standart kütüphanenin bir bileþeni

	templatelerin belirli kategorileri var
		1)function template
			amacý derleyiciye fonksiyon kodu yazdýrmak olan kod

		2)class template
			derleyiciye sýnýf kodu yazdýran templateler

		3)variable template(C++14 standardýyla eklendi)
			
		4)alias template
			derleyiciye tür eþ ismi bildirimi yaptýran bir template

		5)concept(C++20 standardýyla eklendi)

		concept hariç bu template kategorilerinde template anahtar sözcüðünü kullanýyoruz
	
	derleyicinin compile time'da bir template'den faydalanarak ister function template ister class template olsun compile time'da oluþturduðu varlýðýn kendsine o template'in specialization'ý deniliyor
	
	türkçe olarak specialization'a hoca AÇILIM terimini kullanacaðýný belirtti

	template < //template parameters >(angular bracket -> açýsal parantez)
			
	template parametreleri 3 kategoriye ayrýlýyor
		1)type parameter
			bir türe karþýlýk gelen parametre
				
				std::vector<int> // template type argument yada template argument deniliyor // template parametresine karþýlýk gelen tür derleyicinin yazacaðý kodda int türünü kullanacaðýmýzý 
																							   belirtmiþ oluyoruz

		2)non-type parameter
			türü olmayan bir parametre örneðin bir sabit yada belirli bir türden deðer

				template <int n> // kullanýlacak olan türün direkt olarak türünü yazýyoruz derleyici bizim için bu þablondan bir kod ürettiðinde template non-type parametresi karþýlýðý 
									bu türden bir deðer kullanacak anlamýna geliyor C++20 ile beraber non-type parametrelerde geliþmeler yaþandý
				
				OÐUZHANIN SORUSU: n burda constant expression olmak zorunda mý?
					
					n'in kendisi bir ifade deðil n bir isim hoca burada soruyu þu þekilde deðiþtiriyor: n'e karþýlýk gelen argüman sabit olmak zorunda mý? EVET
					
		3)template parameter
			template parametresinin kendisinin template olmasý

	template<typename T> // buradaki T her hangi bir tür anlamýnda typename yerine class anahtar kelimeside kullanýlabiliyor baþlangýçta class anahtar sözcüðü vardý templatelerde typename anahtar sözcüðünü 
						    kullanmakla class anahtar sözcüðünü kullanmak arasýnda hiç bir fark yok

	typename anahtar sözcüðünün kullanýldýðý baþka bir baðlam daha var hoca ileride deðinecek orada class anahtar sözcüðünü kullanamýyoruz 

	ÖRNEK:
		template <typename T>
		T func(T* x) // T==> türü yerine int kullanýlýrsa geri dönüþ deðeri int fonksiyonun parametresi de int olacak
		{
			T& r = *x; // buradaki T türü int& r

			return r;
		}

		int main()
		{
			int x = 5;
			func<int>(&x);
			
			// func(&x); 
		}
	
	DENÝZÝN SORUSU:T yerine incomplete type kullanabilir miyiz? SADECE BELÝRLÝ BAÐLAMLARDA KULLANABÝLÝYORUZ 

	SORU: madem derleyici bir template koddan bir specialization oluþturuken template'in parametrelere karþýlýk kullanýlan template argümanlarýný bilmek zorunda peki bunu nasýl bilecek?
		
		1)DEDUCTION derleyici koda bakarak template parametresi karþýlýðý hangi argümanýn kullanýlacaðýný söylemesekte koda bakarak derleyici bunun çýkarýmýný yapabiliyor
		
		template<typename T>
		void func(T);

		int main()
		{
			func(345); // belirli kurallar dahilinde derleyici fonksiyona gönderilen argüman olan ifadenin türünün int olduðundan template parametresi karþýlýðý kullanýlacak 
						  template argümanýnýn int türü olmasý gerektiðini anlayacak
		}

		2)EXPLICIT TEMPLATE ARGUMENT olarak derleyiciye bildirilmesi
			T func(T* x) 
			{
				T& r = *x; // buradaki T türü int& r

				return r;
			}

			int main()
			{
				int x = 5;
				func<int>(&x);
			}

		modern C++ ÝLE ÖZELÝKLE 17 STANDADARDIYLA devrimsel bir deðiþiklik oldu 17 stadnardýntan önce deductrion mekanizmasý sadece function templateleri için mümkündü
		CTAD(class template argument deduction) belirli sýnýrlar dahilinde sýnýf þablnolarýnda template paremetrelrine karþýþýk gelen temaplte argümanlarýnýn çýkarýmýnýn yapýlmasý
		olanaðý kazandýrýldý

		3)DEFAULT TEMPLATE ARGUMENT

			template parametreleeinden biri yada birden fazlasacý için default template argument belirlenebiliyor explicit olarak templat parametrelerine karþýlýk gelen argümanlarý
			yazmasakta derleyici template bildirimine bakarak hangi argümanlarýn default argument olarak kullanýlacaðýný belirlemiþ oluyor
*/