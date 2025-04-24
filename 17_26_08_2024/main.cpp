/*

bool türüne dönüþüm yapan operator bool fonksiyonunda kaldýk

	bazý türler pointer like türker için yani nesneleri pointer gibi kullanýlabilecek türler için týpký nullptr semantiðinde olduðu gibi nullable type oluþturabilmek için
	operatör bool fonksiyonunu overload ediyoruz böylece logic bir ifade beklenilen yerde sýnýf türünden nesneleri kullanabiliyoruz örneðin smartptr sýnýfý

	operator bool fonksiyonunun ilginç bir özelliði var

		class Nec{
			public:
				operator bool()const // // Nec nesneleri bool ifade beklenen bir baðlamda bool türüne bu fonksiyon ile dönüþtürülebilir olacak
				{
					return true;
				}
		};

		int main()
		{
			Nec mynec;
			int x = mynec; // bu kodun implicit olarak legal olmasýný istemeyiz çünkü derleyici önce sýnýfýn operator bool fonksiyonuna çaðrý yapýyor 
			bool türünden bir ifade ediliyor bool türündende int türüne dönüþüm olduðu için her hangi bir þekilde bir sentaks hatasý olmuyor bu yüzden explicit olmasý gerekiyor
		
			Nec n1,n2;

			auto x = n1 + n2; // derleyici toplama operatörünün operandlarýnýn Nec türünden olduðunu görünce toplama operatörünün operandý olabilecek bir dönüþüm mümkün mü
			diye bakýyor ve sýnýfýn operator bool fonksiyonu olduðunu görüyor böylece her iki nesneyide bool türüne dönüþtürüyor bu durumda toplama operatörünün her iki operandý bool türünde
			olmuþ oluyor burada integral promotion ile int türüne yükseltilecekler ifadenin türü int olacak ve geri dönüþ deðeri true(1) ürettiði için deðeri 2 olacak
			
			operator bool fonksiyonu explicit olsa bile logic bir ifade gereken yerde dönüþümü yapýyor ama logic baðlam olmayan yerlerde örtülü dönüþüm engellenir
				if(n1 && n2){} // geçerli
				auto b = !n1; // geçerli
		}
	
	ÖRNEK:
		
		int main()
		{
			int x;
			while(std::cin >> x)
			{
				std::cout<<x<<'\n'; 
			}

			burada  cin nesnesinin kendisini kullansaydýkda bu kod legal olacaktý
			while(std::cin) peki bu nasýl legal oluyor? çünkü istream sýnýfý için operator bool overload edilmiþ 
			aslýnda derleyici burada while(cin.operator>>(x).operator bool()) fonksiyonuna çaðrý yapýyor

		}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ENUMARATION TYPES ÝÇÝNDE OPERATOR FONKSÝYONU YAZILABÝLÝR
	class type olmadýklarý için member functiona sahip olamazlar global operator fonksiyonu olarak operator fonksiyonlarý tanýmlayabiliriz

	peki bunlarýn operator overloading ile ne ilgisi var?
	WeekDay türünden bir deðþken ++ operatörünü yada -- operatörünün operandý olduðunda günün 1 artmasý çok doðal bir koddur
	yada << operatörü sayesinde günün hangi gün olduðunu yazdýrmasýný isteyebiliriz

	enum class WeekDay{

		Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday
	
	};

	std::ostream& operator<<(std::ostream& os, const WeekDay& wd)
	{
		constexpr const char* wDays[7] = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday"
		};

		return os << wDays[static_cast<int>(wd)];
	}
	WeekDay& operator++(WeekDay& wd) // prefix
	{
		return wd = wd == WeekDay::Saturday ? WeekDay::Sunday : static_cast<WeekDay>(static_cast<int>(wd) + 1);

	}

	WeekDay operator++(WeekDay& wd, int) // postfix
	{
		auto ret = wd;
	
		++wd;

		return ret;
	}

	WeekDay& operator--(WeekDay& wd) 
	{
		return wd = wd == WeekDay::Sunday ? WeekDay::Saturday : static_cast<WeekDay>(static_cast<int>(wd) - 1);

	}

	WeekDay operator--(WeekDay& wd, int)
	{
		auto ret = wd;

		--wd;

		return ret;
	}


	int main()
	{

		WeekDay wd = WeekDay::Monday;

		std::cout << wd;

		WeekDay wd{WeekDay::Saturday};
		for (int i = 0; i < 5; ++i)
		{
			std::cout << ++wd<<'\n';
		}



		WeekDay wd{ WeekDay::Saturday };
		for (int i = 0; i < 5; ++i)
		{
			std::cout << wd++ << '\n';
		}
	}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DÝNAMÝK ÖMÜRLÜ NESNELERLE TANIÞMA
	
	dinamik ömürlü nesne ne demek ve nesnenin bellekte tutulacaðý yer nasýl elde edilecek ayrý sorulardýr

	new Date
	new int
	new Fighter // bu ifadelerin türü bir pointer türü 

	DÝKKAT:new operatörü baþka bir terim operator new ayrý bir terim operator new bir fonksiyon C den gelen malloc fonksiyonuyla ayný parametrik yapýda
	void* operator new(size_t); 

	derleyici bir new ifadesiyle karþýlaþtýðýnda öncelikle operator new fonksiyonuna çaðrý yapýcak bir kod oluþturuyor
	bu fonksiyona argüman olarak new'e operand olan türün sizeof deðerini geçiyor 

	malloc ile operator new kýsmen ayný olduðuna göre neden malloc olarak kalmadý?
		malloc baþarýsýz olduðunda nullptr döndürüyor operator new ise baaþrýsýz olduðunda exception throw ediyor
		operator new baþarýlýysa derleyici ürettiði kodda operatör newden aldýðý adresi this pointerý kullanýlacak þekilde sýnýfýn ctoruna çaðrý yapýyo
		
		new ifadesi aslýnda derleyicinin 2 ayrý kodu üretmesini saðlýyor
		1)dinamik ömürlü nesnenin yerinin elde edilmesi için standart kütüphanenin operator new fonksiyonuna çaðrý yapmak
		2)elde edilen allocate edilen bellek bloðunda nesneyi oluþturmak içni sýnýfýn ctoruna çaðrý yapmak

		exception throw edilmediyse new Object ifadesiyle construct edilmiþ nesneni adresini elde etmiþ oluyoruz ayrý bir initalization söz konusu deðilse
		default initialize edilmiþ nesne için default ctro çaðýrýlacak 

			class Myclass
			{
				public:
					Myclass(int x)
					{
						std::cout<<"Myclass(int x) x = " << x<<'\n';
						std::cout<<"this = " << this << '\n';
					}
					~Myclass()
					{
						std::cout << "Myclass dtor this " << this<<'\n';
					}
					void foo(){}
					void bar(){}

					int ar[16]{};
			};

			int main()
			{
				Myclass* p = new Myclass(12); // derleyici önce operatör nee fonksiyonuna çaðrý yapýcak operator new fonksiyonu baþarýlý olursa allocate edilmiþ bellek bloðunun adresini
				void* olarak döndürecek derleyicide o adreste Myclass nesnesinin oluþturulmasý için sýnýfýn ctoruna çaðrý yapýcak
				
				p->bar();
				p->foo(); 

				std::cout<<"p = " << p <<'\n';

				dinamik ömürlü nesenin hayatýný sonlandýrmak için delete ifadesiyle sýnýfýn destructoruna çaðrý yapýyoruz operand olarak dinamik ömürlü bir nesnenin adresini alýyor
				delete p; // destructor çaðýrýlýr

				DÝKKAT:delete operatorüyle operator delete fonksiyonunu karýþtýrmamamýz lazým
				void operator delete(void *vp); 

				delete ifadesi ne yapýyor?
					1)derleyici delete ifadesi karþýlýðý önce delete operatörünün operandý olan adresteki sýnýf nesnesi için sýnýfýn dtoruna çaðrý yapýyor
					derleyici arka planda böyle bir çaðrý yapýyor  p->~Myclass()
					2)nesnemizin yerini operator new almýþtý onun geri verilmesi içinde operator new fonksiyonu
					tarafýndan elde edilen adresin operator delete fonksiyonuna geçilmesi gerekiyor  operator delete(p); böylece operator delete fonksiyonu hayatý bitmiþ olan 
					nesnenin bellek alanýný de-allocate ediyor

				new ifadesi
					1)allocation 
					2)construction
				delete ifadesi
					1)destruction
					2)de-allocation
			}

	dinamik ömürlü bir nesneyi delete etmezsek ne olur?
		1)memory leak(bellek bloðunun geri verilmemesi)
		2)dtor çaðýrýlmadýðý için resource leak
	
	ÖRNEK:
		auto p = new std::string(10'000, 'A');
	
		delete p; ifadesini yazmazsak ne olur?
			1)operator delete çaðýrýlmayacak dolayýsýyla sizeof string kadar bellek bloðu geri verilemeyecek
		
			10'000 tane A karakteri nerde duruyor?
				allocate edilmiþ bir bellek bloðunda duruyor stringin kendiside heapte tutuluyor heapte tutulan 
				bellek bloðunu string sýnýfýnýn çaðýrýlan dtoru geri veriyor ama dtor çaðýrýlmýyor çünkü delete ifadesi yok

				bu örnekte
				a)nesne için ayrýlan yer memory leak(sizeof string kadar yerin geri verilememesi)
				b)ctor tarafýndan allocate edilen bellek bloðunun geri verilememesi resource leak ama resource leak'in kendiside memory leak

				delete ifadesi kullanýlsaydý derleyici önce p adresindeki nesne için dtoru çaðýrýacaktý dtor 10bin bytelýk allocate edilen heap bloðunu geri verecekti
				ama ayný zamanda operator delete fonksiyonunu çaðýrýp sizeof string kadar elde edilen bellek bloðunu geri verecekti bu örnekte resource'un kendiside memory ama
				resource'un kendiside bir memory olmak zorunda deðil dosya yada baþka herhangi bir þeyde olabilir

			2)dangling pointer
	OPERATOR NEW VE DELETE FONKSÝYONLARINI ÖRNEK ÝÇÝN OVERLOAD EDÝYORUZ		
	
		void* operator new(size_t n)
		{
			std::cout << "operator new called n = " << n << '\n';

			void* vp = std::malloc(n);
			if (!vp)
				throw std::bad_alloc{};
	
			std::cout << "the address of the allocated block : " << vp << '\n';

			return vp;
		}
	
		class Myclass
		{
		public:
			Myclass(int x)
			{
				std::cout << "Myclass(int x) x = " << x << '\n';
				std::cout << "this = " << this << '\n';
			}
			~Myclass()
			{
				std::cout << "Myclass dtor this " << this<<'\n';
			}

			int ar[16]{};
		};

		int main()
		{
			std::cout << "sizeof Myclass = " << sizeof(Myclass) << '\n';
			Myclass* p = new Myclass{ 12 };

			std::cout << "p = " << p << '\n';
	
		}

	SORU: dinamik ömürlü bir nesne oluþturduk ama programýn sonuna kadar hayatta tutacaðýz delete etmememiz bir resource leak yada memory leak olarak nitelendirilebilir mi?
		HAYIR ama programlama disiplini açýsýndan bunu yapmamamýz gerekir

	new ifadelerinin farklý biçimleri var 
		1)yalýn biçimi 
			Myclass* p = new Myclass{ 12 }; 
		2)array new biçimi
			auto p = new Myclass[n]; // 
			class Myclass
			{
			public:
				Myclass()
				{
					std::cout << "ctor this = " << this << '\n';
				}
				~Myclass()
				{
					std::cout << "dtor this " << this<<'\n';
				}
			private:
				char buf[16];
			};


			int main()
			{
				size_t n;

				std::cout << "kac eleman: ";
				std::cin >> n;

				auto p = new Myclass[n]; // n elemanlý dinamik ömürlü dizi derleyici her eleman için ctora çaðrý yapacak

				delete[] p; // her eleman için dtor çaðýrýlýr
				
				ÇIKTI:
				ctor this = 0000025EA7EAB8B8
				ctor this = 0000025EA7EAB8C8
				ctor this = 0000025EA7EAB8D8
				ctor this = 0000025EA7EAB8E8
				ctor this = 0000025EA7EAB8F8
				dtor this 0000025EA7EAB8F8
				dtor this 0000025EA7EAB8E8
				dtor this 0000025EA7EAB8D8
				dtor this 0000025EA7EAB8C8
				dtor this 0000025EA7EAB8B8
			}

		3)placement new
			belirli bir bellek alýnýmýz zaten varsa ve o bellek alanýnda nesne oluþturmak istiyorsak kullanýrýz
			
			unsigned char buf[sizeof(Myclass)]; 
			
			SORU: bir myclass nesnesine bu bellek alanýnda hayata getirebilir miyiz? EVET
			unsigned char buf[sizeof(Myclass)]; // Myclass sýnýfý

			std::cout << "adres = " << static_cast<void*>(buf) << '\n';

			auto p = new (buf)Myclass; // nesnemiz doðrudan bu adreste oluþturulacak bu pointer deðiþken bu dizinin adresini göstermiþ oluyor
			
			std::cout << "p = " << p << '\n';

			bu nesneyi delete etmek için delete operatürünü kullanmayacaðýz kullanýrsak aslýnda operator new ile allocate edilmeyen bellek bloðunu
			operator delete ile geri vermniþ oluruz buda tanýmsýz davranýþa yol açar

			p->~Myclass();

		4)no throw new
			exception throw etmez 

			dinsmik ömürlü nesneler ile þu an sadece tanýþtýk ileride çok detaylý görülecek
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SINIFLARIN STATIC DATA MEMBERLARI VE SINIFLARIN STATIC MEMBER FUNCTIONLARI

STATIC DATA MEMBER
	sýnýflarýn static veri elemanlarý sýnýfla ilgili 

	class Myclass{
		public:
			static int x; // kaç tane myclass nesnesi olursa olsun sadece 1 tane x data memberý var  
			global deðerler gibi main fonksiyonu çaðýrýlmadan hayata gelecek assembly koduna bakarsak global deðiþkenlerden
			hiç bir farký yok aslýnda global deðiþkenlerin ehlileþtirilmiþ hali

			burdaki amaç global bir deðiþkene herkes eriþtiði için sýnýfýn içindede ayný global gibi davranan bir deðiþken olsun
			ama biz bunu class scopa alalým ve eriþimini kýsýtlayalým

			bir veri elemanýný static anahtar sözcüðü ile bildirmek
				1)deðiþkeni sýnýfa ait bir deðiþken yapýyor
				2)class scopa alýyor
				3)üstünde eriþim kontrolü saðlýyor

			static int x ifadesi bir decleration bunun definitionunun yapýlmasý gerekiyor
			ODR'ýn çiðnenmemesi için tanýmý cpp dosyasýnda yapýlacak

			myclass.cpp
				int Myclass::x; // default initalize edersek static ömürlü olduðu için zero initialize edilir

}; 
	sýnýfýn static veri elemaný primitive türlerden olmak zorundada deðil baþka sýnýf türündende olabilir

	SORU:
		class Myclass{
			public:
				Myclass mx; // GEÇERLÝ MÝ? HAYIR sýnýfýn kendi türünden bir veri elemaný olamaz
				incomplete type olduðu için incomplete type türden nesne oluþturamayýz
				ama static olsaydý sentaks hatasý olmayacaktý bu sadece bir bildirim
		};

	SORU:forward decleration yapsak sentaks hatasý olur mu EVET çünkü incomplete type
		class Nec;

		class Myclass{
			public:
				Nec x; // sentaks hatasý
				ama static olsaydý incomplete type olarak kullanýlmasý hata olmayacaktý ama tanýmýnýn olduðu noktada complete type olmasý gerek
		};

	SEMANTÝK VE SENTAKS TARAFI
		class BankAccount
		{
		public:
			static double interest_rate; // non-static veri elemaný olursa her hesabýn farklý bir interest_rate'i olabilir
			 faiz oraný hesaptan hesaba deðiþmiyorsa hepsi için aynýysa artýk instance ile ilgili deðil direkt olarak sýnýf ile ilgili 	
		};
		cpp
			double Account::interest_rate = 50.;

		int main()
		{
			sýnýfýn static veri elemanlarý class scopeta olduðu için isim arama class scopeta yapýlacak
		
			interest_rate // burada ismin bulunmamasýnýn sebebi name lookup 
			BankAccount::interest_rate; // sentaks hatasý deðil isim BankAccount sýnýfýnda aranýr ve bulunur private olsaydý access controle takýlacaktý 
		
			BankAccount a1,a2,a3,a4;

			a1.interest_rate; // sentaks hatasý deðil isim nokta operatörünün saðýnda bu ismi kullandýðýmz zaman isim arama nokta operatörünün sol operandý olan nesnenin 
			iliþkin olduðu sýnýfta aranýr böylece derleyici bu ismi BankAccount isimli sýnýfýn scope'unda arayacak bildirimi görecek ve bunun sýnýfýn static veri elemaný olduðunu anlayacak
			aynýsý member selection arrow operatörü içinde geçerli

			SORU:a1.interest_rate demiþ olsakta bunun a1 nesnesi ile doðrudan bir iliþkisi var mý? HAYIR
				a2.interest_rate += 10;
				std::cout<<a1.interest_rate << '\n'; // 60 çýktýsý alýnýr
				std::cout<<BankAccount::interest_rate<<'\n'; // 60 çýktýsý alýnýr 
				
		}

	sýnýflarýn static veri elemanlarýnýn public yapýlmasý sakýncalý bir durum çünkü yukarýdaki örnekteki gibi bir durumda yanlýþlýkla non-static bir veri elemanýný kullanacakken 
	static veri elemanýný kullanabilirdik ve bu deðeri yanlýþlýkla deðiþtirebilirdik ve bu durumdan tüm sýnýf etkilenirdi
	
	ÇAÐRININ SORUSU ÜZERÝNE: imlicitly static diye bir kavram var mý?
		çok dar bir alanda var örneðin sýnýflarýn operator new fonksiyonlarý implictly static 

STATIC MEMBER FUNCTION
	bildirimini .h'da tanýmýný cpp dosyasýnda yapabiliriz ama static anahtar kelimesini tanýmda yazmýyoruz

	myclass.h
	class Myclass{
		public:
			static int foo();
		private:
	};

	myclass.cpp

	int Myclass::foo(){ // böyle bir fonksiyon tanýmý görürsek sadece fonksiyon tanýmýna bakarak bu fonksiyonun static member function olup olmadýðýný anlama þansýmýz yok 
							bazen þöyle bir konvensiyon kullanýlabiliyor define komutu ile
	}

	#define STATIC // eðer bir makrou böyle define edersek bir replacement vermez isek ön iþlemci program bu define komutunu yürüttüðünde bunu silmek zorunda
	bizim gördüðümüz kod bu ama ön iþlemci modülü iþini tamamladýðýnda sýra derleyiciye geldiðinde sanki oradaki STATIC yazýsýný görmeyecek
	#define PUBLIC

	PUBLIC STATIC int Myclass::foo(){}

	static member functionlar sýnýf içindede tanýmlanabilir inline anahtar sözcüðünü kullanmasak bile implictly inline olacak

	SORU:static member funcitonlar const member function olabilir mi ?
		KULLANAMAYIZ çünkü static member functionlarýn gizli parametresi yok this pointerýna sahip deðiller object ile ilgili deðiller sýnýfla ilgili olduklarý için this pointerlarý yok
		yani bu fonksiyonun çaðýrýlmasý için bir nesneye ihtiyacýmýz yok
			class Myclass{
				public:
					static int foo()const; // sentaks hatasý
			};

		non-static member functionlarda this pointerýný kullandýðýmýzda bu fonksiyon hangi nesne için çaðýrýldýysa o nesnenini adresini kullanmýþ oluyoruz ama static üye fonksiyonlarý
		bir nesne için çaðýrýlmýyor ve static üye fonksiyonlarýnýn içinde this pointerýnýn kullanýlmasý her zaman sentaks hatasý

	SORU:diyelim ki sýnýfýmýzýn non-static veri elemaný var ve static member funciton içinde non-static veri elemanýný kullandýk
			class Myclass{
				public:
					static int foo()
					{
						//mx = 5; 
					}
				private:
					int mx; // static olsaydý her hangi bir sentaks hatasý olmazdý
			};	
		bu kodda name lookup hatasý var mý? YOK burada sentaks hatasý olmasýnýn sebebi mx isminin bulunamamasý deðil mx ile iliþkilendirilecek bir nesnenini olmayýþý 
		çünkü ortada bir nesne yok mx sýnýfýn non-static veri elemaný dolayýsýyla sýnýflarýn static member functionlarý içinde bir niteleme olmadan sýnýfýn non-static 
		veri elemanýný kullanamayýz

		Myclas::mx // þeklinde kullanmakta sentaks hatasý

	ÖRNEK:
		class Myclass{
			public:
				void foo(){}

				void bar()
				{
					foo(); // derleyici bar'ýn gizli parametresi deðiþkenini argüman olarak foo fonksiyonuna gönderiyor bar fonksiyonu hangi nesne için çaðýrýlmýþsa 
							foo fonksiyonuda o nesne için çaðýrýlmýþ olacak

							ama bar fonksiyonu static member function olsaydý static member functionun non-static member functionu bu þekilde çaðýrmasý sentaks hatasý olurdu
							bar fonksiyonun static olduðuçun this pointerý yok foo fonksiyounun çaðýrýlmasý için bir nesneye ihtiyacýmýz var
								static void bar()
								{
									foo(); // sentaks hatasý
								}

							ama tam tersi sentaks hatasý deðil yani non-static bir member function static bir member functionu çaðýrabilir
								void foo()
								{
									bar(); // bar fonksiyonu static olduðu için çaðýrýlmak için bir nesneye ihtiyaç duymuyor
								}
				}
			private:

		};

	MÜLAKAT SORUSU:
		class Myclass{
			public:
				static int foo()
				{
					return 1;
				}

				static int mx;
		};

		int foo()
		{
			return 7;
		}

		int Myclass::mx = foo(); // 

		int main()
		{
			std::cout<<Myclass::mx<<'\n'; // ÇIKTI 1 çünkü static veri elemanlarýna ilk deðer veren ifadedeki isimler ilk önce class scopeta aranýyor
			mx için çaðýrýlan fonksiyon sýnýfýn static foo fonksiyonu 
		}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
INLINE VARIABLE

	C++ 17 öncesinde sýnýflarýn static veri elemanlarýný sýnýf içinde tanýmlama ve initalize etme sentaksý yoktu
	sentaks hatasý ama bunun özel bir istisnasý var

	eðer sýnýfýn static veri elemaný const ise ve integral type ise sýnýf içinde tanýmlanabilir
		const static int x = 5;
		const static double x = 5; // sentaks hatasý

	global deðiþkenleri inline olarak tanýmlarsak ODR çiðnenmemiþ olur o baþlýk dosyasýný kaç tane dosya include ederse etsin 
	link aþamasýna geldiðimzde 1 tane x olacak
		inline int x = 5;
	
	sýnýflarýn static veri elemanlarý içinde aynýsý geçerli
		class Myclass{
			public:
				inline static int x = 10; // sýnýflarýn static veri elemanlarýný inline variable olarak sýnýfýn içinde tanýmlayabiliriz ODR çiðnenmemiþ olur

				statix int y;
		};
		int Myclass::y = 5; // ODR yine çiðnenmiþ olur 


	member functionlar içinde static veri elemanýný doðrudan kullanabiliyoruz
		class Myclass{
			public:
				void foo()
				{
					x = 5;
					Myclass::x = 5;
					Myclass::x = 5;
					this->x = 10; // sýnýf nesnesinin kendisiyle ilgili olmasada isim arama yine gerçekleþtirilebilir
				}

			static int x;
		};

	SORU:member function const üye fonksiyon ise static veri elemanýna atama geçerli olur mu
		
		class Myclass{
			public:
				void foo()const
				{
					// x = 5; // geçerli çünkü üye fonksiyonun const olmasý foonun gizli parametresinin const Myclass* olmasý static veri elemanýyla herhangi bir iliþkisi yok 
					yani const bir fonksiyon içinde static veri elemanýný deðiþtirebiliriz
				}

			static int x;
		};
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



*/