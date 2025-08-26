/*

bool t�r�ne d�n���m yapan operator bool fonksiyonunda kald�k

	baz� t�rler pointer like t�rler i�in yani nesneleri pointer gibi kullan�labilecek t�rler i�in t�pk� nullptr semanti�inde oldu�u gibi nullable type olu�turabilmek i�in
	operat�r bool fonksiyonunu overload ediyoruz b�ylece logic bir ifade beklenilen yerde s�n�f t�r�nden nesneleri kullanabiliyoruz �rne�in smartptr s�n�f�

	operator bool fonksiyonunun ilgin� bir �zelli�i var

		class Nec{
			public:
				operator bool()const // // Nec nesneleri bool ifade beklenen bir ba�lamda bool t�r�ne bu fonksiyon ile d�n��t�r�lebilir olacak
				{
					return true;
				}
		};

		int main()
		{
			Nec mynec;
			int x = mynec; // bu kodun implicit olarak legal olmas�n� istemeyiz ��nk� derleyici �nce s�n�f�n operator bool fonksiyonuna �a�r� yap�yor 
			bool t�r�nden bir ifade elde ediliyor bool t�r�ndende int t�r�ne implicit conversion oldu�u i�in her hangi bir �ekilde bir sentaks hatas� olmuyor bu y�zden explicit olmas� gerekiyor
		
			Nec n1,n2;

			auto x = n1 + n2; // derleyici toplama operat�r�n�n operandlar�n�n Nec t�r�nden oldu�unu g�r�nce toplama operat�r�n�n operand� olabilecek bir d�n���m m�mk�n m�
			diye bak�yor ve s�n�f�n operator bool fonksiyonu oldu�unu g�r�yor b�ylece her iki nesneyide bool t�r�ne d�n��t�r�yor bu durumda toplama operat�r�n�n her iki operand� bool t�r�nde
			olmu� oluyor burada integral promotion ile int t�r�ne y�kseltilecekler ifadenin t�r� int olacak ve operator bool fonksiyonunun geri d�n�� de�eri true(1) 
			�retti�i i�in x'in de�eri 2 olacak
			
			operator bool fonksiyonu explicit olsa bile logic bir ifade gereken yerde implicit d�n���m� yap�yor ama logic ba�lam olmayan yerlerde �rt�l� d�n���m engellenir

				if(n1 && n2){} // ge�erli
				auto b = !n1; // ge�erli
		}
	
	�RNEK:
		
		int main()
		{
			int x;
			while(std::cin >> x)
			{
				std::cout<<x<<'\n'; 
			}

			burada cin nesnesinin kendisini kullansayd�k yine bu kod legal olacakt�
			while(std::cin) peki bu nas�l legal oluyor? ��nk� istream s�n�f� i�in operator bool overload edilmi� 
			asl�nda derleyici burada while(cin.operator>>(x).operator bool()) fonksiyonuna �a�r� yap�yor

		}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ENUMARATION TYPES ���NDE OPERATOR FONKS�YONU YAZILAB�L�R
	class type olmad�klar� i�in member functiona sahip olamazlar global operator fonksiyonu olarak operator fonksiyonlar� tan�mlayabiliriz

	peki bunlar�n operator overloading ile ne ilgisi var?
	WeekDay t�r�nden bir de��ken ++ operat�r�n� yada -- operat�r�n�n operand� oldu�unda g�n�n 1 artmas� �ok do�al bir koddur
	yada << operat�r� sayesinde g�n�n hangi g�n oldu�unu yazd�rmas�n� isteyebiliriz

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
D�NAM�K �M�RL� NESNELERLE TANI�MA
	
	dinamik �m�rl� nesne ne demek ve nesnenin bellekte tutulaca�� yer nas�l elde edilecek ayr� sorulard�r

	new Date
	new int
	new Fighter // bu ifadelerin t�r� bir pointer t�r� 

	D�KKAT:new operat�r� ba�ka bir terim operator new ayr� bir terim operator new bir fonksiyon C den gelen malloc fonksiyonuyla ayn� parametrik yap�da
	void* operator new(size_t); 

	derleyici bir new ifadesiyle kar��la�t���nda �ncelikle operator new fonksiyonuna �a�r� yap�cak bir kod olu�turuyor
	bu fonksiyona arg�man olarak new'e operand olan t�r�n sizeof de�erini ge�iyor 

	malloc ile operator new k�smen ayn� oldu�una g�re neden malloc olarak kalmad�?
		malloc ba�ar�s�z oldu�unda nullptr d�nd�r�yor operator new ise ba�ar�s�z oldu�unda exception throw ediyor
		operator new ba�ar�l�ysa derleyici �retti�i kodda operat�r newden ald��� adresi this pointer� kullan�lacak �ekilde s�n�f�n ctoruna �a�r� yap�yo
		
		new ifadesi asl�nda derleyicinin 2 ayr� kodu �retmesini sa�l�yor
		1)dinamik �m�rl� nesnenin yerinin elde edilmesi i�in standart k�t�phanenin operator new fonksiyonuna �a�r� yapmak
		2)elde edilen allocate edilen bellek blo�unda nesneyi olu�turmak i�ni s�n�f�n ctoruna �a�r� yapmak

		exception throw edilmediyse new Object ifadesiyle construct edilmi� nesnenin adresini elde etmi� oluyoruz ayr� bir initalization s�z konusu de�ilse
		default initialize edilmi� nesne i�in default ctor �a��r�lacak 

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
				Myclass* p = new Myclass(12); // derleyici �nce operat�r new fonksiyonuna �a�r� yap�cak operator new fonksiyonu ba�ar�l� olursa allocate edilmi� bellek blo�unun adresini
				void* olarak d�nd�recek derleyicide o adreste Myclass nesnesinin olu�turulmas� i�in s�n�f�n ctoruna �a�r� yap�cak
				
				p->bar();
				p->foo(); 

				std::cout<<"p = " << p <<'\n';

				dinamik �m�rl� nesenin hayat�n� sonland�rmak i�in delete ifadesiyle s�n�f�n destructoruna �a�r� yap�yoruz operand olarak dinamik �m�rl� bir nesnenin adresini al�yor
				delete p; // destructor �a��r�l�r

				D�KKAT:delete operator� ile operator delete fonksiyonunu kar��t�rmamam�z laz�m
				void operator delete(void *vp); 

				delete ifadesi ne yap�yor?
					1)derleyici delete ifadesi kar��l��� �nce delete operat�r�n�n operand� olan adresteki s�n�f nesnesi i�in s�n�f�n dtoruna �a�r� yap�yor
					derleyici arka planda b�yle bir �a�r� yap�yor  p->~Myclass()
					2)nesnemizin yerini operator new alm��t� onun geri verilmesi i�inde operator new fonksiyonu
					taraf�ndan elde edilen adresin operator delete fonksiyonuna ge�ilmesi gerekiyor operator delete(p); b�ylece operator delete fonksiyonu hayat� bitmi� olan 
					nesnenin bellek alan�n� de-allocate ediyor

				new ifadesi
					1)allocation 
					2)construction
				delete ifadesi
					1)destruction
					2)de-allocation
			}

	dinamik �m�rl� bir nesneyi delete etmezsek ne olur?
		1)memory leak(bellek blo�unun geri verilmemesi)
		2)dtor �a��r�lmad��� i�in resource leak
	
	�RNEK:
		auto p = new std::string(10'000, 'A');
	
		delete p; ifadesini yazmazsak ne olur?
			1)operator delete �a��r�lmayacak dolay�s�yla sizeof string kadar bellek blo�u geri verilemeyecek
		
			10'000 tane A karakteri nerde duruyor?
				allocate edilmi� bir bellek blo�unda duruyor stringin kendiside heapte tutuluyor heapte tutulan 
				bellek blo�unu string s�n�f�n�n �a��r�lan dtoru geri veriyor ama dtor �a��r�lm�yor ��nk� delete ifadesi yok

				bu �rnekte
				a)nesne i�in ayr�lan yer memory leak(sizeof string kadar yerin geri verilememesi)
				b)ctor taraf�ndan allocate edilen bellek blo�unun geri verilememesi resource leak ama resource leak'in kendiside memory leak

				delete ifadesi kullan�lsayd� derleyici �nce p adresindeki nesne i�in dtoru �a��racakt� dtor 10bin bytel�k allocate edilen heap blo�unu geri verecekti
				ama ayn� zamanda operator delete fonksiyonunu �a��r�p sizeof string kadar elde edilen bellek blo�unuda geri verecekti bu �rnekte resource'un kendiside memory ama
				resource'un kendiside bir memory olmak zorunda de�il dosya yada ba�ka herhangi bir �eyde olabilir

			2)dangling pointer olu�ur

	OPERATOR NEW VE DELETE FONKS�YONLARINI �RNEK ���N OVERLOAD ED�YORUZ		
	
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

	SORU: dinamik �m�rl� bir nesne olu�turduk ama program�n sonuna kadar hayatta tutaca��z delete etmememiz bir resource leak yada memory leak olarak nitelendirilebilir mi?
		HAYIR ama programlama disiplini a��s�ndan bunu yapmamam�z gerekir

	new ifadelerinin farkl� bi�imleri var 
		1)yal�n bi�imi 
			Myclass* p = new Myclass{ 12 }; 
		2)array new bi�imi
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

				auto p = new Myclass[n]; // n elemanl� dinamik �m�rl� dizi derleyici her eleman i�in ctora �a�r� yapacak

				delete[] p; // her eleman i�in dtor �a��r�l�r
				
				�IKTI:
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
			belirli bir bellek al�n�m�z zaten varsa ve o bellek alan�nda nesne olu�turmak istiyorsak kullan�r�z
			
			unsigned char buf[sizeof(Myclass)]; 
			
			SORU: bir myclass nesnesine bu bellek alan�nda hayata getirebilir miyiz? EVET
			unsigned char buf[sizeof(Myclass)]; // Myclass s�n�f�

			std::cout << "adres = " << static_cast<void*>(buf) << '\n';

			auto p = new (buf)Myclass; // nesnemiz do�rudan bu adreste olu�turulacak bu pointer de�i�ken bu dizinin adresini g�stermi� oluyor
			
			std::cout << "p = " << p << '\n';

			bu nesneyi delete etmek i�in delete operat�r�n� kullanmayaca��z kullan�rsak asl�nda operator new ile allocate edilmeyen bellek blo�unu
			operator delete ile geri vermi� oluruz buda tan�ms�z davran��a yol a�ar

			p->~Myclass(); // dtoru dor�udan kendimiz �a��r�yoruz

		4)no throw new
			exception throw etmez 

			dinamik �m�rl� nesneler ile �u an sadece tan��t�k ileride �ok detayl� g�r�lecek
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SINIFLARIN STATIC DATA MEMBERLARI VE SINIFLARIN STATIC MEMBER FUNCTIONLARI

STATIC DATA MEMBER
	s�n�flar�n static veri elemanlar� s�n�fla ilgili bir kavram

	class Myclass{ 
		public:
			static int x; // ka� tane myclass nesnesi olursa olsun sadece 1 tane x data member� var  
			global de�erler gibi main fonksiyonu �a��r�lmadan hayata gelecek assembly koduna bakarsak global de�i�kenlerden
			hi� bir fark� yok asl�nda global de�i�kenlerin ehlile�tirilmi� hali

			burdaki ama� global bir de�i�kene herkes eri�ti�i i�in s�n�f�n i�indede ayn� global gibi davranan bir de�i�ken olsun
			ama biz bunu class scopa alal�m ve eri�imini k�s�tlayal�m

			bir veri eleman�n� static anahtar s�zc��� ile bildirmek
				1)de�i�keni s�n�fa ait bir de�i�ken yap�yor
				2)class scopa al�yor
				3)�st�nde eri�im kontrol� sa�l�yor

			myclass.cpp
				int Myclass::x; // default initalize edersek static �m�rl� oldu�u i�in zero initialize edilir

}; 
	s�n�f�n static veri eleman� primitive t�rlerden olmak zorundada de�il ba�ka s�n�f t�r�ndende olabilir

	SORU:
		class Myclass{
			public:
				Myclass mx; // GE�ERL� M�? HAYIR s�n�f�n kendi t�r�nden bir veri eleman� olamaz
				incomplete type oldu�u i�in incomplete type t�rden nesne olu�turamay�z
				ama static olsayd� sentaks hatas� olmayacakt� bu sadece bir bildirim olmu� olurdu
		};

	SORU:forward decleration yapsak sentaks hatas� olur mu EVET ��nk� incomplete type
		class Nec;

		class Myclass{
			public:
				Nec x; // sentaks hatas�
				ama static olsayd� incomplete type olarak kullan�lmas� hata olmayacakt� ama tan�m�n�n oldu�u noktada art�k complete type olmas� gerek
		};

	SEMANT�K VE SENTAKS TARAFI
		class BankAccount
		{
		public:
			static double interest_rate; // non-static veri eleman� olursa her hesab�n farkl� bir interest_rate'i olabilir
			 faiz oran� hesaptan hesaba de�i�miyorsa hepsi i�in ayn�ysa art�k instance ile ilgili de�il direkt olarak s�n�f ile ilgili 	
		};
		cpp
			double Account::interest_rate = 50.;

		int main()
		{
		
			interest_rate // s�n�f�n static veri elemanlar� class scopeta oldu�u i�in isim arama class scopeta yap�lacak burada ismin bulunmamas�n�n sebebi name lookup 
			BankAccount::interest_rate; // sentaks hatas� de�il isim BankAccount s�n�f�nda aran�r ve bulunur private olsayd� access controle tak�lacakt� 
		
			BankAccount a1,a2,a3,a4;

			a1.interest_rate; // sentaks hatas� de�il isim nokta operat�r�n�n sa��nda bu ismi kulland���mz zaman isim arama nokta operat�r�n�n sol operand� olan nesnenin 
			ili�kin oldu�u s�n�fta aran�r b�ylece derleyici bu ismi BankAccount isimli s�n�f�n scope'unda arayacak bildirimi g�recek ve bunun s�n�f�n static veri eleman� oldu�unu anlayacak
			ayn�s� member selection arrow operat�r� i�inde ge�erli

			SORU:a1.interest_rate demi� olsakta bunun a1 nesnesi ile do�rudan bir ili�kisi var m�? HAYIR
				a2.interest_rate += 10;
				std::cout<<a1.interest_rate << '\n'; // 60 ��kt�s� al�n�r
				std::cout<<BankAccount::interest_rate<<'\n'; // 60 ��kt�s� al�n�r 
				
		}

	s�n�flar�n static veri elemanlar�n�n public yap�lmas� sak�ncal� bir durum ��nk� yukar�daki �rnekteki gibi bir durumda yanl��l�kla non-static bir veri eleman�n� kullanacakken 
	static veri eleman�n� kullanabilirdik ve bu de�eri yanl��l�kla de�i�tirebilirdik ve bu durumdan t�m s�n�f etkilenirdi
	
	�A�RININ SORUSU �ZER�NE: implicitly static diye bir kavram var m�?
		�ok dar bir alanda var �rne�in s�n�flar�n operator new fonksiyonlar� implictly static 

STATIC MEMBER FUNCTION
	bildirimini .h'da tan�m�n� cpp dosyas�nda yapabiliriz ama static anahtar kelimesini tan�mda yazm�yoruz

	myclass.h
	class Myclass{
		public:
			static int foo();
		private:
	};

	myclass.cpp

	int Myclass::foo(){ // b�yle bir fonksiyon tan�m� g�r�rsek sadece fonksiyon tan�m�na bakarak bu fonksiyonun static member function olup olmad���n� anlama �ans�m�z yok 
							bazen ��yle bir konvensiyon kullan�labiliyor define komutu ile
	}

	#define STATIC // e�er bir makroyu b�yle define edersek bir replacement vermezsek �n i�lemci program bu define komutunu y�r�tt���nde bunu silmek zorunda
	bizim g�rd���m�z kod bu ama �n i�lemci mod�l� i�ini tamamlad���nda s�ra derleyiciye geldi�inde sanki oradaki STATIC yaz�s�n� g�rmeyecek
	#define PUBLIC

	PUBLIC STATIC int Myclass::foo(){}

	static member functionlar s�n�f i�indede tan�mlanabilir inline anahtar s�zc���n� kullanmasak bile implictly inline olacak

	SORU:static member funcitonlar const member function olabilir mi ?
		HAYIR ��nk� static member functionlar�n gizli parametresi yok this pointer�na sahip de�iller object ile ilgili de�iller s�n�fla ilgili olduklar� i�in this pointerlar� yok
		yani bu fonksiyonun �a��r�lmas� i�in bir nesneye ihtiyac�m�z yok
			class Myclass{
				public:
					static int foo()const; // sentaks hatas�
			};

		non-static member functionlarda this pointer�n� kulland���m�zda bu fonksiyon hangi nesne i�in �a��r�ld�ysa o nesnenini adresini kullanm�� oluyoruz ama static �ye fonksiyonlar�
		bir nesne i�in �a��r�lm�yor ve static �ye fonksiyonlar�n�n i�inde this pointer�n�n kullan�lmas� her zaman sentaks hatas�

	SORU:diyelim ki s�n�f�m�z�n non-static veri eleman� var ve static member funciton i�inde non-static veri eleman�n� kulland�k
			class Myclass{
				public:
					static int foo()
					{
						//mx = 5; 
					}
				private:
					int mx; // static olsayd� her hangi bir sentaks hatas� olmazd�
			};	
		bu kodda name lookup hatas� var m�? YOK burada sentaks hatas� olmas�n�n sebebi mx isminin bulunamamas� de�il mx ile ili�kilendirilecek bir nesnenini olmay��� 
		��nk� ortada bir nesne yok mx s�n�f�n non-static veri eleman� dolay�s�yla s�n�flar�n static member functionlar� i�inde bir niteleme olmadan s�n�f�n non-static 
		veri eleman�n� kullanamay�z

		Myclas::mx // �eklinde kullanmakta sentaks hatas�

	�RNEK:
		class Myclass{
			public:
				void foo(){}

				void bar()
				{
					foo(); // derleyici bar'�n gizli parametresi de�i�kenini arg�man olarak foo fonksiyonuna g�nderiyor bar fonksiyonu hangi nesne i�in �a��r�lm��sa 
							foo fonksiyonuda o nesne i�in �a��r�lm�� olacak

							ama bar fonksiyonu static member function olsayd� static member functionun non-static member functionu bu �ekilde �a��rmas� sentaks hatas� olurdu
							bar fonksiyonun static oldu�u i�in this pointer� yok foo fonksiyonunun �a��r�lmas� i�in bir nesneye ihtiyac�m�z var
								static void bar()
								{
									foo(); // sentaks hatas�
								}

							ama tam tersi sentaks hatas� de�il yani non-static bir member function static bir member functionu �a��rabilir
								void foo()
								{
									bar(); // bar fonksiyonu static oldu�u i�in �a��r�lmak i�in bir nesneye ihtiya� duymuyor
								}
				}
			private:

		};

	M�LAKAT SORUSU:
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
			std::cout<<Myclass::mx<<'\n'; // �IKTI 1 ��nk� static veri elemanlar�na ilk de�er veren ifadedeki isimler ilk �nce class scopeta aran�yor
			mx i�in �a��r�lan fonksiyon s�n�f�n static foo fonksiyonu 
		}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
INLINE VARIABLE

	C++ 17 �ncesinde s�n�flar�n static veri elemanlar�n� s�n�f i�inde tan�mlama ve initalize etme sentaks� yoktu
	sentaks hatas� ama bunun �zel bir istisnas� var

	e�er s�n�f�n static veri eleman� const ise ve integral type ise s�n�f i�inde tan�mlanabilir
		const static int x = 5;
		const static double x = 5; // sentaks hatas�

	global de�i�kenleri inline olarak tan�mlarsak ODR �i�nenmemi� olur o ba�l�k dosyas�n� ka� tane dosya include ederse etsin 
	link a�amas�na geldi�imzde 1 tane x olacak
		inline int x = 5;
	
	s�n�flar�n static veri elemanlar� i�inde ayn�s� ge�erli
		class Myclass{
			public:
				inline static int x = 10; // s�n�flar�n static veri elemanlar�n� inline variable olarak s�n�f�n i�inde tan�mlayabiliriz ODR �i�nenmemi� olur

				statix int y;
		};
		
		.cpp
			int Myclass::y = 5; // ODR �i�nenmez ama ayn� tan�m� birden fazla dosyada yaparsak ODR �i�nenmi� olur

	member functionlar i�inde static veri eleman�n� do�rudan kullanabiliyoruz
		class Myclass{
			public:
				void foo()
				{
					x = 5;
					Myclass::x = 5;
					Myclass::x = 5;
					this->x = 10; // s�n�f nesnesinin kendisiyle ilgili olmasada isim arama yine ger�ekle�tirilebilir
				}

			static int x;
		};

	SORU:member function const �ye fonksiyon ise static veri eleman�na atama ge�erli olur mu
		
		class Myclass{
			public:
				void foo()const
				{
					// x = 5; // ge�erli ��nk� �ye fonksiyonun const olmas� foonun gizli parametresinin const Myclass* olmas� static veri eleman�yla herhangi bir ili�kisi yok 
					yani const bir fonksiyon i�inde static veri eleman�n� de�i�tirebiliriz
				}

			static int x;
		};
*/