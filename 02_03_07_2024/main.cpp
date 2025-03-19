/*

c dilinde void* türünden başka bir pointer türe implicit conversion var ama c++ dilinde yok


    int x = 5;
    void* vptr = &x;
    int* p = &vptr; // C de geçerli C++ 'da geçersiz

aritmetik türlerden pointer türlerine pointer türlerden aritmetik türlerine farklı pointer türleri arasında c dilinde örtülü dönüşüm var ama c++ dilinde yok
--------------------------------------------------------------------------------------------------------------------------------------------------
const correctness const kullanılması gereken yerde cost kullanılması demek bir yerde bile ihmal edilmesi demek kod kalitesini bozar

C ile C++ arasında const farklılığı

c dilinde aritmetik türlerde const ifadesi kullanılsa bile C dilinde constant expr gerektiği yerlerde ibile kullanılmıyor garantidi yok
c++ dilinde ilk değerini const ile alan nesneler const gereknen yerlerde bunu garanyi eder yani const expressiondır

C dilinde const nesnelerin initialize edilmesi zorunlu değil
C++ dilinde const nesnelerşin initialize edilmesi zorunlu
--------------------------------------------------------------------------------------------------------------------------------------------------
**Const Correctness**, bir değişkenin, fonksiyonun veya nesnenin **değiştirilemez** olduğunu açıkça belirtmek için kullanılan bir prensiptir.
Kodun güvenliğini ve okunabilirliğini artırır, yanlışlıkla değişiklik yapılmasını engeller.

# **1. `const` ile Değişken Tanımlama**
Bir değişken `const` olarak tanımlandığında, değeri **atanan ilk değerden sonra değiştirilemez.**

const int x = 10;
x = 20;  // HATA: 'x' sabittir ve değiştirilemez.

📌 **Sabit göstericilerde (pointers) `const` kullanımı:**

const int* ptr1;   // Veri sabit, gösterici değişebilir
int* const ptr2;   // Gösterici sabit, veri değişebilir
const int* const ptr3;  // Hem veri hem gösterici sabit

🔹 **Örnek:**

int a = 5, b = 10;
const int* p1 = &a;  // *p1 değiştirilemez, ancak p1 başka adres gösterebilir
int* const p2 = &a;  // p2 başka adres gösteremez, ancak *p2 değiştirilebilir
const int* const p3 = &a;  // p3 başka adres gösteremez, *p3 de değiştirilemez

# **2. `const` Parametreler**
Bir fonksiyonun parametresini `const` yapmak, onun **fonksiyon içinde değiştirilememesini sağlar**.

🔹 **Değer parametresi için `const` kullanımı (pek gerekli değil):**

void foo(const int x) {
    x = 20;  // HATA: 'x' değiştirilemez.
}

🔹 **Referans parametrelerde `const` kullanımı (Performans için önerilir!):**

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

✔ **Avantaj:** `const std::string&` ile **kopyalama önlenir**, performans artar.

# **3. `const` Üye Fonksiyonlar (Member Functions)**
Bir üye fonksiyon `const` olarak tanımlandığında, **sınıfın veri üyelerini değiştiremez.**

🔹 **Örnek:**

class Example {
public:
    int getValue() const { // Fonksiyon içinde veri değiştirilemez!
        return value;
    }

private:
    int value = 42;
};

📌 **Eğer `const` eklenmezse, `const` nesneler bu fonksiyonu çağıramaz.**

🔹 **Yanlış Kullanım:**

const Example obj;
obj.getValue();  // HATA! getValue() const olmalı.

# **4. `const` Veri Üyeleri**
Bir sınıfın veri üyesi `const` olarak tanımlanırsa, **yalnızca constructor içinde atanabilir.**

class Example {
public:
    Example(int v) : value(v) {} // Constructor içinde atanabilir
    int getValue() const { return value; }

private:
    const int value;  // Sabit üye
};

📌 **Kurucu fonksiyondan sonra `const` veri üyesinin değeri değiştirilemez.**

# **5. `const` ile Dönüş Değerleri**
Bir fonksiyonun dönüş değerini `const` yapmak, **dönüş değerinin değiştirilememesini sağlar.**

🔹 **Temel (primitive) türler için `const` dönüş pek faydalı değildir.**

const int getNumber() {
    return 42;
}

int main() {
    int x = getNumber();
    x = 50;  // x değiştirilebilir, çünkü kopyalandı.
}

🔹 **Nesne döndürürken `const` kullanımı önemli olabilir.**

class Example {
public:
    const std::string getText() { return text; }  // Dönüş değeri değiştirilemez
private:
    std::string text = "Hello";
};

# **6. `mutable` ve `const` Birlikteliği**
**`mutable` anahtar kelimesi**, **`const` fonksiyonlar içinde değiştirilebilecek veri üyeleri** için kullanılır.

🔹 **Örnek:**

class Example {
public:
    void show() const {
        counter++;  // Normalde hata olurdu, ancak 'mutable' olduğu için çalışır.
    }

private:
    mutable int counter = 0;
};

✔ **Nerede Kullanılır?**
- Önbellek hesaplamaları
- Debug sayaçları
- Log mekanizmaları

# **7. `const_cast` Kullanımı**
Bazen `const` bir nesneyi **geçici olarak** değiştirmek gerekebilir. **`const_cast`**, `const` özelliğini kaldırmak için kullanılır.

🔹 **Örnek:**

void modify(const int* ptr) {
    int* nonConstPtr = const_cast<int*>(ptr);
    *nonConstPtr = 100;  // 'const' olmamasına rağmen değiştirildi
}

int main() {
    int x = 50;
    modify(&x);
    std::cout << x;  // Çıktı: 100
}

⚠ **Uyarı:** `const_cast` kullanırken **dikkatli olun**, çünkü `const` olan bir nesneyi değiştirirseniz **tanımsız davranış (UB) oluşabilir!**

# **8. `const` ve `volatile` İlişkisi**
- **`const`** → Değiştirilemez.
- **`volatile`** → Derleyicinin optimizasyon yapmaması gereken değişken (genellikle donanım veya çok iş parçacıklı programlarda kullanılır).

🔹 **Örnek:**

volatile const int* ptr;

Bu, **değiştirilemez ama her erişimde yeniden okunması gereken bir değişken** tanımlar.

# **9. `const` Kullanmanın Faydaları**
✔ **Güvenlik:** Yanlışlıkla değişiklik yapılmasını önler.
✔ **Kod Okunabilirliği:** Bir değerin değişmeyeceği açıkça belirtilmiş olur.
✔ **Optimizasyon:** Derleyici `const` değişkenleri sabit olarak kullanabilir.
✔ **Performans:** `const&` parametreleri kopyalamayı önleyerek daha hızlı çalışır.

# **Özet: `const` Kullanımı**
| Kullanım Alanı | Açıklama |
|--------------|-------------|
| `const int x = 10;` | Değiştirilemez değişken |
| `void foo(const int x);` | Parametre değiştirilemez |
| `void foo(const std::string& str);` | Kopyalama önlenir, performans artar |
| `int getValue() const;` | Üye fonksiyonun veri değiştirmesini önler |
| `const int value;` | Sadece constructor’da atanabilir sabit veri üyesi |
| `mutable int counter;` | `const` fonksiyon içinde değiştirilebilir veri |
| `const_cast<int*>(ptr);` | `const` özelliğini kaldırır (Dikkatli kullanılmalı!) |

C++'ta **`const correctness`**, hataları önlemek ve kodun daha güvenilir olmasını sağlamak için kritik bir konudur.
Kodunuzda `const` kullanarak **yanlışlıkla değişiklikleri önleyebilir, performansı artırabilir ve derleyicinin daha iyi optimizasyon yapmasını sağlayabilirsiniz!** 🚀
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Array to Pointer Decay – C++'ta Dizi → Gösterici Dönüşümü (Array to Pointer Conversion)**

C++’ta **dizi ismi** (array name) genellikle **otomatik olarak** bir göstericiye dönüşür. Bu olaya **Array to Pointer Decay (Dizi → Gösterici dönüşümü)** denir.

## **1. Temel Mantık**
Bir dizinin ismi, dizinin **ilk elemanına işaret eden bir göstericiye** dönüşür.

int arr[5] = {1, 2, 3, 4, 5};
int* ptr = arr;  // 'arr' burada &arr[0] ile aynıdır.

📌 `arr` aslında `&arr[0]` adresine dönüşür.

🔹 **Ancak, bu sadece normal diziler için geçerlidir. `std::array` gibi kapsayıcılarda (containers) bu durum geçerli değildir!**

## **2. `sizeof` ile Farklılık**
Eğer bir dizi doğrudan `sizeof` ile kullanılırsa, **dizinin tamamının boyutunu verir**. Ama bir göstericiye dönüştüğünde, sadece **göstericinin boyutu** ölçülür.

int arr[5] = {1, 2, 3, 4, 5};
std::cout << sizeof(arr) << std::endl;  // Çıktı: 20 (5 * 4 byte)
std::cout << sizeof(&arr[0]) << std::endl;  // Çıktı: 8 (Gösterici boyutu)

📌 **Dizinin boyutu korunmaz, sadece adres bilgisi aktarılır!**

## **3. `&arr` ile `arr` Arasındaki Fark**
Dizinin kendisine (`arr`) ve adresine (`&arr`) dikkat edilmelidir.

int arr[5] = {1, 2, 3, 4, 5};
int* ptr1 = arr;      // 'arr' ilk elemana işaret eder: &arr[0]
int (*ptr2)[5] = &arr;  // '&arr' tüm diziye işaret eder

📌 `arr` → İlk elemana işaret eden **int***
📌 `&arr` → Tüm diziye işaret eden **int (*)[5]**

std::cout << ptr1 << std::endl;  // &arr[0] adresini yazdırır
std::cout << ptr2 << std::endl;  // &arr adresini yazdırır

## **4. Dizi Parametreleri (`T array[]` vs `T* ptr`)**
Bir fonksiyon parametresi olarak dizi kullanılırsa, **otomatik olarak göstericiye dönüşür.**

🔹 **Normal kullanım:**

void func(int arr[5]) {  // 'arr' aslında 'int* arr' olarak geçer!
    std::cout << sizeof(arr) << std::endl;  // Çıktı: 8 (Gösterici boyutu)
}

🔹 **Aynı şey şu şekilde de olur:**

void func(int* arr) {  // Aslında yukarıdakiyle aynıdır!
    std::cout << arr[0] << std::endl;
}

📌 **Dizinin boyut bilgisi kaybolur!**

✔ **Boyutu korumak için `std::array<int, N>` veya `std::span<int>` kullanabilirsiniz.**

## **5. Dizinin Elemanlarına Erişim**
Göstericiye dönüştürüldükten sonra, **dizi elemanları `*` ve `[]` ile erişilebilir.**

int arr[5] = {10, 20, 30, 40, 50};
int* ptr = arr;  // Göstericiye dönüşüm

std::cout << ptr[2] << std::endl;  // Çıktı: 30
std::cout << *(ptr + 2) << std::endl;  // Çıktı: 30 (Pointer arithmetic)

## **6. `std::array` ve `std::vector` Farkı**
`std::array` ve `std::vector` kullanıldığında **dizi göstericiye dönüşmez!**

#include <array>
#include <vector>

std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
std::vector<int> arr2 = {1, 2, 3, 4, 5};

// Bu, array to pointer decay olmadığı için hata verecektir:
// int* ptr1 = arr1;  // HATA!
// int* ptr2 = arr2;  // HATA!

✔ Eğer ham gösterici almak isterseniz `data()` fonksiyonunu kullanabilirsiniz:

int* ptr1 = arr1.data();
int* ptr2 = arr2.data();

## **Özet: Dizi → Gösterici Dönüşümü (Array to Pointer Decay)**
| **Durum** | **Açıklama** |
|--------------|----------------|
| `int arr[5];` | Normal bir dizi |
| `int* ptr = arr;` | `arr` ilk elemana işaret eden bir göstericiye dönüşür |
| `sizeof(arr);` | Dizinin tüm boyutunu verir |
| `sizeof(ptr);` | Göstericinin boyutunu verir (genellikle 8 bayt) |
| `void foo(int arr[]);` | `arr` aslında `int*` olarak geçer (boyut kaybolur) |
| `int (*ptr)[5] = &arr;` | Tüm diziye işaret eden gösterici |
| `std::array<int, 5>` | Göstericiye dönüşmez, güvenlidir |
| `std::vector<int>` | Göstericiye dönüşmez, dinamik olarak yönetilir |

📌 **Sonuç:**
- `arr` → `int*` olarak ilk elemana dönüşür.
- Dizinin boyut bilgisi kaybolur, dikkat edilmelidir.
- Eğer dizi boyutunu korumak istiyorsanız `std::array` veya `std::vector` kullanabilirsiniz. 🚀
--------------------------------------------------------------------------------------------------------------------------------------------------
global değişkenler default olarak external linkage

static yaparsak internal linkage olur

c dilinde static anahtar kelimesiyle nietelemediğimiz sürece global alanda tanımlanan değerler external linkage

c++ dilinde const anahtar değerle tanımanlmş değişkenler internal linkage

hem const hemde external linkage yapmak istersek extern anahtar kelimesini kullanmalıyız

extern const int x = 5; // external linkage
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde "linkage" (bağlama), bir sembolün (değişken, fonksiyon, sınıf, vs.) derleme birimleri (translation units) arasında nasıl erişilebileceğini ve
bağlanabileceğini belirler. Linkage, sembollerin programın farklı bölümlerinde nasıl tanımlandığını ve kullanıldığını yönetir. Üç ana tür linkage vardır:
internal linkage (içsel bağlama), external linkage (dışsal bağlama) ve no linkage (bağlantısızlık).

NOT:Global değerler main başlamadan önce initialize edilir

### Linkage Türleri

1. **Internal Linkage (İçsel Bağlama):**

    Internal linkage, bir sembolün sadece tanımlandığı derleme birimi içinde görülebilmesini sağlar. `static` anahtar kelimesi ve const anahtar kelimesi
    fonksiyonlar ve değişkenler için içsel bağlama
    sağlamak amacıyla kullanılır.

    // file1.cpp
    static int counter = 0; // counter sadece file1.cpp içinde görülebilir
    const int counter2 = 0; // counter2 sadece file1.cpp içinde görülebilir

    static void increment() {
        ++counter;
    }

    void foo() {
        increment();
    }

    // file2.cpp
    void bar() {
        // increment(); // hata: increment() fonksiyonu tanımlanmadı
    }

2. **External Linkage (Dışsal Bağlama):**

    External linkage, bir sembolün diğer derleme birimlerinde de görülebilmesini sağlar. Varsayılan olarak, global değişkenler ve fonksiyonlar dışsal bağlamaya sahiptir.
    `extern` anahtar kelimesi, bir değişkenin veya fonksiyonun başka bir derleme biriminde tanımlandığını belirtmek için kullanılır.

    // file1.cpp
    int globalVar = 42; // globalVar diğer derleme birimlerinde de görülebilir
    // extern const globalVar = 42 // yukarda ki globalVar const olsaydı extern ile kullanabilirdik // static için kullanılmaz

    void foo() {
        // ...
    }

    // file2.cpp
    extern int globalVar; // file1.cpp içindeki globalVar'ı kullanacağına atıfta bulunur

    void bar() {
        globalVar = 21;
    }

3. **No Linkage (Bağlantısızlık):**

    No linkage, bir sembolün sadece tanımlandığı kapsam içinde görülebilmesini sağlar. Yerel değişkenler (blok kapsamındaki değişkenler) ve sınıf üyeleri bağlantısızdır.

    void example() {
        int localVar = 10; // localVar sadece example fonksiyonu içinde görülebilir
    }

### Linkage ve Header Dosyaları

Header dosyaları genellikle deklarasyonları içerir ve tanımlamalar header dosyalarına konulmamalıdır. Bunun nedeni, header dosyalarının birden fazla derleme
biriminde dahil edilmesinin muhtemel olması ve bu durumun çoklu tanım hatalarına yol açmasıdır.

// header.hpp
#ifndef HEADER_HPP
#define HEADER_HPP

extern int globalVar; // definition değil, sadece decleration

void foo();

#endif // HEADER_HPP

// file1.cpp
#include "header.hpp"

int globalVar = 42; // definiton

void foo() { // definitons
    // ...
}

// file2.cpp
#include "header.hpp"

void bar() { // definiton
    globalVar = 21;
}

Bu örnekte, `globalVar` değişkeni `file1.cpp` içinde tanımlanmış ve `header.hpp` içinde deklarasyon olarak kullanılmıştır. Böylece, `file2.cpp` içinde `globalVar` kullanılabilir hale gelir.

### Static Anahtar Kelimesi

`static` anahtar kelimesi, değişkenlerin ve fonksiyonların bağlama türünü belirlemek için kullanılır.

- **Yerel Değişkenlerde:** Bir fonksiyon içindeki `static` değişken, sadece bir kez başlatılır ve fonksiyon çağrıları arasında değerini korur.

    void counter() {
        static int count = 0;
        ++count;
        std::cout << count << std::endl;
    }

- **Global Değişkenlerde ve Fonksiyonlarda:** `static` anahtar kelimesi, değişkenin veya fonksiyonun sadece tanımlandığı derleme birimi içinde görünür olmasını sağlar.

    // file1.cpp
    static int counter = 0;

    static void increment() {
        ++counter;
    }

### Extern Anahtar Kelimesi

`extern` anahtar kelimesi, değişken veya fonksiyonun başka bir derleme biriminde tanımlandığını belirtir.

- **Global Değişkenlerde ve Fonksiyonlarda:** `extern` anahtar kelimesi, değişken veya fonksiyonun başka bir derleme biriminde tanımlandığını belirtir.

    // header.hpp
    extern int globalVar;

    // file1.cpp
    #include "header.hpp"
    int globalVar = 42;

    // file2.cpp
    #include "header.hpp"
    void bar() {
        globalVar = 21;
    }

### Linkage Özeti

- **Internal Linkage:** `static` anahtar kelimesi ile sağlanır. Sembol sadece tanımlandığı derleme birimi içinde görülebilir.
- **External Linkage:** Varsayılan olarak global değişkenler ve fonksiyonlar için geçerlidir. `extern` anahtar kelimesi ile başka bir derleme biriminde tanımlanan semboller kullanılabilir.
- **No Linkage:** Yerel değişkenler ve sınıf üyeleri için geçerlidir. Sembol sadece tanımlandığı kapsam içinde görülebilir.

Linkage kurallarını doğru bir şekilde kullanmak, C++ projelerinde sembol erişimini kontrol etmek ve çoklu tanım hatalarından kaçınmak için kritik öneme sahiptir.
--------------------------------------------------------------------------------------------------------------------------------------------------
int x = 10; // C dilinde const olmalı
int y = x; // C dilinde hata çünkü static ömürlü değişkenlere ilk değer veren ifadeler constant expression olmalı C++ dilinde bu geçerlidir

global değişkenler c ve c++ dilinde main çağırılmadan önce initialize edilir
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:C++’ta **basic types** (temel türler) ve **user-defined types** (kullanıcı tanımlı türler), dilde kullanılan veri türlerini iki ana kategoriye ayırır.

### 1. Basic Types (Temel Türler)

C++ dilinde, **basic types** doğrudan dilin kendisi tarafından sağlanan ve genellikle bellekte sabit bir boyutta olan ilkel veri türleridir. Temel türler şunları içerir:

- **Arithmetic types**:
  - **Integer types**: `int`, `short`, `long`, `unsigned int` vb.
  - **Floating-point types**: `float`, `double`, `long double`
- **Boolean type**: `bool`
- **Character types**: `char`, `wchar_t`, `char16_t`, `char32_t`
- **Null pointer type**: `std::nullptr_t`

### 2. User-Defined Types (Kullanıcı Tanımlı Türler)

Başlıca kullanıcı tanımlı türler şunlardır:
- **Classes**: `class`, `struct` (üye fonksiyonlara ve verilere sahip olabilir)
- **Unions**: Bellek alanını paylaşan türlerdir.
- **Enumerations (enums)**: Sabitler grubu tanımlamak için kullanılır.
- **typedefs / using**: Mevcut türlere yeni isimler vermek için kullanılır.

NOT:Structlarda c++ dilinde class olarak geçer class ile arasındaki tek fark default olarak acces public olması

c de struct anahtar kelimesinden kurtulmak istiyorsak typedef kullanmalıyız

typedef struct Nec {
int x;
}Nec;
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT: C'de aritmetik türlerden bir değerin bir enum türünden değişkene atanması geçerlidir. C++'da
bir enum türünden bir nesneye ancak söz konusu numaralandırma türüne ilişkin bir
“numaralandırma değişmezi” (enumaration constant) atanabilir.
enum Position {ON, OFF, HOLD};
void foo()
{
    enum Position pos = 1;
}
pos değişkenine yapılan atama C‟de geçerli iken C++‟da geçersizdir.

enum Color
{
    White, Gray, Red
};
enum Pos
{
    Open,Ajar,Close
};


void main() {

    enum Color mycolor;
    int x = 2;

    enum Pos pos = Gray; // Sadece C de geçerli
    mycolor = 5; // Sadece C de geçerli
    mycolor = x; // Sadece C de geçerli

    int ival = mycolor; // C de ve C++ dilinde geçerli(C++ için kötü bir durum) Enum türlerinden tam sayı türlerine dönüşüm
}

Color mycolor = 2; // C++ dilinde geçersiz

farklı enumaration türlerinede dönüşüm yok

Color mycolor = Close;

Ama maalesef c++ dilinde geleneksel enuamaration türleri(UNSCOPED ENUMS VEYA CONVENTIONAL ENUMS YADA TRADITIONAL)

Enum türlerinden aritmetik türlere  dönüşüm var bu c++ dili için kötü bir durum diyor hoca

Color mycolor = Gray;
int x = mycolor;

bunun için SCOPED ENUMS eklendi(enum class)

modern c++dan sonra UNSCOPED ENUMS kullanılması hoş görülmez çünkü günümüzde kullanılmasına pek gerek görülmeyebilir

undrlying type modern cpp ile eklendi enum Color : int {White,Gray}; C diline 23 standardı ile eklendi

enum Color {Blue,red,Black};
enum TrafficLight {Blue,red,Black};

aynı scopeta birden fazla numaralarndırm türü oluşturursak isim çakışması durumu olabilir çünkü bu isimler namspace scopeta olmuş oluyor bu yüzden
C++da SCOPED ENUMLAR sayesinde farklı scopeta olmuş olurlar
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde C kütüphanelerini include etmek için başına c konulur
#include <ctime>
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:C++ dilinde `#define` kullanarak makro oluşturmak, bazı sorunlara yol açabileceği için önerilmez. `#define` ile oluşturulan makrolar,
C dilinden miras alınmıştır ve ön işleme aşamasında (preprocessing) çalışır. Ancak C++’ta artık daha güvenli ve esnek olan **const**,
**constexpr**, **inline** fonksiyonlar ve **template** yapıları bulunduğundan, makroların dezavantajları öne çıkmıştır. İşte `#define`
makrolarının zararlı olmasının başlıca nedenleri:

### 1. **Tür Güvenliğinin Olmaması**
Makrolar, dilin tür (type) kontrolünden geçmezler. Bu, tür uyuşmazlıkları ve beklenmeyen davranışlar gibi hatalara yol açabilir. Örneğin,
bir sabit veya işlev yerine makro kullanıldığında, yanlış bir türle çağrıldığında derleme hatası alınmaz.

**Örnek:**

#define PI 3.14
#define SQUARE(x) x * x

int main() {
    double radius = 2.5;
    double area = PI * SQUARE(radius); // Hatalı sonuç!
    // Makro genişleyince `3.14 * 2.5 * 2.5` yerine `(3.14 * 2.5) * 2.5` olur.
    return 0;
}

Bu örnekte `SQUARE(radius)` makrosu genişlediğinde `2.5 * 2.5` değil, `2.5 * 2.5` olarak genişler ve hatalı sonuç verir.

### 2. **Kapsam (Scope) Sorunları**
Makrolar belirli bir kapsam (scope) içinde tanımlanamaz. Bir `#define` makrosu tanımlandığında, dosyanın sonuna kadar geçerli olur,
bu nedenle kapsam sınırlaması yapılamaz. Bu, özellikle büyük projelerde makro adlarının çakışmasına neden olabilir.

### 3. **Debugging ve Hata Ayıklamanın Zor Olması**
Makrolar genişletildiğinde, kaynak kodun kendisinde görünmezler. Bu nedenle hata ayıklarken makroların genişletilmiş halini görmek zorlaşır.
Derleyici, makroların genişletilmesinden sonra hata mesajları verdiğinde, hataların kaynağını bulmak daha zor olur.

### 4. **Yanlışlıkla Yeniden Tanımlanma Riski**
Makrolar yeniden tanımlanabilir ve bu durum beklenmeyen hatalara yol açabilir. Örneğin, `PI` makrosunu birden fazla kez tanımlarsanız, yanlış bir değeri temsil edebilir.

### 5. **Fonksiyon Benzeri Makrolarda Yan Etkiler**
Makrolar, fonksiyonlar gibi parametre alabilir ancak bu parametrelerde yan etkilere dikkat edilmezse hatalara yol açabilir. Parametrelerin her kullanımı,
genişlemede tekrar edilir ve bu da beklenmeyen çoklu değerlendirmelere neden olabilir.

**Örnek:**

#define DOUBLE(x) (x + x)

int main() {
    int i = 5;
    int result = DOUBLE(i++); // i iki kez artırılır!
    // `result` beklenen değerden farklı olur.
    return 0;
}

Bu örnekte `DOUBLE(i++)` genişlediğinde `i++ + i++` olarak değerlendirilir ve `i` beklenenden fazla artırılır.

### 6. **Alternatif Çözümler Var**
Modern C++’ta makrolar yerine tercih edilebilecek daha güvenli ve esnek yapılar bulunur:
- **Sabitler**: `const` veya `constexpr` kullanarak tür güvenliği sağlanabilir.
- **Inline Fonksiyonlar**: Makro yerine işlevsel yapılar kullanarak parametrelerin türü kontrol edilir ve yan etkiler azaltılır.
- **Template**: Makroların sağladığı genellik için `template` yapıları daha iyi bir alternatiftir.

**Örnek: Makro Yerine `constexpr` ve `inline` Kullanımı**

constexpr double PI = 3.14159;

inline int square(int x) {
    return x * x;
}

int main() {
    double radius = 2.5;
    double area = PI * square(radius); // Güvenli ve doğru sonuç!
    return 0;
}

Bu örnekte, `PI` sabiti `constexpr` olarak tanımlandığı için tür güvenliği sağlanır ve `square` işlevi, `inline` fonksiyon olarak tanımlandığından makro gibi davranır ama güvenlidir.

### Özet
Makrolar, C++ dilinde genellikle önerilmez çünkü:
- Tür güvenliği sağlamazlar.
- Kapsam kontrolü zayıftır.
- Hata ayıklama zorlaşır.
- Yan etkiler içerir.
- Alternatif çözümler mevcuttur.

Bu nedenlerden dolayı, C++ projelerinde `#define` makroları yerine modern C++ dil özellikleri tercih edilmelidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde nesnelerin ilkdeğer atama (initialization) işlemleri oldukça kapsamlıdır ve çeşitli şekillerde yapılabilir. Bu işlemler, nesnelerin türüne ve kullanılan
sentaksa bağlı olarak farklılık gösterebilir. Aşağıda C++'ta kullanılan başlıca initialization türleri açıklanmıştır:

NOT:Global variables ve static variables 0 değeri ile hayata başlar

### 1. Default Initialization

Default initialization, nesneye herhangi bir başlangıç değeri verilmediğinde gerçekleşir. Nesnenin türüne bağlı olarak, bu işlem sonucunda nesne bir başlangıç değerine sahip olabilir veya olmayabilir.

- **Temel Türler (Fundamental Types):** Değer verilmez ve nesne çöp değer içerir.
- **Sınıf Türleri (Class Types):** Varsayılan yapıcı (default constructor) çağrılır.

int x;            // Temel tür, x çöp değer içerir
std::string str;  // Sınıf türü, varsayılan yapıcı çağrılır

### 2. Value Initialization

Value initialization, özellikle `{}` kullanılarak yapılan ilkleme işlemidir. Bu, nesneleri sıfır veya boş bir değere başlatır.

- **Temel Türler:** Sıfır değeri ile başlatılır.
- **Sınıf Türleri:** Varsayılan yapıcı çağrılır, yoksa sıfır ile başlatılır.

int x{};          // Temel tür, x sıfır değeri içerir
std::string str{}; // Sınıf türü, varsayılan yapıcı çağrılır

### 3. Zero Initialization

Zero initialization, nesnelerin sıfır değerine başlatılmasıdır. Bu genellikle dinamik bellek tahsisi sırasında veya statik/değişmez (static/const) değişkenler için geçerlidir.

int x = 0;         // Temel tür, x sıfır değeri içerir
int arr[10] = {};  // Dizi türü, tüm elemanlar sıfır ile başlatılır

### 4. Copy Initialization

Copy initialization, bir nesneyi başka bir nesne ile ilkleme işlemidir. Bu işlem, kopya yapıcıyı (copy constructor) çağırır.

int x = 42;               // Temel tür, x 42 değeri ile başlatılır
std::string str = "Hello"; // Sınıf türü, kopya yapıcı çağrılır

### 5. Direct Initialization

Direct initialization, nesne başlatılırken doğrudan parantez veya küme parantezleri kullanılarak yapılan ilklemedir. Bu, copy initialization'dan daha verimlidir ve
kopya yapıcıyı çağırmadan doğrudan ilkleme yapılır.

int x(42);                // Temel tür, x 42 değeri ile başlatılır -> Direct Initialization
std::string str("Hello");  // Sınıf türü, doğrudan ilkleme -> Direct Initialization
std::string str2{"Hello"}; // Sınıf türü, doğrudan ilkleme (C++11 ve sonrası) Direct List Initialization

### 6. Direct List Initialization

C++11 ile tanıtılan list initialization, küme parantezleri `{}` kullanarak nesnelerin ilkdeğer verilmesini sağlar. Bu yöntem, daraltıcı (narrowing) dönüşümlerini önler ve daha güvenlidir.

int x{42};                // Temel tür, x 42 değeri ile başlatılır
std::string str{"Hello"};  // Sınıf türü, list initialization
std::vector<int> vec{1, 2, 3}; // Sınıf türü, vector ilkleme

### 7. Aggregate Initialization

Aggregate initialization, yapısal (structural) türlerin ilkdeğer verilmesinde kullanılır. Bu türler, sınıf veya struct türü olabilir.

struct Point {
    int x;
    int y;
};

Point p = {1, 2}; // Aggregate initialization, p.x = 1, p.y = 2

### Özet
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ Dilinde main fonksiyonunun geri dönüş değeri int olmak zorundadır

c++ dilinde geri dönüş değeri fonksiyonun geri dönüş değeri olmak zorundadır

global yada static değişeğişkenler hayata zero initalize ile başlar
--------------------------------------------------------------------------------------------------------------------------------------------------
uniform initalizationda narrowing conversion söz konusudur

    double x{ 5.5 };
    int z { x }; // narrowing conversion(daraltıcı dönüşüm)

daraltıcı dönüşüme karşı bizi korur veri kaybını önler

uniform initialization'ın getirilmesinin bir diğer nedenide most vexing pars
--------------------------------------------------------------------------------------------------------------------------------------------------
"Most Vexing Parse," C++ dilinde oldukça karmaşık ve kafa karıştırıcı bir sözdizimsel sorun olarak bilinir. Bu terim, C++'ta bir bildirimin aslında bir değişken bildirimi olarak düşünüldüğünde
bir fonksiyon bildirimi olarak yorumlanabileceği durumu tanımlar. Bu, özellikle sınıf türlerinin nesnelerini başlatmak için parantezli ilkleme kullanırken ortaya çıkabilir.

### Örnek

class A {
public:
    A(int x) {}
};

int main() {
    A a(); // Bu bir fonksiyon bildirimi olarak yorumlanır.
}

Yukarıdaki örnekte, `A a();` ifadesi, `a` isimli bir nesne tanımı gibi görünebilir, ancak aslında `A` türünde `a` isimli bir fonksiyonun bildirimi olarak yorumlanır.
Bu fonksiyon, hiçbir parametre almayan ve `A` türünde bir değer döndüren bir fonksiyon olarak tanımlanmıştır.

### Çözüm

Most Vexing Parse durumunu önlemek için birkaç farklı yaklaşım kullanılabilir:

#### 1. Küme Parantezi Kullanımı(Brace intialization yada uniform initalization)

C++11 ve sonrasında küme parantezleri `{}` kullanarak nesneleri başlatabilirsiniz. Bu yöntem, listenin ilk değeri vermesi olarak bilinir ve most vexing parse sorununu önler.

int main() {
    A a{5}; // Doğru: Bu, a isimli bir nesne tanımlamasıdır.
}

#### 2. Parantezleri Kullanma

Nesneleri başlatmak için küme parantezi yerine doğrudan atama kullanabilirsiniz.

int main() {
    A a = A(5); // Doğru: Bu, a isimli bir nesne tanımlamasıdır.
}

#### 3. Doğrudan Atama

Nesneleri başlatmak için doğrudan atama kullanarak sorunları önleyebilirsiniz.

int main() {
    A a(5);(direct intialization) // Doğru: Bu, a isimli bir nesne tanımlamasıdır.
}

### Özet

Most Vexing Parse, C++'ta değişken ve fonksiyon bildirimleri arasındaki sözdizimsel belirsizliklerden kaynaklanır. Bu tür sorunlardan kaçınmak için küme parantezi `{}`
kullanarak ilkleme yapabilir veya doğrudan atama yöntemlerini tercih edebilirsiniz. Bu, kodun daha okunabilir ve güvenilir olmasını sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **"As-if Rule" (Sanki Kuralı) - C++** (observable behaviour)

**As-if rule** (Sanki kuralı), C++ ve diğer dillerde derleyicinin **optimizasyon** yaparken programın **dışarıdan gözlemlenebilir davranışını(observable behaviour)**
değiştirmemesini garanti eden bir prensiptir.

Bu kural, derleyiciye **kodun çalışma şeklini değiştirmeden** herhangi bir dönüşüm yapma özgürlüğü tanır. **Dışarıdan gözlemlenebilir davranış** derken şunlar kast edilir:
- **Bellek ve dosya işlemleri** (girdi-çıktı işlemleri, `std::cout`, `std::cin` vb.)
- **Açık şekilde tanımlanmış yan etkiler** (örneğin, bir değişkenin değerinin değiştirilmesi)
- **Concurrency (çoklu iş parçacığı) ile ilgili etkileşimler**

Eğer bir optimizasyon, programın dışarıdan gözlemlenebilir davranışını değiştirmiyorsa, derleyici onu yapabilir.

### **As-if Rule’un Çalışma Mantığı**
C++ standardına göre, bir program **"sanki" (as-if) orijinal kodu çalıştırıyormuş gibi davranmalıdır**. Yani:
- **Gereksiz hesaplamalar kaldırılabilir.**
- **Kod farklı bir sırayla çalıştırılabilir.**
- **Bazı ifadeler hiç çalıştırılmayabilir.**

Ancak, **dış dünyadan gözlemlenebilir herhangi bir değişiklik olmamalıdır**.

### **As-if Rule Örnekleri**

#### **1. Kullanılmayan Değişkenlerin Kaldırılması (Dead Code Elimination)**

void foo() {
    int x = 5; // x hiçbir yerde kullanılmıyor
}

🔹 **Ne olur?**
- `x` değişkeni gereksizdir.
- Derleyici, `int x = 5;` ifadesini tamamen kaldırabilir.

#### **2. Sabit İfadelerin Önceden Hesaplanması (Constant Folding)**

int getValue() {
    return 2 * 3 + 4; // 6 + 4 = 10
}

🔹 **Ne olur?**
- Derleyici `2 * 3 + 4` ifadesini **derleme zamanında 10** olarak hesaplar.
- Sonuç, direkt `return 10;` olarak değiştirilebilir.

#### **3. Gereksiz Fonksiyon Çağrılarının Kaldırılması (Function Inlining)**

inline int square(int x) { return x * x; }

int main() {
    int a = square(5);
}

🔹 **Ne olur?**
- Normalde `square(5)` fonksiyon çağrılır.
- **Derleyici, fonksiyonu çağırmak yerine direkt `int a = 5 * 5;` olarak değiştirir.**
- `square` fonksiyonu **aslında çağrılmaz**.

#### **4. Kodun Yeniden Sıralanması (Instruction Reordering)**

#include <iostream>

void foo() {
    int x = 10;
    int y = 20;
    std::cout << "Hello\n";
    int z = x + y;
}

🔹 **Ne olur?**
- `x` ve `y` değişkenlerinin atanması **`std::cout` işleminden önce veya sonra** gerçekleşebilir.
- Ancak, `std::cout << "Hello\n";` çıktısı **mutlaka aynı kalmalıdır**.
- Derleyici, yan etki içermeyen `int z = x + y;` işlemini önce veya sonra çalıştırabilir.

### **As-if Rule Ne Yapamaz? (Örnekler)**

Derleyici **programın gözlemlenebilir davranışını değiştiremez!**

#### ❌ **Yan Etkisi Olan Bir İşlem Kaldırılamaz**

void foo() {
    int x = 5;
    std::cout << x;  // x kullanıldığı için derleyici kaldırmaz
}

🔹 **Ne olur?**
- `std::cout << x;` bir **gözlemlenebilir yan etkiye** sahiptir.
- `x` değişkeni kullanıldığı için derleyici **onu kaldırmaz**.

#### ❌ **Girdi-Çıktı Sırası Değiştirilemez**

std::cout << "Merhaba";
std::cout << " Dünya";

🔹 **Ne olur?**
- `"Merhaba Dünya"` çıktısı **aynı kalmalıdır**.
- Derleyici `" Dünya"` yazdırmasını `"Merhaba"`dan önceye alamaz.

### **Sonuç**

✅ **As-if Rule**, derleyiciye agresif optimizasyon yapma özgürlüğü tanır, ancak programın **gözlemlenebilir davranışını** değiştirmemesini garanti eder.
✅ Bellek ve çıktı işlemleri korunurken, gereksiz hesaplamalar ve kod parçaları kaldırılabilir.
✅ Derleyiciler **sadece sanki orijinal kod çalışıyormuş gibi optimize ederler**, ancak **görünür değişiklikler yapamazlar**.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **unevaluated context** (işlem kodu üretilmeyen bağlam), bir ifadenin **derleme zamanı**
sırasında yalnızca sözdizimsel olarak işlendiği, ancak **gerçek bir değer hesaplanmadığı** ve yürütülmediği bağlamları ifade eder.

Bu tür bağlamlarda ifadeler değerlendirilmez, yani:
- **Yan etkileri olmaz** (örneğin, bir değişken artırılmaz).
- **Derleyici yalnızca tür veya boyut bilgisine ihtiyaç duyar**.

### **Unevaluated Context Olan Durumlar**

1. **`sizeof` operatörü**
2. **`decltype` ifadesi**
3. **`noexcept` operatörü**
4. **`typeid` operatörü** (ancak operandın statik türü biliniyorsa)
5. **Konsept gereksinimleri (`requires` ifadeleri)**
6. **Lambda ifadelerinin `decltype` içinde kullanımı**

## **1. `sizeof` Operatörü**
`sizeof` operatörünün operandı **unevaluated context** içindedir. Operand değerlendirilmez ve sadece tür bilgisi kullanılır.

Örnek:

int x = 10;
sizeof(x++); // x++ işlemi GERÇEKLEŞMEZ, x'in değeri değişmez

Burada `x++` ifadesi `sizeof` içinde olduğu için çalıştırılmaz, dolayısıyla `x`'in değeri aynı kalır.

## **2. `decltype` İfadesi**
`decltype` ifadesinin içindeki ifadeler değerlendirilmez, yalnızca **tür bilgisi** alınır.

Örnek:

int x = 10;
decltype(x++) y; // x++ değerlendirilmiyor, sadece türü belirleniyor

Burada `x++` çalıştırılmaz, ancak türü `int` olarak belirlenir ve `y` değişkeni bu türe göre tanımlanır.

## **3. `noexcept` Operatörü**
Bir fonksiyonun istisna atıp atmadığını kontrol eden `noexcept` operatörü de **unevaluated context** içinde çalışır.

Örnek:

void func() noexcept {}
bool b = noexcept(func()); // func() ÇAĞRILMAZ, sadece istisna fırlatıp fırlatmadığı kontrol edilir

Burada `func()` çağrılmıyor, sadece istisna atıp atmadığı derleme zamanında kontrol ediliyor.

## **4. `typeid` Operatörü**
`typeid` operatörü, eğer operandı **statik olarak bilinen bir tür** ise çalıştırılmaz.
Ancak, operand **polimorfik bir nesne** ise (sanal fonksiyonları olan bir sınıf), çalışma zamanında değerlendirilebilir.

Örnek:

struct Base { virtual ~Base() {} };
struct Derived : Base {};

Base* b = new Derived();
const std::type_info& ti = typeid(*b); // ÇALIŞMA ZAMANINDA değerlendirilir

int main() {

    std::cout << ti.name(); // Struct Derived
}

Ancak:

int x = 5;
typeid(x++); // x++ değerlendirilmiyor, sadece türü kullanılıyor

Burada `x++` çalıştırılmaz.

## **5. `requires` İfadeleri (Konseptler - C++20)**
C++20 ile gelen `requires` ifadelerinde, konseptin sağlanıp sağlanmadığını kontrol etmek için yazılan kod **unevaluated context** içinde olur.

Örnek:

template<typename T>
concept Addable = requires(T a, T b) {
    a + b; // Burada a + b DEĞERLENDİRİLMEZ, yalnızca geçerli olup olmadığı kontrol edilir
};

Burada `a + b` işlemi gerçekten yapılmaz, sadece yazılabilir olup olmadığı kontrol edilir.

## **6. Lambda İçinde `decltype` Kullanımı**
Lambda ifadeleri, `decltype` içinde kullanıldığında değerlendirilmez.

Örnek:

auto lambda = [](int x) { return x * 2; };
decltype(lambda(5)) result; // lambda(5) çağrılmaz, sadece dönüş türü belirlenir

Burada `lambda(5)` çağrılmaz, sadece dönüş tipi belirlenir.

## **Özet**
**Unevaluated context** içinde olan ifadeler **değerlendirilmez, çalıştırılmaz ve yan etki oluşturmaz**.
Bunlar genellikle derleme zamanında **tür bilgisi veya geçerlilik kontrolü** için kullanılır.

**Örnek Kullanım Alanları:**
- **`sizeof`** → Bellek boyutunu hesaplamak için
- **`decltype`** → Bir ifadenin türünü almak için
- **`noexcept`** → İstisna fırlatma durumunu kontrol etmek için
- **`typeid`** → Tür bilgisine erişmek için
- **`requires` (C++20)** → Konsept kontrolü için

Bunların hiçbirinde gerçek bir **hesaplama veya işlem** yapılmaz, sadece derleyici seviyesi kontroller gerçekleştirilir.

*/