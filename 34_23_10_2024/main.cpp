/*
forwarding reference karþýmýza 2 þekilde çýkýyor
	1)template olarak
		template<typename T>
		void func(T&&) {} // const yada volatile gibi yada baþka bir specifier varsa artýk universal reference deðil sadece T&& biçiminde universal reference olmuþ oluyor

	2)auto type deduction
		auto&&r

	DÝKKAT:
		hoca sýnýflarýn memberlarý söz konusu olduðunda yanlýþ anlaþýlan bir konuya deðiniyor
			template<typename T>
			class Myclass{
				public:
					void foo(T&&){} // bu universal reference deðil sadece R value deðerleri alýr
			};

			ÖRNEK:vector sýnýfýndan örnek
				template Vector{
					public:
						void push_back(const T&); // L value deðerleri kopyalarak containera ekler
						void push_back(T&&); // R value deðerleri taþýyarak containera ekler
				
						template<typename U> // member template
						void emplace_back(U&&) {} // bu universal reference olmuþ oluyor
				};

	ÖRNEK:perfect forwarding'in faydasýný görmek için vector örneði
	
		sondan ekleme yapýlýrken nesne için ne copy ctor'un nede move ctor'un çaðýrýlmasýný istemiyoruz nesnesinin kendisi oluþturulacak ama nesnesinin kendisi oluþturulmasý için
		ctora gönderdiðimiz argümanlarý göndermemiz gerekiyor öyle bir fonksiyon olacak ki ne L value nede R value bir deðer göndermeyeceðiz sadece ctor'a gönderilecek argümanlarý göndereceðiz 
		bu fonksiyona adeta þöyle demiþ olacaðýz sevgili fonksiyon :D al bu argümanlarý bu argümanlarý kullanarak vector'ün nesneyi oluþturacaðý bellek alanýnda ctoru çaðýrarak benim 
		argümanlarýmý ctora gönder demiþ oluyoruz eðer burada bizim ctoru çaðýrýmamýzla buradaki fonksiyonun bizim adýmýza ctoru çaðýrmasýnýn bir farký olmamasý için gönderdiðimiz argümanlarýn
		value kategorisi ve constluðunun korunmasý gerekiyor -> bunu yapan emplace_back fonksiyonu ne taþýma ne de kopyalama yapmaz


	forward fonksiyonunun çaðýrlmasý gibi bir zorunluluk yok ama
		1)kodu daha pratik hale getiriyor
		2)parametre paketleriyle kullanýlmasýný mümkün hale getiriyor

IF CONSTEXPR(compile time'da ele alýnýr)

	if constexpr(std::is_lvalue_reference<T>::value)
	{
		foo(x);
	}
	else
	{
		foo(std::move(x));
	} // std::forward olmasaydý böyle yazmamýz gerekecekti
	
ABBREVIATED TEMPLATE SENTAKSINDA FORWARDI NASIL KULLANIRIZ
	
	void func(auto&& x)
	{
		std::forward<decltype(x)>(x);
	}

TYPE TRAITS KÜTÜPHANESÝ
	meta functionlardan oluþan C++ dilinin standart kütüphanesinin bir bileþenidir 
	bulunan varlýklar tamamen compile time'a iliþkin

	template<typename T,T v>
	struct integral_constant
	{
		static constexpr T value = v;
		using value_type = T;
		using type = integral_constant;
		constexpr operator value_type() const noexcept { return value; }
		constexpr value_type operator()() const noexcept {return value;}
	};

	using true_type = integral_constant<bool,true>;
	using false_type = integral_constant<bool,false>;

	int main()
	{
		integral_constant<int,5>::value_type; // int 
		integral_constant<int,5>::type; // integral_constant<int,5>

		true_type::type // integral_constant<bool,true>
		 
		constexpr auto val = integral_constant<int,5>{} + integral_constant<int,9>{} // 14 

	}

	ÖRNEK:bir türün pointer türü olup olmadýðýný compile time'da sýnamak

		template <typename T>
		struct isPointer : std::false_type {};
		
		template <typename T>
		struct isPointer<T*> : std::true_type {}; // partial specialization
		
		template<typename T>
		constexpr bool isPointer_v = isPointer<T>::value; // value template

		template <typename T>
		 void func(T x)
		{
			if constexpr (isPointer_v<T>)
			{
				std::cout << "pointer turu\n";
			}
			else
			{
				std::cout << "hayir pointer türü deðil\n";
			}
		}

		int main()
		{
			isPointer<int*>::value; // true
			isPointer<const int*>::value; // true
			isPointer<int>::value; // false

			int* p = {};
			func(p); // true
		}
		
	ÖRNEK:bir türün const olup olmadýðýný sýnamak	

		template<typename T>
		struct isConst : std::false_type {};

		template<typename T>
		struct isConst<const T> : std::true_type {};

		template<typename T>
		constexpr bool isConst_v = isConst<T>::value;

		int main()
		{
			isConst_v<const int>; // true
		}
		
	ÖRNEK:remove_const

		template<typename T>
		struct RemoveConst{
			using type = T;
		}

		template<typename T>
		struct RemoveConst<const T> {
			using type = T;
		}

	ÖRNEK:birinci parametre hangi türden ise ikinci parametre için bir çýkarým yapýlmasýn o da ayný tür olsun

		func(1.24,45); // yani bu sentaks hatasý olmayacak 2.parametrede double türden olacak 
		 
		 template <typename T>
		 struct TypeIdentity{
			using type = T;
		 };

		 template<typename T>
		 void func(T x, std::type_idendtity_t<T> y);

		 int main()
		 {
			func(12.3, // 2.parametrenin türü type ýdentitiy T 'nin double açýlýmý 
		 }

	ÖRNEK:remove_reference

		template <typename T> struct remove_reference { using type = T; };
		template <typename T> struct remove_reference<T&> { using type = T; };
		template <typename T> struct remove_reference<T&&> { using type = T; };

		template <typename  T>
		using remove_reference_t = typename remove_reference<T>::type;

		int main()
		{
			remove_reference_t<int&> x { 3 }; // int x
			remove_reference_t<int&&> y { 3 }; // int y
		}

	ÖRNEK:
		
		template <typename T> struct add_cv { using type = const volatile T; };
		template <typename T> struct add_const { using type = const T; };
		template <typename T> struct add_volatile { using type = volatile T; };

		template <typename T>
		using add_cv_t = typename add_cv<T>::type;

		template <typename T>
		using add_const_t = typename add_const<T>::type;

		template <typename T>
		using add_volatile_t = typename add_volatile<T>::type;

		int main()
		{
			add_cv_t<int> x1{}; // const volatile int
			add_cv_t<int*> x2{}; // int* const volatile
			add_const_t<int*> x3{}; // int* const
			add_const_t<const int*> x4{}; // const int* const
			add_volatile_t<int*> x5{}; // int* volatile
			add_volatile_t<const int*> x6{}; // const int* volatile
		}

	ÖRNEK:
		
		template<typename T>
		struct TypeIdentity {
			using type = T;
		};

		template<typename T>
		struct remove_const : TypeIdentity<T> {};

		template<typename T>
		struct remove_const<const T> : TypeIdentity<T> {};

		template<typename T>
		using remove_const_t = typename remove_const<T>::type;

		int main()
		{
					remove_const_t<const int> a;      // int
					remove_const_t<int> b;           // int
					remove_const_t<const int*> c;     // const int*
					remove_const_t<int* const> d;    // int*
		}


	ÖRNEK:

		her ikiside tüm argümanlarý alabiliyor peki bunlarýn farký ne?

		template <typename T> 
		void foo(T&& t) // bu fonksiyonda bütün argümanlarý alabiliyoruz gönderilen argümanýn L value yada R value olduðunu const olup olmadýðýný bütün bunlarý fonksiyonun içinde
						   compile time'da öðrenebiliyoruz
		{
			std::is_lvalue_reference_v<T>

			//abbreviated template sentaksýnda böyle yazabiliriz -> std::is_lvalue_reference_v<decltype(t)>;
		
			bu bize const yada const olmayanlar için ayrý bir kod yazmayý L value yada R value olup olmadýðýný yada onlara kod yazma olanaðýný bize veriyor 
	
		}

		template <typename T>
		void bar(const T&); // bu fonksiyonda her türlü argümaný kabul ediyor ama gönderilen argümanýný kendisinin const olup olmadýðýný fonksiyonun kendisinin bilmesine olanak yok
							   gönderilen argümanýn L value yada R value olduðunu bilme olasýlýðýmýzda yok bu template o bilgiyi kaybediyor bu template içinde gönderilen argümanýn
							   value kategorisine baðlý bir kod yazamayýz örneðin aldýðý argümaný perfect forward edemez çünkü value kategorisi kayboluyor

	ÖRNEK:
		
		template <typename T>
		struct IsFloatingPoint : std::integral_constant<bool, 
				std::is_same_v<float, std::remove_cv_t<T>> || 
				std::is_same_v<double, std::remove_cv_t<T>> ||
				std::is_same_v<long double, std::remove_cv_t<T>>
				> {}; // SORU: bu template neden böyle yazýlmak yerine baþka þekildede implemenete edilmiyor?
		
		bool ifadesinden sonraki virgülden sonraki ifade bir sabit ifade sabit ifadenin deðeri true ise true_type'dan kalýtým elde edeceðiz false ise false_type'dan 
		
	ÖRNEK:generic programlama tarafýnda öyle durumlar var ki bir koþula baðlý olarak iki farklý türden birini kullanmamýz gerekiyor

		template <typename T>
		void func(T x)
		{
			sizeof(T) // örneðin T türünün sizeof deðeri 2 ise short türünü kullanmak istiyoruz 4 ise int türünü
		}	
		
		template <typename T>
		void func(T x)
		{
			std::conditional_t<std::is_floating_point_v<T>, double,int> val {};
			std::cout<<typeid(val).name()<<'\n';
		}

		int main()
		{
			func(20);
			func(2.3);
		}

VARIADIC TEMPLATE(parameter pack)

	her hangi bir sayýda template parametresi kabul edebilir yani öyle bir template oluþturabiliriz ki o template'den oluþturulan instantiationlar sanki 3 tane parametreisi varmýþ gibi yada
	n tane template parametresi varmýþ gibide kullanýlabilecek

	template parametrelerinin sayýsýnýn deðiþebileceðini compile timeda seçilebileceðini gösteren sentaks öðesine TEMPLATE PARAMETER PACK deniliyor
	
	template <typename ...Args> // Args yerine Types,Ts isimleride yaygýn olarak kullanýlýyor
	class Myclass {};

	int main()
	{
		Myclass<> m1;
		Myclass<int> m2;
		Myclass<int,double> m3;
		Myclass<int,double,long> m4;
	}

	ÖRNEK:

		template <int ...VALS> // non-type
		class Myclass {};

		int main()
		{
			Myclass<> m1;
			Myclass<1> m2;
			Myclass<1,3,5,7> m3;
		}

	ÖRNEK:

		template <typename ... Ts>
		void foo(Ts ...params) // eðer fonksiyonun parametre deðiþkenilerinden biri(genelde sonuncusu) template parametre paketini kullanýyorsa ve template parametre paketinden 
								  sonra ellipsis tokenini kullanýyorsa böyle bir fonksiyonun template parametre paketinde kaç tane tür varsa o kadar parametre deðiþkeni var demektir

		foo(2, 3.4, 5L, "necati"); // geçerli
		
		void foo(Ts& ...params) // eðer referans dekleratörü olsaydý fonksiyonun parametre deðiþkeni her biri L value ref olacaktý ve tür çýkarýmlarýda referans olmasýna göre yapýlacaktý

		int main()
		{
			int x = 5;
			double dval = 3.4;
			int a[5] {};

			foo(x,dval,a)  // foo<int,double,int[5]>(int&,double&, int(&r)[5])
		}

		void foo(Ts&& ...params) // universal reference olsaydý her hangi türden bir argüman gönderebileceðiz fonksiyonun bütün parametreleri universal ref olacak ve aldýðýmýz argümanlarýn 
									hepsini
										a)perfect forward edebileceðiz
										b)value kategorisini öðrenebileceðiz
										c)const olup olmadýklarýný öðreneceðiz

	ÖRNEK:sizeof... operatüründe ellipsis kullandýðýmýz zaman bu operatörün operandý olarak template parameter pack yada function parameter pack kullandýðýmýzda compile time sabiti olarak 
		 pakette ki öðe sayýsýný size_t türünden elde ediyoruz
										
			template<typename ...Ts>
			void func(Ts ...args)
			{
				constexpr auto sz1 = sizeof...(Ts);
				constexpr auto sz2 = sizeof...(args);

				// her ikiside geçerli ve her ikisininde deðeri ayný ve compile time sabiti
	
			}
							
			int main()
			{
				func(2,6,7.8,"murat");
			}

	ÖRNEK:variadic parametre paketi tek parametre olmak zorunda deðil
		
		template<typename ...Ts>
		void func(int,int,Ts ...args)
		{
			constexpr auto sz1 = sizeof...(Ts);
			constexpr auto sz2 = sizeof...(args);

			// eðer fonksiyon böyle bildirilseydi parametre paketinde ki öðe sayýsýyla fonksiyonun parametre deðiþkeninin sayýsý ayný olmayacaktý
			std::cout<<sz1<<" " <<sz2;
		}
				
		int main()
		{
			func(1,3,6,7); // 1 ve 3 1.ve 2.non-type argümana gidecek 6 ve 7 parametre paketine gidecek
		}

	variadic templatelerde en önemli kavramlardan biri PACK EXPANSION(paketin açýlmasý yada geniþletilmesi)

		template <typename ...Ts> 
		class Myclass : public Ts... { // öyle baðlamlar var ki o baðlamlar söz konusu olduðunda derleyici pack expansion ifadesini baþka bir ifadeye dönüþtürüyor
										  burda template parametre paketinden sonra ellipsis tokeni var eðer burda template parametre paketi expand edilmiþse derleyici
										  pack expansion ifadesini virgüllerle ayrýlan bir listeye dönüþtürüyor
		
		};

		struct A{};
		struct B{};
		struct C{};

		Myclass<A,B,C> // derleyicinin oluþturduðu Myclass sýnýf þablonunun specializationu -> class Myclass : public A,public B,public C {};
	
	ÖRNEK:
		template <typename... Args>
		struct Nec {};

		template <typename ...Ts>
		void func(Ts... params)
		{
			Nec<Ts...> x; // pack expansion Nec<int, double, long>
		}

		int main()
		{
			func(2,5.9 , 56L); // T = int, double, long
		}

	ÖRNEK:
		
		struct A {void foo(int); };
		struct B {void foo(double); };
		struct C {void foo(long); };

		template <typename ...Ts>
		class Myclass : public Ts..{

			using Ts::foo ...; // derleyici bunu her bir taban sýnýfýn foo isimli fonksiyonu için bir using decleration'ý olacak
			
		 };

		 int main()
		 {
			Myclass<A,B,C> m1; 

			m1.foo(12); // A sýnýfýnýn foo fonksiyonunu kullanýrýz
			m1.foo(1.2); // B sýnýfýnýn foo fonksiyonunu kullanýrýz
		 }
*/