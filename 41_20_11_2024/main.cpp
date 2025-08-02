/*

capacity

	capacity vector'ün belleðinde hazýrda bulunan yerin kaç öðeye yettiðini döndürür size'dan büyük ya da eþit olabilir.
		
		int main()
		{
			std::vector<int> ivec{ 3,5,7,8 };

			auto cap = ivec.capacity();

			while (ivec.capacity() < 1'000'000u)
			{
				ivec.push_back(0);

				if (ivec.capacity() != cap)
				{
					std::cout << "reallacation occured size = " << ivec.size() << " cap: " << ivec.capacity() << '\n';
					cap = ivec.capacity();
					(void)getchar();

				}
			}

		}

reserve

	vector'ün kapasitesini artýrmak için kullanýlýr ancak (size) deðiþmez sadece bellek bloðunu rezerve etmiþ oluyoruz

	 çok sayýda push_back yapýlacaksa ve eleman sayýsýný önceden biliyorsak reserve fonksiyonunu çaðýrmak realloc maliyetini düþürür

		 std::vector<int> vec;

		vec.reserve(100); // kapasiteyi 100 yapar ama size hala 0'dýr

		vec.push_back(42); // artýk belleði yeniden ayýrmadan ekleme yapýlabilir


MUTATING OPERATIONS

	container'da deðiþikliðe neden olan container'ýn state'inin deðiþtiren fonksiyonlar

	1)assignment operatörü

		int main()
		{
			std::vector<int> ivec {3,6,8,9,12};
			ivec = {2,4,6,8}; // atama operatör fonksiyonunun initalizer list'in int açýlýmý parametreli fonksiyonu
		}

	2)assign
		 içeriðini tamamen deðiþtirir ve yerine yeni elemanlar koyar
		
		1. assign(count, value)
			Belirtilen sayýda, belirtilen deðerden oluþan öðeleri ekler

			std::vector<int> v;
			v.assign(5, 10); // 5 tane 10 eklenir // v = {10, 10, 10, 10, 10}

		2. assign(begin, end)
			Bir aralýktaki öðeleri vektöre kopyalar

			std::list<int> lst{1, 2, 3, 4};
			std::vector<int> v;

			v.assign(lst.begin(), lst.end()); // v = {1, 2, 3, 4}

		3. assign(initializer_list)
			C++11 ile gelen initializer_list ile atama yapar

			std::vector<std::string> v;
			v.assign({"ali", "veli", "ayþe"}); // v = {"ali", "veli", "ayþe"}

	3)resize

		resize, bir std::vector'ün eleman sayýsýný deðiþtirir vektör küçültülürse: fazla elemanlar silinir 
		
		vektör büyütülürse: yeni elemanlar varsayýlan deðerle veya belirttiðiniz deðerle eklenir.

		1. vec.resize(new_size)
			Yeni elemanlar varsayýlan deðerle (T{}) doldurulur.

			std::vector<int> v{1, 2, 3};
			v.resize(5); // v = {1, 2, 3, 0, 0}  // 2 tane 0 eklendi
		
		2. vec.resize(new_size, value)
			Yeni elemanlar value ile doldurulur.

			std::vector<std::string> v{"a", "b"};
			v.resize(4, "x"); // v = {"a", "b", "x", "x"}

		3. containerda'ki öðeleri silme

			std::vector<int> v{1, 2, 3, 4, 5};
			v.resize(3); // v = {1, 2, 3}  // 4 ve 5 silindi // 0 deðeri geçilirse tüm öðeleri siler

		resize sadece boyutu deðiþtirir kapasiteyi azaltmaz yeni elemanlar default ctor ile oluþturulur T tipi int ise 0 std::string ise "" boþ string olur
		
		Eðer T türünün default ctoru yoksa resize(n) kullanýlamaz.	

	INSERTION FUNCTIONS
	
		1)push_back
		
			elemanlarý en sona ekler

			ekleme fonksiyonlarýnýn en büyük avantajý amortized constant time (O(1) olmasý

			int main() 
			{
				std::vector<int> v;

				v.push_back(10);
				v.push_back(20);
				v.push_back(30);

				for (int x : v) 
				{
					std::cout << x << " "; // Çýktý: 10 20 30
				}
			}	

		2)insert
			belirtilen konuma bir veya birden fazla öðe eklemek için kullanýlýr

			 insert(const_iterator pos, const T& value);             // 1 öðe ekler
			 insert(const_iterator pos, T&& value);                  // 1 öðe (move)
			 insert(const_iterator pos, size_type count, const T& value); // count kadar kopya
			
			template< class InputIt >
			 insert(const_iterator pos, InputIt first, InputIt last);    // range
			 insert(const_iterator pos, std::initializer_list<T> ilist); // init list ile

			ÖRNEK:

				int main()
				{

					std::vector<std::string> svec{ "abdullah","necati","emre","kaan","oguzhan" };

					for (std::string name : svec)
					{
						std::cout << name<<" ";
					}
					std::cout << '\n';

					auto iter = svec.insert(svec.begin() + 1, "kaveh");

					for (std::string name : svec)
					{
						std::cout << name << " ";
					}
					std::cout << '\n';
				}

			3)emplace_back
				
				konteynerin sonuna yeni bir öðe in-place (yerinde) olarak ekler yani nesne bellekte doðrudan oluþturulur kopyalanmaz veya taþýnmaz

					std::vector<std::string> names;

					names.emplace_back("ayþe"); // doðrudan yerinde oluþturulur

			4)erase

				konteynýrlar da ki öðeleri siler ve en son silinen öðeden sonra ki silinmemiþ öðenin konumunu döndürüyor

				container.erase(iterator); // Tek bir öðeyi siler
				container.erase(begin, end); // Belirtilen aralýktaki öðeleri siler

				ÖRNEK:

					int main() {
						std::vector<int> vec{1, 2, 3, 4, 5};

						auto it = std::find(vec.begin(), vec.end(), 3);
						if (it != vec.end()) {
							vec.erase(it);
						}

						for (int v : vec) {
							std::cout << v << " ";
						}
					}
				
				ÖRNEK:

					std::vector<int> vec{1, 2, 3, 4, 5, 6};

					vec.erase(vec.begin(), vec.begin() + 3); // 1, 2, 3 silinir

			5)clear

				konteynýrda bulunan tüm öðeleri siler
					
					int main() 
					{
						std::vector<int> vec{1, 2, 3, 4};

						vec.clear();  // Tüm elemanlar silinir

						// vec = std::vector<int>{}; // geçici nesnenin size'ý 0 olduðu için vec'in de size'ý 0 olur bütün öðeler silinir
						// vec = {}; // ayný iþlemi yapar
					}
			
			6)get_allocator

				sýnýfýn kullandýðý allocator'ý get eder

				int main() 
				{
					std::vector<int> vec{ 1, 2, 3, 4 };

					auto a = vec.get_allocator();

					std::cout << typeid(a).name() << '\n'; // class std::allocator<int>
				}

			7)max_size

				konteynýrýn tutabileceði en fazla eleman sayýsýný verir static üye fonksiyon olmamasýnýn nedeni allocator'a baðlý olmasý

					int main()
					{
						std::vector<int> vec{ 1, 2, 3, 4 };


						std::cout<<vec.max_size(); // 4611686018427387903
					}

----------------------------------

1)sort

	std::sort(begin, end);
	std::sort(begin, end, comparator);

	Belirtilen aralýkta (iterator ile) artan sýrada sýralama yapar

	genellikle QuickSort/HeapSort/InsertionSort hibrit algoritmasý olan Introsort kullanýr
	O(n log n) karmaþýklýðýna sahiptir

		int main()
		{
			std::vector<int> vec{ 5, 2, 8, 1, 4 };

			std::sort(vec.begin(), vec.end());  // Artan sýralama
			// std::sort(vec.begin(), vec.end(),std::greater{});  // büyüktür operatörü kullanýlacaktý ve sýralama büyükten küçüðe doðru yapýlacaktý karþýlaþtýrýlan deðerler küçüktür 
																   ve büyüktür operatörleriyle karþýlaþtýrýlmak zorunda eðer kendi nesnelerimizi karþýlaþtýrýyorsak küçüktür ve büyüktür 
																   operatörleri overload edilmeli

			for (int n : vec)
				std::cout << n << " ";  // Çýktý: 1 2 4 5 8
		}
	
	ÖRNEK:

		class Myclass{};

		int main()
		{
			std::vector<Myclass> vec(100);

			std::sort(vec.begin(),vec.end()); // sentaks hatasý olur çünkü derleyici bu bir fonksiyon þablonu olduðu için fonksiyonu compile time'Da yazýyor ve compile time'da
												 sort algoritmasýndan specialization oluþturduðunda Myclass nesneleri küçüktür yada büyüktür oepratörünün operandý olacak
												 ama Myclass küçüktür veya büyüktür operatörünü overload etmediði için sentaks hatasý
		}

2)stable_sort
	sýralama algoritmasýnýn stable olmasý demek ayný deðere sahip öðeler sýralamadan önceki görece konumlarýný koruyacaklar alogirtmanýn stable olmasýnýn önemi 
	birden fazla sýralama iþleminin yapýlmasý 

	ÖRNEK:

		class Person
		{
		public:
			Person(int age, std::string name) : m_age(age), m_name(std::move(name)) {}

			friend std::ostream& operator<<(std::ostream& os, const Person& p)
			{
				return os << "(" << p.m_age << "," << p.m_name << ")";
			}

			bool operator<(const Person& other) const // yaþa göre sýralamak için < operatörünü overload ettik
			{
				return m_age < other.m_age;
			}

		private:
			int m_age;
			std::string m_name;
		};

		int main()
		{
			std::vector<Person> pvec{
				Person(68, "Abdullah"),
				Person(22, "Abdullah"),
				Person(40, "Ahmet"),
				Person(70, "Agah"),
				Person(22, "Elif"),
				Person(22, "Cemil"),

			};

			std::stable_sort(pvec.begin(), pvec.end());  // yaþa göre küçükten büyüðe sýralandý

			for (const auto& p : pvec)
				std::cout << p << "\n";
		}

3)is_sorted
	bir range'in sýralý olup olmadýðýný sýnamamýzý saðlar
	
	std::is_sorted(beg, end)
	std::is_sorted(beg, end, comp)

	int main()
	{
			std::vector vec{ 7,2,4,9,3,5 };

			std::cout << std::boolalpha<<std::is_sorted(vec.begin(),vec.end()) <<'\n'; // false çünkü vector küçükten büyüðe sýralý deðil

	} 
 
4)is_sorted_until

	sýralamanýn bozulduðu yerin  konumunu döndürüyor 

		int main()
		{

			std::vector vec{ 1,3,4,8,12,7,45,98,13 };

			auto iter = std::is_sorted_until(vec.begin(), vec.end());

			std::cout << std::distance(vec.begin(), iter); // 7'nin indeksini döndürür

		}
*/