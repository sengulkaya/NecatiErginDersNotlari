/*

templatelerden devam ediyoruz

ÖRNEK:

	template<long long N>
	constexpr long long factorial()
	{
		return N * factorial<N - 1>();
	}

	template<>
	constexpr long long factorial<0>() // recursive çaðrýyý durduracak olan explicit specialization
	{
		return 1;
	}

	int main()
	{
		factorial<5>();
	}

ÖRNEK:
	
	template<typename T>
	struct Myclass{
		
		template<typename U>
		void func(U)
		{
			std::cout<<"type T is" << typeid(T).name() << '\n';
			std::cout<<"type U is" << typeid(U).name() << '\n';
		}
	};

	int main()
	{
		Myclass<double> x;
		x.func(34);
	}
		ÇIKTI:
			type T is double
			type U is int

ÖRNEK:
	template<typename T>
	struct Myclass{

		template<typename U>
		void func(U)
		{
			std::cout<<"type T is " << typeid(T).name() << '\n';
			std::cout<<"type U is " << typeid(U).name() << '\n';
		}
	};

	template<>
	template<> // template'in member template'i için bir explicit specialization olduðunu derleyici anlayacak
	void Myclass<double>::func(int)
	{
		std::cout<<"explicit specialization\n";
	}

	int main()
	{
		Myclass<double> x;
		x.func(34);
	}

		ÇIKTI:
			explicit specialization
			type T is int
			type U is int

PARTIAL SPECIZALIZATION

	fonksiyon þablonlarýnda kullanýlmýyordu

	template parametrelerine karþýlýk gelen türler için kullanýlýyor

	ÖRNEK:
		template <typename T>
		struct Myclass{

		};

		template<typename T> // burada bulunan template parametre sayýsý deðiþebilir AMA AÇISAL PARANTEZ içine yazdýðýmýz template argüman(Myclass<T*>) sayýsý primary template'de
								bulunan argüman sayýsýyla ayný olmak zorunda
		struct Myclass<T*> { // template argüman olarak pointer türü kullanýlýrsa bu kod kullanýlacak ve interface'in primary tempalate ile ayný olmasý gerekmiyor

		};

	ÖRNEK:
		template <typename T,int N>
		struct Nec{
			Nec()
			{
				std::cout<<"primary template\n";
			}
		};

		template <typename T, typename U, int N>
		struct Nec <std::pair<T, U>, N>
		{
			Nec()
			{
				std::cout << "partial template\n";
			}

		};

		int main()
		{
			Nec<std::pair<int, long>, 5> m1;
		}

	ÖRNEK:
		template <typename T,int N>
		struct Nec{
			Nec()
			{
				std::cout<<"primary template\n";
			}
		};

		template <typename T>
		struct Nec<T,3>{
			Nec()
			{
				std::cout<<"partial specialization Nec<T,3>\n";
			}
		};

		int main()
		{
			Nec<double,5> n1;
			Nec<int,3> n2;
			Nec<long,67> n3;
		}	

			ÇIKTI:
				primary template
				partial specialization Nec<T,3>
				primary template


	tpyename anahtar sözcüðünün kullanýldýðý bir context daha var bu contexte typename anahtar sözcüðünün yerine class anahtar sözcüðünü kullanamýyoruz
	
		template<typename T>
		void foo(const T& t)
		{
			T::size_type* p(T::npos); // böyle isimlere dependent name deniliyor öyle bir isim ki template parametresine baðlý dependent name'in namelookup kurallarýyla
										 dependent olmayanlarýn namelookup kurallarý farklý yakýnda göreceðiz 
			

			bar(); // sentaks hatasý olurdu çünkü derleyici bar her hangi bir þekilde template parametresine baðlý bir isim olamdýðý için template'in üstünden ilk kez geçtiðinde 
						bar ismini arýyor ve bulamadýðý için isim arama hatasý oluyor

			T::value_type x; // bu durumda value_type identifier fakat bu template parametresine baðlý value_type'ýn ne olduðu T yerine kullanýlacak template aegümanýnýn ne olduðuna baðlý 
	
			dependent type'dan bahsediyorsak size_type bir türse nested type ise derleyicinin bunu nested type olarak almasý için typename anahtar sözcüðünü kullanýyoruz eðer typename
			anahtar sözcüðünü kullanmazsak derleyici bunu expression olarak ele alýyor

				typename T::size_type

				ÖRNEK:
					
					template<typename T>
					void foo(const T&)
					{
						typename T::size_type x; // template kodda template parametresinew baðlý bir türden bahsediyorsak kodun ifade olarak deðilde derleyici tarafýndan 
													bir tür olarak ele alýnmasý için typename anahtar sözcüðünü kullanýyoruz
					}

					struct A{
						using size_type = int;
					};

					int main()
					{
						A ax;

						foo(ax); // typename anahtar kelimesinin kullanmasaydýk hata verecekti 
					}

				ÖRNEK: C++20 ile bu kurallar bazý durumlar için gevþetildi template kod içinde türden bahsettiðimiz her yerde typename anahtar kelimesini kullanmak zorundaydýk

					template <typename T>
					T::value_type foo(T) // C++20'den önce olsaydý fonksiyonun geri dönüþ deðerinin türüde olsa burda yine typename anahtar sözcüðünü kullanmamýz gerekiyordu 
					{						fonksiyonun geri dönüþ deðerinin türünün yazýldýðý yerde bir expression olma ihtimali olmadýðý için böyle durumlardada tür olmasý dýþýnda
											baþka bir durum olmasý söz konusu deðilse typename anahtar sözcüðünü kullanmamýza gerek yok
						return {}; 
					}

					template<typename T>
					class Myclass{
						using value_type = T::value_type; // C++20 ile typename anahtar sözcüðünü kullanmamýza gerek kalmýyor
					};
	}		

VARIABLE TEMPLATE
	derleyici variable template'e bir instantiation yaptýðýnda bir variable tanýmlamasý oluþuyor yani variable tanýmlamasý için kullanacaðý template

	ÖRNEK:
		template <typename T>
		struct Myclass{
			constexpr static int value = 10; 
		};

		template <typename T>
		constexpr int Myclass_v = Myclass<T>::value;


		int main()
		{
			constexpr auto x1 = Myclass_v<int>;
		}

	ÖRNEK:
		template <std::size_t N>
		constexpr std::size_t fact = N * fact<N - 1>;

		template<>
		constexpr std::size_t fact<0> = 1;

	ÖRNEK:
		template<std::size_t X>
		constexpr std::size_t sbc = (X % 2) + sbc<X / 2>;

		template <>
		constexpr std::size_t sbc<0> = 0;

		int main()
		{
			constexpr auto val = sbc<15u>;
		}
	
ALIAS TEMPLATE
	
	template<typename T>
	using Ptr = T*; // ptrnin kendisi type ailas deðil type alias template type alias olacak olan Ptr'nin bir specialization'ý


	int main()
	{
		Ptr<int> p1; // int*	
	}

	ÖRNEK:
		template<typename T,int N>
		using ar = T[N];

		int main()
		{
			ar<int,5>; // int[5]
		}

	ÖRNEK:
		template <typename T>
		using epair = std::pair<T,T>;

		int main()
		{
			epair<int>;
		}

	ÖRNEK:
		template<typename T>
		using fptr = T(*)(T);

		int foo(int);
		double bar(double);

		int main()
		{
			fptr<int> fp1 = &foo;
			fptr<double> fp2 = &bar;
		}

	standart kütüphanede generic tarafýnda isminin sonunda _t olanlar alias template _v olanlar ise variable template oluyor
		
		is_floating_point_v<double>; // çoðunlukla bu variable templateler constexpr boolean sabitlerdir
										bunu yazmakla is_floating_point<double>::value yazmak ayný anlama geliyor

		remove_reference<int&>::type // elemanýna eriþtðimizde bir tür elde ediyoruz bu tür template argümaný olan türün referanstan arýndýrýlmýþ hali
										böyle meta functionlar input olarak bir tür alýyorlar output olarak bir tür veriyorlar compile timeda ki bir fonksiyon gibi
										standart kütüphane böyle fonksiyonlar için alias template saðlýyor remove_reference_t<int&> yazmakla ayný þey

		ÖRNEK:
			template<typename T>
			using remove_reference_t = std::remove_reference<T>::type;

			int main()
			{
				remove_reference_t<int&>;
			}

TEMPLATELERÝN DEFAULT ARGUMAN ALMASI
	
	default argüman her hangi bir template parametresi için kullanýlabilir örneðin non-type 

	template <typename T = int>
	class Myclass{};

	int main()
	{
		Myclass<double> m1; // default argümaný kullanmamýþ oluyoruz
		Myclass<> m3; // template argümanýný belirtmediðimiz için T türü int oluyor
	}	

	class templatelerde ve variable templatelerde default argümanlara iliþkin þöyle bir kural var
		bir template parametresi default argüman alýyorsa onun saðýndakilerin hepsi default argüman almak zorunda

		template <typename T = int,typename U> // U türü de default argüman almak zorunda

		ÖRNEK:
			template<typename T = int,typename U = double>
			struct Myclass{
				Myclass()
				{
					std::cout<<typeid(*this).name() << '\n';
				}
			};

			int main()
			{
				Myclass<char,char> m1;
				Myclass<char> m2;
				Myclass<> m3;
			}

			ÇIKTI:
				struct Myclass<char,char>
				struct Myclass<char,double>
				struct Myclass<int,double>

		DÝKKAT:function templatelerde bu geçerli deðil
			template <typename T = int,typename U> // ama bu þekilde yazýlmasý fonksiyona yapýlan her çaðrýnýn legal olacaðý anlamýna gelmiyor
			void func(T x,U y);

		ÖRNEK:
			void strfunc(const char* p,std::size_t len = std::strlen(p)) {} // bu sentaks geçerli deðil ama templatelerde bu durum için bir kýsýtlama yok

			template<typename T, typename U = T>
			struct Myclass {
				Myclass()
				{
					std::cout << typeid(*this).name() << '\n';

				}
			};

			int main()
			{
				Myclass<int, double> m1; // default argümaný kullanmadýðýmýz için U türü double olur
				Myclass<int> m2; // T ve U int olur
			}

		ÖRNEK:
			template <typename T>
			class Nec {};

			template<typename T, typename U = Nec<T>>
			struct Myclass {
				Myclass()
				{
					std::cout << typeid(*this).name() << '\n';
				}
			};

			int main()
			{

				Myclass<int> m;
			}

			ÇIKTI:
				struct Myclass<int,class Nec<int> >


		ÖRNEK:templatelerde de default parametreler kümülatif olabilir

			template<typename T, typename U, typename W = int>
			class Myclass;

			template<typename T, typename U = double, typename W>
			class Myclass;

			template<typename T = char, typename U, typename W>
			class Myclass {
			public:
				Myclass()
				{
					std::cout << typeid(Myclass).name() << '\n';
				}
			};

			int main()
			{
				Myclass<> m1;
			}

			ÇIKTI:
				class Myclass<char,double,int>
			

	hoca function templatelerde sýk yapýlan bir hatadan bahsediyor

		template <typename T>
		void foo(T x = 43);

		int main()
		{
			foo(); // bu çaðrý legal deðil çünkü burda template argument deduction yapýlabilmesi için fonksiyona argüman göndermemiz gerekiyor
					  
		}

		generic programlama tarafýnda çok sýk kullanýlan bir yapý var
			template <typename T = int>
			T foo(T x = 0)
			{
				return x * x;
			}	

			int main()
			{
				auto val = foo();  // fonksiyonun parametresi default argüman alýyor ama template'in parametreside default argüman alýyor derleyici burda çýkarým yapýlmadýðýný 
									  gördüðü zaman template parametresinin default argüman alýp almadýðýna bakýyor int olduðunu görüyor
			}
			
		bunun kullanýldýðý value initialization sentaksýda önemli
			template<typename T = int>
			T foo(T x = {} ) // bu durumda default template argümanýný kullanýrsak T türü int olucak bu durumda int türden parametreye 0 deðeri geçilmiþ olucak 
			{					T türü sýnýf türü olduðu zaman bu durumda default ctor çaðýrýlacak function template'in call parametresi default argüman kullanýldýðýnda 
								aslýnda default ctor edilmiþ bir parametreyi kullanmýþ olucaz
			}

			int main()
			{
				foo<std::string>();
			}

		default argümanlarda küçüktür bütyüktür iþaretlerini kullanýrkan dikkat etmeliyiz
			template<int N = (5 < 9)>
		
PERFECT FORWARDING(MÜKEMMEL GÖNDERÝM)

	void func(Myclass){} // fonksiyona argümanlarý doðrudan göndermek yerine bu fonksiyonu çaðýracak bir fonksiyona çaðrý yapacaðýz örneðin call_func'a gönderdiðimiz argümanlarýn call_func 
	call_func				tarafýndan func'a gönderilmesiyle yani call_func'ýn bizden aldýðý argümanlarla func'ý çaðýýrmasýyla bizim o argümanlarla doðrudan func'ý çaðýrmak arasýnda
							hiç bir fark olmayacak

						gönderdiðmiz argümanlarýn value kategorisi korunacak
						constluðu korunacak

	ÖRNEK:perfect forwarding olmadan nasýl yaparýz
		class Myclass{};

		void func(Myclass&) { std::cout << "func(Myclass&)\n"; }
		void func(const Myclass&) { std::cout << "func(const Myclass&)\n"; }
		void func(Myclass&&) { std::cout << "func(Myclass&&)\n"; }
		void func(const Myclass&&) { std::cout << "func(const Myclass&&)\n"; } // nadiren kullanýlan parametre

		void call_func(Myclass& r) { func(r); }
		void call_func(const Myclass& r) { func(r); }
		void call_func(Myclass&& r) { func(std::move(r)); }
		void call_func(const Myclass&& r) { func(std::move(r)); }

		int main()
		{
			Myclass m;
			const Myclass cm;

			func(m);
			func(cm);
			func(std::move(m));
			func(std::move(cm));

			call_func(m);
			call_func(cm);
			call_func(std::move(m));
			call_func(std::move(cm));
		}

		burada bir sorun mevcut bunu yapmak için tek parametreli fonksiyon varsa 4 tane fonksiyon yazmamýz gerekir 2 tane parametresi olsaydý 4'ün karesi kadar 16 tane 
		fonksiyon yazmamýz gerekirdi 

		ÇÖZÜM:
			template<typename T>
			void call_func(T&& x)
			{
				func(std::forward<T>(x)); // fonksiyonu doðrudan çaðýrmak yerine argümaný forward'a argüman olarak gönderip forward'ýn geri dönüþ deðeri ile fonksiyonu çaðýrdýðýmýzda
											 hem constluðunu hemde value kategorisini korumuþ oluyoruz yani L value deðerini L value olarak koruyor R value deðerinide koruyor
			}

			örneðin iki parametreli olsaydý 
				template<typename T,typename U>
				void call_func(T&& x,T&& y)
				{
					func(std::forward<T>(x), std::forward<U>(y));
				}
*/