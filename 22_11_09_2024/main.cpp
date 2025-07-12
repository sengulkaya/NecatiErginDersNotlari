/*

mutatorlarda kalmıştık

	insert fonksiyonunun iterator interface'i

		iterator interface
			str.insert(str.begin(),'*';

			std::cout<<str;

			ÇIKTI: *murat

			ÖRNEK:
				std::string s1{"ABCDEF"};
				std::string s2{ "0123456789"};

				s1.insert(s1.begin(),s2.begin(),s2.end());

				std::cout<<s1;

				ÇIKTI: 0123456789ABCDEF

			containerların iterator inerface'i insert fonksiyonları insert edilmiş ilk öğeninin konumunu döndürür
		
			ÖRNEK:
				std::string str{"ABCDEF"};
	
				auto iter = str.insert(str.begin() + 3,'*');

				SORU: bu fonksiyon çağrsında elde ettiğimiz geri dönüş değeri ne? ITERATOR

				SORU: peki bu kimin konumuna iteratör? INSERT EDİLMİŞ ÖĞENİN KONUMUNA İTERATOR(yani en son eklenen öğeninin konumunu döndürür)

				std::cout<<*iter<<'\n'; // * çıktısı alınır
		
				std::cout<<str<<'\n'; // ABC*DEF çıktısı alınır

	resize(reserve fonksiyonuyla karıştırmayalım)
		containerdaki öğe sayısını değiştiriyor hem containerdaki eleman sayısını arttırmak için hemde azaltmak için kullanılır

			std::string s{"nazim mammadli"};

			std::cout<<s.length()<<'\n'; // 14 çıktısı alınır

			s.resize(50); // yazının sonuna 50-14 = 36 tane karakter eklenmesi demek 
				eklenecek karakter containerda tutulan öğenin türünden default construct edilmiş öğenin değeri string sınıfı için bu null karakter demek

			s.resize(50,'\0'); // böyle yazmakla yukardaki yazım arasında hiç bir fark yok çünkü default değeri bu
			s.resize(50,'*');

		resize fonksiyonunu containerdaki öğeleri silmek içinde kullanabiliriz

			std::string s{"nazim mammadli"};

			s.resize(5);

			std::cout<<s<<'\n'; // nazim çıktısı alınır
			
			s.resize(0) // tüm elemanları silmiş oluruz


delete işlemleri
	
	erase fonksiyonu iterator interface'i
		c.erase(iter) // öğeninin konumunu iterator olarak verirsek o iterator konumundaki öğeyi siler
		c.erase(iterbeg,iterend) // rangedeki öğeleri siler iterbeg konumundan başlayıp iterend konumuna kadar tüm öğeleri siler
		
		int main()
		{
		
		ÖRNEK:
			std::string s {"necatiergin"};

			s.erase(s.begin() + 3);

			std::cout<<s<<'\n; // nectiergin

		ÖRNEK:
			s.erase(s.begin(),s.begin() + 6);

			std::cout<<s<<'\n; // ergin

		
		ÖRNEK:
			while(!s.empty())
			{
				std::cout<<s<'\n';
				s.erase(s.end() - 1);
			}

			ÇIKTI:
			necatiergin
			necatiergi
			necatierg
			necatier
			necatie
			necati
			necat
			neca
			nec
			ne
			n

		}
		containerların erase fonksiyonlarının geri dönüş değeri silme işleminden sonra silinmemiş ilk öğenin konumu
			auto iter = s.erase(s.begin());

			std::cout<<"*iter<<'\n'; // e çıktısı alınır
			
	erase fonksiyonu index interface'i
		int main()
		{
			ÖRNEK;
			std::string s {"alihanbozkir"};
			
			s.erase(3,3); // alibozkir çıktısını alırız 3.indeksten başlayıp 3 karakter silmiş olacağız
			std::cout << s << '\n';

			ÖRNEK:
			s.erase(3); // default parametre olarak std::string::npos alıyor 3.indeksten başlayıp tüm yazıyı silecek
			std::cout << s << '\n'; // ali çıktısı alınır

			s.erase(0,std::string::npos); // yazının tamamını silmiş oluruz
			
			s.erase(); // yukardakiyle bu yazım arasında bir fark yok

			s.erase(0,1); // sadece 0 yazarksan default olarak npos aldığı içinde tüm karakterleri siler 0.indeksten başlayıp 1.indekse kadar olan elemanları siler
		
		}

	clear fonksiyonu(containerdaki tüm öğeleri siler)
		std::string s {"alihanbozkir"};
		s.clear ();

	resize fonksiyonu
		std::string s {"alihanbozkir"};
		s.resize(0);

	pop_back fonksiyonu(son elemanı siler)
		std::string s {"rasul mammadov"};

		while(!s.empty()){
			std::cout<<s<<'\n';
			(void)getchar();
			s.pop_back();
		}	

search fonksiyonları
	find(belirli indeksten itibaren aramayı yapar belirli indeks geçilmezse default parametre olarak 0.indeksten arama yapar)
		
		ÖRNEK:
		std::string s {"kahramanmaras"};

		if(auto idx = s.find('a'); idx != std::string::npos)
		{
			std::cout<<"found = " << idx<<'\n';
			s[idx] = '*';
			std::cout<<s<<'\n'; // 1.indekste a karakteri bulunur * olarak değiştirilir
		}

		ÇIKTI:
		found = 1
		k*hramanmaras

	ÖRNEK:
		if (auto idx = s.find('a', 2); idx != std::string::npos) // 2.indeksten itibaren 'a' karakterini aramaya başlar
		{
			std::cout << "found = " << idx << '\n';
			s[idx] = '!';
			std::cout << s << '\n';
		};

		ÇIKTI:
		found = 4
		kahr!manmaras

	rfind(aramaya sondan başlar)
		
		if (auto idx = s.rfind('a'); idx != std::string::npos)
		{
			std::cout << "found = " << idx << '\n';
			s[idx] = '*';
			std::cout << s << '\n';
		};

		found = 11
		kahramanmar.s

	find_first_of(karakterlerin bulunduğu ilk indeksin konumunu döndürür)
		
		std::string s{"murat koralp"};

		std::cout<<s.find_first_of("ptrk")<<'\n'; // r nin indeksini döndürür = 2
	
	find_first_not_of(girilen karakterlerden biri olmayan ilk karakterin indeksini döndürür)
		
		std::string s{"murat koralp"};

		std::cout<<s.find_first_not_of("mkru")<<'\n'; // a nın indeksini döndürür = 3

	find_last_of(karakterlerin bulunduğu son indeksin konumunu döndürür)
				
		std::string s{"murat koralp"};

		std::cout<<s.find_last_of("mska")<<'\n'; // a nın indeksini döndürür = 9
		
	find_last_not_of(girilen karakterlerden biri olmayan son karakterin indeksini döndürür)
			
		std::string s{"murat koralp"};

		std::cout<<s.find_last_not_of("pla")<<'\n'; // r nin indeksini döndürür = 8

	bu fonksiyonların ortak noktası arananı bulursa bulunan konumun indeksini döndürüyor bulunamaması durumunda std::string::npos'unu döndürüyor
		
	starts_with(C++20 ile gelen starts_with bir string’in belirli bir karakter dizisiyle başlayıp başlamadığını kontrol eder)
		
		std::string s{"murat koralp"};
		
		std::cout<<std::boolalpha;

		std::cout<<s.starts_with('m') <<'\n'; // true;
		std::cout<<s.starts_with('t') <<'\n'; // false;
		std::cout<<s.starts_with("murat") <<'\n'; // true;

	ends_with(C++20 ile gelen ends_with bir std::string'in belirli bir karakter dizisiyle bitip bitmediğini kontrol eder)

		std::string s{"murat koralp"};
		
		std::cout<<std::boolalpha;

		std::cout<<s.starts_with('p') <<'\n'; // true;
		std::cout<<s.starts_with('t') <<'\n'; // false;
		std::cout<<s.starts_with("koralp") <<'\n'; // true;

	contains(C++23 ile gelen contains bir std::string içinde belirli bir karakterin veya substring'in bulunup bulunmadığını kontrol eder)

		std::string s{"murat koralp"};
		
		std::cout<<std::boolalpha;

		std::cout<<s.containt('k')<<'\n'; // true
		std::cout<<s.containt("koral")<<'\n'; // true
			
stringleri toplayabiliriz

	std::string s1{ "murat " };
	std::string s2{ "han" };

	auto s = s1 + s2 + " alp " + 'k' + "an";

	std::cout << s << '\n'; // murat han alp kan
			
literal operator functions
	"oguzhan"s // burada ismi operator s olan bir fonksiyonun çağırılmasını sağlıyoruz böylelikle bir string nesnesi elde ediyoruz const char* değil 
	 
algoritmalar üzerinde stringler

	#include <algorithm>

	int main()
	{
		std::string s;

		std::cout << "bir yazi girin: ";
		getline(std::cin,s);

		std::cout << s << '\n';

		sort(s.begin(), s.end());
		// sort(s.rbegin(), s.rend()); // tersten sıralamak istersek

		reverse(s.begin(), s.end()); // yazıyı tersine çevirmek için

		std::cout << s << '\n';

	}

remove erase idiom
	
	std::string s{ "adanali kahraman pasa" };

	std::cout << s << '\n';

	s.erase(remove(s.begin(), s.end(), 'a'), s.end()); // tüm a karakterlerini siler
	
	// member erase fonksiyonunu geri dönüş değeri olarak end iterator'ünü döner yani artık geçerli olmayan elemanlardan sonraki yeni bitiş noktası

	std::cout << s << '\n';
		
	auto n = erase(s,'a'); // global erase fonksiyonun geri dönüş değeri silinen öğe sayısını döndürür
	
	std::cout<<n<< " tane a karakteri silindi\n";
			
	remove_if
	
		std::string s{ "ayhan3456oguzhan87234necati7124fatih7235" };

		std::cout << s << '\n';

		s.erase(remove_if(s.begin(), s.end(), [](char c) {return isdigit(c); }), s.end()); // s nesnesinde bulunan rakamları silmiş oluruz

		std::cout << s << '\n';
	
		ÇIKTI: ayhanoguzhannecatifatih

	erase_if
		
		std::string s{ "ayhan3456oguzhan87234necati7124fatih7235" };

		std::cout << s << '\n';

		auto n = erase_if(s, [](char c) {return isdigit(c); }); // s nesnesinde bulunan rakamları global erase_if fonksiyonuyla silmiş oluruz

		std::cout << s << '\n';
		std::cout << n << '\n'; // kaç tane öğe silindiğini döndürür


string sınıfının diğer member functionları(c_str,data)
	
	c_str(string bir yazıyı null terminated byte stream olarak kullanmamızı sağlar)
		
		std::string str{"necati ergin"};

		auto p = str.c_str(); // elde edilen adres const char* sadece okuma amaçlı kullanılır 
		yazı üstünde değişiklik yaptıktan sonra aynı pointerı yazıya erişmek için kullanmamalıyız çünkü undefined behaviour olur

		str = "necati"; // str'nin içeriği değişiyor (assign edildiği için eski bellek muhtemelen serbest bırakılır)

		std::cout << *p; // undefined behavior artık p geçersiz bir belleği işaret ediyor
			
		bir çok yerde string nesnesimizin tutuğuu yazıyı null terminated byte stream olarak kullanmamız gerekiyor bunun önemli bir nedeni var
			
			1)c apileri
				string nesnesinden const char* türüne doğrudan dönüşüm olmadığı için fonksiyona argüman olarak doğrudan string nesnesini geçemiyoruz

				std::string str{"necati ergin"};
				
				auto s = strlen(str.c_str());
	
	data
		modern C++dan önce data fonksiyonu null terminated byte stream döndürmüyordu modern C++ ile geri dönüş değeri null terminated byte stream oldu

		c_str ve data fonksiyonun farkı data fonksiyonunun geri dönüş değeri char * ve const char* parametreli fonksiyonlarının olması fonksiyonu const olmayan nesnelerde değiştirilebilir 
		veri erişimi sağlamak için kullanılır günümüzde c_str ve data fonksiyonu arasında hiç bir fark yok çünkü ikiside null terminated byte stream döndürüyor c_str sadece okuma amaçlıdır
		data const ve non-const erişim sağlar.


C++17 ve 20 standartlarıyla generic progralama tarafı için bazı fonksiyonların member function olmasının yanı sıra global function olarakta karşılıkları geldi

	1)size
		std::string str{"necati ergin"};

		std::size(str);
	2)ssize(işaretli tam sayı olarak size'ı döndürür)

		std::ssize(str);
		
	3)data
		data(str);

	4)empty
		empty(str);

	5)begin,end
		begin(str);
		end(str);

		SORU:modern C++ ile global olarak begin ve end fonksiyonlarının eklenmesinin amacı nedir? C DİZİLERİ

			int ar[] = { 8,7,3,6,1,9,2,4 };

			std::sort(std::begin(ar),std::end(ar)); // dizinin tüm range'ini elde edip sıralama yapabiliyoruz

			for (int i : ar)
				std::cout << i;

swap(yazıları swap etmek yerine pointerları swap etmemizi sağlar ve maliyeti düşürmüş oluruz)
	std::string s1(10'000,'a');
	std::string s2(20'000,'x');

	swap(s1,s2);

	1)modern C++ öncesi move semantiği olmadığı için swap fonksiyonu kopyalama yapıyordu
		
	2)moved from state
		
		template<typename T>
		void swap(T& x,T& y)
		{
			T temp = std::move(x); // x burada moved from state durumunda ama aşağıda tekrar atama yapıyoruz her hangi bir tanımsız davranış yok 
			x = std::move(y);
			y = std::move(temp);
		}

shrink_to_fit(bir container'ın capacity'sini, mevcut size’ına düşürmeye yönelik bir istekte bulunan fonksiyondur)
		
		std::string s(400'000, 'A');

		std::cout << "s.size() = " << s.size() << " s.cap = " << s.capacity() << '\n';

		s.erase(50); // 50.indenskten itibaren tüm elemanları siliyoruz

		std::cout << "s.size() = " << s.size() << " s.cap = " << s.capacity() << '\n'; // burda s nesnesinin kapasitesi düşmüyor sadece size'ı düşüyor

		s.shrink_to_fit(); // standart bu fonksiyonu bağlayıcı olmayan bir talep olarak dökümante etsede derleyicilerin hemen hepsi kapasiteyi düşürüyor çünkü standarta göre 
							  kapasitenin düşmesi garanti altında değil

		std::cout << "s.size() = " << s.size() << " s.cap = " << s.capacity() << '\n'; // burda s nesnesinin kapasitesi size'a uygun şekilde düşmüş oluyor

		ÇIKTI:

		s.size() = 400000 s.cap = 400015
		s.size() = 50 s.cap = 400015
		s.size() = 50 s.cap = 63

replace(belirli bir karakter aralığını başka bir içerikle değiştirmek için kullanılır)

	std::string str = "Merhaba dünya";
	str.replace(8, 5, "evren"); // 	8.indeksten başla, 5 karakteri sil, yerine "evren" koy.
	std::cout << str; // Merhaba evren
		
substr(bir string’in belirli bir kısmını elde etmek için kullanılır)
			
	std::string s = "Merhaba Dünya";

	std::string s1 = s.substr(0, 7);     // "Merhaba" 0.indeksten başla 7 karakter al 
	std::string s2 = s.substr(8);        // "Dünya" (8. indexten sona kadar)
	std::string s3 = s.substr(3, 4);     // "haba" // 3.indeksten başka 4 karakter al
			
string wiev sınıfı(C++17 ile gelen bir karakter dizisine sahip olmadan erişim sağlayan std::string, C tarzı diziler (const char*) ya da sabit string sabitleri ("hello") 
gibi karakter dizilerine kopyalama yapmadan erişmek ve üzerinde okuma işlemleri gerçekleştirmektir)

	veriyi değiştirmez sadece okuma yapar 
	
	dizinin başlangıç adresini ve uzunluğunu tutar

	#include <string_view>

	void print(std::string_view sv) {
		std::cout << "Veri: " << sv << '\n';
	}

	int main() {
		std::string str = "Necati";
		// print(str);      // std::string -> implicit conversion to std::string_view
		// print("Ergin");  // const char* -> implicit conversion to std::string_view

		std::string_view view = str.substr(0, 3);  // "Nec"
		
		print(view); 
	}
			
getline(bir satırı tamamen okuyan ve genellikle `std::string` ile birlikte kullanılan (input) fonksiyonudur)

	cin >> gibi operatörler boşluk veya tab gibi ayırıcı karakterlerde dururken, `getline` yeni satır karakterine kadar olan her şeyi okur.

	std::getline(std::istream& is, std::string& str);
	std::getline(std::istream& is, std::string& str, char delim);

	* `is`: Girdi akışı (`std::cin`, `std::ifstream`, vs.)
	* `str`: Okunan satırın yazılacağı `std::string` nesnesi.
	* `delim` *(opsiyonel)*: Satır sonunu belirleyen karakter. Varsayılan olarak `'\n'` (yeni satır).

	int main() {
		std::string name;
    
		std::cout << "Adınızı girin: ";
		std::getline(std::cin, name); // kullanıcı “Ali Veli” yazarsa, `getline` tüm satırı okur. `cin >> name` kullansaydık boşluk olduğu için sadece “Ali” okunurdu.
    
		std::cout << "Merhaba " << name << '\n';
	}

	std::string s;
	std::getline(std::cin, s, '.');  // Noktaya kadar okur

	getline'dan önce cin >> kullanıldıysa, arada kalan `\n` karakteri getline tarafından okunabilir. Bu durumda `getline`'in boş okuma yapmasını engellemek için 
	`std::cin.ignore()` kullanılır:

	int age;
	std::cin >> age;
	std::cin.ignore(); // \n karakterini temizle
	std::getline(std::cin, name);
		
		
sayısal dönüşümler(modern C++ ile eklendi yazıyı tam sayıya dönüştürmemize yada tam sayıyı bir yazıya dönüştürmemize yarar)
	
	std::string s = "23ahmet.jpg";
	size_t idx;
	auto y = std::stoi(s,&idx); // default olarak 10'luk sistemde dönüşümü yapıyor

	std::cout << y<<'\n'; // 23 çıktısı alınır
	std::cout << idx; // kaç karakterin dönüştürüldüğünü yazdırıyoruz -> 2


	to_string(sayısal değerleri std::string türüne dönüştürmek için kullanılır)
		
	int main()
	{
		int ival = 762345;

		auto file_name = "necati" + std::to_string(ival) + ".jpg";

		std::cout << file_name; // necati762345.jpg çıktısı alınır
	}	

copy(bazen bir stringin tuttuğu yazıyı cstring olarak elde etmek yerine bir yere kopyalamak istiyoruz)

	std::string name{ "fatih akgul" };

	char buf[100];

	auto n = name.copy(buf, 100, 0); // 0.indeksten başlayıp tüm stringi kopyalıyoruz
	buf[n] = '\0'; // null karakteri elle koyuyoruz (copy fonksiyonu koymaz) null karakter koymadan kullanırsak undefined behaviour

	std::cout << n<<'\n'; // fonksiyonun geri dönüş değeri kopyalanmış öğe sayısı olduğu için 11 çıktısı alınır

	puts(buf); // fatih akgul çıktısı alınır
*/