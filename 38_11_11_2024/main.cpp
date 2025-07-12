/*

LOCAL CLASS

	bir fonksiyon içinde local class tanýmlayabiliriz

	ÖRNEK:
		void foo()
		{
			int x = 5; 

			class Nec{
			
				void func()
				{
					auto val = x; // geçersiz x static olsaydý geçerli olacaktý
				} 

			};
		}

	ÖRNEK:
		
		void foo(int x) 
		{

		class Nec {

			void func()
			{
				auto val = x; // geçersiz parametre deðiþkeninide kullanamayýz
			}

			};
		}

	ÖRNEK:
		
		int g = 10;

		void foo()
		{

			class Nec{
			
				void func()
				{
					auto val = g; // geçerli
				}

			};
		}	
		
	ÖRNEK:
	
		void foo()
		{

			static int ival = 7;

			class Nec{

				void func()
				{
					auto val = ival; // geçerli
				}

			};
		}

	ÖRNEK:local class türünden nesneler modern C++'dan önce templatelere argüman olarak gönderilemiyordu

		template<typenae T>
		void foo(T x){}

		void foo(int a){
			class Nec{
				void foo()
				{

				}
			}
			foo(Nec{}); // eski C++'da legal deðil legal yapýlmasýnýn amacý lambdalar çünkü lambda ifadelerini fonksiyon þablonlarýna ve özellikle STL algoritmalarýna 
						   argüman olarak lambda ifadelerinin geçilmesi

		}

LAMBDALARDAN DEVAM 

	modern C++'ýn her standartýyla yeni araçlar ekleniyor ya da daha önce olan kýsýtlamalar kaldýrýldý 

	lambda ifadelerine bazý programcýlar lambda function diyor

	[] -> lambda introducer deniliyor içine yazdýðýmýz ifadelere capture close yada capture expression deniliyor
	[]() -> burda ki parantez derleyiciye yazdýrdðýmýz sýnýfýn fonksiyon çaðrý operatör fonksiyonunun parantezi 
	[](){} -> süslü parantez ise derleyicinin ana bloðu


	ÖRNEK:
		
		class Myclass
		{
			auto operator()(int x)const // fonksiyonun geri dönüþ deðeri türünü return ifadesinden çýkarým yoluyla elde ediyor
			{						  derleyicinin yazdýðý fonksiyon çaðrý operatör foksiyonu default olarak CONST MEMBER FUNCTION
				return x* x;
			}
		};

		int main()
		{
			[](int x) { return x * x; }; // derleyici böyle bir lambda ifadesine karþýlýk yukarýda ki gibi bir sýnýf yazýyor
			
			// Myclass{}(5) bunu böyle çaðýrmakla -> [](int x) { return x * x; }(5); böyle çaðýrmak arasýnda hiç bir fark yok bu þekilde kullanýlan lambda ifadelerine
			   IIFE(Immediately Involved Function Expression) idiyomu deniliyor
		}	


	ÖRNEK:lambda ifadesini isimlendirilmiþ bir closure objecte dönüþtürebiliriz peki bunun faydasý ne?

		1)fonksiyonu birden fazla kez kullanmak isteyebiliriz
			int main()
			{
				const auto f = [](int x) { return x * x + 5; }; // const correctness'a dikkat etmemizde gerekir

				auto i1 = f(123);
				
				auto i2 = f(4);
			}

		2)kodun görsel karmaþýklýðýný azaltmak için olabilir

	
	closure typelar'ýn copy ctoru var

		int main()
		{
		 auto f1 = [](int x) { return x * x + 5; };
		 auto f2 = f1; // f1 ve f2'nin türü burada ayný çünkü copy ctor ile ilk deðer verdik
		}
			
		DÝKKAT: lambda ifadelerinin birebir ayný olmasý ayný türler olduðu anlamýna gelmiyor derleyici her bir tür için farklý bir closure type tanýmlýyor
		
			int main()
			{
				 auto f1 = [](int x) { return x * x + 5; }; 
				 auto f2 = [](int x) { return x * x + 5; }; 
			
				constexpr auto b = std::is_same_v<decltype(f1), decltype(f2)>; // false
			}
		
	C++20 ile deðiþen bir kural var 

		int main()
		{
			 auto f1 = [](int x) { return x * x + 5; };
			 
			 decltype(f1) f2; // bu kod C++20'de geçerli C++17'de geçerli deðil
			auto f2 = f1; // C++17'de de geçerli

			f1 = f2; // copy assignment deleted C++17'de geçersiz
		}

		C++17'de closure type'larýn
			a)default ctor
			b)copy assignment ctor delete edilmiþ durumda

		c++20 standardýnda stateless lambda'larýn default ctoru ve copy assignment'ý artýk delete edilmiþ deðil

	SORU:fonksiyonlarýn geri dönüþ deðeri türü closure type olabilir mi? EVET

		foo(int x)
		{
			return [](int a) { return a * a - 12; };
		}

		bu ifadeyi fonksiyonun geri dönüþ deðeri yapmak için en az 2 ayrý araç var
			1)auto return type
				auto foo(int x)
				{
					return [](int a) { return a * a - 12; };
				}
			2)her hangi bir callable'ý sarmalayan std::function(ileride göreceðiz)
				std::function<int(int)> foo(int x)
				{
					return [](int a) { return a * a - 12; };
				}			

	ÖRNEK: closure typelar kalýtýmda base class olarakta kullanýlabilir

			auto f1 = [](int x) { return x * x; };
			auto f2 = [](int x) { return x + x; };

			class Myclass : public decltype(f1) , public decltype(f2) {};


	ÖRNEK: öyle bir fonksiyon yazmak istiyoruz ki fonksiyonumuzun yaptýðý iþ parametre deðiþkenine gelen argümanla x'in çarpýmýnýn oluþturduðu deðeri döndürmek

		int main()
		{
			int x = 5;

			[](int a) { return x * a; }; // local claas olduðu için x burda visible olmuyor 
		}

		 bunu gerçekleþtirebilmek için COPY CAPTURE kullanmamýz gerekiyor
			
			int main()
			{
				int x = 5;

				[x](int a) { return x * a; }; // buraya x'i yazdýðýmýz zaman derleyiciye þöyle bir talimat veriyoruz
			}									 derleyici closure type'ý oluþtururken sýnýfa bir veri elemaný koy veri elemaný ilk deðerini x'den alsýn
												 fonksiyonun kodunda x ismini kullandýðýmýz zaman aslýnda sýnýfýn veri elemanýný kullanmýþ olucaz
		
	ÖRNEK:eðer bir sýnýf yazýp kendimiz ayný iþlemi yapmak isteseydik 
			
		class nec_26_54{
			public:
				nec_26_54(int x) : mx(x) {}

				auto operator()(int x) const { return mx * x; }

			private:
				int mx;
		};

		int main()
		{
			int x = 5;

			nec_26_54{x}(45);
		}

	DÝKKAT:birden fazla isim olsaydý comma separated list kullanmamýz gerekirdi -> [x,y](int a) { return x * a * y; };
		   ama bunun kestirme bir yolu var -> [=] CAPTURE ALL VISIBLE LOCAL VARIABLES BY COPY

		   int main()
		   {
				[=] // 
					   
				int x = 5;
				int y = 7;

				[=]{ 
				
				 // isimleri tek tek yazmak yerine görünür her ismi lambda fonksiyonu içinde kullanmak istiyorsak bunu kullanýyoruz ama hoca çoðunlukla önermediðini 
					söylüyor çünkü örneðin y'yi kullanmak istemediðimiz halde yanlýþlýkla burda kullanma ihtimalimiz var 
				
				};
		   }

		   ÖRNEK:

				void func(int a,int b)
				{
					// auto f = [=](int x) { return x + (a * b); };
					// auto f = [a,b](int x) { return x + (a * b); };

					her iki þekilde de kullanabiliriz
				}

	DÝKKAT:tüm statik ömürlü deðiþkenler capture edilemez
			
		int g = 5;
		int foo(int) {

			return 1;
		}

		int main()
		{
			auto f = [g] {return foo(g); }; // sentaks hatasý
		}

	ÖRNEK: derleyicinin ürettiði fonksiyon çaðrý operatör fonksiyonu default olarak const member function olduðu için sentaks hatasý olur

		int main()
		{
			std::string name {"hasan"};
			int x = 7;

			auto f = [x,name](int val)
			{
				x+= val;
				name += "can"; // ikiside sentaks hatasý çünkü fonksiyon çaðrý operatörü const member function
			};
		}

		DÝKKAT: sýnýfýn veri elemanýný üye fonksiyon içinde deðiþtirmek istiyorsak mutable anahtar kelimesini kullanmamýz gerekir
			int main()
			{
				std::string name {"hasan"};
				int x = 5;

				auto f = [x,name](int val) mutable 
				{
					x+= val; // DÝKKAT burda aslýnda sýnýfýn veri elemaný olan x'i deðiþtirmiþ oluyoruz bu x'i deðil 
					name += "can"; // mutable anahtar kelimesini kullandýðýmýz için her ikiside geçerli olur sýnýfýn veri elemanlarý non-const member function olmuþ olur  
				}

				f(12);

				std::cout << x; // 5 local olan x deðeri buda deðiþmiyor

			}

		DÝKKAT: amaç yukardaki x gibi local bir deðiþkenin deðerini deðiþtirmek olsaydý 
			
			int main()
			{
				std::string name{ "hasan" };
				int x = 5;

				auto f = [&x](int& val) // referans dekleratörünü kullanýyoruz
					{
						x += val;
					};

				f(x); // DÝKKAT bu fonksiyon çaðrýsý olmadan x'in deðeri zaten deðiþmeyecekti

				std::cout << x; // x + x = 10
			}
			
	[a,b,c] -> a,b,c kopyalama yoluyla alýnýr
	[=] -> hepsi kopyalama yoluyla alýnýr

	[&x] -> referans yoluyla alýnýr
	[&x,y] -> x referans yoluyla alýnýr y kopyalama ile alýnýr
	[&] -> hepsi referans yoluyla alýnýr
	[=, &a] -> hepsi kopyalama yoluyla alýnýr ama a referans yoluyla alýnýr
	[&,x] -> hepsi referans yoluyla alýnýr ama x kopyalama yoluyla alýnýr

	[&&] -> geçersiz

	ÖRNEK:parametre paketlerinide capture edebiliriz

		template<typename ...Ts>
		auto func(Ts ...args)
		{
			auto f = [args...]()
				{
					return (... + args);
				};

			return f() + 100;
		}

		int main()
		{
			std::cout<<func(5); // 105
		}

	stateless lambda -> capture etmez []
	stateful lambda -> bir yada birden fazla varlýðý capture eder [x,y,z]

	ÖRNEK: stateless lambdalar için derleyici oluþturduðu closure type için type cast operator fonksiyonu yazýyor
		   lambda'nýn kendi türünden bir fonksiyon adresi türüne type cast operatörü yazýyor 

		int main()
		{
			[](int a){ return a * a; }; // örneðin parametresi int olan geri dönüþ deðeri türü int olan bir fonksiyon adresi türüne int(*)(int)
		}

		yani elimizde bir stateless lambda varsa onu doðrudan sanki bir fonksiyon adresiymiþ gibi bizden fonksiyon adresi isteyen herhangi bir fonksiyona argüman olarak gönderebiliriz
		yada bir function pointer variable'ý initalize etmek için yada atama yapmak için kullanabiliriz

			int main()
			{
				int(*fp)(int) = [](int a){ return a * a; }; 

				auto val = fp(12);

				std::cout<<val; // 144
			}
	
POSITIVE LAMBDA IDIOM
	
	function poniter type sign operatörü +'nýn operandý olabiliyor

	int foo(int){};

	int main()
	{
		int(*fp)(int) = &foo;
		+fp;
		
		auto f = [](int x) { return x * x; }; // closure type
		auto f2 = +[](int x) { return x * x; }; // derleyicinin bu ifadeyi sýnýfýn type cast operatörüyle function poniter türüne dönüþtürmesi gerekiyor 
												   f2 function pointer type
	}

	ÖRNEK:

		template<typename T>
		void func(T);

		int main()
		{
			func([](int x) { return x * x; }); // closure type
			func(+[](int x) { return x * x; }); // function pointer type

		}

LAMBDA INIT CAPTURE(C++14)

	int main()
	{
		int x = 5;

		auto f = [count = 0]()(int x) // derleyiciye þöyle bir talimat vermiþ oluyoruz sýnýfa bir veri elemaný koy ismi a olsun veri elemanýnýda 0 ile initialize et
		{
			++count; 
			return a + x;
		};


		[x = x](int a) // 5 deðerini sýnýfýn veri elemaný olan x'e atamýþ oluruz
	}

	bu özelliðin eklenmesinin nedenleri

		1)move semantics
			
			int main()
			{
				std::unique_ptr<std::string> uptr(new std::string{ "canim hocam necati hocam" });

				auto f = [uptr = std::move(uptr)]() // uptr'nin kaynaðýný sýnýfýn member'ý olan uptr'ye devrettik
					{
						std::cout << *uptr << '\n';
					};

				f();

				if (uptr)
				{
					std::cout << "dolu"<<'\n';
				}
				else
				{
					std::cout << "bos"<<'\n';
				}
			}

			ÇIKTI: 
				canim hocam necati hocam
				bos

	canýmýz hocamýz capture'da deduction farklýlýðýna deðiniyor

		int main()
		{
			int a[10]{};
		[a] { std::cout << "sizeof(a) = " << sizeof(a)<<'\n'; // sizeof = 40 burda array decay yapýlmýyor 10 elemanlý bir dizi

			}();

		[a = a] { std::cout << "sizeof(a) = " << sizeof(a)<<'\n'; // sizeof = 8 burda array decay yapýlýyor burda auto type deduction'da ki kural geçerli oluyor

			}();
		}

DÝKKAT:referans ile capture yapýldýðýnda dangling reference oluþturmak tipik bir kodlama hatasý

	auto foo(int x)
	{
		return [&x](int a) { return a * x; }; // derleyicinin yazdýðý referans veri elemaný fonksiyonun otomatik ömürlü parametre deðiþkeni olan x'e baðlanacak buda dangling referens
	}

	int main()
	{
		auto f = foo(10);
	}

TRAILING RETURN TYPE

	fonksiyonun geri dönüþ deðerinin çýkarým yoluyla elde edilmesesini istemiyorsak lambdalarda trailing return type'ý kullanabiliriz

	int main()
	{
		auto f = [](int x) -> double
			{
				return x * 5; // ifadenin türü int ama fonksiyonun geri dönüþ deðeri double
			};

		auto val = f(5);
		std::cout << val;

	}

	trailing return type'ýn kullanýlmasýndaki diðer amaçta fonksiyonun geri dönüþ deðerinin referans türü yapýlmak istenmesi

	trailing return type'ýn lambdalarda kullanýlmasýnýn avantajý

		1)farklý türden return ifadelerine sahip birden fazla return statement varsa
		2)fonksiyonun geri dönüþ deðerininin çýkarým yoluyla deðilde kendimiz istediðimiz tür olmasýný istiyorsak
		3)fonksiyonun geri dönüþ deðerinin referans türü olmasýný saðlamak için
		4)fonksiyonun geri dönüþ deðeri türünün auto type deduction ile deðilde decltype(auto) ile elde edilmesini istiyorsak

GENERALIZED LAMBDA EXPRESSIONS
	derleyicinin closure type sýnýfý için fonksiyon çaðrý operatör fonksiyonunu member template olarak yazmasý için auto keyword'ünü kullanýyoruz

		class Myclass
		{
			public:
				template<typename T>
				void operator()(T  x)const
				{
				
				}
		};

		int main()
		{
			[](auto x) // parametreyi auto keyword'ü ile bildirerek derleyicinin fonksiyon çaðrý operatör fonksiyonunu yukarýdaki gibi member template olarak yazmasýný saðlýyoruz
			{
				return x * x;
			}
		}
		
		ÖRNEK:
	
			int main()
			{
				[](auto&& x) // derleyicinin yazdýðý kodda sýnýfýn template'i olan fonksiyon çaðrý operatör fonksiyonun parametresi universal reference
				{
					return x * x;
				}
			}

lambda ifadelerinde derleyicinin yazdýðý closure type'ýn fonksiyon çaðrý operatör fonksiyonunun exception throw etmeme garantisini vermek için noexcept specifier'ýný kullanýyoruz
		
	auto f = [](int a)noexcept
	{
		return a * a;
	};
*/