/*

function overloadingte kaldık 2 tane ayrı soru var
	1)function overloading var mı yok mu
	2)function overload resolution
		aynı isimli fonksiyonlara yapılan çağrının derleycinin hangi fonksiyonun çağrıldığını anlaması süreci

	sorular:
	1) re-decleration
		void foo(int p[]);
		void foo(int* p); 

	2) 1 tane overload var
		void foo(int p[7]);
		void foo(int p[8]);
		void foo(int p[9]);
		void foo(int* p);

	3) 3 tane function overload var hepsi farklı tür referans semantiği ilede olsa yine 3 overload olacaktı
		void foo(int(*)[10]);
		void foo(int(*)[12]);
		void foo(int(*)[16]);

	4) re-decleration burdada decay söz konusu
		void foo(int(int)); // function type
		void foo(int(*)(int)); // function pointer type

	5) 4 tane overload var
		void foo(int); // call by value
		void foo(int*);
		void foo(int&); // call by reference
		void foo(int&&);
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	const overloading
		overloadlardan biri T* ise void foo(T*)
		diğeri low level const T* void foo(const T*) ise bu kesinlikle function overloading 
		referans semantiği ile yapılması daha çok karşımıza çıkacak
		void foo(T&)
		void foo(const T&)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
function overload resolution
	hoca sezgiyle davranmak arasında konuyu bilmemiz arasında ki yere dikkat çekiyor
		void foo(long double);
		void foo(char);

		int main()
		{
			foo(4.5); // ambigious sentaks hatası verir çünkü derleyici burda hangisini çağırması gerektiğine karar veremiyor 
			foo: ambigious call to overloaded function
		}
	
	eğer ortada function overlaoding varsa derleyici bu fonksiyonlardan hangisinin çağırıldığını anlamak için function overload resolution sürecini yürütüyor
	bu süreç 
	
	a)sentaks hatasıyla sonuçlanabilir
		iki ayrı nedenle sentaks hatası olabilir
			
			1)n tane overlaod olmasına karşın overloadlardan hiç biri fonksiyon çağrısıyla uyumlu değildir yani function overlaoding var ama uygun fonksiyon yok
			
			2)ambiguity(hoca çift anlamlılık hatası diyor)
				2 yada daha fazla overload arasında dilin kuralları bunlardan birinin seçilmesini sağlayacak bir kriter sunmuyor buda çağırılabilir buda çağırılabilir 
				yani birbilerine üstünlüğü yok böyle durumda hata vericek ama verdiği hata nedeni çağrılabilecek fonksiyonun olmaması değil 2 yada daha fazla fonksiyon olması fakat
				bunların arasında dilin kurallarınca birinin seçilmesini sağlayacak bir kriterin bulunmayışı
	
	b)sentaks hatası olmaz
		eğer sentaks hatası yoksa derleyici dilin kurallarına göre hangi fonksiyonun çağırıldğını anlamış ve fonksiyon çağrısına o fonksiyonu bağlamış olacak

	function overlaod resolution kuralları
		derleyici function overlaod resolutionu kademe kademe yürütüyor 
			1)derleyici fonksiyonun çağırıldığı noktada aynı isimli olan ve aynı scopeta visible olan fonksiyonların bir listesini çıkartıyor listesini çıkartırken
			kaç tane overload var onları tespit ediyor buna function overload set diyebiliriz
				enum Color {Blue,Black,Red};

				void foo(Color);
				void foo(int);
				void foo(int,int);
				void foo(double);
				void foo(double,double);
				void foo(int*);

				int main()
				{
					foo(12); // çağırılmaya 6 tane aday fonksiyon var
				}
				1.aşama(function overlaod set aday fonksiyonların belirlenmesi)
					derleyici function overload set'i oluşturucak bu seti oluştururken fonksiyon çağrısında kullanılan argümanların hiç bir şekilde konuyla alakası yok
					bu aşama bittiğinde derleyici artık 6 tane overload olduğunu biliyor bu aşamadan geçen fonksiyonlara CANDIDATE FUNCTIONS deniyor(aday fonksiyonlar) 
					6 tane aday fonksiyon var demek bu eğer bu aşamada zaten candidate functions yoksa zaten isim aramada hata olacak demek
				
				2.aşama(viable functions)
					2 yada daha fazla candidate functions varsa derleyici fonksiyon çağırısında kullanılan argüman yada argümanlarla dilin kurallarına göre legal olarak çağırılabilen
					fonksiyonları ayıracak burdan ayrılan fonksiyonlara VIABLE FUNCTIONS deniyor bir fonksiyonun viable olması için fonksiyon çağrısında ki argüman yada
					argümanlardan ilgili parametre değişkeni yada değişkenlerine geçerli dönüşümün olması gerekiyor eğer bu aşamada 1 tane bile viable fonksiyon olmasaydı
					sentaks hatası olur 1 tane viable fonksiyon varsa zaten function overlaod resolution süreci bitecek başka fonksiyonun çağırılma ihtimali yok
						
				fonksiyon nasıl viable olur
					1)fonksiyon çağrısındaki kullanılan argüman sayısıyla ilgili fonksiyonun parametre sayısı aynı olması gerekir default aegument'da dikkate alınıyor burda
					2)dilin kurallarına göre argüman olan ifadenin türünden fonksiyonun parametre değişkenine örtülü dönüşümü gerçekleşebilecek veri kaybı olması önemli değil
					önemli olan böyle bir dönüşüm var mı

					sadece void foo(Color); fonksiyonu olsaydı ve foo yu foo(12) olarak çağırsaydık dilin kurallarına göre int türünden numaralarında türlerine dönüşüm olmadığı için
					sentaks hatası olacaktı
				
				foo(12) böyle bir çağrıda 
					void foo(Color); // tek olursa viable değil
					void foo(int); // tek olursa viable
					void foo(int,int); // tek olursa viable değil
					void foo(double); // tek olursa viable int türünden double türüne örtülü dönüşüm var
					void foo(double,double); // tek olursa viable değil
					void foo(int*); // tek olursa viable değil çünkü int türünden int* türüne dönüşüm yok

				3.aşama viable function sayısının 2 yada daha fazla olması durumunda oluşan durumlar
					derleyici ya viable olan fonksiyon içinde most viable ,best viable ,best match üçüde aynı anlama geliyor fonksiyonlardan en uygun olanının seçilmesi(best match)
					ya da 2 yada daha fazla sayıda fonksiyon arasında ambiguty olucak 

					argümanlardan parametere değişkenlerine yapılan dönüşümlerin belirli dönüşüm kaliteleri var 2 yada daha fazla candidate fonksiyon arasında böyle bir durum varsa
					en iyi olanı seçiliyor

						void func(...); // 2 yada daha fazla uygun aday fonksiyon varsa en düşük önceliktedir yani variadic conversion en kötü dönüşümdür
						
				user defined conversion	
					implicit conversion'ın C++ ta olan C dilinde olmayan ilginç bir biçimi var
						c++ dilinde standart olarak geçerli olmayan(dilin kurallarında mevcut bulunmayan) dönüşümler bir fonksiyonun bildirilmesi durumunda legal oluyorsa ve
						derleyici bizim bildirdiğimiz fonksiyona çağrı yaparak tür dönüşümü sağlıyorsa buna USER DEFINED CONVERSION deniyor 
							struct Nec
							{
								int x{};
								Nec();
								Nec(int);
							};
							int main()
							{
								Nec mynec;
								mynec = 5; // dönüşümü sağlayan Nec(int) çünkü int türünden struct türüne dönüşüm yok
							}

							struct Nec
							{
								double dval{};
								operator int() const;
							};
							int main()
							{
								Nec mynec;
								int x = mynec; // dönüşümü sağlayan operator overloading sayesinde operator int() const çünkü struct türünden int türüne dönüşüm yok
							}							
				
				iyiden kötüye doğru conversion sırası
					standart conversion(Her standart conversion bir implicit conversion ancak her implicit conversion bir standard conversion değildir)
						user-defined conversion
							variadic conversion
				
				variadic conversion yada user defined conversion değilse bu standart conversiondur

				long double -> char türüne dönüşüm var
				enum		-> int türüne dönüşüm var
				int*		-> void* türüne dönüşüm var
				int*		-> bool türüne dönüşüm var
				
				implicit conversion örnekler

| **Kategori**                     | **Örnek Dönüşümler**                               | **Açıklama** |
|----------------------------------|-------------------------------------------------|-------------|
| **1. Integer Promotions**        | `bool → int`, `char → int`, `short → int`      | Küçük tamsayı türleri en az `int` seviyesine yükseltilir. |

| **2. Floating-Point Promotions** | `float → double`                               | `float`, `double` seviyesine yükseltilir. |

| **3. Integer Conversions**       | `int → long`, `unsigned int → long`           | Tamsayı türleri arasında dönüşüm. Veri kaybı olabilir. |

| **4. Floating-Point Conversions**| `double → float`, `long double → double`      | Kayan nokta türleri arasında dönüşüm. Hassasiyet kaybı olabilir. |

| **5. Floating-Integral Conversions** | `int → float`, `float → int`             | Tamsayı ve kayan nokta türleri arasında dönüşüm. `float → int` dönüşümünde ondalık kısım kaybolur. |

| **6. Pointer Conversions**       | `T* → void*`, `nullptr → herhangi bir pointer` | `void*`, herhangi bir işaretçiyi saklayabilir. `nullptr`, her pointer türüne dönüşebilir. |

| **7. Boolean Conversions**       | `int → bool`, `double → bool`, `T* → bool`    | `0` veya `nullptr` → `false`, diğer değerler → `true` olur. |

| **8. User-Defined Conversions**  | `class → başka class`, `class → temel türlere(int gibi)`| Kullanıcı tarafından `operator` veya constructor ile tanımlanan dönüşümler. |

| **9. Derived-to-Base Conversions** | `Derived* → Base*`, `Derived& → Base&`      | Türemiş sınıf nesneleri, taban sınıf işaretçisine veya referansına atanabilir. |

				birden fazla strandart conversion varsa bu durumda best viable function nasıl bulunacak?
					void foo(double);	
					void foo(int);	
					void foo(unsigned int);

					1.exect match 
						derleyici yine argümandan parametre değişkenine olan dönüşümü kategorize ediyor argümanla parametre türünün tamamen aynı olması 

						DİKKAT:exect match olarak kabul edilen durumlar
							a)const olmayan nesne adresimden const nesne adresine dönüşüm
								
								void foo(const int*);

								int main()
								{
									int{};

									foo(&x);
								}
						
							b)fonksiyon türünden fonksiyon adresi türüne olan dönüşüm

								void foo(int (*)(int));

								int func(int);,

								int main()
								{
									foo(&func);
									foo(func); // burdada yukardaki gibi aynı işlem olur function to pointer conversion
								}
							c)array decay
								void foo(int*)

								int main()
								{
									int ar[5]{};
									
									foo(&ar[0);
									foo(ar); // array decay üsttekiyle aynı anlama geliyor
								}
							d)L value to R value conversion

								void foo(int);

								int main()
								{
									int x{35};

									foo(x); // L value to R value conversion
									foo(12); // her ikiside exect match
								}
					
					2.promotion
						a)int altı türlerin int türüne yükselmesi(integral promotion)
							bool->int
							char->int
							signed char->int
							unsigned char-> int (eğer int alabiliyorsa, aksi takdirde unsigned int)
							wchar_t->int veya unsigned int (derleyiciye bağlı)
							(C++20)char8_t->int
							short->int
							unsigned short->int (eğer int alabiliyorsa, aksi takdirde unsigned int)
							Not: Eğer tür int'e sığabiliyorsa, int'e yükseltilir.
							Eğer int'e sığmazsa, unsigned int'e yükseltilir.

								void foo(int);
								void foo(float);
								
								int main()
								{
									foo('A'); // char türünden int türüne -> promotion
								}

						b)float türünden double türüne yapılan dönüşüm(promotion)
							void foo(double);
							void foo(long double);
							void foo(int);

							int main()
							{
								floattan ->  double promotion var 
								floattan -> long double conversion 
								floattan -> int conversion

								foo(3.4f); // void foo(double) çağırılacak
							}
					3.conversion(eğer exect match ve promotion değilse birden fazla conversion varsa ambiguity olur)
						void foo(char);
						void foo(long double);

						int main()
						{
							foo(3.4); // ambiguity
						}

						void foo(unsigned int);
						void foo(long double);
						void foo(long);

						int main()
						{
							int -> unsigned int conversion
							int -> long double conversion
							int -> long conversion

							foo(12); // ambiguity 
						}

			

const overloading
	öyle durumlar var ki biz const nesnelerle const olmayan nesneler için ayrı implementasyonlar istiyoruz
	hem pointer hemde referans semantiği ile gerçekleştirilebilir

		void foo(T*);
		void foo(const T*);
		void foo(T&);
		void foo(const T&);

		DİKKAT: void foo(T* const) // bu re-decleration olurdu parametre'nin kendisi const

		void foo(int*){};
		void foo(const int*){};

		int main()
		{
			const int x{12};

			foo(&x);// const int* olan çağırılır,

			ama x const olmasaydı iki fonksiyonda viable olurdu bu durumda dilin kuralları const olmayan adrese öncelik tanıyor int* olan çağırılacak
			aynı kurallar referans semantiği içinde geçerli
		}

	eğer biri call by value biri call by reference ise bu yine function overloadingtir tipik olarak böyle bir overloading tercih edilmez
	eğer bu fonksiyonlara l value ile çağrı yaparsak her ikiside viable olur call by value ile call by reference birbirinden üstün değildir bu yüzden ambiguity olur 
		void funct(int);
		void funct(int&);

		int main()
		{
			int x{};
			func(x); // int& olan çağırılır

			func(10) // r value ile çağırırsak int& olan viable olmadığı için int parametleri olan fonksiyon çağırılır
			
			void funct(int&) olan fonksiyon const int & olsaydı hem l value hem r value değer kabul ettiği için yine ambiguity oluşacaktı
		}

	SORU:
		1)burda function overloading var default argumanlarda overloadinge dahildir
			varsayılan argümanla çağrının geçerli hale gelmesi onu varsıyılan argüman kullanılmayana göre seçilebilir kılmıyor

			void func(int,int = 0);
			void func(int);

			int main()
			{
				func(12); // ambiguity
			}

		2)tek ambiguity olmayan durum
			void func(void*); 
			void func(bool);
			
			int x = 10;
			func(&x); // void* çağırılır

	nullptr keywordü olmadan c++'ın modern cpp döneminin öncesinde fonksiyona null pointer argümanını bilerek siteyerek göndermek için NULL makrosunu doğrudan 
	kullanmak zaten tercih değildi bu yüzden null pointer conversiondan faydalanılıyordu
		void func(int*);

		int main()
		{
			func(0); // 0 tam sayı sabiti bir pointera atandığında yada pointer değişkeni initalize ettiğinde null pointera dönüşüyor
		}

		diyelim ki kodda bir değişiklik oldu ve int parametreli func fonksiyonu daha geldi böyle bir durumda hangisi çağırılacak?
			void func(int*); // 0'ın null pointera dönüştürülmesi standart conversion
			void func(int); // 0'ın int'e aktarılması exect match
			böyle bir durumda int parametreli olan fonksiyon çağırılacak nullptr keywordünün eklenmesindeki en büyük etkende bu nullptr sabitinin pointer 
			türlerine dönüşüm var ama pointer olmayan türlere örtülü dönüşüm yok 

			func(nullptr) // int * parametreli olan fonksiyon seçilir

			AMA DİKKAT
				iki tane ayrı pointer türünden parametre olsaydı nullptr_t türünden int* türüne yada double* türüne dönüşüm arasında bir fark olmayacaktı ambiguity olacaktı
					void func(int*);
					void func(double*);

	taşıma semantiğine zemin hazırlayacak overloading kuralları
		void func(int&); // l value reference
		void func(int&&); // r value reference
			ikiside overload

			int main()
			{
				intx{};
				func(12); // && çağırılacak
				func(x); // & çağırılacak
			}

		void func(const T&); // const l value reference hem l value hemde r value bağlayabiliriz
		void func(T&&); // r value reference 
		void func(T&); // l value reference(böyle bir overload biçiminde const değerler için const T& çağırılır const olmayan değerler için T& çağırılır)
		bu overlaodlar çok sık karşımıza çıkacak

		int main()
		{
			int x{};
			const int cx{};
			
			func(x); // int&
			func(34); // int&& 
			func(cx); // const T&
		}

		dilin olanakları bize şunu sağlıyor const olan nesne ve const olmayan nesnelerden ayrı ayrı implementasyonlar oluşturabiliyoruz
		eğer amaç gönderdiğimiz argümanın l value yadar r value olmasına bağlı olarak farklı implementasyon olmasını istiyorsak o zaman bir fonksiyonun paramtresini 
		const T& diğer fonkaiyonuda T&& yaparsak bu seçilimleri sağlayabailiriz

		KARIŞTIRILABİLİR ÖNEMLİ
			value category ile date type'ın karışıtırılması

				void foo(int&&)
				{
					std::cout<<"foo(int&&)\n";
				}

				void foo(const int&)
				{
					std::cout<<"foo(const int&)\n";
				}

				void func(int&& r)
				{
					foo(r); // r'nin data type'ı int&& burda r'nin value kategoriside L value
				}				isim şeklindeki ifadeler L value expressiondır

				int main()
				{
					func(123); // const int& çağırılır
				}

		hoca önemli bir yere değiniyor
			expression ifadesinin value kategorisi L value olsun ama bunu R value gibi kullanmak istersek 2 yolu var
				1)static_cast operatörünü kullanmak(pek tercih edilmez)
					void foo(const int&)
					{
						std::cout << "const int&\n";
					}

					void foo(int&&)
					{
						std::cout << "int&&\n";
					}

					int main()
					{
						int x = 10;

						foo(static_cast<int&&>(x));

					}
				2)std::move fonksiyonu
					hoca yanlış isimlendirilmiş bir fonksiyon olduğunu söylüyor ismini görenler sanki taşıma yapıyormuş gibi anlıyor 
					bir l value argümanı doğrudan kullanmak yerine bu fonksiyona çağrı yaptığımızda derleyici bu çağrı ifadesindeki argümanı r value olarak 
					görecek move fonksiyonun geri dönüş değeri X value &&move

					foo(std::move(x)); // compile timeda ele alınan sadece ifadenin value kategorisini değiştiriyor
					
					void foo(T&&) 
					{
						bar(std::move(t)); // r value olarak gönderiyoruz sadece t yi yollarsak l value olur
					}

					void foo(const T&)
					{
						bar(t); // l value olarak gönderiyoruz
					}

std::nullptr_t
	nullptr gönderdiğimizde ayrı bir overload çalışmasını istiyorsak nullptr_t türünden overload eklememiz lazım
		
		void func(std::nullptr_t);
		viod func(int*);

		int main()
		{
			int x = 10;

			func(nullptr); // nullptr_t olan çağırılacak
		}

overload olan fonksiyonların birden fazla fonksiyonları varsa ne olur?
	void func(int,double,long);
	void func(char,int,double);
	void func(long,long,char);

	birden fazla parametre olması durumunda viable fonksiyonların sayısı 2 yada daha fazlaysa ambiguity olmaması için bir fonksiyonun seçilmesi için
		a)en az 1 parametrede diğerlerine üstünlük sağlayacak
		b)ancak diğer parametrelerde diğerlerinden kötü olmayacak

	bu şartları sağlayan bir fonksiyon yoksa ambiguity

	int main()
	{
		func(12,12u,5) // 1.fonksiyon çağırılır 1.argümanda üstünlük sağladı 2. ve 3.cü argümanlar diğerlerinden kötü değil
		func(12,12u,5.f); // 1. ve 2. fonksiyon arasında ambiguity olucak float -> double promotion float -> long conversion
		func(12u,12u,5.f); // 2. fonksiyon çağırılacak 3.parametrede daha iyi 1. ve 2. parametrede daha kötü değil
	}
	 
	 void foo(char&){};
	 void foo(char&&){};

	 int main()
	 {
		char c{};
		foo(+c); // R value expression
	 }
*/