/*
default argument

    function declerationda isim vermeye gerek olmaz çünkü kullanmayacağız
    default argument bildirimi function declerationda yer alması gerekir

    default argument compiler time'a yönelik

    int foo(int, int, int = 10);

    int main()
    {
        foo(5,6); // foo(5,6,10)
    }

    int foo(int, int = 20, int); // sentaks hatası çünkü 2.parametre için default argument bildirilmişken sağ taraftaki değer için bildirilmemiş C++ dilinde bu zorunlu

referanslarda default argument alabilir

    int x = 10;
    void foo(int& = x); // argüman gönderilmezse global x değişkeni kullanılır

    void foo(int y = x + 5); // argüman gönderilmezse foo fonksiyonu x + 5 olarak kullaınılır

    int foo(int = 2,int = 5);
    int bar(int x = foo()); // argüman girilmezse foo fonksiyonun değeri geçilecek // arka planda bar(foo(2,5)) şeklinde çağırmış oluyoruz aslında

pointerlarda argüman alabilir

    void foo(const char* p = nullptr);

    foo("mustafa"); // değer girilmezse nullptr

maximal munch

    int g = 10;

    void func(int *= &g); // maximal munch kuralı

int x = 5;

void foo(int a = ++x)
{
    std::cout<<a;
}

int main()
{
foo(); // foo(++x); x = 6
foo(); // foo(++x); x = 7
foo(); // foo(++x); x = 8

}

int func()
{
    static int x = 0;

    return ++x;
}

void bar(int x = func())
{
    std::cout<<x;
}

int main()
{
    bar(); // bar(func()) x = 1
    bar(); // bar(func()) x = 2
    bar(); // bar(func()) x = 3

re-decleration ile argümanların kümülatif şekilde ele alınması
    samet.h
    void foo(int,int,int);

    samet.cpp
    #include "samet.h"
    void foo(int,int,int = 0); // re-decleration

    int main()
    {
    foo(2,4); // foo(2,4,0)
    }

    samet.h
    void foo(int,int,int =0);

    #include "samet.h"
    samet.cpp
    void foo(int,int = 10,int); //  üstteki satır olmasaydı bu re-decleration hata verirdi çünkü default argument alan ifadenin
    sağ tarafındaki ifadede default argument almak zorunda

     int main()
    {
       foo(4); // foo(4,10,0)
    }
--------------------------------------------------------------------------------------------------------------------------------------------------
Fonksiyonların 2.ci paramterlerine default değer geçmek için veya default argüman geçilmeyen
 değerlere default değer geçmek için wrapper tekniği kullanılır

burada bir wrapper fonksiyon olan `call_foo` tanımlıyoruz ve `foo` fonksiyonuna çağrı yaparken parametrelerin sırasını değiştiriyoruz
Bu tür kullanım, fonksiyonların parametrelerinin varsayılan değerlerini geçersiz kılmak için faydalı olabilir. Örneğinizde, `call_foo` fonksiyonu,
`foo` fonksiyonunun ikinci ve üçüncü parametrelerinin sırasını değiştiriyor.

**Orijinal Fonksiyon (`foo`)**:

void foo(int x, int y, int z);

Bu fonksiyon, üç tamsayı parametresi (`x`, `y`, `z`) alır. Burada sadece deklarasyonu yapılmıştır, yani fonksiyonun gövdesi belirtilmemiştir.

**Wrapper Fonksiyon (`call_foo`)**:

void call_foo(int x, int z, int y = 10)
{
    foo(x, y, z);
}

Bu fonksiyon, `foo` fonksiyonuna yapılan çağrıyı sarmalar ve parametrelerin sırasını değiştirir. Burada şu noktalar önemlidir:
1. `call_foo` fonksiyonu üç parametre alır: `x`, `z`, ve varsayılan olarak `y`.
2. `y` parametresinin varsayılan değeri 10'dur.
3. `call_foo`, `foo` fonksiyonuna çağrı yaparken `x`, `y`, `z` parametrelerini sırasıyla geçirir. Yani, `call_foo` fonksiyonuna verilen
`z` parametresi, `foo` fonksiyonuna üçüncü parametre olarak geçer.

#include <iostream>

// Orijinal fonksiyonun tanımı
void foo(int x, int y, int z)
{
    std::cout << "foo called with x: " << x << ", y: " << y << ", z: " << z << std::endl;
}

// Wrapper fonksiyonun tanımı
void call_foo(int x, int z, int y = 10)
{
    foo(x, y, z);
}

int main()
{
    call_foo(1, 3);      // x: 1, y varsayılan: 10, z: 3
    call_foo(2, 4, 20);  // x: 2, y: 20, z: 4

    return 0;
}

### Çıktı

Bu örnek kodu çalıştırdığınızda aşağıdaki çıktıyı alırsınız:

foo called with x: 1, y: 10, z: 3
foo called with x: 2, y: 20, z: 4

### Açıklama

1. `call_foo(1, 3)` çağrısında, `x` 1, `z` 3 olarak verilmiştir. `y` için varsayılan değer 10 kullanılır. Bu durumda `foo` fonksiyonu `foo(1, 10, 3)` şeklinde çağrılır.
2. `call_foo(2, 4, 20)` çağrısında, `x` 2, `z` 4 ve `y` 20 olarak verilmiştir. Bu durumda `foo` fonksiyonu `foo(2, 20, 4)` şeklinde çağrılır.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 Default argümanlarlar eksik bilgi girildiğini de kontrol edebilir

 Bu kod, `print_date` fonksiyonunu kullanarak tarihleri yazdırmak için tasarlanmıştır. Fonksiyon, gün (`d`), ay (`m`) ve yıl (`y`) parametrelerini alır.
 Eğer herhangi bir parametre belirtilmezse (`-1` olarak geçilirse), o parametre için varsayılan değer olarak mevcut tarih bilgilerini kullanır.

İşte kodun açıklaması:

1. **Kod Başlangıcı:**

   #define _CRT_SECURE_NO_WARNINGS // tanımlaması, bazı güvenlik uyarılarını devre dışı bırakmak için Visual Studio'da yaygın olarak kullanılır.

   #include <iostream>
   #include <ctime>
 
2. **`print_date` Fonksiyonu:**

   void print_date(int d = -1, int m = -1, int y = -1);

   void print_date(int d, int m, int y)
   {
       if (y == -1) { // Yıl parametresi -1 ise (default argument used)
           std::time_t sec;
           std::time(&sec);
           std::tm* p = std::localtime(&sec);
           y = p->tm_year + 1900;

           if (m == -1)
           {
               m = p->tm_mon + 1;

               if (d == -1)
                   d = p->tm_mday;
           }
       }
       std::cout << d << "-" << m << "-" << y << std::endl;
   }

   - `print_date` fonksiyonu, gün (`d`), ay (`m`) ve yıl (`y`) parametreleri alır.

   - Eğer `y` parametresi `-1` ise, fonksiyon mevcut zamanı almak için `std::localtime` fonksiyonunu kullanır. Bu işlem, `std::time_t` türünden bir zamanı
   alır ve bu zamanı yerel zaman dilimindeki bir `tm` yapısına çözer.

   - `p->tm_year + 1900` ifadesi, `tm` yapısındaki yıl bilgisini gerçek yıl olarak elde etmek için kullanılır (1900 yılını ekler).

   - Eğer `m` parametresi `-1` ise, `tm` yapısındaki ay bilgisini (`p->tm_mon + 1`) kullanır.

   - Eğer `d` parametresi `-1` ise, `tm` yapısındaki gün bilgisini (`p->tm_mday`) kullanır.

  - Son olarak, belirtilen gün, ay ve yıl bilgilerini standart çıkış (`std::cout`) üzerinde formatlı olarak yazdırır.

3. **`main` Fonksiyonu:**

   int main()
   {
       print_date(4, 6, 1987); // Belirtilen tarih: 4-6-1987
       print_date(4, 6);       // Belirtilen ay ve gün, ancak yıl eksik: 4-6-Mevcut yıl
       print_date(4);          // Sadece gün belirtilmiş: 4-Mevcut ay-Mevcut yıl
       print_date();           // Hiçbir şey belirtilmemiş: Mevcut gün-Mevcut ay-Mevcut yıl

       return 0;
   }

   - `main` fonksiyonu, `print_date` fonksiyonunu farklı parametre kombinasyonları ile çağırarak çalıştırır.
   - İlk çağrıda tam tarih (gün, ay, yıl) belirtilirken, diğer çağrılarda eksik parametreler verilerek fonksiyonun varsayılan değerleri kullanması sağlanır.
   - Her çağrı sonucunda ekrana yazdırılan tarih bilgileri, `print_date` fonksiyonunun işleyişini ve varsayılan parametre kullanımını gösterir.

Bu şekilde, `print_date` fonksiyonu, belirtilen veya varsayılan tarih bilgilerini doğru şekilde işleyerek ekrana yazdırır.
--------------------------------------------------------------------------------------------------------------------------------------------------
 C++ dilinde ellipsis (`...`) parametresi, bir fonksiyonun değişken sayıda argüman alabilmesini sağlar.
 Bu tür fonksiyonlar "variadic functions" olarak adlandırılır.

### Kullanımı

Bir fonksiyonun parametre listesinin sonuna üç nokta (`...`) ekleyerek variadic bir fonksiyon tanımlayabilirsiniz. Bu fonksiyonlar,
değişken sayıda argüman kabul eder ve genellikle `stdarg.h` başlık dosyasında bulunan makrolar kullanılarak bu argümanlara erişilir.

### Örnek

Aşağıda basit bir variadic fonksiyon örneği verilmiştir. Bu örnekte, `printNumbers` fonksiyonu, ilk argüman olarak kaç tane sayının basılacağını
belirten bir tamsayı alır ve ardından değişken sayıda tamsayı argümanı alır:

#include <iostream>
#include <cstdarg>

void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        std::cout << num << std::endl;
    }

    va_end(args);
}

int main() {
    printNumbers(3, 10, 20, 30);
    printNumbers(5, 1, 2, 3, 4, 5);
    return 0;
}

### Açıklamalar

- `va_list`: Değişken argümanların listesini tutar.
- `va_start`: `va_list` değişkenini başlatır ve ilk argümandan sonra gelen argümanlara erişimi sağlar.
- `va_arg`: `va_list`'ten bir sonraki argümanı alır.
- `va_end`: `va_list`'i sonlandırır.

### Önemli Noktalar

1. **Tip Güvenliği**: Variadic fonksiyonlar tip güvenliği sağlamaz, bu nedenle argümanların tipleri doğru bir şekilde yönetilmelidir.
2. **Standart Kitaplık Kullanımı**: C++'da variadic fonksiyonlar yerine genellikle şablonlar (`templates`) ve diğer standart kütüphane özellikleri kullanılır.
Örneğin, `std::initializer_list`, `std::vector` veya `variadic templates` gibi.
 --------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde "maximal munch" kuralı, lexer (lexical analyzer) tarafından kodu tararken mümkün olan en uzun token'ı
 tanımlamaya çalışmasını ifade eder. Bu kural, token'ların ayrıştırılması sırasında belirsizlikleri çözmek için kullanılır.
 Kısaca, birden fazla geçerli token dizisi olduğunda, en uzun olanı seçilir.

### Örnekler

#### Örnek 1: İsimlendirme ve Operatörler

int main() {
    int a = 0;
    int b = 1;
    int c = a+++b; // Burada c = a+++b ifadesi geçerli ve token'lar şu şekilde: a++, +, b
    return 0;
}

Bu örnekte, `a+++b` ifadesi `a++` (arttırma operatörü) ve `+b` (toplama operatörü) olarak ayrıştırılır, çünkü `++` en uzun geçerli token'dır.

#### Örnek 2: Ayrıştırma ve Yorum Satırları

int main() {
    int x = 5;
    // Comment /* nested comment */
    // int y = 10;
// return 0;
// }

/* Bu örnekte, `/ / ` ile başlayan yorum satırı, satırın sonuna kadar uzanır ve içindeki `/* nested comment* / `
kısmı yorum olarak değerlendirilmez, çünkü `/ / ` tek satırlık bir yorum başlatır ve tüm satırı kapsamına alır.

### Örnek 3: Karakter Dizileri ve Tanımlayıcılar

int main() {
    char a = 'a';
    std::string s = "hello world";
    return 0;
}

Bu örnekte, `'a'` ve `"hello world"` en uzun geçerli karakter dizisi ve string olarak tanınır. Lexer, `'` ve `"`
karakterlerini gördüğünde mümkün olan en uzun karakter dizisini veya string'i tanımlamaya çalışır.

### Maximal Munch Kuralı ve Belirsizlikler

Maximal munch kuralı, belirsizlikleri ortadan kaldırarak token'ların doğru bir şekilde ayrıştırılmasını sağlar. Örneğin, `a+++++b` ifadesinde lexer,
bu ifadeyi `a++ ++ + b` veya `a++ + ++b` olarak ayrıştırmak yerine `a++ + ++b` olarak ayrıştırır, çünkü `++` operatörü en uzun geçerli token'dır.

### Özet

"Maximal munch" kuralı, C++ kodunu ayrıştırırken mümkün olan en uzun geçerli token'ı seçmeye dayanır. Bu kural, kodun doğru ve tutarlı bir şekilde yorumlanmasını sağlar,
belirsizlikleri ortadan kaldırır ve lexer'in işini kolaylaştırır.

##Örnek

Bu kodda "maximal munch" kuralını anlamak için `int *= &g;` ifadesine odaklanalım.

### Kod

int g = 10;

void func(int *= &g);

### Ayrıştırma Adımları
"Maximal munch" kuralı, mümkün olan en uzun geçerli token'ı seçmek anlamına gelir. Bu kuralı göz önünde bulundurarak `int *= &g;` ifadesini ayrıştıralım.

1. **Tokenların Tanımlanması**:
    - `int`
    - `*`
    - `=`
    - `&`
    - `g`
    - `;`

2. **Maximal Munch Kuralı**:
    - `int` ve `*` arasındaki boşluk yok sayılır.
    - `*=` operatörü bir birleşik atama operatörüdür ve bir token olarak kabul edilir.

Ancak burada dikkat edilmesi gereken nokta, `*=` birleşik atama operatörünün geçerli bir C++ sentaksı olduğudur. Bu durumda `*=` bir token olarak seçilecektir.

### Ayrıştırma Sonucu
Bu kurala göre ifade şu şekilde ayrışacaktır:

- `int` → Tür belirleyici (type specifier)
- `*=` → Birleşik atama operatörü (compound assignment operator)
- `&g` → Adres operatörü ile `g` değişkeninin adresi
- `;` → İfade sonu

Bu nedenle, `int *= &g;` ifadesi ayrıştırıldığında, `*=` operatörü en uzun geçerli token olarak kabul edilir ve bu ifade aşağıdaki gibi yorumlanır:

- `int` türünde bir değişken (burada `int` türünde bir pointer) atanmak isteniyor.
- `*=` operatörü ile adres operatörü `&` ve `g` değişkeni birlikte kullanılıyor.

### Doğru Sentaks
Ancak, `void func(int *= &g);` ifadesi sentaks hatası içerir çünkü `*=` operatörü bir değişkene atanmak için kullanılamaz.
Bunun yerine pointer ile çalışmak istiyorsanız, doğru sentaks şu şekilde olmalıdır:

int g = 10;

void func(int *p = &g);

Bu doğru sentaksta:
- `int *p` ifadesi bir pointer değişkeni tanımlar.
- `p` pointer'ı, `g` değişkeninin adresine (`&g`) varsayılan olarak atanır.

### Özet
Maximal munch kuralı, `*=` gibi operatörlerin en uzun geçerli token olarak ayrıştırılmasını sağlar. Ancak doğru C++ sentaksı kullanılmadığında,
bu ayrıştırma kuralları hatalı kod ile sonuçlanabilir. Bu nedenle, pointer ve atama işlemlerini doğru kullanarak hatasız kod yazmak önemlidir.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 Auto keywordü ile Type deduction(Tür Çıkarımı)

 NOT:auto type deduction da tür çıkarımı auto keywordüne yapılır auto bir type holder olarak ele alınır
 auto ya karşılık gelen tür ile değişkenin türü aynı olmak zorunda değil

 default initialize edilemez
    auto x;

 ilk değer veren ifadenin türü neyse auto'ya karşlılık gelen tür o tür

 auto x = 10;

 3 auto ifadesinde auto için yapılan çıkarımlar farklıdır
     1)auto x = expr;
        auto x = 10;

        Constluğun düşmesi:

        const int x = 10;

        auto y = x; // constluk düşer -> int y olur y referans olsaydı düşmeyecekti

         Referansın düşmesi(böyle demek pek doğru değil aslında çünkü bir expressionun türü referans olamaz):

         int x = 10;
         int& r = x;

         auto y = r; //int y olarak ele alınyor r const olsada yine aynı şekilde değerlendirilecekti

         int x = 132;
         const int& r = x;
         auto y = r; // y int

          Dizilerde auto kullanımı:
            int ar[5]{};

            auto x = ar; // x-> int * x

            Dizi const olsaydı:
            const int ar[5]{};

            auto x = ar; x-> const int* x  // low level const gösteriği yer const olduğu için burda constluk düşmez (top level olsaydı düşerdi)

            auto p = "Kaveh" // p nin türü const char*

            int foo(int);

            auto x = foo; function to pointer conversion uygulanıyor int(*)(int) x'in türü bu auto keywordü kullanılmasaydı int(*x)(int) = foo yazmamız gerekirdi

     2)auto &x = expr;
        auto& r = 10 // l value expreesiona r value expression ile ilk değer veremeyiz
        const olsaydı hata vermezdi

        constluğun düşmemesi

            const int x = 5;
            auto& r = x; // const int r = x buradaki const düşseydi const olmayan referansı const nesneye bağlamış olurduk zaten sentaks hatası olurdu

        Referansların dizilerle kullanılması ve array decay uygulanmaması

            int ar[5] {1,4,5,5,2};

            auto &r = ar; // r bir referans olduğu için array decay uygulanmaz

            r'nin tür çıkarımı -> int(&r)[5]

            ar const olsaydı bu sefer çıkarım ->  const int (&r)[5] olurdu

        Referansın string ile kullanılması

            auto x = "sample"; x'in çıkarımı const char *
            auto& y = "sample"; y'nin çıkarımı const char (&y)[5]

        Referansların fonksiyonlarla kullanılması:

            int foo(int) -> türü int(int)

            auto& r = foo; r'nin çıkarımı -> int(&r)(int) olur;


         typedef int inta5[];
         int ar[5]{2,5,8,9,4};
         inta5 *p = &ar;

         tür eş ismi kullanmasaydık int(*)[5] = &ar şeklinde kullanmamız gerekirdi

         inta5& r = ar; // r ar dizisine referans tür eş ismi kullanmasaydık int(&r)[5] = ar; yazmamız gerekirdi

         Referanslarda nasıl array decay uyglanmıyorsa şimdide function to pointer conversion uygulanmicak
            int foo(int);  foo nun türü int(int) fonksiyon türü(function type) ile function pointer türünü birbirine karıştırmayalım

            auto& r = foo; // int (&r)(int)

     3)auto && x = expr;

Fonksiyonların auto keyword ile kullanılması

int main()
{
    auto x = foo; // function to pointer conversion oluyor x -> int(*)(int)  // x in tür çıkarımı yani derleyici böyle yazmışız gibi ele alıyor
    auto x = &foo;     x -> int(*)(int)  // x in tür çıkarımı //üstteki yazım yerine bu yazım tercih edilir ama üstteki de hata değildir
    int (*x)(int) = &foo; // x auto keywordü ile kullanılmasaydı şöyle yazılması gerekirdi
}

referans olduğu için Constuluğun düşmemesi:

const int x = 5;
auto &r = x; // eğer constluk düşseydi const nesneye const olmayan referansı bağlamış olucaktık

  r'nin çıkarımı ->  const int&

bir ifadenin türü referans türü olamaz

int a = 5;
int&r = a; type ile expression farklı şeyler

    r'nin type'ı int&
    r'nin expression'ı int

int x = 10;
int* p = &x;

auto& r = p; // int*& r = p; // pointera referans olan değişken

int x = 10;
int* p = &x;
auto r = p; // r türü int * x'in adresini tutuyor

std::cout << &x<<'\n';
std::cout << r; // x'in adresi

auto r1 = &p; // burda p'nin adresini tutmuş olyor yani int** r1 = &p çıkarımı yapılıyor

auto&& r = 20; r'nin tür çıkarımı -> int r = 20;

int x = 10;

auto&& r = x; r'nin tür çıkarımı -> int& &&r = x; // burda reference collapsing kuralları uygulanıyor çünkü x l value
referansa referans türü oluyor böylelikle r şöyle olmuş oluyor

int& &&r = x; reference collapsing kuralına göre burda r lvalue reference -> int& r = x;

NOT:using keywordü ile kullanımı şu şekilde

using reftype = int&;

int x = 10;
reftype &r = x; // int& &r = x; // int& çıkarımı oluyor

Verdiğiniz örnekte `reference collapsing` (referans çöküşü) olayı meydana geliyor. C++'da, referansların referansı (`& &`)
diye bir şey yoktur ve bunun yerine C++'da reference collapsing kuralları devreye girer. reference collapsing, `using` anahtar sözcüğü veya
`template` kullanılarak referansların birleşimi (collapsing) ile ilgilidir.

Örneğinizde, `reftype` zaten `int&` türünü temsil ediyor. Sonrasında `reftype &r` yazıldığında, `int& &` durumu oluşuyor ve reference collapsing kuralları uygulanıyor.

### reference collapsing Kuralları

1. `T& &` `T&` olur.
2. `T&& &`  `T&` olur.
3. `T& &&` `T&` olur.
4. `T&& &&`  `T&&` olur.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 Universal Reference veya Forwarding Reference

 **Universal Reference** terimi, C++11'de Scott Meyers tarafından ortaya atılmış bir terimdir. Universal reference,
 bir fonksiyon şablonunda veya `auto` ile kullanılan ve hem `lvalue` hem de `rvalue` referanslarını kabul edebilen
 referans türüdür. Genellikle bir şablon parametresi olarak kullanıldığında ve `T&&` (iki ampersand) ile gösterildiğinde
 ortaya çıkar. Universal reference, `forwarding reference` terimi ile eşanlamlıdır.

### Universal Reference'ın Özellikleri ve Kullanımı

Universal reference, bir argümanın değer kategorisini koruyarak (`lvalue` veya `rvalue`) iletilmesini sağlar.
Bu, özellikle şablon metaprogramlama ve move semantiği için çok önemlidir.

#### Universal Reference'ın Tanımı

Universal reference, bir şablon parametresi olarak `T&&` şeklinde tanımlandığında ortaya çıkar:

template <typename T>
void func(T&& param); // param bir universal referanstır

### Universal Reference Kullanım Örneği

Bir universal reference'ın nasıl kullanıldığını ve argümanların doğru şekilde iletilmesini gösteren bir örnek:

#include <iostream>
#include <utility> // std::forward

void process(int& x) {
    std::cout << "Lvalue reference: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "Rvalue reference: " << x << std::endl;
}

template <typename T>
void forwarder(T&& arg) {
    process(std::forward<T>(arg)); // Argümanı doğru şekilde yönlendirir
}

int main() {
    int a = 5;
    forwarder(a);       // Lvalue reference
    forwarder(10);      // Rvalue reference
    return 0;
}

#### Açıklamalar:

- `process(int& x)` fonksiyonu `lvalue` referansı kabul eder.
- `process(int&& x)` fonksiyonu `rvalue` referansı kabul eder.
- `forwarder` şablon fonksiyonu bir universal reference kullanır (`T&&`).
- `std::forward<T>(arg)` ile argüman, `lvalue` veya `rvalue` durumu korunarak `process` fonksiyonuna iletilir.

### Universal Reference Kullanım Kuralları

1. **Şablon Parametresiyle Kullanım:**
   Universal reference, sadece şablon parametreleriyle kullanıldığında ve tür çıkarımı (type deduction) yapıldığında ortaya çıkar.
   `T&&` olarak tanımlandığında, `T` şablon parametresi olmalıdır.

2. **Auto ile Kullanım:**
   Universal reference, `auto` anahtar kelimesiyle birlikte kullanıldığında da oluşabilir.

   auto&& var = expr; // expr'nin değer kategorisine bağlı olarak var bir lvalue veya rvalue referans olabilir.

3. **std::forward Kullanımı:**
   Universal reference ile iletilen argümanları doğru şekilde yönlendirmek için `std::forward` kullanılmalıdır. `std::forward` argümanın
   `lvalue` veya `rvalue` olup olmadığını doğru şekilde belirler ve ilgili referansı çağırır.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 decltype kullanım senaryoları
1.KURAL SETİ:declytype'ın operandının isim olması durumunda tür çıkarımının yapılması türüne göre olur
int x;
decltype(x) y; -> y'nin türü int
decltype(a.y) z  -> a nesnesindeki y değerinin türü
decltype(p->y) < -> p nesnesinin y değerinin türü

decltype(x) foo(decltype(x)* p); // int foo(int* p)türünde bir fonksiyon bildirmiş olucaz

const int y { 435};

decltype(x) y; // const variable must be initalize

int& r = x;

decltype(r) a; // int& çıkarımı olur ama hata verir referanslara ilk değer vermek zorundayız

int&&r = 4;
decltype(r) // int&&

int ar[30]{};
decltype(ar) x // int[30];

structlar ve classlar içinde aynı kural uygulanıyor

dtruct Nec
{
    int x;
    double* p;
}

Nec mynec;

decltype(mynec.p); // double*
decltype(mynec.x); // int

Nec* necptr = &mynec;
decltype(necptr->p); // double*

2.KURAL SETİ: decltype'ın operandının expression olması durumunda yani isim olmadığı ifade olduğu durumda uygulanan kural seti ifadenin
primary value kategorisine bağlıdır

decltype(10) int
decltype(x + 10) int
decltype((x)) -> value categorysine göre yorumlanıyor x'in value kategorisi int&
decltype((((x)))) -> yine value categorysine göre yorumlanıyor  int&
decltype(+x) // PR value int
decltype(x++) // PR value int
decltype(++x) // L value int&
decltype([a[3]) // L value
buradan elde edilecek tür decltypa operand olan expressionun primary value kategorisine bağlı
PR value ise -> T
L value ise -> T&
X value ise -> T&&

NOT:decltype'ın operandı olan ifade için işlem kodu üretilmez UNEVELUATED CONTEXT
--------------------------------------------------------------------------------------------------------------------------------------------------
int x = 5; // x'in burda value category'si yoktur çünkü burda x bir ifade değil

NOT:bir ifadenin türü referans türü olamaz(ama ifadenin türü pointer olabilir) burda ince bir ayrıntı var

int a = 5;
int& r = a; // r değişkeninin kendi türü int &
int* ptr = &a;

a ->ifadesinin türü int
r ->ifadesinin türü int -> ifadenin türü referans olamaz
ptr ->ifadesinin türü int* -> ifadenin türü pointer olabilir
--------------------------------------------------------------------------------------------------------------------------------------------------
autonun kullanılması gerektiği mantıklı yerlerden biri

double foo(); // geri dönüş değeri değişirse auto kullanıldığı için elle değiştirmemize gerek kalmayacak

auto x = foo();
*/