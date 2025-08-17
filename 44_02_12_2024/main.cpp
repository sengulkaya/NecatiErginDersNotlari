/*

set'in tekrarý yapýldý ve örnekler verildi

	ÖRNEK: find(iteratör döndürüyor)

		int main()
		{
			std::set<int> myset{ 5,9,12,14,15,18 };

			for (auto i : myset)
				std::cout << i << " ";

			int x;

			std::cout << "\nenter the key value: ";
			std::cin >> x;

			std::cout << '\n';


			if (auto iter = myset.find(x); iter == myset.end())
			{
				std::cout << "not found\n";
			}
			else
			{
				std::cout << "found: " << *iter<<'\n';
			}
		}

	ÖRNEK: count(kaç tane ayný öðeden olduðunu döndürür)

		int main()
		{
			std::multiset<int> myset{ 5,5,5,9,12,14,15,18 };

			for (auto i : myset)
				std::cout << i << " ";

			std::cout << '\n';

			if (auto n = myset.count(5)) 
			{
				std::cout << "in set:" << n; // 3
			}
			else {
				std::cout << "not in set\n";
			}
		}


	ÖRNEK: contains(C++20 ile gelen boolean deðer döndürüyor varsa true yoksa false)

		int main()
		{
			std::set<int> myset{ 5,9,12,14,15,18 };

			for (auto i : myset)
				std::cout << i << " ";

			std::cout << '\n';

			if (auto n = myset.contains(14))
			{
				std::cout << "var:" << n; // true
			}
			else {
				std::cout << "yok\n";
			}
		}

	ÖRNEK: 

		int main()
		{
			std::set<std::string> myset{"asim","ceyda","ceylan","handesu","izzet","kasim","olcay","rumeysa","zerrin","ziya"};

			for (auto i : myset)
				std::cout << i << " ";

			std::cout << '\n';

			std::string oldkey, newkey;

			std::cout << "eski ve yeni anahtarlar: ";
			std::cin >> oldkey >> newkey;

			if (auto iter = myset.find(oldkey); iter != myset.end())
			{
				myset.erase(iter);
				myset.insert(newkey);
				std::cout << "anahtar degisti\n";

				for (auto i : myset)
					std::cout << i << " ";
			}
			else {
				std::cout << "bulunamadi\n";
			}
		}

	arka planda implementasyon ikili arama aðacý olduðuna göre node'larý kullanýyor bizim set'imiz node'lardan oluþuyor deðiþtirmek istediðimiz anahtarý 
	set'den sildiðimiz zaman set'de olan öðe destroy oluyor node'da arka planda dynamic olarak allocate edildiði için free edilmiþ oluyor peki madem set kendi düðümlerine hakimse
	o düðümü set'den çýkaralým ama nesneyi destroy etmeyelim düðümdeki öðeyi deðiþtirelim o düðümü insert edilmesi gereken yere insert edelim eðer böyle yaparsak
	gereksiz olan destruction,de-allocation,construction, ve tekrar allocation ve construction'dan kaçýnmýþ oluruz modern C++ öncesinde böyle bir imkan yoktu 
	modern C++'da buna EXTARCT isimli fonksiyon ile önlem alýndý

	extract
		extract bir node handle döndürür bu handle containerdan çýkarýlan öðenin tüm içeriðini saklar (anahtar + deðer) artýk bu öðe containerdan ayrýlýr ama hafýzadan silinmez
		bunu baþka bir kapsayýcýya taþýyabilir ya da üzerinde deðiþiklik yapabiliriz
		
		extract(key)
		extract(iter)

		ÖRNEK:

			int main()
			{
				std::set<std::string> myset{"asim","ceyda","ceylan","handesu","izzet","kasim","olcay","rumeysa","zerrin","ziya"};

				for (auto i : myset)
					std::cout << i << " ";

				std::cout << '\n';

				std::string oldkey, newkey;

				std::cout << "eski ve yeni anahtarlar: ";
				std::cin >> oldkey >> newkey;

				if (auto iter = myset.find(oldkey); iter != myset.end())
				{
					auto handle = myset.extract(iter);
					handle.value() = newkey;
					myset.insert(std::move(handle));
					std::cout << "anahtar degisti\n";

					for (auto i : myset)
						std::cout << i << " ";
				}
				else {
					std::cout << "bulunamadi\n";
				}
			}

		ÖRNEK: hint insert 

			int main()
			{
				std::set<std::string> myset{"asim","ceyda","ceylan","handesu","izzet","kasim","olcay","rumeysa","zerrin","ziya"};
			
				for(auto n = : myset)
					std::cout<<n<<" ";,

					myset.insert(myset.begin(),"abidin"); // hint insert (burda bu konuma ekleme yapmýyor) yani demiþ oluyoruz ki bu konumu baþlangýç noktasý olarak almaný istiyoruz 
															 eðer bu konum gerçekten eklenebilecek bir konumsa ekle ama deðilse burdan hareketle eklenecek en yakýn konumu bulacak
			}

		
	ÖRNEK: transparent function object

		Normalde std::set veya std::map bir öðeyi eklerken veya ararken anahtar tipi ile karþýlaþtýrma yapar eðer farklý türler ile karþýlaþtýrma yapmak istersek 
		(örn. std::string ve const char*) normal comparator çalýþmaz transparent comparator bunu mümkün kýlar farklý ama karþýlaþtýrýlabilir türlerle de karþýlaþtýrma yapabiliriz

		struct Nec
		{
			int ival;
			std::vector<std::string> vec;
			bool operatorz(const Nec&) const;
		};

		bool operator<(const Nec&,int);
		bool operator<(int,const Nec&);

		struct TransparentCmp
		{
			using is_transparent = void; // burada olan fonksiyonun bulunmasý için isim aramayla þöyle bir koþul var bu sýnýfýn is_transparent isimli bir nested type'ý olacak ve bu nested type'ýn 
										   hangi tür olduðunun önemi yok zaten tür kullanýlmayacak karþýlaþtýrma gerektiðinde fonksiyon bulunacak
			template<typename T,typename U>
			bool operator()(T&& lsh, U&& rhs) { return std::forward(lsh) < std::forward(rhs); }
		};

		int main()
		{
			// std::set<Nec> myset;
			// myset.find(12); // geçersiz

			// std::set<Nec,TransparentCmp> myset;
			// myset.find(12); // geçerli çünkü oluþturduðumuz function object type'ýn is_transparent nested type'ý var
		}

		TransparentCmp gibi function object type oluþturmak yerine standart kütüphanenin kendi function object type'ý var LESS<> maliyet açýsýndan büyük bir fark var

			ÖRNEK:

				int main()
				{
					std::set<Nec less<>> myset; // less'in void açýlýmý 

					myset.find(12);

					// bir function object'in transparent function object olup olmadýðýný anlamak için is_transparent type'ý olup olmadaðýna bakmamýz yeterli less<void>::is_transparent 
				}

	ÖRNEK:

		int main()
		{
			std::multiset<int> myset{ 1,4,6,8,9,15,23 };

			for (auto i : myset)
				std::cout << i << " ";

			std::cout << '\n';

			int key;

			std::cout << "enter the key: ";
			std::cin >> key;

			//auto iter_lower = myset.lower_bound(key); // eklemenin yapýlacaðý ilk konum(key’den küçük olmayan (yani >= key) ilk elemaný bulmak eðer key multiset içinde o eleman varsa o elemaný döner
																						  eðer yoksa, ekleme yapýlýrsa nereye koyulacaðýný gösterir)
			//auto iter_upper = myset.upper_bound(key); // eklemenin yapýlacaðý son konum(key’den büyük (> key) ilk elemaný bulmak bu özellikle ayný deðerden birden fazla olduðunda o grubun sonrasýný verir
																						  yani o grubun hemen sonrasýný iþaret eder key deðerine sahip son elemanýn bir sonraki yeri)

			auto[iter_lower, iter_upper] = myset.equal_range(key); // (lower_bound(key) ve upper_bound(key) ikilisini tek seferde döndürür)

			if (iter_lower != myset.end())
				std::cout << "Lower bound: " << *iter_lower << '\n';
			else
				std::cout << "Lower bound: end\n";

			if (iter_upper != myset.end())
				std::cout << "Upper bound: " << *iter_upper << '\n';
			else
				std::cout << "Upper bound: end\n";

		}

	emplace_hint

		diyoruz ki elemaný nereye koyacaðýmý tahmin ettim iþte sana ipucu :D buradan baþla ve eklemeyi yap

		int main() 
		{
			std::set<int> s{1, 3, 5};

			// Normal emplace — STL kendi arar
			s.emplace(4);

			// emplace_hint — biz ipucu veriyoruz
			auto hint = s.find(5); // 5'in yeri belli, 4 buradan önce gelecek
			s.emplace_hint(hint, 2); // ipucu 5'in yeri

			for (int x : s)
				std::cout << x << " "; // 1 2 3 4 5

		}

			emplace = Bul bakalým nereye koyacaksýn :D

			emplace_hint = Bence þu elemanýn yanýna koy :D :D


	merge

		bir set'de olan öðeleri baþka bir set'e katýyor yani bir container’dan diðerine elemanlarý taþýyarak ekler (kopyalamaz kaynaðý container’dan siler)

			int main() 
			{
				std::set<int> s1{1, 3, 5};
				std::set<int> s2{2, 4, 5}; // dikkat: 5 s1'de de var

				s1.merge(s2);

				std::cout << "s1: ";
				for (int x : s1) std::cout << x << " ";
				std::cout << "\ns2: ";
				for (int x : s2) std::cout << x << " ";
			}

			ÇIKTI:

			s1: 1 2 3 4 5
			s2: 5 // 5 zaten s1’de olduðu için s2'den taþýnmadý Diðer elemanlar (2, 4) s1’e taþýndý ve s2’den silindi

	generic programlama tarafýnda containerlardan nested typelarý önem taþýyor

	std::set<int>::value_type // containerda tutulan öðenin türünü verir -> int
	std::set<int>::difference_type
	std::set<int>::reference // containerda tutulan öðeye referans türü -> int&
	std::set<int>::const_reference // -> const int&
	std::set<int>::pointer //  -> int*
	std::set<int>::const_pointer //  -> const int*
	std::set<int>::key_type // anahtarýn türü set'de tutulan öðenin türü -> int
	std::set<int>::key_compare // anahtarý karþýlaþtýrmada kullanýlan tür
	std::set<int>::value_comp // ortak arayüz için value_comp'da var set'de key_comp ile ayný anlama geliyor
	

MAP VE MULTIMAP
	
	map ile set neredeyse ayný aradaki fark map key value pairleri tutuyor yani map'de tutlan öðeler birer pair set'de tutulan öðeler key map'de her key'e karþýlýk gelen bir value var
	map bir key'den bir tane tutuabiliyorken multi_map birden fazla tutabiliyor
	

	ÖRNEK: map için eleman eklemenin farklý yollarý

		int main()
		{
			std::map<int,std::string> mymap;

			std::pair<int,std::string> p1 {45 ,"suleyman" };
			std::pair<int,std::string> p2 {14 ,"naciye" };

			mymap.insert(p1);
			mymap.insert(std::move(p2));
			mymap.insert(std::pair {24,"turgut"});

			mymap.emplace(41,"sevim");

			mymap.insert(std::make_pair(12,"necati"));

			for(const auto&p : mymap)
			{
				std::cout<<p.first<<" " <<p.second<<'\n';
			}
		}
	
		mapler'de structure binding ile dolaþmak daha yaygýn ama vector'ün pair açýlýmý olsaydý yinede dolaþabilirdik

			for(const auto& [no,name] : mymap) 
			{
				std::cout<<no<<" "<< name<<'\n';
			}

			ÖRNEK: 
				
				struct Data
				{
					int x,y,z;
				};

				int main()
				{
					std::vector<Data> myvec
					{
						{5,9,15},
					   {33,48,65},
					   {35,45,89}
					};

					for(auto [a,b,c] : myvec)
					{
						std::cout<<a<<" " <<b <<" " <<c<<'\n';
					}
				}

	ÖRNEK:

		int main()
		{
			std::multimap<int, std::string> mymap;

			std::pair<int, std::string> p1{ 45 ,"suleyman" };
			std::pair<int, std::string> p2{ 14 ,"naciye" };

			mymap.insert(std::move(p1));
			mymap.insert(std::move(p2));
			for (const auto& [no, name] : mymap)
			{
				std::cout << std::format("{:<10} {:<20}\n", no, name);
			}
		}
	
	ÖRNEK:
		
		int main()
		{
			std::map<std::string,int> mymap;

			mymap.insert({ "suleyman",45 });
			mymap.insert({ "naciye",14 });
			mymap.insert({ "necati" ,18 });

			for (auto i : mymap)
				std::cout << i.first << " "<<i.second<<'\n';

			std::cout << '\n';

			std::cout << "aranacak ismi giriniz: ";

			std::string name;
			std::cin >> name;

			if (auto iter = mymap.find(name); iter != mymap.end())
			{
				std::cout << "bulundu " << iter->first << " " << iter->second << '\n';
			}

		}

	ÖRNEK:

		int main()
		{
			std::map<std::string, int> mymap;

			mymap.insert({ "suleyman",45 }); 
			mymap.insert({ "naciye",14 });
			mymap.insert({ "necati" ,18 });

			for (auto i : mymap)
				std::cout << i.first << " " << i.second << '\n';

			std::cout << '\n';

			std::cout << "eski ve yeni anahtarlar: ";

			std::string oldkey, newkey;
			std::cin >> oldkey>>newkey;

			if (auto iter = mymap.find(oldkey); iter != mymap.end())
			{
				auto handle = mymap.extract(iter);
				handle.key() = newkey;

				mymap.insert(std::move(handle));

				std::cout << "degistirildi \n";
			}
			else
				std::cout << "bulunamadi\n";

			for (auto i : mymap)
				std::cout << i.first << " " << i.second << '\n';

		}
	
	DÝKKAT: map sýnýfýnýn köþeli parantez operatör fonksiyonu var çok iþe yarýyor ama çok dikkatli kullanmamýz gerekiyor
	 
		int main()
		{
			std::map<std::string,int> mymap;

			mymap.insert({ "suleyman",45 });
			mymap.insert({ "naciye",14 });
			mymap.insert({ "necati" ,18 });

			for(auto i : mymap)
			std::cout << i.first<<" "<<i.second << " ";
		
			mymap["emre"] = 76; // eðer bu anahtar map'de varsa bu ifade map'de olan öðenin value deðerine eriþtiriyor yani bu value deðerine referans böylece key'i "emre" olanýn value'sunu deðiþtirmiþ oluyoruz
			
			eðer key(emre) map'te mevcut ise o key'e karþýlýk gelen value'ya eriþ ve onu deðiþtir demiþ oluyoruz
			
			eðer "emre" map’te yoksa operator[] yeni bir { "emre", 0 } çifti ekler (yani int için default deðer 0) sonra o value 76 ile deðiþtirilir
		}

		ÖRNEK:

			int main()
			{
				std::map<std::string, int> mymap;

				mymap.insert({ "suleyman",45 });
				mymap.insert({ "naciye",14 });
				mymap.insert({ "necati" ,18 });

				for (auto i : mymap)
					std::cout << i.first<<" "<<i.second << " ";

				std::cout << '\n';

				std::string name;
				int val;

				std::cout << "isim ve numara girin: ";

				std::cin >> name >> val;

				mymap[name] = val; // eðer key varsa o key'in value deðerini deðiþtirmiþ oluyoruz
									  eðer key yoksa yeni bir pair insert edicek ve yeni key ve value deðeri eklenir
				
				for (auto i : mymap)
					std::cout << i.first << i.second << " ";
			}
			 
		ÖRNEK:

			int main()
			{
				std::vector<std::string svec{ "ahmet","emre","kaan","necati" };

				std::map<std::string,int> cmap;

				for(const auto& name : svec)
					++cmap[name]; // diyelim ki döngünün ilk turunda name ahmet þu an cmap boþ olduðuna göre ahmet'i ekleyecek
									(varsa value deðerine eriþtiyordu yoksa ekleyip eklenmiþ öðenin value deðerine eriþtiyordu)

									eklenmiþ öðeyi eklerken value initalize ediyordu(0 deðeri) cmap'e ahmet 0 pair'inin second'a referans yoluyla eriþtirecek o secodn'ý 1 arttýrýp 1 yapmýþ olacaðýz
									ama döngünün her hangi bir tutunda name tekrar ahmet olduðunda ahmet deðeri mapte olduðu için value deðerine eriþtirecek örneðin value deðeri 5 ise 6 olacak
			}

		ÖRNEK:

			int main()
			{
				std::vector<std::string> svec{ "emre","zeynep","ahmet","kaan","kaan","necati" };

				std::map<std::string, int> cmap;


				for (const auto& name : svec)
					++cmap[name]; // eðer name map’te yoksa operator[] yeni bir {name, 0} çifti ekler  sonra ++ ile 0 deðeri 1 olur eðer name(key) zaten varsa mevcut deðeri bir artýrýlýr

				for (const auto& [name, count] : cmap)
				{
					std::cout << name<<" "<<count<<'\n';
				}

				std::vector<std::pair<std::string, int>> vec(cmap.begin(), cmap.end()); // map içindeki tüm (key,value) çiftlerini bir vektöre kopyalýyoruz
			}

		ÖRNEK: subscript( [] ) öperatörü yerine at fonksiyonunu kullanýrsak anahtar olmadýðý zaman exception throw ediyor

			int main()
			{
				std::map<std::string, int> cmap;
       
				cmap["emre"] = 10;
        
				try
				{
            
					cmap.at("emre");  // bulunduðu için exception fýrlatmaz 
					cmap.at("ahmet"); //  exception fýrlatýr     
				}
				catch(const std::exception& ex)
				{
					std::cout<<"exception caught: " << ex.what() << '\n';
				}
			}
*/