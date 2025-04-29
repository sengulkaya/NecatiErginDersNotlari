/*

SINIFLARIN STATIC MEMBERLARINDAN DEVAM

	geçen ders anlatýnlar tekrar edildi

	sýnýfýn ctorunun private olmasý 
	
		class Nec
		{
			private:
				Nec(int x){}
			public:
				static void foo()
				{
					Nec x(10); // bazý örüntülerde sýnýfýn ctorlarýný private yapýp ctormuþ gibi member functionlar oluþturabiliriz

				}
		}

	NAMED CTOR IDIOM(ÝSÝMLENDÝRÝLMÝÞ CTOR ÝDÝYOMU) 
		aslýnda ctor deðil ama ctormuþ gibi davranan static member functionlardýr
		
		1)ctorlarýn client kodlar tarafýndan doðrudan çaðýrýlmasýný istemiyoruz o yüzden private yapýyoruz ama sýnýfýn static member functionlarý sýnýfýn member functionu olduðu için
		onlarýn private ctora eriþmesi bir sentaks hatasý deðil
		
		2)named ctor idiomu kullanma sebebimiz
			a)nesneyi oluþturmanýn tek bir noktadan yapýlmasý
			b)nesneyi belirli bir biçimde oluþturulmasýnýn mecburi hale getirmesi içinde kullanýlabilir
				class Complex{
					private:
						//Complex(double r, double i);
						//Complex(double angle, double distance,int dummy); // dummy parametre olmasaydý ikiside sentaks hatasý çünkü sýnýflarýn member functionlarý re-definition edilemez o yüzden 
						imza farklýlýðý olarak dummy parametresini ekleyip overloading mekanizmasýna çevirebiliriz

					public:

						static Complex create_cartesian(double r,double i)
						{
							return Complex(r,i);
						}
						static Complex create_polar(double angle,double distance)
						{
							return Complex(angle,distance,0);
						}
				};
			c)belirli bir nedenle sýnýf türünden nesnelerin sadece dinamik olarak oluþturulmasýný istiyorsak
				class DynamicOnly{
					private:
						DynamicOnly(){}
					
					public:
						static DynamicOnly* create_object()
						{
							return new DynamicOlny;
						}
				};

				int main()
				{
					auto p = DynamicOnly::create_object();
				}

	ÖRNEK:kaç tane nesne var ve ne kadar nesne hayatta
		#include <iostream>
		class Nec {
		public:
			Nec()
			{
				++ms_live_count;
				++ms_lived_count;
			}

			~Nec()
			{
				--ms_live_count;
			}

			static int get_live_count() { return ms_live_count; }
			static int get_lived_count() { return ms_lived_count; }

		private:
			inline static int ms_live_count{};
			inline static int ms_lived_count{};// sadece static anahtar kelimesiyle bildirseydik ve cpp dosyasýnda tanýmýný yapsaydýk zero initialize edilecekti ama cpp
						tanýmýný yapmasaydýk bu sadece bildirim olduðu için link zamanýnda hata verecekti ama þimdi inline olarak tanýmladýðýmýz için zero initialize edilecek
		};

		int main()
		{
			Nec n1, n2, n3;

			std::cout << Nec::get_live_count() << '\n'; // 3 çýktýsý

			Nec n4;
			std::cout << Nec::get_live_count() << '\n'; // 4 çýktýsý

		}

	ÖRNEK:bir sýnýf türünden nesnelerin birbiriyle hayatta olan diðer nesnelerle iletiþimini saðlamak
		class Fighter {
		public:
			Fighter() = default;
			Fighter(const std::string& name) : m_name(name)
			{
				msvec.push_back(this);
			}
			~Fighter()
			{
				std::erase(msvec, this);
			}

			Fighter(const Fighter&) = delete;
			Fighter& operator=(const Fighter&) = delete;

			void ask_for_help()
			{
				std::cout << "ben savasci " << m_name << '\n';
				std::cout << "dusman kabile beni oldurecek\n ";

				for (auto p : msvec)
				{
					if (p != this)
					{
						std::cout << p->m_name<<' ';
					}
				}
				std::cout << "\n yetisin yardim edin kosunnnnnn :D";
			}

		private:
			inline static std::vector<Fighter*> msvec;
			std::string m_name;
		};

		int main()
		{
			Fighter f1{ "fatih" };
			Fighter f2{ "oguzhan" };
			Fighter f2{ "rasul" };

			auto fp1 = new Fighter("cagri");

			fp1->ask_for_help();

			auto fp2 = new Fighter("necati");

			delete fp2;

			fp1->ask_for_help(); 

		}

SINGLETON
	bir sýnýf türünden tek bir nesne olacak ve o nesneye global bir eriþim söz konusu olacak 

		class Singleton{
			public:
				Singleton(const Singleton&) = delete;
				Singleton& operator=(const Singleton&) = delete;

				static Singleton* get_instance()
				{
					if(!mp)
						mp = new Singleton;

					return mp;
				}

				void foo();
				void bar();
				void baz();

			private:
				Singleton();
				inline static Singleton* mp{};
			};

		int main()
		{
			Singleton::get_instance()->foo();
			Singleton::get_instance()->bar();
			Singleton::get_instance()->baz();

			Singleton* p1 = Singleton::get_instance();

			Singleton* p2 = Singleton::get_instance();
		}

	MAYERS SINGLETON
		static Singleton& get_instance()
		{
			static Singleton instance

			return instance;

			1)static yerel nesneler için ctor bu fonksiyon için ilk kez çaðýrýldýðýnda çaðýrýlýyor
			2)static yerel deðiþkenlerin initializationu thread safe bir senkranizasyon oluþturmamýz gerekmiyor

		}
		void foo();
		void bar();
		void baz();
	private:
		Singleton();
	};

	int main()
	{
		Singleton::get_instance.foo();
	}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NAMESPACE(ÝSÝM ALANLARI)
	  namespace nec{

	  } // burada el alýþkanlýðý olabilir ama noktalý virgül yok 
	
	namespaceler global namespacetelerdir

	1)isim alanlarý local düzeyde oluþturulamaz
		int main()
		{
			namespace nec{ // sentaks hatasý

			}
		}
	
	2)bir namespace içindeki namespaceten bahsettiðimiz zaman kullanýlan terim NESTED NAMESPACE
		namespace nec{
			namespace erg{

			} 
		}

	3)bir namespace'in ismi olmasýna gerek yok ama bu bir özel durum buna UNNAMED NAMESPACE deniliyor
		namespace { }

	4)namespaceler isim çakýþmalarýný önlüyor
		int x = 5;

		int x = 7; // ayrý namespacelere alýrsak her hangi bir sentaks hatasý olmaz

		namespace nec{
			int x = 5;

		}

		namespace erg{
			int x = 7;
		}

	5)global namespace alanýnda yapýlan her tanýmlamayý namespace içindede yapabiliriz
		namespace nec{
			void foo();

			class Myclass{};
		}	

	6)namespace bir scope 
		SORU:function overloading olur mu? HAYIR çünkü scopelarý farklý
		
		namespace nec{
			void foo(int);
		}

		namespace erg{
			void foo(double);
		}

		namespace nec{
			void foo(int);

			namespace erg{
				void foo(double); // yine function overloading olmaz farklý scopetalar
			}
		}

	7)namespace içindeki bir ismi isim aramayla buldurmak için scope resolution operatörü kullanýlýyor
		namespace nec{
			int x;
		}

		int main()
		{
			nec::x; // derleyiciye burda x ismini nec namespace'i içinde arayacaksýn talimatýný veriyoruz
		}
	
	8)namespaceler kümülatif bir yapýya sahip
		namespace nec{
			int x = 5;
		}

		namespace nec{
			int y = 5;
		}

		namespace nec{
			int z = 5;
		}

		eðer derleyici bir namespace definitionla karþýlaþtýktan sonra ayný definition ile yine karþýlaþýrsa bunu ayný namespace olarak kabul eder
		
		namespace nec{
			int x = 5;
			int y = 15;
			int z = 7; // kodun bu þekilde derleyiciye sunulmasasýyla üstteki gibi sunulmasý arasýnda bir fark yok
		}

		neden böyle bir olanak saðlanmýþ? HEADER FILE'LAR ÝÇÝN
			örneðin vector baþlýk dosyasýný include ettiðimizde std namespace alanýndaki öðelerde geliyor
			list baþlýk dosyasýný include ettiðimizde ordakilerde geliyor bunu saðlayan bu kümülatif yapý

		SORU:sentaks hatasý mý deðil mi? SENTAKS HATASI AYNI NAMESAPCE ÝÇÝNDELER
			namespace nec{
				int x;
			}

			namespace nec{
				void x(int);
			}

	9)C++17 ile nested namespaceler bir defada tanýmlanabiliyor
		namespace nec{
			namespace erg{
				namespace proj{
					double x = 5.4
			}

			}

		}

		namespace nec::erg::proj{ // bu taným derleyiciye nec'in bir namespace olduðunu ama erg'in nec namespace'i içinde bir nested namespace olduðunu proj'unda erg namespace'i 
									içinde bir nested namespace olduðunu anlatýyor
			double x = 5.4;
		} 

		kümülatif olma durumu burdada geçerli
			namespace nec{
				int a = 6;
			}

			namespace nec::erg{
				int b = 7;
			}

				
			int main()
			{
				nec::a++;

				nec::foo();

				nec::erg::b++;
			}

	SORU:nested namespace içinde onu içine alan enclosing bracete ki namespaceteki isimlere eriþebilir miyiz? EVET
		
		namespace nec{
			int x = 5;
				namespace erg{
					void foo(int a)
					{
						x++; // 1)isim önce block içinde aranacak
								2)erg namespace'i içinde aranacak orda bulunamazsa nested namespace içinde aranacak
					}
				}
		}

USING KEYWORD
	bir ismi nitelemeden ismin yinede namespace içerisinde aranmasýný saðlayan araçlar var
		1)using decleration
			namespace nec{
				int x;
			}

			int main()
			{
				using nec::x; // bu bir decleration bunun bir bildiriminin olmasý bununda bir scope'unun olmasý demek
				örneðin block içinde bildirmekle global isim alanýnda bildirmemiz arasýnda fark var using bildirimi ile tanýtýlan isim
				bildiriminin olduðu scope'a enjekte edilir yani adeta o scopeta tanýmlanmýþ gibi etki yapar
				
				x = 10; // using bildiriminin görülür olduðu yerlderde bu ismi kullandýðmýz zaman derleyici isim aramayla using nec::x bildirimini görücek
				ve bu ismin nec namespace'inde olduðunu anlayacak
			}
			
			eðer bu bildirim global isim alanýnda yapýlsaydý hepsinde görünür olurdu
				
				void foo(){
					x = 5;
				}

				void bar(){
					x = 7;
				}

			ÖRNEK:
				namespace nec{
					int x;
				}

				namespace erg{
					using nec::x; // x ismi erg namespace'ine enjekte edilir
				}

				int main()
				{
					erg::x; // bu isim direkt erg namespace'indeymiþ gibi kullanýlabilir
				}
		
		DÝÐER KONULAR SONRAKÝ DERSLERDE GÖRÜLECEK

		2)using namespace directive
		3)ADL
		4)C++17 ve sonrasý için inline namespace(sonra görülecek)
*/ 