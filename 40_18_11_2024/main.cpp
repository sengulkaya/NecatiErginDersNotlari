/*

copy
	int main()
	{
		std::vector<int> ivec{ 3,9,7,};
		std::list<int> ilist{ 5,9,11,4,};

		 std::copy(ivec.begin(), ivec.end(), ilist.begin());

		 for (auto x : ilist)
		 {
			 std::cout << x << " "; // vectorde bulunan elemanlar listeye kopyalandý 3,9,7,4
		 }

	}

copy_n
	int main()
	{
		std::vector<int> ivec{ 3,9,7,};
		std::list<int> ilist{ 5,9,11,4,};
	
		std::copy_n(ivec.begin(), ivec.size(), ilist.begin());
		

		 for (auto x : ilist)
		 {
			 std::cout << x << " "; // vectorde bulunan eleman sayýsý kadar tüm elemanlarý listeye kopyalandý 3,9,7
		 }

		std::copy_n(ivec.begin(), ivec.size(), std::back_inserter(ilist)); // listeye sondan ekleme yaptýk


		 for (auto x : ilist)
		 {
			 std::cout << x << " ";  // 5 9 11 4 3 9 7
		 }

	}

copy_if

	int main()
	{
		std::vector<std::string> svec{ "necati","ergin","kaan","aslan"};
		std::vector<std::string> svec2;

		size_t len;

		std::cout << "uzunlugu kac olanlar kopyalansin: ";

		std::cin >> len;

		std::copy_if(svec.begin(), svec.end(), std::back_inserter(svec2), [len](const std::string& s) { return s.length() == len;  });


		std::copy(svec2.begin(), svec2.end(), std::ostream_iterator<std::string>(std::cout, " "));
	}

copy_backward

	int main()
	{
		std::vector<int> ivec{ 3,9,7, };
		std::vector<int> destvec(7); // tane 0 deðeri eklemiþ olduk

		std::copy_backward(ivec.begin(), ivec.end(), destvec.end());

		for (auto x : destvec)
		{
			std::cout << x << " "; // 0 0 0 0 3 9 7
		}

	}

reverse
	int main()
	{
		std::vector<int> ivec{ 3,9,7, };

		std::reverse(ivec.begin(), ivec.end());

		for (auto x : ivec)
		{
			std::cout << x << " "; // 7,9,3
		}

	}
	
reverse_copy
	range'in ters çevirilmiþ halini bir yere kopyalýyor

	int main()
	{
		std::vector<int> ivec{ 3,9,7, };
		std::vector<int> destvec(7);

		std::reverse_copy(ivec.begin(), ivec.end(),destvec.begin());

		for (auto x : destvec)
		{
			std::cout << x << " "; // 7 9 3 0 0 0 0
		}

	}

replace

	int main()
	{
		std::vector<int> ivec{ 3,9,7,3,3 };

		std::replace(ivec.begin(),ivec.end(),3,-1);

		for (auto x : ivec)
		{
			std::cout << x << " "; // -1 9 7 -1 -1
		}

	}

replace_if

	int main()
	{
		std::vector<int> ivec{ 2,4,6,9,15,18 };


		int n = 0;
		std::cout << "kaca bolunenler: ";
		std::cin >> n;

		int val = 0;
		std::cout << "yeni deger: ";
		std::cin >> val;
	
		std::replace_if(ivec.begin(), ivec.end(), [n](int i) {return i % n == 0; },val); // n sayýsýna tam bölünenlerin yerine val için girilen deðer yazýlacak
		 
		for (auto x : ivec)
		{ 
			std::cout << x << " ";
		}

		SENARYO:
			kaca bolunenler: 2
			yeni deger: 1
			1 1 1 9 15 1
	} 

replace_copy

	int main()
	{
		std::vector<int> ivec{ 2,4,2,3,2,18 };
		std::vector<int> destvec(ivec.size());

	
		std::replace_copy(ivec.begin(), ivec.end(),destvec.begin(),2,9); // 2 sayýsýnýn yerine 9 sayýsý yazýlacak

		for (auto x : destvec)
		{ 
			std::cout << x << " "; // 9 4 9 3 9 18
		}

	} 

replace_copy_if

	int main()
	{
		std::vector<int> ivec{ 2,4,2,3,2,18 };
		std::vector<int> destvec(ivec.size());


		int n = 0;
		std::cout << "kaca bolunenler: ";
		std::cin >> n;

		int val = 0;
		std::cout << "yeni deger: ";
		std::cin >> val;

		std::replace_copy_if(ivec.begin(), ivec.end(), destvec.begin(), [n](int i) { return i % n == 0; },val); // n sayýsýna tam bölünenlerin yerine val için girilen deðer yazýlacak

		for (auto x : destvec)
		{ 
			std::cout << x << " "; // 
		}

		SENARYO:
			kaca bolunenler : 2
			yeni deger : 65
			65 65 65 3 65 65

	}

SORU:herhangi bir algoritma bir range'i alýp o range'in sahibi olan container'a ekleme yada silme yapabilir mi? HAYIR ÇÜNKÜ ALGORÝTMALAR ITERATOR PARAMETRESÝNE SAHÝP
	peki nasýl oluyorda remove gibi fonksiyonlar iteratör alýp silme iþlemini yapýyor?

	remove

		logic silme iþlemini uygluyor ve geri dönüþ deðeri olarak aslýnda silinmemiþ öðelerin end konumunu veriyor

		gerçekten silme iþlemi yapmam container'ýn size'ýný deðiþtirmem madem bize silinmemiþler gerekiyor o zaman bu range'i sanki öðeler silinmiþ gibi kullanabiliriz

		ÖRNEK:
			int main()
			{
				std::vector<int> ivec{ 2,4,2,3,2,18 };
				
				std::cout << "size = "<<sizeof(ivec) << '\n';

				auto logic_end_iter = remove(ivec.begin(), ivec.end(), 4);

				std::cout << "size = "<<sizeof(ivec) << '\n'; // size deðiþmiyor

				for (auto x : ivec)
				{
					std::cout << x << " "; //
				}
				std::cout << '\n';

				std::cout<<"silinmemis ogelerin sayisi = "<<std::distance(ivec.begin(), logic_end_iter)<<'\n';
				std::cout<<"silimis ogelerin sayisi = "<<std::distance(logic_end_iter,ivec.end());
			}

		ÖRNEK: amacýmýz sadece o deðerleri container'dan çýkartmaksa ERASE REMOVE IDIOMUNU kullanmalýyýz

			int main()
			{
				std::vector<int> ivec{ 2,4,4,4,2,18 };

				std::cout << "size = " << sizeof(ivec) << '\n';

				ivec.erase(remove(ivec.begin(), ivec.end(), 4),ivec.end()); // gerçek silme iþlemi yaptýk

				for (auto x : ivec)
				{
					std::cout << x << " "; //
				}
				std::cout << '\n';

				std::cout << "size = " << sizeof(ivec) << '\n';


				// global erase fonksiyonuyla ERASE REMOVE IDIOMUNU kullanmamýza gerek yok

					erase(ivec,4); // daha basit þekilde silme iþlemini gerçekleþtiriyoruz
			}

	remove_if

		int main()
		{
			std::vector<std::string> svec{ "necati","ergin","oguzhan","kaveh","mehmetcan","abdullah","veli","rasul" };

			std::cout << "enter the character: ";
			char c;
			std::cin >> c;

			svec.erase(std::remove_if(svec.begin(), svec.end(), [c](const std::string& s) { return s.find(c) != std::string::npos; }),svec.end()); // C++23 -> için sadece s.contains(c) yazmamýz yeterli

			for (auto x : svec)
			{
				std::cout << x << " "; //
			}
		}

		SENARYO:
			enter the character: e 
			oguzhan abdullah rasul // içerisinde e karakteri bulunan stringler silindi

	unique
		ardýþýk ayný öðelerin sayýsýný 1'e indiriyor

		ÖRNEK:1.overload
			int main()
			{
			std::vector<int> ivec{ 12,8,8,8,3,8,2};

			for (auto x : ivec)
			{
				std::cout << x << " "<<'\n';
			}
			
			std::cout << '\n';

			ivec.erase(std::unique(ivec.begin(), ivec.end()),ivec.end());

			for (auto x : ivec)
			{
				std::cout << x << " "<<'\n';
			}

			std::cout << '\n';

		}

		ÖRNEK:2.overload binary predicate alýyor

			int main()
			{
				std::vector<int> ivec{ 12,8,8,8,3,8,2};

				for (auto x : ivec)
				{
					std::cout << x << " ";
				}
				std::cout << '\n';
				auto fpred = [](int x,int y){ return x % 2 == y % 2; }; // ardýþýk olan x'in ve y'nin 2 ye bölümünden kalanlar eþitse bunlarý silecek

				ivec.erase(std::unique(ivec.begin(), ivec.end(),fpred),ivec.end());

				for (auto x : ivec)
				{
					std::cout << x << " ";
				}

				std::cout << '\n';

			}

		MÜLAKAT SORUSU: string'de birden fazla boþluk var ve bu boþluðu 1'e indirmek istiyoruz

			int main()
			{
				std::string s;

				std::cout << "enter a string: ";
				std::getline(std::cin, s);

				const auto fpred = [](char c1, char c2) { return isspace(c1) && isspace(c2); };

				s.erase(std::unique(s.begin(), s.end(), fpred),s.end());

				std::cout << "[" << s << "]\n";

			}

	remove_copy_if

		int main()
		{

			std::vector<std::string> svec{ "necati","ergin","kaan","aslan" };

			std::vector<std::string> destvec;

			for (auto x : svec)
			{
				std::cout << x << " ";
			}
			std::cout << '\n';

			size_t len;

			std::cout << "uzunluk degeri girin: ";
			std::cin >> len;

			auto pred = [len](const std::string& s) { return s.length() >= len; }; 

			std::remove_copy_if(svec.begin(), svec.end(), std::back_inserter(destvec),pred); // uzunluðu len veya daha fazla olanlarý atlayacak (kopyalamayacak) diðerlerini destvec'e ekleyecek

			for (auto x : destvec)
			{
				std::cout << x << " ";
			}
			std::cout << '\n';
		}

STL CONTAINERS

	sequence containers
		vector
		deque
		list
		forward_list
		string
		array
	
	associative containers
		set
		multi_set
		map
		multi_map

	unordered associative containers
		unordered_set
		unordered_multiset
		unordered_map
		unordered_multimap

	SORU: elimizde bir container var ve iki ayrý yolumuz var ama ikiside ayný iþi yapýyor hangisini seçmemiz gerek?
		1)algoritmayý çaðýrmak
		2)container'ýn fonksiyonunu çaðýrmak

		CONTAINER'ýn üye fonksiyonunu seçmemiz gerek çünkü algoritma iteratörle iþlemi yapýyor container'ýn içsel implementasyonuna eriþme imkaný yok
		
		örneðin find algoritmasý == ile sýnýyor ama set'in kendi fonksiyonlarý equivalence kavramýný kullanýyor örneðin -> !(a < b) && !(b < a)  
		
	VECTOR
	
		vector'ün bool açýlýmý içerisinde bool tutan bir vectör deðil bir partial specialization 

		vector C++20 ile birlikte contiguous_iterator kategorisine dahil edilmiþtir bu da vector öðelerinin bellekte ardýþýk (contiguous) 
		þekilde tutulmasýnýn zorunlu olduðu anlamýna gelir yani tüm öðeler tek bir bellek bloðunda yer alýr
		
		referans wrapper
			vector<int &> // geçersiz

			a)container'ýn T& açýlýmýný oluþturamoyoruz ama container'ýn reference wrapper specialization açýlýmýný kullanabiliyoruz

				vector<reference_wrapper<string>>

			b)containerda nesnelerin adresini tutmak
				vector<int *> // bunun yerine daha çok smart pointer sýnýfý kullanýlýyor 
			
		SEQUENCE CONTAINLER'LARIN CTORLARI

			a)default ctor

				ister default initalize ister value initalize edelim bu durumda default ctor çaðýrýlacak
				size'ýn 0 olmasý ve empty fonksiyonun true döndürmesi garanti altýnda

					vector<int> ivec;
					vector<int> ivec{};

			b)size_t parametreli ctor(fill ctor)

				vector<int> ivec(10) // container'ý 10 tane 0 deðeriyle baþlatýr örneðin bool ise false deðeri ile pointer ise nullptr deðeri ile baþlatýr

				containerlarýn size_t parametreli ctoru için containerda tutulan öðenin default constructible olmasý gerekiyor

			c)
				ival = 56;

				vector<int> ivec(10,ival); // 10 adet val deðeri oluþturur

			d)range ctor
				
				baþka bir container'ý baþka bir container ile baþlatamýyoruz ama range ctoru ile bunu yapabiliyoruz

					list<int> mylist;

					vector<int> ivec = mylist; // geçersiz

					list mylist2 {3,5,7,9,2};

					vector<int> ivec {mylist.begin(),mylist.end()}; // geçerli
			
			e)initalizer list ctor

				vector(std::initializer_list<T> init, const Allocator& alloc = Allocator());

				süslü parantezler {} ile verilen bir listeyi kullanarak vector'ü baþlatmamýzý saðlar
				
				std::vector<int> v1(10, 5); // 10 adet 5 içerir
				std::vector<int> v2{10, 5}; // 2 eleman içerir: 10 ve 5

				DÝKKAT: Ýkisi farklý ctor'arý çaðýrýr

					v1 (size_type, T) ctor
					v2 initializer_list ctor

	SORU:vectördeki ilk öðenin adresini kullanmak istiyoruz

		int main()
		{
			std::vector<int>{3,6,9,1,6,6};

			auto p1 = ivec.data();
			auto p2 = &ivec[0];
			auto p3 = &*ivec.begin();
			auto p4  = &ivec.front();
		}

CTAD(CLASS TEMPLATE ARGUMENT DEDUCTION C++17)
	
	vector ivec {3,6,9,2,1}; // CTAD

	int main()
	{
		list mylist{3,6,8,1};

		vector ivec2{ mylist.begin(),mylist.end()};

		for(auto x : ivec2)
		{
			std::cout<<x<<" "; // hata olmasýnýn sebebi iteratör çýkarýmý yapýlmasý
		}
	}

Modern C++ öncesinde taþýma semantiði olmadýðý için containerlar kopyalama semantiðine göre çalýþýyordu containerlarda tutlacak öðeye iliþkin türlerin copy constructible olma
zorunluluðu vardý 

içinde emplace fiili geçen fonksiyonlar container'ýn tutacaðý nesneyi oluþturmak için ne copy ctoru nede move ctoru çaðýrýyorlar kendilerine gönderilen argümanlarý 
perfect forwarding mekanizmasýyla sýnýfýn ctoruna geçiyorlar  
*/