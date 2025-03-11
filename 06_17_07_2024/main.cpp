/*

 dynamic_cast'in C dilinde doðrudan karþýlýðý yok inheritance(kalýtým) run time polymorphism ile ilgili bir araç ilerde bu operatörü down casting'in run time da güvenli yapýlýp
 yapýlamadýðýný sýnayacaðýz

 tür dönüþtürme operatörleri template sentaksýyla kullanýlýyor

 static_cast<target type>(operand) // <> buna angular bracket(hoca açýsal parantez diyor)
 const_cast<target type>(operand)
 reinterpret<target type>(operand)
 dynamic_cast<target type>(operand)

 açýsal parantezin içine her zaman hedef türü(target type) yazýyoruz yani tür dönüþümü hangi türe dönüþtürülmek istiyorsa o tür yazýlacak

 hoca explicit dönüþümlerle ilgili kodda bir hata ararken önce reinterpret_cast sonra const_cast en son static_caste bakmayý tercih ediyormuþ

 static_cast
     dilin mümkün kýldýðý bazý örtülü dönüþümler var ve bunlar kategorize ediliyor bu örtülü dönüþümlerden en önemlilerden belkide en sýk kullanýlanlarý 
     standart conversion deniliyor standart dönüþüm aslýnda dilin kurallarýnca legal olan dönüþümler yani örtülü olarakta yapýlan dönüþümler static_cast sadece burada
     deðil ama burada özellikle kullanmamýz gereken bir anahtar kelime yani biz dil tarafýnda örtülü olarak zaten yapýlan bir dönüþümü bilerek isteyerek yani 
     explicit olarak yapýyorsak kullanmamýz gereken operatör static_cast 

    int main()
    {
        int i1 = 190;
        int i2 = 7;

        static_cast<double(i1) / i2; // burda bölme iþlemini double olarak yapmak isteyebiliriz
    }

    double dval = 3.564;

    int ival = dval; // burda veri kaybý olur doðru kabul edilmez ama bilerek isteyerek yapýyorsak tür dönüþtürme operatörünü kullanmamýz gerek
    
    tam sayý türlerinden numaralandýrma türlerine implicit conversion yok bunu bazen bilerek isteyerek yaptýðmýz yerler olabilir
        enum Fruit {Apple,Banana,Pear};
        in main()
        {
            Fruit f = Apple;
            int ival = 3;
            f = static_cast<Fruit>(ival);
        }

     numaralandýrma türlerinden tam sayý türlerine impclicit conversion var ama doðru deðil böyle bir dönüþüm olsa dahi yinede tür dönüþtürme
     operatörlerini kullanmamýz iyi olur
        
       enum Fruit { Apple, Banana, Pear };
       int main()
       {
           Fruit f = Apple;
           int ival = 3;
           ival = static_cast<int>(f); // static_cast kullanmasak hata deðil ama doðruda bir iþlem deðil 
       }

    void* türünden void* olmayan türe dönüþüm
        int x{};
        void* vp{ &x };

        int* ip = static_cast<int*>(vp);

    özetlemek gerekirse 
        standart dönüþümler 
        farklý enum türleri arasýnda dönüþüm
        tam sayý türlerinden enum türlerine dönüþüm
        enum türlerinden tam sayý türlerine dönüþümü bilerek isteyerek yapýyorsak static_cast operatörünü kullanmalýyýz

    bir senaryo düþünelim enum türlerine karþýlýk string literalleri kullanýlmak istensin
        enum class Fruit { Apple, Pear, Banana, Cherry };
        const char* const fnames[] = { "Apple, Pear, Banana, Cherry" };

        int main()
        {
	        Fruit f{ Fruit::Banana };

	        //fnames[f]; // aslýnda burdada tam sayýya bir dönüþüm oluyor unscoped enum olsaydý hata olmayacaktý 
	        fnames[static_cast<int>(f)]; 
        }
const_cast
    referans semantiði ile ve pointer semantiði ile kullanýlabilir karþýmýza daha çok pointer ile kullanýldýðý çýkacak const_cast'in kullanýlma amacý
    const nesne adresinden const olmayan nesne adresine dönüþüm const int* -> int*  const MyClass* -> MyClass* gibi dönüþümler
    const int& -> int& buradaki dönüþüm static_cast dönüþümü ile yapýlamaz sentaks hatasý olur
        int x{};

	    const int* p = &x;
	    int* ptr;

	    ptr = p; // const_cast<int*>(p);

       pointer yada referans semantiðini kullanmazsak const_cast'i kullanamayýz

    const_cast çok riskli kullanýrken çok dikkatli olmak gerekir çünkü fiziksel olarak const olan bir nesnenin adresini const olmayan bir nesne adresi gibi kullanmak
    legalite engelini aþsakta doðru deðil

    constuluðu 2 ye ayýrmalýyýz bunlar standart'ýn kullandýðý terimler deðil
        contractual constness
            int x{4356};
            const int* p = &x; //p'nin gösterdiði nesnenin kendisi const deðil p'nin kendisi const burda adeta kontrakt imzalýyoruz p'nin kendisinden x nesnesine eriþtiðim zaman
            x'i const bir nesne gibi ele alacaðýmýzý söylüyoruz 
            
            int* ptr = p; // burda const_cast kullanmamýz herhangi bir UNDEFINED BEHAVIOUR olmaz çünkü p'nin gösterdiði nesne const deðil eðer x'in kendiside const olsaydý 
            yaptýðýmýz bu dönüþüm UNDEFINED BEHAVIOUR olurdu

        physical constness 
            const int x{4356};
            const int* p = &x; // p burda sadece contractual const deðil ayný zamanda physical const
            int* ptr = const_cast<int*>(p); // böyle bir dönüþümü kesinlikle yapmamamýz gerekir UB

            dilin kutrallarý zaten const olmayan nesne adresi türünden const olan nesne adresi türüne dönüþümede const_cast'in kullanýlmasýna izin veriyor
                int x{ 4356 };
                const int * p= const_cast<const int*>(&x); // bu dönüþüm zaten örtülü olarak yapýldýðý için ender karþýmýza çýkar

reinterpret_cast
    diðerlerine göre çok daha riskli ve çok daha dikkatli þekilde kullanmamýz gerekiyor legal olarak kullanýlmasý doðru kullanýldýðý anlamýna gelmiyor kullanýldýðý yerler
        a)bir nesne adresini farklý türden bir nesne adresiymiþ gibi kullanmak
        b)tam sayý deðerlerini adres deðerleri olarak kullanmak
   
        diðer tür dönüþtürme operatörlerinin kullanýlmasý böyle durumlarda legal deðil
        bazý durumlarda nesneleri char, signed char, unsigned char gibi elemanlara sahip dizilermiþ gibi byte byte char char dolaþmak istiyoruz bu durumda char* türüne
        yada bu char türlerinden herhangi biri için pointer türüne dönüþüm yapmamýz gerekiyor

            int x{45};
            char* p = reinterpret_cast<char*)(x); 

        yada bazen aslýnda adres olarak kullanabileceðimiz tam sayý deðer var ve bunu kullanmak istiyoruz
            int* p = reinterpret_cast<int*>(0x1AC4);

        reinterpret_cast'in kullanýlmasýný zorunlu kýlan durumlar var mesela kursun sonlarýna doðru dosya iþlemleri konusunu gördüðümüzde formatsýz okuma yazma iþlemlerinde
        tipik olarak char* türüne dönüþümün gerektiðini göreceðiz

        kýsacasý reinterpret_cast 
            ya farklý adres türleri arasýnda 
            yada bazen bir tam sayý ifadenini adres olarak kullanýlmasý gerektirdiði yerler oluyor 

        bu dönüþüm yanlýþlýkla olursa ciddi problemler olabilir

        hoca sýk yapýlan bir sentaks hatasýndan söz ediyor
            const int x = 56;
            reinterpret_cast<char*>(&x); // burda tek bir dönüþüm olmuyor iki ayrý dönüþümün gerektirdiði yerde tek bir dönüþtürme operatörüyle buý iþi yapamayýz

            reinterpret_cast<char*>(const_cast<int*>(&x));

           const_cast<char*>(reinterpret_cast<const char*>(&x)); // iki þekildede yapabiliriz            

        c'de olan type cast operatörün tam tersi c++ dilinde eskiden beri var olan explicit type cast dilin kurallarý buna functional type cast diyor
            double dval = 6.76;
            int(dval);
        
dynamic_cast
    inheritance konusunda ele alýnacak
 --------------------------------------------------------------------------------------------------------------------------------------------------
 constexpr(constant expression) specifier c de yok modern c++ ile geldi(c++11)
    derleme zamaný deðeri derleyici tarafýndan belli olan garanti altýnda olan ifadeler c diline göre c++ dilinde constant expression çok daha geniþ ve daha fazla kurala tabii

    const int x = 45; // böyle bir ifadeyi constant expression olarak kullanabilir miyiz cevap: evet yada hayýr deðil onu initialize eden ifadenin ne olduuðna baðlý

    int foo();

    int main()
    {
        const int x = 45;  // constant expression
        const int y = foo(); // constant expression deðil
    }

    constexpr bir type qualifier deðil 
        constexpr int x = 45; // x'in decleration type'ý const int constexpr anahtar sözcüðü zaten bildirimde constu ima ediyor
        constexpr const int x = 45; // ikisi arasýnda bir fark yok yani constexpr'yi kullandýðýmýz zaman constluðuda almýþ oluyoruz

    eðer constantexpr ile bir deðer oluþturursak bu deðerin constant expression olma garantisi var constexpr anahtar sözcüðünün seçilmesindeki nedende bu
    ama constexpr ile initialize edilen deðerinde constant expression olmasý gerek 

    her deðiþkeni constexpr yapamayýz sadece literal typelardan olan deðiþkenleri constexpr yapabiliriz

    auto ile constexprnin doðrudan bir ilgisi yok
        const int a = 67;
        const int b = 33;
        constexpr auto x = a + b; // burda auto için yapýlan çýkarým x deðerini constexpr int olarak nitelemekle ayný anlama geliyor
        a yada b const olmasaydý constexpr niteleyicisi ile oluþturulmuþ deðiþkene böyle bir ifadenin initalize olmasý sentaks hatasý oluþturucaktý
    
    örnek
        int x = 45;
        int y = 13;

        int main()
        {
            constexpr int* py = &x;

            py = &y; // sentaks hatasý çünkü p top level const -> constexpr int* const
            *py = 11;

            constexpr const int* p = &x; // böyle bir bildirim genelde karýþtýrýlýyor burda p hem low level const hemde top level const olmuþ oluyor

            *p = 11;  // artýk hata verir

            yani constexpr bir deðer pointer yada referans olduðunda top level constluðu satýn alýr referans yada pointer olmadýðý durumlarda
            low level constluðu satýn alýr

        }

    constexpr'yi biraz daha karmaþýk kýlan deðiþkenleri deðil fonksiyonlarý nitelemesi bir fonksiyonu constexpr yaparsak böyle fonksiyonlara constexpr function deniyor
        constexpr int func(int x)
        {
            return x * x + 5;
        }

        baþlarda çok kýsýtlama varmýþ c++23 ile birlikte neredeyse kýsýtlama kalmamýþ ama hala var
        kýsýtlamalrdan biri literal type ile ilgii bir constexpr fonksiyonun parametre deðiþkenleri yada deðiþkeni fonksiyonun geri dönüþ deðeri türü fonksiyonun içinde
        tanmlanan yerel deðiþkenler bunlar literal type olmak zorunda

    fonksiyonun constexpr olmasý þöyle bir garanti içeriyor 
        böyle bir fonksiyona yapýlan çaðýrda fonksiyonun tüm parametre deðiþkenlerine gönderilen argümanlar constant expressionsa fonksiyon çaðrý ifadesi constant expression
        gereken bir yerde kullanýldýðýnda fonksiyonun geri dönüþ deðeri derleme zamanýnda elde edilmek zorunda 
        not:fonksiyona gönderilen ifadelerin constant expression olma zorunluluðu yok
            
        constexpr int func(int x)
        {
	        return x * x + 5;
        }

        int main()
        {
	        int a[func(12)]; // int a[149] ile yazmak ayný
        }

    hoca yanlýþ anlaþýlan yere deðiniyor
        bu mecburiyet constexpr fonksiyona yapýlan çaðrýnýn const expression gereken yerde kullanýlmasý durumunda garantisi var,
            int a = func(12) + func(5); // buradaki elde edilen deðerlerin compile timeda elde edilmesi garantisi yok derleyici bunu compile timedada elde edebilir
            etmeyebilirde bu optimizyon sadece bu normal fonksiyonlardada var ama a deðeri constexpr olsaydý compile timeda elde edilme garantisi vardý

            yani burda sadece fonksiyonunda consexpr olmasý yetmiyor kullanýldýðý ifadeninde constant expression olmasý lazým
            constexpr int a = func(12) + func(5); // derleyici artýk burda a'nýn deðerini compile timeda elde etmek zorunda
   
    constexpr fonksiyonlar ve deðiþkenler implicitly inline ODR'ý ihlal etmezler
    not:constexpr fonksiyonlar run time ile de alakalý olabilir

    c++20 ile consteval anahtar sözcüðü eklendi bu tamamen compile time ile ilgili

    constexpr fonksiyon sabit ifadesi üreten bir yerde kullanýldýðýnda undefined behaviour oluþtuðu durumda derleyici sentaks hatasý verir
    deðerlerin doðrudan compile timeda hesaplanmasý bazý iþlemlerin run timeda hesaplanmasýnýn önüne geçiyor özellikle generic programlamada böyle durumlar çok önemli

    constexpr bildirimde ve tanýmda olmak zorunda
     necati.h
       constexpr bool isprime(int);
    necati.cpp
        constexpr bool isprime(int x);
 --------------------------------------------------------------------------------------------------------------------------------------------------
 hoca eksik olunan bir yere dikkat çekiyor comma(virgül) token'ý virgül hem bir operatör hemde delimeter olarak kullanýlýyor(comma seperator list)
 karýþtýrýlan yer ise hangi virgül operatör virgül ve hangi virgül delimeter virgül

 () parantez bazý yerlerde operatör bazý yerlerde sentaksýn bir bileþeni bazý yerlerde ise öncelik parantezi olarak kullanýlýyor
     Parantez içinde hangi deðer varsa o deðerin value kategorisi odur

     int x = 50;

     (x) // l value

 bazý  durumlarda parantez sentaksýn gerektirdiði parantez mi yoksa öncelik parantezi mi diye karýþtýrýlabiliyor
    int x = 6;
    auto sz = sizeof(x); // öncelik parantezi eðer sentaksýn gerektirdiði bir parantez olsaydý sizeof x; þeklinde bir kullaným sentaks hatasý oluþtururdu
    sizeof(int) burada ki parantez artýk sentaksýn gerektirdiði parantez

NOT:Functional type casting
    double dval = 6.76
    int(dval);
--------------------------------------------------------------------------------------------------------------------------------------------------
c++ dilinde standart olan digit seperator
    sabitlerin yazýmýnda yazamyý ve okumayý kolaylaþtýrmak için kullanýmasý
    auto x = 761243678 // gibi bir þey yazsak görsel olarak algýlamak hiç kolay deðil
    x = 761'243'678 þimdi okumasý daha kolay

    diðer sayý sistemlerinin hepsinde de kullanýlabilir
    auto x = 0x1AC4'2345;
    auto x = 0b101'0101;
--------------------------------------------------------------------------------------------------------------------------------------------------
attribute(hoca öznitelik diyor) modern c++ ile eklenen önemli bir özellik
    özel bir sentaksla oluþturulan yapýlardýr [[nodiscard]] gibi sentaks biçimi vardýr bazý yerlerde derleyiciyi uyarý vermeye teþvik ediyor
    bazen uyarý vermesini engelliyor bazý attirbutelar daha iyi optimizasyon yapmamýzý saðlýyor

    baþlangýç seviyesinde iþimize yarayacak olan [[nodiscard]] attribute çok önemli
        bir fonksiyonun geri dönüþ deðerinin olmasý o fonksiyonun geri dönüþ deðerinin kullanýlma mecburiyetini vermiyor
            int func(int)

            int main()
            {
                func(12); // böyle yaparak fonksiyonun geri dönüþ deðerini dicard etmiþ oluyoruz yani geçersiz kýlmýþ oluyoruz SORU:burada logic hata var mý? deðiþir
                fonksiyonun geri dönüþ deðerinin ne olduðuna baðlý mesela printf("necati") printf karakter sayýsýný döndürüyor bunu bir deðiþkende tutsaydýk 6 sayýsýný elde ederdik
                yani geri dönüþ deðeri iþimize yaramadýðý için kullanmýyoruz burda discard etmiþ oluyoruz

            }

    bazý fonksiyonlarýn tek farklýlýk nedeni bir hesaplama yapmak program state'inde de bir deðiþiklik oluþturmuyor böyle fonksiyonlara pure function deniyor

    bool isprime(int);

    inr main()
    {
        int x = 7321;
        isprime(x); // bu fonksiyon pure function olduðu için logic bir hata var geri dönüþ deðerini kullanmamýz gerek
    }
        [[nodiscard]]
    bool ispirme(int); // burada [[nodiscard]] atrribute'u ben bu fonksiyona çaðrý yaptýðýmýzda eðer bu fonksiyonun geri dnüþ deðerini kullanmýyorsak
                          bana uyarý mesajý ver anlamýnda kullanýlýyor 
--------------------------------------------------------------------------------------------------------------------------------------------------
function overloading(fonksiyonlarýn yüklenmesi)
    hoca fonksiyonlarýn aþýrý yüklenmesi terimini kabul etmiyor kulaða kötü bir þeymiþ gibi geldiði için hoca buna fonksiyonlarýn yüklenmesi diyor
    function overloading dediðimiz araç belirli koþullar altýnda fonksiyonlarýn ayný isim ve farklý kodlara sahip olmasýna raðmen ayný ismi paylaþmasýný mümkün kýlýyor

    1)function overloading ne iþe yarýyor?
        eðer soyutlandýklarý zaman farklý kodlara sahip olmasýna raðmen soyutlamayla ayný iþi yapýyorsa onlarýn isimlerinin ayný olmasý böyle fonksiyonlara çaðrý yapan
        programcýnýn iþini kolaylaþtýrýyor c dilinde örneðin mutlak deðer fonksiyonu abs -> fabs ->labs bunlara baktýðýmýzda hepsi mutlak deðer fonksiyonu
        isimleri farklý çünkü c de function overloading yok aslýnda hepsi ayný iþi yapýyor sadece parametreleri ve geri dönüþ deðerleri farklý int,float,long gibi

        ayný ismi verdiðimiz ortak bir soyutlama yapmýþ oluyoruz neyin mutlak deðerini hesaplarsak hesaplayalým çaðýracaðýmýz fonksiyon abs() yine ayrý fonksiyonlar var ama 
        hepsinin ismi ayný böyle bir fonksiyona çaðrý yaptýðýmýzda derleyici compile timeda fonksiyona gönderilen argümanlarýn türünden ve sayýsýndan hareketle 
        n tane abs isimli farklý koda sahip fonsiyondan hangsinin çaðýrýldýðýný compile timeda anlýyor ve fonkisiyon çaðrýsýný o fonksiyona baðlýyor konunun en zor 
        kýsmý derleyicinin bu iþi gerçeleþtirdiði süreç buna FUNCTION OVERLOAD RESOLUTION deniliyor   

    2)function overloading compile time'a yönelik(static binding)
        fonksiyonlarýn hangisinin çaðýrlacaðý compile time'da belli oluyor
        
    bir fonksiyon çaðrýsýnýn hangi fonksiyona baðlanacaðý(bind)
        a)derleme zamanýnda anlaþýlýyorsa
            popüler olarak static binding yada early binding deniliyor
        b)çalýþma zamanýnda anlaþýlýyorsa(inheritance konusunda görülecek)RUN TIME POLYMORPHISM
            dynamic binding yada late binding deniliyor

    hoca bu konuyu öðrenmeyi zorlaþtýran duruma deðiniyor
        function overloding var mý yok mu
            bu sorunun cevabý ya var ya yok tipik olarak karýþtýrýlan þu
            function overloading var bir fonksiyon çaðrýsý yapýlmýþ o fonksiyon çaðýrýsyla biz birden fazla ayný isimli fonksiyondan hangisini çaðýrmýþ oluyoruz
            burdada function overlaod resolution devreye giriyor

    function overloadingin olmasý için gerekli koþullar
        1)fonksiyonlarýn isimlerinin ayný olmasý gerek
        2)ayný scopeta olmalarý gerek
        3)imzalarýnýn farklý olmasý gerek
            int foo(int,int); // 2 parametre deðiþkene sahip olmasý imzaya dahil oluyor fonksiyonun geri dönüþ deðerinin int olmasý imzaya dahil deðil

    özellikle function overloading oluþturmayan durumlarý iyi anlamaýz gerekiyor eðer ayný isimli fonksiyonlar var ve function overloading söz konusu deðilse
    ve ayný scopetaysa 2 tane ihtimal var ya sentaks hatasý ikinci bir bildirim ayný isimle geçerli deðil yada re-decleration en çok karýþtýrýlan noktalardan biride bu

    fonksiyonlarýn imzalarýda geri dönüþ deðeri türleride aynýysa re-decleration
        int foo(int);
        int foo(int);

    eðer imzalar ayný geri dönüþ deðeri türü farklýysa sentaks hatasý olur
        int foo(int);
        double foo(int);

    sorular:
    1)
        int foo(int);
        int foo(const int); //re-decleration overloading deðil pointer yada referans olsaydý const overloading olurdu
        eðer function overloading olsaydý zaten derleyici her ikisinin de tanýmýný yaptðýmýzda sentaks hatasý vermezdi
    
        int foo(int)
        {
            return 1;
        }

        int foo(const int) // parametre pointer yada referans deðilse bildirimsel bir fark oluþturmuyor
        {
            return 3;
        } 
    2)
        void foo(int* p)
        void foo(int* const p) // re-decleration asteriks operatöründen sonra burda parametre deðiþkeninin kendisi const 
        foo(const int *p); eðer böyle olsaydý pointerýn kendisi const olduðu için function overloading olurdu
    
    3)
        void func(char);
        void func(signed char);
        void func(unsigned char); // 3 adet function overloading var bunlarýn hepsi ayrý türlerdir 

    4)
        typedef int Word;
        void foo(int);
        void foo(Word); // re-decleration

    5)
        void foo(int32_t);
        void foo(int); // derleyiciye göre deðiþir çünkü int32_t baþka derleyicilerde hiç olmayadabilir ama varsa derleyiciye baðlý bizim derleyicimizde int32_t int türü
        olduðu için re-decleration

*/