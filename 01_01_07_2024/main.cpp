/*
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
- **Yan Etkiler**: İkinci operandın yan etkileri (örneğin, fonksiyon çağrıları) varsa, bu yan etkiler yalnızca ihtiyaç duyulduğunda gerçekleşir. Bu, kodun daha güvenli ve 
öngörülebilir olmasını sağlar.

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
NOT:C++ da iki karakterlik ayıraç atomları tanımlanmıştır. Derleyici ve önişlemci program bu karakter
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

*/