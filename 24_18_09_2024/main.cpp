/*

inheritance konusundan devam

	SORU:ayný parametreye sahip fonksiyonlar farklý classlarda olsa using bildirimi yaptýðýmýzda sentaks hatasý olur muydu? HAYIR
		
		class Base{
			public:
				void foo(int);
				void foo(double);
		};

		class Der : public Base{
			public:
				using Base::foo; // geçerli
				void foo(int);
		};

	INHERITED CONSTRUCTOR
		
		using bildirimi ile Base class'ýn ctorlarýný Der class'a enjekte ediyoruz

		class Base{
			public:
				Base(int,int);
				Base(int);
				Base(double);
		};

		class Der : public Base{
			public:
				using Base::Base; // Base class'ýn ctorlarýný enjekte ettiðimiz için derleyici burda base class'ýn ctorlarýna çaðrý yapacak

		};

		int main()
		{
			Der d1(23); // Base(int)
			Der d2(2.3); // Base(double)
			Der d3(10,20); // Base(int,int)
		}

	RUN TIME POLYMORPHISM

		bir taban sýnýfýn member functionlarýný 3 kategoriye ayýrýyoruz
			1)türemiþ sýnýflara hem bir interface veren hemde implementasyon veren fonksiyonlar
				
				class Airplane{
					public:
						void fly(); // türemiþ sýnýflar Airplane sýnýfýný kalýtým yoluyla elde ederse onlardada fly fonksiyonu olacak ve tüm miras alan sýnýflar taban sýnýfýn fly fonksiyonunu kullanacak
				}

			2)türemiþ sýnýflara hem bir interface veren hemde bir default implementasyon veren fonksiyonlar
				ister base class'ýn implementasyonunu kullanýrlar isterse kendi implementasyonunu kullanýrlar(POLYMORPHIC CLASS)

					class Airplane{
						public:
							virtual void fly(); // virtual function(türemiþ sýnýf bu fonksiyonu override edebilir)
							
							bir sýnýfýn en az bir tane bile virtual fonksiyonu varsa POLYMORPHIC CLASS olmuþ olur
							
							eðer türemiþ sýnýf taban sýnýfýn fonksiyonunu override ederse türemiþ sýnýfýn kendisine ait fly fonksiyonu olmuþ olur
							eðer override edilmezse taban sýnýfýn fonksiyonu kullanýlmýþ olur
					};

			3)taban sýnýfýn öyle bir üye fonksiyonu ki türemiþ sýnýflara sadece bir interface veren implementasyon vermeyen fonksiyonlar(ABSTRACT CLASS)
				
				class Airplane{
				public:
					virtual void fly(int) = 0; // pure virtual function-saf sanal fonksiyon(türemiþ sýnýflar bu fonksiyonu implemente etmek zorunda)
			
					ABSTRACT CLASS'lardan nesne oluþturulmaz 
				};
					
				class Boeing : public Airplane{ 
					void fly(int) override; // boeing sýnýfýnýn concrete olmasý için fly foknsiyonunu ayný þekilde override etmek zorunda
					override contextual keywordünü yazmasak bile sentaks hatasý olmazdý ama mutlaka yazmamýz gerek

					// türemiþ sýnýf taban sýnýfýn bir sanal fonksiyonuyla ayný isimle ayný imzaya sahipse fakat geri dönüþ deðeri türü farklý bir fonksiyon tanýmlarsa
					bu sentaks hatasý sadece tek bir istisna var COVARIANS deniliyor hoca diðer derslerde deðinecek
				};
	
			virtaul function'ýn tanýmýný cpp dosyasýnda yapýyorsak virtual keywordünü kullanmýyoruz

		VIRTUAL DISPATCH
			// Base classta virtual ile nitelediðimiz fonksiyonlarý türemiþ sýnýflar override ettiðinde o türemiþ sýnýftan hangi nesneleri adres olarak yada referans olarak yollarsak 
				o sýnýfýn fonksiyonu çaðýrýlýr ve burda çaðýrýlan fonksiyon RUN TIME'DA belli oluyor
				
			class Car {
		public:
			virtual void start() { std::cout << "Car::start()\n"; } 
			virtual void run() { std::cout << "Car::run()\n"; }
			virtual void stop() { std::cout << "Car::stop ()\n"; }
		};

		class Volvo : public Car {
		public:
			void start() override { std::cout << "Volvo::start()\n"; }
			void run() override { std::cout << "Volvo::run()\n"; }
			void stop()override { std::cout << "Volvo::stop ()\n"; }
		};

		class Renault : public Car {
		public:
			void start() override { std::cout << "Renault::start()\n"; }
			void run() override { std::cout << "Renault::run()\n"; }
			void stop() override { std::cout << "Renault::stop ()\n"; }
		};


		class Mercedes : public Car {
		public:
			void start() override { std::cout << "Mercedes::start()\n"; }
			void run() override { std::cout << "Mercedes::run()\n"; }
			void stop()override { std::cout << "Mercedes::stop ()\n"; }
		};

		void car_game(Car& c) 
		{
			c.start();
			c.run();
			c.stop();
		}

		int main()
		{
			Mercedes m;
			Volvo v;
			Renault r;

			car_game(m); 
			car_game(v);
			car_game(r);
		}

		ÇIKTI:
		Mercedes::start()
		Mercedes::run()
		Mercedes::stop ()
		Volvo::start()
		Volvo::run()
		Volvo::stop ()
		Renault::start()
		Renault::run()
		Renault::stop ()

		bir fonksiyonun hangi fonksiyona baðlancaðý 2 farklý þekilde anlaþýlabiliyor
			1)static binding yada early binding(compile time'da belli olur)
			2)dynamic binding yada late binding(run time'da belli olur)

			derleyici böyle zamanlarda optimizaasyon yaparak daha düþük maliyetli kod olsun diye virtual dispatch mekanizmasýna iliþkin kod üretmek
			iþini run time'a býrakmayýp compile time da baðlayayým diyebilir buna DEVIRTULAZATION OPTIMIZATION deniliyor

	Car* create_random_car()
	{
		static std::mt19937 eng;
		static std::uniform_int_distribution dist{ 0,2 };

		switch (dist(eng))
		{
		case 0: std::cout << "Volvo..\n"; return new Volvo;
		case 1: std::cout << "Renault..\n"; return new Renault;
		case 2: std::cout << "Mercedes..\n"; return new Mercedes;
		default: return nullptr;
			break;
		}
	}

	int main()
	{

		for (int i = 0; i < 10; ++i)
		{
			Car* p = create_random_car(); // hangi fonksiyonun çaðýrýldýðý run time'da belli olur
			car_game(p);
			(void)getchar;
		}
	}

	VIRTUAL DISPATCH'IN DEVREYE GÝRDÝÐÝ SENARYOLAR
		
		1)virtual dispatch'in devreye girmesi için fonksiyon çaðrýsýnýn taban sýnýf pointerý yada referansý ile yapýlmasý gerekiyor

				class Car {
			public:
				virtual void start() { std::cout << "Car::start()\n"; }
				virtual void run() { std::cout << "Car::run()\n"; }
				virtual void stop() { std::cout << "Car::stop ()\n"; }
			};

			class Volvo : public Car {
			public:
				void start() override { std::cout << "Volvo::start()\n"; }
				void run() override { std::cout << "Volvo::run()\n"; }
				void stop()override { std::cout << "Volvo::stop ()\n"; }
			};

			class Renault : public Car {
			public:
				void start() override { std::cout << "Renault::start()\n"; }
				void run() override { std::cout << "Renault::run()\n"; }
				void stop() override { std::cout << "Renault::stop ()\n"; }
			};


			class Mercedes : public Car {
			public:
				void start() override { std::cout << "Mercedes::start()\n"; }
				void run() override { std::cout << "Mercedes::run()\n"; }
				void stop()override { std::cout << "Mercedes::stop ()\n"; }
			};

			int main()
			{
				Mercedes m;
			
				Car* pcar = &m;

				pcar->start(); // pcar pointerý Mercedes'in adresini tuttuðu için Mercedes'in override fonksiyonlarý çaðýrýlacak
				pcar->run();
				pcar->stop();
			}

		2)virtual olmayan fonksiyon içerisinde gizli parametre fonksiyonuna hangi adres geldiyse o nesnesin adresiyle çaðrý yapabiliyoruz
			
				class Car {
			public:
				virtual void start() { std::cout << "Car::start()\n"; }
				virtual void run() { std::cout << "Car::run()\n"; }
				virtual void stop() { std::cout << "Car::stop ()\n"; }

				void test() // gizli parametre deðiþkeni Car* 
				{
					start(); // hangi nesne ile çaðýrýlýrlarsa gizli parametre deðiþkenine o nesnesinin adresini geçecek ve override olan fonksiyonu çaðýracak
					run();
					stop();
					
					// Car::start(); // burda taban sýnýfýn fonksiyonunu niteleyerek çaðýrdýðýmýz için virtual dispatch devreye girmiyor
					// Car::run();
					// Car::stop();
				}
			};

			class Volvo : public Car {
			public:
				void start() override { std::cout << "Volvo::start()\n"; }
				void run() override { std::cout << "Volvo::run()\n"; }
				void stop()override { std::cout << "Volvo::stop ()\n"; }
			};

			class Renault : public Car {
			public:
				void start() override { std::cout << "Renault::start()\n"; }
				void run() override { std::cout << "Renault::run()\n"; }
				void stop() override { std::cout << "Renault::stop ()\n"; }
			};


			class Mercedes : public Car {
			public:
				void start() override { std::cout << "Mercedes::start()\n"; }
				void run() override { std::cout << "Mercedes::run()\n"; }
				void stop()override { std::cout << "Mercedes::stop ()\n"; }
			};

			int main()
			{
				Mercedes m;

				m.test();
			}

	taban sýnýf sanal fonksiyonunu override eden türemiþ sýnýf fonksiyonunda virtual keyword'ü kullanýlmasa da virtual functiondýr
	çünkü oda override edilebilir

		class Base{
			public:
				virtual void foo()
				{
					std::cout<<"Base::foo()\n";
				}
		};

		class Der : public Base{
			public:
				virtual void foo() override { // virtual anahtar kelimesini yazmasak bile hala virtual fonksiyondur Der sýnýfýndan kalýtýmla yeni bir sýnýf oluþturulduðu zaman 
												 bu fonksiyonu override edebilir
					std::cout<<"Der::foo()\n";
				}
		};

		class Sder : public Der{
			public:
				 void foo() override {
					std::cout<<"Sder::foo()\n";
				}
		};

		void bar(Base& r){
			r.foo();
		}

		void baz(Der& r){
			r.foo();
		}
		
		int main()
		{
			Sder x;

			bar(x); 
			baz(x);
			
			// Sder'in foo fonksiyonu çaðýrýlýr çünkü Sder hem Base hemde Der olduðu için iki þekildede çaðýrýlabilir
		}

	SORU:Der sýnýfý Base sýnýfýnýn pure virtual foo fonksiyonunu override etmezse Sder sýnýfý edebilir mi? EVET ama override etmediðimiz için Der sýnýfýndan nesne oluþturamayýz
	concrete class olmasý için ve Der sýnýfýndan da nesne oluþturmak istiyorsak foo fonksiyonunu override etmemiz gerek
		
		class Base{
			public:
				virtual void foo() = 0;

		};

		class Der : public Base{
		
		};

		class Sder : public Der{
			public:
				 void foo() override {
					std::cout<<"Sder::foo()\n";
				}
		};

	ÖRNEK:eriþim kontrolünün run time ile hiç bir ilgisi yok

		class Base{
			public:
				virtual void foo(){}
		};

		class Der : public Base{
			private:
				void foo() override
				{
					std::cout<<"Der::foo()\n";
				}
		};

		void func(Base* baseptr)
		{
			baseptr->foo(); // burda eriþim kontrolü yapýlýyor çünkü isim ile eriþiliyor eðer foo fonksiyonu Base class'ýn private bölümünde olsaydý burda sentaks hatasý olacaktý
		}

		int main()
		{
			Der myder;
			func(&myder); // virtual dispatch ile Der'in foo fonksiyonu çaðýrýlýr

			myder.foo(); // þimdi eriþim kontrolüne takýlýr çünkü ismi kullandýk direkt olarak Der sýnýfýnda arama yapýldý
		}

		ÖRNEK:default argüman static türle alakalý

			class Base{
				public:
					virtual void foo(int x = 5)
					{
						std::cout<<"Base::foo(int x) x = " << x <<'\n';
					}
			};

			class Der : public Base{
				public:
					virtual void foo(int x = 77) override
					{
						std::cout<<"Der::foo(int x) x = " << x <<'\n';
					}
			};

			int main()
			{
				Der myder;

				Base* baseptr = &myder;

				baseptr->foo(); // derleyici foo fonksiyonunu Base classta buldu virtual dispatch kodu üretecek ama gönderilen argümanýn virtual dispatch ile alakasý olmadýðý için
				baþka argüman gönderilmediðini gördü bu yüzden Base class'ýn default argumanýný görüyor ve o argümaný çaðýrýyor 
			}
	
		ÇIKTI: Der::foo(int x) x = 5

	VIRTUAL DISPATCH DEVREYE GÝRMEDÝÐÝ SENARYOLAR
		1)sanal fonksiyon çaðrýsý taban sýnýf nesnesiyle yapýlýrsa(object slicing)
			
			object slicing'te virtual dispatch devreye girmiyor(Taban sýnýfýn pointer yada referans olmayan nesnesine türemiþ sýnýf nesnesini atamak)
			
			class Car {
			public:
				virtual void start() { std::cout << "Car::start()\n"; }
				virtual void run() { std::cout << "Car::run()\n"; }
				virtual void stop() { std::cout << "Car::stop ()\n"; }

				void test() 
				{
					start(); 
					run();
					stop();

				}
			};

				class Mercedes : public Car {
			public:
				void start() override { std::cout << "Mercedes::start()\n"; }
				void run() override { std::cout << "Mercedes::run()\n"; }
				void stop()override { std::cout << "Mercedes::stop ()\n"; }
			};

			int main()
			{
				Mercedes m;

				Car mycar = m;
				mycar.start(); // virtual dispatch devreye girmez Car sýnýfýnýn start fonksiyonu çaðýrýlýr
			}

		2)taban sýnýfýn sanal fonksiyonu taban sýnýf ismiyle nitelenerek çaðýrýldýysa
				
				class Car {
			public:
				virtual void start() { std::cout << "Car::start()\n"; }
				virtual void run() { std::cout << "Car::run()\n"; }
				virtual void stop() { std::cout << "Car::stop ()\n"; }

				void test() // gizli parametre deðiþkeni Car* 
				{
					start(); 
					run();
					stop();
					
					// Car::start(); // böyle çaðýrýrsak virtual dispatch devreye girmiyor
					// Car::run();
					// Car::stop();
				}
			};

		3)taban sýnýfýn ctor ve dtor içinde sanal fonksiyona çaðrý yapýldýysa
			
			Ctor içinde sanal fonksiyonlara yapýlan çaðrýda virtual dispatch devreye girmiyor eðer ctor içinde virtual dispatch devreye girseydi felaket olurdu çünkü türemiþ sýnýf nesnesi 
				programýn akýþý türemiþ sýnýfýn ctorunu tamamladýðý zaman eðer devreye girseydi türemiþ sýnýfýn override fonksiyonu türemiþ sýnýfýn memberlarýný kullanýyor 
				olabilirdi eðer virtaual dispatch baðlansaydý hayata gelmemiþ türemiþ sýnýf nesnesi için fonksiyon çaðrýsý yapmýþ olurduk

			class Base{
				public:
					Base()
					{
						foo();
					}
					
					virtual void foo()
					{

					}
			};

			class Der : public  Base
			{
				public:
					virtual void foo()
					{
						std::cout<<"Der::foo()\n";
					}
			};

		Dtor'da da virtual dispatch devreye girmiyor çünkü nesnesin hayatý zaten bitmiþ oluyor

	
	VIRTUAL CTOR IDIOM
		ctorlar virtual olabilir mi? HAYIR ama böyle bir ihtiyaç var buna karþýlý gelen idiom VIRTUAL CTOR IDIOM YADA CLON IDIOM deniyor

			class Car {
			public:
				virtual void start() { std::cout << "Car::start()\n"; }
				virtual void run() { std::cout << "Car::run()\n"; }
				virtual void stop() { std::cout << "Car::stop ()\n"; }
				virtual Car* clone() = 0;
				};
			class Volvo : public Car {
			public:
				void start() override { std::cout << "Volvo::start()\n"; }
				void run() override { std::cout << "Volvo::run()\n"; }
				void stop()override { std::cout << "Volvo::stop ()\n"; }
				Car* clone() override
				{
					return new Volvo(*this); // burda copy construct ediyoruz
				}
			};

			class Renault : public Car {
			public:
				void start() override { std::cout << "Renault::start()\n"; }
				void run() override { std::cout << "Renault::run()\n"; }
				void stop() override { std::cout << "Renault::stop ()\n"; }
				Car* clone() override
				{
					return new Renault(*this); // burda copy construct ediyoruz
				}
			};
			class Mercedes : public Car {
			public:
				void start() override { std::cout << "Mercedes::start()\n"; }
				void run() override { std::cout << "Mercedes::run()\n"; }
				void stop()override { std::cout << "Mercedes::stop ()\n"; }
				Car* clone() override
				{
					return new Mercedes(*this); // burda copy construct ediyoruz
				}
			};
			
		Car* create_random_car()
		{
			static std::mt19937 eng;
			static std::uniform_int_distribution dist{ 0,2 };

			switch (dist(eng))
			{
			case 0: std::cout << "Volvo..\n"; return new Volvo;
			case 1: std::cout << "Renault..\n"; return new Renault;
			case 2: std::cout << "Mercedes..\n"; return new Mercedes;
			default: return nullptr;
				break;
			}
		}

		void car_game(Car& c)
		{
			Car* pnewcar = c.clone();
			c.start();
			pnewcar->start();
			c.run();
			pnewcar->run();
			c.stop();
			pnewcar->stop();
		}
		
		int main()
		{
			for (int i = 0; i < 10; ++i)
			{
				Car* p = create_random_car();
				car_game(*p);
			}
		}

		ÖRNEK:sýnýfa sanal fonksiyon eklediðimizde sýnýfýn sizeof deðeri artar

			class Base{
				public:
					int mx,my{};
					virtual void foo(){}
					virtual void bar(){}
					virtual void baz(){} // sadece 1 fonksiyonu virtual yaparsak sýnýfýn storage deðeri artar 
			};

		class Der {
		public:
			virtual void foo() {}
			virtual void bar() {}
			virtual void baz() {}
		};

			int main()
			{
				std::cout<<"sizeof(Base) = " << sizeof(Base) <<'\n';
				std::cout << "sizeof(Der) = " << sizeof(Der) << '\n';
			}
			
			ÇIKTI: 
			sizeof(Base) = 16 // virtual fonksiyon olmasa sýnýfýn storage deðeri 8 olacaktý storage deðeri derleyiciden derleyiciye deðiþiyor 
			sizeof(Der) = 8 

	CONTEXTUAL KEYWORD(baðlamsal anahtar sözcük)
		belirli bir contextte kullanýldýðý zaman anahtar sözcük etkisi yapýyor ama o context'in dýþýnda anahtar sözcük olarak deðil
		doðrudan identifier olarak kullanýlabiliyor

		modern C++ ile dile eklenen 2 tane contextual keyword var
			1)override
			2)final

			int main()
			{
				int override = 5; // eðer anahtar kelime olsaydý sentaks hatasý verirdi anahtar kelime olarak eklenmemesinin nedeni
				eski var olan kodlarýn kýrýlmamasý açýsýndan
			}
*/