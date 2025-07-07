/*

template parametre paketi
	1)type parameter pack
	2)non-type parameter pack
	3)template template parameter pack olabilir

	template parametre paketinin olmasý class template variable template yada function template olmasý ile ilgili deðil 

	fonksiyon þablonu olduðunda eðer template parametre paketinden sonra ellipsis tokeni gelirse buda fonksiyonun parametre paketi 
	template parametre paketi baþka fonksiyon parametre paketi baþka birbiriyle iliþkili ama olmak zorunda da deðil
		
		template <typename ...Ts>
		void func(Ts ...args)
		{

		}

		int main()
		{
			func(1,4,7,2.3); // derleyicinin oluþturduðu instantiation aslýnda þöyle -> void func(int p1,int p2,int p3,double p4) {}
		}

	SORU: birden fazla template parametre paketi olabilir mi? OLABÝLÝR ama belirli templatelerde olamaz  
				template <typename ...A, typename ...B> // hata class templateler'de geçerli deðil
				struct Myclass {}

		ama function templatelerde esneklik var parametre paketi ne bir tane olmak zorunda ne de en sonda olmak zorunda
		
			template <typename ...X, typename ...Y>
			void foo(X ...xargs, int, int, Y ...yargs) // geçerli
			{
				std::cout << "sizeof...X() = " << sizeof...(X) << '\n';
				std::cout << "sizeof...Y() = " << sizeof...(Y) << '\n';

			}

			int main()
			{
				foo<int, double, int>(1, 2.5, 3, 5, 5, 6, 7, 8, 9); // ilk 3 parametre X parametre paketine gidecek 5 ve 5 int int parametresine gidecek diðer geri kalanlar ise
																	   Y parametre paketine gidecek
			}

			ÇIKTI:
				sizeof...X() = 3
				sizeof...Y() = 4

			function templatelerde variadic parametre paketi söz konusu olduðunda standart 2 ye ayrýyor
				1)trailing(en son parametre paketi olmasý)
				2)non-trailing(en son parametre paketi olmamasý)
				
				template <typename ...X, typename ...Y>
				void foo(X ...xargs, int, int, Y ...yargs) // geçerli
				{
					std::cout << "sizeof...X() = " << sizeof...(X) << '\n';
					std::cout << "sizeof...Y() = " << sizeof...(Y) << '\n';
				}

				int main()
				{
					
					foo(1, 2.5, 3, 5, 5, 6, 7, 8, 9); // fonksiyonu çaðýrdýðýmýzda explicit argüman kullanmazsak 1.parametre paketi boþ kabul ediliyor bu durumda argümanlar ondan 
														 sonraki öðelere daðýtýlýyor
				}	

				ÇIKTI:
					sizeof...X() = 0
					sizeof...Y() = 7

	visual studio derleyicisinde __FUNCSIG__ makrosu fonksiyonun geri dönüþ deðeri dahil parametrelerinede iþaret eden bir yazýya açýlýyor

	derleyicinin oluþturduðu instantiation'ýn nasýl bir fonksiyon olduðunu görebiliyoruz

		template <typename T , typename ...Ts>
		void foo(T x, Ts ...yargs) 
		{
			std::cout << __FUNCSIG__ << '\n';

		}

		int main()
		{
			foo(12, 4 , 'A',3.4); // void __cdecl foo<int,int,char,double>(int,int,char,double)
		}

PACK EXPANSION(paketin geniþletilmesi
	
	derleyici ilgili context'de belirli örüntülere uygun olarak virgüllerle ayrýlan bir listeye dönüþtürüyor 
	
	PACK EXPANSION'I template parametre paketi içinde ve foknsiyon parametre paketi içinde kullanabiliriz 
	
		template<typename ...Ts>
		void foo(Ts ...args)
		{
			Ts...  // eðer template parametre paketinin isminden sonra ellipsis tokeni'ni kullanýrsak derleyici bunu paketteki türlerin isimlerini içeren virgülerle 
					  ayrýlan bir listeye çeviriyor
		}	

		ÖRNEK:

			template<typename ...Ts>
			void foo(Ts ...args)
			{
				std::tuple<Ts...> x; // template parametre paketi expand edildiðinde parametre paketinde ki türler yada deðerlerden oluþan comma separated list'e dönüþüyor
			}
			
		DÝKKAT:eðer parametre paketi fonksiyon parametre paketi pack expansion'a tabi tutulursa buda derleyici tarafýndan yine virgülle ayrýlýyor ama
				örneðin fonksiyon parametre paketinde 3 tane parametre varsa T1 türünden -> p1 , T2 türünden -> p2 , T3 türünden -> ,p3 çýkarým yapýlýyor
				template parametre paketini expand edersek aslýnda bu þuna dönüþüyor -> T1 ,T2 ,T3 listesine dönüþtürülecek 
				fonksiyon parametre paketini expand edersek -> p1, p2, p3 listesine dönüþtürülüyor
				virgüllerle ayrýlan liste kullanýlan bir çok context'de parametre paketinin expand edilmiþ halini kullanabiliyoruz
			
				ÖRNEK:
					template<typename ...Ts>
					void foo(Ts ...args)
					{	
						bar(args...); // bar fonksiyonu fonksiyonun parametre deðiþkenlerinin deðerlerini gönderir yani -> p1,p2,p3 
					}

					pack expansion daha uzun bir örüntüde olabilirdi

						template<typename ...Ts>
						void foo(Ts ...args)
						{	
							bar(&args...); // derleyici bunu bar(&p1,&p2,&p3); listesine dönüþtürücek
						}

				ÖRNEK:

					template<typename ...Ts>
					void baz(Ts ...args)
					{
						bar(baz(args)...); // burda expansion -> bar(baz(p1), baz(p2,) , baz(p3))
					}

	ÖRNEK:
		
		template <typename ...Ts>
		void print(Ts ...args)
		{
			((std::cout << args << ' '), ...);
			std::cout << '\n';
		}

		template <typename T>
		auto g(T* x) { return *x * *x + 10; }

		template <typename ...Ts>
		void f(Ts ...args)
		{
			//print(args...); // p1 , p2, p3 -> 1 2 3
			//print(&args...); // &p1 , &p2 , &p3 -> 0x7ffd733d40bc 0x7ffd733d40b8 0x7ffd733d40b4
			//print(10 * args...); // 10 * p1, 10 * p2, 10 * p3 -> 10 20 30
			//print(args * args...); // p1 * p1 , p2 * p2, p3 * p3 -> 1 4 9
			//print(g(&args)...); // g(&p1) , g(&p2) , g(&p3) -> 11 14 19
			//print(++args...); // ++p1 , ++p2 ++p3 -> 2 3 4

		}

		int main()
		{
			int x{ 1 }, y{ 2 }, z{ 3 };
			f(x, y ,z);
		}

	ÖRNEK:
		1)fonksiyonun parametre paketinde referans dekleratörü olursa fonksiyonun bütün parametreleri L value reference olacaktý
			template <typename ...Ts>
			void f(Ts &...args) {}
			
		2)fonksiyonun parametre paketinde const ve referans dekleratörü olursa fonksiyonun bütün parametreleri const L value reference olacaktý
			template <typename ...Ts>
			void f(const Ts &...args) {}

		3)fonksiyonun parametre paketi universal reference olursa örneðin parametre paketinden 2 tane template parametresi varsa 2 tane universal reference parametre olacaktý
			template <typename ...Ts>
			void f(Ts &&...args) {}

	ÖRNEK:

		template <typename... Us>
		void f(Us... pargs{}
		
		template<typename... Ts>
		void g(Ts... args) {
			
			f(&args...); // &args... is a pack expansion 

		}

		int main()
		{
			g(1,0.2,"a"); // Ts... args expand int E1, double E2 ,const char* E3

			// &args expand to &E1,&E2,&E3

			Us... pargs expand to int* E1,double* E2,const char** E3
		}

	ÖRNEK:

		template <typename T,typename ...Args>
		std::unique_ptr<T> MakeUnique(Args&& ...args)
		{
			new T(args...) // fonksiyonun parametre deðiþkenlerini göndermiþ olurduk
			new T(f(args)...) // ismi F olan bir fonksiyona argümanlarý gönderip onlarýn virgüllerle oluþturduðu listeyi T sýnýfýnýn ctoruna argüman olarak göndermiþ olurduk
			
			return std::unique_ptr<T>(new T(std::forward<Args>(args)...)) // burda MANDATORY COPY ELISION GERÇEKLEÞÝYOR ve parametre paketinde örneðin 3 argüman varsa 3 kez forward'a 
																			 çaðrý yapýlacak								
		}

	ÖRNEK:

		template<typename ...TS>
		class Var{};

		template <typename ...Types>
		class Myclass : public Var<Types...>{
			public:
				constexpr static size_t size = sizeof...(Types);
		};

		int main()
		{
			constexpr auto n = Myclass<int,double>::size;
			static_assert(std::is_base_of_v<Var<int,double>,Myclass<int,double>>);	
		}

	ÖRNEK:
			
		 template <typename... Types, int... N>
		 void func(Types(&...args)[N])
		 {
			std::cout<< __FUNCSIG__ << '\n';
		 }

		 int main()
		 {
			int a[2]{};
			int b[3]{};
			int c[5]{};
			double d[7]{};

			func(a,b,c,d); // func<int[2],int[3],int[5],double[7]>(int(&)[2],int(&)[3],int(&)[5],double(&)[7])
		 }

	variadic parametre paketine sahip fonksiyon þablonlarý dilediðimiz sayýda argümanla çaðýrma olanaðý veriyor ama bu olanaktan nasýl istifade ediyoruz?

		template <typename ...Ts>
		void print(const Ts&... args) 
		{
			 örneðin bu fonksiyonun tüm gelen argümanlarý yazdýrmak olsaydý fonksiyonun parametrelerinin her birine eriþmemiz gerekirdi bunu nasýl yapacaðýz?
			
				1)COMPILE TIME RECURSIVE PACK EXPANSION
					
				ÖRNEK:
					template<typename T>
					void print(const T& r) { std::cout<< r << '\n'; }

					template <typename T, typename ...Ts>
					void print(const T& r,const Ts& ...args)
					{
						std::cout<< __FUNCSIG__ << '\n';
						print(r);
						print(args...);
					}

					int main()
					{
						int x = 10;
						double d = 23.5;
						print(x,d,9L,"necati"); // x fonksiyonun 1.parametresine gidecek geri kalan argümanlar fonksiyonun parametre paketi olan ...args'a gidecek
												   print(r) çaðrýsý ilk argümaný yazdýracak print(args...) pack expansion'ý geriye kalan 3 argümaný yazdýracak			
												   pakette ne zaman 1 argüman kalýrsa onuda en son çaðýrýlan print fonksiyonu yazdýrýcak yani argümanlar
												   azalmaya baþladýðý zaman geriye en son 1 parametre kalmýþ olacak ve en son üstte ki print fonksiyonunu çaðýrmýþ olucaz 
					}

				ÖRNEK:
					
					template<typename T>
					std::ostream& print(std::ostream& os,const T& t) { return os << t; } 
					
					template<typename T,typename... Args>
					std::ostream& print(std::ostream& os, const T& t,const Args& ...rest)
					{
						os << t << ", ";
						return print(os,rest...);
					}

					int main()
					{
						print(std::cout,45,"ali",3.87,'A');
					}

				ÖRNEK:

					template<typename T>
					T max(const T&,const T& b) 
					{
						return a > b ? a : b;
					}

					template <typename T,typename ...Args>
					T max(const T& a,const Args&... args)
					{
						return max(a,(max(args...));
					}

					int main()
					{
						std::cout<< max(2,4,1) << '\n';
						std::cout<< max(4.2,2.6.5.1,8.2 ) << '\n';
					}

				2)INITIALIZER LIST

					template <typename ...Ts>
					void print(const Ts& ...args)
					{
						(void)std::initalizer_list{ std::cout << args << " " , 0)... }; // burda virgül operatörünün sequence point oluþturmasý ve virgül operatörünün ürettiði 
																						   deðerin sað operandýn deðeri olmasý
					}

					int main()
					{
						print(2, 2.3, "alihan", std::bitset<16>{453u});
					}

				3)FOLD EXPRESSION(katlama ifadeleri C++17 ile geldi)

					variadic parametre paketleriyle ilgili yani ortada parametre paketi yoksa ve variadic her hangi bir template yoksa fold ifadesinin kullanýlmasý mümkün deðil 
					FOLD EXPRESSION parametre paketinin önceden belirlenmiþ bir þekilde expand edilmesini saðlýyor 

					fold iþlemi bir operatör üstünde yapýlmak zorunda
					
					dil 2 kategoriye ayýrýyor

						1)unary fold expressions
							a)unary right fold
							b)unary left fold

						2)binary fold expressions
							a)binary right fold
							b)binary left fold

					ÖRNEK:

						template <typename ...Ts>
						auto sum(Ts ...args)
						{
							return (... + args) // ellipsis tokeni binary operatörün solundaysa buna unary left fold deniliyor
						}

						SORU: derleyici burda nasýl bir kod üretecek bu ifade bütün argümanlarýn toplamý anlamýna gelecek -> ((p1 + p2) + p3) + p4 left fold olduðu için soldan 
							  parantez içine alýndý

					ÖRNEK:right fold olsaydý derleyici nasýl bir kod üretirdi
						
						template <typename ...Ts>
						auto sum(Ts ...args)
						{
							return (args + ...); -> örneðin 5 tane parametre deðeri varsa derleyici bunu þuna dönüþtürecek return (p1 + p2 + p3 + (p4 + p5)) // right fold olduðu için 
																																								parantez saðdan
						}
					DÝKKAT:left fold ve right fold birbirinden farklý sonuçlar üretebilir
						template <typename ...Ts>
						auto sum(Ts ...args)
						{
							// return (... + args)
							return (args + ...); 
																																								
						}

						int main()
						{
							std::string name{"samet"};

							std::cout<<"sum(name,"sen","gel") << '\n'; // right fold'da hata verir çünkü iki adresi toplayamayýz(const char* + const char*) 
																		  ama string ile const char* toplanabilir
						}

					ÖRNEK:

						template <typename ...Ts>
						auto div(Ts ...args)
						{
							// return(args / ...);
							 return(... / args);
						}

						int main()
						{
							std::cout<<div(500,50,5,2); // left fold olduðunda 1 sonucunu üretir
														   right fold olduðunda 20 sonucunu üretir
						}

					ÖRNEK:

						template <int ...N>
						constexpr int Sum = (... + N);

						int main()
						{
							Sum<2,5,7,9>
						}
						
				4)CONSTEXPR IF & compile time recursive
					
					derleyicinin bir kodu görmesini yada görmemesini saðlayacak derleme zamanýnda ele alýnýyor amaç if'in kontrol ifadesi bir constant expression olacak
					eðer o constant exxpression compile time'da true deðer üretirse if'in doðru kýsmýndaki kodu derleyecek false ise o kýsýmdaki kodu derleyecek
					normal fonksiyonlar içinde static if'i kullanabiliriz ama orda kurallar daha farklý oluyor

					template <typename T>
					void func(T)
					{
						if constexpr(sizeof(T) > 2)
						{
							std::cout<<"compiled code is true path\n";
						}
						else
						{
							std::cout<<"compiled code is false path\n";
						}
					}

					int main()
					{
						short s = 34;

						func(s); // false
						func(45); // true
					}	

					1)bu ifadenin sabit ifade olma mecburiyeti var 
						template <typename T>
						void func(T x)
						{
							if constexpr(x > 2) // gibi bir ifade yazamayýz
							{
								std::cout<<"compiled code is true path\n";
							}
							else
							{
								std::cout<<"compiled code is false path\n";
							}
						}	

					2)derleyicinin derlemedeði kýsýmdaki kod sentaks hatasý oluþturmuyor
						
						namelookup ile ilgili bir problem olmadýðý sürece o kod derlenmiyor 
						
						struct Nec{
							void foo(){};
						};

						template <typename T>
						void func(T x)
						{
							if constexpr(!std::is_integral_v<T>) // bu ifadenin doðru olmasý için T türünün tam sayý türlerinden olmamasý gerekiyor
							{
								x.foo(); 
							}
							else
							{
								std::cout<<"compiled code is false path\n";
							}
						}	

						int main()
						{
							func(12); // T türü int olacak else kýsmý çalýþacak eðer if constexpr kýsmýný derleseydi int türden deðiþkeni nokta operatörünün operandý yapmýþ olacaktýk
										 buda sentaks hatasý oluþturacaktý ama derleyici o kodu derlemedeði için sentaks hatasý oluþmayacak
						}

					DÝKKAT: else if yazarken constexpr yazmayý unutmamalýyýz yazmazsak run time'a iliþkin olur
							if constexpr(!std::is_integral_v<T>)
							{
								x.foo();
							}
							else if constexpr(std::is_floating_point_v<T>){}

					ÖRNEK:
						
						template <typename T>
						std::string as_string(T x)
						{
							if constexpr (std::is_same_v<T, std::string>)
							{
								return x;
							}
							else if constexpr (std::is_arithmetic_v<T>)
							{
								return std::to_string(x);
							}
							else
							{
								return std::string(x);
							}
						}

						int main()
						{
							std::cout << as_string(42) << '\n';
							std::cout << as_string(4.2) << '\n';
							std::cout << as_string(std::string("hello")) << '\n';
							std::cout << as_string("hello") << '\n';
						}

					ÖRNEK:
						
						template <typename T>
						void func(T tx)
						{
							if constexpr(std::is_integral_v<T>)
							{
								if(tx !=0)
								{
									func(tx--);
								}
							}
							else
							{
								// undeclared_f(); // sytanx error name non dependent on template parameter
								// undeclared_f(); // error if else part instantiated
								
							}
						}

					DÝKKAT: if constexpr fonksiyon þablonu deðilse true kýsmýda false kýsmýda compile time'da hata oluþturmayacak kodlardan oluþmalý
						
					ÖRNEK:
					
						template <typename T>
						auto get_value(T x)
						{
							if constexpr (std::is_pointer_v<T>)
								return *x;
							else
								return x;
						}

						int main()
						{
							int i = 56;
							std::string s{ "necati ergin" };
							auto* p = &s;

							std::cout << get_value(i) << '\n';
							std::cout << get_value(p) << '\n';
						}

					ÖRNEK:

						template <typename T>
						std::string tostr(T t) { return std::to_string(t); }
						std::string tostr(const std::string& s) { return s; }
						std::string tostr(const char* cstr) { return cstr; }
						std::string tostr(bool) { return b ? "true" : "false"; }

						int main()
						{
							std::cout<<"tostr("necati")<<'\n';
							std::cout<<"tostr(std::string{"ergin})<<'\n';
							std::cout<<"tostr(13)<<'\n';
							std::cout<<"tostr(5.9)<<'\n';
							std::cout<<"tostr(true)<<'\n';
						}
						
						üstte bulunan overloadingler yerine derleyicinin compile time'da kod seçmesini saðlayalým

							template <typename T>
							std::string tostr(T t)
							{
								if constexpr(std::is_convertible_v<T,std::string>)
									return t;
								else if constexpr(std::is_same_v<T,bool>)
									return t ? "true" : "false"
								else
									return std::to_string(t);
							}

	STATIC_ASSERT DECLERATION

		1)bildirimi global olarak yapabiliriz
		2)local düzeyde yapabiliriz
		3)sýnýf içinde yapabiliriz
		
		ortada template olsada olmasada kullanabiliriz yani generic kodlarla kullanýlmak zorunda deðil ama template kodlalrla kullanýmý çok daha yaygýn

		static_assert(constant expression, string literal); // derleyici compile time'da static assert'e gönderilen sabit ifadenin compile time'da true yada false olduðunu sýnýyor
															   true ise sentaks hatasý oluþmuyor ama false ise sentaks hatasý oluþuyor ve hatayý verirken derleyici 2.parametre olan 
															   string literali'ni hata mesajý olarak gösteriyor(C++ 17'ye kadar string literali argümanýný girmek zorunluydu ama sonra kalktý)

		ÖRNEK:

			static_assert(sizeof(int) > 4,"sizeof int must be greater than 2"); // compile time'da yanlýþ olduðu için derleyici sentaks hatasý verir 

		ÖRNEK: concept'ler dile eklenmeden önce templateleri kýsýtýlamak için farklý farklý araçlar kullanýlýyordu bu araçlardan biride static_assert
				
			template <typename T>
			class Myclass {

				static_assert(std::is_integral_v<T>);
			};

			int main()
			{
				Myclass<int> x;
				Myclass<double> x; // static_assertion'a takýlýr ve hata verir
			}

		ÖRNEK:

			template <typename T>
			class Myclass{
				static_assert(std::is_default_constructible_v<T>);
			};

			struct Nec{
				Nec(int); 
			};

			int main()
			{
				Myclass<Nec> x; // Nec sýnýfýnýn default ctor'u olmadýðý için sentaks hatasý oluþtu
			}
*/