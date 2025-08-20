/*
modern cpp öncesinde big three terimi vardý

destructor
copy constructor
copy assignment operator
 
bu fonksiyonlardan birini özellikle destructorýn yazýmýný derleyiciye býrakmak yerine kendimiz yapmak zorundaysak diðer iki fonksiyonuda implemente etmeliyiz
çünkü destructorý yazma nedenimiz tipik olarak bir kaynaðýn geri verilmesi bu durumda copy ctor ve copy assignment operator function derleyici tarafýndan yazýlýrsa onlarýn kodu uygun olmayacak

modern cpp ile big five terimi geldi
	destructor
	copy ctor
	copy assignment operator
	move ctor
	move assignment operator

hoca bu overloading tipini bize tekrar anýmsatýyor
	class Nec {};

	void foo(Nec&); // l value &
	void foo(const Nec&); // const l value &
	void foo(Nec&&); // r value &
	void foo(const Nec&&); // const r value & tipik olarak bir iþe yaramýyor semantik karþýlýðý çok nadir

	üretimde çoðunlukla karþýmýza çýkacak overloading 
		void foo(const Nec&); // const l value &(l value argümanlarý alýr)
		void foo(Nec&&); // r value & (r value argümanlarý alýr)

		Nec bar();
		Nec&& baz(); // X value(geri dönüþ deðeri R value olan fonksiyonlara yapýlan çaðrý ifadeleri)


		int main()
		{
			Nec mynec; // l value expression

			Nec{}; // r value expression temporary object sýnýf türünden nesne anlamýna geliyor fakat ortada o nesnenin ismi yok sadece sýnýfýn ismi var(ayrý bir baþlýk altýnda incelenecek)

			foo(mynec); // const Nec& çaðýrýlýr
			foo(std::move(mynec)); // Nec&& çaðýrýlýr
			foo(Nec{}) // Nec&& çaðýrýlýr
			foo(bar()); // Nec&& çaðýrýlýr
			foo(baz()); // Nec&& çaðýrýlýr

			burda void foo(Nec&&) overloadunu silsek bile sentaks hatasý olmaz çünkü foo fonksiyonu const Nec& olduðu için hem l value hemde r value ile çaðýrýlabilir buna popüler olarak FALL BACK deniliyor
			
			}	

		void bar(const Nec&&); 
		
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MOVE CONSTRUCTOR VE MOVE ASSIGMENT
	öyle durumlar var ki koda bakarak bir sýnýf nesnesinin artýk kullanýlma olanaðýnýn olmadýðýný o nesnenin kullanbabilecek bir kodun söz konusu olmadýðýný derleyici anlayabilir
	bizde kod bakarak anlayabiliyoruz böyle bir durumda bir sýnýf nesnesi varken örneðin string sýnýfýmýz onun deðeri iile baþka bir sýnýf nesnesini hayata getirmek istediðimizde MODERN CPP öncesi copy ctoru kullanýrken
	deðerini kullanacaðýmýz deðerini alacaðýmýz sýnýf nesnesinin hayatý bitecek olmasýnaa karþýn onun kaynaðýný yine bir çok durumda kopyalýyorduk fakat MOVE CTOR ile derleyiciye þunu demiþ oluyoruz

		sen sýnýf nesnesi seni kullanacak baþka bir kod yok sen gidicisin :D o zaman ben neden senin kaynaðýný kopyalayayým? ben senin kaynaðýný devralayým kaynaðýný çalayým(TO STEAL THE RESOURCE)

	HOCANIN ÇÝZÝMÝ ÜZERÝNE(LÜTFEN ÇÝZÝME BAKIP BÝR YANDAN BUNU OKUYUN)string.png

		bizim yazdýðým string sýnýfýndan bir nesnemiz var bu sýnýf nesnesinin hayatý bitecek
		hayatý biterken bunun için destrutor çaðýrýlacak dynamic allocate edilmiþ kaynaðý geri vericek
		ama biz bu sýnýf nesnenini deðeri ile baþka bir sýnýf nesnesi oluþturmak istiyoruz peki bu neden kaynaðýný geri versin ki?
		onun kaynaðýný biz elde edelim çalmýþ olalým yani bizim sýnýf nesnemiz diðer sýnýf nesnesinin kaynaðýný edinmek için bu sefer gerçekten pointerý kopyalasýn
		ama burda bir problem var 
			1)derleyicinin koda bakarak buradaki sýnýf nesnesinin hayatýnýn bitecek oluðunu anlamasý gerekiyor 
			2)alternatif baþka bir kodu seçmesi gerekiyor

		eðer kopyalama hayatý devam edecek bir nesne kaynak olarak kullanýlmasý suretiyle yapýlýyorsa copy ctor

		ama kopyalama hayatý bitecek olan kullanýlmayacak olan bir nesneden yapýlýyorsa deep copy yapmak yerine gerçekten pointerý kopyalayacak bir kodu seçmemiz gerekiyor
		MODERN CPP öncesinde bunu yapma imkanýmýz yoktu ve MODERN CPP ile bunun rahatlýkla implemente edilmesini saðlayan baðlayýcý araaç R value &
		
		bir problem daha var yeni hayata getireceðimiz nesne diðerinin pointerýný kopyaladý ama deðerini aldýðý nesne için destructor çaðýrýldýðýnda yine o kaynaðý geri vereceði için dangling pointer olmuþ oluyor
		öyle bir fonksiyon yazabilmeliyiz ki diðer nesnenin kaynaðýný çalmakla birlikte yani pointerýný kopyalamakla birlikte diðer nesneyi öyle bir state sokmasý gerekiyor ki destructor çaðýrýldýðýnda 
		kynaðýnýn çalýndýðýnýn farkýnda olacak ve kaynaðý geri vermeyecek bunu saðlayan fonksiyon MOVE CTOR 

		iki tane nesne varsa kendisine atama yapacaðýmýz nesnenin alacaðý yeni deðeri temsil eden diðer nesnenin artýk kullanýlabilir olmadýðýný biliyorsak yine nesnenin kaynaðýný çalabiliriz

		move ctor ve move asignment öyle fonksiyonlar ki copy ctor ve copy assigmenta göre yaptýklarý iþ kopyalama yapmamak(sdeep copy yapmamak) diðer nesnenin kaynaðýný çalmak ve nesnenin destructor 
		çaðýrýldýðýnda kaynaðýnýn geri verilmemesini saðlamak

		peki bunu nasýl yapacaðýz
			baþka bir kodun kullanýlma ihtimali olmayan hayatý bitecek nesneler dilin kurallarýna göre bu ifadeler(r value)
			iki tane constructor overloadu olsa biri l value diðeri r value argümanlarý alsa r value deðeri alan overload referansýn baðlandýðý nesnenin hayatýnýn biteceðini
			baþka bir kodun ona ihtiyaç duymadýðýný bilecek ve onun kaynaðýný çalacak

		hem move ctor hemde copy ctor var ise l valuelar için copy ctor r value argümanlar için move ctor çaðýrýlacak
		move ctor bir nedenden yok ise hem r value hemde l value için copy ctor çaðýrýlacak fall back terimini iþte burada kullanýyoruz
			Myclass(const Myclass&);
			Myclass(Myclass&&);

			Myclass& operator=(const Myclass&); // l valuelar için 
			Myclass& operator=(Myclass&&); // r valuelar için

			kopyalama yerine taþýma daha fazla yararlý olur mu?
				sýnýfa göre deðiþir

			move constructorýn avantaj saðlamasý için ortada bir kaynaðýn olmasý o kaynaðý kopyalama altarnatifine karþý kopyalamayý tamamen ortadan kaldýrýp o kaynaðý çalma alternatifini kullanmýþ oluyoruz
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		DERLEYÝCÝNÝN YAZDIÐI MOVE CTOR

			class Myclass
			{
			public:
				Myclass(Myclass&& r) : ax(std::move(r.ax)), bx(std::move(r.bx)), cx(std::move(r.cx))
				{
				 // bu ifadeler isim formunda olduðu için normalde l value olmuþ oluyor compile timeda r value expression olarak kullanýlmasýný saðlayan move fonksiyonudur
				}
			private:
				A ax;
				B bx;
				C cx;
			};

			Rasulun sorusu üzerine
				class Nec
				{
					private:
						std::string str;
						std::vector<int> vec;

						// bu sýnýfýn move ctorýný biz yazmasak derleyicinin yazsýdý move ctor bir nec nesnesini hayata getiren bir r value nec nesnesi olduðunda
						derleyicinin yazdýðý move ctor çaðýrýlacaktý derleyicinin yazdýðý move ctor nec'in str elemanýný string sýnýfýnýn move ctoru ile hayata getirecekti
						yani hayata gelen nec nesnesi kaynak olarak kullanýlan nec nesnesinin stringinin kaynaðýný çalýcaktý bizim bu durumda bir þey yapmamýz gerekmiyor AMA!
						eðer handle elemanlar varsa taþýma semantiðinin implementasyonunu kendimiz yapmalýyýz
				}
				
				copy ctorun derleyici tarafýndan yazýlmasý eðer sýnýfýn elemanlarý handle ise felakete neden oluyor
				ama sýnýfýn move ctoru olmamasý bir felaket senaryosu deðil sadece efficiently(performans açýsýndan zararý var) 
					
			class String
			{
			public:
				String(const String& other) : mlen(other.mlen)
				{
					mp = static_cast<char*>(std::malloc(mlen + 1));

					if (!mp) {
						std::cerr << "cannot allocate memory\n";
						std::exit(EXIT_FAILURE);
					}

					strcpy(mp, other.mp);
				}
				String(String&& other) : mlen(std::move(other.mlen)),mp(std::move(other.mp)) 
				{
					// other'ýn baðlandýðý nesne içinde destructor çaðýrýlacak mp isimli pointer burda nullptr olmuþ olmuyor 
					destructor çaðýrýldýðý zaman bizim çaldýðmýz kaynaðý geri vermemesi lazým 
					other.mp = nullptr;
					other.mlen = 0; // bunun hakkýnda hoca daha sonra konuþacak
				}
				String(const char* p) : mlen(std::strlen(p))
				{
					mp = static_cast<char*>(std::malloc(mlen + 1));

					if (!mp) {
						std::cerr << "cannot allocate memory\n";
						std::exit(EXIT_FAILURE);
					}

					strcpy(mp, p);
				}
				~String()
				{
					if (mp)
						std::free(mp);
				}
				void print() const
				{
					std::cout << '['<<mp << "]\n";
				}

				size_t length()const
				{
					return mlen;
				}
			private:
				size_t mlen;
				char* mp;
			};

			void foo(String s)
			{
				std::cout << "foo cagrildi\n";
				s.print();
				(void)getchar();
			}

			int main()
			{
				String str(String{"bugun yine cok sicak hava vardi"}); // temporary object olduðu için move ctor çaðýrýlýr			
				
			}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	HOCANIN MÜLAKATTA TAÞIMA SEMANTÝÐÝ ÝLE ÝLGÝLÝ SORDUÐU SORU
		class Myclass{};

		void func(Myclass&&){}

		int main()
		{
			Myclass m;

			func(std::move(m)); // bu satýrdan sonra m nesnesinin kaynaðý çalýnmýþmýdýr?
				TABÝKÝ HAYIR BÝR NESNEYÝ BÝR SAÐ TARAF REFERANSINA BAÐLAMAK ONUN KAYNAÐINI ÇALMAK DEÐÝLDÝR
				FUNC ÝÇÝNDE ÖYLE BÝR ÝMPLEMANTASYON OLMALI KÝ BU SAÐ TARAF REFERANSININ BAÐLANDIÐI NESNESÝN KAYNAÐINI ÇALMALI BUNUNDA 2 TANE YOLU VAR
				1)Myclass nesnesini hayata getireceðiz
				2)Myclass nesnesine atama yapacaðýz
					void func(Myclass&& r)
					{
						Myclass mx = std::move(r); // bu fonksiyon nesnenin kaynaðýný çalar
					}
		}
			iki ayrý overload olsa
				void func(Myclass&&)
				{  
					Myclass mx = std::move(r); // r value deðerler için taþýma yapmasýný saðlýyoruz
				}
				void func(Myclass&)
				{
					Myclass mx = r; // l value deðer için kopyalama yapmasýný saðlýyoruz
				}

		move ctorun implemente edilmesi için bir fayda saðlamasý gerekiyor	
			class Myclass
			{
				private:
					int ar[1000]; // bu sýnýf içn move ctor yazmanýn bir anlamý yok böyle olmasý efficiently açýsýndan bir fayda saðlamaz çünkü derleyiciyede býraksak burda bu dizi kopyalanacak
					
					std::string* p; // dinamik olarak allocate edilmiþ bir bellek bloðundaki string nesnenelerinin bulunduðu bellek bloðunun adresini tutuyor olsaydý
					move ctor burda hayati önem taþýrdý çünkü kopyalama ile yetinirsek kopyalama yoluyla hayata getirdiðimiz nesne gidecek ayrý bir bellek alaný allocate edicek
					ve orda string nesnenelerini oluþturacak yani diðerinin allocate ettiði bellek bloðunda 10 bin string nesnesi varsa bizim hayata getirdiðimiz nesnede 10bin tane string nesnesini hayata getirecek
			}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	DERLEYICININ YAZDIÐI MOVE ASSIGMENT
		class Myclass
		{
			public:
				Myclass(const Myclass& r) : ax(r.ax),bx(r.bx),c(r.cx){}
				Myclass(Myclass&& r) : ax(std::move(r.ax)), bx(std::move(r.bx)), cx(std::move(r.cx)) {}
				Myclass& operator=(const Myclass& r)
				{
					ax = r.ax;
					bx = r.bx;
					cx = r.cx;,
					return *this;
				}
				Myclass& operator=(Myclass&& r)
				{
					ax = std::move(r.ax);
					ax = std::move(r.bx);
					ax = std::move(r.cx);
					return *this;
					DÝKKAT:string sýnýfý için yazdýðmýz other.mp = nullptr diðer nesnenin pointerýný nullptr yapabilmemiz için referans deðiþkenin const olmamasý gerekiyor o yüzden MOVE CTOR yada MOVE ASSIGMENT parametreleri const olmayan referans

				}
			private:
				A ax;
				B bx;
				C cx;
		};

		class String
		{
		public:
			String(String&& other) : mlen(other.mlen), mp(other.mp)
			{
				other.mp = nullptr;
				other.mlen = 0;
			}

			String& operator=(String&& other)
			{
				if (this == &other)
					return* this;

				free(mp); // bunu yapmasak kaynak sýzýntýsý olurdu çünkü pointera yeni deðer atanmasý o pointerýn gösterdiði kaynaðýn geri verildiði anlamýna gelmiyor
				mlen = other.mlen;
				mp = other.mp;

				other.mp = nullptr;
				other.mlen = 0;

				return *this;

			}

		private:
			size_t mlen;
			char* mp;
		};
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		MOVED FROM STATE/OBJECT
			nesne hala hayatta ama kaynaðý çalýnmýþ anlamýna geliyor 

			int main()
			{
				std::string str(10000,'A'); // 10000 tane A karakteri içeren string nesnesi

				std::string sx = std::move(str); // str nesnesinin kaynaðýný çaldýk

				standart kütüphanenin sýnýflarý kaynaðý çalýnmýþ nesneler için þu garantileri veriyor
				
				1)kaynaðý çalýnmýþ bir nesne valid statete olacak
					sýnýfýn invariantlarý korunmuþ olacak(nesnenin deðerinin uzunluðu gibi)
				2)destructorýn çaðýrýlmasý herhangi bir soruna yol açmayacak
					yani destructor çaðýrýlmasý durumunda bir problem olmayacaðý anlamýna geliyor

				3)nesneye yeni bir deðer atayarak tekrar kullanabiliriz
					
				nesnenin deðeri garanti altýnda deðil valid statete olmasý baþka nesnenin deðerinin ne olduðu baþka

				moved from statete ki nesnenin deðerinin ne olacaðý derleyiciye baðlý ama nesne geçerli bir durumda olduðu için o deðeri gerekirse kullanabiliriz

			}

			valid state
				string str{"oguzhan esin ve fatih akgul c++ programcilari"};

				auto s = std::move(str);

				std::cout<<str.length(); // str nesnesinin uzunluðu 0 olacak

				if(str.empty())
					std::cout<<"str nesnesi boþ\n";
				else
					std::cout<<"str nesnesi dolu\n";

				std::cout<<"(" << str << ")\n"; // str nesnesinin içeriði belirsiz ama valid state 

				str = "baris doga yavas"; // burda her hangi bir tanýmsýz davranýþ yok

			sýnýf nesnelerinin kopyalanmasýnda bir sorun yoksa bunlara COPYABLE sýnýflar denebilir ama bazý durumlarda sýnýflarýn kopyalanmasýný engellemek istiyoruz
				nedeni kopyalamanýn o sýnýf için anlamlý bir yapý oluþturmamasý yani semantik bir karþýlýðýnýn olmamasý problem domaininde temsil ettikleri kavram için zaten kopyalama bir anlam taþýmýyor 

				ifstream ifs"text.txt"};
				if(!ifs)
				{
					std::cerr<<"cannot open file\n";
					return 1;
				}

				std::vector<std::string> svec;

				std::string sline;

				while(getline(ifs,sline))
				{
					svec.push_back(sline); // burda sline nesnesinin kopyalanmasý mantýklý bir durum deðil böyle durumlarda sýnýfýn copy ctoru ve copy assignment operatorü delete ediliyor böyle sýnýflara NON-COPYABLE sýnýflar deniliyor
				}

				Nec(const Nec&) = delete;
				Nec& operator=(const Nec&) = delete;					
				
				kopyalama olmayan(non-copyable) sadece taþýnabilir olan sýnýflara MOVE ONLY CLASS deniyor
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DERLEYÝCÝ HANGÝ DURUMLARDA SINIFIN SPECIAL MEMBER FUNCTIONLARINI IMPLICITLY DECLARE EDER(DOSYALARA KOYDUÐUM GÖRSELÝ ÝNCELEYÝN LÜTFEN)
		
		Sýnýfta herhangi bir special member function yoksa derleyici hepsini impilictly declared olarak default bildirir

		class Myclass
		{
			Myclass() = default;
			~Myclass() = default;
			Myclass(const Myclass&) = default;
			Myclass(Myclass&&) = default;
			Myclass& operator=(const Myclass&) = default;
			Myclass& operator=(Myclass&&) = default;

		} // derleyicinin yaptýðý implicitly olarak budur
		--------------------------------------------------------------------------------------------------------------------------------------------------
		Sýnýfa special member function olan yada olmayan her hangi bir constructor bildirilirse derleyici default contructoru
		implictly declared etmez default constructor not declared durumuna düþer diðer special member functionlar hala implicitly declared edilmiþ haldedir
		--------------------------------------------------------------------------------------------------------------------------------------------------
		Sýnýfa default constructor user declared edilmiþse diðer specail member functionlar hala implicitly declared edilmiþ haldedir
		--------------------------------------------------------------------------------------------------------------------------------------------------
		Sýnýfa Destructor user declared olarak bildirilirse
			default contructor derleyici tarafýndan implicitly declared olarak default edilir
			copy constructor derleyici tarafýndan implicitly declared olarak default edilir ->istenmeyen durum deprecated
			copy assginment operator derleyici tarafýndan implicitly declared olarak default edilir ->istenmeyen durum deprecated

			move contructor olmaz/not declared
			move assignment operator olmaz/not declared

			Destructor user declared olduðu zaman move constructor ve move assignment operator default edilmez
			ve bu deprecated(gelecekti standartlarda bu tamamen sentaks hatasýna yol açabilir) edilmiþtir asla olmamasý gereken bir þey
		--------------------------------------------------------------------------------------------------------------------------------------------------
		Sýnýfa copy constructor user declared olarak bildirilirse
			copy assignment operator derleyici tarafýndan implicitly declared olarak default edilir ->istenmeyen durum deprecated
			destructor derleyici tarafýndan implicitly declared olarak default edilir

			default contructor olmaz/not declared
			move constructor/not declared
			move assignment operator olmaz/not declared
		--------------------------------------------------------------------------------------------------------------------------------------------------
		Sýnýfa copy assignment user declared olarak bildirilirse
			default contructor derleyici tarafýndan implicitly declared olarak default edilir
			destructor derleyici tarafýndan implicitly declared olarak default edilir
			copy contructor derleyici tarafýndan implicitly declared olarak default edilir ->istenmeyen durum deprecated

			move constructor olmaz/not declared
			move assginment operator olmaz/not declared
		--------------------------------------------------------------------------------------------------------------------------------------------------
		Sýnýfa move constructor user declared olarak bildirilirse
			destructor derleyici tarafýndan implicitly declared olarak default edilir

			move assignment operator olmaz/not declared
			default contructor olmaz/not declared
			copy constructor var ama/delete edilmiþtir
			copy assignment var ama/delete edilmiþtir
		--------------------------------------------------------------------------------------------------------------------------------------------------
		Sýnýfa move assignment operator user declared olarak bildirilirse
			default constructor derleyici tarafýndan implicitly declared olarak default edilir
			destructor derleyici tarafýndan implicitly declared olarak default edilir

			move constructor olmaz/not declared
			copy constructor/delete edilmiþtir
			copy assignment operator/delete edilmiþtir
		
	Bir sýnýfa default ctor olmayan her hangi bir constructor bildirirsek derleyici default ctoru bildirmez(not declared)
	
	Bir sýnýfýn her zaman destructorý vardýr biz bildirirsek user declared bizim bildirmediðimiz bütün durumlarda implicitly declared
			
	eskiden big three denilen
		destructor
		copy ctor
		copy assignment
			bunlardan her hangi bir tanesini bildirirsek derleyici move memberlarý bildirmez/not declared

	Sýnýfa move memberlardan her hangi birini bildirirsek derleyici copy memberlarý delete eder
	
	bir sýnýfta copy memberlarý delete etmek istenebilir bir þeydir ama
	move memberlarý yani move constructor ve move assignment operator asla delete edilmemeli çünkü
	move gereken yerde sentaks hatasý olur move memberlar delete edilmese ama sýnýfta copy contructor olsaydý
	move gereken yerde kopyalamaya fall back olurdu

		class Myclass
		{
			public:
				Myclass();
				Myclass(const Myclass&);
				Myclass& operator=(const Myclass&);
		};

		int main()
		{
			Myclass m1,m2;

			m1 = std::move(m2);
		}
*/