/*

operator overloadingten devam

	s�n�flar� i�eriden d��ar�ya do�ru de�il d��ar�dan i�eriye do�ru tasarlamak gerekiyor 
	yani olaya clientlar�n g�z�yle bakmam�z laz�m clientlar�n bu s�n�f� nas�l daha kolay kullan�rlar diye bakmam�z gerek
	buna y�nelik bir interface olu�turmam�z laz�m ve genellikle interface'i olu�tururken impelemantasyon taraf�n� d���nmeyece�iz

	zero cost abstraction
		int t�r�n� kullanmakla mint t�r�n� kullanmak aras�nda maliyet a��s�ndan bir fark olmayacak 
		�rne�in 2 tane mint s�n�f�ndan nesneyi toplarsak assembly koduna bakarsak asl�nda iki tane int de�eri toplanm�� oluyor
		
	duration t�rleri
		chrono k�t�phanesi modern C++ ile dile eklenen �nemli k�t�phanelerden biri burda durationu temsil eden t�rler var

		bu fonksiyonlar global operator fonksiyonu olacak ��nk� operat�rlerimizin bir operand� stream nesneneleri ve ostream s�n�f�na m�dahale etme �ans�m�z olmad��� i�in
		free function olarak yaz�caz free function olarak yaz�lmas�ndada �nemli bir se�im var
		1)friend definition olarak class definition i�inde implemente edilsin mi?
		2)yoksa sadece bildirilip implementasyon dosyas�nda m� tan�mlans�n?

		baz� avantajlar� elde etmek i�in free function olan operat�r fonksiyonlar�n�n �ok b�y�k �o�unlu�unu friend function olarak class definition i�inde tan�mlayaca��z bunu yapmam�z�n �nemli nedenlerden biri
		bunlar� hidden friend haline getirmek ama friend yapmam�z�n 2 tane �nemli sonucu var
		1)global bir fonksiyon friend olarak bildirilmezse o fonksiyon s�n�f�n private b�l�m�ne eri�emez
		2)fonksiyon bir global fonksiyon ise friend tan�m�n� class definition i�indede yapabiliriz

	c++ 20 standart�yla kar��la�t�rma operat�rleri primary ve secondary operat�r olarak 2 ye ayr�l�yor
		primary operat�r
			<=>
			==
		secondary operat�r
			!=
			<
			<=
			>
			>=
			
	secondary operat�rlerin avantajlar�
		5 < x // x bir s�n�f nesnesi derleyici bunu sanki x > 5 olarak de�i�iklikte yapabiliyor bu sadece secondary operat�rlere y�nelik bir �zellik
	
	RASUL MAMMADOVUN SORUSU �ZER�NE
		class Myclass{
			friend void func(int);
			friend void func(Myclass);
		};

		int main()
		{
			func(12) // sadece int parametreli fonksiyon tan�ml� olursa name lookup hatas� derleyici fonksiyonu bulamaz

			Myclass m;
			func(m); // nas�l oluyorda �imdi ge�erli oluyor? bu konu namespace ve ADL(argument dependent lookup / ARG�MANA BA�LI �S�M ARAMA) ile ilgili
			b�yle bir fonksiyonun isim aramayla bulunmas� i�in fonksiyonun parametresinin s�n�f t�r�yle ili�kili olmas� gerekiyor e�er s�n�fa ili�kin de�ilse b�yle bir
			friend bildirimi yapsakta s�n�f d���nda b�yle bir isim bulunamaz
		}


	++x -> �n ek ++ operat�r� nesnenin de�erinin bir fazlas�n� veriyor 
	x++ -> son ek ++ operat�r� nesnenin kendi de�erini veriyor 

	int x = 6;
	++x; // 7
	x++ // 6;

	a = b++; yazmak

	a = b;
	b = b + 1; // yazmak ile ayn�

	x = ++y; yazmak

	y = y + 1;

	x = y; yazmak ile ayn�

	--y; // �n ek -- operat�r� nesnenin de�erinin bir eksi�ini veriyor
	y--; // �n ek -- operat�r� nesnenin kendi de�erini veriyor

	C++ dilinde �n ek formlar l value expression son ekler r value expression

	class Myclass
	{
		public:
			Myclass& operator++(); // �nek operat�r�
			Myclass operator++(int); // sonek operat�r� sadece imza farkl�l��� yaratmak i�in int yaz�yoruz bu parametreye arg�man ge�meyece�iz bu y�zden parametreye isim vermiyoruz
			global operat�r olarakta yaz�labilirler ama pek g�r�lmez
	}

array-like s�n�flar
	array olmayan ama array gibi kullanabildi�imiz s�n�flar array,vector gibi

	std::string str = "kaveh nematipour";
	for(int i = 0; str[i] < str.size(); ++i) // string s�n�f�nda subscript operat�r� overload edilmi�
	{
		std::cout<<str[i]<<" ";
	}

	ar[i] // b�yle bir ifadede derleyici k��eli parantezin d���ndaki operand olan s�n�f nesnesinin [] subscript operat�r� olup olmad��na bak�yor 
	derleyici ar.operator[](i) k��eli parantezin i�indeki ifadeyi bu fonksiyona g�nderilen arg�man yap�yor

	vec[5] // vec.operator[](5)
	str[val] // str.operator[](val)

	overladoingi biz yap�yorsak 2 �nemli madde var
		1)index yada subscript operat�r�yle olu�turulan ifadeler l value expresssion bu y�zden fonksiyonlar�n geri d�n�� de�erleri l value ref olmas� gerek
		2)dizinin elemanlar� hangi t�rden elemanlar i�eriyorsa subscript fonksiyonun geri d�n�� de�eri o t�rden l value ref olmal�

	std::string str = "kaveh nematipour";

	std::cout<<str<<'\n';

	str[0] = '!';
	strd[4] = '!';

	std::cout << str<<'\n';

	�IKTI: !ave! nematipour

	const overloading operat�r overloadingte'de ge�erli

	class String
	{
		public:
			char& operator[](std::size_t idx); // const olmayan string nesnesi i�in �a��r�lacak
			const char& operator[](std::size_t idx)const; // const olan string nesnesi i�in �a��r�lacak
	
	}

	int main()
	{
		const String str;

		str[5] = 'A'; // sentaks hatas�

		char cx = str[5]; // ge�erli

	}

	int ar[5] = {10,20,30,40,50};

	for(int i = 0; i< 5; ++i)
	{
		printf(%d ", i[ar]); // normalde ar[i] olarak yazard�k derleyici b�yle bir ifadeyi g�rd���nde *(i + ar) ifadesine d�n��t�r�yor
		ar[i] *(ar + i) *(i + ar) i[ar] ifadelerinin hepsi ayn� anlamda
	}

	adres ile tam say� toplan�rsa = adres
	
	tam say� ile adres toplan�rsa = adres
	
	adres ile adres toplanamaz
		int *p1 = ar + 2;
		int *p2 = ar + 4;

		p1 + p2; // sentaks hatas�

	adresten adres ��kart�labilir bu ifadenin t�r� ptrdiff_t implementation defined derleyiciden derleyiciye de�i�iyor
		
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
			Myclass{}.func(); // ikiside ge�erli

			�yle senaryolar var ki baz� fonksiyonlar�n r value expressionla �a��r�lmas�n� istemiyoruz
					class Bigint
					{
						public:
							Bigint& operator=(int);
					}
					int main()
					{
						Bigint{} = 20 // anlam� yok ama sentaks hatas� de�il
					}

					e�er operat�r = fonksiyonuna & token� koyarsak bu fonksiyon sadece l valuelar i�in �a��r�l�r
						Bigint& operator=(int)&; // bu sefer yukar�daki durum sentaks hatas� olur buna l value reference qualified deniliyor
						
						bu fonksiyonun �a��r�lmas� i�in bu fonksiyonu �a��racak s�n�f nesnesinin l value olmas� gerekiyor
		}

		reference qualified function overloadingtede i�imize yar�yor
			class A
			{
				public:
					void func()const; // const nesneler i�in
					void func()&&; // r value nesneler i�in
					void func()&; // l value nesneler i�in

					// 3 tane ayr� overload var bu durumda en �nemlisi b�yle bir overloadingte l value olan s�n�f nesneleri i�in ba�ka bir implementasyon
					r value s�n�f nesneleri i�in ba�ka bir mplementasyon olu�turabiliriz

					ama reference qualified kullan�yorsak reference qualified olmayan bir ifade koyamay�z
						void func(); // sentaks hatas�

					reference qualified sadece memberlar i�in ge�erlidir free functionlar b�yle tan�mlanamaz

			};
*/

