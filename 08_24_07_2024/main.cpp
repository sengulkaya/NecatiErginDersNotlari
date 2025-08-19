/*

function overloading ile ilgili ilgili bir konu daha var
	C++ dilinde proje geliþtirirken C de oluþturulmuþ kaynak dosyalarýnýda kullanýyoruz

		zeki.h
			int sum(int x,int y);
		zeki.c
			int sum(int x,int y)
			{
				return x + y;
			}

		main.cpp
			#include "zeki.h"

			int main()
			{
				auto x = sum(45,78);

				std::cout<<x;
			}

		iki dil arasýnda ki linker farký olduðu için linker hatasý verir C derleyicileride C++ derleyicileride inline expansion söz konusu deðilse
		çaðýrýlan foknsiyona iliþkin linkera yönelik derleyici oluþturduðu obje dosyada bir external reference yazýyor yani çaðýrýlan fonksiyonu temsil eden bir referans derleyici ile
		linker arasýnda kararlaþtýrýlmýþ linkerda obje dosyalarý arasýndaki baðlantýyý derleyicinin obje dosyalara yazdýðý external referenslarý takip ederek birleþtirme iþlemlerini yapýyor
		C dilinde function overloading yok fakat C++ dilinde function overloading var C dilinde function overloading olmadýðý için derleyiciler obje dosyaya çaðýrýlan fonksiyona 
		iliþkin bir referans isim yazdýklarýnda bu isim sadece fonksiyonun ismi ile dekore ediyorlar 

		C nin yazdýðý isim örneðin þöyle olsun C de buraya kadar yeterli baþka bir sum fonksiyonu olamaz
			@sum

		fakat C++ derleyicileri için bu durum geçerli deðil eðer derleyici gerçekten linker için yazacaðý referans ismi sadece fonksiyonun isminden dekore etseydi
		function overlaoding olmasý durumunda iki ayrý overload arasýndaki fark nasýl anlaþýlacaktý C++ derleyicinin referans isim olarak objeye yazmasý farklý bir deceration gerekiyor
			@sum_i_i // tamamen derleyiciye baðlý hoca örnek olarak verdi int int parametreli sum fonksiyona iliþkin overloading
			@sum_d_d // double için

		yukarýdaki problemde derleyicinin bu fonksiyonun C de yazýlmýþ C de derlenmiþ bir fonksiyon olduðunu bilmediði için derleyici doðal olarak o fonksiyonuda 
		C++ fonksiyonu olarak ele alýyor sum çaðrýsýnda linkera referans yazarken C++ tarzý dekore ediyor böylece link aþamasýna geldiðinde linker fonksiyonu bulamýyor 
		çünkü ikisi ayný deðil gerçekte olan sum fonksiyonu C diline göre dekore edilmiþ

			zeki.h
				extern "C" int sum(int x,int y); // extern "C" bildirimi ile link aþamasýndaki hata gitmiþ olur bunun C derleyicisi ile derleneceðini belirtiyor

			zeki.c
				int sum(int x,int y)
				{
					return x + y;
				}

		main.cpp
			#include "zeki.h" 

			int main()
			{
				auto x = sum(45,78);

			}

		Extern C decleration(C++ dilinde olan bir bildirim)
			bunun çözümü þu þekilde biz derleyiciye öyle bir bildirim yapýcaz ki diyeceðiz ki derleyici bu fonksiyon bir C fonksiyonu C de derlenmiþ dolayýsýyla sen bu fonksiyona 
			çaðrý yaparken bunu C tarzý dekore ediceksin C++ tarzý deðil çünkü C++ tarzý dekore ederse linker bulamýyacak buna extern C bildirimi deniyor

		ama þöyle bir problem var modül C de derlenecek ama hem C de hemde C++ dilinde kullanýlabilecek
			oðuzhan.h
				int foo(int,int); // c derleyicisinde extern c bildirimi olmadýðý için bildirimi böyle görmesi gerekiyor
				
				ama c++ derleyicisi görücekse
					extern "C" int foo(int,int); þeklinde görmesi gerekiyor bu problemin çözümü ayrý ayrý headlerlar oluþturmak olabilir C de kullanýlacak header 
					C++ dilinde kullanýlacak header fakat onun yerine conditional compiling(koþullu derleme) komutlarýndan faydalanýyoruz

					eðer diyelim ki birden fazla fonksiyonun extern "C" bildirimini yapacaksak bunu yapmanýn alternatif bir yolu var
						extern "C"
						{
							int foo(int,int);
							int bar(int,int);
							int baz(int,int);
							int bom(int,int);
							
							bu durumda bu fonksiyonlarýn her biri için extern "C" bildirimi yapmýþ oluyoruz bunu böyle olmasýnýn esas sebebi conditional comopiling ile 
							hem C ye hemde C++ diline uygun hale getirmek
						}

						samet.h
							bu headerdaki bildirimleri hem C derleyicisine hemde C++ derleyicisine vermek istiyorum ama C++ derleyicisinin extern "C" bildirimi ile görmesini istiyorum
							C de de C++ ta da pre-defined macro denen varlýklar var(ön tanýmlý makro)

							#ifdef __cplusplus
							extern "C" {
							#endif

								int foo(int,int);
								int bar(int,int);
								int baz(int,int);

							#ifdef __cplusplus
							}
							#endif
--------------------------------------------------------------------------------------------------------------------------------------------------
CLASSES
	C++ Sadece Nesne Yönelimli Programlama dili deðil NYP'ye de destek veren çok paradigmalý bir programlama dili C++ 'ýn gücünün en önemli kýsmý Data abstraction kavramý 
	hocanýn kendi tanýmý ile problem domaninde ki varlýklarýn yazýlýmsal olarak temsil edilmesi 
	
	classlar c++ dilinin sentaksýnýn en fazla kural barýndýrdýðý yer

	C de bulunan structlar C++ dilindede bir sýnýf ister struct anahtar kelimesini kullanayým ister class'ý kullanalým oluþturduðumuz türler class type

	bir sýnýf oluþturmak için derleyiciye bir sýnýfýn varlýðýndan haberdar etmek için ya o sýnýfa iliþkin bir bildirimini yada o sýnýfýn tanýmýný yaparýz

	class Nec;(incomplete type) // standartýn kullandýðý teknik terim forward decleration deniliyor hoca complete type ile incomplete type konusuna deðinecek
	
	C++ dilinde sýnýflarýn hiç bir member'ý olmayan sýnýf oluþturulabilir bunlara empty class deniliyor
		class Nec{};

		class Nec
		{
			// sýnýfýn içinde bildirilen varlýklara class members deniliyor bu memberlar farklý kategorilerde olabiliyor
				1)data member -> int mx;
				2)member function -> void foo();
				3)type member - member type- nested type hepsi ayný anlamda -> enum,typedef,using,union,class,struct
					class Nec{
						class Erg // nested type;
						{

						};
					};
		};

		class dýþýnda tanýmlanan namespace scopeta olan fonksiyonlar için global function/free function/stand-alone function terimlerini kullanabiliriz
			void foo();

	C++ SCOPE KATEGORÝLERÝ
		1)namespace scope(file scope'u da içeriyor)
		2)block scope
		3)class scope
		4)function prototype scope
		5)function scope

		ismin kapsamý ve nerelerde kullanýlabileceðine dair kurallar bu 5 kural setinden birine iliþkin olmak zorunda
			
	CLASS SCOPE
		öyle isim kullanýmlarý var ki bu kullanýmlara iliþkin isimler bir sýnýf tanýmýnda aranýrlar 3 tane senaryo var bu senaryolarýn oluþturduðu kümeye 
		qualified name(ismin nitelenmesi) deniyor
		
			a)bir isim nokta operatörünün sað operandý ile kullanýlþmýssa -> x.y (x hangi sýnýf türünden nesneyse o sýnýfta y yi arayacak)
			b)ok operatörünün(member selection arrow) sað operandý olarak kullanýlýyorsa -> ptr->a (ptr hangi sýnýf türünden adres ise a yý o sýnýfta arayacak)
			c)scope resolution operatörünün sað operandý olarak kullanýlýyorsa Nec::b (Nec sýnýfýnda b ismini arayacak) 
			
		struct Nec
		{
			int x;
		}


		int main()
		{
			auto b = x; // x ismini burda bulamayacak sentaks hatasý verecek

			Nec::x; // böyle çaðýrmak için x'in static olmasý gerekiyor
			
			Nec mynec;

			mynec.x // mynec Nec sýnýfýndan nesne olduðu için x deðerine ulaþýr

			Nec * necptr= &mynec;

			necptr->x; // necptr Nec sýnýfý türünden bir adres olduðu için Nec sýnýfýndaki x deðerine ulaþýyor

		};

		int x; // global namespace

		class Myclass
		{
			int x; // Myclass class scope
		}

		class Nec
		{
			int x; // Nec class scope
		}

		farklý scopelarý olduklarý için hata vermez
	
	NAME LOOKUP VE CONTEXT CONTROL KONUSUNUN KARIÞITIRILMASI 
		
		1)namelookup
			2)context control
				3)acces control yapýlýr

		int func(int x,int y)
		{
			return x + y;
		}

		int main()
		{
			int func = 4;
			func(2, 5); // func deðiþkeni burda func fonksiyonunu maskeledi(namelookup baþarýlý oldu ve bitti bir daha namelookup baþlamaz burda context controle takýldý)

			}

	ACCESS CONTROL
		class Myclass
		{
			// public: anahtar kelimesi bulunsaydý access controle takýlmayacaktý
			int x; // x default olarak acces control bildirilmediði için private
		};

		int main()
		{
			Myclass m;
			m.x = 5; // Myclass::x cannot access private member declared in class Myclass
			bu kod namelookuptan baþarýyla geçti context controldende geçti ama en son access controlde takýldý
		}

	NOT:struct ile class anahtar kelimesinde ki 1 2 tane farklýklara hoca ilerde deðinecek nested typelar için böyle bir ayrým yok

	DATA MEMBER VE MEMBER FUNCTIONLARI ÝKÝ KATEGORÝYE AYIRIYORUZ
		data member
			a)non-static data member -> int x; 
				sýnýflarýn non-static data memberlarý sýnýf nesnesinin(object) kendisine ait bu yüzden storage deðerini arttýr
				nesne yönelimli programlama tarafýnda kullanýlan terim object burda biraz kavram karmaþasýný doðuruyor C++ dilinde ki object terimi NYP deki object terimi deðil 
				yani C++ standartý objecti NYP deki object anlamýnda kullanmýyor NYP deki object ve instance terimleri sýnýf türünden nesnelerle iliþkilendiriliyor 
				bu yüzden sýnýflarýn non-static veri elemanlarýna instance variable deniliyor
								
				class Myclass{
					int x,int y;
				};

				int main()
				{

				Myclass m1,m2; // m1'in de x ve y deðiþkeni olur m2'nin de x ve y deðiþkeni olur

				}

				bir veri elemanýna sahip olmasa dahi sýnýfýn storage deðeri 1 byte'dýr sizeof hiç bir zaman 0 deðeri üretmez

				class Myclass{

				};

				int main()
				{
					Myclass m;
				}

			b)static data member -> static int x; 
		member function
			a)non-static member function -> int foo();
			b)static member function -> static int foo();

		SORULAR:
			1)function overloading var mý yok mu?
				void func(int); // namespace scope

				class Myclass
				{
					void func(double); // bu func class scopeta olduðu için function overloading yoktur çünkü farklý scopetalar
				}

			2)function overloading var mý yok mu?
				class Myclass
				{
					void func(double); 
					void func(int); 

					// scopelarý ayný olduðu için function overloading
				}

			3)function overloading mi re-decleration mý?
					void func(int,int);
					void func(int,int); // bunlar re-decleration

				class Myclass{
					void func(int,int);
					void func(int,int); // sýnýflarýn member functionlarý re-decleration edilemez bu yüzden sentaks hatasý
				}
		
		ACCESS SPECIFIER
			sýnýflarýn memberlarý sýnýfýn eriþim ayrýcalýklý alanlarýndan birinde bildirilmek zorunda 3 tane access scpecifier mevcut
			public
				bir sýnýfýn public öðelerine o sýnýftan olan nesnenin tüm public bölümüne eriþimi var
			protected
				inheritance ile ilgili sýnýfýn kendisi ve o sýnýftan kalýtým yoluyla elde edilen sýnýflar eriþebiliyor
			private
				sýnýfýn kendisine açýk ama dýþarýya kapalý yani sýnýfýn içinde eriþilebilirler
			
			class Myclass
			{
				public: // private alanýna kadar public eriþim statüsünde
							
					int x;

				private: // protected alanýna kadar private eriþim statüsünde
					int y;
				
				protected: // altýnda her hangi bir baþka access specifier belirtilmezse tüm belirtilen memberlar protected olur
					int z;
			}

			bu keywordler birden fazla kez kullanýlabilir
				public:

				private:

				public:
			
			struct ile class arasýndaki ilk fark(bir fark daha var inheritance konusunda görülecek)structlarda default eriþimleri public classlarda ise private
				struct Nec
				{
					int x;
					void foo();
				}

				class Erg
				{
					int y;
				}
				
				int main()
				{
					Nec nec;
					Erg erg;

					nec.x = 10; // geçerli;

					erg.y = 5; // access  controle takýldý
				}
				
			client kodlarýn doðrudan isimle eriþmesini istemediðimiz sýnýfýn üyelerini sýnýfýn private bölümüne koyarýz ama clientlarýn doðrudan isimle kullanmasýný 
			istediðimiz kodlarý sýnýfýn public bölümüne koyuyoruz bu ilkeye DATA HIDING YADA INFORMATION HIDING denir 

				class Myclass
				{
					void foo(int); // private access
				}

				int main()
				{
					Myclass m;
					
					m.foo(12); // eriþim hatasý
				}

			SORU:
				1)kod legal mi ve function overloading var mý yok mu?
				
					class Myclass
					{
						public:
							void foo(int);
						private:
							void foo(double); // access specifierlar farklý bir scope deðil hepsi ayný class scopeta olduðu için function overloading var ve kod legal 
					}; 
			
			sýnýfýn veri elemanlarýný tipik olarak private bölümüne koyuyoruz böylece bir takým avantajlar saðlamýþ oluyoruz
				1)sýnýfýn veri elemanlarýný ve bunlarýn türlerini bilmezsek o sýnýfý daha kolay kullanabiliyoruz üstümüzdeki öðrenme yükü azalýyor
				2)sýnýf nesnenelerini run timeda hizmet verirken çalýþma þeklini bozmayý riske etmemiþ oluyoruz
			
				mesela sýnýfýn tüm memberlarýný public bölümüne koysaydýk bu memberlara nokta operatörüyle yada ok operatörüyle herkes eriþecekti onlarý olmasý gereken 
				deðerler dýþýnda baþka deðerler verilmesi kontrolümüzden çýkacaktý eðer sýnýfýn elemanlarýnda bir deðiþiklik yapýlsa o zaman kullanýcý kodlarýnda deðiþtirilmesi
				gerekicekti buda implementasyona baðýmlýlýk demek sýnfýn private bölümüne veri elemanlarýný koyduðumuz zaman zaten client kodlarla onlarýn iliþkisini kesiyoruz
				alacaðýn hizmeti bizim sunduðumuz fonksiyonlara çaðrý yaparak alacaksýn demiþ oluyoruz ve veri elemanlarýný kullanmadýðý için daha sonra sýnýfýn impelemansyonunda 
				veri elemanlarýný deðiþtirmemiz durumunda client kodlar kýrýlmayacak veri gizlemenin temel mantýðý bu
				
				eriþim kontrolü illa uygulanmak zorunda deðil hoca buna deðiniyor
					sýnýf prblem domaninide bir varlýðý temsil ediyor ama sýrf information hiding olsun diye private bölümüne koyulmuþ get ve set fonksiyonlarý koyulmuþ 
					ama bir sýnýfýn nesneleri set edilmiyor  
					kýsacasý private olmasý gerekmiyorsa private yapma

				C dilindede public private ayrýmý dosya bazýnda var 
					global bir deðiþekene diðer dosyalardan eriþim saðlamak istiyorsak
						extern int x; // deðiþenler default extern deðil extern anahtar sözcüðünü belirtmemiz gerekiyor
					
					bir fonksiyonun client kodlar tarafýndan çaðýrýlmasýný istiyorsak header dosyasýnda extern bildirimini yapýyoruz
						void func(int); // default olarak extern
					
					ama clientlarýn doðrudan eriþmesini istemeðimiz sadece implementasyonun eriþmesini istediðimiz global deðiþkenleri yada fonksiyonlarý static anahtar
					sözcüðüyle tanýmlýyoruz
						static int g;
				
		SINIFLARIN MEMBER FUNCTIONLARI
			sentaks düzeyinde client kodlarýn sanki c deki struct'ýn elemanlarýna nokta operatörüyle ve ok operatörüyle eriþir gibi isimlere eriþtikleri ama aslýnda o eylemi yapan 
			sýnýf nesnesinin adresini örtülü olarak alan fonksiyonlardýr sýnýfýn non-static member functionlarý týpký C de ki global fonksiyonlarda olduðu gibi bir sýnýf
			nesnesinin adresini isteyen bir sýnýf nesnesinin adresiyle çaðýrýlan fonksiyonlar sentaks 
			düzeyinde gizli parametre olarak bulunur yani sýnýfýn non-static member functionlarý implicitly olarak bir sýnýf nesnesinin adresini alýr ve her zaman 1 adet 
			fazla gizli parametreleri bulunur
			
				class Nec
				{
					public:
					void foo(); // bu fonksiyonun görünürde 0 parametre deðeri var ama gerçekte 1 tane gizli parametre deðiþkeni var bu sýnýf türünden bir pointer -> Nec*
				};

				int main()
				{
					Nec mynec;
					mynec.foo(); // derleyici burda mynec nesnesinin adresini Nec sýnýfýndaki foo fonksiyonunun parametresine geçiyor foo global bir fonksiyon olsaydý 
					ayný bu þekil kullanacaktýk -> foo(&mynec); ikisi ayný anlamda
				}

				// class definiton
				class Fighter
				{
					public:
					int id;
					const char name[20];

					void attack(const Fighter fighter&);
				};

				int main()
				{
					Fighter fighter1,fighter2;

					fighter1.attack(fighter2); // burda fighter1 fighter2 ye saldýrýyor

					member functionlarýn ve referanslarýn saðladýðý yarar kodun okunmasýnýn ve kullanýlmasýnýn kolaylaþmasý
				}

				headera client kodlarýn kullanacaðý isimlere iliþkin varlýklarý sýnýflar çok büyük çoðunlukla ama her zaman deðil class definition headerda olucak

				öyle bir sýnýf olabilir ki clientlarla hiç bir alakasý olmaz sadece implementasyon tarafýnda kullanýlýyor olabilir böyle durumlarda header file'a koymak yerine 
				implementasyon dosyasýna koyacaðýz böyle sýnýflarý nested typeta yapabiliriz
			
				person.h
					class Prson
					{
						public:
							void set_person_name(const char* p);
					};
				person.cpp
					global fonksiyonlardan farklý olarak derleyicinin bu fonksiyonun tanýmý oluðunu anlamasý için nitelenmiþ isim kullanýyoruz
						void Person::set_person_name(const char* p)
						{

						}

				class Nec
				{
					public:
						void set(int x,int y);
					private:
						int mx;my;
				};

				int main()
				{
					Nec::set(3,6); // burda namelookup baþarýyýla yapýlýr ama context kontrole takýlýr çünkü set fonksiyonu bir non-static member function olduðu için 
									  bir sýnýf nesnesiyle çaðýrýlmasý gerekir 
				}

				member functionlarýn nitelenmemiþ ismin kullanýlmasý durumunda isim arama kurallarý farklý
					bloklarda aranacak 
					sonra class definition içinde aranacak

					void Nec::set(int x ,int y)
					{
						x = x; // Nec sýnýfýndaki x parametre deðiþkeni tarafýndan maskelenmiþ bunu önlemek için qualified name olarak Nec::x kullanabiliriz
						Nec::x = x; // scope resloution operatörünü binary olarak kullanýyoruz böylelikle direkt class scopeta arayacak	
					}
*/