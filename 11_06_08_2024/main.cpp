/*

special member functionlardan devam ediyoruz

BÝR SINIF NESNESÝNÝN KOPYALANARAK HAYATA GELMESÝ NE DEMEK(COPY CONSTRUCTOR kýsaltmasý CC)
	KOPYALAMA SEMANTÝÐÝ

	bir nesneyi bir baþka nesnenin deðeri ile hayata getiriyoruz yada bir nesneye bir baþka nesnenin deðerini atýyoruz
	
	1)bu nesneler birbirinden baðýmsýz yani bundan sonraki bir nesnenin biri üstünde yapýlan iþlemler diðerini etkilemeyecek yani kopyalamadan sonra bu nesnelerin birbiriyle bir iliþkisi kalmýyor
	2)bu nesneler karþýlaþtýrýlabilir nesnelerse(equality comparable) böyle bir kopyalamadan sonra nesneler ayný deðerde olduðu için karþýlaþtýrma yaparsak elde edeceðimiz deðer true deðeri olur
		Date dx{12,4,1987};
	
		Date dy = dx; // dy nesnesininde deðeri 12,4,1987 olucak
		dy == dx gibi bir iþlem true deðeri verir

	class Myclass{};

	int main()
	{
		Myclass m1;
		Myclass m2 = m1; // m2 nesnesini hayata getirecek constructor copy ctor
		Myclass m3(m1); // copy ctor çaðýrýlýr
		Myclass m4{m1}; // copy ctor çaðýrýlýr
		auto m5 = m2 // Myclass m5 = m2 çýkarýmý yapýlýr

		sýnýfýn copy constructorý olmak zorunda delete edilmiþ olabilir yada implictly declare edilmiþ olabilir ama kesinlikle olmak zorunda

	}
	
	RULE OF ZERO
		sýnýfýn special member functionlarýnýn derleyici tarafýndan yazýlmasý derleyici bizim için dilin kurallarýna uygun bir þekilde special member functionlarýný default ediyorsa iþi derleyiciye býrakýyoruz
		bizim için bu special member functionlarý tanýmlamak için zaten bir gereklilik olmasý gerekiyor derleyicinin yazdýðý fonksiyonlar iþimizi gördüðü noktada iþi derleyiciye býrakmak
		ama öyle durumlar var ki special member functionlarý kendimiz tanýmlamamýz gerekiyor böyle durumlarda derleyicinin tanýmlamasýna býrakýrsak bu durumda UNDEFINED BEHAVIOUR'a sebep olabiliyor 

	DERLEYÝCÝNÝN YAZDIÐI COPY CTOR NASIL BÝR YAPIYA SAHÝP
		class Myclass
		{
			public:  
				Myclass(const Myclass& r){} // derleyici tarafýndan yazýlan derleyicinin implicitly declare ettiði copy ctor sýnýfýn public non-static inline üye fonksiyonudur
				
		};

		int main()
		{
			Myclass m1;
			Myclass m2(m1); // copy ctor çaðýrýldýðýnda this pointerý m2 nin adresi olucak r referansý m1'e baðlanacak
		
		}

	PEKÝ DERLEYÝCÝNÝN YAZDIÐI COPY CTOR NE YAPIYOR
		diyelim ki bu sýnýfýn non-static data memberlarý var

		class Myclass
		{
			public:
				Myclass(const Myclass& r) : ax(r.ax), bx(r.bx) cx(r.cx) {} // derleyici sýnýfýn her bir veri elemanýný parametresi olan l value referansýnýn baðlandýðý nesnenin ilgili elemanýyla hayata getiriyor 
			private:
				A ax;
				B bx;
				C cx; 

			burdan çýkan sonuçlar þunlar
			1)eðer Myclass sýnýfýnýn bu deðiþkenleri int double pointer gibi elemanlarsa diðer nesneninn karþýlýklý elemanýndan alacaklar 
			2)bu türler sýnýf türündense bu durumda aþaðýdaki gibi copy construct edilecekti böylece bizim kopyalama ile hayata getirdiðimiz nesne deðerini diðer nesnenini elemanlarýndan alýyor
				Myclass(const Myclass& r) : ax(r.ax), bx(r.bx) cx(r.cx) {} 
		};
			
		class Date
		{
			public:
				Date(int d, int m,int y) : md{d},mm{m},my{y}
				{
					std::cout<<"Date(int,int,int) this = " << this <<'\n';
				}

				~Date()
				{ 
					std::cout<<"Date() this = " << this <<'\n';
				}
			private:
				int md,mm,my;
				
		};

		int main()
		{
			Date d1 {12,4,1998};
			Date d2 = d1; // burda derleyicinin yazdýðý copy ctor d2 nesnesini hayata getirdi derleyicinin ipmlictly declare ettiði copy constructor sayesinde
		
		}

		ÇIKTI:
		Date(int,int,int) this = 000000735519F548
		Date() this = 000000735519F578 
		Date() this = 000000735519F548

		bu durumda implictly declare ettiði copy ctoru nasýl yazdý
			Date(const Date& r) : md(r.md), mm(r.mm),my(r.my) // derleyicinin impclitly declare ettiði copy ctor
			{
				std::cout<<"Date copy ctor this = " << this << '\n'; // çýktýyý görmek için yazdýk
				std::cout<<"&r = " << &r << '\n'; // r'nin adresi deðerini veren nesnesinin adresi
			}

			int main()
			{
				Date d1{ 12,4,1998 };
				Date d2 = d1; // derleyici aslýnda burda copy ctor'un çaðýrýlmasýnýn gerektiðini function overload resolution ile anlýyor

				std::cout << "&d1 = " << &d1 << '\n';
				std::cout << "&d2 = " << &d2 << '\n';
			}
		ÇIKTI:
		Date(int,int,int) this = 00000069138FF838
		Date copy ctor this = 00000069138FF868
		&r = 00000069138FF838
		&d1 = 00000069138FF838 
		&d2 = 00000069138FF868
		Date() this = 00000069138FF868
		Date() this = 00000069138FF838
		
		COPY CTORUN ÇAÐIRILDIÐI SENARYOLAR
			1)
				class Myclass{};

				int main()
				{
					Myclass m1;
					Myclass m2 = m1;// copy initalization
					Myclass m3(m1); // direct initialization
					Myclass m4{m1}; // direct list initiazaliton
				}

			2)bir fonksiyonun parametresinin sýnýf türünden olmasý(CALL BY VALUE) ve fonksiyonada sýnýf türünden bir argüman geçilmesi
				class Myclass
				{
				public:
					Myclass()
					{
						std::cout << "default ctor this = " << this << '\n';
					}
					~Myclass()
					{
						std::cout << "destructor this = " << this << '\n';
					}
					Myclass(const Myclass&)
					{
						std::cout << "copy ctor this = " << this << '\n';
					}
				};

				void func(Myclass m)
				{
					std::cout << "foo cagirildi: " << "&m = " << &m << '\n';

				}

				int main()
				{
					Myclass m1;
					func(m1); // func fonksiyonunun m parametre deðiþkeni için copy ctor çaðýrýlacak

					std::cout << "&m1 = " << &m1 << '\n';
				}

				ÇIKTI:
				default ctor this = 0000001310AFFB24
				copy ctor this = 0000001310AFFC04
				&m = 0000001310AFFC04
				destructor this = 0000001310AFFC04
				&m1 = 0000001310AFFB24
				destructor this = 0000001310AFFB24
			
			3)bir fonksiyonun geri dönüþ deðeri türünün bir sýnýf türü olmasý ve fonksiyonun return ifadesinin bir sýnýf nesnesi olmasý bu durumda fonksiyonun geri dönüþ deðerini tutucak temporary object için copy ctor çaðýrýlacak
				burda dilin bazý baþka kurallarý devreye giriyor COPY ELISION,RETEUN VALUE OPTIMIZATION, NAMED RETURN VALUE OPTIMIZATION C++17 DE DÝLE EKLENEN MANDOTARY COPY ELISION gibi kurallar devreye giriyor 
				hoca sonra deðinecek 
				
				class Myclass
				{
				public:
					Myclass(const Myclass& r)
					{
						std::cout<<"Copy ctor this = " <<this<<'\n';
					}
					Myclass()
					{
						std::cout << "Default ctor this = " << this<<'\n';
					}
					~Myclass()
					{
						std::cout << "~Destructor() this = " << this << '\n';
					}
				};

				Myclass g;

				Myclass foo()
				{
					std::cout <<"&g " << &g << '\n';
					return g;
				}

				int main()
				{
					foo();
				}
			ÇIKTI:
			default ctor this = 00007FF608071200
			&g = 00007FF608071200
			Copy ctor this = 00000097691CF834
			~Destructor() this = 00000097691CF834
			~Destructor() this = 00007FF608071200

			ÖRNEK:
				// myclass.h
				class Myclass
				{
					public:
						Myclass(const Myclass&);
						// Myclass(const Myclass&) = default; // böylede yazýlabilir cpp de olduðu gibide yazýlabilir
						Myclass(const Myclass&) = delete; // ilerde bizi çok ilgilendiricek eðer böyle bir fonksiyon bildirmiþsek copy ctor'un çaðýrýldýðý senaryolarda delete edilmiþ
						bir fonksiyona çaðrý yaptðýmýz için sentaks hatasý olacak 
				};
				// myclass.cpp
					Myclass::Myclass(const Myclass&) = default // bu bildirim cpp dosyasýnda da yapýlabilir derleyici ilk bildirimde onun default edilmesi gerektiðini görmese cpp dosyasýnda defualt bildirimini görebilir
					ama dikkat aynýsý DELETE bildirimi için geçerli deðil

	HANGÝ DURUMLARDA DERLEYÝCÝ YERÝNE KENDÝMÝZ COPY COSTRUCTOR YAZMALIYIZ
		öyle sýnýflar var ki bu sýnýflar kaynak kullanýyorlar bu kaynak dinamik allocate edilmiþ bir bellek bloðu olabilir bir dosya olabilir bir veri tabaný olabilir gibi gibi
		böyle durumlarda sýnýf nesneneleri bu kaynaðý handle tutuyor

		String str("bugun sinifin ozel fonkiyonlarini isliyoruz"); // özel bir optimizasyon senaryosu olmaadýðý sürece bu yazýyý bir yerde tutmak zorunda dinamik olarak allocate edilen bir dynamic arrayde tutucak 
		ve string nesnesi yazýyý kullanabilmek için dynamic array'in adresine sahip olmak zorunda bu durumda o adreste sýnýfýn bir veri elemaný olan bir pointer tutucak
		
		class String
		{
			public:
				String(const char*);
			private:
				char *mp; // dinamik olarak allocate edilen bellek bloðunun adresini tutacak
				size_t mlen; // yazýnýn uzunluðunu tutacak
		};

		int main()
		{
			String str("bugun sinifin ozel fonkiyonlarini isliyoruz"); 

			String s = str; // value semantik kaybolmuþ oluyor memberwise copy oluyor hayata gelen nesnesinin her bir elemanýný diðer nesnenin elemanýyla initalize edecekti 
			buda nesnelerin birbiriyle iliþkisi bitmiyor s ile str þu an ayný bellek alanýný kullanýyor bu yazý üzerinde deðiþiklik yapýlmasý demek ayný yazý üzerinde deðiþiklik yapýlmasý demek s nesnesinin
			üye fonksiyonlarýndan biriyle str yazýsýný deðiþtirseydik str nesneside bu yazýyý kullanýyor olacaktý bu nesnelerden birinin hayatý bittiðinde bu kaynaðýn destructorda geri 
			verilmesi gerekiyor buna RAII(Resource Acquisition Is Initialization) deniyor kaynak edinimi ilk deðer verme yoluyla olur 
		}

		bu nesnelerin biribirnden baðýmsýzlýðýný kurmak value semantiðini korumak için hayata gelen nesnede ayrý bir dinamik bellek alaný allocate edicek ve baþlatýldýðý deðerlerini kopyalayacak artýk nesnelerin pointer 
		elemanlarý ayrý bellek alanlarýný gösteriyor s ile str birbirinden baðýmsýz olmuþ oluyor

		SHALLOW COPY/MEMBER WISE COPY
			derleyicinin yazdýðý copy ctor elemanlar pointerda olsa kaynaðý gösteren pointerlarýn kopyalandýðýný yani kaynaðýn kendisi deðil kaynaðýn adresini tutan pointer yada referans kopyalanýyor
			
			#define _CRT_SECURE_NO_WARNINGS

			#include <iostream>
			#include <cstdlib>
			#include <cstring>

			class String
			{
			public:
				String(const String* other) : mlen(other->mlen), mp(other->mp) {} // derleyicinin arka planda yazdýðý copy constructor 
				~String()
				{
					if (mp)
						free(mp);
				}
				String(const char* p) : mlen(std::strlen(p))
				{
					mp = static_cast<char*>(std::malloc(mlen + 1));

					if (!mp) {
						std::cerr << "cannot allocate memory\n";
						std::exit(EXIT_FAILURE);
					}

					strcpy(mp, p);
				}
				void print() const
				{
					std::cout << '['<<mp << "]\n";
				}

				size_t length()const
				{
					return mlen;
				}
			private:
				size_t mlen; // yazýnýn uzunluðunu tutacak
				char* mp; // dinamik olarak allocate edilen bellek bloðunun adresini tutacak
			};

			void foo(String s)
			{
				std::cout << "foo cagrildi\n";
				s.print();
				(void)getchar();
			} // programýn akýþý buraya geldiðinde s nesnesinin hayatý bitiyor ve s nesnesinin destructoru çaðrýlýyor ve s nesnesinin mp elemaný tuttuðu dinamik bellek bloðunu free ediyor

			int main()
			{
				String str("bugun sinifin ozel fonkiyonlarini isliyoruz");

				str.print();

				foo(str); // burda s nesnesi hayata getiriliyor ve s nesnesinin mp elemaný str nesnesinin mp elemanýnýn adresini tutuyor

				str.print(); // dangling pointer kullanmýþ oluyoruz
			}

		DEEP COPY
			pointer kopyalanmasýn hayata gelecek nesnede yeni bir bellek alaný allocate etsin o allocate edilmiþ bellek alanýna kendi kaynaðýný edinsin diðerinin kaynaðýndan copy ctor ile hayata gelen
			nesnenin kaynaðýna kopyalama yapýlsýn böylelikle nesneler birbirinden baðýmsýz olmuþ olur

			copy constructorý kendimiz yazýyorsak bütün veri elemanlarýnýn almasý gereken deðerlerini vermekte biz sorumluyuz derleyiciye býrakýrsak default initialize eder

			class String
			{
			public:
				String(const String& other) : mlen(other.mlen)
				{
					mp = static_cast<char*>(std::malloc(mlen + 1));

					if (!mp) {
						std::cerr << "cannot allocate memory\n";
						std::exit(EXIT_FAILURE);
					}

					strcpy(mp, other.mp);
				}
				String(const char* p) : mlen(std::strlen(p))
				{
					mp = static_cast<char*>(std::malloc(mlen + 1));

					if (!mp) {
						std::cerr << "cannot allocate memory\n";
						std::exit(EXIT_FAILURE);
					}

					strcpy(mp, p);
				}
				~String()
				{
					if (mp)
						std::free(mp);
				}
				void print() const
				{
					std::cout << '['<<mp << "]\n";
				}

				size_t length()const
				{
					return mlen;
				}
			private:
				size_t mlen; 
				char* mp;
			};

			void foo(String s)
			{
				std::cout << "foo cagrildi\n";
				s.print();
				(void)getchar();
			}

			int main()
			{
				String str("bugun sinifin ozel fonkiyonlarini isliyoruz");

				str.print();

				foo(str); 

				str.print();
			}

		copy constructorý her zaman kendimizin yazmasýna gerek kalmýyor çünkü standart kütüphane bunu bizim yerimize yapýyor sýnýfýmýzýn elemanlarý baþka sýnýflar türünden kaynak kullanan elemanlarsa 
		onlar kendi kaynak yönetimini kendileri yapýyorlar otomatik olarak deep copy yapýlýyor çünkü onlarýn copy ctoru ona göre yazýlmýþ
			class Student
			{
				int age;
				int id;
				std::string m_address;
				std::vector<int> m_grade;
				// buna rule of zero deniliyor sýnýfýn special member functionlarýnýn yazýmýný derleyiciye býrakmýþ oluyoruz 
				 string ve vector sýnýfý kendi kopyalamalarýndan kendileri sorumlu yani bunu bizim yerimize standart kütüphanede olan sýnýflarýn copy copy ctorlarý yapýyor
			}

		ÖRNEK STRING SINIFINDAN DEVAM
		int main()
		{
			String str("bugun sinifin ozel fonkiyonlarini isliyoruz");

			str.print();
			if (str.length() > 10)
			{
				String sx{"ben blok icinde kullanilan bir yaziyim"};
				sx.print();
				sx = str; // bir sýnýf nesnesine atam operatörü kullanýlarak ayný türden bir sýnýf nesnesi atandýýðnda bu atama iþlemini sýnýfýn özel fonksiyonu olan Copy Assigment yapýyor
							operatör overloading ile yapýlýyor bir sýnýf nesnesini bir operatörün operandý yapýyoruz operandý sýnýf nesnesi olan operatör ifadesini derleyici bir fonksiyona yapýlan çaðrýya dönüþtürüyor 
							bu þekilde çaðýrýlan fonksiyonlara operator function deniliyor 
  				sx.print();
				(void)getchar();

			//  burda iki ayrý nesne var derleyicinin yazdýðý copy assignment sx'nin mp elemanýna str'in mp elemanýnýn adresini atýyor bu yüzden dangling pointer oluyor

			}

			str.print(); // run timeda hata verir 
		}

		burda copy assignment bu þekilde yazýlmalý
			String& operator=(const String& other)
			{
				mlen = other.mlen;
				std::free(mp);

				mp = static_cast<char*>(std::malloc(mlen+1));

				if(!mp)
				{
					std::cerr << "cannot allocate memory\n";
					std::exit(EXIT_FAILURE);
				}
				strcpy(mp,other.mp);

				return *this;
			}

			ama kodda enteresan olan bir durum var

			SORU:
				int x = 10;
				x = x; // sentaks açýsýndan bir hata yok buna self assigment deniliyor semantik olarak nesnenin deðiþmemesi gerekir çünkü kendine atama yapýlýyor,
				self assignment yazdýðýmýz String sýnýfý için olursa bir felaket olur

				str.print();

				str = str;

				str.print(); // other nesnesiyle *this ayný nesne olmuþ oluyor yazdýðýmýz copy assignmentta nesnenin deðeri deðiþmediði halde biz kaynaðý geri verdik bu yüzden ayný nesnenin kaynaðýný geri vermiþ olduk
				bu durumda dangling pointer olmuþ oluyor bu durumda adresleri kontrol etmemiz gerekiyor

			String& operator=(const String& other)
			{
				if(this == &other) // self assignment kontrolü
					return *this;

				mlen = other.mlen;
				std::free(mp);

				mp = static_cast<char*>(std::malloc(mlen+1));

				if(!mp)
				{
					std::cerr << "cannot allocate memory\n";
					std::exit(EXIT_FAILURE);
				}
				strcpy(mp,other.mp);

				return *this;
			}

		self assignment olabilecek farklý bir durum

		void func(Myclass *p1, Myclass *p2)
		{
			*p1 = *p2; // argümana ayný nesne geçilirse self assignment olma durumu yine var
		}

		DERLEYÝCÝNÝN YAZDIÐI COPY ASSIGMENT
			class Myclass
			{
				Myclass(const Myclass& r) : ax(r.ax),bx(r.bx),cx(r.cx) {}
				Myclass& operator=(const Myclass& r)  // geri dönüþ deðeri sýnýf türünden L value referans
				{
					ax = r.ax;
					bx = r.bx;
					cx = r.cx; 

					return *this; // copy assigment kendisine atama yapýlan nesneyi döndürüyor 

					derleyicinin yazdýðý copy assignment sýnýfýn veri elamanlarýna diðer nesnenin veri elemanlarýný copy assign ediyor 
					1)eðer elemanlar primitive türlerdense int'e int'i atamýþ oluyoruz pointer'a pointer'ý atamýþ oluyoruz
					2)fakat bunlar sýnýf türünden nesnelerse bu durumda sýnýfýn copy assignment fonksiyonu çaðýrýlýyor 
				}
				Myclass& set(int){}
				void print()const

			private:
				A ax;
				B bx;
				C cx;
			};

			int main()
			{
				Myclass m1,m2;

				m1 = m2; // burda m2 yi deðiþtirme gayretimiz olmadýðý için copy assignment'ýn paramtresi const Myclass& olmasý gerekiyor

				m1.operator=(m2); // m1 için copy assignment çaðýrýlýyor böylede yazabiliriz
								
				geri dönüþ deðerinin L value referans olmasý 
					1)atama operatörüyle oluþturulan tüm ifadelerin L value olmasýný destekliyor
			
				(m1 = m2).set(12).print(); // böylede yazabiliriz m1 için set fonksiyonu ve print fonksiyonu çaðýrýlýyot
			}

			int x,y,z,t;
			x = y = z = t = foo(); // right associativity özelliði var yani bu ifade saðdan sola doðru deðerlendiriliyor

			x = (y = (z = (t = foo()))); // bu þekilde yazmakla yukarýdaki gibi yazmak arasýnda bir fark yok

			sýnýf türünden olsalardý operatör overloading sayesinde bu yine geçerli olurdu 

			 x.operator=(y.operator=(z.operator=(t.operator=(foo())))); // sýnýf türünden olsaydý bu þekildede yazabilirdik
*/