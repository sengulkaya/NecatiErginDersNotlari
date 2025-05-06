/*

nested typelardan devam

	nested typelarýn class scopeta olmasý
		1)bu isimleri kullanabilmek için sýnýf ismiyle nitelememiz gerekiyor(qualified name)
			class Nec{
				public:
					class Nected{

					};

					enum class Pos {On,Off};
					using Dollar = double;
			};

			int main()
			{
				Nec::Nested x;
			}
			
		2)isim arama kurallarýný deðiþtiriyor

		3)eriþim kontrolü saðlýyor

		4)logic olarak bu sýnýfla iliþkisini vurguluyor yani bu türler bu sýnýfla ilgili vurgusu yapýlýyor

	ENCLOSING CLASS TERIMI
		class Nec{  // burda Nec sýnýfýndan bahsederken enclosing class terimini kullanacaðýz
			public:
				class Nected{

				};

				enum Pos {On,Off};
				usind Dollar = double;
		};
		
		SORU:enclosing class nested type'ýn private elemanlarýna eriþebiliyor mu? HAYIR
			nested class'ýn private bölümü diðer classlara kapalý

			class Nec{
				public:
					class Nested{
						private:
							void foo();
							int mx;

							frined class Nec; // Nec sýnýfýnýn nested type'ýn private elemanlarýna eriþmesini istiyorsak
					};


					void bar()
					{
						Nested ns;

						ns.foo();
						ns.mx = 5; // ikiside sentaks hatasý
						
						bu bildirimlerin geçerli olmasýný istiyorsak Nested class içinde enclosing classa friend bildirimi yapmamýz gerekir

					}
			};

		SORU:peki nested class enclosing class'ýn private bölümüne eriþebilir mi? EVET
			buradaki kurallar modern C++ ile deðiþti
		
			class Nec{
				private:
					static int sval;
				public:
					class Nested{
						private:
							void foo()
							{
								auto val = sval; // geçerli

								auto sz = sizeof(sval);
							}
					};
			};
				sval static olmasaydý sentaks hatasý olur muydu ve olsaydý olmasýnýn nedeni ne olurdu? 
					sentaks hatasý olurdu ama olmasýnýn nedeni private olmasý deðil ortada bir nesne olmadýðý için hata olurdu
					çünkü sval static deðilse sadece Nec türünden bir nesnesinin bir sval'i olabilir
						void foo()
						{
							Nec mynec;
							auto auto = mynec.sval; // geçerli

							auto sz = sizeof(sval); // uneveluated context olduðu için burada dilin kurallarýna göre bir nesneye ihtiyaç yok
						}			

	member functionýn içindeki kullandýðýmýzdaki isim arama kurallarýyla bir ismi sýnýfýn içinde kullanmamýz durumunda isim arama kurallarý birbirinden farklý
		
		struct Data{
			int get()const;
		}

		class Nec{
			Data mdata; // struct Data
			void foo();
			using Data = int;
			Data mval{}; // int Data(önce Nec'in class definition içinde aranýyor)
		};

		void Nec::foo()
		{
			mdata = 5; // invalid
			mval = 5;
			auto x = mdata.get();
			auto y = mval.get(); // invalid
		}

		SORU:
			class Myclass{
				private:
					class Nested{
						public:
							void set(int);
					};
				public:
					static Nested create_nested();
			};

			int main()
			{
				Myclass::Nested nx; // nested type olan Nested class private o yüzden sentaks hatasý

				Myclass::Nested mx = Myclass::create_nested(); // sentaks hatasý
				auto nx = Myclass::create_nested(); // geçerli çünkü eriþim kontrolü ortada bir isim varsa uygulanýyor üstte ki örnekte Myclass::Nested mx ifadesinde oluþan 
				sentaks hatasý eriþim kontrolü ama burada bir eriþim kontrolü söz konusu deðil
				
				nx.set(2); // geçerli
			}

	cppreference.com örneði
		int x, y; // globals

		class enclose
		{
		private:
			int x;
			static int s;

		public:
			struct inner {

				void f(int i)
				{
					x = i; // error can't write to non-static enclose::x wihhout instance
					int a = sizeof x; // error until C++11
					// OK in C++11 operand of sizeof is uneveluated
					// this use of the non-static enclose::x is allowed

					s = i;
					 
					::x = i;
					y = i;
				}

				void g(enclose* p, int i)
				{
					p->x = i; // OK assign to enclose::x (inner class encloing class'ýn private elemanlarýna eriþebilir)
				}
			};
		};

	SORU:enclosing class içerisinde nested class'ýn fonksiyonunu tanýmlayabilir miyiz? HAYIR
		class Enc{
			
			class Nested{
				void foo(int);
			};

			void Nested::foo(int) // bu definition sentaks hatasý ama namespace alanýnda tanýmlayabiliriz
			{

			}
		};

		void Enc::Nested::foo(int) // artýk geçerli
		{
		 
		}

	SORU:fonksiyonu namespacete tanýmlasayadýk foo fonksiyonunun parametresi Nested class türünden olsaydý tanýmýnda Nested ismini nitelemeden kullansak ve Nested
	türünden nesne oluþtursak sentaks hatasý olur muydu? HAYIR çünkü class scopeta kabul ediliyor
		 	class Enc{
			
				class Nested{
				void foo(Nested);
			};

			void Nested::foo(int) // bu definition sentaks hatasý ama namespace alanýnda tanýmlayabiliriz
			{

			}
		};

		void Enc::Nested::foo(Nested) // geçerli
		{
			Nested n;
		}

		ama fonksiyonun geri dönüþ deðeri nested türünden olursa global namespacete fonksiyonun geri dönüþ deðerini yazarken orada artýk scope içinde deðil 
		artýk Enc::Nested þeklinde yazmamýz gerek  
			Enc::Nested Enc::Nested::foo(Nested x) 
			{
				return x;
			}
	
	MÜLAKAT SORUSU:pimpl idiomu(pointer implementation)
		amaç bu idiyom ile sýnýfýn private bölümünü gizlemek

		class Myclass{
			private:
				int mx,my;

				void foo(); 
		}
			sýnýfýn private bölümünün sýnýfýn baþlýk dosyasýnda olmasýnýn duruma göre istenmeyen bazý sonuçlarý var
			yani sýnýfýn private bölümünü hiç göstermeme þansýmýz olsaydý göstermeye göre göstermemenin avantajý ne olurdu?
				
				1)include zincirleri yüzünden compile time'ýn uzamasý önlenir ve dependency'den kurtulmuþ oluruz
					
					nec.h

					#include "a.h"
					#include "b.h"
					#include "c.h"

					bunlarý include etmek demek bunlarýn include ettiði baþlýk dosyalarýnýda include ediyoruz demek

					class Nec{
						private:
							A ax;
							B bx;
							C cx;
					};

					nec.h

						class Nec{
							private:
								struct pimpl;
								pimpl* mp;
						};
					
					nec.cpp
						#include "a.h" // artýk cpp dosyasý bu kodlarý include ediyor
						#include "b.h"
						#include "c.h"

						struct Nec::pimpl{
							A ax;
							B bx;
							C cx;
						};					
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
COMPOSITION
	1)nesne yönelimli progralama tarafýnda sýnýflar arasýnda iliþki biçimini betimliyor
		ASSOCIATION
			bir iþin yapýlmasý için iki sýnýfýn bir arada olmasý gerekiyor sýnýflardan biri diðerini biliyor ve kullanýyor
			
			AGGREGATION
				associationun özel bir biçimi her aggregation bir association diyebiliriz burada farklý olan iki sýnýfn nesnesi birlikte iþini görüyor
				ama sýnýf nesnelerinden bir tanesi diðer sýnýf nesnesinin sahibi durumunda has a relation-ship
				
				COMPOSITION
					aggregation'ýn bir alt kategorisi her composition bir aggregation her aggregationda bir association ama her aggregation bir compostion olmak zorunda deðil 
					aggregation'ýn composition hale gelmesi için sahip olan nesneyle sahip olunan nesne arasýnda ömürsel bir birliktelik olmasý gerekiyor
					örneðin car ve engine aggregationda olabilir compostionda olabilir örneðin araba motoruyla hayata geliyor arabanýn ömrü bittiðinde motorunda ömrü bitiyor

	HAS-A-RELATIONSHIP
		class Engine{

		};

		class Car{
			private:
				Engine m_Eng; // her car nesnesi hayata geldiðinde Engine türünden veri elemanýda hayata geliyor
				Car nesnesi dtor çaðýrýldýðýnda Engine nesnesi içinde dtor çaðýrýlacak hoca buna containment diyor

				Engine* mp; // Car sýnýfý new ifadesiyle nesne oluþturur Car sýnýfýnýn dtoruda nesneyi delete eder
		};

		SORU:Car sýnýfý Engine sýnýfýnýn private bölümüne eriþebilir mi? HAYIR
		
		SORU:Bu nesneler nasýl hayata geliyor? car nesnesi hayata geldiðinde engine nesnesi nasýl hayata gelicek?
		iki car nesnesi birbirine atandýðýnda engine nesneleri birbirine nasýl atanacak? 

		class Car{
			private:
				Engine mx; // her Car nesnesinin içinde bir Engine nesnesi var 
			
			her car nesnesi hayata geldiðinde engine nesneside hayata gelecek car nesnesinin hayatý bittiðinde de engine nesnesinin hayatý bitecek
		};
	
		1)Engine sýnýfýnýn sizeof'u kadar Car sýnýfýnýn sizeof'u artacak
		2)default member initialization kullanýlmadýysa Car sýnýfýnýn derleyici tarafýndan yazýlan ctor'u elemanlarý default initalize eder Car sýnýfýnýn ctoru
		Engine sýnýfýnýn default ctoruna çaðrý yapacak
			
			class Engine{
				public:
					Engine(){
						std::cout<<"Engine default ctor\n";
					}

					~Engine(){
					std::cout<<"Engine dtor\n";

					}
			};

			class Car{
				public:

				private:
					Engine e;
			};

			int main()
			{
				Car mycar; // bir sýnýfýn default initialize edilmesi default ctorun çaðýrýlmasý demek
				ortada doðrudan Engine nesnesini görmesekte Car nesnesini oluþturduðumuzda Car nesnesinin hayata gelme sürecinde
				programýn akýþý Car sýnýfýnýn ctorunun ana bloðuna henüz girmemiþ durumdayken Engine nesnesi hayata gelmiþ olacak bu son derece önemli
				Car nesnesi destroy olduðunda Car sýnýfýnýn dtoru çalýþacak programýn akýþý dtor'un kodunun sonuna geldiðinde memberlar hayata gelme sýrasýyla ters sýrada
				destroy olacaklar
				
				ÇIKTI:
				Engine default ctor
				Engine dtor
			}

			sýnýfýn default ctoru olmasaydý derleyici tarafýndan yazýlan Car sýnýfýnýn default ctoru Engine sýnýfýnýn default ctoruna çaðrý yapacak 
			bir sentaks hatasý oluþacak ama derleyici sentaks hatasý vermek yerine yazmasý gereken speacial member functionu delete edecek
				class Engine{
					public:
						Engine(int){
							std::cout<<"Engine(int) ctor\n";
						}

				};

				class Car{
					public:

					private:
						Engine e;
				};

				int main()
				{
					Car mycar; // derleyici car sýnýfýnýn default ctorunu delete etmiþ durumda  
					
					the default constructor of "Car" cannot be referenced -- it is a deleted function
				}

				Engine() = delete; // Engine sýnýfýnýn default ctoru delete edilmiþ olsaydý derleyic Car sýnýfý için yazmasý gereken default ctoru yine delete edecekti

				DÝKKAT:eðer default member initialization kullanýrsak derleyici implictly declared defaulted olsa bile default member initialization kullanmak zorunda
					class Engine{
						public:
							Engine(int);
					};

					class Car{
						private:
							Engine e{ 4 };
					};

					int main()
					{
						Car mycar; // geçerli
					}
				
				DÝKKAT:ctorun tanýmýný biz yaparsak durum deðiþiyor
					class Engine{
						public:
							Engine(int);
					};

					class Car{
						public:
							Car(){} // sentaks hatasýnýn olma sebebi derleyici býraya MIL sentaksýyla default ctora yapýlan çaðrýyý ekledi Engine sýnýfýnýn default ctoru olmadýðý
										için hata veriyor 'Engine': no appropriate default constructor available

							Car() : e{5}
							{

							}

						private:
							Engine e; // burada default member initialization kullanýlsaydý yukarýda hata olmazdý 
					};

					int main()
					{
						Car mycar; // sentaks hatasý
					}

					DÝKKAT:elemanlarýn hayata gelme sýrasý bildirimdeki sýraya göre esas alýnýr
						class Team{
							Lead x; // 1.sýrada hayata gelecek
							CppDeveloper c; // 2
							BackendDev b; // 3

							MIL sentaksýyla bu sýraya uymayan bir sýrayla bunlarý initalize edersek  
							Team() : c(12),b(2),x() {} // böylede yazsak bildirimdeki sýrayla hayata gelecekler 
						}
			
			1)CTOR
			programýn akýþý run timeda ctorun ana bloðuna girmiþ ise veri elemanlarý artýk hayata gelmiþ durumda buradaki kod veri elemanlarýný kullanýrsa
			hayata henüz gelmemiþ bir veri elemanýný kullanýyor olur muyuz? HAYIR zaten onlar eðer hayata gelmesiyle alakalý bir exception throw etseydi 
			zaten programýn akýþý ctorun ana bloðuna hiç girmemiþ olurdu
			
			2)DTOR
				~Car()
				{
					dtorda sýnýfýn veri elemanlarý dtorun ana bloðundaki kodlarýn hepsi en son anýna kadar çalýþtýðý zaman veri elemanlarý halen hayatta oluyor

				} // programýn akýþý buraya geldiðinde elemanlar hayata gelme sýrasýnýn tersiyle hayata veda edecek

			3)COPY CTOR
				derleyici sýnýf için copy ctor yazarsa yani copy ctoru default ederse elemanlarý copy construct ediyor 
					
					class Myclass{
						public:
							Myclass(const Myclass& other) : ax(other.ax),bx(other.bx),cx(other.cx) // derleyicinin yazdýðý copy ctor
							{

							}

							copy ctoru biz tanýmlarsak bunlar derleyici tarafýndan artýk copy construct edilmeyecek bizim etmemiz lazým eðer etmezsek
							derleyici default construct eder
						private:
							A ax;
							B bx;
							C cx;
					}

					ÖRNEK:
						class Member{
							public:
								Member()
								{
									std::cout<<"Member default ctor\n";
								}

								Member(const Member& other)
								{
									std::cout<<"Member copy ctor\n";
								}
						};

						class Owner{
							private:
								Member mx;

							public:
								Owner() = default;
								Owner(const Owner& other) // copy ctoru kendimiz implemente ettiðimizde elemanlarý copy ctor etmezsek derleyici default construct edecek  
								{
									std::cout << "Owner copy ctor\n";

								}
						};

						int main()
						{
							Owner owner;
							Owner o(owner); 

							ÇIKTI:
							Member default ctor
							Member default ctor
							Owner copy ctor
						}

						Owner(const Owner& other) : mx(other.mx) // elemanlarý copy construct edersek artýk member'ýn copy ctoruda çaðýrýlýr
						{
							
						}

						ÇIKTI:
						Member default ctor
						Member copy ctor
						Owner copy ctor
			4)MOVE CTOR
				copy ctordaki tüm kurallar ile ayný

					class Myclass{
						public:
							Myclass(Myclass&& other) : ax(std::move(other.ax),bx(std::move(other.bx)),cx(std::move(other.cx)) // derleyicinin yazdýðý move ctor
							{

							}
						private:
							A ax;
							B bx;
							C cx;
					}

			5)ASSIGNMENTLAR(sadece copy assignmentý yazdým)
				copy assginment'ý biz tanýmlarsak elemanlarýn copy assign edilmesinden yine biz sorumluyuz
				class Myclass{
					public:
						Myclass& operator=(const Myclass& other) // derleyicinin yazdýðý copy assignment
						{
						
							// derleyicinin yazdýðý kodda bildirimdeki sýrayla her bir veri elemanýna diðer nesnenin veri elemaný atanýyor
							
							ax = other.ax;
							bx = other.bx;
							cx = other.cx;

							return *this;
						}
					private:
						A ax;
						B bx;
						C cx;
				};

				ÖRNEK:
					class Member {
					public:
						Member& operator=(const Member&)
						{
							std::cout << "Member copy assignment\n";

							return *this;
						}
					};

					class Owner {
					public:
						Owner& operator=(const Owner& other) 
						{
							std::cout << "Owner copy assignment\n";
							mx = other.mx;

							// 1 tane bile elemana atama yapmazsak eleman hala kendi deðerini koruyor olacak
							return *this;
						}
					private:
						Member mx;
					};

					int main()
					{
						Owner x, y;

						x = y;
					}
				
		inheritance konusunda olan iliþkiye IS-A-RELATIONSHIP deniliyor
		containmenta alternatif olarak private inheritance türünde özel bir kalýtým biçimi var ileride göreceðiz
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
STRING SINIFI
	nesnelerinin deðerleri yazý olan sýnýf  
			
	DYNAMIC ARRAY
		öðelerin bellekte ardýþýk olarak tutulduðu veri yapýsý

		string sýnýfýda dynamic array elemanlarý char türden olan nesnelerden oluþan bir dinamik dizi

		dinamik dizi veri yapýsýnda index ile elemana eriþmek constant time O(1)
		
		ekleme ve silme iþlemleri sondan yapýldýðý zaman sondan yapýlan ekleme iþleminin karmaþýklýðý AMORTIZED CONSTANT TIME
			bu sorunun cevabý dinamik dizi veri yapýsýndaki kapasite kavramý öðelerin tutulduðu bellek alaný programýn çalýþma zamanýnda dinamik olarak allocate ediliyor
			dinamik olarak allocate edilmiþ bellek alanýnda tutulabilecek öðe miktarýna kapasite deniliyor örneðin 24 tane nesnesinin sýðacaðý kadar bir bellek alaný allocate edilmiþse
			dinamik dizinin kapasitesi 24 ama fiilen tutulmakta olan öðe sayýsý -> size 12,45,9,3,empty,empty,empty,empty burada size 4 çünkü dinamik dizide 4 öðe tutuluyor
			ama 4 tane daha öðeninin tutulabileceði bellek alaný allocate edilmiþ durumda bu yüzden kapasite 8 kapasite deðeri size deðerinden daha büyük olduðu sürece sondan yapýlan 
			ekleme aslýnda bir pointerýn gösterdiði bellek alanýna yazma þeklinde gerçekleþiyor ekleme aþamasýnda öyle bir duruma geleceðiz ki size ile kapasite eþit olacak kapasite 8 iken 
			size deðeri de 8 olacak bu durumda yeni bir bir ekleme istersen sondan ister ortadan olsun yer olmadýðý için baþka bir allocatationa ihtiyaç duyacak re-allocation olmak 
			zorunda en çok problemin ortaya çýktýðý durum re-allocation örneðin kapasite ve size 8 iken api yi kullanarak bir instertion kodu çalýþtýðýnda artýk yeni bir bellek alaný 
			allocate edilecek eski bellek alanýnda ki öðeler yeni bellek alanýna kopyalanacak ama yeniden yapýlan bu allocaton'da kapasite 1.5 kat 2 kat þeklinde arttýrýlacak bu tamamen 
			implementasyona baðlý microsoft kapasiteyi 1.5 kat arttýyor clang gibi implementasyonlarda 2 kat arttýrýyor böylece size kapasiteye eþit olduðunda reallocationla 
			kapasite artacak yine yapýlan sondan eklemeler sabit zamanda olacak iþte bu karmaþýklýða AMORTIZED CONSTANT TIME deniliyor
			bunu kontrol altýna almakta mümkün baþtan kaç öðe tutulacaðýný biliyorsak kapasiteyi rezerve edebiliyoruz
			
			re-allocationda 2 tane dikkat etmemiz gereken konu var
				1)re-allocation text time
					yeniden allocation yapýlacak eski bellek alanýndaki öðeler yeni bellek alanýna kopyalanacak yada taþýnacak
					eski bellek bloðuda serbest býrakýlacak ciddi bir maliyeti var
				
				2)dangling pointer
					eski bellek alanýný gösteren pointerlar yada referanslar invalidate olacak 
					örneðin bir api'yi kullanarak bir ekleme yaptýðýmýzda re-allocationa neden olursa o ekleme size ve kapasiteye eþitken yapýlmýþsa
					eski bellek alanýna iþaret eden pointerlar,referenslar,iteratörler invalid hale gelecek dangling pointer olacak
					dangling deðilmiþ gibi de-reference edersek undefined behavýour olur
		
	STL'DE OLAN CONTAINER KAVRAMI
		burdaki container terimi belirli türden öðeleri bir data structure kullanarak bir arada tutulmasýný kullanýlmasýný saðlayan sýnýflara
		containter sýnýflar deniliyor string,vector,list,deque,set,map gibi container sýnýflar

		doðrudan string isminde olan bir sýnýfýmýz yok basic_string olan bir class template var basic_string<char,std::char_traits<char>,std::allocator<char>> eðer type alias 
		kullanýlmasaydý string sýnýfý türünden bir nesneyi tanýmlamak için böyle yazmamamýz gerekirdi
				
		string sýnýfýnýn interface'i ortalama bir sýnýfa göre çok büyük hocanýn tabiriyle fat class
			
		string sýnýfýnýn yazý iþleri için özelleþtirilmiþ bir container olduuðu için bir index interface'ine sahip fonksiyonlarýn kodlarýný zorlaþtýran önemli
		faktörlerden biri bu ayný fonksiyonun bazý durumlarda hem index interface'ini kullanan bir overloadu hemde iterator interface'ini kullanan overloadu var
			
			index interface'i
				int main()
				{
					std::string str{ "necatiergin" };

					str.erase(6); // 6 indeksinden sonra bulunan tüm yazýlarý siler

					std::cout << str;

					ÇIKTI: 
					necati
				
					burda beklenti 6.indeksteki e'nin silinmiþ olmasý ama 6.indeksten itibaren tüm yazý siliniyor
				}
			
			STL'de bulunan containerlarýn iterator interfacesini kullansaydýk bu sefer istediðimiz indeksteki harfi silmiþ olduk

			int main()
			{
				std::string str{"necatiergin"};

				str.erase(str.begin() + 6);

				std::cout<<str<<'\n';

				ÇIKTI:
				necatirgin // 6.indekste bulunan e harfini bu sefer gerçekten silmiþ olduk
			}

			burda karýþtýrýlan temel nokta iki ayrý interface olduðu buna dikkat etmemiz gerekiyor en çok karýþtýrýlan yerlerden biri

	SMALL BUFFER OPTIMIZATION(SMALL STRING OPTIMIZATION)
		hemen hemen bütün derleyiciler bu optimizasyonu kullanýyor

		derleyici string sýnýfýnýn implementasyonunda string sýnýf nesnesi içinde bir bellek alanýný buffer olarak kullanýyor
		string sýnýfý türünden nesnesinin tutacaðý yazý belirli bir uzunluk deðerine gelmedikçe dinamik bir bellek alaný allocate etmiyor

			void* operator new(std::size_t sz)
			{
				std::cout << "operator new called for the size of: " << sz << '\n';

				if (sz == 0)
					++sz;

				if (void* ptr = std::malloc(sz))
					return ptr;

				throw std::bad_alloc{};
			}

			void operator delete(void* ptr) noexcept
			{
				std::cout << "operator delete called for the address of: " << ptr << '\n';
				std::free(ptr);
			}

			int main()
			{
				std::string str("cengizhan"); // bu yazý aslýnda allocate edilmiþ bir bellek bloðunda deðil doðrudan string nesnesinin içinde tutuluyor
				
				std::string str("developer: cengizhan varli"); // bu sefer sýnýrý aþtýðý için bellek bloðu allocate ediliyor
			}

	size_type
		container sýnýflarýn bazý nested typelarý ortak þekilde isimlendirilmiþ ki generic programlama tarafýnda olmazsa olmaz bir gereklilik
		örneðin container sýnýflarýn string::size_type isimli nested type'ý var türü derleyiciye baðlý olarak deðiþiyor size_type çok deðerli bir nested type
		çünkü global fonksiyonlarda yada member functionlarda aþaðýdaki türler string::size_type'ý türünden deðiþkenlerle ifade ediliyor
		
			1)yazýnýn uzunluðunu döndüren length ve size fonksiyonuun geri dönüþ deðeri türü string::size_type'ý size_t
		
			2)kapasite deðeri

			3)karakterlerinin indexlerini parametre olarak isteyen fonksiyonlar string::size_type türünden

			4)bazý fonksiyonlar bizden tane ve adet deðeri istiyor 5 tane A karakteri

	std::string sýnýfý null-terminated (yani \0 ile biten) byte stream (C-style string) tutmak zorunda deðildir

	cstring demek bir adres demek o adreste sonunda null karakter olan bir yazý var demek (C-style string) 

	string sýnýfýnýn önemli get fonksiyonlarý
		.length()const; yazýnýn uzunluðunu döndürür // geri dönüþ deðeri string::size_type 
		.size()const; containerda olan üye sayýsýný döndürür // geri dönüþ deðeri string::size_type
		.capacity()const; allocate edilmiþ bellek bloðunda kaç öðe tutulabileceðinin deðerini döndürüyor // geri dönüþ deðeri string::size_type
		.empty(const); size'ýn 0 olup olmadýðýný sýnýyor container boþ mu cevabýný döndürüyor true dönerse container boþ demektir // geri dönüþ deðeri bool

		int main()
		{

			std::string str;

			std::cout << "size = " << str.size() << '\n';
			std::cout << "length = " << str.length() << '\n';
			std::cout << "capacity = " << str.capacity() << '\n';

			std::boolalpha(std::cout);

			std::cout << "empty = " << str.empty() << '\n';
		}
	 
		ÇIKTI:

		size = 0
		length = 0
		capacity = 15 // small string optimization sayesinde 15 karakterlik alaný kullanabiliyoruz
		empty = true
	
	CSTRING PARAMETRE(const char*)
		string sýnýfýnýn interface'inde fonksiyonlarýn parametre deðiþkenleri yada deðiþkenleri olacak ve bunlar için bellirli kalýplar var bunlara karþýlýk gelen
		popüler terimler var bazý fonksiyonlar bizden null terminated byte stream isteyecek örneðin bir fonksiyonun parametresi sadece const char* ise bu fonksiyonun
		parametresinin cstring olduðunu anlayacaðýz (C-style string) yani bu fonksiyon bizden null terminated byte stream istiyor demek oluyor böyle bir fonksiyona
		adres geçersek ve geçtiðimiz adresteki yazý null terminated byte stream deðilse undefined behaviour olur 

	DATA PARAMETRE(const char*,size_t n)
		bir fonksiyonun parametresi yine bir null terimated byte stream ve onun yanýna string::size_type'ý(size_t) istiyorsa bu parametrik yapýya data deniliyor
		bu fonksiyon bizden bir adres ve bir tam sayý istiyor kullanacaðý yazý artýk null terminated byte stream deðil verdiðimiz adresten baþlayarak n kadar karater girmemizi istiyor 

	FILL PARAMETRE(size_t,char c)
		string::size_type'ý(size_t) ve char parametre alýyor yani yapmak istediðimiz iþlem örneðin 5 tane A karakteri gibi bir yazý

	SUBSTRING PARAMETRE
		bir baþka string nesnesinin tuttuðu yazýyý kullanacak demek(const std::string&)

		string nesnesinin tuttuðu yazýnýn belirli indeksli karakterinden baþlayarak geriye kalan bütün karakterlerin oluþturduðu substring üstünde
		iþlem yapacak demek(const std::string&,size_t idx)

		string nesnesinin tuttuðu yazýnýn belirli indeksli karakterinden itibaren n tane karakter üstünde iþlem yapacak demek(const std::string&,size_t idx,size_t n)		
*/