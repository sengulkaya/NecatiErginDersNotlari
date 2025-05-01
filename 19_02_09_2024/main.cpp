/*
 
namespace konusundan devam ediyoruz geçen dersin tekrarý yapýldý

hoca cppreference.com'dan örnek veriyor
	void f();
	
	namespace A{
		void g();
	}

	namespace X{
		using ::f; // global f is now visible as ::X::f
		using A::g; // A::g is now visible as ::X::g
	}

	void h(){
		X::f(); // calls ::f 
		X::g(); // calls A::g
	}


	2.ÖRNEK
		namespace nec{
			void foo()
			{
				std::cout<<"nec::foo()\n";
			}
		}

		namespace erg{
			using nec::foo;
		}

		int main()
		{
			erg::foo(); // foo sanki erg içinde tanýmlanmýþ gibi kullanabiliyoruz
		}
	
	3.ÖRNEK
		namespace foo{
			void foo()
			{
				std::cout<<"foo::f()\n";
			}
		}

		namespace bar{
			using foo::f;
		}

		namespace baz{
			using bar::f;
		}

		int main()
		{
			baz::f(); /
		}

	4.ÖRNEK
		namespace nec{
			namespace pro{
				void foo()
				{
					std::cout<<"nec::pro::foo()\n;
				}
			}
		}

		namespace erg{
			using nec::pro::foo;
		}

		int main()
		{
			erg::foo();
		}

USING NAMESPACE DIRECTIVE

	using namespace std; þeklinde kullanýlýr

	nesnted namespaceler içinde kullanýlabilir
		using namespace nec::erg::pro;

	burada directive bir namespace ismi için yapýlýyor namespace içindeki öðe için deðil üyenin kendisi namespace'se o zaman yazabiliriz
	ve bu namespace'in bildiriminin yapýldýðý scopeta visible olmasý gerekiyor
		
	direktifin kendisi
		a)doðrudan global namespacete
			using namespace std;
		b)bir namespace'in içinde
			namespace nec{
				using namespace std;
			}
		c)fonksiyon tanýmlamasýnda fonksiyonun bloðu içinde yada kapsayan bloklar içinde yapýlabilir
			int main()
			{
				using namespace std;
			}

	class definition içinde doðrudan kullanýlmasý sentaks hatasý
		class Myclass{
			using namespace std;
		}

	ama sýnýfýn bir member functioný olsaydý onun içinde tanýmlamak sentaks hatasý olmayacaktý


	peki bu direktif ne yapýyor?
		bu direktifin kendi scope'u var burada iki tane namespace söz konusu
		1)direktifin tanýmlandýðý namespace örneðin global namespace alanýnda yazýlmasý
		2)using namespace direktifi ile bildirilen namespace

		using namespace direktifi ile bildirilen namespace içindeki isimler sanki bu isim alaný içinde deðilmiþ gibi görünür durumda oluyorlar
			namespace ali{
				using namespace std; // std namespace'i içindeki her þey sanki std'nin içerisinde deðilmiþ gibi görünür durumda oluyorlar
				
			}

		bunlarý içine alan en dar isim alaný içinde using direktifinin kullanýldýðý yerde namespace'in isimleri visible duruma geliyor
			
			using namespace std;   // std namespace'i içindeki isimler sanki global namespacetymiþ gibi görülür durumda
				1)using direktifiiyle bildirin namespace std namespace'i
				2)bildirimin yapýldýðý namespace global namespace 

				ikisini içine alan en dar isim alaný global namespace 

		using bildiriminde olduðu gibi using namespace direktifininde kendi scope'u var
			SORU:using namespace bildirimini global namespacete yapmakla main fonksiyonu içinde yapmak arasýnda bir fark var mý? EVET VAR
				int main()
				{
					using namespace std; // burada yaptýðýmýz using namespace bildirimi sayesinde std namespace'i içindeki isimler sadece main içinde görünür olacak
				}

		 using namespace direktifini neden kullanmamalýyýz
			namespacelerin avantajlarýný tamamen göz ardý etmiþ oluyoruz

			ÖRNEK:
				namespace nec{
					x = 34;
				}

				namespace erg{
					int x = 567;
				}

				using namespace nec;
				using namespace erg;
				
				hem nec namespace'i içindeki isimler hemde erg namespace'i içindeki isimler sanki global namespacete bildirilmiþ gibi visible olacak
				
				int main()
				{
					x = 5; // ambiguity

					amacýmýzý isimleri birbirinden gizlemekti ama bunu burada ihlal etmiþ oluyoruz using namespace direktifini kulalnýrken çok dikkatli olmamýz gerekiyor

				}
			
		using bildirimiyle using namespace direktifinin farklý olduðu nokta
			using direktifi isimleri using direktifinin bulunduðu scopa enjekte etmiyor
				o isim tek olmak zorunda deðil
				namespace nec{
					int x = 34;
				}

				int main()
				{
					using namespace nec; 
					
					using nec::x // using bildirimi ile yapmýþ olsaydýk bu nec namespace'inde bulunan x buraya enjekte edilmiþ olacaktý ve sentaks hatasý olacaktý
					
					int x = 56; // burada name hiding olmuþ oluyor sentaks hatasý yok

				}

				ÖRNEK:
					namespace nec{
						int x = 34;
					}

					int x = 56; // sentaks hatasý using namespace direktifi yapýldýðý için name hiding oluyor 

					using namespace nec; 

					int main()
					{
						
						x = 45; // ambiguity hatasý globaldeki x zaten görünür olduðu için namespace nec direktifiyle ne namespace'i içindeki x ismi de
						global namespace'i içinde görünür oluyor
						::x = 45; // global namespaceteki x
						nec::x = 67; // nec namespace'i içerisindeki x
					}
	
	ÖRNEK:
		namespace nec{
			void foo();
			int ival{};
				
				struct A{
					static void bar();
				};
		}

		using namespace nec;

		void f1()
		{
			foo();
			++ival;
			A::bar();
		}

		void f2()
		{
			foo();
			++ival;
			A::bar();
		}

		bu örnekte hiç bir sentaks hatasý yok

		hoca using direktifini ya hiç kullanýlmýyorum yada dar kapsamda kullanýyorum diyor

		using namespace std; // global namespacete olduðu std namespace'i içindeki tüm isimler görünür olacaktý

		int main()
		{
			using namespace std; // sadece main içinde görünür

		}

	ÖRNEK:
		namespace nec{
			namespace erg{
				namespace pro{
					struct A{
						static void foo();
					};

					void bar();
				}
			}
		}

		void f()
		{
			using namesapce nec::erg::pro;

			A::foo();

			bar();
		}

	using direktifi comma seperator list ile kullanýlamýyor
		using namespace nec,erg,pro // sentaks hatasý
	
	ÖRNEK:
		namespace nec{
			int a;
			int b;
		}

		namespace erg{
			int a;
			int b;
		}

		using namespace nec;
		using namespace erg;

		int main()
		{
			a = 10 // ambigious

			nec::a = 10; // ok
			erg::a = 10; // ok

			b = 20; // ok
			c = 30; // ok
		}

	ÖRNEK:
		namepace nec{
			int a;
		}

		namespace erg{
			using namespace nec;

			int b;
		}
		
		using namespace erg;

		int main(){
			a = 10; // valid
		}

		using namespace erg direktifi ile erg isim alaný içerisindeki isimler global isim alanýnda görülür olur
		böylece isim alanýndaki using namespace nec direktifi de sanki global isim alanýndaymýþ gibi etkiye sahip olur
		bu etki de nec isim alaný içerisindekilerin global isim alanýna enjekte edilmesine yol açar

	ÖRNEK:
		namespace nec{
			int x = 10;
		}

		namespace erg{
			using namespace nec;

			int y = 20;
		}

		int main()
		{
			std::cout<< erg::x << '\n'; 
		}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ADL(ARGUMENT DEPENDENT LOOKUP) ARGÜMANA BAÐLI ÝSÝM ARAMA
	bir fonksiyon çaðrýsýnda fonksiyon ismi nitelenmeden kullanýldýðýnda fonksiyona gönderilen argümanlardan biri bir namespace içinde
	bildirilen türe iliþkinse fonksiyon ismi o namespace içinde de aranýr

	namespace nec{
		class Myclass{};

		void foo();
		void bar(int);
		void baz(Myclass);
	}


	int main()
	{
		nec::Myclass m;

		//foo(); // name lookup hatasý
		//bar(34) // name lookup hatasý
		
		baz(m); // foo ve bar nasýl sentaks hatasý oluyorda baz sentaks hatasý olmuyor? 
	
		fonksiyona gönderilen argüman nec namespace'i içerisinde bildirilen bir türe ilþkin bu yüzden isim arama
		nec namespace'i içindede yapýlýyor
	}

	ayný isimde ve parametreik yapýya sahip olan global bir baz fonksiyonu olsaydý
		void baz(nec::Myclass);

		int main()
		{
			baz(m) // sentaks hatasý olur global namespacete aranýr ama ADL gereði nec namespace'i içerisindede aranýr
		}


	SORU:burada çaðýrýlan bir fonksiyon var mý?
		std::cout<< "hello word"; global operator << fonksiyonu çaðýrýlýyor
		
		member function olsa böyle çaðýrýlacaktý
			std::cout.operator<<("hello world"); // burada çaðýrýlan fonksiyon parametresi void* olan fonksiyon
			hello world yazýsýnýn tutulduðu dizinin adresini yazdýrýyor

			operator<<(std::cout,"hello world"); // burada çaðýrýlan global operator fonksiyonu

			std::cout<<'A'; // burada çaðýrýlan fonksiyon global operator fonksiyonu
			std::cout<operator<<('A'); // burada çaðýrýlan fonksiyon int parametreli member fonksiyon

			peki burada nitelenmiþ isim kullanmamamýza raðmen nasýl sentaks hatasý olmuyot?
				operator<<(std::cout,hello); // çünkü fonksiyonun birinci parametresine gönderilen cout std namespace'i içerisinde bir sýnýfa iliþkin olduðu için
				isim arama std namespace'indede yapýlýyor

	POWER OF ADL
		std::vector<int< ivec {1,5,7,2,3,-5};

		//std::sort(std::begin(ivec),std::end(ivec));


		sort(begin(ivec),end(ivec)); // ortada her hangi bir using bildirimi yok ve bu isimlerin unqualified olarak kullanýlmasýna karþýn her hangi bir sentaks hatasýda yok 
		peki bu nasýl oluyor?

		begin fonksiyonuna gönderilen argüman olan ivec std namespace'i içerisindeki std::vector sýnýfýna iliþkin
		bu isimler nitelenmemiþ olmasýna raðmen std namespace'i içersinde aranmasýný saðlayan ADL

		SORU:sort ismide std nsmespace içerisinde peki nasýl oluyorda nitelenmemiþ olmasýna raðmen aranýp bulunuyor?
			begin ve end fonksiyonlarýnýn geri dönüþ deðerleri sayesinde -> std::vector<int>::iterator

		ÖRNEK:
			namespace nec{
				class Myclass{
					public:
						void foo();
				};
				
				bool is_equal(const Myclass&,const Myclass&);
			}

			int main()
			{
				nec::Myclass m1,m2;

				m1.foo(); // bu ifadeyi yazdýðýmýzda nasýl ilave bir niteleme yapmýyorsak
				is_equal(m1,m2); // bu fonksiyonu çaðýrdýðýmýz zamanda m1 ve m2 yi argüman olarak gönderdiðimizde namespace'i nitelememize gerek kalmýyor
			}

			1)bunlarýn geçerli olabilmesi için funciton call operatörünün kullanýlmasý gerekiyor
			2)function call operatörünü overload etmiþ sýnýf nesneleri için bu geçerli deðil

		ÖRNEK:
			namespace nec{
				class Duration{
					public:
						Duration(int hour,int min,int sec);
			};
				void print(const Duration&);
			}

			namespace erg{
				class Duration{
					public:
						Duration(double min);
			};
				void print(const Duration&);
			}

			int main()
			{
				nec::Duration x{2,12,51};
				erg::Duration y{3445,863};

				print(x);
				print(y);
			}

		MÜLAKAT SORUSU:
			int main()
			{
				std::cout<< endl; // burda neden sentaks hatasý oluyorda ADL devreye girmiyor?
				
				çünkü endl bir fonksiyon burada çaðýrýlan endl fonksiyonu deðil membwer operator<< fonksiyonu 
				
				endl(std::cout); // burda sentaks hatasý yok endl std namespeca'i içerisnide bir fonkaiyon ve gönderilen argüman std namespac'i içersinide bildirien
				ostream sýnýfý türünden bir nesne
			}

		ÖRNEK:
			namespace Enc{
				struct S{};

				void foo(S)
				{
					std::cout<<"Enc::foo(S)\n";
				}

				namespace Nested{
					void foo()
					{
						std::cout<<"Enc::Nested::foo()\n";
					}

					void func()
					{
						S ss;
						foo(ss);
					}
				}
			}
			
			int main()
			{
				Enc::Nested::func();
			}
			
			ÇIKTI:
			Enc::foo(S)

		ÖRNEK:
			namespace A{
				class B{};

				void func(std::vector<B>
				{
					std::cout<<"A::func(std::vector<A::B>\n";
				}
			}

			int main()
			{
				std::vector<A::B> x;

				func(x);
			}
		
		ÖRNEK:
			namespace nec{
				struct X{};

				void func(X) { std::cout<<"Nec::func(X)\n";}
			}

			class Myclass{
				public:
					void func(nec::X) { std::cout<<"Myclass::func(nec::X)\n"; }

					void foo()
					{
						nec::X ax;
						func(ax) // no ADL

						Myclass sýnýfýnýn func fonksiyonu olmaysadý ADL devreye girecekti
					}
			};

			int main()
			{
				Myclass mx;

				mx.foo();
			}

			ÇIKTI:
			Myclass::func(nec::X)

		ÖRNEK:
			namespace nec{
				class NA{

				};

				void foo(int);
				void bar(NA);
			}

			namespace erg{
				using EB = nec::NA;
				void func(EB);
			}

			int main()
			{
				erg::EB b;
				func(b) // invalid there is no func in nec (çünkü b nesnesi nec namespace'i içerisinde ki bir nesneye iliþkin isim arama orada yapýlýyor)
				bar(b); // valid bar found in nec
			}


	bir namespace içerisinde bildirilen bir fonksiyonu o namespace içerisinde yada onu içine alan enclosing namespace içerisinde tanýmlayabiliyoruz
		namespace nec{
			namespace erg{
				int foo(int);
			}
		}

		int nec::erg::foo(int x){
			return x * x;
		}

	UNNAMED NAMESPACE
		önemli bir sentaks özelliðidir derleyici unnamed namespace oluþturduðumuzda derleyici þöyle bir kod oluþturuyor
			
			namespace xyz_98{
				int x;
			}
			 
			using namespace xyz_98; // derleyici namespace'in çýkýþýnda sanki böyle bir taným yapýyormuþ gibi böylelikle onu kapsayan namespace içerisinde
			doðrudan görülür hale geliyor xyz_98 global namespace alanýnda bildirildiði için tüm kaynak dosyada görünür durumda 

			int main()
			{
				x = 10;
				::x = 5; 
			}

			unnamed namespace kullanýlmasýnýn temel amacý sadece bir kaynak dosyaya iliþkin isimlerin diðer kaynak dosyalardan gizlenmesini saðlamak
				ali cpp
					namespace { 
						int x;
					}
				veli cpp
					namespace {
						int y;
					}

				bu namespaceler içerisindeki isimler global olarak doðrudan kullanýlabilir ama diðer modüllerden bunlarýn kullanýlma ihtimali olmayacak
				bu sayede static globallere bir alternatif olarak kullanýlabilir ama tamamen bunlara olan ihtiyacý sýfýra indiriyor diyemeyiz

			unnamed naemspacelerde kümülatiftir 
				namespace {
					int x;
					void foo();
				}

				namespace {
					int y;

					class Nec{

					};
				}
	
			nested namespacelerde kümülatiftif
				namespace ali{
					namespace can{
						int x = 5;
					}
				}

				namespace ali{
					namepace can{
						int y = 15;
					}
				}

				int main()
				{
					ali::can::x = 6;
					ali::can::y = 12;
				}

			ÖRNEK:
				namespace {
					int x = 5;
				}

				int x = 34;

				int main()
				{
					std::cout << ::x << '\n'; // valid x = 34
					std::cout << x << '\n'; // error ambiguous
				}

	namespacelerde overloading
		void foo(int)
		{
			std::cout<<"::foo(int)\n";
		}

		namespace nec{
			void foo(double)
			{
				std::cout<<"nec::foo(double)\n";
			}
		}
		
		using namespace nec; // using namespace direktifi ile nec namespace'i içerisindeki isimler global namespace alanýnda görünür olur ve böylelikle overload set oluþturuluyor 

		int main()
		{
			foo(1.2) // double parametreli fonksiyon çaðýrýlýr
		}

		ÖRNEK:
			namespace nec{
				void func(int)
				{
					std::cout<<"void nec::func(int)\n";
				}

				void func(double)
				{
					std::cout<<"void nec::func(double)\n";

				}
			}

			int func()
			{
				std::cout<<"int func()\n";

				return 1;
			}

			int main()
			{
				using nec::func;

				func(); // nec'in func ismi bu alana enjekte edildiði için geçersiz
				func(12);
				func(2.5);
				::func();
			}

		ÖRNEK:
			namespace nec
			{
				void foo(int nec) { std::cout<< "nec::foo(int)<<'\n';} 
			}

			namespace erg
			{
				using namespace nec;

				void foo(long nec) { std:cout<<"erg::foo(long)" << '\n';}
			}

			void foo(double nec){ std::cout<<"::foo(double)" << '\n';}

			using namespace erg;

			int main()
			{
				foo(10); // nec::foo
				foo(10L); // erg::foo
				foo(3.14); // ::foo
			}


	INLINE NAMESPACE
		inline anahtar sözcüðüyle bir namespace oluþturduðumuz zaman onun içindeki isimler onu kapsayan namespace içinde görülür hale geliyor

		namespace nec{
			namespace erg{
				
				inline namespace asl{
					int x;
				}
			}
		}
		
		int main()
		{
			nec::erg::x; // inline olduðu için bu þekilde eriþebiliyoruz
			erg te inline olsaydý nec::x þeklinde eriþebilecektik hatta nec inline olsaydý direkt x ismi ile eriþebilecektik
		}


		bunun dile eklenmesindeki 2 temel amaç var
			1)ADL
				using direktiflerinin kullanýldýðý yapýda ADL'in devreye girmediði ama inline namespace kullanýldýðýnda ADL'in devreye girdiði senaryolar var
			2)versiyon kontrolü
				namespace nec{
					inline namespace version_1{
						struct A{
							A() { std::cout<<"nec::version_1::A()\n"; } 
						}
					}

					namespace version_2{
						struct A{
							A() { std::cout<<"nec::version_2::A()\n"; }
						}
					}
				}

				int main()
				{
					nec::A ax; // þeklinde çaðýrýyoruz inline anahtar sözcüðü version_2 namespace'inde yazýlmýþ olsaydý bu sefer version_2 namespace'i içerisindeki ctor çaðýrýlacaktý
					
					inline olmasaydý seçimi kodda kendimizin yapmasý gerekirdi
					nec::version_1::A ax;
					nec::version_2::A ax; // böyle çaðýrmamýz gerekirdi
				}

		C++20 ile nested namespacelerde inline olarak tanýmlanabiliyor
			namespace ali::veli:: inline gul{
				int x = 5;
			}

	NAMESPACE ALIAS
		namespace nec{
			
		}

		namespace erg = nec; // namespace alias erg namespace'ini nec namespace'i gibi kullanabiliyoruz erg demek nec demek 

		int main()
		{
			nec::x = 13;
			erg::x = 35;
		}

		namesapce alias kullanmanýn en az 2 ihtiyaç noktasý olabilir
			1)isim çakýþmasý
				namespace isminin kendiside çakýþmaya sebep olabilir 

			2)yazým kolaylýðý saðlamasý
				namespace nec_proj_ai{
					namespace random{

						namespace details{
							int x = 10;
						}
					}
				}

				int main()
				{
					namespace details = nec_proj_ai::random::details;

				}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------					
NESTED TYPES
	class definition içinde bir türün bildirimini yaparsak o bir nested type/member type/type member 

	1)baþka bir sýnýf olmasý(structlarda dahil)
		class Myclass{
			
			class Nested{};

		};

	2)enumaration type olmasý(union dahil)
		class Myclass{
			
			enum class color { black,red,blue};

		};

	3)type alias
		class Myclass{
			using Word = int;
		}
*/