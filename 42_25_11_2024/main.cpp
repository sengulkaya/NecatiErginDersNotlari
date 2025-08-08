/*

partial_sort  
	range'in belirli bir bölümünü sıralamak için kullanılır listenin tamamını sıralamak yerine sadece ilk N elemanı sıralı hale getirir geri kalan elemanların sıralı olması gerekmez
	
	std::partial_sort(begin, middle, end);
	std::partial_sort(begin, middle, end, comparator); // middle: sıralanacak ilk N elemanın bitiş noktası (örneğin begin + 3)

	int main()
	{

		std::vector<int> vec{ 9, 1, 5, 3, 7, 2 };
		std::partial_sort(vec.begin(), vec.begin() + 3, vec.end()); // // ilk 3 eleman 1, 2, 3 küçükten büyüğe sıralandı

		for (auto n : vec)
		{
			std::cout << n<<" ";
		}
	}

partial_sort_copy
	n tane öğeyi sıralanmış şekilde başka bir range'e yazacak 


	std::partial_sort_copy(source_begin, source_end, dest_begin, dest_end);
	std::partial_sort_copy(source_begin, source_end, dest_begin, dest_end, comparator);

	int main()
	{

		std::vector<int> vec{ 9, 1, 5, 3, 7, 2 };
		std::vector<int> dest(4); // ilk 4 en küçük elemanı tutmak için

		std::partial_sort_copy(vec.begin(), vec.end(), dest.begin(), dest.end());

		for (auto n : dest)
		{
			std::cout << n << " "; // 1 2 3 5
		}

	}

partititon

	bir range'i bir koşulu sağlayanlar ve sağlamayanlar olarak ikiye ayırıyor şartı sağlayanları başa sağlamayanları sona ekliyor

	std::partition(begin, end, predicate);

		int main() 
		{
			std::vector<int> vec{1, 2, 3, 4, 5, 6};

			std::partition(vec.begin(), vec.end(), [](int x) {
				return x % 2 == 0;}); // çift sayı olanlar en başa alınacak 

			for (int n : vec)
				std::cout << n << " "; // 2 4 6 3 5 1
		
		}

stable_partition

	bir range'i bir koşulu sağlayanlar ve sağlamayanlar olarak ikiye ayırıyor şartı sağlayanları başa sağlamayanları sona ekliyor ve elemanların sırası korunur
	
	std::stable_partition(begin, end, predicate);

partition_copy

	koşulu sağlayanları bir range'e sağlamayanları başka bir range'e kopyalıyor
	
	std::partition_copy(source_begin, source_end,true_dest_begin, false_dest_begin,predicate);
	
		int main()
		{
			std::vector<int> source{ 1, 2, 3, 4, 5, 6 };

			std::vector<int> evens(source.size());
			std::vector<int> odds(source.size());

			auto result = std::partition_copy(
				source.begin(), source.end(),
				evens.begin(), odds.begin(),
				[](int x) { return x % 2 == 0; }
			);

			std::cout << "cift sayilar: ";
			for (auto it = evens.begin(); it != result.first; ++it)
				std::cout << *it << " ";

			std::cout << "\ntek sayilar: ";
			for (auto it = odds.begin(); it != result.second; ++it)
				std::cout << *it << " ";
		}


structure binding(C++17)
	
	birden fazla değeri tek satırda değişkenlere ayırabilir ve okunabilirliği arttırabiliriz

	auto [x,y] // auto olmak zorunda

	int main()
	{

		std::pair<int, std::string> p{42, "C++"};

		auto [num, text] = p; // structured binding
		std::cout << num << " - " << text << "\n";
	}

	ÖRNEK:

		int main() 
		{
			std::map<std::string, int> scores{
				{"Ahmet", 85},
				{"Elif", 90}
			};

			for (const auto& [name, score] : scores) {
				std::cout << name << " => " << score << "\n";
			}
	}

	dizi türleri ve POD türleri için structure binding core sentaks olarak destekleniyor ama sınıf türleri için structure binding'i kullanabilmemiz için
	TUPLE INTERFACE'i sağlaması gerekiyor
		
		a)tuple_size
		b)tuple_element
		c)get

is_partitioned

	elemanların verilen bir koşula göre düzgünce iki gruba ayrılıp ayrılmadığını kontrol eder

	int main()
	{
		std::vector<int> vec{ 1,7,3,4,1,5,8,6,4,0 };

		auto b = std::is_partitioned(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; }); // koşula göre   tek sayılar önde olmalı

		std::cout << std::boolalpha << b<<'\n'; // false // 1,7,3 diye ilerlerken 4 geliyor ve sonra tekrar tek sayı geliyor şartı bozmuş oluyor 

	}

partition_point
	partisyon yapılmış bir range'de partisyon noktasını bulmaya yarıyor ama DİKKAT bunun için range'in partisyon haline gelmesi gerekiyor

	int main()
	{
		std::vector<std::string> svec {"ali","gul","eda","can","hakan","kaveh","mehmetcan","emirhan"};

		auto iter = std::partition_point(svec.begin(),svec.end(), [](const std::string& s) 
		{
			return s.length() == 3; // eğer bu koşulu sağlayan bir öğe yoksa partition_point koşulu sağlamayan ilk öğenin konumu olacak
		});

		std::cout << "idx for partition point = " << std::distance(svec.begin(), iter)<<'\n';

		if (iter != svec.end())
		{
			std::cout << *iter << '\n';
		}
	}

	// range'de bulunan öğelerin değerini bilmeden *iter deseydik tanımsız davranış olabilirdi çünkü bütün öğelerde koşulu sağlayabilir eğer bütün öğeler
	   koşulu sağlarsa partition_point range'in end'i olacak end konumunu de-reference etmiş olacağız ve bu da tanımsız davranış olacak

HEAP ALGORITMALARI

	heap binary tree'lerin özel bir biçimidir genellikle bir öncelik kuyruğu (priority queue) gibi kullanılır en büyük en küçük elemanı kolayca bulmak için kullanılan veri yapısıdır

		Max-Heap: En büyük öğe en üsttedir (root).

		Min-Heap: En küçük öğe en üsttedir.

	Ebeveyn (parent) düğüm her zaman çocuklarından büyük ya da küçük olur

		Max-heap: parent ≥ children

		Min-heap: parent ≤ children

	her zaman en büyük ya da en küçük öğeye O(1) sürede erişilir ekleme ve silme işlemleri O(log n) karmaşıklıktadır heap dizi olarak tutulabilir
		Parent: i

		Left child: 2*i + 1

		Right child: 2*i + 2

	 std::make_heap->	Diziyi heap’e çevirir
	 std::push_heap->	Yeni öğe ekler (dizinin sonuna)
	 std::pop_heap->	En büyük öğeyi çıkarır (sonda kalır)
	 std::is_heap->		Heap düzeni var mı kontrol eder
	 std::sort_heap->	Heap'i sıralı hale getirir
	   
	ÖRNEK:
	
		int main()
		{
			std::vector<int> v{ 5, 9, 8, 23, 7, 12 };

			std::make_heap(v.begin(), v.end()); // max-heap

			std::cout << "Max element: " << v.front() << "\n"; // en büyük eleman en başta -> 23

			v.push_back(6);             // yeni eleman eklendi
			std::push_heap(v.begin(), v.end()); // heap düzenini koru

			std::pop_heap(v.begin(), v.end());  // en büyük öge sona taşındı
			v.pop_back();                       // en sonda bulunan öğeyi çıkardık

			std::sort_heap(v.begin(), v.end()); // sıralı hale getir
			std::cout << "Sorted: ";
			for (int n : v)
				std::cout << n << " ";
		}

DEQUE(double ended queue)

	hem baştan ekleme hem sondan ekleme ve indeksle erişimde amortized contant time'da yapılır
	veriler örneğin vector gibi contiguous şeklinde tutulmuyor ayrı ayrı bloklar şeklinde tutuluyor

	push_back(x)	Sona eleman ekler
	push_front(x)	Başa eleman ekler
	pop_back()		Sondaki elemanı siler
	pop_front()		Baştaki elemanı siler
	front()			İlk elemanı verir
	back()			Son elemanı verir
	size()			Eleman sayısını verir
	clear()			Tüm elemanları siler
		
C++20 ile range base for loop'a ekleme yapıldı
	for'un başında değişken tanımlayabiliriz

	for(int cnt = 0; auto i : deq){}

ITERATOR INVALIDATION(iteratörün geçersiz hale gelmesi)

	 öyle durumlar var ki elimizde bir veri yapısında tutulan öğeye iterator, pointer ya da referans yoluyla bir işlem yapıyoruz ve bu işlemin sonucunda 
	 daha önce o veri yapısındaki öğeninin konumunu tutan bir iteratör ya da o öğeye bir pointer ya da referans artık geçersiz hale geliyor
			1)artık o konumda bir öğe yok 
			2)konum hala geçerli ama o konumda logic olarak olması gereken öğe yok
		
		deque: ekleme işlemi başından yada son olmayan bir yerden yaparsak bütün iteratörler,referanslar,pointerlarr invalis hale geliyor

			int main() 
			{

				std::deque<int> dq{ 1,3,5,7,8,9,2,6 };

				auto iter = dq.begin() + 3;

				int* ptr = &*iter;

				std::cout << *iter<<'\n';
				std::cout << *ptr<<'\n';

				dq.insert(dq.begin() + 1, 777); 

				std::cout << *iter << '\n'; // ekleme işlemi ortadan yapıldığı için iteratörler yada referanslar geçersiz hale geliyor bu da tanımsız davranış oluyor
				std::cout << *ptr << '\n';

			}

			vector için: re-allacation olduğunda ister iteratör,pointer,referans olsun re-allcation'dan önceki iteratörler pointerlar ve referanslar invalid hale gelecek 
			çünkü başka bir bellekte oluşturuluyor
				
				ÖRNEK:
				
					int main() 
					{

						std::vector<int> ivec{ 1,3,5,7,8,9,2,6 };

						auto iter = ivec.begin();

						std::cout << *iter<<'\n';

						std::cout << ivec.capacity() << '\n';

						ivec.push_back(12);

						std::cout << *iter << '\n'; // invalid!!
					}

			erase ve pop_back fonksiyonlardan birini çağırırsak sildiğimiz öğeye iteratör ve referanslar ve ondan sonra ki öğelere referanslar invalid hale geliyor ondan öncekiler 
			bundan etkilenmiyor
				
				ÖRNEK:
					
					int main() 
					{

					std::vector<int> ivec{ 2,6,8,9,3,7 };

					auto iter = ivec.end() -2; // 3

					std::cout << *iter<<'\n';
	
					ivec.erase(ivec.begin() + 2); // 8

					std::cout << *iter << '\n'; // invalid!! bu satır çökmeyebilir ama yanlış veri verebilir veya çöker çünkü iter artık geçersiz bir konumu gösteriyor
												   silinen öğeden itibaren sonraki tüm elemanları sola kaydırır bu yüzden silinen veya ondan sonra gelen tüm iterator / pointer / reference geçersiz olur
					iter = ivec.end() - 2; // tekrar hesaplarsak ve sorun olmaz // *iter artık geçerli konumu gösterir

				}
*/