/*

template konusundan devam ediyoruz

derleyiciler template koda iliþkin sentaks kontrolünü bir kaç farklý aþamada yapýyorlar
	
	1)template kod kullanýlmadan template'in kendisi üstünde yapýlýyor

		template<typename T>
		void func(T x)
		{
			++x;
			
			x = 5; // T türünün ne olduðunun bilinmemesine karþýn yinede sentaks hatasý vermiyor

			// foo(x); // foo fonksiyonu olmamasýna raðmen burada sentaks hatasý hala yok çünkü T türünün ne olduðuna baðlý olarak foo ismi ADL ile
						  aranabilir 
			
			//	bar(19); // template parametresine karþýlýk gelen template argümanýnýn ne olduðuna baðlý olmadýðý için burada sentaks hatasý olur
		}

	2)template argument deduction söz konusuysa deduction'ýn yapýlamama ihtimali var bu durumda template parametrelerine karþýlýk gelen template argümanýnýn ne olduðu
	anlaþýlamadýysa sentaks hatasý olur

		template <typename T>
		T func();
		
		int main()
		{
			func(); // burda derleyicinin T türünün ne olduðunu anlama þansý yok deduction baþarýsýz olduðu için derleyici sentaks hatasý verecek 
		}

	3)argument deduction'ýn yapýlamamasýnýn nedeni ambiguity olmasý
		
		template <typename T>
		void func(T x,T y); // fonksiyonun parametresine CALL PARAMETER deniliyor

		int main()
		{
			func(10,20); // fonksiyonu böyle çaðýrýrsak 1.argümandan template'in 1.parametresine yapýlacak kopyalama için argümanýn türü int olduðu için fonksiyonun parametresinin türünün 
							int türü olmasý gerekiyor

			// func(10,2.0); // 2.parametreyi double yapsaydýk burada bir belirsizlik olacaðý için ambiguity hatasý olacaktý
		}

TEMPLATE ARGUMENT DEDUCTION NASIL YAPILIYOR
	
	bir istisna haricinde auto type deduction ile temple argument deduction arasýnda kural açýsýndan hiç bir fark yok

	türlerin ne olduðunu öðrenmemiz için bir trick var

	template <typename T>
	class TypeTeller;

	template <typename T>
	void func(T)
	{
		TypeTeller<T> x;
	}
	int main()
	{
		int x = 5;

		func(x); // 'x' uses undefined class 'TypeTeller<int>'

	} 

	ÖRNEK:
		template <typename T>
		void func(T)
		{
			TypeTeller<T> x;
		}

		int main()
		{

			int y[5];

			func(y) // array decay uygulanýr T türü int*

			const int y[5];
			
			func(y); // burda constluk düþmüyor T türü const int*
		}

	ÖRNEK:
		template <typename T>
		void func(T&)
		{
			TypeTeller<T> x;
		}

		int main()
		{
			const int x = 5;

			func(x); // T türü const int çünkü referans decleratörü olduðu için constluk düþmüyor

		}

	ÖRNEK:
		template <typename T>
		void func(T&)
		{
			TypeTeller<T> x;
		}

		int main()
		{
		
			int a[5]{};
			func(a); // referans dekleratörü olduðu için array decay uygulanmýyor T türü int[5] 

			derleyicinin yazdýðý func fonksiyonun parametresi þöyle olacak void func(int(&r)[5]
		}

	ÖRNEK:
		template <typename T>
		void func(T&)
		{
			TypeTeller<T> x;
		}

		int foo(int);

		int main()
		{
			func(foo); // referans dekleratörü olduðu için T için yapýlan çýkarým int(int)
			
			derleyicinin yazdýðý func fonksiyonun parametresi þöyle olacak void func(int (&) (int))
		}

	 ÖRNEK:
		template <typename T>
		void func(T&)
		{
			TypeTeller<T> x;
		}

		int main()
		{
			func("alican"); // referans dekleratörü olduðu için T türü için yapýlan çýkarým const char[7]
		}

	ÖRNEK:
		template <typename T>
		void foo(T,T);

		template <typename T>
		void bar(T&,T&);

		int main()
		{
			foo("veli","bayar"); // T için yapýlan çýkarým const char*
			bar("veli","bayar"); // veli yazýsý için T türünün çýkarýmý -> const char[5] olduðu için bayar yazýsý için T türü -> const char[6] olamaz burda ambiguity söz konusu 
									bu yüzden sentaks hatasý
		}

	ÖRNEK:
		template <typename T>
		void foo(T,T&);

		int main()
		{
			int a[5]{};

			foo(a,a); // 1.parametre için yapýlan çýkarým -> int* 2.parametre için yapýlan çýkarým -> int[5] ambiguity söz konusu olduðu için sentaks hatasý
		}

	ÖRNEK: template functionlarda baþýnda const veya volatile anahtar kelimeleri yoksa bu UNIVERSAL REFERENCE
			burda T için yapýlan çýkarým gönderilen argümanýn value kategorisine baðlý
			
			gönderilen argüman L value ise T için yapýlan çýkarým -> T&
			gönderilen argüman R value ise T için yapýlan çýkarým -> T

		1.SENARYO:
			template <typename T>
			void foo(T&&);
			
			int main()
			{
				foo(12); // T için yapýlan çýkarým int

				int x = 230;
				foo(x); // T için yapýlan çýkarým int&

				T için yapýlan çýkarým int& olduðunda C++ dilinde referansa referanse olmadýðý için reference collapsing kurallarý uygulanýyordu

					T& & -> T&
					T& && -> T&
					T&& & -> T&
					T&& && -> T&&  
			}

			template <typename T>
			void foo(T&& x)
			{
				// T y; // mainde T için yapýlan çýkarým int& olduðu için sentaks hatasý çünkü referanslar default initalize edilemezler
				T y = x; // T için yapýlan çýkarým int& x bir isim olduðu için L value yani L value bir deðeri L value'ya baðlamýþ oluyoruz bu yüzden geçerli
			}

			int main()
			{
				int x = 230;
				foo(x);
			}

		2.SENARYO
			template <typename T>
			void foo(T&&);

			int main()
			{
				foo(10); // T için yapýlan çýkarým int yani fonksiyonun parametre deðiþkeninin türü T&& olur
			}


			template <typename T>
			void foo(T&&)
			{
				T x; // bu sefer sentaks hatasý yok çünkü main'de T için yapýlan çýkarým int
			}

			int main()
			{
				foo(10);
			}

		ÖRNEK:
			template <typename T>
			void foo(T&&, T);

			int main()
			{
				int x = 10;
				
				foo(x,x); // T için yapýlan çýkarýmlar sýrasýyla -> int&,int sentaks hatasý
				foo(5,x); // T için yapýlan çýkarýmlar sýrasýyla -> int,int geçerli
				foo(5,5);  // T için yapýlan çýkarýmlar sýrasýyla -> int,int geçerli
			}

		ÖRNEK:
			template <typename T>
			void foo(T&&, T&);

			int main()
			{
				int x = 10;

				foo(x,x); // T için yapýlan çýkarýmlar sýrasýyla -> int&,int sentaks hatasý
				foo(19,x) // T için yapýlan çýkarýmlar sýrasýyla -> int,int	
			}

		ÖRNEK:
			template <typename T>
			void foo(T*);

			int main()
			{
				int x{};
				foo(&x); // T için yapýlan çýkarým int

				int* ptr = &x;
				foo(&ptr); // T için yapýlan çýkarým int*
			}	

		ÖRNEK:
			template <typename T>
			void foo(T**);

			int main()
			{
				int x{};
				
				int* ptr = &x;
				int** p = &ptr;

				foo(p); // T için yapýlan çýkarým int
				foo(&p); // T için yapýlan çýkarým int*
			}

		ÖRNEK:
			template <typename T>
			void foo(T);

			int main()
			{
				int x{};
				int* ptr = &x;

				foo(&x); T -> int*
				foo(&ptr); T -> int**
			}
		
		ÖRNEK:
			template <typename T, int N>
			void foo(T(&)[N]) // T türünden N elemanlý bir diziye referans
			{

			}

			int main()
			{
				int a[20]{};

				foo(a); // int[20];
			}

			dizinin boyutunu derleme zamanýnda elde etmek için 
				template <typename T, int N>
				constexpr int asize(T(&)[N])
				{
					return N;
				}

				int main()
				{
					int a[5]{};

					constexpr auto size = asize(a); // 5
				}

	hoca kendi kendine function templateleri öðrenenlerin yaptýðý hatalara deðiniyor
		
		template <typename T>
		void foo(T)
		{
			std::cout << typeid(T).name() << '\n';
		}

		int main()
		{
			foo(1.2); 
			foo(12);
			foo('A');

			derleyici her tür için farklý fonksiyon yazar

			ÇIKTI:
				double
				int
				char

				foo(1.2);
				foo<double>(12);
				foo<double>('A'); // explicit bir þekilde türünü yazarsak bu sefer sadece tek bir fonksiyon olmuþ olacak
		}

	ÖRNEK:bütün parametreler template parametresine baðlý bir tür olmak zorunda deðiller

		template <typename T>
		void foo(T x,int y,std::string);

	öyle fonksiyon þablonlarý var ki çýkarým yapmak mümkün olmadýðý için bir yada birden fazla template parametresi için explicit template argümaný kullanmak zorunda kalabiliriz

		EXPLICIT TEMPLATE ARGUMANLARI
			a)çýkarým söz konusu deðilse yani çýkarým yapýlma imkaný yoksa
				
				template <typename T>
				T foo(); // fonksiyonun geri dönüþ deðeri türü T dolayýsýyla T türünün çýkarýmýnýn yapýlmasýnýn imkaný yok

				int main()
				{
					foo<int>();
				}
			
			b)çýkarým yapma imkaný var ama biz çýkarým yapmasýný istemiyoruz
			 
		ÖRNEK:birden fazla template parametreleri olabilir ve farklý template parametresine karþýlýk gelen template argümanlarý ayný tür olabilirler

			template <typename T,typename U>
			void foo(T,U);

			int main()
			{
				foo(2,5); // T ve U için yapýlan çýkarým int
				foo<int,int>(2,5); // bu fonksiyonu böyle çaðýrmak demek üstte ki fonksiyonu çaðýrmak demek
			}

		SORU: birden fazla template parametresi olduðunda bütün template parametrelerini deðilde sadece bir kýsmýný explicit olarak yazmak mümkün mü? EVET
			
			template <typename T,typename U>
			void foo(T,U);

			int main()
			{
				foo(2,5);
				foo<int>('A',5.6); // 1.template parametresine char arrgümaný göndermemize raðmen 1.template parametresi karþýlýðý kullanýlacak olan template argümanýnýn int olduðunu 
									söylediðimiz için çýkarým yapýlmayacak ama 2.template parametresi için explicit template argümaný kullanmadýðýmýz için çýkarým yapýlacak 
									derleyicinin yazacaðý fonksiyon T türünün-> int U türünün-> double türünden olduðu fonksiyon olacak
			}

	standart kütüphanede ve 3.parti kütüphanelerde çok sýk rastlanan senaryolardan biri fonksiyon þablonunun kodu içinde fonksiyon parametresinin
	function call operatörünün operandý olmasý

		template <typename T>
		void foo(T f)
		{
			f(10); // popüler olarak CALLABLE deniliyor yani fonksiyon çaðrý operatörünün operandý olabilen varlýklar
		}

		void bar(int x)
		{
			std::cout << "bar: x = " << x <<'\n';
		}

		int main()
		{
			foo(bar); // derleyicinin yaptýðý çýkarým T türü void(*)int olacaktý bar fonksiyonun adresini function poiner'a göndermiþ olacaktýk bu durumda function
						 pointer'ýn göstermiþ olduðu fonksiyon çaðýrýlmýþ olacaktý
		}

		ÇIKTI:
		bar: x = 10
		
		CALLABLE illa ki bir fonksiyon adresi olmak zorunda deðil
			template <typename T>
			void foo(T f)
			{
				std::cout<<f(10);
			}	

			class Myclass{
				public:
					int operator()(int x) // function call operatörünü overload eden sýnýflara functor class deniliyordu çünkü nesne gibi görünüp fonksiyon gibi davranabiliyorlardý
					{
						return x;
					} 
			 };

			 int main()
			 {
				Myclass m;
				foo(m);
			 }
			 
			 ÇIKTI: 10;
			 
			 callable'lar generic kodlarda yoðun olarak kullanýlýyor
	

	ÖRNEK: fonksiyonun geri dönüþ deðerinin farklý türden olmasý girilen argümanlara göre veri kaybý olmamasý için örnek
	
		template<typename Result,typename T,typename U>
		Result sum(T x,U y)
		{
			return x + y;
		}

		int main()
		{
			auto val = sum<double>(5.7,3); // fonksiyonun geri dönüþ deðerinin ne olacaðýnýn saptamýsýný fonksiyonu çaðýran koda verdik Result'ýn geri dönüþ deðeri türünü explicit olarak 
											  belirtiyoruz -> double
		}

		C++ sentaksý fonksiyonlarýn geri dönüþ deðeri türleri için 2 tane farklý araç sunuyor
			1)trailing return type
				fonksiyonun geri dönüþ deðeri türü yerine auto keywordünü kullanýyoruz 

				auto foo() -> int {} // int foo yazmaya eþ deðer

				hoca main fonksiyonunda sýrf ilginçlik olsun diye trailing return type kullananlara gýcýk oluyormuþ :D
					auto main() -> int {}

				normal fonksiyonlarda trailing return type kullanýlmasýný tercih edebileceðimiz bir durum var
					fonksiyonlarýn geri dönüþ deðeri function pointer olabilir
						int bar(int) 
						{
							return 5;
						}

						int (*foo(int (*fp)(int)))(int)
						{
							return fp;
						}

						int main()
						{
							auto f = foo(&bar);
						}

					yazýmý kolaylaþtýrmak için type alias kullanýyoruz
						using fptr = int (*)(int);

						fptr foo(fptr fp)
						{
							return bar;
						}
					
					ama böyle yazmak yerine trailing return type kullanarak yazarsak
						auto foo() -> int (*)(int){} 

						auto foo() -> int (&)[5]{}

			ÖRNEK:öyle bir fonksiyon olsun ki bu fonksiyonn geri dönüþ deðeri türü x + y ifadesinden hangi tür elde ediliyorsa o tür olsun
				template <typename T,typename U>
				auto foo(T x,U y) -> decltype(x + y){}

		2)auto return type
			
			template<typename T,typename U>
			auto foo(T x,U y)
			{
				return x + y; // fonksiyonun geri dönüþ deðeri türü x + y ifadesinin türü olacak
			}

	auto type deduction ile template argument deductionda sentaks açýsýndan ilginç bir farklýlýk var
		
		auto x = {2,5,6,8}; // auto için yapýlan çýkarým initalizer list sýnýf þablonunun int açýlýmý

		template <typename T>
			void foo(T);

		int main()
		{
			foo({2,5,6,8}); // burda initalizer list çýkarýmý yapýlmýyor explicit þekilde yazmamýz gerekir
		}

	tür çýkarýmý daha karmaþýkta olabilir

		template<typename T,typename U>
		void foo(T (*fp) (U))
		{
			T x; // int
			U y; // double
		}

		int bar(double);

		int main()
		{
			foo(bar); // int (*)double
			}
	
	fonksiyon þablonlarýyla ayný isimli fonksiyonlar bir arada bulunabilir 
		template<typename T>
		void foo(T)
		{
			std::cout<<1function template " << typeid(T).name()<<'\n';
		}

		void foo(int)
		{
			std::cout<<"void func(int)\n";
		}

		buda bir overloading biçimi bu durumda dilin kurallarý biraz farklý: eðer fonksiyon çaðrýsýnda kullanýlan argüman gerçek fonksiyonun parametresiyle tam uyuþuyorsa derleyici
		fonksiyon þablonundan bir fonksiyon yazmayacak

		int main()
		{
			foo(4.5); // function template overload resolution sürecinde derleyicinin template'ten oluþturduðu specialization seçilir void foo<double>(double)
			foo(4u); // function template
			foo(4); // void func(int)
			foo('A'); // function template

			gerçek fonksiyon parametresiyle tam uyum saðlarsa gerçek fonksiyon seçilir aksi halde template seçiliyor 
		}

	MÜLAKAT SORUSU: öyle bir fonksiyon olsun ki sadece parametre deðiþkeninin türünden argüman kabul etsin onun dýþýndakiler sentaks hatasý olsun

		template<typename T>
		void foo(T) = delete;

		void foo(int){}

		int main()
		{
			// foo(4.5); // sentaks hatasý sadece int parametreli fonksiyon çaðýrýlabilir
			   foo(4); // geçerli
		}

	function template ve template function ayný anlama geliyor bazý programcýlar bunlarý ayrý anlamlar için kullanabiliyormuþ ama bir farký yok

	SORU: fonksiyon þablonlarý ayný isimde olabilir mi? EVET

		template <typename T>
		void foo(T);

		template <typename T>
		void foo(T,T);

		template <typename T,typename U>
		void foo(T,U);

			ÖRNEK:
				template <typename T>
				void foo(T)
				{
					std::cout<<"foo(T) " << typeid(T).name() <<'\n';
				}

				template<typename T>
				void foo(T x,T y)
				{
					std::cout<<"foo(T,T)" << typeid(T).name() << '\n';
					foo(x); 
					foo(y);
				}

				int main()
				{
					foo(12,56);
				}

				SORU: istersek void foo(T x,T y) template'inden baþka bir tür argümanýyla yeni bir fonksiyon yazýlmaýný saðlayabilir miydik? EVET

	ÖRNEK: programcýlarýn en çok kafasýný karþýtýran ve zor konulardan biri EÐER FONKSÝYON ÇAÐRISI ÝKÝ AYRI TEMPLAT'E BÝRDEN UYUYORSA NE OLACAK?
		
		template<typename T>
		void foo(T)
		{
			std::cout<<"foo(T)\n";
		}

		template<typename T>
		void foo(T*)
		{
			std::cout<<"foo(T*)\n";
		}

		int main()
		{
			// foo(12) // T türünden olan template çaðýrýlýr

			int x = 10;

			// foo(&x); // T* türünden template olmasa T türünden olan template kullanýlabilirdi bu durumda T türü int* olurdu 
						   ama T türünden olan template olmasaydý T* türünden olan template'in türü int olurdu

			SORU:peki böyle bir durumda ikisi birden olduðunda her iki template'den specialization oluþturabileceðine göre derleyici nasýl bir karar verecek?
				
				burda uygulanan kurallara PARTIAL ORDERING RULES deniliyor

					parametresi en spesifik olan seçilecek demek yani foo(&x) ifadesine göre T* T türüne göre daha spesifik olduðuna göre T* türünden parametresi olan template seçilecek
					
					yani eðer templatelerden biri diðerinin kabul ettiði bütün argümanlarý kabul ediyorsa fakat diðerinin kabul etmedði argümanlarýda kabul ediyorsa o zaman daha az spesifik
					
					ve þunuda diyebiliriz genelden daha çok özele hitap eden bir parametresi varsa o parametreye göre seçilme olaslýðý daha fazla olur
		}
*/