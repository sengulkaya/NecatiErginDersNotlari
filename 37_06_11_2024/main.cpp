/*

algoritmalar containerların range'leri üstünde işlem yapan fonksiyon şablonlarıdır

algoritmalarla containerları birbirine bağlayan öğe itratörlerdir

	iteratörlerin bazı nested typeları var generic programlamayı kolaylaştırmak için bir iteratörün ismi value type olan nested type'ı o iteratör konumundaki nesnenin türünün eş ismi

		int main()
		{
			std::vector<int>::iterator::value_type // int
			std::vector<double>::iterator::value_type // double
		
			yani iteratör türünün value type türü iteratörü de-reference ettiğimizde eriştiğimiz nesnesinin türü

			bir iteratör türünün nested value type'ını kullanmakla iteratör türünü tyep_traits isimli sınıf şablonuna template argümanı yaparak onun value type'ını kullanmak aynı şey 
				std::vector<int>::iterator::value_type -> std::iterator_traits<std::vector<int::iterator>::value_type demek aynı şey 

			SORU:peki neden böyle bir şeye ihtiyaç var?
		
				iterator_traits meta function'ı olmasaydı C dizileriyle ilgili ne yapacaktık? C dizilerinde iteratör aslında bir adres
			
					int main()
					{
						int a[10]{}; // int* -> bu konumdaki öğelerin türü -> int

						algoritmada aranacak değerin türünü elde etmek istediğim zaman dizilerde buu kullanamayız çünkü dizinin value type diye bir elemanı yok 
						işte iterator_traits'de dizi türleri için partial specialization var
				
						type_traits<int*>::value_type;
					}
		}

ITERATORLERIN ITERATOR KATEGORİLERİ(görseli inceleyiniz)

	input iterator
	output iterator
	forward iterator
	bidirectional iterator
	random access iterator
	contigous iterator(C++20)

	iteratörlerin iteratör kategorisinin ne olduğunu
		a)compile time'da sınayabiliriz
		b)generic programlama tarafında iteratörün kategorisinin ne olduğuna bağlı olarak kod seçimi yaptırabiliriz

	EMPTY CLASS -> class Myclass{} ; // böyle sınıflar tag olarak kullanılıyor generic programlama tarafında ki bazı teknikler sadece bir kimlik belirten amacımız o sınıf türünden 
										nesne oluşturmak değil çoğunlukla compile time'da o türü kullanmak

	standart kütüphane iteratör kategorisi için bazı empty classları tanımlıyor
		struct input_iterator_tag
		struct output_iterator_tag
		struct forward_iterator_tag
		struct bidirectional_iterator_tag
		struct random_access_iterator_tag

		eğer bir iteratörün iterator kategori isimli nested type'ını kullanırsak örneğin iteratör random_access iteratörse iterator kategori nested type'ı -> random_access_iterator_tag türünden olmak zorunda

			ÖRNEK:
				
				using iter_type = std::vector<int>::iterator;
				using iter_type2 = std::list<int>::iterator;
				using iter_type3 = std::forward_list<int>::iterator;
				using iter_type4 = std::ostream_iterator<int>;

				int main()
				{
					std::cout<<typeid(iter_type::iterator_category).name()<<'\n';  // struct std::random_access_iterator_tag
					std::cout<<typeid(iter_type2::iterator_category).name()<<'\n';  // struct std::bidirectional_iterator_tag
					std::cout<<typeid(iter_type3::iterator_category).name()<<'\n';  // struct std::forward_iterator_tag
					std::cout<<typeid(iter_type4::iterator_category).name()<<'\n';  // struct std::output_iterator_tag
				}

	implementasyonlar iteratörün beklenen minimal iteratör kategorisini çağrıştırması için template parametrelerini ona göre isimlendiriyorlar				 

		ÖRNEK:

			template<typename InIter,typename T = typename std::iterator_traits<InIter>::value_type> // input iteratör ama illa ki input iteratör kategorisi türünden olması gerekmiyor ama 
			typename std::iterator_traits<InIter>::difference_type										minimal input iteratör yeteneğinde olması gerekir yani daha düşük olamaz
			Count(InIter beg,InIter end,const T& val)													yani kısmen input iteratörün yaptığı işleri yapabilmeli
			{
				typename std::iterator_traits<InIter>::difference_type cnt{};

				while(beg != end)
				{
					if(*beg == val)
						++cnt;
					++beg;
				}

				return cnt;
			}

			int main() {
				std::vector<int> vec{ 1, 4, 6, 1, 9, 1, 3 };

				auto c = Count(vec.begin(), vec.end(), 1);
				std::cout << "1 sayisi: " << c << " kez gecti.\n";
			}

		ÖRNEK:

			int main()
			{
				std::sort() // sort fonksiyonu ranIt bekliyor yani fonksiyonun parametresi random access iteratör bekliyor
				std::copy_if() // 1.parametresi minimal input iterator 2.parametresi minimal output iteratör bekliyor
			}
	
	STL'in alogirtmalarının ve container sınıfların çok önemli bir özelliği var

		int main()
		{
			std::vector<int> ivec;

				auto beg = ivec.begin();
				auto end = ivec.end();

			her hangi bir hata yok container'ın boş olması begin ve end fonksiyonlarıyla iteratör alamayacağımız anlamına gelmiyor ama 
			de-reference etmemiz tanımsız davranış ve exception throw etmez -> *beg

			container boşsa begin ve end fonksiyonlarının geri döndürdüğü iteratörler eşitlik karşılaştırmasında eşit çıkacak -> std::cout<<std::boolalpha<<(beg == end);
		
			DİKKAT: container'da öğe olsada olmasada end konumunu de-reference etmek tanımsız davranış ve exception throw etmez
		
				++end; -> tanımsız davranış yani iteratörü her zaman geçersiz bir konuma çıkaracak olan her işlem tanımsız davranış
				--beg; // tanımsız davranış

				end konumu bir kaşılaştırmaya taabi tutulduğu için bir sonraki konumu gösteriyor
		}

	algoritmalara geçtiğimiz range'in iteratörlerinin geçerli iteratör olmasından biz sorumluyuz
		int main()
		{
			std::vector<int> ivec{ 2,3,7,2,5,2,8,2 };

			std::cout << std::count(ivec.begin() + 5, ivec.begin(), 2) << '\n'; // tanımsız davranış
		}
	
	const correctness iteratörlerde de önemli bir yere sahip
		int main()
		{
			 std::vector<int> ivec{ 3,6,7,9,10 };

			 const std::vector<int>::iterator iter = ivec.begin(); // iteratör'ün kendisi sabit ama iteratör'ün gösterdiği değer değiştirilebilir

			++iter; // sentaks hatası

			*iter = 34; // aslında biz bunun illegal olmasını istiyoruz ++iter'in değil bu yüzden const_iterator'ü kullanıyoruz

			 std::vector<int>::const_iterator iter2 = ivec.begin(); // const olursa ++iter illegal olur ama bunu genelde istemeyiz

			++iter2; // geçerli

			*iter2 = 34; // sentaks hatası

			artık sadece access amaçlı kullanabiliriz -> std::cout << *iter2 << '\n';
		
			auto it1 = ivec.begin(); // std::vector<int>::iterator 
			auto it2 = ivec.cbegin();std::vector<int>::const_iterator 
		}

	reverse_iterator

		template <typename InIter>
		void print_range(InIter beg,InIter end)
		{
			while(beg != end)
			{
				std::cout<<*beg++<<' ';
			}

			std::cout<<'\n';
		}
		
		int main()
		{
			std::vector ivec {2,7,9,8,1,3,4,12,56 };

			print_range(ivec.rbegin(),ivec.rend()); // vector<int>::reverse_iterator
		
		}
	
		reverse iterator bir iterator türünden bir nesneyi sarmalıyor ++ operasyonunu --'ye dönüştürüyor
		 
			reverse_iterator // temsili örnek
			{
				operator*()
				{
					return *(iter - 1)
				}

				iterator iter;
			} 

			reverse_iterator<vector<int>::iterator>
			
			sınıfın rbegin fonksiyonunu çağırdığımız zaman rbegin'in geri dönüş değeri olan reverse_iterator end konumunu tutuyor bunu de-reference ettiğimizde
			vectordeki son öğeye erişiyoruz ++ operatörünün operandı yaptığımızda -- işlemi yapıyor

			rend fonksiyonu sarmaladığı iteratör ilk öğenin konumu de-reference edemeyiz peki bu ne demek

				base() fonksiyonu doğrudan sarmaladığı iteratörü döndürüyor	
					
				int main()
				{
					std::vector ivec {2,7,9,8,1,3,4,12,56 };

					auto riter = ivec.rbegin();	// reverse_iterator<vector<int>::iterator>  
					auto iter = riter.base(); // vector<int>::iterator

					*riter demek -> *(riter.base() -1) yazmaya eş değer
					
					std::cout<< (iter == ivec.end()); // true
				}

				böyle bir tasarımın olmasının 2 nedeni var
					1)diziler
						dizinin bittiği yerin adresi valid bir pointerdır ama dizinin ilk elemanından önce olmayan elemanının adresi geçerli bir pointer değildir 

						int main()
						{
							int a[10]{};

							a - 1 // geçersiz

							işte aynı garanti iteratörler içinde veriliyor 
						}
					2)elimizde reverse iteratör range'i olsa sondan başa doğru değilde baştan sonra doğru bir sıralama yapmak istersek

						template <typename InIter>
						void print_range(InIter beg,InIter end)
						{
							while(beg != end)
							{
								std::cout<<"*beg++<<' ';
							}

							std::cout<<'\n';
						}

						int main()
						{
							std::vector ivec {2,7,9,8,1,3,4,12,56 };

							auto riter_beg = ivec.rbegin();
							auto riter.end = ivec.rend();

							print_range(riter_beg,riter_end);
							
							print_range(riter_end.base(),riter_beg.base()); // aynı iteratörleri kullanarak baştan sona doğru dolaşmış oluyoruz 
						}

		MÜLAKAT SORUSU:containerda bulunan aynı öğenin sonucusunu silmek istersek ne yapmalıyız?
			template <typename InIter>
			void print_range(InIter beg, InIter end)
			{
				while (beg != end)
				{
					std::cout << *beg++<<' ';
				}

				std::cout << '\n';
			}


			int main()
			{
				std::vector<int> ivec{ 5,2,7,9,8,1,3,2,4,7 };


				if (auto iter = std::find(ivec.rbegin(), ivec.rend(), 2); iter != ivec.rend())
				{
					ivec.erase(iter.base() - 1); // direkt olarak ivec.erase(iter) diyemiyoruz çünkü erase fonksiyonunun reverse_iterator türünden bir overload'u yok
				}

				print_range(ivec.begin(), ivec.end());
			}
			
			ÇIKTI: 5 2 7 9 8 1 3 4 7 

	con.begin();
	con.end(); -> container::iterator

	con.cbegin();
	con.cend(); -> container::const_iterator

	con.rbegin();
	con.rend(); -> container::reverse_iterator

	con.crbegin();
	con.crend(); -> container::const_reverse_iterator
			

STL'de geri dönüş değeri bool olan callable'lara predicate deniliyor callable bool döndürüyorsa ve 1 tane parametreye sahipse böyle predicatelara -> UNARY PREDICATE deniliyor
eğer 2 paramete istiyorsa -> BINARY PREDICATE deniliyor

	ÖRNEK:

		template<typename InIter, typename UnPred>
		InIter FindIf(InIter beg, InIter end, UnPred f)
		{
			while (beg != end)
			{
				if (f(*beg))
					return beg;

				++beg;
			}

			return end;
		}
		
		class DivPred{
			public:
				
				DivPred(int x) : mx(x){}

				bool operator()(int x)const
				{		
					return x % mx == 0;
				}
			private:
				int mx;
		};

		int main()
		{
			std::vector<int> ivec {15, 14, 17, 19, 21};

			int val;
			std::cout<<"kaca tam bolunen ilk ogeyi bulmak istiyorsun:";
			std::cin>>val;

			if (auto iter = std::find_if(ivec.begin(), ivec.end(), DivPred(val)); iter != ivec.end())
			{
				std::cout << "found " << *iter << " index = " << iter - ivec.begin() << '\n';
			}
			else
			{
				std::cout << "not found" << '\n';
			}
		}

	SORU:DivPred yerine aynı işlemi lambda ile nasıl yaparız?
		
		[val](int x) {return x % val == 0; } // böyle bir lambda expreesion aslında derleyicinin bir sınıf kodu oluşturmasını ve bu ifadeyide oluşturduğu sınıf türünden temporary object 
		PR VALUE expreesion'a dönüştürmesini sağlıyor yani bunu bizim için derleyici yapıyor
		

			if (auto iter = std::find_if(ivec.begin(), ivec.end(), [val](int x) {return x % val == 0; }); iter != ivec.end())
			{
				std::cout << "found " << *iter << " index = " << iter - ivec.begin() << '\n';
			}
			else
			{
				std::cout << "not found" << '\n';
			}

LAMDA EXPRESSION

	bir lambda ifadesi öyle biri ifade ki derleyici bu ifadeyi bir sınıf türünden geçici nesne ifadesine dönüştürüyor lambda ifadesinin value kategorisi PR value expression 

	lamba ifadesi şunları garanti altına alıyor
		1)lambda ifadesi bir ifade
		2)ifade karşılığı derleyici bir class definition oluşturacak derleyicinin oluşturduğu sınıfa CLOSURE TYPE deniliyor
		  derleyici sadece sınıf kodu oluşturmayacak aynı zamanda ifadeyide oluşturduğu sınıf türünden PR value expression'a dönüştürecek ve oluşturulan bu nesneye ->  CLOSURE OBJECT deniliyor

	[] -> lambda ıntroducer deniliyor içine yazılan ifadelere ise CAPTURE deniliyor
	() -> bu parantez derleyiciye yazdırdığımız sınıfın function call operatörünün fonksiyonunun parametre parantezi
	{}

	[]()contexpr{} // parantez ve küme parantezi arasında bazı specifierları yazabiliyoruz
	[]()mutable{} 
	[]()-> int{} // trailing return type

	ÖRNEK:

		class xyz
		{
			public:
				void operator()()const {}
		};

		int main()
		{
			[](){}; // böyle bir lamda ifadesine karşılık olarak derleyici yukarıdaki gibi bir sınıf yazıyor ve aslında bu ifade bizim xyz{} gibi bir geçiçi değişken oluşturmamız demek
			[](){}(); // böyle yazmak ile -> xyz{}() yazmak aynı anlama geliyor
		}
		
	SORU:lambda ifadeleri nerelerde kullanılır?

		1)lambda ifadesini doğrudan fonksiyon çağrı operatörünün operandı yapıp fonksiyonu çağırabiliriz
			auto val  = [](int x) { return x + 5; }(20)

		2)lambda ifadesini bir fonksiyona argüman olarak göndermek
			
			int foo(int x)
			{
				return x;
			}

			int main()
			{

				auto val = foo([](int x) { return x + 5; }(20));

				std::cout << val; // 25
			}

		3)lambda ifadesini fonksiyon şablonuna argüman olarak göndermek
			
			template<typename T>
			void func(T x)
			{
				std::cout<<x(12); // 17
			}

			int main()
			{
				func([](int x) { return x + 5; });

			}
*/