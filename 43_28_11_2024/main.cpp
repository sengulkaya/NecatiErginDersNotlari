/*

LIST

	bazı fonksiyonlar list'in node'lar yoluyla implemente edilen veri yapısı olması dolayısıyla bazı fonksiyonlar nodelar'da ki pointerlara erişerek daha düşük maliyetli işlem sağladıkları
	için sınıfın üye fonksiyonu diğer containerlarda algoritmaları kullanıyoruz örneğin list'in aynı işlemleri yapan kendi fonksiyonları var

	sort 
	reverse
	unique -> art arda gelen tekrar eden elemanları siler
	remove
	remove_if 
	merge -> İiki sıralı listeyi tek bir sıralı listeye birleştirir
	splice -> bir listedeki elemanları başka bir listeye veya aynı listenin başka yerine taşır

		kopyalama yok  O(1) hızında pointer’lar taşınır 3 farklı şekilde kullanımı vardır

		std::list<int> a{1, 2, 3};
		std::list<int> b{4, 5, 6};

		1) Tüm b'yi a'nın başına ekle
			a.splice(a.begin(), b); // a: 4, 5, 6, 1, 2, 3  b: (boş)

		2) b'deki tek bir elemanı a'nın başına ekle
			b = {4, 5, 6};
			a.splice(a.begin(), b, b.begin()); // a: 4, 1, 2, 3  b: 5, 6

		3) Belirli bir aralığı taşı
			b = {4, 5, 6};
			a.splice(a.begin(), b, std::next(b.begin()), b.end()); // a: 5, 6, 4, 1, 2, 3  b: 4

	ÖRNEK: belirli bir konumuda ki öğeyi silmek

		int main() 
		{

			std::list<int> ilist{ 2,6,8,9,3,7 };

			ilist.erase(std::prev(ilist.end(), 2)); // sondan bir önceki öğeyi sildik -> 3

			for (int i : ilist)
			{
				std::cout << i << " ";
			}
		}

	ÖRNEK: sadece başta ve sonda olan öğeler hariç geri kalanlarını silmek

		int main()
		{

			std::list<int> ilist{ 2,6,8,9,3,7 };

			ilist.erase(std::next(ilist.begin()),std::prev(ilist.end()));

			for (int i : ilist)
			{
				std::cout << i << " ";
			}
		}

	ÖRNEK: string'in baştaki ve sondaki değerleri aynıysa o değeri silecek

		int main()
		{
			std::list<std::string> mylist{ "emre","necati","mehmet","efe","kaan","rasul" };

			auto n = mylist.remove_if([](const std::string& s) { return s.front() == s.back(); });

			std::cout<<n<<" eleman silindi\n";

			for(auto n : mylist)
			{
				std::cout<<n<<" ";
			}
		}

	ÖRNEK:

		int main()
		{
			std::list<std::string> males{ "ahmet","murat","erkan","turgut","fazil","emirhan","cengizhan","thomas","richard","robert" };
			std::list<std::string> females{ "nuriye","huriye","fadime","ayla","canan","nazli","eda","bilge" };

			males.sort();
			females.sort();

			std::cout << "erkekler: " << males.size() << " kadinlar : " << females.size() << '\n';

			for (auto n : males)
				std::cout << n << " ";

			for (auto n : females)
				std::cout << n << " ";

			std::cout << '\n';

			males.merge(females);

			std::cout << "erkekler: " << males.size() << " kadinlar: " << females.size() << '\n';

			for (auto n : males)
				std::cout << n << " ";
		}

FORWARD_LIST

	std::forward_list, std::list’in Yani singly linked list verisoyunudur her eleman sadece bir sonrakini gösterir geriye gidemeyiz

	Ekleme / Silme
		push_front(val) → Başa eleman ekler.

		emplace_front(args...) → Başa yerinde nesne oluşturur.

		pop_front() → Baştaki elemanı siler.

	Belirli konumdan sonra
		insert_after(pos, val) → pos’dan sonra ekler.

		emplace_after(pos, args...) → pos’dan sonra yerinde oluşturur.

		erase_after(pos) → pos’dan sonraki elemanı siler.

		erase_after(pos1, pos2) → [pos1+1, pos2) aralığını siler.

	Koşullu silme
		remove(val) → Belirli değere eşit  tüm elemanları siler.

		remove_if(pred) → Koşulu sağlayan tüm elemanları siler.

	Sıralama / Birleştirme / Tekrar Silme
		sort() → Küçükten büyüğe sıralar.

		sort(comp) → Özel karşılaştırma ile sıralar.

		merge(other) → İki sıralı listeyi birleştirir (other boşalır).

		merge(other, comp) → Özel karşılaştırma ile birleştirir.

		unique() → Yan yana tekrar edenleri siler.

		unique(pred) → Özel eşitlik şartıyla yan yana tekrarları siler.

		reverse() → Elemanların sırasını ters çevirir.

	Liste taşıma
		splice_after(pos, other) → other’ın tümünü pos’dan sonra taşır.

		splice_after(pos, other, it) → other’dan tek eleman taşır.

		splice_after(pos, other, before_first, before_last) → Belirli aralığı taşır.

	Yardımcılar
		clear() → Tüm elemanları siler.

		empty() → Boş mu?

		max_size() → Alabileceği maksimum eleman sayısı.

		before_begin() → İlk elemandan önceki konum.

		cbefore_begin() → before_begin’in const versiyonu.

	MÜLAKAT SORUSU:
		int main()
		{
			std::forward_list<std::string> slist{ "ahmet", "kerim", "nihal", "sadullah", "nuri", "ayse" };

			for (auto n : slist)
				std::cout << n << " ";

			std::cout << '\n';

			std::string name;
			std::cout << "kimin bulundugu yere ekleyelim: ";
			std::cin >> name;

			auto iter_prev = slist.before_begin();

			for (; std::next(iter_prev) != slist.end(); ++iter_prev)
			{
				if (*next(iter_prev) == name)
					break;
			}

			slist.insert_after(iter_prev, "muharrem");

			for (auto n : slist)
				std::cout << n << " ";
		}


ASSOCIATIVE CONTAINERS
	set
	multiset
	map
	multimap

	equivalance karşılaştırma ilişkisi var(eşdeğerlik ya da eşitlik anlamına gelir)
		eşitlik karşılştırmasının aslında reloational operatör kullanılarak yapılması

		!(a < b) && !(b < a) // öğelerin kaptaki yerini belirlemek için ya da aradığımız öğenin o değerde olup olmadığını sınamak için kullanırız
		
	SET
		class Comp
		{
		public:
			bool operator()(int x, int y) const
			{
				return std::abs(x) < std::abs(y);
			}
		};

		int main()
		{
			// std::set<int, std::greater<int>> // sıralama büyükten küçüğe olur
			// std::set<int, Comp> // karşılaştırma Comp'a göre yapılır

			// auto fcomp = [](int x, int y) { return std::abs(x) < std::abs(y); };

			// std::set<int, decltype(fcomp)> // C++ 20 öncesinde stateless lambdalar default constructable değil C++20 öncesinde kod yazıyorsak
			   set'in ctoruna fcomp'u geçmemiz gerek // std::set<int, decltype(fcomp)> myset(fcomp);
		}

		strict weak ordering(katı zayıf sıralama)
			sıralama ve karşılaştırma işlemlerinde kullanılan matematiksel bir kavramdır özellikle std::set, std::map, std::sort gibi STL algoritma ve konteynerlerinde karşılaştırma 
			fonksiyonlarının uyması gereken kuralları belirtir
		
			Bir karşılaştırma fonksiyonunun (örneğin, bool cmp(T a, T b)) strict weak ordering kuralını sağlaması gerekir bu kural sıralama algoritmalarının doğru ve tutarlı çalışmasını sağlar

			Kurallar (özellikler):
				
				1)Irrefleksif (Refleksif değil):
					Hiçbir eleman kendisiyle karşılaştırıldığında küçük değildir.
					Yani: cmp(a, a) == false

				2)Asimetrik:
					Eğer cmp(a, b) doğruysa, cmp(b, a) yanlış olmalıdır.
					Yani: Eğer a < b ise, b < a olamaz.

				3)Transitif:
					Eğer cmp(a, b) ve cmp(b, c) doğruysa, cmp(a, c) da doğru olmalıdır.
					Yani: a < b ve b < c ise, a < c

				4)Transitif zayıflık (Transitive Incomparability):
					Eğer a ve b birbirine karşı “küçük değil” ise (yani cmp(a, b) ve cmp(b, a) her ikisi de false ise), ve b ve c de öyleyse, o zaman a ve c de “küçük değil” olmalı
					Yani, eşitlik ve benzer elemanlar arasındaki tutarlılığı sağlar

				bu özellikleri taşımıyorsa UB

			STL konteynerleri ve algoritmaları (örneğin std::set, std::map) elemanları bu kurallara uyan karşılaştırma fonksiyonları ile sıralar
			aksi takdirde sıralama yanlış veya tutarsız olur hatalar ortaya çıkar

			ÖRNEK:  

				struct Compare 
				{
					bool operator()(int a, int b) const {
						return a < b; // std::less gibi, strict weak ordering sağlar // Burada < operatörü strict weak ordering sağlar.

					}
				};

				bool badCompare(int a, int b) {
					return (a % 10) < (b % 10); // mod 10 karşılaştırması bazen tutarsız olabilir strict weak ordering sağlanmaz

				}

	insert(value)	Eleman ekler. Zaten aynı eleman varsa eklemez
	emplace(args...)	Yerinde oluşturma ile eleman ekler (daha verimli)
	erase(value)	Belirtilen değeri siler
	erase(iterator)	İteratörün gösterdiği elemanı siler
	erase(first, last)	Belirtilen aralıktaki elemanları siler
	find(value)	Elemanı bulur, iterator döner. Bulamazsa end() döner
	count(value)	Elemanın sayısını döner (set için 0 veya 1)
	clear()	Tüm elemanları siler
	empty()	Boş mu diye kontrol eder
	size()	Eleman sayısını döner
	max_size()	Tutabileceği maksimum eleman sayısı
	begin() / end()	İlk ve son sonrası iterator
	rbegin() / rend()	Ters sırada iterator
	lower_bound(value)	value’dan küçük olmayan ilk elemanı döner
	upper_bound(value)	value’dan büyük ilk elemanı döner
	equal_range(value)	lower_bound ve upper_bound çiftini döner
	swap(other)	İki set’in elemanlarını takas eder
	

	MÜLAKAT SORUSU: örneğin vektörümüz olacak ve bu vektöre sürekli eleman eklenecek ama sıralaması hiç bozulmayacak

		int main()
		{
			std::vector<std::string> svec;

			for (int i = 0; i < 10; ++i)
			{
				std::cout << "eklenecek isim: ";
				std::string s;
				std::cin >> s;
				auto iter = std::lower_bound(svec.begin(), svec.end(), s);
				svec.insert(iter, s);
			}
				for (auto k : svec)
					std::cout << k << " ";
			std::cout << '\n';
		}
*/