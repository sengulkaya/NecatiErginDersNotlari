/*

stringlerden devam

RANGE PARAMETRE(char c)
	az sayıda olsada bazı fonksiyonların parametresi range parametre

	iki konumla belirlenen aralık demek 

	int main()
	{

		std::vector<char> cvec{ 'a','h','m','e','t' };

		cvec.begin(); // ilk öğenini konumunu döndürüyor 'a'
		cvec.end(); // end konumuna geldiğinde artık container'ın bir öğesi yok bütün öğeleri gezmiş oluyoruz üyeleri dolaşırken bir kontrol konumu olarak kullanılıyor
					containerdaki son öğenin konumu end konumu değil ondan bir önceki konumu cvec.end() - 1 
					yada global bir fonksiyon olan prev(cvec.end()) fonksiyonuyla bir önceki konumu elde edebiliriz
	
		(beg,end) böyle bir fonksiyon varsa beg konumunda ki öğeden başlayarak end konumuna gelinceye kadar
		karakterlerin oluşturduğu aralık üstünde işlem yapıyor demek
		
		std::string str(cvec.begin(), cvec.end()); // string sınıfının range parametreli ctorunu kullanarak str nesnemizi ahmet yazısıyla hayata başlatıyoruz

		std::cout << str; // ahmet yazısı yazdırılır
	}

STRING SINIFININ CTORLARI
	
	DEFAULT CTOR
		int main()
		{
			string s1; 
			string s2{}; // value initialization 
		
			default construct edilen containerlar öğe tutmayan boş durumda olan containerlardır

			s.length(); // 0 döndürür
			s.empty(); // true döndürür
		
			s.clear(); // std::array hariç hepsinde var containerların içindeki tüm elemanları siler
		
			DİKKAT:boş bir container üstünde begin fonksiyonunu çağırabilir begin fonksiyonun geri döndürdüğü iteratörü belirli işlemlerde kullanabiliriz
			ama begin fonksiyonunun döndürdüğü iterator konumunu de-reference etmek undefined behaviour

			auto iter = s.begin();
			*iter; // undefined behaviour
		}

	CSTRING PARAMETRELİ CTOR(const char*)
		int main()
		{	
			ÖRNEK 1:

				std::string str("alican");

				std::cout<<str.length() <<'\n'; // 6 çıktısı alınır
			
			ÖRNEK 2:

				char buf[] = "emre can";

				string str(buf); 

			ÖRNEK 3:
				
				char buf[10];
				
				buf[1] = 'c';
				buf[2] = 'a';
				buf[3] = 'n';

				string str(buf) // sentaks açısından geçerli ama undefined behaviour çünkü burdaki implementasyon null karakter görene kadar o adresi takip edecek 
		}

	COPY CTOR
		
		int main()
		{
			string s1{"alihan bozkır"};
			string s2 = s1; // copy initialization
			string s3(s1); // direct initialization
			string s4{s1}; // uniform initialization

			hepsinde copy ctor çağırılır
		}
	
	MOVE CTOR

		int main()
		{
			string s1{"alihan bozkır"};
			string s2 = std::move(s1); // s2 s1'in kaynağını çalıyor
		}	
		
		MOVED FROM STATE(taşınmış nesne durumu)

			1)yukarıda s2 nesnesi s1 nesnenini kaynağını çaldı s1 şu an moved from statete olmuş oluyor standart kütüphane kendi sınıfları için
			moved from state'i bir valid state'te olduğunu garanti ediyor ama değerinin ne olduğunun garantisini vermiyor s1'in kaynağı çalındıktan sonra boş bir string değeri
			olmak zorunda mı? HAYIR ama implementasyonların hemen hepsi taşınmış durumdaki moved from state'te ki nesneyi uzunluğu 0 olan tekrar kullanılabilir
			bir nesne haline getiriyor

			std::cout<<s1.length()<<'\n'; // standart tarafından s1'in içinde ne olduğunun bir garantisi yok yani s1 hala kullanılabilir ama içeriği hakkında bir garanti yok

			2)moved from state'te olan bir nesneye tekrar bir atama yapabiliriz 
				s1 = "oguzhan esin";

			std::string foo() adında bir fonksiyonumuz olsun geri dönüş değerini bir değişkeni initialize etmek için kullanalım burda foo'nun kodunun ne olduğuna bağlı olarak 
							olabilecek durumlar
				
				1)mandatory copy elision olabilir

					std::string foo() 
					{
						return std::string{"Hello world"};  // C++17 ve sonrası: no copy/move
					}

				2)named return value optimization

					std::string foo() 
					{
						std::string s = "Hello world";
						return s;  // NRVO uygulanabilir C++14 ve öncesi
					}

				3)move ctor devreye girer
					std::string foo() 
					{
						std::string s = "Hello world";
						return s;  // NRVO yoksa: move ctor devreye girer C++11 ve sonrası
					}

				programcı bunu kavramadığı zaman out parametre koyuyor 
					void foo(std::string& s) // mutator
					{
						s = "Hello world"; // s fonksiyonun dışında tanımlı bir string'e veri koymak için kullanılıyor
					}

					int main()
					{
						std::string s;

						foo(s);

						std::cout << s;
					}
		
	DATA PARAMETRELİ CTOR(const char*,size_t n)
		int main()
		{
			char buf[] = "fatih akgul";

			std::string str { buf, 5 }; // buf adresinden başlayarak 5. karaktere kadar olan karakterleri alacak
			
			std::cout<<"|" << str << "|\n"; // fatih çıktısını alırız
		}
	
		int main()
		{
			char buf[] = "fatih akgul";

			std::string str{ buf + 6, 2 }; // buf adresinden 6.karakterden itibaren başlayarak sadece 2 karakter alacak

			std::cout << "|" << str << "|\n"; // ak çıktısını alırız
		}

	string sınıfının char parametreli ctoru yok ama char parametreli assignment operator fonksiyonu var
		std::string s;
		s = 'A';
	
	FILL PARAMETRELİ CTOR(size_t,char c)
		int main()
		{
			std::string s(10, 'A');

			std::cout << "size = " << s.size() << '\n';
			std::cout << s << '\n';

			ÇIKTI:

			size = 10
			AAAAAAAAAA

			ÖRNEK:
				
				size_t n = 45;

				std::cout<<std::string(n,'*');

		}

		INITIALIZER LIST
			#include <initializer_list>

			std::initializer_list<int> x{ 1,4,6,7,9 }; // derleyici initializer_list sınıfı türünüden nesne oluşturduğumuzda aslında elemanları const olan bir dizi oluşturuyor
			ve oluşturduğu const dizinin başlangıç adresini ve bittiği yerin adresini initializer list sınıfı türünden nesnesnin elemanlarında tutuyor

			constexpr auto sz = sizeof(std::initializer_list<int>); // 2 pointer kadar size değeri vardır

			doğrudan const bir dizi tanımlamak yerine initializer_list ile tanımlayabiliriz
			
			vector<int> ivec {1,3,5,7,9} // initializer list parametreli ctor ile nesne yaratılıyor
		
			ÖRNEK:
				std::initializer_list<int> x{3,6,7,9,2};	
				std::initializer_list<int> y = x; // initializer list'in içinde tutuuğu pointerlar kopyalanıyor
		
				std::cout<<(x.begin() == y.begin()) << '\n'; 
		
			1)initializer list'in önemli faydalarından biride ucuz bir şekilde kopyalama semantiğinden faydalanmak
				void func(std::initializer_list<int>); // bir fonksiyonun parametresinin initializer list olması ciddiye alınacak bir kopyalama maliyeti oluşturmuyor çünkü
				böyle bir fonksiyona bir initalizer list gönderdiğimizde iki tane pointerın kopyalanması sonucunu doğuruyoruz
		
			2)auto type deduction initalizer list ile ilgili C++14 ile bir kural değişikliği geldi
				auto x = {1,4,6}; // type deduction initializer_list'in girilen öğelerin türü açılımı oluyor x 'in türü initializer_list<int>
			
				eğer eşittiri yazmıyorsak birden fazla değer koymamız sentaks hatası
				auto x{1}; // int çıkarımı yapılır

			3)
			class Myclass {

			public:
				Myclass(int)
				{
					std::cout << "Myclasss(int)\n";
				}

				Myclass(int, int)
				{
					std::cout << "Myclass(int,int)\n";
				}

				Myclass(std::initializer_list<int>)
				{
					std::cout << "Myclass(init_list<int>)\n";
				}
			};

			int main()
			{

				Myclass m1(34); // int parametreli ctor seçilir

				Myclass m2{47}; // initializer list int parametreli ctor seçilir


				küme parantezi olduğu zaman initalizer_list parametreli ctor'un seçilebilirliği oluyor

				Myclass m3(3,5); // int,int parametreli ctor çağırılır

				Myclass m4{4,6}; // initializer_listp parametreli ctor çağırılır

			}
	 
	INITIALIZER LIST CTOR(std::initializer_list<char>)

			int main()
			{
				std::string s1{ 'x'}; // initalizer_list parametreli ctor

				std::string s2{53,'x'}; // burada initalizer list parametreli ctor çağırılacak				
			
			}
	
	SUBSTRING CTOR
		
		int main()
		{
			std::string s1{ "adem duygu"};
			
			string s2(s1,5); // s1 stringinin 5 indeksinden başlayarak geriye kalan hepsi

			std::cout<<"|"<<s2<<"|\"; // duygu çıktısı alınır

			std::string s3(s1,1,3); // s1 stringinin 1.indeksinden başlayarak 3 tane karakter al demek

			std::cout<<"|"<<s3<<"|\"; // dem çıktısı alınır

		}
	
	NPOS(string::npos)
		string sınıfının constexpr static data memberıdır npos string'in size_type'ı türünden bir sabit 		
		
		npos'un kullanıldığı 2 yer var
			1)arama fonksiyonları
				hepsi size_type döndürüyor ve arama fonksiyonları aranan bulunduğunda bulunan konumun indeksini döndürüyor
				aranan bulunmadığında string::npos döndürüyor

				int main()
				{

					std::cout << "bir yazi gir: ";

					std::string str;

					getline(std::cin, str);

					std::string::size_type idx = str.find("t");

					if (idx != std::string::npos)
					{
						std::cout <<"bulundu " << idx<<".indeks";

					}
					else {
						std::cout << "bulunamadi";
					}
					ÇIKTI:
					bir yazi gir: ali ertas
					bulundu 6.indeks
				}
			2)karakterlerin hepsini kullanmak istediğimizde
				bazı fonksiyonlar parametre olarak substring parametre alıyor str,idx,n 
				öyle durumlar var ki bu interface'te geriye kalan karakterlerin hepsini kullanmak istiyoruz 
				
				örneğin idx 20 bu indeksten sonra 20 tane karakter yok 
				sadece 5 tane karakter var bu durumda undefined behaviour olmuyor yani bu indeksten sonra ki bu kadar tane karakter anlamında kullandığımız argüman 
				o indeksten sonra geriye kalan karakter sayısından daha fazlaysa tanımsız davranış olmadığı gibi geriye kalan karakterlerin hepsi anlamına geliyor

					std::string str("birazdan ara verecegiz lutfen sabirli olalim :D");

					str.substr(5,4); // 5 indeksinden başlayarak 4 tane karakter
					
					str.substr(5,670); // geriye kalan karakter sayısı 670 sayısından az tanımsız davranış olmaaycaktı 5 indeksinden başlayıp geriye kalan tüm karakterleri alacaktı
					ama stringimiz 3bin karakter olsaydı bu bizim istediğimiz işi yapmayacaktı

					str.substr(5,std::string::npos); // 5 indeksinden başlayıp geriye kalan tüm karakterleri almak garanti altında

	IF WITH INITIALIZER
		C++17 ile gelen yeni bir if deyimidir switchlerdede kullanılabiliyor 
		
		bazen bir fonksiyonun geri dönüş değerini bir değişkende saklıyoruz ama o değişkeni sadece if deyiminin gövdesinde kullanmak istiyoruz
			std::string::size_type idx = str.find("t");

			if (idx != std::string::npos)
			{
				std::cout <<"bulundu " << idx<<".indeks";

			}
			else {
				std::cout << "bulunamadi";
			}

		örneğin yukarıda ki gibi yazdığımızda scope leakage(kapsam sızıntısı) oluyor

		... buralarda yanlışlıkla idx'i kullanabiliriz 
		
		if(size_t idx = str.find('t'); idx != std::string::npos) // if with initializer
		{
			std::cout <<"bulundu " << idx<<".indeks";
		}
		else 
		{
			std::cout << "bulunamadi";
		}
		
		// idx'i artık burda kullanamayız
		
		DİKKAT:C++98 ile gelen if sentaksı logic bir sınama yapıyor
			int foo();
			int* bar();

			int main()
			{
				if(int x = foo())
				{

				}

				if(int* ptr = bar())
				{

				}
			}
	
	RESERVE FONKSİYONUN ÖNEMİ
		int main()
		{
			std::string str(20, 'a');

			str.reserve(1'000'000);

			auto cap = str.capacity();

			for (int i = 0; i < 1'000'000; ++i)
			{
				str.push_back('a');

				if (str.capacity() > cap)
				{
					std::cout << "length = " << str.length() << " capacity = " << str.capacity() << '\n';
					cap = str.capacity();
				}
			}
		}	
	 
		önceden kapasiteyi rezerve ederek re-allocation'ı önlemiş oluyoruz reserve fonksiyonunu kullanmasaydık kapasite arttıkça re-allocation 
		olacaktı ve sürekli kopyalama yapmış olacaktık
	
	STRING SINIFI FONKSİYONLARI
		
		1)öğelere erişmenin yolları
			
			[] // subcript 
				std::string s("mehmetcan");

				for(size_t idx{}; idx < s.length(); ++idx)
				{
					std::cout<< s[idx] << " ";
				}

				subscript operatörünün riskli kısmı indeks geçerli değilse yazının uzunluğundan büyükse undefined behaviour exception fırlatmıyor 

			.at() 
				subscript'ten farkı indeks geçerli değilse exception fırlatır 

			.front() // containerdaki ilk öğeye erişim sağlar
				std::string s("necati");

				std::cout<<s<<'\n';

				s.front() = '*'; // ilk karakter olan n karakteri yerine * karakteri yazılır

				std::cout<<s<<'\n'; // *ecati 

			.back() // containerdaki son öğeye erişim sağlar(begin ve end fonksiyonlarıyla karıştırmamamız lazım begin ve end iteratör döndürüyor front ve back fonksiyonları
			sequence containerlarda ilk ve son öğeye erişmemizi sağlar) 
				std::string s("necati");

				std::cout<<s<<'\n';

				s.back() = '*'; // son karakter olan i karakteri yerine * karakteri yazılır

				std::cout<<s<<'\n'; // necat* 

				DİKKAT:s nesnesi boş olsaydı front ve back fonksiyonlarının çağırılması undefined behaviour'a sebep olurdu  
			
			*iter // iterator konumunu kullanıp de-reference etmek
				std::string s("necati");

				// auto iter = s.begin();

				// std::cout<<*iter; // iterator konumundaki ilk öğe olan n karakterine erişiriz
					
				for(string::iterator iter = s.begin(); iter != s.end(); ++iter)
				{
					std::cout<<*iter; 
				}

				access amaçlı dolaşacağımızı göstermek için cbegin() ve cend() fonksiyonlarını kullanabiliriz
				
				for (std::string::const_iterator iter = s.cbegin(); iter != s.cend(); ++iter)
				{
					std::cout << *iter;
				}
			
				range base for loop kullanarak derleyicinin bunu yazmasını sağlayabiliriz
					
					for(char c: s) // burada yazıyı c değişkenine kopyalıyoruz c değişkeni üzerinde yapılan bir değişiklik s nesnesini değiştirmez 
					{				char &c eğer referans semantiği kullanılsaydı s nesnesinin kendisine erişilirdi ve s üzerindede değişiklik yapılırdı çünk c değişkeni
									s nesnesine referans olmuş oluyor
						std::cout<<c;

						char c = '*'; // referans semantiği olmadığı için s yine aynı kalır sadece c üzerinde işlem yapılır
					}

					char c -> elemanın kopyasını kullanacaksak
					char &c -> elemanın kendisini kullanacaksak
					const char c -> elemanın kopyasını kullanacağız ama kopyaya atama yapmak istemiyoruz
					const char &c -> elemanın kendsini kullanmak istiyoruz ama atama yapmak istemiyoruz
					auto&& c -> auto ile universal reference semantiğini kullanabiliriz türü açık yazmak ile auto ile yazmak arasındaki fark sadece bu yani char && c yazarsak
					sadece r value değerleri kabul eder ama burda auto kullandığımız zaman universal reference devreye giriyor
		
		2)öğeleri karşılaştırma yolları
			
			.compare()
				
				std::string s1("necati");
					< 0	-> *this < other
					== 0 ->	*this == other
					> 0	-> *this > other

			std::string'de lexicographical compare, doğrudan operator<, operator==, operator> gibi karşılaştırma operatörleriyle otomatik olarak uygulanır. 
			C++ std::string’ler için sözlük sırasına göre karşılaştırma yapar.

			int main() {
				std::string s1 = "apple";
				std::string s2 = "banana";

				if (s1 < s2)
					std::cout << s1 << " is less than " << s2 << '\n';
				else
					std::cout << s1 << " is NOT less than " << s2 << '\n';
			}
			ÇIKTI:
			
			apple is less than banana

			"apple" vs "banana"

			'a' < 'b' → true

			"abc" vs "abcd"

			'a' == 'a'

			'b' == 'b'

			'c' == 'c'

			"abc" daha kısa olduğu için küçük kabul edilir.

		3)mutators
			
			operator= 
				std::string s1{"mustafa aksoy"};

				s1 = "turgut akseki"; // bütün mutate işlemlerinde kapasiteyle doğrudan ilgilenmek zorunda değiliz kapasiteyi re-allocation yapmak implementasyonun görevi

			.assign()
				bir stringin kendisi değil bir substring,data,fill bunları atama operatörüyle yapma şansımız yok
				
				std::string s1{"mustafa aksoy"};
				std::string s2{"necati ergin"};

				char buf[] = "kelami akseki";

				std::string str;

				s1.assign("mustafa); // cstring
				s1.assign(s2,5); // substring
				s1.assign(s2,5,3); // substring
				s1.assign(20,'*'); // fill
				str.assign(buf,buf + 5) // range
		
			operator+=
				std::string str = "murat";
				std::string s = "kan";

				str += s; // muratkan
				str += "oğlu";
				str += '.';
				str += {'x','y','z'}; // initalizer list

				std::cout<<str;
				
				ÇIKTI:
				muratkanoglu.xyz
		
			push_back
				std::string str = "murat";

				for(int i = 0; i < 5; ++i)
				{
					str.push_back('A' + i);

					std::cout<<str<<'\n';
				}

				ÇIKTI:
				muratA  
				muratAB
				muratABC
				muratABCD
				muratABCDE
			
			append(daha karmaşık sona ekleme işlemleri yapılabilir)
				std::string str = "murat";

				str.append(5,'A');
			
			insert(iterator interface'i değilse ekleme yapılacak yerin indeksini ister)
				DİKKAT:iterator interface'i de var indeks interface'i de 

				index interface(*this döndürür)
					std::string str = "murat";

					str.insert(2,"ZEYNEP"); // 2 indeksine zeynep yazısını insert edecek
				
					std::cout<<str;
					ÇIKTI: muZEYNEPrat

				iterator interface
					str.insert(str.begin(),'*';

					std::cout<<str;

					ÇIKTI: *murat	
*/