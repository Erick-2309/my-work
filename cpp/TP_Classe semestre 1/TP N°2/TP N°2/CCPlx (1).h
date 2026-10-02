//definition de la classe 
#include<iostream>
using namespace std;

class CCPlx
{
private:
	double m_Re;
	double m_Im;
public:
	//CCPlx();
    CCPlx(double = 0.0, double = 0.0);
    //CCPlx(double , double);
	~CCPlx();
	//void Affiche();
    CCPlx(const CCPlx&);
    CCPlx operator=(const CCPlx&);
    CCPlx operator+=(const CCPlx&);
    CCPlx operator+(const CCPlx&)const;//const;
    
    CCPlx operator-=(const CCPlx&);
    CCPlx operator-(const CCPlx&)const;
    
    CCPlx operator*=(const CCPlx&);
    CCPlx operator*(const CCPlx&)const;
    
    CCPlx operator/=(const CCPlx&);
    CCPlx operator/(const CCPlx&)const;
    
	double Module();
   // CCPlx Addition (const CCPlx&);
   // CCPlx Multiplication(const CCPlx&);
  
   //CCPlx operator=(const CCPlx&);
    
    friend ostream& operator<<(ostream&,const CCPlx& C);
    friend istream& operator>>(istream&,CCPlx& C);
};
