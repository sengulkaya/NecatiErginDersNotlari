/*

derleyicinin bir template koddan template specialization'ý oluþturmasýna template instantiation deniliyor
specialization ile karýþtýrmayalým specialization oluþan ürünün ismi derleyici template instantiation yaptýðýnda yani template'den kodu yazdýðýnda 
oluþan ürün o template'in bir specialization'ý yani derleyici template'i instantiation ederek template'in specializationýný oluþturuyor

	
	TEMPLATE SPECIALIZATION OLUÞTURMANIN YOLLARI
		1)implict
			derleyicinin durumdan vazife çýkartarak instantiation'ý yapmasý

			template<typename T>
			T getMax(T x,T y)
			{
				return x > y ? x : y;
			}

			int main()
			{
				getMax(20,10); // derleyici bu fonksiyona çaðrý yapýldýðý için ve fonksiyon þablonu olduðu için önce argument deduction yapýcak sonra substitution sürecini yönetecek yani
				template parametresine karþýlýk gelen template argümanýný yerine koyacak ve derleyici burda template'i instantiate ediyor derleyicinin burda template'i
				instantiate etmesi için bir talimat vermiyoruz ama  EXPLICIT TEMPLATE INSTANTIATION(hoca ileride deðinecekmiþ) ile derleyiciye fiilen bir template'den 
				instantiotionu yapmasý için talimat veriyoruz
					template<typename T>
					T getMax(T x,T y)
					{
						return x > y ? x : y;
					}
					template double getMax<double>(double,double);
			}

		2)explicit


	C++20 standarýnda generic programlmaya iliþkin revolution eklemekler oldu bunlardan en iyi eklemelerden biri ABBREVIATED TEMPLATE SYNTAX(KISALTILMIÞ ÞABLON SENTAKSI)
		void foo(auto x) 
		{

		}

		bu aslýnda bir function template böyle yazmakla aþaðýdaki gibi yazmak ayný anlamda
			template <typename T>
			void foo(T x); 

		DÝKKAT:
			template <typename T>
			void func(T x,T y);

			void func(auto x, auto y); // þeklinde yazarsak buradaki x ve y farklý template türlerinden olmuþ olur yani sanki þöyle yazmýþ gibi olur
			
				template <typename T,tyepname U>
				void func(T x,U y);

			auto func(auto x,auto y ) // fonksiyonun geri dönüþ deðeri auto return type fonksiyonun parametreli ABBREVIATED TEMPLATE SYNTAX


	bir sýnýf generic olmasada sýnýfýn static veya non-static member functionlarda function template olabilir

		class Myclass{
			public:
				
				template <typename T>
				void foo(T);

				template <typename T> // type cast operatorlerde template olabilir
				operator T()const{
					std::cout << "operator T \n";
					return 5; // derleme sýrasýnda dönüþümün int türüne yapýlacaðýný belirtitiðimiz için geri dönüþ deðerini kullanmamýz gerekli
				}
		};

		int main()
		{
			Myclass m;

			m.foo(45); // derleyici sýnýfa int parametreli specialization oluþturuacak
			
			int x = m;
		}

	C++20 ile gelen özellikleri saymazsak fonksiyonun geri dönüþ deðeri türü için ya 
		a)türü kendimiz belirliyoruz
			template <typename T>
			T foo(T) {} // T türünü int olarak belirlersek geir dönüþ deðeri int olur

		b)geri dönüþ deðeri türünün trailing return type yapýlmasý
			hem generic olmayan kodda hemde generic kodda kullanýlabiliyordu

			int ar[10];

			auto foo() -> int(&)[10]
			{
				return ar;
			}

			trailing return type kullanmazsak böyle yazmamýz gerekirdi

				int (& foo())[10]
				{
					return ar;
				}

			ÖRNEK:
				class Myclass{
					public:
						class Nested{

						};

						Nested foo();
				};

				auto Myclass::foo()-> Nested // ismi nitelemeden yazabiliyoruz
				{
					return {};
				}

			ÖRNEK:
				struct Nec {
					std::vector<int> mvec;

					auto begin() const -> decltype(mvec.begin()) // fonksiyonun geri dönüþ deðeri mvec.begin() fonksiyonýu çaðýrýldýðýnda bu ifadenin türü neyse fonksiyonunda
																	geri dönüþ türü o
					{
						return mvec.begin();
					}

					decltype(mvec.end()) end() const // fonksiyonun geri dönüþ deðerini trailing return type yapmadýk mvec.end() fonksiyonun geri dönüþ deðeri yaptýk
														end() fonksiyonumuz const olduðu için tür uyuþmazlýðý oldu
					{
						return mvec.end(); // bu fonksiyonu çaðýrdýðýmýz zaman sentaks hatasý olur çünkü mvec.end() fonksiyonu const deðil bu yüzden tür uyuþmazlýðý var
					}

				};

				bu örneklerde trailing return type'ý kullanmakla geri dönüþ deðerini doðrudan yazmak arasýnda sentaks açýsýndan farklýlýklar oluþmuþ oluyor

	AUTO RETURN TYPE
		
		auto foo(int x)
		{
			// fonksiyonun geri dönüþ deðeri türü fonksiyonun return ifadesinden deduction yoluyla anlaþýlacak
		}

		
		ÖRNEK: 
			auto foo(int x); // sadece bildirim olursa derleyici çýkarým yapamaz


			int main()
			{
				auto val = foo(5); // sentkas deðeri çünkü geri dönüþ deðerini çýkarým yapma imkaný yok direkt tanýmýný yazmamýz lazým
			}

			auto foo(int x)
			{
				return x * 5;
			}

		ÖRNEK: birden fazla return statement varsa return statementlarda geri dönüþ deðeri türünün ayný olmasý gerek

			auto foo(int x)
			{
				if(x > 10)
					return 1;

				return 3.4; // sentaks hatasý fonksiyonun geri dönüþ deðeri int yani birden return statement varsa türleri ayný olmak zorunda
			}

		ÖRNEK: fonksiyonun geri dönüþ deðeri sadece auto olmak zorunda deðil

			auto& foo(int x);
			auto&& foo(int x);
			const auto& foo(int x);
		
		ÖRNEK:
			auto foo(int& x)
			{
				return x; // auto type deductiona göre fonksiyonun geri dönüþ deðeri int fonksiyonun geri dönüþ deðeri int& olmasý için geri dönüþ deðerini auto& yapmamýz gerekirdi
			}

		ÖRNEK:

			template<typename T>
			auto pri1(const T& x) -> decltype(std::cout << x); // fonksiyonun geri dönüþ deðeri ostream&
			{

				return std::cout<<x;
			}

			int main()
			{
				pri(10) << 40; // sentaks hatasý yok çünkü fonksiyonun geri dönüþ deðeri ostream&
			}
		
			DÝKKAT: eðer fonksiyon þöyle olsaydý
				template<typename T>
				auto pri1(const T& x)  // auto type deduction olduðu için ve referans decleratörü olmadýðý için fonksiyonun geri dönüþ deðeri ostream
				{

					return std::cout<<x;
				}

				int main()
				{
					pri(10) << 20; // þimdi sentaks hatasý olur çünkü fonksiyonun geri dönüþ deðeri ostream olduðu için kopyalama semantiði devreye girdi ve copy ctor delete edildiði için
									  sentaks hatasý oldu
				}
	
PARAMETER PACK(parametre paketi) variadic template'de deniliyor
	modern C++ ile eklenen çok önemli araç
	
	template <typename ...Types> // ellipsis tokený ile kullanýlýyor
	class Myclass{

	};
	
CLASS TEMPLATE
	
	template<typename T>
	class Myclass{
		
		public:
			T get()const;
			void set(const T&);

		private:
			T mx;
			T* a[10];
	};


	int main()
	{
		Myclass<int> m1;
		Myclass<double> m2;

		m1 ve m2 birbirinden tamamen farklý sýnýflardýr

		m2 = m1; // sentaks hatasý
	}

	sýnýf þablonunun üye fonksiyonunu sýnýfýn içinde inline olarak yada class definition dýþýnda tanýmlayabiliriz
		template<typename T>
		class Myclass{
			public:
				T foo(T x);

		};

		template<typename T>
		T Myclass<T>::foo(T x)
		{

		}

	class scope içinde sýnýf þablonunun ismini doðrudan specialization ismi olarak kullanabiliriz
		template<typename T>
		class Myclass{
			public:
				Myclass<T> foo(Myclass<T>); 
				Myclass bar(Myclass) // ikiside ayný anlamda yani class scope içinde sýnýf þablonunun ismini kullanmak ilgili specializationu kullanmak demek
				{
					Myclass m; // Myclass'ýn int açýlýmý için bu yerel deðiþkenin türü Myclass'ýn int açýlýmý türünden olacaktý
				}
			};

			int main()
			{
				Myclass<int> x;
			}

			ÖRNEK:
				template<typename T,typename U>
				class Myclass{
					public:			
						void foo()
						{
							Myclass m;
							std::cout<<typeid(m).name()<<'\n';
						}
				};

				int main()
				{
					Myclass<int,long> x;

					x.foo();
				}
	
	specialization'ýn kendisi class olduðuna göre baþka template'de bir template argümaný olarak'da kullanýlabilir
		
		template<typename T,typename U>
		class Myclass{
			
			public:

		};
		
		int main()
		{
			std::vector<Myclass<int,double>>

			Myclass<Myclass<int,double>,Myckass<long,char>>
		}

	ÖRNEK:
		template<typename T,typename U>
		class Myclass;

		template<typename T>
		void func(T);

		int main()
		{
			Myclass<int,double> m;

			func(m);
		}

	ÖRNEK:
		template<typename T,typename U>
		class Myclass;

		template<typename T,typename U>
		void func(Myclass<T,U> p);

		int main()
		{
			Myclass<int,double> m;

			func(m);
		}

	ÖRNEK:
		template <typename T>
		class Myclass{
			public:
				T val{};
		};

		template<typename T>
		bool operator<(const Myclass<T>& lhs,const Myclass<T>& rhs)
		{
			return lhs.val == rhs.val;
		}

		int main()
		{
			Myclass<int> x,y;
			Myclass<double> d1,d2;

			x < y;
			d1 < d2;
		}

	ÖRNEK:
		template<typename T>
		class Myclass{
			public:
				template<typename U>
				void foo(U)
		};

		int main()
		{

			Myclass<int> m;
			m.foo(std::string{}); 
		}

	ÖRNEK:
		template<typename T>
		class Myclass{
			public:
				template<typename U>
				void foo(Myclass<U> p)
				{
					// *this'in türü Myclass<int> açýlýmý
					// p'nin türü Myclass<double> açýlýmý

					std::cout<<typeid(*this).name() <<'\n';
					std::cout<<typeid(p).name() <<'\n';
				}
		};
		
		int main()
		{
			Myclass<int> x;
			Myclass<double> y;

			x.foo(y);
		}
		
		ÇIKTI:
			class Myclass<int>
			class Myclass<double>

	ÖRNEK:
		template<typename T,typename U>
		struct Pair{
			
			Pair = default;
			template<typename X,typename Y>
			Pair(const Pair<X,Y>&);

			T first;
			U second;
		};

		int main()
		{
			Pair<double,double> pd;
			Pair<int,int> pi;

			pd = pi; // normalde farklý sýnýflar ama yazdýðýmýz ctor member template olduðu için bunu geçerli hale getirebiliyoruz 
		}
*/