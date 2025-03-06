/*

AAA(ALMOST ALWAYS AUTO) demek kullanabildiðin her yerde auto kullan

C++ dilinde, "expression" ve "statement" terimleri farklý anlamlara gelir ve programýn yapý taþlarýný oluþtururlar. Ýþte bu terimlerin tanýmlarý ve aralarýndaki farklar:

### Expression (Ýfade)

Bir **expression** (ifade), bir deðeri hesaplayan veya deðerlendiren bir kod parçasýdýr. Ýfadeler tek baþýna bir deðer üretebilir
veya yan etkilere neden olabilir. Ýfadeler, çeþitli operatörler ve operandlar kullanýlarak oluþturulabilir.

Ýfadelerin bazý örnekleri:

1. **Sabitler**: `42`, `'a'`, `3.14`
2. **Deðiþkenler**: `x`, `y`, `z`
3. **Aritmetik Ýfadeler**: `x + y`, `a * b - c`
4. **Fonksiyon Çaðrýlarý**: `foo()`, `bar(x, y)`
5. **Üyelik Ýfadeleri**: `obj.member`, `ptr->member`
6. **Yöntem Çaðrýlarý**: `obj.method()`
7. **Dizine Eriþim**: `array[index]`

Ýfadeler genellikle bir deðeri deðerlendirir ve bir sonuç döndürür. Örneðin, `x + y` ifadesi `x` ve `y` deðerlerini toplar ve sonuç olarak toplamý döndürür.

### Expression Statement (Ýfade Cümlesi)

Bir **expression statement** (ifade cümlesi), bir veya daha fazla ifadeyi içerebilen, belirli bir eylemi gerçekleþtiren ve genellikle bir noktalý virgül (`;`)
ile biten bir kod parçasýdýr. Ýfade cümleleri, programýn akýþýný kontrol eder ve belirli iþlemleri gerçekleþtirir.

expression statement bazý örnekleri:

1. **Basit Ýfade Cümlesi**: Bir ifadeyi içerir ve bir noktalý virgül ile biter.
    x = y + 1; // Basit ifade cümlesi

2. **Deklarasyon Cümlesi**: Bir deðiþken veya fonksiyon bildirir.

    int a = 5; // Deðiþken bildirimi

3. **Kontrol Akýþý Cümleleri**: `if`, `for`, `while` gibi yapýlarý içerir.

    if (x > 0) {
        y = x;
    }
    for (int i = 0; i < 10; ++i) {
        sum += i;
    }

4. **Dönüþ Cümlesi**: Bir fonksiyondan deðer döndürür.

    return x + y;

5. **Blok Cümlesi**: Birden fazla ifade cümlesini bir blokta gruplar.

    {
        int x = 10;
        int y = 20;
        int z = x + y;
    }

### expression ve statement Cümleleri Arasýndaki Fark

- **expression**, bir deðeri hesaplar veya deðerlendirir ve genellikle bir deðer döndürür. Ýfade cümlesi içinde kullanýlabilirler.
- **expression statement**, programýn yürütme akýþýný kontrol eder ve genellikle belirli bir görevi yerine getirir. Bir ifadeyi içerir ve bir noktalý virgül ile biter.

Örneðin:

// Ýfade:
x + y

// Ýfade cümlesi:
x = y + 1; // expression statement

Ýfade, sadece `x + y` deðerini hesaplar. Ancak ifade cümlesi, `x` deðiþkenine `y + 1` deðerini atar ve bir eylemi tamamlar.

### Özet

- **Expression (Ýfade)**: Bir deðeri hesaplayan veya deðerlendiren bir kod parçasýdýr. Bir sonuç döndürür.
- **Statement (Ýfade Cümlesi)**: Bir veya daha fazla ifadeyi içerebilir ve belirli bir eylemi gerçekleþtiren bir kod parçasýdýr. Noktalý virgül ile biter ve programýn akýþýný kontrol eder.

Bu ayrým, C++ programlama dilinde kod yazarken oldukça önemlidir ve doðru kullaným, kodun doðru ve beklenen þekilde çalýþmasýný saðlar.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde, bir ifadenin (expression) türünü anlamak için ifadelerin deðer kategorilerine (value categories) ayrýlmasý gerekir.
Bu deðer kategorileri, ifadenin bellekte bir nesneyi temsil edip etmediðini ve eðer ediyorsa, bu nesnenin yaþam süresinin ne kadar olduðunu belirtir.
C++'ta üç temel (primary) deðer kategorisi vardýr: lvalue, prvalue ve xvalue. Bu kategoriler, bir ifadenin nasýl deðerlendirildiðini ve hangi baðlamlarda kullanýlabileceðini belirler.

### Primary Value Categories (Birincil Deðer Kategorileri)

1. **Lvalue (Left Value)**
    - Bellekte bir konumu temsil eder ve bu konumda bir nesneye iþaret eder.
    - Lvalue ifadeleri, deðiþtirilebilir (mutable) nesneleri temsil eder.
    - Bir lvalue ifadesi, bir deðiþkenin adý olabilir veya bir referans olabilir.

    #### Örnekler:

    int x = 10;  // x bir lvalue'dir.

2. **Prvalue (Pure Rvalue)**
    - Geçici bir deðeri temsil eder, doðrudan bellekte bir nesneyi temsil etmez.
    - Prvalue ifadeleri genellikle hesaplama sonuçlarýdýr ve kýsa ömürlüdür.
    - Prvalue ifadeleri, fonksiyon dönüþ deðerleri veya geçici (temporary) nesneler olabilir.

    #### Örnekler:

    int y = x + 5;  // x + 5 bir prvalue'dir.
    std::string("hello") // geçici bir std::string nesnesi, bir prvalue'dir.

3. **Xvalue (eXpiring Value)**
    - Bellekte bir nesneyi temsil eder, ancak bu nesne yakýnda yok olacak veya taþýnacak (moved-from) bir nesnedir.
    - Xvalue ifadeleri genellikle kaynaklarý taþýmak için kullanýlýr.

    #### Örnekler:

    std::string s1 = "hello";
    std::string s2 = std::move(s1); // std::move(s1) bir xvalue'dir.
--------------------------------------------------------------------------------------------------------------------------------------------------
C++ dilinde, ifadelerin (expressions) nasýl deðerlendirileceðini ve hangi baðlamlarda kullanýlabileceðini anlamak için deðer
kategorileri (value categories) kullanýlýr. Birincil (primary) deðer kategorileri olan lvalue, prvalue ve xvalue dýþýnda,
bu deðer kategorilerinin birleþiminden oluþan daha genel kategoriler de vardýr. Bu birleþik (combined) deðer kategorileri, daha geniþ anlamda ifadelerin nasýl iþleneceðini tanýmlar.

### Combined Value Categories (Birleþik Deðer Kategorileri)

1. **Glvalue (Generalized Lvalue)**
    - lvalue ve xvalue ifadelerinin birleþimidir.
    - Bellekte bir nesneyi temsil eder.
    - Nesnenin adresi alýnabilir.

    #### Özellikler:
    - Bellekte bir konumu iþaret eder.
    - Nesneye doðrudan eriþilebilir ve bu nesne deðiþtirilebilir.

    #### Örnekler:

    int x = 42;
    int &ref = x;       // ref bir lvalue'dir.
    int &&rref = 42;    // rref bir xvalue'dir.

    // Glvalue örnekleri
    x = 5;              // x bir lvalue (dolayýsýyla bir glvalue) ifadesidir.
    std::move(x) = 10;  // std::move(x) bir xvalue (dolayýsýyla bir glvalue) ifadesidir.

2. **Rvalue (Right Value)**
    - prvalue ve xvalue ifadelerinin birleþimidir.
    - Bellekte kýsa ömürlü veya geçici (temporary) bir nesneyi temsil eder.
    - Kaynaklarýn taþýnmasý ve geçici nesnelerin kullanýmý için kullanýlýr.

    #### Özellikler:
    - Bellekte bir konumu iþaret etmez, dolayýsýyla adresi alýnamaz.
    - Genellikle hesaplama sonuçlarý veya geçici nesnelerdir.

    #### Örnekler:

    int y = 42;
    int z = y + 5;      // y + 5 bir prvalue'dir (dolayýsýyla bir rvalue).
    int &&rref = 42;    // 42 bir prvalue'dir (dolayýsýyla bir rvalue).
    std::move(y);       // std::move(y) bir xvalue'dir (dolayýsýyla bir rvalue).

### Kategori Özeti

- **Glvalue (Generalized Lvalue):** lvalue ve xvalue ifadelerinin birleþimidir. Bellekte bir nesneyi temsil eder.
- **Rvalue (Right Value):** prvalue ve xvalue ifadelerinin birleþimidir. Bellekte kýsa ömürlü veya geçici bir nesneyi temsil eder.
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

comma operatör ( , ) virgül operatörü C de R value C++ da L value expression oluþturuyor

turnory operatörü C de R value C++da L value expression oluþturur
--------------------------------------------------------------------------------------------------------------------------------------------------
referanslar derleyici açýsýndan pointer ile aynýdýr kýsacasý pointerlarýn maskelenmiþ halidir arka planda pointer iþlemi görür
bazý yerlerde pointer semantiði uygun olmadýðý için referanslar gelmiþtir

NOT:Referanslar default initialize edilemez

    int& r; //syntax error

    referanslarýn data type'ý ayný olmak zorundadýr

    referanslar bir kez baþlatýldýktan sonra baþka bir nesneye referans olamazlar(re-bindeble deðil)
        int x = 10;
        int y = 10;
        int&r = x;
        r = y; // burda y'yi x'e atamak anlamýna geliyor y'yi referans almýyor

int x = 5;

int& r1 = x++ // son ek ++ operatörü c++ dilinde rvalue olduðu için syntax error
int& r1 = ++x // ön ek ++ operatörü c++ dilinde lvalue olduðu için geçerli

int x = 5;
int& r = x;

std::cout << &r << '\n'; // x'in adresine ulaþýlýr

int x = 10;
int y = 5;
int* const p = &x; // p pointerý yalnýzca x in adresini tutacaðý güvencesini veriyor yani p nin adresi deðiþemez hayatý boyunca sadece x'in adresini göstericek
bu pointer türünün 3 adý vardýr
// const pointer to int
// top level const
// right const

p = &y // syntax error
*p = y // geçerli

const int* p = &x // p adlý pointerin içeriði dereferance edilemez sadece okuma amaçlýdýr(read-only pointer) ama adresi deðiþebilir
bu pointer türünün 3 adý vardýr
// pointer to const int
// low level const
// left const

*p = 20; // syntax error
p = &y; // geçerli

const int* p const = &x; // p adlý pointerin gösterdiði yerde adresi de deðiþemez
//const pointer to const int

*p = 20; // syntax error
p = &y; // syntax error

*p oluþturduðu ifade L Value
*p++ ve *p-- R value

NOT:Pointerlarý referans almak için kullanýlan syntax biçimi þöyledir

int x{} // zero initialization
int y{36} // direct list initialization
int* p = &x; // x in adresi p pointera atandý p nin içinde 0 deðeri var
int*& r = p; //p adlý pointer r adlý referansa atandý r demek artýk x demek çünkü p x adlý deðiþkenin adresini gösteriyor

r = &y; // p = &y r referansý p ye referans olduðu için p'ye y'nin adresi atanýyor
*p = 678; // y'nin deðeri 678 oluyor

int foo(); // r value

NOT:call by value ile pass by value ayný þey demek

NOT:
void func(T& r) // ifadesi bir mutator bir ifadenin deðerini deðiþtiryor anlamýna gelir
void func(T* r) // mutator
void func(const T& r) // accessor
void func(const T* r) // accessor
T& func() // böyle bir fonksioyn gördüðümüzde bu fonksiyon bize bir nesne döndürüyor demeliyiz bu fonksiþyona çaðrý yaparak bir nesneyi kullanma hakkýna eriþmiþ oluyoruz
T* func() // nesnenin adresini döndüren fonksiyon
const T& func(); // nesneye ulaþmak için kullanýlýr nesneninde const olmasý gerekir
const T* func(); // nesneye ulaþmak için kullanýlýr nesneninde const olmasý gerekir

MÜLAKAT SORUSU

C dilinde foo(x) adýnda bir çaðrý görüyorsak bunun call by value olduðunu anlarýz
ama C++ dilinde bilemeyiz çünkü referans semantiði kullanýlmýþ olabilir

NOT:Otomatik ömürlü (automatic storage duration) bir nesnenin adresini döndürmek mantýklý deðildir çünkü bu nesne,
fonksiyonun bitiminde yok olur ve bellekteki adresi geçersiz hale gelir. Otomatik ömürlü nesneler, tanýmlandýklarý
bloktan çýkýldýðýnda otomatik olarak silinirler. Bu nedenle, bu tür nesnelerin adresini döndürmek, o adresin geçerliliði
sona erdiðinde bellek hatalarýna ve tanýmsýz davranýþlara yol açar.

### Örnek Açýklama

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

Bu kod parçasý sorunsuz çalýþýr çünkü `foo` fonksiyonu `int` türünde bir deðer döndürüyor ve bu deðer `g`nin kopyasýdýr. `g`, `foo`
fonksiyonu sona erdiðinde yok olsa bile, döndürülen kopya `x` deðiþkenine atanýr ve bu nedenle geçerli olur.

### Geçersiz Kod

Ancak, `g`nin adresini döndürmeye çalýþýrsanýz, bu durumda sorunlarla karþýlaþýrsýnýz:

#include <iostream>

int* foo()
{
    int g = 45;
    return &g;  // Geçersiz: g'nin adresini döndürmek
}

int main()
{
    int* x = foo(); // dangling pointer
    std::cout << *x;  // Tanýmsýz davranýþ
    return 0;
}

Bu kodda `foo` fonksiyonu, `g`nin adresini döndürmeye çalýþýyor. g otomatik ömürlü bir nesne olduðu için tanýmsýz davranýþ olur `foo` sona erdiðinde `g` yok olur ve `x`
geçersiz bir adresi iþaret eder. `*x` ifadesi tanýmsýz davranýþa yol açar.

### Doðru Yaklaþým

Eðer fonksiyondan bir nesnenin adresini döndürmek istiyorsanýz, o nesnenin statik veya dinamik ömürlü olmasý gereklidir:

1. **Statik Ömürlü Nesneler**:

    int* foo()
    {
        static int g = 45;
        return &g;  // Geçerli: g'nin adresi her zaman geçerli kalýr
    }

2. **Dinamik Ömürlü Nesneler**:

    int* foo()
    {
        int* g = new int(45);
        return g;  // Geçerli: g'nin adresi, delete edilene kadar geçerli kalýr
    }

    int main()
    {
        int* x = foo();
        std::cout << *x;
        delete x;  // Dinamik ömürlü nesne serbest býrakýlýr
        return 0;
    }

Bu yaklaþýmlar, döndürülen adresin geçerli kalmasýný saðlar. Ancak, dinamik ömürlü nesnelerle çalýþýrken
bellek yönetimi önemlidir ve `delete` ile bellek serbest býrakýlmalýdýr.

volatile
volatile niteleyicisi, bir deðiþkenin program dýþý kaynaklar (örneðin, donaným veya baþka bir iþ parçacýðý) tarafýndan deðiþtirilebileceðini belirtir.
Bu, derleyicinin bu deðiþken üzerinde optimizasyon yapmamasý gerektiðini garanti eder.

volatile int flag = 0;
while (flag == 0) {
    // Bu döngü, 'flag' deðiþkeninin program dýþý bir kaynak tarafýndan deðiþtirilebileceðini belirtir.
}

const volatile Birlikte Kullanýmý
const volatile niteleyicileri birlikte kullanýldýðýnda, deðiþkenin program tarafýndan deðiþtirilemeyeceðini, ancak program dýþý kaynaklar tarafýndan
deðiþtirilebileceðini belirtir. Bu, özellikle donaným kayýtlarý veya çok iþ parçacýklý programlama durumlarýnda kullanýþlýdýr.

const volatile int statusRegister = 0xFF;
while (statusRegister == 0xFF) {
    // 'statusRegister' deðiþkeni program tarafýndan deðiþtirilemez, ancak donaným tarafýndan deðiþtirilebilir.
}

NOT:lvalue referans ve rvalue atamasý

int g = 45;

int &foo() //foo burda l value referans ve g nin adresini döndürüyor
{
    return g; // g nin adresi dönüyor
}

int* foo() // yukarýdaki referans tanýmlamasýnýn pointer karþýlýðý bu þekildedir
{
    return &g;
}

int main()
{
    int &x = foo(); x ile foo lvalue referans olduðu için x deðiþkeni g deðiþkenine referanstýr
    ++*foo() // çaðrýsý aslýnda derleyici tarafýndan ++(*(foo())) ifadesi olarak ele alýnýr

    return 0;
}

int g = 45;

int foo() // foo burda rvalue
{
    return g;
}

int main()
{
    int &x = foo(); x lvalue referans olduðu için bir lvalue deðerine rvalue atanamaz derleme hatasý verir

    return 0;
}

int g = 45;

int foo() // r value
{
    return g;
}

int main()
{
    int x = foo(); // x in kendisi burda lvalue ama aldýðý deðer rvalue yani olan þey aslýnda x = 45;

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

NOT:Array decay ve array pointer farklýlýðý

int a[5] = {1,2,3,4,5};

int* p = a; // array decay olarak geçer a dizisinin ilk elemanýnýn adresini tutar(türü int)

int (*p)[10] = &a; // p, a dizisinin tamamýnýn adresini tutar ve p, a dizisini iþaret eden bir pointer olur(türü int[5])

int (&r)[10] = a; // r, a dizisinin tamamýna referans olan bir referans deðiþkenidir.

NOT:Dizinin tamamýnýn adresini döndürmek ve dizinin ilk elamanýný döndürmek arasýnda ki fark

### 1. Döngü

for (int i = 0; i < 10; i++)
{
    std::cout << &a + i << " ";
}

Bu döngüde `&a + i` ifadesi kullanýlýyor. Bu ifade, `a` dizisinin baþlangýç adresine `i` kadar dizinin tipine göre bir ofset ekler.
Burada `&a` ifadesi, `a` dizisinin tamamýný iþaret eden bir pointer anlamýna gelir ve türü `int (*)[10]`'dir.

Dolayýsýyla `&a + i` ifadesi aslýnda þu anlama gelir:
- `&a` dizisinin baþlangýç adresi (`int (*)[10]` türünde).
- `+ i` bu adresin üzerine `i` tane `int[10]` boyutu kadar ekleme yapar. Yani her adýmda 10 * sizeof(int) = 40byte boyutu kadar aralýklarla ilerler.

Bu nedenle, bu döngüde her iterasyonda dizinin her seferinde 40 eleman uzunluðunda bir blok atlayarak ilerlemesini saðlýyoruz.
Adresleri bastýrýyoruz, bu adresler büyük ihtimalle bellek bloklarý arasýnda büyük aralýklara sahip olacaktýr.

### 2. Döngü

for (int i = 0; i < 10; i++)
{
    std::cout << a + i << " ";
}
Bu döngüde `a + i` ifadesi kullanýlýyor. `a` ifadesi, dizinin baþlangýç adresini (`int*` türünde) temsil eder.

Dolayýsýyla `a + i` ifadesi þu anlama gelir:
- `a` dizisinin baþlangýç adresi (`int*` türünde).
- `+ i` bu adresin üzerine `i` tane `int` boyutu kadar ekleme yapar. Yani her adýmda 1 * sizeof(int) boyutu atlar.

Bu nedenle, bu döngüde her iterasyonda dizinin bir sonraki `int` elemanýna geçerek ilerleriz. Adresleri bastýrýyoruz ve bu adresler
her seferinde sadece 1 * sizeof(int) = 4byte boyutu kadar aralýklarla ilerler.

Özetle:

&a ifadesi, dizinin tamamýný temsil eden bir adres dönerken,
a ifadesi veya a + 0 ifadesi, dizinin ilk elemanýnýn adresini döner.

NOT:Referanslara Farklý Türden Bir Nesne ile Ýlkdeðer Verilmesi Durumu

Bir referansýn ayný türden bir deðiþkenle ilkdeðer verilerek tanýmlanmasý gerektiðini belirtmiþtik.
Referansýns farklý türden bir deðiþkenle ilkdeðer verilerek tanýmlanmasý geçersizdir. Aþaðýdaki örneði
inceleyin:
void func
{
double d = 10.5;
int &r = d; //Geçersiz
//...
}
Ancak const bir referansa baþka türden bir nesne ile ilk deðer verilmesi geçerlidir:
void func()
{
double d = 10.5;
const int &r = d; // Geçerli
//...
}
Bu durumda önce const referansa baðlanan farklý türden nesnenin deðeri, referansýn türünden yaratýlacak
geçici bir nesneye atanýr. Referans da bu geçici nesneye baðlanýr. Yani derleyici aþaðýdaki gibi bir kod üretir:

int main()
{
double d = 10.5;
int temp = (int)d;
const int &r = temp;
return 0;
}

Bir diziyle ilgili genel iþlem yapan iþlev tanýmlanabiliyordu. Böyle iþlevlere dizinin baþlangýç adresi ve boyutu
argüman olarak gönderiliyordu. Dizinin baþlangýç adresini iþleve göndermek için gösterici kullanýyordu. Peki,
böyle bir iþlevin parametresi bir referans olabilir mi? Hayýr! referanslarla bu iþ göstericilerle olduðu gibi
yapýlamaz. Ancak, örneðin 10 elemanlý int türden bir diziyi gösteren gösterici olduðu gibi 10 elemanlý int türden
bir dizinin yerine geçecek bir referans da tanýmlanabilir.

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
Referanslar daha çok, tek bir nesneyi adres yöntemiyle iþleve geçirmek amacýyla kullanýlabilir. Örneðin tek bir
int deðer ya da tek bir yapý deðiþkeni referans yoluyla iþleve geçirilebilir. Ancak int türden bir dizi ya da bir yapý
dizisi bu yöntemle iþleve doðal bir biçimde geçirilemez.

Sözdizimsel açýdan referanslarýn göstericilere göre kullaným alanlarý daha dardýr. Gösterici dizileri olur ama
referans dizileri olamaz. Göstericileri gösteren göstericiler olabilir ama referanslarýn yerine geçen referanslar
olamaz.
Ancak þüphesiz bir göstericinin yerine geçen bir referans olabilir.

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
bir diziyi iþaret eden bir pointer referansý (pointer-to-array reference)

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
Pointer referanslarý, pointer'larýn kendilerine referans vermemizi saðlayan bir C++ dil özelliðidir. Bu, bir pointer deðiþkenini bir fonksiyona aktarýrken,
fonksiyonun sadece pointer'ýn iþaret ettiði deðeri deðil, pointer'ýn kendisini de deðiþtirebilmesine olanak tanýr. Þimdi bunu daha detaylý bir þekilde inceleyelim.

### 1. **Pointer ve Pointer Referansý**

- **Pointer:**
  Bellekteki bir deðiþkenin adresini tutan bir deðiþkendir. Örneðin:

  int x = 10;
  int* ptr = &x; // ptr, x'in adresini tutar

  Burada `ptr`, `x` deðiþkeninin adresini saklar. Yani `*ptr` yazýldýðýnda `x`'in deðerine ulaþýrýz.

- **Pointer Referansý:**
  Bir pointer'ýn kendisine referans vermek, yani pointer'ýn iþaret ettiði adresi (deðer deðil) deðiþtirebilmek için kullanýlýr.
  Pointer referansý `int*&` gibi bir sözdizimiyle ifade edilir.
  Örnek:

  int x = 10;
  int y = 20;
  int* ptr = &x;

  int*& ref = ptr; // ref, ptr'nin referansý
  ref = &y;        // ref üzerinden ptr deðiþtirildi

  Artýk `ptr` deðiþkeni `y`'nin adresini tutar.

### 2. **Pointer Referansý Neden Kullanýlýr?**

#### a. Pointer'ý Deðiþtirmek:
Eðer bir fonksiyonun pointer'ýn iþaret ettiði adresi deðiþtirmesini istiyorsanýz, pointer referansý kullanýrsýnýz.

Örnek:

void changePointer(int*& ptr) {
    static int z = 50; // Kalýcý bir deðiþken
    ptr = &z;          // Pointer'ýn iþaret ettiði adresi deðiþtir
}

int main() {
    int x = 10;
    int* myPtr = &x;

    std::cout << "Before: " << *myPtr << '\n'; // 10
    changePointer(myPtr);
    std::cout << "After: " << *myPtr << '\n';  // 50

    return 0;
}

**Çalýþma Mantýðý:**
- `changePointer` fonksiyonu, `myPtr`'nin adresini deðiþtirir.
- Fonksiyon, pointer'ý referans olarak aldýðý için deðiþiklik çaðýran tarafa yansýr.

#### b. Dinamik Bellek Yönetimi:
Dinamik olarak oluþturulan nesneleri dýþarý taþýmak için kullanýlýr. Bu, `new` ve `delete` ile sýk karþýlaþýlan bir durumdur.

Örnek:

void createObject(int*& ptr) {
    ptr = new int(42); // Dinamik olarak bir int oluþtur ve pointer'a ata
}

int main() {
    int* myPtr = nullptr;

    createObject(myPtr); // Fonksiyon pointer'ý deðiþtirir
    std::cout << "Value: " << *myPtr << '\n'; // 42

    delete myPtr; // Dinamik belleði serbest býrak
    return 0;
}

**Çalýþma Mantýðý:**
- `createObject`, dinamik olarak bir `int` oluþturur ve `myPtr`'nin adresini deðiþtirir.
- Pointer referansý olmadan, bu deðiþiklik fonksiyonun dýþýna yansýmazdý.

### 3. **Pointer Referansýnýn Söz Dizimi**

Pointer referanslarý þu þekilde tanýmlanýr:

int*& ref = pointer; // ref, bir pointer'ýn referansýdýr.

Burada:
- `int*` bir pointer türüdür.
- `&` referans anlamýna gelir.
- `ref` artýk `pointer` deðiþkeninin referansýdýr.

### 4. **Pointer Referansý ve Dereferans Farký**

- Dereferans (`*`) bir pointer'ýn iþaret ettiði deðere ulaþmayý saðlar:

  int x = 10;
  int* ptr = &x;

  std::cout << *ptr; // x'in deðeri (10)

- Pointer referansý (`*&`) pointer'ýn kendisini deðiþtirmeyi saðlar:

  int x = 10, y = 20;
  int* ptr = &x;

  int*& ref = ptr; // Pointer'ýn referansý
  ref = &y;        // Pointer artýk y'yi iþaret eder

  std::cout << *ptr; // 20

### 5. **Neden `*&` Kullanýyoruz?**

Bir pointer'ý doðrudan deðiþtirmek için neden referansa ihtiyacýmýz var? Bunun sebebi, C++'da fonksiyonlara deðer kopyalanarak (pass-by-value) veri gönderilmesidir:
- Eðer bir pointer fonksiyona **deðer olarak** (`int*`) geçirilirse, bu pointer'ýn bir kopyasý üzerinde iþlem yapýlýr ve orijinal pointer deðiþmez.
- Eðer bir pointer **referans olarak** (`int*&`) geçirilirse, orijinal pointer deðiþtirilir.

### 6. **Hata Durumlarý ve Dikkat Edilmesi Gerekenler**

#### a. `nullptr` Kullanýmý:
Bir pointer referansýnýn `nullptr` almasý mümkündür, ancak dereferans etmeye çalýþýrsanýz program çöker:

int* ptr = nullptr;
int*& ref = ptr;

std::cout << *ref; // HATA: nullptr dereferansý!

#### b. Bellek Sýzýntýsý:
Dinamik bellekte bir pointer referansýný yanlýþ yönetmek bellek sýzýntýsýna yol açabilir. Örneðin:

void badExample(int*& ptr) {
    ptr = new int(10); // Yeni bellek ayrýldý
    // Eski bellek serbest býrakýlmadý, bu bir bellek sýzýntýsýdýr!
}

#### c. Kullanýlmayan Adresler:
Statik ya da otomatik ömürlü deðiþkenlere referans verirken dikkatli olun. Örneðin, lokal bir deðiþkenin adresi döndürülemez:

int* unsafePointer() {
    int x = 10;
    return &x; // HATA: Lokal deðiþkenin adresi döndürüldü
}

### 7. **Özet**

- **Pointer referansý (`int*&`)** bir pointer'ý deðiþtirmek için kullanýlýr.
- Bellek yönetimi ve performans iyileþtirme gibi durumlarda faydalýdýr.
- Yanlýþ kullanýldýðýnda bellek sýzýntýlarýna veya `nullptr` dereferansýna yol açabilir.
--------------------------------------------------------------------------------------------------------------------------------------------------
Dangling Pointer Nedir:

Dangling pointer (asýlý gösterici), bellekte geçersiz veya serbest býrakýlmýþ bir adresi iþaret eden bir göstericidir.
Bu durum, bellek hatalarýna ve tanýmsýz davranýþlara yol açar. Bir gösterici, hedeflediði bellek alaný geçerli olmadýðý
halde kullanýlmaya çalýþýldýðýnda dangling pointer durumu ortaya çýkar.

1. **Otomatik Ömürlü Nesne Adresini Döndürme:**

   Otomatik ömürlü (automatic storage duration) n
### Dangling Pointer Örnekleri

nesneler, fonksiyonun sona ermesiyle geçersiz hale gelirler. Bu nesnelerin adresini döndürmek dangling pointer oluþturur.

   int* foo() {
       int x = 10;
       return &x;  // Geçersiz: x'in adresini döndürmek
   }

   int main() {
       int* p = foo();
       // p burada dangling pointer'dýr.
       std::cout << *p;  // Tanýmsýz davranýþ
       return 0;
   }

2. **Dinamik Bellek Serbest Býrakma:**

   Dinamik bellek alaný `delete` veya `free` ile serbest býrakýldýðýnda, bu belleði iþaret eden gösterici dangling pointer haline gelir.

   int main() {
       int* p = new int(5);
       delete p;  // Bellek serbest býrakýlýr
       // p burada dangling pointer'dýr.
       std::cout << *p;  // Tanýmsýz davranýþ
       return 0;
   }

3. **Scope Dýþýna Çýkan Yerel Deðiþken:**

   Bir gösterici, scope dýþýna çýkan bir yerel deðiþkeni iþaret ediyorsa dangling pointer olur.

   int* ptr;

   {
       int x = 20;
       ptr = &x;
   }

   // x burada scope dýþýna çýktý ve ptr dangling pointer'dýr.
   std::cout << *ptr;  // Tanýmsýz davranýþ

### Dangling Pointer'larý Önlemek Ýçin Ýpuçlarý

1. **Göstericiyi Serbest Býrakma Sonrasý Null Yapmak:**

   Dinamik bellek serbest býrakýldýðýnda göstericiyi null yaparak, tekrar kullanýlmasýný önleyebilirsiniz.

   int* p = new int(5);
   delete p;
   p = nullptr;  // p artýk geçerli bir adresi iþaret etmiyor

2. **Akýllý Göstericiler Kullanmak:**

   C++'ta akýllý göstericiler (smart pointers) kullanarak bellek yönetimini otomatikleþtirebilir ve dangling pointer sorunlarýný azaltabilirsiniz.

   #include <memory>

   void foo() {
       std::unique_ptr<int> p = std::make_unique<int>(10);
       // p burada otomatik olarak bellekten serbest býrakýlacak
   }

3. **Geçerli Adresler Döndürmek:**

   Otomatik ömürlü nesnelerin adreslerini döndürmek yerine statik veya dinamik ömürlü nesnelerin adreslerini döndürmek.

   int* foo() {
       static int x = 10;
       return &x;  // Geçerli: x her zaman geçerli kalýr
   }

Dangling pointer'lar bellek hatalarýna ve program çökmesine yol açabilir, bu yüzden dikkatle yönetilmelidir.
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT: referanslarda ampersand operatöründen sonra const yazmak anlamlý deðildir
çünkü referanslar zaten tek bir yeri gösterdiði için default olarak const'tur
gösterdiði yer deðiþmeyeceði için const niteliðini ampersand operatöründen sonra eklemenin anlamý yoktur sadece fazlalýktýr

int x = 10;
int& const r = x; // default olarak zaten orda gizli bir const bulunur yazmaya gerek yoktur

int x = 10;
const int& r = x;

int y = r + 5; // böyle bir ifade kullanýrsak burda r'nin deðeri hala 10dur y'nin deðeri 15 olur
std::cout << y;
--------------------------------------------------------------------------------------------------------------------------------------------------
NOT:Bir fonksiyonun setter veya getter olduðunu nereden anlarýz

void foo(T &r); // Const anahtar kelimesi olmadýðý için deðeri deðiþtirmeye yönelik yazýlan bir fonksiyon olarak
anlaþýlýr bu tarz fonksiyonlar gördüðümüzde anlamamýz gereken þey bu fonksiyon bir deðeri set ettiðidir

void foo(const T &r) // Const anahtar kelimesi olduðu için sadece okuma amacýyla kullanýlýr
--------------------------------------------------------------------------------------------------------------------------------------------------
Bir fonksiyon veya deðiþken const & ise hem lvalue deðer hemde rvalue deðer kabul eder

double x = 2.67;
const int& r = x; // farklý türden olsa bile

int temp = x;
const int& r = temp;

void foo(int &r) // sadece lvalue alýr
{
    std::cout<<r;
}

int main()
{
    int x = 5;

    foo(x + 5); // pr value olduðu için hata
}

void foo(const int &r) //  lvalue ve rvalue alýr
{
    std::cout<<r;
}

int main()
{

    int x = 5;

    foo(x + 5); // geçerli foo deðeri const olduðu için

}

NOT:Geri dönüþ deðeri Referans olmayan fonksiyon deðerleri rvalue sayýlýr

Struct Nec{};

Nec func(const Nec&);
Nec foo();

int main()
{
    func(foo()); // func fonksiyonu const olduðu için hem rvalue hemde lvalue deðeri kabul eder
}

Nec func(Nec&);
Nec foo();

int main()
{
    func(foo()); // func fonksionu lvalue referans aldýðý için foo fonksiyonu yine atanamaz çünkü foo rvalue
}

void bar(Nec&);
Nec& foo();

int main()
{
    bar(foo()) // GEÇERLÝ bar fonksiyonu lvalue referans deðeri alýyor
    foo fonkisiyonuda referans döndürdüðü için lvalue referans olmuþ oluyor
}
--------------------------------------------------------------------------------------------------------------------------------------------------
func(&x) operatörünün oluþturduðu ifade PR value
func(nullptr) PR value
string literalleri L value
a[3] gibi bir ifade L value

pointer array
    int x = 5;
    int y = 5;
    int* p[2]{ &x,&y };

pointer deðiþkenler default initalize edilebilir ama iyi bir uygulama deðildir
int* p; // wild pointer denir

*/