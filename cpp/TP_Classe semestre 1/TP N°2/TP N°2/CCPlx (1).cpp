//defini les methode de la classe
#include "CCPlx (1).h"
#include <math.h>



/*CCPlx::CCPlx()
{
	cout<< "passage dns leconstructeur sans param�tre\n";
	m_Re=0;
	m_Im=0;
}

CCPlx::CCPlx(double Re, double Im)
{
	cout << "passage dns le constructeur avec param�tre\n";
	m_Re=Re;
	m_Im=Im;
}
 */

CCPlx::CCPlx(double Re,double Im)
{
	//cout << "passage dns le constructeur avec param�tre par defaut \n";
	m_Re=Re;
	m_Im=Im;
}


CCPlx::~CCPlx()
{
	//cout << "passage dns le destructeur \n";

}

/*void CCPlx::Affiche()
{
	cout << "le point vaut:" << m_Re << "+ i" << m_Im << endl;
}*/

CCPlx::CCPlx(const CCPlx&C)
 // : m_Re(C1. m_Re),m_Im(C1.m_Im)
{
    //cout << "passage dns le constructeur copie\n";
    m_Re= C.m_Re;
    m_Im= C.m_Im;
}

double CCPlx::Module()
{
	return sqrt(m_Re * m_Re + m_Im * m_Im) ;
}


/*CCPlx CCPlx::Addition (const CCPlx& C)//(int R,int I)
{
    return CCPlx(m_Re+C.m_Re ,  m_Im+C.m_Im);
}*/
CCPlx CCPlx::operator+=(const CCPlx& C)
{
    CCPlx result;
    result.m_Re = m_Re + C.m_Re;
    result.m_Im = m_Im + C.m_Im;
    return result;
}
CCPlx CCPlx::operator+(const CCPlx& C)const
{
    return CCPlx(*this)+=C;
}



CCPlx CCPlx::operator-=(const CCPlx& C)
{
    CCPlx result;
    result.m_Re = m_Re - C.m_Re;
    result.m_Im = m_Im-C.m_Im;
    return result;
}
CCPlx CCPlx ::operator-(const CCPlx& C)const
{
  
    return CCPlx(*this)-=C;
}



/*CCPlx CCPlx::Multiplication(const CCPlx& C)
{
    //cout<<"le produit vaut: "<<(m_Re * C.m_Re-m_Im * C.m_Im)<<" +i"<<(C.m_Im*m_Re+C.m_Re*m_Im)<<endl;
    return CCPlx(m_Re * C.m_Re-m_Im * C.m_Im, C.m_Im*m_Re+C.m_Re*m_Im);
}*/

CCPlx CCPlx::operator*=(const CCPlx& C)
{
    CCPlx result;
    result.m_Re = m_Re*C.m_Re - m_Im*C.m_Im;
    result.m_Im = C.m_Im*m_Re + C.m_Re*m_Im;
    return result;
}
CCPlx CCPlx::operator*(const CCPlx& C)const
{
    return CCPlx(*this)*=C;
 
}



CCPlx CCPlx::operator/(const CCPlx& C)const
{
    return CCPlx((m_Re*C.m_Re + C.m_Im*C.m_Im)/(C.m_Re*C.m_Re + C.m_Im*C.m_Im) , (C.m_Im*m_Re - m_Re*C.m_Im)/(C.m_Re*C.m_Re + C.m_Im*C.m_Im));
}


CCPlx CCPlx::operator=(const CCPlx& C)
{   /*m_Re=C.m_Re;
    m_Im=C.m_Im;
    return (*this);*/
    return CCPlx(C.m_Re,C.m_Im);
}


ostream& operator<<(ostream& cout, const CCPlx& C)
{
    char ch;
    if(C.m_Im<0)
    {
        ch= '-';
    }
    else
    {
        ch= '+';
    }
    cout<<C.m_Re;
    cout<<ch<<"i"<<abs(C.m_Im);
    return cout;
}

istream& operator>>(istream& cin,CCPlx& C)
{
    cout<<"entrez la partie reelle: \n";
    cin>>C.m_Re;
    cout<<"entrez la partie imaginaire: \n";
    cin>>C.m_Im;
    return cin;
}
 
