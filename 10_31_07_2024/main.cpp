/*
DESTRUCTOR
	önünde tilda tokeni vardýr
	~Myclass();
	1)parametresi olamaz
	2)overload edilemez
	3)geri dönüþ deðeri kavramý yoktur
	4)private yada protected olabilir ama clientler tarafýndan çaðýrýlmasý sentaks hataý oluþturur
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Tüm parametreleri varsayýlan argüman alan constructorlara default constructor denir
	Myclass(); // default ctor

SPECIAL MEMBER FUNCTIONS
	sýnýflarýn bazý üye fonksiyonlarý special member function olarak nitelenmiþ(özel üye fonksiyonlar) bu fonksiyonlarý özel yapan bu fonksiyonlarýn bazý nitelikleri
	modern C++ öncesi bu kategoride 4 adet fonksiyon vardý modern C++ ile 6 ya yükseldi
	bu fonksiyonlarý special yapan 1.özellik
		belirli koþullar saðlandýðýnda bu fonksiyonlarýn kodunun bizim tarafýmýzdan deðil derleyici tarafýndan yazýlabilmesi belirli kurallar ve belirli koþullar oluþtuðunda derleyici bu iþlemi yapabiliyor
	
	1)default ctor
	2)destructor
	3)copy ctor
	4)move ctor // modern C++ ile eklendi
	5)copy assignment
	6)move assignment // modern C++ ile eklendi

	special member functionlar cpp dosyasýndada tanýmlanabilirler class definition içindede tanýmlanabilirler
	
	modern C++ öncesinde derleyici tarafýndan yazýlmasýna fonksiyonun generate edilmesi terimi kullanýlýyordu þimdi derleyici tarafýndan default edilmesi terimi kullanýlýyor
	
	SORU
		1)constructor demek special member function mý demek?
			Cevap HAYIR
			Myclass(int);
			Myclass(int,int); // bunlar special member function deðil
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONSTRUCTOR VE DESTRUCTOR NE ZAMAN ÇAÐIRILIYOR?
	1)STATIC OMURLU NESNELERE ORNEK
		class Myclass
		{
		public:
			Myclass()
			{
				std::cout << "Myclass default ctor this = " << this << '\n';

			}
			~Myclass()
			{
				std::cout << "Myclass destructor this = " << this << '\n';

			}
		};

		Myclass m; // bir sýnýf nesnesini default initialize ettiðimizde derleyici default ctoru çaðýrýr ve nesne default ctor ile hayata gelir

		int main()
		{
			std::cout << "main has just started\n";
			std::cout << "main is finishing\n";

		}

	 ÇIKTI:
		Myclass default ctor this = 00007FF70EF41200
		main has just started
		main is finishing
		Myclass destructor this = 00007FF70EF41200

	SORU:
	ayný kaynak dosyada birden fazla static ömürlü deðiþken oluþtursaydýk bunlarýn hayata gelme sýrasý belirli mi?
	kesinlikle EVET bildirimdeki sýraya göre hayata gelecekler
	Myclass m1,m2,m3 // önce m1 sonra m12 sonra m3 hayata gelecek ama DÝKKAT destructorlar ters sýrayla çaðýrýlacaktý
	önce m3 sonra m2 en son m1 nesnesinin destructorý çaðýrýlýr(hayata son gelen hayata ilk veda eden olur(yaz bunu güzel laf :D))
	
	ÇIKTI:
		Myclass default ctor this = 00007FF688E41202
		Myclass default ctor this = 00007FF688E41200
		Myclass default ctor this = 00007FF688E41201
		main has just started
		main is finishing
		Myclass destructor this = 00007FF688E41201
		Myclass destructor this = 00007FF688E41200
		Myclass destructor this = 00007FF688E41202
	
	SORU:
	Farklý kaynak dosyalardaki birden fazla static ömürlü deðiþkenlerin hayata gelme sýrasý belirli mi ?
	HAYIR belirli deðil buda büyük bir sorun oluþturuyor bu probleme karþýlýk gelen terim STATIC INITIALIZATION FIASCO
		
		cengizhan.cpp
			C cx;

		doga.cpp
			D dx;

		oguzhan.cpp
			O ox;

	bunlarýn hauyata gelme sýrasý çok önemli sýk yapýlan hatalardan biri mesela buradaki CX hayat geldiðinde CX'in constructorý DX'i kullanýyorsa 
	CX'in DX'i kullanabilmesi için DX'inde hayatta olmasý lazým ama böyle bir garanti yok

	2)STATIC OMURLU YEREL NESNELERE ORNEK
		fonksiyonlarýn içinde static anahtar kelimesiyle tanýmlanan deðiþenler

		void func()
		{
			static int cnt{};
			std::cout<<"func" << ++cnt<<".kez cagirildi\n";
			static Myclass m;

			fonksiyon çaðýrýlmadýðý sürece hayata gelmiyorlar 

			fonksiyon çaðýrýldýðýnda constructor çaðýrýlacak ama sadece ilk kez çaðýrýldýðýnda fonksiyon her çaðýrýldýðýnda hayata yeni bir nesne gelmez nesne sadece bir defa hayata gelir
		}

		int main()
		{
			std::cout<<"main basliyor\n";

			func();
			func();
			func();
			func();

			std::cout<<"main sonlaniyor\n";
		}

			ÇIKTI:
			main basliyor
			func 1.kez cagirildi
			Myclass default ctor this = 00007FF654C10204 // ayný nesne hayatýný devam ettiriyor constructor sadece bir defa çaðýrýlýyor
			func 2.kez cagirildi
			func 3.kez cagirildi
			func 4.kez cagirildi
			main sonlaniyor
			Myclass destructor this = 00007FF654C10204

			static ömürlü yerel deðiþkenlerin main fonksiyonunun bitmesinden sonra sonlanýyor,

	3)OTOMATIK OMURLU DEGISKENLER
		programýn akýþý onlarýn tanýmýna her geldiðinde ctor çaðýrýlacak 
		prgramýn akýþý onlarýn scope'unun sonunu belirleyen closing brace'e geldiðinde hayatlarý bitecek
		void func()
		{
			static int cnt{};

			std::cout << "func ["<< ++cnt << "]" << '\n';
			 Myclass m;
			std::cout << "func [" << ++cnt << "]" << '\n';

		}

		int main()
		{
			std::cout << "main basliyor\n";

			func(); // programýn akýþý func'a girdiðinde nesne hayata gelicek ve hayata gelen her nesne farklý bir nesne olmuþ olacak
			func();
			func();
			func();

			std::cout << "main sonlaniyor\n";
		}

		ÇIKTI:
		main basliyor
		func [1]
		Myclass default ctor this = 000000175BCFF754
		func [2]
		Myclass destructor this = 000000175BCFF754
		func [3]
		Myclass default ctor this = 000000175BCFF754
		func [4]
		Myclass destructor this = 000000175BCFF754
		func [5]
		Myclass default ctor this = 000000175BCFF754
		func [6]
		Myclass destructor this = 000000175BCFF754
		func [7]
		Myclass default ctor this = 000000175BCFF754
		func [8]
		Myclass destructor this = 000000175BCFF754
		main sonlaniyor

		otomatik ömürlü nesnelerde hayata bildirildiði sýraya göre geliyor ve destructor hayata gelme sýrasýsýn tam tersi þekilde çaðýrýlýyor
			Myclass m1,m2,m3 

	SORULAR
		1)kaç kez constructor çaðýrýlacak?
			Myclass mx;
			Myclass& r1 = mx;
			Myclass& r2 = mx;

			bir referansý nesneye baðlamamýz bir nesne oluþturmuyor(pointerlar içinde aynýsý geçerli)

			R value referans olsaydý?
				Myclass mx;
				Myclass&& r1 = std::move(mx);
				Myclass& r2 = mx;

			R value referans olmasý yeni bir nesne olmayacaðý anlamýna gelir miydi? EVET ister L value ister R value referans olsun bunlar nesnelere baðlanan
			isimlerdir

		2)Sýnýf elemanlarý dizi türünden olabilir mi? EVET
			Myclass ar[5];
			çok kullanýlmýyor çünkü bunlara daha iyi alternatifler var standart kütüphanenin array sýnýfý gibi

			burda sýrayla dizinin her elemaný için 5 kez constructor çaðýrýlýr 

		3)Mülakatta sorulan soru 1'den 100'e kadar sayýlarý ekrana yazdýracaðýz ama döngü kullanmayacaðýz
			class Myclass
			{
			public:

				Myclass()
				{
					static int count;

					std::cout << ++count << " ";
				};

			};

			int main()
			{
				Myclass m[100];

			}

	HANGÝ DURUMLARDA DEFAULT CTOR ÇAÐIRILIR?
		1)Sýnýf nesnesini default initialize ettiðimizde
			Myclass m;
		2)Value initialization
			Myclass m{};

		ÖRNEK:
			1)most vexing parse örneði
				Myclass m(); // burda nesne tanýmý yapýlmýyor burda bir bildirim yapýlýyor ismi M olan geri dönüþ türü Myclass olan bir fonkiyon tanýmý yapýyoruz
				burda value initialization kullanmamýz gerek

		SORU:
			1)Myclass sýnýfýnýn constructorý var mý?
				class Myclass
				{
					public:
						// EVET var bu konu çok karmaþýk hangi durumda derleyici hangi special member functionlarý bizim için default ediyor ilerde göreceðiz
				}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MODERN C++ ILE DÝLE GELEN ÇOK ONEMLI BAZI OZELLIKLER
	1)Bir fonksiyonun delete edilmesi(delete decleration)
		fonksiyonun olduðunun ama ona yapýlan çaðrýda sentaks hatasý olmasý gerektiðinin bildirilmesi
		
		void foo(int) = delete; // foo int argüman bir deðerle çaðýrýldýðý zaman sentaks hatasý verecek
		
		Neden böyle bir þey kullanmak isteyelim?
			hiç böyle bir bildirim yapmazdýk derleyicide bu durumda ismi arar bulamazdý ama delete bildirimi öyle deðil fonksiyonun var olduðunu 
			ama bunun çaðýrýlmasý durumunda sentaks hatasý oluþacaðýný söylüyor bu ikisi ayný durum deðil fonksiyonun olmamasý durumunda oluþan sentaks hatasý baþka 
			fonksiyonun delete edilmesi yüzünden oluþan sentaks hatasý baþka

		ÖRNEK:delete bildirimi ile bildirilen bir fonksiyonda bir overloadtur
			void foo(int) = delete;
			void foo(double);
			void foo(long);

			int main()
			{
				foo(2.3); // double parametreli seçilir
				foo(34); // sentaks hatasý
			}

	SORU:
		1)global fonksiyonlar delete edilebilir mi? EVET
		2)sýnýflarýn tüm functionlarý delete edilebilir mi? EVET
		3)sýnýflarýn constructorlarý ve destructorlarý delete edilebilir mi? EVET
	
	2)default bildirimi
		bir fonksiyonu default bildirimi ile bildirirsek derleyiciye bunun kodunu sen yazacaksýn talimatý vermiþ oluyoruz
			class Nec
			{
				public:
					Nec() = default; // programcý Nec sýnýfýnýn default constructor kodunun derleyici tarafýndan yazýlmasýný talep ediyor
			};

		SORU:
			1)hangi fonksiyonlar default bildirimi ile bildirebilir?
				special member functionlar
				1)default ctor
				2)destructor
				3)copy ctor
				4)move ctor
				5)move assignment
				6)copy assignment
				yani default bildirimi sadece sýnýflarýn special member functionlarý için yapýlabilir

			ve spaceship operatörü(C++ 20)

	Modern C++ ile dile gelen çok ilginç kurallar var
		special member functionlar þu statülerden birinde olabilir
			not declared(bildirilmemiþ)
			user declared(programcý trarafýndan bildirilmiþ)
			implicitly declared(dilin kurallarý gereði derleyici bu bildirimi yapýyor)

			class Nec
			{
				public:
					Nec(); // user declared
					Nec() = default // user declared
					Nec() = delete // user declared

					Nec sýnýfýnýn default constructorýnýn bildirimi hiç olmasaydý implicitly declared
			
			};

			implictly declared'in 2 kategorisi var
				1)bildiriyor ve default ediyor(impclitly declared defaulted)
					class Nec
					{
						public:
							// implictly declared defaulted derleyici burda örtülü olarak constructorý bildirir
					};

				2)bildiriyor fakat delete ediyor(implictly delete)

					class Nec
					{
						public:
							const int mx; // const nesneler default initalize edilemeyeceði için nesne oluþturulmaya çalýþýldýðý zaman constructorýýn delete edilmiþ olduðu hatasýný verecek
					}

					int main()
					{
						Nec mx; // derleyici burda default constructorý delete ediyor

						öyle durum var ki derleyici bir special member functionu implictly delete edebilir
					}

			SORU: bütün sýnýflarýn default constructorý olmak zorunda mý ? tabi ki HAYIR
				standartta bazý sýnýflarýn default constructor'ý yok
				ama hoca %90 olmasý gerekiyor diyor çünkü bazý araçlarla birlilkte kullanýlacak sýnýflarýn default constructorýnýn çaðýrýlmasý gerekiyor

				mesela bir sýnýf nesnesini bir containerda tutmak istiyoruz 

				std::vector<Nec> vec(10); // burda default constructorýn çaðýrýlmasý gerekir
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MEMBER INITIALIZER LIST(MIL) yada daha çok yaygýn terim CONSTRUCTOR INITIALIZER LIST
	bir constructorýn sýnýfýn non-static veri elemanlarýný initalize etmesini saðlayan sentaks biçimi 

	class Nec
	{
		public:
			Nec()
			{
				mx = 5; // programýn akýýþý constructorýn ana bloðuna girmiþ ise sýnýfýn veri elemanlarý hayata gelmiþ durumda mx ve my'yi hayata gelmiþ olarak düþünüyoruz burda sadece atama yapýyoruz
				hayata gelmiþ olan bir nesneye deðer atamýþ oluyoruz
				my = 3.4;
			}
		private:
			int mx;
			double my;
	};

	MIL sentaksý ile sýnýfýn veri elemanýný hayata getiren onu initialize eden bir sentaks peki bunun farký ne?
	hoca bazý durumlarda bir farký yok diyor ama öyle durumlar var ki
	a)sýnýfýn veri elemaný initalize edilmek zorundaysa default initalize edilemiyorsa MIL sentaksýný kullanmamýz gerekir üstteki const örneðinde kullanmamýz gerektiði gibi
		çünkü zaten default initalize edilemiyorsa derleyicinin yazdýðý constructor her zaman veri elemanlarýný default initalize ediyor
		yada MIL sentaksýný kullanmazsak sýnýfýn veri elemanlarýný default initalize etmiþ oluyoruz
			
	sýnýfýn non-static veri elemanlarý için birinci tercihimiz MIL sentaksýný kullanmak olmalý 
	

	class Nec
	{
		public:
			Nec();
		private:
		iny mx,my;
	};

	cpp
	Nec::Nec() : mx(12),my(34) // member initalizer list sentaks
	{
		// nec sýnýfýnýn default constructorý çaðýrýldýðýnda sýnýfýn mx elemaný hayata 12 deðeri ile baþlayacak my deðeri 34 deðeri ile baþlayacak
		
	}
			
	SORU:constructor initalizer listte tüm non-static veri elemanlarýný initialize etmek zorunda mýyýz? HAYIR 
		eðer initalize etmediðimiz non-static veri elemanlarý varsa derleyici onlarý default initialize edecek eðer onlarýn default initalize edilmesi sentaks hatasý oluþturuyorsa sentaks hatasý olacak
		
		ÖRNEK
		1)const memberlar MIL sentaksý ile initialize edilmek zorundadýr default initalize edilemez
		class nec
		{	
			public:
				Nec();
				const int mx;
		};

		Nec::Nec() : mx(0) {}
		
		2)referanslar MIL sentaksý ile initialize edilmek zorunda default initialize edilemez
			class Nec
			{
				public:
				int& mr;
			};
		
		3)sýnýfýn baþka sýnýflardan veri elemanlarý olduðu senaryolarda MIL sentaksý çok önemli
			
			class Erg 
			{
				public:
					Erg(int); // baþka constructor'ýn bildirimi ile sýnýfýn default constructorý derleyici tarafýndan implictly delete edilmiþ 
			}

			class Nec
			{
				public:
					Nec();
				private:
					Erg e; // Nec sýnýfýnýn default constructorýnýn tanýmýný yaptýðýmýz zaman sentaks hatasý verir çünkü default initialize edilemez sýnýf nesnesinin default initialize edilmesi demek 
							o sýnýfýn default constructorýnýn çaðýrýlmasý demek derleyici tarafýndan delete edildiði için böyle bir bildirimi yapamayýz 
			}

			Nec::Nec()
			{
				// no default constructor exists for class "Erg"
			}
			
			
		ÖRNEK:
			class Nec
			{
				public:
					Nec();
					void print()const
					{
						std::cout << "mx = << mx << " my = " << my << '\n';
					}
				private:
				int mx,my;
			};

			Nec::Nec() {} // derleyici MIL sentaksý ile implict olarak mx ve my deðiþkenini garbage value olarak default initialize eder bu durum UNDEFINED BEHAVIOUR

			int main()
			{
				Nec mynec;
				mynec.print();
			}


		SORU:MIL sentaksýnda Küme parantezi kullanabilir miyiz?
			Nec() : mx{10} {} // Modern C++ ile kullanabiliyoruz NARROWING CONVERSION söz konusu deðil sentaks hatasý unutmayalým 
				
			normalde parantez yerine küme parantez kullanmak anlamsal olarak bir farka yol açmýyor ama öyle yerler var ki parantez yada küme parantez kullanýlmasý kodun anlamýný deðiþtiriyor
			hoca daha sonra bu konuya deðinecekmiþ

		
		class Nec
		{
			public:
				Nec()
				{
					mstr = "necati ergin"; // eðer burada böyle bir kod yazarsak bunun anlamý derleyici önce MIL sentaksý ile mstr yi default initialize eder sonra programýn akýþý programýn ana bloðuna girer
					ondan sonrada bu atama iþi yapýlýr aslýna iki ayrý iþlem yapýlma durumu var 
					1.string sýnýfýnýn default constructorý çalýþacak
					2)atamayý yapmak içinde baþka bir fonksiyon çalýþacak
				}
				std::string mstr;

				Nec() : mstr("necati ergin") // MIL sentaksýný kullansaydýk burda string sýnýfýnýn parametresi const char* olan constructor çalýþacaktý
		};

				
		ÖRNEK:Nesneyi hayata getirdiðimiz sýrayý deðilde ters sýrayý MIL sentaksýnda kullansaydýk ne olurdu
			class Nec
			{
				public:
					Nec() : my(10),mx(20) // burada bu deðiþkenlerin hayata gelmesi sýnýfta ki bildirimm sýrasýna göre esas alýnýr burdaki tanýmlama çok tehlikeli hatalara neden olabiliyor
					{
						// eðer my(10), mx(my / 3) þeklinde bir ifade olsaydý önce mx hayata gelecekti my'nin içinde garbage value olacaktý ve bu durum UNDEFINED BEHAVIOUR olacaktý 
					}

					int mx,my;
			};
				
		MIL sentaksýnýn en önemli olduðu yerlerden biride parametreli constructorlarýn olduðu durum
			class Point
			{
				public:
					Point() : mx(0), my(0) {}
					Point(int x,int y) : mx(x), my(y) {}
				private:
				int mx,my;
			};

		Modern C++'da en çok yanlýþ anlaþýlan konulardan birine deðiniyor hoca
			class Point
			{
				public:

				private:
					int x = 0; 
					int y = 0;
					// bu sentaks modern C++ öncesi yoktu bu sentaks ile sýnýfnn x ve y deðiþkenleri 0 deðeri yapýlmýyor bu sentaksa
					in-class initializer yada default member initializer deniliyor yani memberýn default olarak initialize edileceði deðeri gösteriyor
					eðer yazdýðýmýz constructorlardan birinde MIL sentaksý ile bu veri elemanlarýný initalize etmezsek normalde derleyici bunlarý default edicekti 
					ama derleyici default member initializer ile bizim verdiðimiz initalizer deðerlerini kullanýyor

					eðer MIL sentaksýný kullanmazsak aslýnda derleyici arka planda böyle bir kod ekliyor
					Point() : mx(0), my(0)

					sýnýf içinde parantez atamonu böyle kullanamýyoruz
						int x(10)
			};

		eðer derleyici sýnýdfýn default constructorunu implictly declared ediyorsa derleyicinin yazdýðý default constructor veri elemanlarýnýn hepsini default initialize eder
			class Myclass
			{
				public:
					// bu sýnýfýn default constructorý var derleyici yazdý derleyicinin yazdýðý bu default constructor ne yapýyor?
						dilin kuralalrý derleyicinin implictly declared ettiði bir special member functionun kodunun derleyici tarafýndan nasýl yazýlacaðýný belirliyor
						
				private:
					int mx,my;
			}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	derleyici implictly declare ettiði bir special member functionu tanýmlama sürecinde bir sentaks hatasý oluþursa yani dilin kurallarýný çiðneyen bir durum olursa
	derleyici default etmesi gereken special member functionu delete eder
		Myclass
		{
			public:
			
			private:
				int& r; // sentaks hatasý deðil ama referanslar default initialize edilemez bu yüzden constructor delete edilecek 
				delete edilmiþ constructora çaðrý yapýldýðý zaman sentaks hatasý verir aynýsý const deðerler içinde geçerlidir 
		}

		int main()
		{
			Myclass m; // defaut olan constructora çaðrý yapamayýz sentaks hatasý
		}
		
		ÖRNEK
			class Nec
			{
				private:
					Nec(); // public olsaydý herhangi bir problem olmayacaktý
				
			};
			
			class Myclass
			{
				public:
				 // bu sýnýfýn default constructýrý delete edilmiþtir çünkü Nec sýnýfýnýn constructorý private olduðu için derleyici Myclass sýnýfý için default constructor yazarken 
				 sýnýfýn veri elemanýný default initalize edicek default initalize edilmesi demek default constructorýn çaðýrýlmasý demek ama privare constructýrýn çaðýrýlmasý sentaks hatasý
				 yani derleyici implictly declared edilen bir special member fucntionu default etme giriþiminde buluduðu zaman dilin herhangi bi kuralýný çiðneyen bir yapý oluþursa sentaks hatasý vermek
				 yerine default etmesi gerekn special member functioný implictly declared delete ediyor
				private:
					Nec mynec;
			};

		 derleyici special member functionu dilin kurallarýna göre implictly declare ediyorsa derleyicinin yazdýðý function sýnýfýn non-static public inline member functionýdýr
		 
		 class Nec
		 {
			public:
				Nec() = default // user declared defaulted olduðu için bu kural geçerli deðil 
		 }
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
constructorý ismiyle çaðýrabilir miyiz? HAYIR
	constructorýn diðer special member functionlardan önemli bir farký nokta operatörüyle yada ok operatörüyle çaðýrýlamýyor olmasý
	class Nec
	{
		public:
			Nec();
			Nec(int);
			void func()
	};
				
	int main()
	{
		Nec mynec;
		mynec.Nec(); // sentaks hatasý
	}
				
	ayný durumu destructor için uygulasak kod legal olur ama legal olmasý kodun doðru olduðu anlamýna gelmiyor destructorý kendimiz çaðýrýyoruz sonra ana blok sonuna geldiðinde
	derleyici tarafýndan tekrar destructor çaðýrýlmýþ oluyor

	mynec.~Nec();

	destructorýn böyle kullanýlmasý placement new adýnda bir operatör kullanýmýnda gerekiyor dinamik ömürlü nesnelerle ilgili durumlara izin vermesi için
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
hoca complete type incomplete type konusunu tekrar ediyor
	bir veri türü ya complete typetýr yada incomplete typetýr
		
	derleyici bir sýnýfýn varlýðýndan haberdar fakat o sýnýfýn tanýmýný henüz görmemiþ durumda
		class Myclass; // incomplete type yada forward decleration

		derleyici sýnýf tanýmýný gördüðü zaman artýk complete type olmuþ olur
		
		incomplete type oluþturmanýn bir yolu daha var
			class Myclass* ptr;

		derleyici bir sýnfýn varlýðýndan haberdarsa bir ismin bir sýnýfa iliþkin oldjðunu biliyorsa ama henüz osýnýfýn definitionunu görmediyse derleyici için o sýnýf incomplete type
		ama derleyici class definitionu gördüðü anda derleyici için o sýnýf türü bir complete type

	incomplete typelar ile neler yaparsak sentaks hatasý olmaz
		1)fonksiyon prototype'inde kullanmamýz sentaks hatasý olmaz
			class Myclass;

			Myclass foo(Myclass);

		2)Tür eþ isim bildirimleri
			using Type = Myclass;

		3)incomplete type türlerden pointer deðiþkenler tanýmlanabilir
			class Nec

			Nec* mp; // (object pointer) derleyici Nec sýnýfýnýn ne olduðunu bilmemesine raðmen mp'nin storage deðerinin ne kadar olduðunu biliyor

			Nec* create_nec();
			void foo(Nec*);

			int main()
			{
				Nec* p = create_nec();
				foo(p);
			}

			derleyici bu kodda Nec sýnýfýnýn definitinunu görmüyor olmasýna raðmen hepsi legal 
		
		4)extern bildirimi yapabiliyoruz
			extern Nec mynec; // non defining decleration bu bildirim mynec nesnesinin baþka modüldeki global bir deðiþken olduðunu söylüyor
			derleyiciye nec sýnýf nesnesinin yerini ayýrmasýný söylemiyor yani burda nesne oluþturmuyor

		5)static anahtar kelimesi ile bildirebiliriz
			static Myclass m; 

		incomplete typelar ile neler yapamayýz
			1)incomplete type türünden nesne tanýmlayamayýz
				class Nec;

				Nec mynec;

			2)sýnýfýn kendi türünden veri elemaný olamaz(ama DÝKKAT kendi türünden pointer yada referans elemaný olabilir)
				class Myclass
				{
					Myclass m; // çünkü bu noktada bu incomplete typetýr
				};
			
			ÖRNEK:
				auto sz = sizeof(Myclass); // incomplete türler sizeof operatörünün operandý olamazlar çünkü derleyici myclass için ne kadar yer ayýrmasý gerektiðini bilemez
				
				pointerlarda kullanýlabilir ama pointerý de-reference edecek bir ifade kullanamayýz

					Myclass* foo();

					int main()
					{
						Myclass * p = foo();
						auto x = *p; // incomplete type pointerý de-reference ettiðimiz için sentaks hatasý subscript[] operatörü içinde aynýsý geçerli ok operatörü içinde
						
					}

			hoca programcýlarýn incomplete typelarýn iþlerini gördüðü halde onu complete type haline getirmeleri durumununa deðiniyor
				
				kaveh.h
				
				#include "nec.h" // programcý bu tanýmýn gerekli olduðunu düþünüyor bunu include etmek yerine
				Nec sýnýfý türünden bir incomplete type oluþturabiliriz

				class Nec;

				class Myclass
				{
					Nec* mp; // programcý madem nec sýnýfýný kullanýyoruz hemen include edeyim bari diyor :D
				};

				SORU:include etmenin bir zararý mý var?
					dependency oluþturacaktý hemde compile time uzayacaktý dolayýsýyýla incomplete type'ýn yeterli olduðu yerlerde gereksiz yere complete type'a dönüþtürmememiz gerekiyor

				SORU:void bir tür müdür? EVET 
					ama void doðuþtan bir incomplete bir type
						void x; // sentaks hatasý çünkü incomplete type türden nesne tanýmlamýþ oluyoruz

					bir nesnenini türü void olamaz ama bir ifadenini türü void olabilir peki bu durumlar nelerdir
						1)herhangi bir ifadeyi void türüne dönüþtürmek
						2)function call
							void func();

							int main()
							{
								func(); // ifadenin türü void türü
							}
				SORU:(void)func(); ifadesi ne anlama gelir?
					fonksiyonun geri dönüþ deðeri var ama biz bunu void türüne cast ederek o fonksiyonun geri dönüþ deðerini discard etmiþ oluyoruz ve geri dönüþ deðerini kullanmýyoruz 			
*/