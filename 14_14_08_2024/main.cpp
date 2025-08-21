/*

friend bildirimlerinden devam 3 tane maddemiz vardý
		1)global fonksiyonlara verilen friendlik
			
			class Myclass
			{
			public:
				friend int foo(int);
			private:
				int mx;
				void bar();
			};

			int foo(int x)
			{
				// burda sýnýfýn private bölümüne eriþim sentaks hatasý olarak deðerlendirilmez

				Myclass m;
				auto val = m.mx;
			}

			sýnýfýn hangi bölümünde friend bildirimi yaptýðýmýz farkeder mi? FARKETMÝYOR public private protected hepsinde bildirebiliriz deðiþen bir þey olmuyor

		2)bir baþka sýnýfýn bir member functionuna verilen friendlik

			class Nec{
				public:
				int foo();
			}

			class Myclass{
				public:
					friend int Nec::foo();
				private:
					int mx;
			}

			int Nec::foo()
			{
				Myclass m;

				m.mx = 5;
			}

		3)bir sýnýfýn tamamýna verilen friendlik(nadiren karþýmýza çýkar)

			class Myclass
			{
				public:
					friend class Nec; // Nec sýnýfý Myclass sýnýfýnýn private elemanlarýna eriþebilir
				private:
					int mx;
			}

			class Nec{
				void foo()
				{
					Myclass m;
					m.mx = 5;
				}
			}

	Sýnýfýn special member functionlarýnýda friendlik verebiliriz	

	generic programlama tarafýnda friendlik daha karmaþýk hale gelecek ileride bahsedilecek

	FRIEND HAKKINDA KURALLARA ÖRNEK
		1)A sýnýfý -> B sýnýfýna friendlik versin
			class A
			{
				friend class B; // burada B sýnýfýda A sýnýfýna friendlik vermiþ olmuyor yani A sýnýfý B sýnýfýnýn private bölümüne eriþemez
			}

		2)Geciþkenlik yok yani A -> B sýnýfýna friendlik versin B sýnýfýda -> C sýnýfýna friendlik versin
			B sýnýfý A sýnýfýnýn private bölümüne eriþebilir C sýnýfýda B sýnýfýnýn private bölümüne eriþebilir
			ama C A'nýn private bölümüne eriþemez burada hoca inheritance konusuna vurgu yapýyor
		
		3)bir sýnýfa friendlik vermek istiyoruz ama bütün private bölümüne deðil istediðimiz fonksiyona eriþmesini istiyoruz böyle bir þey mümkün mü? HAYIR
		bunu gerçekleþtiren doðrudan bir araç yok ama dolaylý olarak idiomatik bazý yapýlarý kullanarak bunu gerçekleþtirmek mümkün buna ATTORNEY-CLIENT IDIOM deniliyor
			
			"Attorney" (avukat), eriþimi aracýlýk eden sýnýftýr.

			"Client" (müþteri), eriþmek isteyen kod/sýnýftýr.

			"Target" (hedef), eriþilmek istenen sýnýftýr (private/protected üyeleri olan).

			Amaç: Target sýnýf, doðrudan Client'a friend yapmak yerine, araya bir Attorney sýnýfý koyar, sadece bu sýnýfa friend eriþim verir. Böylece eriþim daha kontrollü olur

		// Target class: Eriþimi korunan sýnýf
		class Engine {
		private:
			void start() const {
				std::cout << "Engine started!\n";
			}

			// Sadece Attorney'e friend veriyoruz
			friend class EngineAttorney;
		};

		// Attorney class: Ara katman, sadece start fonksiyonunu açar
		class EngineAttorney {
		public:
			static void startEngine(const Engine& e) {
				e.start(); // private fonksiyona eriþim burada saðlanýyor
			}
		};

		// Client class: start()'a doðrudan eriþemez ama Attorney üzerinden eriþebilir
		class Car {
		public:
			void run() {
				Engine e;
				EngineAttorney::startEngine(e); // Engine'e doðrudan deðil, Attorney üzerinden eriþim
			}
		};

		int main() {
			Car myCar;
			myCar.run(); // Output: Engine started!
		}

HIDDEN FRIEND
 bir çok durumda sýnýfýn free function olan friend fonksiyonlarýný doðrudan inline olarak sýnýf içinde tanýmlayabiliriz
 önemini ileride hoca anlatacak
	class Myclass
	{
		public:
			friend int foo(int)
			{

			}
	};	

idiom -> programlama diline baðlýdýr baþka bir programlama dilinde o kalýpsal yapýyý kullanamayabiliriz 
	idiom burada kalýplaþmýþ çok sayýda programcýnýn kodu daha iyi hale getirmek için kullandýðý kodsal yapýlar anlamýna geliyor

pattern -> hoca örüntü demeyi tercih ediyor dilden baðýmsýz bir yapýya iþaret ediyor çoðu programlama dilinde kullanýlan kalýplar   
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
OPERATOR OVERLODING

	C++ dilinde bir sýnýf nesnesi bir operatörün operandý olduðunda derleyici dilin kurallarýna göre operatörün operandý olmuþ sýnýf nesnesi ifadesini bir fonksiyon çaðrýsýna dönüþtürüyor
	yani ortada doðrudan fonksiyon çaðrý operatörü yok ama kodun anlamý derleyicinin bir fonksiyona çaðrý yapmasý 
	bunlara operator functions deniliyor

	a + b ifadesi olsun a ve b bir sýnýf türünden nesneler olsun bu durumda tanýmlanmýþ bir fonksiyon varsa derleyici a + b ifadesini bir operatör fonksiyonuna yapýlan çaðrý ifadesine dönüþtürüyor
	peki burada çaðýrýlan fonksiyon global function mý yoksa sýnýfýn non-static member functioný mý ? HER ÝKÝSÝDE OLABÝLÝR 
	
	SORU:run time'a yönelik bir mekanizma mý compiler time'a mý?
		compile time'a yönelik bir mekanizma çünkü derleyici hangi fonksiyonun çaðýrýldýðýný derleme zamanýnda anlýyor

	operatör fonksiyonlarý static member function olamaz

	operatör overloadingten faydalanabilmemiz için intuitive olmamýz gerekiyor

	OPERATOR OVERLOADING KURALLARI
		1)operatör overloadingten bahsedebilmemiz için operatörün operandý olan ifadelerden en az birinin bir sýnýf türünden yada bir enumaration türünden olmasý gerekiyor
			
		2)overload edilecek operatörün C++ dilinin operatör kümesinde olmasý gerekiyor
			örneðin @ C++ dilinin operatör kümesinde yok
		
		3)operatör overloading fonksiyonlarýný istediðimiz gibi isimlendiremiyoruz hangi operatörü overload ediyorsak onu belirtmemiz gerekiyor
			operator+ ,operator[] gibi

		4)dilin bütün operatörleri overload edilemiyor bazý operatörler için overloading mekanizmasý yasaklanmýþ
			sizeof
			:: scope resolution operatörü
			. member access operatörü
			.* pointer to member operatörü
			? : conditional operatörü
			->* pointer to member operatörü
			typeid

		5)operatör fonksiyonlarýnýn bazýlarý free function olarak tanýmlanamýyor member function olmak zorundalar
			() function call operatörü
			[] subscript operatörü
			-> member access operatörü
			= assignment operatörü
			type cast operatörleri

		6)tüm operatör fonksiyonlarý istisnasýz isimleriylede çaðýrýlabilir
			class Myclass{};

			int main()
			{
				Myclass m1,m2;

				m1.operator=(m2); // m1 = m2 
			}

		7)function call () operatörü hariç diðer operatör overloading mekanizmasýnda kullanýlan fonksiyonlar default argument alamazlar
			
		8)operatör overloading mekanizmasýnda ki operatörlerin (arity) deðiþtirilemez yani operatörün unary yada binary olmasý 
			
			binary operators
				x * y // binary bir operatörü olduðu için buna uygun sentaksla overload edilecek bu overloading free functionla yapýlýyorsa bu durumda
			
				çarpma oepratörünün sol operandý ve sað operandýda o fonksiyonun parametrelerine argüman olarak gönderiliyor
				derleyici x * y ifadesini operator*(x,y) ifadesine dönüþtürücek bu global fonksiyonun 2 tane parametre deðiþkeni olmalý bunun dýþýnda baþka bir parametre olursa sentaks hatasý olur
				derleyici sol operandý 1.ci parametresini sað operandý 2.ci parametresine geçiyor 
			
					class Matrix{
						public:

					};

					bool operator<(const Matrix&,const Matrix&)

				fakat binary operatörünü overload edicek fonksiyon member function ise o member function binary operatörünün sol operandý için çaðýrýlýyor,
				this pointerý sol operand olan nesnenin adresi x > y ifadesini derleyici x.operator>(y) ifadesine dönüþtürüyor bu functionlar tek parametre olmak zorundalar bunun dýþýnda 
				baþka bir parametre olursa sentaks hatasý olur
				
					class String{
						public:
							bool operator<(const String&) const;
					}

			unary operators
				!ptr// unary opeartör olduðu için buna uygun sentaksla yazýlmasý gerek

				unary operator olan ifade global function ise derleyici operatör ifadesini operator!(ptr) ifadesine yapýlan bir çaðrýya dönüþtürücek operatörün operandý olan sýnýf nesnesinide 
				bu fonksiyona yapýlan çaðrýda argüman olarak kullanýcak tek parametre almak zorundalar bunun dýþýnda sentaks hatasý olur 

					class SmartPtr{};

					bool operator!(const SmartPtr&)const;

				unary operator bir member function ise parametresi olmaz zaten o nesne için çaðýrýlýr
					class SmartPtr{
						public:
							bool operator!() const;
					};

			SORU:sentaks hatasý mý deðil mi?
				class Myclass
				{
					public:
						Myclass operator+(); // sentaks hatasý deðil çünkü bu toplama operatörünü overload etmiyor sign operatörünü overload ediyor
						Myclass operator+(Myclass) const; // toplama operatörünü overload ediyor
				}


		9)operatör overloading mekanizmasýnda function overloadingte kullanýlabilir

			class Bigint{
				public:
					Bigint operator+(int)const;
					Bigint operator+(long)const;
					Bigint operator+(long long)const;
			}

			int x = 10;
			double dval = 3.4;

			operator<<(cout.operator<<(x), '\n'); // derleyici function overload resolution ile int parametreli functionu çaðýrýyor
			operator<<(cout.operator<<(dval), '\n'); // derleyici function overload resolution ile double parametreli functionu çaðýrýyor

		atama operatör fonksiyonu demek illa ki special member function olmasý anlamýna gelmiyor
			class Myclass {
			public:
				Myclass& operator=(int) {

					std::cout << "operator=(int)\n"; // Myclass sýnýfý türünden bir nesneye int atadaðýmýzda bu fonksiyon çaðýrýlacak
					return *this;
				}
				Myclass& operator=(double) {

					std::cout << "operator=(double)\n";// Myclass sýnýfý türünden bir nesneye double atadaðýmýzda bu fonksiyon çaðýrýlacak
					return *this;

				}

			};

			int main()
			{
				Myclass m;

				m = 5;
				m = 5.5;
			}

	10)operator overloading mekanizmasýnda operatörlerin öncelik seviyesini deðiþtiremeyiz
		class Bigint{
		};

		Bigint operator*(const Bigint&,const Bigint&);
		Bigint operator+(const Bigint&,const Bigint&);
		Bigint operator&const Bigint&,const Bigint&);

		int main()
		{
			Bigint b1,b2,b3,b4,b5;
			Bigint bx;

			bx = b1 * b2 + b3 * b4 & b5; // 5 adet operator olduðu için o kadar fonksiyon çaðýrýlmýþ oluyor 

			bx.operator=(operator&(operator+(operator*(b1,b2), operator*(b3,b4)), b5)); // ((b1 * b2)) + (b3 * b4)) & b5; bu iki kodun anlamsal olarak hiç bir farký yok
		
			bu operatörlerin yazým þekliyle öncelik seviyesini deðiþtiremeyiz
		}

		member function olsaydýlar
			Bigint operator*(const Bigint&)const;
			Bigint operator+(const Bigint&)const
			Bigint operator&const Bigint&)const;

			 int main()
			 {
				bx.operator=(b1.operator*(b2).operator+(b3.operator*(b4)).operator&(b5));
			 }

	SORU:global operator fonksiyonlarý neden var?
		1)x + 5;
		x.operator+(5); // x + 5 gibi bir iþlemi yapabiliyorsak 5 + x gibi bir iþlemide yapabilmemiz gerekiyor ama bu sefer sol operand bir sýnýf türünden olmamýþ oluyor int türünün bir operator fonksiyonu 
		olamaz bu iþi global operator fonksiyonlar yapabilir yani global operator fonksiyonlar olmasaydý sol operandýn bir sýnýf türünden olmamasý durumunda sýnýfýn üye operatör 
		fonksiyonuna çaðrýya dönüþtürme imkanýmýz olmazdý
		
		2)
			class Matrix{};

			std::ostream& operator<<(std::ostream&,const Matrix&);

			int main()
			{
				Matrix m;

				std::cout << m; // inserter deniliyor 
			}

	 referans semantiði olmasaydý operator overloading mekanizmasýný kullanmak mümkün deðildi

	SORU:operator overloading ile const corretncess arasýndaki iliþki nedir?
		
		toplama operatörünü ve büyüktür operatörünü düþünelim bu operatörler side effecte sahip deðil örneðin a + b ifade karþýlýðý bir iþlem yapýldýðý için program stateinde bir deðiþiklik olmuyor 
		ne a ne b deðiþecek a + b yazmakla bir fonksiyonu çaðýrýlmasýný saðlýyorsak fonksiypnun a ve b yi deðiþtirmeme garantisi vermesi gerekiyor
		
		oeprator+(const Matrix&,const Matrix&) // global operator+ fonksiyonunda burda const anahtar sözcüðünü kullanmasaydýk semantik olarak ciddi bir hata olurdu kodu okuyanlarý yanýltýrdý ve
		const nesneleri ve r value deðerleri baðlamayazdýk

		member function olsaydý

		Matrix operator+(const Matrix&) const;

		unary operatorler için
			bool operator!() const; // side effecte sahip olmadýðý için const member function olmalý

		eðer operator bir mutatorsa const olmamasý gerek
			operator*=(int); // 
			
		return value type
			dilin operator overloadinge ilþkin kurallarý fonksiyonlarýn geri dönüþ deðeri üstünde bir kýsýtlama yapmýyor
				int operator+(const Matrix&)const; // bir matris ile bir matrisi topluyoruz ve bir tam sayý elde ediyoruz semantik olarak doðru deðil ama derleyici burda hata vermiyor 
				sentaks hatasý olmamasý böyle bir bildirimin doðru olduðu anlamýna gelmiyor
				
				fonksiyonun geri dönüþ deðeri türünün ne olacaðýný problem domaini belirliyor mesele karþýlaþtýrma operatörleri primitive türlerde bool deðer üretiyor
					
					class Date
					{
						public:
							Date operator+(int ndays)const;
							Date operator-(int ndays)const;
							Date operator-(const Date&)const;
					};
					
					int main()
					{
						Date today{14,8,2024};
						Date dx{5,5,2017};

						today - dx;
					}
+
			SORU:
				class Matrix{
					public:
						Matrix& operator+(const Matrix&)const; // geri dönüþ deðeri referans olmasý iyi bir fikir olabilir mi? HAYIR
						referans bir nesnenin yerine geçtiði için fonksiyonun geri dönüþ deðeri kime referans olacak? eðer fonksiyonun geri dönüþ deðeri otomatik ömürlü bir nesneyse ona referans döndürmemiz
						undfined behaviour ve dangling reference böyle fonksiyonlarýn geri dönüþ deðerini l value reference yapmamalýyýz
				
				};

			operator fonksiyonlarýnýn bir kaç istisna dýþýnda çok büyük çoðunlukla geri dönüþ deðerini discard etmek logic bir hata
				class Bigint
				{
					public:
						[[nodiscard]] Bigint operator+(const Bignit&);
				}

				özellikle side effect olmayan operatörlerin nodiscard attribute ile nitelenmesi doðru bir yaklaþýmdýr

			bir operatörü overload etmek istiyoruz ama free function mý olsun member function mý olsun?
				bu sorunun net bir cevabý yok fakat bir çok kiþinin uyduðu ilke simetrik operatörleri global operator fonksiyonu yapmak
				yani x + y yazmakla y + x yazmak ayný iþleme karþýlýk geliyorsa o zaman global operator fonksiyonu tercih ediliyor

				aritmatik operatorler ve karþýlaþtýrma operatörleri global operator fonksiyonu olarak tanýmlamak bir kural deðil ama daha iyi bir tercih olarak görülüyor

			https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines hoca bu sitedeki ilkeleri benimsememizi tavsiye ediyor

			SORU:
				class Myclass{
					public:
						Myclass operator+(int)const;

				  };

				  int main()
				  {
					Myclass m;
					m += 5; // burada + ve = operatörü ayrý ayrý overload edilmiþse += fonksiyonu otomatik var oluyor mu? HAYIR
				  }

				aynýsý C++20 de karþýlaþtýrma öperatörleri için geçerli deðil C++20 de operatör overloadinge çok büyük bir ekleme geldi dile yeni bir operatör eklendi
				<=> space ship operator bunun sayesinde 6 tane operatörü ayrý ayrý overload etmemize gerek kalmýyor
				sýnýfta ya sadece space ship operatörü var yada onun yanýnda == operatörüde var
*/