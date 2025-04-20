#pragma once

#include "ostream"
#include "istream"

class Mint
{
public:
	Mint() = default;
	explicit Mint(int x) : mval{ x } {}
	// sýnýfýn içinde tanýmlansalarda member function deðiller çünkü friend fonksiyonlar yani global

	// symetric binary operators
	friend Mint operator+(const Mint& lhs, const Mint& rhs)  
	{
		return Mint{ lhs } += rhs; // aritmetik operatörlerin ovarload edilmesinde scott mayersýn effective C++ kitabýnda çok güzel bir yaklaþým var hoca bu yaklaþýmý kullanacak
								   // + ile += birbirine çok benziyor bu yüzden += fonksiyonunu yazalým bunuda + fonksiyonunda çaðýracaðýz
	}
	friend Mint operator-(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } -= rhs;
	}
	friend Mint operator*(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } *= rhs;

	}
	friend Mint operator/(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } /= rhs;

	}
	friend Mint operator%(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } %= rhs;

	}

	// equality operators/relations operators
	// C++20 kullanmýyorsak hepsini ayrý ayrý implemente etmek yerine == fonksiyonunu implemente ediyoruz != foknsiyonu == fonksiyonunu çaðýrýyor gibi gibi
	friend bool operator==(const Mint& lhs, const Mint& rhs)
	{
		return lhs == rhs;
	}
	friend bool operator!=(const Mint& lhs, const Mint& rhs)
	{
		return !(lhs == rhs); // derleyici burda yeni bir fonksiyon yazmýyor yazmýþ olduðumuz == operatör fonksiyonunun ! ifadesini alýyor
		// return !operator==(lhs,rhs); // bazý programcýlar böyle yazmayý tercih ediyor
	}
	friend bool operator<(const Mint& lhs, const Mint& rhs)
	{
		return lhs.mval < rhs.mval;
	}
	friend bool operator>=(const Mint& lhs, const Mint& rhs)
	{
		return !(lhs < rhs); // operator >= operator < fonksiyonunu çaðýrdý
	}
	friend bool operator>(const Mint& lhs, const Mint& rhs)
	{
		return rhs < lhs;
	}
	friend bool operator<=(const Mint& lhs, const Mint& rhs)
	{
		return !(rhs < lhs);
	}

	// assigned operators
	Mint& operator+=(const Mint& other) // sýnýfa yazýlan atama operatör fonksiyonlarý geri dönüþ deðeri sýnýf türünden l value reference olmasý gerekir
	{
		mval += other.mval;
		return *this;
	}
	Mint& operator-=(const Mint& other)
	{
		mval -= other.mval;
		return *this;
	}
	Mint& operator*=(const Mint& other)
	{
		mval *= other.mval;
		return *this;
	}
	Mint& operator/=(const Mint& other)
	{
		mval /= other.mval;
		return *this;
	}
	Mint& operator%=(const Mint& other)
	{
		mval %= other.mval;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Mint& m) // inserter
	{
		return os << '[' << m.mval << ']'; // ostream sýnýfýnýn int parametreli << fonksiyonunu çaðýrýyor
	}

	friend std::istream& operator>>(std::istream& is, Mint& m) // extraction
	{
		return is >> m.mval;
		// bu implementasyonlarý cpp dosyasýndada yapabiliriz iosfwd adýnda baþlýk dosyasýný kullanmamýz gerekir kodlarýn kendileri yok ama onlarýn forward declerationu var
	}

	Mint operator+() const
	{
		return *this;
	}

	Mint operator-() const
	{
		return Mint(-mval);
	}

	bool operator!() const
	{
		return static_cast<bool>(mval);
	}

	Mint& operator++() // prefix
	{
		++mval;
		return *this;
	}

	Mint operator++(int) // postfix
	{
		 Mint retval { *this };
		 ++*this; // nesnenin deðerini 1 arttýrmak için prefix fonksiyonunu çaðýrýyor bu ifadeyi yazmak yerinede operator++() þeklinde yazabiliriz
		 return retval; 
	}

	int get()const
	{
		return mval;
	}

	Mint& operator--() // prefix
	{
		--mval;
		return *this;
	}

	Mint operator--(int) // postfix
	{
		Mint retval{ *this };
		--*this; 
		return retval;
	}
	
	explicit operator int() const
	{
		return mval;
	}
private:
	int mval{};
};
