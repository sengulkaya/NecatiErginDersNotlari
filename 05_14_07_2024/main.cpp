/*

scope isimlere yönelik bir kavram(ıdentifiers)

c++ dilinde 5 tane scope kategorisi var
    namespace scope(file scopeu da içerir)
    block scope(otomatik ömürlü değişekenler)
    function scope (goto labelları)
    function prototype scope void foo(int x); bu isim sadece bu scope içinde bilinir aynı isimli değişken tanımlanamaz
    class scope
--------------------------------------------------------------------------------------------------------------------------------------------------
name lookup
    bir ismin neyin varlığının karşılığı olduğunun anlaşılması

    önce namelookup yapılır(isim bir kere bulunduğunda name lookup biter)
        sonra context control(dilin kurallarının çiğneyen bir durum var mı yok mu diye bakar)
            en son access control(private,protected)

name lookup
    a)başarılı olabilir
        başarılı olursa derleyici aranan ismin hagi varlığa ait olduğunu anlamıştır
    b)başarısız olabilir
        aranan ismin hangi varlığa ait olduğunu anlşamamış demek ve aranan ismin bulunamaması her zaman sentaks hatası
    c)name lookup neden başarısız olabilir
        isim bulunamaması(x undecleard ıdentifıer)
        ambiguit(ambigious)(derleyicinin ayrım yapamaması) isim arama yine başarısız olur isim bulunur ama çift anlamlılık hatası verir
            int x(int);
            int x(double);
            x(5u); // implicit conversion olduğu için ikisi arasında karar veremiyor

name lookup ile ilgili 2 altın kural var hoca böyle diyor
    1)isim arama bir sıra halinde yapılır
        içten dışa doğru arama yapılır
    2)aranan isim bulununca isim arama biter ve bir daha başlamaz
        int x(int);
        int main()
        {
             int x = 5; // isim arandı bulundu bir değişkenin ismi olduğunu anladı ve sona erdi
             //x değişkeni burda x fonksiyonunu gizlemiş oluyor buna name hiding,name masking,name shadowing deniliyor hepsi aynı anlamda
             x(12); // context control

            farklı scopetaki isimlerin aynı olması sentaks hatası değil ama x ismini aradağımız zaman bu bloktaki x bulunur
            bazı derleyicilr bu durumda uyarı verebilir
        }

--------------------------------------------------------------------------------------------------------------------------------------------------
C dilinde bilinirlik alanlarının dörde ayrıldığını anımsayın. Bunlar dardan genişe doğru “işlev bildirim bilinirlik
alanı” (function prototype scope), “blok bilinirlik alanı” (blok scope), “işlev bilinirlik alanı “(function scope)
ve “dosya bilinirlik alanı” (file scope) dır.
Blok bilinirlik alanı bir ismin yalnızca bir blok içinde, işlev bilinirlik alanı bir işlevin her yerinde, dosya bilinirlik
alanı ise tüm işlevler içinde bilinmesi, kullanılabilmesi anlamına gelir. C++‟da bu bilinirlik alanlarına ek olarak
bir de sınıf bilinirlik alanı (class scope) tanımlanmıştır. Sınıf bilinirlik alanı, bir ismin hem sınıf bildirimi içinde,
hem de sınıfın tüm üye işlevleri içinde bilinmesidir. Sınıfın elemanları ile üye işlevleri, sınıf bilinirlik alanı
kuralına uyar. Sınıf bilinirlik alanının darlık – genişlik bakımından işlev bilinirlik alanı ile dosya bilinirlik alanı
arasında bulunduğuna dikkat edin. Bu durumda C++‟daki bilinirlik alanları dardan genişe doğru,
1. İşlev bildirimi bilinirlik alanı (function prototype scope)
2. Blok bilinirlik alanı (block scope)
3. İşlev bilinirlik alanı (function scope)
4. Sınıf bilinirlik alanı (class scope)
5. isim uzayları alanı (namespace scope) -> file scopuda içerisine alıyor
biçimindedir. Şimdi de aynı isimli değişkenlerin durumuna bir göz atalım: Aynı isimli değişkenler konusunda şu
kuralı anımsatalım: C‟de(C dilinde) olduğu gibi C++‟da aynı bilinirlik alanına ilişkin aynı isimli birden fazla
değişken tanımlanamaz. Fakat farklı bilinirlik alanına ilişkin aynı isimli birden fazla değişken tanımlanabilir. Bir
blok içinde aynı isimli birden fazla değişken etkinlik gösteriyorsa, o blok içinde dar bilinirlik alanına sahip olana
erişilebilir.

Aşağıdaki örneği inceleyin:
#include <iostream>
void func(); //işlev bildirimi
int a = 50; //global değişken
class X {
public:
void foo(int);
void func();
private:
int a;
};
using namespace std;
void X::func()
{
cout << "X sınıfının func isimli üye işlevi…" << endl;
}
void func()
{
cout << "Global func isimli işlev…" << endl;
}
Bu örnekte hem a isimli global bir değişken tanımlanıyor, hem de X sınıfının a isimli bir elemanı var. Sınıfın
foo üye işlevi de şöyle tanımlanmış olsun:
void X::foo(int a)
{
cout << a << endl; // Parametre değişkeni olan a
{
int a = 30;
cout << a << endl; // Blok içindeki a
}

func(); // Üye işlev olan func
}
Şimdi dört tane a söz konusu. Global olan a, sınıfın elemanı olan a, parametre değişkeni olan a ve iç blokta
tanımlanmış olan a. Dar bilinirlik alanına sahip olana erişme kuralına göre, iç blokta kullanılan a o blokta
tanımlanan a değişkenidir. Dış bloktaki ise işlevin parametre değişkenidir. Çağrılan işlev üye işlev olan func isimli
işlevdir. Çünkü işlev isimleri de değişken gibi ele alınır, aynı bilinirlik alanı kuralında uyar. Global işlevler dosya
bilinirlik alanına, üye işlevler ise sınıf bilinirlik alanına sahiptir. Şimdi foo işlevinin parametre değişkeninin ismini
değiştirelim:
void X::foo(int x)
{
a = x; // Sınıfın elemanı olan a
{
int a = 30; // Blok içindeki a
cout << a << endl;
}
func(); // Üye işlev olan func
}
Şimdi dış bloktaki a, sınıfın elemanı olan a olarak ele alınır. Peki, bir üye işlev içinde sınıfın elemanları ya
da üye işlevleriyle aynı isimli global değişkenlere ya da işlevlere erişmek mümkün olabilir mi? İşte
çözünürlük işleci ile bu durum mümkün kılınmıştır.
--------------------------------------------------------------------------------------------------------------------------------------------------
scope resolution operator(C de yok)
    SCOPE RESOLUTİONU UNARY OPERATOR ŞEKLİNDE KULLANDIĞIMIZDA İSİM ARAMA DEVREYE GİRMEZ DİREKT OLARAK GLOBAL NAMESPACETE OLAN DEĞERE ULAŞMAMIZI SAĞLAR

     ::x ->  unary operator
     class::x -> binary operator

     int x = 5;
     int main()
     {
        int x = 10;
        std::cout<<::x<<'\n';// global namespace
        std::cout<<x;// block scope
     }

     BINARY OPERATOR ŞEKLİNDE KULLANMAK İSE CLASS NAMEPSACE GİBİ ALANLARDA KULLANILIR

     ClassA::ClassB

qualified name(nitelenmiş isim):

    bir isim ya qualified namedir yada unqualified namedir
    ismin qualified olması bu operatörlerin operandı olarak kullanılması demek
    a.b
    p->x
    ::a // unary scope resolution
    x::y // binary scope resolution

    bu kullanımların her biri qualified namedir
    bunları kullanmıyorsa yani normal olarak kullanılıyorsa a gibi unqualified namedir

ÖRNEK:
    int x = 5;

    int main()
    {
        int x = x; // self assigment isim arama yapılır bulunur(UNDEFINED BEHAVIOUR kendi çöp değeri ile ilk değer vermiş oluyoruz)
        int x = ::x; // doğru kullanım
    }
ÖRNEK:
    void foo(int foo)
    {

        foo(foo); // recursive fonksiyon çağrısı başarısız olur çünkü isim arama kurallarına göre derleiyici ilk block scopeta arama yapar foo parametresi
                     bloce scopeta olduğu için  fonksiyonun ismi olarak görmez foo fonksiyonu ise namespace scopeta(global scope) global isim maskeleniyor
                     terms does not evaluate to a function taking 1 arguments bunun bir fonksiyon ismi olmadığını söylüyor

        ::foo(foo); -> global fonksiyonu recursive olarak çağırmak istiyorsak unary scope resolution operatorü kullanmalıyız
    }

ÖRNEK:
    int main()
    {
        int x = 62;

        if(x > 10)
        {
            double x = 5.6; // dış blokta olan x değişkenini maskeler
            x++; // double olan değişken arttırılır
        }
    }
-------------------------------------------------------------------------------------------------------------------------------------------------
source file ile translation unit karıştırılıyor
    source file
        preprocessor direktiflerinin yürütülmemiş hali
    translatioun unit
        derleyicinin gördüğü kod artık preprocessor direktifleri işlenmiş durumda sıra derleyice geliyor
        tüm kodların sanki aynı cpp dosyasında toplanması gibi
-------------------------------------------------------------------------------------------------------------------------------------------------
Translation Unit nedir(Çeviri Birimi):

Translation Unit
derleyicinin tek bir derleme işleminde ele aldığı en küçük mantıksal koddur. Bir çeviri birimi, bir kaynak dosya ve onun doğrudan
veya dolaylı olarak include ettiği tüm başlık dosyalarından (header files) oluşur.

Örneğin, example.cpp dosyasını derlediğimizde, derleyici bu dosyayı ve onun include ettiği <iostream> başlık dosyasını tek bir çeviri birimi olarak ele alır.

Çeviri Biriminin İşleyişi:

Kaynak Dosya + Başlık Dosyaları: Derleyici, kaynak dosyayı ve include edilen tüm başlık dosyalarını bir araya getirir.
Preprocessing (Ön İşleme): Makrolar genişletilir, koşullu derleme yönergeleri işlenir ve include edilen dosyalar eklenir.
Compilation (Derleme): Ön işleme sonrası oluşan tek bir dosya derlenir.
Object File (Nesne Dosyası): Derleme sonucu bir nesne dosyası oluşturulur (genellikle .o veya .obj uzantılı).

Örnek Senaryo
Aşağıda, iki kaynak dosya (main.cpp ve functions.cpp) ve bir başlık dosyası (functions.h) ile bir proje örneği verilmiştir:

main.cpp

#include <iostream>
#include "functions.h"

int main() {
    int a = 5, b = 10;
    std::cout << "Sum: " << add(a, b) << std::endl;
    return 0;
}
functions.cpp
#include "functions.h"


int add(int x, int y) {
    return x + y;
}
functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int add(int x, int y);

#endif // FUNCTIONS_H

Çeviri Birimleri:

main.cpp dosyasını derlediğimizde, derleyici main.cpp ve functions.h dosyalarını tek bir çeviri birimi olarak ele alır.
functions.cpp dosyasını derlediğimizde, derleyici functions.cpp ve functions.h dosyalarını tek bir çeviri birimi olarak ele alır.
Sonuç olarak, bu iki çeviri birimi ayrı ayrı derlenir ve iki nesne dosyası (main.o ve functions.o) oluşturulur. Daha sonra bu nesne dosyaları,
linker (bağlayıcı) tarafından bir araya getirilir ve çalıştırılabilir bir program (örneğin, a.out veya program.exe) oluşturulur.

Özet
Çeviri Birimi (Translation Unit): Bir kaynak dosya ve onun include ettiği tüm başlık dosyalarından oluşan,
derleyicinin tek bir derleme işleminde ele aldığı en küçük mantıksal birimdir.

Source file ile Translation Unit Farkları

Özellik	Source  |     File (Kaynak Dosya)	            |       Translation Unit (Çeviri Birimi)
Kapsam	        |Yalnızca .cpp dosyasını ifade eder.    |cpp dosyası ve onun eklediği tüm dosyaları kapsar.
İşlenme Aşaması |Preprocessor öncesi dosya.	            |Preprocessor sonrası işlenen birim.
Birleşme Durumu	|Diğer kaynak dosyalardan bağımsızdır.	|İçerik bakımından genişletilmiş ve bağlanmaya hazırdır.
Örneklendirme	|Yazdığınız temel kod dosyasıdır.	    |Derleme sırasında derleyicinin işlediği içerik.

Sonuç
Source file: , programınızın fiziksel olarak yazıldığı dosyadır.
Translation Unit:, bu kaynak dosyanın preprocessor aşamasından geçip, eklenen tüm içerikleri bir araya
getirilmiş haliyle derleyiciye sunulmuş genişletilmiş versiyonudur.
--------------------------------------------------------------------------------------------------------------------------------------------------
ODR(One Definition Rule) tek tanımlama kuralını bilmemiz gerekiyor bunun gibi daha bir çok akronim var
    ODR link aşaması ile ilgili proje içinde sadece ve sadece bir tane tanımı olabilir ikinci bir tanımın olması dilin kurallarına aykırıdır ama birden fazla bildirimi olabilir
    c++ dili decleration ile definition arasında farklılık görüyor her decleration bir definition değildir ama her bir definition bir declerationdur
    proje içinde birden fazla definition olamaz ama birden fazla declerations olabilir

    kaveh.h
        int x = 0;

    yiğt.cpp
        include "kaveh.h"

    berkay.cpp
        include "kaveh.h"

    iki farklı cpp dosyasında kaveh.h include edildiği için ODR çiğnenmiş oluyor aslında x iki defa tanımlanmış oluyor

    ODR'da fonksiyonlar ve global değişkenlerin birden fazla definitionu olamaz
    ODR'ın aynı kaynak dosyada çiğnenirse doğrudan sentaks hatası
        int x = 5;
        int x = 456;

        int foo(int x) { return x * 5;};
        int foo(int x) { return x * 20;}; // ODR çiğnendi bir fonksiyonun 2 defa definitionu yapıldı
    aynı isimde oldukları için farklı cpp dosyalarında birbirini include etmese bile ODR yine çiğnenmiş olur

    ODR'ın ihlal edilmediği durumlar
        inline functionslarda inline variablelar constexpr anahtar kelimesi ile nitelenenler ve temlate definitionda ihlal edilmez
--------------------------------------------------------------------------------------------------------------------------------------------------
inline expansion ile inline function çok karıştırılıyor
    inline expansion
        derleyicinin kullandığı optimizasyon tekniğidir
            int sum_square(int x,int y)
            {
                return x * x + y * y;
            }
            int main()
            {
                int a = 10; b = 5;
                int c = sum_square(a,b);
            }
            derleyici burda gereksiz makina kodlarını çalıştırmak yerine arka planda madem ben bu fonksiyonun kodunun görğyorum
            o zaman sanki bu kodu şöyle yazılmış gibi ele alabilirim -> c = a * a * * b * b; böyle bir durumda çağırılan bir fonksiyon olmayacağı için
            derleyicinin ürettiği kod çok daha etkin olucak ama burda önemli olan derleyicinin fonksiyonun tanımını görmesi bu işlemler compiler timeda olan bir işlem

            1)derleyici tanımı görmek zounrda
            2)her fonksiyon için inline expansion avantaj sağlamaz derleyicinin burda analiz yapması gerekiyor fonksiyonun kodu büyükse kontrol deyimleri fazlaysa
             recursive çağrılar çoksa derleyicinin inline expansion yapması felaket olabilir
            3)derleyici inline expansion yapmak isteyebilir ama yapamayabilir
                burda derleyici yazanların yeteneğine göre belirlenir
            4)derleyicinin bu konuyla ilgili switchleri var
                bazı seçeneklerle derleyicinin inline expansion yapmasını zorlayabiliriz
inline functions
    bir fonksiyonun tanımında inline anahtar sözcüğünün kullanılması derleyiciye inline expansion yapma zorunluluğunu vermiyor derleyiciye bağlıdır
    inline anahtar sözcüğü olmasa bile inline expansion yapmaz diyede bir kural yoktur inline anahtar kelimesi olmasa bile yinede inline expansion yapabilir görünüşte saçma gözüküyor
    inline olarak kullanmamızın asıl nedeni ODR'ın çiğnenmemesi

    birden fazla kaynak dosyada inline fonksiyon aynı şekilde tanımlanırsa ODR çiğnenmez

        ahmet.cpp
            inline int sum_square(int x,int y)
            {
                return x * x + y * y;
            }
        ayşe.cpp
             inline int sum_square(int x,int y)
            {
                return x * x + y; // fonksiyonlar aynı olmadığı için ODR çiğnenmiş olur
            }

    birden fazla kaynak dosya bu fonksiyonu include edebilir ve ODR çiğnenmez
    bir fonksiyonu inline olarak tanımını bir başlık dosyasına koyarsak bunu include eden bütün kaynak dosyalarda derleyici
    bu fonksiyonun tanımını görme garantisi elde ediyor buda şu demek derleyicie bir fonksiyon için inline expansion şansı vermiş oluyoruz yapar mı yapmaz mı derleyiciye bağlı
    burda derleyici fonksiyonun tanımını görmek zorunda ama tanımını inline olmadan başlık dosyasına koyarsak bu durumda ODR ihlal edilmiş olucak

    inline functionlar ile header only library oluşturabilir

    bütün fonksyonları inline yapmak iyi bir şey olmayabilir ama kodu küçük ve sık çağırılan fonksiyonlar varsa inline olması avantaj sağlayabilir
    başlık doyasında fonksiyonun sadece bildirimi olursa inline expansion şansı olmaz

    derleyici inline fonksiyona inline expansion yaparsa fonksiyonun derlenmiş hali derlenmiş kodda bulunmak zorunda değil

    eğer ODR çiğnenseydi oluşacak kötü durum şuydu mesela 3 tane başlık dosyası olsun ahmet.h mehmet.h mert.h derleyici bu başlık dosyasındaki fonksiyonların tanımını gördüğü için
    bu fonksiyonun kodunu derlemek zorunda olsa yani inline expansion yapmamış olsa kodun derlenmiş halini oluştursa aslında 3 tane ayrı kaynak dosya 3 tane ayrı derlenmiş
    kod üretecek bu durumda link aşamasında bu fonksiyonlardan 3 ayrı kopya olmuş olacaktı buda aslında şu demek inline expansion yapılmaması durumunda
    bu fonksiyonların adresi kullanılsa aynı adres kullanılmış olucak

    static olarak fonksiyon tanımını yaparsak internal linkage'a sahip olduğu için ODR çiğnenmez ama başlık dosyasını
    include eden her kaynak dosyanın ayrı bir foo fonksiyonu olucaktı ve hepsinin adresi farklı olucaktı

    derleyici hem bildirimde ve hem tanımda inline tanımını görüyorsa bildirimde yada tanımında olması yeterli ikisinde olması hata değil
    en az bir yerde olması inline kelimesini görmesi onu inline fonksiyon yapmaya yetiyor

    c de ki inline ile c++da ki aynı değil
--------------------------------------------------------------------------------------------------------------------------------------------------
inline variable(C++17 ile geldi)
    inline functions ile yapı aynı o yüzden yazmadım

    inline değişkenler olmadığı zaman ufak bir hile kullanılıyordu global bir değişken kullanmak yerine referans yada adres döndüren inline fonksiyon tanımlamak
    static yerel değişken tanımlamak
        inline int& foo()
        {
            static int x = 10;
            return x;
         }
    global değişkenleri tabiri caizse ehlileştirmiş oluyoruz

    inline olması benzer şekilde tanımlanmış olmasına rağmen adresi kullanılırsa run timeda aynı adres olucak
    5 tane ayrı kaynak dosyada da böyle bir değişken olsa 5'i de aynı varlığa ait olucak yani adresleri aynı olmuş olucak


--------------------------------------------------------------------------------------------------------------------------------------------------
unscoped enumların istenmeyen 3 özeliği(traditional ve conventional enumda deniliyor)

    1)implicit type conversion
        enum türünden aritmetik türlerine örtülü dönüşüm olması

        enum Color{
        White,Gray,Blue,Black
        };

        Color mycolor = Blue;

        int x = mycolor;

    2)underlying type olarak kullanılmaması -> yani derleyiceden derleyice farklı olması başka bir derleyicide int iken başka bir derleyicide long olabilir
        bu yüzden incomplete type olarak kullanamıyoruz

        enum Color; // forward decleration

        struct Nec
        {
            Color c; // Struct nec'in complete type olması gerekiyor complete type olması için derleyicinin Color türünün sizeof değerini bilmesi gererkiyor
        }
          eğer derleyici bu noktada enum Colorın underlying type'ını bilseydi bu kodun derlenmesinde herhangi bir sorun olmayacaktı

        underlying type hem unscoped enumlar(modern C++ ile unscoped enumlara geldi öncesinde yoktu) için hemde scoped enumlar için kullanılıyor enum Color : int

     3)scope problemi -> enum classlar yani (scoped enumlar bu sorunu çözüyor)
       C den kurallarla unscoped enunların ayrı bir scopu yok başka bir White veya Gray ismi aynı scopeta varsa sentaks hatası olucak
       sanki bunlar o scopeta global olarak tanımlanmış gibi davranıyor

     berkay.h
         enum Color{ White,Gray,Blue,Black};

     furkan.h
         enum ScreenColor{ White,Gray,Blue,Black};

      aynı kod dosyasında include edersek Color ile ScreenColor'ın görünürlüğü aynı isim çakışması olur sentaks hatası verir
      yani aynı scope içinde aynı ismin birden fazla varlığa verilmesi sentaks hatası

      bu problemle baş etmek için programcılar bazı teknikleri kullanmak zorunda kalıyordu bunlara ön ekler ekleyerek çakışma riskini
      en aza indirmeye çalışıyorlardı

      enum TextWindowColor{ TextWindowColorWhite,TextWindowColorGray,TextWindowColorBlue,TextWindowColorBlack};
      enum ScreenColor{ ScreenColorWhite,ScreenColorGray,ScreenColorBlue,ScreenColorBlack};

      ama buda isimleri karmaşık hale getiriyor ve okumayıda azaltıyor
      başka bir teknik daha ise bunları ayrı isim alanları içine almak yada ayrı sınıfların nested typeları yapmak

scoped enumlar(kapsamlandırılmış numaralandırma türleri)
    enum class Color {Blue,Red,Brown,Black}; // undrlying type'ı belirtmezsek default olarak int olarak belirtmiş oluyoruz(unscoped enumlara modern c++ ile eklendi)

    bu isimleri nitelenden kullanma şansımız yok

    Color mycolor = Blue; // direkt böyle kullanamıyoruz bunu kullanmak için scope resolution operatörünü binary olarak kullanmamız gerekiyor

    Color mycolor = Color::Blue;

    böylelikle farklı scopelardan gelen isimlerle çakışmayacak

    traffic.h
        enum TrafficLight{Red,Yellow,Green};

    widget.h
        enum ScreenColor{White,Gray,Red,Blue,Black}; // unscoped enumlar kullanıldığı için ikisindede Red ismi olduğu için isim çakışması oluyor scoped enumları kullanırsak
        scopeları farklı olmuş olucak

    auto x = TrafficLight::Red; // TrafficLight x
    auto y = ScreenColor::Red;  // ScreenColor y

    unscoped enumlarda olan numaralandırma türlerinden artimetik türlere olan implicit conversion
    scoped enumlarda geçerli değil

        TrafficLight t1 = TrafficLight::Red;
        int x = t1;

     bilerek isteyerek dönüşüm yapıyorsak type cast operatörlerini kullanabilirdik

        int x = static_cast<int>(t1); // her hangi bir sentaks hatası değil bilerek isteyerek yaptık

    unscoped enumlarda da scope resolution operatörü binary olarak kullanılabilir ama bu onun ayrı bir scopa sahip olduğu anlamına gelmiyor

    scoped enumlarda class anahtar sözcüğü kullanmamız onun bir class olduğu anlamına gelmiyor bunu karıştırmayalım

    scoped enumlar çıktıktan sonra unscoped enumları kullanmaya hitiyaç yok denebilir eğer legacy(eskiden yazılmış kodlar) bir kod değilse kullanmamak en iyisi

C++ 20 ile using keywordü enum türleriyle beraber kullanılabilir hale geldi
    scoped enumların kendi scopelarının olması kodlarda bunların nitelenmiş isim olarak kullanılma zorunluluğu kodda ki Verbosity'i(karmaşıklığı) arttırdı

    enum class Suit {Club,Diamond,Heart,Spade}; // using enum decleration deniyor

    void func(Suit x)
    {

        using enum Suit; // Suit enum'ı için sanki onun scopunu kaldırıyoruz nitelemeden kullanılma zorunluluğunu ortadan kaldırıyoruz
        yani sadece func fonksiyonunun scopu içinde bu şekilde kullanılacağını belirtmiş oluyoruz

        x = Club;

        auto y = Diamond;
    }

    veya tüm numaralandırma sabitlerini kullanmak yerine birini yada ikisini kullanmak istiyoruz using Suit::Diamond,Suit::Hearth gibi kullanabiliriz

    enum türü namespace içinde nested type olsaydı

        namespace Neco
        {
            enum class Suit {Club,Diamond,Heart,Spade};

        }

     using enum Neco::Suit; // tüm numaralandırma türlerini kunitelemeden llanmak için
     using Neco::Suit::Diamond; // spesifik olarak belirttiğimiz numaralandırma türünü kullanmak için

type cast operatörleri
    eğer bir dönüşümü dilin kuralları gereği örtülü olarak yapmıyorsak bu explicit type conversion deniyor
    static_cast
    const_cast
    reinterpret_cast
    dynamic_cast

c-tipi type cast(C++ dilindede geçerliliğini koruyor)
    (int)dval;
    bunu kullanmak yerine C++ dilinin type cast öoperatörlerini kullanmayı tercih etmemiz gerekir

    C dilinde genel sorun tür dönüşümünün neden yapıldığı direkt olarak anlaşılmıyor

        int x,y;
        x / y; // bu işlem int türünde değilde double türünde yapılmasını istiyoruz dilin kurallarına göre operandlar int türünden
                  olduğu için bölme işlemide int türünde yapılacak
        (double)x / y; // implicit conversion gerçekleşicek int türünde değil double türünde yapılacak

        fakat başka amaçlarda var

        int main()
        {
            int x = 10;
            const int* p = &x;

            int *ptr = p; // const pointer olmayan bir değişkene p'nin değerini geçmek isteyeleim ama böyle yazarsak hata verir C ve C++ dilinde dilin kuralların aykırı
                            c tipi tür dönüştürme operatörünü kullanarak kodu legal hale getiriyoruz (int*)p böyle yapılan dönüşümlere const cast deniliyor
                            x'in kendisi const olsaydı tanımsız davranış olurdu ve burda data typelar'ı compatable(uyumlu olması gerekir) int -> int  double -> double

            int x = 12;
            float* fp = (float*)(&x); // legalite sağlandı ama bu kod yanlış böyle bir kod yazılmamalı

            her hangi bir türden
            char*
            signed char*
            unsignec char* türlerine dönüşüm yapabiliriz

            int* -> unsigned int* türüne dönüşüm yapabiliriz

            bir structure nesnesinin adresinin türünden onun ilk elemanını adresine dönüşüm yapabiliriz

              struct Data
             {
                 int x;
                 double d;
                 char c;
             };
            int main()
            {
                Data mydata{};

                char* cp = (char*)&mydata;
                int* ip = (int*)&mydata;
                double* dp = (double*)&mydata;
            }

            C++ diyor ki madem tür dönüşümünde farklı farklı amaçlar olabiliyor bütün bu farklı amaçlar için C de aynı operatörlerle dönüşüm yapılıyor biz bunu değiştirelim
            dile yeni operatörler ekleyelim dönüşümün amacının ne olduğuna bağlı olarak farklı operatörler kullanalım bununda sağlayacağı fayda operatörün ne olduğunu
            bağlı olarak ne amaçla dönüşümün yapıldığı anlaşılsın ve yanlışlıkla dönüşüm yapılmasın mesela const cast ayrı bir operatöel yapılsın o operatör yerine başka bir
            tür dönüştürme operatörü kullanıldığında sentaks hatası versin esas amaç bu

Fatih Akgül burda bir soru sormuştu enum class yerine enum struct kullanabilir miyiz diye hoca başta hayır diyor ama diğer derste kullanılabileceğini söylüyor

*/