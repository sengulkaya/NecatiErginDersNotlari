/*

MULTIPLE INHERITANCE

	 class XBase {
		public:
	 };
	 class YBase {
		public:
	 };

	 class Der : public XBase,public YBase{
		public:

	 
	 };

	 int main()
	 {
		
	 }

	AMBIGUITY ÖRNEK

		 class XBase {
			public:
				void foo(int);
		 };
		 class YBase {
			public:
				void foo(double);
		 };

		 class Der : public XBase,public YBase{
			public:

			// Der sýnýfýndan foo fonksiyonu olsaydý base classlarýn foo fonksiyonunu gölgelemiþ olacacaktý ve main'de ambiguity olmayacaktý
		 };

		 int main()
		 {
			Der myder;
			// myder.foo(2); // foo ismi burda ambiguity'e sebep olur gönderdiðimiz argüman ile bir alakasý yok çünkü function overloading yok
			
			myder.XBase::foo(12); // niteleyerek kullanýrsak sentaks hatasý olmaz
			myder.YBase::foo(12);
		 }
		
		using bildirimi ile türemiþ sýnýfýn içine foo fonksiyonlarýný enjekte edersek function overloading olmuþ olur
			class XBase {
			public:
				void foo(int) { std::cout << "XBase::foo(int)\n"; }
			};
			class YBase {
			public:
				void foo(double){ std::cout << "YBase::foo(int)\n"; }
			};

			class Der : public XBase, public YBase {
			public:
				using XBase::foo , YBase::foo; // foo fonksiyonlarýný enjekte ediyoruz(sanki bu scopeta tanýmlanmýþ gibi etki ediyor ve function overloading olmuþ oluyor)
			};

			int main()
			{
				Der myder;
				myder.foo(2);
				myder.foo(2.5);
			}
			
			ÇIKTI:
			YBase::foo(int)
			XBase::foo(double)
	
	AMBIGUITY ÖRNEK

		class X {};
		class Y {};

		class D : public X,public Y{};

		void foo(X& ){}
		void foo(Y& ){}

		int main()
		{
			D dx;

			foo(dx); // dx'ten X ve Y'ye yapýlan dönüþüm arasýnda bir seçilebilirlik olmadýðý için ambiguity

			foo(static_cast<X&>(dx)); // static_cast operatürünü kullanarak sentaksý geçerli hale getirebiliriz

		}

	CTORLARIN ÇAÐIRILMA SIRASI

		class XBase {
		public:
			XBase()
			{
				std::cout << "XBase ctor\n";
			}

		};
		class YBase {
		public:
			YBase()
			{
				std::cout << "YBase ctor\n";
			}
		};

		class Der : public XBase, public YBase { // kalýtýmdaki sýraya göre classlarýn ctorlarý çaðýrýlýr
		public:

			Der() {

				std::cout << "Der ctor\n";
			}
		};


		int main()
		{
			Der myder;
		}
		
		ÇIKTI:
		XBase ctor
		YBase ctor
		Der ctor
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DREADFUL(deatful) DIAMOND OF DERIVATION(DDD) / DIAMOND FORMATION 

	çoðunlukla çoklu kalýtýmda kullandýðýmýz taban sýnýflar ortak bir sanaf sýnýftan kalýtým elde edilmiþ oluyorlar(görseli inceleyin)
	
		   DEVICE

	
	PRINTER		 SCANNER

			
			COMBO

	böyle bir kalýtým hiyerarþisi varsa özel bir sentaks aracýný kullanmaz PRINTER sýnýfý içerisindede bir DEVICE olacak SCANNER sýnýfý içerisinde de bir DEVICE olacak 
	ve bunlardan kalýtým alan COMBO sýnýfý hem PRINTER hemde SCANNER sýnýfýndan çoklu kalýtým yoluyla elde edildiði için COMBO sýnýfýnýn içinde 2 tane DEVICE olmuþ olacak
	çünkü hem PRINTER sýnýfýnda DEVICE var hemde SCANNER sýnýfýnýn içinde de bir DEVICE var

	
	VIRTUAL INHERITANCE

		diamond of derivation sorununu çözmek için kullanýlan yöntem

		PROBLEMÝN ORNEÐÝ

			class B {
				public:
					void foo();
			};

			class X : public B {};
			
			class Y : public B {};

			class D : public X , public Y {
				
				void bar()
				{
					// foo(); // ambiguity

					X::foo(); // geçerli
					Y::foo(); // geçerli

					static_cast<X*>(this)->foo(); // geçerli
					static_cast<Y*>(this)->foo(); // geçerli
				}	
			
			};

			int main()
			{
				D dx;

				// dx.foo(); ambiguity derleycinin ürettiði kodda B'nin foo fonksiyonuna B nesnesi adresi geçþlmesi gerekiyor ama dx'in içinde 2 tane B nesnesi var biri X'ten gelen B diðeri Y'den gelen B

				dx.X::foo();
				dx.Y::foo(); // Y'nin B adresini kullanmak istersek ve niteleyerek kullanýrsak geçerli olur

				// B* bptr = &dx; // ambiguity derleyici hangi adresi kullanacaðýný bilmiyor çünkü dx'in içerisinde 2 tane B nesnesi var

				B* bptr1 = static_cast<X*>(&dx); 
				B* bptr2 = static_cast<Y*>(&dx); // ikiside geçerli
			}


		ÖRNEK SENARYO

			class B{
				public:
					void foo();
			};
			class X : virtual public B {
			
			};
			class Y : virtual public B{
			
			};
			class D : public X, public Y{ // bu sýnýfýn taban sýnýflarý olan sýnýflarda virtual keywordünü kullanýyoruz
			
			}; 

			int main()
			{
				D dx;

				dx.foo(); // artýk sentaks hatasý yok

				B* bptr = &dx; // UP CASTING artýk geçerli 

				virtual inheritance kullandýðýmýz için ambiguity olan senaryolar artýk ambiguity olmuyor
			}

		ÖRNEK SENARYO 2
			
			class EDevice {
			public:
				virtual ~EDevice() = default;
				 bool is_on() const { return m_flag; }
				void turn_on()
				{
					m_flag = true;

					std::cout << "cihaz acildi\n";
				}
				void turn_off()
				{
					m_flag = false;

					std::cout << "cihaz kapatildi\n";
				}
			private:
				bool m_flag = true;
			};

			class Printer : virtual public EDevice {
			public:
				void print()
				{
					if (!is_on()) {
						std::cout << "cihaz kapali oldugundan print islemi yapilamiyor\n";
					}
					else {
						std::cout << "print islemi tamamlandi\n";
					}
				}

			};

			class Scanner : virtual public EDevice {
			public:
				void scan()
				{
					if (!is_on()) {
						std::cout << "cihaz kapali oldugundan scan islemi yapilamiyor\n";
					}
					else {
						std::cout << "scan islemi tamamlandi\n";
					}
				}

			};

			class Combo : public  Printer,public  Scanner { // bu sýnýfýn taban sýnýflarý olan sýnýflarda virtual keywordünü kullanýyoruz
			public:


			};
			int main()
			{
				Combo mycombo;

				Combo mycombo;

				mycombo.turn_on();
				
				mycombo.print();
				mycombo.scan();

				mycombo.turn_off();

				mycombo.print();
				mycombo.scan()
			}

			ÇIKTI:
			cihaz acildi
			print islemi tamamlandi
			scan islemi tamamlandi
			cihaz kapatildi
			cihaz kapali oldugundan print islemi yapilamiyor
			cihaz kapali oldugundan scan islemi yapilamiyor

		ÖRNEK:sadece DIRECT BASE CLASSLAR MIL sentaksý ile initialize edilebilir
			
			class X{
				public:
				X(int);
				X();
			};

			class Y : public X{};

			class Z : public Y{
				public:
					Z() : Y() // geçerli çünkü Y Z'nin DIRECT BASE CLASS'I , X(12); // geçersiz çünkü X Z sýnýfýnýn IN-DIRECT BASE CLASS'I{}
			};

			ama öyle bir senaryo var ki sýnýf hiyerarþisinde ki tüm sýnýflarýn doðrudan taban sýnýf deðil ortak taban sýnýf nesnesini intialize etmesi gerekiyor
				
				class X
				{
				public:
					X(const char* p)
					{
						std::cout << "X ctor " << p << '\n';
					}
				};

				class Y : virtual public X {
				public:
					Y() : X("Y ctor\n") {}
				};

				class Z : virtual public X {
				public:
					Z() : X("Z ctor\n") {}
				};

				class D : virtual public Y, virtual public Z // virtual inheritance sayesinde sýnýfýn içinde ortak taban sýnýf olan X nesnesinden bir adet nesne var
				{
				public:
					D() : X("D ctor\n") {} // X D'nin doðrudan taban sýnýfý deðil ama virtual inheritance'dan dolayý D'nin içerisinde ortak olan X taban sýnýf nesnesini initialize etme 
											  görevi artýk D'nin ctorunda
				};

				class E : public D {
				public:
					E() : X("E ctor\n") {} // X E'nin doðrudan taban sýnýfý deðil ama virtual inheritance'dan dolayý E'nin içerisinde ortak olan X taban sýnýf nesnesini initialize etme 
											  görevi artýk E'nin ctorunda
				};

				int main()
				{
					E dx;

				}

				ÇIKTI:
				X ctor E ctor
				Y ctor
				Z ctor
				D ctor
				E ctor
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
RTTI(RUN TIME TYPE INFORMATION)

	çalýþma zamanýnda tür bilgisi elde etmek için kullanýlýr program çalýþýrken bir nesnenin gerçek türünü öðrenmemizi saðlar

	void car_game(Car* p)
	{
		if(p mercedes nesnesini gösteriyor ise onu mercedes olarak kullan)
	}

	dynamic_cast operatörü: Polimorfik sýnýflar arasýnda güvenli tür dönüþümü yapar run time'da DOWN CASTING'IN güvenli yapýlýp yapýlmadýðýný bilgisini verir
		hedef türü
			a)pointer türü
			b)referans türü
			c)void* türü(az kullanýlan senaryo)

		class Base{
			public:
				virtual void foo(){}
		};

		class Der : public Base{

		};

		int main()
		{
			Der myder;
			Base* baseptr = &myder;

			Der* der_ptr = dynamic_cast<Der*>(baseptr); // operand olan baseptr ifadesi polimorfik bir tür olmaasý gerekiyor eðer dönüþüm iþlemi baþarýsýz olursa nullptr deðeri üretilecek


			if (Der* der_ptr = dynamic_cast<Der*>(baseptr)) // scope leakge olmamasý için if with initializer kullanýyoruz
			{
				// programýn akýþý buraya girerse nesnesin artýk Der nesnesi olduðu anlaþýlýr
			}
		}

	DÝKKAT:sýnýf hiyerarþisi olan sýnýflar için static_cast operatörüyle de dönüþüm yapýlabilir ama bu saptama run time'a yöneik bir saptama deðil compile time'a yönelik bir saptama
		
		class A {};
		class B : public A {};
		class C : public A {};

		int main()
		{
			B bx;

			A* ptr = &bx;

			C* cptr = static_cast<C*>(ptr); // kod legal ama ptr'nin gösterdiði nesnesin bir C sýnýfýnýn nesnesi olduðunun garantisi yok static_cast ile yaptýðýmýz dönüþümün
			derleme zamanýnda geçerli olmasý ayný sýnýf hiyerarþisinde olan sýnýflar arasýnda geçerli ama operand olan pointer hedef türü gösteriyor mu göstermiyor mu sorusunun cevabýný
			run time'da vermiyor
		}

		ÖRNEK:

		int main()
		{
			for (int i = 0; i < 10; ++i)
			{
				Car* carptr = create_random_car();

				std::cout << *carptr;

				Volvo* vptr = static_cast<Volvo*>(carptr); // kod legal ama doðru bir kod deðil buraya gelen tür Volvo deðilse örneðin bir Mercedes ise tanýmsýz davranýþ olacak
				vptr->open_sunroof();


				if (Volvo* vp = dynamic_cast<Volvo*>(carptr)) // DOWN CASTING baþarýlý olursa Volvo'nun open sunroof fonksiyonu çaðýrýlacak eðer VOLVOXC90'ýn adresi gelirse VOLVO sýnýfýna 
																 UP CASTING yapýlacak
				{
					vp->open_sunroof();

					eðer hedef türü referans türü olarak seçersek null referans diye bir þey olmadýðý için eðer dönüþüm baþarýsýz olursa bad_cast türünden exception fýrlatýyor
				}

				delete carptr;
		}

	SIDE CAST
		
		Ayný taban sýnýfa sahip olan sýnýf arasýnda yapýlan dönüþüm

		class Base{
			virtual void foo(){}
		};

		class Xder: public virtual Base{};

		class Yder: public virtual Base{};

		class Mder: public Xder,public Yder{};

		int main()
		{
			Mder mder;

			Xder& dx = mder;

			Mder& r_mder = dynamic_cast<Mder&>(dx); // downcast

			Yder& ry = dynamic_cast<Yder&>(dx); // sidecast

		}

		Xder -> Mder (downcast)

		Mder -> Yder (upcast)

		Bu zincirli tür dönüþümüne side cast denir çünkü Xder ve Yder arasýnda doðrudan bir iliþki yok, ama ortak bir alt sýnýflarý (Mder) var.

	VOID POINTER
		dynamic_cast<void*> ile nesnenin gerçek adresini öðrenebiliriz

		Bu genellikle:

			1)Nesne kimliðini (identity) saklamak

			2)Serileþtirme (serialization)

			3)Doðrudan bellekteki yerle ilgili iþlemler gibi özel durumlar için kullanýlýr

		class Base{
			public:
				virtual void foo(){}
		};

		class Der : public Base {};
		class Erg : public Der {};

		int main()
		{
			Base* baseptr = new Erg; // Erg nesnesinin içinde Der var Der nesnesinin içinde de bir Base var bu yüzden geçerli

				taban sýnýf pointerý ile Erg nesnesini gösteriyoruz ama taban sýnýf pointerýnýn deðeri Base* türünden taban sýnýf nesnesini gösteriyor ama biz Erg nesnesinin adresini elde etmek istiyoruz

			void* vptr = dynamic_cast<void*>(baseptr); // run time'da baseptr'nin gösterdiði Erg nesnesinin adresini elde ediyoruz

			Erg nesnesinin adresiyle baseptr'nin adresi ayný olmak zorunda deðil baseptr'nin Erg'i gösteriyor olmasý demek baseptr'nin deðerinin fiziksel olarak Erg nesnesinin adresi demek deðil
			çünkü Erg'in içindeki Base'in adresini tutuyor
		}

	type_info(typeid operatörü): Nesnenin tür bilgisine eriþim saðlar
		
		typeid operatörüyle oluþturulan ifade 2 þekilde oluþturabiliyor
			1)type(int) operaand olarak tür alabiliriz
			2)type(10) operaand olarak ifade alabiliriz

		dynamic_cast operatöründen farký operandý olan ifadenini yada türün polimorfik olma mecburiyeti yok

		typeid ifadesi ile oluþturulan ifade std::type_info sýnýfý  türünden const&

			const std:type_info& r = typeid(10);

		class Myclass{};
		int main()
		{
			std::boolalpha(std::cout);

			std::cout<<typeid(Myclass).name()<<'\n'; // burada gelen yazý standart deðil 
			std::cout << (typeid(m1) == typeid(m2)); // true
			std::cout << (typeid(m1) != typeid(10)); // true
		}

		ÇIKTI: class Myclass
				true true

	ÖRNEK:
		class Base{
			public:
				
		};

		class Der : public Base{};

		int main()
		{
			Der myder;
			Base* baseptr = &myder; // baseptr'nin gösterdiði nese Der sýnýf türünden olmasýna raðmen Base çýktýsý alýnýyor

			std::cout<<typeid(*baseptr).name()<<'\n';
		}
		
		ÇIKTI: class Base

		eðer Base'de polimorfik bir tür olsaydý run time'a iliþkin tür olacaktý  

			class Base{
				public:
				virtual void foo(){}
			};

			class Der : public Base{};

			int main()
			{
				Der myder;
				Base* baseptr = &myder; 

				std::cout<<typeid(*baseptr).name()<<'\n';
			}
		
			ÇIKTI: class Der

		ÖRNEK:
			class Base{
				public:
				virtual void foo(){}
			};

			class Der : public Base{};

			int main()
			{
				Der myder;
				Base* baseptr = &myder;

				if(typeid(*baseptr) == typeid(Der)) // run time'da baseptr'nin türünün Der türünden olup olmadýðýný sýnýyoruz 
				{
					
				}
			}
*/