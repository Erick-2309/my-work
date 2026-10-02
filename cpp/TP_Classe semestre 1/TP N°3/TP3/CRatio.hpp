#include <iostream>
using namespace std;

class CRatio
{
private:
    int m_num,m_num2;
    int m_den,m_den2;
public:
    CRatio(double=0.0,double=0.0);
    ~CRatio();
    CRatio(const CRatio&);
    //void Affiche();
    CRatio Oppose();
    CRatio Incremente();
    
    //CRatio operator=(const CRatio&);
    
    CRatio Somme(const CRatio&);
    CRatio operator+=(const CRatio&);
   // CRatio operator+(const CRatio&)const;
    
    CRatio Difference(const CRatio&);
    CRatio operator-=(const CRatio&);
    CRatio operator-(const CRatio&)const;
    
    CRatio ProduitRatio(const CRatio&);
    CRatio operator*=(const CRatio&);
    CRatio operator*(const CRatio&)const;
    
    CRatio ProduitScal(int x);
    int Signe();
    friend ostream& operator<<(ostream& , const CRatio& C);
    friend istream& operator>>(istream& , CRatio& C);
    
    
    CRatio operator/=(const CRatio&);
    CRatio operator/(const CRatio&)const;
};
