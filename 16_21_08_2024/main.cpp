/*

operator overloadingten devam
	fonksiyonu çaðýrdýðýmýz nesne bir r value expression ise kopyalama yerine taþýma semantiðinden faydalanablir miyiz? EVET
		class Big{};
		class Nec
		{
			public:
				const Big& get_biggie()& 
				{
					return biggie;
				}
				const Big& get_biggie()&&
				{
					return std::move(biggie);
				}
			private:
				Big biggie;
	};

	bazý veri yapýlarýný temsil eden soyutalam yapýldýðýnda bellekte ardýþýklýk olmasý söz konusuysa subscript operatörü array-like bir eriþimi
	çaðrýþtýrdýðý için overload ediliyor
		std::string[]
		std::array[]
		std::vector
		std::deque
		
		bazý iterator sýnýflarý iterator yine pointer like bir sýnýf fakat burada iterator dediðmiiz türlerin görevi veri yapýlarýndaki tutulan elemanlarýn konumunu tutmak
			vecotr<int>::iterator
		
		smart pointer sýnýfý amaç bir nesnenin bir kaynaðýn hayatýný kontrol etmek
			unieque_ptr 

		associative containerlar
			bir key'den value'ya eriþtiðimiz veri yapýlarý
				std::set
				std::multiset
				std::map
				std::multimap
		
		unordered containerlar
			 elemanlarý sýrasýz (unsorted) olarak tutan ve hash tablolarý üzerinden eriþim saðlayan
				std::unordered_multiset
				std::unordered_multimap
				std::unordered_map
				std::unordered_set
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	DEREFERENCING VE MEMBER SELECTIN ARROW OPERATOR
		a * b -> asteriks
		*ptr -> dereferencing
			
			DEREFERENCING
			unary operatördür
			1)dereferenence operatörünün operandý adres olmak zorunda
			2)operatörün oluþturduðu ifade l value expression

			bazý sýnýflar pointer like sýnýflar
				class Iterator{};
					amacý bir veri yapýsýndaki elenanýn konumunu tutmak
				
				ÖRNEK
				class SmartPtr{};
					dinamik ömürlü nesnelerin hayatlarýný kontrol etmek
				
				class Nec
				{
					public:
						void foo();
				};

				class NecPtr
				{
					public:
						NecPtr(Nec* p);
						Nec& operator*();
				};

				int main()
				{
					NecPtr = new Nec;
					(*ptr).foo();
					ptr.operator*().foo(); // iki þekildede eriþebiliriz
				}
				
				ÖRNEK
				int main()
				{
					std::vector<int> ivec{ 4,7,3,1,2,7,9 };
				
					auto iter = ivec.begin(); // dinamik dizide tutulan ilk elemanýn konumunu tutuyor
					std::vector<int>::iterator iter2 = ivec.begin(); // auto olmasaydý böyle yazacaktýk
				
					std::cout << *iter << '\n'; // 4 çýktýsý alýnýr
					std::cout<<++*iter<<'\n';// ilk elemanýný deðerini 1 arttýrýr 5 yapar
				
					++iter; // bir sonraki elemaný gösterir -> 7

					*iter = 987; // 7'nin deðerini deðiþtirir
					iter.operator*() = 777; // ikiside ayný anlama geliyor
				
					std::cout << *iter << '\n';
				}

				bazý pointer-like sýnýflar ++ operatörünü overload ediyor

			MEMBER SELECTION
				binary operatördür ama unary operatör olarak overload edilir
				
				SmartPtr ptr;
				
				ptr->mx; // derleyici böyle bir ifade ile karþýlaþtýðýnda ptr'nin bir sýnýf nesnesi olduðunu gördüðünde ptr'nin iliþkin olduðu sýnýfýn yani SmartPtr'nin member selection arrow 
				operatörü olup olmadýðýna bakýyor 
				
				ptr.operator->() // derleyici sýnýfýn ok operator fonksiyonu olduðunu gördü bu ifadeyi okun sol operandý yapýyor 
				ptr.operator->()->mx ifadesine dönüþtürüyor bu yüzden member selection arrow operatörünün geri dönüþ deðeri pointer olmalý çünkü ancak bir pointer ok operandýnýn sol operandý olabilir

				ÖRNEK
				Mint* türünden bir deðer sanki pointermýþ gibi davranacak bir sýnýf yazýyoruz neden bunu yapalým?
				MinPtr sýnýfý dinamik ömürlü Mint nesnelerinin hayatýný kontrol eden smart pointer sýnýf
				class MintPtr
				{
				public:
					explicit MintPtr(Mint* p) : mp(p) {} //  p'yi sýnýfýn veri elamaný olan mpde tutuyoruz
					~MintPtr()
					{
						if (mp)
						{
							delete mp; // mp'nin gösterdiði nesne için
						}
					}
				
				// eðer amaç dinamik ömürlü bir mint nesnesini sadece bir pointerý göstermesini saðlamaksa kopyalamaya karþý kapatmamýz gerek
					MintPtr(const MintPtr&) = delete;
					MintPtr& operator=(const MintPtr&) = delete;
				
					MintPtr(MintPtr&& other) : mp(other.mp)
					{
						other.mp = nullptr; // nesneyi yok etmiyor
					}
					MintPtr& operator=(MintPtr&& other)
					{
						delete mp;
				
						mp = other.mp;
				
						other.mp = nullptr;
					}
				
					Mint& operator*()
					{
						return *mp;
					}
				
					Mint* operator->() 
					{
						return mp;
					}
				
				private:
					Mint* mp;
				};
			
				int main()
				{

					MintPtr ptr{ new Mint(45) };

					std::cout << *ptr << '\n';
					++*ptr;

					std::cout << ptr->get() << '\n';
					std::cout << ptr.operator->()->get() << '\n'; // hiç bir anlam farký yok

				}

			çok büyük çoðunlukla member selection arrow operatörünün geri dönüþ türü pointer türünden olacak ama doðrudan pointer olmasý dýþýnda nadir olarak kullanýlsada þöyle bir kullanýmda var
				class A{
					public:
						void foo();
				};

				class B{
					public:
						A* operator->();
				};

				class C{
					public:
						B operator->(); // B* deðil B döndürüyor 
				};

				int main()
				{
					C cx;
					cx->foo(); // derleyici bunu cx.operator->().operator->()->foo(); ifadesine dönüþtürüyor
				}

				örneðin Mint deðilde Sint türünden baþka bir sýnýfýn dinamik nesnelerinin hayatýný kontrol eden bir sýnýfa ihtiyacýmýz olursa ne yapacaðýz?
				burda iþimize yarayan durum generic programming burda derleyiciye diyeceðiz ki derleyici ben sana akýllý pointer sýnýfý yazmanýn yolunu öðreteceðim
				öyle bir kod vereceðim ki sen o kodu kullanarak Mint sýnýýf türünden nesneleri gösterecek akýllý pointer sýnýfýnýda Sint sýnýfý türünden dinamik ömürlü
				nesneleri gösterecek akýllý pointer sýnýfýnýda bizim verdiðimiz kalýba göre kodu yazacaksýn yani sýnýflarýn kodunu biz yazmayacaðýz ama sýnýfýn kodunu yazdýracak
				kodu biz yazacaðýz 

				template<typename T>
				class SmartPtr {
					// T türü için Mint'i kullan desek derleyici T yerine Mint sýnýfýný kullanarak bir sýnýf yazacak
				public:
					explicit SmartPtr(T* p) : mp(p){}
					~SmartPtr()
					{
						if (mp)
						{
							delete mp;

						}
					}
					SmartPtr(T&& other) mp(other.mp)
					{
						other.mp = nullptr;
					}
					SmartPtr& operator=(SmartPtr&& other)
					{
						delete mp;
						mp = other.mp;
						other.mp = nullptr;
					}
					T& operator*()
					{
						return *mp;
					}

					T* operator->()
					{
						return mp;
					}
				private:
					T* mp;
				};

				int main()
				{

					SmartPtr<Mint> ptr{ new Mint(45) };

					std::cout << *ptr << '\n';
					++*ptr;

					std::cout << ptr->get() << '\n';
					std::cout << ptr.operator->()->get() << '\n'; // hiç bir anlam farký yok

				}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	FUNCTION CALL OPERATOR
		C de foo(4) þeklinde bir ifade görsek 
		1)foo gerçetken bir fonksiyon ismidir
		2)foo nun function macro olmasý
		3)foo nun bir function pointer variable olmasý  
			void(*foo)(int) = &bar;
		C++ da ise C de ki senaryolar hala devam etmekte birlikte
			foo bir sýnýf türünden nesne olabilir
			Nec foo;
			fonksiyon çaðrý operatörünün oprandý olduðu için foo nun üye fonksiyonu olan function call operatörünü çaðýrýr foo nun iliþkin olduðu Nec sýnýfý
			fuonksiyon çaðrý operatünü overlaod etmiþtir fonksiyon çaðrý operatörünü overload ettiði için kendisi bir sýnýf nesnesi olmasýna raðmen
			fonksiyon çaðrý operatörünün operandý olabilen sýnýflara FUNCTOR CLASS yada FUNCTION OBJECT
			foo.operator()(4) olarak çaðýrýlabilir
		fonksiyon çaðrý operatörünün operandý olduðunda bir fonksiyonun çaðýrýlamasý söz konusuysa bu anlamda kullanýlan terim CALLABLE

		class Myclass {
		public:
			int operator()(int x)
			{
				std::cout << "Myclass::operator()(int x) x = " << x << '\n';
				std::cout << "this = " << this << '\n';
				return 42;
			}

			// parametre alabilir const yada non-const olabilir

			// fonksiyonun geri dönüþ deðeri türünde kýsýtlama yok

			// birden fazla function call operator overloadingi olabilir

			// sadece bu operator fonksiyonu default argument alabilir

			// double parametreli bir function call operator daha olsaydý derleyici hangi fonksiyonu çaðýracaðýný founction overlaod resolutionda analyacaktý

			int operator()(double x)
			{
				std::cout << "Myclass::operator()(int x) x = " << x << '\n';
				std::cout << "this = " << this << '\n';
				return 42 * 0.5;
			}

		};

		int main()
		{
			Myclass m;
			
			std::cout << "&m = " << &m << '\n';
			
			auto x = m(25);
			std::cout << "x = " << x << '\n';

			auto y = m(2.5);
			std::cout << "y = " << y << '\n';

		}

		SORU:peki function call operator ne iþe yarýyor?
			esas faydasý generic programlamada olacak

			operaor() fonkaiyonu sýnýf nesnesi için çaðýrýlýyor ve çaðrýnýn yapýldýðý sýnýf nesnesi o sýnýfýn ne anlama geldiðine göre farklý farklý statete olabilir
			bu state sýnýfýn private veri elemanlarýylada temsil edilebilir sýnýfýn mx isimli veri elemaný olsaydý operator() fonksiyonunda mx'i kullandýðýmýzda bu fonksiyon hangi nesne için çaðýrýlýrsa
			o nesnenin mx'ini kullanmýþ olurduk biz öyle bir fonksiyon oluþturmuþ oluoruz fonksiyonun kendidi adete bir state sahip yani fonksiyona bir argüman göndermeden fonksiyonun
			zaten bir state'i var
			
			öyle bir fonksiyon olsun ki o fonksiyon verilen bir aralýkta rastgele bir sayý üretsin mesela 20 ve 50
			ama biz yine ayný fonksiyona 1000 2000 aralýðýnda rastgele sayý üretmesini talep edebileceðiz böyle bir senaryoyu gerçekleþtirmenin en pratik yolu 
			bunu bir sýnýf olarak tasarlamak aralýk öðelerini sýnýfýn private veri elemanlarý yapmak sýnýf nesnesinin contrcut ederken ctoru kullanacak user codedan aralýk deðerlerini
			argüman olarak almak ve sýnýfa bir fonksiyon çaðrý operatörü tanýmlamak ve bu fonksiyonda sýnýfýn veri elemanlarýný kullanacak

			class Random
			{
			public:
				Random(int low, int high) : mlow(low), mhigh(high) {}
				int operator()()
				{
					++mcount;
					return rand() % (mhigh - mlow + 1) + mlow;
				}

				int get_count()const
				{
					return mcount;
				}

			private:
				int mlow, mhigh,mcount{};
			};

			int main()
			{
				Random rand1{ 42,87 };

				for (int i = 0; i < 5; ++i)
				{
					std::cout << rand1() << ' ';
				}
				std::cout<<rand1.get_count() << " sayi uretildi\n";

				std::cout << '\n';


				Random rand2{ 8764,8923 };
				for (int i = 0; i < 10; ++i)
				{
					std::cout << rand2() << ' '; // bu nesnede kendi stateine sahip
				}
				std::cout<<rand2.get_count() << " sayi uretildi\n";


			}

			void func(Random rx){
				rx(); // böyle bir fonksiyonumuz olsa rx'i kullanarak rastgele bir sayý oluþtursak func fonksiyonu hangi aralýkta rastgele sayý üreteceðini bilmiyor
				onu bilen parametreye gönderilen Random nesnesinin kendisi
			}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	TYPE CAST OPERATOR FUNCTIONS
		user defined conversion kategorsindedir

		class Nec{
			public:
				operator int()const // sýnýfýn stateini deðiþtirmediði için const yaptýk
				{
					std::cout<<"Nec::operator int()\n";
					return 4; 
				}
		};

		int main()
		{
			Nec mynec;
			int ival{};

			ival = mynec; // derleyi operator int fonksiyonuna implicit conversion olarak çaðrý yaptý yani aslýnda ival'e myneci deðil mynec'in
							operator int fonksiyonuna yapýlan çaðrýdan elde edilen geri dönüþ deðerini atamýþ olduk	ival'e aslýnda 4 deðerini atamýþ olduk

			
			ival = mynec.operator int(); // ikisinide yazmak ayný

		}

		burda bir istisna var genelde fonksiyonlarýn bildirimnde yada tanýmýnda fonksiyonun geri dönüþ deðerini yazmamýz gerekir tür dönüþtürme operatör fonksiyonlarýnýn ismi 
		operatör keywordünü izleyen dönüþtürülecek hedef tür örneðin operator int() hedef tür kýsmýnda hiç bir kýsýtlama yoktur her hangi bir tür olabilir
		geri dönüþ deðeri türünün boþ býrakýlmasý geri dönüþ deðerinin olmamasý anlamýna gelmiyor gereksiz yere tekrardan kaçýnýldýðýný için yazýlmýyor hedef tür ne ise fonksiyonun heri dönüþ deðeri türü

		conversion ctorda olduðu gibi bu dönüþümün yapýlmasý gerektiði durumlarda bu dönüþümleri ötrülü olarak dönüþümü yapcak buda çok büyük bir risk oluþturuyor
		ya yanlþýklýkla bir kod yazarsak dilin kurallarý gereði o fonksiyon çaðýrýlýrsa? büyük bir risk oluþturur ve eðer bir dönüþüm örtülü olarak önce standart dönüþüm sonra user defined conversion
		olarak yapýlýyorsa derleyici bu dönüþümü yapmak zorunda yada önce user defined conversion sonra standart conversion uygulanarak yapýlýyorsa derleyici bu dönüþümü
		yapmak zorunda 
			class Nec {
			public:
				explicit operator int() const // istenmeyen dönüþümlerin implicit olarak yapýlmasýný istemiyorsak explicit olarak bildirmemiz gerekir
				{
					std::cout << "operator int()\n";

					return 1;
				}

			};

			int main()
			{
				Nec mynec;

				int ival{};

				ival = static_cast<int>(mynec); // tür dönüþtürme operator int fonksiyonu çaðýrýlýr
			};
		
		SORU:Baþka bir sýnýfa dönüþüm yapabilir miydik? EVET
			class Erg{};

			class Nec{
				public:
					 operator Erg()const;
			};

			int main()
			{
				Erg erg;
				Nec mynec;

				erg = mynec; // Nec türü Erg türüne dönüþüyor
				erg = mynec.operator Erg(); // ikiside ayný anlama geliyor
			}

		SORU:tür dönüþtürme operatörlerinde hedef tür function pointer türü olabilir mi? EVET
			usin fptr = int(*)(int);
			class Nec{
				operator fptr()const;
			}
			 
		tür dönüþtürme operatörlerini neden kullanýrýz?
			bazý sýnýflarda zaten doðal olarak interface'e bizim eklemek istediðimiz bir api 
				class Fraction{
					public:
						Fraction(int nom = 0,int den = 1) : m_nom(nom),m_den(den){}

						explicit operator double() const
						{
							return static_cast<double>(m_nom) / m_den;
						}
					private:
						int m_nom, m_den;
				};

				int main()
				{
					Fraction f1(3,7);
					Fraction f1(3);
					Fraction f1;

					double dval = static_cast<double>(f1);

					std::cout<<"dval =" << dval<<'\n';
				}	

			bazý sýnýflarýn isimlendirilmiþ dönüþüm fonksiyonlarý var
			int main()
			{
				std::string{"meric turkcan"};

				const char* p = str // str yi const char* türüne dönüþtürücek doðrudan bir operatör fonksiyonu yok

				p = str.c_str(); // isimlendirilmiþ bir fonksiyonla bu dönüþüm yapýlabiliyor ama operator fonksiyonu ilede yapýlabilirdi ama böyle tercih edilmiþ

			}

			ÖRNEK 2
				functional kütüphanesinde tanýmlana reference wrapper adýnda generic bir sýnýf var

				int main()
				{
					using namespace std;
					
					int x = 10;
					reference_wrapper r = x; // aslýnda kendisi bir referans deðil ama referans olarak kullanýlýyor üstelik re-bindble normalde referenslar tekrardan baðlanamaz
					reference wrapper sýnýfý bir pointerý sarmalýyor ve biz böyle bir nesne oluþturduðumuzda aslýnda ctor sýnýfýn ver elemaný olan pointera x'in adresini yerleþtirmiþ oluyor

					++r; // nasýl oluyorda bu ifadeyi yazdýðýmýzda x deðiþkenini deðeri 11 oluyor?
					reference wrapper sýnýfýnýn tür dönüþtürme operatör fonksiyonu var bu örnek için int& türüne dönüþtürüyor 
					derleyici bu ifadede ++r.operator int&() fonksiyonuna çaðrý yapýyor sarmaladýðý pointerýn göterdiði nesneye referans döndürüyor

				}

		nerelerde logic yorumlama yapýlýyor?
			!exp
			exp1 && exp2
			exp1 || exp2
			exp ? op2 : op3
			if(expr)
			while(expr)
			do while(expr)
			for(;expr;)

		SORU:
			class Sint{

			}

			class SmartPtr{
			}
			
			int main()
			{
				Sint i;
				SmartPtr ptr;

				if(i) {} 
				if(ptr) {} //  her ikisindede böyle ifadelerde bool türüne bir dönüþüm bekleniyor logic ifade beklenen yerde kullanmak için operator bool fonksiyonunu tanýmlarsak bunlarý legal kýlmýþ oluruz
				diðer derste hoca anlatacak
			}
*/