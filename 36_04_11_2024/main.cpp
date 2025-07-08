/*

UNARY FOLD EXPRESSION
	
	ortada binary bir operatör olmasý gerekiyor ve burda kullanýlan parantez öncelik parantezi deðil sentaksýn gerektirdiði parantez
	
	( + ) // parantezin içinde hangi operator üstünde fold expression'ý oluþturuyorsak UNARY FOLD OVER + operator deniliyor

	(... + args) // ellipsis solda olduðu için unary left fold
	(args + ...) // unary right fold

	ikisi arasýnda ki fark associativity(öncelik yönünde)
		a)unary left fold ise -> derleyici böyle bir kod üretiyor ((((p1 + p2) + p3) + p4) + p5)
		b)unary right fold ise -> derleyici böyle bir kod üretiyor (p1 + (p2 + (p3 + (p4 + p5))))

		bu bir / operatörü olsaydý left fold ve right fold'un ürettiði sonuçlar deðiþirdi

		DÝKKAT: unary fold'da && operatörü || operatörü ve , operatörü dýþýnda paket boþ olamaz

			ÖRNEK:

				template <typename ...Ts>
				auto sum(const Ts& ...args)
				{
					return (... + args);
				}

				int main()
				{
					auto val = sum(); 

				}

			ÖRNEK:

				template <typename ...Ts>
				auto sum(const Ts& ...args)
				{
					// return (... && args); // argüman göndermezsek true deðeri elde edilir 
					// return (... || args); // argüman göndermezsek false deðeri elde edilir
					// return (... , args); 

				}

				int main()
				{
					auto val = sum(); // && -> true deðer || -> false deðer

				}

			ÖRNEK:

				template <typename ...Args>
				void print(const Args&... args)
				{
					((std::cout << args << ' ') , ...) // unary right fold 
				}

				int main()
				{
					print(2,5,3.4,"neco"); // derleyici böyle bir koda çeviriyor -> ((std::cout<<2<<' '), ((std::cout<<5<<' '), ((std::cout<<3.4<<' '), (std::cout<<"neco"<<' '))));
				}

BINARY FOLD EXPRESSION

	burda da binary operatör kullanýlmak zorunda

	hangi operatör üstünde binary fold oluþturuyorsak operatörü 2 kez yazýyoruz

	(expression + ... + args) // ellipsis tokeni parametre paketinin sol tarafýnda kaldýðý için binary left fold -> (((((expression + p1) + p2) + p3) + p4) + p5)
	(args + ... + expression) // binary right fold	-> (p1 + (p2 + (p3 + (p4 + (p5 + expression)))))

	ÖRNEK:

		template <typename ...Args>
		constexpr auto sum(Args ...args)
		{
			return (args + ... + 0); //  binary fold expression'da bu sentaks ile paket boþ býrakýlabilir
		}

		int main()
		{
			constexpr auto val = sum(); // paket boþ ama geçerli buda
		}

	ÖRNEK:

		template <typename ...Args>
		auto sum(Args ...args)
		{
			 (std::cout << ... << args); // fonksiyona gelen tüm argümanlarý yazdýrýr
		}

		int main()
		{
			sum(2, 5, 6);
		}

STL(STANDARD TEMPLATE LIBRARY)
		
	STL demekle STANDARD C++ LIBRARY ayný þey demek deðil STL bir akronim C++ standart kütüphanesi tamamen STL demek deðil ama STL C++'ýn standart kütüphanesinin en önemli bileþeni 
	ve büyük çoðunluðunu oluþturuyor STL bir generic library OOP'ye yönelik bir kütüphane deðil 

CONTAINERS

	belirli türden yada türlerden deðerleri bir arada tutan sýnýflarýn oluþturulmasý için kullanýlacak sýnýf þablonlarý(vector,list gibi)

	SORU:sequence container'lar ile associative container'lar ve unordered associative container'lar arasýnda ki fark nedir?

		sequence container'lar öðeleri bir arada tutuyor ve öðelerin bir sýrasý var öðeleri eklediðimiz zaman ekleme zamaný ya da ekleme yeriyle ilgili bir sýra oluþuyor
		yani konum belirterek her hangi bir deðeri insert edebiliyoruz sondan ekleme yapabiliyoruz 

		associative container'lar ekleme ve sýrayla deðil deðerle yapýyor yani container'ýn belirli bir iç sýralamasý var

		unordered associative container'lar da ise sýralama yok deðere göre tutuyor ama temel amaçlarý sýralama iliþkisi olmadan var mý yok mu sorusuna cevap vermek

	sequence container'lar
		std::vector -> dinamik dizi
		std::deque _ dinamik dizilerin dizisi
		std::list -> çifte baðlý liste
		std::forward_list -> tekli baðlý liste
		std::array -> C dizilerinin sarmalayýcýsý
		std::string -> amacý yazý tutmak olan dinamik dizi

	associative container'lar(binary search tree/red black tree)
		std::set -> sýralama iliþkisiyle birbirinden farklý keyleri tutuyor
		std::multiset -> sýralama iliþkisiyle keyleri tutuyor ayný key birden fazla olabilir
		std::map -> key-value deðerlerini tutar key birbirinden farklý olmalýdýr
		std::mutlimap -> key-value deðerlerini tutar ayný key birden fazla olabilir

	unordered associative containers
		std::set std::map gibi aðaç (tree) tabanlý konteynerlerin hash tabanlý versiyonlarýdýr
		
		std::unordered_set -> sýralamasý olmayan birbirinden farklý keyleri tutar O(1) karmaþýklýðýnda
		std::unordered_multiset -> sýralamasý olmayan keyleri tutar ayný key birden fazla olabilir O(1) karmaþýklýðýnda
		std::unordered_ map -> key-value deðerlerini tutar keyler birbirinden farklý keyleri tutar O(1) karmaþýklýðýnda
		std::unordered_ multimap -> key-value deðerlerini tutar ayný key birden fazla olabilir O(1) karmaþýklýðýnda


	STL'in çok önemli bir özelliði var 
		STL'in bütün tasarýmý geniþletilebilirlik üstünede kurulu STL'de bir çok öðe var mesela diðer öðelerle birlikte olmayan bir container kullanýlabilir mi? EVET
		algoritmalar yada örneðin sequence containters içerisinde olmayan 3.parti bir kütüphanenin containterlarýyla da kullanýlabilir yeni containerlar yeni iteratörler oluþturabiliriz 

ITERATORS
	
	containterda tutulan öðelerin konumunu tutarlar

	pointerlarýn daha soyutlanmýþ hali iteratörleride pointer olarak kullanabiliriz ya da pointer-like bir arayüze sahip sýnýf þeklinde kullanabiliriz

	*iter -> iteratörler containerlardan baðýmsýzdýrlar hangi container'in iteratörüyse o containerda deðeri olan öðeye eriþir
	++iter -> bir sonraki öðeninin konumunu tutar
	
	ÖRNEK:

		template<typename Iter>
		void print_range(Iter first, Iter last)
		{
			while (first != last)
			{
				std::cout << *first++ << ' ';
			}
			std::cout << '\n';
		}

		int main()
		{
			std::vector vec{ 4,7,9,1,23,89,12 };
			print_range(vec.begin(), vec.end());

			std::list mylist{ 4,7,9,1,23,89,12 };
			print_range(mylist.begin(), mylist.end());
		}

	STL konteynerlarý söz konusu olduðunda iteratörler konteynerlarýn nested type'ý oluyor

	iteratörlerin interface'inin hangi operasyonlarý saðladýðý ve destek verdiði iteratörün kategorisine baðlýdýr

		1)input iterator
		2)output iterator
		3)forward iterator
		4)bidirectional iterator
		5)random access iterator
		6)contigues iterator(C++20)

		iteratörlerin iteratör kategorisi bu iteratörlerden birine ait olmak zorunda bir iteratörün iteratör kategorisinin hangi kategoride olduðunu compile time'da da 
		meta functionlarla da sýnayabiliyoruz iteratörlerin hangi kategoride olduðu itratörün hangi operasyonlarý saðladýðýný belirtiyor

	RANGE(aralýk)
		STL'de range iki konumdan oluþan bir unit eðer iki konum bir range belirtiyorsa þöyle bir garanti oluþturuyor
		[konum1 konum2] konum1'i sürekli arttýrdýðýmýzda belirli bir noktada konum2'ye eþit olacak yani konum1'den konum2'ye kadar olan 
		öðeleri örneðin yazdýracaðýz ama konum2'ye dokunmayacaðýz demek yani son öðeyi yazdýrmýyoruz

		ÖRNEK:copy algoritmasý(bir range'de ki öðeleri bir konuma bir konumdan baþlayarak kopyalýyor)

			template <typename InIter, typename OutIter>
			OutIter Copy(InIter beg, InIter end, OutIter destbeg)
			{
				while (beg != end)
				{
					*destbeg++ = *beg++;
				}

				return destbeg; // yazma algoritmalarý en son yazdýklarý konumdan bir sonraki konumu döndürüyorlar
			}

			int main()
			{
				std::vector<int> ivec{3,6,8,1,9};
				std::list<int> ilist{9,1,4,6,7,3,6,5};

				Copy(ivec.begin(), ivec.end(), ilist.begin()); // Copy<std::vector<int>::iterator,std::list<int>::iterator>(ivec.begin(), ivec.end(), ilist.begin());

				for (auto i : ilist)
					std::cout << i << " ";
			}

			derleyicinin oluþturduðu instantiation
				std::list<int>::iterator Copy(std::vector<int>::iterator beg,std::vector<int>::iterator end,std::list<int>::iterator destbeg)
				{
					while (beg != end)
					{
						*destbeg++ = *beg++;
					}

					return destbeg;
				}

		ÖRNEK
			
			template <typename InIter, typename T>
			InIter Find(InIter beg, InIter end, const T& val)
			{
				while (beg != end)
				{
					if (*beg == val)
						return beg;

					++beg;
				}

				return end;
			}

			int main()
			{
				std::list<int> ilist{ 9,1,4,6,7,3,6,5 };

				auto iter = Find(ilist.begin(), ilist.end(), 3);

				if (iter != ilist.end())
				{
					std::cout << "bulundu: " << *iter<<'\n';
				}
			}
			
		global olarak begin fonksiyonunu kullanmakla örneðin bir vector'ün begin fonksiyonunu kullanmak arasýnda bir fark yok

			ivec.begin();
			begin(ivec);
*/