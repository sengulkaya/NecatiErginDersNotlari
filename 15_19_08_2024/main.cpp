/*

operator overloadingten devam

	sýnýflarý içeriden dýþarýya doðru deðil dýþarýdan içeriye doðru tasarlamak gerekiyor 
	yani olaya clientlarýn gözüyle bakmamýz lazým clientlarýn bu sýnýfý nasýl daha kolay kullanýrlar diye bakmamýz gerek
	buna yönelik bir interface oluþturmamýz lazým ve genellikle interface'i oluþtururken impelemantasyon tarafýný düþünmeyeceðiz

	zero cost abstraction
		int türünü kullanmakla mint türünü kullanmak arasýnda maliyet açýsýndan bir fark olmayacak 
		örneðin 2 tane mint sýnýfýndan nesneyi toplarsak assembly koduna bakarsak aslýnda iki tane int deðeri toplanmýþ oluyor
		
	duration türleri
		chrono kütüphanesi modern C++ ile dile eklenen önemli kütüphanelerden biri burda durationu temsil eden türler var

		bu fonksiyonlar global operator fonksiyonu olacak çünkü operatörlerimizin bir operandý stream nesneneleri ve ostream sýnýfýna müdahale etme þansýmýz olmadýðý için
		free function olarak yazýcaz free function olarak yazýlmasýndada önemli bir seçim var
		1)friend definition olarak class definition içinde implemente edilsin mi?
		2)yoksa sadece bildirilip implementasyon dosyasýnda mý tanýmlansýn?

		bazý avantajlarý elde etmek için free function olan operatör fonksiyonlarýnýn çok büyük çoðunluðunu friend function olarak class definition içinde tanýmlayacaðýz bunu yapmamýzýn önemli nedenlerden biri
		bunlarý hidden friend haline getirmek ama friend yapmamýzýn 2 tane önemli sonucu var
		1)global bir fonksiyon friend olarak bildirilmezse o fonksiyon sýnýfýn private bölümüne eriþemez
		2)fonksiyon bir global fonksiyon ise friend tanýmýný class definition içindede yapabiliriz

	c++ 20 standartýyla karþýlaþtýrma operatörleri primary ve secondary operatör olarak 2 ye ayrýlýyor
		primary operatör
			<=>
			==
		secondary operatör
			!=
			<
			<=
			>
			>=
			
	secondary operatörlerin avantajlarý
		5 < x // x bir sýnýf nesnesi derleyici bunu sanki x < 5 olarak deðiþiklikte yapabiliyor bu sadece secondary operatörlere yönelik bir özellik
				
	RASUL MAMMADOVUN SORUSU ÜZERÝNE
		class Myclass{
			friend void func(int);
			friend void func(Myclass);
		};

		int main()
		{
			func(12) // sadece int parametreli fonksiyon tanýmlý olursa name lookup hatasý derleyici fonksiyonu bulamaz

			Myclass m;
			func(m); // nasýl oluyorda þimdi geçerli oluyor? bu konu namespace ve ADL(argument dependent lookup / ARGÜMANA BAÐLI ÝSÝM ARAMA) ile ilgili
			böyle bir fonksiyonun isim aramayla bulunmasý için fonksiyonun parametresinin sýnýf türüyle iliþkili olmasý gerekiyor eðer sýnýfa iliþkin deðilse böyle bir
			friend bildirimi yapsakta sýnýf dýþýnda böyle bir isim bulunamaz
		}


	++x -> ön ek ++ operatörü nesnenin deðerinin bir fazlasýný veriyor 
	x++ -> son ek ++ operatörü nesnenin kendi deðerini veriyor 

	int x = 6;
	++x; // 7
	x++ // 6;

	a = b++; yazmak

	a = b;
	b = b + 1; // yazmak ile ayný

	x = ++y; yazmak

	y = y + 1;

	x = y; yazmak ile ayný

	--y; // ön ek -- operatörü nesnenin deðerinin bir eksiðini veriyor
	y--; // ön ek -- operatörü nesnenin kendi deðerini veriyor

	C++ dilinde ön ek formlar l value expression son ekler r value expression

	class Myclass
	{
		public:
			Myclass& operator++(); // önek operatörü
			Myclass operator++(int); // sonek operatörü sadece imza farklýlýðý yaratmak için int yazýyoruz bu parametreye argüman geçmeyeceðiz bu yüzden parametreye isim vermiyoruz
			global operatör olarakta yazýlabilirler ama pek görülmez
	}

array-like sýnýflar
	array olmayan ama array gibi kullanabildiðimiz sýnýflar array,vector gibi

	std::string str = "kaveh nematipour";
	for(int i = 0; str[i] < str.size(); ++i) // string sýnýfýnda subscript operatörü overload edilmiþ
	{
		std::cout<<str[i]<<" ";
	}

	ar[i] // böyle bir ifadede derleyici köþeli parantezin dýþýndaki operand olan sýnýf nesnesinin [] subscript operatörü olup olmadýðna bakýyor 
	derleyici ar.operator[](i) köþeli parantezin içindeki ifadeyi bu fonksiyona gönderilen argüman yapýyor

	vec[5] // vec.operator[](5)
	str[val] // str.operator[](val)

	overladoingi biz yapýyorsak 2 önemli madde var
		1)index yada subscript operatörüyle oluþturulan ifadeler l value expresssion bu yüzden fonksiyonlarýn geri dönüþ deðerleri l value ref olmasý gerek
		2)dizinin elemanlarý hangi türden elemanlar içeriyorsa subscript fonksiyonun geri dönüþ deðeri o türden l value ref olmalý

	std::string str = "kaveh nematipour";

	std::cout<<str<<'\n';

	str[0] = '!';
	strd[4] = '!';

	std::cout << str<<'\n';

	ÇIKTI: !ave! nematipour

	const overloading operatör overloadingte'de geçerli

	class String
	{
		public:
			char& operator[](std::size_t idx); // const olmayan string nesnesi için çaðýrýlacak
			const char& operator[](std::size_t idx)const; // const olan string nesnesi için çaðýrýlacak
	
	}

	int main()
	{
		const String str;

		str[5] = 'A'; // sentaks hatasý

		char cx = str[5]; // geçerli

	}

	int ar[5] = {10,20,30,40,50};

	for(int i = 0; i< 5; ++i)
	{
		printf(%d ", i[ar]); // normalde ar[i] olarak yazardýk derleyici böyle bir ifadeyi gördüðünde *(i + ar) ifadesine dönüþtürüyor
		ar[i] *(ar + i) *(i + ar) i[ar] ifadelerinin hepsi ayný anlamda
	}

	adres ile tam sayý toplanýrsa = adres
	
	tam sayý ile adres toplanýrsa = adres
	
	adres ile adres toplanamaz
		int *p1 = ar + 2;
		int *p2 = ar + 4;

		p1 + p2; // sentaks hatasý

	adresten adres çýkartýlabilir bu ifadenin türü ptrdiff_t implementation defined derleyiciden derleyiciye deðiþiyor
		
	REFERENCE QUALIFIERS
		class Myclass
		{
			public:
				void func();
		}

		int main()
		{
			Myclass m;
			m.func();
			Myclass{}.func(); // ikiside geçerli

			öyle senaryolar var ki bazý fonksiyonlarýn r value expressionla çaðýrýlmasýný istemiyoruz
					class Bigint
					{
						public:
							Bigint& operator=(int);
					}
					int main()
					{
						Bigint{} = 20 // anlamý yok ama sentaks hatasý deðil
					}

					eðer operatör = fonksiyonuna & tokený koyarsak bu fonksiyon sadece l valuelar için çaðýrýlýr
						Bigint& operator=(int)&; // bu sefer yukarýdaki durum sentaks hatasý olur buna l value reference qualified deniliyor
						
						bu fonksiyonun çaðýrýlmasý için bu fonksiyonu çaðýracak sýnýf nesnesinin l value olmasý gerekiyor
		}

		reference qualified function overloadingtede iþimize yarýyor
			class A
			{
				public:
					void func()const; // const nesneler için
					void func()&&; // r value nesneler için
					void func()&; // l value nesneler için

					// 3 tane ayrý overload var bu durumda en önemlisi böyle bir overloadingte l value olan sýnýf nesneleri için baþka bir implementasyon
					r value sýnýf nesneleri için baþka bir mplementasyon oluþturabiliriz

					ama reference qualified kullanýyorsak reference qualified olmayan bir ifade koyamayýz
						void func(); // sentaks hatasý

					reference qualified sadece memberlar için geçerlidir free functionlar böyle tanýmlanamaz

			};
*/

