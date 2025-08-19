/*

non-static member functionlarda kalmýþtýk
	
	class Myclass
	{
		public:
			void func(int x);
	};
	
	int main()
	{
		Myclass m;
		Myclass* p = &m;

		(*p).func(35);
		p->func(354);
		 
		// iki þekilde de kullanmak ayný anlama gelir
	}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
GLOBAL FUNCTIONLAR ÝLE MEMBER FUNCTIONLAR ARASINDAKI FARKLILIKLAR
	
	1)member fonksiyonlara nesne adresini yollamýyoruz nokta operatörünün yada ok operatörünün sol operandý olan nesnesnin adresini derleyici kendisi geçiyor
		class Myclass
		{
			public:
				void func(int x);
		}
	
		void globalFunc(Myclass* p,int x;)

		int main()
		{
			Myclass m;
			m.func(24);

			// eðer pointer ile çaðýrmak istersek 
			   Myclass* p = &m;

			   (*p).func(35);
			   p->func(354) // her iki kullanýmda ayný anlama geliyor

			// global fonksiyona nesnenin adresini geçmek zorundayýz
				globalFunc(&m,24);
		}

	2)eriþim kontrolü farký(global fonksiyonlar sýnýfýn private bölümüne eriþemez)

		class Myclass
		{
			private:
				int mx,my;
		}

		void globalFunc(Myclass* p,int x)
		{
			auto a = p->mx; // access controle takýlýr
		}

		Myclass sýnýfý içinde func fonksiyonu olsaydý class scopeta olduðu için private memverlarada eriþebilecekti

	3)scope farklýlýðý
		class Myclass
		{
			public:
				void func(int x); // class scopeta
			private:
				int mx,my;
		}

		void globalFunc(Myclass* p,int x) // namespace scopeta
		{}
	
		int main()
		{
			Myclass::func(235); // burda nesnenin adresi ile çaðýrýlmasý gerekiyor burda context kontrole takýldý static member function olursa geçerli olurdu bu konu iþlenecek 
		}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CLASSLARIN MEMBER FUNCTIONLARININ TANIMI NASIL YAPILIR

2 tane alternatif durum var
	1).cpp dosyasýnda fonksiyonun normal tanýmýný yapmak
		
		Myclass.h
			class Myclass
			{
				public:
					void set(int x,int y);
				private:
					int mx;int my;
			};
		
		Myclass.cpp
			void Myclass::set(int x,int y)
			{
				mx = x;
				my = y;
			}
	2)header fileda yapabiliriz ama implicit inline olmuþ olur ODR çiðnenmemiþ olur
			class Myclass
			{
				public:
					void set(int x,int y),
					{
						mx = x;
						my = y;
					}
				private:
					int mx;int my;
			}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
GLOBAL FUNCTIONLARADA VE MEMBER FUNCTIONLARADA NAME LOOKUP KURALLARI FARKLI
	Myclass.h
		class Myclass
		{
			public:
				void set(int x,int y);
			private:
				int mx;int my; // non-static data member
		};

	Myclass.cpp
		void Myclass::set(int x,int y)
		{
			// bu fonksiyon bir global function olsaydý bir ismi ifade biçiminde kullanýdðýmýzda isim önce 
				1)block içinde aranýr
				2)onu kapsayan block içinde aranýr(enclosing block) 
				3)onuda bulamazsa namespace scopeta aranýr

			// fakat class memberlar için isim arama
				1)block içinde arayýp bulamazsa
				2)class scopeta arar 

				mx = x; // block scopeta class'ýn içindeki mx deðiþkenini gölgeyen baþka bir mx deðiþkeni yoksa class scopeta ismi arar ve bulur
				derleyici burda mx'in non-static data member olduðunu anlar
				my = y;
		}

		int main()
		{
			Myclass m;

			m.set(3,5); // buradaki 3 ve 5 deðeri m nesnesine ait olan mx ve my deðiþkenlerinin deðerleri
			
			3 tane farklý nesneler olsaydý þüphesiz her çaðrýda set fonksiyonunun gizli parametresine aktarýlan adres farklý adres olucaktý her nesne için farklý deðerler biribirnden baðýmsýz olmuþ olacaktý

			Myclass m1,m2,m3;

			m1.set(3,5);
			m2.set(4,7);
			m3.set(6,9);

		}

SORU: Sýnýftan global bir nesne olsa member function içinde o global nesneden private elemanlara eriþebilir miyiz?
		Myclass.cpp
			Myclass g;

			void Myclass::set(int x,int y)
			{
				g.mx = 5; // sentaks hatasý deðil sýnýfýn member functionu sýnýfýn private bölümüne eriþebilir derken bu fonksiyon hangi nesne için çaðýrýlýrsa
				o nesnesnin private elemanýna deðil her ne þekilde olursa olsun private bölümüne eriþebiliyor 
			}

			void Myclass::foo(Myclass& r)
			{
				r.mx = r.my;

				Myclass x;
				x.my = g.my;

				mx = my;

				// hiç biri sentaks hatasý deðil sadece data memberlar için deðil bütün memberlar için geçerli private olan member function olsaydý yine eriþimide herhangi bir problem olmayacaktý veya nested type
			}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
HOCA NAME HIDING KONUSUNA DEÐÝNÝYOR 
	void Myclass::set(int x,int y)
	{
		// block scopeta ki isimler class scopeta ki isimleri maskeleyebilir
			int mx = 45;
			mx // deðiþkenini aradýðýnda block scopeta bulur eðer buna raðmen sýnýfn elemanýna eriþmek istiyorsak 2 yolu var
		
			1)sýnýf ismiyle nitelemek
				Myclass::mx; // direkt sýnýf içinde aranýr
			2)sýnýftan nesne oluþturmak
				Myclass myclass;
				myclass.mx;
	}

	class scopetaki isimde namespaceteki ismi maskeleyebilir
		
		int mx = 56;

		void Myclass::set(int x,int y)
		{
			mx = x; // atama class scopetaki mx'e yapýlmýþ olacak
			::mx = x; // global mx'e eriþmek için unary scope resolutin operatörüyle eriþebiliriz
		}

hem namespace scopeta hem class scope hemde block scopeta mx olsaydý nasýl ayýrt edecektik
		
		class Myclass
		{
			private:
				int mx;
		};

		int mx = 56;

		void Myclass::set(int x,int y)
		{
			int mx = 10;

			Myclass::mx // class scopeta ki mx
			mx // block scopetaki mx
			::mx // namespace scopeta ki mx
		}

SORU:bar fonksiyonu hangi nesnenin adresiyle çaðrýlmýþsa foo fonksiyonuda bar fonksiyonunun içinde ki ayný nesne adresiyle nasýl çaðýrýlýr
	void foo(Myclass *p)
	{};

	void bar(Myclass* p)
	{
		foo(p);
	}

	non-static member functionlarda birbirini çaðýrmasý durumunda derleyici zaten isim aramayla o fonksiyonun non-static member function olduðunu anlayacak
		
		class Myclass{
			public:
				void foo(int x,int y);
				void bar(int x);
			private:
				int mx; int my;
		};

		void Myclass::foo(int x,int y)
		{
			bar(x);
			bar(y);

			// non-static member fonksyiyonlarýn gizli nir parametre deðiþkeni olduðu için foo(Myclass* p,int x,int y) aslýnda derleyici burda bar fonksiyonuna myclass nesnesinin türünden adres zaten yolluyor
				bar(p,x); 
				bar(p,y); // her iki çaðrýadada ayný adresle deðerleri çaðýrýyoruz
		}

		int main()
		{
			
			Myclass x;
			x.Myclass::bar(25); // bu fonksiyonu böylede çaðýrýlabiliriz ama burda nesneyle çaðýrdýðýmýz için Myclass:: olarak nitelemeye gerek yok
		}

 SORU:
	1)
		Myclass
		{
			public:
				void bar(int x);
				void bar(double,double);
		};

		void bar(double);

		void Myclass::bar(int x)
		{
			bar(2.3); // doubledan int türüne dönüþüm olur int parametreli member function çaðýrýlýr burda narrowing conversion söz konusudur
		}

	2)
	Myclass
	{
		public:
			void bar(double);
		private:
			void bar(int x);
	};

	int main()
	{
		Myclass m;
		m.bar(12); // isim bulunur ama access contrele takýlýr sentaks hatasý 

		// burda yanlýþ anlamýþsak double parametreli fonksiyonun çaðýrýlmasýný bekleyebiliriz ama aslýnda burda isim bulunur ve isim arama sonra erer int parametreli fonksiyon seçilir ama private olduðu
			için access controle takýlacak
		}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SINIFIN ÜYE FONKSIYONLARI OLDUÐU ZAMAN BIR FONKSIYONUN SET YADA GET FONKSIYONU OLDUÐUNU NERDEN BILECEÐIZ?

	class Myclass
	{
		public:
			void foo()const; // böyle functionlara const member function deniliyor
			void bar(); // non-const member function yani non-static non-const member function deniliyor :D
	}

	sýnýfa bir interface oluþutururken þu soruyu sormamýz gerekiyor sýnýfa non-static member function mý tanýmlayacaðýz bu fonksiyon sýnýf nesnesini deðiþtirmeye yönelik mi? cevap evet ise kesinlikle 
	non-static non-const member function olacak ama sýnýf nesnesini deðiþtirmeye yönelik deðilse sýnýf nesnesinin deðerini kullanmaya yönelikse mutlaka const member function yapmamýz gerekir bu çok önemli 

	SORU:
		const üye olup olmadýðýný düþünüyoruz kararý þuna göre vermeliyiz sýnýfýn nos-static veri elemanlarýndam birini deðiþtiriyorsa -> non-const deðiþtirmiyorsa -> const member function olmalý saptamasý kesinlikle YANLIÞ
		NEDEN?:hoca bu tarz düþünenlere C tarzý düþünenler diyor 
				non-static fonksiyonun const member function olup olmamasý sýnýf nesnesinin veri elemanlarýyla doðrudan ilgisi yoktur
				sýnýf nesnesinin problem domaininde ki anlamýyla ilgisi vardýr önemli olan nesnesinin stateinin deðiþip deðiþmemesi

		class Fighter
		{
			public:
				std::string cry_name(); // bu const üye foknsiyon olmalý mý olmamalý mý ?
										burda düþüneceðimiz þey sýnýf nesnesinin problem domaninideki anlamý				
		}

		sýnýfýn veri elemanýnýn deðiþitren bir fonksiyon const olabilir mi? EVET 
	
		derleyicinin yaptýðý sentaks kontrolü ile bizim yazdýðýmýz kodun semantik olarak ayný olmak zorunda deðil
		derleyici const member function olmasý durumunda fonksiyonun gizli parametre deðiþkenine const Myclass* parametre deðerini geçiyor
			class Nec
			{
				public:
					void foo(); // non-static non-const member function -> gizli parametre deðiþkeni (Nec*);
					void foo()const; non-static const member function -> gizli parametre deðiþkeni (const Nec*);
			};
	
	SORU
		1)
			class Nec
			{
				public:
					void foo(); // void foo/Nec*)
					void bar()const;
					int mx;
			};

			void Nec::foo()
			{
				mx = 5; // geçerli // p->mx = 5; // gizli parametre ile arka planda olan
			}

			void Nec::bar()const
			{
				mx = 5; // Geçersiz // sýnýfýn const üye fonksiyonlarý sýnýfýn non-static veri elemanlarýný deðiþtiremezler çünkü gizli parametre deðiþkenleri const T*
			}
		
		2)foo fonksiyonu içinde bar fonksiyonunu çaðýrmamýz sentaks hatasý mý deðil mi?
			void Nec::foo()
			{
				bar(); // hata deðil burda dönüþüm T* türünden -> const T* türüne dönüþüm
			}

			ama bar fonksiyonu içinde foo fonksiyonu çaðýrmayý denersek bu aslýnda derleyiciyiyi const T* türünden T* türüne dönüþüm yapmayý zorluyor sentaks hatasý
			
			void Nec::bar()const
			{
				foo(); // sentaks hatasý burda const olmayan bir nesne çaðýrýlýyor
				
				const member functionlar const olmayan member functionlarýný çaðýramaz
				const üye functionlar sýnýfýn data memberlarýný deðiþtiremez
			}
		
		3)kod legal mi deðil mi
			class Nec
			{
				public:
					void bar()const;
				private:
					int *mp;
				};

				int g{}; // namespace scope

				void Nec::bar()const
				{
					*mp = 5; // burasý sentaks ile semantiðin ayrýldýðý yer mp'nin gösterdiði nesnesinin deðerini deðiþtirmek sentaks hatasý deðil

					mp = &g; // eðer mp'ye farklý bir adres atasaydýk bu sefer sentaks hatasý olurdu
				}
			}

		4)
			class Person
			{
				public:
					std::string get_name() const;
				private:
					int m_debug_count = 0;
			
					her üye fonksiyon çaðýrýldýðýnda m_debug_count deðerini bir arttýrýcak böylece herhangi bir noktada bir person nesnesi için m_debug_count ýn deðerini get ettiðimde o sýnýf nesnesi için 
					kaç kez üye fonksiyon çaðýrýldýðýný anlayacaðýz 
			};

			std::string get_name()const
			{
				++m_debug_count; // sentaks hatasý 

				bu fonksiyonun gizli parametresi const Person* low level const bir pointerýn gösterdiði yeri deðiþtirmeye çalýþýyoruz ama semantik olarak bunu deðiþtirmem gerekiyor
				çünkü bu veri elamanýn deðerinin deðiþmesini person nesnesinin problem domainindeki anlamýný deðiþtirmiyor örneðin ismi yaþý parasý deðiþmiyor burda MUTABLE anahtar kelimesini kullanyoruz
				böylelikle derleyiciye diyeceðiz ki bu elemanýn sýnýf nesnesinin problem domainindeki gözlemlenebilir davranýþýyla doðrudan bir iliþkisi yok normalde const bir member function 
				bu deðeri deðiþtiremez ama ben bu anahtar kelimeyi kullandýðýmda deðiþtirmeme izin ver derleyiciye bunu söylemiþ oluyoruz const üye fonksiyonun bunu deðiþtirmesine izin ver demiþ oluyoruz

				bir veri elemanýný mutable olarak bildirmek sýnýf nesnesinin deðerini deðiþmesiyle alakasý yok yani sýnýf nesnesinin problem domainindeki anlamýyla ilgisi yok demiþ oluyoruz 
		
				mutable int m_debug_count

				++m_debug_count; // artýk geçerli

			}

		BARIÞ DOÐA YAVAÞ mutable anahtar kelimesinin baþka bir kullanýmý var mý diye sordu hoca bu anahtar kelimeninin overloadingleri olduðunu söyledi ve
		ilerde özellikle lambdalarda karþýmýza çýkacaðýný söyledi
	
		5)
			class Nec
			{
				public:
					void foo();
					void bar()const;
			};

			int main()
			{
				const Nec mynec;

				mynec.foo(); // mynec nesnesi const foo fonksiyonunun gizli parametre deðiþkeni Nec* biz ona const bir nesne yollarsak const T* türünden T* türüne dönüþüm olmadýðý için sentaks hatasý
				mynec.bar(); // geçerli

				const bir nesne için sýnýfýn sadece const member functionlarýný çaðýrabiliriz
				non-const member functionlarýný çaðýramayýz
			}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
THIS KEYWORD
	bir sýnýfýn non-static member functioný içinde kullanabileceðimiz bir keyword

	THIS NERELERDE KULLANILMAZ
		1)global fonksiyon içinde
		2)sýnýfýn static member functionlarý içinde

	this'in geçerli olarak kullanýlabileceði tek durum sýnýfýn non-static member functionunun tanýmýnýn içinde
		class Myclass
		{
			public:
				void func();
				int x;
		}

		void Myclass::func()
		{
			stc::cout << "this = " << this << '\n'; // this keywordu bu fonksiyon hangi nesne için çaðýrýlýyorsa o nesnenin adresini kullanmýþ oluyoruz

		}

		int main()
		{
			Myclass m,m1;

			std::cout << "&m = " << &m << '\n';
			std::cout << "&m1 = " << &m1 << '\n';

			m.func();
			m1.func();

		}

	her hangi bir nedenle bir fonksiyon hangi nesne için çaðýrýldýysa o nesnenin kendisini kullanmak istiyirosak *this ifadesini kullanacaðýz nesnenin kendisi
		this -> nesnenin adresi
		*this -> nesnenin kendisi

	this pointerýnýn oluþturduðu ifade PR value expression
		fonksiyon içinde this pointerýnýn deðerini kullanabiliriz ama this pointerýn bir nesneymiþ bir L value gibi bir atama yapma giriþimi bulunduðumuzda yada onunn adresini pointerýn kendi adresini
		almayý denersek sentaks hatasý olur

	class Myclass
	{
		public:
			void func();
			void foo();
		private:
			int x;
	};

	void Myclass::func()
	{
		x = 5;
		this->x = 5; // böylede yazabiliriz dimi? evet ama bu sorunun cevabýnýn evet olmasý baþka bu kodlarý böyle yazmamýz baþka
		this->foo();

		this keywordunu sürekli kullanmak gereksiz kod kalabalýðý ve kirli bir görünüm saðlýyor this keywordunun varlýk nedeni bu anlamda kullanmak deðil

		bir data member ile parametre deðiþkeni ayný isme aitse isimlendirmeyi daha mantýklý yapmamýz gerekiyor func fonksiyonunun int x parametresi olsaydý x = x yapmak self assigment olacaktý 
		bu sefer this keywordu yada scope resolution operatörünü kullanmamýz gerekecekti
			Myclas::x = x;
			this->x = x;
		ama böyle kullanýlmamasý gerekiyor burada isimlendirme problemleri var data memberlara isim verirken diðer isimlerden ayýrt edici isimlendirme kullanmamýz gerekiyor 

		sýnýfn data memberlarýnýn baþýna m ön ekiyle baþlatabiliriz yada sonuna _ koyabiliriz 
			mx yada x_ böyle bir durumda this keywordunu kullanmakta gerekmeyecekti
				mx = x;

	THIS KEYWORDUNUN MANTIÐI
		
		1.Senaryo
			bir global fonksiyonumuz olsun
			void fg1(Myclass*);
			void fg2(Myclass&);

			sýnýfýn üye fonksiyonu içinde func hangi nesne için çaðýrýlmýþsa o nesnenin adresiyle global fg1 fonksiyonuna çaðrý yapmamýz gerekiyorsa yada
			func hangi nesne için çaðýrýlmýþsa ayný nesneyi referans semantiði ile fg2 fonksiyonuna argüman olarak göndermemiz gerekiyorsa bunu nasýl yapacaðýz?
			
			void Myclass::func(int x)
			{
				fg1(this); // Myclass*
				fg2(*this); // Myclass&
			}

			int main()
			{
				Myclass m,m1;

				m.func();
				m1.func();

			}
		2.Senaryo
			sýnýflarýn bazý üye fonksiyonlarý yaptýklarý iþin neticesinde hangi nesne için çaðýrýlmýþlarsa o nesnenin adresini ysda o nesnenini kendisini döndürüyorlar
				class Myclass
				{
					public:
						Myclass* foo(); // bu fonksiyon hangi nesne için çaðýrýlmýþsa onun adresi
						// Myclass& foobar(); // daha basit ve sýk kullanýlan senaryo referans
				};

				Myclass* Myclas::foo()
				{
					// fonksiyon en son yaptýðý iþ neticesinde this pointerý döndürecek
					return this; // hangi nesne ile çaðýrýlmýþsa o nesnenin adresini döndürüyor
				}

				Myclass& Myclass::bar()
				{
					// code
					return *this; // hangi nesne ile çaðýrýlmýþsa o nesneninn kendisini döndürüyor
				}

				int main()
				{
					Myclass m;
					m.foo(); // fonksiyonun geri dönüþ deðeri m nesnesinin adresi olacak 
					m.bar(); // fonksiyonun geri dönüþ deðeri m nesneninin kendisi olacak
				}

		*this nesnenin kendisi olduðu için L value expressiondýr ve atama yapabiliriz
			void Myvlass::foo()
			{
				*this =
			}

		eðer sýnýfýn üye fonksiyonu const üye fonksiyonsa this pointerý low level const pointer
			class Myclass
			{
				public:
					void foo()const
					{
						mx = 10;
						this->mx = 10; // her ikiside sentaks hatasý
					}
				private:
					int mx;
			};

			en çok karýþtýrýlan yerlerden biri fonksiyonun geri dönüþ deðeri sýnýf nesnesinin adresi olan const member functionlar
				Myclass* foo()const
				{
					return this; // sýnýfýn member functionu const member functýon olduðu için this pointerýda low level const pointer const T* türünden T* türüne dönüþüm olmadýðý için sentaks hatasý verecek
					bu yüzden foo fonksiyonununda geri dönüþ deðeri const Myclass* olmasý gerekiyor(ayný durum referanslardada geçerli) 
				}

			const overloading member functionlar içinde geçerli
				class Myclass
				{
					public:
						void foo(); // const olmayan nesneler için bu fonksiyon çalýþacak
						void foo()const; // const olan nesneler için bu fonksiyon çalýþacak
				};

				int main()
				{
					Myclass m;
					m.foo(); // const olmayan foo çaðýrýlacak

					const Myclass m1;
					m1.foo(); // const olan foo fonksiyonu çaðýrýlacak
				}

		CHAINING TERIMI
			class Myclass
			{
			public:
				Myclass& foo();
				Myclass& bar();
				Myclass& baz();
			};

			Myclass& Myclass::foo()
			{
				return *this;
			}
			Myclass& Myclass::bar()
			{
				return *this;
			}
			Myclass& Myclass::baz()
			{
				return *this;
			}

			int main()
			{
				Myclass m;
				m.foo().bar().baz();

				m.foo();
				m.bar();
				m.baz(); // þeklindede çaðýrabilirdik bir fark yok ama bazý durumlarda bu chainingten faydalanmamýz bize avantaj saðlayabiliyor
			}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
HOCA INLINE FONKSÝYONLARA TEKRAR DEÐINIYOR
	karýþýtýrýlan bir yer daha var sýnýfýn üye fonksiyonunun sýnýf içinde tanýmlanmasýyla cpp dosyasýnda tanýmlanmasý ayný þey deðildir

	class Myclass
	{
		public:
		void set(int x)
		{
			mx = x;
		}
		private:
			int mx;
	}

	void Myclass::set(int x)
	{
		mx = x;
	}

	global fonksiyonlarda olduðu gibi sýnýfýn üye fonksiyonlarýndada ODR'ý çiðnemememiz gerekiyor ODR'ý çiðnemememiz için fonksiyonun inline olmasý gerekiyor 
	bir sýnýfýn üye fonksiyonunu inline yapmanýn birden fazla yolu var
		1)fonksiyonun tanýmýný header dosyasýnda yapmak(en az yapýlan durum)
			myclass.h
			
			class Myclass
			{
				public:
					inline void set(int x);
				
				private:
					int mx;
			}

			inline void Myclass::set(int x)
			{
				mx = x;
			}

		2)fonksiyonun tanýmýný direkt class definition içinde yapmak
			class Myclass
			{
				public:
					void set(int x)
					{
						mx = x;
					}

				bir fonksiyonun tanýmýný class definition içinde yapmak fonksiyonu örtülü olarak inline yapýyor
			};

		SORU SORULDU:sýnýf içinde bildirimi inline yapsak cpp dosyasýnda tanýmýný yapsak inline expansion þansý olabilir mi?
			derleyici fonksiyonun tanýmýný görmediði için herhangi bir þekilde inline expansion yapma þansý doðurmaz
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SINIF NESNELERÝNÝN HAYATA BAÞLAMASI VE HAYATLARININ SONLANMASI
	
	bir sýnýf nesnesinin hayata baþlamasýný saðlayan sýnýf nesnesini kullanýlabilir bir varlýk haline getiren sýnýfýn bir üye fonksiyonu fakat böyle üye fonksiyonlar için özel bir terim kullanýyor
		constructor
	
	bir sýnýf nesnesinin hayatý bittiðinde sýnýfýn üye fonksiyonuna yapýlan çaðrýnýn adý
		destructor
	
	bu fonksiyonlara iliþkin kurallar
		1)constructor ve destructor sýnýfýn member functionu
		2)global fonksiyon olamazlar
		3)sýnýfýn statik member functionu olamýyorlar
		4)sýnýfýn non-static non-const member functýonu olmak zorundalar
		
	CONSTRUCTOR
		1)sýnýfýn constructorýnýn ismi sýnýfýn ismiyle ayný olmak zorunda
			class Myclass
			{
				public:
					Myclass();
			}
		2)constructorýn geri dönüþ deðeri yok

		3)constructor'ýn const member function olmasý sentaks hatasý
			Myclass()const;

		4)overload edilebilirler
			Myclass();
			Myclass(int);
			Myclass(double);
			Myclass(int,int); // function overload resolution burdada geçerli olacak

		5)sýnýfýn constructorý private ve protected olabilir ama clientlar tarafýndan çaðýrýlmasý sentaks hatasý

		6)class definition içinde de tanýmý yapýlabilir(örtülü olarak inline olurlar)

*/