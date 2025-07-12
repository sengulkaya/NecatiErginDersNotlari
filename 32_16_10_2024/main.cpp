/*

	template<typename T>
	class Myclass{

	};

	template<typename T>
	class Nec{};

	int main()
	{
		Myclass<Nec<int> > mx; // modern C++ öncesinde maximal munch kuralýna takýlýyordu burada tokenizing yapabilmesi için boþluk býrakmamýz gerekirdi
	}

bir sýnýf þablonu artýk bir sýnýf olmuyor 

	template<typename T>
	class Myint{ // class template derleyicinin sýnýf kodu yazmasýný saðlayacak bir kod

	};

	ÖRNEK:
		template<typename T>
		class Myint{
		public:
			Myint(T x);
			Myint& set(T x)
			{
				Myint y; // function template içinde sýnýf ismini yalýn olarak kullandýðýmýz zaman derleyici bunu hangi specialization için instantiation yapýcaksa o tür olarak görüyor
							Myint<T> y; yazmak arasýnda bir fark olmuyor
			}
			T get()const;
		private:
			T mval;
		}

		template<typename T> 
		Myint<T>& Myint<T>::set(T val) // scope resolution operatöründen sonra artýk class scopetayýz gerek parametreyi yazdýðýmýz yer gerek fonksiyonun ana bloðu içinde 
		{
			// yukarýdaki ifadeye göre Myint<T> x; demek Myint x demek aralarýnda hiç bir fark olmuyor

			DÝKKAT:fonksiyonun geri dönüþ deðerinin türünü yazdýðýmýz yerde bu durum geçerli deðil sadece bir istisna var oda ctorlar
				
				template<typename T>
				class Myint{
					public:
						Myint(int);
				};

				template <typename T>
				Myint<T>::Myint(int) // classs scope'a girdiðimizde sýnýfýn ismini yazmakla açýsal parantez içinde template parametresini yazmak arasýnda burda fark var burada açýsal parantezi kullanmamak zorundayýz		
		}

		template<typename T> // SORU: T yerine U kullansaydýk yine ayný anlama gelir miydi HAYIR GEÇERLÝ fonksiyonun tanýmýný yaparken template parametresine 
								verdiðimiz ayný ismi kullanmak zorunda deðiliz ama okunma amacýyla ayný isim kullanýlýyor 
		T Myint<T>::get()const{
			return mval;
		}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CLASS TEMPLATELERDE INHERITANCE
	
	ÖRNEK: sýnýf þablonunu oluþtururken þablon olmayan bir taban sýnýftan kalýtým yoluyla elde edebiliriz
		class Base{};

		template <typename T>
		class Der: public Base{};

	ÖRNEK: þablon olan bir taban sýnýftan kalýtým elde edebiliriz
		template <typename T>
		class Base{};

		class Der: public Base<int>{};

	ÖRNEK:
		template<typename T>
		class Base{};

		template <typename T>
		class Der: public Base<T>{};

		int main()
		{
			Der<int>; // Der'in int açýlýmýnýn taban sýnýfý Base'in int açýlýmý olacak
		}

	ÖRNEK:
		template<typename T>
		class Base{
			public:
				void foo();
		};

		class Der : public Base<int>{
			
			void bar()
			{
				foo(); // geçerli
			}
		};	
		
		Der sýnýfý bir class template olsaydý bu sefer foo fonksiyonunu niteleyerek kullanmamýz gerekirdi

			template<typename T>
			class Base{
				public:
					void foo();
			};

			template<typename T>
			class Der : public Base<T>{ // 

			void bar()
			{
					foo(); // sentaks hatasý foo ismini niteleyerek kullanmalýyýz çünkü T türünün ne olduðu belli deðil Base<T>::foo();
				}
			};
		
	ÖRNEK:class templatelerde nested type'a sahip olabilir
		template<typename T>
		class Myclass{ // Myclass sýnýfý bir þablon olduðu için her instantiate için ayrý bir nested class var  
			public:
				class Nested{}; 
		};

		int main()
		{
			Myclass<int>::Nested
			Myclass<double>::Nested // ikiside farklý türler
		}

	ÖRNEK:sýnýfýn içinde nested type'ý bildirip sýnýfýn dýþýndada tanýmýný yapabiliriz
		template<typename T>
		class Myclass{ 
			public:
				class Nested;
		};

		template<typename T>
		class Myclass<T>::Nested{

		};
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NON-TYPE PARAMETRE
	template<int N>
	class Myclass{}; // bu sýnýf þablonunun bir specializatiton'ý için instantiation yaptýrdýðýmýzda derleyici compile time'da deðeri belli olan int türde bir deðer bekleyecek

	int main()
	{
		Myclass<5>
	}

	ayný sýnýf için farklý türden non-type parametrelerde kullanabilir miyiz? HAYIR SENTAKS HATASI fakat modern C++ ile dile yeni bir özellik eklendi böyle durumlarda 
	auto keywordünü kullanýyoruz 
		template<int N>
		class Myclass{};

		template<long N> // sentaks hatasý
		class Myclass{}; 

		ÖRNEK:
			template<auto N> // hala non-type parameter bu ayrý bir deduction burada auto'yu kullandýðýmýz zaman sýnýf þablonundan bir instantiate oluþturmak istersek
			struct Myclass		deduction olacak template argümaný olarak kullanýlan constant expression ifadenin türü neyse o türden bir deðer kullanmýþ olucaz
			{
				Myclass()
				{
					std::cout << typeid(N).name() << " " << N << '\n';
				}
			};

			int main()
			{
				Myclass<10> m1;
				Myclass<5u> m2;
				Myclass<4.5> m3; // C++20 ile legal hale geldi
			}

			ÇIKTI:
				int 10
				unsigned int 5
				double 4.5

	DÝKKAT:
		template<int N> 
		struct Nec{};

		int main()
		{
			Nec<20> x;
			Nec<19> y; // ikiside birbirinden ayrý sýnýf
			Nec<10 + 5 + 4 +1> z; // ifadesini kullansaydýk bu ifadeninde deðeri 20 olacaðý için ayný olmuþ olur
		}
	
	DÝKKAT:

		template<typename T, T x> // x'in türü burda non-type parameter typename anahtar kelimesini kullanmadýk
		class Myclass {
		public:
			void print() const {
				std::cout << "x = " << x << '\n';
			}
		};

		int main() 
		{
			Myclass<int, 42> obj;
			obj.print(); // x = 42

			Myclass<double, 4.5> obj2;
			obj2.print(); // x = 4.5
		}

	non-type parametrenin türleri
		
		1)tam sayý türleri olabilir
			template <int N>
			class Myclass{};

		2)enum türü olabilir
			enum Color {blue,black,white};
			
			template <Color c>
			class Myclass{};

		3)pointer türü olabilir
			template<int *p>
			class Myclass{};

			DÝKKAT: pointer olmasý durumunda template argümanýna karþýlýk gelecek adresin static ömürlü olmasý gerekiyor
			
				int main()
				{
					static int x = 5; 
					Myclass<&x> m;
				}
		4)referans türü olabilir
			template<int &r>
			class Myclass{};

			int g{};

			int main()
			{
				Myclass<g> m1;
			}

		5)function pointer olabilir
			template<int (*fp)(int)>
			class Myclass {
			public:
				void foo() {
					int x = fp(10);
				}
			};

			int f1(int x){}
			int f2(int x){}

			int main()
			{
				Myclass<f1> m1;

				m1.foo(); // foo fonksiyonu içinde çaðýrýlacak template argümaný olan function pointer'ýn gösterdiði fonksiyon olacak yani template argümanýn non-type parametreye karþýlýk 
							 gelen template argümaný bir free function'ýn adresi olabilir
			}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MEMBER FUNCTION POINTER	

	sýnýflarýn static üye fonksiyonlarýnýn this pointerý yoktu yani gizli parametreleri yok bu yüzden sýnýflarýn static üye fonksiyonlarýný göstericek function 
	pointer türleri bildiðimiz C den gelen function pointer türleri

		class Myclass{
			public:
				static int foo(int);
		};

		int main()
		{
			int (*fptr)(int) = Myclass::foo;

			int x = fptr(20);  
		}

		eðer bu fonksiyon static üye fonksiyon deðilse artýk bu atamayý yapamayýz int (*fptr)(int) = Myclass::foo; bu iki tür arasýnda uyumsuzluk var C de olmayan C++'da olan
		MEMBER FUNCTION DEDÝÐÝMÝZ AYRI BÝR TÜR VAR

	ÖRNEK:
		class Myclass{
			public:
				 int foo(int);
		};

		int main()
		{
			int (Myclass::*fptr)(int) = Myclass::foo;
			Myclass m;

			(m.*fptr)(23); 
		}

	ÖRNEK:non-type parametreler member function pointer türüde olabilirler
		struct Myclass{
			int foo(int);
		};

		template<int (Myclass::*)(int)> 
		class Nec{

		};

		int main()
		{
			Nec<&Myclass::foo> mynec;
		}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
hoca non-type parametrelerde olan soruna deðiniyor
	template<const char* p>
	class Nec{
		public:
			void foo()
			{
				std::cout<<p;
			}
	};

	char s[] = "oguzhan esin"; ; // statik ömürlü olmayan bir diziyi non-type argüman olarak kullanamayýz global scopeta olduðu için her hangi bir sentaks hatasý olmuyor
									ama main içinde tanýmlasaydýk statik ömürlü olmayacaðý için hata verecekti
	int main()
	{
		Nec<s> y;

		y.foo();

		Nec<"necati ergin"> x; // string literalini bu þekilde kullanamayýz
	}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
LEXICOGRAPHICAL COMPARE
	
	2 7 9 3
	2 7 6 6 9

	karþýlýklý olarak her iki kaptaki öðeler karþýlaþtýrýlacak ilk farklý eleman çiftinde küçük olan küçüktür buna göre üsttekinde 9 alttakinde 6 olduðu için üstte ki alttakinden büyük
	STL de bulunan bütün containerlar böyle karþýlaþtýrýlýyor

	ÖRNEK:
		int main()
		{
			std::vector<int> vx(100'00,1);
			std::vector<int> vy(2);

			std::cout<< vx.size() <<'\n';
			std::cout<< vy.size() <<'\n';

			if(vy > vx)
			{
				std::cout<<"doðru \n";
			}
			else
			{
				std::cout<<"yanlis\n";
			}
		}

		container sýnýflarýn operator karþýlaþtýrma fonksiyonlarý lexicographical compare yapýyor 

		ÇIKTI:
			10000
			2
			yanlis

	SORU: öyle bir less fonksiyonu yazacaðýz ki örneðin iki tane dizi için less fonksiyonunu less(a,b) þekilnde çaðýrýrsak lexicographical compare þeklinde true döndürücek
		template <typename T,int N,int M>
		constexpr bool Less(const T(&x)[N], const T(&y)[M])
		{
			for(int i = 0; i< N && i < M; ++i)
			{
				if(x[i] < y[i])
					return true;

				if(y[i] < x[i])
					return false;
			}

			return N < M;
		}

		int main()
		{
			int a[] = { 1, 5, 8};
			int b[] = { 1, 5, 8, 6, 8};

			Less(a,b)
		}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPILICIT SPECIALIZATION(FULL SPECIALIZATION)
	
	belirli bir template argümanlarý için zaten oluþturulmasý gereken specialization'ýn kodunu sana veriyorum diyor intantiate etmek için kod yazmak yerine benim o tür argümanlarý 
	verdiðim kodu kullanacaksýn diyor
	
	template <typename T>
	T getmax(T x,T y)
	{
		return x > y ? x : y;
	}

	int main()
	{
		std::string x = "zeynep";
		std::string y = "fuat";

		std::cout<< getmax(x,y) << '\n'; // zeynep çýktýsý alýnýr

		const char* x = "zeynep";
		const char* y = "fuat";
		
		std::cout<< getmax(x,y) << '\n'; // yazýlarý deðil pointerlarý karþýlaþtýrmýþ oluyoruz çýktý tamamen derleyiciye baðlý 
	
		biz þunu istiyoruz eðer T türü const char* ise primary template'den bir instantiation yapmak yerine bizim verdiðimiz specialzation'ý kullancaksýn diyeceðiz iþte buna 
		EXPLICIT SPECIALIZATITN deniliyor
	}

	template<> // getmax'ýn const char* türü için EXPLICIT SPECIALIZATION kullanýlacak
	conat char* getmax<const char* // buradaki açýsal parantez zorunlu deðil parametrelerden çýkarým yapýlabiliyor>(const char* p1,const char* p2)
	{
		return std::strcmp(p1,p2) > 0 ? p1 : p2; // artýk const char* kullandýðýmýz zaman adresler karþýlaþtýrýlmaz yazýlar karþýlaþtýrýlýr ve doðru çýktýyý alýrýz
	}
	
	bizim verdiðimiz specialization'dan deðilde derleyicinin instantiation yapacaðý ana template'den oluþruulacak specializaiondan bahsediyorsak o template primary template deniliyor
		template <typename T>
		void foo(T){std::cout<<"primary template \n";}

		template<>
		void foo(int){std::cout<<"explicit specialization for foo(int)\n";}
		
		template<>
		void foo(double){std::cout<<"explicit specialization for foo(double)\n";}

		int main()
		{
			foo(34L); // primary template
			foo(3.4); // explicit specialization for foo(double)
		}

	meta function:compile timeda bir tür yada bir deðer hesaplamak için kullanýlan koda meta function deniliyor meta function tipik olarak sýnýflarla gerçekleþtiriliyor

	explicit specialization primary template ile ayný interface'e sahip olmak zorunda deðil
		
		template<typename T>
		struct Myclass{
			Myclass()
			{
				std::cout<<"primary template\n";
			}
			void foo();
		};

		template<>
		struct Myclass<int>{
			Myclass()
			{
				std::cout<<"explicit specialization\n";

			}

			void bar();
			void baz();
		};

		int main()
		{
			Myclass<double> m1;
			m1.foo();
			Myclass<int> m2;

			m2.bar();
			m2.baz();
		}

		ÇIKTI:
			primary template
			explicit specialization

	ÖRNEK:template ile 0 dan 100 e kadar sayý yazdýrmak
		template<int N>
		struct Print : Print<N -1>
		{
			Print()
			{
				std::cout<<N<< ' ' ;
			}
		};

		template<>
		struct Print< -1 > // template specialization ile recursion'u durdurduk
		{ 
		
		};
		
		int main()
		{
			Print<100> x;
		}

	ÖRNEK:explicit specialization'da ve partial specialization'da primary template'in complete type olmasý gerekmiyor

		template<typename>
		class Nec;

		template<>
		class Nec<int>
		{
			public:
				Nec()
				{
					std::cout<<"int spec\n";
				}
		}


		int main()
		{
			Nec<int> x;
			Nec<double> y; // primary template incomplete type olduðu için bu sentaks hatasý 
		}

	ÖRNEK:fonksiyonlarýn explicit specialization'ý olduðunda anlamamýz gereken çok önemli bir yer
		function overload resolution'a her zaman primary template girer
			
			template<typename T>
			void func(T)
			{
				std::cout<<"primary\n"; // SORU: function overload resolution'ý primary template kazanýrsa template parametresi karþýlýðý kullanýlmasý gereken template argümaný
												 örneðin int* olursa derleyici bir instantiaton yapacak bu instantion'ý explicit specialization'dan yapýyor
			}

			template<>
			void func(int*)
			{
				std::cout<<"int*\n";
			}	
			
			template<typename T>
			void func(T*)
			{
				std::cout<<"T*\n";
			}

			int main()
			{
				int* p = nullptr;

				func(p); // burda partial ordering rules kurallarý geçerli buna göre daha spesifik olan parametre kazanacak yani T* çýktýsý alýnýr

			}
		
			SORU: T* ile int* parametreli func fonksiyonlarýnýn yerini deðiþtirirsek ne olur?
				template<typename T>
				void func(T)
				{
					std::cout<<"primary\n"; 
				}

				template<typename T>
				void func(T*)
				{
					std::cout<<"T*\n";
				}

				template<>
				void func(int*)
				{
					std::cout<<"int*\n"; // bu explicit specialization artýk T* parametreli template'in explicit specialization'ý
											function overlaod resolutin T ve T* türleri arasýnda yapýlacak T* kazanacak instantiation'ý explicit specialization'dan yaptýðý için
											int* çýktýsý alýnýr
				}

				int main()
				{
					int* p = nullptr;

					func(p);

				}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
PARTIAL SPECIALIZATION
	tüm template argümanlarý kümesi içinde belirli nitelikteklere sahip türler için verilen specialization ve fonksiyon þablonlarýnda partial specialization yok 
	class templatelerde ve value templatelerde var

	template<typename T>
	struct Myclass{
		Myclass()
		{
			std::cout<<"primary template\n";
		}
	};

	template <typename T> // ayný sayýda parametre olmasýna gerek yok daha fazlada olabilir
	struct Myclass<T*> { // template argümanýnýn bir pointer türü olmasý durumunda partial specialization kullanýlacak
		Myclass()
		{
			std::cout<<"partial specialization\n";

		}
	}; 

	int main()
	{
		Myclass<int>m1;
		Myclass<double>m2;
		Myclass<int* >m3;
		Myclass<int** >m4;
	}
	
	ÇIKTI:
		primary template
		primary template
		partial specialization
		partial specialization

	ÖRNEK:
		template<typename T>
		struct Myclass{
			Myclass()
			{
				std::cout<<"primary template\n";
			}
		};

		template <typename T>
		struct Myclass<T,T>
		{
			Myclass()
			{
				std::cout<<"partial specialization\n";
			}
		};

		int main()
		{
			Myclass<int,double> m1; // primary
			Myclass<double,double> m2; // partial
		}

	ÖRNEK:
		template<typename T>
		struct Myclass{
			Myclass()
			{
				std::cout<<"primary template\n";
			}
		};

		template <typename T>
		struct Myclass<T,int> // 1.template parametresi ne olursa olsun 2.template parametresi int parametreyse partial specialization kullanýlacak 
		{
			Myclass()
			{
				std::cout<<"partial specialization\n";
			}
		};

		int main()
		{
			Myclass<double,long> m1; // primary
			Myclass<double,int> m2; // partial
		}
*/