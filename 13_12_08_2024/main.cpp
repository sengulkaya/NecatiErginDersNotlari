/*

TEMPORARY OBJECT
	bir geçici nesne ismi temp olan bir nesne deðil hoca böyle düþününler için diyor bunu
		int temp;

	geçici nesneler PR value expressiondýr ve C++ dilinin böyle nesnelere iliþkin önemli kurallarý var hoca bahsedecek

	class Myclass{};

	void func(Myclass);

	int main()
	{
		Myclass{}; //böyle bir ifadeyle ne yapabiliriz
		
				1)bir baþka myclass nesnesine ilk deðer vericek ifade olarak kullanabiliriz
		
				auto m = Myclass{};

				2)bir fonksiyonun parametresine geçici nesne olarak geçirebiliriz
					func(Myclass{});
	}	

	isimlendirilmemiþ nesneler iþimizi görüyorsa nesneleri isimlendirmeyin çünkü bunlarý böyle kullanmanýn avantajlarý var 

	referanslar söz konusu olduðu zaman geçici nesne ifadesi PR value expression olduðu için baðlancak referansýn const L value & yada
	R value && olmasý gerekiyor

		const Myclass& = Myclass{};
		Myclass&& = Myclass{};

	TEMPORARY OBJECT saðladýðý avantajlar
		1)öyle durumlar var ki bir fonksiyon çaðrýsýnda kullanacaðýmýz argümana ihtiyacýmýz var ama amacýmýz sadece orda kullanýlmasý örneðin
		func fonksiyonuna myclass sýnýfý türünden bir argüman göndereceðiz ama oluþturduðumuz argümanýn deðeri zaten belliyse
			Myclass{3,5}; böyle bir myclass nesnesini argüman olarak göndermek istiyorsak 

			Myclass m;
			func(m)  böylede yazabiliriz ama böyle yazarsak
				
				1)isim alanýna bir isim enjekte etmiþ oluyoruz
				2)kodu okuyan kiþiye buradaki myclass nesnesinin fonksiyon çaðrýsýndan sonra tekrar kullanýlacaðý algýsýný yaratýyoruz
				3)myclass nesnesinin hayatý otomatik ömürlü bir deðiþken olduðu için tanýmlandýðý bloðun sonuna kadar geçerli olacak

				oysa bizim sadece bu iþ için bu nesneye ihtiyacýmýz varsa iþini yaptýktan sonra hala hayatýnýn devam etmesi  
				özellikle bu nesne bir takým kaynaklar kullanýyorsa bu bizim istediðimiz bir þey deðil bu ayný zamanda bir SCOPE LEAKAGE

		eðer böyle kullanmak yerine temporary object kullansaydýk önce isim alanýna gereksiz olarak bir isim enjekte etmemiþ olacaktýk ayný zamanda geçici nesnelerin hayata veda etmesi otomatik ömürlü yerel nesneler gibi deðil
		geçici nesneler içlerinde bulunduklarý full expressionýn yürütülmesi sonucunda hayata veda ediyorlar

		C++17 standartýndan önce þimdiye kadar kullandýðýmýz terimlerde bir yanlýþlýk yok ama C++17 ile birlikte kullandýðýmýzda terimlerde daha dikkatli olmak gerekiyor
			Myclass{3,5}; // bu bir nesne mi ? HAYIR 
				C++17 standartý ile PR value expression artýk doðrudan bir nesne deðil bir nesnenin oluþturulmasý için bir reçete bir talimat gibi yani yeri geldiðinde bu ifadeden bir nesne yaratýlabilir
				bunun teknik olarak karþýlýðý TEMPORARY MATERIALIZATION
			
		2)doðrudan bir nesne olmamasý ve bazý senaryolarda COPY ELISION dediðimiz sonucu doðurmasý
			
			MANDATORY COPY ELISION
				C++ dilinde çok önemli bir durum yazdýðýmýz kodun verimini %100 arttýrabilecek bir durum COPY ELISION demek kopyalamanýn yapýlmamasý demek
				modern c++ öncesinde derleyiciler yine COPY ELISION yapýyorlardý fakat derleyicinin gerçekleþtirdikleri COPY ELISION koda baktýðmýzda bir kopyalama var ama run timeda bir
				kopyalama yapýlmýyor bu derleyicinin gerçekleþtirdiði bir optimizasyondu þimdi bahsedeceðimiz senaryolarda zaten artýk dilin kuralý gereði COPY ELISION garanti altýnda yani kopyalama yapýlmayacak  
				
				1)geçici nesne ifadesini baþka bir geçici nesne ifadesini oluþturken argüman olarak kullanmak
					class Mylcass
					{
						public:
							Myclass()
							{
								std::cout<<"default ctor\n";
							}

							Myclass(const Myclass&)
							{
								std::cout<<"copy ctor\n";
							}

							~Myclass()
							{
								std::cout<<"destructor \n";
							}
					};

					int main()
					{
						Myclass m = Myclass{}; 
					}

					ÇIKTI:
					default ctor
					destructor

				2)bir temporary object ile parametresi sýnýf türünden olan fonksiyona çaðrý yapmak
					int main()
					{
						func(Myclass{}) // c++17 öncesi önce default ctor çaðýrýlacaktý sonra copy ctor çaðýrýlacaktý ve derleyici bunu optimize edecekti
					}
					
					ÇIKTI:
					default ctor
					destructor
					
				bu çok önemli çünkü bazý sýnýf nesnelerinin inþasý çok ciddi bir maliyet biz doðrudan kopyalama maliyetinden kurtulmuþ oluyoruz yani COPY ELISION bize
				büyük bir verimlilik saðlýyor vector yada string gibi sýnýflarýmýz olsaydý yine temporary object kullansaydýk bu sefer de move ctor'un çaðýrýlma maliyetinden kurtulmuþ olacaktýk
				sýnýfýn ne olduðuna baðlý olarak move operation copy operationdan daha az maliyetli olabilir ama copy elision bunlarýn hepsinden daha verimli çünkü 1 kere nesne oluþturuyoruz

				buda bize þöyle bir olanak saðlýyor copy ctoru ve move ctoru olmayan yada delete edilmiþ sýnýflar için hala bu þekilde fonksiyon çaðýrýlarý yapabiliriz

				3)bir fonksiuonun geri dönüþ deðerinin bir sýnýf türünden olmasý ve fonksiyonun return ifadesinin sýnýf türünden bir PR value expression olmasý
				(buna karþýlýk gelen terim Unnamed Return value optimization(URVO)) isimlendirilmemiþ geri dönüþ optimizasyonu

					C++17 öncesi URVO bir compiler optimizationdý ama artýk bir compiler optimization deðil dilin kuralý
					Myclass func()
					{
						return Myclass{};
					}

					int main()
					{
						Myclass m = func(); // C++17 öncesi önce default ctor çaðýrýlacak sonra copy ctor çaðýrýlacak ve derleyici bunu optimize edecekti
											   C++17 sonrasý ise sadece default ctor çaðýrýlacak
					}

				4)Named return value optimization(NRVO) isimlendirilmiþ geri dönüþ deðer optimizasyonu
					copy elision'ýn bir baþka biçimidir c++ dili tarafýndan garanti altýnda deðildir mandatory deðildir(yani zorunlu deðil)bu compiler optimizationdur 
					dilin direkt olarak kuralý deðildir ve NRVO kod verimini arttýran bir durumdur
					
					Myclass func()
					{
						Myclass x;

						return x;
					}

					int main()
					{
						Myclass m = func(); // bu durumda func fonksiyonu çaðýrýldýðýnda func fonksiyonun içindeki x nesnesi için default ctor çaðýrýlacak fonksiyon çaðýrýsý tamamlandýðýnda fonksiyonun geri dönüþ deðerini 
						m ismini verdiðimiz nesneye kopyaladðýmýzda 1 yada 2 kez copy ctor çaðýrýlacak 1 yada 2 kez dememimizin sebebi aslýnda böyle durumda derleyici fonksiyonun geri dönüþ deðerini 
						bellekte bir yere yazýyor ordada bir nesne oluþuyor o nesnede bir temporary object ve o nesne copy ctor ile hayata getiriliyor ama o nesnedende yine kopyalama yoluyla m isimli nesneyi oluþturuyoruz

						bu optimizasyonu yapmak garanti deðildir derleyiciye baðlýdýr yani derleyici optimizasyon yaparsa copy ctor yada move ctor çaðýrýlmaz 
					}
			
			TEMPORARY MATERIALIZATION OLAN DURUMLAR
			1)referansa baðlama
				Myclass &&r = Myclass{};
				const Myclass& r = Myclass{};

			2)ifadeden bir nesne oluþturursak
				Myclass m = Myclasss{3,5}; // burada dikkat acaba derleyici burada önce iki int parametreli ctoru çaðýrýp geçici nesneyi oluþturup ondan sonra bu geçici nesneden hareketle belki move yada copy ctoru çaðýrýp
				m isimli nesneyi mi oluþturuacak? HAYIR bu kodda ctor yada destructorýn çaðýrýldýðýný gösteren statementlar koysaydýk sadece bir kez ctorun çaðýrýldýðýný görecektik buna C++17 de COPY ELISION deniliyor
				yani bir PR value expressionýn materyalize olmadan kullanýlmasý durumu ne demek?
					class Mylcass
					{
						public:
							Myclass()
							{
								std::cout<<"default ctor\n";
							}

							Myclass(const Myclass&)
							{
								std::cout<<"copy ctor\n";
							}

							~Myclass()
							{
								std::cout<<"destructor \n";
							}
					};

					int main()
					{
						Myclass m = Myclass{}; // C++17 öncesi copy ctor çaðýrýlýrdý ve copy ctor delete edilmiþse yada private durumdaysa sentaks hatasý olur
					}

					ÇIKTI:
					default ctor
					destructor
					
					C++17 standartýndan önce bu tür durumlar compiler'ýn yaptýðý optimizasyon olarak ele alýnýyordu yani C++17 standartýný desteklemiyorsa
					1 defadan fazla default ctor çaðýrýlmýyor 1 kere destructor çaðýrýlýyor gibi bu derleyicinin yaptýðý bir optimizasyon fakat C++17 ile birlikte
					bu PR value expression olan geçici nesnelerin nesnenin kendisi deðilde nesne oluþturmaya yönelik bir reçete olmasý C++17 standartýnda MANDOTARY COPY ELISION terimi
					ama bu terim pek doðru bulunmuyor çünkü bir nesne yok ki kopyalansýn nesne ne zaman oluþacak? TEMPORAY MATERIAZLIZATION gerekeceði zaman oluþacak
					dolayýsýyla PR value expressionýn doðrudan bir nesne olarak kabul edilmemesi hedefini bulduðunda bir nesne haline gelmesi kuralý COPY CTOR'un çaðýrýlmayayacaðý durumlarda 
					delete edilmesi yada private olmasý durumunda hala bir sentaks hatasý oluþmayacak çünkü copy ctor burada çaðýrýlmýyor
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONVERSION CONSTRUCTOR(DÖNÜÞTÜREN KURUCU ÝÞLEV)
	sýnýflarýn özellikle tek parametreli ctorlarý nesneyi oluþturmanýn dýþýnda ilginç bir niteliðe daha sahipler
	
		class Myclass
		{
			public:
				Myclass()
				{
					std::cout<<"default ctor this = " << this<<'\n';
				}
				~Myclass()
				{
					std::cout<<"destructor this = " << this<<'\n';
				}
				Myclass(int x) // bu ctor ayný zamanda parametresi olan türden bu sýnýf türüne örtülü bir dönüþüm gerçekleþtirmek içinde kullanýlýyor 
				{
					std::cout<<"Myclass(int x) x = " << x <<'\n';	
					std::cout<<"this = " << this <<'\n';	

				}
				Myclass& operator=(const Myclass& r)
				{
					std::cout<<"copy assignment"<<'\n';
					std::cout<<"this = " << this <<'\n';
					std::cout<<"&r = "<< &r <<'\n';
					return *this;
				}
		}
		
		int main()
		{
			Myclass m;

			m = 5; // Myclass(int x) parametreli conversion ctor olmasaydý hata verirdi çünkü int türünden sýnýf türüne dönüþüm yok
			dilin kurallarýna göre derleyici conversion ctor tanýmýný gördüðünde int türünden sýnýf türüne dönüþümü conversion ctora çaðrý yaparak dönüþtürüyor
			burada aslýnda olan þu derleyici conversion ctorun bildirimini gördü conversion ctora örtülü olarak çaðrý yaptý 5 ifadesini argüman olarak gönderdi ve bir myclass nesnesi oluþturdu
			aslýnda m = 5 ifadesi arka planda bir gecici nesne m = Myclass{5] ifadesi gibi bir ifade
		
		}
		
		ÇIKTI:
		default ctor this = 0000000EC42FF644
		Myclass(int x) x = 5
		this = 0000000EC42FF724
		copy assignment
		this = 0000000EC42FF644
		&r = 0000000EC42FF724
		destructor this = 0000000EC42FF724
		destructor this = 0000000EC42FF644

		böyle bir dönüþümün dilin kurallarýna göre yapýlmasý iyi bir þey mi kötü bir þey mi?
			deðiþir çünkü öyle bir sýnýf olabilir ki sýnýfýn genel mantýðýyla genel kullaným fikriyle o sýnýfý tasarlayanýn isteðiyle
			zaten böyle bir örtülü dönüþümün yapýlmasý istenebilir fakat diðer taraftan conversion ctor sayesinde yapýlan örtülü dönüþümler çok büyük bir risk kaynaðý

			int main()
			{
				Myclass m;
				double dval{};
				bool flag{};

				m = dval; 
				m = flag; 

				dilin bu konuda þöyle bir kuralý var 
					standard conversion(dilin kurallarý gereði varolan dönüþüm)
					user defined conversion(bir fonksiyona çaðrý yapýlarak oluþturulan dönüþüm)
						ama user defined conversion = conversion ctor diyemeyiz aslýnda 2 tane birbirinden ayrý user defined conversion var
						
						1)conversion ctor yoluyla yapýlan dönüþüm
						2)baþka bir fonksiyonun çaðýrýlmasýyla yapýlan user defined conversion(type cast operator function deniliyor)
							class Nec{
								public:
								operator int()const // bu fonksiyon nec türünden bir nesneyi int türüne dönüþtüren bir fonksiyon	
								{
									std::cout<<"operator int \n";
									return 49;
								}
							};

							int main()
							{
								Nec mynec;
								int ival;

								ival = mynec;

								std::cout<<"ival = "<< ival <<'\n';
							}

							ÇIKTI:
							operator int
							ival = 49

					eðer bir örtülü dönüþüm önce 
						standart conversion + user defined conversion uygulanarak yapýlabiliyorsa derleyici önce standart conversion sonra user defined conversionu uygular
						önce user defined conversion + standart conversion uygulayarak dönüþümü gerçekleþtirebiliyorsa derleyici önce user defined conversion ondan sonra standart conversion uygular
						user defined conversion + user defined conversion uygulanýyorsa derleyici hiç bir zaman bu dönüþümü örtülü olarak yapmaz

						Myclass m;
						double dval{};
						double flag{};

						m = dval; // önce standart conversion yapýlýr(double türünden int türüne dönüþüm) sonra user defined conversion yapýlýr(int türünden sýnýf türüne dönüþüm)
						m = flag; // önce standart conversion yapýlýr(double türünden int türüne dönüþüm) sonra user defined conversion yapýlýr(int türünden sýnýf türüne dönüþüm)
						
						bu durumu daha kötü bir hale getiriyor diyebilir miyiz? KESÝNLÝKLE
						class Myclass
						{
						public:
							Myclass() {}

							Myclass(bool b)
							{
								std::cout << "b = " << b << '\n'; 
							}
						};

						int main()
						{
							Myclass m;
							m = "fatih akgul"; // geçerli oldu ama çok tehlikeli bir durum array decay ile const char* türüne dönüþüyor const char* türündende bool türüne dönüþüyor
							 bu yapýlan örtülü dönüþüm bazý senaryolarda istenen bir durum ama bir çok durumda bizi riske sokanda bir durum

						}

						ÇIKTI:
						b = 1 // m ekrana bool olduðu için true deðerini yazdýrýr

						EXPLICIT CONSTRUCTOR(istenmeyen dönüþümlerin önüne geçmek için kullanýlýr)
							bir ctoru ama özellikle tek parametreli bir ctoru explicit anahtar sözcüðüyle bildirmek o ctoru explicit ctor yapýyor
							bu ctor sadece explicit conversiona(açýk dönüþüme) izin verir yani bir dönüþüm yapýlacaksa c++'ýn tür dönüþtürme operatörleriyle yapýlmalý
							her zaman tek parametreli ctorlarý explicit olarak belirtmeliyiz anca özel bir durum olduðu zaman non-explicit yapmalýyýz

								class Myclass
								{
									public:
										Myclass(){}
										explicit Myclass(int){}
								};

								int main()
								{
									Myclass m;
									m = 5; // ctor explicit olduðu için örtülü dönüþüm yapýlamýyor ve constructor'ýn explicit olmasý copy initialization sentaksýnýda geçersiz kýlýyor

									
									eðer bu dönüþümü explicit olarak yapmak istersek

									ival{245};
									m = static_cast<Myclass>(ival); // artýk dönüþümü explicit olarak yaptýðmýz için sentaks hatasý olmaz
								
								}
								tüm constructorlar explicit olabilir ama olmasý gerekiyor mu buna karar vermek gerek

								class Myclass
								{
									explicit Myclass();
									explicit Myclass(int);
								};

								void func(Myclass);

								Myclass foo()
								{
									return 15; // int parametreli ctor explicit olduðu için sentaks hatasý
								}
								int main()
								{
									Myclass x = {}; // böyle yazmak Myclass x = Myclass{}; yazmak ayný þey dilin kurallarýna göre örtülü dönüþüm olmuþ oluyor ama default ctor explicit olduðu için sentaks hatasý

									Myclass x = {12,56}; // int parametreli ctor explicit olduðu için örtülü dönüþüm yapýlamýyor sentaks hatasý
									
									func(132); // int parametreli ctor explicit olduðu için implicit conversion sentaks hatasýna sebep oluyor
								}
							
							SORU: 
								class Myclass
								{
									public:
										explicit Myclass(int);
										Myclass(dobule);
								};

								int main()
								{
									// Myclass m = 12; // double parametreli ctor çaðýrlacak genel beklenti sentaks hatasý olmasý ama sentaks hatasý yok explicit ctor overlaod set'e dahil edilmiyor 
														
								}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DELEGATING CONSTRUCTOR
	bir ctorun bir nesneyi hayata getirirken bir baþka ctor ile memberlarýn initialize edilmesini saðlamak
	bir ctor MIL sentaksý ile sýnýfýn diðer ctorlarýna çaðrý yaparak initalization yapma sürecini o ctora delege edebiliyor

	class Myclass{
		public:
			Myclass(int,int,int);
			Myclass(int,int);
			Myclass(int x) : Myclass(x,x,x)
			{

			}

			burda recursive bir çaðrý oluþursa bu durum programcýnýn sorumluluðunda
	}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
FRIEND DECLERATION(ARKADAÞLIK BÝLDÝRÝMLERÝ)

	bir sýnýfýn private bölümü client kodlara kapalý eriþmeye çalýþýrsak access control sürecinde sentaks hatasý alýrýz friend bildirimleri sýnýfýn kendi kodlarýn dýþýnda baþka kodlarýn sýnýflarýn 
	private ve protected elemanlarýna eriþimini geçerli kýlýyor eðer bir kod friend olarak bildirilmiþse o kodun içinde friend bildirimi yapan sýnýfýn private ve protected bölümüne eriþim sentaks hatasý olmayacak
	friend bildirimleri client kodlar için yapýlmýyor sýnýfýn kendi kodlarý için yapýlýyor 
	bir sýnýfýn public inerface'i sadece sýnýfn public bölümünden ibaret deðil baþlýk dosyasýnda yapýlan tüm bildirimler(public öðeler ve global öðeler) sýnýfýn public inerface'ine dahil oluyor
	
	friend bildirimi verilen fonksiyonlar
		1)global fonksiyonlara
		2)bir baþka sýnýfýn bir member functionuna
		3)bir sýnýfýn tamamýna
*/