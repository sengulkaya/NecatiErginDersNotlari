/*

lambdalarda constexpr için C++17 ile değişikler yapıldı

	fonksiyon constexpr olma koşullarını sağlıyora default olarak constexpr olmuş oluyor
	
	ÖRNEK:
	
		int main()
		{
			auto f = [](int x) { return x * x; }; // constexpr fonksiyon

			constexpr auto val = f(10); // sentaks hatası yok çünkü fonksiyon constexpr 
		}

	ÖRNEK:constexpr olma kuralını çiğneyelim

		int main()
		{
			auto f = [](int x) 
			{ 
				static int cnt = 0;
				return x * x; 
			}; 

			constexpr auto val = f(10); // fonksiyon artık constexpr değil sentaks hatası
		}

	SORU:peki neden lambdalarda constexpr specifier'ını kullanalım?
		
		constexpr koşulunu ihlal eden bir öğe söz konusu olduğunda direkt kod geçerli olmayacak

		int main()
		{
			auto f = [](int x) constexpr
			{
				static int cnt = 0;  // sentaks hatası
				return x * x;
			};

		}
	
	SORU:neden trailing return type kullanalım?

		1)örneğin fonksiyonun içinde birden fazla return statement varsa kullanırız return expressionları farklı türden ise sentaks hatası oluşturur 
		
			int main()
			{
				auto [](int x)
				{
					if(x > 10)
						return 1;
					
					return 3.4; // sentaks hatası
				};
			}
		
			ÖRNEK:

				int main()
				{
					[](int x) -> double // artık fonksiyonun geri dönüş değeri double ve böylelikle çıkarım yapılmayacak
					{
						if(x > 10)
							return 1;

						return 3.4;
					};

				}
		2)fonksiyonun geri dönüş değerinin referans olmasını istiyorsak

			[](int &x) -> int&
			{
				return x;
			};
	
sınıfların üye fonksiyonları içinde kullanılan lambda ifadeleri

	ÖRNEK:
		class Point{
		public:
			void foo()
			{
				[this]() // sınıfın veri elemanlarına eşimek this pointerı'nı capture etmemiz gerekiyor
				{ 
			
					return mx * my; 
			
				};
			}

			int mx{},my{};
		};

	ÖRNEK:
		
		class Point {
		public:
			void foo()
			{
				[*this]() mutable //
				{ 
						mx++;
						my++;

					} ();
			}

			int mx{}, my{};
		};

		int main()
		{
			Point pt;

			std::cout<<pt.mx<<'\n'; // 0 0
				
			pt.foo();

			std::cout<<pt.my<<'\n'; // 0 0

			0 olmalarının nedeni mx ve my pt'nin mx ve my'si değil kopyalama yoluyla capture ettiğimiz *this'in mx'i
				
				[this]() // bu şekilde capture etseydik mutable olması gibi bir zorunluluk olmayacaktı ve nesnenin kendi mx ve my'yi değiştirmiş olacaktık
				{
						mx++;
						my++;

					} ();
		}

	SORU:neden *this'i capture ediyoruz ?

		genellikle dangling pointerlarla ilgili

			auto foo()
			{
				return [this]() {}; // this'i capture etmiş olsaydık pt nesnesinin elemanlarını kullanıyor olacaktık ama fonksiyonu çağırdıktan sonra adresi capture edilen
									   point nesnesinin hayatı bitmişse lambdayı kullanan ifadeler dangling pointer kullanmış olacaktı ama *this'i capture edersek dangling pointer 
									   olma durumu olmayacak yani *this'in kullanıldığı durumlarda closure object'in capture edilen nesnenin hayatının üstünde onun hayatı bittikten 
									   sonra bir hayata sahip olması :D :D  
			}

			int main()
			{
				Point pt;
			}

		DİKKAT: C++20 ile this'i = ile capture etmek deprecated edildi
		
			auto foo()
			{
				[=]() // [=,this] eğer kullanacaksak önerilen sentaks bu
				{
					mx++;
					my++;
				}();
			}
		
IIFE(Immediatly Invoked Function Expression)

	ÖRNEK:

		void foo()
		{
			static bool firs_call_flag = true; // static yerel değişkenlerin initalization'ı thread safe ama aşağıda bulunan if bloğu thread safe değil

			if(first_call_true)
			{
				std::cout<<"executed only once!\n";
				first_call_true = false;
			}
		}
		
		int main()
		{
			for(int i = 0; i < 10; ++i)
			{
				foo();
			}
		}

	ÖRNEK: thread safe'i sağlamak amacıyla lambdayı kullanıyoruz

		void foo()
		{
			static int _ { [] { std::cout<<"executed only once!\n"; return 0; }() }; //
		}

		int main()
		{
			for(int i = 0; i < 10; ++i)
			{
				foo();
			}
		}

	ÖRNEK: .operator ile de fonksiyonu çağırabiliriz

		auto x = [](){

		}.operator()(); 

INITIALIZATION ASSIGMENT SPLIT

	bir değişken tanımlandıktan sonra daha sonra değer vermek için atama yapıyoruz 

	std::string foo();

	int main()
	{
		std::string s;

		s = foo(); 
	}

	1)hoca böyle kodların çok kötü olduğunu söylüyor çünkü okuyanı yanıltıyor

	2)bazı kaynakları boş yere tutuyor olabiliriz

	3)scope leakage
		
	4)önce default ctoru çağırırp sonra da assignment fonksiyonunu çağırıyoruz 2 tane ayrı kodu çalıştırıyoruz doğrudan da yazılabilirdi

		std::string s = foo();

MULTI LAMBDA IDIOMU

	template<typename ...Ts>
	class MultiLambda : public Ts...{
		public:
			using Ts::operator()...;
	};

	int main()
	{
		MultiLambda mlx{
			[](int x){ std::cout<<"int\n"; },
			[](double x){ std::cout<<"double\n"; },
			[](char x){ std::cout<<"char\n"; },
			[](auto x){ std::cout<<"other type\n"; },
			 
		};

		mlx(12); // int parametreli fonksiyon çağırılır
		mlx(4.5f); // en sonda ki çağırılır
	}

--------------------------------------------------

int main()
{
	auto f = [](auto x) { return x + 3; };

	f.operator()<double>(4.5); // deduction yapılmasını istemiyoruz ve double parametreli fonksiyonun çağırılmasını istiyoruz
}

TRANSFORM ALGORITMASI

	1.overload
		range'de bulunan öğeleri bir fonksiyona göndereceğiz o fonksiyonun geri dönüş değerini başka bir range'e yazacağız

	template<typename InIter,typename OutIter,typename UFunc>
	OutIter Transfrom(InIter beg,InIter end,OutIter destebeg, UFunc f)
	{
		while(beg != end)
		{
			*destbeg++ = f(*beg++);
		}

		return destbeg;
	}

	2.overload
		2 tane range'de ki karşılıklı öğeleri 2 parametreli olan bir fonksiyona argüman olarak göndereceğiz fonksiyonun geri dönüş değerini bir range'e yazacağız
		
		template<typename InIter1, typename InIter2, typename OutIter ,typename BFunc>
		OutIter Transfrom(InIter1 beg1, InIter1 end,InIter2 beg2, OutIter destebeg, BFunc f)
		{
			while (beg1 != end)
			{
				*destbeg++ = f(*beg1++ *beg2++);
			}

			return destbeg;
		}

	ÖRNEK:

		int square(int x)
		{
			return x * x;
		}

		int main()
		{
			std::vector<int> ivec{ 2,4,6,8 };

			std::list<int> ilist(ivec.size());

			std::transform(ivec.begin(), ivec.end(), ilist.begin(), square); // vectordeki elemanların karesini ilist'e ekledik
			std::transform(ivec.begin(), ivec.end(), ilist.begin(), [](int x) { return x * x; }); // lambda ile vectordeki elemanların karesini ilist'e ekledik
		}

belirli fonksiyonlar var ki bu fonksiyonlar iteratörler ilgili iş yapıyorlar yani onları manipüle etmek

	1)advance
		iterötür n pozisyon ileri yada geri almak için kullanılır

		int main()
		{
			std::vector<int> ivec{ 3,6,7,8,9,1,2 };
			std::list<int> ilist{ 3,6,7,8,9,1,2 };

			auto veciter = ivec.begin() + 5;
			auto listiter = ilist.begin(); // list'in iteratörü sadece ++, -- destekler

			advance(veciter, -3); // 5. indisten 2. indise gider → 7
			advance(listiter, 3); // 0 → 1 → 2 → 3. konum → 8 // list'in iteratörü bidirectional olmasına rağmen döngüsel bir yapı içinde iteratörü 3 kez arttırmaya dönüştürüyor

			std::cout << *veciter << '\n';
			std::cout << *listiter << '\n';
		}

	2)distance
		iki parametreli bir fonksiyon ve iki iteratör alıyor 1.argüman olarak gönderdiğimiz konumundan 2.argüman olan konuma varmak için kaç arttırmamız gerek bunu buluyor 

		int main()
		{
			std::vector<int> ivec{ 3,6,7,8,9,1,2 };

			auto iter = find(ivec.begin(), ivec.end(), 9);

			std::cout<<distance(ivec.begin(), iter); // 9'a ulaşmak için 4 konum var
		}

	3)iter_swap
		2 iteratör konumu alır ve o iteratör konumun da ki nesneleri takas eder

		int main()
		{
			std::vector<int> ivec{ 3,6,7,8,9,1,2 };
			std::list<int> ilist{ 3,6,7,8,9,1,2 };

			iter_swap(ivec.end() - 1, ilist.begin()); // ivec'de bulunan son öğeyi ilist'in ilk öğesini takas ettik

			for (auto x : ivec)
			{
				std::cout << x<<" ";
			}
			std::cout << '\n';
			for (auto x : ilist)
			{
				std::cout << x << " ";
			}
		}

		ÇIKTI:
		3 6 7 8 9 1 3 -> ivec
		2 6 7 8 9 1 2 -> ilist

	4)next
		aldığı iteratör konumundan n uzaklıktaki konumu döndürüyor

		int main()
		{
			std::vector<int> ivec{ 3,6,7,8,9,1,2 };

			auto iter = next(ivec.begin(), 3); 

			std::cout<<*iter;
		}

	5)prev
		aldığı iteratör konumundan önceki n uzaklıktaki konumu döndürüyor

		int main()
		{
			std::vector<int> ivec{ 3,6,7,8,9,1,2 };
			std::list<int> ilist{ 3,6,7,8,9,1,2 };

			auto iter = prev(ivec.end() ,5);

			std::cout << *iter; // 7
		}
*/