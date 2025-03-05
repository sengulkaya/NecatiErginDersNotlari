/*

                                                                             ********* 1-DERS NOTLARI *********             

her implementation defined unspecified behaviourdır ama her unspecified behaviour implementatiom defined değildir                      

Undefined Behavior(Tanımsız Davranış) Nedir:

Undefined behavior (UB), C++ programlama dilinde ve diğer birçok düşük seviye programlama dilinde, belirli bir durum veya işlem gerçekleştirildiğinde 
dilin standardında belirlenmemiş ve beklenmeyen sonuçlara yol açabilecek davranışı ifade eder. Bu, derleyicinin veya çalıştırma zamanının belirli bir 
işlem veya kod parçasının sonucunu belirlememesine veya garantilememesine neden olur.

Undefined behavior'ın birkaç yaygın nedeni şunlardır:

1. **Geçersiz Bellek Erişimi**: Tanımsız veya serbest bırakılmış belleğe erişim.
2. **Bölme İşlemi**: Sıfıra bölme.
3. **Out-of-Bounds Erişim**: Dizinin sınırları dışına çıkma.
4. **Yanlış Tür Dönüşümleri**: Uygunsuz tür dönüşümleri veya tür güvenliği ihlalleri.
5. **Tanımsız Değişken Kullanımı**: Başlatılmamış değişkenlere erişim.
6. **Reentrancy İhlalleri**: Yeniden girilebilir olmayan fonksiyonların yeniden çağrılması.
    Reentrancy ihlalleri, bir fonksiyonun kendini tekrar çağırması veya aynı anda başka bir yerden tekrar çağrılması sırasında ortaya çıkar. 
    Bu genellikle çok iş parçacıklı programlamada veya kesme (interrupt) işlemlerinde gerçekleşir.
7. **Signed Integer Overflow**: İşaretli tamsayı taşması.

### Undefined Behavior'ın Önemi

Undefined behavior, programların beklenmeyen şekillerde çalışmasına veya hata vermesine neden olabilir. En kötü durumda, 
UB güvenlik açıklarına veya sistem çökmesine neden olabilir. UB'nin etkileri şunlar olabilir:

- **Derleyici Optimizasyonları**: UB içeren kod, derleyicilerin agresif optimizasyonları nedeniyle beklenmedik şekilde davranabilir.
- **Platform Bağımsızlığı**: UB, farklı platformlarda farklı sonuçlar üretebilir.
- **Debugging Zorlukları**: UB, hata ayıklamayı zorlaştırabilir çünkü hatalar belirsiz ve tutarsız olabilir.

### Undefined Behavior Örnekleri

1. **Geçersiz Bellek Erişimi**:

int* p = nullptr;
int value = *p; // Undefined behavior: null pointer dereference

2. **Out-of-Bounds Erişim**:

int arr[5] = {1, 2, 3, 4, 5};
int value = arr[10]; // Undefined behavior: out-of-bounds array access

3. **Signed Integer Overflow**:

int a = INT_MAX;
int b = a + 1; // Undefined behavior: signed integer overflow

4. **Tanımsız Değişken Kullanımı**:

int x;
int y = x + 1; // Undefined behavior: uninitialized variable

5. **Sıfıra Bölme**:

int a = 10;
int b = 0;
int c = a / b; // Undefined behavior: division by zero

### Undefined Behavior'dan Kaçınma Yöntemleri

Undefined behavior'dan kaçınmak için aşağıdaki iyi uygulamaları benimseyebilirsiniz:

- **Bellek Yönetimi**: Bellek tahsisini ve serbest bırakmayı dikkatlice yönetin. Serbest bırakılmış belleğe erişimden kaçının.
- **Dizi Erişimi**: Dizilere erişirken sınır kontrolleri yapın.
- **Değişken Başlatma**: Tüm değişkenleri kullanmadan önce başlatın.
- **Tür Güvenliği**: Tür dönüşümlerine dikkat edin ve tür güvenliğini ihlal etmeyin.
- **Derleyici Uyarıları**: Derleyici uyarılarını dikkate alın ve mümkünse tüm uyarıları düzeltin.
- **Statik Analiz Araçları**: Undefined behavior'ı tespit etmek için statik analiz araçları kullanın.

Undefined behavior, C++'ın esnekliğinin ve performansının bir yan ürünüdür, ancak dikkatli programlama ve uygun kontrollerle büyük ölçüde önlenebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
Unspecified Behavior(Belirtilmemiş Davranış) Nedir:

Unspecified behavior, C++ programlama dilinde ve diğer birçok düşük seviye programlama dilinde, belirli bir işlem veya ifadenin sonuçlarının dil standardında
kesin olarak tanımlanmadığı ancak bir dizi kabul edilebilir sonuç arasından birinin seçileceği durumu ifade eder. Bu, derleyicinin veya çalıştırma zamanının,
hangi özel sonucu vereceğine karar vermekte serbest olduğu, ancak belirli bir dizi olası sonuçtan biriyle sınırlı olduğu anlamına gelir.

### Unspecified Behavior'ın Önemi

Unspecified behavior, undefined behavior kadar tehlikeli olmasa da, programın farklı derleyicilerde veya farklı derleyici sürümlerinde
farklı sonuçlar üretebileceği anlamına gelir. Bu, yazılımın taşınabilirliğini ve tutarlılığını etkileyebilir.

### Unspecified Behavior Örnekleri

1. **Fonksiyon Parametrelerinin Değeri**:
   C++ standardına göre, fonksiyon parametrelerinin değerlenme sırası belirlenmemiştir.

   void func(int a, int b);
   int x = 10;
   func(x++, x++); // Unspecified behavior: sıra belirlenmemiştir

2. **Yan Etkiler ve Değerlemeler**:
   Bir ifadedeki yan etkilerin gerçekleştirilme sırası belirlenmemiştir.

   int i = 0;
   int a = i++ + i++; // Unspecified behavior: değerlenme sırası belirlenmemiştir

Unspecified behavior'dan kaçınmak için aşağıdaki iyi uygulamaları benimseyebilirsiniz:

- **Yan Etki(side effect) Sırası**: Yan etkilerin sırası belirli olmayan ifadelerden kaçının.
- **Fonksiyon Parametreleri**: Fonksiyon parametrelerinin değerlenme sırasına bağımlı ifadelerden kaçının.
- **Statik Analiz**: Kodunuzu analiz eden ve unspecified behavior konusunda uyarılar veren statik analiz araçları kullanın.

Unspecified behavior, kodun tahmin edilebilir ve taşınabilir olmasını zorlaştırabilir, bu nedenle belirtilmemiş davranışlardan kaçınmak iyi bir programlama uygulamasıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
Implementation-Defined Behavior (Uygulama Tanımlı Davranış) Nedir:

C++'ta "implementation-defined behavior" terimi, belirli bir işlemin veya ifadenin sonucu veya etkisinin, C++ standardı tarafından tanımlanmadığı ancak her derleyici
veya çalışma zamanı ortamının bu durumu nasıl ele alacağına dair kendi tanımını sağladığı durumu ifade eder. Yani, bu davranışlar derleyiciye veya platforma
özgüdür ve her bir derleyici veya platform tarafından dökümantasyonda açıklanmalıdır.

### Implementation-Defined Behavior'ın Önemi

Implementation-defined behavior, programın taşınabilirliğini etkileyebilir çünkü bir derleyicide veya platformda çalışırken beklenen sonuçlar, başka bir derleyici
veya platformda farklı olabilir. Bu nedenle, bu tür davranışlar hakkında farkındalık, programın farklı ortamlarda tutarlı çalışmasını sağlamak için önemlidir.

### Implementation-Defined Behavior Örnekleri

1. **Char Türünün İşareti**:
   C++ standardı, `char` türünün işaretli (`signed`) mi yoksa işaretsiz (`unsigned`) mi olduğunu belirtmez. Bu, derleyiciye bağlıdır.

   char c = -1; // Implementation-defined: `char` işaretli mi, işaretsiz mi?

2. **Yazılım Bellek Düzeni**:
   Bir yapının (`struct`) üyelerinin bellek içindeki düzeni de implementation-defined olabilir.

   struct MyStruct {
       int a;
       char b;
       double c;
   }; // Implementation-defined: Üyelerin bellekteki sırası ve hizalaması

3. **Dosya Açma Modu**:
   C++'ta bir dosyayı açarken kullanılan modların tam anlamı implementation-defined olabilir.

   std::fstream file("example.txt", std::ios::out | std::ios::binary);
   // Implementation-defined: `std::ios::binary` modunun davranışı

### Implementation-Defined Behavior Örneği

Aşağıdaki örnek, `char` türünün işaretli olup olmadığını belirlemek için kullanılan implementation-defined bir durumu gösterir:

#include <iostream>

int main() {
    char c = -1;
    if (c < 0) {
        std::cout << "char is signed" << std::endl;
    } else {
        std::cout << "char is unsigned" << std::endl;
    }
    return 0;
}

Bu kodun çıktısı, derleyiciye ve platforma bağlı olarak değişebilir. Bazı derleyiciler `char` türünü işaretli (`signed`) olarak tanımlar, bazıları ise işaretsiz (`unsigned`) olarak tanımlar.

Implementation-defined behavior ile çalışırken dikkate alınması gereken bazı noktalar:
- **Dokümantasyon**: Kullandığınız derleyicinin veya platformun dökümantasyonunu dikkatlice okuyun ve implementation-defined davranışlarını anlayın.
- **Taşınabilirlik**:s Kodunuzu farklı derleyicilerde veya platformlarda test edin ve beklenmeyen davranışlardan kaçınmak için gerekli ayarlamaları yapın.
- **İşaretçiler ve Bellek Yönetimi**: Bellek düzeni ve işaretçi aritmetiği gibi konularda implementation-defined davranışlara dikkat edin.

Implementation-defined behavior, derleyiciye veya platforma özgü olan ancak dökümantasyonda açıkça belirtilen bir davranıştır. Bu tür davranışlarla başa çıkarken
derleyici veya platform dökümantasyonuna güvenmek ve kodun taşınabilirliğini sağlamak önemlidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:**Lexical Analysis** (sözcüksel analiz), bir programın kaynak kodunu daha küçük bileşenlere (token'lara) ayıran ilk derleme aşamasıdır. 
C++ ve diğer dillerde, bu aşama bir derleyicinin başlangıç aşaması olup, karakter akışını dilin sözdizimsel yapılarına ayırır.

### Lexical Analysis Süreci:
1. **Kaynak Koddan Token Üretimi**: Programın kaynak kodu, belirli dil kurallarına göre token adı verilen daha küçük parçalara ayrılır.

2. **Token Türleri**: C++ dilinde yaygın olarak kullanılan token türleri şunlardır:
   - Anahtar Kelimeler (keywords): `if`, `else`, `while`, `int`, vb.
   - Tanımlayıcılar (identifiers): Değişken, fonksiyon adları.
   - Sabitler (literals): Sayılar, karakterler, dizgiler.
   - Operatörler (operators): `+`, `-`, `*`, `/`, vb.
   - Ayırıcılar (delimiters): `;`, `,`, `{`, `}`, vb.
   - Yorumlar (comments): `//`, '/* /*' 

       ### Lexical Analysis'ın İşlevleri:
       - **Boşluk ve Yorumları Göz Ardı Etme * *: Boşluklar ve yorumlar, programın sözdizimini etkilemediği için bu aşamada göz ardı edilir.
       - **Hata Tespiti * *: Geçersiz karakterler veya token'lar tespit edilerek derleme hataları raporlanır.

       Bir kaynak kodun lexical analysis süreci şu şekilde işler :

       int main() {
       int x = 42;
       return x;
   }
       1. * *Token'lara Ayrılma**:
       - `int`: Anahtar kelime
       - `main`: Tanımlayıcı
       - `(`, `)`, `{`, `}`: Ayırıcılar
       - `int`: Anahtar kelime
       - `x`: Tanımlayıcı
       - `=`: Operatör
       - `42`: Sabit
       - `;`: Ayırıcı
       - `return`: Anahtar kelime
       - `x`: Tanımlayıcı
       - `;`: Ayırıcı

       2. * *Sonuç * *: Bu token'lar daha sonra sözdizimsel analiz (syntax analysis) aşamasına geçer.

       Lexical analysis, doğru ve etkili bir derleme sürecinin temel taşıdır.Token'lar üzerinden yapılan bu ayrıştırma, 
       programın daha karmaşık sözdizimsel yapılarının anlaşılmasını sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
Short-Circuit (Kısayol Değerlendirme) Nedir:

"Short-circuit evaluation" (kısayol değerlendirme) terimi, genellikle mantıksal `&&` (ve) ve `||` (veya) operatörlerinin kullanımı sırasında karşılaşılan bir değerlendirme 
tekniğini ifade eder. Bu teknik, ifadenin tamamının değerlendirilmesine gerek kalmadan sonucun belirlenebilmesini sağlar.

### Short-Circuit Evaluation Nasıl Çalışır?

- **Mantıksal VE (`&&`) Operatörü**:
  - İlk operand `false` ise, ifadenin tamamı `false` olur ve ikinci operand değerlendirilmez.
  - İlk operand `true` ise, ifadenin sonucu ikinci operanda bağlıdır.

- **Mantıksal VEYA (`||`) Operatörü**:
  - İlk operand `true` ise, ifadenin tamamı `true` olur ve ikinci operand değerlendirilmez.
  - İlk operand `false` ise, ifadenin sonucu ikinci operanda bağlıdır.

### Örnekler

1. **Mantıksal VE (`&&`) Operatörü**:

   bool a = false;
   bool b = true;

   if (a && b) {
       // Bu blok çalıştırılmayacak çünkü 'a' false ve 'b' değerlendirilmez.
   }

2. **Mantıksal VEYA (`||`) Operatörü**:

   bool a = true;
   bool b = false;

   if (a || b) {
       // Bu blok çalıştırılacak çünkü 'a' true ve 'b' değerlendirilmez.
   }

### Short-Circuit Evaluation'ın Avantajları

- **Performans**: Gereksiz hesaplamalardan kaçınılır. Özellikle uzun ve karmaşık ifadelerde performans avantajı sağlar.
- **Yan Etkiler**: İkinci operandın yan etkileri (örneğin, fonksiyon çağrıları) varsa, bu yan etkiler yalnızca ihtiyaç duyulduğunda gerçekleşir. Bu, kodun daha güvenli ve öngörülebilir olmasını sağlar.

### Yan Etkiler ve Dikkat Edilmesi Gereken Noktalar

Short-circuit evaluation, bazı durumlarda beklenmeyen sonuçlara yol açabilir, özellikle de operandların yan etkileri varsa. Örneğin:

bool func1() {
    std::cout << "func1 called" << std::endl;
    return false;
}

bool func2() {
    std::cout << "func2 called" << std::endl;
    return true;
}

int main() {
    if (func1() && func2()) {
        // func1 'false' döndüğünde, func2 çağrılmaz.
    }
    return 0;
}

Bu örnekte, `func1()` `false` döndürdüğünde `func2()` hiç çağrılmaz ve "func2 called" mesajı yazdırılmaz.

### Short-Circuit Evaluation ve Uygulama

Short-circuit evaluation, genellikle koşullu ifadelerde ve hata kontrolü gibi durumlarda kullanılır:

int* ptr = nullptr;
if (ptr != nullptr && *ptr > 0) {
    // ptr geçerli bir işaretçi olduğunda dereference edilir.
}

Bu durumda, `ptr` `nullptr` ise, `*ptr` ifadesi değerlendirilmez ve program çökmekten kurtulur.

### Sonuç

Short-circuit evaluation, performans ve güvenlik açısından önemli bir tekniktir. Mantıksal `&&` ve `||` operatörleriyle kullanılır ve operandların
yan etkilerini göz önünde bulundurmak, beklenmeyen sonuçlardan kaçınmak için önemlidir. Bu tekniği dikkatlice kullanarak kodunuzu daha verimli ve güvenli hale getirebilirsiniz.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Name Hiding** (İsim Gizleme), C++’ta bir türetilmiş sınıfın (derived class), temel sınıftaki (base class) bir üyeyi aynı isimle tekrar 
tanımlaması durumunda oluşan bir durumdur. Bu, **değişkenlerde, fonksiyonlarda ve typelarda** görülebilir.

📌 **Önemli:** **Name Hiding**, fonksiyonların **overriding (geçersiz kılma)** işlemiyle karıştırılmamalıdır. Overriding, yalnızca sanal 
fonksiyonlarda (virtual functions) olur ve temel sınıftaki fonksiyonu geçersiz kılar. **Name Hiding ise aynı isimli tüm fonksiyonları gizler.**

## **1. Name Hiding in Variables (Değişkenlerde İsim Gizleme)**
Türetilmiş sınıf, temel sınıftaki bir üye değişkenle aynı isme sahip bir değişken tanımladığında, temel sınıftaki değişken **gizlenir**.

#include <iostream>

class Base {
public:
    int value = 10;
};

class Derived : public Base {
public:
    int value = 20; // Base::value gizlenir!
};

int main() {
    Derived obj;
    std::cout << obj.value << std::endl; // Çıktı: 20
}

✔ **Çözüm:** Temel sınıftaki değişkene erişmek için `Base::value` kullanılabilir.

std::cout << obj.Base::value << std::endl; // Çıktı: 10

## **2. Name Hiding in Functions (Fonksiyonlarda İsim Gizleme)**
Türetilmiş sınıf, temel sınıftaki bir fonksiyonla aynı isimde bir fonksiyon tanımladığında, **aynı isimdeki tüm versiyonları gizler**.

#include <iostream>

class Base {
public:
    void show(int x) { std::cout << "Base::show(int) -> " << x << std::endl; }
};

class Derived : public Base {
public:
    void show() { std::cout << "Derived::show()" << std::endl; }
    // Base::show(int) tamamen gizlenir!
};

int main() {
    Derived obj;
    obj.show();     // Derived::show() çağrılır
    obj.show(10);   // HATA: Base::show(int) gizlendi!
}

✔ **Çözüm:** Temel sınıftaki fonksiyonları görünür hale getirmek için `using` anahtar kelimesi kullanılabilir.

class Derived : public Base {
public:
    using Base::show; // Base sınıfındaki show(int) fonksiyonunu görünür yapar!
    void show() { std::cout << "Derived::show()" << std::endl; }
};

Böylece `obj.show(10);` artık çalışır.

## **3. Name Hiding in Types (Türlerde İsim Gizleme)**
Türetilmiş sınıf, temel sınıfta bulunan bir tür tanımını gizleyebilir.

class Base {
public:
    using Type = int;
};

class Derived : public Base {
public:
    using Type = double; // Base::Type gizlenir!
};

Derived::Type x = 3.14; // Derived içindeki double kullanılır

✔ **Çözüm:** `Base::Type` ile temel sınıftaki tür açıkça belirtilebilir.


Base::Type y = 42; // int olarak kullanılır

### **Sonuç**
- **Aynı isimli değişkenler türetilmiş sınıfta tanımlandığında, temel sınıftaki değişken gizlenir.**
- **Aynı isimde bir fonksiyon türetilmiş sınıfta tanımlandığında, temel sınıftaki tüm overload'lar gizlenir.**
- **Aynı isimli tür tanımları türetilmiş sınıfta yapıldığında, temel sınıftaki tür tanımı gizlenir.**

✔ **Çözüm olarak, `using Base::function;` veya `Base::member;` şeklinde erişim sağlanabilir.**
--------------------------------------------------------------------------------------------------------------------------------------------------
Scope Leakage (Kapsam Sızıntısı) Nedir:

bir programlama dilinde kapsamın (scope) beklenmedik veya istenmeyen şekilde değişmesi veya etki alanının dışındaki bir değişkenin beklenmeyen
şekilde erişilebilir olması durumunu ifade eder. Bu durum genellikle programcı hatalarından kaynaklanır ve programın doğru çalışmasını engelleyebilir.

### Örnek:

int foo();

int main()
{
    int x = foo();

    if(x > 10)
    {
        //code
    }

}

bu örnekte x değişkeni main bitene kadar devam eder ve scope leakage oluşur x başka yerde kullanılmıyorsa foo
fonksiyonunu x değerine atamak mantıksızdır çünkü bu atama programcıya x değişkeninin başka yerdede
kullanılabileceğini söyler x değeri başka yerde kullanılmıyorsa scope leakage önlemek için şu şekilde tanımlamak daha doğrudur

    if(foo() > 10)
    {
        //code
    }
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:**Null pointer conversion** C++'ta, bir işaretçinin (pointer) veya işlev işaretçisinin geçerli bir nesne veya işlevi göstermediği 
durumları ifade eder. Bu tür bir işaretçi genellikle **null pointer** olarak adlandırılır ve standart C++'ta birkaç şekilde elde edilebilir.

### Null Pointer Conversion Nedir?
C++'ta, bir işaretçi türü **null pointer** olarak ayarlanabilir veya dönüştürülebilir. Bu işlem, aşağıdaki durumlarda gerçekleşir:

1. **Null Pointer Literali Kullanma**: `nullptr` anahtar kelimesi, bir işaretçinin geçerli bir nesne veya işlevi göstermediğini belirtir.
2. **`0` veya `NULL` Kullanımı**: Geçmişte, `0` veya `NULL` makrosu null pointer için kullanılırdı. Ancak modern C++'ta `nullptr` tercih edilir.
3. **Null Pointer'a Dönüşüm**: Bir işaretçi türü, `nullptr` veya `0` ile atanarak null pointer'a dönüştürülebilir.

### Örnekler:

#### `nullptr` ile Null Pointer:

int* p = nullptr; // 'p' geçerli bir nesneyi işaret etmeyen bir işaretçidir

#### `0` ile Null Pointer (eski tarz):

int* p = 0; // Null pointer, modern C++'ta önerilmez

#### Null Pointer Kontrolü:

int* p = nullptr;
if (p == nullptr) {
    // p geçerli bir nesneye işaret etmiyor
}

### Null Pointer Conversion'ın Kullanım Alanları:
- **Güvenli İşaretçi Kontrolleri**: Null pointer dönüşümleri, işaretçinin geçerli bir nesneyi işaret edip etmediğini kontrol etmek için kullanılır.
- **Varsayılan İşaretçi Değeri**: İşaretçilerin ilk değerlerinin null pointer olması, bellek hatalarının önlenmesine yardımcı olabilir.
- **Polimorfik Sınıflarda Kullanım**: Null pointer, işaretçilerin geçerli bir nesneye sahip olmadığını belirtmek için kullanılabilir.

### Önemli Notlar:
- **`nullptr`** kullanımı, **`0`** veya **`NULL`** kullanımından daha güvenlidir ve modern C++'ta tercih edilir.
- Null pointer'lara erişmeye çalışmak **undefined behavior**'a yol açar, bu nedenle işaretçiler kullanılmadan önce null olup olmadıkları kontrol edilmelidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:C++ da iki karakterlik ayıraç atomları tanımlanmıştır. Derleyici ve önişlemci program bu kakarakter 
çiftelerini gördüğü yerde bunlara eşdeğer karakterlerinin bulunduğunu varsayar: 

<: [
:> ]
<% {
%> }
%: # 

C'de bu karakter çifteleri geçerli değildir: 

%:include <stdio.h> 
void copy(char dest<::>, const char source<::>, size_t nbytes) 
<% 
%> 
while (nbytes--) 
*dest++ = *source++; 
Yukarıdaki program C++'da geçerli, C'de geçersizdir
--------------------------------------------------------------------------------------------------------------------------------------------------
 C++'da geri dönüş değeri üretmeyen bir işlevin return deyiminde return anahtar sözcüğünü void
türünden bir ifade izleyebilir. C'de böyle işlevlerde return anahtar sözcüğünü bir ifade izleyemez:
void foo();
void func()
{
}

return foo();
Yukarıdaki örnekte kullanılan return deyimi C++'da geçerli, C'de geçersizdir.

*****************************************************************************************************************************************


                                                                                 ********* 2-DERS NOTLARI *********
c dilinde void* türünden başka bişka bir pointer türe türe implicit conversion var ama c++ dilinde yok


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
    // Makro genişleyince `3.14 * 2.5 * 2.5` yerine `3.14 * 2.5 * 2.5` olur.
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
******************************************************************************************************************************


                                                                                         ********* 3-DERS NOTLARI *********                   
AAA(ALMOST ALWAYS AUTO) demek kullanabildiğin her yerde auto kullan

C++ dilinde, "expression" ve "statement" terimleri farklı anlamlara gelir ve programın yapı taşlarını oluştururlar. İşte bu terimlerin tanımları ve aralarındaki farklar:

### Expression (İfade)

Bir **expression** (ifade), bir değeri hesaplayan veya değerlendiren bir kod parçasıdır. İfadeler tek başına bir değer üretebilir
veya yan etkilere neden olabilir. İfadeler, çeşitli operatörler ve operandlar kullanılarak oluşturulabilir. 

İfadelerin bazı örnekleri:

1. **Sabitler**: `42`, `'a'`, `3.14`
2. **Değişkenler**: `x`, `y`, `z`
3. **Aritmetik İfadeler**: `x + y`, `a * b - c`
4. **Fonksiyon Çağrıları**: `foo()`, `bar(x, y)`
5. **Üyelik İfadeleri**: `obj.member`, `ptr->member`
6. **Yöntem Çağrıları**: `obj.method()`
7. **Dizine Erişim**: `array[index]`

İfadeler genellikle bir değeri değerlendirir ve bir sonuç döndürür. Örneğin, `x + y` ifadesi `x` ve `y` değerlerini toplar ve sonuç olarak toplamı döndürür.

### Expression Statement (İfade Cümlesi)

Bir **expression statement** (ifade cümlesi), bir veya daha fazla ifadeyi içerebilen, belirli bir eylemi gerçekleştiren ve genellikle bir noktalı virgül (`;`)
ile biten bir kod parçasıdır. İfade cümleleri, programın akışını kontrol eder ve belirli işlemleri gerçekleştirir.

expression statement bazı örnekleri:

1. **Basit İfade Cümlesi**: Bir ifadeyi içerir ve bir noktalı virgül ile biter.
    x = y + 1; // Basit ifade cümlesi

2. **Deklarasyon Cümlesi**: Bir değişken veya fonksiyon bildirir.

    int a = 5; // Değişken bildirimi

3. **Kontrol Akışı Cümleleri**: `if`, `for`, `while` gibi yapıları içerir.

    if (x > 0) {
        y = x;
    }
    for (int i = 0; i < 10; ++i) {
        sum += i;
    }

4. **Dönüş Cümlesi**: Bir fonksiyondan değer döndürür.

    return x + y;

5. **Blok Cümlesi**: Birden fazla ifade cümlesini bir blokta gruplar.

    {
        int x = 10;
        int y = 20;
        int z = x + y;
    }

### expression ve statement Cümleleri Arasındaki Fark

- **expression**, bir değeri hesaplar veya değerlendirir ve genellikle bir değer döndürür. İfade cümlesi içinde kullanılabilirler.
- **expression statement**, programın yürütme akışını kontrol eder ve genellikle belirli bir görevi yerine getirir. Bir ifadeyi içerir ve bir noktalı virgül ile biter.

Örneğin:

// İfade:
x + y

// İfade cümlesi:
x = y + 1; // expression statement

İfade, sadece `x + y` değerini hesaplar. Ancak ifade cümlesi, `x` değişkenine `y + 1` değerini atar ve bir eylemi tamamlar.

### Özet

- **Expression (İfade)**: Bir değeri hesaplayan veya değerlendiren bir kod parçasıdır. Bir sonuç döndürür.
- **Statement (İfade Cümlesi)**: Bir veya daha fazla ifadeyi içerebilir ve belirli bir eylemi gerçekleştiren bir kod parçasıdır. Noktalı virgül ile biter ve programın akışını kontrol eder.

Bu ayrım, C++ programlama dilinde kod yazarken oldukça önemlidir ve doğru kullanım, kodun doğru ve beklenen şekilde çalışmasını sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde, bir ifadenin (expression) türünü anlamak için ifadelerin değer kategorilerine (value categories) ayrılması gerekir. 
Bu değer kategorileri, ifadenin bellekte bir nesneyi temsil edip etmediğini ve eğer ediyorsa, bu nesnenin yaşam süresinin ne kadar olduğunu belirtir. 
C++'ta üç temel (primary) değer kategorisi vardır: lvalue, prvalue ve xvalue. Bu kategoriler, bir ifadenin nasıl değerlendirildiğini ve hangi bağlamlarda kullanılabileceğini belirler.

### Primary Value Categories (Birincil Değer Kategorileri)

1. **Lvalue (Left Value)**
    - Bellekte bir konumu temsil eder ve bu konumda bir nesneye işaret eder.
    - Lvalue ifadeleri, değiştirilebilir (mutable) nesneleri temsil eder.
    - Bir lvalue ifadesi, bir değişkenin adı olabilir veya bir referans olabilir.

    #### Örnekler:

    int x = 10;  // x bir lvalue'dir.

2. **Prvalue (Pure Rvalue)**
    - Geçici bir değeri temsil eder, doğrudan bellekte bir nesneyi temsil etmez.
    - Prvalue ifadeleri genellikle hesaplama sonuçlarıdır ve kısa ömürlüdür.
    - Prvalue ifadeleri, fonksiyon dönüş değerleri veya geçici (temporary) nesneler olabilir.

    #### Örnekler:

    int y = x + 5;  // x + 5 bir prvalue'dir.
    std::string("hello") // geçici bir std::string nesnesi, bir prvalue'dir.

3. **Xvalue (eXpiring Value)**
    - Bellekte bir nesneyi temsil eder, ancak bu nesne yakında yok olacak veya taşınacak (moved-from) bir nesnedir.
    - Xvalue ifadeleri genellikle kaynakları taşımak için kullanılır.

    #### Örnekler:

    std::string s1 = "hello";
    std::string s2 = std::move(s1); // std::move(s1) bir xvalue'dir.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde, ifadelerin (expressions) nasıl değerlendirileceğini ve hangi bağlamlarda kullanılabileceğini anlamak için değer 
kategorileri (value categories) kullanılır. Birincil (primary) değer kategorileri olan lvalue, prvalue ve xvalue dışında, 
bu değer kategorilerinin birleşiminden oluşan daha genel kategoriler de vardır. Bu birleşik (combined) değer kategorileri, daha geniş anlamda ifadelerin nasıl işleneceğini tanımlar.

### Combined Value Categories (Birleşik Değer Kategorileri)

1. **Glvalue (Generalized Lvalue)**
    - lvalue ve xvalue ifadelerinin birleşimidir.
    - Bellekte bir nesneyi temsil eder.
    - Nesnenin adresi alınabilir.

    #### Özellikler:
    - Bellekte bir konumu işaret eder.
    - Nesneye doğrudan erişilebilir ve bu nesne değiştirilebilir.

    #### Örnekler:

    int x = 42;
    int &ref = x;       // ref bir lvalue'dir.
    int &&rref = 42;    // rref bir xvalue'dir.
    
    // Glvalue örnekleri
    x = 5;              // x bir lvalue (dolayısıyla bir glvalue) ifadesidir.
    std::move(x) = 10;  // std::move(x) bir xvalue (dolayısıyla bir glvalue) ifadesidir.

2. **Rvalue (Right Value)**
    - prvalue ve xvalue ifadelerinin birleşimidir.
    - Bellekte kısa ömürlü veya geçici (temporary) bir nesneyi temsil eder.
    - Kaynakların taşınması ve geçici nesnelerin kullanımı için kullanılır.

    #### Özellikler:
    - Bellekte bir konumu işaret etmez, dolayısıyla adresi alınamaz.
    - Genellikle hesaplama sonuçları veya geçici nesnelerdir.

    #### Örnekler:

    int y = 42;
    int z = y + 5;      // y + 5 bir prvalue'dir (dolayısıyla bir rvalue).
    int &&rref = 42;    // 42 bir prvalue'dir (dolayısıyla bir rvalue).
    std::move(y);       // std::move(y) bir xvalue'dir (dolayısıyla bir rvalue).

### Kategori Özeti

- **Glvalue (Generalized Lvalue):** lvalue ve xvalue ifadelerinin birleşimidir. Bellekte bir nesneyi temsil eder.
- **Rvalue (Right Value):** prvalue ve xvalue ifadelerinin birleşimidir. Bellekte kısa ömürlü veya geçici bir nesneyi temsil eder.
--------------------------------------------------------------------------------------------------------------------------------------------------
privmary value category
    L value
    PR value -> Pure R value
    X value -> eXpiring value

combined value category
    L value ve X value demek -> GL value demek
    PR value ve X Value demek -> R value demek

++x // C de R value C++ Da L value
--x // C de R value C++ Da L value

ama x++ R value

comma operatör ( , ) virgül operatörü C de R value C++ da L value expression oluşturuyor

turnory operatörü C de R value C++da L value expression oluşturur 
--------------------------------------------------------------------------------------------------------------------------------------------------
referanslar derleyici açısından pointer ile aynıdır kısacası pointerların maskelenmiş halidir arka planda pointer işlemi görür
bazı yerlerde pointer semantiği uygun olmadığı için referanslar gelmiştir

NOT:Referanslar default initialize edilemez

    int& r; //syntax error

    referansların data type'ı aynı olmak zorundadır

    referanslar bir kez başlatıldıktan sonra başka bir nesneye referans olamazlar(re-bindeble değil)
        int x = 10;
        int y = 10;
        int&r = x;
        r = y; // burda y'yi x'e atamak anlamına geliyor y'yi referans almıyor

int x = 5;

int& r1 = x++ // son ek ++ operatörü c++ dilinde rvalue olduğu için syntax error 
int& r1 = ++x // ön ek ++ operatörü c++ dilinde lvalue olduğu için geçerli

int x = 5;
int& r = x;

std::cout << &r << '\n'; // x'in adresine ulaşılır

int x = 10; 
int y = 5;
int* const p = &x; // p pointerı yalnızca x in adresini tutacağı güvencesini veriyor yani p nin adresi değişemez hayatı boyunca sadece x'in adresini göstericek
bu pointer türünün 3 adı vardır
// const pointer to int
// top level const
// right const 

p = &y // syntax error
*p = y // geçerli

const int* p = &x // p adlı pointerin içeriği dereferance edilemez sadece okuma amaçlıdır(read-only pointer) ama adresi değişebilir
bu pointer türünün 3 adı vardır
// pointer to const int
// low level const
// left const

*p = 20; // syntax error
p = &y; // geçerli

const int* p const = &x; // p adlı pointerin gösterdiği yerde adresi de değişemez
//const pointer to const int

*p = 20; // syntax error
p = &y; // syntax error

*p oluşturduğu ifade L Value
*p++ ve *p-- R value

NOT:Pointerları referans almak için kullanılan syntax biçimi şöyledir

int x{} // zero initialization
int y{36} // direct list initialization
int* p = &x; // x in adresi p pointera atandı p nin içinde 0 değeri var
int*& r = p; //p adlı pointer r adlı referansa atandı r demek artık x demek çünkü p x adlı değişkenin adresini gösteriyor

r = &y; // p = &y r referansı p ye referans olduğu için p'ye y'nin adresi atanıyor
*p = 678; // y'nin değeri 678 oluyor

int foo(); // r value 

NOT:call by value ile pass by value aynı şey demek

NOT:
void func(T& r) // ifadesi bir mutator bir ifadenin değerini değiştiryor anlamına gelir
void func(T* r) // mutator
void func(const T& r) // accessor
void func(const T* r) // accessor
T& func() // böyle bir fonksioyn gördüğümüzde bu fonksiyon bize bir nesne döndürüyor demeliyiz bu fonksişyona çağrı yaparak bir nesneyi kullanma hakkına erişmiş oluyoruz
T* func() // nesnenin adresini döndüren fonksiyon  
const T& func(); // nesneye ulaşmak için kullanılır nesneninde const olması gerekir
const T* func(); // nesneye ulaşmak için kullanılır nesneninde const olması gerekir

MÜLAKAT SORUSU

C dilinde foo(x) adında bir çağrı görüyorsak bunun call by value olduğunu anlarız
ama C++ dilinde bilemeyiz çünkü referans semantiği kullanılmış olabilir

NOT:Otomatik ömürlü (automatic storage duration) bir nesnenin adresini döndürmek mantıklı değildir çünkü bu nesne, 
fonksiyonun bitiminde yok olur ve bellekteki adresi geçersiz hale gelir. Otomatik ömürlü nesneler, tanımlandıkları 
bloktan çıkıldığında otomatik olarak silinirler. Bu nedenle, bu tür nesnelerin adresini döndürmek, o adresin geçerliliği 
sona erdiğinde bellek hatalarına ve tanımsız davranışlara yol açar.

### Örnek Açıklama

#include <iostream>

int foo()
{
    int g = 45;
    return g;
}

int main()
{
    int x = foo();
    std::cout << x;
    return 0;
}

Bu kod parçası sorunsuz çalışır çünkü `foo` fonksiyonu `int` türünde bir değer döndürüyor ve bu değer `g`nin kopyasıdır. `g`, `foo` 
fonksiyonu sona erdiğinde yok olsa bile, döndürülen kopya `x` değişkenine atanır ve bu nedenle geçerli olur.

### Geçersiz Kod

Ancak, `g`nin adresini döndürmeye çalışırsanız, bu durumda sorunlarla karşılaşırsınız:

#include <iostream>

int* foo()
{
    int g = 45;
    return &g;  // Geçersiz: g'nin adresini döndürmek
}

int main()
{
    int* x = foo(); // dangling pointer
    std::cout << *x;  // Tanımsız davranış
    return 0;
}

Bu kodda `foo` fonksiyonu, `g`nin adresini döndürmeye çalışıyor. g otomatik ömürlü bir nesne olduğu için tanımsız davranış olur `foo` sona erdiğinde `g` yok olur ve `x` 
geçersiz bir adresi işaret eder. `*x` ifadesi tanımsız davranışa yol açar.

### Doğru Yaklaşım

Eğer fonksiyondan bir nesnenin adresini döndürmek istiyorsanız, o nesnenin statik veya dinamik ömürlü olması gereklidir:

1. **Statik Ömürlü Nesneler**:

    int* foo()
    {
        static int g = 45;
        return &g;  // Geçerli: g'nin adresi her zaman geçerli kalır
    }

2. **Dinamik Ömürlü Nesneler**:

    int* foo()
    {
        int* g = new int(45);
        return g;  // Geçerli: g'nin adresi, delete edilene kadar geçerli kalır
    }

    int main()
    {
        int* x = foo();
        std::cout << *x;
        delete x;  // Dinamik ömürlü nesne serbest bırakılır
        return 0;
    }

Bu yaklaşımlar, döndürülen adresin geçerli kalmasını sağlar. Ancak, dinamik ömürlü nesnelerle çalışırken 
bellek yönetimi önemlidir ve `delete` ile bellek serbest bırakılmalıdır.

volatile
volatile niteleyicisi, bir değişkenin program dışı kaynaklar (örneğin, donanım veya başka bir iş parçacığı) tarafından değiştirilebileceğini belirtir. 
Bu, derleyicinin bu değişken üzerinde optimizasyon yapmaması gerektiğini garanti eder.

volatile int flag = 0;
while (flag == 0) {
    // Bu döngü, 'flag' değişkeninin program dışı bir kaynak tarafından değiştirilebileceğini belirtir.
}

const volatile Birlikte Kullanımı
const volatile niteleyicileri birlikte kullanıldığında, değişkenin program tarafından değiştirilemeyeceğini, ancak program dışı kaynaklar tarafından 
değiştirilebileceğini belirtir. Bu, özellikle donanım kayıtları veya çok iş parçacıklı programlama durumlarında kullanışlıdır.

const volatile int statusRegister = 0xFF;
while (statusRegister == 0xFF) {
    // 'statusRegister' değişkeni program tarafından değiştirilemez, ancak donanım tarafından değiştirilebilir.
}

NOT:lvalue referans ve rvalue ataması 

int g = 45;

int &foo() //foo burda l value referans ve g nin adresini döndürüyor
{
    return g; // g nin adresi dönüyor
}

int* foo() // yukarıdaki referans tanımlamasının pointer karşılığı bu şekildedir
{
    return &g;
}

int main()
{
    int &x = foo(); x ile foo lvalue referans olduğu için x değişkeni g değişkenine referanstır
    ++*foo() // çağrısı aslında derleyici tarafından ++(*(foo())) ifadesi olarak ele alınır

    return 0;
}

int g = 45;

int foo() // foo burda rvalue
{
    return g;
}

int main()
{
    int &x = foo(); x lvalue referans olduğu için bir lvalue değerine rvalue atanamaz derleme hatası verir

    return 0;
}

int g = 45;

int foo() // r value
{
    return g;
}

int main()
{
    int x = foo(); // x in kendisi burda lvalue ama aldığı değer rvalue yani olan şey aslında x = 45;

    return 0;
}

int foo()
{
    int g = 45;
    return g;
}

int main()
{
    int x = foo();

    return 0;
}

NOT:Pointer array var ama pointer referance yok

int x=10,y=5;
int* p[2] = {&x,&y};

NOT:Array decay ve array pointer farklılığı

int a[5] = {1,2,3,4,5};

int* p = a; // array decay olarak geçer a dizisinin ilk elemanının adresini tutar(türü int)

int (*p)[10] = &a; // p, a dizisinin tamamının adresini tutar ve p, a dizisini işaret eden bir pointer olur(türü int[5])

int (&r)[10] = a; // r, a dizisinin tamamına referans olan bir referans değişkenidir.

NOT:Dizinin tamamının adresini döndürmek ve dizinin ilk elamanını döndürmek arasında ki fark  

### 1. Döngü

for (int i = 0; i < 10; i++)
{
    std::cout << &a + i << " ";
}

Bu döngüde `&a + i` ifadesi kullanılıyor. Bu ifade, `a` dizisinin başlangıç adresine `i` kadar dizinin tipine göre bir ofset ekler. 
Burada `&a` ifadesi, `a` dizisinin tamamını işaret eden bir pointer anlamına gelir ve türü `int (*)[10]`'dir.

Dolayısıyla `&a + i` ifadesi aslında şu anlama gelir:
- `&a` dizisinin başlangıç adresi (`int (*)[10]` türünde).
- `+ i` bu adresin üzerine `i` tane `int[10]` boyutu kadar ekleme yapar. Yani her adımda 10 * sizeof(int) = 40byte boyutu kadar aralıklarla ilerler.

Bu nedenle, bu döngüde her iterasyonda dizinin her seferinde 40 eleman uzunluğunda bir blok atlayarak ilerlemesini sağlıyoruz. 
Adresleri bastırıyoruz, bu adresler büyük ihtimalle bellek blokları arasında büyük aralıklara sahip olacaktır.

### 2. Döngü

for (int i = 0; i < 10; i++)
{
    std::cout << a + i << " ";
}
Bu döngüde `a + i` ifadesi kullanılıyor. `a` ifadesi, dizinin başlangıç adresini (`int*` türünde) temsil eder.

Dolayısıyla `a + i` ifadesi şu anlama gelir:
- `a` dizisinin başlangıç adresi (`int*` türünde).
- `+ i` bu adresin üzerine `i` tane `int` boyutu kadar ekleme yapar. Yani her adımda 1 * sizeof(int) boyutu atlar.

Bu nedenle, bu döngüde her iterasyonda dizinin bir sonraki `int` elemanına geçerek ilerleriz. Adresleri bastırıyoruz ve bu adresler 
her seferinde sadece 1 * sizeof(int) = 4byte boyutu kadar aralıklarla ilerler.

Özetle:

&a ifadesi, dizinin tamamını temsil eden bir adres dönerken,
a ifadesi veya a + 0 ifadesi, dizinin ilk elemanının adresini döner.

NOT:Referanslara Farklı Türden Bir Nesne ile İlkdeğer Verilmesi Durumu

Bir referansın aynı türden bir değişkenle ilkdeğer verilerek tanımlanması gerektiğini belirtmiştik.
Referansıns farklı türden bir değişkenle ilkdeğer verilerek tanımlanması geçersizdir. Aşağıdaki örneği
inceleyin:
void func
{
double d = 10.5;
int &r = d; //Geçersiz
//...
}
Ancak const bir referansa başka türden bir nesne ile ilk değer verilmesi geçerlidir:
void func()
{
double d = 10.5;
const int &r = d; // Geçerli
//...
}
Bu durumda önce const referansa bağlanan farklı türden nesnenin değeri, referansın türünden yaratılacak
geçici bir nesneye atanır. Referans da bu geçici nesneye bağlanır. Yani derleyici aşağıdaki gibi bir kod üretir:

int main()
{
double d = 10.5;
int temp = (int)d;
const int &r = temp;
return 0;
}

Bir diziyle ilgili genel işlem yapan işlev tanımlanabiliyordu. Böyle işlevlere dizinin başlangıç adresi ve boyutu
argüman olarak gönderiliyordu. Dizinin başlangıç adresini işleve göndermek için gösterici kullanıyordu. Peki,
böyle bir işlevin parametresi bir referans olabilir mi? Hayır! referanslarla bu iş göstericilerle olduğu gibi
yapılamaz. Ancak, örneğin 10 elemanlı int türden bir diziyi gösteren gösterici olduğu gibi 10 elemanlı int türden
bir dizinin yerine geçecek bir referans da tanımlanabilir. 

#include <iostream>
using namespace std;
void display(const int(&r)[10])
{
int k;
for (k = 0; k < 10; ++k)
cout << r[k] << " ";
cout << endl;
}

int main()
{
const int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
display(a);
return 0;
}
Referanslar daha çok, tek bir nesneyi adres yöntemiyle işleve geçirmek amacıyla kullanılabilir. Örneğin tek bir
int değer ya da tek bir yapı değişkeni referans yoluyla işleve geçirilebilir. Ancak int türden bir dizi ya da bir yapı
dizisi bu yöntemle işleve doğal bir biçimde geçirilemez.

Sözdizimsel açıdan referansların göstericilere göre kullanım alanları daha dardır. Gösterici dizileri olur ama
referans dizileri olamaz. Göstericileri gösteren göstericiler olabilir ama referansların yerine geçen referanslar
olamaz.
Ancak şüphesiz bir göstericinin yerine geçen bir referans olabilir.

#include <iostream>
int main()
{
}
int x = 10;
int *ptr = &x;
int *&r = ptr;
*r = 20;
std::cout << "x = " << x << std::endl;
return 0;
--------------------------------------------------------------------------------------------------------------------------------------------------
bir diziyi işaret eden bir pointer referansı (pointer-to-array reference)

void func(const int(*&r)[5])
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << (*r)[i] << "\n";
    }
}

int main()
{
    int a[5]{ 1,2,3,4,5 };
    int(*p)[5]{ &a };
    func(p);
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Pointer referansları, pointer'ların kendilerine referans vermemizi sağlayan bir C++ dil özelliğidir. Bu, bir pointer değişkenini bir fonksiyona aktarırken, 
fonksiyonun sadece pointer'ın işaret ettiği değeri değil, pointer'ın kendisini de değiştirebilmesine olanak tanır. Şimdi bunu daha detaylı bir şekilde inceleyelim.

### 1. **Pointer ve Pointer Referansı**

- **Pointer:**
  Bellekteki bir değişkenin adresini tutan bir değişkendir. Örneğin:

  int x = 10;
  int* ptr = &x; // ptr, x'in adresini tutar

  Burada `ptr`, `x` değişkeninin adresini saklar. Yani `*ptr` yazıldığında `x`'in değerine ulaşırız.

- **Pointer Referansı:**
  Bir pointer'ın kendisine referans vermek, yani pointer'ın işaret ettiği adresi (değer değil) değiştirebilmek için kullanılır. 
  Pointer referansı `int*&` gibi bir sözdizimiyle ifade edilir.
  Örnek:

  int x = 10;
  int y = 20;
  int* ptr = &x;

  int*& ref = ptr; // ref, ptr'nin referansı
  ref = &y;        // ref üzerinden ptr değiştirildi

  Artık `ptr` değişkeni `y`'nin adresini tutar.

### 2. **Pointer Referansı Neden Kullanılır?**

#### a. Pointer'ı Değiştirmek:
Eğer bir fonksiyonun pointer'ın işaret ettiği adresi değiştirmesini istiyorsanız, pointer referansı kullanırsınız.

Örnek:

void changePointer(int*& ptr) {
    static int z = 50; // Kalıcı bir değişken
    ptr = &z;          // Pointer'ın işaret ettiği adresi değiştir
}

int main() {
    int x = 10;
    int* myPtr = &x;

    std::cout << "Before: " << *myPtr << '\n'; // 10
    changePointer(myPtr);
    std::cout << "After: " << *myPtr << '\n';  // 50

    return 0;
}

**Çalışma Mantığı:**
- `changePointer` fonksiyonu, `myPtr`'nin adresini değiştirir.
- Fonksiyon, pointer'ı referans olarak aldığı için değişiklik çağıran tarafa yansır.

#### b. Dinamik Bellek Yönetimi:
Dinamik olarak oluşturulan nesneleri dışarı taşımak için kullanılır. Bu, `new` ve `delete` ile sık karşılaşılan bir durumdur.

Örnek:

void createObject(int*& ptr) {
    ptr = new int(42); // Dinamik olarak bir int oluştur ve pointer'a ata
}

int main() {
    int* myPtr = nullptr;

    createObject(myPtr); // Fonksiyon pointer'ı değiştirir
    std::cout << "Value: " << *myPtr << '\n'; // 42

    delete myPtr; // Dinamik belleği serbest bırak
    return 0;
}

**Çalışma Mantığı:**
- `createObject`, dinamik olarak bir `int` oluşturur ve `myPtr`'nin adresini değiştirir.
- Pointer referansı olmadan, bu değişiklik fonksiyonun dışına yansımazdı.

### 3. **Pointer Referansının Söz Dizimi**

Pointer referansları şu şekilde tanımlanır:

int*& ref = pointer; // ref, bir pointer'ın referansıdır.

Burada:
- `int*` bir pointer türüdür.
- `&` referans anlamına gelir.
- `ref` artık `pointer` değişkeninin referansıdır.

### 4. **Pointer Referansı ve Dereferans Farkı**

- Dereferans (`*`) bir pointer'ın işaret ettiği değere ulaşmayı sağlar:

  int x = 10;
  int* ptr = &x;

  std::cout << *ptr; // x'in değeri (10)

- Pointer referansı (`*&`) pointer'ın kendisini değiştirmeyi sağlar:

  int x = 10, y = 20;
  int* ptr = &x;

  int*& ref = ptr; // Pointer'ın referansı
  ref = &y;        // Pointer artık y'yi işaret eder

  std::cout << *ptr; // 20

### 5. **Neden `*&` Kullanıyoruz?**

Bir pointer'ı doğrudan değiştirmek için neden referansa ihtiyacımız var? Bunun sebebi, C++'da fonksiyonlara değer kopyalanarak (pass-by-value) veri gönderilmesidir:
- Eğer bir pointer fonksiyona **değer olarak** (`int*`) geçirilirse, bu pointer'ın bir kopyası üzerinde işlem yapılır ve orijinal pointer değişmez.
- Eğer bir pointer **referans olarak** (`int*&`) geçirilirse, orijinal pointer değiştirilir.

### 6. **Hata Durumları ve Dikkat Edilmesi Gerekenler**

#### a. `nullptr` Kullanımı:
Bir pointer referansının `nullptr` alması mümkündür, ancak dereferans etmeye çalışırsanız program çöker:

int* ptr = nullptr;
int*& ref = ptr;

std::cout << *ref; // HATA: nullptr dereferansı!

#### b. Bellek Sızıntısı:
Dinamik bellekte bir pointer referansını yanlış yönetmek bellek sızıntısına yol açabilir. Örneğin:

void badExample(int*& ptr) {
    ptr = new int(10); // Yeni bellek ayrıldı
    // Eski bellek serbest bırakılmadı, bu bir bellek sızıntısıdır!
}

#### c. Kullanılmayan Adresler:
Statik ya da otomatik ömürlü değişkenlere referans verirken dikkatli olun. Örneğin, lokal bir değişkenin adresi döndürülemez:

int* unsafePointer() {
    int x = 10;
    return &x; // HATA: Lokal değişkenin adresi döndürüldü
}

### 7. **Özet**

- **Pointer referansı (`int*&`)** bir pointer'ı değiştirmek için kullanılır.
- Bellek yönetimi ve performans iyileştirme gibi durumlarda faydalıdır.
- Yanlış kullanıldığında bellek sızıntılarına veya `nullptr` dereferansına yol açabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
Dangling Pointer Nedir:

Dangling pointer (asılı gösterici), bellekte geçersiz veya serbest bırakılmış bir adresi işaret eden bir göstericidir. 
Bu durum, bellek hatalarına ve tanımsız davranışlara yol açar. Bir gösterici, hedeflediği bellek alanı geçerli olmadığı 
halde kullanılmaya çalışıldığında dangling pointer durumu ortaya çıkar.

1. **Otomatik Ömürlü Nesne Adresini Döndürme:**

   Otomatik ömürlü (automatic storage duration) n
### Dangling Pointer Örnekleri

nesneler, fonksiyonun sona ermesiyle geçersiz hale gelirler. Bu nesnelerin adresini döndürmek dangling pointer oluşturur.

   int* foo() {
       int x = 10;
       return &x;  // Geçersiz: x'in adresini döndürmek
   }

   int main() {
       int* p = foo();
       // p burada dangling pointer'dır.
       std::cout << *p;  // Tanımsız davranış
       return 0;
   }

2. **Dinamik Bellek Serbest Bırakma:**

   Dinamik bellek alanı `delete` veya `free` ile serbest bırakıldığında, bu belleği işaret eden gösterici dangling pointer haline gelir.

   int main() {
       int* p = new int(5);
       delete p;  // Bellek serbest bırakılır
       // p burada dangling pointer'dır.
       std::cout << *p;  // Tanımsız davranış
       return 0;
   }

3. **Scope Dışına Çıkan Yerel Değişken:**

   Bir gösterici, scope dışına çıkan bir yerel değişkeni işaret ediyorsa dangling pointer olur.

   int* ptr;
   
   {
       int x = 20;
       ptr = &x;
   }

   // x burada scope dışına çıktı ve ptr dangling pointer'dır.
   std::cout << *ptr;  // Tanımsız davranış

### Dangling Pointer'ları Önlemek İçin İpuçları

1. **Göstericiyi Serbest Bırakma Sonrası Null Yapmak:**

   Dinamik bellek serbest bırakıldığında göstericiyi null yaparak, tekrar kullanılmasını önleyebilirsiniz.

   int* p = new int(5);
   delete p;
   p = nullptr;  // p artık geçerli bir adresi işaret etmiyor

2. **Akıllı Göstericiler Kullanmak:**

   C++'ta akıllı göstericiler (smart pointers) kullanarak bellek yönetimini otomatikleştirebilir ve dangling pointer sorunlarını azaltabilirsiniz.

   #include <memory>

   void foo() {
       std::unique_ptr<int> p = std::make_unique<int>(10);
       // p burada otomatik olarak bellekten serbest bırakılacak
   }

3. **Geçerli Adresler Döndürmek:**

   Otomatik ömürlü nesnelerin adreslerini döndürmek yerine statik veya dinamik ömürlü nesnelerin adreslerini döndürmek.

   int* foo() {
       static int x = 10;
       return &x;  // Geçerli: x her zaman geçerli kalır
   }
  
Dangling pointer'lar bellek hatalarına ve program çökmesine yol açabilir, bu yüzden dikkatle yönetilmelidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT: referanslarda ampersand operatöründen sonra const yazmak anlamlı değildir
çünkü referanslar zaten tek bir yeri gösterdiği için default olarak const'tur
gösterdiği yer değişmeyeceği için const niteliğini ampersand operatöründen sonra eklemenin anlamı yoktur sadece fazlalıktır

int x = 10;
int& const r = x; // default olarak zaten orda gizli bir const bulunur yazmaya gerek yoktur

int x = 10;
const int& r = x;

int y = r + 5; // böyle bir ifade kullanırsak burda r'nin değeri hala 10dur y'nin değeri 15 olur
std::cout << y;
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Bir fonksiyonun setter veya getter olduğunu nereden anlarız

void foo(T &r); // Const anahtar kelimesi olmadığı için değeri değiştirmeye yönelik yazılan bir fonksiyon olarak
anlaşılır bu tarz fonksiyonlar gördüğümüzde anlamamız gereken şey bu fonksiyon bir değeri set ettiğidir

void foo(const T &r) // Const anahtar kelimesi olduğu için sadece okuma amacıyla kullanılır 
--------------------------------------------------------------------------------------------------------------------------------------------------
Bir fonksiyon veya değişken const & ise hem lvalue değer hemde rvalue değer kabul eder

double x = 2.67;
const int& r = x; // farklı türden olsa bile

int temp = x;
const int& r = temp;

void foo(int &r) // sadece lvalue alır
{
    std::cout<<r;
}

int main()
{
    int x = 5;

    foo(x + 5); // pr value olduğu için hata
}

void foo(const int &r) //  lvalue ve rvalue alır
{
    std::cout<<r;
}

int main()
{

    int x = 5;

    foo(x + 5); // geçerli foo değeri const olduğu için

}

NOT:Geri dönüş değeri Referans olmayan fonksiyon değerleri rvalue sayılır

Struct Nec{};

Nec func(const Nec&);
Nec foo(); 

int main()
{
    func(foo()); // func fonksiyonu const olduğu için hem rvalue hemde lvalue değeri kabul eder
}

Nec func(Nec&); 
Nec foo();

int main()
{
    func(foo()); // func fonksionu lvalue referans aldığı için foo fonksiyonu yine atanamaz çünkü foo rvalue
}

void bar(Nec&);
Nec& foo();

int main()
{
    bar(foo()) // GEÇERLİ bar fonksiyonu lvalue referans değeri alıyor 
    foo fonkisiyonuda referans döndürdüğü için lvalue referans olmuş oluyor
}
--------------------------------------------------------------------------------------------------------------------------------------------------
func(&x) operatörünün oluşturduğu ifade PR value
func(nullptr) PR value
string literalleri L value
a[3] gibi bir ifade L value

pointer array
 	int x = 5;
	int y = 5;
	int* p[2]{ &x,&y };

pointer değişkenler default initalize edilebilir ama iyi bir uygulama değildir
int* p; // wild pointer denir
******************************************************************************************************************************

                                                                             ********* 4-DERS NOTLARI *********

default argument

    function declerationda isim vermeye gerek olmaz çünkü kullanmayacağız
    defaul argument bildirimi function delcerationda yer alması gerekir

    default argument compiler time'a yönelik

    int foo(int, int, int = 10); 

    int main()
    {
        foo(5,6); // foo(5,6,50)
    }

    int foo(int, int = 20, int); // sentaks hatası çünkü 2.parametre için default argument bildirilmişken sağ taraftaki değer için bildirilmemiş C++ dilinde bu zorunlu

referanslardaa default argument alabilir

    int x = 10;
    void foo(int& = x); // argüman gönderilmezse globlal x değişkeni kullanılır

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

    #include "samet.h"
    void foo(int,int, = 0); // re-decleration

    int main()
    {
    foo(2,4); // foo(2,4,0)
    }

    samet.h
    void foo(int,int,int =0);

    #include "samet.h"
    void foo(int,int = 10); //  üstteki satır olmasaydı bu re-decleration haat verirdi çünkü default argument alan ifadenin
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

### Kodun Detaylı Açıklaması

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

### Örnek Kullanım

Bu fonksiyonların nasıl kullanılacağını göstermek için bir örnek yazalım:

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

Bu örnek, varsayılan parametre değerlerini kullanarak ve parametre sırasını değiştirerek fonksiyon çağrılarını sarmalamanın bir yolunu göstermektedir.
Bu, kodun esnekliğini artırabilir ve fonksiyon çağrılarında daha fazla kontrol sağlar.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 Default argümanlarlar eksik bilgi girildiğini de kontrol edebilir

 Bu kod, `print_date` fonksiyonunu kullanarak tarihleri yazdırmak için tasarlanmıştır. Fonksiyon, gün (`d`), ay (`m`) ve yıl (`y`) parametrelerini alır.
 Eğer herhangi bir parametre belirtilmezse (`-1` olarak geçilirse), o parametre için varsayılan değer olarak mevcut tarih bilgilerini kullanır.

İşte kodun açıklaması:

1. **Kod Başlangıcı:**

   #define _CRT_SECURE_NO_WARNINGS // tanımlaması, bazı güvenlik uyarılarını devre dışı bırakmak için Visual Studio'da yaygın olarak kullanılır.

   #include <iostream>
   #include <ctime>
 f
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

NOT:
emre.h

void foo(int, int, int);

// #include "emre.h"

void foo (int, int = 10, int); NOT: bu satırdaki gibi bir bildirim yaparak fonksiyonu tanımladığımızda
default argüman geçmemizde herhangi bir sorun yoktur

ÖRNEK2

void foo(int, int, int = 0); fakat burda dikkat edilmesi gereken husus bu satırdaki bildirim olmasaydı

void foo(int, int = 10, int); bu satırdaki
bildirim hata verirdi çünkü 2.parametredeki default argüman alıyorsa sağındaki parametre de default argüman almak zorundadır
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

 3 auto ifadesinde auto için yapılan çıkarımlar farklı
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

            auto x = foo; function to pointer conversion uygulanıyor int(*)(int) x'in türü bu auto keywordü kullanılmasaydı
            int(*x)(int) = foo yazmamız gerekirdi

     2)auto &x = expr;
        auto& r = 10 // l value expreesiona r valur expreesion ile ilk değer veremeyiz
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

            int foo(int) -> int(int)

            auto& r = foo; r'nin çıkarımı -> int(&r)(int) olur;


         typedef int inta5[];
         int ar[5]{2,5,8,9,4};
         inta5 *p = &ar;

         tür eş ismi kullanmasaydık int(*)[5] = &ar şeklinde kullanmamız gerekirdi

         inta5& r = ar; // r ar dizisine referans tür eş ismi kullanmasaydık int(&r)[5] = ar; yazmamız gerekirdi

         Referans dekleratörü olduğunda array decay uyglanmıyorsa şimdide function to pointer conversion uygulanmicak
            int foo(int);  foo nun türü int(int) fonksiyon türü ile function pointer türünü birbirine karıştırmayalım

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
 
  r'nin çıkarımı ->  const int& r

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
auto r = p;

std::cout << &x<<'\n';
std::cout << r; // x'in adresi

auto r1 = &p; // burda p'nin adresini tutmuş olyor yani int** r1 = &p çıkarımı yapılıyor

auto&& r = 20; r'nin tür çıkarımı -> int r = 20;

int x = 10;

auto&& r = x; r'nin tür çıkarımı -> int& &&r = x; // burda reference collapsing kuralları uygulanıyor çünkü
referansa referans türü oluyor böylelikle r şöyle olmuş oluyor

int& &&r = x; reference collapsing kuralına göre burda r lvalue reference -> int& r = x;

NOT:using keywordü ile kullanımı şu şekilde

using reftype = int&;

int x = 10;
reftype &r = x; // int& &r = x;

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

Universal reference, bir argümanın değer kategorisini koruyarak (`lvalue` veya `rvalue`) iletilmesini sağlar. Bu, özellikle şablon metaprogramlama ve hareket semantiği için çok önemlidir.

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

### Özet

Universal reference, C++11 ile gelen güçlü bir özellik olup, hem `lvalue` hem de `rvalue` referanslarını kabul edebilen ve 
argümanların değer kategorisini koruyarak iletilmesini sağlayan bir referans türüdür. Bu özellik, özellikle şablon metaprogramlama ve 
hareket semantiği işlemleri için önemlidir. Universal reference'lar, `T&&` şeklinde tanımlanır ve `std::forward` ile birlikte kullanılarak performans optimizasyonu sağlar.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 decltype kullanım senaryoları

 `decltype` C++11'de tanıtılan bir anahtar kelimedir ve bir ifadenin türünü sorgulamak için kullanılır. 
 `decltype`'ın çeşitli kullanım senaryoları vardır. İşte bazıları:

### 1. Bir İfadenin Türünü Öğrenmek

Bir ifadenin türünü öğrenmek için `decltype` kullanılabilir. Bu, özellikle karmaşık ifade türlerini tespit etmek için yararlıdır.

int x = 5;
decltype(x) y = 10; // y is of type int

### 2. Şablon (Template) Tür Çıkarımı

`decltype`, şablonlarda tür çıkarımı yapmak için kullanılabilir.

template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    auto result = add(5, 2.5); // result will be of type double
}

### 3. Üyeleri ve Dönüş Türlerini Tespit Etmek

`decltype`, sınıf üyelerinin veya fonksiyon dönüş türlerinin tespit edilmesinde kullanılabilir.

struct MyStruct {
    int member;
    double func() { return 3.14; }
};

int main() {
    MyStruct obj;
    decltype(obj.member) a = 1;  // a is of type int
    decltype(obj.func()) b = 3.14; // b is of type double
}

### 4. Lambda Fonksiyonların Dönüş Türünü Öğrenmek

Lambda fonksiyonların dönüş türünü öğrenmek için `decltype` kullanılabilir.

auto lambda = [](int x, int y) { return x + y; };
decltype(lambda(1, 2)) result = lambda(1, 2); // result is of type int

### 5. Geçici (Rvalue) ve Sabit (Const) Türlerin Çıkarımı

`decltype`, ifadenin tam türünü, yani `const` veya `volatile` olup olmadığını ve geçici (`rvalue`) veya sabit (`lvalue`) olup olmadığını öğrenebilir.

const int ci = 0;
decltype(ci) x = 0;  // x is of type const int

int foo();
decltype(foo()) y;   // y is of type int (return type of foo)

### 6. pointer ile Kullanım

Sınıf üyesi işaretçileri ile birlikte `decltype` kullanılabilir.

struct MyStruct {
    int member;
};

int main() {
    decltype(&MyStruct::member) pMember = &MyStruct::member; // pMember is of type int MyStruct::*
    MyStruct obj;
    obj.*pMember = 10; // Accessing member using the pointer-to-member
}

### 7. İfade Türlerine Dayalı Değişken Tanımlama

Bir ifadenin türüne dayalı olarak değişken tanımlamak için `decltype` kullanılabilir.

int arr[10];
decltype(arr) anotherArr = {0}; // anotherArr is of type int[10]

### 8. Conditional Types (Koşullu Türler)

Şablon metaprogramlamada koşullu türler oluşturmak için `decltype` kullanılabilir.

template <typename T>
auto conditional(T a) -> decltype(a > 0 ? a : -a) {
    return a > 0 ? a : -a;
}

int main() {
    auto result = conditional(-5); // result will be of type int
}

### 9. Basit İfade Türlerini Bulma

Fonksiyon şablonlarında karmaşık ifadelerin türünü bulma ve bu türü kullanma.

template <typename T1, typename T2>
auto multiply(T1 a, T2 b) -> decltype(a * b) {
    return a * b;
}

int main() {
    auto result = multiply(3, 4.5); // result will be of type double


`decltype` anahtar kelimesi, C++'da tür çıkarımını daha esnek ve güçlü hale getiren önemli bir özelliktir. 
Bu senaryolar, `decltype`'ın çeşitli kullanım alanlarını göstermektedir.

1.KURAL SETİ:declytype'ın operandının isim olması durumunda tür çıkarımının yapılması farklı kural seti ile olur
int x;
decltype(x) y; -> y'nin türü int
decltype(a.y) z  -> a nesnesindeki y değerinin türü
decltype(p->y) < -> p nesnesinin y değerinin türü 

decltype(x) foo(decltype(x)* p); // int foo(int* p )türünde bir fonksiyon bildirmiş olucaz

const int y { 435};

decltype(x) y; // const variable must be initalize 

intr& r = x;

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
function pointer to conversion, function decay de denir(fonksiyon bozunması) bir fonksiyonun adresini bir fonksiyon işaretçisi (pointer) türüne dönüştürmeyi ifade eder. 
Fonksiyon işaretçileri, belirli bir işlevi referans alıp bu işlevi daha sonra çağırmak için kullanılan işaretçilerdir. 
Bu tür işaretçiler, dinamik işlev çağırma, callback mekanizmaları ve programın esnekliğini artırmak amacıyla kullanılır.

### Fonksiyon İşaretçisi
Bir fonksiyon işaretçisi, bir fonksiyonun bellekteki adresini tutar. Bu adres aracılığıyla o işlev çağrılabilir.

#### Basit Örnek:

#include <iostream>

// Basit bir fonksiyon
int add(int a, int b) {
    return a + b;
}

int main() {
    // 'add' fonksiyonuna işaret eden bir işaretçi tanımlama
    int (*functionPointer)(int, int) = &add;

    // İşaretçiyi kullanarak fonksiyonu çağırma
    int result = functionPointer(5, 3);

    std::cout << "Sonuç: " << result << std::endl;

    return 0;
}

Bu örnekte:
- `int (*functionPointer)(int, int)` ifadesi bir fonksiyon işaretçisi tanımlar. Bu işaretçi, `int` döndüren ve iki `int` parametre alan bir fonksiyona işaret eder.
- `&add` fonksiyonunun adresi `functionPointer` işaretçisine atanmıştır.
- İşaretçiyi kullanarak `add` fonksiyonunu çağırabiliyoruz: `functionPointer(5, 3)`.

### Fonksiyon Pointer'ı Dönüşümü (Function Pointer Conversion)
Fonksiyon pointer'ı dönüşümü, bir fonksiyonun doğrudan bir fonksiyon pointer türüne dönüştürülmesi anlamına gelir. C++'ta, işaretçiyi 
atarken işlevin adresini açıkça belirtmek genellikle gerekmez çünkü implicit conversion (örtülü dönüşüm) otomatik olarak gerçekleşir. Yani, bir 
fonksiyon ismini kullanmak aslında onun adresini işaret eder.

#### Örnek:

#include <iostream>

void greet() {
    std::cout << "Hello!" << std::endl;
}

int main() {
    // greet işlevine işaret eden işaretçi
    void (*greetPtr)() = &greet;  // Dönüşüm burada otomatik olarak gerçekleşir.
    
    // İşlevi işaretçi ile çağırma
    greetPtr();

    return 0;
}

Bu örnekte:
- `greet` fonksiyonu `void (*greetPtr)()` işaretçisiyle ilişkilendirilmiştir.
- `greet` ismi işlevin adresini temsil eder, bu yüzden `&greet` yazmak gerekmez (yazılabilir doğru olanı budur ama fark etmez).

### `reinterpret_cast` ile Dönüşüm
Bazen fonksiyon işaretçileri arasında açık dönüşüm yapmak gerekebilir. Örneğin, farklı imzaya sahip fonksiyon pointer'ları arasında dönüştürme yapmak için `reinterpret_cast` kullanılabilir.

#include <iostream>

void sayHello() {
    std::cout << "Hello!" << std::endl;
}

int main() {
    // Farklı türde bir işaretçi tanımlama
    void (*funcPtr)() = reinterpret_cast<void (*)()>(sayHello);

    // İşaretçiyi kullanarak fonksiyonu çağırma
    funcPtr();

    return 0;
}

### Özet:
- **Fonksiyon pointer to conversion**, bir fonksiyonun adresini bir işaretçiye atamayı ifade eder. Bu işlem genellikle C++'ta otomatik olarak yapılır.
- Fonksiyon işaretçileri, bir fonksiyona işaret ederek o fonksiyonu daha esnek bir şekilde çağırma olanağı sağlar.
- Daha karmaşık dönüşümler için `reinterpret_cast` gibi explicit (açık) dönüşüm operatörleri kullanılabilir.

### Function Decay ve Parametreler

Fonksiyon decay işlemi, özellikle fonksiyon parametrelerinde yaygındır. Bir fonksiyon parametre listesinde bir fonksiyon ismi geçildiğinde, 
o fonksiyonun adı otomatik olarak bir **function pointer** olarak değerlendirilir.

#### Örnek:

#include <iostream>

// Fonksiyonu parametre olarak alan bir fonksiyon
void callFunction(void (*func)()) {
    func();  // Fonksiyon pointer'ını çağırıyoruz
}

void hello() {
    std::cout << "Hello from function!" << std::endl;
}

int main() {
    // hello fonksiyonunu callFunction'a geçiriyoruz, burada decay gerçekleşiyor ve hello fonksiyonunu çağırıyoruz
    callFunction(hello); 

    return 0;
}

Bu örnekte:
- `callFunction` fonksiyonu, bir fonksiyon pointer'ı parametre olarak alıyor.
- `hello` fonksiyon adı `callFunction`'a geçtiğinde, **function decay** işlemi gerçekleşir ve `hello` otomatik olarak bir fonksiyon pointer'ına dönüştürülür.

### Function Decay ve `&` Operatörü

Aslında, `&` operatörünü kullanarak fonksiyon adresini açıkça yazmak mümkündür. Ancak, fonksiyon adı zaten bir fonksiyon pointer'ına decay olduğu için `&` yazmaya gerek yoktur. Örneğin:

void (*greetPtr)() = &greet;  // Bu da geçerlidir, ancak & kullanmaya gerek yoktur.

### Function Decay ile `decltype`

Bir fonksiyon adı ile işaretçiye decay olmasını `decltype` ile doğrulayabilirsiniz:

#include <iostream>

void greet() {
    std::cout << "Hello!" << std::endl;
}

int main() {
    // 'greet' decay olduğu için 'decltype(greet)' ve 'decltype(&greet)' aynı olur
    void (*funcPtr)() = greet;

    std::cout << std::boolalpha;
    std::cout << "Are they the same type? " << std::is_same<decltype(greet), decltype(&greet)>::value << std::endl;

    return 0;
}

Çıktı: `Are they the same type? true` olur, çünkü `greet` otomatik olarak `&greet`'e decay olur.

### Decay'in Olmadığı Durumlar

Her durumda decay olmaz. Örneğin, aşağıdaki durumlarda **function decay** gerçekleşmez:

1. **Fonksiyonun sizeof Operatörüne Geçilmesi:**

   sizeof(greet);  // Function decay burada gerçekleşmez, çünkü fonksiyonun boyutu bilinmez.

2. **& Operatörü ile Açık Fonksiyon Adresi Kullanımı:**
   `&greet` kullanıldığında decay zaten açıkça yapılmış olur, yani decay gerçekleşmez çünkü işaretleme işlemi açık bir şekilde belirtilmiştir.

### Özet:
- **Function decay**, bir fonksiyonun adresini işaretçiye otomatik olarak dönüştüren bir mekanizmadır.
- Decay, genellikle fonksiyon isimleri bir işaretçiye atandığında veya bir fonksiyon parametresi olarak geçirildiğinde gerçekleşir.
- Bu sayede fonksiyonlar dinamik olarak işaret edilebilir ve çağrılabilir, bu da programın esnekliğini artırır.

### **Function Pointer Nedir ve Ne İşe Yarar?**

C++'da **function pointer**, bir fonksiyonun adresini saklayan ve o fonksiyonu dolaylı olarak çağırmak için kullanılan 
bir değişkendir. Bu sayede, bir fonksiyon ismini doğrudan kullanmak yerine, o fonksiyonun işaretçisini alarak esnek yapılar 
ve dinamik çağrılar yapabilirsiniz. Özellikle **callback mekanizmaları**, **event handling** ve **daha esnek tasarımlar** için kullanılır.

### **Neden Kullanılır?**
1. **Callback Fonksiyonları**: Bir fonksiyonu parametre olarak geçirmek için.
2. **Esneklik ve Modülerlik**: Farklı fonksiyonların koşullara göre çağrılmasını sağlamak.
3. **Event Handling**: Olaylara göre belirli fonksiyonların çalıştırılması.

Function pointer kullanımı, daha modüler ve esnek kod tasarımları yapmanıza yardımcı olur.
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
******************************************************************************************************************************

                                                                             ********* 5-DERS NOTLARI *********
1)C++ Scopes:

C++ dilinde **scope** (kapsam) bir isim (değişken, fonksiyon, sınıf, vb.) tanımının geçerli olduğu bölgeyi belirler. 

namespace scope(içerisinde file scopu da barındırır)
block scope, 
class scope
function prototype scope int foo(int x) x-> fonksiyon prototip kapsamında
funcion scope, 

### 1. Blok Kapsamı (Block Scope)
Blok kapsamı, genellikle `{}` süslü parantezler içinde tanımlanan değişkenler için geçerlidir. Bu kapsam içinde tanımlanan değişkenler sadece bu blok içinde geçerlidir. Blok bittiğinde değişken yok edilir.

#include <iostream>

int main() {
    int x = 10; // x burada tanımlandı

    if (true) {
        int y = 20; // y burada tanımlandı
        std::cout << x << " " << y << std::endl; // x ve y burada erişilebilir
    }

    std::cout << x << std::endl; // x burada erişilebilir
    // std::cout << y << std::endl; // y burada erişilemez, hata verir

    return 0;
}

### 2. Fonksiyon Kapsamı (Function Scope)
Fonksiyon kapsamı, fonksiyon içinde tanımlanan etiketler (labels) ve değişkenler için geçerlidir. Bir fonksiyonun içinde tanımlanan etiketler, sadece o fonksiyon içinde geçerlidir.

void myFunction() {
    int x = 10; // x sadece bu fonksiyon içinde geçerlidir
}

### 3. Sınıf Kapsamı (Class Scope)
Sınıf kapsamı, bir sınıf içinde tanımlanan üyeler (değişkenler, fonksiyonlar) için geçerlidir. Bu üyeler, sınıfın içinde ve sınıfın dışından belirli erişim kuralları çerçevesinde erişilebilir.

class MyClass {
public:
    int x; // x sınıf üyesi, sınıfın her yerinde geçerli
    void myFunction() {
        x = 10; // x burada erişilebilir
    }
};

int main() {
    MyClass obj;
    obj.x = 20; // x burada erişilebilir
    return 0;
}

### 4. Dosya Kapsamı (File Scope)
Dosya kapsamı, global olarak tanımlanan değişkenler ve fonksiyonlar için geçerlidir. Bu tür değişkenler ve fonksiyonlar, tanımlandıkları dosyanın her yerinde geçerlidir.

int globalVar = 10; // globalVar tüm dosya boyunca geçerlidir

xxx.cpp
void myFunction() {
    globalVar = 20; // globalVar burada erişilebilir
}

### 5. Ad Alanı Kapsamı (Namespace Scope)
Ad alanı kapsamında tanımlanan isimler, ad alanının içinde geçerlidir ve ad çakışmalarını önlemek için kullanılır.

namespace MyNamespace {
    int x = 10; // x sadece MyNamespace içinde geçerlidir
}

int main() {
    std::cout << MyNamespace::x << std::endl; // x'e MyNamespace ile erişilir
    return 0;
}

### Özet
C++’da kapsam, bir isim tanımının geçerli olduğu bölgeyi belirler ve beş temel kapsam türü vardır: blok kapsamı, fonksiyon kapsamı, 
sınıf kapsamı, dosya kapsamı,namepsace kapsamı. Bu kapsamlar, programın derleme zamanında isim çözümlemeyi ve isim çakışmalarını yönetmeyi sağlar.

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
2)Name lookup:

C++ dilinde **name lookup** (isim arama), bir isim (değişken, fonksiyon, sınıf, vb.) kullanıldığında, derleyicinin bu ismin tanımını bulma sürecidir. 
İsim arama işlemi, bir ismin anlamlandırılabilmesi için belirli kurallar ve kapsamlar (scopes) dahilinde gerçekleştirilir.

### İsim Arama Süreci

1. **Blok Kapsamı (Block Scope)**: Bir isim ilk olarak, bulunduğu blok ({} süslü parantez içi) içinde aranır. En içteki bloktan başlayarak dışa doğru arama yapılır.

2. **Fonksiyon Kapsamı (Function Scope)**: Eğer isim, bir fonksiyonun içinde ise, fonksiyonun parametre listesi ve yerel değişkenleri arasında aranır.

3. **Sınıf Kapsamı (Class Scope)**: Eğer isim, bir sınıfın içinde ise, sınıf üyeleri arasında aranır. Sınıfın içindeki üyeler (değişkenler, fonksiyonlar) ve base class üyeleri kontrol edilir.

4. **Ad Alanı Kapsamı (Namespace Scope)**: İsim, bir ad alanı içinde tanımlanmışsa, bu ad alanı içinde aranır. Aynı zamanda, "using" deyimleri ile getirilen isimler de kontrol edilir.

5. **Global Kapsam (Global Scope)**: İsim, global kapsamda aranır. Bu kapsam, dosya seviyesinde tanımlanan isimleri içerir.

### Örnekler

#### Örnek 1: Blok Kapsamı

#include <iostream>

int main() {
    int x = 10; // x burada tanımlandı

    {
        int x = 20; // İç blokta yeni bir x tanımlandı
        std::cout << x << std::endl; // Bu x, iç bloktaki x'tir (20)
    }

    std::cout << x << std::endl; // Bu x, dış bloktaki x'tir (10)
    return 0;
}

#### Örnek 2: Sınıf Kapsamı

#include <iostream>

class MyClass {
public:
    int x; // Sınıf üyesi x
    void setX(int value) {
        x = value; // Sınıf üyesi x'e erişim
    }
};

int main() {
    MyClass obj;
    obj.setX(10);
    std::cout << obj.x << std::endl; // Sınıf üyesi x'e erişim
    return 0;
}

#### Örnek 3: Ad Alanı Kapsamı

#include <iostream>

namespace MyNamespace {
    int x = 10;
}

int main() {
    std::cout << MyNamespace::x << std::endl; // MyNamespace içindeki x'e erişim
    return 0;
}

#### Örnek 4: Global Kapsam

#include <iostream>

int x = 10; // Global değişken x

int main() {
    std::cout <<::x << std::endl; // Global değişken x'e erişim
    return 0;
}

### İsim Arama ve Fonksiyon Çağrıları

Fonksiyonlar için isim arama, overload resolution (aşırı yükleme çözümlemesi) ile birlikte çalışır. Bu süreç, 
fonksiyonun doğru versiyonunu bulmak için parametre türlerini ve sayısını kontrol eder.

#include <iostream>

void foo(int) {
    std::cout << "int" << std::endl;
}

void foo(double) {
    std::cout << "double" << std::endl;
}

int main() {
    foo(10);    // int versiyonu çağrılır
    foo(10.5);  // double versiyonu çağrılır
    return 0;
}

### Özet
C++’da isim arama, bir ismin doğru tanımını bulmak için kapsamlar (scopes) dahilinde yapılan bir işlemdir. Bu işlem, isimlerin kullanıldığı 
bağlama göre farklı kapsamlar içinde arama yaparak gerçekleştirilir. Bu sayede isim çakışmaları önlenir ve doğru isimler kullanılabilir hale gelir.

name lookup 
    context control
        access control

NOT:name lookup aranan ismin bulunmasıyla sona erer ve bir daha başlamaz
NOT:isim arama hatalarında biride ambigious(çift anlamlılık) hatası aynı isimden birden fazla 
isim varsa derleyici hangisini çağırması gerektiğine karar veremez
NOT:eğer isim arama başarısız olduysa ya derleyici aranan ismi bulamamıştır ya da ambigious olmuştur

### **1. Name Lookup (İsim Çözümleme)**
C++'da **name lookup**, bir değişken, fonksiyon veya diğer sembollerin tanımlarını bulmak için derleyicinin kullandığı mekanizmadır.

#### Çalışma Şekli:
- Derleyici, bir ismin (örneğin `x`) bağlanabileceği en yakın kapsamdan (scope) başlayarak ismi arar.
- **Kapsam Türleri:**
  - **block scope:** Bir fonksiyonun içindeki yerel değişkenler.
  - **class scope:** Bir sınıfın üyeleri (metotlar ve değişkenler).
  - **Global scope:** Tüm dosyada erişilebilen global değişkenler ve fonksiyonlar.
  - **Namespace scope:** Ad alanları içinde tanımlanan isimler.
- C++'ın **argument-dependent lookup (ADL)** özelliği, çağrılan fonksiyonun bağımsız değişken türüne göre uygun kapsamı otomatik olarak arar.

#### Örnek:

#include <iostream>

int x = 10; // Global kapsam

void func() {
    int x = 5; // Yerel kapsam
    std::cout << x << std::endl; // Yerel 'x' kullanılır
}

int main() {
    func(); // Çıktı: 5
    std::cout << x << std::endl; // Global 'x' kullanılır, çıktı: 10
    return 0;
}

### **2. Context Control (Bağlam Kontrolü)**
C++'da **context control**, bir isim veya ifade çözümlenirken derleyicinin kullandığı bağlama bağlı kuralları ifade eder. Bağlam, şu durumlarla ilgilidir:
- **Kapsam**: İsim hangi kapsamda tanımlandıysa ona göre çözülür.
- **Tür ve Erişim:** İsim, erişilebilir bir tür ya da uygun bir isim mi?
- **Yapısal Çatışmalar:** Örneğin, aynı isim hem sınıfta bir üye hem de bir yerel değişken olabilir.

#### Çalışma Şekli:
Bağlam kontrolü sırasında:
1. Derleyici önce ismin geçerli kapsamda tanımlanıp tanımlanmadığını kontrol eder.
2. Eğer birden fazla olası isim varsa, kapsam öncelik sırasına göre seçim yapılır.

#### Örnek:

class Test {
public:
    int x = 20;
    void print() {
        int x = 10; // Yerel x
        std::cout << this->x << std::endl; // Sınıf x'ine erişim
    }
};
```
Yukarıdaki örnekte `this->x` kullanımı, sınıf üyesi `x`'i bağlamına göre açıkça belirtir.

### **3. Access Control (Erişim Kontrolü)**
**Access control**, C++'da sınıflar ve yapılar için **public**, **protected**, ve **private** erişim belirteçleriyle uygulanır. 
Bu kurallar, bir üyenin (değişken veya fonksiyon) nereden erişilebilir olduğunu belirler.

#### Erişim Türleri:
1. **Public:** Her yerden erişilebilir.
2. **Protected:** Sadece sınıf ve türeyen sınıflar tarafından erişilebilir.
3. **Private:** Sadece sınıfın kendisi tarafından erişilebilir.

#### Çalışma Şekli:
- Varsayılan erişim seviyesi:
  - **Struct:** `public`.
  - **Class:** `private`.

#### Örnek:

class MyClass {
private:
    int privateVar = 1;

protected:
    int protectedVar = 2;

public:
    int publicVar = 3;

    void printVars() {
        std::cout << privateVar << " " << protectedVar << " " << publicVar << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.printVars(); // Geçerli
    // obj.privateVar; // Hata: private erişim
    // obj.protectedVar; // Hata: protected erişim
    std::cout << obj.publicVar << std::endl; // Geçerli
    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------
3)qualified name(nitelenmiş isim):

ismin qualified olması bu operatörlerin operandı olarak kullanılması demek 
a.b
p->x
::a
x::y

bu kullanımların her biri qualified namedir 
bunları kullanmıyorsa yani normal olarak kullanılıyorsa

a gibi unqualified namedir

NOT: SCOPE RESOLUTİONU UNARY OPERATOR ŞEKLİNDE KULLANMAK TEK BİR BİÇİMDE KULLANMAK
 YANİ GLOBALDE OLAN BİR DEĞERE ULAŞMAK

 ::x ->  unary operator

class::x -> binary operator

 int x = 5;
 int main()
 {
    std::cout<<::x;
 }

 BINARY OPERATOR ŞEKLİNDE KULLANMAK İSE CLASS NAMEPSACE GİBİ ALANLARDA KULLANILIR

 ClassA::ClassB

 void foo(int foo)
 {
    ::foo(foo); -> global fonksiyonu recursive olarak çağırmak istiyorsak unary scope resolution operatorü kullanmalıyız
 }
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **indeterminate value** (belirsiz değer), bir değişkenin bir başlangıç değeri (initialization) 
atanmadığında veya atanması gereken bir değerin belirsiz bir şekilde elde edildiğinde oluşur. Bu tür bir 
durum, genellikle tanımsız davranışa (undefined behavior) yol açabilir.

### **Indeterminate Value Tanımı**
- Bir değişken bildirildiğinde, ona başlangıç değeri atanmazsa, değişken **indeterminate value** içerir.
- Belirsiz değer, rastgele bir bellek alanındaki veriyi temsil edebilir ve bu nedenle kontrolsüz bir şekilde değişebilir.

### **Detaylar ve Örnekler**
1. **Yerel Değişkenler (Local Variables)**:
   - Otomatik depolama ömrüne sahip bir değişken (örneğin, bir fonksiyon içinde tanımlanmış) başlangıç değerine sahip değilse, değeri belirsiz olur.

   void example() {
       int x; // 'x' belirsiz bir değere sahip.
       std::cout << x; // Tanımsız davranış.
   }

2. **Dinamik Bellek**:
   - `new` ile ayrılan bellekte değişkenler başlatılmadıysa, belirsiz bir değer içerebilir.

   int* ptr = new int; // Başlatılmamış, belirsiz değer.
   std::cout << *ptr; // Tanımsız davranış.
   delete ptr;

3. **Statik ve Global Değişkenler**:
   - Statik veya global değişkenler otomatik olarak sıfır ile başlatılır ve bu nedenle **indeterminate value** içermez.

   static int y; // Varsayılan olarak sıfır değerine sahiptir.

4. **Birleşimler (Unions)**:
   - Eğer bir birleşim (union) üyesi erişim öncesinde doğru şekilde atanmazsa, belirsiz bir değer dönebilir.

### **İstisnalar**
1. **Trivial Types**:
   - Eğer bir değişken *trivial* türde değilse (örneğin, kullanıcı tanımlı bir sınıf), indeterminate value ile sonuçlanmaz. Bunun yerine varsayılan yapıcı çağrılır.

   C++'da **Trivial Types**, standart tarafından tanımlanmış ve oldukça "basit" bir şekilde kopyalanabilir, taşınabilir ve oluşturulabilir 
   türlerdir. Bir türün trivial olması, onun belirli gereklilikleri yerine getirmesi anlamına gelir. Trivial türler genellikle optimize edilmiş 
   kopyalama ve taşıma işlemlerine izin verir, bu da performansı artırır.

### **Trivial Türlerin Tanımı**
Bir türün trivial olması için aşağıdaki şartları sağlaması gerekir:

1. **Trivial Yapıcı (Constructor):**
   - Türün, kullanıcı tarafından tanımlanmış (non-default) bir kurucusu (constructor) olmamalıdır.
   - Varsayılan yapıcı (`default constructor`) bir işlem yapmamalıdır.

2. **Trivial Kopyalama/Atama:**
   - Türün kopyalama kurucusu (`copy constructor`) ve kopya atama operatörü (`copy assignment operator`) basit, kullanıcı tarafından değiştirilmemiş olmalıdır.
   - Varsayılan olarak `= default` ile belirtilebilir.

3. **Trivial Yıkıcı (Destructor):**
   - Türün yıkıcısı (`destructor`) kullanıcı tarafından tanımlanmamış olmalıdır ve basit bir yıkıcı olmalıdır.

4. **Temel Veri Üyeleri:**
   - Veri üyeleri trivial türlerden oluşmalı (örneğin, int, float gibi basit türler veya trivial olan yapılar).

5. **Sanallık Yok (No Virtual):**
   - Türün herhangi bir sanal (virtual) fonksiyonu veya sanal tabanı olmamalıdır.

### **Trivial Türlerin Avantajları**
- **Hızlı Bellek Kopyalama:** Trivial türler doğrudan bellekte `memcpy` ile kopyalanabilir.
- **Düşük Maliyetli Başlatma:** Bu türlerin oluşturulması veya yok edilmesi genellikle herhangi bir işlem gerektirmez.
- **Optimize Edilmiş Kod:** Derleyiciler, trivial türleri optimize etmek için özel stratejiler kullanabilir.

### **Trivial Türler Örnekleri**
#### Trivial Bir Tür:

struct Trivial {
    int x;
    float y;
};

- Trivial çünkü:
  - Kullanıcı tarafından tanımlanmış bir kurucu/yıkıcı yok.
  - Basit veri üyeleri var.
  - Sanallık (virtual) kullanılmamış.

#### Non-Trivial Tür:

struct NonTrivial {
    int x;
    NonTrivial() : x(0) {} // Kullanıcı tanımlı kurucu
};

- Bu tür trivial değildir çünkü kullanıcı tarafından tanımlanmış bir kurucuya sahiptir.

### **Trivial Türleri Tespit Etmek**
C++'da trivial türleri tespit etmek için `std::is_trivial` özelliği kullanılabilir (C++11 ve sonrası):

#include <type_traits>
#include <iostream>

struct Trivial { int x; };
struct NonTrivial { NonTrivial() {} };

int main() {
    std::cout << std::boolalpha;
    std::cout << "Trivial: " << std::is_trivial<Trivial>::value << "\n";        // true
    std::cout << "NonTrivial: " << std::is_trivial<NonTrivial>::value << "\n"; // false
}

2. **Sanitize Tools ile Test Etme**:
   - Modern derleyicilerde **Undefined Behavior Sanitizer** gibi araçlar, belirsiz değerlerin kullanımını tespit edebilir.

### **Çözümler**
- **Başlangıç Değeri Atayın**: Değişkenleri tanımlandığı anda bir başlangıç değeri ile başlatmak.

  int x = 0;

- **Dinamik Bellekte Default Initialization**:

  int* ptr = new int(0);

- **Modern C++ ile Güvenli Kullanım**: `std::optional` gibi yapı taşlarını kullanarak belirsizlikleri yönetebilirsiniz.
--------------------------------------------------------------------------------------------------------------------------------------------------
4)Translation Unit nedir(Çeviri Birimi):

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
ODR, C++'daki **One Definition Rule**'ün kısaltmasıdır ve derleyici/linker tarafından kontrol edilen bir kuraldır. 
Bu kural, bir programdaki semboller (fonksiyonlar, değişkenler vb.) için yalnızca bir **tanımın** (definition) mevcut olmasını 
zorunlu kılar. ODR'nin amacı, kodun davranışını netleştirmek ve tanımsız davranışı (undefined behavior) önlemektir.

### **ODR'nin Temel İlkeleri**
1. **Her Sembolün Yalnızca Bir Tanımı Olmalı:**
   - Herhangi bir fonksiyon veya değişken, program genelinde yalnızca bir kez tanımlanmalıdır. 
   Ancak birden fazla yerde **bildirimi (declaration)** olabilir.

   // Geçerli
   extern int x; // Bildirim
   int x = 10;   // Tanım

2. **Inline Fonksiyonlar,Constexpr Fonksiyonlar ve Templateler:**
   - **Inline** fonksiyonlar, şablonlar ve `constexpr` fonksiyonlar ve Template definitionlar birden fazla Translation Unit'de bulunabilir, 
   ancak tüm tanımlar birbirinin **aynısı** olmalıdır.

   inline void func() {
       // Aynı tanım tüm çeviri birimlerinde kullanılmalı.
   }

3. **Namespace ve Sınıf Üyeleri:**
   - Aynı isim alanında (namespace) veya sınıf içinde birden fazla tanım yapılması yasaktır.

4. **Header Dosyaları ve `#include`:**
   - Header dosyalarında yalnızca **bildirim** yer almalı, genellikle **tanım** değil. Tanımlama yapılacaksa `inline` veya `constexpr` gibi kurallar dikkate alınmalıdır.

   // Header Dosyası
   extern int y; // Bildirim

   // Kaynak Dosyası
   int y = 20; // Tanım

### **ODR Neden Kullanılır?**
ODR, C++ derleme ve bağlama sürecinin (compilation & linking) tutarlı ve hatasız bir şekilde çalışmasını sağlar:

1. **Tanımsız Davranışı Önler:**
   - Bir sembolün birden fazla tanımı olduğunda, hangi tanımın kullanılacağını derleyici belirleyemez, bu da tanımsız davranışa yol açabilir.

2. **Bağımsız Translation Unit:**
   - ODR sayesinde her çeviri birimi (translation unit) bağımsız olarak işlenebilir ve derleme sürecinde birleştirildiğinde hata riski azaltılır.

3. **Kodun Modülerliği:**
   - ODR, modüler kod yazımını teşvik eder. Tanım ve bildirimlerin ayrılması, kodun okunabilirliğini ve yeniden kullanılabilirliğini artırır.

### **ODR'nin İhlal Edilmesi (Violations of ODR)**
ODR'nin ihlali genellikle derleme veya bağlama hatalarıyla sonuçlanır. Bazı durumlarda tanımsız davranış (undefined behavior) da meydana gelebilir.

#### Örnek:

// Birinci kaynak dosyası
int x = 5;

// İkinci kaynak dosyası
int x = 10; // ODR ihlali: Aynı isim için iki tanım mevcut.

#### Link Hatası:
- Derleyici, hangi tanımı kullanacağını bilemez ve genellikle aşağıdaki gibi bir hata üretir:

  error: multiple definition of 'x'

### **ODR'nin Pratik Kullanımı**
1. **Header Guards veya `#pragma once`:**
   - Header dosyalarının birden fazla kez dahil edilmesini önlemek için kullanılır.

   #ifndef HEADER_H
   #define HEADER_H
   // Kod
   #endif

2. **`extern` Anahtar Kelimesi:**
   - Global değişkenlerin birden fazla çeviri biriminde kullanılmasını sağlar.

   extern int sharedVar; // Bildirim
   int sharedVar = 100;  // Tanım

3. **Şablonlar ve Inline Fonksiyonlar:**
   - Şablonlar ve `inline` fonksiyonlar, ODR ihlaline neden olmadan birden fazla dosyada tanımlanabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
emre.h
    int x = 0;

ahmet.cpp
    include "emre.h"

mehmet.cpp
    include "emre.h"

ODR çiğnenmiş oluyor x iki defa tanımlanmış oluyor

NOT:Her decleration bir definition değildir ama her definition bir decleration dır

int foo(); decleration

int foo() hem decleration hem definition
{

}
--------------------------------------------------------------------------------------------------------------------------------------------------
5)C++ programlama dilinde, belirli terimlerin ve kavramların kısaltmaları veya akronimleri yaygın olarak kullanılır. 

### Genel C++ Kavramları
1. **RAII (Resource Acquisition Is Initialization):**
   - Kaynak edinimi, başlatmadır. Bir nesne oluşturulduğunda bir kaynağın (bellek, dosya, soket, vb.) edinilmesi ve nesne yok edildiğinde bu kaynağın serbest bırakılması anlamına gelir.

2. **SFINAE (Substitution Failure Is Not An Error):**
   - Yerine koyma hatası hata değildir. Şablonların (templates) derleme sürecinde belirli koşullar altında başarısız olmasının bir derleme hatası değil, geçerli bir durum olduğunu belirtir.

3. **POD (Plain Old Data):**
   - Basit eski veri. C++'ta, yalnızca C'de bulunabilecek veri türleri (struct'lar, basit veri türleri) anlamına gelir.

4. **TAD (Type Erasure):**
   - Tür silme. Bir nesnenin türünün, çalıştırma zamanında değiştirilebilmesini veya gizlenmesini sağlayan bir tekniktir.

### Standart Kütüphane Bileşenleri
1. **STL (Standard Template Library):**
   - Standart Şablon Kütüphanesi. C++'ın standart kütüphanesinde bulunan ve şablonlara dayalı veri yapıları ve algoritmalar içerir.

2. **RNG (Random Number Generator):**
   - Rastgele sayı üreteci. Rastgele sayı üretmek için kullanılan fonksiyonlar ve sınıfları ifade eder.

3. **IO (Input/Output):**
   - Giriş/Çıkış. Veri okuma ve yazma işlemlerini ifade eder.

4. **CLI (Command Line Interface):**
   - Komut satırı arayüzü. Kullanıcının komut satırı üzerinden programlarla etkileşim kurmasını sağlar.

### Bellek Yönetimi
1. **RVO (Return Value Optimization):**
   - Dönüş değeri optimizasyonu. Bir fonksiyonun dönüş değerinin gereksiz kopyalamalarını önlemek için yapılan bir optimizasyondur.

2. **NRVO (Named Return Value Optimization):**
   - Adlandırılmış dönüş değeri optimizasyonu. RVO'nun adlandırılmış dönüş değerleri için genişletilmiş halidir.

3. **UB (Undefined Behavior):**
   - Tanımsız davranış. Programın standart dışı çalışmasına veya beklenmedik sonuçlar üretmesine neden olan durumlar.

4. **ODR (One Definition Rule):**
   - Tek Tanım Kuralı. Bir sınıf, şablon, fonksiyon veya değişkenin program boyunca yalnızca bir kez tanımlanması gerektiğini belirtir.

### Şablonlar ve Türler
1. **CRTP (Curiously Recurring Template Pattern):**
   - Merakla Yineleyen Şablon Deseni. Bir sınıfın kendi türev sınıfını şablon parametresi olarak aldığı bir şablon tekniğidir.

2. **CTAD (Class Template Argument Deduction):**
   - Sınıf Şablon Argüman Çıkarsama. C++17'de tanıtılan, sınıf şablonlarının argümanlarının otomatik olarak çıkarılmasını sağlayan bir özelliktir.

3. **ADL (Argument Dependent Lookup):**
   - Argümana Bağımlı Arama. Bir fonksiyonun argümanlarının türlerine bağlı olarak uygun isim aramasının yapılmasıdır.

4. **SFINE (Substitution Failure Is Not An Error):**
   - Yerine koyma hatası hata değildir. Bir şablonun belirli türlerle geçersiz hale gelmesi, derleme hatasına neden olmaz, bunun yerine alternatif bir şablon denemesi yapılır.

### Diğer Akronimler
1. **ABI (Application Binary Interface):**
   - Uygulama İkilik Arayüzü. Farklı yazılım bileşenlerinin birbiriyle nasıl etkileşime girdiğini tanımlar.

2. **API (Application Programming Interface):**
   - Uygulama Programlama Arayüzü. Yazılım uygulamaları arasındaki iletişim kuralları ve araçlar setidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
6)C++ programlama dilinde, "inline expansion" veya "inline genişletme", bir fonksiyonun çağrıldığı yerde doğrudan 
kodunun yerleştirilmesi sürecini ifade eder. Bu, fonksiyon çağrısının maliyetini ortadan kaldırarak performansı artırabilir. 
Inline genişletme, özellikle küçük ve sıkça çağrılan fonksiyonlar için kullanışlıdır.

### Inline Fonksiyonların Kullanımı

Bir fonksiyonu inline olarak belirlemek için `inline` anahtar kelimesi kullanılır. Örneğin:

inline int add(int a, int b) {
    return a + b;
}

Bu örnekte, `add` fonksiyonu inline olarak belirlenmiştir. Bu, derleyiciye bu fonksiyonun çağrıldığı yerde kodunu doğrudan yerleştirmesini önerir.

### Inline Expansion Süreci

Inline genişletme süreci şu adımları içerir:

1. **Fonksiyon Tanımlaması:** Fonksiyonun inline olarak tanımlanması.
2. **Çağrı Noktası:** Fonksiyonun çağrıldığı noktaların belirlenmesi.
3. **Kod Yerleştirme:** Fonksiyonun kodunun çağrı noktasına doğrudan yerleştirilmesi.

NOT:fonksiyon inline değilse ve definition yapılmadıysa decleration yapılmışsa inline expansion yapılmaz 

Örneğin, aşağıdaki kodda:

inline int multiply(int x, int y) {
    return x * y;
}
NOT:Burda önemli olan derleyicinin inline expansion yapma şansı olması için kodun definitionun olması sadece 
decleration olsaydı inline expansion yapamazdı yani kodu görmesi gerek

int main() {
    int result = multiply(3, 4);
    return 0;
}

Derleyici, `multiply` fonksiyon çağrısını genişleterek aşağıdaki koda dönüştürebilir:

int main() {
    int result = 3 * 4;
    return 0;
}

### Avantajlar ve Dezavantajlar

#### Avantajlar:
1. **Performans Artışı:** Fonksiyon çağrısının ek yükü ortadan kalkar, bu da özellikle sıkça çağrılan küçük fonksiyonlarda performans iyileştirmesi sağlar.
2. **Daha Küçük Kod:** Küçük fonksiyonların kodu doğrudan yerleştirildiğinde, bazı optimizasyonlar mümkün olabilir.

#### Dezavantajlar:
1. **Büyük Kod Boyutu:** Büyük inline fonksiyonlar kod boyutunu artırabilir ve bu da önbellek performansını olumsuz etkileyebilir.
2. **Bakım Zorluğu:** Kodun genişletilmesi, hata ayıklama ve bakım süreçlerini zorlaştırabilir.

### Inline Tavsiyeleri

1. **Küçük Fonksiyonlar:** Inline fonksiyonlar genellikle küçük ve sıkça çağrılan fonksiyonlar için uygundur.
2. **Performans Kritikleri:** Performansın kritik olduğu yerlerde dikkatlice kullanılmalıdır.
3. **Derleyici Önerisi:** Derleyicilerin inline expansion kararlarına müdahale etmekten kaçınılmalıdır. Derleyiciler genellikle en iyi kararları verebilir.

NOT:Birden fazla kaynak dosyasında inline fonksiyon özdeş olarak tanımlanırsa
ODR(One Definition Rules) ihlal edilmez 
fonksiyonların inline olması derleyicinin inline expansion yapmasını garanti etmez ister yapar 
ister yapmaz inline değilse bile optimizasyon yapma garantisi yoktur derleyiciye bağlıdır

NOT:Recursive çağrılar çoksa iç içe if deyimleri varsa inline expansion yapma şansı azalır 

NOT:static ile fonksiyon tanımını yaparsak internal linkage'a sahip olduğu için ODR çiğnenmez ama başlık dosyasını
include eden her kaynak dosyanın ayrı bir foo fonksiyonu olucaktı ve hepsinin adresi farklı olucaktı inlinelarda ise adresi aynı olurdu

NOT:her şekilde yine inline fonksiyon olur ister hem decleration hem definitionda yazarız yada sadece declerationda yada definitionda

inline int foo(int);

int foo(int) 
{

}

foo(int);

inline int foo(int)
{

}
--------------------------------------------------------------------------------------------------------------------------------------------------
7)C++17 ile birlikte, "inline değişkenler" kavramı tanıtılmıştır. Inline değişkenler, bir değişkenin birden fazla çeviri biriminde 
(translation unit) tanımlanmasına ve tanımların birbirine tutarlı olmasına olanak tanır. Bu, özellikle değişkenin global 
scope'da veya namespace scope'da tanımlandığı durumlarda faydalıdır.

### Inline Değişkenlerin Kullanımı

Bir değişkeni inline yapmak için `inline` anahtar kelimesi kullanılır. Örneğin:

inline int myVar = 42;

Bu, `myVar` değişkeninin birden fazla çeviri biriminde tanımlanabileceği ve her birinin aynı değere sahip olacağı anlamına gelir. 

### Inline Değişkenlerin Faydaları

1. **ODR (One Definition Rule) Uyumu:** Inline değişkenler, One Definition Rule (Bir Tanım Kuralı) ile uyumludur. Bu, bir inline değişkenin birden 
fazla çeviri biriminde tanımlanabileceği ve bu tanımların aynı olacağı anlamına gelir.
2. **Global ve Namespace Scope:** Inline değişkenler, global veya namespace scope'da tanımlanabilir ve her çeviri biriminde tutarlı bir şekilde kullanılabilir.
3. **Header Dosyalarında Kullanım:** Inline değişkenler header dosyalarında tanımlanabilir ve birden fazla kaynak dosyasına dahil edilebilir.

### Örnek Kullanım

Bir inline değişkeni tanımlamak ve kullanmak için aşağıdaki gibi bir yapı kullanılabilir:

// my_header.h
#ifndef MY_HEADER_H
#define MY_HEADER_H

inline int myVar = 42;

#endif // MY_HEADER_H

// file1.cpp
#include "my_header.h"
#include <iostream>

void printVar() {
    std::cout << "myVar in file1: " << myVar << std::endl;
}

// file2.cpp
#include "my_header.h"
#include <iostream>

void modifyVar() {
    myVar = 100;
    std::cout << "myVar in file2: " << myVar << std::endl;
}

// main.cpp
#include "my_header.h"

void printVar();
void modifyVar();

int main() {
    printVar();    // Output: myVar in file1: 42
    modifyVar();   // Output: myVar in file2: 100
    printVar();    // Output: myVar in file1: 100
    return 0;
}

Bu örnekte, `myVar` inline değişkeni hem `file1.cpp` hem de `file2.cpp` içinde tanımlanmış ve kullanılmıştır. 
Her iki dosya da aynı inline değişkeni paylaşır ve bu değişkeni değiştirebilir.

### Inline Değişkenlerin Kısıtlamaları ve Dikkat Edilmesi Gerekenler

1. **C++17 ve Üstü:** Inline değişkenler sadece C++17 ve sonraki standartlarda desteklenir.
2. **Thread Safety:** Inline değişkenler global veya namespace scope'da oldukları için çoklu thread kullanımı durumunda dikkatli olunmalıdır.
3. **Static Initialization Order:** Inline değişkenlerin statik başlatma sırası, farklı çeviri birimleri arasında karmaşıklık yaratabilir. Bu nedenle, 
başlatma sırasının belirgin olmadığı durumlarda dikkatli olunmalıdır.

Inline değişkenler, global ve namespace scope'da değişkenlerin tanımlanmasını ve kullanılmasını kolaylaştırır. Bu değişkenler, özellikle header dosyalarında 
tanımlandığında ve birden fazla kaynak dosyasına dahil edildiğinde faydalıdır. Ancak, dikkatli kullanılmalı ve potansiyel sorunların farkında olunmalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
8)UNSCOPED ENUMLARIN İSTENMEYEN 3 ÖZELLİĞİ

    1)implicit type conversion
    enum türünden aritmetik türlerine örtülü dönüşümü olması

    enum Color{
    White,Gray,Blue,Black
    };

    Color mycolor = Blue;

    int x = mycolor;

    2)underlying type olarak kullanılmaması ->derleyiceden derleyice farklı olması
        bu yüzden incomplete type olarak kullanamıyoruz

        enum Color;

        struct Nec
        {
            Color c; // hata
        }

        C++'da, **incomplete type** bir tür, tam tanımı olmadan bildirilen ancak henüz tanımlanmamış olan bir türdür. 
        Bu türlere, sınıf veya yapı tanımlarının tamamı sağlanmamışken yapılan bildirimler örnek olarak verilebilir. 
        İncomplete type'lar bazı sınırlamalara tabidir ve yalnızca belirli durumlarda kullanılabilirler. Örneğin, 
        incomplete type'lar nesne oluşturmak için kullanılamazlar, çünkü derleyici bu türlerin bellek boyutunu bilmez.

        ### Örnek 1: **Incomplete Type** ve **Underlying Type** ile Kullanılamama
        
        Aşağıdaki örnekte, `Foo` sınıfı incomplete bir type olarak bildiriliyor ve bu nedenle nesne oluşturulması başarısız oluyor.
        
        #include <iostream>
        
        // Incomplete type bildirimi
        class Foo; // Foo sınıfının incomplete bir tür olduğu için boyutu bilinmiyor

        int main() {
            // Bu yüzden aşağıdaki satır derleme hatasına neden olur:
            // Foo fooObject;  // HATA: İncomplete type ile nesne oluşturulamaz.
        
            // Ancak incomplete type'ı bir pointer ile kullanabilirsiniz:
            Foo* fooPtr;  // Bu çalışır, çünkü pointer bellek boyutu bellidir (sabit boyutludur).
        
            std::cout << "Incomplete type örneği" << std::endl;
            return 0;
        }
        
        Bu örnekte, `Foo` sınıfı bildiriliyor ama tanımlanmıyor. Dolayısıyla, `Foo fooObject;` satırı derleyici tarafından bilinmeyen bir bellek 
        boyutu gerektirdiği için derleme hatasına neden olur. Ancak, `Foo* fooPtr;` geçerli bir işlemdir, çünkü pointer türlerinin boyutu derleyici tarafından bilinir.
        
        ### Örnek 2: **Underlying Type** ve **Incomplete Type**
        
        #include <iostream>
        
        // Forward declaration (incomplete type)
        class MyClass;
        
        // Bir enum'un underlying type'ını kullanma (tamamlanmış tür gerektirir)
        enum class Colors : int {
            Red,
            Green,
            Blue
        };
        
        int main() {
            // Incomplete type kullanılamaz
            // MyClass myObject;  // HATA: İncomplete type ile nesne oluşturulamaz.
        
            // Ancak enum'ın underlying type'ı kullanılabilir
            int colorValue = static_cast<int>(Colors::Red);
            std::cout << "Underlying type example: " << colorValue << std::endl;
        
            return 0;
        }
        
        Bu örnekte, `enum class Colors`'ın `underlying type`'ı `int` olarak belirlenmiştir. Enum'lar incomplete type değildir 
        ve underlying type kullanılarak enum değerleri ile rahatça işlem yapılabilir. Ancak `MyClass` incomplete bir type olduğundan
        onunla nesne oluşturmak yine mümkün değildir.

     3)scopeları olmaması(unscoped enum) -> enum classlar yani (scoped enumlar bu sorunu çözüyor)

        enum Color{White,Gray,Blue,Black};

        enum ScreenColor{Magenta,Red,Blue};

            Color mycolor = Blue;  //Sentaks error çünkü Color da Blue ya sahip ScreenColor da 

Verbos:kodun karmaşıklığının artması
    bunu önlemek için c++20de using keywordu kullanılıyor

    enum class Suit {Club,Diamond,Heart,Spade};

    void func(Suit x)
    {
        using enum Suit;

        x = Club;

        auto y = Diamond;
    }

    veya using Suit::Diamond,Suit::Hearth gibi hangisini kullanmak istiyorsak onuda niteleyebiliriz

    Namespace içinde olsaydı

    namespace Neco
    {
        enum class Suit {Club,Diamond,Heart,Spade};

     }

     using enum Neco::Suit;
******************************************************************************************************************************
 
                                                                             ********* 6-DERS NOTLARI *********
 NOT:Parantez içinde hangi değer varsa o değerin value kategorisi odur

 int x = 50;

 (x) // l value

 NOT:Öncelik parantezimi yoksa fonksiyonun sentaksı mı

 int x = 6;

 auto sz = sizeof x; // sizeof(x) olarak yazılsaydı öncelik parantezi olurdu

sizeof int // şeklinde yazılamaz sizeof(int) şeklinde olmalıdır bu fonksiyonun sentaksıdır
 
NOT:Functional type casting

double dval = 6.76
int(dval);
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **contractual constness** ve **physical constness**, `const` anahtar kelimesinin kullanımıyla ilgili farklı yaklaşımlardır:

### **Physical Constness**
- Bir nesnenin bellekteki gerçek (fiziksel) verilerinin değişmezliğini ifade eder. Eğer bir üye fonksiyon `const` olarak işaretlenmişse, 
bu fonksiyonun `mutable` olmayan herhangi bir üye değişkeni değiştirmemesi gerekir.
- Derleyici, bu kurala sıkı bir şekilde uyar ve ihlalleri derleme zamanında yakalar.

**Örnek:**

class Example {
public:
    int getValue() const { return value; } // Bellekteki verileri değiştirmiyor
private:
    int value = 42;
};

Bu örnekte, `getValue` fonksiyonu fiziksel olarak sabittir çünkü hiçbir veri üyesini değiştirmez.

### **Contractual Constness**
- Bir fonksiyonun nesnenin soyut veya mantıksal durumunu değiştirmemesi gerektiğine dair bir sözleşmeyi ifade eder. 
Ancak bu, bazı özel durumlarda nesnenin fiziksel durumunun değiştirilebileceği anlamına gelir.Örneğin, **`mutable`** anahtar kelimesiyle 
işaretlenmiş üyeler, `const` fonksiyonlarda bile değiştirilebilir. Bu durum, genellikle bir nesnenin dahili bir önbelleğini güncellemek 
veya eş zamanlı erişim kontrolü yapmak için kullanılır.

**Örnek:**

class CacheExample {
public:
    int getValue() const {
        if (!isCached) {
            cache = computeExpensiveValue();
            isCached = true;
        }
        return cache;
    }
private:
    int computeExpensiveValue() const { return 42; }
    mutable int cache = 0;
    mutable bool isCached = false;
};

Bu örnekte, `getValue` fonksiyonu sözleşmeye göre mantıksal sabittir, çünkü kullanıcıya göre nesne değişmez. 
Ancak fiziksel olarak `cache` ve `isCached` değiştirilebilir, çünkü bunlar `mutable` olarak tanımlanmıştır.

### **Özet**
- **Physical Constness:** Bellekteki verilerin gerçekten değişip değişmediğine odaklanır. Derleyici tarafından katı bir şekilde kontrol edilir.
- **Contractual Constness:** Nesnenin mantıksal durumunu değiştirmemeye odaklanır. Ancak fiziksel değişikliklere izin verebilir (örn. `mutable` kullanılarak).
--------------------------------------------------------------------------------------------------------------------------------------------------
 1)constexpr tür niteleyicisi fonksiyonlarda da kullanılabilmektedir. 
Bu tür fonksiyonlara constexpr fonksiyonlar denilmektedir. constexpr 
fonksiyonların 
dile sokulmasından amaç bir fonksiyon çağrısının sabit ifadesi 
biçiminde derleme zamanında ele alınabilmesini sağlamaktır. const 
niteleyicisinin böyle bir 
yeteneği yoktur. Örneğin:
constexpr int foo()
{
return 10;
}
Bu fonksiyon çağrıldığında derleyici CALL makine komutu ile 
fonksiyonu çağırmaz. Doğrudan sanki çağrıdan 10 değeri elde edilmiş gibi 
10 değerini kullanır. 
Örneğin:
constexpr int x = foo();
Bu işlem için derleyici aşağıdakine eşdeğer bir kod üretecektir:
constexpr int x = 10;
constexpr fonksiyonların bazı ayrıntıları vardır. İzleyen 
bölümlerde bu ayrıntılar üzerinde duracağız. Örneğin:
constexpr int x = foo(); // geçerli
Yukarıdaki foo fonksiyonu sabit ifadesi oluşturduğu için constexpr 
bir değişkene ilkdeğer vermede kullanılabilmiştir.

int foo()
{
return 10;
}
constexpr int bar()
{
return 10;
}
int main()
{
int a[foo()]; // geçersiz! fonksiyon çağrıları sabir
ifadesi oluşturmaz
int b[bar()]; // geçerli, bar çağrısı sabit ifadesi
oluşturur
return 0;
}

constexpr fonksiyonlar aynı zamanda inline fonksiyon olarak kabul
edilmektedir. inline fonksiyonlar izleyen paragraflarda ele alınmaktadır.
Bu durumda her
constexpr fonksiyon aynı zamanda bir inline fonksiyondur. Ancak
inline fonksiyonlar constexpr fonksiyon değildir.

Ancak sabit ifadesi belirtmeyen constexpr fonksiyonlar
tamamen normal inline fonksiyon gibi işleme sokulmaktadır.

constexpr int square(int a)
{
return a * a;
}

Örneğin:
int a = 10;
int b = square(a); // geçerli
Burada constexpr fonksiyon sabit ifadesi belirtmemektedir. Normal
bir fonksiyon olarak ele alınacaktır.

NOT:constexpr fonksiyonlar ve değişkenler  implicit olarak inline
--------------------------------------------------------------------------------------------------------------------------------------------------
2)constexpr fonksiyonlar "koşula bağlı olarak sabit ifadesi 
oluşturur" hale getirildi. İşte C++20 ile birlikte her zmaan sabit 
ifadesi oluşturması gereken (yani
C++11'deki constexpr fonksiyonlar gibi) yeni bir fonksiyon biçimi 
oluşturuldu. Bunlara consteval fonksiyonlar ya da "immediate 
fonksiyonlar" denilmektedir. 
consteval bir fonksiyonun her çağrısının sabit ifadesi oluşturması 
zorunludur. Örneğin:
constexpr int square1(int a)
{
return a * a;
}
consteval int square2(int a)
{
return a * a;
}

int x = 10;
 int y = square1(x); // geçerli 
 int z = square2(x); // geçersiz!
Burada hem square1 hem de square2 çağrıları sabit ifadesi 
oluşturmamaktadır. Ancak constexpr fonksiyonların zaten çağrıldıklarında 
sabit ifadesi oluşturma 
zorunluluğu yoktur. Fakat consteval fonksiyonların çağrıldıklarında 
sabit ifadesi oluşturma zorunluluğu vardır. Biz consteval fonksiyonları 
hangi ifadede 
ve hangi nesneye ilkdeğer vermek için çağırırsak çağıralım çağrının 
sabit ifadesi oluşturması zorunludur.

consteval fonksiyonların constexpr fonksiyonların içerisinde
çağrılması bu bakımdan bir farklılık yaratmamaktadır. Örneğin:
consteval int square1(int a)
{
return a * a;
}
constexpr int square2(int a)
{
return square1(a);
}
Burada square2 fonksiyonu square1 fonksiyonunu çağırmıştır. Ancal
square1 çağrısında sabit ifadesi kullanılmamış durumdadır. Bu işlemin
tersini yapalım:
constexpr int square1(int a)
{
return a * a;
}
consteval int square2(int a)
{
return square1(a);
}
Burada consteval fonksiyon olan square2, constexpr fonksiyon olan
square1 fonksiyonunu çağırmıştır. Bu tanımlama derleme aşamsında bir
sorun oluşturmayacaktır.
Tabii square2 çağrılırken yine sabit ifadesi oluşturması
gerekmektedir. Örneğin:
int x = square2(10); // geçerli
int z = 10;
int k = square2(z); // geçersiz!
Buradan da görüldüğü gibi önemli olan consteval fonksiyonun
çağrısının derleme aşamasında sabit ifadesi oluşturma zorunluluğudur.

ÖNEMLİ!!:consteval fonksiyonların adresleri alınamamaktadır.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 3)C++'ta `constexpr` sınıflar, derleme zamanında sabit değerlere sahip nesneler oluşturabilen sınıflardır. Bu sınıflar, sınıf türünden değişkenlerin
sabit ifadelere dahil edilmesine olanak tanır. `constexpr` sınıf tanımlamak, sınıfın tüm üyelerinin ve fonksiyonlarının da `constexpr` olması gerektiği anlamına gelir, 
yani bu sınıfın örnekleri ve üyeleri sabit ifadelere dahil edilebilir.

### `constexpr` Sınıfının Özellikleri:

1. **Tüm Üyeler `constexpr` Olmalıdır**: Sınıfın tüm veri üyeleri ve üye fonksiyonları `constexpr` olmalıdır.
2. **Kapsayıcı Kurallar**: `constexpr` kurallarına uymalıdır. Bu, sınıfın kurucu fonksiyonlarının, yıkıcılarının ve diğer üyelerinin de `constexpr` olmasını gerektirir.
3. **Sınırlamalar**: `constexpr` sınıflarda sanal fonksiyonlar, dinamik bellek tahsisi (`new` ve `delete`), bazı tür dönüşümleri ve diğer dinamik işlemler yapılamaz.

### `constexpr` Sınıfı Tanımlama

Bir `constexpr` sınıfının tanımlanması ve kullanılması aşağıdaki gibidir:

#include <iostream>

class Point {
public:
    constexpr Point(double x = 0, double y = 0) : m_x(x), m_y(y) {}

    constexpr double getX() const { return m_x; }
    constexpr double getY() const { return m_y; }
    constexpr void setX(double x) { m_x = x; }
    constexpr void setY(double y) { m_y = y; }

private:
    double m_x;
    double m_y;
};

constexpr Point midPoint(const Point& p1, const Point& p2) {
    return Point((p1.getX() + p2.getX()) / 2, (p1.getY() + p2.getY()) / 2);
}

int main() {
    constexpr Point p1(1.0, 2.0);
    constexpr Point p2(3.0, 4.0);
    constexpr Point mid = midPoint(p1, p2);

    std::cout << "Midpoint: (" << mid.getX() << ", " << mid.getY() << ")\n";

    return 0;
}

### Açıklama

1. **Sınıf Tanımı**: `Point` sınıfı `constexpr` üyeleri ve fonksiyonları içerir. Bu, sınıfın derleme zamanında değerlendirilebileceği anlamına gelir.
2. **Kurucu ve Üye Fonksiyonlar**: Kurucu fonksiyon ve diğer üye fonksiyonlar `constexpr` olarak tanımlanmıştır. Bu, `Point` nesnelerinin derleme zamanında oluşturulmasına ve kullanılmasına olanak tanır.
3. **Fonksiyon**: `midPoint` fonksiyonu `constexpr` olarak tanımlanmış ve derleme zamanında değerlendirilebilir.
4. **Kullanım**: `p1`, `p2` ve `mid` nesneleri `constexpr` olarak tanımlanmış ve bu nesneler derleme zamanında değerlendirilebilir.

### Avantajlar

- **Derleme Zamanı Optimizasyonu**: `constexpr` sınıflar, derleme zamanında hesaplanarak çalışma zamanında daha az işlem yapılmasına olanak tanır.
- **Güvenlik**: Sabit ifadelerin kullanımı, hataların erken tespit edilmesine ve daha güvenli kod yazılmasına yardımcı olur.
- **Performans**: Derleme zamanında hesaplanan ifadeler, çalışma zamanında performansı artırabilir.

### Sınırlamalar

- **Dinamik Bellek Tahsisi Yok**: `constexpr` sınıflarda dinamik bellek tahsisi yapılamaz.
- **Sanal Fonksiyonlar Yok**: `constexpr` sınıflarda sanal fonksiyonlar kullanılamaz.
- **Daha Sınırlı Kullanım**: Tüm üyelerin ve fonksiyonların `constexpr` olması gerektiği için bazı karmaşık işlemler yapılamaz.

Sonuç olarak, `constexpr` sınıflar, derleme zamanında sabit değerlere sahip nesneler oluşturmak ve sabit ifadelerle çalışmak için güçlü bir araçtır. Bu, performansı artırabilir 
ve daha güvenli kod yazılmasına yardımcı olabilir.

new operatörü sabit ifadesi yaratmakta mıdır? Mevcut C++
standartlarına göre new operatörünün sabit ifadesi yaratabilmesi için new
operatörü ile tahsisatın
yapıldığı ifade sonlandığında o tahsisatın delete operatörü ile
siliniyor olması gerekir. Örneğin:
class Sample {
public:
constexpr Sample(int a) : m_pa(new int(a))
{}
constexpr ~Sample()
{
delete m_pa;
}
constexpr int a() { return *m_pa;}
private:
int *m_pa;
};

Burada biz Sample sınıfı türünden constexpr bir nesneyi aşağıdaki
gibi yaratamayız:

constexpr Sample s{10}; // geçersiz!

Buradaki sorun derleme aşamasında ele alınan new operatörü için
delete işleminin çalışma zamanında yapılmasıdır. Yani bu haliyle s
nesnesi aslında sabit
ifadesi biçiminde değerlendirilememektedir. Ancak bunun şöyle bir
istisnası vardır: Eğer nesne geçici nesne olarak yaratılırsa bu durumda
ilgili ifadenin
sonunda zaten yıkıcı fonksiyon çalışacağı için bu nesne de yalnızca
o ifadede kullanılabileceği için new işlemi sabit ifadesi oluşturmada bir soruna yol açmamaktadır. Örneğin:

constexpr int x = Sample{10}.a(); // geçerli

Yukarıdaki Sample{10}.a() ifadesi artık sabit ifadesi
oluşturmaktadır. Bu ifadede her ne kadar yine new operatörü kullanılmışsa da delete ile boşaltım
ifadenin sonunda yapılacağı için söz konusu bu ifade bir yan etkiye
yol açmadan derleme aşamasında yapılabilecektir.
Tabii bu anlatımın anlaşılabilebilmesi için "geçici sınıf
nesnelerinin yaratılması" konusunun biliniyor olması gerekmektedir.
İzleyen paragraflarda geçici
sınıf nesnelerin yaratılması konusu el alınmaktadır.
--------------------------------------------------------------------------------------------------------------------------------------------------
### `consteval` Nedir?
C++20 ile tanıtılan **`consteval`**, bir fonksiyonun yalnızca derleme zamanında çağrılmasını zorunlu kılan bir anahtar kelimedir. 
`consteval` ile işaretlenmiş bir fonksiyon, derleme zamanında çalıştırılmak zorundadır ve çalışma zamanında çağrılamaz.

### Sözdizimi:

consteval return_type function_name(parameters) {
    // Function body
}

### **Kullanım Amacı:**
- **Derleme Zamanında Sabit Hesaplamalar:** `consteval` fonksiyonları, derleme sürecinde değerlendirilecek sabit değerlere ihtiyaç duyulan durumlar için kullanılır.
- **Hataları Erken Yakalama:** Yanlış bir kullanımı derleme zamanında tespit ederek daha güvenli bir kod sağlar.
- **Metaprogramlama:** `consteval`, özellikle sabit ifadeler oluşturmak ve derleme zamanında program mantığı yürütmek için yararlıdır.

### Örnek:
#### Derleme Zamanında Sabit Bir Değer Döndüren Fonksiyon

#include <iostream>

consteval int square(int x) {
    return x * x;
}

int main() {
    constexpr int result = square(5); // Derleme zamanında hesaplanır
    std::cout << result << std::endl;

    // int runtime_result = square(6); // Hata: Çalışma zamanında çağrılamaz
    return 0;
}

### **Kullanım Alanları**
1. **Sabite Dayalı Hesaplamalar:**
   - Matematiksel ifadelerin veya sabitlerin derleme zamanında hesaplanması.
2. **Sınıf Sabitleri:**
   - `constexpr` veya `consteval` kullanılarak derleme zamanı sabit sınıf örneklerinin oluşturulması.
3. **Compile-Time Metaprogramming:**
   - Şablon parametrelerinin veya sabit ifadelerin daha etkili yönetimi.

### `constexpr` ile Karşılaştırma
| Özellik                | `consteval`                         | `constexpr`                        |
|------------------------|--------------------------------------|------------------------------------|
| Zorunlu Çağrı Zamanı   | Sadece derleme zamanında çağrılır.   | Hem derleme hem de çalışma zamanında çağrılabilir. |
| Esneklik               | Daha katıdır.                       | Daha esnektir.                    |
| Amaç                   | Sabit hesaplamaları garanti eder.   | Sabit hesaplamalara izin verir, ancak zorunlu değildir. |

### Önemli Notlar:
- **`consteval` ve `constexpr` birleştirilemez.**
- `consteval` fonksiyonları sabit olmayan bir bağlamda kullanılırsa derleyici bir hata verir.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **bit field members** (bit alanları), bir yapı veya birlik içinde, bir üyenin bellekte yalnızca 
belirli bir sayıda bit kullanmasını sağlayan özel bir veri üyesidir. Bu, özellikle bellek kullanımını optimize etmek için kullanılır.

### **Bit Alanlarının Tanımlanması**
Bir bit alanı, temel bir tür ve ardından bir `:` işaretiyle belirtilen bit genişliğiyle tanımlanır.

#### Sözdizimi:

struct StructName {
    unsigned int field_name : bit_width;
};

- **`field_name`:** Bit alanının adı.
- **`bit_width`:** Üyenin kullanacağı bit sayısı.

### **Özellikler**
1. **Bellek Tasarrufu:**
   - Bit alanları, bir üyenin gereksiz bellek tüketmesini önler.
   - Örneğin, 1 bitlik bir bayrak için tam bir `int` yerine yalnızca 1 bit kullanılır.

2. **Tipik Kullanım Alanları:**
   - **Bayraklar:** Birden fazla bayrağı aynı tam sayı üzerinde saklamak.
   - **Donanım ve protokol tanımları:** Örneğin, ağ protokolü başlıkları.

3. **Sınırlamalar:**
   - Bit alanlarının adresi alınamaz (`&` operatörüyle).
   - Bit genişliği 0 olarak belirtilirse, bir hizalama sınırı zorlanır.

### **Örnekler**
#### 1. Temel Kullanım:

#include <iostream>

struct Flags {
    unsigned int is_enabled : 1;
    unsigned int has_error  : 1;
    unsigned int mode       : 2; // 2 bit: 0-3 değerlerini saklayabilir
};

int main() {
    Flags f = {1, 0, 3}; // Bit alanlarını doldur
    std::cout << "is_enabled: " << f.is_enabled << "\n";
    std::cout << "has_error: " << f.has_error << "\n";
    std::cout << "mode: " << f.mode << "\n";

    return 0;
}

#### 2. Boşluk Oluşturma:

struct Header {
    unsigned int version : 4;
    unsigned int : 4;         // Boşluk (kullanılmayan 4 bit)
    unsigned int type : 8;
};

#### 3. Hizalama:

struct Padded {
    unsigned int field1 : 5;
    unsigned int : 0;         // Yeni hizalama başlatır
    unsigned int field2 : 6;
};

### **Avantajları**
1. **Optimize Bellek Kullanımı:**
   - Küçük boyutlu değerler için fazla bellek tüketiminden kaçınılır.

2. **Daha Az Karmaşıklık:**
   - Bayrak veya durum bilgilerini saklamak için ayrı bitmask işlemleri gerektirmez.

### **Sınırlamaları**
1. **Taşınabilirlik Sorunları:**
   - Bit alanlarının yerleşimi (endianness) platformdan platforma değişebilir.

2. **Adreslenemez:**
   - Bit alanlarının adresi alınamaz veya doğrudan işaretçilerle kullanılamaz.

3. **Performans:**
   - Bellek erişimi bazen diğer veri türlerine kıyasla daha yavaş olabilir.
-------------------------------------------------------------------------------------------------------------------------------------------------- 3)
 4)"Compiler extension" (derleyici uzantısı), bir derleyicinin, standart dil özelliklerinin ötesinde ek işlevsellik veya özellikler 
 sağlayan eklemelerdir. Bu uzantılar, belirli bir derleyicinin yeteneklerini genişleterek programcılara standart dilde bulunmayan özellikler sunar. 
 Derleyici uzantıları, performans iyileştirmeleri, hata ayıklama, platforma özgü optimizasyonlar veya geliştirilmiş dil özellikleri gibi çeşitli amaçlarla kullanılabilir.

### Compiler Extension Örnekleri

1. **__attribute__ (GCC ve Clang)**
   - GCC ve Clang derleyicileri, `__attribute__` uzantısıyla işlevler, değişkenler veya türler için ek özellikler belirlemenize olanak tanır.
   - Örneğin:

     void my_function() __attribute__((noreturn));

2. **#pragma Direktifleri**
   - Çoğu derleyici, derleyiciye belirli yönergeler sağlamak için `#pragma` direktiflerini kullanır.
   - Örneğin, Visual Studio'da bellek hizalamasını değiştirmek için:

     #pragma pack(push, 1)
     struct MyStruct {
         char c;
         int i;
     };
     #pragma pack(pop)

3. **__declspec (MSVC)**
   - Microsoft Visual C++ derleyicisi, `__declspec` uzantısıyla işlevler, veri veya sınıflar için ek nitelikler tanımlar.
   - Örneğin:

     __declspec(dllexport) void my_exported_function();

4. **Inline Assembly**
   - Birçok derleyici, kaynak kodunda doğrudan makine kodu eklemek için inline assembly uzantılarını destekler.
   - Örneğin, GCC'de:

     asm("movl %eax, %ebx");

5. **Built-in Functions**
   - Derleyiciler, belirli donanım özelliklerinden veya özel işlemlerden yararlanmak için dahili işlevler sunabilir.
   - Örneğin, GCC'de `_builtin_popcount` işlevi bit sayısını hesaplar:

     int count = __builtin_popcount(0b10101010);

### Kullanım Alanları ve Dikkat Edilmesi Gerekenler

- **Performans Optimizasyonları:** Belirli donanım özelliklerinden yararlanarak daha verimli kod üretmek için kullanılır.
- **Platforma Özgü Kod:** Belirli bir işletim sistemi veya donanım platformu için özel kod yazarken kullanılır.
- **Hata Ayıklama:** Ek hata ayıklama bilgileri veya kontrolleri eklemek için kullanılabilir.
- **Gelişmiş Dil Özellikleri:** Standart dilin izin vermediği gelişmiş dil özelliklerini kullanmak için kullanılabilir.

Ancak, derleyici uzantıları kullanırken dikkatli olunmalıdır, çünkü bu uzantılar taşınabilirliği azaltabilir ve kodun başka derleyicilerde 
derlenmesini zorlaştırabilir. Bu nedenle, mümkün olduğunca standart dil özelliklerine bağlı kalmak ve yalnızca gerçekten gerekli 
olduğunda derleyici uzantılarını kullanmak önemlidir.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 5)Digit separator (sayı ayırıcı), uzun sayıların okunabilirliğini artırmak için kullanılan bir özelliktir. C++11 standardında tanıtılan bu özellik, 
 sayılar arasında `_` (alt çizgi) kullanarak sayıları daha okunabilir hale getirir. Sayıların okunmasını kolaylaştırmak ve hata yapma olasılığını azaltmak için kullanılır.

### Kullanım Örnekleri

C++'da digit separator kullanımı oldukça basittir. Aşağıdaki örnekler, çeşitli sayı türlerinde digit separator kullanımını göstermektedir:

#include <iostream>

int main() {
    int largeNumber = 1'000'000; // 1 milyon
    double pi = 3.141'592'653'589'793; // Pi'nin yaklaşık değeri
    unsigned long long bigHex = 0xFF'FF'FF'FF'FF'FF'FF'FF; // Büyük bir hexadecimal sayı

    std::cout << "Large Number: " << largeNumber << std::endl;
    std::cout << "Pi: " << pi << std::endl;
    std::cout << "Big Hex: " << std::hex << bigHex << std::endl;

    return 0;
}

### Avantajlar

1. **Okunabilirlik**: Büyük sayıların okunabilirliğini artırır, özellikle finansal, bilimsel veya mühendislik uygulamalarında faydalıdır.
   - `1000000` yerine `1'000'000` kullanmak, sayının milyon olduğunu hemen anlamayı kolaylaştırır.
   
2. **Hata Azaltma**: Uzun sayıların yazılmasında hata yapma riskini azaltır.
   - `3141592653589793` gibi bir sayıyı yazarken hata yapma olasılığı yüksektir, ancak `3.141'592'653'589'793` gibi yazmak hatayı azaltır.

### Desteklenen Türler

Digit separatorlar, tamsayılar (`int`, `unsigned int`, `long`, `unsigned long`, `long long`, `unsigned long long`), kayan noktalı sayılar (`float`, `double`, `long double`) 
ve hexadecimal, binary, octal sabitler dahil olmak üzere tüm sayısal sabitlerde kullanılabilir.

### Notlar

- Digit separator yalnızca sayısal sabitlerin okunabilirliğini artırmak için kullanılır. Derleyici, bu karakteri görmezden gelir ve sayıyı normal şekilde işler.
-  '  karakteri sadece sabitlerin içinde kullanılabilir; değişken isimlerinde veya diğer yerlerde kullanılamaz.

### Özet

Digit separator, kodun okunabilirliğini ve bakımını iyileştiren bir araçtır. Büyük ve karmaşık sayıları yazarken ve okurken hata yapma olasılığını azaltır. 
Bu nedenle, C++'da büyük sayılarla çalışırken digit separatorları kullanmak iyi bir uygulamadır.
--------------------------------------------------------------------------------------------------------------------------------------------------
6)Attributelar

C++ attribute'ları (öznitelikler), kodun belirli yönlerini belirtmek ve derleyiciye ipuçları vermek için kullanılan özel sözdizimlerdir.
C++11'den itibaren standartlaştırılmış attribute'lar dilin parçası haline gelmiştir. İşte bazı yaygın C++ attribute'ları ve açıklamaları:

### 1. `[[nodiscard]]`
Bu attribute, bir fonksiyonun veya dönüş değerinin kullanılmasını zorunlu kılar. Kullanılmazsa derleyici bir uyarı verir.

[[nodiscard]] int compute() {
    return 42;
}

int main() {
    compute(); // Uyarı: 'compute' fonksiyonunun geri dönüş değeri kullanılmadı.
}

### 2. `[[deprecated]]`
Bu attribute, bir fonksiyonun veya değişkenin kullanımının artık önerilmediğini belirtir. Kullanılırsa derleyici bir uyarı verir.

[[deprecated("Use newFunction instead")]]
void oldFunction() {
    // eski işlevsellik
}

void newFunction() {
    // yeni işlevsellik
}

int main() {
    oldFunction(); // Uyarı: 'oldFunction' kullanımı önerilmemektedir. Bunun yerine 'newFunction' kullanılmalıdır.
}

### 3. `[[fallthrough]]`
Bu attribute, bir `switch` durumu içindeki bilerek bırakılmış bir geçişi belirtir. Bu, `case` bloklarının sonunda `break` ifadesi olmadığında kullanılır.

void process(int value) {
    switch (value) {
        case 1:
            // bir şeyler yap
            [[fallthrough]];
        case 2:
            // daha fazla şey yap
            break;
        default:
            break;
    }
}

### 4. `[[maybe_unused]]`
Bu attribute, bir değişkenin veya fonksiyonun kullanılmamasının kabul edilebilir olduğunu belirtir. 
Derleyici, bu attribute ile işaretlenmiş kullanılmayan kod için uyarı vermez.

[[maybe_unused]] void helperFunction() {
    // yardımcı işlevsellik
}

int main() {
    [[maybe_unused]] int x = 42; // Kullanılmayan değişken için uyarı verilmez.
}

### 5. `[[likely]]` ve `[[unlikely]]`
Bu attribute'lar, bir koşulun gerçekleşme olasılığının yüksek veya düşük olduğunu belirtmek için kullanılır. 
Bu attribute'lar, dallanma tahmini ve optimizasyon için derleyiciye ipucu sağlar.

void process(int value) {
    if (value == 0) [[unlikely]] {
        // Bu blok nadiren çalışacak
    } else {
        // Bu blok genellikle çalışacak
    }
}

### 6. `[[noinline]]`
Bu attribute, derleyiciye belirtilen fonksiyonun inline edilmemesini söyler. Performans analizi veya hata ayıklama için kullanışlıdır.

[[noinline]] void foo() {
    // Bu fonksiyon inline edilmeyecek
}

### 7. `[[carries_dependency]]`
Bu attribute, bellek bağımlılıklarını işaretlemek için kullanılır. Özellikle paralel programlamada kullanılır.

void foo([[carries_dependency]] int* ptr) {
    // Belirtilen bağımlılıklarla çalış
}

### 8. `[[noreturn]]`
Bu attribute, belirtilen fonksiyonun normal şekilde geri dönmeyeceğini belirtir. Genellikle hata işleme veya sonlandırma fonksiyonları için kullanılır.

[[noreturn]] void terminate() {
    std::exit(1);
}

### 9. `[[alignas]]`
Bu attribute, veri yapılarını belirli bir hizalamayla hizalamak için kullanılır.

struct alignas(16) AlignedStruct {
    float data[4];
};
--------------------------------------------------------------------------------------------------------------------------------------------------
7)**Pure function** (saf fonksiyon), aynı girdilerle her zaman aynı çıktıyı veren ve hiçbir yan etkiye (side effect) sahip olmayan bir fonksiyondur. 
Yan etkiler, fonksiyonun dışındaki herhangi bir durumu (global değişkenler, dosya sistemleri, veri tabanları, vb.) değiştirme veya dış dünyayı etkileme anlamına gelir.

Bir fonksiyonun saf (pure) olabilmesi için şu iki koşulu sağlaması gerekir:

1. **Deterministik Olma (Aynı Girdilere Aynı Çıktıyı Verme)**:
   Bir saf fonksiyon, her çağrıldığında aynı girdilere aynı çıktıyı üretir. Bu, fonksiyonun çıktısının yalnızca girdilerine bağlı olduğu anlamına gelir.

2. **Yan Etkisiz Olma (Side Effect Olmama)**:
   Saf fonksiyon, dış dünyayı değiştirmez veya etkilemez. Yani, fonksiyonun çalıştırılması sırasında global değişkenlerde, 
   dosya sisteminde veya kullanıcı arayüzünde herhangi bir değişiklik yapılmaz.

### Saf Fonksiyon Örnekleri

#### Saf Fonksiyon Örneği (Pure)
Aşağıdaki fonksiyon, saf bir fonksiyondur çünkü dışarıda herhangi bir değişiklik yapmaz ve aynı girdilere her zaman aynı çıktıyı verir.

int add(int a, int b) {
    return a + b;  // Yan etki yok, dış dünyayı değiştirmiyor
}

Bu `add` fonksiyonu saf bir fonksiyondur. Aynı `a` ve `b` değerleri verildiğinde her zaman aynı sonucu döner ve dış dünyada herhangi bir değişiklik yapmaz.

#### Saf Olmayan Fonksiyon Örneği (Impure)
Saf olmayan bir fonksiyon, yan etkilere sahip olabilir. Örneğin:

int getRandomNumber() {
    return rand();  // Yan etki: Farklı çıktılar üretir ve dış dünyaya bağımlıdır
}

Bu `getRandomNumber()` fonksiyonu saf değildir, çünkü her çağrıldığında farklı sonuçlar üretir (deterministik değildir) ve dış dünyaya (rastgele sayı üreteci) bağımlıdır.

Bir diğer örnek, saf olmayan bir fonksiyonun dış dünyayı değiştirdiği durumu gösterebilir:

int counter = 0;

void incrementCounter() {
    counter++;  // Yan etki: Global değişkeni değiştirme
}

Bu `incrementCounter()` fonksiyonu da saf değildir, çünkü fonksiyon her çağrıldığında global `counter` değişkenini değiştirir, yani yan etkiye sahiptir.

### Saf Fonksiyonların Faydaları
- **Test edilebilirlik**: Saf fonksiyonlar test edilmesi kolaydır, çünkü herhangi bir yan etki olmadığından yalnızca girdiler ve çıktılar dikkate alınır.
- **Yüksek modülerlik**: Saf fonksiyonlar diğer kod parçalarından izole oldukları için, kolayca tekrar kullanılabilirler.
- **Performans iyileştirmesi**: Aynı girdilere sahip fonksiyonlar cache'lenebilir (memoization), çünkü aynı girdi her zaman aynı çıktıyı verecektir.
 --------------------------------------------------------------------------------------------------------------------------------------------------
8)early binding veya static binding(erken bağlama) ve late binding veya dynamic binding(geç bağlama), bir fonksiyon çağrısının 
derleme zamanında mı yoksa çalışma zamanında mı çözümlendiğini belirleyen iki farklı kavramdır.

### 1. **Early Binding (Erken Bağlama)**
- **Early binding**, fonksiyon çağrısının derleme zamanında çözümlendiği durumdur. Yani, hangi fonksiyonun çağrılacağı, derleme sırasında belirlenir.
- C++'da **normal (non-virtual) fonksiyonlar**, **inline fonksiyonlar**, **template fonksiyonlar** ve **static fonksiyonlar** erken bağlamaya tabidir.
- Bu yaklaşım daha hızlıdır çünkü derleme zamanında hangi fonksiyonun çağrılacağı bellidir, bu yüzden çalışma zamanı performansı yüksektir.

#### Örnek:

#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class show function" << std::endl;
    }
};

int main() {
    Base obj;
    obj.show();  // Erken bağlama: Derleme zamanında çözülür
    return 0;
}

Yukarıdaki örnekte, `show()` fonksiyonu **early binding** ile çağrılır. Çünkü `show()` sanal (virtual) bir fonksiyon değildir. 
Derleyici, hangi fonksiyonun çağrılacağını derleme zamanında bilir ve fonksiyon çağrısını o an çözer.

### 2. **Late Binding (Geç Bağlama)**
- **Late binding**, fonksiyon çağrısının çalışma zamanında çözümlendiği durumdur. Yani, hangi fonksiyonun çağrılacağı, program çalışırken belirlenir.
- C++'da **virtual** (sanal) fonksiyonlar geç bağlamaya tabidir. Sanal fonksiyonlar, temel sınıftan türetilmiş sınıflarda geçersiz kılınarak (override edilerek) dinamik bir şekilde çağrılabilirler.
- **Late binding**, polimorfizm sağlar. Bu, bir taban sınıf (base class) işaretçisinin veya referansının, türetilmiş sınıfların fonksiyonlarını çağırmasına olanak tanır.

#### Örnek:

#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->show();  // Geç bağlama: Çalışma zamanında çözülür
    delete obj;
    return 0;
}

Bu örnekte, `show()` fonksiyonu **late binding** ile çağrılır. Çünkü `show()` sanal bir fonksiyondur. Derleme zamanında hangi fonksiyonun 
çağrılacağı belli değildir. Çalışma zamanında, `obj` işaretçisinin aslında `Derived` sınıfına ait olduğu belirlenir ve `Derived` sınıfındaki `show()` fonksiyonu çağrılır.

### **Farklar**

| **Özellik**                | **Early Binding (Erken Bağlama)**                             | **Late Binding (Geç Bağlama)**                             |
|----------------------------|---------------------------------------------------------------|------------------------------------------------------------|
| **Çözüm Zamanı**            | Derleme zamanı                                                | Çalışma zamanı                                              |
| **Performans**              | Daha hızlıdır (derleme zamanında çözüldüğü için).              | Daha yavaştır (çalışma zamanı çözümü olduğu için küçük bir maliyet vardır). |
| **Kullanım Alanı**          | Sanal olmayan fonksiyonlar, static fonksiyonlar, template fonksiyonlar | Sanal fonksiyonlar (virtual), polimorfizm kullanımı         |
| **Polimorfizm**             | Polimorfizm sağlamaz                                          | Polimorfizm sağlar                                         |
| **Fonksiyon Çözümlemesi**   | Fonksiyon derleme zamanında çözülür                           | Fonksiyon çalışma zamanında çözülür                        |

### Sonuç:
- **Early binding** daha hızlıdır çünkü fonksiyon çağrısı derleme zamanında çözülür.
- **Late binding** ise polimorfizm sağlar, ancak çalışma zamanında çözümleme olduğu için küçük bir performans maliyeti vardır.

NOT:

int foo(int);
int foo(const int); //re-decleration overloading değil pointer yada referans olsaydı const overloading olurdu

int foo(int *p); 
int foo(int* const p); //parametre değişkenini kendisi const re-decleration

int foo(const int *p); //pointerın kendisi const function overloading
 ******************************************************************************************************************************     

                                                                          ********* 7-DERS NOTLARI *********
 1) Const overloading 

 Bir işlevin parametre değişkeni gösterdiği yer const olan bir gösterici iken, aynı isimli bir başka işlevin 
parametre değişkeni, gösterdiği yer const olmayan bir gösterici olabilir:

void foo(const int *); 
void foo(int *);

Bu durum da işlev yüklemesi olarak ele alınır. Yani iki ayrı işlev söz konusudur. foo
işlevine int türden bir nesne ile çağrı yapıldığında, hangi işlev çağrılmış olur?

void func()
{
int x = 20;
foo(&x); //hangi işlev çağrılır?
}

Bu durum "const yüklemesi" (const overloading) olarak bilinir. Hangi işlevin çağrılacağı, işleve gönderilen 
nesnenin const olup olmamasına göre belirlenir. Eğer işlev çağrısı const bir nesne adresi ile yapılırsa, parametre 
değişkeni gösterdiği yer const gösterici olan işlev çağrılırken, işlev çağrısı const olmayan bir nesnenin adresi ile 
yapılırsa, çağrılan diğer işlev olur:

void foo(const int *); 
void foo(int *);

void func()
{
int x = 20;
const int y = 30;
foo(&x); // void foo(int *); 
foo(&y); // void foo(const int *);
}

Şüphesiz const yüklemesi, parametre değişkeninin referans olması durumunda da geçerlidir:

void foo(const int &); 
void foo(int &);
void func()
{
int x = 20;
const int y = 30;
foo(x); // void foo(int &); 
foo(y); // void foo(const int &);
}

Aşağıda yer alan programda, çift anlamlılık hatasının olduğu bir başka tipik durum gösteriliyor:

#include <iostream>
using namespace std; 

void foo(int &r)
{
cout << "void foo(int &)" << endl;
}

void foo(int x)
{
cout << "void foo(int)" << endl;
}

int main()
{
int a = 20;
//foo(a); çift anlamlılık hatası 
foo(5); //void foo(int);

return 0;
}

Yukarıdaki programda, ilk tanımlanan foo işlevinin parametre değişkeni int türden bir referans iken, ikinci foo 
işlevinin parametre değişkeni int türden bir nesnedir. Bunlar farklı işlevdir. main işlevi içinde, yorum satırı 
içine alınmış birinci işlev çağrısı çift anlamlılık hatasına neden olur. Yani bu durumda, değerle çağırma(call by 
value) ya da adresle çağırma (call by reference) birbirine göre öncelikli değildir. Ancak ikinci işlev çağrısında, 
argüman olan ifade bir değişmezdir. Bir referansa bir değişmez ifadesi ile ilk değer verilemeyeceğine göre, 
çağrılabilecek tek bir işlev vardır. Şunu da ekleyelim:
Birinci işlevin parametre değişkeni const referans olsaydı, ikinci işlev çağrısı da çift anlamlılık hatası 
durumuna düşerdi.
Hangi işlevin çağrılmış olduğunu saptamak, derleme zamanında yapılan bir işlemdir. Yani kaynak kod derlenip 
hedef dosya haline getirildiğinde, artık hangi işlevin çağrılmış olduğu bilinir. Çünkü çağrılan işlevin kimliği bir 
şekilde hedef koda yazılmış olur. Başka bir deyişle "işlev yüklemesi" aracının, programın çalışma zamanı 
açısından bakıldığında bir ek maliyeti söz konusu değildir. Ancak böyle bir araç derleyici üzerindeki yükü de
artırır.
Derleyici programın boyutunun büyümesine neden olur. Küçük bir dil olarak tasarlanan C dilinde, bu aracın 
bulunmamasının önemli bir nedeni de budur.
Aynı isimli işlevler gereksiz yere tanımlanmamalıdır. İşlev yüklemesinin ana amacı, çalışacak kodları gerçekte 
birbirinden farklı olan işlemleri, aynı isim altında soyutlamaktır. Farklı işler gören işlevlerin, aynı ismi taşıması 
okunabilirliği bozar. Birden fazla işlevin aynı ismi taşıması, kullanıcı kodların işini kolaylaştırmaya yöneliktir
--------------------------------------------------------------------------------------------------------------------------------------------------
2)fuction overload resolution

lond double -> char
enum -> int
int* -> void* 
int* -> bool

Bir işlev çağrısının, hangi işleve ilişkin olduğunun saptanması işlemine “Yüklenmiş İşlevin Saptanması" (function
overload resolution) denir.
"Yüklenmiş işlevin saptanması", derleyici tarafından üç aşamada yapılan bir işlemdir.
Birinci aşamada, derleyici söz konusu işlev çağrısı için ele alınacak aynı isimli işlevleri saptayarak bu
işlevlerin parametrik yapısı hakkında bilgi edinir. Çağrılması söz konusu olan aynı isimli işlevlere "aday
işlevler" (candidate functions) denir.
Aday işlevler, işlev çağrı ifadesinde kullanılan isimle aynı isme sahip olan, işlev çağrı ifadesinin bulunduğu
yerde görülebilen (visible) işlevlerdir.
Birinci aşamada derleyici, aday işlevler hakkında gerekli bilgiyi de edinir. Aday işlevlerin parametre değişkeni
sayılarını, parametre değişkenlerinin türlerini öğrenir.

İkinci aşamada, işlev çağrı ifadesinde yer alan argümanlar kullanılarak, hangi aday işlevlerin geçerli
biçimde çağrılabileceği saptanır. Söz konusu işlev çağrısıyla, geçerli biçimde çağrılabilen işlevlere, uygun
işlevler (viable functions) denir.
Bir işlevin uygun işlev olarak belirlenebilmesi için, aşağıdaki koşulları sağlaması gerekir:

i) İşlev çağrı ifadesindeki argüman sayısı ile, işlevin parametre değişkeni sayısının aynı olması zorunludur.
İşlev çağrı ifadesindeki argüman sayısı, işlevin parametre değişkeni sayısından daha az ise, bu durumda
işlevin argüman gönderilmeyen parametre değişkenleri varsayılan argüman almalıdır.

ii) Argüman olan ifadenin, parametre değişkeni olan nesneye uygun bir şekilde
dönüştürülebilmesi gerekir:

Örnek olarak, aşağıda bildirimleri verilen işlevleri inceleyelim:

void foo(); //1
void foo(int); //2
void foo(double, double = 3.4) //3
void foo(char *); //4
void func()
{
foo(5);
}

func işlevi içinde foo isimli işleve yapılan çağrının, işlevlerden hangisine ait olduğunun saptanması
aşamalarını inceleyelim:
1. aşama
İşlevin çağrıldığı noktada, tüm işlev bildirimleri görülebilir (visible) olduğundan bu aşamada, dört işlev de
aday olarak belirlenir, parametrik yapıları hakkında bilgi edinilir.

2. aşama
1 numaralı işlevin parametre değişkeni sayısı (0) ile, işlev çağrısındaki argüman sayısı (1) birbirine eşit
olmadığından, bu işlev uygun (viable function) olarak ele alınmaz.

2 numaralı işlev uygundur. Parametre değişkeni ile argüman sayısı uyumludur, argümandan
parametre değişkenine geçerli bir dönüşüm söz konusudur.

3 numaralı işlev uygundur. İşlevin iki parametre değişkeni vardır. Ancak ikinci parametre değişkeni varsayılan
argüman aldığı için, işlev tek bir argüman ile çağrılabilir. Argüman olan ifade int türden, bu argümanın
kopyalanacağı parametre değişkeni double türdendir. Ancak atama öncesinde int türü, geçerli olarak double
türüne dönüştürülebilir.

4 numaralı işlev uygun değildir. İşlevin parametre değişkeni sayısı ile, işlev çağrısındaki argüman sayısı birbirine
eşit olmasına karşın, int türden ifade, dilin kurallarına göre char* türüne dönüştürülemez.
İkinci aşamada uygun bir işlev bulunmaz ise, işlev çağrısı geçersiz kabul edilir. Bu duruma İngilizcede "no
match" durumu (çağrılacak uygun bir işlevin bulunmaması) denir.

Üçüncü aşama
Üçüncü yani son aşamada, uygun işlevler içinde en uygun olan işlev belirlenir. Uygun işlevler içinden
seçilerek, çağrı ifadesi ile eşlenecek işleve "en uygun işlev" (best viable function / best match function) denir.
üçüncü aşamada, belirli sayıda uygun işlev içinden, bir işlevin en uygun işlev olarak seçilebilmesi için
aşağıdaki koşulları yerine getirmesi gerekir:

İşlev çağrı ifadesindeki argümanlardan işlevin ilgili parametre değişkenine yapılan dönüşümün derecesi
diğer uygun işlevlere göre daha kötü olmaması gerekir. En az bir argüman için yapılacak dönüşümün
diğerlerine göre daha iyi olması gerekir.
Birden fazla uygun işlev içinden, en uygun işlevin seçilememesi durumunda "çift anlamlılık hatası" (ambiguity)
denilen bir hata durumu oluşur. Bu durumda, derleyici için kurallara uygun olarak çağrılabilecek birden fazla
işlev söz konusudur.
"Argümanlardan parametre değişkenlerine yapılacak dönüşümün derecesi" ne anlama gelir?
C++ standartları, argümanlardan parametre değişkenlerine yapılabilecek otomatik dönüşümleri 4 ayrı
dereceye ayırmıştır.

1. Tam uyum (exact match)
2.      Yükseltme (promotion) 
3.           Standart dönüşüm (standard conversion)
4.                 Programcının tanımladığı dönüşüm (user defined conversion)

Kurallara göre, "tam uyum" durumu "yükseltme"den, "yükseltme" durumu standart dönüşümden,
standart dönüşüm de programcının tanımladığı dönüşümden daha iyi olarak kabul edilir.
Yukarıdaki derecelendirmeleri ayrıntılı biçimde inceleyelim:

1. Tam uyum durumu
Argüman olan ifadenin türü ile, bu argümanın kopyalanacağı parametre değişkeni olan nesnenin türü
tamamen aynı ise, bu durum tam uyum (exact match) olarak ele alınır. Ancak aşağıdaki durumlar da tam
uyum olarak ele alınır:

i) Argüman olan nesne bir sol taraf değeri, yani bir nesne ise, parametre değişkenine kopyalanacak değerin,
bu nesneden alınması. Bu duruma sol taraf değerinden sağtaraf değerine dönüşüm denir (L-value to R-value
transformation).

ii) Parametre değişkeninin bir gösterici olması, işlevin de aynı türden bir dizinin ismi ile çağrılması. Dizi
isimlerinin bir işleme sokulduğunda, işlem öncesinde otomatik olarak dizinin ilk elemenının başlangıç adresine
dönüştürüldüğünü (array to pointer conversion)

iii) Parametre değişkeninin bir işlev göstericisi (function pointer) olması, işlevin de aynı türden bir işlevin
ismi ile çağrılması. İşlev isimlerinin bir işleme sokulduğunda, işlem öncesinde otomatik olarak işlev bloğunun
başlangıç adresine dönüştürüldüğünü biliyorsunuz.

iv) İşlev parametre değişkeninin, gösterdiği yer const olan bir gösterici olması, işlevin aynı türden ancak
const olmayan bir adres ile çağrılması (qualification conversion).

2. Yükseltme durumu
Yükseltme (promotion), aşağıdaki durumları kapsar

i. char, unsigned char, short, unsigned short , bool türlerinden int türüne yapılacak dönüşüm. Bu duruma "int
türüne yükseltme" (integral promotion) denir. Argüman olan ifade, int türünden küçük türlerden ise, int
türüne yükseltme kuralı gereği, işlevin parametre değişkenlerine yapılan bir atama söz konusu ise, bu durum
yükseltme olarak ele alınır.
void func(int);
int main()
{
func('A'); //Yükseltme (integral promotion)
func(true); // Yükseltme (integral promotion)
//...
}
ii) Argüman olan ifade float türden ise, işlevin bu argümana karşılık gelen parametre değişkeni double
türden ise, bu durumda, float türünden double türüne yapılacak dönüşüm de yükseltme olarak
değerlendirilir:
void func(double);
int main()
{
float fx;
//...
func(fx); //yükseltme
//...
}

iii. Bir numaralandırma türünden, o numaralandırma türüne baz olan (underlying type)
türe yapılan dönüşüm de, yükseltme olarak değerlendirilir. Aşağıdaki örneği inceleyin:
enum POS {OFF, ON, HOLD, STAND_BY};
int func(int);
int main()
{
POS position = OFF;
func(position); // Numaralandırma türünden int türüne yükseltme)
func(STAND_BY); // Numaralandırma türünden int türüne yükseltme)
//...
}

3. Standart dönüşümler
Standart dönüşüm (standard conversions) başlığı altında toplanan, 5 grup dönüşüm söz konusudur:
i. Tamsayı türlerine ilişkin dönüşümler
Bir tamsayı türünden ya da bir numaralandırma türünden, başka bir tamsayı türüne yapılan
dönüşümler.
ii. Gerçek sayı dönüşümleri
Bir gerçek sayı türünden başka bir gerçek sayı türüne yapılan dönüşümler

iii. Gerçek sayı türleri ile tamsayı türleri arasında yapılan dönüşümler.

iv. Adres türlerine ilişkin dönüşümler
0 değerinin herhangi türden bir göstericiye atanması ya da void türden olmayan herhangi bir adres bilgisinin
void türden bir göstericiye atanması durumu.

v. bool türüne yapılan dönüşümler
Herhangi bir tamsayı, gerçek sayı, numaralandırma ya da adres türünden, bool türüne yapılan dönüşümler.
Aşağıda standart dönüşümlere ilişkin bazı örnekler veriliyor:

void func(int);
void foo(long);
void sample(float);
void pf(int *);
void vfunc(void *);

int main()
{
int x = 10;
foo(x); //standart dönüşüm (int türden long türüne)
foo('A'); //standart dönüşüm (char türden long türüne)
func(20U); //standart dönüşüm (unsigned int türünden int)
sample(7.5); //standart dönüşüm (double türden float türüne)
pf(0); //standart dönüşüm (0 değerinin bir göstericiye atanması
vfunc(&x) //standart dönüşüm (int * türden void * türüne)
//...
return 0;
}

4. Programcının tanımladığı dönüşümler(User defined conversion). Bu dönüşümler,
bir sınıf türünden nesnenin başka bir sınıf türüne ya da doğal bir veri türüne dönüştürülmesine ilişkindir.
Derleyicinin bu tür dönüşümleri gerçekleştirebilmesi için, programcının özel dönüşüm işlevleri tanımlamış
olması gerekir. İsimleri "Dönüştürme kurucu işlevleri" ya da "tür dönüştürme işlevleri"
Hangi işlevin çağrılmış olduğunun saptanması konusunda örnekler verelim:

int foo(int); //1
int foo(double); //2
void foo(char); //3
long foo(long); //4
void foo(int, int); //5
void foo(char *); //6
void foo(int *); //7

void func()
{
foo(10);
foo(3.4F);
foo((double *) 0x1FC0);
foo(6U);
}
func işlevi içinde yapılan işlev çağrılarını teker teker ele alalım:

foo(10);
Çağrısı için
1, 2, 3, 4, 5, 6, 7 numaralı işlevler adaydır.
1, 2, 3, 4 numaralı işlevler uygundur.
Tam uyum sağladığı için, 1 numaralı işlev en uygun olanıdır.

int foo(int); //1
int foo(double); //2
void foo(char); //3
long foo(long); //4
void foo(int, int); //5
void foo(char *); //6
void foo(int *); //7

foo(3.4F)
Çağrısı için
1, 2, 3, 4, 5, 6, 7 numaralı işlevler adaydır.
1, 2, 3, 4 numaralı işlevler uygundur.
Yükseltme durumu olarak değerlendirildiğinden, 2 numaralı işlev en uygun olanıdır.

foo((double *) 0x1FC0)
Çağrısı için
1, 2, 3, 4, 5, 6, 7 numaralı işlevler aday işlevlerdir. Uygun işlev
yoktur (no match).
İşlev çağrısı geçersizdir.

foo(6U)
Çağrısı için
1, 2, 3, 4, 5, 6, 7 numaralı işlevler adaydır.
1, 2, 3, 4 numaralı işlevler uygundur.
1, 2, 3 ve 4 numaralı işlevler için standart dönüşüm uygulanabilir. Çift anlamlılık hatası (ambiguity) söz
konusudur. İşlev çağrısı geçersizdir.

Ad Arama (Name Lookup):

İlk adım, çağrılan fonksiyonun isminin scope içinde aranmasıdır. Bu, global, sınıf ve namespace kapsamları 
ile başlar ve bir dizi aday fonksiyon (candidate functions) oluşturulur.

Uygun Adayların Belirlenmesi:

Aday fonksiyonlar listesinden, çağrı ile uyumlu olanlar seçilir. Parametre türleri, çağrıda verilen
argüman türlerine dönüştürülebiliyorsa fonksiyon uyumludur.

Fonksiyonların Derecelendirilmesi (Ranking):
Aday fonksiyonlar, argüman türleriyle olan uyumlarına göre sıralanır. Dönüşüm türlerine göre sıralama şu şekilde yapılır:
Doğrudan eşleşme (Exact Match): Argüman türü ve parametre türü birebir uyumludur.
Standart Dönüşüm (Standard Conversion): Örneğin, int'ten long'a veya float'tan double'a dönüşüm.
Kullanıcı Tanımlı Dönüşüm (User-Defined Conversion): Operatör dönüşümleri veya yapıcılarla gerçekleştirilen dönüşümler.
 
Ellips Dönüşümü: Fonksiyonun ... parametresiyle uyumu (en düşük öncelik).

En İyi Uyumu Bulma (Best Match):
Derleyici, çağrıyı en iyi karşılayan fonksiyonu seçer. Eğer birden fazla fonksiyon eşit derecede uygun ise bu bir ambiguity hatasına neden olur.

Hata Durumları:
Eğer hiçbir fonksiyon uygun değilse, bir uygun eşleşme bulunamadı hatası oluşur.
Eğer birden fazla fonksiyon aynı derecede iyi uyuyorsa, bir belirsizlik (ambiguity) hatası oluşur. 

NOT:
int x{};

+x -> l value olmaktan çıkar r value olur int altı türlerden biriysede integral promotionda olur
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:C dilinde aynı isimli işlevlerin bir arada bulunamamasının nedeni nedir? C derleyicileri, bir işlev çağrı ifadesi ile 
karşılaştığında, hedef koda (object code) yalnızca çağrılan işlevin ismini yazar. Örneğin Borland derleyicileri, 
çağrılan işlevin isminin başına alttire karakteri ekleyerek oluşturdukları ismi hedef koda yazar. Aşağıda bildirimi 
verilen işlevi örnek olarak ele alalım: 
int foo(int, int); 
Derleyici bu işlevin çağrılması durumunda hedef koda 

_foo 
gibi bir isim yazar. Oysa foo işlevinin bildirimi farklı olsa da, C derleyicisinin hedef koda yazacağı isim aynı olur. 
Aynı isimli fakat parametrik yapıları farklı, birden fazla foo işlevi olsaydı, derleyici bu işlevlerin hepsi için amaç 
kodda aynı ismi kullanırdı. Bu durumda da, bağlayıcı program aynı isimli işlevlerden hangisinin çağrılmış 
olduğunu anlayamazdı. 

C++ dilinde aynı isimli işlevlerin tanımlanabilmesi nasıl mümkün oluyor? C++ dilinde farklı olan nedir? 
C++ derleyicisi, bir işlev çağrı ifadesinin karşılığı olarak hedef koda, C derleyicisi gibi yalnızca işlevin ismini 
yazmaz. C++ derleyicisi çağrılan işlevin ismini, işlevin parametre değişkenlerinin türleri ile birleştirerek bir isim 
oluşturur, bu ismi amaç koda yazar. Amaç koda yazılmak üzere oluşturulan bu ismin oluşturulma biçimi, 
standartlarca kesin olarak belirtilmemiş, derleyiciyi yazanlara bırakılmıştır. Örneğin bir C++ derleyicisi yukarıda 
bildirimi verilen foo işlevini hedef koda aşağıdaki gibi yazabilir: 

_foo@i@i 

C++derleyicisinin, işlev isimlerinin sonuna @ karakterini izleyecek biçimde, parametre değişkeninin türünün 
baş harfini yazdığını varsayalım. Bu durumda 
int foo(double, double); 
gibi ikinci bir foo işlevi var olsaydı, derleyici bu işlevin çağrı ifadesi karşılığı hedef koda bu kez 

_foo@d@d yazardı. 

Böylece sıra bağlayıcı programa geldiğinde, bağlayıcı program aynı isimli birden fazla 
işlev olmasına karşın, hedef koda yazılan ismi görerek, aynı isimli işlevlerden hangisinin çağrılmış olduğunu 
anlar. 
Aynı isimli işlevlerin var olabilmesi için gerekli koşul da ortaya çıkıyor: 
Aynı isimli iki işlevin, aynı bilinirlik alanında var olabilmesi için, işlevlerin parametrik yapılarının farklı olması 
gerekir. Aynı isimli işlevlerin parametre değişkeni sayısı ve/veya parametre değişkenlerinin türleri bir farklılık 
göstermelidir. Eğer aynı isimli iki işlevin, hem parametre değişkeni sayısı aynı hem de parametre 
değişkenlerinin türleri aynı ise, bu durumda her iki işlev de hedef koda aynı şekilde yazılacağından, bağlayıcı 
program yazılan isimlerden, hangi işlevin çağrılmak istendiğini anlayamaz. 
Yukarıdaki açıklamalardan, C++derleyicilerinin çağrılan işlevi hedef koda yazarken kullandıkları ismin 
oluşturulmasında, işlevin geri dönüş değeri türünün hiçbir katkısı olmadığını anlamalısınız. Bu durumda, 
imzaları birbirleriyle tamamen aynı, ancak geri dönüş değerleri farklı türlerden olan, aynı isimli iki işlev, aynı 
bilinirlik alanında bildirilemez. Geri dönüş değeri türü dışında tüm parametrik yapısı aynı olan iki işlevin var 
olduğunu düşünelim. Bu isimle bir işlev çağrısı yapıldığında, derleyici hangi işlevin çağrıldığını anlayabilir miydi? 

int foo(int); 
double foo(int); //Geçersiz! 

int main() 
{
foo(); 

return 0;
} 
******************************************************************************************************************************

                                                                             ********* 8-DERS NOTLARI *********
1)extern "C" Kullanımı

C++ dilinde `extern "C"` ifadesi, C++ kodunu **C dili ile uyumlu hale getirmek** için kullanılır. 
Bunun amacı, C++ derleyicisinin isimleri "mangling" işlemi yapmadan, C dilinde olduğu gibi derlemesini sağlamaktır.
C++ ve C dilleri arasında fonksiyonların isimlerinin nasıl işlendiği konusunda önemli farklar vardır, bu yüzden `extern "C"` kullanılır.

### **C++ ve C Arasındaki İsim Mangling (Name Mangling)**

C++'da fonksiyonlar aşırı yüklenebilir (overloading), yani aynı isimde birden fazla fonksiyon, farklı parametre listeleriyle tanımlanabilir. 
Bu, derleyicinin fonksiyon isimlerini derleme zamanında daha karmaşık hale getirip, parametre türlerine göre farklılaştırmasını gerektirir. 
Bu işleme **name mangling (isim değiştirme)** denir. C dilinde ise bu tür bir isim mangling işlemi yapılmaz; fonksiyonlar düz isimlendirilir.

C++ derleyicileri, aşırı yüklemeyi desteklemek ve farklı fonksiyonları ayırt etmek için fonksiyon isimlerini karmaşıklaştırır. Örneğin:

void func(int);   // Mangled name: _Z4funci
void func(double);  // Mangled name: _Z4funcd

Bu fonksiyonların C++ derleyicisinde ismi mangled edilir ve C derleyicisinin bunları anlaması mümkün olmaz.

###`extern "C"` Ne Yapar?

`extern "C"` bildirimi, C++ derleyicisine bu fonksiyon veya değişkenin C stilinde isimlendirilmesi gerektiğini söyler.
Bu, C++ derleyicisinin name mangling yapmamasını ve C dilinde olduğu gibi basit bir isimlendirme yapmasını sağlar. 
Bu sayede, C dilinde yazılmış bir kütüphaneyi C++ programında kullanabiliriz ya da C++ fonksiyonları bir C programı tarafından çağrılabilir.

### **Kullanım Senaryoları**

#### 1. **C Kütüphanelerini C++ Kodunda Kullanma**

C ile yazılmış bir kütüphaneyi C++ kodu içerisinde kullanmak istediğinizde, C++ derleyicisinin fonksiyon isimlerini değiştirmemesi için `extern "C"` kullanılır.

Örnek olarak, bir C başlık dosyası (`library.h`) aşağıdaki gibi olsun:

// library.h (C dili ile yazılmış)
#ifndef LIBRARY_H
#define LIBRARY_H

void c_function(int a);

#endif

Bu fonksiyonu C++ kodunda kullanmak için şu şekilde `extern "C"` kullanılır:

// main.cpp (C++ kodu)
extern "C" {
    #include "library.h"  // C fonksiyonlarını include ediyoruz
}

int main() {
    c_function(10);  // C fonksiyonunu çağırıyoruz
    return 0;
}

Bu sayede, `c_function` C++ derleyicisinde aynı şekilde çağrılabilir.

#### 2. **C++ Fonksiyonlarını C Kodu İçerisinde Kullanma**

Tersine, bir C++ fonksiyonunu C kodunda kullanılabilir hale getirmek için de `extern "C"` bildirimi yapılabilir. Örneğin:

// mylibrary.cpp (C++ dosyası)
extern "C" void cpp_function(int a) {
    // C++ kodu
}

Bu şekilde tanımlanan `cpp_function`, bir C programı tarafından çağrılabilir, çünkü `extern "C"` ile tanımlandığında fonksiyon C dilinde olduğu gibi isimlendirilecektir.

#### 3. **Kapsamlı Kullanım**

Birden fazla fonksiyon veya değişken için `extern "C"` kullanmak gerektiğinde, bunu bir blok içerisinde yazabilirsiniz:

extern "C" {
    void c_function1(int a);
    void c_function2(int b);
}

### **`extern "C"` Kullanımıyla İlgili Notlar**

1. **Sadece Fonksiyonlar ve Global Değişkenler**:
   - `extern "C"` yalnızca fonksiyon ve global değişkenler için kullanılır. Sınıflar, yapılar, namespace'ler gibi C++'a özgü yapıların 
   `extern "C"` ile kullanılması mümkün değildir, çünkü bunlar C dilinde desteklenmez.

2. **C++ Aşırı Yükleme (Overloading)**:
   - `extern "C"` ile bildirilen fonksiyonlarda **aşırı yükleme (overloading)** yapılamaz, çünkü C dilinde aşırı yükleme desteklenmez. 
   Aynı isme sahip yalnızca tek bir fonksiyon olabilir.

3. **Kütüphaneler Arası Uyum**:
   - `extern "C"` özellikle C ile yazılmış kütüphaneleri C++ programlarında kullanırken çok yararlıdır. Çoğu C kütüphanesi, 
   C++ başlık dosyalarına uyum sağlamak için `#ifdef __cplusplus` koşullu derleme direktifi ile korunur.

### **Örnek: C++ Başlık Dosyasında C Fonksiyonlarını Korumak**

C++ başlık dosyaları yazarken, C kodu ile uyumlu olması için genellikle aşağıdaki gibi bir yapı kullanılır:

#ifdef __cplusplus
extern "C" {
#endif

void c_function(int a);

#ifdef __cplusplus
}
#endif

Bu yapıda, başlık dosyasının hem C hem de C++ programları tarafından doğru şekilde işlenmesi sağlanır.

### **Sonuç**

`extern "C"`, C++ programlarının C dilinde yazılmış fonksiyonlar ve kütüphanelerle uyumlu çalışmasını sağlar. 
Bu, C++'ın isim mangling sürecini atlayarak C dilinde olduğu gibi düz isimlendirme yapılmasına olanak tanır ve iki dil arasında köprü oluşturur.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 2)
 C++ dilinde **complete type** (tam tür) ve **incomplete type** (tamamlanmamış tür) kavramları, türlerin derleme zamanında
 ne kadar bilgiye sahip olduğunu belirler. **Cppreference**, bu kavramları şu şekilde açıklar:

### **1. Complete Type (Tam Tür)**
- **Complete type**, bellekte bir nesnenin boyutunun tamamen bilindiği bir türdür.
- Başka bir deyişle, derleyici türün bellek boyutunu ve düzenini (layout) bilir.

#### **Özellikler:**
- Bir nesne oluşturulabilir.
- İşlevlerde ve sınıf üyelerinde tam olarak kullanılabilir.

#### **Örnekler:**
- Yerleşik türler (örneğin `int`, `double`).
- Tam olarak tanımlanmış sınıflar, yapı (struct) ve birleşimler (union).

int x;  // int bir complete type'dır.
struct Point { 
    int x, y; 
}; 
Point p;  // Point bir complete type'dır.

### **2. Incomplete Type (Tamamlanmamış Tür)**
- **Incomplete type**, derleyicinin tür hakkında eksik bilgiye sahip olduğu bir türdür.
- Genellikle türün tam tanımı olmadan bir bildirimi mevcut olduğunda incomplete olarak kabul edilir.

#### **Özellikler:**
- Bellek boyutu bilinmez; dolayısıyla bir nesne yaratılamaz.
- Sadece sınırlı bağlamlarda kullanılabilir, örneğin bir işaretçi tanımlaması için.

#### **Örnekler:**

##### a. **Forward Declaration** (İleri Bildirim yada ön bildirim):

struct MyStruct;  // MyStruct bir incomplete type'dır.
MyStruct* ptr;    // İşaretçi tanımlamak geçerli, çünkü bellekte bir işaretçinin boyutu sabittir.

##### b. **Incomplete Array Types**:

extern int array[];  // Boyutu belirtilmediği için incomplete.

##### c. **Birleştirme veya Yapı Üyesi:**
Eğer bir tür kendi içinde tanımlı bir üye olarak bulunuyorsa, incomplete olabilir:

struct Node {
    Node* next;  // Node türü burada incomplete olarak işaretçi tanımlanabilir.
};

### **Incomplete Type Tamamlanması**
- Bir incomplete type, türün tam tanımı verildiğinde complete type hâline gelir.
- Örneğin:

struct MyStruct;         // Incomplete type.
struct MyStruct { int x; };  // Şimdi complete type.

### **Incomplete ve Complete Type Kullanım Alanları**
1. **Incomplete Type'ın Kullanıldığı Yerler:**
   - Header dosyalarında ileri bildirim (forward declaration) yaparak bağımlılıkları azaltmak.
   - İşaretçi veya referans tanımlamaları.

2. **Complete Type Gerektiren Yerler:**
   - Bir nesne tanımlamak:

     MyStruct obj;  // MyStruct complete type olmalı.

   - Bir türün boyutunu almak:

     sizeof(MyStruct);  // Complete type olmalı.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Class members

data member
non-static data members
static data members

member functon
non-static member function
static member function

type member/member type/nested type olarak 3 ada sahiptir

**Type member** (Tür üyesi), C++ dilinde bir sınıf, yapı (struct), veya birleşim (union) gibi bir tür içinde tanımlanan 
**bir tür (type)** ifadesidir. Bu tür üyeler genellikle sınıfların içinde özel ad alanları yaratmak veya tür bilgisi sağlamak amacıyla kullanılır.
* 
### **Type Member'ın Temel Anlamı**
Bir sınıf ya da yapı içinde bir tür tanımlandığında, bu bir **type member** olarak adlandırılır. 
Bu, kullanıcı tanımlı türler için bir tür alias (takma ad) veya başka bir tür bildirimi olabilir.

#### **Örnek:**

class MyClass {
public:
    using ValueType = int; // 'ValueType' bir type member'dır.
};

Bu örnekte:
- `ValueType` bir **type member** olarak tanımlanmıştır.
- Sınıfın bir üyesi olup, kullanıcı tarafından daha sonra `MyClass::ValueType` olarak erişilebilir.

### **Type Member Kullanımı**
Type member'lar genellikle aşağıdaki durumlarda kullanılır:

#### **1. Kullanıcı Tanımlı Türler İçin Alias (Takma Ad)**
Bir sınıfta, bir türün takma adı sağlanabilir:

class Container {
public:
    using ValueType = double; // Container içindeki öğelerin türü.
};
Container::ValueType val = 3.14;  // val, bir double türündedir.

#### **2. Şablonlar ile Kullanım**
Şablon programlamada type member'lar, türleri genel bir şekilde ifade etmek için kullanılır:

template <typename T>
class Wrapper {
public:
    using ValueType = T;  // T bir tür alias olarak atanır.
};

Wrapper<int>::ValueType a = 42; // a, bir int türündedir.

#### **3. İç Türler (Nested Types)**
Bir sınıfın içinde başka bir sınıf türü tanımlandığında, bu da bir **type member** olarak kabul edilir:

class Outer {
public:
    class Inner { };  // Inner, Outer'ın bir type member'ıdır.
};
Outer::Inner obj; // Inner türü kullanılır.

#### **4. `typedef` ile Kullanım**
`typedef`, bir type member tanımlamak için kullanılabilir:

struct Node {
    typedef int ValueType; // ValueType bir type member'dır.
};
Node::ValueType val = 10; // val, bir int türündedir.

### **Type Member ve Standart Şablonlar**
C++ Standard Template Library (STL) tür alias'larını yaygın olarak kullanır:

#include <vector>

std::vector<int>::value_type x = 10; // 'value_type' bir type member'dır.

Bu örnekte:
- `std::vector<int>` içinde tanımlı bir tür üyesi olan `value_type`, vektörün öğelerinin türünü belirtir (`int`).

### **Type Member ve Erişim**
- Type member'lar sınıfın diğer üyeleri gibi `public`, `protected`, veya `private` olabilir:

class MyClass {
private:
    using SecretType = int; // Yalnızca sınıf içinde kullanılabilir.
};

### **Sonuç**
Type member'lar, türlerin düzenlenmesi, şablon programlama ve büyük projelerde kod okunabilirliğini artırmak için önemli bir araçtır. 
Bunlar, bir sınıfın iç yapısını anlamayı ve türlerle çalışmayı kolaylaştırır.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Global functionlara / free functionda deniliyor / veya stand-alone function
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Classların non-static veri elemanları classtan yaratılan nesneye aittir
NOT:Member functionlar sınıfın storage değerini arttırmaz 
NOT:sizeof operatörü hiç bir tür için 0 değeri üretmez
NOT:class empty olsa bile sizeof değeri 1 olur
NOT:classların member functionları için re-decleration olmaz free functionlar re-decleration edilir

NOT:Sınıfın non-static member functionları implicit olarak sınıfın adresini alıyor

class Nec
{
public:
void foo(//Nec* gizli parametre);
};

int globalFoo(Nec*);

int main()
{
    Nec mynec;
    mynec.foo(//Nec* gizli olarak); // derleyici ürettiği kodda mynec nesnesini bu fonksiyonunun gizli parametre değişkenine adresini geçiyor &mynec
    globalFoo(&mynec); // global olarak böyle çağırırdık aynı assembly kodu üretilir fark yok
} 

******************************************************************************************************************************    


                                                                             ********* 9-DERS NOTLARI *********

NOT:Global fonksiyonlarda sınıftan pointer oluştursak bile sınıfın private bölümüne erişemeyiz 

class MyClass
{
private:
int x;
};


int func(MyClass *p)
{
	p->x; //sentaks error
}

--------------------------------------------------------------------------------------------------------------------------------------------------
Sınıftan global nesne oluşturulursa o sınıfa ait olduğu için private bölümüne yinede erişebilir

class MyClass
{
public:
void foo();

private:
int x;
};

Myclass g;
 
void MyClass::foo()
{
	g.x = 5;	
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Struct Data
{

}

void foo(Data* p); // mutator
void foo(const Data* p); //accessor

void foo(Data& p); // mutator
void foo(const Data& p); //accessor
--------------------------------------------------------------------------------------------------------------------------------------------------
1)
class MyClass
{
public:
    void foo()const; // const member function ve bunlar overloadingtir (const olan nesne ile çağırılır)
    void foo(); // non-const member function (const olmayan nesne ile çağırılır)

};

NOT:non-static fonksiyonun
    const üye fonksiyon olup olmaması sınıf nesnesinin veri elemanlarıyla doğrudan ilişkisi yoktur
    sınıf nesnesinin problem domainindeki anlamıyla ilgisi vardır yani const olsun mu olmasın mı
    kararı o fonksiyon sınıf nesnesinin durumunda bir değişiklik yapıyorsa o fonksiyon const member fucntion olmaması gerekir

NOT:Ama Sınıfın veri elemanını değiştiren bir fonksiyon const olabilir derleyicinin yaptığı kontrol ile bizim yazdığımız
kodun semantik karşılığı aynı olmak zorunda değil

NOT:Derleyici const member functionlara gizli olarak parametre geçiyor (implicit object parameter)
    class Nec  
    {
        public:
        void foo(//Nec*); // Nec* gizli parametre 
        void bar(//const Nec *)const; //const Nec * gizli parametre
    };

    void Nec::foo() 
    {
        mx = 5;
        p->mx = 5; // gizli parametre olduğu için aslında arka planda olan şey bu
    }

    void Nec::bar()const
    {
        mx = 5; // sentaks error
    }

 NOT: foo fonksiyonun içinde bar() fonksiyonu çağrılabilir burda const T* 'a dönüşüm oluyor

    ama bar() fonksiyonun içinde foo() fonksiyonunu çağırırsak burda const member function olduğu için
     T *'a dönüşüm gerçekleşmez SENTAKS ERROR
    
    Yani const member function sınıfın const üye olmayan fonksiyonunu çağıramaz çünkü const fonksiyondan (const T* dan T* a dönüşüm olmaz)
--------------------------------------------------------------------------------------------------------------------------------------------------
class Nec{
public:
void foo();
void bar()const;
};

int main()
{
	const Nec mynec; // Nec mynec olsaydı her ikisinide çağırabilirdik
	mynec.foo(); //sentaks hatası
	mynec.bar(); // valid

NOT:const nesne için sınıfın sadece const üye fonksiyonlarını çağırabiliriz 
	
}
--------------------------------------------------------------------------------------------------------------------------------------------------
2)sentaks ile semantiğin ayrıldığı yer 2 örnek

class Nec
{
public:
void bar()const;

private:
int *mp;

};

void Nec::bar()const
{
	*mp = 5; // sentaks olarak yanlış bir şey yok ama semantik olarak yanlış bir şey 
}

class Person
{
public:
    std::strint get_name()const;

private:
int m_debug_count = 0; // sentaks hatası vermeemesi için mutable int m_debug_count;
};

std::string Person::get_name()const
{
    ++m_debug_count; // semantik olarak yanlış bir şey yok ama sentaks olarak yanlış bir şey 
    çünkü get_name() fonksiyonun const Person * gizli bir parametresi var
}

m_debug_count data memberi mutable olarak değiştirildiğinde get_name() fonksiyonu içindeki
sentaks hatası giderilmiş olur

veri elemanını mutable ile bildirmek kodu okuyana ve derleyice bunun sınıf nesnesinin değerinin değişmesiyle alakası yok 
const üye fonksiyonlar içinde mutable anahtar sözcüğü olmasaydı hata verirdi
--------------------------------------------------------------------------------------------------------------------------------------------------
3)this keyword

nerede kullanılmaz;

global fonksiyon içinde kullanılması hata
sınıfın statik fonksiyonu içinde kullanılması hata

nerede kullanılır;

this pointer bir fonkisyon hangi nesne ile çağırılıyorsa o nesnenin adresi değerini kullanmış olur
yani this sınıf nesnesinin adresini temsil eder

this = nesnenin adresi
*this = nesnenin kendisi

NOT:this pointerın oluşturduğu ifade pr value expression

this = //sentaks error atama operatörünün operandı olamaz
&this // sentaks error adres operatörünün operandı olamaz
*this = //valid dereference edilebilir sınıf nesnesine başka bir nesneyi yada başka bir ifadeyi atayabiliriz

NOT:this pointerı low level const pointerdır

NOT:const member functionda this return edilmesi için geri dönüş değeri const  Myclass* olması gerek
veya Mycclass& için aynı kural geçerli

const Myclass* ()const // const Myclass şeklinde yazmasaydık return this ifadesi hata verirdi
{

	return this; 
}

const Myclass& ()const  
{

	return *this; 
}


class Myclass
{
public:
    void func();

};

void Myclass::func()
{
    std::cout<<"this -"<<this<<"\n"; 
}
 
int main()
{
    Myclass m;

    std::cout<<"&m - "<<&m<<"\n";
    
    m.func(); // m nesnesi ile func() fonksiyonunun adresleri aynı
}

NOT:this keyword mantığı

void fg1(Myclass *); 
void fg2(Myclass &);

void Myclass::func(int x) // func hangi nesne için çağırılmışsa o nesnenin adresiyle global fg1 fonksiyonuna çağrı yapmamız
gerekiyorsa yada func hangi nesne ile çağırılmışsa referans semantiği ile fg2 fonksiyonuna argüman olarak göndermemiz gerekiyorsa
    fg1(this);
    fg2(*this);
}

int main()
{
	Myclass m;
	m.func(12); // fonksiyon hangi nesne ile çağırılmışsa onun adresini ve nesnenin kendisini func ile aldık
}

NOT:sınıfın bazı member functionları yaptıkları işin neticesinde hangi nesne ile çağırılmışlarsa o nesnenin adresini 
yada o nesnenin kendisini döndürüyorlar

class Myclass
{
public:
    Myclass* foo(); // pointer ile hangi nesne ile çağırılmışsa onun adresi 
    Myclass& bar(); // l value referans ile hangi nesne ile çağırılmışsa nesnenin kendisini döndürür 

};

Myclass* Myclass::foo()
{
    return this;
}
Myclass& Myclass::bar()
{
    return *this;
}

int main()
{
    Myclass m;
    m.foo(); 
    m.bar();
}

6)this pointer kullanılma amacı

Şimdi şöyle bir soru soralım: Madem bir sınıfın üye işlevi içinde sınıf nesnesinin elemanlarına doğrudan
erişiliyor, o zaman neden this diye bir anahtar sözcük var? Üye işlev içinde sınıf nesnesinin adresinin elde
edilebilmesinin ne gibi faydaları olabilir? this
adresi bir üye işlev içinde aşağıdaki amaçlar için kullanılabilir:
1. Üye işlev hangi sınıf nesnesi için çağrılmışsa, o sınıf nesnesinin adresi, üye işlev tanımı içinde bir başka işleve
argüman olarak gönderilebilir:
class A {
public:
//...
void a_func();
private:
//...
};
void g_func(A *);
void A::a_func()
{
//...
g_func(this);
}

int main()
{
A a;
a.a_func();
return 0;
}
Yukarıdaki programda, A sınıfının a_func isimli üye işlevi içinde çağrılan g_func isimli global işleve, this
adresi argüman olarak gönderiliyor. main işlevi içinde tanımlanan A sınıfı türünden a nesnesi ile a_func üye
işlevi çağrıldığında, a nesnesinin adresi gizlice a_func işlevine geçirilir. Bu işlev içinden de, bu adres global
g_func işlevine gönderilir.
2. Üye işlev içinde, üye işlevi çağıran sınıf nesnesinin kendisine erişilebilir. Madem ki this
adresi üye işlevi çağıran sınıf nesnesinin adresidir, bu durumda
*this
ifadesi bu nesnenin kendisidir, değil mi? Aşağıdaki kodu inceleyin:
void g_func(A);
void A::a_func()
{
A a;
a = *this;
//...
g_func(*this);
}
int main()
{
A x;
x.a_func();
return 0;

}
A sınıfının a_func işlevi içinde tanımlanan A sınıfı türünden a nesnesine *this ifadesi atanıyor. main işlevi içinde
a_func işlevi x nesnesi ile çağrıldığından, a_func işlevi içindeki a ya x nesnesinin değeri atanıyor. Bu kez global
g_func isimli işlevin parametre değişkeninin A sınıfı türünden olduğunu görüyorsunuz. a_func üye işlevi içinde
çağrılan global g_func işlevine böylelikle main işlevi içindeki yerel x nesnesinin değeri aktarılmış olur.
3. Çağrılan bir üye işlev, hangi sınıf nesnesi için çağrılmışsa, o sınıf nesnesini ya da o sınıf nesnesinin adresini
geri döndürebilir. Bu durum ileride anlatılacak bazı araçlarda yoğun bir biçimde kullanılır. Aşağıdaki örneği
dikkatle inceleyin:
class A {
public:
//...
A a_func1();
A *a_func2();
A &a_func3();
private:
//...
};
A sınıfının üye işlevlerinden a_func1, A sınıf türünden bir değerle, a_func2 işlevi A sınıfı türünden bir adresle,
a_func3 işlevi ise A sınıfı türünden bir referansla geri dönüyor.
Şimdi bu işlevlerin tanımlarına bir bakalım:
A A::a_func1()
{
//...
return *this;
}
A *A::m_func2()
{
//...
return this;

}
A &A::m_func3()
{
//...
return *this;
}
a_func1 üye işlevi hangi sınıf nesnesi için çağrılmışsa, o sınıf nesnesinin değerini geri döndürür.
a_func2 üye işlevi hangi sınıf nesnesi için çağrılmışsa, o sınıf nesnesinin adresini geri döndürür.
a_func3 üye işlevi hangi sınıf nesnesi için çağrılmışsa, o sınıf nesnesinin kendisini geri döndürür.
4. this göstericisi, sınıf elemanlarının yerel değişkenler tarafından maskelenmesi durumunda, sınıf
elemanlarına erişmek amacıyla da kullanılır. Bu durum "sınıf bilinirlik alanı" başlığı altında incelenecek.
--------------------------------------------------------------------------------------------------------------------------------------------------
4)Chaining (Zincirleme), genellikle birden fazla fonksiyon çağrısını tek bir ifade içinde zincirleme şeklinde yazmayı ifade eder. 
Bu yöntem özellikle sınıf fonksiyonlarında, aynı nesne üzerinden birden fazla işlemi ardışık olarak gerçekleştirmek için kullanılır.

Chaining, genellikle üye fonksiyonların (member functions) her birinin kendi sınıf tipinde referans veya işaretçi döndürmesiyle mümkün olur.
Bu sayede, bir fonksiyon çağrısının sonucu başka bir fonksiyonun çağrısı için kullanılabilir. Zincirleme fonksiyon çağrıları, C++'ta temiz ve okunabilir bir kod yazmanıza yardımcı olur.

### **Chaining (Zincirleme) Fonksiyonları**

Bir sınıf içinde, fonksiyonların kendi nesnesini döndürmesiyle zincirleme yapılabilir. 
Bu, genellikle `return *this;` ifadesiyle gerçekleştirilir. `*this` ifadesi, mevcut nesnenin bir referansını döndürür.

#### **Örnek 1: Basit Zincirleme**
#include <iostream>

class MyClass {
public:
    MyClass& setA(int value) {
        a = value;
        return *this;  // Bu sayede zincirleme yapılabilir
    }

    MyClass& setB(int value) {
        b = value;
        return *this;
    }

    void print() {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }

private:
    int a;
    int b;
};

int main() {
    MyClass obj;
    obj.setA(10).setB(20).print();  // Zincirleme fonksiyon çağrısı

    return 0;
}

**Açıklama:**
- `setA()` ve `setB()` fonksiyonları, `MyClass` sınıfına ait üye değişkenlerin değerlerini ayarlamak için kullanılır.
- Bu fonksiyonlar `return *this;` ile mevcut nesnenin referansını döndürdükleri için, zincirleme çağrı yapılabilir.
- `obj.setA(10).setB(20).print();` ifadesi, hem `setA()`, hem `setB()` fonksiyonlarını ardışık olarak çağırır ve sonrasında `print()` fonksiyonu çalışır.

### **Örnek 2: Fluent Interface (Akıcı Arayüz)**

Zincirleme fonksiyonlar diğer ismiyle , **fluent interface (akıcı arayüz)** olarak bilinen bir tasarım deseniyle yaygın şekilde kullanılır. 
Bu desende, fonksiyonlar nesne üzerinde çalışmaya devam eder ve sonuç olarak yine o nesneyi döndürerek, başka işlemleri zincirlemeye imkan tanır.

#include <iostream>
#include <string>

class Person {
public:
    Person& setName(const std::string& name) {
        m_name = name;
        return *this;
    }

    Person& setAge(int age) {
        m_age = age;
        return *this;
    }

    void print() const {
        std::cout << "Name: " << name << ", Age: " << m_age << std::endl;
    }

private:
    std::string m_name;
    int m_age;
};

int main() {
    Person person;
    person.setName("Alice").setAge(30).print();  // Fluent Interface (akıcı arayüz)

    return 0;
}

**Açıklama:**
- `setName()` ve `setAge()` fonksiyonları, `Person` nesnesinin verilerini ayarlamak için kullanılır.
- Her iki fonksiyon da mevcut nesnenin referansını döndürdüğü için zincirleme yapılabilir.
- Bu, bir nesnenin özelliklerini daha temiz ve akıcı bir şekilde ayarlamamıza olanak sağlar.

### **Zincirleme (Chaining) ve Operatör Aşırı Yükleme (Operator Overloading)**

Zincirleme çağrılar, operatör aşırı yüklemeleri (operator overloading) ile de yapılabilir. Özellikle C++'ta `<<` ve `>>` gibi akış operatörleri zincirleme kullanılır.

#### Örnek: Akış Operatörü ile Zincirleme

#include <iostream>

int main() {
    std::cout << "Hello " << "World " << 123 << std::endl;  // Zincirleme
    return 0;
}

Bu örnekte, `std::cout` üzerinde `<<` operatörü aşırı yüklendiği için, zincirleme şeklinde birden fazla değer basılabilir. 
Bu işlemin arka planında, `<<` operatörü her seferinde `std::ostream&` döndürdüğü için zincirleme yapılabilmektedir.

### **Zincirleme Kullanımının Avantajları**
1. **Okunabilirlik**: Fonksiyonları ardışık olarak tek bir satırda çağırarak kodunuzu daha okunabilir ve temiz hale getirebilirsiniz.
2. **Kısa ve Akıcı Kod**: Her bir fonksiyon çağrısında ayrı satır yazmaktansa, zincirleme ile kodu kısaltabilirsiniz.
3. **Fluent Interface Deseni**: Bu desen, özellikle API veya kütüphane tasarımında, kullanıcıların işlemleri daha kolay ve doğal bir şekilde gerçekleştirmesine olanak tanır.

### **Sonuç**
C++'ta **chaining** (zincirleme), üye fonksiyonların aynı nesneye referans döndürmesiyle mümkün hale gelir ve fonksiyonların 
akıcı şekilde çağrılmasını sağlar. Bu, daha okunabilir ve düzenli kod yazmanıza olanak tanır ve özellikle sınıf tabanlı API'lerde sıkça kullanılır.
--------------------------------------------------------------------------------------------------------------------------------------------------
5)NOT:Fonksiyonu class içinde definiton yapılırsa implicit inline olarak ele alınır(örütülü olarak inline olma)

class MyClass
{
public:
    void set(int x) // default olarak inline
    {
        mx = x;
    }

private:
    int mx;

}

inline set(int x);

yada fonksiyonu inline yapıp tanımını yapabiliriz

inline void Myclass::set(int x)
{
	
}
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:constructor ve destructor statik veya global olamaz ve non const special member function olmak zorunda
 ******************************************************************************************************************************   

                                                                             ********* 10-DERS NOTLARI *********
 
 1)special member functions (özel üye fonksiyonlar), C++ dilinin belirli durumlarda otomatik olarak oluşturabildiği 
 veya geliştiricinin tanımlaması gereken önemli fonksiyonlardır. Bu fonksiyonlar, bir sınıfın nesneleri oluşturulurken, 
 kopyalanırken, taşınırken veya yok edilirken çağrılır. C++'ta beş adet özel üye fonksiyon bulunur:

1. **Default constructor (Varsayılan yapıcı)** MyClass()
2. **Destructor (Yıkıcı)** ~MyClass()
3. **Copy constructor (Kopya yapıcı)** MyClass(const MyClass& other)
4. **Copy assignment operator (Kopya atama operatörü)** MyClass& operator=(const MyClass& other)
5. **Move constructor (Taşıma yapıcı)** MyClass(MyClass&& other) 
6. **Move assignment operator (Taşıma atama operatörü)** MyClass& operator=(MyClass&& other)

### 1. **Default Constructor (Varsayılan Yapıcı)**
- Bu, sınıftan bir nesne oluşturulduğunda çağrılan yapıcıdır ve nesneyi default değerlerle başlatır. 
Eğer sınıf içinde başka bir yapıcı tanımlanmamışsa, derleyici bu fonksiyonu otomatik olarak oluşturur.
  
#### Örnek:

class MyClass {
public:
    MyClass() = default;  // Varsayılan yapıcı user declared edilmiş ama yinede derleyici yazıyor
};

- Eğer sınıf içinde hiçbir constructor tanımlanmadıysa, C++ derleyicisi otomatik olarak bir **default constructor** oluşturur.
- Ancak, sınıf içinde başka yapıcılar tanımlanırsa, default constructor otomatik olarak oluşturulmaz ve gerekirse manuel olarak tanımlanmalıdır.

### 2. **Destructor (Yıkıcı)**
- Bir sınıfın nesnesi bellekte serbest bırakıldığında veya yaşam döngüsü sona erdiğinde çağrılan fonksiyondur. 
Bellek yönetimi veya kaynakların temizlenmesi gerektiğinde kullanılır.
  
#### Örnek:

class MyClass {
public:
    ~MyClass() { 
        // Bellek temizleme, dosya kapatma gibi işlemler
    }
};

- Eğer bir sınıf için bir destructor tanımlanmazsa, derleyici otomatik olarak defualt bir destructor oluşturur.
- Bu destructor sınıfın veri üyelerine özel işlemler yapmaz; sadece nesnenin ömrünün sonunda çağrılır.

### 3. **Copy Constructor (Kopya Yapıcı)**
- Bir nesne, başka bir nesneden kopyalandığında çağrılan constructordır. Bu genellikle, 
bir nesnenin başka bir nesne ile başlatılması veya geçici nesnelerin oluşturulması sırasında çağrılır.
  
#### Örnek:

class MyClass {
public:
    MyClass(const MyClass& other) {
        // 'other' nesnesinden kopyalama işlemleri
    }
};

- Eğer copy consturctor tanımlanmazsa, derleyici her veri üyesi için **shallow copy** (yüzeysel kopyalama) gerçekleştiren bir default copy consturctor oluşturur.
- Eğer sınıf dinamik belleği veya başka kaynakları yönetiyorsa, copy consturctorı kendiniz tanımlamanız gerekir. Aksi halde, derleyicinin 
varsayılan kopya işlemi yetersiz kalabilir ve bellek sızıntılarına (memory leak) neden olabilir.

### 4. **Copy Assignment Operator (Kopya Atama Operatörü)**
- Bir nesne, başka bir nesneye kopya yoluyla atandığında çağrılan operatördür. 
Yani, bir nesne daha önceden oluşturulmuş bir başka nesneye eşitlendiğinde devreye girer.
  
#### Örnek:

class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        // Kopya atama işlemleri
        return *this;
    }
};

- Eğer bu operatör tanımlanmazsa, derleyici otomatik olarak shallow copy yapan bir varsayılan atama operatörü oluşturur.
- Eğer sınıfın içinde dinamik bellek gibi kaynaklar varsa, bu operatörü kendiniz tanımlayarak derin kopyalama (deep copy) yapmanız gerekebilir.

### 5. **Move Constructor (Taşıma Yapıcı)**
- Bir nesne, başka bir nesneden taşındığında çağrılan constructordır. Taşıma yapıcı, kopyalamak yerine bir nesnenin iç kaynaklarını 
diğer nesneye "taşır". Bu, özellikle geçici nesnelerle veya kaynakları çok olan sınıflarda performans avantajı sağlar.
  
#### Örnek:

class MyClass {
public:
    MyClass(MyClass&& other) noexcept {
        // other nesnesinin kaynaklarını bu nesneye taşıma işlemleri
    }
};

- Taşıma yapıcı, nesnenin kaynaklarını kopyalamak yerine sahipliği transfer eder, bu da daha verimli bellek ve performans kullanımı sağlar.
- Eğer sınıfın içinde pointer'lar veya başka kaynaklar yönetiliyorsa, move contructor tanımlamak performans açısından önemlidir.

### 6. **Move Assignment Operator (Taşıma Atama Operatörü)**
- Bir nesne başka bir nesneye atandığında ve kaynakları kopyalamak yerine taşımak istediğimizde bu operatör devreye girer.
  
#### Örnek:

class MyClass {
public:
    MyClass& operator=(MyClass&& other) noexcept {
        // Kaynakları other'dan bu nesneye taşı
        return *this;
    }
};

- Kopyalamak yerine nesnenin kaynaklarını taşır. Bu, özellikle nesnelerin taşındığı ve artık kaynaklarını kullanmadığı durumlarda faydalıdır (örneğin geçici nesneler).
- **noexcept** anahtar kelimesi, bu fonksiyonun istisna atmaması gerektiğini belirtir. Bu, move semantiğinde performans optimizasyonları sağlar.

### **Özet**
C++'taki **special member functions**'lar, sınıfın davranışını ve bellek yönetimini şekillendiren temel fonksiyonlardır. Eğer bu fonksiyonlardan 
herhangi biri tanımlanmazsa, derleyici varsayılan bir sürümünü sağlar. Ancak, dinamik bellek veya dış kaynakların yönetildiği 
sınıflarda bu fonksiyonları manuel olarak tanımlamak önemlidir. Bu fonksiyonların doğru kullanımı, özellikle kopyalama ve taşıma işlemlerinin performansı açısından kritik rol oynar.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 2)**Static Initialization Fiyaskosu** (Static Initialization Order Fiasco), C++'ta **global veya statik** 
 değişkenlerin başlatılma sırasındaki bir soruna verilen isimdir. Bu problem, farklı çevirim birimlerinde (translation units) 
 tanımlanmış statik veya global değişkenlerin başlatılma sırasının belirlenemez olmasından kaynaklanır. Bu durum, 
 programın belirli kısımlarında beklenmeyen davranışlara ve hatalara yol açabilir.

### **Sorunun Kökeni**
C++'ta global ve statik ömürlü değişkenler, programın başlatılması sırasında, genellikle `main()` fonksiyonu çağrılmadan önce başlatılır. 
Ancak, bu değişkenler farklı çevirim birimlerinde tanımlanmışlarsa, bunların başlatılma sırası **derleyici tarafından garanti edilmez**. 
Yani, bir çevirim birimindeki global bir değişken, başka bir çevirim biriminde tanımlı bir global değişkene bağımlıysa, 
doğru sırada başlatılmadıkları için program çalışırken istenmeyen sonuçlar doğabilir.

### **Örnek: Static Initialization Fiyaskosu**

İki farklı çevirim biriminde (örneğin, iki farklı `.cpp` dosyasında) şu tür bir durum olduğunu varsayalım:

// file1.cpp
#include <iostream>

struct A {
    A() { std::cout << "A initialized\n"; }
    void print() const { std::cout << "A\n"; }
};

extern A a;

// file2.cpp
#include <iostream>

struct B {
    B() { std::cout << "B initialized\n"; a.print(); }  // a henüz başlatılmamış olabilir!
};

A a;  // file1.cpp'deki A nesnesi
B b;  // file2.cpp'deki B nesnesi

// main.cpp
int main() {
    return 0;
}

Bu örnekte, `file2.cpp`'de `B` sınıfı oluşturulurken `a.print()` çağrılıyor, fakat `a` henüz başlatılmamış olabilir. 
Başlatılma sırası belirsiz olduğu için `a`'ya erişildiğinde hatalı bir davranış veya program çökmesi gerçekleşebilir.

### **Static Initialization Fiyaskosunu Engelleme Yolları**

1. **Meyers' Singleton Pattern Kullanımı**:
   Global ve statik değişkenleri güvenli bir şekilde başlatmak için, **Meyers' Singleton** kullanımı önerilir. Bu yöntem, 
   statik bir değişkeni bir fonksiyon içinde tanımlayarak, bu değişkenin ilk erişimde başlatılmasını garanti eder 
   (C++11 ve sonrası ile birlikte, statik değişkenler thread-safe bir şekilde başlatılır).

   **Örnek**:

   class A {
   public:
       static A& getInstance() {
           static A instance;  // İlk çağrıda güvenli bir şekilde başlatılır
           return instance;
       }
       void print() const { std::cout << "A\n"; }
   private:
       A() { std::cout << "A initialized\n"; }
   };

   class B {
   public:
       B() {
           A::getInstance().print();  // Artık güvenli bir şekilde çağrılır
       }
   };

   B b;

2. **Değişkenleri Fonksiyonlarda Tanımlama**:
   Global veya statik değişkenleri doğrudan global alanda tanımlamak yerine, bunları bir fonksiyonun içinde tanımlamak, başlatılma sırasını kontrol etmenizi sağlar.

   **Örnek**:

   A& getA() {
       static A a;
       return a;
   }

   B::B() {
       getA().print();  // getA() ilk çağrıldığında a'yı başlatır
   }

3. **Bağımlılıkları Sınırlama**:
   Statik değişkenler arasında bağımlılıkları mümkün olduğunca sınırlandırarak, bu tür fiyaskoların ortaya çıkmasını 
   önlemek de bir başka çözümdür. Bu sayede başlatılma sırası daha az önemli hale gelir.

### **Sonuç**
**Static Initialization Fiyaskosu**, C++'ta global veya statik ömürlü değişkenlerin farklı çevirim birimlerinde başlatılma
sırasının belirlenememesi nedeniyle oluşan bir sorundur. Bu fiyasko, programın beklenmedik davranışlar sergilemesine veya çökmelere yol açabilir. 
Bu sorunu çözmek için Meyers' Singleton, fonksiyon içinde statik değişkenler veya başlatma bağımlılıklarını azaltma gibi teknikler kullanılabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Static yerel sınıf nesneleri veya değişkenler initializition thread safetir 10 tane thread çalıştırsa
hala fonksiyonun 1 kere hayata gelmesi garanti altında
--------------------------------------------------------------------------------------------------------------------------------------------------
 3)delete bildirimi böyle bir fonksiyonun var olduğunu ama çağırılması durumunda sentaks hatası olacağını söyler

 void foo(int) = delete;
 void foo(double);
 void foo(long);

 int main()
 {
    foo(34); // sentaks hatası
 }
 --------------------------------------------------------------------------------------------------------------------------------------------------
 4)default bildirimi ile special memeber functionsları bildirirsek fonksiyonların derleyici tarafından yazılamasını talep etmiş oluruz
 NOT:default bildirimini yalnızca Special member functionslar için yapabiliriz delete bildirimi için böyle bir kısıtlama yok
1. **Default constructor (Varsayılan yapıcı)**
2. **Destructor (Yıkıcı)**
3. **Copy constructor (Kopya yapıcı)**
4. **Copy assignment operator (Kopya atama operatörü)**
5. **Move constructor (Taşıma yapıcı)**
6. **Move assignment operator (Taşıma atama operatörü)**
 --------------------------------------------------------------------------------------------------------------------------------------------------
 5)
NOT:Constructor nokta operatünün yada ok operatörünün operandı olamaz ama destructor olur ama yanlıştır 
placement new ile ilgili özel bir durumda kullanılıyor(undefined behaviour oluşturduğu durum var)
 
 not declerad(bildirilmemiş)

user defined declared(programcı tarafından bildirilen)

class Nec
{
   public:
   Nec(); // user declared
   Nec() = default; // user declared çünkü bildirimi biz yapıyoruz
   Nec() = delete; // user declared 
}

implicitly declared(derleyici tarafından örtülü şekilde)
   default
   delete

NOT:Derleyici dilin kurallarına göre bir speacial member functionu implicitly declare ediyorsa
derleyicini yazdığı special member function her zaman sınıfın non-static public inline member
functionudur

class Nec
{
    public:
    //default ctor -> implicitly declared
    //default destructor -> implicitly declared

    burda herhangi bir bildirim yapmadığımız için implicitly declared ve
    special member function non-static public inline member functiondur
}

NOT:derleyici impilictly declare ettiği bir special member functionu tanımlama sürecinde dilin kurallarını çiğeneyen
bir durum oluşursa default etmesi gereken special member functionu delete eder

class Nec
{
    public:
    const int x; //initialize edilmesi gerekirdi
};

int main()
{
    Nec mx;//sentaks hatası derleyici ctoru delete eder çünkü const bir değere her zaman ilk değer verilmesi gerekir 
}

class olmasaydı const int x sentaks hatası olurdu ama class içinde olduğu için 
x direkt olarak hata vermiyor ama mainde nesne yaratmaya açlıştığımızda default ctor
delete edilmiş durumda 
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Nec ar[10] //sınıftan 10 elemanlı bir dizi tanımlamak için default ctor gerekir
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **Member Initializer List (MIL) yada Conctructor Initializer List**, bir sınıfın yapıcı fonksiyonunda (constructor) üye değişkenlerin 
başlangıç değerlerini atamak için kullanılan bir sentaks yapısıdır. **MIL**, üye değişkenlerin atamalarını 
doğrudan yapıcı fonksiyonun gövdesi yerine, başlangıç listesi kısmında tanımlamaya olanak tanır.

NOT:Sınıfın non-static veri elemanları için birinci tercih MIL sentaksı olmalı
NOT:Sınıfın tüm non-static veri elemanları MIL ile initialize edilmesi gerekmez ama bazı
durumlarda default initialize edilmeye çalışılması sentaks hatasına sebep olur aşağıda örnekleri verildi

### **Sentaks**
Member Initializer List, şu şekilde yazılır:

class MyClass {
    int a;
    double b;
public:
    MyClass(int x, double y) : a(x), b(y) {
        // Yapıcı gövdesi (isteğe bağlı)
    }
};

Burada `: a(x), b(y)` kısmı MIL'dir.

### **Neden Kullanılır?**

MIL kullanımı aşağıdaki durumlarda gereklidir veya önerilir:

#### **1. Sabit Üye Değişkenleri (const Members)**
`const` olarak tanımlanan üye değişkenler, yalnızca ilk tanımlandıklarında bir değer alabilir. 
MIL kullanılmazsa, bu üyelere bir değer atamak mümkün değildir.

class MyClass {
    const int a;
public:
    MyClass(int x) : a(x) {} // MIL ile a'yı başlatıyoruz.
};

Eğer MIL kullanılmazsa, aşağıdaki kod derlenemez:

class MyClass {
    const int a;
public:
    MyClass(int x) {
        a = x; // HATA! const üye değişkenler atama ile değiştirilemez.
    }
};

#### **2. Referans Üyeler (Reference Members)**
C++'ta referans üye değişkenleri, yalnızca tanımlandıkları sırada bağlanabilir. 
Sonradan bağlanmaları mümkün değildir. MIL, referans üyeleri başlatmak için gereklidir.

class MyClass {
    int& ref;
public:
    MyClass(int& x) : ref(x) {} // ref, x'e bağlanıyor.
};

#### **3. Taban Sınıf Yapıcılarını Çağırma (Base Class Constructor Call)**
Bir derived sınıf, base sınıfın bir constructorını çağırmak zorundadır. Bu çağrı yalnızca MIL içinde yapılabilir.

class Base {
    int value;
public:
    Base(int x) : value(x) {}
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) {} // Base sınıf yapıcısı çağrılıyor.
};

#### **4. Üye Nesnelerin Yapıcılarını Çağırma**
Bir sınıfın memberı başka bir sınıfın türündeyse, bu memberın constructorı doğrudan çağrılmalıdır. MIL olmadan, bu mümkün değildir.

class Member {
    int value;
public:
    Member(int x) : value(x) {}
};

class MyClass {
    Member m;
public:
    MyClass(int x) : m(x) {} // Member sınıfının yapıcısı çağrılıyor. 
};

#### **5. Performans Avantajı**
MIL, üye değişkenleri doğrudan başlatır ve constructor çağırılmadan önce değerleri geçer.
Eğer yapıcı gövdesinde atama yaparsanız, önce üye değişken varsayılan olarak başlatılır, 
ardından bir değer atanır. Bu da gereksiz bir maliyet oluşturur.

##### MIL ile:

class MyClass {
    int a;
public:
    MyClass(int x) : a(x) {} // Doğrudan başlatma.
};

##### MIL olmadan:

class MyClass {
    int a;
public:
    MyClass(int x) {
        a = x; // Önce ctor hayata gelir, sonra atama yapılır.
    }
};

Bu, özellikle karmaşık türler (örneğin bir `std::vector`) için performans farkı yaratır.

### **Cppreference'a Göre MIL Kullanımı**
Cppreference'da **MIL**, üye değişkenlerin nasıl başlatılacağına dair ayrıntılı bilgiler içerir. Özetle:
- MIL, sınıf üyelerinin doğrudan başlatılmasını sağlar.
- Bazı türler (const, reference) için gerekli bir yapı taşıdır.
- Performans açısından daha etkilidir.

C++'ta **Member Initializer List (MIL)**, birçok durumda üye değişkenlerin başlatılması için tercih edilir. 
Ancak bazı durumlarda MIL kullanımı mümkün veya uygun olmayabilir. İşte MIL'in kullanılmadığı veya kullanılmaması gereken durumlar:

### **1. Üye Değişken Varsayılan Başlatma Gerektiriyorsa**
Eğer üye değişken varsayılan bir değere sahip olacaksa ve bu değer parametreden bağımsızsa, yapıcı gövdesinde atama yapmak yeterlidir.

**Örnek:**

class MyClass {
    int a;
public:
    MyClass() { a = 10; } // a her zaman 10 olarak başlatılacak.
};

Bu durumda MIL kullanımı gerekli değildir, çünkü üye `a` için sabit bir başlangıç değeri atanacaktır.

### **2. Karmaşık Mantık Gerektiriyorsa**
Eğer üye değişkenlerin başlatılması için karmaşık bir mantık gerekiyorsa (örneğin, bir döngü, koşul veya hesaplama), 
MIL yerine yapıcı gövdesinde başlatma yapmak daha pratiktir.

**Örnek:**

class MyClass {
    int a;
public:
    MyClass(int x) {
        if (x > 0) {
            a = x;
        } else {
            a = 1;
        }
    }
};

Bu tür durumlarda MIL ile karmaşık mantık yazmak zor olabilir ve okunabilirliği azaltabilir.

### **3. Dinamik Bellek Yönetimi İçin**
Eğer bir üye değişkenin değeri, yapıcı sırasında dinamik olarak oluşturulacaksa, MIL kullanımı yerine yapıcı 
gövdesinde bellek ayırma işlemi yapmak daha uygundur.

**Örnek:**

class MyClass {
    int* ptr;
public:
    MyClass(int x) {
        ptr = new int[x]; // Bellek yapıcı gövdesinde ayrılıyor.
    }
};

### **4. Başlatma Sırası Önemliyse**
Üye değişkenlerin başlatılma sırasını kesin olarak kontrol etmek gerekiyorsa ve bu sıra taban sınıfların veya 
diğer üye nesnelerin başlatılmasıyla çakışıyorsa, MIL yerine yapıcı gövdesinde işlem yapmak gerekebilir.

**Not:** Normalde MIL, üye değişkenlerin sınıf tanımındaki sırasına göre başlatılır. Ancak bu bazen sorun çıkarabilir.

### **5. Varsayılan veya Geçici Atama Kullanılıyorsa**
Eğer bir üye değişken yapıcı sırasında kesin bir başlangıç değerine ihtiyaç duymuyorsa (örneğin, daha sonra bir 
fonksiyon çağrısı ile değer atanacaksa), yapıcı gövdesinde atama yapmak tercih edilebilir.

**Örnek:**

class MyClass {
    int a;
public:
    MyClass() {
        // a, daha sonra bir fonksiyon çağrısı ile atanacak.
        setA(42);
    }

    void setA(int x) { a = x; }
};

### **Cppreference Perspektifi**
Cppreference’a göre MIL, üye değişkenlerin doğrudan başlatılmasını önerir çünkü:
- Performans açısından daha iyidir (varsayılan başlatmayı önler).
- `const` ve referans türündeki üyeler için gereklidir.

Ancak yukarıdaki gibi durumlarda MIL’in kullanılmaması da doğru bir yaklaşım olabilir.

### **Özet**
MIL şu durumlarda kullanılmaz:
1. **Sabit değer gerekmiyorsa veya parametre bağımsızsa.**
2. **Karmaşık mantık ve koşullar gerekiyorsa.**
3. **Dinamik bellek yönetimi yapılıyorsa.**
4. **Başlatma sırası özel bir anlam taşıyorsa.**
5. **Üye değişkenlerin ilk değeri constructordan sonra atanacaksa.**

Bu durumlarda constructor gövdesinde işlem yapmak daha mantıklıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:MIL sentaksında değerlerin intialize edilmesi hangisi daha önce bildirlmişse o sırayla olur

class Nec{
public:
    Nec() my(10),mx(my / 3){} // mx daha önce bildirildiği için burdaki sıra önemsizdir bildirim sırası önemlidir 
    bu tarz durumlar UNDEFINED BEHAVIOURA SEBEB OLABİLİR çünkü my değikeni garbage value
    private:
    int mx,my;
}
--------------------------------------------------------------------------------------------------------------------------------------------------
6)Default member initializer/veya in class initializer (eski cpp de yok)

MIL ile initialize edilmezse default olarak bu değerleri kullanacağı anlamına gelir MIL kullanılırsa öncelik MIL de

class Point
{
public: 

private:
    int x = 0;
    int y = 0;
}

class içinde direct initialization kullanılamıyor

    int x(0); // sentaks hatası
    int y(0); // sentaks hatası
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT: Sınıfın kendi türünden veri elemanı olamaz ama pointer yada referans türü olabilir

 class Myclass
 {
    Myclass m; // hata static olsaydı hata vermezdi
 }
--------------------------------------------------------------------------------------------------------------------------------------------------
7)Placement `new`, C++'ta bir nesneyi, bellekte belirli bir adrese yerleştirerek başlatmak için kullanılan bir mekanizmadır. 
Bu, standart `new` operatöründen farklıdır çünkü placement `new`, belleği ayırmaz; bunun yerine, daha önce ayrılmış bir 
belleği kullanır ve o bellekte bir nesne inşa eder.

### **Placement `new` Nasıl Çalışır?**

Placement `new`, standart `new` gibi heap'ten (yığın) bellek tahsis etmek yerine, hali hazırda var olan bir bellek bloğunu kullanır. 
Bu, bellek yönetimi üzerinde daha fazla kontrol sahibi olmayı sağlar ve belirli durumlarda performans kazancı elde etmek için kullanılabilir.

### **Sözdizimi**

void* operator new (std::size_t, void* place) noexcept;

- `std::size_t` -> Nesnenin boyutunu belirtir.
- `place` -> Nesnenin yerleştirileceği bellek adresidir.

Bu overload, bir bellek alanı sağlandığında o bellekte nesne oluşturur ve belleği tahsis etmez.

### **Örnek Kullanım**

#include <iostream>
#include <new>  // Placement new için gerekli

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructor\n"; }
    ~MyClass() { std::cout << "MyClass destructor\n"; }
};

int main() {
    // Bellek bloğunu ayıralım (örneğin bir buffer):
    alignas(MyClass) char buffer[sizeof(MyClass)];  // Uygun hizalama ile bellek bloğu

    // Placement new ile bellekte nesne oluşturalım:
    MyClass* obj = new (buffer) MyClass;  // 'buffer' içine yerleştirilmiş bir nesne

    // Nesneyle işlem yapabiliriz:
    // ...

    // Nesneyi manuel olarak yıkmamız gerekiyor:
    obj->~MyClass();  // Destructor'u manuel olarak çağırmak gerekli

    return 0;
}

#### Adımlar:
1. **Bellek ayırma**: `buffer` adında, `MyClass` nesnesinin boyutuna uygun bir char dizisi kullanarak bellek bloğu ayırıyoruz. `alignas` ile hizalama şartlarına uyduğumuzdan emin oluyoruz.
2. **Placement `new` kullanımı**: `new (buffer) MyClass` ifadesi ile `MyClass` nesnesini `buffer` içerisine yerleştiriyoruz. Normal 
`new`'den farklı olarak, bu işlem heap'ten bellek tahsis etmiyor, sadece var olan `buffer`'ı kullanıyor.
3. **Nesne yıkımı**: Placement `new` ile oluşturduğumuz nesnelerin ömrü sona erdiğinde, destructor'ı manuel olarak çağırmamız gerekiyor (`obj->~MyClass()`).

### **Placement `new` Kullanım Alanları**
- **Özel bellek yönetimi**: Heap'ten bellek tahsis etmek yerine belirli bir bellek alanını kullanmak gerektiğinde (örneğin gömülü sistemlerde veya yüksek performans gerektiren uygulamalarda).
- **Önceden ayrılmış bellek blokları**: Birden çok nesneyi aynı bellekte yerleştirmek veya sabit bellek alanlarını kullanmak için.
- **Custom allocators**: Özelleştirilmiş bellek ayırıcılar yazmak ve bellek tahsis işlemlerini kontrol etmek için.

### **Placement `new` ve Destructor**
Placement `new` ile oluşturulan nesnelerin ömrü sona erdiğinde, destructor'ın manuel olarak çağrılması gerektiği unutulmamalıdır. 
Bellek tahsisi `new` ile yapılmadığından, `delete` ile bellek serbest bırakılamaz. Bunun yerine, sadece nesnenin destructor'ı çağrılır.

#### Destructor Çağırma:

obj->~MyClass();  // Manuel destructor çağrısı

### **Placement `new` Kullanımında Dikkat Edilmesi Gerekenler**
- **Bellek Ayırma**: Placement `new` bellek ayırmadığı için, önceden tahsis edilen belleğin yeterli büyüklükte ve doğru hizalamada olduğundan emin olmanız gerekir.
- **Destructor Çağırma**: Placement `new` ile oluşturulan nesnelerin destructor'ı manuel olarak çağrılmalıdır. Bu işlemin unutulması, bellek sızıntısına veya tanımsız davranışa yol açabilir.
- **Bellek Yönetimi Karmaşıklığı**: Placement `new`, özellikle manuel bellek yönetimi gerektirdiği için daha karmaşık ve hata yapma ihtimali yüksektir. Bu nedenle dikkatli kullanılmalıdır.

### **Sonuç**
Placement `new`, C++'ta bellek yönetimi üzerinde daha fazla kontrol sağlamak ve belirli bellek alanlarında nesneler oluşturmak 
için kullanılan güçlü bir tekniktir. Özellikle performansın önemli olduğu durumlarda ve özel bellek ayırma stratejileri için kullanışlıdır. 
Ancak, manuel destructor çağrılması ve bellek hizalaması gibi detaylar göz önünde bulundurulmalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:bir veri türü ya incomplete typetır yada complete type
--------------------------------------------------------------------------------------------------------------------------------------------------
8)C++'ta **dependency oluşması**, bir nesnenin, sınıfın ya da modülün başka bir nesneye, sınıfa ya da modüle 
bağımlı hale gelmesi anlamına gelir. Bu, genellikle bir sınıfın veya fonksiyonun başka bir sınıfın veya fonksiyonun 
varlığına, davranışına veya durumuna ihtiyaç duyduğu durumlarda ortaya çıkar. **Dependency** kavramı, yazılım geliştirmede 
önemli bir tasarım konusu olup kodun okunabilirliği, test edilebilirliği ve yeniden kullanılabilirliği üzerinde büyük etkiler yaratabilir.

### **Dependency Çeşitleri**
C++'ta **dependency oluşumu** şu şekillerde gerçekleşebilir:

#### 1. **Statik Bağımlılıklar (Compile-Time Dependency)**
Bir sınıf veya fonksiyon, başka bir sınıfın veya fonksiyonun tanımını **derleme zamanında** bilmek zorundadır. 
Bu durum genellikle bir başlık dosyasının (`.h`) diğerine dahil edilmesiyle oluşur.

**Örnek:**
#include <iostream>

class Dependency {
public:
    void performTask() {
        std::cout << "Dependency Task Executed!" << std::endl;
    }
};

class Dependent {
    Dependency dep; // Dependency sınıfına bağımlılık
public:
    void doWork() {
        dep.performTask();
    }
};

int main() {
    Dependent d;
    d.doWork();
    return 0;
}

Burada, `Dependent` sınıfı, `Dependency` sınıfına bağımlıdır çünkü `Dependency` olmadan çalışamaz.

#### 2. **Dinamik Bağımlılıklar (Runtime Dependency)**
Bir sınıf veya fonksiyon, başka bir nesnenin veya kaynağın **çalışma zamanında** sağlanmasına ihtiyaç duyar. 
Bu genellikle bağımlılığın dinamik olarak sağlanmasıyla gerçekleşir.

**Örnek:**

#include <iostream>

class Dependency {
public:
    void performTask() {
        std::cout << "Runtime Dependency Task Executed!" << std::endl;
    }
};

class Dependent {
    Dependency* dep; // Dependency'yi dinamik olarak tutar
public:
    Dependent(Dependency* d) : dep(d) {}
    void doWork() {
        if (dep) {
            dep->performTask();
        }
    }
};

int main() {
    Dependency d;
    Dependent obj(&d); // Dependency enjekte ediliyor
    obj.doWork();
    return 0;
}

Bu tür bağımlılıklar, **Dependency Injection (Bağımlılık Enjeksiyonu)** ile yönetilebilir.

### **Dependency’nin Getirdiği Sorunlar**
Bağımlılıklar kontrolsüz bırakıldığında şu sorunlara neden olabilir:

1. **Sıkı Bağımlılık (Tight Coupling):**
   - Bir sınıfın, başka bir sınıfa çok sıkı bağlanması, kodun esnekliğini ve yeniden kullanılabilirliğini azaltır.
   - Statik bağımlılık bu durumu kötüleştirebilir.

2. **Değişiklik Etkileri:**
   - Bağımlı olunan bir sınıfta yapılan değişiklikler, bağımlı sınıfı da etkiler ve bu da domino etkisi yaratabilir.

3. **Test Edilebilirlik Sorunları:**
   - Bağımlı sınıfı test etmek zorlaşır, çünkü bağımlı olunan sınıfın varlığı veya durumu test sırasında sorun çıkarabilir.

### **Dependency Yönetimi Teknikleri**
Bağımlılıklarınızı kontrol etmek ve yönetmek için aşağıdaki yöntemler kullanılabilir:

#### 1. **Dependency Injection (Bağımlılık Enjeksiyonu)**
Bağımlılıkların, sınıfın yapıcısı veya bir setter fonksiyonu aracılığıyla sağlanmasıdır. 
Bu, bağımlılıkların dinamik olarak yönetilmesini sağlar.

**Örnek:**

class Dependency {};
class Dependent {
    Dependency* dep;
public:
    Dependent(Dependency* d) : dep(d) {}
};

#### 2. **Abstract Interfaces (Soyut Arayüzler)**
Bir sınıfın doğrudan başka bir sınıfa bağımlı olmaması için soyut sınıflar kullanılır.

**Örnek:**

class IDependency {
public:
    virtual void performTask() = 0;
};

class ConcreteDependency : public IDependency {
public:
    void performTask() override {
        std::cout << "Concrete Task!" << std::endl;
    }
};

class Dependent {
    IDependency* dep;
public:
    Dependent(IDependency* d) : dep(d) {}
    void doWork() { dep->performTask(); }
};

#### 3. **Loose Coupling (Gevşek Bağlantı)**
Sınıflar arasında gevşek bir bağ oluşturularak bağımlılıklar minimuma indirilir. 
Örneğin, bağımlılık bir `std::shared_ptr` veya `std::unique_ptr` ile tutulabilir.

### **Cppreference Bağlamında Dependency**
Cppreference, bağımlılıklar hakkında doğrudan bir kavramsal açıklama sunmaz; ancak, **include directive**, 
**forward declaration**, ve **polymorphism** gibi araçlar bağımlılıkları kontrol etmek için kullanılan mekanizmalardır. 

### **Özet**
Dependency oluşması, bir sınıfın başka bir sınıfa ihtiyaç duymasıdır. Bu bağımlılıklar:
- **Statik** (derleme zamanı) ya da 
- **Dinamik** (çalışma zamanı) olabilir. 

**İyi yönetilmemiş bağımlılıklar**, kodun bakımını ve testini zorlaştırabilir. **Dependency Injection** ve 
**Soyut Arayüzler** gibi teknikler bu sorunları çözmek için kullanılabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Bir nesnenin türü void olamaz ama bir expressionun türü void olabilir

void func();

int main()
{
    func();
}
--------------------------------------------------------------------------------------------------------------------------------------------------
static cast operatörüyle yada c style cast operatörüyle cast etderek olur
--------------------------------------------------------------------------------------------------------------------------------------------------
void ile geri dönüş değerini discard etmek yani geri dönüş değerini kullanmamak

(void)getchar(); // normalde geri dönüş değer int
******************************************************************************************************************************  

                                                                             ********* 11-DERS NOTLARI *********
 1)copy semantics

 Kopyalama semantiği ne demek:
 bir nesneyi bir başka nesnesinin değeriyle hayata getiriyoruz ya da bir nesneye bir başka nesnenin değerini atıyoruz
 eğer eşitlik karşılaştırmasına tabiiyse bu durumda 2 sonuç doğuyor

 1.nesneler birbirinden bağımsız yani bu nesnelerin biri üzerinde yapılan işlemler diğerini etkilemicek yani 
 kopyalamadan sonra bu nesnelerin birbiriyle ilişkisi kalmıyor
 
 2.bu nesneler (equality comparable) karşılaştırılırsa eşit olucak yani true değeri verir

 NOT:Derleyicinin yazdığı copy constructor sınıfın implicit non-static public inline special member functionu

 Myclass m1;
 Myclass m2(m1); // m1 == m2 -> true
 --------------------------------------------------------------------------------------------------------------------------------------------------
 Copy constructorun çağırıldığı 1.senaryo
class Date
{ 
public:
    Date(const Date& r) : md(r.md),mm(r.mm),my(r.my)
    {
        std::cout << "Date copy constructor(int,int,int) this = " << this << "\n";
        std::cout << "&r					= " << &r << "\n"; // referansın bağlandığı sınıfın adresi -> d1
    }
    Date(int d, int m ,int y) : md(d),mm(m),my(y)
    {
        std::cout << "Date(int,int,int) this = " << this << "\n";
    }
    ~Date()
    {
        std::cout << "~Data() this = " -<< this << "\n";
    }

    void print_date()
    {
        std::cout << md << "/" << mm << "/" << my << "\n";
    }

private:
    int md;
    int mm;
    int my;
};

int main()
{
    Date d1(12, 4, 1998);

    Date d2 = d1;
    d1.print_date();
    d2.print_date();

    std::cout << "&d1 = " << &d1 << "\n";
    std::cout << "&d2 = " << &d2 << "\n";

    return 0;
}

burda Copy constructor yazılmasaydı derleyici arka planda kendi kendine yazmış oluyor
d2 yi d1 ile başlatmış oluyoruz

Date(int,int,int) this                  =   0000007730AFFC58 d1
Date copy constructor(int,int,int) this =   0000007730AFFC88 d2 copy constructor ile çağırıldığı için
&r                                      =   0000007730AFFC58 d1 adresi
12/4/1998 //d1
12/4/1998 //d2
&d1                                     =   0000007730AFFC58 d1
&d2                                     =   0000007730AFFC88 d2
~Data() this                            =   0000007730AFFC88 d2
~Data() this                            =   0000007730AFFC58 d1
--------------------------------------------------------------------------------------------------------------------------------------------------
 Copy constructorun çağırıldığı 2.senaryo

class Myclass {
public:
    Myclass();
    ~Myclass();
};

Myclass::Myclass()
{
    std::cout << this << " default cunstructor called\n";
}

Myclass::~Myclass()
{
    std::cout << this << " destructor called\n";

}

void func(Myclass x)
{
    std::cout << "func called\n";
    std::cout << "Param MyClass & " <<&x << '\n';
}

int main()
{
    Myclass my;
    func(my);
}

Sorunuzdaki kodu inceleyelim ve `func` fonksiyonundaki `Myclass` nesnesi için neden **constructor** çağrılmadığını açıklayalım.

### **Kod Akışı**
1. `main` fonksiyonunda bir `Myclass` nesnesi (`my`) oluşturuluyor:

   Myclass my;

   Bu satırda, `Myclass` için **default constructor** çağrılır ve bu nesne bellekte `my` olarak adlandırılır.

2. `func` fonksiyonu çağrılıyor:

   func(my);

   Burada, `my` nesnesi `func` fonksiyonuna **değer (by value)** olarak geçiliyor.

### **Neden Constructor Çağrılmıyor?**

#### **Değer Semantiği (By Value)**
- `func` fonksiyonu şu şekilde tanımlanmış:

  void func(Myclass x)

  Bu, `Myclass` türünde bir **kopya** parametre alır. `my` nesnesi, `func`'a bir kopyası alınarak geçirilir.

#### **Kopya Constructor (Copy Constructor)**
- Bir nesne başka bir nesneden kopyalanarak oluşturuluyorsa, **kopya constructor** çağrılır. Sizin kodunuzda
**kopya constructor** tanımlanmamış, bu yüzden derleyici **varsayılan (default)** kopya constructor'ı kullanır.

  Varsayılan kopya constructor şu şekilde işler:
  - Mevcut nesnenin (örneğin `my`) tüm üyelerini, hedef nesneye (`x`) birebir kopyalar.
  - Siz bir `std::cout` eklemediğiniz için, kopya constructor çağrıldığı sırada herhangi bir çıktı gözükmez.

### **Kod Çıktısı**
Kodunuzu çalıştırırsak şu çıktıyı görürüz:

0x61ff0c default cunstructor called
func called
Param MyClass & 0x61fef8
0x61fef8 destructor called
0x61ff0c destructor called

#### Çıktının Analizi:
1. **0x61ff0c default constructor called**:
   - `Myclass my;` satırında `my` nesnesi oluşturuluyor. Adresi `0x61ff0c`.

2. **func(my);** çağrısı:
   - `my` nesnesinin **kopyası** oluşturulur ve `func`'a geçirilir.
   - Bu sırada, **kopya constructor** çağrılır, ancak kopya constructor içinde `std::cout` olmadığından bir çıktı görmezsiniz.

3. **func called**:
   - `func` fonksiyonunun gövdesi çalışmaya başlar.

4. **Param MyClass & 0x61fef8**:
   - `x` nesnesinin adresi (kopya nesne), `0x61fef8` olarak yazdırılır.

5. **0x61fef8 destructor called**:
   - `func` fonksiyonu sona erdiğinde, `x` nesnesi (kopya) otomatik olarak yok edilir ve `destructor` çağrılır.

6. **0x61ff0c destructor called**:
   - `main` fonksiyonu sona erdiğinde, `my` nesnesi yok edilir ve destructor çağrılır.

### **Kopya Constructor’ı Özelleştirme**
Kopya constructor’ı özelleştirirseniz, kopya oluşturulduğunu açıkça görebilirsiniz:

class Myclass {
public:
    Myclass();
    ~Myclass();
    Myclass(const Myclass& other); // Kopya constructor
};

Myclass::Myclass() {
    std::cout << this << " default constructor called\n";
}

Myclass::~Myclass() {
    std::cout << this << " destructor called\n";
}

Myclass::Myclass(const Myclass& other) {
    std::cout << this << " copy constructor called from " << &other << '\n';
}

void func(Myclass x) {
    std::cout << "func called\n";
    std::cout << "Param MyClass & " << &x << '\n';
}

int main() {
    Myclass my;
    func(my);
}

#### Yeni Çıktı:

0x61ff0c default constructor called
0x61fef8 copy constructor called from 0x61ff0c
func called
Param MyClass & 0x61fef8
0x61fef8 destructor called
0x61ff0c destructor called
 --------------------------------------------------------------------------------------------------------------------------------------------------
 2)C++’ta **copy elision** (kopyalama yok sayma), derleyicinin belirli durumlarda nesnelerin kopyalanmasını atlamasına olanak tanıyan 
 bir optimizasyon tekniğidir. Bu, performansı artırmak ve gereksiz kopyalama işlemlerini önlemek için kullanılır.

### **Copy Elision Nedir?**
Kopyalama yok sayma, derleyicinin belirli durumlarda bir nesnenin kopyasını oluşturmadan, doğrudan nesneyi hedef alana 
yerleştirmesine olanak tanır. Bu, özellikle aşağıdaki durumlarda ortaya çıkar:

1. **Geçici nesnelerin döndürülmesi**: Fonksiyonlardan dönen geçici nesneler genellikle kopyalanmadan doğrudan hedef alana yerleştirilir.
2. **Nesne başlatma**: Bir nesnenin, başka bir nesne ile doğrudan başlatılması durumunda 
(örneğin, bir nesnenin inşa edilirken başka bir nesne ile başlatılması).

### **Örnek**
Aşağıdaki örnek, kopyalama yok saymanın nasıl çalıştığını göstermektedir:

#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Default constructor\n"; }
    MyClass(const MyClass&) { std::cout << "Copy constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
};

// Fonksiyon, MyClass nesnesini döndürür
MyClass createObject() {
    MyClass obj;
    return obj;  // Kopyalama yok sayma burada devreye girebilir
}

int main() {
    MyClass myObj = createObject();  // Kopyalama işlemi gerçekleşmeyebilir
    return 0;
}

Bu kodda `createObject` fonksiyonu bir `MyClass` nesnesi döndürmektedir. Normalde, `obj` nesnesi dönerken kopyalanması gerekebilir.
Ancak, derleyici optimizasyonu sayesinde bu kopyalama yok sayılabilir ve doğrudan `myObj`'a yerleştirilir.

### **C++17 ve Copy Elision**
C++17 ile birlikte, kopyalama yok sayma daha da katı hale getirilmiştir. Eğer bir geçici nesne bir 
fonksiyonun dönüş değeri olarak kullanılıyorsa, derleyici bu dönüşümde kopyalama yok saymayı zorunlu kılar. 
Bu durum, kopyalama işlemlerinin kesinlikle atlanmasını sağlar.

### **Örnek (C++17)**

class MyClass {
public:
    MyClass() { std::cout << "Default constructor\n"; }
    MyClass(const MyClass&) { std::cout << "Copy constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
};

// C++17 ile zorunlu kopyalama yok sayma
MyClass createObject() {
    return MyClass();  // Burada kopyalama yok sayılır
}

int main() {
    MyClass myObj = createObject();  // "Copy constructor" çağrılmaz
    return 0;
}

### **Sonuç**
**Copy elision**, C++'ta performansı artırmak için kullanılan önemli bir optimizasyon tekniğidir. 
Derleyicinin nesneleri kopyalamadan doğrudan hedef alana yerleştirmesine olanak tanır. Özellikle 
C++17 ile birlikte bu optimizasyon zorunlu hale gelmiştir ve programcıların daha verimli kod yazmalarına yardımcı olur.
 --------------------------------------------------------------------------------------------------------------------------------------------------
Rule of Zero (Sıfır Kuralı)

**Rule of Zero**, modern C++'ta bir sınıf tasarım prensibidir. Bu prensip, bir sınıfın kopyalama, 
taşıma, ve yok etme (destruction) gibi özel üye fonksiyonlarını manuel olarak tanımlamaktan kaçınılmasını
ve bunun yerine varsayılan davranışların kullanılmasını önerir. Bu, genellikle kaynak yönetimini 
(örneğin, dinamik bellek veya dosya tanıtıcıları) sınıf içinde değil, 
**RAII (Resource Acquisition Is Initialization)** nesnelerine devrederek sağlanır.

Manuel olarak özel üye fonksiyonları (constructor, destructor, copy/move constructor ve assignment operator) tanımlamak:
- Karmaşıklığı artırır.
- Hatalara neden olabilir (örneğin, kaynak sızıntısı, kopyalama veya taşımada eksiklikler).
- Daha fazla bakım gerektirir.

C++'ta standart kütüphane (örneğin, `std::unique_ptr`, `std::shared_ptr`, `std::vector`) 
bu kaynak yönetimini güvenli ve verimli bir şekilde yapar. Rule of Zero, bu araçları kullanmayı teşvik eder.

### **Prensip**
Bir sınıf:
1. Hiçbir özel üye fonksiyon (constructor, destructor, copy/move constructor veya assignment operator) tanımlamamalıdır.
2. Kaynak yönetimini, standart kütüphane sınıfları (`std::unique_ptr`, `std::vector`, vb.) gibi **RAII** sınıflarına bırakmalıdır.

Bu şekilde derleyicinin otomatik olarak sağladığı varsayılan davranışlar 
(copy/move constructor ve assignment operator) doğru ve yeterli olacaktır.

### **Örnek: Rule of Zero'yu Uygulamak**

#### **Yanlış Yaklaşım (Manuel Kaynak Yönetimi):**

#include <iostream>

class MyClass {
    int* data;
public:
    MyClass(int value) : data(new int(value)) {}

    ~MyClass() { delete data; }

    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};

Bu kod:
- Tüm özel üye fonksiyonları manuel olarak tanımlar.
- Kaynak yönetimi hatalarına açık hale gelir (örneğin, unutulan `delete` veya yanlış kopyalama).

#### **Doğru Yaklaşım (Rule of Zero):**

#include <iostream>
#include <memory>

class MyClass {
    std::unique_ptr<int> data; // Kaynak yönetimini std::unique_ptr'a bırakıyoruz.
public:
    MyClass(int value) : data(std::make_unique<int>(value)) {}

    // Özel üye fonksiyonlar varsayılan olarak derleyici tarafından sağlanır:
    // - Default Constructor
    // - Copy/Move Constructor
    // - Copy/Move Assignment Operator
    // - Destructor
};

Bu kod:
- Kaynak yönetimini `std::unique_ptr`'a devreder.
- Özel üye fonksiyonların hiçbiri manuel olarak tanımlanmadığı için basittir.
- Kaynak sızıntısı gibi hatalar olasılıkla tamamen engellenir.

### **Faydalı Standart Kütüphane Bileşenleri**
Rule of Zero'yu uygulamak için aşağıdaki standart kütüphane bileşenlerini kullanabilirsiniz:
- **`std::unique_ptr`**: Tek bir sahip tarafından yönetilen dinamik kaynaklar.
- **`std::shared_ptr`**: Paylaşılan sahiplik için.
- **`std::vector`**, **`std::string`**, vb.: Dinamik diziler ve metinler.
- **`std::optional`**: Bir değeri opsiyonel olarak taşımak için.

### **Sonuç:**
- **Rule of Zero**, daha güvenli ve kolay yönetilebilir kod yazmanıza yardımcı olur.
- Kaynak yönetimini standart kütüphane sınıflarına devrederek özel üye fonksiyonları manuel olarak yazma ihtiyacını ortadan kaldırır.
- Daha az kod, daha az hata ve daha yüksek okunabilirlik sağlar.

**Not:** Eğer manuel kaynak yönetimi gerçekten gerekliyse, **Rule of Five** veya **Rule of Three** 
prensiplerine geçebilirsiniz. Ancak bu nadir bir durum olmalıdır.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 3)RAII (Resource Acquisition Is Initialization)(Kaynak Edinimi ilk değerle olur), 
 C++'da yaygın olarak kullanılan bir tasarım paradigmasıdır. Bu yaklaşım, bir kaynağın 
 (örneğin, bellek, dosya tanıtıcısı, ağ bağlantısı) yaşam döngüsünü yönetmek için nesne ömründen yararlanır. 

RAII'nin temel ilkeleri şunlardır:

1. **Kaynak Yönetimi**: Bir nesne oluşturulduğunda, bu nesneye ait kaynaklar edinilir. Nesne yok olduğunda (örneğin, 
bir fonksiyondan çıkıldığında), otomatik olarak bu kaynaklar serbest bırakılır.

2. **Otomatik Temizlik**: RAII kullanarak, bellek sızıntıları ve kaynak yönetimi hataları azaltılır. 
Çünkü kaynaklar, nesnenin ömrü sona erdiğinde otomatik olarak temizlenir.

3. **Scoped Resource Management**: Kaynaklar, genellikle yerel bir kapsamda tanımlanır, 
böylece kapsam sona erdiğinde kaynaklar otomatik olarak serbest bırakılır.

RAII, C++'da sıkça kullanılan `std::unique_ptr`, `std::shared_ptr` ve `std::lock_guard` 
gibi sınıflarda örneklerini bulabilirsiniz. Bu sayede, programcıların kaynak yönetimi 
konusundaki yükleri önemli ölçüde azalır.

#include <iostream>
#include <fstream>

class File {
public:
    File(const std::string& filename) {
        file.open(filename);
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~File() {
        if (file.is_open()) {
            file.close();
        }
    }

    void write(const std::string& data) {
        if (file.is_open()) {
            file << data;
        }
    }

private:
    std::ofstream file;
};

int main() {
    try {
        File myFile("example.txt");
        myFile.write("Hello, RAII!");
        // File nesnesi scope'dan çıktığında destructor çağrılacak
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // myFile burada yok oluyor ve destructor çağrılıyor
    return 0;
}
 --------------------------------------------------------------------------------------------------------------------------------------------------
 4)Big Three ne demek:(günümüzde big five)

üç önemli özel üye fonksiyonu(SPECİAL MEMBER FUNCTİONS) ifade eder. Bu üç fonksiyonun doğru bir şekilde uygulanması, 
dinamik bellek yönetimi ve nesne yaşam döngüsü açısından önemlidir. Bu üç fonksiyon şunlardır:

1)Copy Constructor
2)Copy Assignment Operator
3)Destructor
(move constructor,move assigment ) c++11 ile geldi
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Memberwise Copy (Üye Bazlı Kopyalama)

**Memberwise copy**, bir nesnenin bir başka nesneye kopyalanması sırasında, sınıfın her bir üyesinin ayrı ayrı kopyalanması işlemidir. 
C++'ta bu işlem, varsayılan olarak sağlanan kopya yapıcı (**copy constructor**) ve kopya atama operatörü (**copy assignment operator**) 
tarafından gerçekleştirilir.

### **Derleyicinin Sağladığı Varsayılan Davranış**

Eğer bir sınıf için copy contructor veya copy assignment operatör açıkça tanımlanmadıysa, C++ derleyicisi bu işlemleri 
**memberwise copy** şeklinde otomatik olarak oluşturur.

- **Kopya Yapıcı (Copy Constructor):** Bir nesneyi başka bir nesne kullanarak başlatır.
Myclass m1;
Myclass m2(m1);

- **Kopya Atama Operatörü (Copy Assignment Operator):** Bir nesnenin içeriğini başka bir nesneye kopyalar.
Myclass m1,m2;
m2 = m1;

**Varsayılan davranış:**
- **Non-static** veri üyeleri sırayla, **bitwise copy** yöntemiyle kopyalanır.
- Herhangi bir üye veri türü başka bir sınıfsa, o sınıfın kopya yapıcısı veya kopya atama operatörü çağrılır.

### **Memberwise Copy'nin Örnekleri**

#### **Basit Türler için (Primitive Types):**

#include <iostream>

class MyClass {
    int a;
    double b;
public:
    MyClass(int x, double y) : a(x), b(y) {}
    void print() const { std::cout << "a: " << a << ", b: " << b << '\n'; }
};

int main() {
    MyClass obj1(10, 3.14);
    MyClass obj2 = obj1; // Memberwise copy (copy contructor çağrılır)
    obj2.print();
}

- `obj2`, `obj1`'den **memberwise copy** ile kopyalanır.
- `a` ve `b` değerleri birebir kopyalanır.

#### **Dinamik Bellek İçeren Sınıflarda Sorun:**
Memberwise copy'nin varsayılan davranışı, dinamik bellek kullanan sınıflarda sorunlara yol açabilir. 
Bu durumda **shallow copy (yüzeysel kopyalama)** yapılır ve aynı belleğe işaret eden iki nesne oluşur.

#include <iostream>

class MyClass {
    int* data;
public:
    MyClass(int value) : data(new int(value)) {}
    ~MyClass() { delete data; }

    void print() const { std::cout << "Data: " << *data << '\n'; }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1; // Varsayılan kopya yapıcı kullanılır (shallow copy)
    obj1.print();
    obj2.print();
}

Bu kodda:
- `obj2 = obj1` sırasında shallow copy yapılır.
- Hem `obj1` hem de `obj2`, aynı `int` bellek adresine işaret eder.
- `obj1` ve `obj2` yok edilirken aynı bellek alanı birden fazla kez `delete` edilmeye çalışılır ve tanımsız davranış oluşur.

#### **Doğru Kullanım: Deep Copy**
Dinamik kaynakları güvenli bir şekilde kopyalamak için **copy constructor ** ve **copy assignment operator ** 
manuel olarak tanımlayarak **deep copy** yapabilirsiniz.

#include <iostream>

class MyClass {
    int* data;
public:
    MyClass(int value) : data(new int(value)) {}

    // Kopya yapıcı (deep copy)
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    ~MyClass() { delete data; }

    void print() const { std::cout << "Data: " << *data << '\n'; }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1; // Deep copy ile kopyalanır
    obj1.print();
    obj2.print();
}

### **Memberwise Copy'nin Avantajları**
- Basit ve hızlıdır.
- Primitive (temel) türler ve **RAII** nesneleri için güvenlidir.

### **Memberwise Copy'nin Dezavantajları**
- **Shallow copy** dinamik bellek veya diğer özel kaynakları kullanan sınıflarda sorunlara yol açabilir.
- **Deep copy** gereken durumlarda manuel kopya yapıcı ve atama operatörü tanımlanmalıdır.

### **Sonuç:**
C++'ta memberwise copy:
- Derleyicinin varsayılan olarak sağladığı, hızlı ve basit bir mekanizmadır.
- Dinamik bellek veya özel kaynaklar kullanan sınıflar için dikkatli olunmalıdır.
- Modern C++ ile **RAII** araçları (`std::unique_ptr`, `std::shared_ptr`) kullanılarak memberwise copy güvenli hale getirilebilir.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 ### Value Semantics 

**Value semantics**, bir nesnenin kopyalanması, atanması veya taşınması sırasında, o nesnenin tüm içeriğinin 
bağımsız bir kopyasının oluşturulması anlamına gelir. Bu, kopyalanan nesnelerin birbiriyle tamamen bağımsız olmasını sağlar.

C++'ta değer semantiği genellikle temel türler (**int**, **double**, **char**, vb.) ve standart kütüphane 
konteynerleri (**std::vector**, **std::string**, vb.) ile kullanılır.

### **Değer Semantiğinin Temel Özellikleri**
1. **Kopyalama:** Bir nesne kopyalandığında, tüm verileri başka bir nesneye kopyalanır ve her iki nesne bağımsız olur.
2. **Atama:** Bir nesne başka bir nesneye atandığında, tüm veri üyeleri kopyalanır ve bağımsız bir içerik oluşur.
3. **Bağımsızlık:** Kopyalanmış nesneler birbiriyle hiçbir şekilde bağlantılı değildir. Bir nesnedeki değişiklik diğerini etkilemez.
4. **Hafıza Yönetimi:** Varsayılan olarak, her nesne kendi belleğini yönetir ve diğer nesnelerle paylaşmaz.

### **Örnek: Temel Türlerde Değer Semantiği**

#include <iostream>

int main() {
    int x = 42;
    int y = x; // Değer kopyalanır.
    y = 100;

    std::cout << "x: " << x << ", y: " << y << '\n'; // x ve y bağımsızdır.
    return 0;
}

**Çıktı:**

x: 42, y: 100

Bu örnekte, `x` ve `y` tamamen bağımsızdır; biri değiştirildiğinde diğeri etkilenmez.

### **Değer Semantiği ile Sınıflar**
C++ sınıflarında değer semantiği, genellikle varsayılan kopya yapıcı, kopya atama operatörü ve yok edici (destructor) kullanılarak uygulanır.

#### **Varsayılan Değer Semantiği Örneği:**

#include <iostream>
#include <string>

class MyClass {
    std::string name;
    int age;
public:
    MyClass(const std::string& n, int a) : name(n), age(a) {}

    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << '\n';
    }
};

int main() {
    MyClass obj1("Alice", 25);
    MyClass obj2 = obj1; // Değer semantiği ile kopya oluşturulur.

    obj2.print();

    obj2 = MyClass("Bob", 30); // Yeni bir nesne atanır.
    obj2.print();
    obj1.print(); // obj1 ve obj2 birbirinden bağımsızdır.
}

**Çıktı:**

Name: Alice, Age: 25
Name: Bob, Age: 30
Name: Alice, Age: 25

Burada, `obj2`, `obj1`'den bağımsızdır. Kopyalama veya atama işlemleriyle her iki nesne de kendi verilerini saklar.

### **Değer Semantiği ile Derin Kopyalama**
Dinamik kaynak kullanan sınıflarda, değer semantiğini sağlamak için **deep copy (derin kopya)** uygulanır. 
Bu, her bir nesnenin bağımsız olarak kendi kaynağını yönetmesini sağlar.

#### **Deep Copy Örneği:**

#include <iostream>
#include <cstring>

class MyClass {
    char* data;
public:
    MyClass(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Kopya yapıcı (deep copy)
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    // Yok edici
    ~MyClass() { delete[] data; }

    void print() const { std::cout << "Data: " << data << '\n'; }
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2 = obj1; // Deep copy yapılır.
    obj2.print();

    return 0;
}

Bu kod, değer semantiğini korur çünkü `obj1` ve `obj2` tamamen bağımsızdır.

### **Değer Semantiği ile Modern C++**
Modern C++ ile RAII (Resource Acquisition Is Initialization) ve akıllı işaretçiler (**std::unique_ptr**, 
**std::shared_ptr**) gibi araçlar sayesinde değer semantiği çok daha kolay ve güvenli hale gelmiştir.

#### **Örnek: std::unique_ptr ile Değer Semantiği:**

#include <iostream>
#include <memory>

class MyClass {
    std::unique_ptr<int> data;
public:
    MyClass(int value) : data(std::make_unique<int>(value)) {}

    void print() const { std::cout << "Data: " << *data << '\n'; }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = std::move(obj1); // Move semantiği ile taşınır.
    obj2.print();

    return 0;
}

### **Değer Semantiği vs. Referans Semantiği**
- **Değer Semantiği:** Her kopya bağımsızdır (örneğin, temel türler, deep copy).
- **Referans Semantiği:** Nesneler arasında veri paylaşımı yapılır (örneğin, pointerlar veya `std::shared_ptr`).

### **Sonuç:**
- **Değer semantiği**, bir nesnenin kopyalanabilir ve bağımsız olmasını sağlar.
- Modern C++ araçlarıyla (akıllı işaretçiler ve standart konteynerler) bu işlemler daha güvenli ve kolaydır.
- Değer semantiği, özellikle kaynak sızıntılarını önlemek ve kodun tahmin edilebilirliğini artırmak için tercih edilir.
 --------------------------------------------------------------------------------------------------------------------------------------------------
**shallow copy** ile **memberwise copy** farkları 

### **Memberwise Copy**
- **Memberwise copy**, bir sınıfın veri üyelerinin bire bir (her bir veri üyesi için) kopyalanması işlemidir.
- C++ derleyicisi, varsayılan kopya yapıcı (**copy constructor**) ve kopya atama operatörünü 
(**copy assignment operator**) memberwise copy kullanarak otomatik olarak sağlar.

- Her bir üye kendi türüne uygun şekilde kopyalanır:
  - **Primitive türler** (ör. `int`, `double`) doğrudan kopyalanır.
  - **Sınıf türleri** için o sınıfın kopya yapıcısı veya kopya atama operatörü çağrılır.

#### **Örnek: Memberwise Copy**

#include <iostream>

class MyClass {
    int a;
    double b;
public:
    MyClass(int x, double y) : a(x), b(y) {}
    void print() const { std::cout << "a: " << a << ", b: " << b << '\n'; }
};

int main() {
    MyClass obj1(42, 3.14);
    MyClass obj2 = obj1; // Memberwise copy yapılır.
    obj2.print();
}

Bu örnekte, `obj2`'nin `a` ve `b` üyeleri, `obj1`'den bire bir kopyalanır.

### **Shallow Copy**
- **Shallow copy**, bir nesnenin yalnızca bellek adreslerinin veya referanslarının kopyalandığı bir kopyalama işlemidir.
- Shallow copy, genellikle bir nesnenin veri üyeleri **pointer** veya başka kaynaklara işaret ettiğinde (örneğin dinamik bellek), 
bu kaynakların kopyalanmadan, sadece adreslerinin kopyalanması anlamına gelir.Bu durum, kopyalanan nesnelerin aynı kaynağı 
paylaşmasına neden olur ve kaynak yönetimi problemlerine yol açabilir (ör. çift `delete` çağrısı).

#### **Örnek: Shallow Copy**

#include <iostream>

class MyClass {
    int* data;
public:
    MyClass(int value) : data(new int(value)) {}
    ~MyClass() { delete data; }

    void print() const { std::cout << "Data: " << *data << '\n'; }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1; // Varsayılan kopya yapıcı shallow copy yapar.
    obj1.print();
    obj2.print();
}

Bu kodda:
- `obj2`, `obj1` ile aynı dinamik belleği paylaşır.
- `obj1` veya `obj2` yok edildiğinde `delete` çağrılır ve çift `delete` problemi oluşur.

### **Farklar**
| **Özellik**               | **Memberwise Copy**                                                      | **Shallow Copy**                                |
|---------------------------|-------------------------------------------------------------------------|------------------------------------------------|
| **Kapsam**                | Her bir veri üyesini bire bir kopyalar.                                | Dinamik kaynaklarda sadece adresleri kopyalar. |
| **Dinamik Bellek Desteği**| Dinamik bellek için özel bir davranış tanımlanmaz.                     | Bellek paylaşımı yapılır (kaynak paylaşılır).   |
| **Varsayılan Davranış**    | Derleyicinin varsayılan kopya yapıcı ve atama operatörü ile sağlanır. | Üye türü pointer olduğunda ortaya çıkar.       |

### **Memberwise Copy ve Shallow Copy İlişkisi**
- **Memberwise copy**, shallow copy'yi kapsayabilir, ancak shallow copy, yalnızca veri üyeleri pointer olduğunda etkili olur.
- Eğer bir sınıf dinamik bellek kullanmıyorsa, memberwise copy ve shallow copy arasında pratikte fark yoktur.
- Dinamik bellek kullanan bir sınıf için shallow copy, ciddi kaynak yönetimi problemleri yaratabilir.

### **Deep Copy ile Sorunları Çözmek**
**Deep copy**, shallow copy'nin aksine, kaynakların yeni bir kopyasını oluşturarak bu tür sorunları önler.

#include <iostream>

class MyClass {
    int* data;
public:
    MyClass(int value) : data(new int(value)) {}

    // Deep copy için kopya yapıcı
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    ~MyClass() { delete data; }

    void print() const { std::cout << "Data: " << *data << '\n'; }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1; // Deep copy yapılır.
    obj1.print();
    obj2.print();
}

### **Sonuç**
- **Memberwise copy**, varsayılan olarak veri üyelerini bire bir kopyalar.
- Eğer sınıf dinamik bellek veya özel kaynak kullanıyorsa, memberwise copy bir **shallow copy**'ye dönüşebilir.
- Dinamik kaynakların doğru yönetimi için **deep copy** gereklidir.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 ### **Copy Assignment Operator (Kopya Atama Operatörü) Neden Kullanılır ve Ne Zaman Kullanılır?**

#### **Neden Kullanılır?**

**Copy assignment operator**, bir nesnenin bir başka nesneden veri alarak kendisini güncellemesini sağlar. Bu operatör şu durumlarda önemlidir:

1. **Varolan Nesneyi Güncellemek:**
   - Eğer bir nesne önceden oluşturulmuşsa ve başka bir nesneyle aynı duruma getirilmek isteniyorsa, copy assignment operator devreye girer.
   - Örneğin:

     MyClass obj1(42);
     MyClass obj2(13);
     obj2 = obj1; // obj2'nin içeriği obj1'e eşitlenir.

2. **Dinamik Bellek Yönetimi:**
   - Eğer sınıfınız dinamik bellek veya özel kaynaklar (ör. dosya tanıtıcıları, ağ bağlantıları) kullanıyorsa, 
   derleyicinin varsayılan olarak sağladığı **memberwise copy** yeterli olmayabilir. Bu durumda, özel bir copy 
   assignment operator tanımlanması gerekebilir.

3. **Derleyici Tarafından Sağlanan Varsayılan Davranışı Değiştirmek:**
   - Eğer kaynakların **shallow copy** yerine **deep copy** yapılması gerekiyorsa veya bazı kaynakların kopyalanmasını 
   engellemek istiyorsanız, copy assignment operator tanımlamanız gerekir.

Derleyicinin yazdığı copy assignment operator

class Myclass{
public:
    Myclass& operator=(const Myclass& r)
    {
        ax = r.ax;
        bx = r.bx;
        cx = r.cx;

        return *this;
    }
    int ax,bx,cx;
}
    
#### **Ne Zaman Kullanılır?**

**Copy assignment operator** şu durumlarda çağrılır:

1. **Varolan Nesneye Yeni Değer Atama:**
   - Bir sınıfın nesnesi başka bir nesneye atandığında:

     MyClass obj1(42);
     MyClass obj2(13);
     obj2 = obj1; // Copy assignment operator çağrılır. 

2. **Bir Koleksiyonda veya Standart Konteynerde Kullanıldığında:**
   - Standart STL konteynerleri (ör. `std::vector`, `std::map`) öğeleri kopyalarken copy assignment operator çağırabilir.

3. **Dinamik Belleği veya Kaynakları Yönetirken:**
   - Kaynak paylaşımı veya derin kopya yapmak gerekiyorsa, özel bir copy assignment operator tanımlanmalıdır.

#### **Varsayılan Copy Assignment Operator**

Eğer sınıfınızda özel bir copy assignment operator tanımlamazsanız, derleyici şu şekilde bir **memberwise copy** operatörü oluşturur:

- Tüm veri üyelerini bire bir kopyalar (primitive veri türleri için `=` operatörünü çağırır).
- Veri üyeleri başka bir sınıf ise, onların copy assignment operator'ü çağrılır.

**Örnek:**

class MyClass {
    int a;
    double b;
};

MyClass obj1, obj2;
obj1 = obj2; // Memberwise copy yapılır.

#### **Kullanımın Gereksiz Olduğu Durumlar (Rule of Zero)**

- Eğer sınıfınız **dinamik bellek** veya **özel kaynak yönetimi** gerektirmiyorsa, copy assignment operator yazmanız gerekmez.
- Derleyici, memberwise copy üzerinden varsayılan davranışı sağlayacaktır.

**Örnek:**

class MyClass {
    int a;
    double b;
    std::string c; // Dinamik bellek `std::string` tarafından zaten yönetiliyor.
};

#### **Kendi Copy Assignment Operator'ünüzü Ne Zaman Yazmalısınız?**

1. **Dinamik Bellek veya Kaynak Kullanımı:**
   - Eğer sınıfınız dinamik bellek kullanıyorsa veya özel kaynaklar içeriyorsa (ör. dosyalar, ağ bağlantıları), 
   kendi copy assignment operator'ünüzü tanımlamalısınız.

   **Örnek:**

   class MyClass {
       int* data;
   public:
       MyClass(int value) : data(new int(value)) {}
       ~MyClass() { delete data; }

       MyClass& operator=(const MyClass& other) {
           if (this != &other) {
               delete data;
               data = new int(*other.data);
           }
           return *this;
       }
   };

2. **Kaynakların Kopyalanmasını Engellemek:**
   - Eğer nesnenin kopyalanmasını istemiyorsanız, copy assignment operator'ü **`=delete`** ile silebilirsiniz.

   **Örnek:**

   class MyClass {
   public:
       MyClass& operator=(const MyClass&) = delete; // Atama engellendi.
   };

3. **Performans Optimizasyonu:**
   - Eğer kopyalama işlemi çok maliyetliyse, kopya yerine taşımayı tercih edebilirsiniz (**move assignment operator**).

### **Sonuç**

- **Neden Kullanılır?**
  - Varolan nesneleri güncellemek.
  - Dinamik bellek veya özel kaynakları yönetmek.
  - Varsayılan davranışı değiştirmek.

- **Ne Zaman Kullanılır?**
  - Nesneleri atamak istediğinizde veya STL konteynerlerinde kullanıldığında çağrılır.
  - Özel kaynak yönetimi durumlarında manuel olarak tanımlanması gerekebilir.

Varsayılan davranış çoğu durumda yeterli olsa da, dinamik bellek veya karmaşık kaynak yönetimi durumlarında, 
özel bir copy assignment operator yazmak gerekebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:aynı nesneyi birbirine atarken dikkat etmemiz gerek çünkü nesnenin değeri değişmeyecekken
o nesneyi delete edersek aynı nesnenin değerinin kaynağını geri vermiş oluyoruz böylelikle
dangling pointer oluyor burda kontrol etmemiz gereken nesnelerin adresi aynı nesneyse 
bir işlem yapmamısını sağlayabiliriz

if(this == &other) // self assginment str = str ->kendisine atama
    return *this;

String& operator=(const String& other)
{
    if(this == &other)
        return *this;

    mlen = other.mlen;
    std::free(mp);

    mp = static_cast<char*>(std::malloc(mlen + 1));
    if (!mp)
    {
        std::cerr << "cannot allocate memory";
    }

    return *this;
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Cppreference'de **pointer aliasing** doğrudan başlık olarak ele alınmasa da, ilgili kavramlar çeşitli 
konular altında açıklanır. Pointer aliasing, aynı bellek adresine birden fazla işaretçi veya referansla 
erişme durumudur. Bu, bellek erişimi davranışını ve performans optimizasyonlarını etkileyebilir.

Aşağıda pointer aliasing'i ve ilgili kuralları, Cppreference'deki bilgileri temel alarak detaylı bir şekilde açıklıyorum:

### **1. Pointer Aliasing'in Tanımı**
**Pointer aliasing**, iki veya daha fazla işaretçinin aynı bellek adresine işaret etmesi durumudur. 
Bu, bir nesneye birden fazla işaretçi veya referans yoluyla erişilmesine olanak tanır. Örneğin:

int x = 42;
int* a = &x;
int* b = &x; // a ve b alias oluşturuyor.

Bu durumda, `a` ve `b` aynı nesneyi işaret eder ve alias oluşturur. Bir işaretçi üzerinden yapılan değişiklik, diğer işaretçinin göreceği değerleri etkiler.

### **2. Strict Aliasing Rule (Katı Aliasing Kuralı)**

C++'da **strict aliasing rule**, bir işaretçinin belirli bir türdeki bir nesneye yalnızca şu türlerle erişebileceğini belirtir:
1. Aynı tür (`int`, `int` gibi),
2. `char`, `unsigned char`, veya `std::byte` (herhangi bir türün alias'ı olabilir),
3. Türün `const` veya `volatile` nitelikli hali,
4. Türler arasında explicit casting (örneğin, `reinterpret_cast`) kullanımı.

**Strict aliasing rule** derleyicinin optimizasyon yapmasına olanak sağlar çünkü derleyici, 
farklı türlerdeki işaretçilerin aynı nesneyi işaret etmeyeceğini varsayabilir.

#### **Kurala Uyulmayan Örnek:**

void aliasing_violation() {
    int x = 42;
    float* f = reinterpret_cast<float*>(&x); // Alias oluşturuyor.
    *f = 3.14f; // Strict aliasing rule'u ihlal eder.
}

Bu kod **tanımsız davranış**a neden olur çünkü `float*` ile bir `int` nesnesine erişiliyor.

### **3. Bellek Erişim ve Derleyici Optimizasyonları**
Derleyiciler strict aliasing rule'u uygulayarak bazı optimizasyonlar yapar. Pointer aliasing varsa veya kurallar ihlal edilirse:
- Derleyiciler, her işaretçinin bellekten veriyi tekrar okuyacağını varsayar.
- Bu, ekstra bellek yükleme ve kaydetme işlemlerine yol açabilir.

Örnek:

void example(int* a, int* b) {
    *a = 42;
    *b = 50; // b'nin alias olup olmadığını bilmediğinden a tekrar yüklenebilir.
    std::cout << *a << std::endl; // Belirsiz sonuç.
}

### **4. `std::launder` ile Aliasing Sorunlarını Çözme**
C++17 ile tanıtılan `std::launder`, strict aliasing rule ihlali durumlarında kullanılabilir. `std::launder`, 
bir nesnenin aliasing veya yeniden yapılandırma (reinterpretation) sorunlarını güvenli bir şekilde ele alır.

Örnek:

#include <new>
struct S { int i; };

void example() {
    alignas(S) char buffer[sizeof(S)];
    new (buffer) S{42};
    S* s = std::launder(reinterpret_cast<S*>(buffer)); // Güvenli alias erişimi.
    std::cout << s->i << std::endl;
}

### **5. Aliasing ve `char` Türü**
C++ standardına göre, `char`, `unsigned char` ve `std::byte` türleri her türlü nesneye alias olarak erişebilir. 
Bu türler bellek manipülasyonu ve debugging için sıklıkla kullanılır.

Örnek:

int x = 42;
char* p = reinterpret_cast<char*>(&x);
p[0] = 0xFF; // Belleğin ilk baytını değiştirir.

Bu durum strict aliasing rule'u ihlal etmez çünkü `char` her türü alias edebilir.

### **6. `volatile` ve Aliasing**
`volatile` işaretçiler, strict aliasing rule'u ihlal etmeyecek şekilde kullanılır. Ancak, `volatile` 
bir nesne üzerinde optimizasyonlar yapılmaz ve her zaman belleğe erişilir.

Örnek:

volatile int x = 42;
int* p = const_cast<int*>(&x); // Strict aliasing ihlali değil, ama önerilmez.
*p = 50;

### **7. Derleyici Genişletmeleri ve `restrict`**
C++ standardı doğrudan `restrict` anahtar kelimesini desteklemez, ancak GCC ve Clang gibi derleyiciler 
`__restrict__` ile bu davranışı sağlayabilir.

Örnek (GCC/Clang ile):

void example(int* __restrict__ a, int* __restrict__ b) {
    *a = 42;
    *b = 50; // a ve b alias oluşturmaz.
}
 ****************************************************************************************************************************** 
 
                                                                             ********* 12-DERS NOTLARI *********
 
 1)"Fall back," genellikle bir planın, sistemin veya uygulamanın beklenmedik bir durumla karşılaştığında, alternatif bir yönteme veya daha 
 güvenilir bir çözüme geri dönmesi anlamında kullanılır. Örneğin, bir yazılımda bir özellik çalışmadığında, sistem varsayılan bir ayara veya 
 yedek bir yöntemle devam edebilir. Bu terim, sistemlerin ve süreçlerin dayanıklılığını artırmak için önemlidir.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 2)Copy-swap idiomu, C++'ta güvenli ve etkili bir şekilde kopya atama operatörünü (`operator=`) yazmanın bir yoludur. 
 Bu idiom, hem kaynak sızıntılarını önlemek hem de exception-safe (istisnalara karşı güvenli) kod yazmak için kullanılır. 
 Temel fikir, kopya atama işlemi sırasında geçici bir nesneyle çalışmak ve son aşamada kaynakları değiştirmektir. 
 Bu sayede, orijinal nesne istisna durumunda bile tutarlı kalır.

### Copy-Swap İdiomunun Bileşenleri

1. **Copy Constructor (Kopya Kurucu)**: Sınıfın bir kopyasını oluşturur.
2. **Destructor (Yıkıcı)**: Sınıfın kaynaklarını serbest bırakır.
3. **Swap Function (Değiş Tokuş Fonksiyonu)**: İki nesnenin iç kaynaklarını değiştirir. Genellikle `std::swap` kullanılır veya kendi özel `swap` fonksiyonunuz yazılır.
4. **Copy Assgigment Operator (`operator=`)**: Kopya atama işlemi sırasında, nesneye yeni bir değer atar.

### Copy-Swap İdiomunun Temel Mantığı

Copy-swap idiomunun temel aşamaları şunlardır:

- Kopya atama işlemi sırasında, önce geçici bir kopya oluşturulur (bu, kopya kurucuyu çağırır).
- Ardından, geçici nesneyle asıl nesnenin iç kaynakları `swap` fonksiyonu ile değiştirilir.
- Geçici nesne yok edildiğinde, artık orijinal kaynaklar serbest bırakılır.

Bu süreç, mevcut nesneyi etkilenmeden bırakır ve exception-safe olmasını sağlar, çünkü eğer kopya oluşturma başarısız 
olursa (örneğin, bellek yetersizliği nedeniyle), eski nesne herhangi bir değişikliğe uğramamış olur.

### Copy-Swap İdiomunun Uygulaması

Aşağıda bir sınıf için copy-swap idiomunun nasıl uygulanacağını gösteren bir örnek:

#include <iostream>
#include <algorithm> // std::swap kullanmak için

class MyClass {
private:
    int* data;
public:
    // Constructor
    MyClass(int value) : data(new int(value)) {}

    // Destructor
    ~MyClass() {
        delete data;
    }

    // Copy Constructor (Deep copy)
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Swap function (noexcept guarantees exception safety)
    void swap(MyClass& other) noexcept {
        std::swap(data, other.data); // Pointerları değiştir
    }

    // Copy assignment operator using copy-swap idiom
    MyClass& operator=(MyClass other) { // Pass by value (copy)
        swap(other); // İç kaynakları değiştir
        return *this;
    }

    // Print function to show the value
    void print() const {
        std::cout << "Value: " << *data << std::endl;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2(20);

    obj1 = obj2;  // Kopya atama işlemi (copy-swap idiomu)
    obj1.print(); // 20 yazdırır

    return 0;
}

### Açıklamalar:
1. **Copy Constructor**: `MyClass(const MyClass& other)` fonksiyonu, derin kopya yaparak kaynakları doğru şekilde kopyalar.
2. **Swap Fonksiyonu**: `swap` fonksiyonu iki nesnenin iç kaynaklarını güvenli bir şekilde değiştirir. Bu işlem hızlıdır çünkü sadece işaretçilerin yerini değiştirir.
3. **Copy Assgignment Operator**: `operator=` fonksiyonu, argümanı değer olarak alır (bu, derleyicinin kopya kurucuyu çağırmasına neden olur) ve ardından `swap` kullanarak iç kaynakları değiştirir. 

Bu yapı:
- İstisna güvenliği sağlar (eğer bir hata oluşursa, geçici nesne yok edilir ve mevcut nesne bozulmaz).
- Yinelemeli (self-assignment) durumunda bile doğru çalışır.
--------------------------------------------------------------------------------------------------------------------------------------------------
 3)C++'ta **handle** terimi, genellikle bir kaynağa (örneğin, bellek, dosya veya ağ bağlantısı gibi) erişimi kontrol eden aracı yapıları ifade eder. 
 Normal pointer'lar da bir tür handle olarak kullanılabilir, çünkü bir kaynağı işaret ederler ve bu kaynak üzerinde işlem yapmanıza olanak tanırlar. 
 Normal pointer'lar (**raw pointer**'lar), doğrudan bellekte bir kaynağa işaret eder ve bellek yönetimi açısından sorumluluk tamamen programcıya aittir.

Pointer'lar kullanılarak oluşturulmuş basit bir handle yapısına örnek verelim.

### Pointer ile Basit Handle Örneği

#include <iostream>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired.\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed.\n";
    }
    void use() {
        std::cout << "Using resource.\n";
    }
};

class Handle {
private:
    Resource* resource; // Normal pointer (raw pointer) bir handle olarak kullanılıyor

public:
    Handle() : resource(new Resource()) {}  // Kaynak ediniliyor (Resource allocated)

    ~Handle() {
        delete resource; // Kaynak serbest bırakılıyor (Resource deallocated)
        resource = nullptr;
        std::cout << "Handle destroyed, resource released.\n";
    }

    void useResource() {
        if (resource) {
            resource->use();  // Resource nesnesine erişiliyor ve kullanılıyor
        }
    }
};

int main() {
    {
        Handle handle;  // Handle nesnesi oluşturuluyor ve kaynak tahsis ediliyor
        handle.useResource();  // Kaynağa erişiliyor ve kullanılıyor
    }  // Burada scope sonlandığında, Handle yıkıcısı (destructor) çalışır ve kaynak serbest bırakılır

    return 0;
}

### Açıklamalar:

1. **`Resource` Sınıfı**: Kaynağı temsil eden sınıftır. Yapıcı (constructor) ile kaynak edinilir ve yıkıcı (destructor) ile kaynak serbest bırakılır. 
Bu sınıfı bir dosya, ağ bağlantısı veya dinamik bellek tahsisi gibi düşünebilirsiniz.

2. **`Handle` Sınıfı**: Kaynağı kontrol eden bir handle'dır. Kaynağa bir işaretçi (raw pointer) ile erişir ve yıkıcıda bu kaynağı serbest bırakır. 
Bu sınıf, kaynağın sahipliğini üstlenir ve RAII (Resource Acquisition Is Initialization) prensibine uyar.

3. **`useResource()` Fonksiyonu**: Handle içindeki kaynağa erişip, kaynağı kullanmaya yarayan fonksiyondur.

### Handle'ın Avantajları:
- **Kaynak Yönetimi**: `Handle` sınıfı, kaynak edinme ve serbest bırakma işlemlerini yönetir. Bu sayede, 
kaynak sızıntılarını önlemek için yıkıcıda (`destructor`) kaynakları serbest bırakabilirsiniz.
- **İstisna Güvenliği**: RAII (kaynak edinimi başlatma) prensibine uygun çalışır. Handle nesnesi 
oluşturulduğunda kaynak edinilir ve yıkıcı çağrıldığında kaynak serbest bırakılır.

### Önemli Noktalar:

- **Normal pointer'lar** kullanırken, belleği manuel olarak tahsis edip serbest bırakmak zorundasınız. 
Yukarıdaki örnekte, `new` operatörü ile bellek tahsisi yapılır ve `delete` ile bellek serbest bırakılır. 
Eğer `delete` unutulursa veya bir istisna meydana gelirse, bellek sızıntısı olabilir. Bu yüzden modern 
C++'ta genellikle **akıllı işaretçiler** (`std::unique_ptr`, `std::shared_ptr`) tercih edilir, çünkü bu 
yapılar otomatik bellek yönetimi sağlar ve kaynak sızıntılarını önler.

### Not:
**Normal pointer** kullanımı, dikkatli olunması gereken bir yöntemdir, çünkü bellek yönetimi tamamen programcıya aittir. Kaynak sızıntıları, 
çifte serbest bırakma hataları (double delete) veya işaretçilerin boşa çıkması (dangling pointers) gibi sorunlara yol açabilir. 
Modern C++'ta bu tür hataları önlemek için `std::unique_ptr` veya `std::shared_ptr` gibi akıllı işaretçiler tercih edilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
"To steal the resource" ifadesi, genellikle C++'ta bir nesnenin sahip olduğu kaynağın başka bir nesneye aktarılması 
(move semantics) bağlamında kullanılır. Bu ifade, özellikle C++11 ile tanıtılan **move semantics** ve **rvalue references** 
ile ilişkilidir. Kaynakların "çalınması", bir nesnenin sahip olduğu kaynakların başka bir nesneye taşınmasını ifade eder. 
Taşıma işleminden sonra, kaynak ilk nesnede artık geçerli değildir veya kullanılmaz durumda olur.

### **1. Kaynak Çalmanın Teknik Anlamı**
Bir nesnenin "kaynağını çalmak", şunları içerir:
- Kaynağın (örneğin, dinamik bellek, dosya tanıtıcıları veya başka bir sistem kaynağı) başka bir nesneye transfer edilmesi.
- Orijinal nesnenin kaynağı artık kullanılamaz hale gelir, ancak genellikle güvenli bir duruma (örneğin, `nullptr`) getirilir.

Bu işlem genellikle performans optimizasyonu için yapılır çünkü kaynak çalmak, kaynağı kopyalamaktan daha hızlıdır.

#### Örnek:

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1); // v1'in kaynağı v2'ye taşınıyor.

    std::cout << "v1 size: " << v1.size() << std::endl; // v1 artık boş.
    std::cout << "v2 size: " << v2.size() << std::endl; // v2 eski v1'in kaynağını aldı.

    return 0;
}

**Çıktı:**

v1 size: 0
v2 size: 3

### **2. Move Constructor ve Move Assignment**
Bir nesnenin kaynağını çalmak, **move constructor** veya **move assignment operator** ile gerçekleştirilir. 
Bu mekanizmalar, kopyalama yerine kaynağı taşımayı sağlar.

#### Örnek: Move Constructor

#include <iostream>
#include <string>

class MyString {
    char* data;
public:
    MyString(const char* str) {
        size_t len = std::strlen(str) + 1;
        data = new char[len];
        std::strcpy(data, str);
        std::cout << "Constructor called\n";
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(std::move(other.data)) {
        other.data = nullptr; // Kaynak taşındı, orijinal güvenli bir duruma getirildi
        std::cout << "Move constructor called\n";
    }

    ~MyString() {
        delete[] data;
    }

    void print() const {
        if (data) std::cout << data << std::endl;
        else std::cout << "No data\n";
    }
};

int main() {
    MyString s1("Hello");
    MyString s2 = std::move(s1); // s1'in kaynağı s2'ye taşınıyor.

    s1.print(); // No data
    s2.print(); // Hello

    return 0;
}

**Çıktı:**

Constructor called
Move constructor called
No data
Hello

### **3. Kaynak Çalma ve Performans**
Kaynak çalma, kaynakların kopyalanması yerine taşınmasını sağlayarak performansı artırır. Örneğin:
- **Kopyalama**: Büyük bir veri bloğunu bellekte kopyalamak zaman alıcıdır.
- **Taşıma**: Kaynağı kopyalamak yerine, kaynağın adresini taşımak çok daha hızlıdır.

#### Örnek:
Kopyalama yerine taşıma:
#include <vector>
#include <iostream>

std::vector<int> createLargeVector() {
    std::vector<int> vec(1000000, 42); // Büyük bir vektör
    return vec; // Kaynak taşınır.
}

int main() {
    std::vector<int> v = createLargeVector(); // Move semantics kullanılır.
    std::cout << "Vector size: " << v.size() << std::endl;
    return 0;
}

### **4. Orijinal Nesnenin Durumu**
Kaynak çalma işleminden sonra orijinal nesne güvenli bir duruma geçirilmelidir:
- Eğer bir pointer taşınıyorsa, `nullptr`'a atanır.
- Eğer bir kapsayıcı taşınıyorsa, boyutu sıfırlanır (boş hale getirilir).

Bu sayede, orijinal nesne artık kullanılmasa bile tanımsız davranış (undefined behavior) oluşmaz.

#### Örnek:

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> p1 = std::make_unique<int>(42);
    std::unique_ptr<int> p2 = std::move(p1); // p1'in kaynağı p2'ye taşınıyor.

    if (!p1) {
        std::cout << "p1 is now nullptr\n"; // Güvenli durum
    }
    std::cout << "p2 value: " << *p2 << std::endl;

    return 0;
}

**Çıktı:**

p1 is now nullptr
p2 value: 42

### **5. Kaynak Çalma ve `std::move`**
`std::move`, bir nesneyi **rvalue** olarak değerlendirmek için kullanılır. Ancak, `std::move` 
sadece bir cast işlemidir; taşıma işlemini gerçekleştiren `move constructor` veya `move assignment` operatörüdür.

#### Örnek:

#include <iostream>

class Foo {
public:
    Foo() { std::cout << "Default constructor\n"; }
    Foo(const Foo&) { std::cout << "Copy constructor\n"; }
    Foo(Foo&&) { std::cout << "Move constructor\n"; }
};

int main() {
    Foo a;
    Foo b = std::move(a); // Move constructor çağrılır.
    return 0;
}

**Çıktı:**

Default constructor
Move constructor

**Özet:**
"To steal the resource", bir nesnenin sahip olduğu kaynağı başka bir nesneye taşımak anlamına gelir. 
Bu işlem move constructor veya move assignment ile yapılır ve genellikle performans optimizasyonu için 
kullanılır. Kaynak taşındıktan sonra orijinal nesne güvenli bir durumda olmalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
4) **Persistent (Kalıcı) nesneler**, programın çalıştığı sürenin ötesinde yaşamlarını sürdürebilen, 
bellekte veya bir dış kaynaktaki (veritabanı, dosya, disk  vs.) veriler gibi kalıcı hale getirilen nesnelerdir. 
Bu nesneler, tipik olarak program kapanıp yeniden açıldığında bile verilerini koruyarak, uygulamanın önceki durumunu hatırlamasını sağlar. 
Persistent nesneler, verilerin sadece bellekte (RAM) geçici olarak saklandığı durumlardan farklı olarak, verilerin disk gibi kalıcı depolama ortamlarına yazılmasını içerir.

Kalıcı nesneler, yazılım dünyasında özellikle büyük uygulamalarda (veritabanı yönetimi, dosya yönetimi, oyunlardaki kaydedilmiş ilerlemeler vb.) yaygın olarak kullanılır.

### Persistent Nesnelerin Özellikleri
1. **Uzun Süreli Yaşam Döngüsü**: Bir persistent nesne, programın ömrüyle sınırlı değildir. Programın kapanması veya bilgisayarın yeniden başlatılması durumunda bile varlığını sürdürür.
   
2. **Depolama**: Kalıcı nesneler genellikle disk, veritabanı, bulut veya dosya sistemleri gibi kalıcı depolama mekanizmalarında saklanır.
   
3. **Yeniden Erişim**: Uygulama daha sonra bu kalıcı nesnelere erişebilir ve onları kullanabilir. Örneğin, bir program kapanıp tekrar açıldığında, 
kullanıcı ayarları, veritabanındaki kayıtlar veya oyundaki ilerleme bilgileri tekrar yüklenebilir.
   
4. **Serileştirme (Serialization)**: Persistent nesneleri diske yazmak için tipik olarak **serileştirme** (serialization) kullanılır. 
Bu, nesneleri bir veri akışına (byte stream) dönüştürerek onları dosyalara veya veritabanlarına yazmayı ve gerektiğinde geri yüklemeyi sağlar.

### Persistent Nesne Kullanım Alanları
- **Veritabanları**: Veritabanındaki kayıtlar kalıcı nesnelerdir. Örneğin, bir müşteri veritabanındaki müşteri bilgileri kalıcıdır ve veritabanı sunucusu kapanıp açılsa bile bu bilgiler silinmez.
- **Dosya Sistemleri**: Dosya sistemine yazılan dosyalar ve belgeler de kalıcı nesnelerdir. Bir uygulama dosyaya veri yazar, kapanıp tekrar açıldığında bu veriyi geri alabilir.
- **Kullanıcı Ayarları**: Kullanıcı arayüzü ayarları, tercihleri veya uygulama durumları kalıcı olarak saklanabilir, böylece uygulama tekrar açıldığında kullanıcı aynı ayarlarla devam edebilir.
- **Oyunlar**: Bir oyunun ilerlemesi, kullanıcı kayıtları kalıcıdır. Oyuncu oyundan çıkıp tekrar girdiğinde kaldığı yerden devam edebilir.
  
### Persistent Nesnelere Örnek

C++'ta persistent nesneleri serileştirmek ve disk üzerinde kalıcı hale getirmek için bir örnek verelim. 
Bu örnekte, bir nesneyi bir dosyaya yazıp, daha sonra dosyadan geri okuyarak yeniden kullanacağız.

### C++ ile Persistent Nesne Örneği (Serileştirme ve Deserileştirme)

#include <iostream>
#include <fstream>  // Dosya işlemleri için gerekli
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Parametreli yapıcı
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Serileştirme (Serialization): Nesneyi dosyaya yazma
    void serialize(const std::string& filename) const {
        std::ofstream outFile(filename, std::ios::binary); // Binary modda dosya açılıyor
        if (outFile.is_open()) {
            size_t nameSize = name.size();
            outFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize)); // İsim boyutu yazılıyor
            outFile.write(name.c_str(), nameSize);  // İsmi yazıyoruz
            outFile.write(reinterpret_cast<const char*>(&age), sizeof(age)); // Yaşı yazıyoruz
            outFile.close();
        }
    }

    // Deserileştirme (Deserialization): Dosyadan nesneyi geri okuma
    static Person deserialize(const std::string& filename) {
        std::ifstream inFile(filename, std::ios::binary); // Binary modda dosya açılıyor
        if (inFile.is_open()) {
            size_t nameSize;
            inFile.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));  // İsim boyutunu okuyoruz
            std::string name(nameSize, ' ');
            inFile.read(&name[0], nameSize);  // İsmi okuyoruz
            int age;
            inFile.read(reinterpret_cast<char*>(&age), sizeof(age));  // Yaşı okuyoruz
            inFile.close();
            return Person(name, age);  // Okunan verilerle yeni Person nesnesi döndürülüyor
        }
        return Person("", 0);  // Dosya açılamazsa varsayılan Person nesnesi döner
    }

    void printInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Persistent olacak Person nesnesi
    Person person("John Doe", 30);
    person.serialize("person.dat");  // Nesneyi dosyaya kaydet

    // Program kapandı ve tekrar açıldı diyelim; dosyadan geri okuyalım
    Person loadedPerson = Person.deserialize("person.dat");
    loadedPerson.printInfo();  // Geri yüklenen nesneyi yazdır

    return 0;
}

### Açıklamalar:
1. **Serileştirme (serialize)**: `Person` nesnesi, `serialize()` fonksiyonu kullanılarak bir dosyaya kaydedilir. 
Bu işlemde nesne verileri bir byte akışına dönüştürülür ve dosyaya yazılır.
   
2. **Deserileştirme (deserialize)**: `deserialize()` fonksiyonu kullanılarak dosyadaki veriler tekrar bir 
`Person` nesnesine dönüştürülür ve programda kullanılabilir hale gelir.

3. **Dosya**: Serileştirilen veri dosya sistemine yazıldığı için program kapandığında bile bu dosyadaki veriler saklanır. 
Program yeniden açıldığında, dosyadan okunan verilerle `Person` nesnesi tekrar oluşturulabilir.

### Persistent Nesnelerin Avantajları
- **Veri Kalıcılığı**: Programın yaşam süresini aşan veri saklama yeteneği sağlar.
- **İstisna Durumlarında Güvenlik**: Bir uygulama kapanırsa, çökme veya başka nedenlerle durursa bile, kalıcı nesneler veriyi güvenli bir şekilde korur.
- **Daha Geniş Uygulamalar**: Kalıcı verilerle çalışan sistemler (veritabanları, dosya yönetim sistemleri) daha geniş ölçekli ve sürekli çalışan uygulamalara olanak sağlar.

### Persistent Nesne Kullanım Alanları:
- **Veritabanı uygulamaları** (SQL/NoSQL sistemleri)
- **Konfigürasyon dosyaları**
- **Oyunlar** (kullanıcı ilerlemesi veya kayıtlar)
- **Bulut tabanlı veri saklama**
- **Web uygulamalarında oturum verileri (cookies, session storage)**
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Kaynağı sağ taraf değeri yapmak onu çaldığmız anlamına gelmez

class MyClass{};

void func(MyClass&& r)
{
    
}

int main()
{
    MyClass m;

    func(std::move(m));

}

Kaynağı çalmamız için burda önemli olan nokta func içinde öyle bir implementasyon olmalı ki sağ taraf referansının bağlandığı
kaynağını çalmalı

1.Ya bir myclass nesnesini hayata getiricez  MyClass m;
2.ya da bir myclass nesnesine atama yapıcaz  MyClass m = std::move(r);
--------------------------------------------------------------------------------------------------------------------------------------------------
5)*"Kaynağı çalınmış nesne in a valid state invariant"* ifadesini incelemek için, iki temel kavramı açıklayarak başlayalım:

1. *Kaynağı çalınmış nesne (Moved Object)*:
   C++ gibi sistem programlama dillerinde, nesneler bir fonksiyona aktarılırken taşınabilir (move semantics). Bu durumda, nesnenin kaynakları 
   (örneğin bellek, dosya tanıtıcıları gibi) orijinal nesneden yeni nesneye aktarılır. Kaynağı taşınan (moved-from) nesne, işlem sonrasında 
   hala geçerli bir durumda olmalıdır. Ancak, bu nesne genellikle boş ya da varsayılan bir hale gelir.

2. *Valid State Invariant (Geçerli Durum Sabiti)*:
   Bir nesne her zaman belirli kurallar veya sabitler çerçevesinde olmalıdır. Bu kurallara "invariant" denir. Bir nesnenin geçerli bir durumda 
   (valid state) olması, nesnenin sınıf tanımında belirtilen kurallar çerçevesinde tüm üye verilerinin anlamlı ve kullanılabilir olduğu anlamına gelir.

Bu bağlamda, *kaynağı çalınmış bir nesne için geçerli durum sabiti (invariant)*, şu anlama gelir: 

- Bir nesnenin kaynakları başka bir nesneye taşındıktan sonra, bu nesne hala geçerli bir durumda kalmalıdır. Yani, her ne kadar içindeki kaynaklar 
başka bir nesneye verilmiş olsa da, bu nesnenin yıkıcısı (destructor) çağrıldığında hata üretmemeli, sınıfın diğer fonksiyonları 
ona eriştiğinde beklenmeyen bir davranış sergilememelidir.
  
Örneğin, bir std::vector'ün kaynakları başka bir vektöre taşındıktan sonra, orijinal vektör boş bir duruma gelir ancak hala geçerlidir 
(valid) yani hala kullanılabilir durumdadır. Boş bir std::vector ile işlevsel operasyonlar yapılabilir (örneğin, boyutunu sorgulamak), 
ancak içerisinde artık eleman bulunmaz.

Bu tür durumlar, yazılımda güvenli bellek yönetimini sağlamak açısından kritik öneme sahiptir.

### Örnek: Kaynağı taşınan bir sınıf

#include <iostream>
#include <utility>
#include <string>

class Resource {
    std::string* data;
public:
    // Yapıcı (Constructor)
    Resource(const std::string& str) : data(new std::string(str)) {
        std::cout << "Kaynak oluşturuldu: " << *data << std::endl;
    }

    // Yıkıcı (Destructor)
    ~Resource() {
        if (data) {
            std::cout << "Kaynak serbest bırakıldı: " << *data << std::endl;
            delete data;
        } else {
            std::cout << "Kaynak zaten boş." << std::endl;
        }
    }

    // Kopya yapıcı (Copy constructor)
    Resource(const Resource& other) : data(new std::string(*other.data)) {
        std::cout << "Kaynak kopyalandı: " << *data << std::endl;
    }

    // Taşıma yapıcı (Move constructor)
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr;  // Kaynak taşındıktan sonra eski nesneyi boş duruma getiriyoruz.
        std::cout << "Kaynak taşındı." << std::endl;
    }

    // Veriyi gösteren fonksiyon
    void show() const {
        if (data) {
            std::cout << "Veri: " << *data << std::endl;
        } else {
            std::cout << "Veri yok (kaynak taşınmış)." << std::endl;
        }
    }
};

int main() {
    Resource r1("Örnek veri");  // r1 kaynağı oluşturulur.
    r1.show();

    // r1'den r2'ye taşıma yapılır (move).
    Resource r2(std::move(r1));
    r2.show();
    r1.show();  // r1 artık kaynağı taşınmış durumda, ancak hala geçerli.

    return 0;
}

### Açıklama:
Bu örnekte bir Resource sınıfı tanımlıyoruz. Bu sınıf, bir std::string kaynağına sahip ve kaynağı taşınabilir (move semantics) 
hale getiriyoruz. İşlemler şu şekilde gerçekleşiyor:

1. *Kaynak oluşturulması*: 
   
   Resource r1("Örnek veri");
   
   r1 isimli nesne, "Örnek veri" adlı bir string'i bellekte oluşturur. Bu noktada r1 kaynağını başarıyla tutuyor. Ekranda "Kaynak oluşturuldu: Örnek veri" mesajı görünür.

2. *Kaynağın taşınması*: 
   
   Resource r2(std::move(r1));
   
   r1'den r2'ye bir taşıma işlemi gerçekleşiyor. Bu noktada, r1'deki veri r2'ye taşınıyor ve r1'in kaynağı artık geçersiz (null) hale geliyor. 
   Ancak **kaynağı çalınmış (moved-from) bir nesne geçerli durumda olmalıdır** kuralına göre, r1 hala kullanılabilir durumda. 
   Taşıma işleminden sonra, r1.show() çağrıldığında veri olmadığını belirten bir mesaj gösterir. 
   Bu, nesnenin hala geçerli olduğunun bir işaretidir, çünkü program hatasız çalışmaya devam eder.

3. *Geçerli Durum Sabiti (Invariant)*: 
   - Taşıma işleminden sonra r1 nesnesi hala geçerlidir, çünkü yıkıcı fonksiyonu çağrıldığında geçerli bir durumda olmalıdır 
   (boş olsa bile yıkıcı sorunsuz çalışır). Ekranda "Veri yok (kaynak taşınmış)." mesajını görürüz. Bu, kaynağın taşındığını, ancak nesnenin hâlâ geçerli durumda olduğunu gösterir.

### Önemli Noktalar:
- Kaynağı taşınan (moved-from) nesneler, geçerli durumda kalmalıdır, yani nullptr olabilirler, ancak yıkılabilir ve güvenli bir şekilde kullanılabilir olmalıdırlar.
- *Geçerli Durum Sabiti (Invariant)* şu anlama gelir: Kaynağı çalınmış bir nesne, programın stabil çalışmasına engel olmaz ve beklenen davranışları yerine getirir, örneğin, boş bir veri ile çalışmak.

Bu örnek, kaynağı taşınmış nesnelerin nasıl kullanıldığını ve geçerli durum sabitinin nasıl korunduğunu gösteriyor.
--------------------------------------------------------------------------------------------------------------------------------------------------
kaynağı çalışnmış nesne in a valid state durumundadır yani geçerli bir nesnedir
a)sınıfın invariantları korunmuş olucak
b)destructorun çağırılması her hangi bir soruna yol açmicak yani nesnenin yok edilmesi sorun değil

NOT:moved from state ki nesnenin değeri konusunda garanti yoktur

c)nesneye yeni bir değer atayarak onu tekrar kullanabiliriz moved from state olarak verdiği garanti bu

"Moved-from state", bir nesnenin kaynaklarının move semantics kullanılarak başka bir nesneye taşınmasından 
sonra kalan durumunu ifade eder. Bu, C++'ta bir nesne, move constructor veya move assignment operator 
aracılığıyla "kaynağını taşıdığında" oluşur.

Moved-from state, tanımsız bir durum değil, genellikle "geçerli fakat tanımlı bir durum" olarak tasarlanmalıdır.
Bir moved-from nesne, güvenli bir şekilde yok edilebilir ve sınıfın public API'sine yapılan çağrılarda hata oluşturmamalıdır.

1. Moved-From State Nedir?
Bir nesne, move operation (taşıma işlemi) sırasında sahip olduğu kaynağı başka bir nesneye taşır. 
Bu durumda, kaynakları taşınan (moved-from) nesne, genellikle:

Kaynaklarının boş bir durumuna getirilir (örneğin, bir pointer ise nullptr atanır).
Kapsayıcı sınıflar (std::vector, std::string gibi) için "boş" bir duruma geçer.
Not: Moved-from nesne, sınıf tasarımına bağlı olarak tanımlı bir durumda olmalıdır. 
Ancak davranışı genellikle sınıfın tasarımcılarına bırakılır.

2. Moved-From Nesnenin Özellikleri
Geçerli Olmalıdır:
Moved-from bir nesne hala geçerli bir durumdadır (yani, programın çökmesine neden olmaz).

Boş veya Default Durumunda Olmalıdır:
Çoğu sınıf, moved-from durumda üye değişkenlerini varsayılan değerlere (default) geri döndürür.

Kullanılabilir Olabilir ya da Olmayabilir:
Bir moved-from nesne üzerinde işlem yapmaya devam etmek, sınıfın tasarımına bağlıdır. Genelde, API çağrıları boş bir durumda anlamlıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfta copy constructor ve copy assginment delete edilmişse bu sınıflara non-copyable sınıflar nedir
NOT:move contructor ve move assginment varsa move only nedir
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfta herhangi bir special member function yoksa derleyici hepsini impilictly declared olarak default bildirir

class Myclass
{
    Myclass() = default;
    ~Myclass() = default;
    Myclass(const Myclass&) = default;
    Myclass(Myclass&&) = default;
    Myclass& operator=(const Myclass&) = default;
    Myclass& operator=(Myclass&&) = default;

} derleyicinin yaptığı implicitly olarak budur
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa special member function olan yada olmayan her hangi bir constructor bildirilirse derleyici default contructoru 
implictly decalred etmez default constructor not declared durumuna düşer diğer special member functionlar hala implicitly declared edilmiş haldedir
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa default constructor user declared edilmişse diğer specail member functionlar
hala implicit declared edilmiş haldedir
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa Destructor user declared olarak bildirilirse 
default contructor derleyici tarafından implicitly declared olarak default edilir
copy constructor derleyici tarafından implicitly declared olarak default edilir ->istenmeyen durum deprecated
copy assginment operator derleyici tarafından implicitly declared olarak default edilir ->istenmeyen durum deprecated

move contructor olmaz/not declared
move assignment operator olmaz/not declared

NOT:Destructor user declared olduğu zaman move constructor ve move assignment operator default edilmez
ve bu deprecated(gelecekti standartlarda bu tamamen sentaks hatasına yol açabilir) edilmiştir asla olmaması gereken bir şey
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa copy constructor user declared olarak bildirilirse 
copy assignment operator derleyici tarafından implicitly declared olarak default edilir ->istenmeyen durum deprecated
destructor derleyici tarafından implicitly declared olarak default edilir

default contructor olmaz/not declared
move constructor/not declared 
move assignment operator olmaz/not declared
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa copy assignment user declared olarak bildirilirse
contructor derleyici tarafından implicitly declared olarak default edilir
destructor derleyici tarafından implicitly declared olarak default edilir
copy contructor derleyici tarafından implicitly declared olarak default edilir ->istenmeyen durum deprecated

move constructor olmaz/not declared
move assginment operator olmaz/not declared
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa move constructor user declared olarak bildirilirse
destructor derleyici tarafından implicitly declared olarak default edilir

move assignment operator olmaz/not declared
default contructor olmaz/not declared
copy constructor var ama/delete edilmiştir
copy assignment var ama/delete edilmiştir
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa move assignment operator user declared olarak bildirilirse
default constructor derleyici tarafından implicitly declared olarak default edilir
destructor derleyici tarafından implicitly declared olarak default edilir

move constructor olmaz/not declared
copy constructor/delete edilmiştir
copy assignment operator/delete edilmiştir
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Bir sınıfın her zaman destructorı vardır
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfa eskiden big three denilen 
destructor
copy ctor
copy assignment 
    bunlardan her hangi bir tanesini bildirirsek derleyici move memberları bildirmez/not declared

NOT:Sınıfa move memberlardan her hangi birini bildirirsek derleyici copy memberları delete eder
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT: bir sınıfta copy memberları delete etmek istenebilir bir şeydir ama
move memberları yani move constructor ve Move assignment operator asla delete edilmemeli çünkü
move gereken yerde sentaks hatası olur move memberlar delete edilmese ama sınıfta copy contructor olsaydı
move gereken yerde kopyalamaya fall back olurdu
 ****************************************************************************************************************************** 
      
                                                                       ********* 13-DERS NOTLARI *********
1)**Temporary Materialization**, C++ dilinde geçici nesnelerin (temporary objects) oluşturulma sürecini tanımlar. 
Bu durum, bir ifadenin veya dönüş değerinin, daha karmaşık işlemler veya bağlanmalar için geçici bir nesneye dönüştürülmesi gerektiğinde ortaya çıkar. 

Bu süreç, genellikle atama, fonksiyon çağrısı veya referans bağlama gibi durumlarda devreye girer. **C++17**
ile birlikte kurallar ve mekanizmalar daha belirgin hale getirilmiş ve dilde yapılan iyileştirmelerle geçici 
nesnelerin yaşam döngüsü daha iyi yönetilmeye başlanmıştır.

### **Temporary Materialization'ın Temel İlkeleri**

1. **Geçici Nesnelerin Doğuşu:**
   - Geçici nesneler, genellikle ifadelerin veya dönüş değerlerinin, bir referansa bağlanmadan önce materyalleştirilmesiyle oluşturulur.
   - Bu, genellikle literal türleri (ör. `std::string("Hello")` gibi) veya başka bir nesnenin kopyası ya da taşıması olan türlerde olur.

2. **Bağlama Türleri:**
   - **Geçici Nesnelerin Referanslara Bağlanması:**
     - Geçici nesneler, `const` bir lvalue referansa veya bir rvalue referansa bağlanabilir. Bu bağlama sırasında nesne materyalleştirilir.
   - **Geçici Nesnelerin Kaydırılması (Move Semantics):**
     - Bir geçici nesne taşınabilir bir hedefe bağlanıyorsa, materyalleştirme taşınma semantiğiyle gerçekleşebilir.

3. **Oluşum ve Yaşam Süresi:**
   - Geçici bir nesne materyalleştirildiğinde, genellikle ifade değerlendirilirken oluşturulur ve tipik olarak, 
   ifade sona erdiğinde veya daha uzun süreli bir bağlama yoksa yok edilir.
   - **C++17** ile geçici nesnenin yaşam süresi, eğer bir referansa bağlanıyorsa, referansın yaşam süresiyle eşleşir.

### **Temporary Materialization Örnekleri**

#### **Basit Örnek:**

#include <string>
#include <iostream>

void printString(const std::string& s) {
    std::cout << s << std::endl;
}

int main() {
    printString(std::string("Hello, World!")); // Temporary materialization
    return 0;
}

Yukarıdaki kodda:
- `std::string("Hello, World!")` ifadesi geçici bir nesne oluşturur.
- Bu geçici nesne, `const std::string&` parametresine bağlanır ve materyalleştirilir.

#### **Lambda ve Geçici Nesneler:**

#include <iostream>

int main() {
    auto lambda = [](const std::string& str) {
        std::cout << str << std::endl;
    };

    lambda(std::string("Temporary")); // Materialization of a temporary std::string
    return 0;
}

Burada:
- Lambda ifadesine geçici bir `std::string` nesnesi geçirilir ve bu nesne materyalleştirilir.

### **C++17 ve Temporary Materialization**
**C++17**, temporary materialization ile ilgili önemli değişiklikler yaptı:
- **Ifade Değerlendirme:** Daha önce materyalleştirme gerektiren bazı durumlar, artık gerektirmez. 
Örneğin, sınırlı optimizasyonlar yapılabilir.
- **Kopya Elisyonu ve Zorunlu Materyalleştirme:** C++17'de kopya elisyonunun zorunlu hale gelmesi, 
temporary materialization'ın kapsamını daha iyi anlamayı gerektirir.

Örnek:

struct MyStruct {
    MyStruct(int) {  }
};

void process(const MyStruct&) {}

int main() {
    process(MyStruct{ 42 }); // Materialization occurs for the temporary MyStruct
}

###  * *Temporary Materialization'ın Kullanım Alanları**
1. * *Fonksiyon Argümanları : **
-Geçici nesneler sıklıkla bir fonksiyon çağrısına argüman olarak geçirilir.
2. * *Standart Kütüphane Fonksiyonları : **
-`std: : move` veya `std::forward` gibi yardımcı fonksiyonlar geçici nesneler üzerinde çalışır.
3. * *Operator Overloading : **
-Geçici nesneler operatör aşırı yüklemede sıkça kullanılır.
4. * *Geçici Nesnelerin Referanslara Bağlanması : **
-`const lvalue` ve `rvalue` referanslar, geçici nesnelere bağlanarak materyalleştirme sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Mandatory Copy Elision**(Zorunlu Kopya Eleme), diğer adı guaranteed copy eliison C++17 standardıyla birlikte dilde bazı durumlarda 
**copy elision** işlemini zorunlu kılan bir özelliktir. **Copy elision** (kopyalama kaldırma), bir nesnenin 
kopyalanmasını veya taşınmasını önlemek için derleyicinin yaptığı bir optimizasyondur. Ancak C++17 öncesinde, 
bu optimizasyon isteğe bağlıydı ve derleyiciye bırakılmıştı. C++17 ile birlikte, belirli durumlarda bu işlem zorunlu hale getirildi.

### **Mandatory Copy Elision Nedir?**
Mandatory Copy Elision, aşağıdaki durumlarda kopyalama veya taşıma işleminin ortadan kaldırılmasını zorunlu kılar:

1. **Return Value Optimization (RVO):**
   - Bir fonksiyonun bir yerel nesneyi (`local object`) döndürmesi durumunda, o nesne doğrudan çağıran bağlamda (örneğin, ana fonksiyonda) oluşturulur.
   - Kopyalama ya da taşıma constructor çağrılmaz.

2. **Throw İfadelerinde:**
   - Bir nesne bir `throw` ifadesiyle fırlatıldığında, nesne doğrudan exception handling 
   mekanizmasında oluşturulur. Kopyalama veya taşıma işlemi yapılmaz.

Bu optimizasyonlar, artık standart tarafından zorunlu hale getirildiği için dil seviyesinde tutarlı bir davranış sağlar.

### **Örnek 1: Return Value Optimization (RVO)**

#include <iostream>

struct MyClass {
    MyClass() { std::cout << "Default Constructor\n"; }
    MyClass(const MyClass&) { std::cout << "Copy Constructor\n"; }
    MyClass(MyClass&&) { std::cout << "Move Constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
};

MyClass createObject() {
    return MyClass(); // RVO: Nesne doğrudan main'deki bağlamda oluşturulacak.
}

int main() {
    MyClass obj = createObject();
    return 0;
}

**C++17 ve Sonrası Çıktısı:**

Default Constructor
Destructor

- `createObject()` fonksiyonu içinde oluşturulan `MyClass` nesnesi doğrudan `obj` içinde oluşturulur.
- Kopya veya taşıma constructor'ları çağrılmaz.

### **Örnek 2: Throw İfadesinde Copy Elision**

#include <iostream>

struct MyException {
    MyException() { std::cout << "Default Constructor\n"; }
    MyException(const MyException&) { std::cout << "Copy Constructor\n"; }
    MyException(MyException&&) { std::cout << "Move Constructor\n"; }
    ~MyException() { std::cout << "Destructor\n"; }
};

int main() {
    try {
        throw MyException(); // Copy elision: Geçici nesne doğrudan exception mekanizmasında oluşturulur.
    } catch (const MyException&) {
        std::cout << "Exception caught\n";
    }
    return 0;
}

**C++17 ve Sonrası Çıktısı:**
* 
Default Constructor
Destructor
Exception caught

- Fırlatılan `MyException` nesnesi doğrudan exception handling mekanizmasında oluşturulur.
- copy veya move constructor'ı çağrılmaz.

### **Cppreference'deki Açıklama**
Cppreference'de **mandatory copy elision**, şu durumları kapsar:

1. **Return Statements (RVO):**
   Bir fonksiyon bir yerel nesneyi return ederse ve bu nesne bir lvalue referansına bağlanmazsa, 
   derleyici nesneyi doğrudan çağıran bağlamda oluşturur.

2. **Throw Statements:**
   Bir `throw` ifadesinde geçici bir nesne oluşturuluyorsa, bu nesne doğrudan exception handling mekanizmasında oluşturulur.

3. **Kopyalama ve Taşıma Yapıcıların Çağrılmaması:**
   Bu durumlarda, sınıfın copy veya move constructor'larının olması gerekmez, çünkü derleyici bu işlevleri çağırmaz.

### **Mandatory Copy Elision ile İlgili Önemli Notlar**
1. **Dil Seviyesinde Zorunluluk:**
   - Derleyicinin bu optimizasyonları uygulaması artık zorunludur.
   - Kopyalama kaldırma (copy elision), dilin semantiğinin bir parçası haline gelmiştir, sadece bir optimizasyon değildir.

2. **copy ve move Constructor'larının Gerekli Olmaması:**
   - Eğer bir fonksiyon sadece copy elision zorunluluğuna bağlı bir `return` ifadesi içeriyorsa, 
   sınıfın copy veya move constructor'larının tanımlanması gerekmez.

3. **C++17 Öncesi Durum:**
   - Copy elision isteğe bağlı bir optimizasyondur ve farklı derleyiciler farklı davranışlar 
   sergileyebilir. C++17 sonrası bu davranış standartlaşmıştır.

### **Özet**
Mandatory Copy Elision:
- C++17 ile dil tarafından zorunlu hale getirilen copy elision durumudur.
- Return Value Optimization (RVO) ve `throw` ifadeleri gibi durumlarda geçerlidir.
- Performansı artırır ve programın daha tutarlı davranmasını sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
pr value U X value = R value;
L value U X value = GL value 
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **Named Return Value Optimization (NRVO)**, bir fonksiyondan isimlendirilmiş bir yerel değişkenin 
döndürülmesi sırasında kopyalama veya taşıma işlemlerini ortadan kaldırarak performansı artıran bir derleyici 
optimizasyonudur. Bu optimizasyon, döndürülen nesnenin doğrudan çağıran kodun belleğinde oluşturulmasını sağlar, 
böylece gereksiz kopyalama işlemleri engellenir.

**NRVO Nasıl Çalışır?**

Bir fonksiyon içinde bir yerel değişken tanımlandığında ve bu değişken fonksiyondan döndürüldüğünde, normalde bir kopya 
veya taşıma işlemi gerçekleşir. NRVO ile derleyici, bu yerel değişkeni doğrudan çağıran kodun belleğinde oluşturur, 
böylece ek kopyalama veya taşıma işlemlerine gerek kalmaz.

**Örnek:**

class MyClass {
public:
    MyClass() {  }
    MyClass(const MyClass&) { } // Kopya yapıcı
    // ...
};

MyClass createObject() {
    MyClass obj;
    // obj üzerinde işlemler
    return obj; // NRVO uygulanırsa, kopyalama olmadan döndürülür
}

Yukarıdaki örnekte, `createObject` fonksiyonu bir `MyClass` nesnesi oluşturur ve döndürür.NRVO uygulanırsa, 
`obj` nesnesi doğrudan çağıran kodun belleğinde oluşturulur ve kopyalama işlemi gerçekleşmez.

** Derleyici Desteği : **

NRVO, modern C++ derleyicileri tarafından yaygın olarak desteklenir.Ancak, derleyicinin bu optimizasyonu 
uygulayıp uygulamaması, kodun yapısına ve derleyicinin optimizasyon seviyesine bağlıdır.Örneğin, Microsoft 
Visual C++ derleyicisinde NRVO desteği `/Zc : nrvo` seçeneğiyle kontrol edilebilir.

* *Dikkat Edilmesi Gerekenler : **

-NRVO, derleyicinin uygulayabileceği bir optimizasyondur, ancak her durumda garanti edilmez.

- Fonksiyon içinde birden fazla dönüş noktası veya farklı yerel değişkenlerin döndürülmesi gibi durumlar, NRVO'nun uygulanmasını engelleyebilir.

- C++17 ile birlikte, belirli durumlarda copy elysionu zorunlu hale getirilmiştir, ancak NRVO hala derleyicinin takdirine bağlıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:C++17 ile birlikte

class Myclass{};

void func(Myclass)
{

}

int main() {

    func(Myclass{});

    return 0;
}

burda sadece func içinde default constructor çağrılır 
--------------------------------------------------------------------------------------------------------------------------------------------------
2)**Conversion Constructor**, bir türün başka bir türe dönüşümünü sağlamak için tanımlanan, bir parametre alan 
yapıcılardır (constructors). C++ dilinde, bir sınıfın bu türden bir yapıcısı, **explicit** olarak işaretlenmemişse, 
derleyici otomatik dönüşümlerde bu yapıcıyı kullanabilir. 

### **Conversion Constructor'ın Özellikleri**

1. **Tek Parametreli Constructor:**
   - **Conversion Constructor**, genellikle tek bir parametre alır ve bu parametreyi kullanarak nesne oluşturur.
   - Örneğin, bir `std::string` yapıcısı, `const char*` parametresi alarak, bir C tarzı dizeyi `std::string` nesnesine dönüştürebilir.

2. **Implicit ve Explicit Dönüşüm:**
   - Eğer yapıcı **explicit** olarak işaretlenmemişse, bu dönüşüm **implicit** olarak gerçekleştirilebilir.
   - **explicit** olarak işaretlenirse, yalnızca açık bir şekilde çağrıldığında kullanılabilir.

3. **Kullanım Alanları:**
   - Tür dönüşümünü kolaylaştırır. Örneğin, bir sınıfın bir temel türden (ör. `int`) türetilmiş nesnelere dönüştürülmesini sağlar.

### **Conversion Constructor Örnekleri**

#### **Implicit Conversion Constructor**

#include <iostream>
#include <string>

class MyClass {
public:
    MyClass(int x) : value(x) { } // Conversion constructor
    void print() const {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};

int main() {
    MyClass obj = 42; // Implicit conversion from int to MyClass
    obj.print();      // Output: Value: 42
    return 0;
}

Yukarıdaki örnekte:
- `MyClass(int x)` bir dönüşüm yapıcısıdır.
- `42` gibi bir `int` değeri, `MyClass` türüne otomatik olarak dönüştürülür.

#### **Explicit Conversion Constructor**

#include <iostream>

class MyClass {
public:
    explicit MyClass(int x) : value(x) { } // Explicit conversion constructor
    void print() const {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};

int main() {
    // MyClass obj = 42; // Hata: Explicit constructor implicit dönüşümü engeller.
    MyClass obj(42);     // Doğru: Açık bir şekilde çağrılıyor.
    obj.print();         // Output: Value: 42
    return 0;
}

Yukarıdaki örnekte:
- **explicit** anahtar sözcüğü, `int` türünden `MyClass` türüne otomatik dönüşümü engeller.
- Yapıcı yalnızca açık bir çağrı yapıldığında kullanılabilir.

#### **Conversion Constructor Kullanımı ve Tür Dönüşümü**
Conversion Constructor, aşağıdaki gibi otomatik tür dönüşümlerinde yaygın olarak kullanılır:

#include <string>
#include <iostream>

void printString(const std::string& str) {
    std::cout << str << std::endl;
}

int main() {
    printString("Hello, World!"); // Conversion from const char* to std::string
    return 0;
}

Burada:
- `"Hello, World!"` bir `const char*` türüdür.
- `std::string` sınıfındaki `std::string(const char*)` yapıcısı, bu dönüşümü sağlar.

### **Conversion Constructor ve Type Casting**

1. **Static Cast ile Kullanım:**

   MyClass obj = static_cast<MyClass>(42);

   - `static_cast`, explicit bir dönüşüm için kullanılabilir.

2. **Implicit Dönüşüm Tehlikeleri:**
   - İstenmeyen veya beklenmeyen tür dönüşümlerine yol açabilir.
   - **explicit** anahtar sözcüğü, bu tür tehlikeleri önler.

### **Conversion Constructor ile İlgili Kurallar**

1. **explicit** Kullanımı:
   - **C++11**'den itibaren, yapıcılar explicit olarak işaretlenebilir.
   - Bu işaretleme, dönüşümün yalnızca açık bir şekilde yapılmasını zorunlu kılar.

2. **C++17 ile Genelleşmiş (Deduction Guides):**
   - **C++17** ile, sınıf şablonlarının dönüşüm kuralları daha karmaşık hale geldi. 

NOT:Sınıfın tek parameteli constrcutorlarını başka bir durum söz konusu değilse explicit yapınız
olmayadabilir en basit örnek string sınıfı

string str = "emre";

NOT: Myclass x = {} -> Myclass x = Myclass{} ile eşittir explicit olduğunda ise hata verir
--------------------------------------------------------------------------------------------------------------------------------------------------
class Myclass
{
public:
    Myclass(int); // explicit
};

void func(Myclass);

int main()
{
    func(132); // conversion constructor explicit olsaydı hata verirdi
}
--------------------------------------------------------------------------------------------------------------------------------------------------
class Myclass
{
public:
    explicit Myclass(int); 
             Myclass(double); 
};

int main()
{
    Myclass m = 12; // sentaks hatası vermez double parametreli olan çağırılır explicit olan constructor overload resolutiona dahil edilmez
}
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Class türünden int türüne dönüşüm olmadığı için hata verir ancak

class Nec{
 // operator int()const;
};

int main() {

    Nec mynec;
    int ival;

    ival = mynec;

}
operator overloading sayesinde class türünden int türüne implicit olarak dönüşüm olabilir -> operator int()const;

NOT:eğer bir implicit conversion

 (conversion sequince) deniliyor
1.önce standart conversion  + user defined conversion = uygulanarak conversionlar yapılabiliyorsa önce standart conversionu uygular ondan sonra user defined conversionu uygular
2.önce user defined conversion + standart conversion uygulayarak dönüşümü gerçekleştirebiliyorsa derleyici yine bu dönüşümü yapmak zorunda
3.ama eğer dönüşüm arka arkaya user defined conversion + user defined conversion ile yapılabiliyorsa derleyici hiç bir zaman bu dönüşümü örtülü olasrak yapmaz
--------------------------------------------------------------------------------------------------------------------------------------------------
3)**Conditional `explicit`** (koşullu explicit), C++20 ile gelen bir özelliktir ve bir yapıcı veya dönüştürücü fonksiyonun 
`explicit` olup olmamasını derleme zamanında belirli koşullara bağlı olarak kontrol etmenizi sağlar. Bu özellik, şablonlu sınıflar
ve şablonlu yapıcılar kullanırken büyük bir esneklik sağlar.

C++'ta normalde, bir yapıcıyı `explicit` olarak işaretleyerek otomatik tür dönüşümünü engelleyebilirsiniz. Ancak bazı durumlarda, yapıcının 
`explicit` olup olmamasını derleme zamanında belirli koşullara göre ayarlamak isteyebilirsiniz. **Conditional `explicit`** tam da bu noktada devreye girer.

### Syntax

explicit (condition)

`condition` ifadesi bir `constexpr` boolean ifadesi olmalıdır. Bu ifade `true` olduğunda yapıcı `explicit` olur, 
`false` olduğunda ise **implicit** olur (yani otomatik tür dönüşümüne izin verir).

### Örnek: Conditional `explicit`

#include <iostream>
#include <type_traits>  // std::is_integral

template<typename T>
class MyClass {
public:
    // Conditional explicit constructor
    explicit(std::is_integral<T>::value) MyClass(T value) {
        std::cout << "Constructor called with value: " << value << "\n";
    }
};

int main() {
    MyClass<int> obj1(10);       // Geçerli: int integral türdür ve explicit bir şekilde olduğu için hata vermez 
    // MyClass<int> obj2 = 10;   // Hata: implicit dönüşüm yok çünkü int integral tür
    MyClass<double> obj3 = 3.14;  // Geçerli: double integral değildir, implicit dönüşüm olur
}

### Açıklama:

- `MyClass` şablon sınıfında bir conversion constructor tanımlanmıştır.
- Bu constructor `explicit(std::is_integral<T>::value)` ile işaretlenmiştir. Yani, `T` türü integral (tamsayı) bir türse, bu constructor 
`explicit` olacak ve **implicit conversion**'a (örtülü dönüşüme) izin vermeyecektir. - Eğer `T` integral olmayan bir türse (örneğin `double`), 
constructor `explicit` olmayacak ve **implicit conversion** mümkün olacaktır.

#### Çıktı:

Constructor called with value: 10
Constructor called with value: 3.14

### Uygulama Alanları:

- **Şablonlu Sınıflar**: Bir sınıfın farklı türler için farklı dönüşüm davranışlarına sahip olmasını istediğinizde faydalıdır.
- **Performans İyileştirmeleri**: Implicit ve explicit davranışlar arasında koşullu geçiş sağlayarak daha iyi kontrol sunar.
- **Derleme Zamanı Kontrolü**: `constexpr` boolean ifadeler ile koşullu olarak derleyiciye explicit olup olmayacağına karar verdirebilirsiniz.

### Koşullu `explicit` Kullanımının Avantajları:

1. **Daha Esnek Tür Dönüşümü**: Farklı türler için farklı davranışlar tanımlayarak daha esnek tür dönüşüm kuralları uygulayabilirsiniz.
2. **Güvenlik**: Belirli türlerde istemediğiniz otomatik tür dönüşümlerini engelleyebilir ve yalnızca açık tür dönüşümlerine izin verebilirsiniz.
3. **Şablonlarda Güçlü Tür Kontrolü**: Şablonlu sınıflar veya fonksiyonlar ile çalışırken, explicit olup olmama durumunu derleme zamanında belirlemek daha güçlü bir tür kontrolü sağlar.

### Özet:

- **Conditional `explicit`**, C++20 ile gelen ve bir constructor'ın `explicit` olup olmayacağını koşullu olarak belirlemenizi sağlayan bir özelliktir.
- Bu mekanizma, özellikle şablonlu yapılarla çalışırken yararlıdır, çünkü farklı türler için farklı dönüşüm kurallarını uygulamanıza olanak tanır.
- Kullanımı basittir ve `constexpr` boolean ifadeler ile koşullandırılabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
4)**Delegating Constructor**, C++11 ile tanıtılan bir özellik olup, bir sınıfın bir kurucusunun (constructor) 
aynı sınıftaki başka bir kurucuyu çağırmasına izin verir. Bu mekanizma, kurucu fonksiyonların tekrar eden 
kodlarını önlemek ve daha modüler bir yapı oluşturmak için kullanılır.

### **Temel Kavram**
Bir "delegating constructor", sınıfın diğer bir kurucusunu çağırır ve ardından çağrılan kurucunun 
yaptığı işleme dayanarak sınıfın geri kalanını tamamlar.  
Bu, bir kurucu içinde tekrar eden kodun önüne geçerek kodun daha temiz ve sürdürülebilir olmasını sağlar.

### **Kurallar**
1. Delegating constructor, **aynı sınıfın başka bir kurucusunu çağırır**.
2. Çağrılan kurucu, çağıran kurucunun gövdesinden önce çalışır.
3. Delegating constructor, **constructor initializer list** kullanarak başka bir kurucuyu çağırmalıdır.
4. Bir sınıfta **sonsuz döngüye neden olmamak** için delegasyon zinciri dikkatli tasarlanmalıdır.

### **Temel Sentaks**

class MyClass {
public:
    MyClass(int x, int y) {
        // Ana işlevsellik burada
    }

    // Delegating constructor
    MyClass(int x) : MyClass(x, 0) { 
        // Ek işlevsellik burada
    }

    MyClass() : MyClass(0, 0) { 
        // Ek işlevsellik burada
    }
};

Bu örnekte:  
- `MyClass(int x, int y)` ana işlevselliği sağlar.  
- `MyClass(int x)` ve `MyClass()` bu ana kurucuyu kullanarak gerekli işlemleri gerçekleştirir.  

### **Örnek Kullanım**
Aşağıdaki örnek, bir delegating constructor'ın nasıl çalıştığını gösterir:

#### **Kod:**

#include <iostream>
#include <string>

class Person {
    std::string name;
    int age;

public:
    // Ana kurucu
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Ana kurucu çağrıldı.\n";
    }

    // Delegating constructor: Varsayılan yaş 0
    Person(const std::string& name) : Person(name, 0) {
        std::cout << "Delegating kurucu: Yaş varsayılan olarak 0 alındı.\n";
    }

    // Delegating constructor: Varsayılan ad "Unknown", yaş 0
    Person() : Person("Unknown", 0) {
        std::cout << "Delegating kurucu: Ad ve yaş varsayılan olarak belirlendi.\n";
    }

    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << '\n';
    }
};

int main() {
    Person p1("Alice", 25);  // Ana kurucu
    Person p2("Bob");        // Delegating kurucu
    Person p3;               // Delegating kurucu

    p1.print();
    p2.print();
    p3.print();

    return 0;
}

#### **Çıktı:**

Ana kurucu çağrıldı.
Delegating kurucu: Yaş varsayılan olarak 0 alındı.
Ana kurucu çağrıldı.
Delegating kurucu: Ad ve yaş varsayılan olarak belirlendi.
Ana kurucu çağrıldı.
Name: Alice, Age: 25
Name: Bob, Age: 0
Name: Unknown, Age: 0

### **Avantajları**
1. **Tekrarı Azaltır:** Aynı kodun birden fazla kurucuda yazılmasını önler.  
2. **Bakımı Kolaylaştırır:** Bir kurucuda yapılan değişiklikler diğer tüm delegating constructor'lara yansır.  
3. **Kapsamlı ve Modüler Yapı:** Ana kurucuda temel işlevselliği sağlayarak diğer kurucuların 
sadece özel durumlar için farklılık eklemesine izin verir.

### **Dikkat Edilmesi Gerekenler**
1. **Sonsuz Döngüden Kaçının:** Bir constructor'ın dolaylı veya doğrudan kendisini çağırması, 
sonsuz döngüye neden olur ve bu derleme hatası üretir.

   class MyClass {
   public:
       MyClass() : MyClass(0) {}      // Delegates to MyClass(int)
       MyClass(int x) : MyClass() {} // Delegates back to MyClass()
   };

   Bu kod, **sonsuz döngü** oluşturur ve hataya neden olur.

2. **Ek Performans Maliyeti:** Delegating constructor'lar, gereksiz delegasyon durumlarında 
performans kaybına neden olabilir. Kodunuzu bu açıdan optimize edin.


class Myclass {
public:
    Myclass(int a) : Myclass(a, a, a)		// işte buradaki yapı delegating constructor. Init görevini alaşıdaki ctora havale etti.
    {
        std::cout << "Myclas(int)\n";

    }
    Myclass(int a, int b) : Myclass(a, b, 0)  //Buda aşağıdakine havale etti.
    {
        std::cout << "Myclas(int,int)\n";

    }
    Myclass(int x, int y, int z) : mx{ x }, my{ y }, mz{ z }
    {
        std::cout << "Myclas(int,int,int)\n";

    }
    Myclass(const char* p) : Myclass(std::atoi(p), 0, 0) //aynı şekilde 3 parametreli ctora havale etti bu işi.
    {
        std::cout << "Myclas(const char*)\n";

    }

    void print()
    {
        std::cout << mx << " " << my << " " << mz<<'\n';
    }
private:
    int mx, my, mz;
};
int main()
{

    Myclass m{ 5 }; // önce Myclass(int,int,int) hayata gelir ondan sonra Myclass(int) hayat gelir

    m.print();

}


ÖNEMLİ KURAL
Hem delege edip hemde elemana tekrar ilk değer veremeyiz.!!!

Yukarıdan Bir örnek
Myclass(int a,int b) : Myclass(a,b,0)  , mz{10}  //Burası hem delege edip hemde initilization etmeye çalışmış SENTAKS HATASI
{

}

Burada default member initializer sentaki kullanilabilir.
Eğer delege ettiğimiz ctor ilk değer vermezse tabi.

class Myclass{
public:
    Myclass(int a,int b) : Myclass(a,b)  //3. parametre yok
    {

    }
    Myclass(int x,int y,int z) : mx{x}, my{y} //burada da init edilmemiş ama aşağıda default member initten buraya yazılır compiler tarafından
    {

    }

private:
    int mx, my, mz = 25;
};

NOT : DELEGE SAYISI 1 OLMAK ZORUNDA DEĞİL. BİRİ BİR CTORU DELEGE EDER, DELEGE ETTİĞİ İSE BİR BAŞKASINI DELEGE EDER.

NOT : RECURSİVE(RECURSIVE BİR FUNC CALL MEKANİZMASI) BİR DELEGE OLMAMASI GEREKİR. YA SENTAKS HATASI YA DA UB.
--------------------------------------------------------------------------------------------------------------------------------------------------
5)friend bildirimi

Sınıfın üye işlevi olmayan herhangi bir işleve, o sınıfın private ve protected bölümlerine erişim hakkı verilebilir. 
Bir işlev bir sınıfın arkadaş işlevi olarak bildirilebilir. Bir işlevi bir sınıfın arkadaş işlevi olarak bildirmek için işlev 
bildiriminin önüne friend anahtar sözcüğü yazılır. Aşağıdaki sınıf bildirimini inceleyin:

class Account { 
    int account_no; 
    double balance;
public;
//...
    friend double balance_dif(const Account &, const Account &);
//...
};

Bu örnekte balance_dif global bir işlevdir. Ancak Account sınıfı içinde friend anahtar sözcüğüyle arkadaş işlev 
olarak bildiriliyor. Arkadaş işlevler yalnızca erişim bakımından ayrıcalıklı olan işlevlerdir. Bir arkadaş işlev içinde 
arkadaş olunan sınıfa ilişkin bir nesne, gösterici ya da referans tanımlanırsa, o nesne gösterici ya da referans 
yoluyla sınıfın her bölümüne erişilebilir. Yukarıdaki örnekte balance_dif işlevi Account sınıfının bir arkadaş 
işlevi olarak bildirilmiştir. Bu yüzden balance_dif işlevi içinde tanımlanan Account sınıfına ilişkin bir sınıf 
nesnesi ile sınıfın her bölümüne erişilebilir.

class A {
    int x, int y; 
public:
    A(int, int);
    friend void func();
};

Yukarıdaki örneği inceleyelim. A sınıfının x ve y isminde iki private elemanı var. func isimli global işlev sınıfın 
arkadaş işlevi olarak bildiriliyor. func global bir işlev olmasına karşın func işlevi içinde tanımlanan A sınıfı 
türünden nesnelerin private elemanları için erişim sınırlaması ortadan kalkar:

void func()
{
    A a;
    a.x = 10; // private bölüme erişiliyor ama geçerli
    a.y = 20; // private bölüme erişiliyor ama geçerli
//...
}

Eğer func normal bir işlev olsaydı, yani A sınıfının arkadaş işlevi olmasaydı a.x ve a.y erişimleri geçersiz 
olurdu. friend anahtar sözcüğünün yalnızca işlevin bildiriminde kullanılmalıdır. İşlevin tanımında friend 
anahtar sözcüğünün yazılması bir sözdizim hatasıdır.
Arkadaş işlevler sınıfın üye işlevleri değildir. Arkadaş işlevlerin diğer global işlevlerden tek farkı erişim 
ayrıcalığına sahip olmalarıdır. Arkadaş işlevlere this göstericisi geçirilmez. Bu nedenle sınıfın elemanlarına 
arkadaş işlevler içinde doğrudan erişilemez.
Uygulamalarda genellikle arkadaş işlevlerin parametre değişkeni arkadaş olunan sınıfa ilişkin bir gösterici ya 
da referans olur. İlk örnekteki Account sınıfına balance_dif işlevini inceleyelim:

double balance_dif(const Account &r1, const Account &r2)
{
    return r1.balance - r2.balance;
}

İşlevlerin parametre değişkenleri işlev sınırları içindedir. Yani arkadaş bir işlevin parametre değişkeni 
arkadaş olunan sınıfa ilişkin bir nesne, bir gösterici ya da bir referans ise bu nesne, gösterici ya da referans 
ile sınıfın her bölümüne erişilebilir. Yukarıdaki balance_dif işlevinin tanımında, işlevin parametre değişkeni 
olan r1 ve r2 referansları nokta işleci ile kullanılarak ismi balance olan private elemana erişiliyor. Şüphesiz 
balance_dif işlevi Account sınıfı içinde friend işlev olarak bildirildikten sonra, aşağıdaki biçimlerde de 
tanımlanabilirdi:

double balance_dif(const Account a1, const Account a2)
{

    return a1.balance - a2.balance;
}
ya da
double balance_dif(const Account *p1, const Account *p2)
{
    return p1->balance - p2->balance;
}

Bir işlev, birden fazla sınıfın arkadaş işlevi olabilir. Arkadaş işlev bildiriminin sınıfın hangi bölümünde 
yapıldığının hiçbir önemi yoktur. Yukarıdaki örnekte, Account sınıfında balance_dif işlevi public bölümde 
arkadaş olarak bildirildi. Ancak private ya da protected bölümde bildirilseydi de bir farklılık oluşmazdı.
Yalnızca global işlevler değil, başka sınıfların üye işlevleri de arkadaş işlev olabilir. Örneğin:

class Myclass {
//…
    void myfunc();
};

class Herclass{
//…
    friend void Myclass::myfunc();
};

Yukarıdaki örnekte Herclass sınıfın, Myclass sınıfının myfunc isimli işlevini arkadaş olarak bildiriyor.
Arkadaş işlev bildirimi aynı zamanda işlevin bildirimi yerine de geçer. Bu durumda işlev bildiriminin bilinirlik 
alanı sınıf bildiriminin yapılış yeriyle belirlenir. Örneğin:

int main()
{
    class X {

//…
    friend void f();
    };

    f(); // Geçerli
// …
}

void func()
{
//…
    f(); // Geçersiz! İşlev bildirimi bu blokta tanınamaz!
}

Burada f arkadaş işlevinin sınıf içindeki arkadaşlık bildirimi aynı zamanda işlevin prototip bildirimi olarak da 
kabul edilir. Ancak bu bildiriminin bilinirlik alanı X sınıfının bilinirlik alanı ile aynıdır. Yani bu bildirim yalnızca 
main işlevi içinde bilinir. Bu yüzden func işlevi içinde f işlevi çağrıldığında, daha önce bildirimi yapılmamış bir 
işlev çağrılmış olur.
Arkadaş İşlevler Ne Zaman Kullanılmalıdır
Arkadaş işlevler erişim bakımından ayrıcalıklı işlevler olduğundan sınıfın private elemanlarının korunmasını 
azaltır. Arkadaş işlevler sınıfın her bölümüne erişebildiğine göre, sınıfın private elemanlara yönelik bir değişiklik 
yapıldığında yalnızca üye işlevleri değil aynı zamanda arkadaş işlevleri de yeniden yazmak gerekir. Arkadaş 
işlevleri fazlaca kullanmak sınıfın private bölümünün önemini azaltmayı kabul etmek anlamına gelir.
Arkadaş işlevler karmaşık durumlarda tasarımı ve işlemleri kolaylaştırmak için kullanılmalıdır. Kodun daha 
kolay yazılmasını sağlamak için bazı işlevlere gereksiz bir şekilde arkadaşlık vermek iyi bir fikir değildir. 
Arkadaş işlevlerin kullanılmasını gerekli duruma getirebilecek en tipik örnek işleçleri yükleyen global 
işlevlerinin yazımıdır. Böyle işlevleri ileride ele alacağız.

Arkadaş Sınıflar
Bir başka sınıfın bir üye işlevine arkadaşlık verilebileceğini belirtmiştik. Bir sınıf bir başka sınıfın tüm üye 
işlevlerine arkadaşlık verebilir. Arkadaş sınıf bir sınıfın tüm üye işlevlerinin başka bir sınıfın arkadaş işlevi olması 
durumudur. Bir sınıfı arkadaş sınıf yapmak için, arkadaş olunan sınıf içinde,
friend class <sınıf ismi>;

bildirimini yapmak gerekir. Bu bildirimin sınıfın hangi bölümünde yapılmış olduğunun bir önemi yoktur. Bu 
durumda arkadaş olarak belirtilen sınıfın tüm üye işlevleri içeri ilgili sınıf türünden bir nesne, gösterici ya da 
referans yoluyla sınıfın her bölümüne erişilebilir.
Aşağıdaki örneği inceleyin:

class Node {
    int val;
    Node *next;
    friend class LList;
};

class LList { 
public:
    void add(int val); 
    void delete(size_t n); 
    Node *get_head();
// … 
private:
    Node *phead; 
    Node *pnode; 
    size_t size;
};

Yukarıdaki örnekte LList sınıfı Node isimli sınıfın arkadaş sınıfıdır. LList sınıfının tüm üye işlevleri içinde Node 
sınıfına ilişkin nesne, gösterici ya da referans yoluyla, Node sınıfının her bölümüne erişilebilir. Node sınıfının 
elemanlarının private bölümde olduğuna ve herhangi bir işlev içinde Node sınıfı türünden nesne 
tanımlanabileceği halde, o nesne yardımıyla sınıfın private elemanlarına erişilemeyeceğine dikkat edin.
Arkadaş sınıflar da arkadaş işlevlerde olduğu gibi erişim kolaylığı sağlamak için kullanılabilir. Tabii arkadaş 
sınıfların da, private elemanlarının korunmasını azaltacağını söylemeliyiz.
Arkadaşlık Bildirimi Çift Yönlü Değildir
Bir sınıfın bir başka sınıfa arkadaşlık vermesi, arkadaşlık verilen sınıftan da bir arkadaşlık alındığı sonucunu 
doğurmaz. Aşağıdaki örneği inceleyin:

class A{ 
public:
    friend class B; 
    void func();
};
class B{
    int b;
//...
};
void A::func()
{
    B object;
    object.b = 1; //Geçersiz!
}

Yukarıdaki örnekte A sınıfı B sınıfına arkadaşlık veriyor. Bu B sınıfının da A sınıfına arkadaşlık verdiği 
sonucunu doğurmaz. A sınıfının üye işlevi olan func işlevi içinde tanımlanan B sınıfı türünden object isimli 
nesnenin private elemanına ulaşma girişimi geçersizdir, derleme zamanında hata oluşturur.

Arkadaşımın Arkadaşı Benim de Arkadaşımdır
Bu cümle arkadaşlık bildirimleri söz konusu olduğunda doğru değildir. Arkadaşlık bildirimlerinde 
geçişme özelliği söz konusu değildir. Aşağıdaki örneği inceleyin:

class A{
    int a; 
public:
    friend class B;
};

class B{
    friend class C;
//...

};

class C{ 
public:
    void func();
};

void C::func()
{
    A object;
    object.a = 1; //Geçersiz
}
Yukarıdaki örnekte A sınıfı B sınıfına, B sınıfı da C sınıfına arkadaşlık veriyor. Bu durumdan A sınıfının C sınıfına 
arkadaşlık verdiği gibi bir sonuç çıkmaz. C sınıfının func isimli üye işlevi içinde A sınıfının private kısmına 
erişme çabası derleme zamanında hata ile sonuçlanır
******************************************************************************************************************************   

                                                                             ********* 14-DERS NOTLARI *********
1)**Attorney-Client İdiomu Nedir? C++'ta Nasıl Kullanılır?**

C++'ta **Attorney-Client İdiomu**, bir sınıfın belirli üyelerine (özellikle `private` veya `protected` üyeler) başka bir sınıfın kontrollü 
erişimini sağlamak için kullanılan bir tasarım desenidir. Bu idiom, avukat-müvekkil ilişkisine benzer şekilde, bir sınıfın belirli bilgilerini
veya işlevlerini başka bir sınıfa açığa çıkarmak için kullanılırken, genel erişimi kısıtlar. Bu sayede, sınıflar arası sıkı bağımlılıkları 
azaltarak daha esnek ve güvenli bir yapı oluşturulur.

### 1. Giriş

C++'ta sınıflar, verilerini ve işlevlerini `private`, `protected` ve `public` erişim belirleyicileri ile kontrol eder. Bazen, bir sınıfın 
belirli üyelerine sadece belirli başka sınıfların erişmesini isteyebilirsiniz. Bu noktada, doğrudan `friend` anahtar kelimesini kullanmak 
yerine Attorney-Client idiomunu tercih etmek, daha kontrollü ve sürdürülebilir bir erişim yönetimi sağlar.

### 2. Attorney-Client İdiomunun Amacı

- **Kontrollü Erişim Sağlamak**: Sınıfın belirli üyelerine sadece belirli sınıfların erişmesini sağlar.
- **Bağımlılıkları Azaltmak**: `friend` kullanımı yerine, daha az sıkı bağımlılık oluşturarak kodun esnekliğini artırır.
- **Kapsüllemeyi Güçlendirmek**: Sınıflar arasındaki etkileşimi sınırlandırarak, veri gizliliğini ve bütünlüğünü korur.

### 3. Attorney-Client İdiomunun Nasıl Çalıştığı

Attorney-Client idiomu, iki ana bileşenden oluşur:

1. **Client (Müvekkil) Sınıfı**: Korunan (`protected` veya `private`) üyelere sahip olan ana sınıftır.
2. **Attorney (Avukat) Sınıfı**: Client sınıfının belirli üyelerine erişim sağlayan yardımcı sınıftır. Attorney sınıfı, genellikle 
sadece gerekli işlevleri sağlar ve diğer tüm üyelerden gizlidir.

Bu yapı, Attorney sınıfının sadece belirli işlevlere erişim izni vererek, Client sınıfının iç yapısını korumasını sağlar.

### 4. Örnek: C++'ta Attorney-Client İdiomu

Aşağıda, C++'ta Attorney-Client idiomunun nasıl uygulanabileceğini gösteren bir örnek bulunmaktadır.

#include <iostream>

// Client (Müvekkil) Sınıfı
class Account {
private:
    double balance;

public:
    Account(double initial_balance) : balance(initial_balance) {}

    // Friend olarak sadece belirli bir Attorney sınıfına izin veriyoruz
    friend class AccountAttorney;

    void displayBalance() const {
        std::cout << "Current Balance: $" << balance << std::endl;
    }
};
 
// Attorney (Avukat) Sınıfı
class AccountAttorney {
public:
    // Yalnızca bu fonksiyon, Account sınıfının private balance üyesine erişebilir
    static void deposit(Account& account, double amount) {
        if (amount > 0) {
            account.balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    static void withdraw(Account& account, double amount) {
        if (amount > 0 && amount <= account.balance) {
            account.balance -= amount;
            std::cout << "Withdrew: $" << amount << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount!" << std::endl;
        }
    }
};

int main() {
    Account myAccount(100.0);
    myAccount.displayBalance();

    // Attorney sınıfı aracılığıyla hesap işlemleri yapıyoruz
    AccountAttorney::deposit(myAccount, 50.0);
    myAccount.displayBalance();

    AccountAttorney::withdraw(myAccount, 30.0);
    myAccount.displayBalance();

    // Doğrudan erişim engellenmiştir
    // myAccount.balance += 100.0; // Derleyici hatası!

    return 0;
}

#### Açıklama:

1. **Account Sınıfı (Client)**:
    - `balance` adlı `private` bir üyesi vardır.
    - Sadece `AccountAttorney` sınıfı, `balance` üyesine erişebilir çünkü `AccountAttorney` 
    sınıfı `Account` sınıfı tarafından `friend` olarak tanımlanmıştır.
    - `displayBalance` fonksiyonu, mevcut bakiyeyi görüntüler.

2. **AccountAttorney Sınıfı (Attorney)**:
    - `deposit` ve `withdraw` gibi statik fonksiyonları içerir.
    - Bu fonksiyonlar, `Account` nesnesinin `balance` üyesine erişerek belirli işlemleri gerçekleştirir.
    - Diğer sınıflar veya fonksiyonlar, `AccountAttorney` sınıfı aracılığıyla `Account`'un `balance` üyesine erişemezler.

3. **Main Fonksiyonu**:
    - `Account` nesnesi oluşturulur ve başlangıç bakiyesi atanır.
    - `AccountAttorney` sınıfının `deposit` ve `withdraw` fonksiyonları kullanılarak bakiye güncellenir.
    - Doğrudan `balance` üyesine erişim derleyici hatası verir, bu da kapsüllemeyi güçlendirir.

#### Çıktı:

Current Balance: $100
Deposited: $50
Current Balance: $150
Withdrew: $30
Current Balance: $120

### 5. Avantajları ve Dezavantajları

#### Avantajları:

- **Kapsüllemeyi Güçlendirir**: Sınıfın iç yapısını koruyarak, sadece belirli işlemlere izin verir.
- **Kod Tekrarını Azaltır**: Ortak işlevler Attorney sınıfında toplandığı için kod tekrarı önlenir.
- **Güvenli Erişim Sağlar**: Sadece yetkili sınıflar veya fonksiyonlar belirli üyelere erişebilir.

#### Dezavantajları:

- **Ekstra Sınıf Gerektirir**: Her Client sınıfı için bir Attorney sınıfı oluşturmak ek kod gerektirebilir.
- **Karmaşıklık**: Tasarım deseni, kodun anlaşılmasını ve bakımını biraz daha zorlaştırabilir.
- **Friend Kullanımı**: `friend` anahtar kelimesinin kullanılması, sınıflar arasındaki ilişkileri açıkça gösterir ancak 
aşırı kullanımı tasarımın karmaşıklaşmasına yol açabilir.

### 6. Sonuç

C++'ta Attorney-Client idiomu, sınıflar arası kontrollü erişim sağlamak için güçlü bir tasarım desenidir. Özellikle büyük ve karmaşık projelerde, 
veri gizliliğini korumak ve sınıflar arası bağımlılıkları azaltmak için oldukça faydalıdır. Ancak, bu idiomun getirdiği ek karmaşıklığı göz önünde bulundurarak,
kullanımını dikkatli bir şekilde planlamak önemlidir.

**Anahtar Noktalar:**

- **Attorney-Client İdiomu**, sınıflar arası kontrollü erişim sağlamak için kullanılır.
- **Client Sınıfı** (`Account`), gizli üyelere (`balance`) sahiptir.
- **Attorney Sınıfı** (`AccountAttorney`), belirli işlevler aracılığıyla Client sınıfının gizli üyelerine erişim sağlar.
- **Avantajları**, kapsüllemeyi güçlendirmek ve kod tekrarını azaltmak iken, **dezavantajları** ekstra sınıf gerektirmesi ve potansiyel karmaşıklıktır.

Bu idiom, doğru kullanıldığında C++ projelerinizde daha güvenli ve sürdürülebilir bir kod yapısı oluşturmanıza yardımcı olabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Hidden Friend Idiom**, C++'ta serbest (free) bir fonksiyonun sınıfın bir üyesiymiş gibi davranmasını sağlayan ve free 
fonksiyonların sadece belirli bir sınıfın bağlamında erişilebilir olmasını temin eden bir tasarım desenidir. 
Genellikle **arkadaşlık** (`friend`) mekanizmasıyla birlikte kullanılır. 

Bu idiom, genellikle **operatör aşırı yükleme** veya belirli serbest fonksiyonların sınıfın private veya protected 
üyelerine erişmesi gerektiği durumlarda kullanılır.  

### **Temel Özellikler**
- Serbest bir fonksiyon, sınıfın **özel (`private`)** veya **korumalı (`protected`)** üyelerine erişebilir.  
- Bu serbest fonksiyon, sınıfın içinde bir **`friend`** olarak tanımlandığında sadece ilgili sınıfın bağlamında görünür hale gelir.  
- Diğer kod bu serbest fonksiyona doğrudan erişemez; bu, istemeden oluşabilecek ad çakışmalarını ve yanlış kullanımı önler.  

### **Sentaks ve Çalışma Prensibi**

class MyClass {
private:
    int value;

public:
    explicit MyClass(int v) : value(v) {}

    // Arkadaş olarak tanımlanmış serbest fonksiyon
    friend bool operator==(const MyClass& lhs, const MyClass& rhs) {
        return lhs.value == rhs.value;
    }
};

Bu örnekte:
- `operator==` serbest bir fonksiyondur.
- Ancak `MyClass` içinde `friend` olarak tanımlandığı için, `value` gibi `private` üyelerine doğrudan erişebilir.
- **Hidden Friend Idiom** sayesinde `operator==`, yalnızca `MyClass` için geçerli hale gelir ve global isim alanını kirletmez.

### **Hidden Friend Kullanımının Avantajları**
1. **Global İsim Alanını Temiz Tutmak:** Fonksiyon sadece ilgili sınıfın bağlamında görünür olur, böylece diğer isim alanlarıyla çakışmayı önler.
2. **Enkapsülasyonu Korur:** Sınıfın özel üyelerine erişim sağlarken, diğer kodun bu serbest fonksiyonlara erişimini sınırlar.
3. **Optimize Edilmiş ADL (Argument Dependent Lookup):** Hidden Friend Idiom, serbest fonksiyonun yalnızca aynı sınıfın bağlamında 
bulunmasını sağlar. Bu, yalnızca gerekli olduğunda arama işlemini optimize eder.

### **Detaylı Örnek**
#### **Kod:**

#include <iostream>

class MyClass {
private:
    int value;

public:
    explicit MyClass(int v) : value(v) {}

    // Hidden Friend: operator==
    friend bool operator==(const MyClass& lhs, const MyClass& rhs) {
        return lhs.value == rhs.value;
    }

    // Hidden Friend: operator!=
    friend bool operator!=(const MyClass& lhs, const MyClass& rhs) {
        return !(lhs == rhs); // operator== kullanılarak uygulanıyor
    }
};

int main() {
    MyClass a(5);
    MyClass b(5);
    MyClass c(10);

    std::cout << std::boolalpha;
    std::cout << "a == b: " << (a == b) << '\n'; // true
    std::cout << "a != c: " << (a != c) << '\n'; // true

    return 0;
}


#### **Çıktı:**

a == b: true
a != c: true

### **Neden Hidden Friend Idiom Kullanılır?**
- **Kapsamı Sınırlamak:** Serbest fonksiyonun yalnızca ilgili sınıfın bağlamında bulunmasını sağlamak için.  
- **Yazılım Bakımı Kolaylığı:** Sınıfa özgü serbest fonksiyonlar, sınıf tanımına daha yakın bir şekilde organize edilir.  
- **Ad Çakışmalarını Önlemek:** Global isim alanına eklenmediği için aynı isimde başka bir fonksiyonla çakışmaz.

### **Argument Dependent Lookup (ADL) ile İlişkisi**
Hidden Friend Idiom, serbest fonksiyonların ADL yoluyla çağrılmasını kolaylaştırır. Serbest fonksiyon sınıfın içinde bir 
`friend` olarak tanımlandığında, sadece o sınıfın türlerinden çağrıldığında görünür olur. Bu, serbest fonksiyonların global
isim alanını kirletmesini önler ve ADL optimizasyonlarını destekler.

#### **ADL'nin Çalışma Şekli**

class Example {};

void myFunction(const Example&); // Serbest fonksiyon

int main() {
    Example e;
    myFunction(e); // ADL sayesinde `Example` bağlamında bulunur
}

Eğer `myFunction`, `Example` içinde `friend` olarak tanımlanmış olsaydı, bu fonksiyon yalnızca `Example` bağlamında bulunacaktı.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Type Erasure Nedir?**

**Type Erasure** (Tür Silme), C++'da farklı türleri bir arada kullanabilmek veya saklayabilmek için kullanılan bir tekniktir. 
Bu teknikle, bir türün (type) ayrıntıları gizlenir ve sadece gerekli olan bir ortak arayüz veya davranış bırakılır. 
Türün kendisi çalışma zamanında da var olabilir, ancak genellikle derleme zamanı tür bilgisi "silinir" ve bir soyutlama sağlanır.

C++'da **type erasure** genellikle şablonlar (`templates`) ve polimorfizm ile gerçekleştirilir. Bu yaklaşım, genellikle farklı türlerden 
nesneleri ortak bir şekilde saklamak veya çalıştırmak istediğiniz durumlarda kullanılır.

### **Neden Kullanılır?**

1. **Çeşitli Türleri Bir Arada Saklama:**
   - Farklı türde nesneleri bir koleksiyon içinde saklamak için (örneğin, `std::any` veya `std::function`).

2. **Tür Bağımsızlığı Sağlama:**
   - Tür bağımsız bir API sunmak için kullanılır. Kullanıcılar, türlerin iç detaylarını bilmeden bu API'yi kullanabilir.

3. **Runtime Polimorfizm:**
   - Derleme zamanında tür bilgisine bağımlı olmadan, çalışma zamanında türler arası davranışları soyutlama.

4. **Esnek ve Basit Arayüzler Sağlama:**
   - Türün tam bilgisini gizleyerek daha temiz ve kullanımı kolay bir arayüz sunmak.

### **Nasıl Çalışır?**

Type erasure genellikle üç temel bileşene dayanır:

1. **Soyut Arayüz (Interface):**
   - Ortak davranışlar tanımlanır (örneğin, saf sanal işlevler veya bir `concept`).

2. **Türün Detaylarını Gizleyen Yapı:**
   - Türün ayrıntılarını saklamak için bir kaplama (wrapper) sınıf kullanılır.

3. **Tür Bilgisi Saklama:**
   - Tür silinmesine rağmen, gerekli olduğunda orijinal türle çalışabilmek için bazı tür bilgisi korunabilir (örneğin, `std::any` ve `std::type_info`).

### **Örnek: Basit Type Erasure**

#### **Runtime Polimorfizm ile Type Erasure**

Aşağıdaki örnekte, farklı türde nesneleri saklayıp ortak bir işlevi çağırmak için `std::function` kullanılıyor.

#include <iostream>
#include <functional>
#include <vector>

void RunAll(const std::vector<std::function<void()>>& tasks) {
    for (const auto& task : tasks) {
        task(); // Her bir görevi çağır
    }
}

int main() {
    std::vector<std::function<void()>> tasks;

    tasks.push_back([] { std::cout << "Task 1\n"; });
    tasks.push_back([] { std::cout << "Task 2\n"; });
    tasks.push_back([] { std::cout << "Task 3\n"; });

    RunAll(tasks);

    return 0;
}

**Çıktı:**

Task 1
Task 2
Task 3

Bu örnekte:
- `std::function<void()>` ile herhangi bir çağrılabilir nesne (`callable`) saklanabilir.
- Türler arasındaki fark gizlenir; sadece `void()` imzasına sahip bir işlev gibi davranır.

#### **`std::any` ile Type Erasure**

C++17'den itibaren, `std::any` kullanarak farklı türde nesneleri saklayabilirsiniz.

#include <iostream>
#include <any>
#include <vector>

int main() {
    std::vector<std::any> container;

    container.push_back(42);              // int
    container.push_back(3.14);            // double
    container.push_back(std::string("C++"));

    for (const auto& item : container) {
        if (item.type() == typeid(int)) {
            std::cout << "int: " << std::any_cast<int>(item) << "\n";
        } else if (item.type() == typeid(double)) {
            std::cout << "double: " << std::any_cast<double>(item) << "\n";
        } else if (item.type() == typeid(std::string)) {
            std::cout << "string: " << std::any_cast<std::string>(item) << "\n";
        }
    }

    return 0;
}

**Çıktı:**

int: 42
double: 3.14
string: C++

Bu örnekte:
- `std::any` ile herhangi bir tür saklanabilir.
- Tür bilgisi `std::type_info` kullanılarak gerektiğinde geri alınabilir (`typeid` ve `std::any_cast`).

### **Avantajlar**

1. **Tür Bağımsızlık:** Kullanıcılar, belirli bir tür hakkında bilgi sahibi olmadan nesnelerle çalışabilir.
2. **Esneklik:** Farklı türde nesneleri tek bir konteynerde veya ortak bir arayüz üzerinden işleyebilirsiniz.
3. **Temiz ve Basit Kod:** Type erasure, karmaşık tür bağımlılıklarını gizleyerek kodun daha okunabilir olmasını sağlar.

### **Dezavantajlar**

1. **Performans Maliyeti:**
   - Type erasure, genellikle bir miktar performans kaybına neden olabilir (örneğin, dinamik bellek tahsisi veya sanal işlev çağrıları).

2. **Tür Güvenliği:**
   - Tür silme işlemi yanlış kullanılırsa, `std::bad_cast` gibi hatalar ortaya çıkabilir.

3. **Karmaşıklık:**
   - Basit durumlarda type erasure, daha karmaşık bir yapıya neden olabilir.

### **C++ Standart Kütüphanesinde Type Erasure Örnekleri**

1. **`std::function`**:
   - Çeşitli çağrılabilir nesneleri (işlev, lambda, işlev işaretçisi) tek bir türde saklamak için kullanılır.

2. **`std::any`**:
   - Farklı türde nesneleri tek bir konteynerde saklamak için kullanılır.

3. **`std::shared_ptr` veya `std::unique_ptr`**:
   - Belirli bir arayüze (`interface`) işaret eden akıllı işaretçiler.

4. **`std::variant`**:
   - Birkaç önceden tanımlı türü bir arada saklayabilmek için kullanılır.

### **Özet**

Type erasure, tür soyutlama ve çalışma zamanı esnekliği sağlamak için kullanılan güçlü bir tekniktir. C++'da, özellikle 
`std::function`, `std::any`, `std::variant` gibi standart kütüphane araçları ile yaygın bir şekilde kullanılır. 
Tür bağımlılıklarını gizlemek ve esnek arayüzler oluşturmak için bu teknik sıklıkla tercih edilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
operator function

bir operator sınıf nesnesinin operandı olduğunda derleyicinin ifadeyi fonksiyon çağrısına dönüştürdüğü
orda çağrılan fonksiyona operator function diyoruz

global functionda olabilirler
non-static member function olmak zorundalar
olmayan bir operatör overload edilemez
dilin bütün operatörleri overload edilemez -> sizeof operatörü / . nokta operatörü / .* Pointer-to-member operator / ? : koşul operatörü(ternary operator)
scope resolution operatörü :: / typeid / 

### **1. Member (Sınıf Üyesi) Olarak Overload Edilemeyen Operatörler**
Member fonksiyonlar olarak overload edilemeyecek operatörler şunlardır:

- **`::`** (Scope resolution operator)
  Sınıf veya namespace'e ait üyeye erişim için kullanılır.

- **`.`** (Dot operator)
  Bir nesnenin üyesine erişim için kullanılır.

- **`.*`** (Pointer-to-member operator)
  Pointer ile bir üye fonksiyona veya değişkene erişim için kullanılır.

- **`sizeof`**
  Bir türün veya ifadenin bellekteki boyutunu öğrenmek için kullanılır.

- **`typeid`**
  Runtime Type Identification (RTTI) için kullanılır.

- **`alignof`**
  Bir türün bellekteki hizalama gereksinimlerini öğrenmek için kullanılır.

- **`co_await`**
  Coroutine kullanımı için özel bir operatördür.

### **2. Global (Serbest Fonksiyon) Olarak Overload Edilemeyen Operatörler**
Global fonksiyonlar olarak overload edilemeyecek operatörler şunlardır:

- **`=`** (Assignment operator)
  **Not:** Üye fonksiyon olarak overload edilebilir.

- **`&`** (Address-of operator)
  Adres alma operatörüdür. **Not:** Üye fonksiyon olarak overload edilebilir.

- **`,`** (Comma operator)
  Sıralı değerlendirme için kullanılır. **Not:** Üye fonksiyon olarak overload edilebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
free function olarak overload edilemeyen member function olmak zorunda olan operatörler
()
[]
->
=
type cast operator functions

C++'da bazı operatörler **sadece sınıfın üyesi (member function)** olarak overload edilebilir. Bu operatörlerin
member function olmak zorunda olmasının temel nedeni, dilin tasarımında bu operatörlerin anlamlarının sınıfın iç durumu ile doğrudan ilgili olmasıdır.

### Sadece Member Function Olarak Overload Edilebilen Operatörler

1. **Assignment Operator (`operator=`)**
   - Bir nesneyi başka bir nesneye atamak için kullanılır.
   - Nesne durumunu değiştirdiği için sadece sınıfın bir üyesi olarak tanımlanabilir.

2. **Function Call Operator (`operator()`)**
   - Bir nesneyi bir fonksiyon gibi çağırmak için kullanılır.
   - Bu operatörün anlamı, çağırıldığı sınıfın bağlamıyla ilgilidir.

3. **Subscript Operator (`operator[]`)**
   - Bir nesneyi dizi gibi erişmek için kullanılır.
   - Nesnenin özel bir elemanına erişimi sağlar ve genellikle sınıfın verilerini manipüle eder.

4. **Pointer-to-Member Access Operator (`operator->`)**
   - Bir sınıf nesnesi üzerinden bir üye işlevi veya üye değişkene erişmek için kullanılır.
   - Sınıfın kendisine veya üyelerine erişim sağladığı için yalnızca bir member function olabilir.

### Neden Free Function Olarak Tanımlanamazlar?

- **`operator=`**: Nesnenin iç durumunu değiştirdiği için, bu operasyon doğrudan sınıfın özel durumlarına erişim gerektirir.
- **`operator()`**: Nesnenin bir fonksiyon gibi davranmasını sağladığından, nesnenin bağlamıyla doğrudan ilgilidir.
- **`operator[]`**: Doğrudan nesnenin elemanlarına erişim sağladığı için, yalnızca sınıfın bir üyesi olarak anlamlıdır.
- **`operator->`**: Nesnenin kendisine veya bir alt öğesine erişimi yönettiğinden, bu işlev yalnızca sınıf bağlamında tanımlanabilir.
### Örnekler

#### `operator=`

class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        // Atama işlemleri
        return *this;
    }
};

#### `operator[]`

class MyArray {
private:
    int data[10];
public:
    int& operator[](int index) {
        return data[index];
    }
};


#### `operator->`

class MyClass {
public:
    MyClass* operator->() {
        return this;
    }
};

Bu operatörlerin yalnızca member function olarak overload edilebilmesi, dilin tasarımında **kontrolü koruma** ve **anlamı açık tutma** amacı taşır.
--------------------------------------------------------------------------------------------------------------------------------------------------
tüm operatör fonksiyonları istisnasız isimleriylede çağırılabilir

class Myclass {};

int main() {

    Myclass m1, m2;
    m1 = m2 // iki şekildede yazsam aynı fonksiyonu çağırmış oluyorum
    m1.operator=(m2); tüm operatör fonksiyonları isimleriylede çağırılabilir
}
--------------------------------------------------------------------------------------------------------------------------------------------------
sadece function call operatorü default arguman alır 

operatör overloading mekanizmasında operatörlerin (arity) değiştirilemez yani operatörün unary yada binary olması
a * b -> binary operatör
!x -> unary operatör

operatör global fonksiyon ise operator<(x,y); gibi bir çağrıya dönüştürür ama tabi ki fonksiyon
tanımınında 2 parametresi olması lazım

class Myclass {

};

  bool operator<(const Myclass&,const Myclass&){}

yani member function olmayan binary operatörler tek parametreli olamaz iki parametreli olmak zorundadır üç parametre olursa yine sentaks hatası verir

eğer binary operatörü global olarak overload ediyorsak operatörün sol operandını fonksiyonun birinci parametresini sağ operandını
foknisyonun ikinci parametresine geçicek

DİKKAT:binary operatör member fnuction ise o üye funksiyon binary operandın sol operandı için çağırılıyor
m1.operator<(m2); burda m1 için eşittir operatörü çağırılıyor yani member funcitonlarda tek parametre olmak zorunda

class Myclass
{
public:
    bool operator<(const Myclass&) const{}
}
--------------------------------------------------------------------------------------------------------------------------------------------------
unary operators

global function operatör ise derleyici operatör ifadesini operator!(ptr) olarak çağırır yani ! operatörü unary operatör olduğu için
1 tane parametre alır
class Myclass
{

}
    bool operator!(const Myclass&){}

unary operatör member function operatör ise paramtere almasına gerek yoktur zaten o nesne için çağırılacaktır

class Myclass
{
    bool operator!(){}
}
--------------------------------------------------------------------------------------------------------------------------------------------------
+ hem toplama operatöür hemde sign operatörü x + y yada +x
- hem çıkarma operatörü hemde sign operatörü x - y yada -x
& hem bitwise operatörü hemde adres operatörü x & y yada &x
* hem çarpma hemde dereferans operatörü x * y yada *p
Myclass operator+()const // sign operatör
Myclass operator+(Myclass)const // add operatörü

NOT:bir sınıfın birden fazla operatör fonksiyonları olabilir yani function overloading vardır

Myclass operator+(int)const
Myclass operator+(long)const
Myclass operator+(int,int)const

Myclass& operator=(int)
Myclass& operator=(double)

Myclass m;
m = 5 // int olan çağrılır
m = 5.5 // double olan çağrılır
--------------------------------------------------------------------------------------------------------------------------------------------------
operatörün öncelik seviyesi ve öncelik yönü asla değiştirilemez

class Bigint{
}

Bigint operator*(const Bigint&,const Bigint&)
Bigint operator+(const Bigint&,const Bigint&)

Bigint b1,b2,b3,b4,b5
Bigint bx;

bx = b1 * b2 + b3 * b4 & b5; bu ifade derleyici için aşağıdaki gibidir
bx = ((b1 * b2) + (b3 * b4)) & b5; 

global olduğu için isimleriyle çağırsaydık böyle çağırırdık
bx.operator=(operator&(operator+(operator*(b1,b2) operator*(b3,b4)), b5));

member function operator olsaydı

bx.operator=(b1.operator*(b2).operator+(b3.operator*(b4)).operator&(b5));
--------------------------------------------------------------------------------------------------------------------------------------------------
global operator fonksiyonu olmasaydı sol operandın bir sınıf türünden olmaması durumunda sentaks hatası olucaktı

x + 5;
5 + x; 
x.operator(5); sol operand sınıf türünden olduğu için hata vermez 
--------------------------------------------------------------------------------------------------------------------------------------------------
Simetrik operatörler
Simetrik operatörler, matematiksel ve bilgisayar bilimlerinde, iki operand arasında yapılan işlemlerin sırasının değiştirilmesinin 
sonucu etkilemediği operatörlerdir. Yani, operandlar arasındaki işlemde hangi sırayla yer aldıklarına bakılmaksızın sonuç 
aynı olur. Bu tür operatörler, genellikle toplama, çarpma gibi işlemleri içerir.

Simetrik Operatörler Örnekleri:
Toplama (+): A + B = B + A
Çarpma (*): A * B = B * A
Eşitlik (==): A == B = B == A
Yukarıdaki operatörler simetriktir çünkü operandların yerleri değiştirildiğinde sonuç aynı kalır. Örneğin, 3 + 5 ve 5 + 3 
ifadeleri aynı sonucu verir, yani her iki ifade de 8 sonucunu döndürür.

Simetrik Operatörlerin Özellikleri:
Operandların Yeri Değiştirilse Bile Sonuç Aynıdır: Operatörün işlediği iki operandın yerleri değiştirildiğinde, 
işlem sonucu değişmez. Örneğin, toplama ve çarpma gibi işlemler simetriktir.

İki Taraflı Eşitlik: Simetrik operatörler, işlemin her iki tarafında da eşitlik sağlar. Bu, operatörün iki
operandı işleme sırasını değiştirebileceğiniz anlamına gelir.

C++'ta Simetrik Operatörler:
C++ dilinde, simetrik operatörler genellikle global operatörler olarak tanımlanır, çünkü iki nesne arasında işlem 
yaparlar ve operandların sırasının önemli olmadığı durumlar için uygundur.

Simetrik Olmayan Operatörler:
Simetrik olmayan operatörler, operandların sırasına bağlı olarak farklı sonuçlar verirler. 
Bu tür operatörler genellikle yönlü işlemler için kullanılır.

Farklılık (-): A - B ≠ B - A
Bölme (/): A / B ≠ B / A
Atama (=): A = B ≠ B = A
Yukarıdaki operatörler simetrik değildir çünkü operandların sırası sonucu etkiler.
*******************************************************************************************************************************

                                                                             ********* 15-DERS NOTLARI *********

NOT:Sınıfları içerden dışarıya doğru değil dışardan içeriye doğru tasarlamak gerekiyor yani olaya clietntların gözüyle bakmamız
lazım yani clientler bu sınıfı nasıl daha kolay kullanılabilir buna bakıcaz

Bu prensip, modern yazılım tasarımında önemli bir yaklaşımdır ve kullanıcı odaklı tasarımı temel alır. Özellikle **API tasarımı** ve **sınıf tasarımı** 
sırasında, sınıfı kullanacak olan "müşteri" (client) kodun ihtiyaçlarını göz önünde bulundurarak hareket etmek, hem kullanım kolaylığı hem de işlevsellik açısından daha iyi sonuçlar sağlar.

### **Prensibin Açıklaması**
1. **Dışarıdan İçeriye Doğru Tasarım**:
   - Sınıfınızı oluştururken öncelikle sınıfın dışarıdan nasıl kullanılacağını düşünün.
   - Sınıfın public API'sini (yani dış dünyaya sunduğu arayüzleri) basit, anlaşılır ve sezgisel hale getirmeye odaklanın.
   - Kullanıcıların ihtiyaç duyacağı işlevler açık ve erişilebilir olmalıdır.

2. **Client Perspektifi**:
   - Sınıfın nasıl kullanılacağını belirlerken, bir kullanıcı olarak bu sınıfı nasıl daha kolay kullanabileceğinizi sorgulayın.
   - Gereksiz karmaşıklık, fazla iş yükü veya öğrenme eğrisi yaratmamaya çalışın.

3. **Encapsulation (Kapsülleme)**:
   - İç detayları (private veya protected alanlar) mümkün olduğunca gizleyin.
   - Kullanıcının iç mekanizmaları bilmesine gerek kalmadan sınıfın işlevlerini yerine getirebilmesi sağlanmalıdır.

### **Uygulamada Örnek**
#### **Kötü Tasarım (İçeriden Dışarıya Tasarım)**:

class File {
private:
    FILE* file;
    bool isOpen;

public:
    void open(const std::string& filename) {
        file = fopen(filename.c_str(), "r");
        isOpen = (file != nullptr);
    }

    void read(char* buffer, size_t size) {
        if (isOpen) {
            fread(buffer, 1, size, file);
        }
    }

    void close() {
        if (isOpen) {
            fclose(file);
            isOpen = false;
        }
    }
};

- Kullanıcı, dosyayı açma, okuma ve kapatma gibi işlemleri manuel olarak yönetmek zorunda. Bu, hem hata yapma riskini artırır hem de karmaşıklığı artırır.

#### **İyi Tasarım (Dışarıdan İçeriye Tasarım)**:

class File {
public:
    File(const std::string& filename) {
        file = fopen(filename.c_str(), "r");
        if (!file) {
            throw std::runtime_error("File could not be opened");
        }
    }

    ~File() {
        if (file) fclose(file);
    }

    std::string read() {
        char buffer[1024];
        size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
        return std::string(buffer, bytesRead);
    }

private:
    FILE* file;
};

- Kullanıcı açısından:
  - Dosya açma ve kapatma işlemleri sınıfın destructor'ına taşınmış, yani otomatik olarak hallediliyor.
  - Kullanıcı sadece dosya içeriğini okuma veya yazma işlevine odaklanıyor.

### **Avantajları**
1. **Kullanım Kolaylığı**:
   Kullanıcılar, sınıfın karmaşık iç yapısıyla uğraşmak zorunda kalmaz.

2. **Daha Az Hata Yapma Riski**:
   İyi kapsüllenmiş bir API, kullanıcıların yanlış kullanımını önler.

3. **Okunabilir ve Anlaşılır Kod**:
   Kullanıcılar için kodun okunabilirliği artar ve sınıfın işlevini anlamak kolaylaşır.

4. **Yüksek Esneklik**:
   İç detaylar değiştirilebilir, ancak dış API aynı kaldığı sürece kullanıcılar etkilenmez.

### **Sonuç**
Sınıfları tasarlarken, kullanıcıların perspektifini öncelikli olarak ele almak, daha sağlam, kolay anlaşılır ve kullanılabilir bir API oluşturmanın
temel yoludur. **"Dışarıdan içeriye doğru tasarım"** bu felsefeyi uygulamak için en iyi yaklaşımdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
1)ADL (Argument-Dependent Lookup),Argümana bağlı isim arama C++ dilinde **argümanların türlerine bağlı olarak** isim çözümleme (name resolution) yapan bir 
mekanizmadır. ADL'nin anlaşılması, özellikle **namespace'ler** ve **operatör aşırı yükleme (operator overloading)** gibi konularda kritik öneme sahiptir.

Bu geniş açıklamada ADL'nin temelleri, çalışma şekli, kullanıldığı senaryolar ve dikkat edilmesi gereken noktalar ayrıntılı olarak ele alınacaktır.

## **ADL'nin Temel Mantığı**
C++'da bir işlev çağrıldığında, işlevin ismini çözmek için iki temel yol izlenir:
1. **Normal İsim Çözümleme:** Çağrının yapıldığı kapsamda (scope) işlev aranır.
2. **ADL (Argument-Dependent Lookup):** Argümanların türleri incelenir ve bu türlerin tanımlandığı ad alanlarında (namespace) işlev aranır.

ADL, işlevin veya operatörün çağrıldığı ad alanını açıkça belirtmeye gerek kalmadan, çağrının doğru işlevle eşleşmesini sağlar.

## **ADL'nin Çalışma Mekanizması**
ADL'nin temel prensibi şu şekildedir:
1. İşlev çağrılırken kullanılan argümanların türleri belirlenir.
2. Bu türlerin tanımlandığı **namespace'ler** otomatik olarak işlev arama kapsamına eklenir.
3. Derleyici, bu ek kapsamda işlevin veya operatörün tanımını arar ve çağrıyı çözümler.

## **Örneklerle ADL'nin Çalışması**

### **Basit Bir Örnek**

#include <iostream>

namespace MyNamespace {
    struct MyType {};
    void print(const MyType&) {
        std::cout << "MyNamespace::print çağrıldı!" << std::endl;
    }
}

int main() {
    MyNamespace::MyType obj;
    print(obj); // ADL sayesinde MyNamespace::print bulunur.
    return 0;
}

**Açıklama:**
- `print(obj)` çağrısında, `obj`'nin türü `MyNamespace::MyType` olduğu için derleyici `MyNamespace`'i arama kapsamına alır.
- Sonuç olarak, `MyNamespace::print` işlevi çağrılır.

### **ADL Olmadan Çözümleme**
Eğer ADL olmasaydı, yukarıdaki işlevi çağırmak için `MyNamespace` ad alanını açıkça belirtmeniz gerekirdi:

MyNamespace::print(obj);

### **Operatörlerde ADL**
ADL, operatör aşırı yükleme ile birlikte doğal olarak çalışır. Örneğin:

#include <iostream>

namespace MyNamespace {
    struct MyType {};
    bool operator==(const MyType&, const MyType&) {
        return true; // Karşılaştırma mantığı.
    }
}

int main() {
    MyNamespace::MyType a, b;
    if (a == b) { // ADL sayesinde operator== aranır.
        std::cout << "Nesneler eşit!" << std::endl;
    }
    return 0;
}

**Açıklama:**
- `a == b` ifadesi değerlendirildiğinde, `operator==` işlevi `MyNamespace` içinde aranır.
- ADL sayesinde `MyNamespace::operator==` otomatik olarak çağrılır.

## **ADL Kullanımının Avantajları**
1. **Kodun Okunabilirliği:** Namespace belirtmek zorunda kalmadan işlev çağrıları yapılabilir. Bu, kodun daha temiz ve kısa olmasını sağlar.
2. **Operatör Aşırı Yükleme ile Uyumlu:** Özellikle özel operatörler kullanılırken, ADL çağrıları kolaylaştırır.
3. **Modülerlik:** Birden fazla namespace kullanan projelerde, namespace'lerin sınırları içinde otomatik çözümleme yapılır.

## **ADL'nin Sınırları ve Dikkat Edilmesi Gerekenler**

### **1. Beklenmedik Eşleşmeler**
ADL, argüman türlerine bağlı olarak geniş kapsamlı bir arama yapabilir. Bu, bazen beklenmeyen işlevlerin çağrılmasına neden olabilir.

**Örnek:**

#include <iostream>

namespace A {
    struct MyType {};
    void func(const MyType&) {
        std::cout << "A::func çağrıldı!" << std::endl;
    }
}

namespace B {
    struct MyType {};
    void func(const MyType&) {
        std::cout << "B::func çağrıldı!" << std::endl;
    }
}

int main() {
    A::MyType obj;
    func(obj); // Derleyici hata verebilir (ambiguous call).
    return 0;
}

**Açıklama:**
- `func` çağrısı hem `A` hem de `B` namespace'lerindeki işlevlerle eşleşebilir. Bu belirsizlik derleyici hatasına yol açar.

### **2. ADL'nin Etkisiz Olduğu Durumlar**
ADL, yalnızca fonksiyon çağrılarında ve operatör aşırı yüklemelerinde çalışır. **Şablon (template)** türü argümanları doğrudan kapsamaz.

**Örnek:**

#include <iostream>

namespace MyNamespace {
    template <typename T>
    void print(const T&) {
        std::cout << "Şablon işlev çağrıldı!" << std::endl;
    }
}

int main() {
    MyNamespace::print(42); // ADL çalışmaz, namespace belirtilmeli.
    return 0;
}

## **Sonuç**
ADL, C++'da işlev çağrılarında ve operatör aşırı yüklemede isim çözümlemesini kolaylaştıran güçlü bir araçtır. 
Ancak, doğru şekilde kullanılmadığında beklenmedik sonuçlara yol açabilir. Bu nedenle:

1. Namespace'lerin dikkatli organize edilmesi,
2. ADL'nin hangi durumlarda devreye girdiğinin bilinmesi,
3. Belirsizliklerin önlenmesi için kodun açık bir şekilde yazılması önemlidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **inserter** ve **extractor**, genellikle akış operatörleriyle (`<<` ve `>>`) kullanılan kavramlardır. Bu operatörler, 
giriş ve çıkış akışlarını kolaylaştıran bir mekanizma sağlar ve genellikle `std::ostream` ve `std::istream` sınıflarıyla ilişkilendirilir.

## **Inserter (Ekleme Operatörü `<<`)**

### **Tanım**
`Inserter`, bir akış nesnesine (örneğin, `std::cout`) veri yazmak için kullanılan operatördür. Bu, veri akışını bir çıkış kaynağına yönlendirmek için kullanılır.

### **Örnek Kullanım**

#include <iostream>

int main() {
    std::cout << "Merhaba, Dünya!" << std::endl;
    return 0;
}

**Açıklama:**
- `std::cout << "Merhaba, Dünya!"` ifadesi, `"Merhaba, Dünya!"` metnini standart çıkış akışına ekler.
- `<<` operatörü burada bir "inserter" olarak işlev görür.

### **Kullanıcı Tanımlı Türler için Inserter**
Kendi sınıflarınız için `<<` operatörünü aşırı yükleyerek özel davranışlar tanımlayabilirsiniz.

#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(const std::string& name, int age) : name(name), age(age) {}
};

// Inserter operatörünü aşırı yüklüyoruz.
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Name: " << p.name << ", Age: " << p.age;
    return os;
}

int main() {
    Person person("Alice", 25);
    std::cout << person << std::endl; // Name: Alice, Age: 25
    return 0;
}

**Açıklama:**
- `operator<<` aşırı yüklenerek, `Person` sınıfı için özel bir ekleme davranışı tanımlandı.
- `std::ostream&` döndürmek, zincirleme işlemleri (chaining) desteklemek için gereklidir (`std::cout << obj1 << obj2` gibi).

## **Extractor (Çıkarma Operatörü `>>`)**

### **Tanım**
`Extractor`, bir akış nesnesinden veri okumak için kullanılan operatördür. Bu, bir giriş kaynağından veri almak için kullanılır.

### **Örnek Kullanım**

#include <iostream>

int main() {
    int age;
    std::cout << "Yaşınızı girin: ";
    std::cin >> age;
    std::cout << "Yaşınız: " << age << std::endl;
    return 0;
}

**Açıklama:**
- `std::cin >> age` ifadesi, standart giriş akışından (`std::cin`) bir `int` değeri okur ve `age` değişkenine atar.
- `>>` operatörü burada bir "extractor" olarak işlev görür.

### **Kullanıcı Tanımlı Türler için Extractor**
Kendi sınıflarınız için `>>` operatörünü aşırı yükleyerek giriş işlemleri tanımlayabilirsiniz.

#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;
};

// Extractor operatörünü aşırı yüklüyoruz.
std::istream& operator>>(std::istream& is, Person& p) {
    is >> p.name >> p.age;
    return is;
}

int main() {
    Person person;
    std::cout << "Ad ve yaş girin: ";
    std::cin >> person; // Özel davranış devreye girer.
    std::cout << "Girdiğiniz kişi: " << person.name << ", " << person.age << std::endl;
    return 0;
}

**Açıklama:**
- `operator>>` aşırı yüklenerek, `Person` sınıfı için özel bir çıkarma davranışı tanımlandı.
- `std::istream&` döndürmek, zincirleme işlemleri desteklemek için gereklidir (`std::cin >> obj1 >> obj2` gibi).

## **Inserter ve Extractor'ın Özellikleri**

1. **Tip Güvenliği:**
   - Akış operatörleri türlere göre özelleştirilebilir ve aşırı yüklenebilir.
   - Varsayılan olarak, temel türler (`int`, `double`, `std::string`) için tanımlanmıştır.

2. **Zincirleme (Chaining):**
   - Hem `<<` hem de `>>` operatörleri zincirleme işlemlerine izin verir.

   std::cout << "Yaş: " << age << ", Ad: " << name << std::endl;

3. **Akış Durumları:**
   - Hem `std::istream` hem de `std::ostream`, hata durumlarını kontrol etmek için kullanılabilir (`std::cin.fail()`, `std::cout.good()` gibi).

## **Avantajları ve Kullanım Alanları**

- **Standartlaştırılmış Giriş ve Çıkış:** Kullanıcı tanımlı türlerde bile tutarlı bir giriş-çıkış arabirimi sunar.
- **Kodun Okunabilirliği:** Akış operatörleri sayesinde giriş ve çıkış işlemleri daha okunabilir hale gelir.
- **Esneklik:** Kullanıcı tanımlı sınıflar için kolayca özelleştirilebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
**C++'da Operatör Fonksiyonların `friend` Olması**, bir sınıfın özel (`private`) veya korumalı (`protected`) üyelerine erişmesi 
gereken operatörlerin tanımlanmasını sağlar. `friend` olarak tanımlanan operatör fonksiyonlar, sınıfın dışındadır ancak sınıfın 
iç yapısına erişim yetkisine sahiptir.

## **Neden Operatör Fonksiyonlar `friend` Olarak Tanımlanır?**

1. **Sınıf Dışında Tanımlama Gereksinimi:**
   - Bazı operatörler (örneğin, `<<` ve `>>`) mutlaka sınıfın dışında tanımlanmalıdır çünkü sol tarafında sınıf olmayan bir 
   operand (örneğin `std::ostream` veya `std::istream`) olabilir.

2. **Özel ve Korumalı Üyelere Erişim:**
   - Operatör işlevi, sınıfın özel (`private`) veya korumalı (`protected`) üyelerine erişmek zorundaysa, bu işlev `friend` olarak tanımlanır.

## **Örnek: Friend Operatörlerin Kullanımı**

### **1. Giriş ve Çıkış Operatörleri (`<<` ve `>>`)**

#include <iostream>
#include <string>

class Person {
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // friend olarak << operatörünü tanımlıyoruz
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }

    // friend olarak >> operatörünü tanımlıyoruz
    friend std::istream& operator>>(std::istream& is, Person& p) {
        is >> p.name >> p.age;
        return is;
    }
};

int main() {
    Person person("John", 30);

    // << operatörünü kullanarak bilgileri yazdırıyoruz
    std::cout << person << std::endl;

    // >> operatörünü kullanarak yeni bilgi alıyoruz
    std::cout << "Enter name and age: ";
    std::cin >> person;
    std::cout << person << std::endl;

    return 0;
}

**Açıklama:**
- `<<` ve `>>` operatörleri sınıfın dışında tanımlanmalıdır çünkü sol operand genellikle `std::ostream` veya `std::istream` olur.
- Bu operatörlerin sınıfın özel üyelerine erişebilmesi için `friend` olarak tanımlanmaları gerekir.

### **2. İki Nesne Arasında Karşılaştırma**

#include <iostream>

class Vector {
    int x, y;

public:
    Vector(int x, int y) : x(x), y(y) {}

    // friend olarak == operatörünü tanımlıyoruz
    friend bool operator==(const Vector& v1, const Vector& v2) {
        return v1.x == v2.x && v1.y == v2.y;
    }
};

int main() {
    Vector v1(3, 4), v2(3, 4), v3(5, 6);

    if (v1 == v2) {
        std::cout << "v1 ve v2 eşittir." << std::endl;
    }

    if (v1 != v3) {
        std::cout << "v1 ve v3 eşit değildir." << std::endl;
    }

    return 0;
}

**Açıklama:**
- `==` operatörü, iki nesnenin özel üyelerini karşılaştırır.
- Bu işlem için operatörün `friend` olarak tanımlanması gerekir.

## **Friend Operatörlerin Avantajları**

1. **Esneklik:**
   - Operatörler sınıfın dışında tanımlanabilir ve yine de özel üyelere erişebilir.

2. **İyi Tasarım:**
   - Giriş/çıkış operatörleri gibi sınıfın üyesi olamayacak operatörleri destekler.
   - Sınıfın doğal bir şekilde kullanılmasını sağlar.

3. **Kodun Okunabilirliği:**
   - Karmaşık işlemleri daha temiz bir şekilde ifade eder.

## **Friend Olmayan Operatörler**

Her operatörün friend olmasına gerek yoktur. Eğer bir operatör yalnızca sınıfın genel (`public`) üyelerine erişiyorsa, 
sınıfın üyesi olarak tanımlanabilir veya friend olmadan işlevsel olabilir.

**Örnek:**

#include <iostream>

class Vector {
    int x, y;

public:
    Vector(int x, int y) : x(x), y(y) {}

    // Sınıf üyesi olarak + operatörünü tanımlıyoruz
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }
};

int main() {
    Vector v1(1, 2), v2(3, 4);
    Vector v3 = v1 + v2; // + operatörü çalışır
    return 0;
}

Bu durumda, `+` operatörünün `friend` olmasına gerek yoktur çünkü tüm verilere sınıf üyesi olarak zaten erişilebilir.

## **Sonuç**

- **Friend operatörler**, sınıfın özel veya korumalı üyelerine erişim gerektiren durumlarda kullanılır.
- Özellikle `<<` ve `>>` gibi giriş/çıkış operatörleri, friend olarak tanımlanır.
- Diğer operatörlerde friend tanımlamaya yalnızca erişim gereksinimi varsa ihtiyaç duyulur.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **Zero-cost abstraction (Sıfır maliyetli soyutlama)**, bir yazılım tasarım felsefesidir. Bu felsefe, bir soyutlamanın performans üzerindeki 
etkisinin, aynı işlevselliği daha düşük seviyeli bir yöntemle manuel olarak gerçekleştirdiğinizdeki etkiden farklı olmaması gerektiğini belirtir.
Başka bir deyişle, bir soyutlama kullanmanın maliyeti, elle optimize edilmiş bir kod yazmanın maliyetiyle eşdeğer olmalıdır.

## **Zero-cost Abstraction'ın Temel İlkeleri**
1. **Hiçbir Gizli Maliyet Yoktur:**
   - Soyutlama katmanları performans açısından belirgin bir ceza getirmemelidir.
   - Örneğin, bir `std::vector` kullanırken, belleğe erişim ve işlem maliyetleri, elle yönetilen dinamik bir diziyle aynı seviyede olmalıdır.

2. **Kullanılmayan Özellikler için Maliyet Yoktur:**
   - Eğer bir özelliği kullanmıyorsanız, onun için ekstra maliyet (runtime veya memory) ödememelisiniz.
   - Örneğin, `std::optional` gibi bir tür, bir değer içerdiğinde yalnızca ek bir bayrak saklar; boş olduğunda ekstra masraf yaratmaz.

3. **Soyutlama, Derleme Zamanında Kaldırılabilir:**
   - C++'ın `inline` fonksiyonları, şablonları ve derleyicinin optimizasyonları sayesinde soyutlamaların büyük kısmı derleme zamanında kaldırılabilir. 
   Bu, runtime performansını etkilemeden yüksek seviyeli bir kod yazmayı mümkün kılar.

## **Zero-cost Abstraction'a Örnekler**

### **1. Şablonlar ve Metaprogramlama**
C++ şablonları, derleme zamanında özelleştirilir ve kodun çalıştırılmasında ek bir maliyet oluşturmaz.

**Örnek:**

#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    std::cout << add(x, y) << std::endl; // 15
    return 0;
}

**Açıklama:**
- `add` fonksiyonu, derleme zamanında türüne göre özelleştirilir.
- Ekstra bir soyutlama maliyeti (örneğin, sanal fonksiyon çağrısı) yoktur.

### **2. `std::vector` ve Dinamik Diziler**
`std::vector`, bellek yönetimini kolaylaştırır ve tipik olarak elle yazılan bir dinamik dizi kadar verimli çalışır.

**Örnek:**

#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    vec.push_back(5);

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}

**Açıklama:**
- `std::vector`, soyutlamasına rağmen, elle yönetilen bir dinamik dizinin maliyetine yakındır.
- Bellek yeniden tahsisi gibi işlemler verimli bir şekilde optimize edilmiştir.

### **3. Lambda Fonksiyonları**
Lambda ifadeleri, basit bir şekilde inline kod olarak yerleştirilir, bu da soyutlamaya rağmen performans maliyetinin düşük olmasını sağlar.

**Örnek:**

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x * 2 << " ";
    });

    return 0;
}

**Açıklama:**
- Lambda ifadesi, derleme zamanında inline olarak optimize edilir.
- Ekstra bir fonksiyon çağrısı veya nesne oluşturma maliyeti yoktur.

### **4. `std::optional` Kullanımı**
`std::optional`, bir değerin varlığını ifade eder ve bunu düşük maliyetle yapar.

**Örnek:**

#include <optional>
#include <iostream>

int main() {
    std::optional<int> opt = 42;

    if (opt) {
        std::cout << "Value: " << *opt << std::endl;
    } else {
        std::cout << "No value" << std::endl;
    }

    return 0;
}

**Açıklama:**
- `std::optional`, varlık kontrolü için bir bayrak kullanır. Bu, elle yapılan bir "bool + değer" yapısına eşdeğerdir.

## **Zero-cost Abstraction'ın Faydaları**

1. **Performans ile Kolaylık Arasında Dengeler:**
   - Düşük seviyeli dillerin (örneğin, C) performansını korurken, yüksek seviyeli dillerin (örneğin, Python) kolaylığını sunar.

2. **Yazılım Geliştirme Hızını Artırır:**
   - Soyutlama katmanları, daha az hata ve daha okunabilir kod sağlar.

3. **Derleyici Optimizasyonları ile Uyumlu:**
   - Modern C++ derleyicileri, gereksiz kodları ortadan kaldırarak (örneğin, inline) soyutlamaların maliyetini düşürür.

## **Zero-cost Abstraction'ın Limitasyonları**

1. **Derleyiciye Güven:**
   - Zero-cost abstraction, büyük ölçüde derleyicinin optimizasyon yeteneklerine dayanır.
   - Zayıf bir derleyici veya optimizasyon seçeneği, soyutlamaların maliyetini artırabilir.

2. **Soyutlama Karmaşıklığı:**
   - Çok karmaşık soyutlamalar, beklenmedik bir şekilde performansı etkileyebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
operator + ile operator += operator functionları birbirine çok benzer oldukları için scoot mayers ın dediğine göre operator += fonksiyonunu operator + fonksiyonunu çağırarak yazmak daha iyi olur.

class Myclass {
public:

	friend Myclass operator+(const Myclass& lhs,const Myclass& rhs) // global operator function
	{
		return Myclass{lhs} += rhs;
		
	}

	Myclass& operator+=(const Myclass& rhs) { member operator function
		
		mval += rhs.mval;
		return *this;
	}

private:
	int mval;
};
--------------------------------------------------------------------------------------------------------------------------------------------------
bazı operatörlerin hepsini implemente etmek yerine birbirlerini çağırıyorlar

### Eşitlik ve Eşitsizlik Operatörleri (`==` ve `!=`)
friend bool operator==(const MyClass& lhs, const MyClass& rhs) {
    return lhs.value == rhs.value;
}

friend bool operator!=(const MyClass& lhs, const MyClass& rhs) {
    return !(lhs == rhs);
}

### Karşılaştırma Operatörleri (`<`, `<=`, `>`, `>=`)
friend bool operator<(const MyClass& lhs, const MyClass& rhs) {
    return lhs.value < rhs.value;
}

friend bool operator<=(const MyClass& lhs, const MyClass& rhs) {
    return !(rhs < lhs); // <= türetiliyor
}

friend bool operator>(const MyClass& lhs, const MyClass& rhs) {
    return rhs < lhs; // > türetiliyor
}

friend sbool operator>=(const MyClass& lhs, const MyClass& rhs) {
    return !(lhs < rhs); // >= türetiliyor
}

primary Operatörler: ==, <, >, <=, >= gibi temel karşılaştırma operatörleridir.

secondary Operatörler: != gibi operatörler, birincil operatörler kullanılarak tanımlanabilir. Örneğin, != operatörü, == operatörünün sonucu ters çevrilerek (!(a == b)) elde edilebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
operatör spaceship ile bu fonksiyonların hepsini yazmadan sadece tek bir fonksiyon ile bu sorunu çözebiliyoruz

C++20 ile tanıtılan **üç yönlü karşılaştırma operatörü** `<=>`, görünümü nedeniyle **"spaceship operatörü"** olarak da adlandırılır. 
Bu operatör, iki nesne arasında karşılaştırma yaparak, nesnelerin birbirine göre küçük, eşit veya büyük olduğunu belirler. 
Sonuç olarak, `<`, `<=`, `==`, `!=`, `>=` ve `>` gibi karşılaştırma operatörlerinin tek bir operatörle ifade edilmesini sağlar.

**Kullanımı:**

`<=>` operatörü, sınıf içinde tanımlanarak, o sınıfın nesneleri arasında karşılaştırma yapılmasına olanak tanır. Örneğin:

#include <compare>

struct MyClass {
    int value;

    auto operator<=>(const MyClass&) const = default;
};

Bu örnekte, `MyClass` yapısının `value` üyesi için `<=>` operatörü varsayılan olarak tanımlanmıştır. Bu sayede, `MyClass` 
nesneleri arasında tüm karşılaştırma işlemleri otomatik olarak gerçekleştirilebilir.

**Faydaları:**

- **Kod Basitliği:** Tek bir operatör tanımıyla birden fazla karşılaştırma işlemi gerçekleştirilebilir, bu da kodun daha temiz ve anlaşılır olmasını sağlar.

- **Bakım Kolaylığı:** Karşılaştırma mantığı tek bir yerde tanımlandığı için, kodun bakımı ve güncellenmesi daha kolaydır.

- **Performans:** Derleyici, `<=>` operatörünü kullanarak optimize edilmiş karşılaştırma kodu üretebilir.

**Dikkat Edilmesi Gerekenler:**

`<=>` operatörünün dönüş tipi, karşılaştırmanın türüne bağlı olarak `std::strong_ordering`, `std::weak_ordering` veya `std::partial_ordering`
olabilir. Bu türler, karşılaştırmanın gücünü ve doğruluğunu belirtir.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta `++` operatörü iki farklı şekilde aşırı yüklenebilir:

1. **Prefix (Önek)**: `++x`
2. **Postfix (Sonek)**: `x++`

Bu iki kullanım arasındaki farklar, hem işlev hem de aşırı yükleme yöntemi açısından önemlidir. Aşağıda bu farkları detaylandırdım:

### 1. **Prefix (Önek) `++x`**
- **İşlevi**: Değişkenin değerini önce artırır, ardından bu artırılmış değeri döndürür.
- **Kullanım Durumu**: Daha hızlıdır çünkü genellikle bir geçici (temporary) nesne oluşturmaz.
- **İmplementasyon**:

    MyClass& operator++() {
        // Önce artır
        ++value;
        // Kendisini döndür
        return *this;
    }

- **Kullanım Örneği**:

    MyClass obj;
    ++obj; // Değer artırılır ve artırılmış değer kullanılır

### 2. **Postfix (Sonek) `x++`**
- **İşlevi**: Değişkenin mevcut değerini döndürür, ardından değeri artırır.
- **Kullanım Durumu**: Daha maliyetlidir çünkü geçici bir nesne oluşturur (artırılmadan önceki değeri tutmak için).
- **İmplementasyon**:

    MyClass operator++(int) {
        MyClass temp {*this}; // Geçici nesne oluştur
        ++value;              // Artır
        return temp;          // Artırılmadan önceki değeri döndür
    }

- **Kullanım Örneği**:

    MyClass obj;
    obj++; // Değer döndürülür, ardından artırılır

### Farklar Tablosu

| Özellik               | Prefix (`++x`)                       | Postfix (`x++`)                       |
|-----------------------|---------------------------------------|----------------------------------------|
| **Artırma Sırası**    | Değer artırılır, ardından döndürülür  | Değer döndürülür, ardından artırılır   |
| **Performans**        | Daha hızlıdır                        | Daha yavaştır (geçici nesne oluşturur)|
| **Dönüş Değeri**      | Kendisine (`MyClass&`) referans döner| Geçici nesne (`MyClass`) döner         |

### Hangisini Ne Zaman Kullanmalı?

- **Prefix (`++x`)**:
  Performans kritik yerlerde tercih edilmelidir. Örneğin, bir döngüde:

  for (int i = 0; i < 10; ++i) {
      // İşlemler
  }

  Prefix kullanımı burada daha verimli olur.

- **Postfix (`x++`)**:
  Geçici nesneye ihtiyaç duyulan durumlarda kullanılır, ancak genellikle postfix operatörünün maliyetini göz önünde bulundurmak önemlidir.

### Örnek: Prefix ve Postfix Farkını Gösterme

#include <iostream>

class MyClass {
    int value;

public:
    MyClass(int val) : value(val) {}

    // Prefix
    MyClass& operator++() {
        ++value;
        return *this;
    }

    // Postfix
    MyClass operator++(int) {
        MyClass temp{*this};
           ++*this; // nesnenin değerini 1 arttırmak için prefix fonksiyonunu çağırıyopr operator++(); olarakta çağırılabilirdi yada ++value; olarakta çağırılabilirdi
        return temp;
    }

    int getValue() const { return value; }
};

int main() {
    MyClass obj(5);

    // Prefix
    ++obj;
    std::cout << "Prefix: " << obj.getValue() << std::endl;

    // Postfix
    obj++;
    std::cout << "Postfix: " << obj.getValue() << std::endl;

    return 0;
}

### Çıktı:

Prefix: 6  
Postfix: 7

 -- decrement operatörü içinde aynı yazım geçerlidir
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta "array-like" sınıflar, dizilerle benzer şekilde davranan ancak ek özellikler sunan sınıflardır. Bu sınıflar, dizilerin sunduğu sabit boyutlu 
ve ardışık bellek düzenini korurken, ek olarak daha fazla işlevsellik ve güvenlik sağlar.

**`std::array` Sınıfı:**

C++11 ile tanıtılan `std::array`, sabit boyutlu dizilerin modern bir temsilidir. `std::array`, C tarzı dizilerin sunduğu performansı ve 
erişilebilirliği, standart konteynerlerin sunduğu avantajlarla birleştirir. Örneğin, kendi boyutunu bilme, atama işlemleri, rastgele erişim iteratörleri gibi özellikler sunar.

**Özellikler:**

- **Sabit Boyut:** `std::array`, derleme zamanında belirlenen sabit bir boyuta sahiptir.
- **Dizi Semantiği:** C tarzı dizilerle aynı bellek düzenini kullanır, ancak ek işlevsellik sunar.
- **Standart Konteyner Özellikleri:** `std::array`, konteyner gereksinimlerini karşılar ve `std::vector` gibi diğer konteynerlerle benzer işlevsellik sunar.

**Örnek Kullanım:**

#include <array>
#include <iostream>

int main() {
    // 5 elemanlı bir std::array oluşturuluyor
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Elemanlara erişim
    std::cout << arr[0] << std::endl; // 1

    // Boyut bilgisi
    std::cout << arr.size() << std::endl; // 5

    // std::array ile for-each döngüsü
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

Bu örnekte, `std::array` kullanarak sabit boyutlu bir dizi oluşturulmuş ve çeşitli işlemler gerçekleştirilmiştir.

**Dikkat Edilmesi Gerekenler:**

- **Boyut Sabitliği:** `std::array`'in boyutu derleme zamanında belirlenir ve çalışma zamanında değiştirilemez.
- **Bellek Yönetimi:** `std::array`, C tarzı diziler gibi stack üzerinde depolanır ve otomatik olarak bellek yönetimi sağlar.

"Array-like" sınıflar, dizilerin sunduğu performansı ve bellek düzenini korurken, ek işlevsellik ve güvenlik sağlayarak daha modern ve esnek bir kullanım sunar.
--------------------------------------------------------------------------------------------------------------------------------------------------
    int ar[5] = { 10,20,30,40,50 };

    for (int i = 0; i < 5; ++i)
    {
        std::cout << ar[i] << *(ar + i) << *(i + ar) << i[ar]; // hepsi aynı anlama gelir ve adrese ulaşır
    }

adres + tam sayı  = adres elde edilir
tam sayı + adres  = adres elde edilir
adres + adres = sentaks hatası
adres -  adres = işaretli tam sayı türü ptrdiff_t implementation defined
--------------------------------------------------------------------------------------------------------------------------------------------------
C++17 ile tanıtılan `[[nodiscard]]` özniteliği, bir işlevin dönüş değerinin göz ardı edilmemesi gerektiğini belirtmek için kullanılır. 
Bu öznitelik, sınıf tanımına uygulandığında, o sınıfın türündeki dönüş değerlerinin kullanılmaması durumunda derleyicinin uyarı vermesini sağlar.

**Sınıfa `[[nodiscard]]` Uygulama:**

Bir sınıfı `[[nodiscard]]` olarak işaretlemek için, sınıf tanımının başına bu özniteliği ekleyebilirsiniz:

struct [[nodiscard]] ErrorInfo {
    // ...
};

Bu şekilde işaretlenmiş bir sınıfın nesnesi, dönüş değeri olarak kullanıldığında ve bu değer kullanılmadığında derleyici bir uyarı verecektir.

**Örnek Kullanım:**

struct [[nodiscard]] ErrorInfo {
    // ...
};

ErrorInfo enableMissileSafetyMode() {
    // ...
    return {};
}

void launchMissiles() {
    // ...
}

void testMissiles() {
    enableMissileSafetyMode(); // Derleyici burada uyarı verebilir
    launchMissiles();
}

Yukarıdaki örnekte, `enableMissileSafetyMode` işlevi `ErrorInfo` türünde bir değer döndürmektedir. Ancak, dönüş değeri kullanılmadığı 
için derleyici bir uyarı verebilir. Bu, önemli dönüş değerlerinin yanlışlıkla göz ardı edilmesini önlemeye yardımcı olur.

**C++20 ile Gelen Geliştirme:**

C++20'de, `[[nodiscard]]` özniteliğine bir açıklama ekleyerek, uyarı mesajında özel bir bilgi vermek mümkündür:

struct [[nodiscard("Bu sınıfın dönüş değeri kullanılmalıdır")]] ErrorInfo {
    // ...
};

Bu şekilde, derleyicinin verdiği uyarı mesajına özel bir açıklama eklenebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
class  Myclass {
public:

    void func();

private:

};



int main()
{
    Myclass m;

    m.func(); // l value ile
    Myclass{}.func(); // r value ile

}
******************************************************************************************************************************
 
                                                                            ********* 16-DERS NOTLARI *********

C++'da **reference qualifier** (referans niteleyicisi), sınıfın non static üye işlevlerin (`member functions`) hangi türde nesnelerle çağrılabileceğini
belirtmek için kullanılan bir mekanizmadır. Bu niteleyiciler, özellikle nesnelerin lvalue (sol-değer) veya rvalue (sağ-değer) olarak
kullanıldığı durumlarda işlev aşırı yüklemesi yapmak için kullanılır.

## **Reference Qualifier Çeşitleri**

Bir üye işlevde kullanılan referans niteleyicileri şunlardır:

1. **Hiçbir niteleyici olmaması:** İşlev, hem lvalue hem de rvalue nesnelerle çağrılabilir.

   void foo();

2. **Lvalue Referans Niteleyici (`&`):** İşlev sadece lvalue nesnelerle çağrılabilir.

   void foo() &;

3. **Rvalue Referans Niteleyici (`&&`):** İşlev sadece rvalue nesnelerle çağrılabilir.

void foo() &&;

## **Nasıl Çalışır?**

Bir üye işlevi belirli bir referans türüyle sınırlandırmak için referans niteleyicileri kullanılır. İşlevin çağrıldığı nesnenin
türü, derleyici tarafından kontrol edilir ve uygun niteleyiciye sahip olan işlev çağrılır.

## **Örneklerle Anlatım**

### **1. Temel Kullanım**

#include <iostream>

class MyClass {
public:
    void foo() & {
        std::cout << "Lvalue çağrıldı" << std::endl;
    }
    void foo() && {
        std::cout << "Rvalue çağrıldı" << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.foo();           // Lvalue nesneyle çağrı: "Lvalue çağrıldı"
    MyClass().foo();     // Rvalue nesneyle çağrı: "Rvalue çağrıldı"
    return 0;
}

**Açıklama:**
- `obj.foo()` çağrısı, `obj` bir lvalue olduğundan `foo() &` sürümünü çağırır.
- `MyClass().foo()` çağrısı, geçici bir rvalue nesnesi olduğundan `foo() &&` sürümünü çağırır.

### **2. Reference Qualifier Olmadan**
Eğer referans niteleyicileri kullanılmazsa, üye işlev hem lvalue hem de rvalue nesnelerle çağrılabilir:

class MyClass {
public:
    void foo() {
        std::cout << "Her iki türde de çağrılır" << std::endl;
    }
};

### **3. Const ve Reference Qualifier Birlikte**
Referans niteleyiciler, `const` ile birlikte kullanılabilir. Bu, işlevlerin hem lvalue/rvalue durumlarını hem de `const` durumlarını kontrol etmesine olanak tanır.

#include <iostream>

class MyClass {
public:
    void foo() const & {
        std::cout << "Const Lvalue çağrıldı" << std::endl;
    }

    void foo() & {
       std::cout << "Const olmayan Lvalue çağrıldı" << std::endl;

    }

    void foo() && {
        std::cout << "Const olmayan Rvalue çağrıldı" << std::endl;
    }

    void foo() yaparsak sentaks hatası olur qualifier olarak kullanmak zorundayız

};

int main() {
    const MyClass obj;
    obj.foo();           // Const Lvalue nesneyle çağrı: "Const Lvalue çağrıldı"
    MyClass().foo();     // Geçici Rvalue nesneyle çağrı: "Const olmayan Rvalue çağrıldı"
    return 0;
}

## **Üye İşlevlerde Reference Qualifier Kullanmanın Amacı**

1. **Lvalue ve Rvalue Farklı Davranışları:** Nesnenin lvalue veya rvalue olmasına bağlı olarak farklı işlemler yapılabilir.
2. **Bellek Optimizasyonu:** Rvalue nesnelerle çağrılabilen işlevler genellikle geçici nesneleri taşımak (`move`) veya verimlilik için optimize edilmiş işlemleri gerçekleştirmek için kullanılır.
3. **Hata Yakalama:** Yanlış referans türünde işlev çağrılarından kaçınmayı sağlar.

## **Reference Qualifier Kullanımında Dikkat Edilmesi Gerekenler**

1. Referans niteleyiciler, yalnızca **üye işlevlerde** kullanılabilir. Serbest işlevlerde (`free functions`) veya statik üye işlevlerde (`static member functions`) kullanılamaz.
2. İşlev aşırı yüklemesi yaparken uygun niteleyiciyle işlevin çağrıldığından emin olunmalıdır.
3. Eğer `const` ve referans niteleyiciler bir arada kullanılacaksa, doğru kombinasyonlarla işlev tanımları yapılmalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
de-reference(*) operatörünü kullanmamız için adres olması zorunlu bu operatörün oluşturduğu ifade l value expr

int i = {50};

*i // hata adres olmak zorunda

int *ptr = &i;

*ptr // doğru

unary prefix operatördür
--------------------------------------------------------------------------------------------------------------------------------------------------
member selection operatörü bniary operatör ama dilin kurlları gereği unary operatör olarak overload edliyor

Myclass* operator->()
{
    return mp;
}

derleyici ptr'nin bir sınıf nesnesi olduğunu gördüğünde ptr.operator->()->foo(); şeklinde çağrı yapar

arrow operatörünn geri dönüş değeri pointer olmalı

### **`->` Operatörünün Overload Edilmesi**
**`->` operatörü**, bir pointer'ın üye erişim işlemlerinde kullanılır. Eğer bir sınıfın `->` operatörünü overload ederseniz, bu operatör bir
pointer döndürmek zorundadır. Pointer üzerinden yapılan üye erişimi, dönen nesnenin üzerine uygulanır.

### **Kullanım Örneği**
Aşağıda `->` operatörünün overload edilmesine bir örnek verilmiştir:

#include <iostream>
#include <memory>

class Inner {
public:
    void display() const {
        std::cout << "Inner sınıfına erişildi.\n";
    }
};

class Outer {
private:
    Inner inner;
public:
    Inner* operator->() {
        return &inner; // Pointer döndürülmesi zorunludur.
    }
};

int main() {
    Outer outer;
    outer->display(); // Outer üzerinden Inner'ın display() fonksiyonu çağrılır.

    return 0;
}

### **Nasıl Çalışır?**
1. `outer->display()` ifadesi, önce `Outer` sınıfındaki `operator->` işlevini çağırır.
2. `operator->` işlevi, `Inner` sınıfının bir pointer'ını döndürür.
3. Ardından, `display()` çağrısı bu pointer üzerinden yapılır.

### **Önemli Notlar**
1. **Pointer Döndürme Zorunluluğu**:
   `operator->` bir pointer döndürmelidir. Eğer bu kural ihlal edilirse, derleyici hata verir.

2. **Zincirleme Kullanım**:
   Eğer dönen pointer üzerinden de `->` operatörü kullanılabilir durumdaysa, bu işlem zincirleme yapılabilir:

   outer->nestedMethod()->anotherMethod();

3. **Akıllı Pointer'larda Kullanımı**:
   `std::unique_ptr` ve `std::shared_ptr` gibi sınıflar, `->` operatörünü overload ederek içeride tuttukları nesnenin üyelerine erişimi sağlarlar.

### **Sınırlamalar**
- `->` operatörünü sadece sınıflarda overload edebilirsiniz.
- Pointer olmayan türler için bu operatörün anlamı yoktur.

### **Sonuç**
`->` operatörünü overload etmek mümkündür ve genelde iç içe nesnelerle çalışırken veya proxy sınıflarında kullanılır. 
Ancak overload sırasında bir pointer döndürme zorunluluğu olduğundan dikkatli kullanılmalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
class  A {
public:

    void foo();

};

class  B {
public:
    A* operator->();

};

class  C {
public:
    B operator->();


};


int main()
{
    C cx;
    cx->foo(); // derleyici bu ifadeyi cx->operator->().operator->()->foo(); haline çevirir
    // pek kullanılan bir senaryo değildir
}
--------------------------------------------------------------------------------------------------------------------------------------------------
bir fonksiyonun geri dönüş değeri ne olabiliyorsa fonksiyon çağrı operatörü içinde bu kural geçerlidir

global fonksiyon olamazlar ve non-static member function olmak zorundalar

default argüman alabilirler bu sadece function call operatöre özgü bir şeydir

function overload edilebilirler
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **function object ** (veya functor yada popüler olarak callable), bir fonksiyon gibi davranan sınıf nesnesidir. Bu, bir sınıfın `operator()` (function call operator)
üyesinin overload edilmesiyle elde edilir. Function object'ler, standart algoritmalarda, lambda ifadelerinde veya özel davranışlar için yaygın olarak kullanılır.

### **Function Object'in Tanımı**
Bir **function object**, bir fonksiyon çağırma operatörünü (`operator()`) overload eden bir sınıfın nesnesidir. Böylece nesne, bir fonksiyon gibi çağrılabilir.

### **Örnek**

#include <iostream>

class FunctionObject {
public:
    void operator()(int x) const {
        std::cout << "Function object called with: " << x << '\n';
    }
};

int main() {
    FunctionObject f; // Function object oluşturuluyor
    f(42); // Function object bir fonksiyon gibi çağrılıyor
    return 0;
}

#### **Çıktı:**

Function object called with: 42

### **Kullanım Alanları**

#### **1. Standart Algoritmalar**
Function object'ler, STL algoritmalarında özel davranışlar sağlamak için yaygın olarak kullanılır.

**Örnek:**

#include <algorithm>
#include <vector>
#include <iostream>

class IsOdd {
public:
    bool operator()(int x) const {
        return x % 2 != 0;
    }
};

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto it = std::find_if(v.begin(), v.end(), IsOdd());
    if (it != v.end()) {
        std::cout << "First odd number: " << *it << '\n';
    }
    return 0;
}

#### **2. Durum (State) Tutma**
Function object'ler, bir veya daha fazla üye değişkenle birlikte durum bilgisi tutabilir.

**Örnek:**

class Adder {
    int offset;
public:
    Adder(int off) : offset(off) {}
    int operator()(int x) const {
        return x + offset;
    }
};

int main() {
    Adder add10(10);
    std::cout << add10(5) << '\n'; // 15
    return 0;
}

### **Avantajları**
1. **Durum Bilgisi Tutabilir**: Function object'ler, içlerinde durum (state) saklayabilir, bu da normal fonksiyonlardan farklı bir avantajdır.
2. **STL ile Uyumlu**: Standart algoritmalar ve konteynerlarla birlikte kullanılabilir.
3. **Inline Fonksiyonlardan Daha Hızlı Olabilir**: Compiler optimization ile inline hale getirilebilir.

### **Alternatif: Lambda Fonksiyonlar**
Function object'lerin kullanım alanlarının çoğu, lambda ifadeleriyle de çözülebilir.

**Örnek:**

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto it = std::find_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
    if (it != v.end()) {
        std::cout << "First odd number: " << *it << '\n';
    }
    return 0;
}

### **Sonuç**
**Function object**, bir sınıfın nesnesini bir fonksiyon gibi davranmasını sağlayarak esneklik sunar. Durum bilgisi taşıma yeteneği 
ve STL ile uyumu, onu güçlü bir araç haline getirir. Ancak modern C++'ta lambda ifadeleri daha sık tercih edilir çünkü daha okunaklıdır
ve kısa kullanımlar için uygundur.
--------------------------------------------------------------------------------------------------------------------------------------------------
class  Nec {
public:

     operator int() const
    {
        std::cout << "operator int()\n";
        return 1;
    }

};


int main()
{
    int ival{};

    Nec mynec;

    ival = mynec; // mynec.operator int() çağrılır

    explicit operator int() const olsaydı böyle kullanmamız gerekirdi

   ival = static_cast<int>(mynec); // mynec.operator int() çağrılır
    ival = (int)mynec; // mynec.operator int() çağrılır
    ival = int(mynec); // mynec.operator int() çağrılır
    ival = mynec.operator int(); // mynec.operator int() çağrılır
    ival = (int)mynec.operator int(); // mynec.operator int() çağrılır

}
--------------------------------------------------------------------------------------------------------------------------------------------------
explicit keywordü conversion constructor için ve tür dönüştürme operatörleri için kullanılır
--------------------------------------------------------------------------------------------------------------------------------------------------
`operator int()` C++ dilinde kullanılan bir **dönüştürme (conversion) operatörü**dür. Bu operatör, özel bir sınıfın nesnesinin, 
tamsayı (int) türüne dönüştürülmesine izin verir.

### **Kullanımı ve Tanımı**
`operator int()` bir sınıfın üye işlevi olarak tanımlanır. Bu işlev, sınıfın bir nesnesinin `int` türüne dönüştürülmesini sağlar. İşlevin tanımı şöyledir:

class MyClass {
public:
    operator int() const {
        // Sınıfın bir nesnesini int'e dönüştürmek için gerekli kod
        return some_integer_value;
    }
};

### **Örnek Kullanım**
Aşağıda basit bir örnek verilmiştir:

#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    // int'e dönüştürme operatörü
    operator int() const {
        return value;
    }
};

int main() {
    MyClass obj(42);

    // int'e otomatik dönüşüm
    int intValue = obj;

    cout << "intValue: " << intValue << endl; // Çıktı: intValue: 42

    return 0;
}

### **Neden Kullanılır?**
1. **Tür Dönüşümü Kolaylığı:**
   - Bir sınıfın nesnesini doğal bir şekilde `int` veya başka bir türde işlem yapmak için kullanılabilir hale getirir.

2. **Kod Okunabilirliği:**
   - Operatör kullanımı sayesinde, bir nesneyi açıkça dönüştürmek yerine dolaylı yoldan işlem yapılabilir.
   - Örneğin, `int x = obj.operator int();` yerine `int x = obj;` yazılabilir.

3. **Özelleştirilmiş Davranış:**
   - Bir sınıfın nesnesinin belirli bir türe dönüştürülürken özel bir işlem yapılmasını sağlar.

### **Dikkat Edilmesi Gerekenler**
1. **Yan Etkiler ve Anlam Karışıklığı:**
   - `operator int()` tanımlandığında, sınıfın nesnesi birçok bağlamda otomatik olarak `int` türüne dönüştürülebilir. Bu, beklenmeyen davranışlara neden olabilir.

2. **Explicit Kullanımı (C++11 ve Sonrası):**
   - Eğer otomatik dönüşümlerden kaçınmak istiyorsanız, `explicit` anahtar sözcüğünü kullanabilirsiniz. Bu, dönüşümün yalnızca açık bir şekilde çağrıldığında gerçekleşmesini sağlar.

   class MyClass {
   private:
       int value;

   public:
       MyClass(int v) : value(v) {}

       explicit operator int() const {
           return value;
       }
   };

   int main() {
       MyClass obj(42);

       // int intValue = obj; // HATA: explicit nedeniyle otomatik dönüşüm engellenir
       int intValue = static_cast<int>(obj); // Doğru: explicit dönüşüm

       return 0;
   }
--------------------------------------------------------------------------------------------------------------------------------------------------
operator int() ile ilgili olan reference_wrapper örneği

int main()
{
    int x = 10;
    std::reference_wrapper r = x;

    ++r; // burda r aslında ++r.operator int& (); fonksiyonuna çağrı yapıyor

    std::cout << x << "\n";

}
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Adres operatörüyle oluşturulan bir ifade PR value expression

void func(char*& x)
{
	std::cout <<"&x"<< x << "\n";
}
void func(char*&& x)
{
    std::cout << "&&"<<x << "\n";
}

char c{ 'A' };

func(&c); // func&& olan çaçğırılır

char *p{&c];

func(p) ; // p bir l value exp olduğu için şimdi func& olan çağrılır
******************************************************************************************************************************
                                                                             
                                                                             ********* 17-DERS NOTLARI *********

new operatörü başka bir terim operator new başka bir terim

derleyici operator new ifadesiyle karşılaştığında öncelikle operatör new fonksiyonuna çağrı yapıcak bir kod oluşturuyor 
bu fonksiyona arügman olarak new e operand olan türün sizeof değerini yani storage değerini geçiyor

malloc ile new arasındaki  farklar 

C++'ta **`malloc`** ve **`new`** bellek tahsisi için kullanılan iki farklı mekanizmadır, ancak aralarında önemli farklar vardır. 
Aşağıda, her iki yöntemin tüm farklarını detaylıca ele alıyoruz:

### **1. Bellek Tahsisi**
- **`malloc`:**
  - C dilinden gelir ve C++’ta da kullanılabilir.
  - `malloc(size)` belirli bir bayt miktarı için ham bellek tahsisi yapar.
  - Tahsis edilen bellek, sadece ham (uninitialized) bellek alanıdır ve herhangi bir nesne oluşturulmaz.
  - Kullanım:

    int* ptr = (int*)malloc(sizeof(int)); // C++'ta tür dönüşümü gerekir

- **`new`:**
  - C++'a özgüdür ve nesnelerin oluşturulmasını destekler.
  - Bir nesnenin belleğini tahsis eder ve aynı anda kurucusunu çağırır.
  - Kullanım:

    int* ptr = new int; // Bellek tahsis edilir ve int nesnesi oluşturulur

### **2. Başlatma (Initialization)**
- **`malloc`:**
  - Tahsis edilen bellek başlatılmamış halde bırakılır.
  - Belleği sıfırlamak için `memset` gibi fonksiyonlar kullanılabilir.

    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 0; // Elle başlatma

- **`new`:**
  - Tahsis edilen bellek, varsayılan kurucu ile başlatılır.

    int* ptr = new int(42); // Başlatılmış bellek

### **3. Tür Desteği**
- **`malloc`:**
  - Tür bilgisi içermez; dönüş tipi `void*` olduğu için tür dönüşümü gerekir.

    int* ptr = (int*)malloc(sizeof(int));

- **`new`:**
  - Tür bilgisi içerir ve tür dönüşümüne gerek yoktur.

    int* ptr = new int;

### **4. Kurucu ve Yıkıcı**
- **`malloc`:**
  - Sadece ham bellek tahsis eder, kurucu çağrılmaz.
  - Yıkıcıyı elle çağırmanız gerekir (örneğin, sınıf nesnelerinde).

    MyClass* obj = (MyClass*)malloc(sizeof(MyClass));
    obj->~MyClass(); // Yıkıcıyı elle çağırma

- **`new`:**
  - Bellek tahsisi ile birlikte kurucuyu çağırır.
  - Belleği serbest bırakırken (`delete`), yıkıcıyı otomatik olarak çağrırır.

    MyClass* obj = new MyClass();
    delete obj; // Yıkıcı otomatik çağrılır

### **5. Belleği Serbest Bırakma**
- **`malloc`:**
  - Tahsis edilen belleği serbest bırakmak için `free` kullanılır.

    free(ptr);

- **`new`:**
  - Tahsis edilen belleği serbest bırakmak için `delete` kullanılır.

    delete ptr;

### **6. Hata Durumları**
- **`malloc`:**
  - Bellek tahsisi başarısız olursa, `NULL` döner.

    int* ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        // Hata kontrolü
    }

- **`new`:**
  - Bellek tahsisi başarısız olursa, bir `std::bad_alloc` istisnası fırlatır.

    try {
        int* ptr = new int;
    } catch (std::bad_alloc& e) {
        // Hata kontrolü
    }

### **7. Performans**
- **`malloc`:**
  - Daha düşük seviyeli bir fonksiyondur ve sadece ham bellek tahsisi yapar.
  - Kurucu/yıkıcı işlemleri olmadığı için bazen daha hızlı olabilir.

- **`new`:**
  - Kurucu çağrıldığı için biraz daha maliyetlidir, ancak modern C++ derleyicileri bunu optimize edebilir.

### **8. Kullanım Amacı**
- **`malloc`:**
  - Daha çok ham bellek tahsisi için kullanılır.
  - C tarzı programlama ve C++ ile C kodlarının entegrasyonu için uygundur.

- **`new`:**
  - Nesne yönelimli programlama için tasarlanmıştır.
  - Kurucu ve yıkıcı çağrısını destekler.

### **9. Bellek Alanı**
- **`malloc`:**
  - Tahsis edilen bellek, yığın (heap) alanından gelir.

- **`new`:**
  - Tahsis edilen bellek de yığın (heap) alanından gelir.

### **Hangi Durumda Hangisi Kullanılmalı?**
- **`malloc`:**
  - C tarzı programlama yapıyorsanız veya ham bellek tahsisine ihtiyacınız varsa.
  - Eski kodlarla uyumluluk gerektiğinde.

- **`new`:**
  - Modern C++ programlamasında, özellikle nesne oluşturmanız gerektiğinde.
  - Kurucu ve yıkıcı gerektiren durumlarda.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **smart pointer** (akıllı işaretçiler), dinamik bellek yönetimini daha güvenli ve kolay hale getiren, standart kütüphanede 
sunulan sınıf şablonlarıdır. **Raw pointer** (ham işaretçiler) ile çalışmanın getirdiği bellek sızıntısı, yanlış bellek erişimi gibi 
sorunları önlemeyi amaçlar.

### **1. Smart Pointer Nedir?**
Smart pointer'lar, bir nesneye olan sahipliği ve ömrünü yönetir. Dinamik olarak tahsis edilen bir nesneyi otomatik olarak serbest bırakmak 
için kullanılır. Smart pointer'lar, `std::shared_ptr`, `std::unique_ptr`, ve `std::weak_ptr` gibi sınıf şablonları aracılığıyla sağlanır.

### **2. Smart Pointer Türleri**
C++'ta 3 ana smart pointer türü vardır:

#### **a) `std::unique_ptr`**
- Bir nesneye **tek sahiplik** sağlar.
- Başka bir `unique_ptr` nesnesine kopyalanamaz; yalnızca taşınabilir (move semantics).
- Kullanım amacı: Nesneye yalnızca bir sahip olduğu durumlarda.
- Serbest bırakma işlemi: `unique_ptr` nesnesi yok edildiğinde, belleği otomatik olarak serbest bırakır.

##### **Örnek:**

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

int main() {
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>(); // Bellek tahsisi
    // `ptr` yalnızca kendisi tarafından kullanılır.
    return 0; // `ptr` yok edildiğinde MyClass belleği serbest bırakılır.
}

##### **Özellikler:**
- `std::unique_ptr` kopyalanamaz:

  std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();
  std::unique_ptr<MyClass> ptr2 = ptr1; // HATA: Kopyalama yapılamaz

- Ancak taşınabilir:

  std::unique_ptr<MyClass> ptr2 = std::move(ptr1); // Doğru: ptr1 artık boş

#### **b) `std::shared_ptr`**
- Bir nesnenin **paylaşılan sahipliği** için kullanılır.
- Birden fazla `shared_ptr`, aynı nesneyi paylaşabilir.
- Referans sayacı kullanır; sahip olan `shared_ptr` sayısı sıfıra düştüğünde nesne serbest bırakılır.
- Kullanım amacı: Bir nesnenin birden fazla sahipliği olduğu durumlar.

##### **Örnek:**

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    {
        std::shared_ptr<MyClass> ptr2 = ptr1; // Paylaşım
        std::cout << "ptr2 scope ending\n";
    } // ptr2 yok edildi, referans sayacı azalır.
    std::cout << "End of main\n";
    return 0; // Son `shared_ptr` yok edildiğinde nesne serbest bırakılır.
}

##### **Özellikler:**
- Referans sayısı görüntülenebilir:

  std::cout << "Use count: " << ptr1.use_count() << "\n";

#### **c) `std::weak_ptr`**
- **Zayıf referans** sağlar; referans sayısını artırmaz.
- `shared_ptr` ile kullanılan nesneleri gözlemlemek için kullanılır.
- Çevrimsel referans sorunlarını önlemek için tasarlanmıştır.
- Kullanım amacı: `shared_ptr` tarafından yönetilen bir nesneye zayıf bir referans oluşturmak.

##### **Örnek:**

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

int main() {
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr = sharedPtr; // Zayıf referans

    if (auto ptr = weakPtr.lock()) { // Geçerli bir `shared_ptr` oluşturur
        std::cout << "Shared pointer is still valid\n";
    } else {
        std::cout << "Shared pointer is no longer valid\n";
    }

    sharedPtr.reset(); // Nesne serbest bırakılır
    if (auto ptr = weakPtr.lock()) {
        std::cout << "Shared pointer is still valid\n";
    } else {
        std::cout << "Shared pointer is no longer valid\n";
    }

    return 0;
}

### **3. Avantajlar**
- **Otomatik Bellek Yönetimi:** Dinamik nesneleri manuel olarak serbest bırakmanıza gerek kalmaz.
- **Kaynak Güvenliği:** Bellek sızıntılarını ve `dangling pointer` hatalarını önler.
- **Kod Okunabilirliği:** Bellek yönetimi kodunu sadeleştirir.
- **Çevrimsel Referansların Önlenmesi:** `std::weak_ptr` ile bu tür sorunlar çözülebilir.

### **4. Dezavantajlar**
- **Performans:** `shared_ptr`'ın referans sayacı yönetimi bir miktar ek maliyet getirir.
- **Karmaşıklık:** Çok sayıda smart pointer türü, doğru olanı seçmeyi zorlaştırabilir.
- **Aşırı Kullanım:** Tüm durumlar için smart pointer gerekmez; stack veya raw pointer'lar bazı durumlarda daha uygundur.

### **5. Smart Pointer ile Ham Pointer Karşılaştırması**
| Özellik                  | Smart Pointer                     | Ham Pointer (Raw Pointer) |
|--------------------------|------------------------------------|---------------------------|
| **Bellek Yönetimi**      | Otomatik                          | Manuel                   |
| **Kurucu ve Yıkıcı**     | Desteklenir                       | Yok                      |
| **Bellek Sızıntısı**     | Minimize edilir                   | Kolayca oluşabilir       |
| **Referans Sayısı**      | `shared_ptr` ve `weak_ptr` ile takip edilir | Yok            |
--------------------------------------------------------------------------------------------------------------------------------------------------
1)**Resource leak** (kaynak sızıntısı) ve **memory leak** (bellek sızıntısı), C++ gibi düşük seviyeli kaynak yönetimi gerektiren dillerde 
karşılaşılan yaygın sorunlardır. Her ikisi de bir programın kaynakları yanlış yönetmesi nedeniyle ortaya çıkar, ancak aralarındaki fark, 
hangi tür kaynağın sızıntıya neden olduğuyla ilgilidir.

## **1. Resource Leak (Kaynak Sızıntısı)**
**Kaynak sızıntısı**, bir programın belleğin dışında başka tür sistem kaynaklarını (örneğin dosya tanıtıcıları, ağ bağlantıları, 
iş parçacıkları veya cihazlar) serbest bırakmayı ihmal etmesi durumunda oluşur. Bu, kaynakların tükenmesine ve programın veya işletim 
sisteminin performansının düşmesine neden olabilir.

### **Özellikler**
- Sistem kaynaklarının gereksiz yere meşgul edilmesine yol açar.
- Bellek dışındaki kaynaklarla ilgilidir (örneğin, dosya tanıtıcıları, soketler, vb.).
- Çoğunlukla işletim sisteminin kaynak limitlerini zorlar ve programın çökmesine neden olabilir.

### **Örnek:**

#include <iostream>
#include <fstream> // Dosya işlemleri için gerekli
using namespace std;

void resourceLeakExample() {
    fstream file;
    file.open("example.txt", ios::out); // Dosya açılır
    if (file.is_open()) {
        file << "Resource leak example\n";
        // `file.close()` unutuldu! Kaynak sızıntısı oluşur.
    }
} // Dosya otomatik kapanmaz, kaynak sızıntısı olur

#### **Sorun:**
- Dosya kapatılmadığı için işletim sistemi, açık dosya tanıtıcısını tutmaya devam eder.
- Yeterince fazla sızıntı olursa, sistemin dosya tanıtıcı limiti aşılabilir.

#### **Çözüm:**
Kaynakları manuel olarak serbest bırakmak yerine, **RAII (Resource Acquisition Is Initialization)** ilkesine uygun bir yaklaşım benimseyin.

void fixedExample() {
    // RAII: std::fstream otomatik olarak kaynakları yönetir.
    std::fstream file("example.txt", std::ios::out);
    if (file.is_open()) {
        file << "Resource management with RAII\n";
    } // Destructor çağrılır ve dosya kapanır.
}

## **2. Memory Leak (Bellek Sızıntısı)**
**Bellek sızıntısı**, bir programın dinamik olarak tahsis ettiği belleği serbest bırakmayı ihmal etmesi durumunda oluşur. Bellek sızıntıları, 
sınırlı bellek kaynaklarının tükenmesine neden olabilir ve programın çökmesine veya yavaşlamasına yol açabilir.

### **Özellikler**
- Sadece dinamik bellek ile ilgilidir.
- Tahsis edilmiş bellek, referansı kaybolduğu için serbest bırakılamaz.
- Programın uzun süre çalışması durumunda performans düşüşüne neden olabilir.

### **Örnek:**

#include <iostream>
using namespace std;

void memoryLeakExample() {
    int* arr = new int[100]; // Dinamik bellek tahsisi
    // arr işaretçisi unutuluyor, delete çağrılmıyor!
} // `arr` artık ulaşılmaz, ancak bellek serbest bırakılmadı

#### **Sorun:**
- `arr` için tahsis edilen 100 adet `int` bellekte tutulur.
- Bellek hiçbir zaman serbest bırakılmaz, bu da belleğin tükenmesine neden olabilir.

#### **Çözüm:**
Belleği manuel olarak serbest bırakmak yerine, modern C++'ın **smart pointer**'larını kullanarak bellek yönetimini otomatik hale getirin.

#include <memory>

void fixedMemoryExample() {
    std::unique_ptr<int[]> arr(new int[100]); // Smart pointer kullanımı
    // `arr` otomatik olarak serbest bırakılır.
}

## **3. Resource Leak ve Memory Leak Arasındaki Fark**
| Özellik               | Resource Leak                                | Memory Leak                              |
|-----------------------|----------------------------------------------|------------------------------------------|
| **Kaynak Türü**       | Bellek dışındaki kaynaklar (dosyalar, soketler, vs.) | Dinamik olarak tahsis edilen bellek     |
| **Neden**             | Kaynağı serbest bırakmayı unutma             | Tahsis edilen belleği serbest bırakmayı unutma |
| **Sonuçları**         | Performans düşüşü, sistem kaynaklarının tükenmesi | Performans düşüşü, belleğin tükenmesi   |
| **Çözüm**             | RAII veya smart kaynak yönetimi             | Smart pointer veya `delete` ile manuel bellek yönetimi |

## **4. Resource Leak ve Memory Leak'i Önleme Yöntemleri**

### **a) RAII (Resource Acquisition Is Initialization)**
- Bir kaynağı sınıfın yaşam döngüsüne bağlar.
- Destructor, kaynakların otomatik olarak serbest bırakılmasını sağlar.
  
#### **Örnek:**

#include <iostream>
#include <fstream>
using namespace std;

class FileGuard {
    fstream file;
public:
    FileGuard(const string& filename) {
        file.open(filename, ios::out);
    }
    ~FileGuard() {
        if (file.is_open()) {
            file.close(); // Kaynak serbest bırakılır
        }
    }
};

void example() {
    FileGuard guard("example.txt");
    // Dosya otomatik olarak kapanır
}

### **b) Smart Pointer Kullanımı**
- **`std::unique_ptr`**, **`std::shared_ptr`**, ve **`std::weak_ptr`** gibi sınıflar, bellek yönetimini kolaylaştırır.
- `new` ve `delete` kullanmaktan kaçınılmasını sağlar.

#### **Örnek:**

#include <memory>

void smartPointerExample() {
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    // `ptr` artık otomatik olarak yönetiliyor, delete gerekmez
}

### **c) Analiz ve Araçlar**
- **Statik Analiz:** Koddaki potansiyel sızıntıları tespit etmek için kullanılabilir (örneğin, `clang-tidy`, `cppcheck`).
- **Dinamik Analiz:** Çalışma zamanı sızıntılarını tespit etmek için kullanılabilir (örneğin, `Valgrind`, `AddressSanitizer`).
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta `delete` operatörü, dinamik olarak tahsis edilmiş bellek alanlarını serbest bırakmak için kullanılır. **`delete`** operatörünün çalışma 
şekli, nesnenin türüne, belleğin nasıl tahsis edildiğine ve yıkıcı işlemlere bağlıdır.

### **1. Temel Çalışma Prensibi**
- **`delete`**, dinamik olarak tahsis edilmiş bir nesne için önce **yıkıcıyı (`destructor`) çağırır**, ardından belleği serbest bırakır.
- Ham bellek alanı (`malloc` ile tahsis edilmiş) üzerinde kullanılamaz; sadece `new` veya `new[]` ile tahsis edilen bellek için geçerlidir.

#### **Örnek:**

#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor called\n"; }
    ~MyClass() { cout << "Destructor called\n"; }
};

int main() {
    MyClass* ptr = new MyClass(); // Dinamik tahsis
    delete ptr; // Destructor çağrılır ve bellek serbest bırakılır
    return 0;
}

**Çıktı:**

Constructor called
Destructor called

### **2. Tekil Nesneler ve Diziler**
- **Tekil Nesne (`new`)**:
  - `delete` tek bir nesne üzerinde çalışır.
  - Belleği serbest bırakmadan önce nesnenin yıkıcı işlevini çağırır.

  MyClass* obj = new MyClass();
  delete obj; // Destructor çağrılır, ardından bellek serbest bırakılır

- **Diziler (`new[]`)**:
  - Bir dizi için `delete[]` kullanılır.
  - Dizideki her bir öğe için yıkıcı çağrılır, ardından bellek serbest bırakılır.

  MyClass* arr = new MyClass[3]; // 3 nesne oluşturulur
  delete[] arr; // Tüm nesnelerin destructor'ı çağrılır

  Eğer `delete` yerine `delete[]` kullanımı ihmal edilirse, sadece ilk nesnenin yıkıcısı çağrılır ve davranış tanımsızdır.

### **3. Çalışma Aşamaları**
1. **Yıkıcı Çağrılır:**
   - `delete`, nesne için varsa yıkıcıyı çağırır.
   - Bu adım, sınıfın belleği serbest bırakmadan önce nesne kaynaklarını temizlemesine olanak tanır.

2. **Bellek Serbest Bırakılır:**
   - Yıkıcı çağrıldıktan sonra, nesnenin belleği sistem belleğine iade edilir.

### **4. `delete` ile `free` Arasındaki Fark**
- **`delete`**:
  - Kurucu ve yıkıcı işlevleri çağırır.
  - Sadece `new` ile tahsis edilen bellek üzerinde çalışabilir.
  - Daha yüksek seviyeli ve nesne yönelimli bellek yönetimi sağlar.

- **`free`**:
  - Yıkıcıyı çağırmaz, sadece ham belleği serbest bırakır.
  - Sadece `malloc` ile tahsis edilen bellek üzerinde çalışabilir.

### **5. Tanımsız Davranış (Undefined Behavior)**
**`delete` veya `delete[]` yanlış kullanıldığında tanımsız davranış oluşabilir:**
- **Birden Fazla Serbest Bırakma:**
  Aynı bellek alanı için birden fazla kez `delete` çağrılırsa:

  int* ptr = new int(5);
  delete ptr;
  delete ptr; // Tanımsız davranış

- **Geçersiz Bellek:**
  Dinamik olarak tahsis edilmemiş bellekte `delete` kullanımı:

  int x = 10;
  delete &x; // Tanımsız davranış

- **Yanlış Operatör Kullanımı:**
  `delete` yerine `delete[]` veya tam tersi durumda:
  
  int* arr = new int[5];
  delete arr; // Tanımsız davranış (delete[] kullanılmalıydı)

### **6. `delete` ve Smart Pointer'lar**
C++'ta **smart pointer'lar** (`std::unique_ptr` ve `std::shared_ptr`), `delete` operatörünü manuel olarak çağırmayı gereksiz kılar. Bellek yönetimini otomatik olarak yaparlar.

#### **Örnek:**

#include <memory>
#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor called\n"; }
    ~MyClass() { cout << "Destructor called\n"; }
};

int main() {
    unique_ptr<MyClass> ptr = make_unique<MyClass>(); // Bellek otomatik yönetilir
    // `delete` gerekmez
    return 0;
}

### **7. Özel Bellek Yönetimi**
C++'ta `delete` operatörü, kullanıcı tarafından özelleştirilebilir (`operator delete` aşırı yükleme). Bu, nesnelerin bellek serbest bırakma sürecini değiştirmek için kullanılabilir.

#### **Örnek:**

#include <iostream>
#include <cstdlib>
using namespace std;

class MyClass {
public:
    void* operator new(size_t size) {
        cout << "Custom new called\n";
        return malloc(size);
    }

    void operator delete(void* ptr) {
        cout << "Custom delete called\n";
        free(ptr);
    }

    ~MyClass() {
        cout << "Destructor called\n";
    }
};

int main() {
    MyClass* obj = new MyClass();
    delete obj; // Custom delete çağrılır
    return 0;
}

**Çıktı:**

Custom new called
Destructor called
Custom delete called

### **8. Özet**
| Özellik                 | `delete`                      | `delete[]`                |
|-------------------------|-------------------------------|---------------------------|
| **Amaç**               | Tek nesneyi serbest bırakır   | Dizi nesnelerini serbest bırakır |
| **Yıkıcı Çağrımı**     | Bir yıkıcı çağrılır           | Tüm elemanların yıkıcısı çağrılır |
| **Hatalı Kullanım**    | Dizi üzerinde çağrılırsa UB   | Tekil nesnede çağrılırsa UB |
| **Bellek Yönetimi**    | Otomatik                     | Otomatik                   |

Bu bilgilerle, `delete` operatörünün doğru kullanımı bellek sızıntılarını ve tanımsız davranışları önlemeye yardımcı olur.
--------------------------------------------------------------------------------------------------------------------------------------------------
sınıfın non-static veri elemanları object ile ilgili her objenin o nesneye ait farklı bir değeri olabilir.
sınıfın static veri elemanları ise sınıfın tüm objeleri için aynı değeri paylaşır. ve direkt sınıfla alakalıdır
non-static veri elemanları sınıfın storage değerini belirler
static veri elemanları sınıfın storage değerini belirlemez

hpp
clas Myclass{
public:
	static int x;
};

cpp
int Myclass::x; // zero intialize

sınıfın kendi static veri türünden elemanı olabilir

clas Myclass{
public:
    static Myclass m;
};

class Nec;

clas Myclass{
public:
     Nec x; //incomplete type olduğu için hata ama static yaparsak hata vermez
};

static veri elemanları class scopeta aranır 

static veri elemanları sınıfın içinde tanımlanamaz

clas Myclass{
public:
    static int x = 5; hata
};

ama bunun bir istisnası var eğer sınıfın veri elemanı const ise ve integral type ise sınıf içinde tanımlanabilir

static const int x = 5;

sınıfların static veri elamanlarını sınıf içinde inline olarakta tanımlayabiliriz

inline static double x = 5.6;

const üye fonksiyon sınıfın static veri elemanını değiştirebilir

clas Myclass{
public:
    void foo() const
    {
        x = 5;
    }

    static int x;
};

sınıfların non static ve static üye fonksiyonlarının farkı non static fonksiyonlar bi obje için çağırılıyor ve gizli bir parametre
değişkeni var Myclass* gibi ama static üye fonksiyonlarda böyle bir paramtere yok yani gizli bir parametreleri yok

static üye fonksiyonlar const olamaz

static int foo() const // sentaks hatası

static üye fonksiyonlarının içinde this pointerı kullanılamaz

sınıfın static üye fonksiyonları içinde niteleme olmadan non static veri elemanını kullanamayız çünkü ortasda bir nesne yok

clas Myclass{
public:
    static int foo() 
    {
        x = 5; // burda sentaks hatasının sebebi namelookup hatası değil x ile doğrudan ilişkilendirilecek bir nesnenin olmayışı
        
    }

     int x; // static yaparsak Myclass::x olarak foo içinde kullanabilirdik ve sentaks hatası olmazdı
};

örneğin burda foo fonksiyonu Myclass sınıfından bir parametre aslsaydı sentaks hatası olmaaycaktı

static int foo(Myclass m)
{
    m.x = 5;
}

static üye fonksiyonu non-static üye fonksiyonu çağıramaz çünkü static üye fonksiyonlarını this pointerı yok

void foo()
{
}

static void bar()
{
    foo(); // sentaks hatası çağırmak için nesneye ihtiyacımız var ama tersi sentaks hatası değildir 
    non-static member fucnitonlarda static üye fonksiyonları çağırabiliriz
}

her ikiside static olsaydı sentaks hatası olmazdı
--------------------------------------------------------------------------------------------------------------------------------------------------
#define PUBLIC
  

PUBLIC int foo(int x)
{

    return x + 2;
} // derleyici define tanımını aslında görmez substitution olmadığı için 

bu senaryo cpp dosyalarında fonksiyonların public mi private mi static yada inline olduklarının bilgisin geçmek için kullanılır
yani isimlendirme gibi bir şey
******************************************************************************************************************************

                                                                             ********* 18-DERS NOTLARI *********

static veri elemanları default initialize edilse bile zero initialize edilirler

h
static int mx;

cpp
int Nec::mx; // zero initialize edilir

h
static int* p;

cpp
int* Nec::p; // zero initialize edildiği içinh nullpointer olur 

h
static bool b;

cpp
bool Nec::b; // zero initialize edildiği için false değerinde olur


static veri elemanları MIL sentaksı ile intialize edemeyiz

Nec: mx(10){} // sentaks hatası
static int mx;
--------------------------------------------------------------------------------------------------------------------------------------------------
static veri elemanlarıyla ilgili önemli bir nokta daha var global değişkenler açısından bir kere hoca değinmişti
sınıfların static veri elemanlarının farklı kaynak dosyalarında bulunması durumunda bunların sırayla initialize edileceği garanti altında değil 
garanti altına almak için başka örüntüleri kullanmak zorundayız

static veri elemanlarının diğer başka sınıfların static veri elemanlarını yada global değişkenleri kullanmaları durumunda onların hayata gelmiş olmasından
biz sorumluyuz buna static intialization fiyasko deniyordu
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Sınıfıların member functionları için re-decleration yoktur sentaks hatası
--------------------------------------------------------------------------------------------------------------------------------------------------
constructormış gibi davranan static member functionlardır

**Named Constructor Idiom**, C++'ta bir sınıfın örneklerini (nesnelerini) oluştururken, özel yapıcılar (constructors) yerine statik 
üyelik fonksiyonlarını kullanma yaklaşımıdır. Bu, özellikle bir sınıf için birden fazla yapıcı gerektiğinde veya yapılandırmayı daha 
açık ve okunabilir hale getirmek istediğinizde kullanışlıdır.

### **Amaç ve Avantajlar**
1. **Kullanım Kolaylığı ve Okunabilirlik:**
   - Kullanıcıya, nesnenin hangi özel parametrelerle oluşturulduğunu açıkça ifade eder.
2. **Doğru Kullanımı Zorlar:**
   - Yapıcılar özel (`private` veya `protected`) hale getirildiği için, sınıf nesneleri yalnızca adlandırılmış fonksiyonlar aracılığıyla oluşturulabilir.
3. **Güvenlik ve Yönetilebilirlik:**
   - Yanlış parametrelerle doğrudan yapılandırmayı önler.

#### ** Kullanıcı Oturumu: Giriş Seçenekleri**
Bir kullanıcı oturumu, farklı kimlik doğrulama yöntemleriyle oluşturulabilir:
- Kullanıcı adı ve şifreyle.
- E-posta ve şifreyle.
- Bir kimlik doğrulama token'ı ile.

#include <iostream>
#include <string>

class UserSession {
public:
    // Named constructors
    static UserSession fromUsernamePassword(const std::string& username, const std::string& password) {
        return UserSession(username, password);
    }

    static UserSession fromEmailPassword(const std::string& email, const std::string& password) {
        return UserSession(email, password, true);
    }

    static UserSession fromAuthToken(const std::string& token) {
        return UserSession(token, true);
    }

    void print() const {
        std::cout << "User: " << identifier_ << " (" << (isAuthenticated_ ? "Authenticated" : "Guest") << ")\n";
    }

private:
    std::string identifier_;
    bool isAuthenticated_;

    // Private constructors for different use cases
    UserSession(const std::string& id, const std::string& pass)
        : identifier_(id), isAuthenticated_(false) {
        std::cout << "Authenticating with username/password...\n";
    }

    UserSession(const std::string& id, const std::string& pass, bool auth)
        : identifier_(id), isAuthenticated_(auth) {
        std::cout << "Authenticating with email/password...\n";
    }

    UserSession(const std::string& token, bool auth)
        : identifier_(token), isAuthenticated_(auth) {
        std::cout << "Authenticating with token...\n";
    }
};

int main() {
    // Creating user sessions
    UserSession user1 = UserSession::fromUsernamePassword("john_doe", "password123");
    UserSession user2 = UserSession::fromEmailPassword("john@example.com", "emailpassword");
    UserSession user3 = UserSession::fromAuthToken("token123");

    user1.print();
    user2.print();
    user3.print();

    return 0;
}

#### ** RGB ve HEX ile Renk Oluşturma**
Bir renk sınıfı, RGB değerleri (kırmızı, yeşil, mavi) veya bir HEX koduyla tanımlanabilir.

#include <iostream>
#include <sstream>
#include <iomanip>

class Color {
public:
    static Color fromRGB(int red, int green, int blue) {
        return Color(red, green, blue);
    }

    static Color fromHex(const std::string& hexCode) {
        int red, green, blue;
        std::stringstream ss(hexCode);
        ss >> std::hex >> red >> green >> blue;
        return Color(red, green, blue);
    }

    void print() const {
        std::cout << "Color(R: " << red_ << ", G: " << green_ << ", B: " << blue_ << ")\n";
    }

private:
    int red_, green_, blue_;

    // Private constructor
    Color(int red, int green, int blue) : red_(red), green_(green), blue_(blue) {}
};

int main() {
    Color color1 = Color::fromRGB(255, 0, 0);         // Red
    Color color2 = Color::fromHex("00FF00");          // Green

    color1.print();
    color2.print();

    return 0;
}

### **Özet**
**Named Constructor Idiom**, yapıcıların özel olarak tanımlandığı ve kullanıcıların yalnızca anlamlı statik fonksiyonlarla nesne oluşturmasını sağlayan bir kalıptır.
- Bu, özellikle sınıflarınızın farklı yapılandırma yollarına sahip olduğu durumlarda kullanışlıdır.
- Hem kodun okunabilirliğini artırır hem de yanlış kullanım olasılığını azaltır.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Mülakat sorusu örnek 

fighter adlı bir sınıf var ve bu sınıfta nesneler biribiryle bağlantılı 

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Fighter
{
public:
    explicit Fighter(const std::string& name) : m_name(name)
    {
        msvec.push_back(this); //Savaşçıyı msvec listesine ekler.
    }

    ~Fighter()
    {
        std::erase(msvec, this); // savaşçı yok edildiğinde, msvec listesinden kaldırır.
    }

    void ask_for_help() const
    {
        std::cout << "Ben savasci " << m_name << "\n";
        std::cout << "dusman kabile saldiriyor" << "\n";

        for (const Fighter* p : msvec)
        {
            if (p != this) //msvec listesindeki diğer savaşçılara çağrı yapar (kendisi hariç).
            {
                std::cout << p->m_name << " yardim et\n";
            }
        }
    }

    Fighter(const Fighter&) = delete;
    Fighter& operator=(const Fighter&) = delete;

private:
    inline static std::vector<Fighter*> msvec; //Tüm savaşçıları ve savaşçıların adreslerini tutan bir statik vektör. Bu, sınıfın tüm objectleri tarafından paylaşılır.
    std::string m_name;
};

int main()
{

    Fighter f1{ "emre" };
    Fighter f2{ "asli" };

    auto fptr = new Fighter("murat");

    fptr->ask_for_help();

}
--------------------------------------------------------------------------------------------------------------------------------------------------
**GoF Patterns (Gang of Four Patterns)**, yazılım tasarımında kullanılan, sıklıkla tekrar eden sorunlara çözüm sunan tasarım desenlerini ifade eder. 
"Gang of Four" (Dörtlü Çete) ifadesi, bu desenleri ilk kez derleyen ve tanımlayan dört yazılım mühendisini 
(Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides) ifade eder. 1994'te yayımladıkları 
**"Design Patterns: Elements of Reusable Object-Oriented Software"** adlı kitap, yazılım mühendisliğinde bir dönüm noktasıdır.

### **GoF Tasarım Desenleri**
GoF desenleri, **Nesneye Yönelik Programlama (OOP)**'nin oriye ayrılır:
temel prensiplerini kullanarak yazılımın modüler, esnek ve yeniden 
kullanılabilir olmasını sağlar. Bu desenler üç ana kategegoride incelenir

### **1. Yaratıcı Desenler (Creational Patterns)**
- **Amaç:** Nesne oluşturma sürecini soyutlamak ve dinamikleştirmek.
- **Desenler:**
  - **Singleton:** Bir sınıftan yalnızca bir örneğin oluşturulmasını sağlar.
  - **Factory Method:** Nesne oluşturmayı alt sınıflara bırakarak soyutlama sağlar.
  - **Abstract Factory:** İlgili nesne gruplarını oluşturmak için bir arayüz sağlar.
  - **Builder:** Karmaşık nesnelerin adım adım oluşturulmasını sağlar.
  - **Prototype:** Bir nesneyi kopyalayarak yeni bir nesne oluşturur.

### **2. Yapısal Desenler (Structural Patterns)**
- **Amaç:** Nesneler arasındaki ilişkileri ve organizasyonu düzenlemek.
- **Desenler:**
  - **Adapter:** Uyumsuz arayüzlere sahip nesnelerin birlikte çalışmasını sağlar.
  - **Bridge:** Uygulama ve soyutlama arasındaki bağlantıyı ayırır.
  - **Composite:** Nesneleri ağaç yapısı içinde birleştirip birlikte çalıştırmayı sağlar.
  - **Decorator:** Nesnelere dinamik olarak ek davranışlar ekler.
  - **Facade:** Karmaşık alt sistemlere kolay bir arayüz sağlar.
  - **Flyweight:** Bellek tüketimini azaltmak için ortak nesne durumunu paylaşır.
  - **Proxy:** Bir nesneye erişim kontrolü sağlar.

### **3. Davranışsal Desenler (Behavioral Patterns)**
- **Amaç:** Nesneler arasındaki iletişim ve sorumluluk dağıtımını yönetmek.
- **Desenler:**
  - **Observer:** Bir nesne değiştiğinde bağlı diğer nesneleri bilgilendirir.
  - **Strategy:** Bir algoritmanın farklı versiyonlarını birbirinin yerine kullanılabilir hale getirir.
  - **Command:** İstekleri nesne olarak temsil ederek geri alınabilir veya yeniden oynatılabilir hale getirir.
  - **Iterator:** Nesnelerin bir koleksiyon üzerinde sıralı bir şekilde gezinmesini sağlar.
  - **State:** Bir nesnenin iç durumuna bağlı olarak davranışını değiştirmesini sağlar.
  - **Chain of Responsibility:** Bir isteğin bir dizi nesne tarafından işlenmesini sağlar.
  - **Template Method:** Bir algoritmanın ana yapısını tanımlar, alt sınıflar belirli adımları özelleştirir.
  - **Mediator:** Nesneler arasındaki karmaşık iletişimi tek bir arabulucuyla yönetir.
  - **Visitor:** Algoritmayı veri yapılarından ayırarak yeni işlemler eklenmesini kolaylaştırır.
  - **Memento:** Bir nesnenin önceki durumunu kaydeder ve gerektiğinde geri yükler.

--------------------------------------------------------------------------------------------------------------------------------------------------
scot mayers'ın bulduğu singleton örneği

class Meyers
{
    public:
    static Meyers& get_instance()
    {
        static Meyers instance; // Static yerel değişkenler için constructor o fonksiyonun çağırılması ile çağrılır
                                    sadece 1 kere hayata getirilir ve hep aynı nesne kullanılır
        return instance;
    }

    void foo();
    void bar();
    void baz();
private:
    Meyers();
};


int main()
{
    Meyers::get_instance().foo();
    Meyers::get_instance().bar();
    Meyers::get_instance().baz();

}
--------------------------------------------------------------------------------------------------------------------------------------------------
namespace olarak derleyicinin izin verdiği yazım biçimi

namespace nec::erg::proj
{
    double x = 5.4;
}


int main()
{

    auto x = nec::erg::proj::x;

}

derleyici bu sentaks ile 

namespace nec
{
    namespace erg
    {
        namespace proj
        {
            double x = 5.4;
        }
    }
}

bu sentaksı aynı kabul ediyor
--------------------------------------------------------------------------------------------------------------------------------------------------
namespace nec
{
    int x;
}

namespace nec
{
    int y;
}

namespacelerde bu sentaksta geçerlidir derleyici kümülatif şekilde ele alır 

namespace nec
{
    int x;
    int y;
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Bİr ismi mitelemeden namespace içerisinde aranmasını sağlayan birden fazla araç var

using decleration
using namespace directive
adl
inline namespace

using bildirimi ile tanıtılan isim bildirimin olduğu scopa enjekte edilir adeta o scopeta tanımlanmış gibi etki yapar

namepsace nec
{
    int x;
}

namepsace erg
{
    using nec::x;
}

int main()
{
    erg::x; 
}
******************************************************************************************************************************

             
                                                                ********* 19-DERS NOTLARI *********

using namespace direktifi class içinde kullanılamaz

namespace nec
{
    int x = 0;
}

class myclass
{
public:
    using namespace nec; // sentaks hatası
};
--------------------------------------------------------------------------------------------------------------------------------------------------
namespace nec
{
    int x = 34;
}


int main()
{

    using nec::x; // using namespace nec; olsaydı otomatik ömürlü değişken nec namespaceindeki x i gölgelerdi
                   ama burda nec::x bildirimi nec in x değişkenini sanki mainde tekrardan tanımlanmış gibi etki yapar 
                   
     int x = 50; o yüzden bu bildirim sentaks hatası olur

}
--------------------------------------------------------------------------------------------------------------------------------------------------
using bildirimi comma seperator list ile yapılabiliyor ama using namespace direktifi için bu geçerli değil
    using namespace nec,erg,st// sentaks hatası


   using nec::x,nec::y; // geçerli
--------------------------------------------------------------------------------------------------------------------------------------------------
using namespace erg direktifi ile erg isim alanı içerisindeki isimler global isim alanında görülür olur
böylece isim alanıdaki using namespace nec direktifi de sanki global isim alanınndaymış gibi etkiye sahip olur
bu etki de nec isim alanı içerisindekilerin global isim alanına enjekte edilmesine yol açar

namespace nec
{
    int x;
}

namespace erg
{
    using namespace nec;
}

using namespace erg;

int main()
{

    x = 50;
}
--------------------------------------------------------------------------------------------------------------------------------------------------
ADL(ARGUMAN DEPENDENT LOOKUP)'in diğer ismi Koenıg lookup
--------------------------------------------------------------------------------------------------------------------------------------------------
ADL ufak değiniş

bir fonksiyon çağrısında fonksiyon ismi nitelenmeden kullanıldığında eğer fonksiyona gönderilen argümanlardan biri
bir namesapce içinde bildirilen bir türe ilişkinse fonksiyon ismi o namespace içinde de aranır

namespace nec
{
    class Myclass{};

    void foo();
    void bar(int);
    void baz(Myclass);
}


int main()
{

    //foo(); // sentaks hatası
    //bar(34); // sentaks hatası
    nec::Myclass m;

    baz(m); // ADL
}

global bir baz fonksiyonu baz(nec::Myclass); olsadyı ambiguty hatası olurdu
--------------------------------------------------------------------------------------------------------------------------------------------------
necati hocanın terimiyle power of adl örneği

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<int> ivec{ 1,5,7,9 };

    sort(begin(ivec), end(ivec)); // ADL sayesinde unqualified şeklinde kullanılmasını sağlıyor ve
                                    sort,begin ve end fonksiyonları std namespace içinde aranıyor
                                    sort std ile nitelenmemesi begin ve end fonksiyonlarının geri dönüş değeri sayesinde
                                    std::vector<int>::Iterator
                                    begin ve end  std namespace içinde olduğu için sort da std içinde aranıyor
}
--------------------------------------------------------------------------------------------------------------------------------------------------
namespace nec
{
    class A{};
    void bar(A);
}

namespace erg
{
    using B = nec::A;
    void func(B);
}
int main()
{
    erg::B b;

    func(b); // invalid there is no func in nec // func fonksiyonu nec içinde olmadığı için sentaks hatası
    bar(b); // valid bar found in nec

}
--------------------------------------------------------------------------------------------------------------------------------------------------
unnamed namespace

namespace {
    int x;
}

int main()
{
    x = 10;
}
unnamed namespacelerin kullanılmasındaki amaç sadece 1 kaynak dosyaya ilişkin isimlerin diğer kaynak dosyalardan gizlenmesi
static değerlere bir alternatif olarak kullanılabilir yani bu namespace içindeki her bir varlık hiç bir kaynak dosya ile bağlantılı olmayacak

derleyicinin burda yaptığı bu namespace'i aslında isimlendiriyor sanki global olarak using namespace kullanılmış gibi 
--------------------------------------------------------------------------------------------------------------------------------------------------
nested namespace bildirimi böylede olabilir

namespace nec::erg::B
{
    int x = 5;
}

namespace nec
{
    namespace erg
    {
        
        namespace B
        {
            int x = 5;
        }

    }
}
ile aynıdır
--------------------------------------------------------------------------------------------------------------------------------------------------
Inline Namespace

C++'da **inline namespace** (satır içi isim alanı), özellikle büyük projelerde ve kütüphane geliştirmede sürüm yönetimini kolaylaştırmak 
için kullanılan güçlü bir özelliktir. Inline namespace'ler, isim alanları içerisindeki elemanların dışarıdan erişimini daha esnek ve yönetilebilir 
hale getirirken, geriye dönük uyumluluğu korumaya yardımcı olur.

### **Inline Namespace Nedir?**

Inline namespace, bir isim alanının (namespace) **inline** anahtar kelimesi ile tanımlandığı özel bir isim alanıdır. Bu yapı, inline 
namespace içerisindeki elemanların, dış isim alanı tarafından direkt olarak erişilebilir olmasını sağlar. Yani, inline namespace içindeki 
fonksiyonlar, sınıflar veya değişkenler, sanki dış namespace içinde tanımlanmış gibi kullanılabilir.

### **Inline Namespace'in Amaçları ve Kullanım Alanları**

1. **Sürüm Yönetimi:**
   - Kütüphanelerde yeni sürümler yayımlandığında, eski sürümlere geriye dönük uyumluluğu korumak önemlidir. Inline namespace'ler,
   farklı sürümleri aynı isim alanı içerisinde yönetmeye olanak tanır.
   
2. **Geriye Dönük Uyumluluk:**
   - Mevcut kullanıcıların kodlarını değiştirmeden yeni sürümlere geçiş yapmalarını sağlar. Bu, özellikle geniş çaplı projelerde büyük kolaylık sunar.

3. **API Geliştirme:**
   - Geliştiricilere, yeni özellikler eklerken veya mevcut özellikleri güncellerken, eski API'leri koruma imkanı verir.

### **Inline Namespace Nasıl Çalışır?**

Inline namespace kullanıldığında, inline olarak tanımlanan namespace içindeki elemanlar, dış namespace'in bir parçasıymış gibi davranır. 
Bu, kullanıcıların inline namespace belirtmeden bu elemanlara erişebilmesini sağlar.

### **Örnek Uygulama**

Aşağıda, inline namespace kullanımını gösteren basit bir örnek bulunmaktadır:

#include <iostream>

// Ana isim alanı
namespace Library {
    
    // Inline namespace ile sürüm yönetimi
    inline namespace Version2 {
        void display() {
            std::cout << "Library Version 2" << std::endl;
        }
    }
    
    namespace Version1 {
        void display() {
            std::cout << "Library Version 1" << std::endl;
        }
    }
}

int main() {
    // Inline namespace sayesinde Version2::display() direkt olarak Library::display() olarak çağrılır
    Library::display(); // Çıktı: Library Version 2
    
    // Eski sürüme erişmek için namespace belirtmek gerekir
    Library::Version1::display(); // Çıktı: Library Version 1
    
    return 0;
}

### **Açıklama:**

1. **Ana İsim Alanı (`Library`):**
   - `Library` isim alanı içerisinde iki farklı sürüm tanımlanmıştır: `Version1` ve `Version2`.

2. **Inline Namespace (`Version2`):**
   - `Version2` isim alanı `inline` olarak tanımlanmıştır. Bu sayede, `Version2` içindeki `display` fonksiyonu, `Library::display()` olarak doğrudan çağrılabilir.
   
3. **Geriye Dönük Uyumluluk:**
   - `Version1` isim alanı ise `inline` olarak tanımlanmamıştır. Bu nedenle, `Version1::display()` fonksiyonuna erişmek için doğrudan 
   `Library::Version1::display()` şeklinde tam isimlendirme yapmak gerekmektedir.

### **Avantajları:**

1. **Kolay Sürüm Geçişi:**
   - Yeni bir sürüm eklerken, mevcut kullanıcıların kodlarını değiştirmelerine gerek kalmadan yeni sürümü kullanmalarını sağlar.

2. **Temiz ve Yönetilebilir Kod:**
   - Farklı sürümler için ayrı isim alanları kullanmak, kodun düzenli ve okunabilir olmasını sağlar.

3. **Geriye Dönük Uyumluluk:**
   - Eski sürümlere erişim sağlanırken, yeni sürümün varsayılan olarak kullanılmasını mümkün kılar.

### **Dikkat Edilmesi Gerekenler:**

1. **Çakışmalar:**
   - Inline namespace'ler, aynı isim alanı içinde çakışmalara neden olabilir. Bu nedenle, sürüm numaralarını veya adlarını dikkatli seçmek önemlidir.

2. **Karmaşıklık:**
   - Çok fazla inline namespace kullanımı, isim alanlarının karmaşık hale gelmesine yol açabilir. Bu yüzden, sürüm yönetimini basit ve anlaşılır tutmak gerekir.

3. **Performans:**
   - Genellikle performans üzerinde olumsuz bir etkisi olmasa da, isim çözümlemesi karmaşıklaştıkça derleyici optimizasyonları zorlaşabilir.

### **Inline Namespace ile İlgili Ek Bilgiler**

- **Sadece C++11 ve Sonrası:**
  - Inline namespace özelliği, C++11 standardı ile tanıtılmıştır.

- **Sadece Namespace İçinde Kullanılır:**
  - Inline namespace'ler sadece diğer namespace'ler içinde tanımlanabilir, global isim alanında doğrudan kullanılamazlar.

### **Sonuç**

C++'da inline namespace'ler, özellikle büyük ve sürüm gerektiren projelerde isim alanı yönetimini kolaylaştıran, okunabilirliği 
artıran ve geriye dönük uyumluluğu koruyan önemli bir özelliktir. Sürüm yönetimi ihtiyaçlarınıza uygun olarak doğru şekilde
kullanıldığında, kodunuzun bakımını ve genişletilmesini oldukça kolaylaştırır.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)namespace alias (eş isim) 

isimlerin gizlenmesi için bir namespace içine koyuyoruz ama namespace isminin kendisi de bir çakışmaya tabii olabilir

namesapce nec_erg{}

class nec_erg {}; // nec_erg adında bir namespace olduğu için sentaks hatası

int main()
{
    namespace nec = nec_erg; // 
}
--------------------------------------------------------------------------------------------------------------------------------------------------
namespace nec
{
    int x = 5;
}

namespace erg = nec; // erg demek nec demek

int main()
{
    nex::x = 13; // hepsi aynı
    erg::x = 35; // hepsi aynı
}
--------------------------------------------------------------------------------------------------------------------------------------------------
nested types olarak kullanılabilenler

class
enum
union
typedef
using

******************************************************************************************************************************

                                                                             ********* 20-DERS NOTLARI *********

**Enclosing Class** (Kapsayıcı Sınıf), bir sınıfın başka bir sınıfın içinde tanımlandığı durumlarda, dış sınıfı ifade etmek için kullanılan bir terimdir. Bu durumda:

- **Outer Class (Dış Sınıf):** Kapsayıcı (enclosing) sınıf.
- **Inner Class (İç Sınıf):** Kapsayıcı sınıfın içinde tanımlanan sınıf.

C++’ta **enclosing class**, iç sınıfın kapsandığı dış sınıfı ifade eder. Bu durum, genellikle iç içe sınıf tanımlamaları (**nested classes**) ile ilişkilidir.

### **Nested Class Örneği**

#include <iostream>

class Outer {
public:

    class Inner { // Nested (Inner) Class
    public:
        void display() {
            std::cout << "Inside Inner class\n";
        }
    };

    void show() {
        std::cout << "Inside Outer class\n";
    }
};

int main() {
    Outer outerObj;
    outerObj.show(); // Outer class'ın fonksiyonunu çağırır.

    Outer::Inner innerObj;
    innerObj.display(); // Inner class'ın fonksiyonunu çağırır.

    return 0;
}

### **Kod Analizi**
1. `Outer` sınıfı bir kapsayıcı sınıf (**enclosing class**) olarak tanımlanmıştır.
2. `Inner` sınıfı, `Outer` sınıfının içinde tanımlanmış bir iç sınıftır (**nested class**).
3. `Outer::Inner` kullanımı, `Inner` sınıfının `Outer` içinde tanımlandığını belirtir.

### **Enclosing Class ve Nested Class Arasındaki İlişki**

- **Erişim Kuralları:**
  - inner class, enclosing sınıfın private üyelerine bile erişebilir.
  - Ancak enclosing class, inner classın özel üyelerine doğrudan erişemez (iç sınıfın erişim denetimlerine uyması gerekir).
    enclosing classın inner classın private elemanlarına erişmesi için friend bildirimide yapılabilir

**Örnek:**

class Outer {
private:
    int privateData = 42;

public:
    class Inner {
    public:
        void accessOuterPrivate(Outer& outer) {
            std::cout << "Accessing Outer private data: " << outer.privateData << "\n";
        }
    };
};

int main() {
    Outer outer;
    Outer::Inner inner;

    inner.accessOuterPrivate(outer); // Inner class, Outer'ın private verisine erişebilir.

    return 0;
}

### **Enclosing Class Kullanımı**

1. **Kapsülleme:** İç sınıf, yalnızca kapsayıcı sınıfa özgü detayları içerebilir, bu da kodu daha modüler hale getirir.
2. **Bağımsızlık:** İç sınıf, dış sınıfın bir parçasıdır ama diğer sınıflarla bağımsız olarak kullanılabilir.
3. **Bağlantıyı Belirtme:** Bir nested sınıfın kapsayıcı sınıfı ile bağlantısını açıkça göstermek için kullanılır.

### **Not: Static Nested Class**

Eğer iç sınıf bir **`static`** sınıf olarak tanımlanırsa, enclosing classın bir örneğine (instance) ihtiyaç duymadan erişilebilir:

class Outer {
public:
    static class Inner {
    public:
        void staticInnerMethod() {
            std::cout << "Static Inner Class Method\n";
        }
    };
};

int main() {
    Outer::Inner innerObj;
    innerObj.staticInnerMethod();

    return 0;
}

### **Sonuç**

**Enclosing Class**, iç sınıfın ait olduğu dış sınıftır. Bu yapı, özellikle kapsülleme, düzen ve iç içe ilişkili sınıfların yönetiminde oldukça faydalıdır. 
Nested class'lar sayesinde kapsayıcı sınıfın yapısına uygun detaylar organize edilebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:inner class enclosing class'ın private bölümüne erişebilir ama enclosing class inner classın private bölümüne erişemez

class Nec
{
    class Nested
    {
    private:
        void foo();
        int mx;

        friend Nec;
    };

    void bar()
    {
        Nested n; // Inner class içinde friend Nec bildirimi sayesinde enclosing class'tan inner classtaki private elemanlara erişim sağlıyoruz
        n.foo();
        n.mx = 5;
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------
class Nec
{
private:
    int sval;

    class Nested
    {
    private:

        void foo()
        {
            auto val = sval; // sentaks hatasının sebebi erişim kontrolü değil object olmadığı için
                                sval static olsaydı bu atama legal olacaktı
        }

    };
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Pimpl Idiom (Pointer to Implementation Idiom)**

**Pimpl idiom** (Pointer to Implementation idiom), C++'ta kullanılan bir tasarım desenidir. Bu desen, bir sınıfın uygulama 
detaylarını gizleyerek, birden çok avantaj sağlar:

1. **Bilgi Gizleme (Encapsulation):**
   - Uygulama detayları başlık dosyasından (`.hpp`) ayrılır ve yalnızca kaynak dosyasında (`.cpp`) bulunur.
   - Kullanıcılar, sınıfın yalnızca arabirimini görür.

2. **Derleme Bağımlılıklarını Azaltma:**
   - Başlık dosyası değiştiğinde, bu başlığı içeren diğer dosyaların yeniden derlenmesi gerekmez.

3. **İkili Uyumluluk (Binary Compatibility):**
   - Sınıfın arabirimi değiştirilmeden, uygulama detayları değiştirilebilir.

### **Nasıl Çalışır?**

Pimpl idiom, bir sınıfın uygulamasını bir özel veri üyesinde saklar. Bu veri üyesi, sınıfın gerçek uygulamasını işaret eden bir işaretçidir. İşte temel adımlar:

1. **Header Dosyasında Uygulama Detaylarını Gizleme:**
   - Uygulama ayrıntıları, bir özel işaretçi ile temsil edilir.
2. **Kaynak Dosyasında Gerçek Uygulamayı Tanımlama:**
   - İşaretçi, gerçek uygulama sınıfına işaret eder.

### **Kod Örneği**

**Header Dosyası (`MyClass.hpp`):**
* 
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <memory>

class MyClassImpl; // Uygulama sınıfı öne bildirimi (forward declaration)

class MyClass {
private:
    std::unique_ptr<MyClassImpl> impl; // Uygulama için işaretçi

public:
    MyClass();  // Constructor
    ~MyClass(); // Destructor

    void doSomething(); // Arabirim fonksiyonu
};

#endif // MYCLASS_HPP
```
**Kaynak Dosyası (`MyClass.cpp`):**

#include "MyClass.hpp"
#include <iostream>

// Gerçek uygulama sınıfı
class MyClassImpl {
public:
    void doSomething() {
        std::cout << "Doing something in MyClassImpl!" << std::endl;
    }
};

MyClass::MyClass()
    : impl(std::make_unique<MyClassImpl>()) // Uygulama nesnesi oluşturuluyor
{
}

MyClass::~MyClass() = default; // unique_ptr otomatik olarak bellek yönetimi yapar

void MyClass::doSomething() {
    impl->doSomething(); // Uygulama fonksiyonunu çağırma
}

**Kullanım (`main.cpp`):**

#include "MyClass.hpp"

int main() {
    MyClass obj;
    obj.doSomething(); // MyClassImpl'deki iş mantığı çalıştırılır
    return 0;
}

### **Avantajlar**
1. **Başlık Dosyası Gizliliği:**
   - `MyClassImpl` sınıfı `MyClass.hpp` dosyasında tanımlanmaz, yalnızca kaynak dosyasına dahildir.
2. **Derleme Bağımlılığı Azaltılır:**
   - Kullanıcılar yalnızca `MyClass.hpp` dosyasını dahil eder ve bu dosyadaki herhangi bir değişiklik, yalnızca kaynak dosyasını etkiler.
3. **Uygulama Ayrıntılarını Değiştirme Özgürlüğü:**
   - `MyClassImpl` sınıfında yapılan değişiklikler, arabirimi değiştirmeden uygulanabilir.

### **Dezavantajlar**
1. **Performans Maliyeti:**
   - Uygulama sınıfına her erişim, dolaylı çağrılar (`->`) içerir.
2. **Artan Karmaşıklık:**
   - Tasarım daha karmaşık hale gelir, çünkü iki ayrı sınıf (public ve private) yönetilir.

### **Nerede Kullanılır?**
- Büyük ölçekli projelerde, uygulama ayrıntılarının gizlenmesi gerektiğinde.
- Sık sık değişen uygulama mantığına sahip sınıflarda.
- İkili uyumluluk ve derleme süresini optimize etmek istenildiğinde.
--------------------------------------------------------------------------------------------------------------------------------------------------
her compostion bir aggregation her aggregation bi association ama her aggregation bir composition olmak zorunda değildir

Mesela her BMW bir arabadır ama her araba BMW değildir
--------------------------------------------------------------------------------------------------------------------------------------------------
Engine sınıfının constructorı olduğu için default constructor derleyici tarafından delete ediliyor

class Engine
{
public:
    Engine(int)
    { }
};

class Car
{
public:

private:
    Engine eng;
};

int main()
{
    Car c; // sentaks hatası constructor derleyici tarafından delete edilmiş

}

DİKKAT:Ama default member initialization kullanılılırsa derleyici implictly declared default olsa dahi bu durum geçerli olmuyor

class Engine
{
public:
    Engine(int)
    { }
};

class Car
{
public:

private:
    Engine eng{4}; // default member initialization
};

int main()
{
    Car c;

}

her hangi bir sentaks hatası yok normalde Engine classında conversion constrtuctor olduğu için default contructor delete edilmiş durumda
ama default member initialization kullanıldığı için bu legal

DİKKAT:Constructor user declared olduğu zamanda işler değişiyor

class Engine
{
public:
    Engine(int)
    { }
};

class Car
{
public:
    //Car() // eğer burda MIL Sentaksını kullanmazsak sentaks hatası olur
    {}
    
    Car() : eng(3) // geçerli sentaks hatası yok
    {}
private:
    Engine eng;
};

int main()
{
    Car c;

}
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **Association**, **Aggregation** ve **Composition**, sınıflar arasındaki ilişki türlerini tanımlar ve nesne yönelimli programlamada 
(OOP) sıkça kullanılır. Bu terimler, sınıfların birbirleriyle nasıl etkileşime geçtiğini ve bağımlılık düzeylerini ifade eder. İşte bu kavramların detayları:

### **1. Association (İlişkilendirme)**

- **Tanım**:
  - İki sınıf arasındaki basit bir ilişkiyi ifade eder.
  - Bir sınıfın diğerine sahip olmadığı, ancak birbiriyle iletişim kurduğu durumdur.
  - İlişki "zayıf bağlanmış"tır.

- **Örnek Durum**:
  - Öğretmen ve öğrenci arasında bir ilişki vardır, ancak bir öğretmen bir öğrenciye ait değildir ve tam tersi.

- **Kod Örneği**:

#include <iostream>

class Student {
public:
    void learn() {
        std::cout << "Student is learning.\n";
    }
};

class Teacher {
public:
    void teach(Student& student) {
        std::cout << "Teacher is teaching.\n";
        student.learn();
    }
};

int main() {
    Student student;
    Teacher teacher;

    teacher.teach(student); // İlişki, ownership (sahiplik) içermez.
    return 0;
}

### **2. Aggregation (Toplama)**

- **Tanım**:
  - Bir sınıf, başka bir sınıfın nesnesine referans veya işaretçi (pointer) aracılığıyla sahiptir.
  - Sahiplik **zayıftır** ve yaşam döngüsü bağlamı **bağımsızdır**.
  - İçerilen nesne (örneğin bir koleksiyonun parçası olan nesne), başka bir yerde de var olabilir.

- **Örnek Durum**:
  - Bir sınıf bir okula bağlı olabilir, ancak okul o sınıfın yaşam döngüsünü kontrol etmez.

- **Kod Örneği**:

#include <iostream>
#include <vector>
#include <memory>

class Student {
public:
    std::string name;
    Student(const std::string& name) : name(name) {}
};

class School {
private:
    std::vector<Student*> students; // Aggregation: School, Student'lara sahip değil, yalnızca referans tutar.
public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void listStudents() {
        for (const auto& student : students) {
            std::cout << "Student: " << student->name << "\n";
        }
    }
};

int main() {
    Student student1("Alice");
    Student student2("Bob");

    School school;
    school.addStudent(&student1);
    school.addStudent(&student2);

    school.listStudents(); // Öğrencilerin referansları tutulur, sahiplik yoktur.

    return 0;
}

### **3. Composition (Bileşim)**

- **Tanım**:
  - Bir sınıf, başka bir sınıfın nesnesine doğrudan sahiptir.
  - Sahiplik **güçlüdür** ve yaşam döngüsü bağlamı **bağımlıdır**.
  - İçerilen nesne, kapsayıcı sınıfın bir parçasıdır ve kapsayıcı sınıf yok edildiğinde o da yok edilir.

- **Örnek Durum**:
  - Bir araba (Car), motor (Engine) içerir. Motor, arabanın ayrılmaz bir parçasıdır.

- **Kod Örneği**:

#include <iostream>

class Engine {
public:
    void start() {
        std::cout << "Engine started.\n";
    }
};

class Car {
private:
    Engine engine; // Composition: Engine, Car'ın ayrılmaz bir parçası.
public:
    void start() {
        engine.start();
        std::cout << "Car is ready to go.\n";
    }
};

int main() {
    Car car;
    car.start(); // Car, Engine'i içerir ve kontrol eder.
    return 0;
}

### **Farkların Özeti**
| Özellik         | Association             | Aggregation             | Composition            |
|------------------|-------------------------|-------------------------|------------------------|
| **Sahiplik**    | Yok                     | Zayıf                   | Güçlü                 |
| **Yaşam Döngüsü**| Bağımsız                | Bağımsız                | Bağımlı               |
| **Kullanım**    | Referans veya İşaretçi   | Referans veya İşaretçi   | Nesne olarak          |
| **Örnek**       | Öğretmen-Öğrenci        | Okul-Öğrenciler         | Araba-Motor           |

---------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **containment** (kapsama), bir sınıfın başka bir sınıfın örneğini bir **üye değişkeni** olarak barındırması anlamına gelir. 
Bu, iki sınıf arasında bir **has-a (sahiptir)** ilişkisini temsil eder. **Containment**, bir sınıfın bileşenlerinin veya parçalarının 
başka sınıflar tarafından temsil edildiği bir yapıyı ifade eder.

### **Containment'in Anlamı**

Containment, bir sınıfın başka bir sınıfın işlevselliğini kullanmasını sağlar, ancak kalıtım yerine 
**bileşim (composition)** veya **agregasyon (aggregation)** yoluyla yapılır.

- **Composition (Bileşim):** İçerilen nesne, dış sınıfın ömrüne bağlıdır (örneğin, bir sınıfın üyesi olarak oluşturulmuş bir nesne).
- **Aggregation (Agregasyon):** İçerilen nesne, dış sınıfın ömründen bağımsızdır (örneğin, bir işaretçi veya referans ile temsil edilir).

### **Containment Örneği**

Bir "Car" sınıfının bir "Engine" sınıfını içermesi gibi bir senaryoyu ele alalım.

#### **Composition Örneği:**

#include <iostream>

class Engine {
public:
    void start() {
        std::cout << "Engine started!" << std::endl;
    }
};

class Car {
private:
    Engine engine; // Containment: Car has-an Engine // araba bir motora sahiptir

public:
    void start() {
        engine.start(); // Car, engine'in işlevlerini kullanıyor
        std::cout << "Car started!" << std::endl;
    }
};

int main() {
    Car car;
    car.start();
    return 0;
}
Bu örnekte:
- `Car` sınıfı bir `Engine` nesnesi içerir.
- `Engine` nesnesi `Car` sınıfının bir parçasıdır ve `Car`'ın ömrü boyunca var olur.

#### **Aggregation Örneği:**

#include <iostream>

class Engine {
public:
    void start() {
        std::cout << "Engine started!" << std::endl;
    }
};

class Car {
private:
    Engine* engine; // Containment: Car has-a reference to an Engine

public:
    Car(Engine* engine) : engine(engine) {}
    void start() {
        if (engine) {
            engine->start();
            std::cout << "Car started!" << std::endl;
        }
    }
};

int main() {
    Engine engine;  // Engine ayrı olarak oluşturulur
    Car car(&engine); // Engine, Car'a iletilir
    car.start();
    return 0;
}

Bu örnekte:
- `Car`, bir `Engine` nesnesine işaret eder.
- `Engine` nesnesinin ömrü `Car` sınıfından bağımsızdır.

### **Containment'in Avantajları**
1. **Tekrar Kullanılabilirlik:**
   - İçerilen sınıf (`Engine`) diğer sınıflar tarafından da kullanılabilir.
2. **Daha Esnek Yapı:**
   - Bileşim ve agregasyon, kalıtıma göre daha az sıkı bir bağ sağlar.
3. **Karmaşıklığın Azaltılması:**
   - Daha küçük ve odaklanmış sınıflarla daha yönetilebilir bir yapı sağlar.

### **Containment Ne Zaman Kullanılır?**
- **"Has-a"** ilişkisi olduğu durumlarda (örneğin, bir Araba bir Motor'a sahiptir).
- Kalıtımın gereksiz derecede bağımlılık yarattığı durumlarda.
- Bir sınıfın yalnızca diğer bir sınıfın işlevlerini kullanması gerektiğinde.
---------------------------------------------------------------------------------------------------------------------------------------------------
Constant Time (Sabit Zaman) Nedir?

**Constant Time (Sabit Zaman)**, algoritmaların çalışma süresini analiz ederken kullanılan temel kavramlardan biridir. 
Bir algoritmanın veya işlemin **sabit zamanlı** olması, girdinin boyutundan bağımsız olarak çalışma süresinin sabit kalması 
anlamına gelir. Yani, girdinin büyüklüğü ne olursa olsun, işlem her zaman aynı sürede tamamlanır.

### **Matematiksel Tanım ve Notasyon**

- **Big O Notasyonu:** Sabit zamanlı işlemler genellikle **O(1)** olarak ifade edilir.
  
  \[
  O(1)
  \]

  Bu notasyon, girdinin boyutu arttıkça algoritmanın çalışma süresinin nasıl değiştiğini gösterir. O(1) ifadesi, çalışma süresinin girdinin boyutundan bağımsız olduğunu belirtir.

### **Sabit Zamanlı İşlemlere Örnekler**

C++ programlama dilinde ve genel olarak bilgisayar bilimlerinde, sabit zamanlı işlemlere birkaç örnek şunlardır:

1. **Diziye Erişim:**
   int arr[100];
   int value = arr[50]; // O(1) işlemi

   Dizide herhangi bir indeksteki elemana erişmek sabit zamanlı bir işlemdir çünkü diziler ardışık bellek adreslerinde depolandığı için doğrudan adresleme yapılabilir.

2. **Değişken Ataması:**
   int a = 5; // O(1) işlemi
   Bir değişkene değer atamak sabit zamanlıdır.

3. **Basit Aritmetik İşlemleri:**
   int sum = a + b; // O(1) işlemi

   İki sayıyı toplamak sabit zamanlı bir işlemdir.

4. **İşaretçi Değiştirme:**
   int* ptr = &a; // O(1) işlemi

   Bir işaretçiyi başka bir değişkene işaret edecek şekilde değiştirmek sabittir.

5. **Map veya Unordered_map'te Anahtar Sorgulama:**
   std::unordered_map<int, std::string> myMap;
   myMap[1] = "One";
   std::string value = myMap[1]; // Ortalama O(1) işlemi

   `std::unordered_map` kullanırken, anahtara göre değere erişim ortalama olarak sabit zamanlıdır. Ancak, en kötü durumda O(n) olabilir, ancak bu durum nadiren gerçekleşir.

### **Sabit Zamanlı İşlemlerin Önemi**

1. **Verimlilik:** Sabit zamanlı işlemler, algoritmaların en hızlı işlemleridir çünkü girdinin boyutundan bağımsız olarak çalışırlar. 
Bu, büyük veri setleriyle çalışırken özellikle önemlidir.

2. **Algoritma Tasarımı:** Verimliliği artırmak için algoritma tasarımcıları, mümkün olduğunca sabit zamanlı işlemler kullanmaya çalışırlar.
Örneğin, bir algoritmanın belirli adımlarını O(1) yapmak, genel çalışma süresini azaltabilir.

3. **Veri Yapıları:** Sabit zamanlı işlemler sunan veri yapıları (örneğin, diziler, hash tabloları) belirli uygulamalar için idealdir. Bu veri yapıları, hızlı erişim ve güncelleme sağlar.

### **Sabit Zamanlı İşlemlerin Karşılaştırılması**

Algoritma analizinde sıkça karşılaşılan diğer zaman karmaşıklıkları ile sabit zamanlı işlemler arasındaki farklar:

| **Zaman Karmaşıklığı** | **Tanım**                                                   | **Örnek İşlemler**                            |
|------------------------|-------------------------------------------------------------|-----------------------------------------------|
| **O(1)**               | Girdinin boyutundan bağımsız sabit zaman.                  | Diziye erişim, değişken ataması, işaretçi değişimi |
| **O(log n)**           | Girdinin boyutunun logaritması ile artan zaman.            | İkili arama, bazı ağaç veri yapıları           |
| **O(n)**               | Girdinin boyutu ile orantılı artan zaman.                  | Lineer arama, dizide tüm elemanları dolaşma     |
| **O(n log n)**         | Girdinin boyutu ile logaritmasının çarpımı kadar artan zaman. | Hızlı sıralama (quicksort), birleşim sıralaması (mergesort) |
| **O(n²)**              | Girdinin boyutunun karesi ile artan zaman.                 | Kabarcık sıralama (bubble sort), seçmeli sıralama (selection sort) |
| **O(2^n)**             | Girdinin boyutunun üssel olarak artan zaman.               | Bazı rekürsif algoritmalar                     |
| **O(n!)**              | Girdinin boyutunun faktöriyel olarak artan zaman.          | Tam permütasyon üretimi                        |

### **Sabit Zamanlı İşlemlerin Kısıtlamaları**

- **Donanım Bağımlılığı:** Sabit zamanlı işlemlerin gerçek dünyadaki süreleri, işlemcinin hızı, bellek erişim süresi gibi donanım özelliklerine 
bağlı olarak değişebilir. Ancak, zaman karmaşıklığı analizinde bu faktörler göz ardı edilir.

- **O(1) Olmayan Durumlar:** Bazı işlemler teoride O(1) iken, pratikte sabit bir süre içinde tamamlanmayabilir. Örneğin, `std::vector`'ün sonuna 
eleman eklemek genellikle O(1) amortize zamanlıdır, ancak bellek yeniden tahsis edilmesi gerektiğinde O(n) sürebilir.

### **C++'ta Sabit Zamanlı İşlemlere Dair Örnekler**

#### **1. `std::vector` ile Sabit Zamanlı Erişim**

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    // Sabit zamanlı erişim
    std::cout << "İkinci eleman: " << vec[1] << std::endl; // O(1)
    
    return 0;
}

#### **2. `std::unordered_map` ile Sabit Zamanlı Ekleme ve Erişim**

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> myMap;
    
    // Sabit zamanlı ekleme
    myMap[1] = "Bir";   // O(1)
    myMap[2] = "İki";   // O(1)
    
    // Sabit zamanlı erişim
    std::cout << "Anahtar 1 için değer: " << myMap[1] << std::endl; // O(1)
    
    return 0;
}

#### **3. Basit Değişken Ataması**

#include <iostream>

int main() {
    int a = 5; // O(1)
    int b = a; // O(1)
    
    std::cout << "a: " << a << ", b: " << b << std::endl;
    
    return 0;
}

### **Sabit Zamanlı İşlemlerin Avantajları ve Dezavantajları**

**Avantajları:**

1. **Hız:** Sabit zamanlı işlemler, girdinin boyutundan bağımsız olarak hızlıdır, bu da büyük veri setleriyle çalışırken performansı artırır.

2. **Basitlik:** Algoritma tasarımında, sabit zamanlı işlemler kullanmak genellikle daha basit ve anlaşılır kodlar yazmanıza yardımcı olur.

3. **Verimlilik:** Sabit zamanlı işlemler, genel olarak daha düşük işlemci ve bellek kullanımı sağlar, bu da enerji verimliliğini artırır.

**Dezavantajları:**

1. **Sınırlamalar:** Her işlem sabit zamanlı olmayabilir. Bazı işlemler, özellikle büyük veri yapılarıyla çalışırken, sabit zamanlı olmayabilir.

2. **Kapsam:** Sabit zamanlı işlemler genellikle belirli veri yapıları ve algoritmalarla sınırlıdır. Örneğin, `std::vector`'ün ortalama O(1) 
erişim süresi vardır, ancak bazı durumlarda performans değişebilir.

### **Sonuç**

**Constant Time (Sabit Zaman)**, algoritma ve veri yapıları analizinde kritik bir kavramdır. O(1) zaman karmaşıklığı, girdinin boyutundan bağımsız olarak 
sabit bir süre içinde tamamlanan işlemleri ifade eder. Sabit zamanlı işlemler, performans açısından oldukça değerlidir ve verimli algoritma tasarımlarında 
sıklıkla kullanılır. Ancak, her işlemin sabit zamanlı olmadığını ve gerçek dünyada donanım bağımlılıkları gibi faktörlerin bu sürelere etki edebileceğini unutmamak önemlidir.

Algoritma tasarımında ve optimizasyonunda, işlemlerin zaman karmaşıklıklarını anlamak ve en uygun veri yapısını seçmek, yazılımın performansını önemli ölçüde artırabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
4)**Small String Optimization (SSO) Nedir?**

**Small String Optimization (SSO)**, C++ programlama dilinde `std::string` sınıfının performansını artırmak amacıyla kullanılan bir optimizasyon tekniğidir.
SSO, kısa metin dizilerini (small strings) dinamik bellek tahsisi (heap allocation) yapmadan, `std::string` nesnesinin kendisinin içinde saklamayı hedefler. 
Bu sayede, küçük stringler için bellek yönetimi daha hızlı ve verimli hale gelir.

### **SSO'nun Amacı ve Önemi**

1. **Performans İyileştirmesi:**
   - **Dinamik Bellek Tahsisi Maliyeti:** Küçük stringler için her seferinde heap üzerinde bellek tahsis etmek ve serbest bırakmak ek maliyet getirir. SSO, bu işlemleri ortadan kaldırarak performansı artırır.
   - **Cache Lokalitesi:** String verisinin `std::string` nesnesi içinde saklanması, verinin CPU önbelleğine daha yakın olmasını sağlar, bu da erişim süresini azaltır.

2. **Bellek Verimliliği:**
   - **Daha Az Bellek Tüketimi:** Küçük stringler için gereksiz heap tahsisi ve yönetimi olmadan bellek kullanımı optimize edilir.

3. **Basitleştirilmiş Yönetim:**
   - **Hızlı Kopyalama ve Atama:** Küçük stringler, doğrudan nesne içinde saklandığından kopyalama ve atama işlemleri daha hızlı gerçekleşir.

### **SSO Nasıl Çalışır?**

SSO, `std::string` sınıfının iç yapısında küçük stringleri doğrudan nesnenin içinde saklamak için ek alan (buffer) kullanır. Büyük stringler için ise normal 
`std::string` davranışını sürdürür ve veriyi heap üzerinde saklar.

#### **Temel Yapı:**

1. **SSO Buffer:** `std::string` nesnesinin içinde yer alan, küçük string verilerini saklamak için ayrılmış bir karakter dizisi (örneğin, 15 karakterlik bir tampon).
2. **Heap Allocation:** SSO sınırını aşan stringler için dinamik bellek tahsisi yapılır ve veri heap üzerinde saklanır.

#### **Örnek Yapı:**

class MyString {
private:
    static const size_t SSO_BUFFER_SIZE = 15;
    union {
        char ssoBuffer[SSO_BUFFER_SIZE + 1]; // +1 null terminator
        struct {
            char* heapData;
            size_t length;
            size_t capacity;
        };
    };
    bool isSSO;

public:
    MyString() : isSSO(true) {
        ssoBuffer[0] = '\0';
    }

    MyString(const char* str) {
        size_t len = strlen(str);
        if (len <= SSO_BUFFER_SIZE) {
            isSSO = true;
            strcpy(ssoBuffer, str);
        } else {
            isSSO = false;
            length = len;
            capacity = len + 1;
            heapData = new char[capacity];
            strcpy(heapData, str);
        }
    }

    ~MyString() {
        if (!isSSO) {
            delete[] heapData;
        }
    }

    // Diğer fonksiyonlar (kopyalama, atama, vb.) burada tanımlanmalıdır.
};

**Açıklama:**

- **Union Kullanımı:** `union`, SSO ve heap verisini aynı bellek alanını paylaşarak depolamaya olanak tanır.
- **isSSO Bayrağı:** Stringin SSO ile mi yoksa heap ile mi saklandığını belirler.
- **Constructor:** Giriş stringinin uzunluğunu kontrol eder ve uygun depolama yöntemini seçer.
- **Destructor:** Heap üzerinde tahsis edilmiş veriyi serbest bırakır.

> **Not:** Bu örnek basit bir SSO implementasyonunu göstermektedir. Gerçek `std::string` implementasyonları çok daha karmaşıktır ve birçok optimizasyon içerir.

### **SSO'nun Avantajları**

1. **Hızlı Erişim ve İşlem:**
   - Küçük stringler için heap tahsisi yapılmadığından, erişim ve işlem süreleri kısalır.
   
2. **Daha Az Bellek Tahsisi:**
   - SSO, küçük stringler için ek heap tahsisine gerek kalmadan bellek kullanımı sağlar.

3. **Geliştirilmiş Cache Lokalitesi:**
   - String verisi `std::string` nesnesi içinde saklandığından, CPU önbelleğinde daha iyi yer alır ve erişim hızını artırır.

4. **Daha Az Bellek Yönetimi Yükü:**
   - Heap tahsisi ve serbest bırakma işlemleri minimize edilir, bu da programın genel performansını olumlu etkiler.

### **SSO'nun Dezavantajları**

1. **Artan `std::string` Boyutu:**
   - `std::string` nesnesinin içinde SSO için ek bir buffer bulunduğundan, nesnenin boyutu biraz daha büyük olabilir.

2. **SSO Sınırının Belirlenmesi:**
   - Hangi string uzunluklarının SSO kapsamında olduğunu belirlemek, implementasyona bağlı olarak değişebilir ve taşkın kullanımları engellemek zor olabilir.

3. **Karmaşık Implementasyon:**
   - SSO'nun etkin bir şekilde çalışması, `std::string` implementasyonunu daha karmaşık hale getirebilir ve potansiyel olarak hata yapma riskini artırabilir.

4. **Platform ve Implementasyon Bağımlılığı:**
   - SSO, C++ standardının bir parçası değildir. Farklı standart kütüphane implementasyonları (örneğin, GCC'nin libstdc++, Clang'ın libc++) farklı SSO stratejileri kullanabilir.

### **SSO'yu Anlamak ve Kullanmak**

#### **1. Uygulama Performansını Artırmak İçin SSO**

SSO'nun avantajlarından yararlanmak için, programınızda sık kullanılan ve genellikle kısa olan stringler varsa, `std::string`'in SSO'yu etkin bir şekilde kullanmasını sağlayabilirsiniz. Bunun için:

- **Kısa Stringler Kullanmak:** Küçük ve sık kullanılan stringler, SSO'nun faydalarını maksimize eder.
  
  std::string shortStr = "Hello"; // Muhtemelen SSO ile saklanır

- **Yığın Üzerinde Stringler:** `std::vector<std::string>` gibi veri yapılarında sık sık küçük stringler kullanmak performansı artırabilir.

#### **2. SSO'yu Test Etmek ve Görmek**

SSO'nun etkin olup olmadığını anlamak için, stringlerin bellekte nasıl saklandığını inceleyebilirsiniz. Ancak, bu genellikle standard kütüphane implementasyonlarının
detaylarına bağlıdır ve doğrudan gözlemlenmesi zor olabilir.

Aşağıdaki örnek, `std::string`'in SSO kullanıp kullanmadığını anlamak için kullanılan tekniklerden biridir:

#include <iostream>
#include <string>
#include <cstring>

int main() {
    std::string s1 = "Hello";
    std::string s2 = "This is a longer string that likely exceeds the SSO buffer.";

    // Fiziksel olarak string verisini kontrol etmek için.
    // Bu, her implementasyonda çalışmayabilir.
    std::cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << std::endl;
    std::cout << "s2 size: " << s2.size() << ", capacity: " << s2.capacity() << std::endl;

    return 0;
}

**Açıklama:**

- **Küçük Stringler:** `s1` gibi küçük stringler, SSO kullanılarak `std::string` nesnesinin içinde saklanabilir.
- **Büyük Stringler:** `s2` gibi uzun stringler, heap üzerinde saklanır.

> **Not:** `capacity()` fonksiyonu, SSO'nun kullanılıp kullanılmadığını doğrudan göstermese de, stringin kapasitesi hakkında ipuçları verebilir. 
Örneğin, SSO sınırına yakın veya üzerinde kapasite değerleri, stringin heap üzerinde saklandığını gösterebilir.

### **SSO'nun Etkilerini Anlamak İçin Profil Oluşturma**

SSO'nun performans etkilerini anlamak için, profil oluşturma araçlarını kullanabilirsiniz. Aşağıda, SSO'nun etkisini görmek için basit bir performans testi örneği verilmiştir.

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

int main() {
    const int iterations = 1000000;
    std::vector<std::string> strings;
    strings.reserve(iterations);

    // Kısa string ekleme (SSO kullanma olasılığı yüksek)
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < iterations; ++i) {
        strings.emplace_back("Short");
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_short = end - start;
    std::cout << "Kısa string ekleme süresi: " << elapsed_short.count() << " saniye\n";

    // Uzun string ekleme (SSO kullanmama olasılığı yüksek)
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < iterations; ++i) {
        strings.emplace_back("This is a significantly longer string that exceeds SSO.");
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_long = end - start;
    std::cout << "Uzun string ekleme süresi: " << elapsed_long.count() << " saniye\n";

    return 0;
}

**Açıklama:**

- **Kısa Stringler:** "Short" gibi küçük stringler SSO ile saklanır, bu nedenle ekleme süresi daha düşük olabilir.
- **Uzun Stringler:** Uzun stringler heap üzerinde saklanır, bu da ekleme süresini artırabilir.

> **Not:** Gerçek performans farkları, kullanılan standart kütüphane implementasyonuna ve sistem donanımına bağlı olarak değişebilir.

### **SSO'yu Kullanırken Dikkat Edilmesi Gerekenler**

1. **Yazılım Gereksinimleri:**
   - Eğer yazılımınızın belirli bir `std::string` implementasyonuna bağımlı olmasını istemiyorsanız, SSO'nun nasıl çalıştığını ve performans etkilerini göz önünde bulundurun.

2. **Buffer Boyutları:**
   - Farklı implementasyonlar farklı SSO buffer boyutları kullanabilir. Bu, uygulamanızın SSO performansını etkileyebilir.

3. **SSO'nun Devre Dışı Bırakılması:**
   - Bazı durumlarda, SSO'yu devre dışı bırakmak isteyebilirsiniz (örneğin, bellek kullanımı üzerinde tam kontrol sahibi olmak için). Bu, standart kütüphane
   implementasyonuna bağlı olarak mümkün olabilir, ancak genellikle tavsiye edilmez.

4. **Karşılaştırma ve Test Etme:**
   - Performans iyileştirmelerini değerlendirmek için kendi testlerinizi oluşturun. SSO'nun gerçek uygulamanız üzerindeki etkisini anlamak için profil oluşturma araçlarını kullanın.

### **Sonuç**

**Small String Optimization (SSO)**, C++'ta `std::string` sınıfının performansını artırmak için yaygın olarak kullanılan bir tekniktir. Küçük stringlerin
`std::string` nesnesinin içinde saklanması, dinamik bellek tahsisi maliyetini azaltır ve performansı iyileştirir. Ancak, SSO'nun kullanımı ve etkinliği, 
kullanılan standart kütüphane implementasyonuna bağlı olarak değişebilir.

SSO'yu anlamak ve etkili bir şekilde kullanmak, yazılımınızın performansını artırmak için önemli bir adımdır. Performans kritik uygulamalarda, SSO'nun sunduğu 
avantajlardan yararlanmak için veri yapılarınızı ve algoritmalarınızı optimize edebilirsiniz. Ancak, SSO'nun bir implementasyon detayı olduğunu ve farklı kütüphane 
implementasyonlarının farklı stratejiler kullanabileceğini unutmamak önemlidir.
---------------------------------------------------------------------------------------------------------------------------------------------------
String kütüphanesi constructorları

(const char*) //  cstring parametre
(const char* c size_t n) // data parametre -> c adresinden başlayarak n tane karakter okuyacak
(size_t n char c) // fill parametre ->  n tane c karakteri
(const string &) // başka string nesnesinin tutuuğu yazıyı kullanıcak demek
(const string &, size_t idx) // substring parametre -> string nesnesinin tutuğu yazının idx adlı indeksinden başlayarak geriye kalan 
bütün karakterlerin oluşturduğu substring üstünde işlem yapıcak demek
(const string &, size_t idx,size_t n) // substring parametre -> stringin idx adlı indeksinden başlayarak n tane karakterin üstünde işlem yapıcak demek
(char c) karakter üzerinde işlem yapıcak demek
******************************************************************************************************************************

                                                                             ********* 21-DERS NOTLARI *********

void foo(std::string& s) out parameter ama kullanması pek mantıklı değil onun yerine std::string& döndürmek daha mantıklı
--------------------------------------------------------------------------------------------------------------------------------------------------
initializer_list parametreli constructorımız olmazsa () direct initialization yada {} value initialization arasında bir fark yoktur
ama initializaer_list constructorımız varsa () direct init yad {} value init arasında farklar olur {} ile nesneyi oluşturmak
initializaer_list constructorını çağırır

class Myclass
{
public:
    Myclass(int){}
    Myclass(int, int) {
        std::cout << "int,int\n";
    }
    Myclass(std::initializer_list<int>)
    {
        std::cout << "initializer_list\n";
    }
};

int main()
{

    Myclass m1(34); // int,
    Myclass m2(30,45); // int,int
    Myclass m3{10,25,25}; //initializer_list

}
NOT:çoğu kütüphanenin initializer_list constructorı vardır
--------------------------------------------------------------------------------------------------------------------------------------------------
1)**Null-Terminated Buffer Stream Nedir?**

C++ ve genel olarak programlamada, **null-terminated buffer stream** kavramı, **null-terminated** (sonlandırılmış) 
**buffer** (tampon) kullanarak veri akışını (stream) yönetmeyi ifade eder. Bu kavram, özellikle C tarzı stringler ve veri 
iletiminde sıkça kullanılır. Aşağıda bu kavramın detaylı açıklaması, kullanım alanları ve örnekleri bulunmaktadır.

### **1. Temel Kavramlar**

#### **a. Null-Terminated (Sonlandırılmış) Buffer**

- **Tanım:**
  - Bir buffer, verinin geçici olarak saklandığı bellek alanıdır. **Null-terminated buffer**, verinin sonunda `'\0'` karakteri (null karakteri) bulunan bir tampondur.
  - C/C++ programlamada, C tarzı stringler genellikle null-terminated olarak saklanır. Yani, stringin sonu `'\0'` karakteri ile işaretlenir.

- **Örnek:**

  char buffer[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
  // veya daha yaygın olarak
  char buffer[] = "Hello"; // Otomatik olarak sonuna '\0' eklenir

#### **b. Stream (Akış)**

- **Tanım:**
  - **Stream**, verilerin kaynaktan hedefe aktarıldığı soyut bir kavramdır. C++'ta `std::istream` ve `std::ostream` gibi akış sınıfları, veri okuma ve yazma işlemlerini yönetir.
  - **Buffer stream**, veri akışının bir buffer üzerinden yönetilmesini sağlar. Bu, verinin geçici olarak buffer içinde saklanması ve gerektiğinde işlenmesi anlamına gelir.

- **Örnek:**

  std::ifstream inputFile("example.txt"); // Dosya okuma akışı
  std::ofstream outputFile("output.txt"); // Dosya yazma akışı

### **2. Null-Terminated Buffer Stream Nasıl Çalışır?**

Null-terminated buffer stream, genellikle C tarzı stringlerin veya verilerin, null karakteri ile sonlandırıldığı buffer'lar üzerinden veri akışını yönetir. Bu, özellikle aşağıdaki durumlarda kullanılır:

1. **C Cihazları veya Kütüphaneler ile Entegrasyon:**
   - C++ uygulamaları, C dilinde yazılmış kütüphanelerle çalışırken, veri iletiminde null-terminated stringler kullanılır.

2. **Veri İletimi ve Serializasyon:**
   - Ağ üzerinden veri gönderirken veya alırken, verinin sonunu belirtmek için null karakteri kullanılabilir.

3. **Özel Buffer Yönetimi:**
   - Performans optimizasyonu amacıyla, veri akışını doğrudan buffer üzerinde yönetmek ve gereksiz bellek tahsisini önlemek için null-terminated buffer kullanılır.

#### **Nasıl Kullanılır?**

C++'ta null-terminated buffer stream kullanmak için çeşitli yöntemler bulunmaktadır. Aşağıda bazı yaygın kullanım senaryoları ve örnekler verilmiştir.

### **3. Uygulama Örnekleri**

#### **a. C tarzı Stringleri Akışlara Yazma ve Okuma**

C++'ta C tarzı stringleri `std::ostream` ve `std::istream` ile kullanmak mümkündür. Null-terminated buffer'lar, bu süreçte veri sonunu belirtmek için kullanılır.

**Örnek:**

#include <iostream>
#include <sstream>
#include <cstring>

int main() {
    // Yazma akışı oluşturma
    std::ostringstream oss;
    const char* cStr = "Hello, World!";
    oss.write(cStr, std::strlen(cStr) + 1); // +1 ile null karakteri de yazılır

    // Buffer'dan okuma akışı oluşturma
    std::istringstream iss(oss.str());
    char buffer[50];
    iss.read(buffer, sizeof(buffer));

    // Okunan stringi yazdırma
    std::cout << "Okunan string: " << buffer << std::endl; // "Hello, World!"

    return 0;
}

**Açıklama:**
- `std::ostringstream` kullanılarak bir yazma akışı oluşturulur ve C tarzı string (`cStr`) buffer'a yazılır.
- `std::istringstream` kullanılarak buffer'dan veri okunur ve null karakteri ile sonlandırılmış bir string elde edilir.

#### **b. Ağ Üzerinden Veri Gönderme ve Alma**

Ağ programlamasında, verilerin gönderildiği buffer'ların null karakteri ile sonlandırılması, veri sonunun belirlenmesi için kullanılır.

**Örnek:**

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    // Basit bir TCP sunucusu örneği
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* response = "Hello from server!\0";

    // Socket oluşturma
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Bağlantı adresi yapılandırma
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Socket'e bağlanma
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Dinleme yapma
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "Sunucu bekleniyor..." << std::endl;

    // Bağlantıyı kabul etme
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, 
                       (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Veriyi okuma
    read(new_socket, buffer, 1024);
    std::cout << "Gelen veri: " << buffer << std::endl;

    // Yanıt gönderme
    send(new_socket, response, std::strlen(response) + 1, 0);
    std::cout << "Yanıt gönderildi." << std::endl;

    close(new_socket);
    close(server_fd);
    return 0;
}

**Açıklama:**
- Sunucu, gelen veriyi `buffer`'a okur ve null karakteri ile sonlandırır.
- Yanıt gönderilirken, null karakteri (`'\0'`) ile sonlandırılmış string gönderilir, böylece alıcı taraf veri sonunu kolayca belirleyebilir.

#### **c. Özel Buffer Yönetimi ile Veri Akışı**

Performans optimizasyonu amacıyla, veri akışını doğrudan null-terminated buffer'lar üzerinden yönetmek mümkündür. Bu, özellikle büyük veri setleri ile çalışırken bellek yönetimini kolaylaştırır.

**Örnek:**

#include <iostream>
#include <cstring>

class NullTerminatedBufferStream {
private:
    char* buffer;
    size_t capacity;
    size_t size;

public:
    NullTerminatedBufferStream(size_t initialCapacity = 1024) 
        : capacity(initialCapacity), size(0) {
        buffer = new char[capacity];
        buffer[0] = '\0';
    }

    ~NullTerminatedBufferStream() {
        delete[] buffer;
    }

    // Veriyi buffer'a ekleme
    void write(const char* data) {
        size_t dataLen = std::strlen(data);
        if (size + dataLen + 1 > capacity) {
            // Yeni kapasite hesaplama (örneğin, iki katına çıkarma)
            capacity = (size + dataLen + 1) * 2;
            char* newBuffer = new char[capacity];
            std::memcpy(newBuffer, buffer, size);
            delete[] buffer;
            buffer = newBuffer;
        }
        std::memcpy(buffer + size, data, dataLen + 1); // +1 null karakteri
        size += dataLen;
    }

    // Buffer'dan veriyi okuma
    const char* read() const {
        return buffer;
    }

    // Buffer'ı temizleme
    void clear() {
        size = 0;
        buffer[0] = '\0';
    }
};

int main() {
    NullTerminatedBufferStream nts;
    nts.write("Hello");
    nts.write(", ");
    nts.write("World!");
    std::cout << "Buffer içeriği: " << nts.read() << std::endl; // "Hello, World!"

    nts.clear();
    nts.write("Yeni veri.");
    std::cout << "Buffer içeriği: " << nts.read() << std::endl; // "Yeni veri."

    return 0;
}

**Açıklama:**
- `NullTerminatedBufferStream` sınıfı, veriyi null karakteri ile sonlandırılmış bir buffer üzerinde yönetir.
- `write` fonksiyonu, veriyi buffer'a eklerken null karakteri ile sonlandırır ve gerektiğinde buffer kapasitesini artırır.
- `read` fonksiyonu, buffer içeriğini null-terminated bir string olarak döner.

### **4. Avantajları ve Dezavantajları**

#### **Avantajları:**

1. **Basitlik:**
   - Null-terminated buffer'lar, C tarzı stringlerin ve veri akışının yönetimini basitleştirir.
   
2. **Uyumluluk:**
   - C ve C++ arasında veri paylaşımında kolaylık sağlar, çünkü C tarzı stringler her iki dilde de yaygın olarak kullanılır.
   
3. **Performans:**
   - Küçük veri parçalarının yönetiminde hızlı erişim ve ekleme sağlar, özellikle SSO (Small String Optimization) ile birlikte kullanıldığında performansı artırır.

#### **Dezavantajları:**

1. **Hata Yapma Olasılığı:**
   - Null karakterinin unutulması veya yanlış kullanılması, veri sonunun yanlış anlaşılmasına veya bellek hatalarına yol açabilir.
   
2. **Sınırlamalar:**
   - Null karakteri, veri içerisinde kullanılabilir olmadığından, veri formatına bu sınırlamayı ekler. Bu, özellikle binary verilerle çalışırken sorun yaratabilir.
   
3. **Güvenlik:**
   - Buffer overflow gibi güvenlik açıklarına karşı dikkatli olunmalıdır. Veri eklerken buffer sınırlarının aşılmamasına özen gösterilmelidir.

### **5. Modern C++ Yaklaşımları**

Modern C++'ta, null-terminated buffer stream yönetimi için daha güvenli ve esnek yöntemler bulunmaktadır. Örneğin:

#### **a. `std::vector<char>` Kullanımı**

`std::vector<char>`, dinamik olarak büyüyebilen ve yönetilebilen bir buffer sağlar. Null karakteri ile sonlandırmak kolaydır.

**Örnek:**

#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char> buffer;
    const char* data1 = "Hello";
    const char* data2 = ", World!";

    // Veriyi ekleme
    buffer.insert(buffer.end(), data1, data1 + std::strlen(data1));
    buffer.push_back('\0'); // Null karakteri ekleme

    buffer.insert(buffer.end(), data2, data2 + std::strlen(data2));
    buffer.push_back('\0'); // Null karakteri ekleme

    // Okuma
    std::cout << "First string: " << buffer.data() << std::endl; // "Hello"
    std::cout << "Second string: " << (buffer.data() + std::strlen(buffer.data()) + 1) << std::endl; // "World!"

    return 0;
}

#### **b. `std::string` Kullanımı**

`std::string`, otomatik olarak null-terminated olabilir ve veri yönetimini kolaylaştırır.

**Örnek:**

#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";

    // İki stringi birleştirme
    std::string combined = str1 + ", " + str2 + '!';
    combined += '\0'; // Null karakteri ekleme

    // Okuma
    std::cout << "Combined string: " << combined.c_str() << std::endl; // "Hello, World!"

    return 0;
}

### **6. Sonuç**

**Null-Terminated Buffer Stream**, C++ programlamada veriyi null karakteri ile sonlandırılmış buffer'lar üzerinden yönetmeyi ifade eder. Bu kavram, 
C tarzı stringlerin ve veri akışlarının yönetiminde yaygın olarak kullanılır. Modern C++ yaklaşımları, daha güvenli ve esnek yöntemler sunarak, 
null-terminated buffer stream yönetimini kolaylaştırır ve hata yapma olasılığını azaltır.

**Özetlemek Gerekirse:**

- **Null-Terminated Buffer:** Verinin sonunda `'\0'` karakteri bulunan buffer.
- **Stream:** Verilerin kaynaktan hedefe aktarıldığı soyut akış.
- **Null-Terminated Buffer Stream:** Verinin null-terminated buffer üzerinden yönetildiği akış.

Bu kavramları etkili bir şekilde kullanmak, veri yönetimini optimize ederken aynı zamanda kodun okunabilirliğini ve güvenilirliğini artırır.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)**`if` with Initializer (C++17)**

C++17 tanıtılan **`if` with initializer** özelliği, `if` ifadeleri içinde değişkenlerin tanımlanmasını ve başlatılmasını mümkün kılar.
Bu özellik, değişkenlerin yalnızca `if` bloğu içinde geçerli olmasını sağlayarak kodun daha temiz, okunabilir ve kapsam kontrolünü daha iyi yönetilebilir hale getirir.

### **Özelliklerin Genel Tanımı**

C++17 ile birlikte gelen bu özellik, `if` ifadesi içinde bir değişken tanımlamanıza ve bu değişkeni koşul ifadesiyle birlikte kullanmanıza olanak tanır. 
Bu sayede, değişkenler yalnızca `if` bloğu içinde geçerli olur ve dışarıdan erişilemez.

**Sözdizimi:**

if (initialization; condition) {
    // Koşul doğruysa çalışacak kod bloğu
}

### **Temel Kullanım**

#### **1. Temel Örnek**

#include <iostream>

int main() {
    if (int x = 10; x > 5) {
        std::cout << "x büyük 5: " << x << std::endl;
    }
    // x burada erişilemez
    // std::cout << x; // Hata: 'x' bulunamadı
    return 0;
}

**Çıktı:**

x büyük 5: 10

Bu örnekte, `x` değişkeni yalnızca `if` bloğu içinde geçerlidir. Blok dışında `x`'e erişmeye çalışmak derleyici hatası verir.

#### **2. `std::map` ile Kullanım**

`std::map` gibi konteynerlerde belirli bir anahtarın var olup olmadığını kontrol etmek için bu özelliği kullanabilirsiniz.

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ageMap = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

    std::string name = "Bob";

    if (auto it = ageMap.find(name); it != ageMap.end()) {
        std::cout << name << " yaşta: " << it->second << std::endl;
    } else {
        std::cout << name << " bulunamadı." << std::endl;
    }

    return 0;
}

**Çıktı:**

Bob yaşta: 25

Bu örnekte, `it` iterator'ü yalnızca `if` bloğu içinde geçerlidir ve `find` fonksiyonunun sonucuna göre işlem yapılır.

### **Avantajları**

1. **Kapsam Yönetimi:**
   - Değişkenler yalnızca `if` bloğu içinde tanımlanır ve kullanılır, bu da kapsamın daha iyi yönetilmesini sağlar.
   
2. **Daha Temiz Kod:**
   - Kodun okunabilirliğini artırır ve gereksiz değişken tanımlamalarını önler.
   
3. **Hata Riskini Azaltır:**
   - Değişkenlerin yanlışlıkla blok dışına taşınmasını engeller, böylece potansiyel hataların önüne geçilir.
   
4. **Performans:**
   - Değişkenler yalnızca ihtiyaç duyulduğunda tanımlandığı için, gereksiz bellek kullanımı azaltılır.

### **Kullanım Senaryoları**

#### **1. Dosya Açma ve Kontrol Etme**

Bir dosyayı açarken, açma işleminin başarılı olup olmadığını kontrol etmek için kullanılabilir.

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "example.txt";

    if (std::ifstream file(filename); file.is_open()) {
        std::cout << "Dosya başarıyla açıldı: " << filename << std::endl;
        // Dosya işlemleri
    } else {
        std::cout << "Dosya açılamadı: " << filename << std::endl;
    }

    return 0;
}

#### **2. `std::optional` ile Kullanım**

`std::optional` kullanılarak bir değerin var olup olmadığını kontrol etmek için.

#include <iostream>
#include <optional>
#include <string>

// Basit bir arama fonksiyonu
std::optional<int> findInArray(const int* arr, size_t size, int target) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == target)
            return i;
    }
    return std::nullopt;
}

int main() {
    int numbers[] = {1, 3, 5, 7, 9};
    int target = 5;

    if (auto result = findInArray(numbers, 5, target); result.has_value()) {
        std::cout << "Hedef " << target << " bulundu, indeksi: " << result.value() << std::endl;
    } else {
        std::cout << "Hedef " << target << " bulunamadı." << std::endl;
    }

    return 0;
}

**Çıktı:**

Hedef 5 bulundu, indeksi: 2

### **Dikkat Edilmesi Gerekenler**

1. **Önceki C++ Sürümleri ile Uyumluluk:**
   - Bu özellik, C++17 ile birlikte tanıtıldığından, daha eski C++ sürümlerinde kullanılamaz. Proje derleyicinizin C++17 veya daha yeni bir standardı desteklediğinden emin olun.
   
2. **Okunabilirlik:**
   - Aşırı kullanım, kodun karmaşık görünmesine neden olabilir. Yalnızca gerekli durumlarda bu özelliği kullanmak, kodun okunabilirliğini korur.
   
3. **Değişken Adları:**
   - `if` bloğu içindeki değişken adlarının açık ve anlamlı olmasına dikkat edin. Bu, kodun anlaşılmasını kolaylaştırır.

### **Ek Örnekler**

#### **1. Lambdalar ile Kullanım**

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    if (auto it = std::find_if(numbers.begin(), numbers.end(),
                               [](int n) { return n > 3; });
        it != numbers.end()) {
        std::cout << "4'ten büyük ilk sayı: " << *it << std::endl;
    } else {
        std::cout << "4'ten büyük sayı bulunamadı." << std::endl;
    }

    return 0;
}

**Çıktı:**

4'ten büyük ilk sayı: 4

#### **2. `std::variant` ile Kullanım**

#include <iostream>
#include <variant>
#include <string>

int main() {
    std::variant<int, std::string> data = "Merhaba";

    if (auto ptr = std::get_if<std::string>(&data); ptr) {
        std::cout << "String değeri: " << *ptr << std::endl;
    } else {
        std::cout << "Değer bir int." << std::endl;
    }

    return 0;
}

**Çıktı:**

String değeri: Merhaba

### **Sonuç**
C++17 ile gelen **`if` with initializer** özelliği, değişkenlerin tanımlanmasını ve başlatılmasını `if` ifadeleri içinde daha etkili bir şekilde 
yönetmenizi sağlar. Bu, kodun okunabilirliğini artırır, kapsam yönetimini iyileştirir ve potansiyel hataların önüne geçer. Ancak, bu özelliği dengeli 
ve gerekli durumlarda kullanmak, kod kalitesini en üst düzeye çıkarır.

Bu özelliği kullanarak, kodunuzda gereksiz değişken tanımlamalarını azaltabilir ve daha temiz, anlaşılır bir yapı oluşturabilirsiniz. Modern 
C++ programlamada bu tür dil özelliklerini etkin bir şekilde kullanmak, daha verimli ve bakımı kolay kodlar yazmanıza yardımcı olur.
--------------------------------------------------------------------------------------------------------------------------------------------------
if(bool b = isOk()) // bu ifte logic işlem yapılıyor isOk() true ise buraya girecek
{
}
--------------------------------------------------------------------------------------------------------------------------------------------------
3)"**Moved-from state**," özellikle C++'ta nesnelerin taşınma semantiğiyle (move semantics) ilgili bir terimdir. Bir nesne, kaynak bir nesneden verilerin 
"taşındığı" durumdan sonra **moved-from** (taşınmış) olarak kabul edilir. Bu, tipik olarak bir nesnenin kaynaklarını başka bir nesneye transfer etmesi sonucu oluşur.

### Moved-from State'in Özellikleri

1. **Geçerli ama Belirsiz Durum**: 
   - Bir nesne "taşınmış" durumdaysa, hâlâ geçerlidir (yani, programda var olur), ancak belirli bir durumu garanti edilmez. Nesnenin 
   iç durumu belirsizdir ve yalnızca sınıfın özel olarak tanımladığı kurallarla ilişkilidir.
   
2. **Kaynakların Transferi**:
   - Moved-from bir nesne, sahip olduğu kaynakları başka bir nesneye aktarmış olabilir. Örneğin, bir dinamik belleğe sahip nesne, taşındığında 
   belleğin sahibi yeni nesne olur ve moved-from nesnenin bu kaynaklarla ilgisi kalmaz.

3. **Standartların Tanımı**:
   - C++ standartları, moved-from bir nesne için bazı sınırlamalar getirir. Ancak moved-from durumdaki bir nesne, yok edilebilir (destructible) 
   olmalı ve yeniden atanabilir (assignable) olmalıdır. Yani bir nesne taşındıktan sonra güvenli bir şekilde yok edilebilmeli ve yeni bir değer atanabilmelidir.

### Moved-from State Nasıl Oluşur?

Moved-from state genellikle **move constructor** veya **move assignment operator** ile oluşur. Bunlar, bir nesnenin kaynaklarını başka bir nesneye taşır.

#### Örnek (Move Constructor ile)

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = std::move(vec1); // vec1 moved-from state'e geçer

    std::cout << "vec1'in boyutu: " << vec1.size() << std::endl; // Belirsiz bir değer
    std::cout << "vec2'nin boyutu: " << vec2.size() << std::endl; // Boyut: 5
}

Bu örnekte, `vec1`, `std::move` kullanılarak `vec2`'ye taşınır. Bu işlemden sonra `vec1`, belirsiz bir durumdadır (moved-from state), ancak hala geçerlidir. 
`vec1`'in durumu net olarak tanımlanmamış olsa da, genellikle kaynakları (bellek, veri) `vec2`'ye taşınmıştır.

### Moved-from Nesneler Nasıl Kullanılır?

Moved-from bir nesneyi kullanırken dikkatli olmak gerekir, çünkü bu nesne artık kaynaklara sahip olmayabilir ve durumu belirsiz olabilir. Ancak moved-from 
nesneler hâlâ yok edilebilir (destructor'ları çağrılabilir) ve yeni bir değere atanabilirler. Örneğin:

vec1 = {10, 20, 30}; // Moved-from durumdaki vec1 yeniden kullanılabilir

Moved-from bir nesnenin hangi işlevleri yerine getirebileceği, sınıfın nasıl tanımlandığına bağlıdır.

### Genel Tavsiyeler

- **Moved-from nesnelerle işlem yaparken dikkatli olun**: Moved-from bir nesnenin durumu tanımlanmış olmayabilir, bu yüzden onu kullanırken özellikle belirsiz durumları göz önünde bulundurun.
- **Moved-from nesneleri yok etmek güvenlidir**: Moved-from nesneler, yok edildiklerinde hata vermezler ve yeni bir değere atanabilirler.
- **Kaynakları taşındıktan sonra nesneleri yeniden başlatmayı düşünün**: Eğer moved-from bir nesneyle daha fazla çalışmak istiyorsanız, ona yeni bir değer atamak güvenli bir yol olabilir.

Moved-from state, performans kazanımları için önemli bir özelliktir. Özellikle büyük veri yapılarının kopyalanmak yerine taşınmasını sağlayarak, gereksiz bellek ve işlem yükünü azaltır.
--------------------------------------------------------------------------------------------------------------------------------------------------
`std::string::npos`, C++'da `std::string` sınıfına ait özel bir sabittir. Bu sabit, genellikle "hiçbir konum" anlamına gelir ve bir arama işleminin 
başarısız olduğunu ifade etmek için kullanılır. Tam adı `npos`, "no position" ifadesinden türetilmiştir.

### **`std::string::npos` Kullanım Amacı**

1. **Başarısız Arama Durumlarının Belirtilmesi:**
   - `std::string` sınıfının `find`, `rfind`, `find_first_of`, `find_last_of` gibi arama işlevleri, belirtilen alt dizenin bulunamaması durumunda `npos` döner.

2. **Hata Kontrolü:**
   - Arama işlemlerinde alt dize bulunup bulunmadığını kontrol etmek için kullanılır.

### **`std::string::npos` Örneği**

#### **Alt Diziyi Arama ve Kontrol**

#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::string toFind = "World";

    // Alt diziyi ara
    size_t pos = str.find(toFind);

    if (pos != std::string::npos) {
        std::cout << "Alt dize bulundu! Pozisyon: " << pos << '\n';
    } else {
        std::cout << "Alt dize bulunamadı.\n";
    }

    return 0;
}

**Çıktı:**

Alt dize bulundu! Pozisyon: 7

### **Başarısız Arama Durumu**

#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::string toFind = "C++";

    if (str.find(toFind) == std::string::npos) {
        std::cout << "Alt dize bulunamadı.\n";
    }

    return 0;
}

**Çıktı:**

Alt dize bulunamadı.

### **Diğer Kullanım Alanları**

1. **Alt Dize Bulunduğunda Sonraki İşlemler**
   - Bir alt dizeyi bulduktan sonra onun pozisyonunu kullanarak işlem yapabilirsiniz.

2. **Dizinin Sonuna Kadar Arama Yapmak**
   - `npos`, aynı zamanda bir dizinin sonuna kadar arama yapmak için kullanılabilir.

#include <iostream>
#include <string>

int main() {
    std::string str = "C++ is amazing!";
    size_t pos = str.find("is", 0); // Baştan itibaren ara

    if (pos != std::string::npos) {
        std::cout << "\"is\" bulundu! Pozisyon: " << pos << '\n';
    }

    return 0;
}

### **`npos` Değeri ve Türü**
- `std::string::npos`, genellikle `std::string::size_type` türünde en büyük olası değeri ifade eder (`std::numeric_limits<std::size_t>::max()` ile aynı olabilir).
- Bu, dizilerde geçerli bir indeks olmayacak şekilde tasarlanmıştır.

### **Özet**
- `std::string::npos`, C++'ta başarısız arama durumlarını ifade eder.
- `std::string`'in arama işlevlerinde yaygın olarak kullanılır.
- Kodunuzu daha güvenli ve okunabilir hale getirir, çünkü başarısız işlemleri kontrol etmek kolaylaşır.
--------------------------------------------------------------------------------------------------------------------------------------------------
Kodda şu ifade dikkat çekiyor:

str.substr(5, std::string::npos);

Bu satırda `std::string::substr` işlevine ikinci parametre olarak `std::string::npos` verilmiş. Bunun amacı ve kullanım detayları aşağıdaki gibidir:

### **`std::string::substr` İşlevi**
`substr` işlevi, bir dizgeden (string) belirtilen başlangıç konumundan itibaren bir alt dize döndürmek için kullanılır.

#### **Sözdizimi:**

std::string substr(size_t pos = 0, size_t count = npos) const;

- **`pos`**: Alt dizenin başlaması gereken indeks.
- **`count`**: Alt dizenin maksimum uzunluğu. Varsayılan olarak `std::string::npos`, yani dizenin sonuna kadar anlamına gelir.

### **Neden `npos` Kullanılıyor?**

1. **Dizenin Sonuna Kadar Alt Dize Almak İçin:**
   - `std::string::npos`, "dizenin sonuna kadar git" anlamında kullanılır.
   - Eğer ikinci parametre olarak `std::string::npos` verilirse, `substr` başlangıç konumundan itibaren dizenin sonuna kadar tüm karakterleri döndürür.

2. **Daha Temiz ve Anlamlı Kod İçin:**
   - Açıkça dizenin sonuna kadar olan kısmı almayı belirtir. Sabit bir uzunluk yazmak yerine `npos` kullanmak, kodun amacını daha net ifade eder.

### **Kodun Çalışması**

#include <iostream>
#include <string>

int main() {
    std::string str{ "bugün persembe" };

    // 5. indexten itibaren dizenin sonuna kadar olan kısmı al
    std::string result = str.substr(5, std::string::npos);

    std::cout << "Alt dize: " << result << '\n';
    return 0;
}

**Çıktı:**

Alt dize: persembe

#### Adım Adım:
1. **Başlangıç Konumu (5):** `substr` işlemi, dizenin 5. indeksinden başlar (`p` harfi).
2. **Uzunluk (`std::string::npos`):** Dizinin sonuna kadar tüm karakterleri alır.

### **Özet**
- `std::string::npos` burada, dizenin sonuna kadar olan tüm karakterleri almak için kullanılır.
- Bu, kodu daha temiz ve esnek yapar. Eğer dizenin uzunluğu değişse bile `npos` ile çalışmaya devam eder.

Alternatif olarak `str.size() - 5` gibi bir ifade yazılabilir, ancak `npos` kullanımı hem daha sade hem de daha güvenlidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
`std::string` sınıfında bulunan `reserve` fonksiyonunun amacı, bir dizge (`std::string`) nesnesi için bellek tahsisini önceden ayarlayarak,
performans iyileştirmesi sağlamaktır. Bu, özellikle sık sık büyüyen dizgeler üzerinde çalışıyorsanız önemlidir.

### **`reserve` Fonksiyonu**
#### **Sözdizimi:**

void reserve(size_t new_cap);

- **`new_cap`**: Tahsis edilmesi istenen minimum kapasite.

#### **Ne Yapar?**
1. **Bellek Tahsisi:**
   - `new_cap` kadar bir kapasite (hafıza) rezerv eder.
   - Bu kapasite, dizgenin uzunluğunu artırmak için kullanılabilir.

2. **Performans İyileştirme:**
   - Dizge büyüdüğünde belleğin yeniden tahsis edilmesini (reallocation) ve kopyalama işlemlerini azaltır.

#### **Özellikler:**
- Eğer mevcut kapasite (`capacity()`) `new_cap`'den büyükse, bir şey yapmaz.
- Eğer `new_cap`, mevcut kapasiteden küçükse kapasiteyi azaltmaz.
- Kapasite artırıldığında, mevcut veriler korunur.

### **`reserve` Kullanımının Önemi**

1. **Performans Optimizasyonu:**
   - Varsayılan olarak, bir `std::string` büyüdüğünde kapasite otomatik olarak yeniden tahsis edilir. Bu işlem maliyetlidir, çünkü:
     - Eski belleğin içeriği yeni belleğe taşınır.
     - Bu işlemler tekrar tekrar yapılabilir.
   - `reserve`, başlangıçta yeterli bellek tahsis ederek yeniden tahsis işlemlerini en aza indirir.

2. **Kontrollü Bellek Kullanımı:**
   - `reserve`, dizge için tahsis edilen belleği kontrol etmenize olanak tanır. Bu, bellek yönetimini daha tahmin edilebilir hale getirir.

3. **Büyük Dizge İşlemleri:**
   - Eğer bir dizgeye sürekli olarak karakter ekleyeceğinizi biliyorsanız (`push_back`, `+=` veya `append`), `reserve` kullanarak büyük bir kapasite ayırmak, işlemleri hızlandırabilir.

### **Bir Örnek:**

#include <iostream>
#include <string>
#include <chrono>

int main() {
    const size_t size = 1'000'000;

    // 1. Reallocation olmadan
    std::string str;
    str.reserve(size); // Önceden kapasite ayır
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < size; ++i) {
        str.push_back('a');
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "With reserve: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // 2. Reallocation ile
    std::string str2;
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < size; ++i) {
        str2.push_back('a');
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Without reserve: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    return 0;
}

#### **Çıktı:**

With reserve: 5 ms
Without reserve: 50 ms

**Açıklama:**
- İlk durumda, `reserve` ile önceden kapasite tahsis edilmiştir. Bu nedenle yeniden tahsis işlemleri yapılmaz, işlemler hızlıdır.
- İkinci durumda, dizge büyüdükçe yeniden tahsis ve kopyalama işlemleri gerçekleşir, bu da yavaşlığa neden olur.

### **Kısaca `reserve` Fonksiyonu:**
- Büyük veya dinamik olarak büyüyen dizgelerde bellek tahsis işlemlerini optimize etmek için kullanılır.
- Performansı artırır ve gereksiz bellek yeniden tahsislerini önler.
- Özellikle, dizge boyutunun önceden tahmin edilebildiği durumlarda çok kullanışlıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilindeki `std::string` sınıfında ve STL (Standart Şablon Kütüphanesi) kapsayıcılarında kullanılan `at` fonksiyonu ile indeksleme operatörü 
(`[]`) arasında bazı benzerlikler ve önemli farklar vardır. Aşağıda bu iki yöntemi detaylıca inceleyelim:


### **`at` ve `[]` Operatörünün Karşılaştırılması**

| **Özellik**       | **`at` Fonksiyonu**                                       | **`[]` Operatörü**                              |
|--------------------|-----------------------------------------------------------|------------------------------------------------|
| **Güvenlik**       | Sınır kontrolü yapar. Erişim sınır dışındaysa 
                        `std::out_of_range` hatası fırlatır.                    | Sınır kontrolü yapmaz. Davranış tanımsızdır (UB). |
| **Performans**     | Daha yavaş (kontrol ve hata yakalama ek yükü nedeniyle).  | Daha hızlı (kontrol ek yükü yoktur).           |
| **Hata Durumu**    | Hatalı erişimde program kontrollü bir şekilde çöker.      | Hatalı erişimde tanımsız davranış oluşabilir.  |
| **Kullanım Amacı** | Güvenli erişim gerektiren durumlar.                        | Performansın kritik olduğu durumlar.           |

### **Kullanım**

#### **`at` Fonksiyonu**
- Daha güvenlidir çünkü sınır kontrolü yapar.
- Eğer geçersiz bir indeks verilirse, `std::out_of_range` exception fırlatır.

##### Örnek:

#include <iostream>
#include <string>

int main() {
    std::string str = "hello";

    try {
        // Geçerli bir erişim
        std::cout << "Karakter: " << str.at(1) << '\n';

        // Geçersiz bir erişim
        std::cout << "Karakter: " << str.at(10) << '\n';
    } catch (const std::out_of_range& e) {
        std::cerr << "Hata: " << e.what() << '\n';
    }

    return 0;
}

#### **Çıktı:**

Karakter: e
Hata: basic_string::at: __n (which is 10) >= this->size() (which is 5)

#### **`[]` Operatörü**
- Daha hızlıdır çünkü sınır kontrolü yapmaz.
- Erişim sınırların dışındaysa, davranış tanımsızdır (undefined behavior).

##### Örnek:

#include <iostream>
#include <string>

int main() {
    std::string str = "hello";

    // Geçerli bir erişim
    std::cout << "Karakter: " << str[1] << '\n';

    // Geçersiz bir erişim (undefined behavior)
    std::cout << "Karakter: " << str[10] << '\n';

    return 0;
}

#### **Çıktı (tanımsız davranış):**

Karakter: e
Karakter: (bir şey veya çökme)

### **Kullanım Yönergeleri**
1. **Performans öncelikli ise:** `[]` operatörünü kullanabilirsiniz. Ancak sınırların dışına çıkmamaya dikkat edin.
2. **Güvenlik öncelikli ise:** `at` fonksiyonunu tercih edin. Bu, sınır kontrolü gerektiren durumlar için daha iyidir.
3. **Hata yakalama gerektiren durumlar:** `at` fonksiyonu ile sınır dışı hataları kontrol edebilirsiniz.
4. **Yazılım geliştirme aşaması:** Geliştirme aşamasında `at` kullanmak, sınır hatalarını tespit etmek için faydalıdır.

### **Birlikte Kullanım Örneği**

#include <iostream>
#include <string>

void printCharacter(const std::string& str, size_t index) {
    if (index < str.size()) {
        std::cout << "Karakter: " << str[index] << '\n';  // Performans
    } else {
        try {
            std::cout << "Karakter: " << str.at(index) << '\n';  // Güvenlik
        } catch (const std::out_of_range& e) {
            std::cerr << "Hata: " << e.what() << '\n';
        }
    }
}

int main() {
    std::string str = "world";

    printCharacter(str, 2);  // Geçerli
    printCharacter(str, 10); // Geçersiz

    return 0;
}

### **Sonuç**
- **`at` fonksiyonu:** Sınır kontrolüyle güvenliği artırır, ancak performans açısından daha maliyetlidir.
- **`[]` operatörü:** Performans öncelikli işler için uygundur, ancak hatalara karşı dikkatli olunmalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
    std::string s("emre");

    for (const char& c : s) // bu parametre char& olsaydı ve döngü içinde c değiştirilseydi string s nesnesininde
                                değeri değişmiş olucaktı çünkü referans deklatörü var
    {
        std::cout << c;
    }

    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        char c = *iter;
        std::cout << c;
    }

    bu iki döngü arasında hiç bir fark yok range base for loop ile derleyici kodu altta ki koda çeviriyor
******************************************************************************************************************************

                                                                             ********* 22-DERS NOTLARI *********

insert

std::string str{"ABCDEF};

auto iter = str.insert(str.begin() + 3, "*"); // insert fonksiyonundan elde ettiğimiz geri dönüş değeri iteratör yani öğenin konumu

bu iteratör insert edilmiş öğenin konumuna iteratör yani * değerinin konumuna

std::cout<<*iter // * çıktısı olur
--------------------------------------------------------------------------------------------------------------------------------------------------
1)C++'ta konteyner sınıfları (örneğin `std::vector`, `std::string` gibi) kullanıldığında, **`size`** ve **`capacity`** 
terimleri, farklı anlamlara gelir ve bellek yönetimi açısından önemli farklılıklar gösterir.

### `size` Nedir?

- **`size`**, konteynerdeki **mevcut eleman sayısını** ifade eder.
- Bu, o an için konteynerin içinde bulunan elemanların sayısıdır.
- Örneğin, bir `std::vector` içinde kaç tane öğe olduğunu temsil eder.

#### Örnek:

std::vector<int> vec = {1, 2, 3};
std::cout << "Size: " << vec.size() << std::endl;  // Çıktı: 3

Yukarıdaki örnekte, `vec.size()` değeri 3'tür çünkü `vec` içinde 3 eleman (1, 2 ve 3) bulunmaktadır.

### `capacity` Nedir?

- **`capacity`**, konteynerin o anki **depolayabileceği maksimum eleman sayısını** ifade eder.
- `capacity`, konteynerin içindeki mevcut eleman sayısından büyük olabilir, çünkü konteynerin kapasitesi bellekte dinamik olarak ayırılan alanla ilgilidir.
- Bir konteynerin kapasitesi, mevcut eleman sayısını aştığında, yeni elemanlar eklenene kadar bellekte fazladan yer kullanır. Bu sayede, sürekli yeniden tahsis (reallocation) yapılmaz ve performans artar.

#### Örnek:

std::vector<int> vec;
vec.reserve(10);  // 10 eleman için kapasite ayır
std::cout << "Capacity: " << vec.capacity() << std::endl;  // Çıktı: 10

Bu örnekte, `vec.reserve(10)` ile `vec`'in kapasitesi 10 olarak ayarlanmıştır. Ancak şu anda içinde eleman yoktur, dolayısıyla `size` 0'dır.

### `size` ve `capacity` Arasındaki Fark

1. **`size`**:
   - Konteynerdeki mevcut eleman sayısını temsil eder.
   - Her zaman `capacity` değerinden küçük veya ona eşit olabilir.
   
2. **`capacity`**:
   - Konteynerin depolayabileceği maksimum eleman sayısını ifade eder.
   - Genellikle `size`'dan büyüktür, çünkü konteyner, yeniden tahsis maliyetlerini azaltmak için ek kapasite ayırır.
   - Eğer eklenen eleman sayısı `capacity`'yi aşarsa, konteyner otomatik olarak daha büyük bir bellek bloğu ayırarak kapasitesini artırır.

### `size` ve `capacity` Dinamik Değişimi

Konteyner eleman ekledikçe, `size` artar. Ancak `size`, `capacity`'yi aştığında, konteynerin kapasitesi yeniden tahsis edilir ve artırılır. 
Bu tahsis işlemi genellikle konteynerin kapasitesini katlayarak büyütür (genellikle 1.5x veya 2x).

#### Örnek:

std::vector<int> vec;
vec.push_back(1);  // Bir eleman ekliyoruz

std::cout << "Size: " << vec.size() << std::endl;       // Çıktı: 1
std::cout << "Capacity: " << vec.capacity() << std::endl;  // Capacity: Genelde 1 ya da daha fazla olabilir.

vec.push_back(2);
std::cout << "Size: " << vec.size() << std::endl;       // Çıktı: 2
std::cout << "Capacity: " << vec.capacity() << std::endl;  // Capacity: Yine büyüyebilir.

Bu örnekte, her `push_back` işlemiyle `size` artarken, `capacity` kapasite aşımında genişletilebilir.

### Özet

- **`size`**: Konteynerde şu anda kaç eleman bulunduğunu gösterir.
- **`capacity`**: Konteynerin şu anda yeniden tahsis (reallocation) yapılmadan kaç eleman depolayabileceğini gösterir.

Bu ayrım, belleğin verimli kullanılmasını ve performansın optimize edilmesini sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'daki `std::string::shrink_to_fit` metodu, bir `std::string` nesnesinin kapasitesini, o anki uzunluğuna (**size**) kadar düşürmek 
için kullanılır. Bu, dinamik bellek kullanımını optimize etmek amacıyla fazla ayrılmış bellek alanını serbest bırakır.

### **Kullanım Amaçları**
1. **Bellek Optimizasyonu**: Eğer bir `std::string` büyük bir kapasiteye sahipse ancak daha az bir boyut kullanılıyorsa, gereksiz bellek alanını azaltmak için `shrink_to_fit` kullanılır.
2. **Dinamik Bellek Yönetimi**: Büyük bir `std::string` üzerinde işlem yaptıktan sonra, kullanılmayan kapasiteyi temizlemek için idealdir.

### **Metodun Söz Dizimi**

void shrink_to_fit();

- Bu fonksiyon, çağrıldığı `std::string` nesnesinin kapasitesini o anki uzunluğuna eşitlemeye çalışır.
- Bellek, azaltılabilirse, bu işlem genellikle başarılı olur, ancak bu durum garanti edilmez (platforma ve standart kütüphaneye bağlıdır).

### **Örnek Kullanım**

#include <iostream>
#include <string>

int main() {
    std::string str = "C++ Programming";
    std::cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << '\n';

    // Kapasiteyi artırıyoruz.
    str.reserve(50);
    std::cout << "After reserve, Capacity: " << str.capacity() << '\n';

    // Kapasiteyi küçültüyoruz.
    str.shrink_to_fit();
    std::cout << "After shrink_to_fit, Capacity: " << str.capacity() << '\n';

    return 0;
}

#### **Çıktı**:

Size: 15, Capacity: 22
After reserve, Capacity: 50
After shrink_to_fit, Capacity: 15

### **Önemli Noktalar**
1. **Kapasite ve Boyut**:
   - `size`: String içindeki karakterlerin sayısını temsil eder.
   - `capacity`: String için ayrılmış toplam bellek miktarını temsil eder.
2. **`shrink_to_fit` Garantileri**:
   - Standart, `shrink_to_fit` metodunun bellek azaltmayı garanti etmediğini belirtir.
   - Bu durum, bellek ayırma stratejilerine bağlıdır ve bazı durumlarda `capacity`, `size` ile aynı kalmayabilir.

### **Bellek Yönetimi ile İlgili Diğer Metodlar**
1. **`std::string::reserve`**: Kapasiteyi belirli bir değere artırır.

   str.reserve(100); // Kapasiteyi en az 100 olacak şekilde artırır.

2. **`std::string::resize`**: Boyutu değiştirir, gerekirse karakter ekler veya siler.

   str.resize(10); // Boyutu 10 karaktere ayarlar.
 
### **Ne Zaman Kullanılır?**
- String üzerinde büyük miktarda veri işlendiğinde ve işlemden sonra kullanılmayan kapasitenin serbest bırakılması gerektiğinde.
- Özellikle bellek sınırlamaları olan veya yoğun bellek işlemleri yapılan projelerde.

### **Kısaca**
`std::string::shrink_to_fit`, bir `std::string` nesnesinin kapasitesini optimize etmek için kullanılan bir yöntemdir. Gereksiz bellek alanını 
azaltmak için etkili bir yöntem olmasına rağmen, başarısı garanti edilmez ve genellikle belleğin yönetiminden bağımsızdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'daki **`std::string_view`**, C++17 ile gelen bir sınıftır ve **kopyalama gerektirmeden bir `std::string` veya bir C tarzı string'e 
(null-terminated char array) bakış (view)** sağlamak için kullanılır. Bu, bir string'in içeriğine **performans açısından verimli bir şekilde erişim** sağlar.

### **`std::string_view` Ne İşe Yarar?**
- **Kopyalama yapmaz**: String'in bir kopyasını oluşturmak yerine, orijinal string'in bellekteki verisine referansla erişir.
- **Hafif ve hızlıdır**: Sadece bir pointer ve uzunluk (length) bilgisinden oluşur.
- **İmmutabledır (değiştirilemez)**: `std::string_view`'in temsil ettiği veriyi değiştiremezsiniz; yalnızca okuyabilirsiniz.
- **Çeşitli string türlerini destekler**: `std::string`, C tarzı string (`const char*`), veya diğer string-like nesnelere bir bakış sağlar.

### **Söz Dizimi**

#include <string_view>

std::string_view sv;

### **Temel Özellikleri**
1. **Kopyalamadan String Erişimi**:
   - String verisine hızlı erişim sağlar.
2. **Değiştirilemez**:
   - String içeriği değiştirilemez; sadece okunabilir.
3. **Geçici Stringler İçin Uygun Değil**:
   - `std::string_view`'in ömrü, işaret ettiği string'in ömrüne bağlıdır. Geçici bir string'in (`std::string` veya `char*`) ömrü dolarsa, `std::string_view` bozuk bir referans tutabilir.

### **Örnek Kullanım**
#### **`std::string` ile Kullanım**

#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv = str;

    std::cout << "String View: " << sv << '\n';
    std::cout << "Length: " << sv.size() << '\n';

    // İlk 5 karakteri alalım.
    std::cout << "First 5 chars: " << sv.substr(0, 5) << '\n';

    // str'nin içeriği değişirse, sv de değişir.
    str = "Goodbye!";
    std::cout << "Updated String View: " << sv << '\n';

    return 0;
}

#### **Çıktı**:

String View: Hello, World!
Length: 13
First 5 chars: Hello
Updated String View: Goodbye!

#### **C Tarzı String ile Kullanım**

#include <iostream>
#include <string_view>

int main() {
    const char* c_str = "C++ is awesome!";
    std::string_view sv = c_str;

    std::cout << "String View: " << sv << '\n';
    return 0;
}

### **Avantajları**
1. **Performans**: String'in kopyalanmasını önler, bu da özellikle büyük string'lerle çalışırken performans kazancı sağlar.
2. **Bellek Verimliliği**: Ekstra bellek tahsisi yapılmaz.
3. **Esneklik**: Hem `std::string` hem de C tarzı string'lerle çalışabilir.

### **Dezavantajları**
1. **Geçici String Sorunu**:
   - `std::string_view` bir geçici string'e bağlanırsa, string'in ömrü dolduğunda `string_view` bozulur.

   std::string_view sv = std::string("temporary"); // Hatalı kullanım
   std::cout << sv << '\n'; // Tanımsız davranış

2. **Değiştirilemezlik**:
   - `std::string_view` kullanarak string'in içeriğini değiştiremezsiniz. Eğer değişiklik gerekliyse, `std::string` kullanmanız gerekir.

### **Ne Zaman Kullanılır?**
1. **Kopyalamayı Önlemek**:
   - Büyük string'ler üzerinde sadece okuma işlemleri yapmak istediğinizde.
2. **API Tasarımı**:
   - Bir fonksiyonun hem `std::string` hem de `char*` almasını istiyorsanız, `std::string_view` daha iyi bir seçenek olabilir.
3. **Performans Öncelikli Durumlar**:
   - Hafif ve hızlı erişim gerektiren senaryolarda.

### **Kısaca**
`std::string_view`, string verisine verimli ve değiştirilemez bir şekilde erişim sağlamak için kullanılan hafif bir sınıftır. 
Ancak dikkatli kullanılması gerekir, özellikle string'in ömrüyle ilgili kısıtlamalar nedeniyle. Daha fazla performans ve esneklik için ideal bir araçtır.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Lookup Table (LUT)**, **önceden hesaplanmış değerlerin saklandığı bir veri yapısıdır**. Bir hesaplama veya işlem sırasında bu tabloya bakılarak 
hızlı bir şekilde sonuç alınır. Lookup tabloları genellikle zaman tasarrufu sağlamak veya sık yapılan hesaplamaları optimize etmek için kullanılır.

### **Lookup Table'ın Amacı**
- **Performans Artışı:** Hesaplama işlemini daha hızlı hale getirmek için kullanılır.
- **Yineleyen Hesaplamaların Önlenmesi:** Aynı işlemleri tekrar tekrar hesaplamak yerine, sonuçları bir tabloda saklar ve gerektiğinde bu tabloya başvurur.
- **Basitlik:** Karmaşık işlemleri daha kolay bir şekilde yönetir.

### **Nasıl Çalışır?**
1. Önceden belirli bir aralık için hesaplamalar yapılır ve bu değerler bir tabloda saklanır.
2. Program çalışırken, bir anahtar veya indeks kullanılarak bu tablodan değer alınır.
3. Böylece işlemin kendisi yerine doğrudan sonuca erişilir.

### **Örnek Kullanım Alanları**
1. **Matematiksel Hesaplamalar:**
   - Trigonometrik, logaritmik veya karekök gibi sık kullanılan fonksiyonlar için.

   // Örnek: Sinüs değerlerini saklayan bir lookup table
   double sinTable[360];
   for (int i = 0; i < 360; ++i) {
       sinTable[i] = sin(i * M_PI / 180.0); // Dereceden radyana çevirip sinüs hesaplar
   }
   double sin45 = sinTable[45]; // 45 derece için sinüs değeri doğrudan alınır

2. **Grafik Programlama:**
   - Renk dönüşümleri veya piksel değerlerini hızlandırmak için LUT kullanılır.
3. **Metin İşleme:**
   - Karakter eşlemeleri, frekans analizleri gibi işlemlerde.
4. **Kriptografi:**
   - Şifreleme veya çözme algoritmalarını hızlandırmak için.

5. **Oyun Geliştirme:**
   - Fizik motorlarında hareket veya çarpışma hesaplamaları için önceden hesaplanmış değerler.

### **Avantajları**
1. **Hız:** Karmaşık veya maliyetli işlemleri hızlı hale getirir.
2. **Basitlik:** Hesaplamaları bir diziye veya hash tablosuna indirger.
3. **Tekrar Kullanılabilirlik:** Aynı sonuçlar defalarca kullanılabilir.

### **Dezavantajları**
1. **Bellek Kullanımı:** Tablo boyutu çok büyükse, bellekte fazla yer kaplayabilir.
2. **Hassasiyet:** Bazı durumlarda, özellikle matematiksel işlemlerde, tablonun doğruluğu sınırlı olabilir.
3. **Statik Yapı:** Lookup tabloları genellikle sabit bir aralık için tasarlandığından, dinamik ihtiyaçlara uygun olmayabilir.

### **Basit Bir Lookup Table Örneği (C++):**

#include <iostream>
#include <cmath>

int main() {
    // 0-9 arasındaki sayıların karelerini tutan bir lookup table
    int squareTable[10];

    // Tabloyu doldur
    for (int i = 0; i < 10; ++i) {
        squareTable[i] = i * i;
    }

    // Kareyi hesaplamak yerine tablodan doğrudan alın
    int number = 7;
    std::cout << "Square of " << number << " is " << squareTable[number] << '\n';

    return 0;
}

#### **Çıktı:**

Square of 7 is 49

### **Sonuç**
Lookup Table, hız ve performans gerektiren durumlarda son derece faydalı bir yöntemdir. Ancak belleği etkili kullanmak için dikkatlice tasarlanması gerekir. 
Özellikle oyun motorlarında, grafik işleme ve matematiksel hesaplamalarda sıkça tercih edilir.
******************************************************************************************************************************

                                                                             ********* 23-DERS NOTLARI *********

Kalıtım-inheritance da is-a relationship ilişkisi var

Kalıtım alınacak sınıfın Complete type olması gerek
--------------------------------------------------------------------------------------------------------------------------------------------------
c++da 3 tane kalıtım tipi var

public inheritance(is-a relationship'i sağlayan public inheritancedır)

private inheritance(has-a relationship)

protected inheritance

kalıtımda public anahtar kelimesini kullanmazsak default olarak private inheritance olur

class Base{};

class Der : Base{} // private inherit edilir

structlarda ise public anahtar kelimesini yazmasak bile default olarak public inherit edilir
--------------------------------------------------------------------------------------------------------------------------------------------------
inheritanceda isim arama 

class Base
{
public:
    int x;
};

class Der : public Base
{
public:

    int x;
};

int main()
{
    Der myder;

    myder.x; // isim arama Der sınıfında başlar x Der classta olmasaydı Base classta ki x bulunur
               NOT:türemiş sınıf ile base classın aynı isimde değişkenleri olması sentaks hatasıda değil çünkü farklı scope
}
--------------------------------------------------------------------------------------------------------------------------------------------------    
class Base
{
public:
     void foo(double);

};

class Der : public Base
{
public:

    void foo(int);
};

int main()
{
    Der myder;

    myder.foo(3.4); // function overloading  olması için yok aynı scopeta olması lazım burda Base clas foo çağırılır
    myder.Base::foo(3.4); // bu şekildede direkt çağırabiliriz
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Sınıfların protected bölümü sadece miras alınan sınıf içinde erişilir

class Base
{
public:

    void func(int);

};

class Der : public Base
{
private:
    void func(double)

};

int main()
{
    Der myder;
    myder.func(12);// acces control hatası namelookup bir kere olur isim bulunur ve biter Der sınıfında aranır ve bulunur 
                    sonra accses control yapılır private olduğu için erişilemez
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Derived classtan Base classa implicit conversion var UP CASTING

Mercedes m;
Car* pcar = &m;

tam terside DOWN CASTING ama BASE classtan DERIVED classa implicit conversion yok tür dönüştürme operatörlerini kullanmamız gerek

Car mycar;
Mercedes* m = &mycar; // sentaks hatası

Mercedes* m = static_cast<Mercedes*>(&mycar); // geçerli
--------------------------------------------------------------------------------------------------------------------------------------------------
class Car
{

};

class Mercedes : public Car 
{

};

class Volvo : public Car 
{

};

int main()
{
    Mercedes m;
    Volvo v;

    Car* pcar = &v; // is-a relationship yani public kalıtımı olmasaydı sentaks hatası olurdu
}
--------------------------------------------------------------------------------------------------------------------------------------------------
class Base
{
public:
    void foo();
};

class Der : public Base
{

};

int main()
{
    Der myder;

    myder.foo();

}

derleyicinin burda ürettiği kod Class member funciton parametrelerinde gizli bir paramter(Base*) olduğu için 

Der'in içinde bir Base olduğu için Der classının içindeki Base'in adresini foo fonksiyonuna geçiyor ve Base'in foosu çağırılıyor
--------------------------------------------------------------------------------------------------------------------------------------------------
class A{};

class B : public A{};

class C : public B {};

C B den kalıtım yoluyla elde ediliyorsa B C nin direct base classı(doğrudan taban sınıf)
ama A C'NİN indirect base classı(dolaylı taban sınıf) 
--------------------------------------------------------------------------------------------------------------------------------------------------
inheritance & special member functions

Türemiş sınıfın nesnenin oluşması için önce Base nesnesinin hayata gelmesi gerekiyor
--------------------------------------------------------------------------------------------------------------------------------------------------
class Person
{
public:
    Person(const std::string& name, const std::string& surname);
};

class VipPerson : public Person
{
public:
    VipPerson(const std::string& name, const std::string& surname,int vipno) : Person(name,surname),m_vipNo(vipno){}

private:
    int m_vipNo;
};

Türemiş sınıfın herhangi bir constructorında base classın herhangi bir constructrını çağırabiliriz
--------------------------------------------------------------------------------------------------------------------------------------------------
class Base
{
public:
    Base() {std::cout<< "base default ctor\n"; }
    Base(const Base&) { std::cout << "base copy ctor\n"; }
};

class Der : public Base
{
public:


};

int main()
{
    Der d1; // base default ctor
    Der d2(d1); // base'in copy ctor çağırılır
}

derleyici her zaman base sınıf nesnesinin derived sınıfının copy ctorunu yazarken base sınıf nesnesini copy ctor ediyor

NOT:derived sınıfın copy ctrounu kendimiz yazıyorsak artık base sınıfın default contructorının değil copy constructorunun çağırılmasından biz sorumluyuz
base sınıfının copy constructorını çağrı yapmazsak derleyici base classın default construcotına çağır yapar

Der(const Der&) {} der'in içindeki base default construct edilmiş olur

eğer Der'in copy constructorını çağırmak istersek

Der(const Der& other) : Base(other) {} //UPCASTING

Aynı durum move constructor içinde geçerli
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:MIL Sentaksında yalnızca direct base classın constructorını çağırabiliriz

class A{
    public:
    A(int)
}

class B : public A
{
    public:
    B(int,int);
    B(int);
}

class C : public B
{
    public:
    //C(int x) : A(x) //sentaks hatası A burda indirect base class(dolaylı base class)
                        C'nin direct classı B sınıfı
}
--------------------------------------------------------------------------------------------------------------------------------------------------
İnheritanceda function overlaodingi sağlamak için

class Base
{
public: // protected olabilir
    void foo(int i ){}
};

class Der : public Base
{
public:
    void foo(double d){}

    void foo(int i)
    {
        Base::foo(i);
    }
};

öyle bir bildirim var ki base sınıf bir ismi derived sınıfın scop'uına enjekte ediyor ubu bildirim using anahtar kelimesi 

class Base
{
public: // protected olabilir
    void foo(int i ){}
};

class Der : public Base
{
public:
    using Base::foo; // böyle bir bildirim yaparsak base classtaki foo ismi sanki derived sınıfta bildirilmiş gibi derived
                        classın scopuna katılıyor türemiş sınıfın aynı fonksiyon isminde fonksiyonu olursa function overloading olur

     void foo(double d);  //function overloading                  
};

int main()
{
    Der myder;

    myder.foo(3.4);
    myder.foo(3);
}
--------------------------------------------------------------------------------------------------------------------------------------------------
**Object Slicing** (Nesnenin dilimlenmesi), C++ dilinde, bir **türetilmiş sınıf** (derived class) nesnesinin bir **taban sınıf** (base class) 
türüne atanması sırasında, türetilmiş sınıfa özgü üyelerin kaybolması durumudur. Bu durum genellikle sınıf nesneleri kopyalanırken veya bir 
fonksiyona argüman olarak geçirilirken ortaya çıkar.

### **Detaylı Açıklama**

1. **Neden Oluşur?**
   - Türetilmiş sınıflar, taban sınıfların tüm özelliklerini miras alır ve üzerine kendi üyelerini ekler.
   - Ancak, taban sınıf türüne kopyalama yapılırken, taban sınıfın bildiği kadar veri kopyalanır. Türetilmiş sınıfa özgü olan üyeler **"kesilir"** ve bu bilgiler kaybolur.

2. **Mekanizma:**
   - Taban sınıfın bir nesnesine, türetilmiş sınıf nesnesinin **bir kopyası** atanır.
   - Türetilmiş sınıfa ait üyeler ve davranışlar bu kopyaya dahil edilmez.

### **Örnek: Object Slicing**

#include <iostream>
#include <string>

class Base {
public:
    virtual void display() const {
        std::cout << "Base class\n";
    }
};

class Derived : public Base {
private:
    std::string extra_data;
public:
    Derived(const std::string& data) : extra_data(data) {}

    void display() const override {
        std::cout << "Derived class with data: " << extra_data << '\n';
    }
};

void printObject(Base obj) {
    obj.display(); // Slicing: only Base's part of the object is used
}

int main() {
    Derived d("Hello");
    printObject(d); // Object slicing occurs here
    return 0;
}

#### **Çıktı:**

Base class

### **Açıklama:**
1. `Derived` sınıfındaki `extra_data` üyesi ve `display` fonksiyonunun türetilmiş versiyonu, `Base` türüne kopyalandığında **kaybolur**.
2. `printObject` fonksiyonu `Base` türünde bir parametre alır, bu yüzden türetilmiş nesne "kesilir" ve sadece `Base` sınıfının bilgileri kullanılır.

### **Object Slicing'i Önlemek**
Object Slicing’i önlemek için aşağıdaki yaklaşımlar kullanılabilir:

1. **Pointer veya Referans Kullanımı:**
   - Taban sınıf türünde bir pointer veya referans kullanmak, türetilmiş sınıfa ait bilgilerin kaybolmasını engeller.

void printObject(const Base& obj) {
    obj.display(); // No slicing: virtual function mechanism works
}

#### **Çıktı (Yukarıdaki Örnek Güncellendi):**

Derived class with data: Hello

2. **Polymorphism (Çok Biçimlilik):**
   - Taban sınıfın sanal fonksiyonlar (virtual functions) içerdiğinden emin olun ve türetilmiş sınıflar bu fonksiyonları override etsin.

3. **Kopyalama Operatörünü (Copy Constructor) ve Atama Operatörünü (Assignment Operator) Yasaklama:**
   - Taban sınıfta kopyalama işlemlerini **`delete`** ederek nesne kesilmesini engelleyebilirsiniz:

class Base {
public:
    Base(const Base&) = delete;
    Base& operator=(const Base&) = delete;
    virtual ~Base() = default;
};

### **Neden Önemli?**

- **Beklenmeyen Davranışlar:** Türetilmiş sınıfın özelliklerinin kaybolması, beklenmeyen ve yanlış sonuçlara yol açabilir.
- **Polimorfizmin Kullanımı:** Polimorfizm, nesne kesilmesini önlemek için doğru tasarlanmış sanal fonksiyonlarla uygulanabilir.
- **Performans ve Güvenlik:** Doğru türde bir referans veya işaretçi kullanmak, kodun güvenliğini ve performansını artırır.

### **Sonuç**
**Object Slicing**, C++'ta türetilmiş sınıf nesnelerinin taban sınıf türüne kopyalanmasından kaynaklanan bir durumdur. Bu, genellikle veri kaybına 
ve beklenmedik davranışlara neden olur. Pointer, referans ve polimorfizmin doğru kullanımıyla nesne kesilmesi önlenebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
Code reuse (kod yeniden kullanımı), yazılım geliştirme sürecinde verimliliği artırmak, hata oranını düşürmek ve kodun bakımını 
kolaylaştırmak için kritik bir yaklaşımdır. 
--------------------------------------------------------------------------------------------------------------------------------------------------
**Inherited Constructors (Miras Alınan Yapıcılar) Nedir?**

C++11 ile tanıtılan **inherited constructors** (miras alınan yapıcılar), türetilmiş sınıfların (derived classes) taban sınıflarından (base classes) 
yapıcıları (constructors) otomatik olarak miras almasını sağlayan bir özelliktir. Bu özellik, özellikle türetilmiş sınıfların yapıcılarını 
manuel olarak tanımlamak zorunda kalmadan, taban sınıfın yapıcılarının kullanımını kolaylaştırır.

### Neden Kullanılır?

- **Kod Tekrarını Azaltır**: Türetilmiş sınıflarda, taban sınıfın yapıcılarını tekrar tekrar tanımlamak yerine, doğrudan miras alarak daha temiz ve bakımı kolay kod yazmayı sağlar.
- **Kullanım Kolaylığı**: Taban sınıfın mevcut yapıcılarını kullanarak türetilmiş sınıf nesnelerini kolayca oluşturmanıza olanak tanır.
- **Esneklik**: Farklı yapıcı parametrelerine sahip taban sınıf yapıcılarını kolayca türetilmiş sınıfta kullanabilirsiniz.

### Nasıl Kullanılır?

C++11'de, türetilmiş sınıfta `using` ifadesi kullanılarak taban sınıfın yapıcıları miras alınabilir.

#### Söz Dizimi:

class Derived : public Base {
public:
    using Base::Base; // Taban sınıfın yapıcılarını miras al
};

### Örneklerle Açıklama

#### Örnek 1: Basit Miras Alınan Yapıcılar

#include <iostream>
#include <string>

// Taban sınıf
class Base {
public:
    Base() {
        std::cout << "Base default constructor" << std::endl;
    }

    Base(int x) {
        std::cout << "Base parameterized constructor with x = " << x << std::endl;
    }
};

// Türetilmiş sınıf
class Derived : public Base {
public:
    using Base::Base; // Taban sınıfın yapıcılarını miras al

    void show() {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    Derived d1;        // Base'in default yapıcısı çağrılır
    Derived d2(10);    // Base'in parametreli yapıcısı çağrılır

    d1.show();
    d2.show();

    return 0;
}

**Çıktı:**

Base default constructor
Base parameterized constructor with x = 10
Derived class
Derived class

**Açıklama:**
- `Derived` sınıfı, `Base` sınıfının yapıcılarını `using Base::Base;` ifadesi ile miras alır.
- `Derived d1;` ifadesi, `Base` sınıfının varsayılan yapıcısını çağırır.
- `Derived d2(10);` ifadesi, `Base` sınıfının parametreli yapıcısını çağırır.
- Bu sayede, `Derived` sınıfında ekstra yapıcı tanımlamaya gerek kalmaz.

#### Örnek 2: Miras Alınan Yapıcıların Kullanımı ile Ek Üyelerin Başlatılması

Bazen, türetilmiş sınıfların kendi ek üyeleri olabilir ve bu üyeleri başlatmak için özel yapıcılara ihtiyaç duyabilirsiniz. 
Miras alınan yapıcılarla birlikte, bu ek üyeleri başlatmak için türetilmiş sınıfın yapıcılarını da tanımlayabilirsiniz.

#include <iostream>
#include <string>

// Taban sınıf
class Base {
public:
    Base() : baseValue(0) {
        std::cout << "Base default constructor, baseValue = " << baseValue << std::endl;
    }

    Base(int x) : baseValue(x) {
        std::cout << "Base parameterized constructor, baseValue = " << baseValue << std::endl;
    }

private:
    int baseValue;
};

// Türetilmiş sınıf
class Derived : public Base {
public:
    using Base::Base; // Taban sınıfın yapıcılarını miras al

    Derived() : extraValue(100) {
        std::cout << "Derived default constructor, extraValue = " << extraValue << std::endl;
    }

    Derived(int x, int y) : Base(x), extraValue(y) {
        std::cout << "Derived parameterized constructor, extraValue = " << extraValue << std::endl;
    }

private:
    int extraValue;
};

int main() {
    Derived d1;            // Türetilmiş sınıfın varsayılan yapıcısı
    Derived d2(20, 200);   // Türetilmiş sınıfın parametreli yapıcısı

    return 0;
}

**Çıktı:**

Base default constructor, baseValue = 0
Derived default constructor, extraValue = 100
Base parameterized constructor, baseValue = 20
Derived parameterized constructor, extraValue = 200

**Açıklama:**
- `Derived` sınıfı, `Base` sınıfının yapıcılarını miras alırken, kendi ek üyesi olan `extraValue`'yu başlatmak için kendi yapıcılarını tanımlar.
- `Derived d1;` ifadesi, `Base` sınıfının varsayılan yapıcısını çağırır ve ardından `Derived` sınıfının varsayılan yapıcısı `extraValue`'yu başlatır.
- `Derived d2(20, 200);` ifadesi, `Base` sınıfının parametreli yapıcısını çağırır ve ardından `Derived` sınıfının parametreli yapıcısı `extraValue`'yu başlatır.

### Dikkat Edilmesi Gerekenler

1. **Yapıcı Çakışmaları**: Eğer türetilmiş sınıfta miras alınan yapıcılarla aynı imzaya sahip bir yapıcı tanımlarsanız, miras alınan yapıcı gizlenir (hidden olur).
   
   class Derived : public Base {
   public:
       using Base::Base;

       Derived(int x) { // Bu yapıcı, Base'in aynı imzaya sahip yapıcısını gizler
           // ...
       }
   };

2. **Erişim Kontrolü**: Taban sınıfın yapıcılarının erişim belirleyicileri (public, protected, private) miras alınırken korunur. Örneğin, 
taban sınıftaki protected yapıcılar, türetilmiş sınıfta da protected olarak kalır.

3. **Varsayılan ve Silinmiş Yapıcılar**: Miras alınan yapıcılar, türetilmiş sınıfın diğer yapıcıları tarafından etkilenmez. Örneğin, 
türetilmiş sınıfta başka yapıcılar tanımlanmışsa, miras alınan yapıcıların otomatik olarak silinmesi (suppression) gibi bir durum söz konusu olmaz.

### Ekstra: C++20 ile Gelişmeler

C++20 ile birlikte **inherited constructors** (miras alınan yapıcılar) konusunda önemli gelişmeler yapılmıştır. Bu gelişmeler, kalıtım hiyerarşilerinde 
yapıcıların daha esnek ve kapsamlı bir şekilde miras alınmasını mümkün kılmıştır. Özellikle, `using` ifadesi ile miras alınan yapıcıların kontrolü artırılmış 
ve çeşitli yeni özellikler eklenmiştir. Aşağıda, C++20'deki bu gelişmelerin detaylı bir açıklaması ve örneklerle desteklenmiş kullanımları bulunmaktadır.

### C++20'de Inherited Constructors'ın Gelişmeleri

1. **Miras Alınan Yapıcıların Daha Esnek Kullanımı:**
   C++20 ile birlikte, `using` ifadesi ile miras alınan yapıcılar üzerinde daha fazla kontrol sağlanmıştır. Bu, türetilmiş sınıfların taban 
   sınıflardan miras aldıkları yapıcıları seçme ve bunları özelleştirme yeteneğini artırır.

2. **Yapıcıların İstisnai Durumlarla Baş Etmesi:**
   C++20, miras alınan yapıcıların istisna güvenliği ve diğer yapıcı özellikleri ile daha uyumlu olmasını sağlar. Bu, özellikle karmaşık kalıtım 
   hiyerarşilerinde yapıcıların doğru şekilde çalışmasını garanti eder.

3. **Şablon Yapıcılarla Entegrasyon:**
   Şablon (template) yapıcılar, C++20 ile birlikte miras alınan yapıcılar ile daha iyi entegre edilmiştir. Bu, şablon sınıflarında miras alınan yapıcıların daha kolay kullanılmasını sağlar.

### `using` İfadesi ile Miras Alınan Yapıcıların Kontrolü

`using` ifadesi, türetilmiş sınıfın taban sınıfından belirli yapıcıları miras almasını sağlar. C++20 ile birlikte, bu kullanım daha esnek hale gelmiştir 
ve türetilmiş sınıfın kendi ek üyelerini başlatmak için miras alınan yapıcılarla birlikte kullanılabilir.

#### Örnek 1: Basit Miras Alınan Yapıcılar

#include <iostream>
#include <string>

// Taban sınıf
class Base {
public:
    Base() {
        std::cout << "Base default constructor" << std::endl;
    }

    Base(int x) {
        std::cout << "Base parameterized constructor with x = " << x << std::endl;
    }
};

// Türetilmiş sınıf
class Derived : public Base {
public:
    using Base::Base; // Taban sınıfın yapıcılarını miras al

    void show() {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    Derived d1;        // Base'in default yapıcısı çağrılır
    Derived d2(10);    // Base'in parametreli yapıcısı çağrılır

    d1.show();
    d2.show();

    return 0;
}

**Çıktı:**

Base default constructor
Base parameterized constructor with x = 10
Derived class
Derived class

**Açıklama:**
- `Derived` sınıfı, `Base` sınıfının yapıcılarını `using Base::Base;` ifadesi ile miras alır.
- `Derived d1;` ifadesi, `Base` sınıfının varsayılan yapıcısını çağırır.
- `Derived d2(10);` ifadesi, `Base` sınıfının parametreli yapıcısını çağırır.
- Bu sayede, `Derived` sınıfında ekstra yapıcı tanımlamaya gerek kalmaz.

#### Örnek 2: Ek Üyeler ile Miras Alınan Yapıcılar

C++20'de, türetilmiş sınıfın kendi ek üyelerini başlatmak için miras alınan yapıcılarla birlikte özel yapıcılar tanımlanabilir.

#include <iostream>
#include <string>

// Taban sınıf
class Base {
public:
    Base() : baseValue(0) {
        std::cout << "Base default constructor, baseValue = " << baseValue << std::endl;
    }

    Base(int x) : baseValue(x) {
        std::cout << "Base parameterized constructor, baseValue = " << baseValue << std::endl;
    }

private:
    int baseValue;
};

// Türetilmiş sınıf
class Derived : public Base {
public:
    using Base::Base; // Taban sınıfın yapıcılarını miras al

    // Ek üye
    std::string extraValue;

    // Miras alınan yapıcıları genişletmek için özel yapıcılar
    Derived() : Base(), extraValue("Default") {
        std::cout << "Derived default constructor, extraValue = " << extraValue << std::endl;
    }

    Derived(int x, const std::string& y) : Base(x), extraValue(y) {
        std::cout << "Derived parameterized constructor, extraValue = " << extraValue << std::endl;
    }
};

int main() {
    Derived d1;                  // Türetilmiş sınıfın varsayılan yapıcısı
    Derived d2(20, "Extra");     // Türetilmiş sınıfın parametreli yapıcısı

    return 0;
}

**Çıktı:**

Base default constructor, baseValue = 0
Derived default constructor, extraValue = Default
Base parameterized constructor, baseValue = 20
Derived parameterized constructor, extraValue = Extra

**Açıklama:**
- `Derived` sınıfı, `Base` sınıfının yapıcılarını miras alırken kendi ek üyesi olan `extraValue`'yu başlatmak için kendi yapıcılarını tanımlar.
- `Derived d1;` ifadesi, `Base` sınıfının varsayılan yapıcısını çağırır ve ardından `Derived` sınıfının varsayılan yapıcısı `extraValue`'yu "Default" olarak başlatır.
- `Derived d2(20, "Extra");` ifadesi, `Base` sınıfının parametreli yapıcısını çağırır ve ardından `Derived` sınıfının parametreli yapıcısı `extraValue`'yu "Extra" olarak başlatır.

### C++20'de `using` İfadesi ile Gelişmiş Kontrol

C++20, `using` ifadesi ile miras alınan yapıcıların daha detaylı kontrol edilmesini sağlar. Özellikle, belirli yapıcıların devre dışı bırakılması veya özelleştirilmesi mümkün hale gelmiştir.

#### Örnek 3: Belirli Yapıcıların Gizlenmesi

Eğer türetilmiş sınıfın bazı miras alınan yapıcılarını gizlemek veya devre dışı bırakmak istiyorsanız, bu yapıcıları açıkça tanımlayabilirsiniz.

#include <iostream>

// Taban sınıf
class Base {
public:
    Base() {
        std::cout << "Base default constructor" << std::endl;
    }

    Base(int x) {
        std::cout << "Base parameterized constructor with x = " << x << std::endl;
    }
};

// Türetilmiş sınıf
class Derived : public Base {
public:
    using Base::Base; // Taban sınıfın yapıcılarını miras al

    // Bazı yapıcıları gizlemek
    Derived(int x) = delete; // Base'in int parametreli yapıcısını sil
};

int main() {
    Derived d1;        // Base'in default yapıcısı çağrılır
    // Derived d2(10); // Derleme hatası: Derived(int) silinmiş

    return 0;
}

**Açıklama:**
- `Derived` sınıfı, `Base` sınıfının yapıcılarını miras alır.
- Ancak, `Derived(int x)` yapıcısı `= delete;` ile silinir.
- Bu nedenle, `Derived d2(10);` ifadesi derleme hatası verecektir çünkü ilgili yapıcı silinmiştir.

#### Örnek 4: Şablon Yapıcılarla Entegrasyon

C++20'de, şablon yapıcılar ile miras alınan yapıcıların kullanımı daha entegre hale gelmiştir. Bu, türetilmiş sınıflarda şablon yapıcıları daha kolay kullanmanızı sağlar.

#include <iostream>
#include <string>

// Taban sınıf
class Base {
public:
    Base() {
        std::cout << "Base default constructor" << std::endl;
    }

    template <typename T>
    Base(T x) {
        std::cout << "Base templated constructor with x = " << x << std::endl;
    }
};

// Türetilmiş sınıf
class Derived : public Base {
public:
    using Base::Base; // Taban sınıfın yapıcılarını miras al

    // Ek üye
    std::string extraValue;

    // Miras alınan yapıcıları genişletmek için özel yapıcılar
    Derived() : Base(), extraValue("Default") {
        std::cout << "Derived default constructor, extraValue = " << extraValue << std::endl;
    }

    template <typename T>
    Derived(T x, const std::string& y) : Base(x), extraValue(y) {
        std::cout << "Derived templated constructor, extraValue = " << extraValue << std::endl;
    }
};

int main() {
    Derived d1;                  // Base'in default yapıcısı
    Derived d2(3.14, "Pi");      // Base'in templated yapıcısı (double)

    return 0;
}

**Çıktı:**

Base default constructor
Derived default constructor, extraValue = Default
Base templated constructor with x = 3.14
Derived templated constructor, extraValue = Pi

**Açıklama:**
- `Base` sınıfı, şablon yapıcıya sahiptir.
- `Derived` sınıfı, `using Base::Base;` ifadesi ile `Base` sınıfının şablon yapıcılarını miras alır.
- `Derived d2(3.14, "Pi");` ifadesi, `Base` sınıfının şablon yapıcısını çağırır ve ardından `Derived` sınıfının kendi şablon yapıcısı `extraValue`'yu "Pi" olarak başlatır.

### Dikkat Edilmesi Gerekenler

1. **Yapıcı Çakışmaları:**
   - Eğer türetilmiş sınıfta miras alınan yapıcılarla aynı imzaya sahip bir yapıcı tanımlarsanız, miras alınan yapıcı gizlenir.
   - Bu durum, istenmeyen yapıcıların devre dışı bırakılmasına yol açabilir.

   class Derived : public Base {
   public:
       using Base::Base;

       Derived(int x) { // Bu yapıcı, Base'in aynı imzaya sahip yapıcısını gizler
           // ...
       }
   };

2. **Erişim Kontrolü:**
   - Taban sınıfın yapıcılarının erişim belirleyicileri (public, protected, private) miras alınırken korunur.
   - Örneğin, taban sınıftaki protected yapıcılar, türetilmiş sınıfta da protected olarak kalır.

3. **Varsayılan ve Silinmiş Yapıcılar:**
   - Miras alınan yapıcılar, türetilmiş sınıfın diğer yapıcıları tarafından etkilenmez.
   - Türetilmiş sınıfta başka yapıcılar tanımlanmışsa, miras alınan yapıcıların otomatik olarak silinmesi (suppression) gibi bir durum söz konusu olmaz.

### Sonuç

Inherited constructors, C++11 ve sonraki standartlarda tanıtılan güçlü bir özelliktir. Türetilmiş sınıfların, taban sınıflarının yapıcılarını otomatik olarak
miras almasını sağlayarak kod tekrarını azaltır ve kodun bakımını kolaylaştırır. Ancak, yapıcı çakışmaları ve erişim kontrolü gibi konulara dikkat etmek önemlidir.
Doğru kullanıldığında, inherited constructors, C++ sınıf hiyerarşilerinde daha temiz ve etkili bir yapı oluşturmanıza yardımcı olur.

C++20 ile birlikte **inherited constructors**, kalıtım hiyerarşilerinde yapıcıların daha esnek ve kapsamlı bir şekilde miras alınmasını sağlar. 
`using` ifadesi ile miras alınan yapıcıların kontrolü artırılmış, şablon yapıcılarla entegrasyon geliştirilmiş ve yapıcı çakışmalarını önleme yöntemleri 
sunulmuştur. Bu gelişmeler, türetilmiş sınıfların daha temiz, bakımı kolay ve esnek bir şekilde oluşturulmasını mümkün kılar. Ancak, bu özellikleri 
kullanırken yapıcı çakışmaları ve erişim kontrolüne dikkat etmek önemlidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Structure Padding** (Yapı Dolgusu), C ve C++ gibi programlama dillerinde, bellek erişim performansını optimize etmek için yapı 
(structure) üyeleri arasına eklenen boşluklardır. Bu boşluklar, işlemcinin bellek erişim kurallarına (alignment rules) uygun hale getirmek için kullanılır.

### **Detaylı Anlatım**

1. **Bellek Alignment (Hizalama):**
   İşlemciler, bellekten veri okurken veya yazarken genellikle belirli sınırlarla hizalanmış adreslerde daha verimli çalışır. Örneğin, 4 baytlık bir veri (int), 4'e tam bölünebilen adreslerde daha hızlı okunabilir.

2. **Structure Padding:**
   - Yapıdaki üyeler, hizalama kurallarına göre sıralandığında aralarda boşluklar oluşabilir. Bu boşluklara "padding" denir.
   - Padding, yapı üyelerinin hizalama gereksinimlerini karşılamak için eklenir.

### **Örnek: Structure Padding**

#include <iostream>
struct Example {
    char a;  // 1 bayt
    int b;   // 4 bayt
    char c;  // 1 bayt
};

int main() {
    std::cout << "Size of struct: " << sizeof(Example) << '\n';
    return 0;
}

#### **Bellek Düzeni:**
| Byte | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   |
|------|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| Data | `a` | pad | pad | pad | `b` | `b` | `b` | `b` | `c` |

- `a`: 1 bayt alır.
- `b`: 4 bayt hizalaması gerektirir, bu yüzden `a`'dan sonra 3 bayt boşluk (padding) eklenir.
- `c`: 1 bayt alır, ama toplam boyut 4 baytın katı olmalıdır. Bu nedenle son 3 bayt dolgu eklenir.

#### **Çıktı:**

Size of struct: 12

### **Padding'in Amacı**
- **Performans:** İşlemcinin bellek okuma/yazma işlemlerini hızlandırmak.
- **Hizalama Gereksinimleri:** İşlemci mimarisine bağlı hizalama kurallarına uymak.

### **Padding'i Azaltmak İçin Yapı Sıralaması**

Yapıdaki üyelerin sırasını düzenleyerek padding miktarı azaltılabilir:

#include <iostream>
struct Optimized {
    int b;   // 4 bayt
    char a;  // 1 bayt
    char c;  // 1 bayt
};

int main() {
    std::cout << "Size of struct: " << sizeof(Optimized) << '\n';
    return 0;
}

#### **Bellek Düzeni:**
| Byte | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
|------|-----|-----|-----|-----|-----|-----|-----|-----|
| Data | `b` | `b` | `b` | `b` | `a` | `c` | pad | pad |

#### **Çıktı:**

Size of struct: 8

- Üyelerin sırası değiştirilerek padding azaltıldı.

### **Padding'i Kaldırma**

Padding'i tamamen kaldırmak için **`#pragma pack`** veya **`alignas`** gibi araçlar kullanılabilir. Ancak bu, performansı olumsuz etkileyebilir ve kullanılmadan önce dikkatle değerlendirilmelidir.

#### **Örnek: Pragma Pack**

#include <iostream>
#pragma pack(push, 1)
struct Packed {
    char a;
    int b;
    char c;
};
#pragma pack(pop)

int main() {
    std::cout << "Size of struct: " << sizeof(Packed) << '\n';
    return 0;
}

#### **Çıktı:**

Size of struct: 6

- Padding tamamen kaldırıldı, ancak bu işlem performans kaybına neden olabilir.

### **Sonuç**
Structure Padding, hizalama gereksinimlerini karşılamak ve bellek erişim performansını artırmak için otomatik olarak eklenir. 
Ancak, gerektiğinde yapının sırasını optimize ederek veya hizalamayı manuel kontrol ederek padding miktarı azaltılabilir.
Performans ve bellek kullanımı arasında bir denge sağlanması önemlidir.

Bu kod örneği, modern C++ (C++17 ve sonrası) özelliklerini kullanarak bir `std::map` üzerinde çalışmayı göstermektedir. Öne çıkan noktalar şunlardır:

### **1. `if` ile Başlatıcı (Initializer)**

if (auto[iter, inserted] = mymap.insert({"umut", "kotankiran"}); !inserted)
```
Bu ifade, bir **if initializer** ile birlikte **yapısal bağlama** (structural binding) kullanmaktadır:

- **`mymap.insert({"umut", "kotankiran"})`:**
  - `std::map`'in `insert` fonksiyonu çağrılır. Bu fonksiyon, bir `std::pair` döner:
    - İlk eleman (`iter`): Eklenecek öğenin iteratorudur.
    - İkinci eleman (`inserted`): Eklemenin başarılı olup olmadığını belirten bir `bool` değerdir.

- **`auto[iter, inserted]`:**
  - Yapısal bağlama kullanılarak `std::pair`'in elemanları ayrı değişkenlere atanır:
    - `iter`: Eklenecek veya mevcut öğenin iteratoru.
    - `inserted`: Eklemenin başarılı olup olmadığını kontrol eder.

- **`!inserted`:**
  - Eğer `inserted` `false` ise, ekleme başarısız olmuştur (örneğin, aynı anahtar zaten mevcut olduğu için).

### **2. `for` Döngüsü ve Yapısal Bağlama**

for (const auto&[name, surname] : mymap)

Bu döngü, `std::map`'in içindeki her bir öğeye erişmek için **range-based for loop** kullanır:

- **`auto&[name, surname]`:**
  - Her `std::pair` öğesi, iki elemanına (`key` ve `value`) doğrudan erişim sağlayacak şekilde çözümlenir:
    - `name`: `std::map`'in anahtarını (`key`) temsil eder.
    - `surname`: `std::map`'in değerini (`value`) temsil eder.

### **Kodun İşleyişi**
1. **Ekleme İşlemi:**
   - `"umut"` anahtarı ve `"kotankiran"` değeri ile bir çift eklenmeye çalışılır.
   - Eğer ekleme başarısız olursa (örneğin, `"umut"` zaten haritada varsa), hata mesajı yazdırılır.

2. **Tüm Öğeleri Dolaşma:**
   - `std::map`'in tüm öğeleri döngü ile dolaşılır ve her bir öğenin anahtar (`name`) ve değer (`surname`) bilgileri kullanılabilir.

### **Tam Kodun Çalışması:**

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> mymap;

    // Yeni bir öğe ekleme
    if (auto [iter, inserted] = mymap.insert({"umut", "kotankiran"}); !inserted) {
        std::cout << "Ekleme yapilamadi\n";
    }

    // Tüm öğeleri dolaşma
    for (const auto& [name, surname] : mymap) {
        std::cout << "Name: " << name << ", Surname: " << surname << '\n';
    }

    return 0;
}

#### **Örnek Çıktı:**
1. Eğer `"umut"` zaten haritada yoksa:
   Name: umut, Surname: kotankiran

2. Eğer `"umut"` haritada zaten varsa (başka bir yerde eklenmişse):

   Ekleme yapilamadi
   Name: umut, Surname: kotankiran

### **Özelliklerin Önemi**
- **Yapısal Bağlama (Structured Binding):**
  - `std::pair` veya benzeri veri yapılarının elemanlarına daha okunabilir şekilde erişim sağlar.

- **`if` ile Başlatıcı (If with Initializer):**
  - Bir değişkeni sadece bir kontrol bağlamında tanımlamak ve kullanmak için idealdir.

- **`std::map` ve Range-based Döngü:**
  - Haritanın anahtar ve değerlerini kolayca dolaşmayı sağlar.
******************************************************************************************************************************

                                                                             ********* 24-DERS NOTLARI *********

Base sınıfın member functiolnarını 3 kategoriye ayıracağız

1.kategori
derived sınıflara hem bir interface veren hemde implementasyon veren fonksiyonlar
bunlara concrete sınıflar denir(somut sınıflar)
void fly(){}

2.kategori
derived sınıflara hem bir interface veren hemde bir (default) implementasyon veren fonksiyonlar
base classın fly fonsiyonunu kullanmak istemezse kendi fly fonksiyonu override edebilir

bunlara polymorphic class denir

en az bir tane virtual fonksiyon varsa polymorphic class olma hakkını elde ediyor

virtual void fly(){} // virtual function

3.kategori
derived sınıflara sadece bir interface veren bir implementasyon vermeyen fonksiyonlar
derived class kendi classında pure virtuasl fonksiyonu override etmesi zorunludur

böyle sınıflara abstract class deniyor(soyut sınıflar)

virtual void fly() = 0 // pure virtual function

en az bir tane pure virtual fonksiyon varsa abstrac class olma hakkını elde ediyor

abstract classlardan nesne oluşturulamaz ama bu classların fonksiyonlarının override eden derived classlardan nesne oluşturabiliriz

Derived classın base classın virtual fonksiyonunu override etmesi için aynı parametreye ve aynı geri dönüş değerine
sahip olması gerek

class Base
{
    public:
    virtual void foo(int);
};

class Der : public Base
{
    public:
    void foo(double) // geri dönüş değeri aynı olduğu için sentaks hatası değil ama override değil
    int foo(int) // geri dönüş değeri farklı olduğu için sentaks hatası
}

Aynı imzaya sahip ama geri dönüş değeri farklı olmasını istiyorsak ve sentaks hatası olmamasını istiyorsak 
Covariant return types kullanılır
--------------------------------------------------------------------------------------------------------------------------------------------------
modern c++ ile dile eklenmiş 2 tane contextual keyword var

override 
final

int override = 5; // gerçek anlamda keyword olsaydı hata verirdi

anahtar sözcük olarak eklenmemesinin sebebi eski kodların kırılmasının önlenmesi
örneğin override adında bir fonksiyon olabilirdi 
--------------------------------------------------------------------------------------------------------------------------------------------------
override kelimesini yazmasakaa hala geçerli ama yazmamız en doğrusu çünkü kullanmazsak bazı sorunlar ortaya çıkabilir 

class Base
{
public:
    virtual void foo(int);
};

class Der : public Base
{
public:
    void foo(int); // override contextual keywordünü yazmazsak virtual functionun paramtere değeri değişirse bu override olmaktan çıkar
};

virtual void foo(int,int); // olduğu zaman Der classındaki foo fonksiyonu override olmaktan çıkar

eğer override contextual kwyeördünü kullansaydık derleyici hata vericekti ve kod legal olmicaktı

void foo(int) override; // derleyici hata verir ve parametre değerlerini int,int yapmamız gerekir

override sadece bildirimde olmak zorunda inline olarak tanımlanırsa zaten olması gerekir aynı yerde tanımlandığı için
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **contextual keyword** (bağlamsal anahtar kelime), dilin bazı özel durumlarında anahtar kelime gibi davranan, ancak genel 
kullanımda bir anahtar kelime olmayan sözcüklerdir. Bu tür anahtar kelimeler, belirli bağlamlarda anlam kazanır ve o bağlamda bir 
anahtar kelime gibi yorumlanır. Diğer bağlamlarda ise sıradan bir tanımlayıcı (identifier) olarak kullanılabilirler.

Örneğin, **`final`**, **`override`** ve **`import`** gibi sözcükler, C++’da bazı spesifik kullanımlara sahiptir. Ancak bunlar, 
belirli bir bağlam dışında kullanıldıklarında hata üretmezler.

### Örnekler:
1. **`override`**  
   - Sadece **virtual** fonksiyonları geçersiz kılarken anahtar kelime gibi davranır.
     
   class Base {
   public:
       virtual void func() {}
   };

   class Derived : public Base {
   public:
       void func() override {}  // override burada bağlamsal anahtar kelime
   };

   Başka bir bağlamda:

   int override = 5;  // Hata değil, burada override sıradan bir değişken adı

2. **`final`**  
   - Bir sınıf ya da sanal fonksiyonun artık türetilemeyeceğini belirtir.

   class MyClass final {};  // final burada bağlamsal anahtar kelime

   C++'da `final` anahtar kelimesi, belirli nesne yönelimli programlama davranışlarını kontrol etmek için kullanılır. 
   `final`, bir sınıfın veya yöntemlerin daha fazla türetilmesini veya geçersiz kılınmasını engeller. İşte `final` anahtar kelimesinin kullanıldığı yerler:

### 1. **Sınıf Düzeyinde Kullanımı**
`final`, bir sınıfın türetilmesine izin verilmediğini belirtmek için kullanılır. Bu durumda, sınıfın daha fazla alt sınıfı olamaz.

class Base final {
    // Sınıf içeriği
};

// Bu kod derleme hatası verecektir:
// class Derived : public Base {};

### 2. **Metod Düzeyinde Kullanımı**
`final`, bir sanal metodun daha fazla geçersiz kılınmasını engellemek için kullanılabilir. Böylece, o metot, türemiş sınıflar tarafından değiştirilemez.
yani override edilmesini istemediğimiz virtual fonksiyonu final contextual keywordü ile bildiririz

class Base {
public:
    virtual void show() final {
        // Metot içeriği
    }
};

class Derived : public Base {
public:
    // Bu kod derleme hatası verecektir:
    // void show() override {
    //     // Yeni içerik
    // }
};

### 3. **Performans Optimizasyonu**
`final`, derleyiciye belirli optimizasyonlar yapma imkanı verir. Çünkü derleyici, `final` olarak işaretlenmiş sınıf ve metodların belirli kalıplarda kullanılacağını 
bildiğinden, daha etkili kod üretebilir

### 4. **Polimorfizm ve Tasarım Kalıpları**
`final` anahtar kelimesinin kullanılması, tasarım kalıplarında belirli davranışların tutarlılığını sağlamaya yardımcı olur. Örneğin, bir strateji deseni uygularken, 
belirli stratejilerin daha fazla değiştirilmesini istemeyebilirsiniz

### Sonuç
`final` anahtar kelimesi, C++ programcılarına sınıf ve metot düzeyinde türetme ve geçersiz kılma üzerinde tam kontrol sağlar. 
Bu, kodun güvenliğini ve tutarlılığını artırır. 

3. **`import`** (C++20 ile geldi)  
   - Modüllerle çalışırken kullanılır.

   import std.core;

4. **`co_await`**, **`co_yield`**, **`co_return`** (C++20 coroutine desteği ile)  
   - Coroutines bağlamında kullanıldıklarında anahtar kelime gibi davranırlar.

### Özet
Bağlamsal anahtar kelimeler, kodun okunabilirlni artırmak için C++’a ekleiğinmiş olup yalnızca ilgili bağlamlarda anlam kazanır. 
Bu yaklaşım sayesinde C++ diline yeni işlevler eklenirken eski kodlarla uyum korunmuş olur, çünkü bu tür sözcükler her durumda anahtar kelime gibi davranmaz.
--------------------------------------------------------------------------------------------------------------------------------------------------
bir fonksiyon çağrısı karlışığı hangi fonksiyonun çağrılacağı hangi fonksiyona bağlanacağını 2 farklı şekilde anlaşılır

static binding / early binding(erken bağlama compile timeda bağlanır)
dynamic binding / late binding(geç bağlama run timeda bağlanır) run time polymoprhism
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **virtual dispatch** (sanal gönderim), bir sanal fonksiyonun hangi sürümünün çalıştırılacağını **çalışma zamanında** 
belirleyen bir mekanizmadır. Eğer bir temel sınıfta (base class) tanımlanan fonksiyon **virtual** olarak işaretlenmişse, 
türetilmiş sınıf (derived class) bu fonksiyonu **override** ederek yeniden tanımlayabilir. Bu durumda, fonksiyon bir **base class pointer'ı** 
veya **referansı** üzerinden çağrılsa bile, çalışma zamanında gerçek nesnenin türüne uygun fonksiyon çalıştırılır.

### Nasıl Çalışır?
Bu işlem, her sınıf için oluşturulan bir **vtable** (sanal tablo) ve her nesnede bulunan bir **vptr** (sanal tablo göstericisi) ile gerçekleştirilir. 
Vtable, sınıfa ait sanal fonksiyonların adreslerini içerir, vptr ise her nesnenin doğru sanal tabloya işaret etmesini sağlar. 

### Örnek:  

class Base {
public:
    virtual void foo() { std::cout << "Base foo\n"; }
};

class Derived : public Base {
public:
    void foo() override { std::cout << "Derived foo\n"; }
};

int main() {
    Base* b = new Derived();
    b->foo();  // Çıktı: Derived foo (virtual dispatch sayesinde)
    delete b;
}

Yukarıdaki örnekte, `b` işaretçisi `Base*` türünde olmasına rağmen, çalışma zamanında `Derived::foo()` fonksiyonu çağrılır. Çünkü **virtual dispatch**, 
nesnenin gerçek türünü kullanarak doğru fonksiyonu çalıştırır. Eğer `virtual` anahtar kelimesi kullanılmasaydı, temel sınıfın fonksiyonu (`Base::foo`) çağrılacaktı.  

### Performans Etkisi
Virtual dispatch, bir miktar performans maliyeti getirir; çünkü fonksiyon çağrıları doğrudan değil, sanal tablo üzerinden yönlendirilir. Ancak bu mekanizma, 
C++ dilinde **polimorfizm** sağlamak için gereklidir ve nesne yönelimli programlamanın temel taşlarından biridir.
--------------------------------------------------------------------------------------------------------------------------------------------------
virtual dispatch devreye girdiği ve girmediği senaryolar

virtual dispatccin devreye girmesi için fonksiyon çağrısının base class pointerı yada referansı ile yapılması gerekiyor

bir fonksiyonun paramtresi base class türünden bir pointer yada referans ise void foo(Base *p) sanal fonksiyonlara çağrı
virtual dispatch mekanizmasıyla ele alınacak

DİKKAT:virtual distpachın devereye girdiği olası ve üretimde çok sık karışmıza çıkan bir senaryo daha var
base classın virtual olmayan bir fonksiyonunu düşünelim

classların non-static fonksiyonlarında olan gizli parametre değeri sayesinde virtual fonksiyonları çağırabiliriz

class Car
{
    public:
    virtual void start();
    virtual void run();
    virtual void stop();
    void test() // Car* gizli parametre olduğu için virtual dispatch yine sağlanır
    {
        start();
        run();
        stop();
    }
}

Çağrıları base classı niteleyerek yaparsak virtual dispatch mekanizması devreye girmiyor

    void test() 
    {
        Car::start();
        Car::run();
        Car::stop();
    }
}

bazı durumlarda önce taban sınıfın virtual fonksiyonunun çağırılması ondan sonra derived classın virtual fonksiyonunun çağırılması gerekebilir
böyle durumlarda bu mekanizma kullanılır

sanallığın devreye girmediği en önemli durum object slicing

Merceded m;
Car mycar = m;

mycar.start(); // Car sınıfının startı çalışır Base classtan bir nesneye derived classtan bir nesneyi atadığımız zaman virtual dispatch
devreye girmiyor
--------------------------------------------------------------------------------------------------------------------------------------------------
Base classın virtual fonksiyonunu override eden derived class fonksiyonunda virtual keywordü kullanılmasa da virtual functiondır

class Base
{
public:
    virtual void foo() { std::cout << "Base::foo()\n"; } // virtual function

};

class Der : public Base
{
public:
     void foo() override { std::cout << "Der::foo()\n"; } // virtual function

};

class SDer : public Der
{
public:
     void foo() override { std::cout << "SDer::foo()\n"; } // virtual function

};

hepsi polymorphic class
--------------------------------------------------------------------------------------------------------------------------------------------------
overrida ederken public bölümde yada  private bölümde override olması farketmiyor

class Base
{
public:
    virtual void foo() { std::cout << "Base::foo()\n"; }

};

class Der : public Base
{
private:
    void foo() override { std::cout << "Der::foo()\n"; } 

};

void func(Base* ptr)
{
    ptr->foo(); // foo base sınıfının private bölümünde olsaydı burda access controle takılırdı sentaks hatası olurdu
}

int main()
{
    Der myder;

    func(&myder); // legal çünkü virtual dispatch devreye girer ve accces controlüne takılmaz çünkü  run time ile alakası yoktur
                    tamamen static binding(early binding) ile alakalıdır

    myder.foo() // bu şekilde çağırsaydık access controlden dolayı sentaks hatası olurdu
}

Taban sınıfın fonksiyonu private olursa yine override edilebilir
--------------------------------------------------------------------------------------------------------------------------------------------------
static type vs dynamic type

void car_game(Car* p)
{
    compile timeda isim arama Car türüne göre static binding yapılacak 
    ama Car polymoprhic bir sınıfsa isim arama tüm polymorhpic sınıflar arasında dynamic binding yapılacak
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Default argümanın run time ile bir alakası yoktur compile time ile alakası vardır

### Varsayılan Argümanların Kuralı:
- **Varsayılan argümanlar, çağrıyı yapan bağlamda belirlenir.**
- Bu, sanal bir işlev çağrılırken, varsayılan argümanların işlevin **çağrıldığı sınıfın türüne göre değil, işaretçi veya referans türüne göre** belirlenmesi anlamına gelir.

### Kod Analizi:

class Base {
public:
    virtual void foo(int x = 5) { // Varsayılan argüman x = 5
        std::cout << "Base::foo() x = " << x << '\n';
    }
};

class Der : public Base {
public:
    void foo(int x = 77) override { // Varsayılan argüman x = 77
        std::cout << "Der::foo() x = " << x << '\n';
    }
};

int main() {
    Der myder; // Türetilmiş sınıf nesnesi
    Base* baseptr = &myder; // Türetilmiş sınıfın adresi temel sınıf işaretçisine atanıyor

    baseptr->foo(); // Sanal işlev çağrısı
}

### Çıktı:

Der::foo() x = 5

### Neden Varsayılan Argüman 5 Kullanılıyor?
1. `baseptr` türü `Base*` olduğundan, **varsayılan argüman değeri** `Base` sınıfındaki `foo` işlevinden alınır.
2. Sanal işlev çağrısı nedeniyle `Der::foo` işlevi çağrılır, ancak varsayılan argüman değeri `Base::foo`'dan alınır.

### Varsayılan Argümanlar ile Sanal İşlevler Arasındaki Çakışma:
- Varsayılan argümanlar **derleme zamanında** belirlenir.
- Sanal işlevler **çalışma zamanında** çözümlenir.
- Bu nedenle, `baseptr->foo()` çağrısı `Der::foo`'yu çalıştırır, ancak varsayılan argüman `Base::foo`'dan alınır.

### Çözüm:
Varsayılan argümanlarla çalışırken bu karışıklıklardan kaçınmak için **varsayılan argümanları sanal işlevlerde kullanmaktan kaçınmak** 
iyi bir uygulamadır. Bunun yerine, her zaman argümanları açıkça geçmek daha iyi bir tasarım sağlar:

baseptr->foo(77); // Varsayılan argüman yerine açıkça belirtiliyor
--------------------------------------------------------------------------------------------------------------------------------------------------
**Devirtualization** (devirtualizasyon), C++’da sanal fonksiyon çağrılarının maliyetini düşürmek veya tamamen ortadan kaldırmak için kullanılan 
bir optimizasyon tekniğidir. Sanal fonksiyonlar, **vtable** (sanal tablo) üzerinden çağrıldığından her çağrı ekstra maliyet getirir. Devirtualizasyon 
ile, sanal çağrılar mümkün olduğunca **doğrudan çağrılara veya inline fonksiyonlara** dönüştürülerek performans iyileştirilir.

### Devirtualizasyon Nasıl Çalışır?

1. **Spekülatif Devirtualizasyon**: Derleyici, bir sanal fonksiyonun neredeyse her zaman aynı türetilmiş sınıf tarafından kullanılacağını varsayar. 
Bu durumda, fonksiyon **inline** hale getirilir ve vtable araması devre dışı bırakılır. Yanlış tahmin edilirse, yine de sanal tablo üzerinden normal çağrı yapılabilir.

2. **`final` Anahtar Kelimesinin Kullanımı**: Bir sanal fonksiyon veya sınıf **`final`** olarak işaretlendiğinde, daha fazla override yapılmayacağını 
garanti eder. Bu bilgi, derleyicinin sanal çağrıyı tamamen kaldırmasına olanak tanır.

3. **Link-Time ve Whole-Program Optimization (LTO/WPO)**: Derleyici, programın tamamını derleme sırasında analiz eder. Bir sanal fonksiyonun yalnızca 
tek bir uygulamasının var olduğu belirlenirse, sanal çağrılar doğrudan çağrılara dönüştürülür.

### Devirtualizasyonun Faydaları  
- **Çağrı Maliyetini Azaltır**: Vtable üzerinden dolaylı çağrıları önleyerek performansı artırır.  
- **Daha Fazla Inline Fırsatı**: Devirtualize edilen fonksiyonlar derleyici tarafından inline hale getirilebilir, bu da dallanmaları azaltır ve önbellek performansını artırır.

### Zorluklar  
Devirtualizasyon her zaman uygulanamaz. Özellikle, nesne türünün yalnızca çalışma zamanında belirlendiği durumlarda sanal çağrılardan kaçınmak zordur. 
Ancak **spekülatif devirtualizasyon** gibi teknikler, bu sınırlamaları kısmen aşar

Aşağıda **devirtualization** (devirtualizasyon) optimizasyonuna yönelik bir örnek sunulmaktadır. 
Bu örnek, sanal fonksiyon çağrısının nasıl doğrudan çağrıya dönüştürülebileceğini göstermektedir.

### Kod Örneği:

#include <iostream>

class Base {
public:
    virtual void foo() { std::cout << "Base::foo()\n"; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo()\n"; }
};

void call_foo(Base* obj) {
    obj->foo();  // Sanal çağrı (virtual dispatch)
}

int main() {
    Derived d;
    call_foo(&d);  // Çıktı: Derived::foo()
    return 0;
}

### Normal Çalışma
Bu kodda, `call_foo` fonksiyonu `Base*` türündeki bir işaretçi üzerinden `foo()` fonksiyonunu çağırır. Derleyici bu fonksiyon çağrısını, çalışma zamanında **vtable** 
kullanarak çözümleyecektir. Ancak her çağrıda vtable üzerinden yönlendirme yapıldığından performans maliyeti oluşur.

### Devirtualization ile Optimizasyon
Eğer `Base::foo()` fonksiyonunu **override** eden tek sınıf `Derived` ise ve bu fonksiyon daha fazla türetilmeyecekse, 
derleyici **devirtualizasyon** uygulayarak sanal çağrıyı doğrudan çağrıya dönüştürebilir.

#### Optimizasyon için Kod Güncellemesi:

class Derived final : public Base {  // final: Daha fazla türetilmeyecek
public:
    void foo() override { std::cout << "Derived::foo()\n"; }
};

Bu durumda, derleyici sanal tabloyu kullanmadan, `Derived::foo()` çağrısını doğrudan yapabilir. Bu optimizasyon sayesinde fonksiyon çağrı maliyeti azalır ve performans artar.

### Devirtualizasyonun Kullanımı
Bu tür optimizasyonlar, derleyicinin **LTO (Link-Time Optimization)** veya **Whole-Program Optimization** yapmasıyla daha etkili hale gelir. 
Derleyici, programın tamamını analiz ederek, sanal çağrıların gereksiz olduğu durumları belirleyip doğrudan çağrılara dönüştürebilir
--------------------------------------------------------------------------------------------------------------------------------------------------
DİKKAT:Constructor içinde yapılan virtual fonksiyonlara çağrıda virtual dispatch mekanizması devreye girmez çünkü
devreye girseydi felaket olurdu çünkü derived class nesnesi programın akışı derived clasın constructorının kodunu tammaladığı zaman
oysa derived class nesnesi önce base sınıf hayat geliyor ondan sonra memberlar hayat geliyor ondan sonra constructırın ana bloğundaki kod çalıştırılıyor

hayata gekmemiş derived class nesnesi için bir fonksiyon çağrısı yapmış olurduk ve bu run time hatasına maruz kalmak demek

Destructorda da yapılan virtual fonksiyon çağrılarında virtual dispatch devreye girmez 
çünkü nesnesinn hayatı zaten bitmiş

virtual dispatch mekanizmasının devreye girmediği senaryolara kısa özet

1.virtual sanal fonksiyon çağrısı base class nesnesiyle yapılırsa(pointer ve referans olmayan)

2.base classın virtual fonksiyonu nitelenerek çağırılıması Base::foo();

3.base classın fonstructorı içerisinde sanal fonksiyona çağrı yapılmışsa ve destructorı içinde çağrı yapılmışsa
--------------------------------------------------------------------------------------------------------------------------------------------------
Sınıfa bir virtual fonksiyon eklediğimizde sizeof değeri artar ama sadece bir tanesi için
3 4 tanede virtual fonksiyon olsa onlar için sizeof değeri yine aynıdır
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'da **Virtual Constructor Idiom**, polimorfik bir sınıf hiyerarşisi içinde, çalışma zamanında doğru türetilmiş sınıfın nesnesini oluşturmak için 
kullanılan bir desendir. C++'ta doğrudan sanal bir kurucu yoktur, ancak bu idiom, sanal işlevler ve yardımcı nesne oluşturma teknikleriyle bu davranışı taklit eder.
### **Problem:**
- C++'ta bir sınıfın kurucuları sanal değildir. Bu, türetilmiş bir sınıfın nesnesini, temel sınıfın bir işaretçisi veya referansı aracılığıyla doğrudan oluşturmayı imkânsız hale getirir.

### **Çözüm:**
Bu problemi çözmek için aşağıdaki yaklaşımlar kullanılır:

1. **Sanal Clone (Kopyalama):**
   - Bir temel sınıfta sanal bir `clone()` işlevi tanımlanır ve türetilmiş sınıflar bu işlevi aşırı yükler. Bu yöntem, çalışma 
   zamanında dinamik türü belirlemek ve doğru nesneyi oluşturmak için kullanılır.

2. **Nesne Üretim Fonksiyonları:**
   - Bir fabrika metodu veya statik bir yaratıcı fonksiyon, doğru türetilmiş sınıfın nesnesini oluşturur.

### **Örnek 1: Virtual Clone**

#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() = default;

    // Sanal clone metodu
    virtual std::unique_ptr<Base> clone() const = 0;

    virtual void display() const {
        std::cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    std::unique_ptr<Base> clone() const override {
        return std::make_unique<Derived>(*this);
    }

    void display() const override {
        std::cout << "Derived class\n";
    }
};

int main() {
    std::unique_ptr<Base> base = std::make_unique<Derived>(); // Türetilmiş nesne
    std::unique_ptr<Base> copy = base->clone();              // Sanal constructor benzeri davranış

    base->display();
    copy->display();
}

#### **Çıktı:**

Derived class
Derived class

Bu kodda:
- `clone()` işlevi, çalışma zamanında doğru türetilmiş sınıfın bir kopyasını oluşturur.

### **Örnek 2: Factory Method**

#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() = default;

    // Sanal fabrika metodu
    static std::unique_ptr<Base> create();

    virtual void display() const {
        std::cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived class\n";
    }
};

// Temel sınıfın fabrika metodunun tanımı
std::unique_ptr<Base> Base::create() {
    return std::make_unique<Derived>();
}

int main() {
    std::unique_ptr<Base> obj = Base::create(); // Fabrika metodu ile nesne oluşturma
    obj->display();
}

#### **Çıktı:**

Derived class

Bu kodda:
- `Base::create()` metodu, doğru türetilmiş sınıfın nesnesini oluşturur ve döner.

### **Avantajlar:**
- Çalışma zamanında doğru türetilmiş sınıfın nesnesini oluşturmayı sağlar.
- Polimorfizmin avantajlarından yararlanır.
- `clone()` yaklaşımı, kopyalama semantiği gerektiğinde faydalıdır.
- Fabrika metodu, farklı yapılandırma parametreleriyle nesne oluşturmayı sağlar.

### **Dezavantajlar:**
- Ekstra bellek ve performans maliyeti olabilir.
- Daha fazla kod karmaşıklığı ve bakım gerektirir.
- Doğru kullanım için tasarım desenlerinin iyi anlaşılması gerekir.

### **C++20 ile İlgili Gelişmeler:**
- C++20'nin **concepts** ve **std::any** gibi özellikleri, tür güvenliğini artırarak bu idiyomun uygulanmasını daha açık hale getirebilir. 
Ancak sanal kurucuların doğrudan desteği hâlâ yoktur.
******************************************************************************************************************************

                                                                             ********* 25-DERS NOTLARI *********

class içinde virtual keywordü ile fonksiyonu tanımladığımızda sizeof değeri artar bu artan değer sınıf içine  bir pointer gömülüyor
virtual function table pointer(vtable)

derleyici kalıtım hiyerarşisindeki her class için run-timeda bir veri yapısı oluşturuyor(vtable)
nasıl bir verei yapısı olduğu tamamen derleyiciye bağlı

vtable indeksle fonksiyon adreslerine erişebileceğimiz bir veri yapısı
her bir sınıf için oluşturulan vtable'ın aynı indeksinde aynı virtual fonksiyon adresi var

her sınıf nesnesinin içinde bir vptr var 
ama vtable her sınıf için var

derleyici compile timeda virtual fonksiyon çağrısını anlıyor bunun için compile timeda tablodaki indeksi elde edebilir

carptr->vptr[idx]() derleyicinin yaptığı bu vptrye ulaşıp o indeksi elde etmek 

MALİYET

İşlemsel maliyet

2 dereferencing 
sınıf nesnesinin içindeki vptrye erişim 
pointer yoluyla tablodaki belirli indeksindeki fonksiyon adresine erişim

kullanılan bellek alanı maliyeti

sanal fonksiyon tablolarının oluşturulması maliyeti

her polimorfik nesne için vptr'ın initialize edilmesi maliywti

DİKKAT:Büyük çoğunlukla virtual dispatch dinamik ömürlü nesneleri gerektiriyor
--------------------------------------------------------------------------------------------------------------------------------------------------
**RTTI (Run-Time Type Information)**, C++ dilinde nesnelerin türünü **çalışma zamanında** belirlemek için kullanılan bir mekanizmadır. 
Bu özellik, özellikle **polimorfik sınıflar** kullanıldığında (yani bir temel sınıfın türemiş sınıf referansları veya işaretçileriyle kullanılması durumunda) nesnenin gerçek türünü tespit etmeyi sağlar.

### RTTI'nin Bileşenleri  
1. **`typeid` Operatörü**: Bir nesnenin çalışma zamanındaki türünü belirlemek için kullanılır.  
   - `typeid` operatörü, bir nesne veya bir referansın tür bilgilerini sağlar ve `std::type_info` nesnesini döndürür.

   #include <iostream>
   #include <typeinfo>

   class Base {};
   class Derived : public Base {};

   int main() {
       Base* obj = new Derived();
       std::cout << typeid(*obj).name() << std::endl;  // Derived türü
   }
   
2. **`dynamic_cast` Operatörü**: Bir temel sınıf işaretçisini veya referansını, uygun türemiş sınıf türüne dönüştürmek için kullanılır. 
Dönüştürme başarısız olursa işaretçi için `nullptr` döner, referans içinse bir `std::bad_cast` istisnası fırlatılır.

   Derived* d = dynamic_cast<Derived*>(basePtr); // down casting
   if (d) {
       std::cout << "Successful cast!" << std::endl;
   } else {
       std::cout << "Failed cast." << std::endl;
   }

### RTTI'nin Kullanım Alanları  
- **Polimorfik Nesnelerle Çalışma**: `dynamic_cast` kullanarak doğru türde nesnelerle işlem yapmayı sağlamak.  
- **Hata Ayıklama**: `typeid` ile nesne türlerini çalışma zamanında kontrol etmek.  
- **Genişletilebilir Sistemler**: Belirli türleri çalışma zamanında seçerek modüler yapıdaki sistemlerde işlemler yapmak.

### Dezavantajlar  
- **Performans Maliyeti**: RTTI, çalışma zamanında ek maliyet getirir. Özellikle büyük sistemlerde sık kullanıldığında performans sorunlarına yol açabilir.  
- **Tasarım Karmaşıklığı**: RTTI, iyi tasarlanmamış kodlarda çok fazla kullanılırsa kodun anlaşılmasını zorlaştırabilir. Genellikle, doğru polimorfik tasarımlar RTTI kullanımına gerek bırakmaz.

RTTI, yalnızca **en az bir sanal fonksiyon** içeren sınıflar için etkin hale gelir. Dolayısıyla, RTTI kullanan sınıfların ya doğrudan ya da dolaylı olarak sanal fonksiyonları bulunmalıdır
--------------------------------------------------------------------------------------------------------------------------------------------------
*Covariant Return Types** C++ dilinde, türemiş sınıfların sanal fonksiyonlarının dönüş türünün, temel sınıftaki sanal fonksiyonun 
dönüş türünden **daha spesifik** olmasına izin veren bir özelliktir. Bu özellik sayesinde, bir türemiş sınıfın sanal fonksiyonu, 
temel sınıfta yer alan fonksiyonu yeniden tanımlarken (override) daha özelleşmiş bir dönüş türü kullanabilir.

### Covariant Return Types'ın Tanımı

Temel bir sanal fonksiyonun türemiş sınıf içinde yeniden tanımlanırken, aynı dönüş türü yerine **türemiş bir tür** döndürülmesine izin verilir. 
C++’da **covariant return type** desteği, polimorfizmi daha esnek hale getirir.

#### Örnek:

#include <iostream>

class Base {
public:
    virtual Base* clone() const {
        return new Base(*this);
    }
};

class Derived : public Base {
public:
    // Dönüş türü Base* yerine Derived*
    Derived* clone() const override {
        return new Derived(*this);
    }
};

int main() {
    Derived d;
    Base* b = d.clone();  // Derived nesnesi kopyalandı.
    std::cout << "Clone işlemi tamamlandı." << std::endl;
    delete b;
}

### Covariance’ın Sağladığı Avantajlar
- **Daha Anlamlı Dönüş Türleri**: Türemiş sınıf, kendisine özgü bir dönüş türü döndürdüğü için kullanım daha güvenlidir. Örneğin, `Derived*` 
türüne dönüş yapan fonksiyon, çağrıldığında doğrudan türemiş sınıfa erişim sağlar ve gereksiz `dynamic_cast` işlemlerini önler.
- **Override Esnekliği**: Temel sınıftaki sanal fonksiyon, daha genel bir tür döndürürken; türemiş sınıf, daha özelleşmiş bir tür döndürebilir.

### Kurallar
- Covariant dönüş türleri sadece **işaretçi veya referans** türlerinde geçerlidir.  
- Türemiş sınıfın dönüş türü, temel sınıftaki dönüş türüyle uyumlu olmalıdır, yani türemiş tür, temel türe dönüştürülebilir olmalıdır (yani "is-a" ilişkisi olmalıdır).

Bu özellik, C++’da tasarımı daha esnek hale getirir ve özellikle **virtual constructor idiom** gibi kalıplarla birlikte kullanıldığında oldukça kullanışlıdır
--------------------------------------------------------------------------------------------------------------------------------------------------
Base* baseptr = new Der;

baseptr->foo();

delete baseptr; // UB

çünkü burda compile timeda baseptr'nin türü Base* olduğu için derleyici Base sınıfının destructorını çağırıcak
aslında burda Der'in dstructorıı çağırılması gerekiyor çünkü Der nesnesi

burda Base classın Destructor'ını Virtual yaptığımız zaman Der classınında destructorı çağırılır ve UB den kaçınılmış oluruz

class Base
{
public:
    virtual void foo(){std::cout << "Base::foo()\n";}

    virtual  ~Base(){std::cout << "Base Destructor\n";}
};

class Der : public Base
{
public:
    virtual void foo(){std::cout << "Der::foo()\n";}
     virtual ~Der(){std::cout << "Der Destructor\n";}
};
int main()
{
    Base* baseptr = new Der;

    delete baseptr; // şimdi hem Der sınıfının hemde Base sınıfının Destroctorı çağırılır

}

 türemiş sınıf nesnelerini taban sınıf pointerı ile delete ediceksek mutlaka base classın destroctırı virtual olmalı

 polymorhpic base classların destroctorı

 a)public virtual olmalı
 yukardaki senaryo yani

 b)yada protected non-virtual olmalı

 class Base
{
public:
    virtual void foo(){std::cout << "Base::foo()\n";}
protected:
     ~Base(){std::cout << "Base Destructor\n";}
};

class Der : public Base
{
public:
     void foo() override{std::cout << "Der::foo()\n";}
      ~Der(){std::cout << "Der Destructor\n";}
};
int main()
{
    Der* derptr = new Der;

    delete derptr;

}

böyle bir senaryo olduğu zaman  Base'in destroctorı yine çağırılır çünkü protected bu yüzden der classı base'in destroctırına ulaşabilir
--------------------------------------------------------------------------------------------------------------------------------------------------
3)Virtual Destructor

C++’da **virtual destructor** (sanal yıkıcı), özellikle **kalıtım** (inheritance) yapılarında, bir türemiş sınıf nesnesi temel sınıfın işaretçisiyle 
(veya referansıyla) silindiğinde, **türemiş sınıfın yıkıcı fonksiyonunun da çağrılmasını garanti eder**. Aksi takdirde, yalnızca temel sınıfın yıkıcı 
fonksiyonu çalışır ve türemiş sınıfa ait kaynaklar (örneğin, dinamik bellek) serbest bırakılmaz. Bu, **bellek sızıntısı (memory leak)** gibi problemlere yol açabilir.

### **Neden Virtual Destructor Kullanılır?**

Bir sınıfın yıkıcısı `virtual` olarak işaretlendiğinde, o sınıfı miras alan (türeyen) sınıfların yıkıcılarının da çağrılması sağlanır. 
Bu, polimorfik sınıflar kullanırken gereklidir. Temel sınıfın yıkıcısı sanal değilse, türemiş sınıfın nesnesini temel sınıf işaretçisi 
üzerinden silerken yalnızca temel sınıfın yıkıcısı çağrılır, bu da kaynakların tam olarak serbest bırakılmamasına neden olur.

### **Örnek: Virtual Destructor Kullanımı**

#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Hem Derived hem Base yıkıcıları çağrılır.
    return 0;
}

**Çıktı:**

Derived destructor
Base destructor

Bu örnekte, `Base` sınıfının yıkıcısı sanal olarak tanımlanmıştır. Bu sayede, `delete obj;` satırı çalıştırıldığında 
hem `Derived` hem de `Base` yıkıcıları doğru sırasıyla çağrılır.

### **Eğer Virtual Destructor Kullanılmazsa**

Şimdi aynı örnekte `Base` sınıfının yıkıcısını sanal yapmazsak:

class Base {
public:
    ~Base() {
        std::cout << "Base destructor\n";
    }
};

Bu durumda, `delete obj;` sadece **Base** sınıfının yıkıcısını çağırır ve `Derived` sınıfının yıkıcısı çalıştırılmaz. 
Bu, türemiş sınıfta kullanılan kaynakların serbest bırakılmamasına neden olur ve **bellek sızıntısı** gibi sorunlar doğurabilir UNDEFINED BEHAVIOUR.

### **Ne Zaman Virtual Destructor Kullanılmalıdır?**
- Bir sınıf, polimorfik olarak (yani sanal fonksiyonlarla) kullanılacaksa yıkıcısının **virtual** olarak işaretlenmesi önerilir.
- Eğer bir sınıfın nesneleri türetilecek ve o nesnelere temel sınıf işaretçisi ile erişilecekse, sanal yıkıcı zorunlu hale gelir.

### **Performans Etkisi**
Sanal yıkıcı kullanmak, her sınıfın yıkıcı çağrısını bir **vtable** araması ile yapar, bu da çok küçük bir performans maliyeti getirir. 
Ancak doğru bellek yönetimi ve güvenilirlik açısından bu maliyet ihmal edilebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Non-Virtual Interface (NVI) Idiom Nedir?**

**Non-Virtual Interface (NVI) idiom**, C++ programlamada bir sınıfın davranışını düzenlemek için kullanılan bir tasarım tekniğidir. 
Bu idiyom, **türetilebilir sınıflarda** bir temel sınıfın (base class) **kamuya açık (public)** arayüzünün **virtualliğini kaldırmak** 
ve davranışı **özel (private)** veya **korumalı (protected)** sanal (virtual) fonksiyonlarla kontrol etmek amacıyla kullanılır.

### **Ana Prensipleri**
1. **Kamuya Açık Fonksiyonlar (Public Interface) Virtual Olmaz:**
   - Kamuya açık arayüz fonksiyonları (public member functions), virtual değildir. Böylece türetilmiş sınıflar bu arayüzü **doğrudan override edemez**.

2. **Davranış, Protected Virtual Fonksiyonlar Üzerinden Kontrol Edilir:**
   - Türetilebilir davranış, temel sınıfta **korumalı (protected)** olarak işaretlenen **virtual** fonksiyonlar üzerinden sağlanır. 
   Bu sayede türetilmiş sınıflar sadece korumalı fonksiyonları override edebilir.

3. **Kontrol Temel Sınıfta Olur:**
   - Kamuya açık arayüz fonksiyonları, temel sınıf tarafından davranışın kontrol edilmesini ve düzenlenmesini sağlar. 
   Türetilecek sınıflar yalnızca belirli davranış kısımlarını özelleştirebilir.

### **Örnek Kullanım:**

#include <iostream>

class Base {
public:
    // Kamuya açık ve sanal olmayan arayüz (Non-Virtual Interface)
    void operation() {
        std::cout << "Base: Pre-processing...\n";
        doOperation(); // Protected virtual fonksiyon çağrılır
        std::cout << "Base: Post-processing...\n";
    }

protected:
    // Türetilecek sınıflar için override edilebilir sanal fonksiyon
    virtual void doOperation() const = 0; // Saf sanal (pure virtual) olabilir

    virtual ~Base() = default; // Sanal yıkıcı (virtual destructor)
};

class Derived : public Base {
protected:
    void doOperation() const override {
        std::cout << "Derived: Custom operation!\n";
    }
};

int main() {
    Derived obj;
    obj.operation(); // Temel sınıftaki `operation` çalışır ve türetilmiş sınıftaki `doOperation` çağrılır
}

### **Çıktı:**

Base: Pre-processing...
Derived: Custom operation!
Base: Post-processing...

### **NVI Idiom'un Faydaları**

1. **Davranış Üzerinde Kontrol:**
   - Kamuya açık arayüzler (non-virtual), temel sınıf tarafından kontrol edilir. Bu, türetilmiş sınıfların yanlış kullanımını önler.

2. **Tek Tip Arayüz:**
   - Tüm türetilmiş sınıflar aynı **public** arayüzü kullanmak zorundadır. Bu, arayüzün tutarlılığını sağlar.

3. **Sınıf Hiyerarşisinde Güvenlik:**
   - Kamuya açık arayüzün override edilmesini engelleyerek, temel sınıfın kontrol mekanizması korunur.

4. **Kod Yeniden Kullanımı:**
   - Pre-Processing ve Post-Processing gibi ortak işlemler temel sınıfta tanımlandığı için bu kod tekrar yazılmak zorunda kalmaz.

### **Kullanım Senaryoları**
- **Şablon Metot Tasarımı (Template Method Design Pattern):**
  - NVI idiom, Şablon Metot Tasarım Deseni’nin bir uygulamasıdır. Tüm iş akışı temel sınıfta tanımlanır, 
  ancak iş akışındaki belirli parçalar türetilmiş sınıflar tarafından özelleştirilebilir.

- **Kütüphane Geliştirme:**
  - NVI, bir kütüphanede sağlam bir kamuya açık arayüz oluşturmak için kullanılır. Kullanıcılar sadece temel sınıfın 
  kamuya açık fonksiyonlarını kullanır; türetilmiş sınıfların detaylarını görmeleri gerekmez.

### **Sonuç:**
**Non-Virtual Interface Idiom**, C++’da sınıf hiyerarşisinde hem davranışı düzenlemek hem de güvenli bir kamuya açık arayüz 
sağlamak için etkili bir tekniktir. Özellikle karmaşık projelerde kontrolü sağlamak ve kod tekrarını önlemek amacıyla sıkça kullanılır.
--------------------------------------------------------------------------------------------------------------------------------------------------
static member funcitonlar virtual olamaz

global fonksiyonlar normalde virtual olamaz ama bazı senaryolarda olmasına ihtiyaç vardır 

class Car
{
public:
    virtual ~Car(){}
    Car(){}
    virtual void start() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
    virtual std::ostream& print(std::ostream&) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Car& c){
        return c.print(os);
     }
};
class Mercedes : public Car
{
public:
    Mercedes(){}
    virtual ~Mercedes(){}
    virtual void start() override { std::cout << "Mercedes::start\n"; }
    virtual void run() override{ std::cout << "Mercedes::run\n"; }
    virtual void stop() override{ std::cout << "Mercedes::stop\n"; }
    virtual std::ostream& print(std::ostream& os) const override{return os << "I am a mercedes\n";}
};
int main()
{
    Car* p = new Mercedes{};
    std::cout << *p << '\n'; // print foknisyonu çalışır
    p->start();
    p->run();
    p->stop();

    delete p;
}
--------------------------------------------------------------------------------------------------------------------------------------------------
final contextual keywordü 2 şekilde kullanılıyor

bir sınıfın final class yapılması (final class)
class Nec final{}; // bu sınıftan kalıtım yapılmayacağını belirtir

bir polymorphic sınıfın virtual fonksiyonunun final yapılması(final override)

derived class base class'ın fonksiyonunu override ediyor ama benden kalıtım yoluyla benim alt classlarım bendeki fonksiyonu override etmesin benim 
overridaımı kullansın demek

class Base
{  
    public:
    virtual void foo();
};

class Der : public Base
{
    public:
    void foo() override final
    {
    }
};

class Der2 : Der
{
    public:
    void foo() ovveride{} // sentaks hatası
}
--------------------------------------------------------------------------------------------------------------------------------------------------
private inheritance

base classın public memberları derived classın private bölümüne ekleniyor

class Base
{
public:
     void foo_public();
protected:
    void foo_protected();
private:
    void foo_private();

};

class Der : private Base
{
public:
    void foo()
    {
        foo_public();
        foo_protected();
        foo_private(); // sentaks hatası
    }
};
int main()
{
    Der myder;
    myder.foo_public(); // sentaks hatası çünkü Der private kalımı aldı yani Der'in clientları için hepsi private bölümüne eklendi
                        // yani aslında Der için bu private bir fonksiyon

    myder.foo_protected(); // sentaks hatası
    myder.foo_private(); // sentaks hatası
{

is-a relationship clientlar açısından artık yok public kalıtımı olmadığı için has-a relationship vardır
normalde her Der bir Base'idi ama artık öyle değil

Der myder;

Base* bptr = &base; // sentaks hatası upcastingi önlüyor

Genelde pek dikkate alınmayan bir yer var

Derived classın member functionları için durum yukarda olduğu gibi değil Der classının içinde hala is-a relationship var

class Der : private Base
{
    void foo()
    {
        Der myder;
        Base* bptr = &myder; // geçerli sınıfın içinde is-a relationship var
    }
};

böyle durumlarda is-a relationship derived classların member funcitonlarına ve friendlerine var

class Der : private Base
{
    friend void gf();
};

void gf()
{
    sDer myder;
    Base* bptr = &myder; // geçerli is-a relationship var
}

private kalıtımının kullanıldığı senaryolar

containment'a alternatiftir member yoluyla composition yapar aslında

private kalıtımını compositiona bir alternatif olarak kullanabiliriz ancak containmenttan farklı olarak taban sınıfın
virtual fonksiyonlarını override edebiliriz

class X
{
public:
    void foo() { std::cout << "X::foo()\n"; }

    virtual void baz();
};

class Nec
{
private:
    X x;
public:
    void foo(){ x.foo();}
};

class Erg : private X
{
public:
    using X::foo;
    void bar() { foo(); } // X::foo()}
    void baz() override;
};
int main()
{
    Erg e;
    e.bar();
}
--------------------------------------------------------------------------------------------------------------------------------------------------
class Base
{
public:
    void foo();
};

class Der : private Base
{
    void derfoo()
    {
        foo();
    }
};

class SDer : public Der
{
    void bar()
    {
        foo(); // Der base'ten private kalıtım aldığı için sentaks hatası eğer public yada protected olsaydı hata vermezdi
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Empty Base Optimization (EBO) Nedir?**

**Empty Base Optimization (EBO)**, C++ derleyicilerinin **boş (empty) taban sınıfların** (yani veri üyesi olmayan sınıfların) 
gereksiz yer kaplamasını önlemek için yaptığı bir optimizasyondur. Normalde, her sınıfın bellekte bir yeri olması beklenir. 
Ancak bir sınıfın taban sınıfı boşsa ve tek amacı türetilen sınıfa davranış (örneğin, fonksiyonlar veya arayüzler) sağlamaksa, bu sınıf için ekstra bellek alanı tahsis edilmesi gereksiz olabilir. 

C++ derleyicileri, **EBO** sayesinde bu boş taban sınıflara ayrılan belleği ortadan kaldırarak, veri yapılarının boyutunu optimize eder.

### **Neden EBO'ya İhtiyaç Duyulur?**

- **Verimlilik:** Bellek alanının gereksiz kullanımını önler.
- **Küçük nesne boyutu:** Özellikle sınıfların içinde boş taban sınıflar çok sayıda kullanıldığında, EBO, gereksiz belleğin tahsis edilmesini engelleyerek nesne boyutunu küçültür.

Örneğin, boş bir taban sınıf normalde 1 byte yer kaplar. Ancak türetilen sınıfla birlikte kullanılan EBO sayesinde bu 1 byte gereksiz hale gelir.

### **EBO'nun Çalışma Şekli**

C++ standardı (özellikle **C++11 ve sonrası**) derleyicilere boş taban sınıfların bellekte ek alan kaplamasını önleme imkanı verir. 
Ancak, EBO yalnızca **birden fazla boş taban sınıf** olmadığında ve **çoklu kalıtım** durumlarında sınırlı şekilde uygulanabilir.

### **EBO Örneği**

#include <iostream>

class EmptyBase {};

class Derived : public EmptyBase {
    int data;
};

int main() {
    std::cout << "EmptyBase size: " << sizeof(EmptyBase) << "\n"; // 1 byte olabilir.
    std::cout << "Derived size: " << sizeof(Derived) << "\n";     // 4 byte (int'in boyutu).
    return 0;
}

**Çıktı:**

EmptyBase size: 1
Derived size: 4

Bu örnekte, `EmptyBase` sınıfı 1 byte yer kaplayabilir (standart gereği her sınıfın bir boyutu olmalıdır). Ancak `Derived` 
sınıfı EBO sayesinde yalnızca `int` veri üyesi kadar (4 byte) yer kaplar; `EmptyBase` için fazladan yer ayrılmaz.

### **EBO’nun Sınırlamaları**
1. **Çoklu Kalıtımda Kısıtlama:** Birden fazla boş taban sınıf kullanıldığında, her biri için EBO uygulanamayabilir.
2. **Boş Olmayan Veri Üyeleri:** Eğer taban sınıfın veri üyesi varsa, EBO devreye girmez.
3. **Standartlara Uygunluk:** Tüm derleyicilerde EBO her zaman garanti edilmez, ancak yaygın olarak desteklenir (örneğin, GCC ve Clang).

### **Performans Avantajı ve Kullanım Alanları**
- **Kalıtım temelli tasarımlar:** Özellikle **CRTP (Curiously Recurring Template Pattern)** gibi desenlerde EBO önemlidir. 
- **Veri yapılarında bellek optimizasyonu:** Küçük boyutlu nesneler üretmek isteyen kütüphanelerde (örneğin, STL veya Boost).

### **Sonuç**

EBO, C++'da boş taban sınıfların gereksiz bellek tüketimini önleyerek, daha verimli veri yapıları ve nesneler oluşturulmasını sağlar. 
Küçük nesne boyutları ve bellek optimizasyonu gibi konulara önem veren projelerde bu optimizasyon hayati olabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Restricted polymorphism** (sınırlı çok biçimlilik), C++'ta polimorfizmin belirli kısıtlamalarla kullanılması durumlarını ifade eder. 
Bu terim genellikle bir sistemde ya da tasarımda polimorfizm kullanımını tam kapsamlı değil, belirli bir kontrol altında tutma ihtiyacını anlatır.

C++'ta **restricted polymorphism**, genellikle performans veya tasarım gereksinimleri nedeniyle tercih edilir ve aşağıdaki şekillerde ortaya çıkabilir:

### **1. Polimorfizm ve Statik Bağlama**
Polimorfizm genellikle sanal işlevler (virtual functions) ile gerçekleştirilir. Ancak, sanal işlevler bazı performans maliyetleri 
getirir (örneğin, sanal tablo kullanımı ve dinamik bağlama). **Restricted polymorphism**, sanal işlevler yerine statik bağlama 
kullanmayı tercih ederek bu maliyetlerden kaçınabilir.

Örnek:

struct Base {
    void foo() { std::cout << "Base::foo\n"; } // Sanal değil
};

struct Derived : public Base {
    void foo() { std::cout << "Derived::foo\n"; } // Gölgeleme (hiding)
};

int main() {
    Base* b = new Derived();
    b->foo(); // Base::foo çağrılır, dinamik bağlama yok
    delete b;
}

Bu durumda, polimorfizm sınırlıdır çünkü sanal işlevler kullanılmadığından dinamik bağlama gerçekleşmez. 
Bunun yerine **statik bağlama** tercih edilmiştir.

### **2. Türetilmiş Sınıflar Arasındaki Kontrol**
Bazen türetilmiş sınıfların temel sınıf işlevlerini belirli bir şekilde kullanması istenir. Bu durumda sanal işlevler 
kullanılsa bile, temel sınıf türetilmiş sınıfların davranışını kontrol edebilir.

class Base {
public:
    virtual void foo() final { std::cout << "Base::foo\n"; } // 'final' ile sınırlama
};

class Derived : public Base {
    // void foo() override; // Hata: 'foo' işlevi override edilemez
};

Bu örnekte, `final` anahtar sözcüğü kullanılarak polimorfizmin türetilmiş sınıflarda genişletilmesi sınırlandırılmıştır.

### **3. Şablonlarla (Templates) Kısıtlı Polimorfizm**
C++'ta şablonlar, **statik polimorfizm** sağlayabilir. Ancak şablonların bazı türlerle veya sınırlı davranışlarla çalışması 
istenebilir. Bu, `std::enable_if` veya `concepts` gibi araçlarla gerçekleştirilebilir.

Örnek:

#include <type_traits>
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
process(T value) {
    std::cout << "Integer processing: " << value << '\n';
}

// Sadece tamsayı olmayan türler için başka bir işlem
template <typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
process(T value) {
    std::cout << "Non-integer processing: " << value << '\n';
}

int main() {
    process(42);        // Integer processing
    process(3.14);      // Non-integer processing
}

Bu örnekte, yalnızca belirli türlerle polimorfizm sağlanmıştır (tamsayı ve tamsayı olmayan türler).

### **4. Soyut Sınıf Kullanımındaki Kısıtlamalar**
Soyut sınıflar polimorfizm sağlamak için kullanılır. Ancak bir soyut sınıfın yalnızca belirli türler veya durumlar için kullanılmasını isteyebilirsiniz.

Örnek:

class Animal {
public:
    virtual void makeSound() const = 0; // Saf sanal işlev
};

class Dog : public Animal {
public:
    void makeSound() const override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void makeSound() const override { std::cout << "Meow!\n"; }
};

// Restricted usage
void interactWithAnimal(const Animal& animal) {
    animal.makeSound();
}

int main() {
    Dog dog;
    Cat cat;

    interactWithAnimal(dog);
    interactWithAnimal(cat);
}

Bu, polimorfizmin yalnızca `Animal` soyut sınıfı ve türevleriyle sınırlandırıldığı bir durumdur.

### **C++'ta Restricted Polymorphism Araçları**
1. **Final Anahtar Sözcüğü**: Türetilmiş sınıfların işlevleri veya sınıfları genişletmesini engeller.
2. **Statik Polimorfizm (CRTP)**: Sanal işlevlerin yerine compile-time polimorfizm kullanılır.
3. **`std::enable_if` ve Concepts**: Şablonlar için tür kısıtlamaları sağlar.
4. **Sanallık Kontrolü**: Sadece belirli durumlarda sanal işlevler kullanılır.

**Sonuç:** Restricted polymorphism, polimorfizmin esnekliğini ihtiyaçlara göre sınırlandırmak için kullanılan bir yaklaşımdır.
Bu, performans veya tasarım gereksinimleri nedeniyle tercih edilir ve C++'ta bir dizi araçla uygulanabilir.
******************************************************************************************************************************

                                                                             ********* 26-DERS NOTLARI *********

multilevel inheritance
car sınıfından örneğin bir volvo diye bir sınıf var ve car sınıfından kalıtım almış aynı zamanda volvodanda bir kalıtım alan volvoXC90 sınıfı var

class Car
class Volvo: public Car
class VolvoXC90 : public Volvo

multiple inheritance
bir sınıfı tek bir kalıtım işlemiyle birden fazla taban sınıf kullanrak elde etmek

PRİNTER         SCANNER
              
        COMBO 

örneğin combo hem bir printerdır hemde bir scanner

class Printer
class Scanner

class Combo : public Printer,public Combo
--------------------------------------------------------------------------------------------------------------------------------------------------
class XBase
{
public:
    void foo(int){ "XBase::foo(int)\n"; }
};

class YBase
{
public:
    void foo(double){ "YBase::foo(double)\n"; }
};

class Der : public XBase, public YBase
{
public:
    void foo(int) { std::cout << "Der::foo(int)\n"; }
};

int main()
{
    Der myder;

    myder.foo(12);

}

burda fonksiyon overloading yoktur aynı scopeta olmadıkları için foo fonksiyonunu çağırdığı zaman ambigious olur

eğer türemiş sınıfta aynı isimde foo ismi olsaydı base classların foo isimde olan fonksiyonlarını gizlemiş olucaktı böylelikte hata olmazdı

class Der : public XBase, public YBase
{
public:
void foo(int);
};

int main()
{
    Der myder;

    myder.foo(12); // geçerli Der::foo(int)
    myder.XBase::foo(12); // geçerli niteleyerekte çağırabiliriz

}

her iki sınıftada aynı isimde fonksiyon olmasını istiyorsak Der classının içine using bildirim ile enjekte edebiliriz ve funcition overloadinigde sağlayabiliriz

class Der : public XBase, public YBase
{
public:
    using XBase::foo;
    using YBase::foo;
};
--------------------------------------------------------------------------------------------------------------------------------------------------
TABAN SINIFLARIN CONSTRUCTOLARININ VE DESTROCTORLARININ ÇAĞIRILMASI SIRASI

class XBase
{
public:
    XBase() { std::cout << "XBase Ctor\n"; }
    ~XBase() { std::cout << "~XBase Dtor\n"; }
};

class YBase
{
public:
    YBase() { std::cout << "YBase Ctor\n"; }
    ~YBase() { std::cout << "~YBase Dtor\n"; }
};

class Der : public XBase, public YBase
{
public:
    Der() { std::cout << "Der Ctor\n"; }
    ~Der() { std::cout << "~Der Dtor\n"; }
};

int main()
{
    Der myder;

}

Kalıtım alınan sıraya göre construcorlar çağırılır yani ilk XBase,YBase en son Der sınıfının constructolrarı çağırılır destroctor içinde
tam tersi sıra geçerlidir ilk Der,YBase,XBase
--------------------------------------------------------------------------------------------------------------------------------------------------
class X
{
public:
};

class Y
{
public:
};

class Der : public X, public Y
{
public:
};

void foo(X){}
void foo(Y){}

int main()
{
    Der myder;
    foo(myder); // ambigious hatası verir çünkü Der sınıfından X ve Y base classlarına UPCASTING olduğu için bir seçilebilirlik mevcut değil
                   ama istersek tür dönüştürme operatörleriyle yapabiliriz

     foo(static_cast<X>(myder));
}
--------------------------------------------------------------------------------------------------------------------------------------------------
Diamond problem
           DEVICE
   
   
   PRINTER          SCANNER
    
           
           COMBO
Burda olan sorun COMBO sınıfının içinde 2 ayrı DEVICE nesnesi olması hem PRINTERDA DEVICE var hemde SCANNERDA var
böylelikle COMBODA 2 ayrı DEVICE nesnesi olmuş oluyor böylelikle hangi device nesnesinin kullanılacağını derleyici anlamadıığı için ambiguty olucak
eğer COMBONUN içinde 1 DEVICE olmasını istiyorsak burda VIRTUAL INHERITANCE devreye giriyor

class Device
{
public:
int x{};
};

class Printer :public Device
{
public:
};

class Scanner : public Device
{
public:
};

class Combo : public Printer,public Scanner
{
public:
};

sizeof(Device) // 4 byte
sizeof(Printer) // 4 byte
sizeof(Scanner) // 4 byte
sizeof(Combo) // 8 byte

Device classının içinde foo isminde non-static bir fonksiyon olsaydı Combo cclassı bu fonksiyonu çağırmak isteseydi ve gizli parametre olarak
Device* içerdiği için Combo classınında içinde 2 Adet Device nesnesi olduğu için ambigious hatası verecekti

class Device
{
public:
    void foo(){}
};

int main()
{
    Combo c;
    c.foo(); // sentaks hatası derleyici hangi adresi kullanaacağını bilemez
    c.Printer::foo(); // niteleyerek kullanırsak her hangi bir sentaks hatası olmaz
    c.Scanner::foo(); // niteleyerek kullanırsak her hangi bir sentaks hatası olmaz
}

direkt olarak UPCASTING yapmakta sentaks hatası çünkü Combonun içinde 2 adet Device nesnesi var

Combo c;
Printer* dptr = &c; // sentaks hatası

Combo c;
Device* dptr = static_cast<Printer*>(&c);// geçerli
--------------------------------------------------------------------------------------------------------------------------------------------------
class Device
{
public:
    void foo(){}
};

class Printer :public virtual Device // virtual tanımı burda yapılır baştada olabilir publicten sonrada
{
public:
};

class Scanner : virtual public  Device
{
public:
};

class Combo : public Printer, public Scanner
{
public:
};

Combo c;
c.foo(); // artık sentaks hatası değil

Device* dptr = &c; // UPCASTING yapılabiliyor
--------------------------------------------------------------------------------------------------------------------------------------------------
 RTTI RUN TIME TYPE INFORMATION

 dynamic_cast
 typeid 

 sty::type_info classsı 
 NOT:<>angular bracket deniyor (açısal parantez)
 dynamic_cast DOWNCASTING'IN başarılı olup olmadığını güvenli bir şekilde run timeda bilgisini vericek

 dynamic_cast operatörünü kullanmamız için sanallık olması gerekir

 Der myder;
 Base* baseptr = &myder;
 dynamic_cast<Der*>(baseptr) // base class sanal olmalı 

 if with initializer ile kullanılması daha mantıklı scope leakge önlemek için

 if(Der* der_ptr =  dynamic_cast<Der*>(baseptr);)

 NOT:static_cast'in run time ile bir ilgisi yoktur compile time ile ilgisi vardır static cast ile yaptığmız bir dönüşüm compile timeda
 hata vermese bile run timeda sıkıntı olmayacağı anlamına gelmez bu yüzden dynamic_cast kullanılması gerek

 bu cast'i referans ile yaptığımız zaman null reference olmadığı için exception fırlatır

 Car* carptr = create_random_car();
 try
 {
    Volvo& vr = dynamic_cast<Volvo&>(*carptr);

    //code
 }
 catch(const std::exception& ex){std::cout<<"exception caught:"<<ex.what()<<'\n'; }

 Der dx;
 Der* myder = dynamic_cast<Der*>(dx) // sidecast yaparkende dynamic_cast kullanılır

 void* olarak ta kullanabiliriz

 Base* ptr = new Der;

 void* vptr = dynamic_cast<void*>(ptr);

 dynamic_cast operatörü
 DOWNCASTINGTE KULLANILIR
 SIDECASTTE KULLANILIR
 VOID* TURUNE DÖNÜŞTÜRÜRKEN KULLANILIR

 TYPEID

 <typeinfo>

 typeid operatörünün aldığı değer expression yada type olabilir

 typeid(10) typeid(x)

 typeid ile oluşturulan bir ifade const& standart kütüphanenin std::type_info türünden

 typeid ile türlerin eşit olup olmadığınıda karşılaştırabilirz

class Base
{
public:
    virtual void foo(){}
};

class Der :public Base
{
public:
};

int main()
{
    Der myder;
    Base* base_ptr = &myder;
    auto p = typeid(*base_ptr) == typeid(Der); // Base polymorphic class olduğu için run timeda bilgi vericek TRUE değerini üretir
                                                   eğer virtual olmasaydı compile timea yönelik bilgi verecekti ve compile timeda 
                                                    FALSE değeri üretir
    std::cout << p;

}

typeid polymorphic classlar için run time bilgisi verir polymorphic olmayan classlar için
compile time a yönelik bilgi verir

Car* carptr;

if(typeid(*carptr) == typeid(Volvo))
{
    burda dynamic_cast yapmıyoruz zaten ife girerse volov olduğunu biliyoruz bu yüzden static_cast yapıyoruz 

    Volvo* vptr = static_cast<Volvo*> (carptr);
    vptr->code;

}

typeid yada dynamic_cast operatörü run time da örneğin car'ın bir volvo olduğunu nerden biliyor
vtable yoluyla erişilen bir type info nesnesini kullanıyoruz
******************************************************************************************************************************           
          
                                                     ********* 27-DERS NOTLARI *********

exception handling error handlingin alt başlıklarından biridir

ERROR 2 ye ayrılıyor alt başlıkları ikisi genelde karıştırılıyor
    prograaming error
    bizim yazdığımız kodda bir hata var yani kod yanlış böyle durumlarda assertion kullanılması gerekir
    iki ayrı kategoriye ayrılır bu hatada yapmamız gereken kodu düzeltmek

        static assertions(compile time)
        yazdığımız yanlış kod derleme sırasında anlaşılıyor
        static_assert

         dynamic assertions(run time)
         run timeda anlaşılıyor
          assert()

RUNTIME ERROR
fonksiyonun  yapması gerekn bir iş var yapması gereken işi yapamadğını kendi koduyla saptıyor
karar verme yetkisi kendisinde değil onu çağıran kodda bu durumda fonksiyon bir hata durumuna düştüm işimi yapamıyorum
bunu local olarakta halledemyorum beni çağıranı bu durumdan haberdar etmek istiyorum bir error durumu oluşturuyor

bir fonksiyonun işini yapamaması ne demek bunlarla formülize ediliyor
    pre conditions ikiye ayrılır(fonksiyonu çağıran kod işini gerçekleştiremediyse buna narrow contract ve broad constract denir
    bunun muhattabı fonksiyonu çağıran kod
   
        narrow contracat:ben dökümante ettim bu fonksiyona negatif değer gelmemliydi sen buna uymak zorundasın ben bunu hata oplarak görmüyorum
        eğer negatif sayı gelirsede sonucuna herkes katlanmak zorunda UB yani dasqweweqqw
    
        broad contract:fonksiyuonu çöağıranı bırakmıyorum fonksiyon pre conditionsun sağlanıp sağlanmadığını kendisi kontrol ediyor

        pre conditionsun bir başka biçimi daha var ki çok karıştırılıyor fonksiyonun çağırdığı fonksiyonu pre conditionsları bunlardan biz sorumluyuz
        double foo(double x)
        {
            bar(x) // bar fonksiyonuan argüman göndericek ama argüman olucak ifadenin değerini hesaplaması gerekiyor ama hesaplayamıyor
                      bar'ın pre condiotnsunu sağlayamadığı için işini yapamıyor
        }

    fonksiyon işini yaptığında oluşması gereken durum  
    post conditions oluşmazsa error handling mecburi

    invariant
    sınıfların public member funcitonları için gereken bir kavram
     
    fonksiyon işini yapmadan önce snıfın geçerli durumunu biliyor(valid state) ve bunu devam ettiriyor
    
ERROR HANDBLING
fonksiyonun kendisin çağıran kodu yada kodları bu durumdan haberdar etmesine denir

traditional error handling
    exception handling
 
NOT:ne kadar if varsa o kadar test yazmak zorundayız hata yönetimine dair if deyimlerini azaltırsak test aşamassındada önemli avantajlar elde ederiz

EXCAPTION HANDLING

önceden olan bir sorun call chain sorunu f1 f2 f3 ... f18 f19  f19 fonskiyonunda bir sorun olsaydı bu soruna f1 fonksiyonuna göndermesi için önce f18 sonra f17 ... diye 
sırayla gitmesi gerekiyordu ama exception handling ile f19 a bir sorun olduğu zaman direkt olarak f1 fonksiyonuna throw edebiliyoruz exception ahndling bu sorunu çözüyor

throw statement
fonksiyon işini yapamadığı zaman bir nesne oluşturuyor ve bunu throw ediyor
throw ifadesi derleyicinin oluşturacağı hata nesnesini initalize etmekte kullanılır direkt olarak o nesne yollanmaz

try(try block)
hata gönderilmesi durumunda hataya müdahale edeceğimizi belirleyen hatanınn oluşacağı run timea ilşkin kod aralığını belirler

cath block
hataya müdahale eden catch bloku

uncaught exception
gönderilen bir hata nesnesinin yakalanmaması durumunda  std::terminate çağrılıyor ve program sonlanıyor
burda customiztion pointimiz var std::terminate fonksiyonun default davranışı var c den gelen std::abort fonksiyonnu çağırmak
bu fonksiyon hiç bir önlem anlamadan programı anında sonlandırıyor terminate'in çağırılması demek abort'un çağırılması demek
terminate'in default davranışını set_terminate fonksiyonu ile değiştirebiliriz  

void my_terminate()
{
    std::cout<<"my terminate\n";
    std::exit(EXIT_FAILURE); // set ettiğimiz fonksiyonda programı sonlandırmak zorunda
}
int main()
{
    std::set_terminate(&my_terminate); // set_terminate bir fonksiyon pointerı alıyor
    
}

exception handling 2 ayrı biçimde kullanılır

resumptive 
hata yakalanabilir ama programın çalışmasını devam etmesini istiyoruz yani hata yakalandıktan sonra programın çalışmasında her hangi bir problem olmaması 
in a valid state durumunda çalışması garantisidir ve bu garantiye basic guarantee denir

terminative
program beklenmeyen bir hataya düştüğünde mümkünse bir kayıp olmadan loglarla programın sonlanması 

call chain örnek

void foo()
{
    std::cout << "foo called\n";
    throw 14; // buraya gönderilen değer ile catch bloğundaki exception yakalanır
                 double göndersek double olan çağırılacaktı
}

void baz()
{
    foo();
}

void bar()
{
    baz();
}

int main()
{
    try {
        bar();
    }
    catch (int i)
    {
        std::cout << "exception caught catch(int) x = " << i << '\n'; // bu çalışır
    }
    catch (double d)
    {
        std::cout << "exception caught catch(int) x = " << d << '\n';
    }
    catch (char c)
    {
        std::cout << "exception caught catch(int) x = " << c << '\n';
    }
}

burada coversion çok kısıtlı olmakla beraber sadece türemiş sınıftan taban sınıfa dönüşüm vardır

class Base{};
class Der : public Base{};

void foo()
{
    std::cout << "foo called\n";
    throw Der(); // UPCASTING olur aslında

}

void baz()
{
    foo();
}

void bar()
{
    baz();
}

int main()
{
    try {
        bar();
    }
    catch (const Base&) // bu çalışır
    {
        std::cout << "exception caught catch(Base&) "; 
    }
}

exception sınıfının what const char* döndüren virtual fonksiyonu var türemiş sınıflar bu fonksiyonu override ediyorlar
burdada virtual dispatch devreye giriyor

catch bloğunda olan sıralamalar önemlidir özelden genele doğru gitmesi gerek

hatanın referans semantiği ile yakalanması çok önemli yakalanmazsa
    polymorphic bir türdense object clicing olur
--------------------------------------------------------------------------------------------------------------------------------------------------
C++'ta **hata yönetimi (error handling)**, programların beklenmeyen durumlarla düzgün bir şekilde başa çıkmasını sağlar. 
Hatalar, derleyici uyarıları, çalışma zamanı hataları veya mantıksal hatalar gibi farklı kategorilere ayrılabilir. 
İşte C++’ta yaygın olarak kullanılan hata yönetim teknikleri ve bu tekniklerin detayları:

## 1. **İstisna (Exception) Yönetimi**

C++ istisnalar, hata anında normal program akışını durdurup, hatayı güvenli bir şekilde yakalamak ve işlemek için kullanılır.  

### Temel Kullanım:

- **`try`**: Hata olabilecek kod bloğu içine alınır.
- **`throw`**: İstisna fırlatmak için kullanılır.
- **`catch`**: Fırlatılan istisnayı yakalar ve işler.

Örnek:

#include <iostream>
#include <stdexcept>

void divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    std::cout << "Result: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

### İstisna Türleri:
- **`std::exception`**: Temel istisna sınıfı.
- **`std::runtime_error`**: Çalışma zamanı hataları için.
- **`std::out_of_range`**: Geçersiz indeks hatası için.
- **`std::bad_alloc`**: Bellek tahsisi hatası.

**Not:** Herhangi bir istisna yakalanmazsa, program `std::terminate()` çağrısıyla sonlanır.

## 2. **İstisnasız Fonksiyonlar (`noexcept`)**

C++11’den itibaren, bir fonksiyonun istisna fırlatmayacağını belirtmek için `noexcept` anahtar kelimesi kullanılır. Bu, optimizasyon sağlar ve güvenlik sunar.

void safe_function() noexcept {
    // Bu fonksiyon istisna fırlatamaz.
}

Eğer `noexcept` olarak işaretlenmiş bir fonksiyon içinde istisna fırlatılırsa, `std::terminate()` çağrılır.

## 3. **Hata Kodları Kullanmak**

Bazı durumlarda, özellikle düşük seviyeli API’lerde, hata kodları yaygın olarak kullanılır. Bu yöntem, işlevlerin bir hata durumunda belirli bir kod döndürmesini içerir.

Örnek:

#include <iostream>

int divide(int a, int b, int& result) {
    if (b == 0) return -1;  // Hata kodu: Bölme sıfıra bölünemez
    result = a / b;
    return 0;  // Başarı kodu
}

int main() {
    int result;
    if (divide(10, 0, result) != 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
    }
    return 0;
}

Bu yöntemde, her işlev çağrısından sonra hataların kontrol edilmesi gerekir.

## 4. **`std::optional` Kullanımı**

C++17 ile gelen `std::optional`, bir fonksiyonun geçerli bir değer döndüremediği durumda kullanışlıdır.

Örnek:

#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b) {
    if (b == 0) return std::nullopt;  // Geçersiz durum
    return a / b;
}

int main() {
    auto result = divide(10, 2);
    if (result) {
        std::cout << "Result: " << *result << std::endl;
    } else {
        std::cerr << "Error: Division by zero!" << std::endl;
    }
    return 0;
}

## 5. **`std::error_code` ve `std::system_error`**

`std::error_code` ve `std::system_error`, özellikle sistem seviyesindeki hataları daha ayrıntılı şekilde ifade etmek için kullanılır.

#include <iostream>
#include <system_error>

int main() {
    try {
        throw std::system_error(std::make_error_code(std::errc::permission_denied));
    } catch (const std::system_error& e) {
        std::cerr << "Caught system error: " << e.what() << std::endl;
    }
    return 0;
}

## 6. **`assert` Makrosu ile Hata Kontrolü**

`assert`, çalışma zamanında belirli koşulların sağlandığını doğrulamak için kullanılır. Yanlış bir durum tespit edilirse, program durdurulur.

#include <cassert>

int main() {
    int a = 5;
    assert(a > 10 && "a must be greater than 10");  // Bu koşul yanlış, program duracak
    return 0;
}

`assert` sadece *debug* derlemelerinde aktiftir. *Release* modunda devre dışıdır.

## Özet

C++'ta hata yönetimi, ihtiyaçlara göre farklı yöntemlerle ele alınabilir:
1. **İstisnalar**: Güçlü hata işleme mekanizması.
2. **Hata Kodları**: Sistem ve düşük seviyeli programlama için.
3. **`std::optional`**: Değerin olup olmamasını kontrol etmek için.
4. **`std::error_code` ve `std::system_error`**: Daha ayrıntılı sistem hataları.
5. **`assert`**: Debug modunda koşul kontrolü.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **C++ Exception Handling (İstisna Yönetimi)**

C++'ta *exception handling* (istisna yönetimi), beklenmeyen durumlarla karşılaşıldığında programın kontrollü bir şekilde hata işleme
mekanizmalarına geçmesini sağlar. Bu, program akışını bozmak yerine hataların ele alınmasına ve düzeltici işlemlerin uygulanmasına olanak tanır.

## **İstisna Yönetimi Temelleri**

C++'ta istisnalar şu yapı taşlarıyla ele alınır:

- **`try`**: İstisna oluşabilecek kod bloğu içine alınır.
- **`throw`**: Bir hata tespit edildiğinde, istisna fırlatmak için kullanılır.
- **`catch`**: Fırlatılan istisnayı yakalayıp işler.

### Temel Örnek:

#include <iostream>
#include <stdexcept>  // runtime_error için gerekli

void divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero error!");  // Hata fırlatılıyor
    }
    std::cout << "Result: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
**Açıklama:**  
- `divide` fonksiyonu sıfıra bölme durumunda bir `std::runtime_error` fırlatıyor.  
- `main` fonksiyonunda, `try-catch` bloğu ile hata güvenli bir şekilde yakalanıyor ve işleniyor.

## **İstisna Türleri**

- **`std::exception`**: Tüm standart istisnaların taban sınıfıdır.
- **`std::runtime_error`**: Çalışma zamanında oluşabilecek hatalar.
- **`std::logic_error`**: Mantıksal hataları temsil eder (örn. geçersiz argümanlar).
- **`std::bad_alloc`**: Bellek tahsis hatası (örn. `new` operatörü başarısız olursa).
- **`std::out_of_range`**: Kapsam dışı erişim hataları.

Her istisna sınıfı, hatanın açıklaması için bir `what()` üyesi sunar.

## **İstisnaların Zincirlenmesi ve Genel Yapı**

Birden fazla istisna türü yakalamak için çoklu `catch` blokları kullanabilirsiniz:

#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::out_of_range("Out of range error!");
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

**Açıklama:**  
- `catch` blokları, spesifikten genele doğru sıralanmalıdır.  
- Eğer ilk `catch` bloğunda uygun bir istisna yakalanmazsa, daha genel bir `std::exception` yakalayıcısı devreye girer.

## **Genel İstisnaları Yakalama**

Tüm türden istisnaları yakalamak için bir `catch(...)` bloğu kullanılabilir.

try {
    // Hata oluşabilecek kod
} catch (...) {
    std::cerr << "An unknown exception occurred!" << std::endl;
}

Bu yöntem, hangi türden bir istisna fırlatıldığını bilmediğiniz durumlarda kullanışlıdır.

## **İstisna Güvenliği (Exception Safety)**

İstisna güvenliği, programın hata oluştuğunda tutarlı kalmasını sağlar. C++'ta yaygın olarak kullanılan üç seviye istisna güvenliği vardır:

1. **Basic Guarantee**: Programın durumu tutarlı kalır, ancak bazı kaynaklar kaybedilebilir.
2. **Strong Guarantee**: Hata oluşursa program hiçbir değişiklik yapmaz, orijinal durum korunur.
3. **No-Throw Guarantee**: Fonksiyon hiçbir koşulda istisna fırlatmaz (örneğin, `noexcept` kullanarak).

## **Standart Olmayan İstisnalar**

İstisna olarak yalnızca standart sınıflar değil, kullanıcı tanımlı sınıflar veya herhangi bir veri türü de fırlatılabilir:

try {
    throw 42;  // Bir tam sayı istisnası fırlatılıyor
} catch (int e) {
    std::cerr << "Caught exception with value: " << e << std::endl;
}

Ancak, **`std::exception`** türevleri kullanmak, kodun daha okunabilir ve bakımı kolay olmasını sağlar.

## **Destructor'larda İstisna Yönetimi**

Destructor'lar içinde istisna fırlatılması tavsiye edilmez, çünkü destructor çağrıları sırasında bir istisna 
fırlatılırsa ve başka bir istisna halihazırda aktifse, program `std::terminate()` ile sonlanır.

class MyClass {
public:
    ~MyClass() noexcept {
        // Destructor içinde istisna fırlatılmaz
    }
};

## **Özet**

- **`try-catch` yapıları**, istisna yönetiminin temelidir.
- **Özel istisna sınıfları** kullanılarak, hatalar kategorize edilebilir.
- **`noexcept`** ile istisnasız fonksiyonlar tanımlanabilir.
- **Destructor'larda** istisna fırlatmaktan kaçınılmalıdır.
- **İstisna güvenliği** prensipleri, programların kararlı kalmasını sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Preconditions (Ön Koşullar) Nedir?**  

**Precondition** (ön koşul), bir fonksiyonun veya metodun doğru çalışabilmesi için sağlanması gereken başlangıç koşuludur. 
Eğer bu koşullar yerine getirilmezse, fonksiyonun veya metodun beklenen şekilde çalışması garanti edilemez ve hata oluşabilir.  

C++'ta ön koşulların kullanımı, **hata önleme** ve **kod güvenliği** sağlamak açısından önemlidir. 

## **Precondition Örnekleri**

Örneğin, bir fonksiyonun sıfır olmayan bir sayıyla bölme yapmasını bekliyorsanız, bölünenin sıfır olmaması bir ön koşuldur.

#include <iostream>
#include <stdexcept>

double divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    return static_cast<double>(a) / b;
}

int main() {
    try {
        std::cout << divide(10, 0) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

### **Açıklama:**
- `divide` fonksiyonu, `b` parametresinin sıfır olmamasını bekler.  
- Eğer ön koşul sağlanmazsa (`b == 0`), `std::invalid_argument` istisnası fırlatılır.

## **Preconditions'un Belirtilmesi ve Kontrol Edilmesi**

Ön koşulları kontrol etmek için bazı yaygın yöntemler şunlardır:

### 1. **`assert` ile Kontrol (Debug Modunda)**

`assert` makrosu, koşulun doğru olup olmadığını çalışma zamanında kontrol eder. Koşul sağlanmazsa program sonlanır. 

#include <cassert>

int factorial(int n) {
    assert(n >= 0 && "Input must be non-negative");  // Ön koşul
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    factorial(-5);  // Hata, program durur.
    return 0;
}

**Not:** `assert` yalnızca **debug** derlemelerde etkindir. **Release** modda otomatik olarak devre dışı kalır.

## **`noexcept` ve Ön Koşullar**

Eğer bir fonksiyon, ön koşullar sağlanmazsa hata fırlatmaması ve bu durumda programın sonlanmasını engellemesi bekleniyorsa, 
**`noexcept`** kullanılması uygundur. Bu, daha güvenli ve performanslı kod yazmanızı sağlar.

void safe_function(int n) noexcept {
    assert(n >= 0 && "n must be non-negative");
    // Ön koşul sağlanmazsa assert ile hata verir
}

## **Ön Koşullarla Kod Güvenliği Sağlamak**

1. **Dokümantasyon**: Ön koşulları fonksiyon açıklamalarında belirtmek iyi bir uygulamadır.

   // Bu fonksiyon, n >= 0 ön koşulunu gerektirir.
   int factorial(int n);

2. **İstisnalar**: Beklenmeyen koşullarda uygun istisna fırlatmak kodun güvenliğini artırır.

3. **Unit Testler**: Fonksiyonun ön koşullarının ihlali durumlarını test etmek, kodun güvenliğini ve kararlılığını artırır.

## **Sonuç**

Preconditions, fonksiyonların doğru çalışmasını sağlamak için hayati önem taşır. C++’ta ön koşullar şu yöntemlerle sağlanabilir:
- `assert` kullanımı (debug modunda)
- İstisnalarla hata yönetimi (`throw`)
- `std::optional` kullanımı ile güvenli dönüş
- `noexcept` ile garanti edilen istisnasız kod

Bu yöntemler, kodun güvenliğini artırır ve hataların erken fark edilmesine olanak tanır.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Postconditions (Son Koşullar) Nedir?**  

**Postcondition** (son koşul), bir fonksiyon veya metodun başarılı bir şekilde çalışmasının ardından programın belirli bir durumda olmasını garanti eder. 
Son koşullar, fonksiyonun beklenen çıktılarının veya yan etkilerinin doğruluğunu denetlemek için kullanılır.  

Son koşullar, **fonksiyonun doğru bir şekilde çalışıp çalışmadığını** kontrol ederek kodun güvenliğini sağlar ve programın tutarlı olmasını garanti eder.

## **Postcondition Örnekleri**

### Örnek 1: Temel Postcondition Kullanımı

Aşağıdaki örnek, bir fonksiyonun pozitif bir tam sayının faktöriyelini hesapladığını gösterir. 
**Postcondition** olarak, döndürülen sonucun her zaman 1 veya daha büyük olması beklenir. 

#include <iostream>
#include <cassert>

int factorial(int n) {
    assert(n >= 0 && "Input must be non-negative");  // Ön koşul

    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    // Postcondition: Sonuç 1 veya daha büyük olmalı
    assert(result >= 1 && "Result must be >= 1");
    return result;
}

int main() {
    int result = factorial(5);
    std::cout << "Factorial: " << result << std::endl;
    return 0;
}

**Açıklama:**  
- **Ön koşul:** `n` değeri negatif olmamalı.
- **Son koşul:** Hesaplanan faktöriyel sonucu **1 veya daha büyük** olmalı.

## **Postconditions ile `assert` Kullanımı**  

`assert` ile hem ön koşulları hem de son koşulları kontrol edebilirsiniz. Ancak, **assert sadece debug modda** çalışır.
Bu nedenle, son koşulları **release** modda da doğrulamak için farklı yöntemler gerekebilir.

### Örnek 2: `std::vector` ile Postcondition  

Bu örnekte bir elemana ekleme işlemi sonrası **vektörün boyutunun arttığı** postcondition olarak kontrol edilir.

#include <iostream>
#include <vector>
#include <cassert>

void add_element(std::vector<int>& vec, int element) {
    size_t initial_size = vec.size();

    vec.push_back(element);

    // Postcondition: Vektörün boyutu 1 artmış olmalı
    assert(vec.size() == initial_size + 1 && "Vector size must increase by 1");
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    add_element(vec, 4);

    std::cout << "New size: " << vec.size() << std::endl;
    return 0;
}

**Açıklama:**  
- Postcondition: Yeni eleman eklendikten sonra vektörün boyutunun 1 artmış olması beklenir.

## **Son Koşulları İfade Etmenin Alternatif Yolları**

### 1. **İstisna Fırlatma ile Son Koşulların Kontrolü**

Bazı durumlarda, son koşul sağlanmazsa istisna fırlatmak uygun olabilir. Bu, programın yanlış sonuçlar üretmesini engeller.

#include <iostream>
#include <stdexcept>

int increment(int value) {
    int result = value + 1;

    // Postcondition: Sonuç, başlangıç değerinden büyük olmalı
    if (result <= value) {
        throw std::logic_error("Postcondition failed: result is not greater than input.");
    }

    return result;
}

int main() {
    try {
        std::cout << increment(5) << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

### 2. **`noexcept` ile Postcondition Kullanımı**

Eğer bir fonksiyon hem **ön koşulları** hem de **son koşulları** garantili bir şekilde sağlıyorsa, 
`noexcept` kullanarak bu durumu belirtebilirsiniz. Bu, derleyici optimizasyonlarını artırır.

int square(int n) noexcept {
    int result = n * n;

    // Postcondition: Sonuç negatif olmamalı
    assert(result >= 0 && "Result must be non-negative");
    return result;
}

## **Design by Contract (DbC) Yaklaşımı**

**Design by Contract (DbC)**, bir yazılım geliştirme metodolojisidir ve ön koşullar, son koşullar ve sınıf içi 
*invariant* kurallarını açıkça tanımlar. Bu yaklaşım, kodun tutarlı olmasını sağlar.  

Örneğin:
- **Ön Koşul:** Girdi parametreleri geçerli olmalı.
- **Son Koşul:** Çıktı, belirlenen kurallara uygun olmalı.
- **Invariant:** Nesne durumları her zaman belirli bir durumda olmalı.

## **Özet**

- **Postconditions** (son koşullar), bir fonksiyonun çalışmasından sonra belirli durumların sağlanmasını garantiler.
- C++'ta son koşullar, **`assert`**, **istisnalar**, veya **invariant kontrolleri** ile uygulanabilir.
- **Design by Contract** gibi yöntemler, kodun güvenli ve hatasız çalışmasını sağlamak için ön ve son koşulları birleştirir.
- **Postconditions**, fonksiyonların doğru çalıştığını ve tutarlı sonuçlar ürettiğini doğrulamak için hayati önem taşır.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Invariants (Değişmezler) Nedir?**

**Invariant (değişmez)**, bir nesnenin veya programın **her zaman geçerli olması gereken bir durum veya koşulu** ifade eder.
Bir sınıf veya veri yapısında invariant, **nesnenin geçerli (valid) durumunu** tanımlar.  

Eğer bir nesne, her işlemden sonra belirlenen invariant koşullarını ihlal ederse, o nesne artık tutarlı (consistent) 
değildir ve program hatalı çalışabilir. Invariant'lar genellikle **constructor**, **destructor** ve sınıfın diğer metodları arasında geçerliliği korumayı hedefler.

## **Invariants'ın Temel Amacı**

- **Veri Tutarlılığını Sağlamak**: Nesne veya veri yapısının belirli kurallara uygun olmasını garantiler.  
- **Hata Önlemek**: Invariant'ın bozulması, bir yerde hata olduğunu gösterir.
- **Kodu Anlaşılır Kılmak**: Invariant'lar, kodun nasıl çalıştığını ve hangi durumların geçerli olması gerektiğini açıklar.

## **Örnek 1: Banka Hesabı Invariant'ı**

Bir bankadaki hesap bakiyesinin her zaman sıfır veya pozitif kalması gerektiğini varsayalım. Bu, **invariant**'tır.  

#include <iostream>
#include <stdexcept>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial_balance) : balance(initial_balance) {
        if (balance < 0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Deposit amount cannot be negative.");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Withdrawal amount cannot be negative.");
        }
        if (amount > balance) {
            throw std::runtime_error("Insufficient balance.");
        }
        balance -= amount;
    }

    double get_balance() const {
        return balance;
    }

    // Invariant kontrolü: Balance her zaman >= 0 olmalı
    void check_invariant() const {
        if (balance < 0) {
            throw std::logic_error("Invariant violated: balance cannot be negative.");
        }
    }
};

int main() {
    try {
        BankAccount account(100);
        account.deposit(50);
        account.withdraw(200);  // Bu işlem invariant'ı ihlal eder ve istisna fırlatır.
        account.check_invariant();  // Kontrol sırasında hata fırlatılacak
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

### **Açıklama:**
- **Invariant:** Hesap bakiyesi hiçbir zaman negatif olamaz.
- Invariant kontrolü `check_invariant()` metodu ile yapılıyor.
- Hata durumlarında, istisna fırlatılıyor.

## **Sınıf Invariant'larını Korumak**

1. **Constructor'da**: Nesne oluşturulurken invariant sağlanmalıdır.
2. **Metodlar Arasında**: Her metoddan sonra invariant geçerli olmalıdır.
3. **Destructor'da**: Nesne yok edilmeden önce geçerli durumda olmalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Narrow Contract (Dar Anlaşma) Nedir?**  

**Narrow contract (dar anlaşma)**, bir fonksiyon veya metodun sadece **belirli giriş değerlerinde çalışmayı garanti ettiği** anlamına gelir. 
Diğer bir deyişle, bu tür fonksiyonlar belirli koşullar sağlanmazsa **geçersiz duruma (undefined behavior)** neden olabilir. 
**Kullanıcıdan kesin olarak belirli ön koşulların sağlanmasını bekler** ve eğer sağlanmazsa, fonksiyonun davranışı belirsiz olabilir veya istisna fırlatabilir.  

Narrow contract’lı fonksiyonlar, daha hızlı ve performanslı olabilir çünkü **tüm olası durumları** kontrol etmeye ihtiyaç duymazlar.

## **Özellikleri**

1. **Belirli ön koşullara** bağlıdır. Kullanıcı, çağrılan fonksiyona geçerli parametreler sağlamazsa, sonuç garanti edilmez.
2. **Daha performanslıdır**, çünkü her koşul için ek kontrol gerekmez.
3. **Undefined behavior (UB)** riski taşır, yani ön koşullar ihlal edilirse program beklenmedik davranış gösterebilir.
4. Genellikle **belirli girdilere güvenildiği** durumlarda kullanılır. Örneğin, performans kritik kodlarda yaygındır.

## **Örnek 1: Sıfıra Bölme Kontrolü Olmayan Fonksiyon**

Bu fonksiyon **dar anlaşma** kapsamındadır, çünkü kullanıcının bölünen sayının sıfır olmadığını garanti etmesi gerekir. Aksi takdirde, davranış belirsizdir.

#include <iostream>

double divide(int a, int b) {
    // Ön koşul: b != 0 olmalı, aksi takdirde UB oluşabilir.
    return static_cast<double>(a) / b;
}

int main() {
    std::cout << divide(10, 2) << std::endl;  // Geçerli
    std::cout << divide(10, 0) << std::endl;  // Undefined behavior
    return 0;
}

### **Açıklama:**
- Fonksiyon **narrow contract**’a sahiptir, çünkü `b` parametresinin sıfır olmaması beklenir.
- Eğer `b` sıfır olursa, davranış belirsiz olur ve program çökebilir.

## **Narrow Contract ile İlgili Problemler**

1. **Undefined Behavior Riski:** Ön koşullar yerine getirilmezse fonksiyon belirsiz şekilde çalışır. 
2. **Kullanıcı Hatalarına Açık:** Kullanıcı, fonksiyonun beklentilerini bilmiyorsa hatalara yol açabilir.
3. **İstisna Fırlatmamak:** Bazı narrow contract’lı fonksiyonlar, hatalı durumlarda istisna bile fırlatmayabilir. 

## **Örnek 2: `std::vector::operator[]` Kullanımı**

C++’ta **`std::vector::operator[]`** fonksiyonu da **narrow contract** sağlar. 
Geçersiz bir indeks verilirse **davranış belirsizdir**. Bu, performans için sağlanmış bir tercihtir.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};
    std::cout << vec[1] << std::endl;  // Geçerli
    std::cout << vec[10] << std::endl;  // Undefined behavior
    return 0;
}

### **Açıklama:**
- `vec[10]` ifadesi, geçerli bir indeks olmadığında belirsiz davranışa (UB) yol açar.  
- Performans açısından, her erişimde sınır kontrolü yapılmaz. Bunun yerine `at()` fonksiyonu kullanılabilir.

    std::cout << vec.at(10) << std::endl;  // std::out_of_range hatası fırlatır.

## **Wide Contract (Geniş Anlaşma) ile Karşılaştırma**

**Wide contract (geniş anlaşma)**, bir fonksiyonun **her tür giriş değeri için güvenli** çalışmayı garanti ettiği durumdur. 
Hatayla karşılaşıldığında ya **istisna fırlatır** ya da güvenli bir durum döndürür.

### Karşılaştırma Tablosu

| **Özellik**          | **Narrow Contract**                    | **Wide Contract**                     |
|----------------------|-----------------------------------------|---------------------------------------|
| Ön Koşul             | Belirli koşullar sağlanmalı             | Her durumda çalışır                  |
| Undefined Behavior   | Mümkün                                   | Mümkün değil                         |
| Performans           | Daha yüksek performans                  | Biraz daha yavaş                     |
| Hata Yönetimi        | Kullanıcı sorumluluğunda                | İstisna veya güvenli dönüş sağlar    |

## **Ne Zaman Narrow Contract Kullanılır?**

- **Performansın önemli olduğu** durumlarda.
- Kullanıcıların fonksiyonun doğru kullanımı konusunda **bilinçli olduğu** senaryolarda.
- **Sınır kontrolü gerekmeyen** veya hatalı durumların istisna fırlatmasını istemediğiniz yerlerde.

## **Özet**

- **Narrow contract**, belirli ön koşullara bağlı olan ve bu koşullar ihlal edilirse undefined behavior ile sonuçlanabilecek fonksiyonlardır.
- **Performans** gerektiren durumlarda tercih edilir, ancak **güvenlik riski** taşır.
- Kullanıcının ön koşulları sağlaması gerektiğinden, fonksiyonun **doğru şekilde kullanılmasına dikkat edilmelidir**.
- Eğer tüm durumlarda güvenli çalışma isteniyorsa, **wide contract** tercih edilmelidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Wide Contract (Geniş Anlaşma) Nedir?**  

**Wide contract (geniş anlaşma)**, bir fonksiyon veya metodun **her tür giriş** için güvenli ve tahmin edilebilir bir şekilde çalışmayı 
garanti ettiği bir tasarım yaklaşımıdır. Giriş parametreleri yanlış veya sınır dışı olsa bile, fonksiyon **undefined behavior (belirsiz davranış)** sergilemez.  

Bu tür fonksiyonlar, hatalı kullanımlara karşı güvenli olacak şekilde tasarlanır:  
- **İstisna fırlatabilir.**  
- **Geçerli bir varsayılan değer döndürebilir.**  
- **Hataları işlemeye uygun olur.**  

Wide contract, **hata yönetimi** için daha sağlam bir yaklaşım sunduğu için kritik ve güvenli yazılım geliştirme süreçlerinde tercih edilir.

## **Özellikleri**  

1. **Her durumda çalışır:** Parametreler geçersiz bile olsa fonksiyon güvenli bir sonuç verir.
2. **İstisna fırlatma desteği:** Hatalı girişlerde istisna fırlatılabilir.
3. **Güvenlik ve sağlamlık:** Undefined behavior içermez, yani her koşulda güvenli çalışır.
4. **Performans**: Narrow contract’a göre daha fazla kontrol yapması gerekebilir, bu nedenle biraz daha yavaş olabilir.

## **Örnek 1: Güvenli Bölme İşlemi**  

Bu fonksiyon, sıfıra bölünme durumunda **istisna fırlatarak** hatayı ele alır. Böylece undefined behavior oluşmaz.

#include <iostream>
#include <stdexcept>

double safe_divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return static_cast<double>(a) / b;
}

int main() {
    try {
        std::cout << safe_divide(10, 2) << std::endl;  // Geçerli
        std::cout << safe_divide(10, 0) << std::endl;  // İstisna fırlatır
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

### **Açıklama:**  
- **İstisna fırlatma** kullanılarak sıfıra bölünme hatası ele alınıyor.  
- Böylece program, undefined behavior yerine tahmin edilebilir şekilde çalışır.

## **Örnek 2: `std::vector::at()` Kullanımı**  

C++’taki **`std::vector::at()`** metodu, geçersiz indeks verilmesi durumunda **istisna fırlatarak** hatayı ele alır. Bu, `operator[]`’dan farklı olarak **wide contract** sağlar.

#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<int> vec = {1, 2, 3};

    try {
        std::cout << vec.at(1) << std::endl;  // Geçerli
        std::cout << vec.at(10) << std::endl;  // std::out_of_range hatası
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

### **Açıklama:**  
- **`at()` metodu**, geçersiz indeks durumunda **std::out_of_range** hatası fırlatır.  
- Bu sayede, program güvenli ve tahmin edilebilir bir şekilde çalışır.

## **Ne Zaman Wide Contract Kullanılır?**  

- **Güvenliğin kritik** olduğu durumlarda (ör. finansal işlemler, güvenlik yazılımları).  
- Hata yönetiminin **kolay anlaşılabilir** ve **yapısal** olması gerektiğinde.  
- Fonksiyonun her durumda çalışmasının gerektiği **genel amaçlı kütüphanelerde**.  
- **Kullanıcı hatalarına açık** durumlarda.

## **Örnek 3: Varsayılan Değer ile Hata Yönetimi**  

Bir fonksiyon, geçersiz bir giriş alırsa **varsayılan bir değer döndürebilir**. Bu da bir wide contract yöntemidir.

#include <iostream>

int safe_parse_int(const std::string& input) {
    try {
        return std::stoi(input);  // Geçerli bir tamsayıya dönüştürmeye çalış
    } catch (...) {
        return 0;  // Hata durumunda varsayılan değer olarak 0 döndür
    }
}

int main() {
    std::cout << safe_parse_int("42") << std::endl;  // 42
    std::cout << safe_parse_int("abc") << std::endl; // 0 (hata durumunda)
    return 0;
}

### **Açıklama:**  
- `std::stoi` bir dönüştürme hatası fırlatırsa, fonksiyon **0** döndürür.  
- Böylece, hata durumunda program çökmez ve güvenli bir varsayılan değerle çalışmaya devam eder.

## **Özet**  

- **Wide contract** fonksiyonlar, her durumda güvenli ve tahmin edilebilir çalışmayı sağlar.  
- **Hatalar ya istisna ile yönetilir ya da varsayılan değerler döndürülür.**  
- **Undefined behavior’a yer verilmez**, bu da güvenliği artırır.  
- Performansın biraz daha az önemli, ancak **güvenliğin ön planda** olduğu durumlarda kullanılır.  
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Zombie Object (Zombi Nesne) Nedir?**  

Bir **zombie object (zombi nesne)**, ömrü tamamlanmış veya geçersiz hale gelmiş, ancak hâlâ bellekte erişilebilir olan bir nesnedir. 
Böyle nesneler genellikle artık **geçerli** veya **kullanılabilir** değildir, ama programda kalan **yanlış kullanımlar** sonucunda erişilmeye çalışılır. 
Bu durum, beklenmedik hatalar ve belirsiz davranışlara (undefined behavior) yol açabilir.  

Zombi nesneler, özellikle nesne yönetimi ve dinamik bellek kullanımının hatalı olduğu durumlarda ortaya çıkar. Örneğin:  
- **Destructor çağrıldıktan sonra** nesneye erişim sağlanır.  
- **Kopyalama veya taşıma işlemlerinde** kaynak yönetimi düzgün yapılmaz.  
- **Bellek serbest bırakıldıktan** sonra o alana erişilmeye çalışılır (dangling pointer).  

## **Nasıl Zombi Nesne Oluşur?**  

1. **Destructor Çalıştıktan Sonra Erişim:** Nesne yok edildiğinde, referans hâlâ ona işaret ediyor olabilir.
2. **Dinamik Bellek Kullanımında Hatalar:** Bellek serbest bırakıldıktan sonra göstericiyle aynı nesneye erişilmeye çalışılır.
3. **Kopyalama ve Taşıma Semantiği Sorunları:** Bir nesne kaynaklarını başka bir nesneye devrettikten sonra eski nesneye yanlışlıkla erişim.
4. **Invalid State (Geçersiz Durum):** Bir nesne kısmen bozulmuş olabilir ve artık fonksiyonlarının kullanılmaması gerekir.

## **Örnek 1: Destructor Sonrası Erişim (Zombi Nesne)**  

Bu örnekte, bir nesne yok edildikten sonra hâlâ erişilmeye çalışılır.

#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Constructor called." << std::endl;
    }

    ~Test() {
        std::cout << "Destructor called." << std::endl;
    }

    void printMessage() {
        std::cout << "This is a valid object." << std::endl;
    }
};

int main() {
    Test* obj = new Test();  // Dinamik olarak nesne oluşturuluyor
    delete obj;              // Nesne yok ediliyor

    // Destructor sonrası nesneye erişim (zombi nesne)
    obj->printMessage();  // Undefined behavior
    return 0;
}

### **Açıklama:**  
- `delete` ile `obj` bellekten siliniyor.
- Ancak daha sonra `obj` üzerinden `printMessage()` çağrıldığında **undefined behavior** ortaya çıkıyor, çünkü `obj` bir **zombi nesne**.

## **Örnek 2: Dangling Pointer ve Zombi Nesne**  

Bir gösterici, bellekteki serbest bırakılmış bir alana işaret etmeye devam ettiğinde **dangling pointer** olur ve böyle nesneler zombi nesne olarak kabul edilir.

#include <iostream>

void createAndDestroy() {
    int* ptr = new int(42);
    std::cout << "Value: " << *ptr << std::endl;
    delete ptr;  // Bellek serbest bırakıldı

    // ptr artık geçersiz ama ona tekrar erişilmeye çalışılıyor
    std::cout << "Dangling pointer: " << *ptr << std::endl;  // Undefined behavior
}

int main() {
    createAndDestroy();
    return 0;
}

### **Açıklama:**  
- `ptr` göstericisi, serbest bırakıldıktan sonra aynı bellek alanına erişmeye çalışır.
- Bu durum **dangling pointer** problemine yol açar ve nesne **zombi** hâline gelir.

## **Zombi Nesne Sorunlarını Nasıl Önleriz?**

1. **Belleği Zamanında ve Doğru Şekilde Serbest Bırak:** `delete` işlemlerinden sonra göstericiyi **`nullptr`** yaparak erişimi engelleyin.  

   delete ptr;
   ptr = nullptr;  // Geçersiz belleğe erişimi engeller
   
2. **Akıllı Göstericiler (Smart Pointers) Kullanın:** `std::unique_ptr` ve `std::shared_ptr` gibi akıllı göstericilerle dinamik bellek yönetimini kolaylaştırın.

   std::unique_ptr<int> ptr = std::make_unique<int>(42);

3. **Move Semantiği ve Taşıma Yapıcılarını Doğru Kullanın:** Nesne taşındıktan sonra eski nesnenin kullanılmadığından emin olun.
   
4. **Boşaltılmış Nesneye Erişimi Engelleyin:** Taşınan nesnelerin durumunu kontrol edin ve geçersiz durumda olan nesnelerle işlem yapmaktan kaçının.

## **Örnek 3: Akıllı Gösterici Kullanımı ile Sorunu Çözmek**  

#include <iostream>
#include <memory>

class Test {
public:
    Test() {
        std::cout << "Constructor called." << std::endl;
    }

    ~Test() {
        std::cout << "Destructor called." << std::endl;
    }

    void printMessage() {
        std::cout << "This is a valid object." << std::endl;
    }
};

int main() {
    std::unique_ptr<Test> obj = std::make_unique<Test>();  // Akıllı gösterici kullanımı
    obj->printMessage();

    // Akıllı gösterici ile destructor otomatik çağrılır.
    return 0;
}

### **Açıklama:**  
- `std::unique_ptr` kullanımı, belleği otomatik olarak serbest bırakır ve **zombi nesne** oluşumunu engeller.

## **Özet**  

- **Zombie object (zombi nesne)**, ömrü tamamlanmış veya geçersiz hale gelmiş, ancak hâlâ erişilen bir nesnedir.
- Bu durum, **undefined behavior** ve program çökmelerine yol açabilir.
- **Dangling pointer** kullanımı ve yanlış bellek yönetimi zombi nesneye neden olabilir.
- **Akıllı gösterici kullanımı** ve **nullptr ataması** gibi yöntemlerle bu sorunlardan kaçınabilirsiniz.

Zombi nesneleri önlemek için bellek ve nesne yönetimine dikkat etmek, özellikle **C++** gibi düşük seviyeli dillerde çok önemlidir.
******************************************************************************************************************************

                                                                             ********* 28-DERS NOTLARI *********

exceptionu yakaladağımızda ne yapıyoruz ?

exception gönderme ihtimali olan herhangi bir fonksiyona çağrı yaptığmızda o fonksiyonun çağrıldığı yerde o exceptionu yakalamak zorundayız gibi bir yanlış
algı var

yapacak bir şey yoksa yakalama!
yapacak bir şeyin varsa yakala sorumluluğmuıuz olması gerekiyor

1.exceptionu yakalarsak terminative bir yaklaşım olur gerekli önemler alınır ve program sonlandırlır
2.expceion yakalanır ve handle edilir nerde yakalanıyorsa orda gerekli işlemler yapılrı fakat o fonksiyonu çağırıan koda karşı sormululk bir şekilde yerine getirilmiş olur
ve program çalışmaya devam eder resumptive yaklaşımdır
3.exception yakalanır exceptiona kısmen müdahele edilir ve exception tekrar gönderilir başka kodlara geri kalan işi bırakır

DİKKAT:Excetpionu rethrow etmek başka
exceptionu translate etmek başka

throw(ifadeli throw statement)
re-throw statement(ifadesiz throw statement)
gönderilen hata nesnesinin kendisini tekrar yakalıyor

void foo(int x)
{
    throw 12;
}

void bar()
{
    try
    {
        foo(15);
    }
    catch (int&r)
    {
        std::cout << "exception caught in function bar\n";
        std::cout << "&r = "<<&r<<'\n';
        throw; // burda r yi throw etmiş olsaydık re-throw olmuş olmayacaktı throw etmiş olucaktık 
                  ömrü o zamana kadar bitmiş olucaktı ve adresleri farklı olucaktı
    }

int main()
{
    try
    {
        bar();
    }
    catch (int&r)
    {
        std::cout << "exception caught in main\n";
        std::cout << "&r = " << &r << '\n';
    }
}

NOT:re-throw statement'ın illa catch bloğunda olma gibi bir zotunluluğu yoktur

re-throw statement yürütüldüğünde ortada gönderilmiş bir exception nesnesi yoksa doğrudan terminate fonksiyonu çağırılır

void bar()
{
    std:cout<<"bar called\n";
    throw;
}

int main()
{
    bar(); //std::terminate fonksiyonu çağırılır
}

exceptionu yakaladığımızda program valid statede kalmalı yoksa program kaynak yada kaynakları sızdırırsa yada program geçerli stateini kaybederse

no guarantee
    basic guarantee
        strong guarantee(basic gurantee'nin üst kümesi basicte olan her şey strongtada olmak zorunda) commit or rollack'i sağlıyor
            nofail guarentee(nothrow) 

stack unwinding neden önemli

bir kaynak kullanıyorsak ve bu kaynağı sınıfa bağlarsak(RAII)

class ResourceUser{};

void foo()
{
    ResourceUser x; 

    bar();

    bu kodlardan herhangi biri exception throw ederse excetion yakalndığında stack unwinding sürecinde x'in destructorı çağırılır
    kayunaklar geri verilmiş olur exception göderilmezse otomatik ömürlü olduğu için destroctırı yine çağırılıacak
}

expcetion gönderildiğinde call caihndeki sstack framedlerde otomaitk ömürlü nesneler oluşturlmuşsa exception yakalndğında programın akışı exceptionun
handle eden koda girmeden stack frameelrde oluşturulan nesneler son çağrılan fonksiyondan ilk çağırılan fonksiyona doğru hepsi için destrucorın çağırılma garantisi var

class Myclass
{
public:
	Myclass()
	{
		mp = new int[100]; // exception gönderilmeden kaynak edinildi ama destroctor çağırılamadığı için kaynak geri verilemedi
		throw std::runtime_error("error");
	}
	~Myclass()
	{
		delete[] mp;
	}
	int* mp{};
};

int main()
{
	try
	{
		Myclass m; // burda aslında tam anlamıyla bir nesne olmadığı için destroctor çağırılmıyor
	    Myclass*p = new Myclass; // ama dinamik ömürlü nesneler için aynı durum geçerli değildir bu nesneyi oluşturucak
                                    constroctır çağırıldığında zaten operator new çağırılmış durumda operator new excetpion throw etseydi
                                    constroctor zaten çağırılmazdı burda dilin sağladığı garanti operator delete fonksiyonun çağırılması
    }
	catch (const std::exception& ex)
	{
		std::cout << "exp " << ex.what() << '\n';
	}

}

constroctırın ana bloğu içinde exception gönderildiğinde o exception yakalansa dahi destroctor çağırılmıyor çünkü dilin kurallarıona göre ortada 
constrot edilen bir nesne yok ama memberlar için bu geçerli değil yukardaki örnekle beraber bunu anlıyoruz

class Member
{
public:
    Member(){}
    ~Member(){}
};

class Nec
{
public:
    Nec() : mp(new Member)
    {
        throw std::runtime_error("error");
    }
    ~Nec()
    {
        delete[] mp;
    }
    Member* mp;
};

böyle bir senaryoda sınıf içinde dinamik ömürlü nesneleri kullanırsak yine delete edilmez bunun yerine smart pointerları kullanmalıyız

function try block
Eğer MIL kısmında initialize edilen memberlardan birinin gönderdiği exceptionu sınıfın constroctırı içinde yakalamak istiyorsam
funnction try bloğunu kullanıyoruz

void func(int x)
try { // hem fonksiyonun ana bloğu hemde try bloğu
    
}

constroctorda function try block kullanırsak MIL ile initalize edilen değerleri yaklaam şansımız olur

constroctor exception throw ettikten sonra expcetion yakalanıacak ve catch yazısının içine giricek ve artık bizim classımızı constroct etme şanımız yok
function try blocun catch bloğunda herhangi bir kod yazmsak derleyici re-throw ediyor

noexceptin 2 kullanımı var bir specifier olarak aynı zamanda da bir operatör olarak

void func()noexcept // specifier 
void func()noexcept(constant expression yazılabilir yani compile timeda üretilecek bir değer ve logic yorumlamaya tabi tutuluacak ve true değer elde edilirse fonksiyon noexcept olarak bildiriliecek
                    ama false değeri üretirse noexcept olarak bildirilmiyecek)  // specifier

noexcept operatörü compile time operatörü yani bununla oluşturlan ifadeler constant expression boolean değer üretiyor 

inf foo(); // noexcept olsaydı true dönerdi

constexpr bool b = noexcept(foo()); // false döner çünkü foo fonksiyonun noexcept garantisi yoktur

int * ptr{nullptr};

constexpr bool b = noexcept(*ptr); // uneveluated context olmasaydı UB ilginç geldi ilk başta ama burda true dönüyor
çünkü pointerı dereference etme ifadeseninin exception throw etme ihtimali yok burda uneveluated context olduğu için

void func(int x) noexcept(bu spicifier)noexcept(Myclass{})); buda operator burda myclass üzerinden logic işlem uygulanacak

noexcept garantisinin ciğnenmesi doğrudan std::terminate'in çağırılmasını gerektiriyor
tamamen programın run time'ına yönelik bir durum bu
--------------------------------------------------------------------------------------------------------------------------------------------------                                                                            
### **Exception Propagation (İstisna İletimi) Nedir?**  

**Exception propagation (istisna iletimi)**, bir fonksiyon veya blokta meydana gelen bir istisnanın, 
**üst seviyedeki çağrıcılara otomatik olarak iletilmesi** sürecidir. C++'ta bir fonksiyon içinde istisna (exception) 
fırlatıldığında, **catch** bloğuyla yakalanmazsa, kontrol akışı bir üst seviyeye geçer ve uygun bir **catch** bloğu bulunana 
kadar bu işlem devam eder. Eğer hiçbir yerde yakalanmazsa, program **`std::terminate`** çağrılarak sonlandırılır.  

## **İstisna İletiminin Temel Yapısı**  

İstisnalar, yakalanana kadar çağrı yığınının (call stack) yukarılarına iletilir. Bu süreçte:

1. Fonksiyon içinde bir **`throw`** ifadesiyle istisna fırlatılır.
2. İstisna yakalanmazsa, kontrol bir üst fonksiyona aktarılır.
3. Uygun bir **catch** bloğu bulunmazsa program sonlandırılır.

### **Örnek 1: İstisna İletimi ve Yakalanması**  

#include <iostream>
#include <stdexcept>

void func3() {
    throw std::runtime_error("Error in func3.");  // İstisna fırlatıldı
}

void func2() {
    func3();  // func3 çağrısı
}

void func1() {
    try {
        func2();  // func2 çağrısı
    } catch (const std::runtime_error& e) {  // İstisna yakalandı
        std::cerr << "Exception caught in func1: " << e.what() << std::endl;
    }
}

int main() {
    func1();  // func1 çağrısı
    return 0;
}

### **Çıktı:**  

Exception caught in func1: Error in func3.

### **Açıklama:**  
- **func3** içinde bir `std::runtime_error` istisnası fırlatılır.
- **func2** bu istisnayı yakalamaz, dolayısıyla kontrol **func1**’e geçer.
- **func1** içinde istisna yakalanır ve hata mesajı ekrana yazdırılır.

## **İstisna İletimi Sürecinde Bellek Temizliği (Stack Unwinding)**  

Çağrı yığını boyunca istisna iletilirken, **stack unwinding** (yığın çözme) işlemi gerçekleşir. 
Yani, fonksiyonlar çağrı sırasına ters şekilde kapanır ve **otomatik nesnelerin destructorları** çağrılır.

### **Örnek 2: Yığın Çözme (Stack Unwinding) ile Destructor Çağrıları**  

#include <iostream>
#include <stdexcept>

class Test {
public:
    Test() { std::cout << "Constructor called." << std::endl; }
    ~Test() { std::cout << "Destructor called." << std::endl; }
};

void func() {
    Test obj;  // Otomatik nesne
    throw std::runtime_error("Exception thrown.");  // İstisna fırlatılıyor
}

int main() {
    try {
        func();  // func çağrısı
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

### **Çıktı:**  

Constructor called.
Destructor called.
Caught exception: Exception thrown.

### **Açıklama:**  
- İstisna fırlatıldığında, yığın çözülür ve `Test` nesnesinin destructor'ı çağrılır.
- Bu, **bellek sızıntısını önlemek** için önemlidir.


## **İstisna İletiminde Dikkat Edilmesi Gerekenler**

1. **Yakala ve Yeniden Fırlat (Catch and Re-throw):** İstisnayı yeniden fırlatarak üst seviyedeki çağrıcıya iletebilirsiniz.  

   try {
       throw std::runtime_error("Error");
   } catch (...) {
       std::cerr << "Handling partially and rethrowing..." << std::endl;
       throw;  // İstisna yeniden fırlatılıyor
   }

2. **`noexcept` Anahtar Kelimesi:** Bir fonksiyonun istisna fırlatmayacağını belirtmek için `noexcept` kullanılabilir. Böyle bir fonksiyon istisna fırlatırsa, program hemen sonlandırılır.  

   void foo() noexcept {
       throw std::runtime_error("This will terminate the program.");
   }

3. **Bellek Temizliği için RAII Kullanımı:** **Akıllı göstericiler** gibi araçlar kullanarak istisna sırasında kaynakların otomatik olarak serbest bırakılmasını sağlayabilirsiniz.

## **İstisna İletimi ve Performans**  

- **İstisnalar performans üzerinde bir miktar olumsuz etki yaratabilir**, çünkü yığın çözme işlemi sırasında destructorlar çağrılır ve kontrol akışı değiştirilir.
- Performansın kritik olduğu durumlarda **istisna tabanlı hata yönetimi yerine döndürülen hata kodları** kullanılabilir.

## **Özet**  

- **Exception propagation (istisna iletimi)**, bir fonksiyon içinde fırlatılan istisnanın yakalanana kadar çağrı yığını boyunca iletilmesidir.
- İstisnalar yakalanmazsa program **`std::terminate`** ile sonlandırılır.
- **Stack unwinding** ile otomatik nesnelerin destructorları çağrılır.
- **İyi tasarlanmış istisna yönetimi**, hataların güvenli ve etkili bir şekilde ele alınmasını sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Rethrow Statement (İstisnayı Yeniden Fırlatma)**

**Rethrow statement**, bir istisnanın (exception) yakalandıktan sonra, üst seviyedeki bir fonksiyona ya da çağırıcıya 
**yeniden fırlatılması** anlamına gelir. Yeniden fırlatma, bir alt seviyedeki fonksiyonun istisnayı tam olarak çözemediği 
ve istisnayı daha üst seviyeye devretmek istediği durumlarda kullanılır. C++’ta bu işlem için **`throw;`** ifadesi kullanılır.

## **Yeniden Fırlatma (Rethrowing) Nasıl Çalışır?**

- **`throw;`**: Aynı istisnayı yakalandığı bloktan yeniden fırlatır.
- **`throw new_exception;`**: Orijinal istisna yerine yeni bir istisna fırlatabilir.

Rethrow kullanırken **catch bloğu içinde yakalanan istisna**, üst seviyede uygun bir `catch` bloğu bulunana kadar çağrı yığını boyunca iletilir.

### **Örnek 1: İstisnayı Aynen Yeniden Fırlatma**  

#include <iostream>
#include <stdexcept>

void func2() {
    throw std::runtime_error("Error occurred in func2.");
}

void func1() {
    try {
        func2();
    } catch (...) {  // Tüm istisnaları yakala
        std::cerr << "Handling exception in func1, rethrowing..." << std::endl;
        throw;  // Aynı istisnayı yeniden fırlat
    }
}

int main() {
    try {
        func1();
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }
    return 0;
}

### **Çıktı:**  

Handling exception in func1, rethrowing...
Caught exception in main: Error occurred in func2.

### **Açıklama:**  
1. **`func2()`** içinde bir `std::runtime_error` istisnası fırlatılır.
2. **`func1()`** içinde bu istisna **catch bloğunda** yakalanır, ancak tam olarak çözülemediği için **`throw;`** ile yeniden fırlatılır.
3. Ana fonksiyon olan `main()` içinde, istisna **catch** bloğunda yakalanır ve işlenir.

### **Örnek 2: Yeni Bir İstisna Fırlatma (İstisna Dönüştürme)**  

#include <iostream>
#include <stdexcept>

void func2() {
    throw std::runtime_error("Original error in func2.");
}

void func1() {
    try {
        func2();
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught runtime_error in func1: " << e.what() << std::endl;
        throw std::logic_error("Converted to logic_error.");
    }
}

int main() {
    try {
        func1();
    } catch (const std::logic_error& e) {
        std::cerr << "Caught logic_error in main: " << e.what() << std::endl;
    }
    return 0;
}

### **Çıktı:**  

Caught runtime_error in func1: Original error in func2.
Caught logic_error in main: Converted to logic_error.

### **Açıklama:**  
- **`func2()`** içinde `std::runtime_error` fırlatılır.
- **`func1()`** bu hatayı yakalar ve **yeni bir `std::logic_error`** fırlatarak üst seviyeye iletir.
- Ana fonksiyon olan `main()` içinde, bu yeni istisna yakalanır ve işlenir.

## **Ne Zaman Rethrow Kullanılır?**

- Bir **alt seviye fonksiyon** yalnızca hata mesajını kaydetmek ister, ancak çözüm için **üst seviyeye iletmek** gerekiyorsa.
- **İstisnayı dönüştürmek** ve daha genel veya anlamlı bir hata mesajı sağlamak gerektiğinde.
- Birden fazla seviyeli hata yönetimi stratejisinde, **her seviyenin kendi sorumluluğu kadarını** yapması gerektiğinde.

## **Rethrow Kullanırken Dikkat Edilmesi Gerekenler**  

1. **`throw;` yalnızca catch bloğu içinde kullanılabilir:**  

   try {
       // ...
   } catch (...) {
       throw;  // Geçerli
   }
   // throw;  // Geçersiz (syntax error)

2. **Bellek Temizliği:** İstisna iletimi sırasında **stack unwinding** işlemi yapıldığı için, 
destructor'ların doğru şekilde çağrıldığından emin olun. **RAII** kullanarak kaynak yönetimi yapmanız önerilir.

3. **Performans:** İstisna fırlatma ve iletimi, performans üzerinde maliyetli olabilir. 
Kritik performans gerektiren yerlerde **istisna yerine hata kodları** kullanmak daha iyi olabilir.

## **Özet**  

- **Rethrow statement**, bir istisnayı yakaladıktan sonra aynı veya farklı bir istisnayı üst seviyedeki fonksiyonlara iletmek için kullanılır.
- `throw;` ile aynı istisna yeniden fırlatılabilir, ya da yeni bir istisna fırlatarak dönüştürülebilir.
- İyi bir hata yönetimi stratejisi ile **istisna iletimi** programın kararlılığını artırır ve daha anlamlı hata mesajları sağlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Exception translation (istisna çevirisi)**, bir kodun bir türden bir istisnayı yakalayıp bunu farklı bir türden istisnaya 
dönüştürme tekniğidir. Bu, bir kütüphanenin veya bir modülün kendine özgü istisna türlerini dış dünyaya daha anlaşılır veya 
bağlama uygun bir şekilde sunmak istediği durumlarda kullanılır.


### **Temel Amaçlar**
1. **Bağlam eklemek:**
   - Bir istisnanın ne zaman ve neden atıldığını açıklamak için daha fazla bilgi eklemek.
2. **Abstraksiyon sağlamak:**
   - Bir kütüphane, dahili uygulamasına özel istisnaları dış dünyaya yansıtmadan bunları kendi genel istisna türlerine dönüştürebilir.
3. **Farklı istisnaları birleştirmek:**
   - Benzer nedenlerden kaynaklanan farklı istisnaları tek bir türde toplamak.

### **Nasıl Çalışır?**

#### Örnek 1: Standart bir istisnayı çevirme

#include <iostream>
#include <stdexcept>
#include <string>

void riskyFunction() {
    throw std::out_of_range("Index out of range");
}

void wrapperFunction() {
    try {
        riskyFunction();
    } catch (const std::out_of_range& e) {
        throw std::runtime_error(std::string("Wrapper error: ") + e.what());
    }
}

int main() {
    try {
        wrapperFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
}

**Çalışma Açıklaması:**
- `riskyFunction` bir `std::out_of_range` istisnası fırlatır.
- `wrapperFunction`, bu istisnayı yakalar ve daha genel bir `std::runtime_error` ile bağlama uygun bir mesaj ekleyerek fırlatır.
- Sonuç olarak, dış kod sadece `std::runtime_error` ile ilgilenir ve daha anlaşılır bir hata mesajı alır.

#### Örnek 2: Bir kütüphanenin özel istisnaları

class FileNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "File not found";
    }
};

void readFile(const std::string& filename) {
    // Simüle edilmiş hata durumu
    if (filename.empty()) {
        throw FileNotFoundException();
    }
}

void openFile(const std::string& filename) {
    try {
        readFile(filename);
    } catch (const FileNotFoundException& e) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
}

int main() {
    try {
        openFile("");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

### **Avantajlar**
- Daha anlaşılır ve bağlama uygun istisna mesajları sağlar.
- Kütüphanelerin veya modüllerin, dahili ayrıntıları dışa vurmadan çalışmasına olanak tanır.
- Uygulama kodunun farklı bileşenlerini birbirinden soyutlar.

### **Dezavantajlar**
1. **İlave karmaşıklık:**
   - İstisna çevirme mantığı, kodun karmaşıklığını artırabilir.
2. **Performans etkisi:**
   - Her istisna çevirme, küçük de olsa bir işlem yükü ekler.
3. **Orijinal istisna bilgilerini kaybetme riski:**
   - İstisnalar doğru bir şekilde çevrilmezse hata ayıklama zorlaşabilir.

Bu teknik, özellikle büyük ölçekli projelerde ve soyutlama seviyesinin önemli olduğu yerlerde faydalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Catch-All Bloğu (`catch(...)`) Nedir?**

C++'ta **`catch(...)`** bloğu, **catch-all (her şeyi yakala)** bloğu olarak adlandırılır. Bu blok, **tüm türdeki istisnaları** 
yakalamak için kullanılır. İstisnanın türü bilinmediğinde veya türü ne olursa olsun bir hata yakalamak ve işlemek istendiğinde 
kullanışlıdır. Ancak, bu blok içinde fırlatılan istisnanın türüne doğrudan erişilemez.

## **Catch-All Bloğunun Temel Kullanımı**

`catch(...)` bloğu, genellikle **programın güvenli bir şekilde sonlandırılması** veya **temel hata yönetimi** yapmak amacıyla kullanılır. 
Eğer programda istisna türünü ayırt etmeden genel bir tepki verilmek isteniyorsa, bu blok etkili olur.

### **Örnek 1: Catch-All Bloğu Kullanımı**

#include <iostream>

void func() {
    throw 42;  // int türünde bir istisna fırlatılıyor
}

int main() {
    try {
        func();
    } catch (...) {  // Tüm istisnaları yakala
        std::cerr << "An exception was caught!" << std::endl;
    }
    return 0;
}

### **Çıktı:**,

An exception was caught!

### **Açıklama:**
- **`func()`** fonksiyonu içinde **`int` türünde** bir istisna fırlatılıyor.
- `main()` içindeki **`catch(...)`** bloğu, türü fark etmeksizin bu istisnayı yakalıyor ve ekrana mesaj yazdırıyor.

## **Catch-All Bloğunun Kullanım Alanları**

1. **Beklenmeyen İstisnaları Yakalamak:**  
   İstisna türünün önceden bilinmediği durumlarda programın güvenli bir şekilde sonlanmasını sağlamak.

2. **Kritik Hata Yönetimi:**  
   Program çökmemesi için tüm istisnaları yakalayıp **kayıt tutmak** veya **temizleme işlemleri** yapmak.

3. **Temizlik İşlemleri (Cleanup):**  
   Yığın çözme (stack unwinding) sırasında bazı kaynakları serbest bırakmak için.

## **Örnek 2: Catch-All ile Temizlik İşlemi**

#include <iostream>

void func() {
    throw std::runtime_error("Runtime error occurred.");
}

int main() {
    try {
        func();
    } catch (...) {
        std::cerr << "An unexpected exception occurred. Cleaning up resources..." << std::endl;
        // Temizlik işlemleri burada yapılır
    }
    return 0;
}

### **Çıktı:**

An unexpected exception occurred. Cleaning up resources...

## **Rethrow ile Kullanımı**

Catch-all bloğunda istisnayı yakaladıktan sonra **`throw;`** ile yeniden fırlatabilirsiniz.

### **Örnek 3: Catch-All ile İstisnayı Yeniden Fırlatma**

#include <iostream>
#include <stdexcept>

void func() {
    throw std::runtime_error("Runtime error occurred.");
}

int main() {
    try {
        try {
            func();
        } catch (...) {
            std::cerr << "Handling exception, rethrowing..." << std::endl;
            throw;  // İstisnayı yeniden fırlat
        }
    } catch (const std::exception& e) {
        std::cerr << "Caught in main: " << e.what() << std::endl;
    }
    return 0;
}

### **Çıktı:**

Handling exception, rethrowing...
Caught in main: Runtime error occurred.

### **Açıklama:**  
- İç blokta **catch-all** kullanarak istisna yakalanıyor, ancak çözüm sağlanmadığı için **`throw;`** ile yeniden fırlatılıyor.
- Dış blokta, bu sefer istisnanın türü (`std::exception`) yakalanıp işleniyor.

## **Catch-All Bloğunun Dikkat Edilmesi Gereken Noktaları**

1. **İstisna Türüne Erişilemez:**  
   `catch(...)` içinde istisnanın türü bilinmez. Eğer tür hakkında bilgi gerekiyorsa, **tip tabanlı `catch` blokları** tercih edilmelidir.

2. **Aşırı Kullanımdan Kaçının:**  
   Tüm istisnaları tek bir blokta yakalamak, bazı hataların fark edilmemesine neden olabilir. 
   Spesifik türdeki istisnalar için ayrı **`catch` blokları** kullanmak daha güvenlidir.

3. **`noexcept` ve İstisnalar:**  
   `catch(...)` bloğu kullanılsa bile, `noexcept` olarak işaretlenmiş fonksiyonlarda istisna fırlatılırsa program **`std::terminate()`** ile sonlandırılır.

## **Özet**

- **`catch(...)`** bloğu, tüm türlerdeki istisnaları yakalamak için kullanılır.
- İstisna türü bilinmediğinde, kritik temizlik işlemleri veya programın güvenli bir şekilde sonlanmasını sağlamak için etkilidir.
- İhtiyaç halinde **`throw;`** ile yakalanan istisna yeniden fırlatılabilir.
- Ancak, aşırı kullanımı hata yönetimini zorlaştırabilir. Spesifik türdeki istisnalar için ayrı `catch` blokları önerilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **C++ Exception Safety Guarantees (İstisna Güvenlik Garantileri)**

İstisna güvenlik garantileri (exception safety guarantees), bir fonksiyon veya işlemin **istisna durumunda 
bile programın beklenen davranışını koruyup koruyamayacağını** belirten kurallardır. Bu garantiler, **bellek sızıntılarını** 
ve **bozulmuş nesne durumlarını** önlemeye yöneliktir. C++’ta üç temel istisna güvenliği seviyesi vardır:  

1. **No Guarantee (Garantisiz)**
2. **Basic Guarantee (Temel Garanti)**
3. **Strong Guarantee (Güçlü Garanti)**

## **1. No Guarantee (Garantisiz)**

- **Açıklama:**  
  Bir fonksiyon, istisna durumunda **herhangi bir güvenlik garantisi sunmaz**. İstisna fırlatıldığında 
  nesnelerin durumu **bozulabilir** ve bu, bellek sızıntılarına veya hatalı duruma yol açabilir.

- **Kullanım:**  
  Eğer fonksiyonun başarısızlık durumunda nesnenin durumunun korunması garanti edilmiyorsa, **no guarantee** sunmuş olur.

### **Örnek: No Guarantee**  

#include <vector>

void append(std::vector<int>& vec, int value) {
    vec.push_back(value);  // Eğer bellek tükenirse, push_back() istisna fırlatabilir
}

int main() {
    std::vector<int> vec;
    append(vec, 42);  // push_back başarısız olursa vec bozulabilir
    return 0;
}

### **Açıklama:**  
Eğer `push_back()` bellek yetersizliği nedeniyle istisna fırlatırsa, `vec` kısmen değiştirilmiş 
ve belirsiz bir durumda kalabilir. Bu, **no guarantee** sunulan bir durumdur.

## **2. Basic Guarantee (Temel Garanti)**

- **Açıklama:**  
  Temel garanti, bir fonksiyonun **istisna fırlatması durumunda programın bozulmayacağını** ve nesnelerin durumlarının 
  **geçerli kalacağını** söyler. Ancak nesnenin içeriği **beklenmedik bir durumda** olabilir.
- **Özellik:**  
  Herhangi bir bellek sızıntısı olmayacağı ve nesnelerin **bozulmamış bir duruma sahip** olacağı garanti edilir, ancak bu durum önceden tahmin edilemeyebilir.

### **Örnek: Basic Guarantee**  

#include <iostream>
#include <vector>

void appendWithGuarantee(std::vector<int>& vec, int value) {
    try {
        vec.push_back(value);  // İstisna fırlatabilir
    } catch (...) {
        std::cerr << "Failed to append. State is still valid." << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    appendWithGuarantee(vec, 42);  // push_back başarısız olursa bile vec geçerli kalır
    return 0;
}

### **Açıklama:**  
Eğer `push_back()` başarısız olursa, **nesne (vektör) geçerli** kalır, ancak ekleme işlemi yapılmaz. Bu durumda program güvenli bir şekilde devam edebilir.

## **3. Strong Guarantee (Güçlü Garanti)**

- **Açıklama:**  
  Güçlü garanti, bir fonksiyonun ya **başarılı olacağını ya da hiçbir değişiklik yapmadan çıkacağını** garanti eder. 
  Yani, istisna fırlatıldığında nesne **orijinal (eski) durumuna geri döner**.
- **Özellik:**  
  Bu garanti, **atomik işlem** olarak da bilinir: ya her şey başarılı olur ya da hiçbir şey değişmez. 
  Bu, güçlü hata dayanıklılığı sağlar, ancak uygulanması zor olabilir.

### **Örnek: Strong Guarantee Kullanımı**

#include <iostream>
#include <vector>

void safeAppend(std::vector<int>& vec, int value) {
    std::vector<int> temp = vec;  // Geçici kopya oluştur
    temp.push_back(value);         // İstisna fırlatabilir
    vec = std::move(temp);         // Başarılı olursa asıl vektörü güncelle
}

int main() {
    std::vector<int> vec;
    try {
        safeAppend(vec, 42);  // İstisna fırlarsa, vec değişmez
    } catch (...) {
        std::cerr << "Append failed. Original state is preserved." << std::endl;
    }
    return 0;
}
### **Açıklama:**  
Bu örnekte, bir geçici kopya kullanarak güçlü garanti sağlanır. Eğer `push_back()` başarısız olursa, **asıl vektör değişmeden kalır**. Bu, güçlü garantinin sağlandığı bir durumdur.

## **Özet Tablosu**

| **Garanti Türü**      | **Açıklama**                                                       | **Örnek Durum**                              |
|-----------------------|--------------------------------------------------------------------|---------------------------------------------|
| **No Guarantee**      | İstisna durumunda nesne bozulabilir veya bellek sızıntısı olabilir | Kısmen değişmiş, belirsiz bir durum        |
| **Basic Guarantee**   | İstisna olsa bile nesne geçerli kalır, ancak beklenmedik bir durumda olabilir | Ekleme işlemi başarısız olur ama nesne bozulmaz |
| **Strong Guarantee**  | İstisna durumunda hiçbir değişiklik yapılmaz, eski durum korunur   | Ya işlem tamamlanır ya da nesne değişmez   |

## **Sonuç**  

- **No guarantee**: Hata durumunda herhangi bir koruma sunmaz.  
- **Basic guarantee**: Programın geçerli bir durumda kalmasını sağlar, ancak beklenmedik içerikler olabilir.  
- **Strong guarantee**: Ya işlem başarıyla tamamlanır ya da nesne orijinal haline döner.

İyi tasarlanmış C++ kodlarında **RAII (Resource Acquisition Is Initialization)** ve **akıllı göstericiler (smart pointers)** 
kullanarak **en az temel garanti** sağlamak yaygın bir yaklaşımdır. Kritik durumlarda **güçlü garanti** sağlanması tercih edilir, ancak uygulaması karmaşık olabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Stack Unwinding (Yığın Çözme) Nedir?**

**Stack unwinding**, C++ programında bir **istisna (exception)** fırlatıldığında, istisnanın yakalanana kadar **çağrı yığını boyunca 
fonksiyonların sırasıyla geri sarılması** sürecine denir. Bu süreçte her fonksiyon sonlandırılırken **otomatik ömürlü nesnelerin 
(local variables)** destructor’ları çağrılır ve bellek sızıntıları veya kaynak sızıntılarının önlenmesi sağlanır.

## **Nasıl Çalışır?**

1. **İstisna fırlatılır**: Bir fonksiyonda `throw` ifadesi ile istisna fırlatıldığında, o fonksiyon hemen sonlandırılır.
2. **Çağrı yığını boyunca geri sarılır**: İstisna yakalanana kadar (örn. `catch` bloğuna ulaşana kadar) program **çağrı yığını** boyunca birer birer fonksiyonlardan çıkar.
3. **Destructor'lar çalışır**: Her fonksiyon çıkarken otomatik ömürlü yerel nesnelerinin **destructor’ları** çağrılır ve kaynaklar serbest bırakılır.
4. **İstisna yakalanır**: Eğer istisna uygun bir `catch` bloğu ile yakalanmazsa, **std::terminate()** çağrılarak program sonlandırılır.

### **Örnek: Stack Unwinding**

#include <iostream>

struct Test {
    Test(const char* name) : name(name) {
        std::cout << "Constructor: " << name << std::endl;
    }
    ~Test() {
        std::cout << "Destructor: " << name << std::endl;
    }
    const char* name;
};

void func2() {
    Test t2("t2");
    throw std::runtime_error("Exception in func2");
}

void func1() {
    Test t1("t1");
    func2();
}

int main() {
    try {
        func1();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

### **Çıktı:**

Constructor: t1
Constructor: t2
Destructor: t2
Destructor: t1
Caught exception: Exception in func2

### **Açıklama:**

1. `func1()` içinde `t1` adlı bir nesne oluşturuluyor.
2. `func1()`, `func2()` fonksiyonunu çağırıyor. `func2()` içinde `t2` adlı bir nesne oluşturuluyor.
3. `func2()` içinde `std::runtime_error` türünde bir istisna fırlatılıyor.
4. **Stack unwinding** başlıyor: 
   - `func2()` sonlandırılırken, `t2` nesnesinin destructor'ı çağrılıyor.
   - `func1()` sonlandırılırken, `t1` nesnesinin destructor'ı çağrılıyor.
5. İstisna `main()` fonksiyonundaki `catch` bloğunda yakalanıyor ve hata mesajı ekrana yazdırılıyor.

## **Neden Önemli?**

- **Kaynak sızıntılarını önlemek:** Destructor'ların çağrılması, açık dosya tanıtıcılarının, bellek veya ağ bağlantılarının doğru şekilde serbest bırakılmasını sağlar.
- **RAII (Resource Acquisition Is Initialization):** Kaynakların otomatik yönetimi için RAII ile birlikte çalışır. 
Bir nesne kapsam dışına çıktığında, destructor'ı kaynakları otomatik olarak temizler.
- **Programın güvenli bir şekilde sonlanması:** Stack unwinding sayesinde, istisnalar sırasında bile program güvenli bir şekilde sonlanır.

## **Stack Unwinding ve Rethrow (İstisnayı Yeniden Fırlatma)**

İstisnayı bir fonksiyonda yakalayıp yeniden fırlatmak mümkündür. Stack unwinding, her yeniden fırlatıldığında tekrarlanır. 

### **Örnek: Rethrow ile Stack Unwinding**

#include <iostream>

struct Test {
    Test(const char* name) : name(name) {
        std::cout << "Constructor: " << name << std::endl;
    }
    ~Test() {
        std::cout << "Destructor: " << name << std::endl;
    }
    const char* name;
};

void func2() {
    Test t2("t2");
    throw std::runtime_error("Exception in func2");
}

void func1() {
    Test t1("t1");
    try {
        func2();
    } catch (...) {
        std::cerr << "Caught exception in func1, rethrowing..." << std::endl;
        throw;  // İstisnayı yeniden fırlat
    }
}

int main() {
    try {
        func1();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception in main: " << e.what() << std::endl;
    }
    return 0;
}

### **Çıktı:**

Constructor: t1
Constructor: t2
Destructor: t2
Caught exception in func1, rethrowing...
Destructor: t1
Caught exception in main: Exception in func2

### **Açıklama:**  
1. `func2()` istisna fırlatır ve `t2`’nin destructor'ı çağrılır.
2. `func1()` içinde istisna yakalanır, ancak tekrar fırlatılır (**rethrow**).
3. Rethrow ile birlikte `func1()` sonlandırılır ve `t1`’in destructor'ı çağrılır.
4. `main()` içinde istisna yakalanır ve işlenir.

## **Stack Unwinding’de Karşılaşılan Sorunlar**

1. **İstisna Fırlatan Destructor:**  
   Destructor içinde bir istisna fırlatılırsa ve aynı anda bir başka istisna da çözülüyorsa, **std::terminate()** çağrılır.
   
   struct Bad {
       ~Bad() { throw std::runtime_error("Exception in destructor"); }
   };

2. **Çift İstisna Durumu:**  
   Aynı anda iki farklı istisna çözümlenmeye çalışıldığında program **sonlandırılır**. Bu yüzden destructor'ların istisna fırlatmaması gerekir.
## **Özet**

- **Stack unwinding**, istisnalar sırasında çağrı yığını boyunca fonksiyonların birer birer çözülmesi ve **nesnelerin destructor'larının çağrılması** işlemidir.
- Bu süreç, bellek veya kaynak sızıntılarını önlemek için kritik öneme sahiptir.
- **RAII** prensibi ile birlikte stack unwinding, kaynakların otomatik yönetimini sağlar.
- Destructor’ların istisna fırlatmadığından emin olunmalıdır; aksi halde **std::terminate()** çağrılır.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++’da **function try block** (fonksiyon-try bloğu), bir fonksiyonun tamamını veya bir yapıcı fonksiyonun (constructor) 
**üye başlatma listesi** dahil tüm başlangıç işlemlerini bir `try-catch` yapısıyla sarmaya olanak tanır. Bu yapı, özellikle 
**constructor** ve **destructor** işlemlerinde faydalıdır, çünkü nesnelerin başlatılması veya yok edilmesi sırasında oluşabilecek hataları yakalamayı sağlar.

### **Nasıl Çalışır?**  
1. **Yapıcı Fonksiyonlar (Constructors):** Üye başlatma listesinde veya fonksiyon gövdesinde bir istisna oluşursa, function try block içindeki `catch` bloğu bunu yakalayabilir. 
   - Örneğin, bir üyenin yapıcı fonksiyonunda bir hata oluştuğunda bu hata function try block kullanılarak yönetilebilir.

2. **Yıkıcı Fonksiyonlar (Destructors):** Destructor sırasında oluşan istisnalar da function try block tarafından yakalanabilir. 
Ancak destructor’larda birden fazla istisna fırlatılmasına dikkat edilmelidir; aksi takdirde program `std::terminate` ile sonlanır.

### **Örnek: Constructor'da Kullanım**

#include <iostream>
#include <string>

struct S {
    std::string m;

    S(const std::string& str, int idx)
    try : m(str, idx) {
        std::cout << "S(" << str << ", " << idx << ") oluşturuldu, m = " << m << '\n';
    } catch (const std::exception& e) {
        std::cout << "S(" << str << ", " << idx << ") başarısız: " << e.what() << '\n';
    }
};

int main() {
    try {
        S s1{"ABC", 1};  // Başarılı (geçerli indeks)
        S s2{"ABC", 4};  // Hata (geçersiz indeks)
    } catch (const std::exception& e) {
        std::cout << "Hata yakalandı: " << e.what() << '\n';
    }
    return 0;
}

### **Açıklama:**
- **Başlatma Listesi:** Yapıcı fonksiyon içindeki başlatma sırasında (`: m(str, idx)`), `str` dizin dışıysa istisna fırlatılır. 
Bu istisna, function try block içindeki `catch` bloğu tarafından yakalanır. 
- **Destructor’lar:** Destructor'da function try block kullanıldığında, üye nesneler ve taban sınıflar yok edildikten sonra `catch` bloğu çalışır.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **`noexcept` Spesifikatı ve Operatörü**  
C++11 ile tanıtılan `noexcept` anahtar kelimesi, belirli bir fonksiyonun **istisna fırlatmayacağını** 
belirtmek için kullanılır. İki temel kullanımı vardır: **noexcept spesifikatı** ve **noexcept operatörü**.

## **1. `noexcept` Spesifikatı**  
- Bir fonksiyonun **istisna atmayacağını garanti** eder.  
- Derleyiciye optimizasyon yapma fırsatı verir; çünkü istisna beklenmediğinde bazı kontrol mekanizmaları atlanabilir.  
- Eğer böyle bir fonksiyondan istisna fırlatılırsa, program `std::terminate` ile sonlanır.

### **Kullanım Örneği:**

void func() noexcept {
    // Bu fonksiyon hiçbir zaman istisna atmaz.
}

- `noexcept` spesifikatı, özellikle **destructor** ve **taşıma (move) fonksiyonları** gibi yerlerde yaygın olarak kullanılır. 
  Örneğin:

  ~MyClass() noexcept = default;

## **2. `noexcept` Operatörü**  
`noexcept` operatörü, bir ifadenin **istisna fırlatıp fırlatmadığını** derleme zamanında kontrol eder. Operatörün sonucu, bir **bool** değeri (`true` veya `false`) döndürür.

### **Kullanım Örneği:**

bool canThrow = noexcept(func());  // func() istisna atmazsa true döner.

- Bu operatör, fonksiyonların **noexcept durumu hakkında bilgi** almayı sağlar ve koşullu noexcept kullanımı için idealdir. 

### **Koşullu `noexcept`:**

template <typename T>
void func(T&& obj) noexcept(noexcept(T(std::forward<T>(obj)))) {
    // Yalnızca move constructor'ı noexcept olan türler için noexcept olur.
}

Bu örnekte, fonksiyonun `noexcept` durumu, içindeki `T` türünün taşıma işleminin `noexcept` olup olmamasına bağlıdır. 

## **`noexcept` Kullanımının Faydaları:**
- **Optimize edilmiş kod üretimi:** Derleyici, istisna mekanizması ile ilgili ek yüklerden kaçınabilir.
- **Güvenilir kod tasarımı:** İstisna atmadığını garanti eden fonksiyonlar açıkça belirtilir.
- **Program sonlanması:** İstisna atan `noexcept` fonksiyonlarda, program güvenli bir şekilde `std::terminate` ile kapanır.
******************************************************************************************************************************

                                                                             ********* 29-DERS NOTLARI *********
NOT:Destructor ve constroctor default olarak noexcepttir

destroctor exception thorw etmemeli etse bile programın akışı destroctordan dışarı çıkmamalı yani yakalamalı

move constroctırın ve move assignment'ın noexcept olması gerekiyor performans açısından  

bütün swap fonksiyonlarının noexcept olması gerekir
memory deallocation fonksiyonlarının noexcept olması gerekir
--------------------------------------------------------------------------------------------------------------------------------------------------
virtual fonksiyonlarda base classın bir fonksiyonu noexcept ise onu override eden derived classlardada noexcept bildirilmesi gerekir 
çünkü override ettiği fonksiyon gibi aynı garantiyi vermesi gerekiyor

class Base
{
public:
    virtual void foo() noexcept;
};

class Der : Base
{
public:
    void foo() noexcept override;
};
--------------------------------------------------------------------------------------------------------------------------------------------------
std::exception sınıfının what fonksiyonu noexcept'tir override ettiğimiz zaman noexcept specifierını kullanmamız gerekir
--------------------------------------------------------------------------------------------------------------------------------------------------
fonksiyon pointerların noexcept ile bildirilirse o fonksiyona noexcept ile bildirilmiş bir fonksiyonun adresi atanabilir

int foo(int)noexcept;
inf (*fp)(int)noexcept = &foo;

ama tam tersi sorun değil

inf (*fp)(int) = &foo; 

noexcept imzanın bir parçası ama overloadingte kullanılamaz
--------------------------------------------------------------------------------------------------------------------------------------------------
meta functionlar:compile timeda hesaplama yapar sınıftırlar

type_traits sınıfı örnek

class Myclass
{
public:
    virtual void func() noexcept;
};

template<typename T>
void func(T)noexcept(std::is_nothrow_default_constructible_v<T>);

int main()
{
    constexpr auto b = noexcept(func(Myclass{})); // func'ın noexcept olma koşulu Myclass sınıfının constroctırın noexcept olması

}
--------------------------------------------------------------------------------------------------------------------------------------------------
move constroctırın exception yapmanın önemi 2 bin tane A karakterini tutan bir stringin kopyalanması ve taşınmasında ki büyük maliyet farkı

class Nec
{
public:
    Nec() : ms(2'000,'A'){}
    Nec(const Nec& other) : ms(other.ms){}
    Nec(const Nec&& other) : ms(std::move(other.ms)){}
    //Nec(const Nec&& other) noexcept : ms(std::move(other.ms)){}
private:
    std::string ms;
};

int main()
{
    using namespace std::chrono;

    std::vector<Nec> vec(100'000);

    auto start = steady_clock::now();

    vec.resize(vec.capacity() + 1); // kapasitesini arttırarak başka bellek bloğuna reallacation oluyor bunun yerine reserve fonkiyonunu kullanmak daha
                                        mantıklı fakat örnek için kullandık

    auto end = steady_clock::now();

    std::cout << duration<double, std::milli>(end - start).count() << "ms\n";

}

Move constroctor burda çağırılmıyor copy constroctor çağırılıyor 

copy constroctor: 354 ms;

noexcept olana copy constroctırı yorum satırından kaldırdıktan sonra tekrar çalıştırıdığımda

move ctor: 294 ms;

generic kodlarda derleyicinin kod seçimi burda compile timeda koda bakarak en iyi hangisiyse onu seçiyor o yüzden copy ctor çağırılmıyor
--------------------------------------------------------------------------------------------------------------------------------------------------
exception ptr sınıfı

polymorphic bir pointer gibi davranıyor exception ptr sınıfı türünden bir nesnede bir exception nesnesini polymorhpic olarak tutabiliyoruz
belirli bir hiyerarşisi olduğu için

hatayı yakalıyoruz yakaldağımız hata nesnesini bir expcetion ptrye bağlıyoruz sonra o nesneyi başka bir koda göndererek onun tutuğu expcetionu tekrar göndermesini
sağlayarak o exceptionu handle edebiliyoruz

void handle_exception(std::exception_ptr eptr)
{
    try
    {
        if (eptr) // eptr boş değilse rethrow_exception ile exception gönderilecek
        {
            std::rethrow_exception(eptr);
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "expception caught" << ex.what()<<'\n';
    }

}

int main()
{
    std::exception_ptr ep;

    try
    {
        std::string str{ "emre" };
        auto c = str.at(35);
    }
    catch (...)
    {
        ep = std::current_exception(); // exceptionu exception_ptr ye dönüştüren fonksiyon
        handle_exception(ep);
    }
}
--------------------------------------------------------------------------------------------------------------------------------------------------
polymorphic exception idiom

class EBase
{
public:
    virtual ~EBase() = default;
    virtual void raise()
    {
        throw *this;
    }
};

class Der1 : public EBase {
public:
    virtual void raise() override
    {
        throw *this;
    }
};

class Der2 : public EBase
{
public:
    virtual void raise() override
    {
        throw* this;
    }
};

void foo(EBase& ex)
{
    ex.raise();
}

int main()
{

    try
    {
        Der1 der1;
        foo(der1);
    }
    catch (Der1&) { std::cout << "Der1\n"; }
    catch (Der2&) { std::cout << "Der1\n"; }
    catch (...) { std::cout << "catch all\n"; }

}
--------------------------------------------------------------------------------------------------------------------------------------------------
exception dispatcher idiom

class NecException
{

};

class ErgException
{

};

class CSDException
{

};

void handle_exception()
{
    try
    {
        throw;
    }
    catch (NecException&)
    {

    }
    catch (ErgException&)
    {

    }
    catch (CSDException&)
    {

    }

}
void func()
{
    try
    {

    }
    catch (...)
    {
        handle_exception();
    }
}
--------------------------------------------------------------------------------------------------------------------------------------------------
generic programlama- veya TMP(template meta progrramnig) STL(Standart Template Library)

derleyicye compile timeda kod yazdırmak(run tineda kod çağırılır)

//specialization(açılım)
    bir templetten elde edilen ürünün kendsi o şablonunun bir sepcaizliationudır(conceptler hariç)

function template
    derleyice fonksiyon kodu yazdırır (modern cpp önceside vardı)

class template
    derleyice sınıf kodu yazdıran templateler (modern cpp önceside vardı)

variable template(c++14 ile eklendi)
    derleyice değişken tanımı yaptırır

alias template
    derleyice bir tür eş ismi bildirimi yaptıran template

concept(c++20)

template parameters
    type parameter -> türe karşılık gelir(int,float gibi)

        template<typename T> // ikisi arasında bir fark yok sadece tek bir fark var burdada class kullanılmıyor sonra bahsedilecek
        template<class T>

    non-type parameter -> tür olmayan bir parametre
        template<int x>(c++20 den önce hataydı) buna gelen tür constant expression olmalı

    template paremeter
        template parameteri parameter pack ile oluşturulan templateler variadic template 

template argument class yada typename olabilir

derleyici template parametreleri için kullanılan argümanların neler olacağını 3 şekilde bilir
    deduction (CTAD) CLASS TEMPLATE ARGUEMNT DEDUCTION
    explicit template arguement->türlerin açık açık yazılması vector<int> gibi
    default template argument

c++17 öncesinde decution sadece function templateler için deduction vardı
c++17 de CTAD akronimi ile class templatelerin tür çıkarımını yapabiliyoruz
--------------------------------------------------------------------------------------------------------------------------------------------------
SOLID Prensipleri
**SOLID**, yazılım geliştirme sırasında **esnek**, **bakımı kolay** ve **uzatılabilir** kod yazmayı hedefleyen 5 temel tasarım prensibidir. 
Bu prensipler, özellikle nesne yönelimli programlama (OOP) yaparken, kodun daha anlaşılır ve sürdürülebilir olmasını sağlar. Aşağıda, SOLID prensipleri C++ perspektifinde detaylandırılmıştır:

### 1. **S - Single Responsibility Principle (SRP)**  
**Tek Sorumluluk İlkesi:** Bir sınıfın yalnızca **tek bir sorumluluğa** sahip olması gerektiğini belirtir. 
Bu, her sınıfın yalnızca bir amaca hizmet etmesini ve bir tür değişikliğin yalnızca bir sınıfı etkilemesini sağlar.  

**C++ Örneği:**

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

class Order {
    Logger logger;  // Order sadece loglama için Logger'ı kullanır.
public:
    void processOrder() {
        // Sipariş işleme kodu...
        logger.log("Order processed.");
    }
};

- **Kural ihlali:** Eğer `Order` sınıfı hem sipariş işleme hem de loglama işlemini içerirse, tek sorumluluk ilkesini ihlal etmiş olur.

### 2. **O - Open/Closed Principle (OCP)**  
**Açık/Kapalı İlkesi:** Bir sınıf **genişletmeye açık**, ancak **değişikliğe kapalı** olmalıdır. 
Yani, mevcut kodu değiştirmek yerine, yeni işlevsellik eklemek için kodun genişletilebilmesi sağlanmalıdır.

**C++ Örneği:**

class Shape {
public:
    virtual double area() const = 0;  // Polimorfizm ile genişletilebilir.
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.1415 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

- Yeni şekiller eklemek için mevcut kodu değiştirmemize gerek yoktur; sadece yeni sınıflar eklenir.

### 3. **L - Liskov Substitution Principle (LSP)**  
**Liskov Yerine Geçme İlkesi:** Bir alt sınıf, üst sınıfın her yerde kullanılabileceği şekilde davranmalıdır. 
Yani, bir türetilmiş sınıf, taban sınıfının tüm işlevlerini **bozmadan** yerine geçebilmelidir.

**C++ Örneği:**

class Bird {
public:
    virtual void fly() const {
        std::cout << "Flying..." << std::endl;
    }
};

class Sparrow : public Bird {};
class Ostrich : public Bird {
public:
    void fly() const override {
        throw std::runtime_error("Ostriches can't fly!");  // LSP ihlali!
    }
};

- Burada, `Ostrich` sınıfı, `Bird` sınıfının yerine geçemediği için LSP ilkesini ihlal eder.

### 4. **I - Interface Segregation Principle (ISP)**  
**Arayüz Ayrımı İlkesi:** Bir sınıf, kullanmadığı işlevleri içeren geniş arayüzlere bağımlı olmamalıdır. Bunun yerine, **küçük ve spesifik arayüzler** kullanılmalıdır.

**C++ Örneği:**

class IPrinter {
public:
    virtual void print() const = 0;
};

class IScanner {
public:
    virtual void scan() const = 0;
};

class MultiFunctionPrinter : public IPrinter, public IScanner {
public:
    void print() const override { std::cout << "Printing..." << std::endl; }
    void scan() const override { std::cout << "Scanning..." << std::endl; }
};

- Burada `IPrinter` ve `IScanner` arayüzlerinin ayrılması, gereksiz işlevlere bağımlılığı önler.

### 5. **D - Dependency Inversion Principle (DIP)**  
**Bağımlılıkları Ters Çevirme İlkesi:** Üst düzey modüller, alt düzey modüllere doğrudan bağımlı olmamalıdır; her ikisi de **soyutlamalara bağımlı** olmalıdır.

**C++ Örneği:**

class IMessage {
public:
    virtual void sendMessage(const std::string& msg) const = 0;
};

class Email : public IMessage {
public:
    void sendMessage(const std::string& msg) const override {
        std::cout << "Email: " << msg << std::endl;
    }
};

class Notification {
    const IMessage& messageService;
public:
    Notification(const IMessage& service) : messageService(service) {}
    void notify(const std::string& msg) {
        messageService.sendMessage(msg);
    }
};

int main() {
    Email emailService;
    Notification notification(emailService);
    notification.notify("Hello, World!");
    return 0;
}

- Burada, `Notification` sınıfı doğrudan `Email` sınıfına değil, `IMessage` arayüzüne bağımlıdır. Böylece, başka tür mesaj servisleri (örneğin SMS) eklenebilir.

### **Sonuç: SOLID ve C++**  
C++'da **SOLID prensipleri**, kodun **daha esnek, yeniden kullanılabilir ve bakım yapılabilir** olmasını sağlar. 
Bu prensipleri uygulayarak yazılım geliştiriciler, değişen gereksinimlere kolayca uyum sağlayan ve yüksek kalitede yazılım çözümleri üretebilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **Exception Dispatcher Nedir?**

C++'da **exception dispatcher**, farklı kod blokları veya iş parçacıkları (threads) arasında istisnaların yakalanması, saklanması 
ve yeniden fırlatılmasını (propagation) sağlayan mekanizmadır. Bu mekanizma, özellikle eşzamanlı programlama ve iş parçacıkları 
arasında hataların güvenli şekilde aktarılmasını sağlar. 

C++11 ile tanıtılan **`std::exception_ptr`** ve ilgili fonksiyonlar (örn. `std::current_exception` ve `std::rethrow_exception`), 
istisnaları yakalamak ve başka yerlerde yeniden fırlatmak için kullanılır. Böylece, istisnalar kaybolmadan ve türleri bozulmadan doğru bir şekilde yönetilir.

### **Exception Dispatcher için Örnek**

Aşağıdaki örnek, bir iş parçacığında oluşan istisnayı yakalayıp başka bir fonksiyona ileterek nasıl ele alındığını gösterir:

#include <iostream>
#include <exception>
#include <thread>

// İş parçacığında oluşan istisnayı yakalayıp iletecek bir fonksiyon
void thread_function(std::exception_ptr& eptr) {
    try {
        throw std::runtime_error("İş parçacığında hata oluştu!");
    } catch (...) {
        eptr = std::current_exception();  // İstisnayı yakala
    }
}

// İstisnayı ele alacak ana fonksiyon
void handle_exception(std::exception_ptr eptr) {
    try {
        if (eptr) {
            std::rethrow_exception(eptr);  // İstisnayı yeniden fırlat
        }
    } catch (const std::exception& e) {
        std::cout << "İstisna yakalandı: " << e.what() << '\n';
    }
}

int main() {
    std::exception_ptr eptr;

    // Yeni bir iş parçacığı başlat ve istisnayı yakala
    std::thread t(thread_function, std::ref(eptr));
    t.join();  // İş parçacığının tamamlanmasını bekle

    // Ana iş parçacığında istisnayı ele al
    handle_exception(eptr);

    return 0;
}

**Çıktı:**

İstisna yakalandı: İş parçacığında hata oluştu!

### **Çalışma Mantığı**  
1. **İstisna Yakalama:** İş parçacığı içinde bir hata oluştuğunda, `std::current_exception()` kullanılarak geçerli istisna yakalanır ve `std::exception_ptr` içine saklanır.  
2. **İstisna Fırlatma:** Daha sonra, `std::rethrow_exception()` ile bu işaretçi kullanılarak istisna yeniden fırlatılır.  
3. **Ana İş Parçacığında İşleme:** İstisna, ana iş parçacığında yakalanır ve düzgün bir şekilde işlenir.
--------------------------------------------------------------------------------------------------------------------------------------------------
### **CTAD (Class Template Argument Deduction) Nedir?**  

**CTAD**, C++17 ile tanıtılan bir özelliktir ve **sınıf şablonlarının (template class)** argümanlarının otomatik olarak çıkarılmasına 
olanak tanır. Normalde, şablon sınıflarının tür parametreleri belirtilmelidir. Ancak CTAD sayesinde, derleyici bu türleri **başlangıç verilerine** 
veya yapıcı fonksiyonlara bakarak otomatik olarak tahmin eder.

### **CTAD Örneği**  
Aşağıdaki kod, CTAD’ın nasıl çalıştığını gösterir:

#include <iostream>
#include <utility>  // std::pair

int main() {
    std::pair p(42, 3.14);  // std::pair<int, double> türetilir.
    std::cout << "p.first = " << p.first << ", p.second = " << p.second << '\n';
    return 0;
}

**Çıktı:**
* 
p.first = 42, p.second = 3.14

Bu örnekte `std::pair` için türler (`int` ve `double`) açıkça belirtilmemiştir. Derleyici, **`42`'yi `int`**, **`3.14`'ü ise `double`** 
olarak tanıyarak `std::pair<int, double>` türünü çıkarır. CTAD, bu şekilde kodun daha sade yazılmasını sağlar.

### **CTAD'ın Kullanım Alanları ve Avantajları**  
- **Sade Kod:** Argümanları açıkça belirtme ihtiyacını ortadan kaldırarak kodu kısaltır.
- **Hata Azaltma:** Yanlış şablon parametresi vermekten kaynaklanan hataların önüne geçer.
- **Esneklik:** CTAD, hem STL sınıflarında (`std::pair`, `std::tuple` gibi) hem de kullanıcı tanımlı sınıflarda kullanılabilir.

### **Kullanıcı Tanımlı Sınıflarda CTAD Örneği**  

template <typename T>
struct A {
    A(T x, T y) : first(x), second(y) {}
    T first, second;
};

int main() {
    A a{1, 2};  // Tür otomatik olarak A<int> olur.
    std::cout << "a.first = " << a.first << ", a.second = " << a.second << '\n';
    return 0;
}

Bu örnekte `A` sınıfı için tür belirtmeden nesne oluşturulmuştur. Derleyici, sağlanan `1` ve `2` değerlerine göre türü **`A<int>`** olarak çıkarır.

Daha fazla bilgi için:

CTAD, özellikle STL şablon sınıflarıyla çalışırken oldukça kullanışlıdır ve kodun okunabilirliğini artırır
******************************************************************************************************************************

                                                                             ********* 30-DERS NOTLARI *********
Derleyici templatelerde çağırılmayan fonksiyonun kodunu yazmaz


template argümanlarının ne olacağını belirlemenin en az 3 yolu var

1)template argument deduction
    function template
    CTAD(c++17 ile gelişme yaşandı) 
2)explicit template argument
3)default template argument

Derleyiceler templatelree ilişkin sentaks kontrolünü bir kaç farklı aşamada yapıyorlar

1.aşama
template kod kullanılmadan templatein kendisi üstünde yapılıyor yani derleyicinin deduction yapmak için yeterli bilgisi yok
template<typename>
void func(T x)
{
    foo(x);// T türünün ne olduğna bağlı olarak ADL İle aranabilir hata vermez 
    bar(15); // Template paramteresine karşılık gelen template arghümanının ne olduğuna bağlı değil namelookup hatası verir
}

2.aşama
template argument deduction söz konusuysa bu deductionun yapılamama ihtimali var bu durumda eğer template parametlerine karşılık gelen template argümanının
ne olduğu anlaşılamazzsa derleyici hata verir

template<typename T> template parameter oluyor template ait parametre
T func(); burdada parametre olursa call parameter fonksiyonun parametresi yani

int main()
{
    func(); // derelyici burda T türünün ne olduğunu bilmediği için sentaks hatası verir 
}

ufak bir auto ya değiniş

int ival = 5;
auto y = ival; // burda tür çıkarımı auto içi yapılıyor y için değil burda auto için yapılan tür çıkarımı
belli olduktan sonra y'nin değeri belli olucak

auto &y = ival; // referans dekleratörü olduğunda işler değişiyor burda auto için yapılan tür çıkarımı int olucak ama y için
yapılan tür çıkarımı int&

func(ival) // auto için yapılan tür çıkarımı neyse template parametredede aynı

template parameter default argument alabilir ama varsayılan argümana bağlı olarak bir tür çıkarımı mümkün değil

template<typename T>
void foo(T x = 0)

int main()
{
    foo(); // hata
}

template<typename T>
void foo(T f)
{
    f(); // callable deniliyor fonksiyon çağrı operatörünün operandı olabilen varlıklar
            T türünün çıkarımını function pointer yaparsa derleyicinin yazdığı kodda fonksiyonun parametere değişkeni function pointer
            olucak ve biz bu function pointerın gösterrdiği fonksiyonu çağırmış olucaz
}

void bar() {
    std::cout << "bar\n";
}

int main()
{
     foo(bar); // function pointer olarak çağırılır bar çıktısı alınır
}

ama callable illa fonksiyon adresi olmak zorunda değil bir class olsaydı ve function call operatoru overload etmiş olsaydı

class Myclass
{
public:
    int operator()(int);
};

int main()
{
    Myclass m;//functor class dendiğini hatırlayalım
     foo(m); //T türü Myclass türü olucak
}

fonksiyonun geri dönüş değerini fonksiyonu çağıran koda geçme

template<typename ReturnType,typename T,typename U>
ReturnType sum(T x,U y)
{
    return x + y;

int main()
{
    auto val = sum<double>(5.7, 3); // fonksiyonun geri dönüş değerini explicit olarak belirttik 

}
    std::cout << "val = " << val<<'\n';
}

geri dönüş değerleri için 2 farklı araç daha var
   
    trailing return type tür eş ismi belirtmeden fonksiyonun geri dönüş değerini daha kolay belirtmeyi sağlıyor
        fonksiyonun geri dönüş yerine auto keywordünü yazıyoruz  parametere parantezibnin kapanmasından sonra
        arrow tokwnini yazıp fonksiyonun geri dönüş türünü yazıyoruz
        auto foo() -> int{}
        auto foo() -> int (*)(int){}
        auto foo() -> int (&)[5]{}
        
    trailing return type ile yazmazsak daha uzun olanı

    int ar[10];
    int(& foo())[10]
    { return ar;} // 10 elemannlı bir referans diziyi döndürüyor genelde c de pointer türünde
                     böyle kullanılıyor
     
function pointerlarını using bildirimi ile de bildirebiliriz ama trailing return type daha kullanışlı olabilir

int bar(int);
int baz(int);

int(*foo())(int){}

using fptr = int(*)(int);

fptr foo(fptr f)
{
    return &bar;
}

int main()
{
    auto f = foo(&baz);
}

tenplate <typename T,typename U
auto foo(T x,U y) -> decltype(x + y)// burda x ile y yi toplamak istersem ve o türe göre geri dönüş değeri olsun istersek böyle kullanılırz
{
    
}
    auto return type
        tenplate <typename T,typename U
        auto foo(T x,U y) { return x + y;} // derleyici fonksiyonun geri dönüş değeri türünü return türüne göre çıkarım yapıyor 

templatelerde function overlaod resolution
    template <typename T>
    void foo(T){std::cout << "function template " << typeid(T).name() << '\n';}

    void foo(int){std::cout << "void func(int)\n";}

    int main()
    {
	    foo(4.5);// function template fonksiyon yazıcak
	    foo(4u); // function template yeni fonksiyon yazıcak
	    foo(4); // free fonksiyon çağırılacak tam uyum sağlarsa bu çağırılıyor ama sağlamazsa
                   çağırılmaz template yeni fonksiyon yazar
    }

öyle bir fonksiyon olsun ki int dışında her hangi bir değerle çağırıldığı zaman sentaks hatası olsun

  template<typename T>
  void foo(T) = delete;

  void foo(int){}

  int main()
  {
    foo(3.4)//hata
    foo('A')//hata
    foo(4)//geçerli
  }

  partial ordering rules (partial specialization ile karıştırma)
    paramteresi en uygun olan template seçilir

  template <typename T>
  void foo(T) { std::cout << "foo(T)\n"; }

  template <typename T>
  void foo(T*) { std::cout << "foo(T *)\n"; }

  int main()
  {
    int x = 5;
    foo(5); // T //sadece T * olsaydı hata verirdi
    foo(&x); // T * // T * olmasa bile T çalışırdı 
  }

  fubnction overlaod resolutiona templatelerin kendisi girmez templatelerden oluşturulan fonksiyonlar giriyor
******************************************************************************************************************************

                                                                             ********* 31-DERS NOTLARI *********

template instantiation(derleyicinin template koddan template specializationunu oluşturması)
    implicit instantiation
    explicit instantiation
--------------------------------------------------------------------------------------------------------------------------------------------------
abbreviated template syntax
    kısaltılmış template sentaksı c++20 ile geldi

    void foo(auto x){} // buda bir template aslında auto dönüş türü olarak kullanılsaydı auto return type olurdu
--------------------------------------------------------------------------------------------------------------------------------------------------
bir sınıf generic olmasada yani template olmasada sınıfın static yada non-static üye fonksiyonları function template olabilir

class Myclass{
    public:
    void foo(auto x); yada

    template <typename T>
    void foo(T);
}
--------------------------------------------------------------------------------------------------------------------------------------------------
auto return type ufak not

auto foo(int x);

int main()
{
    auto val = foo(5); // sentaks hatası çünkü auto return type'ta foo fonksiyonun içindeki return değerine göre türü belli olucak
}

auto foo(int x)
{
	return x; // burda x int olduğu için autonun türü int olucak
}

auto geri dönüş değeri varsa fonksiyon içinde birden fazla farklı türde return ifadesi varsa derleyici sentaks hatası olarak değerlendirir

auto foo(int x)
{
	if(x < 10)
		return x;
	else
		return 5.5;
}

template<typename T>
class Myclass
{
public:

};

int main()
{
    Myclass<int> m1;
    Myclass<double> m2;

    m2 = m1;

}
aynı templatten elde edilen specializationlar tamamen farklı sınıflar bunların arasında ipmlicit conversion yok biz yazmadığımız sürece

copy ctor yada mtor tanımlarsak farklı türleri birbirine atayabiliriz
template<typename T, typename U>
struct Pair
{
    Pair() = default;
    template<typename T,typename U>
    Pair(const Pair<T, U>&) {} // copy ctor

    T first;
    U second;
};

int main()
{
    Pair<double, double> pd;
    Pair<int, int> pi;

    pd = pi;

}
Aynı türden olmadıkları için implicit conversion yok ve Myclas'ın kendisi class değildir ondan üretilen sınıflar classtır m1 ve m2 int olsaydı atama hata vermicekti

templatelerde bildirim yaparken template aprametresine isim vermemek daha iyi olabilir
template<typename>
class Myclass;

template classların fonksiyon tanımını yapmak

template<typename T>
class Myclas{
public:
	T foo(T x); // decleration
}

template<typename T> // definition
T Myclass<T>::foo(T x)
{

}

Sınıf şablonunun ismini kullanmak specializationu kullanmak demek

template<typename T>
class Myclass {
public:
    Myclass<T> foo(Myclass<T>){}
    Myclass bar()
    {
        Myclass m;
        //Myclass <T> m // yazmak ile yukardakini yazmak arasına bir fark yok;
        std::cout << typeid(m).name() << '\n';
        return m;
    }
};

int main()
{
    Myclass<int> x; // yukarda ki Myclass'ın specializationu
    x.bar(); // burada bar fonksiyonnunda ki m instance'ı int specialization olacak
}

template<typename T> // template parameterda && olsaydı universal reference olurdu
class Myclass{
    public:
	void func(T &&){} // burda T && rvalue reference universal referance değil çünkü func'ın kendisi bi template değil

}

template<typename T>
void func(T &&) {} // burda universal reference olurdu çünkü func'ın kendisi bir template ama const volatile veya herhangi bir specifier koyarsak
universal reference olmaktan çıkar

template<typename T>
void func(const T&&) //universal ref değil rvalue

template<typename T>
void func(std::vector<T> &&) //universal ref değil rvalue

template<typename T>
class Myclass {
public:
    template<typename U>
    Myclass foo(Myclass<U> p)
    {
        std::cout << typeid(*this).name() << '\n'; // *this burda Myclass<int> x oluyor
        std::cout << typeid(p).name() << '\n'; // p burda Myclass<double> y oluyor
    }
};

int main()
{
    Myclass<int> x;
    Myclass<double> y;

    x.foo(y);

}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p)
{
    return os << "[" << p.first << "," << p.second << "]";
}

int main()
{
    using namespace std;
    pair<pair<int, double>, pair<string, long>> p{ {12,3.4},{"murat",34L} };

    cout<<p;

}
derleyici templatten pair için bir kod yazıcask burda template parametresi pair türünden first'ü yazdırırken pair<int,double> türünden olduğu için
bunun içinde bir fonksiyon yazıcak diğeri içinde öyle toplam 3 tane fonksiyon yazıcak
--------------------------------------------------------------------------------------------------------------------------------------------------
C++20'de eklenen **concept** kavramı, şablon parametrelerinin belirli kriterlere uygun olup olmadığını kontrol etmek için kullanılır. 
Concept'ler, şablon kodu daha okunabilir ve güvenilir hale getirir. Bir concept, parametre olarak verilen türlerin istenilen özelliklere 
veya kısıtlamalara sahip olup olmadığını denetler.  

Örnek:  

template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T add(T a, T b) { return a + b; }

Bu örnek, yalnızca tam sayı türlerini kabul eden bir fonksiyon tanımlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
**Parameter pack**(Variadic templates), C++ şablonlarında (templates) birden fazla parametreyi esnek şekilde kabul etmek için kullanılır. 
Özellikle **variadic templates** ile birlikte çalışır ve istenilen sayıda tür veya değer parametresi alınmasını sağlar. 

Örnek:  

template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n';
}

Bu kod, herhangi sayıda parametreyi alıp ekrana yazdırabilir. **Parameter pack** kullanımı, şablonların daha genel ve esnek olmasını sağlar.

*Pack expansion*, C++'ta *variadic templates* (değişken sayıda parametre alan şablonlar) ile kullanılan bir özelliktir. 
Bu özellik, bir şablonun çok sayıda tür veya parametre ile çalışmasını sağlar. *Pack expansion* (`...` üç nokta operatörü ile ifade edilir), 
bir tür paketi (`typename... Ts`) veya parametre paketi (`Args... args`) içindeki her bir öğe üzerinde genişletme işlemi yapar.

### 1. `Pack Expansion` ile Variadic Function Template Kullanımı

Bu örnekte, `print_all` adlı bir fonksiyon, değişken sayıda argüman alır ve her bir argümanı sırayla ekrana yazdırır.

#include <iostream>

template <typename... Args>
void print_all(Args... args) {
    (std::cout << ... << args) << '\n';  // Fold expression: tüm argümanlar arasında `<<` operatörü uygulanır
}

int main() {
    print_all(1, 2, 3, "Hello", 4.5);  // 1 2 3 Hello 4.5
}

Bu örnekte `Args... args`, bir parametre paketidir ve `print_all` fonksiyonu içine gelen tüm argümanları içerir. 
`(std::cout << ... << args)` ifadesi, tüm argümanlara `<<` operatörünü uygulayan bir *fold expression* (katlama ifadesi) kullanarak `args` parametre paketini genişletir.

### 2. Tür Paketi ile `Pack Expansion`

Tür paketleri ile de `pack expansion` yapılabilir. Aşağıdaki örnekte, her bir türün boyutunu hesaplamak için tür paketi (`Ts...`) genişletilir.

#include <iostream>

template <typename... Ts>
void print_sizes() {
    (std::cout << ... << (sizeof(Ts) << " ")) << '\n'; // Fold expression ile genişletme
}

int main() {
    print_sizes<int, double, char>(); // 4 8 1 (int, double, char türlerinin boyutları)
}

Bu örnekte, `Ts...` bir tür paketidir. `sizeof(Ts)...` ile her bir türün boyutu hesaplanır ve ekrana yazdırılır. 
Çıktı, her bir türün `sizeof` değeri olacaktır.

### 3. `Pack Expansion` ile Recursive Function (Özyinelemeli Fonksiyon)

Değişken sayıda argüman alan bir fonksiyonu özyinelemeli olarak çağırmak için *pack expansion* kullanılabilir. 
Örneğin, tüm argümanları ayrı ayrı işleyen bir fonksiyon yazabiliriz:

#include <iostream>

void print() {
    std::cout << "No more arguments\n";
}

template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << ' ';
    print(args...); // Recursive çağrı: args paketi genişletilir
}

int main() {
    print(1, 2.5, "Hello", 'c'); // 1 2.5 Hello c
}

Bu örnekte, `print` fonksiyonu değişken sayıda argüman alır. İlk argümanı (`first`) işledikten sonra, geri kalan 
`args...` parametreleriyle kendisini özyinelemeli olarak çağırır. Son argümana ulaşıldığında, `print()` fonksiyonu çağrılır ve "No more arguments" mesajını basar.

### 4. `std::initializer_list` ile `Pack Expansion`

`std::initializer_list` ile `pack expansion`, tüm argümanları bir listeye yerleştirip genişletmek için kullanılabilir.

#include <iostream>

template <typename... Args>
void print_all(Args... args) {
    std::initializer_list<int>{ (std::cout << args << " ", 0)... }; // Pack expansion with initializer list
    std::cout << '\n';
}

int main() {
    print_all(1, 2, 3, 4); // 1 2 3 4
}

Bu örnekte `args...`, `std::initializer_list` ile genişletilmiştir. `std::initializer_list<int>{ (std::cout << args << " ", 0)... };` 
ifadesi, tüm `args` öğeleri için `std::cout << args << " "` işlemini gerçekleştirir ve ardından `0` döndürür.
******************************************************************************************************************************

                                                                             ********* 32-DERS NOTLARI *********

templatelerde function definition

template <typename T>
class Myint
{

    Myint& set(T x);
};

template<typename T>
Myint<T>& Myint<T>::set(T x)
{
    return *this;
}
--------------------------------------------------------------------------------------------------------------------------------------------------                                                                      
template classlarda constructorun tanımını yaparken açısal parantez kullanılmaz

templete <typename T>
class Myint
{
    public:
    Myint(int);
}

template<typename T>
Myint<T>::Myint(int){}
--------------------------------------------------------------------------------------------------------------------------------------------------
templatelerde static veri elemanları her instance için farklı bir specializationdur 

template<typename T>
class Nec
{
public:
     static int ms;
};

template<typename T>
int Nec<T>::ms{ 0 };

int main()
{
    ++Nec<int>::ms; 
    ++Nec<double>::ms;
    // iki ms farklı bir instance'dır
}
--------------------------------------------------------------------------------------------------------------------------------------------------
23.35
--------------------------------------------------------------------------------------------------------------------------------------------------
templatelerde nested typeları tanımlamak

template<typename T>
class Myclass
{
public:
    class Nested; // forward decleration
};

template<typename T>
class Myclass<T>::Nested // nested class definition
{};
--------------------------------------------------------------------------------------------------------------------------------------------------
non-type parameter olarak auto keywordünü kullanmak

template<auto N>
class Myclas{
    public: 
};

Myclass<10> m1;
Myclass<10.5> m2; // c++20 ile legal oldu
--------------------------------------------------------------------------------------------------------------------------------------------------
non-type parametrenin türleri
    template<int N> // tam sayı türü
    template<int (*fp)(int)> // function pointer
    template<int (Myclass::*)(int)> // member function pointer
    template<int* p> // gelen adres static ömürlü olmak zorunda
    template<int& r> // referans türü
    template<Color c> // enum türü enum Color {blue,white}

non-type parametre

--------------------------------------------------------------------------------------------------------------------------------------------------
sınıfın non-static veri elemanının adresini bir function pointerda tutabiliriz

class Myclass
{
public:
    int foo(int x){return x;}
};

int main()
{
    int (Myclass:: * fp) (int) = &Myclass::foo;
    Myclass m;
    std::cout<<(m.*fp)(10);

}
--------------------------------------------------------------------------------------------------------------------------------------------------
explicit template specialization örnek

template<typename T>
T getmax(T x, T y)
{ return x > y ? x : y; }

template<> // diamond deniliyor popüler olarak
const char* getmax<const char*>(const char* x, const char* y)
{ return std::strcmp(x, y) > 0 ? x : y; }

int main()
{

    const char* x = "emree";
    const char* y = "asli";

    std::cout << getmax(x, y) << '\n';
}
--------------------------------------------------------------------------------------------------------------------------------------------------
2.explicit template specialization örneği

template<typename T>
void foo(T) { std::cout << "primary template\n"; }

template<>
void foo(int) { std::cout << "int specialization\n"; }

template<>
void foo(double) { std::cout << "double specialization\n"; }


int main()
{
    foo(34L); // primary template
    foo(34); // int specialization
    foo(34.5); // double specialization 
}
--------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
struct Myclass {
    Myclass() {
        std::cout << "primary template\n";
    }
    void foo() {}
};

template<>
struct Myclass<int>
{
Myclass() {
		std::cout << "int specialization\n";
	}
    void bar() {}
    void baz() {}

};

int main()
{
    Myclass<int> m1;
    m1.bar();
    m1.baz();
}

ama illaki primary template ile aynı arayüze sahip olmasına gerek yoktur explicit specialization olan
tempaltede başka fonksiyonlarda olabilir

primary template'in complete type olması gerekmiyor

template <typename T>
class Nec;
--------------------------------------------------------------------------------------------------------------------------------------------------
function overload resolutiona primary templateler girer explicit template girmez
 
explicit template specialization'ın nerde olduğu önemlidir

template<typename T>
void func(T) { std::cout << 1 << '\n'; } // bu template'in altında olsaydı bunun explicit template'i olucaktı

template<typename T>
void func(T*) { std::cout << 2 << '\n'; }

template<>
void func(int *) { std::cout << 3 << '\n'; } // T*'ın altında olduğu için int* primary template'in explicit template'i oluyor

int main()
{
    int* p = nullptr;

    func(p);
}
--------------------------------------------------------------------------------------------------------------------------------------------------
partial specialization(diamond kullanılmaz) sadece sınıf şablonları için var fonksiyon şablonları için yok

template <typename T>
struct Myclass {
    Myclass(){std::cout << "primary template\n";}
};

template<typename T>
struct Myclass<T*> {
    Myclass(){std::cout << "artial specialization\n";}
};


int main()
{
    Myclass<int> m1; // primary
    Myclass<int*> m2; // partial
}



--------------------------------------------------------------------------------------------------------------------------------------------------
C++'te `std::lexicographical_compare`, iki aralığı leksikografik (sözlük sırasına göre) karşılaştırmak için kullanılan bir algoritmadır. 
Bu fonksiyon, `std::mismatch` veya `operator<` gibi karşılaştırma işlemlerine dayanarak iki aralığı karşılaştırır.

### **Sözdizimi**

#include <algorithm>

bool std::lexicographical_compare(
    InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2);

veya özel bir karşılaştırıcıyla:

bool std::lexicographical_compare(
    InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    Compare comp);

### **Açıklama**
- İki aralığı **karakter karakter** veya **eleman eleman** karşılaştırır.
- `first1` ve `first2` dizilerini soldan sağa karşılaştırarak ilerler.
- Eğer bir eleman **diğerinden küçükse** ilk aralığın daha küçük olduğunu döndürür (`true`).
- Eğer tüm elemanlar eşitse ve birinci dizi ikinciye göre daha kısaysa yine `true` döndürür.
- Tüm elemanlar eşitse ve uzunluk da eşitse `false` döner.
- Eğer `Compare comp` sağlanırsa, elemanları karşılaştırmak için bu özel fonksiyonu kullanır.

### **Örnek Kullanım**

#include <iostream>
#include <algorithm>

int main() {
    char a[] = "apple";
    char b[] = "banana";

    if (std::lexicographical_compare(std::begin(a), std::end(a) - 1,
                                     std::begin(b), std::end(b) - 1)) {
        std::cout << "apple < banana" << std::endl;
    } else {
        std::cout << "banana <= apple" << std::endl;
    }

    return 0;
}

**Çıktı:**

apple < banana

### **Özel Karşılaştırıcı Kullanımı**

#include <iostream>
#include <algorithm>
#include <cctype>

// Küçük harfleri büyük harf olarak değerlendiren karşılaştırıcı
bool caseInsensitiveCompare(char a, char b) {
    return std::tolower(a) < std::tolower(b);
}

int main() {
    char a[] = "Apple";
    char b[] = "banana";

    if (std::lexicographical_compare(std::begin(a), std::end(a) - 1,
                                     std::begin(b), std::end(b) - 1,
                                     caseInsensitiveCompare)) {
        std::cout << "Apple < banana (case-insensitive)" << std::endl;
    } else {
        std::cout << "banana <= Apple (case-insensitive)" << std::endl;
    }

    return 0;
}

**Çıktı:**

Apple < banana (case-insensitive)

### **Kullanım Senaryoları**
- **String karşılaştırmaları:** Alfabetik sıralama için kullanılır.
- **Sıralı veri yapıları için karşılaştırmalar:** Özel sıralama algoritmalarında kullanılabilir.
- **Özel karşılaştırmalar:** Küçük-büyük harf duyarsız sıralama gibi.

C++'ta **std::lexicographical_compare** genellikle **std::set, std::map** gibi sıralı kapsayıcılarda öğelerin karşılaştırılmasında da kullanılır.

******************************************************************************************************************************

                                                                             ********* 33-DERS NOTLARI *********


template'in member templateini kullanmak

template <typename T>
struct Myclass
{
    template<typename U>
    void func(U)
    {
        std::cout << "type T is" << typeid(T).name() << '\n';
        std::cout << "type U is" << typeid(U).name() << '\n';
    }

};

template<>
template<> // garip sentaks
void Myclass<double>::func(int) 
{
    std::cout << "Specialization for double and int\n";
}

int main()
{
    Myclass<double> x;
    x.func(3.4);
}
--------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------
**Dependent name** (bağımlı isim), C++'ta şablon (template) kullanımı sırasında, şablon parametrelerine bağlı olarak değişen türler, 
üyeler veya değişken isimlerini ifade eder. Şablonlar derlenirken, derleyici bu isimlerin hangi türe karşılık geldiğini tam olarak bilemeyebilir. 
Bu nedenle, bağımlı isimleri doğru yorumlamak için ek bilgiye ihtiyaç duyabilir.


template <typename T>
void func(T t) {
    typename T::value_type x; // 'value_type' burada bağımlı bir isimdir
}

Bu örnekte, `T::value_type`, `T` tipi belirlenmediği sürece tam olarak çözülemez. `value_type`, `T` türüne bağlı bir isim olduğu için derleyici, 
bu ismi bir tür olarak anlaması gerektiğini bilmelidir. Bu nedenle `typename` anahtar kelimesiyle belirtilir.

Bu örnekte, `func` fonksiyonu bir şablon fonksiyonudur. `T` tür parametresine bağlı olarak, `T::value_type` ifadesi bir tür olabilir, 
fakat bu durum ancak `T`'nin hangi tür olduğuna bağlı olarak belirlenir. Örneğin, `T` türü bir konteyner (örneğin `std::vector<int>`) ise `value_type` 
burada `int` olur. Ancak, derleyicinin `T::value_type`'i tür olarak yorumlaması için `typename` anahtar kelimesiyle bu isim belirtildi.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)`typename` anahtar kelimesi, C++’ta özellikle şablonlarda (templates) türleri belirtmek için kullanılır. 
`typename`, türü (type) belirtmek için kullanılan `class` ile benzer bir anlam taşır, ancak bazı durumlarda `typename` 
kullanımı zorunlu veya daha uygun olur.

### 1. Tür Parametrelerini Belirtmek için
Şablon tanımlarında, tür parametreleri belirtmek için `typename` veya `class` kullanılabilir.

template <typename T>
void func(T x) {
    // ...
}

Burada `func` fonksiyonu bir şablon fonksiyonudur ve herhangi bir tür `T` ile çağrılabilir.

### 2. Bağımlı Türleri Belirtmek için
Şablonlarda `typename` daha çok bağımlı türlerin (`dependent type`) belirtiminde kullanılır. 
Şablonun içinde başka bir şablondan türetilmiş bir tür varsa, bu türü belirtmek için `typename` zorunludur.

template <typename T>
void func(typename T::value_type x) {
    // ...
}

Bu örnekte `T::value_type` ifadesinin bir tür olduğunu belirtmek için `typename` kullanılıyor.

### 3. Şablon İçinde İç İçe Tür Tanımları
Bir şablon türünün altındaki bir başka türden bahsederken de `typename` kullanılır. Aksi takdirde, 
derleyici `T::iterator` ifadesinin bir tür mü yoksa bir değişken mi olduğunu ayırt edemez.

template <typename T>
void func(T container) {
    typename T::iterator it = container.begin();
    // ...
}

Bu durumda, `T::iterator` bir tür olduğu için `typename` ile belirtilmiştir.

### 4. Şablonların Şablon Parametreleri
Bir şablon parametresi başka bir şablon türüne ait bir tür olduğunda, `typename` kullanılarak şablon parametreleri tanımlanabilir:

template <typename T, typename U = typename T::value_type>
void func(T container, U value) {
    // ...
}

Bu örnekte `U`, `T` türüne ait bir alt tür olan `value_type` ile varsayılan olarak ayarlanır.
--------------------------------------------------------------------------------------------------------------------------------------------------
3)C++20 ile birlikte gelen *concepts* ve *constraints*, şablonların (template) belirli gereksinimlerle kısıtlanmasını sağlar. 
*Constraint* (kısıtlama), bir şablonun sadece belirli türlerle çalışmasını zorunlu kılar, böylece daha güvenilir ve anlaşılır bir kod yazılabilir. 

### 1. `requires` İfadesi ile Kısıtlama
Bir şablonun, belirli bir koşulu sağlaması gerektiğini belirtmek için `requires` anahtar kelimesi kullanılabilir.

#include <concepts>
#include <iostream>

template <typename T>
requires std::integral<T> // T, integral bir tür olmalı
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4) << '\n';     // Geçerli: int integral bir tür
    // std::cout << add(3.5, 4.2);      // Geçersiz: double integral bir tür değil
}

Bu örnekte, `add` fonksiyonu sadece `std::integral` (*integer* tipi) olan türler için geçerlidir. 
`requires` ifadesi ile bu türlerin integer (tam sayı) olması gerektiği belirtilmiştir.

### 2. Şablon Parametrelerinde Doğrudan `concept` Kullanımı
Bir concept, şablon parametresinde doğrudan kullanılabilir. Bu durumda `requires` ifadesine gerek kalmaz.

#include <concepts>
#include <iostream>

template <std::integral T> // T, doğrudan integral tür olmak zorunda
T subtract(T a, T b) {
    return a - b;
}

int main() {
    std::cout << subtract(10, 3) << '\n'; // Geçerli
    // std::cout << subtract(10.0, 3.5);  // Geçersiz: double integral değil
}

Bu örnekte `std::integral T` ifadesi, `T` türünün doğrudan bir integral tür olmasını gerektirir. 
Böylece fonksiyon, sadece tam sayı türleriyle çağrılabilir.

### 3. Kullanıcı Tanımlı Concepts ile Kısıtlama
Kendi `concept` tanımınızı yaparak daha özel kısıtlamalar oluşturabilirsiniz.

#include <iostream>
#include <type_traits>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>; // Arithmetic concept tanımı

template <Arithmetic T> // T, sadece arithmetic (sayısal) bir tür olmalı
T multiply(T a, T b) {
    return a * b;
}

int main() {
    std::cout << multiply(4, 5) << '\n';       // Geçerli: int arithmetic bir tür
    std::cout << multiply(3.14, 2.5) << '\n';  // Geçerli: double arithmetic bir tür
    // std::cout << multiply("abc", "def");     // Geçersiz: string arithmetic bir tür değil
}

Bu örnekte `Arithmetic` adında bir `concept` tanımlanmıştır ve `std::is_arithmetic_v` ile sayısal türler için geçerlidir. 
`multiply` fonksiyonu yalnızca sayısal türler (`int`, `float`, `double`, vb.) ile çalışabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
4) C++'ta *template default argument* (şablon varsayılan argümanları), bir şablonun tür parametrelerine varsayılan değer atayarak, 
kullanıcıların belirli bir parametreyi belirtmeden şablonu kullanmalarını sağlar. Bu, şablonları daha esnek hale getirir 
ve bazı durumlarda gereksiz kod tekrarı yapmadan işlerinizi kolaylaştırır.

### 1. Şablon Tür Parametresi için Varsayılan Argüman Tanımlama

Bir şablon türü tanımlarken, `T` tür parametresinin varsayılan bir değeri olabilir:

#include <iostream>
#include <string>

template <typename T = int> // T için varsayılan tür int
class MyClass {
public:
    T value;
    MyClass(T v) : value(v) {}
};

int main() {
    MyClass<> obj1(10);          // int olarak varsayılan, T=int
    MyClass<double> obj2(3.14);   // T=double olarak belirtilmiş
    
    std::cout << "obj1.value: " << obj1.value << '\n';
    std::cout << "obj2.value: " << obj2.value << '\n';
}

Bu örnekte, `MyClass` şablonunun `T` tür parametresi varsayılan olarak `int`'tir. `obj1` oluşturulurken tür parametresi 
belirtilmediği için `T=int` olarak kabul edilir, ancak `obj2` için `double` olarak belirlenmiştir.

### 2. Şablon Parametre Listesinde Birden Fazla Varsayılan Argüman

Bir şablonda birden fazla tür parametresi varsa, birden fazla varsayılan değer atayabilirsiniz. 
Ancak, varsayılan değeri olmayan parametreler varsayılan olanlardan önce gelmelidir.

#include <iostream>

template <typename T1, typename T2 = double, typename T3 = int>
class MyTemplate {
public:
    T1 a;
    T2 b;
    T3 c;
    MyTemplate(T1 x, T2 y, T3 z) : a(x), b(y), c(z) {}
};

int main() {
    MyTemplate<char> obj('A', 2.5, 100);           // T1=char, T2=double, T3=int
    MyTemplate<int, float> obj2(1, 3.14f, 42);     // T1=int, T2=float, T3=int
    
    std::cout << "obj.a: " << obj.a << ", obj.b: " << obj.b << ", obj.c: " << obj.c << '\n';
    std::cout << "obj2.a: " << obj2.a << ", obj2.b: " << obj2.b << ", obj2.c: " << obj2.c << '\n';
}

Bu örnekte, `MyTemplate` üç tür parametresine sahip ancak yalnızca `T1` zorunlu; `T2` ve `T3` için varsayılan olarak `double` 
ve `int` atanmıştır. Bu sayede şablon, bazı parametreler belirtilmeden de kullanılabilir.

### 3. Şablon Fonksiyonlarında Varsayılan Argümanlar

Şablon fonksiyonları için de varsayılan argüman kullanılabilir. Bu, şablon parametresi varsayılan bir değere 
sahip olduğunda fonksiyon çağrılarında tür belirtmeden de kullanılmasını sağlar.

#include <iostream>

template <typename T = int>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add<>(5, 10) << '\n';      // T=int varsayılan, çıktısı 15
    std::cout << add<double>(3.5, 4.2) << '\n'; // T=double olarak belirtilmiş, çıktısı 7.7
}

Bu örnekte, `add` fonksiyonunun şablon tür parametresi `T` varsayılan olarak `int` türündedir. 
`add<>(5, 10)` çağrısında `T` belirtilmediği için `int` olarak kabul edilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
5)*Explicit instantiation* (açık örnekleme), şablonların belirli türler için derleme sırasında bir defa oluşturulmasını 
sağlamak amacıyla kullanılan bir tekniktir. Normalde, C++ derleyicisi bir şablonun örneğini yalnızca gerekli olduğunda oluşturur. 
Ancak bazen, performans veya kod organizasyonu gibi nedenlerle bir şablon örneğinin belirli türler için açıkça oluşturulmasını isteyebiliriz. 
Bu durumda, *explicit instantiation* (açık örnekleme) yapılır.

*Explicit instantiation* iki türde olabilir:

1. **Explicit Instantiation Declaration (Açık Örnekleme Beyanı):** Derleyiciye bir şablon örneğinin dışarıda bir yerde var olacağını söyler.
2. **Explicit Instantiation Definition (Açık Örnekleme Tanımı):** Derleyiciye şablonun belirli türler için örneğini oluşturmasını söyler.

### Explicit Instantiation Declaration ve Definition

#include <iostream>

template <typename T>
class MyClass {
public:
    void print() const {
        std::cout << "MyClass instance of type " << typeid(T).name() << '\n';
    }
};

// MyClass<int> sınıf şablonunun açık örnekleme tanımı
template class MyClass<int>;  // Explicit instantiation definition for MyClass<int>

int main() {
    MyClass<int> obj; // MyClass<int> şablon örneği, yukarıdaki açık örneklemeden kullanılır
    obj.print();
}

Bu örnekte:
- `template class MyClass<int>;` ifadesi, `MyClass<int>` için bir **explicit instantiation definition**’dır. 
Bu ifade, `MyClass` şablonunun `int` türü için tam bir örneğini oluşturur.
- `main` fonksiyonu içerisinde `MyClass<int> obj;` ifadesi ile `int` türünde `MyClass` nesnesi oluşturulur. 
Açık örnekleme tanımı sayesinde, `MyClass<int>` şablonu daha önce derlendiği için derleyici `MyClass<int>`'i yeniden örneklemez.

### Explicit Instantiation Declaration Kullanımı

Eğer yalnızca derleyiciye bir şablon örneğinin başka bir yerlerde tanımlı olduğunu belirtmek isterseniz, 
explicit instantiation declaration kullanabilirsiniz. Bu, `.h` dosyasındaki bildirimlerle `.cpp` dosyasındaki tanımları ayırmanıza olanak tanır.

#### Örnek: 

`MyClass.h` başlık dosyasında:

#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

template <typename T>
class MyClass {
public:
    void print() const;
};

// MyClass<int> sınıf şablonunun açık örnekleme beyanı
extern template class MyClass<int>; // Explicit instantiation declaration

#endif // MYCLASS_H

`MyClass.cpp` kaynak dosyasında:

#include "MyClass.h"
#include <typeinfo>

template <typename T>
void MyClass<T>::print() const {
    std::cout << "MyClass instance of type " << typeid(T).name() << '\n';
}

// MyClass<int> sınıf şablonunun açık örnekleme tanımı
template class MyClass<int>; // Explicit instantiation definition

Bu örnekte:
- `extern template class MyClass<int>;` ifadesi bir **explicit instantiation declaration**’dır. `MyClass<int>` örneğinin başka bir dosyada tanımlı olduğunu belirtir.
- `template class MyClass<int>;` ifadesi ise **explicit instantiation definition**’dır ve `MyClass<int>` için tam bir örnek oluşturur. 
Bu sayede, `MyClass<int>` örneği yalnızca bir kez derlenir ve `.h` dosyasında tekrar derlenmesine gerek kalmaz.

Bu kullanım, derleme süresini azaltır ve `.cpp` dosyalarında gereksiz tekrar örneklemelerin önüne geçer.
******************************************************************************************************************************

                                                                             ********* 34-DERS NOTLARI *********
1)Value ve Valu type farkı
C++'ta şablonlarda kullanılan `value` ve `value type`, şablon parametrelerinin türlerini ve değerlerini ifade eder, ancak farklı amaçlara hizmet ederler.

- **Value (Değer) Parametreleri**: Sabit bir değeri temsil eder. `int`, `char` veya `bool` gibi türler için değer parametreleri kullanılabilir. 
`value` parametreleri, şablonun kullanıldığı yerde bir sabit değer olarak belirlenir.
  
- **Type (Tür) Parametreleri**: Belirli bir türü temsil eder. `typename` veya `class` anahtar kelimeleri ile tanımlanır ve bir türü temsil eder.

İşte `cppreference` sitesine benzer bir açıklama ve örnekler:

### 1. Value Parametresi (Değer Parametresi)

Şablon parametresi olarak bir değer alabiliriz. Aşağıdaki örnekte `Array` sınıfı, 
bir tür (`T`) ve bir tamsayı (`N`) alır. Bu, `N` elemanlı sabit boyutlu bir dizi oluşturmak için kullanılır.

#include <iostream>

template <typename T, int N> // N, bir "value" parametresidir
class Array {
public:
    T data[N];  // Boyutu N olan bir dizi

    void print() const {
        for (int i = 0; i < N; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    Array<int, 5> arr = {1, 2, 3, 4, 5}; // Array<int, 5> -> N=5
    arr.print();  // Çıktı: 1 2 3 4 5
}

Bu örnekte:
- `N`, `Array` sınıfının değer parametresidir. Sadece sabit bir değer olduğu için `int` gibi türlerle sınırlandırılır.
- `Array<int, 5>`, `N`’in `5` olduğu bir `Array` türü tanımlar.

### 2. Type (Tür) Parametresi

Bir şablon tür parametresi, belirli bir türü temsil eder. `value_type`, genellikle bir sınıfın içindeki türleri ifade eden bir tür tanımıdır. 
Örneğin, bir kapsayıcının (container) içinde tutulan elemanların türünü belirten bir `value_type` olabilir.

#### Örnek: `value_type` Tanımı ile Type Parametreleri

`Container` sınıfı içinde bir `value_type` tanımlayarak, sınıfın öğelerinin türünü belirtebiliriz.

#include <iostream>
#include <vector>

template <typename T>
class Container {
public:
    using value_type = T;  // value_type, Container'ın öğelerinin türünü temsil eder

    void add(const T& value) {
        data.push_back(value);
    }

    void print() const {
        for (const auto& val : data) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

private:
    std::vector<T> data;
};

int main() {
    Container<int> c;
    c.add(10);
    c.add(20);
    c.print();  // Çıktı: 10 20

    Container<double>::value_type d = 3.14;  // value_type `double` olur
    std::cout << "value_type örneği: " << d << '\n';  // Çıktı: 3.14
}

Bu örnekte:
- `using value_type = T;` ifadesi, `Container` sınıfının elemanlarının türünü belirten bir `value_type` tanımı yapar.
- `Container<int>::value_type`, `int` türüne eşdeğerdir. Bu, `Container` sınıfının hangi türde değerler içerdiğini ifade etmek için kullanılır.

### Fark Özeti:
- **Value (Değer) Parametreleri**: Sabit bir değeri temsil eder ve `int`, `char`, `bool` gibi türlerde kullanılabilir.
- **Type (Tür) Parametreleri (Örneğin `value_type`)**: Bir türü temsil eder ve genellikle bir sınıfın içinde tanımlanır. 
`value_type`, bir sınıfın elemanlarının türünü tanımlamak için yaygın olarak kullanılır.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)*Perfect forwarding*, C++'ta şablon işlevleri ve `std::forward` ile birlikte kullanılan bir tekniktir. 
Bu teknik, bir argümanın (örneğin, fonksiyonun parametreleri) orijinal değer kategorisini (lvalue veya rvalue) 
koruyarak başka bir işlev veya nesneye iletilmesini sağlar. Bu, özellikle şablonlarla birlikte kullanıldığında önemli 
avantajlar sunar, çünkü nesnelerin kopyalanmasını veya taşınmasını önler, böylece performansı artırır.

### Perfect Forwarding’in Temel İlkesi

Perfect forwarding, bir fonksiyona geçirilen argümanların orijinal türlerini koruyarak yeni bir fonksiyona iletilmesini sağlar.
Bu işlem için genellikle `std::forward` kullanılır.

### Örnek: Perfect Forwarding

Aşağıda, perfect forwarding'i gösteren basit bir örnek verilmiştir:

#include <iostream>
#include <utility> // std::forward

// Fonksiyon şablonu: Argümanı doğrudan başka bir fonksiyona iletir
template <typename T>
void wrapper(T&& arg) {
    // arg'yi perfect forwarding ile başka bir fonksiyona ilet
    process(std::forward<T>(arg));
}

// Örnek bir işlem fonksiyonu
void process(int& x) { // lvalue referansı
    std::cout << "lvalue: " << x << '\n';
}

void process(int&& x) { // rvalue referansı
    std::cout << "rvalue: " << x << '\n';
}

int main() {
    int a = 10;
    wrapper(a);               // lvalue geçer, process(int&) çağrılır
    wrapper(20);              // rvalue geçer, process(int&&) çağrılır
}

#### Açıklama:
- `wrapper` fonksiyonu, `T&&` ile hem lvalue hem de rvalue referanslarını alabilir.
- `std::forward<T>(arg)` ifadesi, `arg`'nin orijinal değer kategorisini koruyarak `process` fonksiyonuna iletilmesini sağlar.
- `process` fonksiyonu, argümanın türüne bağlı olarak doğru aşırı yükleme (overload) çağrılır.

### Örnek: Sınıf ile Perfect Forwarding

Perfect forwarding, sınıf yapılarında da kullanılabilir. Aşağıda, bir sınıfın yapıcısının perfect forwarding kullanarak argümanlarını başka bir sınıfa ilettiği bir örnek verilmiştir:

#include <iostream>
#include <utility> // std::forward

class MyClass {
public:
    MyClass(int& x) {
        std::cout << "MyClass(int&): " << x << '\n';
    }
    
    MyClass(int&& x) {
        std::cout << "MyClass(int&&): " << x << '\n';
    }
};

template <typename T>
class Wrapper {
public:
    // Yapıcı: Perfect forwarding ile argümanları MyClass'a iletir
    Wrapper(T&& arg) : obj(std::forward<T>(arg)) {}
    
private:
    MyClass obj; // MyClass nesnesi
};

int main() {
    int a = 30;
    Wrapper<int&> w1(a); // lvalue olarak geçer
    Wrapper<int&&> w2(40); // rvalue olarak geçer
}

#### Açıklama:
- `Wrapper` sınıfının yapıcısı, `T&&` ile argümanı alır ve `std::forward<T>(arg)` ile `MyClass`'ın yapıcısına iletir.
- `MyClass`'ın hangi aşırı yükleme fonksiyonunun çağrılacağı, `arg`'nin değer kategorisine bağlıdır.

### Özet

*Perfect forwarding*, C++'ta argümanların orijinal değer kategorisini koruyarak başka bir fonksiyona iletilmesini sağlayan bir tekniktir. 
Bu, performansı artırır ve gereksiz kopyalamaları önler. Özellikle şablon fonksiyonları ve sınıflarında sıkça kullanılır. `std::forward`, 
bu işlemi gerçekleştirmek için kritik bir araçtır.
--------------------------------------------------------------------------------------------------------------------------------------------------
3)`if constexpr`, C++17 ile tanıtılan bir özellik olup, derleme zamanında (compile-time) bir koşulu kontrol etme imkanı sağlar. 
Bu ifade, şablon programlamada oldukça yararlıdır, çünkü koşul sağlandığında ilgili kod bloğu derlenir, aksi takdirde derleyici bu kodu yok sayar. 
Böylece, koşulun durumu derleme zamanında belirlenir ve gereksiz kodların derlenmesinin önüne geçilir.

### Kullanım

`if constexpr` ifadesinin temel yapısı şu şekildedir:

if constexpr (koşul) {
    // Koşul doğruysa bu kod bloğu derlenir
} else {
    // Koşul yanlışsa bu kod bloğu derlenir
}

### Örnek 1: Temel Kullanım

Aşağıdaki örnek, `if constexpr` ifadesinin basit bir kullanımını göstermektedir:

#include <iostream>
#include <type_traits>

template <typename T>
void printType(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "This is an integral type.\n";
    } else {
        std::cout << "This is not an integral type.\n";
    }
}

int main() {
    printType(10);    // Çıktı: This is an integral type.
    printType(3.14);  // Çıktı: This is not an integral type.
}

#### Açıklama:
- `printType` fonksiyonu, `T` türünün integral bir tür olup olmadığını kontrol eder. Eğer `T` integral bir türse, ilgili kod bloğu derlenir ve "This is an integral type." mesajı basılır.
- `if constexpr`, derleme zamanında `T` türünün integral olup olmadığını kontrol ettiği için, `std::is_integral_v<T>` ifadesi doğruysa sadece o kod bloğu derlenir.

### Örnek 2: Çok Yönlü Şablonlar

`if constexpr`, birden fazla tür için farklı işlemler yapmak için de kullanılabilir. Aşağıdaki örnekte, bir şablon fonksiyonu içinde `if constexpr` 
kullanarak farklı türler için farklı davranışlar tanımlanmıştır:

#include <iostream>
#include <type_traits>

template <typename T>
void process(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Processing an integral: " << value << '\n';
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Processing a floating-point: " << value << '\n';
    } else {
        std::cout << "Processing an unknown type.\n";
    }
}

int main() {
    process(10);      // Çıktı: Processing an integral: 10
    process(3.14);    // Çıktı: Processing a floating-point: 3.14
    process("text");   // Çıktı: Processing an unknown type.
}

#### Açıklama:
- `process` fonksiyonu, verilen `value`'nin türüne bağlı olarak farklı mesajlar basar.
- `if constexpr`, her bir koşul için uygun kod bloğunun derlenmesini sağlar. Bu, kodun yalnızca geçerli tür için derlenmesini ve gereksiz kodun yok sayılmasını sağlar.

### Örnek 3: Template Metaprogramming

Aşağıdaki örnek, `if constexpr` kullanarak bir değer üzerinde metaprogramlama yapmaktadır:

#include <iostream>
#include <type_traits>

template <typename T>
void add(const T& a, const T& b) {
    if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Floating-point addition: " << (a + b) << '\n';
    } else {
        std::cout << "Integral addition: " << (a + b) << '\n';
    }
}

int main() {
    add(3, 4);         // Çıktı: Integral addition: 7
    add(3.5, 2.5);     // Çıktı: Floating-point addition: 6
}

#### Açıklama:
- `add` fonksiyonu, iki argümanın türüne bağlı olarak toplama işlemi yapar. `if constexpr`, `T` türü floating-point ise farklı bir işlem, 
integral ise başka bir işlem yapılmasını sağlar.

### Özet

`if constexpr`, C++17 ile gelen ve şablon programlamada koşullu kod yazımını kolaylaştıran bir özelliktir. 
Derleme zamanında koşulları kontrol etme yeteneği, daha verimli ve temiz kod yazma imkanı sunar. Bu özellik, 
kodun yalnızca geçerli türler için derlenmesini sağlayarak, gereksiz kopyalamaları ve derleme süresini azaltır.
******************************************************************************************************************************

                                                                             ********* 35-DERS NOTLARI *********
1)**Trailing ve non-trailing** terimleri, özellikle **trailing return types** bağlamında anlam kazanır. C++11 ile birlikte gelen
**trailing return types**, fonksiyonun dönüş türünü parametre listesinden sonra belirtmenize olanak tanır. Bu, özellikle karmaşık
dönüş türleri söz konusu olduğunda okunabilirliği artırır.

### C++11 Öncesi:
Dönüş türü fonksiyonun başında belirtilir:

int add(int a, int b) {
    return a + b;
}

### Trailing Return Types (C++11 ve Sonrası):
Dönüş türü, `->` işareti kullanılarak parametre listesinden sonra belirtilir:

auto add(int a, int b) -> int {
    return a + b;
}

### Neden Kullanılır?
1. **Şablonlar (Templates)**: Karmaşık tür dönüşlerinde faydalıdır.
2. **Lambda Fonksiyonları**: Lambda ifadelerinde dönüş türünü açıkça belirtmek için kullanılır.

### cppreference.com Örneği:

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

Bu örnekte, `add` fonksiyonunun dönüş türü, `decltype(t + u)` ile belirlenir ve `t` ile `u` parametrelerine bağlıdır.
Bu tür karmaşık durumlarda **trailing return type** kullanımı, dönüş türünü belirtmek için daha esnek ve okunabilir bir yapı sağlar.

### Trailing Comma (C++11 ve Sonrası):
Bir liste veya parametre dizisinin sonunda fazladan bir virgül bırakılmasıdır:

void func(int a, int b,) {
    // C++11 ve sonrası için geçerli
}

Bu tür kullanım, özellikle bir listeye yeni elemanlar eklenirken veya elemanlar çıkarılırken versiyon kontrolü değişikliklerini daha okunabilir ve düzenlenebilir hale getirir.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)**Compile-time recursive pack expansion**, C++'da şablon meta-programlamada kullanılan bir tekniktir.
Özellikle **variadic templates** ile çalışırken, bir parametre paketinin her elemanı üzerinde işlem yapabilmek için
rekürsif bir şekilde açılım yapılır. Bu teknik, şablon parametre paketlerinin elemanlarını compile-time sırasında tek tek işlemek için kullanılır.

### Temel Tanım:
- **Pack Expansion**: Bir şablon parametre paketindeki her bir öğeyi tek tek genişletmek veya işlem yapmak için kullanılır.
- **Recursive Pack Expansion**: Parametre paketi elemanlarını işlemek için bir rekürsif fonksiyon veya şablon çağırılır.

### Örnek:
Cppreference'den ilham alınarak basit bir örnek:

#include <iostream>

// Base case for recursion
void print() {
    std::cout << "End of recursion.\n";
}

// Recursive variadic template function
template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << "\n";
    print(args...);  // Recursive call with reduced parameter pack
}

int main() {
    print(1, 2.5, "Hello", 'A');
    return 0;
}

### Açıklama:
1. **print()**: Bu, parametre paketi tamamen boşaldığında çağrılan temel (base case) fonksiyondur. Rekürsif işlemi sonlandırır.
2. **print(T first, Args... args)**: Bu fonksiyon, parametre paketinden ilk elemanı alır ve geri kalan elemanlarla kendisini rekürsif olarak çağırır.
   - İlk eleman işlenir (`std::cout << first << "\n";`).
   - Kalan elemanlar `print(args...)` ile tekrar çağrılarak işlenir.

### Compile-Time İşleyiş:
- Her derleme zamanı rekürsif çağrı sırasında, `Args...` paketi her seferinde bir eleman azalır.
- Sonunda, parametre paketi boşaldığında temel durumdaki `print()` çağrılır ve rekürsiyon sonlanır.

Bu yapı, derleme zamanında parametre paketi içindeki her eleman üzerinde işlem yapılmasını sağlar ve variadic şablonların güçlü bir kullanım örneğidir.

### Daha Karmaşık Bir Örnek:
Cppreference'de daha karmaşık ve ileri düzey bir örnek bulabilirsiniz, örneğin:

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);  // Fold expression
}

Bu örnek, C++17'deki **fold expressions** ile aynı işi daha kısa bir şekilde yapar, ancak C++11 ve C++14 için rekürsif pack expansion yöntemini kullanabilirsiniz.
--------------------------------------------------------------------------------------------------------------------------------------------------
3)**Fold expressions** C++17 ile tanıtılan ve **variadic templates** üzerinde işlem yapmayı kolaylaştıran bir özelliktir.
Fold expressions, parametre paketlerinin tüm elemanları üzerinde belirli bir işlemi (örneğin toplama, çarpma) kompakt ve okunabilir bir şekilde yapmanızı sağlar.

### Fold Expression Türleri:
Fold expressions, dört farklı şekilde kullanılabilir:

1. **Unary Left Fold**: `( ... op pack )`
2. **Unary Right Fold**: `( pack op ... )`
3. **Binary Left Fold**: `( init op ... op pack )`
4. **Binary Right Fold**: `( pack op ... op init )`

### Cppreference Örneği:

#include <iostream>

// Unary Left Fold
template<typename... Args>
auto sum(Args... args) {
    return (... + args);  // Adds all elements in the parameter pack
}

int main() {
    std::cout << sum(1, 2, 3, 4) << '\n';  // Outputs: 10
    return 0;
}

### Açıklama:
1. **`(... + args)`**: Bu bir **unary left fold** örneğidir. Parametre paketindeki tüm elemanlar soldan sağa doğru toplanır.
2. `sum(1, 2, 3, 4)` çağrıldığında, bu ifade `(((1 + 2) + 3) + 4)` şeklinde açılır ve sonuç `10` olur.

### Diğer Fold Türleri:

**Unary Right Fold**:

template<typename... Args>
auto sum(Args... args) {
    return (args + ...);  // Adds all elements from right to left
}

Bu, sağdan sola işlem yapar: `1 + (2 + (3 + 4))`.

**Binary Left Fold**:

template<typename... Args>
auto sum(Args... args) {
    return (0 + ... + args);  // Starts with an initial value
}

Bu örnekte, işlem `0` ile başlar: `((0 + 1) + 2) + 3) + 4`.

**Binary Right Fold**:

template<typename... Args>
auto sum(Args... args) {
    return (args + ... + 0);  // Ends with an initial value
}

Burada ise sağdan sola `0` ile biten bir toplama işlemi yapılır: `1 + (2 + (3 + (4 + 0)))`.

### Neden Kullanılır?
- **Kompakt ve Okunabilir**: Variadic şablonların elemanlarını işlemek için yazılan karmaşık rekürsif kodları tek bir ifadeyle ifade edebilirsiniz.
- **Hata Azaltma**: Daha az kod yazmak daha az hata demektir.
- **Performans**: Derleme zamanı hesaplamaları optimize edilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
4)**`static_assert`**, C++11 ile gelen ve derleme zamanında bir ifade üzerinde statik kontrol yapmanızı sağlayan bir özelliktir.
`static_assert`, verilen ifadenin doğru (true) olup olmadığını kontrol eder. Eğer ifade yanlış (false) ise, derleme hatası oluşturur.

Bu özellik, belirli koşulların derleme zamanında sağlanıp sağlanmadığını garanti altına almak için kullanılır.
Böylece, hatalar daha erken bir aşamada, yani derleme sırasında yakalanabilir.

### `static_assert` Söz Dizimi:

static_assert(condition, message);

- `condition`: Kontrol edilecek derleme zamanı ifadesi.
- `message`: (Opsiyonel) Hata mesajı, `condition` false olduğunda gösterilir.

### Basit Örnek:

#include <type_traits>

template<typename T>
void checkType() {
    static_assert(std::is_integral<T>::value, "T must be an integral type");
}

int main() {
    checkType<int>();   // Derleme başarılı
    // checkType<double>();  // Derleme hatası: T must be an integral type
    return 0;
}

### Açıklama:
1. `std::is_integral<T>::value`: `T` türünün tam sayı (integral) olup olmadığını kontrol eder.
2. `static_assert`: Eğer `T` tam sayı değilse (örneğin `double` gibi), derleme hatası üretir ve belirtilen mesajı görüntüler.

### Cppreference Örneği:

#include <iostream>
#include <type_traits>

template<typename T>
struct Check {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
    static void print() {
        std::cout << "T is arithmetic." << std::endl;
    }
};

int main() {
    Check<int>::print();    // Derleme başarılı
    // Check<std::string>::print(); // Derleme hatası: T must be an arithmetic type
    return 0;
}


### Kullanım Senaryoları:
1. **Tür Kontrolü**: Şablon parametrelerinin belirli bir tür veya özellik taşıdığını kontrol etmek için kullanılır.
2. **Sabit Değer Kontrolü**: Belirli bir sabitin derleme zamanı doğruluğunu kontrol etmek.
3. **Program Mantığı Kontrolü**: Derleme zamanında bazı mantıksal kontroller yapmak.

### Avantajları:
- **Derleme Zamanı Kontrolü**: Hataları derleme sırasında erken yakalama imkanı.
- **Daha Güvenli Kod**: Program mantığını daha iyi koruma ve beklenmedik tür veya durumların önlenmesi.
- **Dokümantasyon**: `static_assert` mesajları, kodun ne yapmaya çalıştığı hakkında açıklayıcı bilgiler sağlar.
******************************************************************************************************************************

                                                                             ********* 36-DERS NOTLARI *********
1)C++'ta *iterator categories* (yineleyici kategorileri), yineleyicilerin yeteneklerine göre sınıflandırılmasını ifade eder. Her kategori, 
bir yineleyicinin desteklediği işlemleri tanımlar ve hangi algoritmalarla uyumlu olduğunu belirler. C++ Standard Library'de, iterator kategorileri 
belirli bir hiyerarşi içinde düzenlenmiştir ve algoritmalarda yineleyicilerin verimli kullanımını sağlar.

### Iterator Categories

C++'ta 5 temel iterator kategorisi vardır:

1. **Input Iterator**: Bu tür yineleyiciler, bir sıradaki öğeleri tek yönde okumanıza izin verir. Sadece sıralı okuma işlemleri 
desteklenir ve bir kez okunduktan sonra aynı öğeye tekrar dönmek mümkün değildir. Örnekler: `std::istream_iterator`.

2. **Output Iterator**: Yineleyici, bir sıradaki öğelere yazma işlemi için kullanılır. Ancak sadece yazma işlemi yapabilir,
okuma desteklenmez. Tek yönlüdür ve aynı konuma yazılamaz. Örnekler: `std::ostream_iterator`.

3. **Forward Iterator**: Bu kategori, hem okuma hem de yazma işlemlerini destekleyen yineleyiciler içindir ve bir konuma birden fazla 
kez erişilebilir. Tek yönlüdür, ancak sıralı ve tekrar erişilebilir veri yapılarında kullanılabilir. Örnekler: `std::forward_list`.

4. **Bidirectional Iterator**: Hem ileri hem geri hareket edebilen, okuma ve yazma işlemlerini destekleyen bir yineleyicidir. 
Çift yönlü olduğu için daha fazla esneklik sunar. Örnekler: `std::list`.

5. **Random Access Iterator**: Bu, en güçlü iterator kategorisidir. Elemanlara rasgele erişim sağlamakla beraber, yineleyiciyi 
aritmetik işlemlerle (örneğin `+`, `-`) ileri veya geri taşımak mümkündür. Bu kategorideki yineleyiciler vektör, dizi gibi veri 
yapılarında sıklıkla kullanılır. Örnekler: `std::vector`, `std::deque`.

### Kullanım Örnekleri

Her iterator kategorisi belirli algoritmalarla uyumludur ve uygun olmayan kategorilerle kullanıldığında verimsizlik veya hata ortaya çıkabilir.
Örneğin, `std::sort` algoritması yalnızca Random Access Iterator ile çalışır.

Elbette! Aşağıda her bir iterator kategorisine uygun örnekler bulabilirsiniz. Bu örnekler, farklı iterator kategorilerinin 
nasıl çalıştığını ve hangi veri yapılarına uygun olduğunu gösteriyor.

### 1. Input Iterator Örneği

`std::istream_iterator`, bir veri akışını sıralı olarak okuma işlevi görür. Örneğin, bir dosyadan tamsayıları okuyabiliriz:

#include <iostream>
#include <iterator>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt");
    std::istream_iterator<int> start(file), end;

    for (auto it = start; it != end; ++it) {
        std::cout << *it << " ";  // Dosyadan sırasıyla okunan sayıları yazdırır
    }

    file.close();
    return 0;
}

### 2. Output Iterator Örneği

`std::ostream_iterator` ile çıktı akışına veri yazabiliriz. Örneğin, bir vektördeki elemanları standart çıktıya yazalım:

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::ostream_iterator<int> out(std::cout, " ");

    for (int num : numbers) {
        *out++ = num;  // Vektördeki sayıları yazdırır
    }

    return 0;
}

### 3. Forward Iterator Örneği

`std::forward_list`, forward iterator desteği sağlar. Bu veri yapısında ileri yönde gezinilebilir:

#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flist = {1, 2, 3, 4, 5};

    for (auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";  // Elemanları sırasıyla yazdırır
    }

    return 0;
}

### 4. Bidirectional Iterator Örneği

`std::list`, bidirectional iterator desteği sağlar. Bu veri yapısında ileri ve geri yönde hareket edilebilir:

#include <iostream>
#include <list>

int main() {
    std::list<int> numbers = {1, 2, 3, 4, 5};

    // İleri yönde gezinelim
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    // Geriye doğru gezinelim
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}

### 5. Random Access Iterator Örneği

`std::vector`, random access iterator desteği sağlar. Yineleyici ile rasgele erişim işlemleri yapabiliriz:

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 3, 1, 4, 2};

    // Elemanları sıralayalım (random access sayesinde verimli bir şekilde sıralar)
    std::sort(numbers.begin(), numbers.end());

    // Elemanlara doğrudan indeksle erişim sağlanabilir
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}

Bu örnekler, her iterator kategorisinin C++'ta hangi veri yapılarıyla nasıl kullanılabileceğini gösterir.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)C++20 ile eklenen *contiguous iterator* (bitişik yineleyici), bir veri yapısındaki elemanların bellekte ardışık olarak sıralandığını 
garanti eden bir iterator türüdür. `std::vector` ve `std::array` gibi dizilerde kullanılır ve veri öğelerine bellek adresine göre doğrudan 
erişim sağlar. Bu özellik, bellekteki öğelere hızlı bir şekilde erişilmesine olanak tanır ve veri yerleşimi üzerinde tam bir kontrol sunar.

### Özellikleri
* Contiguous iterator, `Random Access Iterator` yeteneklerinin tümünü sağlar, dolayısıyla rasgele erişim işlemlerini destekler.
* Aynı zamanda bir diziyi işaret eden bir çıplak gösterici (`pointer`) ile aynı garantileri sağlar, yani yineleyiciden elemanların adreslerine doğrudan erişim mümkündür.
* Bellekte ardışık olarak depolanan öğelere sahip olduğu için `memcpy`, `std::copy`, veya SIMD işlemleri gibi düşük seviyeli optimizasyonları kullanmayı sağlar.
* `std::span`, `std::vector`, `std::array` gibi veri yapılarında bulunur, ancak `std::list` gibi yapıların iteratorları bu kategoriye girmez, çünkü elemanlar bellekte ardışık olmayabilir.

### Örnek Kullanım

Bir `std::vector`'ün contiguous iterator olmasından faydalanarak, bellekte ardışık olan elemanlara gösterici olarak erişebiliriz:

#include <iostream>
#include <vector>
#include <array>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Contiguous iterator ile doğrudan göstericiye dönüştürme
    int* ptr = vec.data();  // veya &vec[0] şeklinde de elde edilebilir

    // Bellekteki tüm elemanları ardışık olarak yazdır
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << *(ptr + i) << " ";  // Pointer aritmetiği ile erişim
    }

    return 0;
}

Bu örnekte `vec.data()` fonksiyonu, `std::vector`'ün bitişik depolama garantisi sayesinde güvenilir bir şekilde ilk elemana 
işaret eden bir `int*` döndürür. Bu göstericiye erişim sayesinde, veri bellekte ardışık olarak depolandığından `ptr + i` 
gibi pointer aritmetiği ile tüm elemanlara hızlıca erişebiliriz.

### Hangi Yapılar Contiguous Iterator Destekler?

C++'ta bazı veri yapıları aşağıdaki gibi `contiguous iterator` sağlar:
- `std::vector`
- `std::array`
- `std::string`
- `std::span`

`std::list` veya `std::deque` gibi veri yapıları ise contiguous iterator içermez, çünkü bellek düzenleri ardışık olma garantisi vermez.
******************************************************************************************************************************

                                                                             ********* 37-DERS NOTLARI *********
1)*Pointer-like* terimi, C++'ta işaretçi (`pointer`) gibi davranabilen veri türlerini ifade eder. Bu türler, bir işaretçi 
gibi erişim ve gösterim işlemleri yapabilir, ancak doğrudan işaretçi (`T*`) olmayabilirler. `std::unique_ptr`, `std::shared_ptr`, 
`std::optional` gibi akıllı işaretçiler ve gösterici benzeri sınıflar, pointer-like türlerin örnekleridir.

### Pointer-like Özellikler

Pointer-like türler genellikle şu özelliklere sahiptir:
1. **Dereference İşlemi (`*` Operatörü)**: Bir işaretçi gibi gösterdikleri nesneye `*` operatörüyle erişilebilir.
2. **Pointer Semantiği ile Erişim (`->` Operatörü)**: İçerdikleri nesnenin üyelerine `->` ile erişilebilir.
3. **Boş Olma Durumu (null-like)**: `nullptr` gibi boş bir durumu temsil edebilir ve bu durumu `if (!ptr)` gibi bir ifadeyle kontrol etmek mümkündür.
4. **Implicit veya Explicit Pointer Dönüşümü**: Çoğu pointer-like tür, bir işaretçiye dönüştürülebilir veya doğrudan işaretçi olarak kullanılabilir.

### Örnekler

1. **std::unique_ptr ve std::shared_ptr**  
   Bu akıllı işaretçiler, nesne ömrünü otomatik yönetirken bir işaretçi gibi davranır.

   #include <iostream>
   #include <memory>

   int main() {
       std::unique_ptr<int> ptr = std::make_unique<int>(10);
       if (ptr) {
           std::cout << *ptr << std::endl; // Dereference ile içeriğe erişim
       }
       return 0;
   }

2. **std::optional**  
   Bir değeri içerip içermediğini belirten, bir türden değer tutma kapasitesine sahip bir türdür.

   #include <iostream>
   #include <optional>

   int main() {
       std::optional<int> opt = 42;
       if (opt) {
           std::cout << *opt << std::endl; // Dereference ile değere erişim
       }
       return 0;
   }

3. **Iterators**  
   Çoğu iterator, pointer-like türlerdir; çünkü bir nesneyi işaret eder gibi davranırlar ve `*` veya `->` ile içerdikleri değerlere erişilebilir.

   #include <iostream>
   #include <vector>

   int main() {
       std::vector<int> vec = {1, 2, 3};
       auto it = vec.begin();
       std::cout << *it << std::endl; // İlk elemana erişim

       return 0;
   }

### Pointer-like Türlerin Avantajları

Pointer-like türler, bir işaretçi semantiği sunarken aynı zamanda nesne ömrü yönetimi, null kontrolleri ve güvenli bellek erişimi gibi avantajlar 
sağlar. Özellikle `std::unique_ptr` ve `std::shared_ptr`, RAII (Resource Acquisition Is Initialization) prensibiyle bellek yönetimini kolaylaştırır.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)*Tag class*, C++'ta özel bir sınıf türüdür ve genellikle tür veya kategori bilgisi sağlamak için kullanılır. Bir `tag class`, 
tipik olarak işlevlerde veya sınıflarda belirli bir davranışı veya özellik kümesini temsil eden bir tür olarak kullanılır. İçinde 
veri üyesi veya işlev olmayan bu sınıflar, yalnızca sınıfın kendisiyle ilişkilendirilen bilgi veya özellikleri belirtmek için vardır.

### Tag Class Kullanım Alanları

*Tag class* yapıları, özellikle standart kütüphanede ve algoritmalarda kullanılır. Belirli bir türün özelliklerini veya kategorisini
belirlemek için `tag class` yapılarından faydalanılır. Bu sayede, işlevler ve algoritmalar derleme zamanında türleri ayırt edebilir ve buna göre optimize edilebilir.

C++ Standart Kütüphanesi'ndeki `iterator` kategorileri, *tag class* kullanımına iyi bir örnektir.

### Örnek: Iterator Tag Classes

C++'ın `std::iterator` yapısında, farklı iterator kategorilerini belirtmek için tag sınıfları kullanılır. Bu tag sınıfları, 
bir iteratorun yeteneklerini belirtmek amacıyla çeşitli algoritmalar ve veri yapıları tarafından kullanılır:

- `std::input_iterator_tag`: Input iterator özelliğini belirtir.
- `std::output_iterator_tag`: Output iterator özelliğini belirtir.
- `std::forward_iterator_tag`: Forward iterator özelliğini belirtir.
- `std::bidirectional_iterator_tag`: Bidirectional iterator özelliğini belirtir.
- `std::random_access_iterator_tag`: Random access iterator özelliğini belirtir.
- `std::contiguous_iterator_tag` (C++20): Contiguous iterator özelliğini belirtir.

Bu tag sınıfları, bir iteratorun hangi işlemleri desteklediğini ve hangi algoritmalarla uyumlu olduğunu belirtmek için kullanılır. 
Bir algoritma, bu tag sınıflarıyla işaretlenen iterator türlerini tanıyabilir ve iteratorun sağladığı özelliklere göre optimize edilebilir.

### Tag Class Örneği

Aşağıda, iterator tag sınıflarını nasıl kullanabileceğimize dair basit bir örnek verilmiştir:

#include <iostream>
#include <iterator>
#include <type_traits>

template <typename Iterator>
void process(Iterator it, std::random_access_iterator_tag) {
    std::cout << "Random access iterator detected.\n";
    // Random access iteratorlar için optimize edilmiş işlemler
}

template <typename Iterator>
void process(Iterator it, std::input_iterator_tag) {
    std::cout << "Input iterator detected.\n";
    // Input iteratorlar için optimize edilmiş işlemler
}

template <typename Iterator>
void process(Iterator it) {
    typename std::iterator_traits<Iterator>::iterator_category category;
    process(it, category);  // Doğru tag class'ı kullanarak işlem yapılır
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    process(vec.begin());  // Random access iterator ile çalışır

    std::istream_iterator<int> it(std::cin);
    process(it);  // Input iterator ile çalışır

    return 0;
}

Bu örnekte, `process` işlevi farklı iterator türleriyle farklı işlevleri çağırır. Hangi `tag class`'ın geçerli olduğunu 
belirlemek için `std::iterator_traits` kullanılır ve ilgili `process` işlevi çağrılır.
--------------------------------------------------------------------------------------------------------------------------------------------------
3)C++'de **predicate** (Türkçe: "yargı fonksiyonu"), bir değeri doğrulayan veya sınayan bir fonksiyondur. 
Genellikle, bir elemanın belirli bir koşulu sağlayıp sağlamadığını kontrol etmek amacıyla kullanılır. 
Predicate'ler sıklıkla algoritmalarla (örneğin, `std::find_if`, `std::count_if`, `std::remove_if` gibi) birlikte kullanılır.

**cppreference.com**'da predicate hakkında bazı genel kurallar vardır:

- **Unary Predicate**: Bir parametre alan ve `bool` döndüren fonksiyon veya lambda ifadesidir. Bir `UnaryPredicate` genellikle tek bir değeri sınar. Örneğin:

  bool is_even(int n) {
      return n % 2 == 0;
  }

  Bu `is_even` fonksiyonu, bir sayı çift ise `true`, değilse `false` döndürür ve `UnaryPredicate` olarak kullanılabilir.

- **Binary Predicate**: İki parametre alır ve `bool` döndürür. İki değeri karşılaştırmak veya bir koşulda birlikte sınamak için kullanılır. Örneğin:

  bool are_equal(int a, int b) {
      return a == b;
  }

  Bu `are_equal` fonksiyonu, iki sayı eşitse `true`, değilse `false` döndürür ve `BinaryPredicate` olarak kullanılabilir.

Predicate'leri templatelerle kullanmak, özellikle `std::function` veya fonksiyon pointer'larından bağımsız, 
doğrudan herhangi bir fonksiyon, lambda veya callable nesneyi parametre olarak alabilmek açısından çok avantajlıdır. 
Templateler sayesinde, hem unary (tek argüman alan) hem de binary (iki argüman alan) predicate'leri daha esnek ve genel bir yapıda kullanabiliriz.

İşte templatelerle predicate'leri nasıl kullanabileceğinize dair bazı örnekler:

### 1. Unary Predicate ile Genel Bir `find_if` Fonksiyonu

Bu örnekte, bir kapsayıcıda belirli bir koşulu sağlayan ilk öğeyi bulan genel bir `find_if` fonksiyonu tanımlayacağız.

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Container, typename Predicate>
auto find_if_custom(const Container& container, Predicate predicate) -> typename Container::const_iterator {
    return std::find_if(container.begin(), container.end(), predicate);
}

int main() {
    std::vector<int> numbers = {1, 3, 5, 6, 7, 8};

    auto is_even = [](int n) { return n % 2 == 0; };

    auto it = find_if_custom(numbers, is_even);
    if (it != numbers.end()) {
        std::cout << "First even number: " << *it << std::endl;  // Output: 6
    }
}

Bu örnekte `Predicate` tipi, templateli `find_if_custom` fonksiyonuna geçilen koşul olarak işlev görüyor ve `find_if` algoritması içinde kullanılıyor.

### 2. Unary Predicate ile Genel Bir `count_if` Fonksiyonu

Predicate olarak lambda veya fonksiyon pointer'ı alabilen genel bir `count_if` fonksiyonu tanımlayabiliriz:

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Container, typename Predicate>
int count_if_custom(const Container& container, Predicate predicate) {
    return std::count_if(container.begin(), container.end(), predicate);
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    auto is_odd = [](int n) { return n % 2 != 0; };

    int odd_count = count_if_custom(numbers, is_odd);
    std::cout << "Number of odd elements: " << odd_count << std::endl;  // Output: 3
}

Bu örnekte `Predicate`, herhangi bir unary (tek argüman alan) predicate olabilir ve `count_if` içinde kullanılır.

### 3. Binary Predicate ile Genel Bir Sıralama Fonksiyonu

Binary predicate kullanarak kapsayıcıyı belirli bir sıraya göre sıralayan genel bir `sort` fonksiyonu tanımlayabiliriz.

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Container, typename BinaryPredicate>
void sort_custom(Container& container, BinaryPredicate predicate) {
    std::sort(container.begin(), container.end(), predicate);
}

int main() {
    std::vector<int> numbers = {1, 3, 5, 2, 4};

    auto descending = [](int a, int b) { return a > b; };

    sort_custom(numbers, descending);

    for (int n : numbers) {
        std::cout << n << " ";  // Output: 5 4 3 2 1 (descending order)
    }
}

Bu örnekte, `BinaryPredicate` bir lambda veya fonksiyon pointer'ı olabilir ve `std::sort` algoritmasında sıralama koşulu olarak kullanılır.

### 4. Genel `remove_if` Fonksiyonu

`remove_if` algoritmasını templatelerle kullanarak, predicate'e uyan tüm öğeleri kaldıran bir fonksiyon oluşturabiliriz.

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Container, typename Predicate>
void remove_if_custom(Container& container, Predicate predicate) {
    container.erase(std::remove_if(container.begin(), container.end(), predicate), container.end());
}

int main() {
    std::vector<int> numbers = {1, -2, 3, -4, 5};

    auto is_negative = [](int n) { return n < 0; };

    remove_if_custom(numbers, is_negative);

    for (int n : numbers) {
        std::cout << n << " ";  // Output: 1 3 5
    }
}

Bu örnekte, `Predicate` templateli `remove_if_custom` fonksiyonuna geçilir ve predicate'e uyan tüm öğeler kapsayıcıdan silinir.

### 5. Çok Amaçlı `all_of_custom`, `any_of_custom`, `none_of_custom` Fonksiyonları

Bu fonksiyonları kullanarak kapsayıcının tüm, herhangi bir veya hiçbir elemanının belirli bir predicate'i karşılayıp karşılamadığını kontrol edebiliriz.

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Container, typename Predicate>
bool all_of_custom(const Container& container, Predicate predicate) {
    return std::all_of(container.begin(), container.end(), predicate);
}

template <typename Container, typename Predicate>
bool any_of_custom(const Container& container, Predicate predicate) {
    return std::any_of(container.begin(), container.end(), predicate);
}

template <typename Container, typename Predicate>
bool none_of_custom(const Container& container, Predicate predicate) {
    return std::none_of(container.begin(), container.end(), predicate);
}

int main() {
    std::vector<int> numbers = {1, 2, 3, -4, 5};

    auto is_positive = [](int n) { return n > 0; };

    std::cout << "All positive: " << all_of_custom(numbers, is_positive) << std::endl;    // Output: 0 (false)
    std::cout << "Any positive: " << any_of_custom(numbers, is_positive) << std::endl;    // Output: 1 (true)
    std::cout << "None negative: " << none_of_custom(numbers, [](int n) { return n < 0; }) << std::endl; // Output: 0 (false)
}

Bu örneklerde `Predicate` tipi, tüm `std::all_of`, `std::any_of`, ve `std::none_of` fonksiyonlarında kullanılıyor. 
Templateler sayesinde, her bir fonksiyon farklı türlerdeki predicate'lerle uyumlu hale gelir.

Bu örnekler, predicate'leri templatelerle birlikte kullanarak C++'ta çok yönlü ve yeniden kullanılabilir fonksiyonlar yazmanıza olanak tanır.
--------------------------------------------------------------------------------------------------------------------------------------------------
4)
--------------------------------------------------------------------------------------------------------------------------------------------------
5)**Lambda Expression**, **Closure Type**, ve **Closure Object** kavramları, C++'ta lambda ifadeleriyle çalışırken kullanılan terimlerdir. 
Bu terimlerin her biri, lambda ifadelerinin farklı yönlerini temsil eder ve onları anlamak, lambda ifadeleriyle çalışırken daha verimli 
olmanıza yardımcı olur. İşte her birinin açıklaması:

### 1. Lambda Expression (Lambda İfadesi)

**Lambda Expression**, bir fonksiyonu anonim (isimsiz) olarak tanımlamak için kullanılan kısa bir C++ yapısıdır. Lambda ifadeleri, 
genellikle bir işlevi bir defa çalıştırmak istediğinizde veya bir callback veya STL algoritmasında basit bir işlev kullanmak istediğinizde 
faydalıdır. Lambda ifadeleri, `[capture]` bloğuyla dış değişkenleri yakalayarak bunları işlev gövdesinde kullanmanıza olanak tanır.

Lambda ifadesinin temel sözdizimi şöyledir:

[capture](parameters) -> return_type { body };

- **`[capture]`**: Lambda'nın dışındaki değişkenleri nasıl yakalayacağını belirtir.
- **`(parameters)`**: Fonksiyonun parametre listesidir.
- **`-> return_type`**: Dönüş türüdür (isteğe bağlıdır, derleyici genellikle bunu çıkarır).
- **`{ body }`**: Lambda'nın fonksiyon gövdesidir.

**Örnek**:

auto add = [](int a, int b) -> int {
    return a + b;
};
int result = add(3, 4);  // Output: 7

Bu lambda ifadesi `a` ve `b` parametrelerini alır, ikisini toplar ve sonucu döndürür.

### 2. Closure Type (Kapanış Türü)

**Closure Type**, lambda ifadesinin arkasındaki türdür. Lambda ifadesi tanımlandığında, derleyici o lambda ifadesine karşılık gelen anonim bir 
sınıf türü oluşturur. Bu sınıfa *closure type* denir. Closure type, lambda'nın yakalama listesinde belirtilen dış değişkenleri 
(örneğin, `[=]`, `[&]`, `[x]`, `[&x]` gibi) saklar. Bu tür sınıflarda `operator()` fonksiyonu aşırı yüklenir, böylece bu nesne bir fonksiyon gibi çağrılabilir.

Closure type, lambda ifadesinin türünü temsil eder, ancak bu tür derleyici tarafından oluşturulduğundan dolayı anonimdir ve kod içerisinde doğrudan kullanılamaz.

**Örnek**:

Aşağıdaki lambda ifadesini düşünelim:

auto add = [](int a, int b) { return a + b; };

Bu `add` ifadesinin türü, derleyici tarafından oluşturulan anonim bir sınıf (closure type) olacaktır. Yani, `add` aslında `operator()` üyesi olan anonim bir sınıf türündedir.

### 3. Closure Object (Kapanış Nesnesi)

**Closure Object**, lambda ifadesinin kendisini çalıştırmak için kullanılan nesnedir. Lambda ifadesi tanımlandığında bir closure type oluşturulur
ve ardından bu closure type'ın bir nesnesi closure object olarak tanımlanır. Closure object, yakalanan değişkenleri tutar ve `operator()` işlevi sayesinde çağrılabilir.

**Örnek**:

int factor = 2;
auto multiply = [factor](int x) { return x * factor; };  // factor değeri kopyalanarak yakalanır.
int result = multiply(5);  // Output: 10

Bu örnekte, `[factor](int x) { return x * factor; }` lambda ifadesi bir closure object olan `multiply` nesnesini oluşturur. 
`multiply` çağrıldığında, `operator()` sayesinde `factor` değeri ile `x` çarpılır ve sonuç döndürülür.

**Özetle**:

- **Lambda Expression**: Kısa ve anonim bir işlevi tanımlamak için kullanılan ifade.
- **Closure Type**: Lambda ifadesi derlendiğinde oluşturulan anonim sınıf türü. Bu tür, lambda'nın yakalama listesindeki değişkenleri saklar.
- **Closure Object**: Lambda ifadesinin bir örneği olarak, closure type'ın bir nesnesidir ve yakalanan değişkenleri tutarak çağrılabilir hale gelir.

[] lambda introducer
******************************************************************************************************************************

                                                                             ********* 38-DERS NOTLARI *********
1)C++'da **local class**, bir fonksiyonun içinde tanımlanmış sınıflardır. Bu sınıflar, yalnızca tanımlandıkları
fonksiyonun içinde geçerlidir ve işlev dışında doğrudan erişilemez. Local class'lar, sadece tanımlandıkları fonksiyonun
içinde var olduklarından dolayı, fonksiyon dışındaki kod tarafından doğrudan kullanılamazlar. 

### Neden Kullanılır?
Local class'lar, genellikle:
- Belirli bir işlevin içinde geçici bir yapı tanımlamak gerektiğinde,
- Kodun yalnızca bir fonksiyon içerisinde kullanılacak bir veri yapısına veya işleme ihtiyaç duyduğunda,
- Genel kapsamda tanımlanması gerekmeyen, lokal işlevsellik sağlayan sınıflar yaratmak istediğinizde kullanılır.

Bu sayede kodda daha fazla kapsülleme (encapsulation) sağlanır ve fonksiyon dışındaki kodun sınıfa erişimi kısıtlanır.
s
### Local Class Kullanım Kısıtlamaları
C++ local class'larla ilgili bazı kısıtlamalar getirir:
- `static`, `extern` veya `thread_local` değişkenlere erişemezler.
- Global ad alanındaki isimleri (değişken veya sabit gibi) doğrudan kullanamazlar.

### Örnek

Aşağıda `cppreference` tarzında bir local class örneği gösterilmiştir:

#include <iostream>

void printMessage() {
    class LocalClass { // Local class, printMessage() fonksiyonunun içinde tanımlı
    public:
        void sayHello() const {
            std::cout << "Hello from local class!" << std::endl;
        }
    };

    LocalClass lc;  // LocalClass nesnesi oluşturuluyor
    lc.sayHello();  // Local class içindeki fonksiyon çağrılıyor
}

int main() {
    printMessage();
    return 0;
}

### Açıklama
- `printMessage` fonksiyonu içinde `LocalClass` adlı bir sınıf tanımlıyoruz.
- `LocalClass` içinde `sayHello` adında bir üye fonksiyonu var ve bu fonksiyon bir mesaj yazdırıyor.
- `main` fonksiyonunda `printMessage` fonksiyonu çağrıldığında, yalnızca bu fonksiyonun içinde geçerli olan `LocalClass` kullanılıyor.

### Ne Zaman Kullanılır?
- Bir işleve özgü geçici veri yapıları gerektiğinde,
- Kodun okunabilirliğini ve bakımını artırmak amacıyla, belirli bir işlevde dar kapsamlı bir sınıf tanımlamak için kullanılır.

Local class kullanımı, kodda özel durumları ve lokal işlevleri kapsüllemek için etkili bir tekniktir.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)**IIFE (Immediately Invoked Function Expression)**, adından da anlaşılacağı gibi, tanımlandığı anda hemen çağrılan işlev anlamına gelir. 
C++'ta, IIFE, genellikle bir anonim işlev (lambda) veya sınırlı kapsamda çalıştırılmak istenen bir işlevi hemen çalıştırmak için kullanılır. 
JavaScript'te daha yaygın olan IIFE, C++'ta da kapsam sınırlamak, geçici değişkenler tanımlamak veya hemen işlem yapmak için kullanılabilir.

### Neden Kullanılır?
C++’ta IIFE, özellikle:
1. **Geçici değişkenlerin kapsamını sınırlamak** için (kodun başka yerlerinde kullanılmadan yalnızca bir yerde işlem yapılması isteniyorsa).
2. **İlk değer ataması veya hesaplamalar** yapılması gereken durumlarda.
3. **Kodun okunabilirliğini artırmak** ve yan etkilerden korunmak için.
   
Bu yapı, karmaşık bir hesaplamayı veya başlangıç işlemini kapsülleyip, tek satırda gerçekleştirmeyi sağlar.

### C++’ta IIFE Örneği

C++'ta IIFE, lambda ifadesi kullanılarak oluşturulabilir. Aşağıdaki örnek `cppreference` tarzında bir örnektir:

#include <iostream>

int main() {
    // IIFE kullanılarak hemen hesaplanan bir değer
    int result = []() -> int {
        int a = 5;
        int b = 10;
        return a + b;  // 15 değerini döner
    }();

    std::cout << "Result: " << result << std::endl;

    return 0;
}

### Açıklama
- `[]() -> int { ... }()` ifadesi bir IIFE’dir. `[]()` lambda ifadesini tanımlar ve sonundaki `()` ise onu hemen çağırır.
- Lambda ifadesi içinde `a` ve `b` geçici olarak tanımlanır ve toplanarak bir sonuç döner.
- `result` değişkeni, lambda tarafından döndürülen değeri alır ve `Result: 15` çıktısını verir.

### Ne Zaman Kullanılır?
- Karmaşık bir başlangıç veya hesaplama işlemini yalnızca bir kez yapmak istiyorsanız,
- Geçici bir değeri hesaplayıp kullanmak, ardından kapsam dışına çıkmasını sağlamak istiyorsanız,
- Kodun daha kısa ve okunabilir olmasını amaçlıyorsanız, IIFE kullanabilirsiniz.

IIFE, C++’ta belirli bir işlevi hızlıca yapmak, geçici değişkenlerin kapsamını sınırlamak ve kodun daha temiz olmasını sağlamak için kullanışlıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT: C++17 de closure typeların 
    default constructorı
        copy assignment constructorı delete edilmiştir

C++20 de stateless lambdalarda delete edilmemiştir
--------------------------------------------------------------------------------------------------------------------------------------------------
3)**Stateless lambda** ifadesi, yakalama listesi (`[]`) boş olan ve böylece herhangi bir durumu (state) taşımayan lambdaları ifade eder.
Bu tür lambdalar, bir dış değişkeni yakalamaz veya kendine özel bir durumda çalışmaz; yalnızca aldığı parametrelere göre işlem yapar ve yan etkisizdir.

### Stateless Lambdalar Neden Kullanılır?
1. **Hafif ve Hızlı**: Stateless lambdalar, herhangi bir harici değişkeni yakalamadığı için bellek açısından daha verimlidir ve daha hızlıdır. 
Ekstra durum bilgisi taşımadığı için compiler bunları optimize edebilir.
2. **Thread-Safe**: Durum (state) taşımadıkları için paralel programlama ve çoklu thread kullanımında güvenlidir.
3. **Yeniden Kullanılabilir**: Aynı işlevi tekrar tekrar kullanmak ve dışsal verilere bağlı olmamak için idealdir. 
Özellikle saf fonksiyonlar (pure functions) gibi, yalnızca girdiye bağlı ve yan etkisiz işlevler yazmak için uygundur.
4. **Fonksiyonel Programlama**: Matematiksel fonksiyon gibi davranarak belirli girdilere göre çıktı üreten ve yan etkisiz olan işlemler yapmak için kullanılabilir.

### C++’ta Stateless Lambda Örneği

Aşağıda `cppreference` tarzında bir stateless lambda örneği verilmiştir:

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Stateless lambda kullanarak sayıları iki katına çıkarma
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * 2 << " ";
    });

    return 0;
}

### Açıklama
- `[](int n) { std::cout << n * 2 << " "; }` ifadesi stateless bir lambda ifadesidir.
- `[]` boş yakalama listesi, lambdanın dış değişkenlere erişmediğini gösterir.
- Bu lambda, aldığı `n` parametresini ikiyle çarpar ve sonucu ekrana yazdırır.
- `std::for_each` ile kullanılarak `numbers` vektöründeki her elemanı işler.

### Stateless Lambdalar Ne Zaman Kullanılır?
- **Sabit bir işlemi tanımlamak** istediğinizde (örneğin, sayıların iki katını almak gibi).
- **Yan etkisiz** küçük işlemler için.
- **Hafif ve taşınabilir** bir işlev gerektiğinde, özellikle algoritmalarda (`std::sort`, `std::for_each`, vb.) basit işlemler yapmak için.

Stateless lambdalar, dış durumları yakalamadıkları için daha verimlidir ve güvenilirdir; bu da onları genellikle kısa ve basit işlemler için tercih edilen bir çözüm yapar.
--------------------------------------------------------------------------------------------------------------------------------------------------
4)**Copy capture**, C++ lambdalarında bir değişkenin değerini lambda ifadesinin içine kopyalayarak yakalamayı ifade eder. 
Bu durumda, yakalanan değişkenin bir kopyası lambda içinde kullanılır, yani orijinal değişkenle bağlantılı değildir. 
Bu, yakalanan değişkenin lambda içindeki değişikliklerinin orijinal değişkeni etkilemeyeceği anlamına gelir.

### Copy Capture Neden Kullanılır?
1. **Değişkenin Sabit Bir Halini Kullanma**: Değişkenin anlık değerine ihtiyaç varsa ve dışarıda değişse bile lambda içinde sabit kalması isteniyorsa, copy capture kullanılabilir.
2. **Yan Etkileri Önleme**: Lambda içinde yapılan değişikliklerin, dıştaki değişkeni etkilemesi istenmiyorsa, copy capture tercih edilir.
3. **Dışarıdaki Kaynağın Ömrünü Uzatma**: Lambda içinde dıştaki kaynağın kopyasını almak, lambda kullanım ömrünü dış kaynaktan bağımsız hale getirebilir.

### C++’ta Copy Capture Örneği

C++'ta copy capture, lambda ifadesindeki `[]` içine değişken adı eklenerek yapılır. Ayrıca, `=` işareti kullanılarak tüm yerel değişkenlerin kopya olarak yakalanması sağlanabilir.

#include <iostream>

int main() {
    int x = 10;

    // x'i kopya olarak yakalayan lambda
    auto lambda = [x]() {
        std::cout << "Lambda'daki x: " << x << std::endl;
    };

    x = 20;  // x'in değeri lambda dışında değiştiriliyor

    lambda();  // Lambda çağrıldığında x'in kopyalanmış halini kullanır

    std::cout << "Ana fonksiyondaki x: " << x << std::endl;

    return 0;
}

### Açıklama
- `auto lambda = [x]() { ... };` ifadesinde `x` kopyalanarak lambda içinde kullanılır.
- `x = 20;` ile ana fonksiyondaki `x` değeri değiştirilir. Ancak lambda çağrıldığında, `x`'in kopyalanmış değeri olan `10` kullanılır.
- Çıktı olarak önce "Lambda'daki x: 10" ve ardından "Ana fonksiyondaki x: 20" basılır. Bu da lambdanın `x`'in orijinal değeri yerine kopyasını kullandığını gösterir.

### Copy Capture Ne Zaman Kullanılır?
- **Lambda içinde sabit bir değerle çalışmak** istendiğinde.
- **Orijinal değişkene dokunmadan** lambda içinde bir değerle işlem yapmak gerektiğinde.
- **Lambda ömrünü orijinal değişkenden bağımsız hale getirmek** istediğinizde.

Copy capture, lambdaların yan etkisiz bir şekilde belirli bir değeri kullanması gerektiğinde faydalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
5)**Lambda init-capture**, C++14 ile tanıtılan ve C++17 ve sonrasında da geniş kullanılan bir özellik olup, 
lambda ifadelerinde dış değişkenleri **yakalamak** ve aynı anda **başlatmak** için kullanılır. Init-capture, 
lambda içinde bir değişkenin başlangıç değeri atanarak, lambda içinde bağımsız bir kopyasının kullanılmasına izin verir. 
Bu özellik, özellikle bir lambda ifadesinde dışarıdaki bir değişkenin sabit veya hesaplanmış bir kopyasını alırken faydalıdır.

### Lambda Init-Capture Kullanımı

Lambda init-capture, köşeli parantez `[]` içinde `var_name = expression` şeklinde kullanılır:
- `var_name`: Lambda içinde kullanmak istediğiniz değişken adı.
- `expression`: Lambda içinde bağımsız bir kopya olarak kullanacağınız değerin başlangıç ifadesi.

### Lambda Init-Capture Örneği

Aşağıda `cppreference` tarzında, lambda init-capture kullanımını gösteren bir örnek verilmiştir:

#include <iostream>
#include <vector>

int main() {
    int factor = 5;

    // Init-capture ile factor'ün değeri yakalanarak bir lambda tanımlanıyor
    auto multiply_by_factor = [factor = factor * 2](int n) {
        return n * factor;
    };

    std::cout << "4 * factor: " << multiply_by_factor(4) << std::endl; // Çıktı: 4 * 10 = 40

    return 0;
}

### Açıklama
- `factor = factor * 2` ifadesi, init-capture kullanarak lambda içinde `factor` isimli yeni bir değişken oluşturur ve ona `factor * 2` değerini atar.
- Bu durumda, lambda içindeki `factor`, dıştaki `factor` değişkeninin iki katı olan bağımsız bir değerdir.
- Lambda, verilen bir sayıyı (`n`) `factor` ile çarpar.
- `multiply_by_factor(4)` ifadesi 4 sayısını 10 ile çarpar ve `40` sonucunu verir.

### Init-Capture ile Daha Karmaşık Bir Örnek

Bir listeyi, belirli bir başlangıç değeriyle filtrelemek için init-capture kullanılabilir:

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    int threshold = 3;

    // Init-capture ile threshold'un değeri iki katına çıkarılarak lambda içinde kullanılıyor
    auto count = std::count_if(numbers.begin(), numbers.end(),
                               [threshold = threshold * 2](int n) {
                                   return n > threshold;
                               });

    std::cout << "Threshold'dan büyük eleman sayısı: " << count << std::endl; // Çıktı: 2

    return 0;
}

### Açıklama
- `threshold = threshold * 2` ifadesi init-capture ile lambda içinde kullanılmak üzere `threshold` isimli yeni bir değişken oluşturur ve `threshold` değerini iki katına çıkarır.
- `std::count_if`, `numbers` listesindeki `threshold` değerinden büyük olan elemanları sayar.
- Dış `threshold` değişkeni `3` iken, lambda içindeki `threshold` değeri `6` olur ve `count` sonucu `6`'dan büyük olan `5` ve `6` elemanları için `2` olur.

### Init-Capture Ne Zaman Kullanılır?
- Bir değişkenin belirli bir başlangıç değeri ile yakalanması gerektiğinde.
- Hesaplanmış veya değişkenin güncellenmiş bir kopyasını almak gerektiğinde.
- Lambda içinde bağımsız bir değişken kopyası ile işlem yapma gereği duyulduğunda.

Init-capture, lambdaların daha esnek ve bağımsız çalışmasını sağlayarak, fonksiyonel programlamada önemli bir araç haline gelir.
******************************************************************************************************************************

                                                                             ********* 39-DERS NOTLARI *********
1)**Initializing assignment split** (başlatma ve atamanın ayrılması), genellikle değişkenlerin değerlerini başlangıçta bir yerde belirlemek 
(initialize etmek) ve sonra farklı bir noktada bu değerleri tekrar atamak (assign etmek) anlamına gelir. Bu, genelde yazılım tasarımında **verimsizliklere** 
ve **hatalara açık durumlara** yol açabilir. C++'ta, özellikle modern standartlarda bu tür bir yapı genellikle önerilmez ve bundan kaçınılması gerektiği düşünülür.

### **Initializing Assignment Split Nedir?**

Bu terim, bir değişkenin önce varsayılan bir değerle **başlatılması**, ardından başka bir noktada bu değerin **yeniden atanması** anlamına gelir. Örneğin:

#include <iostream>

int main() {
    int x;         // Başlatılmadan tanımlama (undefined behavior olabilir)
    x = 42;        // Atama yapılıyor (initialize ve assign ayrılmış)

    std::cout << x << std::endl;
    return 0;
}

**Sorunlar:**
1. **Potansiyel Tanımsız Davranış (Undefined Behavior):** Eğer değişken bir değere başlatılmadan önce kullanılırsa, program tanımsız davranabilir.
2. **Kod Karmaşıklığı:** Değişkenin başlatıldığı ve yeniden atandığı yerler uzakta olduğunda, kodun okunabilirliği ve bakımı zorlaşır.
3. **Performans Maliyeti:** Başlatma sırasında bir değer atamak ve ardından yeniden atama yapmak, özellikle karmaşık veri türleri (örneğin, sınıflar veya STL konteynerleri) için fazladan maliyet yaratır.

### **C++ Modern Alternatifi**

Modern C++'ta (C++11 ve sonrası), **RAII** (Resource Acquisition Is Initialization) ve **doğrudan başlatma** (direct initialization) konseptleri kullanılarak bu durumdan kaçınılır. Örnek:

#include <iostream>

int main() {
    int x = 42;  // Doğrudan başlatma
    std::cout << x << std::endl;
    return 0;
}

Bu yaklaşım:
- Değişkeni tanımlar ve aynı anda başlatır.
- Tanımsız davranışı önler.
- Daha net ve güvenilir kod oluşturur.

### **Initializing Assignment Split'in Tehlikeleri**

1. **Gereksiz Karmaşıklık:**
   - Başlatma ve atama farklı yerlerde olursa, hangi değerin geçerli olduğu karışabilir.
   - Kodun anlamını takip etmek zorlaşır.

2. **Performans Maliyeti:**
   - Değişken önce bir varsayılan değere atanır, ardından tekrar bir değerle güncellenirse, özellikle dinamik bellek 
   tahsisi yapan veri türlerinde (örneğin `std::string`, `std::vector`) gereksiz maliyet yaratır.

   Örnek:

   #include <string>
   #include <iostream>

   int main() {
       std::string str;       // Varsayılan başlatma (boş string)
       str = "Hello, world!"; // Yeniden atama (fazladan işlem)
       std::cout << str << std::endl;
       return 0;
   }

   Alternatif:

   #include <string>
   #include <iostream>

   int main() {
       std::string str = "Hello, world!";  // Doğrudan başlatma
       std::cout << str << std::endl;
       return 0;
   }

3. **Hatalara Açıklık:**
   - Değişken başlatılmadan önce kullanılırsa, tanımsız davranışa yol açabilir.

   Örnek (Yanlış kullanım):

   int x;
   std::cout << x << std::endl;  // Tanımsız davranış: x başlatılmadı!

### **Neden Kaçınmalıyız?**

**Initializing assignment split**'ten kaçınmamızın başlıca nedenleri:
- **Kod Güvenilirliği:** Değişkeni doğru başlatmak, hataları erken önler.
- **Kod Okunabilirliği:** Değişkenin ilk değeri hemen görülebilir, bu da kodu anlamayı kolaylaştırır.
- **Performans:** Fazladan bellek ve işlem maliyetinden kaçınılır.
- **C++'ın Modern Tasarımı:** Modern C++ doğrudan başlatma yöntemini teşvik eder.

### **Özet**

Initializing assignment split, değişkenlerin önce varsayılan bir değerle başlatılıp sonra yeniden atanmasını ifade eder. 
Modern C++'ta, bu yapıdan **doğrudan başlatma** ve RAII gibi daha güvenilir yöntemlerle kaçınılır. Daha temiz, performanslı
ve hataya dayanıklı kod yazmak için `Initializing assignment split` kullanılmamalıdır.
--------------------------------------------------------------------------------------------------------------------------------------------------
2)**Deduction guide**, C++17'de tanıtılan bir özellik olup, **şablon sınıflarının (template classes)** otomatik tür çıkarımı (type deduction) 
için nasıl bir yol izlemesi gerektiğini belirler. Normalde, bir şablon sınıfı oluşturulurken türlerin açıkça belirtilmesi gerekebilir. 
Ancak, deduction guide sayesinde, sınıfın yapılandırıcılarını (constructor) temel alarak türlerin otomatik olarak çıkarılmasına izin verebilirsiniz.

### **Deduction Guide Kullanımı**

Şablon sınıflarında tür çıkarımı yapılırken, sınıfın yapılandırıcısından türlerin otomatik olarak tahmin edilmesini sağlar. Bazen varsayılan 
çıkarım mantığı uygun olmadığında, özel bir **deduction guide** ekleyerek tür çıkarımı kontrol edilebilir.

### **Deduction Guide Örneği**

#### Örnek: Basit Kullanım

#include <iostream>
#include <string>
#include <utility>

template <typename T1, typename T2>
struct MyPair {
    T1 first;
    T2 second;

    // Yapılandırıcı
    MyPair(T1 f, T2 s) : first(f), second(s) {}
};

// Deduction guide tanımı
template <typename T1, typename T2>
MyPair(T1, T2) -> MyPair<T1, T2>;

int main() {
    // Deduction guide sayesinde türler otomatik çıkarılır
    MyPair p = {42, std::string("Hello")};

    std::cout << "First: " << p.first << ", Second: " << p.second << std::endl;
    return 0;
}

#### Açıklama:
1. `MyPair` bir şablon sınıfıdır.
2. `MyPair(T1, T2)` deduction guide sayesinde, yapılandırıcıya (`MyPair(42, "Hello")`) bakılarak `T1` ve `T2` türleri otomatik çıkarılır.
3. `p` nesnesinin türü `MyPair<int, std::string>` olarak belirlenir.

Çıktı:

First: 42, Second: Hello

### **Neden Deduction Guide Kullanılır?**

1. **Kodun Daha Az Yük Olması:**
   - Türleri manuel belirtmek yerine, çıkarımı otomatikleştirmek kodun okunabilirliğini artırır.
   
2. **Varsayılan Tür Çıkarımına Müdahale:**
   - C++'ın varsayılan çıkarım mantığını değiştirmek veya genişletmek gerektiğinde faydalıdır.

### **Daha Karmaşık Bir Örnek**

Şablon sınıfında çıkarım kurallarını özelleştirme:

#include <iostream>
#include <string>

template <typename T>
struct Wrapper {
    T value;

    Wrapper(T v) : value(v) {}
};

// Deduction guide: int türü için özelleştirilmiş çıkarım
Wrapper(int) -> Wrapper<double>;

int main() {
    Wrapper w = 42; // Burada 42, double olarak çıkarılır

    std::cout << "Value: " << w.value << " (Type: double)" << std::endl;
    return 0;
}

#### Açıklama:
- `Wrapper(int)` için bir deduction guide tanımlanmıştır: `int` türü verilse bile, bu `Wrapper<double>`'a dönüştürülür.
- `w` nesnesinin türü `Wrapper<double>` olur ve `42` değeri `double` olarak saklanır.

Çıktı:

Value: 42 (Type: double)

### **Varsayılan Tür Çıkarımı ve Müdahale**
Deduction guide olmadan, C++ varsayılan çıkarım kurallarını uygular. Ancak bazı durumlarda çıkarımı açıkça kontrol etmek için `deduction guide` gerekir.

### **Özet**

- **Deduction guide**, şablon sınıflarında tür çıkarımını özelleştirmek için kullanılır.
- Varsayılan çıkarım mantığının yetersiz olduğu veya yanlış olduğu durumlarda tür çıkarımını kontrol etmek için kullanılır.
- C++17'den itibaren desteklenir ve kodun okunabilirliğini artırır.
--------------------------------------------------------------------------------------------------------------------------------------------------
3)C++'ta **multi-lambda idiomu**, genellikle birden fazla lambda ifadesini bir yerde kullanmayı ifade eder. 
Bu idiom, genellikle lambda ifadelerinin çoklu görevleri yerine getirmesi için bir yapı olarak tasarlanır.
Modern C++ standartlarında, özellikle **std::visit** gibi fonksiyonlarla birlikte veya işlevsel bir programlama stilini benimserken kullanılabilir.

**Multi-lambda idiomu**, farklı türlerle veya durumlarla çalışırken, çoklu lambda ifadelerini tek bir yapı içinde toplamak için sıkça kullanılır.
Özellikle, **C++17** ile gelen **std::variant** ve **std::visit** gibi araçlarla kullanılmak üzere tasarlanmış **overloaded (fazladan yükleme)** isimli bir yardımcı yapı popüler bir örnektir.

### Multi-lambda Idiomu ile Overloaded Örneği

C++17'den itibaren gelen `std::variant` ve `std::visit` ile, çoklu türleri ele almak için birden fazla lambda kullanılabilir. İşte `cppreference`'e uygun bir örnek:

#include <iostream>
#include <variant>
#include <string>

// Overloaded isimli bir yardımcı yapı oluşturulur
template <typename... Ts>
struct Overloaded : Ts... {
    using Ts::operator()...;
};

// C++17 sınıf şablonu kuralı
template <typename... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

int main() {
    // std::variant birden fazla türü temsil edebilir
    std::variant<int, double, std::string> myVariant;

    // Farklı türlerde bir değer atayalım
    myVariant = 42;

    // std::visit ile farklı türleri ele almak için multi-lambda kullanımı
    std::visit(Overloaded{
        [](int i) { std::cout << "int: " << i << std::endl; },
        [](double d) { std::cout << "double: " << d << std::endl; },
        [](const std::string& s) { std::cout << "string: " << s << std::endl; }
    }, myVariant);

    myVariant = 3.14;
    std::visit(Overloaded{
        [](int i) { std::cout << "int: " << i << std::endl; },
        [](double d) { std::cout << "double: " << d << std::endl; },
        [](const std::string& s) { std::cout << "string: " << s << std::endl; }
    }, myVariant);

    return 0;
}

### Açıklama

1. **std::variant**: `std::variant`, birden fazla türün bir arada temsil edilmesini sağlar.
   - Burada `std::variant<int, double, std::string>` tipi tanımlanmıştır, yani bu değişken bu üç türden birini içerebilir.
   
2. **Overloaded Yapısı**:
   - Çoklu lambda ifadelerini tek bir yerde toplamak için kullanılır.
   - `template <typename... Ts>` ile birden fazla türü kabul eder ve bunları kalıtım yoluyla bir araya getirir (`Ts...`).

3. **std::visit**:
   - `std::visit`, `std::variant` içindeki mevcut türü ziyaret etmek ve buna uygun bir işlemi gerçekleştirmek için kullanılır.
   - Her tür için bir lambda sağlanır ve doğru türdeki lambda çağrılır.

4. **Çıktı**:
   - İlk değer `42` olduğu için, `"int: 42"` yazdırılır.
   - İkinci değer `3.14` olduğunda, `"double: 3.14"` yazdırılır.

### **Multi-lambda Idiomu'nun Kullanım Alanları**

1. **Farklı Türleri Ele Alma**:
   - `std::variant` veya benzeri veri yapılarıyla çalışırken farklı türler için özel işlemler gerçekleştirmek.

2. **Pattern Matching Alternatifi**:
   - C++'ta henüz tam anlamıyla bir pattern matching mekanizması bulunmadığı için, multi-lambda idiomu bu ihtiyacı kısmen karşılayabilir.

3. **Kodun Okunabilirliğini ve Modülerliğini Artırma**:
   - Tek bir yapı içinde birden fazla işlemi tanımlayarak, kodun net ve anlaşılır olmasını sağlar.

### **Neden Kullanılır?**

- **Esneklik**: Farklı türler veya durumlar için ayrı ayrı kod yazmak yerine, lambdalarla esnek ve modüler bir yapı oluşturur.
- **Tip Güvenliği**: Derleme zamanında tür eşleştirmesi sağlandığı için, yanlış türlerin işlenmesini önler.
- **Kod Tekrarını Azaltma**: Lambda ifadeleri bir arada tutulduğu için kod tekrarı azalır ve bakım kolaylaşır.

### Özet

**Multi-lambda idiomu**, özellikle **std::variant** ve **std::visit** gibi araçlarla birlikte kullanılan,
birden fazla lambda ifadesini tek bir yapı içinde tanımlamaya olanak tanıyan güçlü bir desendir. C++'ta işlevsel
programlama yaklaşımlarını kolaylaştırır ve kodun netliğini artırır. Bu idiom, **farklı türleri yönetmek** veya **durumları ele almak** için harika bir çözümdür.
******************************************************************************************************************************

                                                                             ********* 40-DERS NOTLARI *********
1)erase remove idiom
--------------------------------------------------------------------------------------------------------------------------------------------------
2)sequence container
--------------------------------------------------------------------------------------------------------------------------------------------------
3)associative container
--------------------------------------------------------------------------------------------------------------------------------------------------
4)unordered associative container
******************************************************************************************************************************

                                                                             ********* 41-DERS NOTLARI *********
1)almost always vector
--------------------------------------------------------------------------------------------------------------------------------------------------
2)shring to fit
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************

                                                                             ********* 42-DERS NOTLARI *********
1)structure binding
--------------------------------------------------------------------------------------------------------------------------------------------------
2)iterator invalidation
--------------------------------------------------------------------------------------------------------------------------------------------------
3)linked list
--------------------------------------------------------------------------------------------------------------------------------------------------
4)fragmantation
******************************************************************************************************************************

                                                                             ********* 43-DERS NOTLARI *********
1)profiling code
--------------------------------------------------------------------------------------------------------------------------------------------------
2)splices functions
--------------------------------------------------------------------------------------------------------------------------------------------------
3)equievalance

lower bound

upper bound

equal range
******************************************************************************************************************************

                                                                             ********* 44-DERS NOTLARI *********
1)
--------------------------------------------------------------------------------------------------------------------------------------------------
2)
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************

                                                                             ********* 45-DERS NOTLARI *********
1)
--------------------------------------------------------------------------------------------------------------------------------------------------
2)
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************

                                                                             ********* 46-DERS NOTLARI *********
1)
--------------------------------------------------------------------------------------------------------------------------------------------------
2)
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************

                                                                             ********* 47-DERS NOTLARI *********
1)
--------------------------------------------------------------------------------------------------------------------------------------------------
2)
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************

                                                                             ********* 48-DERS NOTLARI *********
1)
--------------------------------------------------------------------------------------------------------------------------------------------------
2)
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************

                                                                             ********* 49-DERS NOTLARI *********
1)
--------------------------------------------------------------------------------------------------------------------------------------------------
2)
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************

                                                                             ********* 50-DERS NOTLARI *********
1)
--------------------------------------------------------------------------------------------------------------------------------------------------
2)
--------------------------------------------------------------------------------------------------------------------------------------------------
3)
******************************************************************************************************************************





*/