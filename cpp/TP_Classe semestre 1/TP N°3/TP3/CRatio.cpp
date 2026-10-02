#include "CRatio.hpp"
using namespace std;



CRatio::CRatio(double num,double den)
 : m_num(num),m_den(den)
{
    //cout<<"passage dans le constructeur avec parametre par defaut\n";
   //m_num=num;
   //m_den=den;
}

CRatio::~CRatio()
{
    //cout<<"passage dans le destructeur\n";
}

CRatio::CRatio(const CRatio& C)
{
    //cout<<"passage dans le constructeur copie\n";
    m_num=C.m_num;
    m_num=C.m_den;
}
 
/*
void CRatio:: Affiche()
{
    cout<<"la ratio vaut: "<<m_num<<"/"<<m_den<<endl;
}
*/

CRatio CRatio::Oppose()
{
    //cout<<"l'opposé vaut: "<<m_den<<"/"<<m_num<<endl;
    return  CRatio(m_den , m_num) ;
}
 

int CRatio::Signe()
{
    if((m_num<0 && m_den<0) || (m_num>0 && m_den>0))
    {
        cout<<"positif on obtien donc: ";
        //cout<<1<<endl;//"positif"<<endl;
        return 1;
    }
    else if ((m_num<0 && m_den>0) || (m_num>0 && m_den<0))
    {
        cout<<"negatif on botien donc: ";
        //cout<<-1<<endl;//"negatif"<<endl;;
        return -1;
    }
    else
        cout <<"nulle";
             return 0;
}

CRatio CRatio::Incremente()
{
    //cout<<"le ratio incrementé de 1 vaut: "<<(m_num+m_den)<<"/"<<m_den<<endl;
    return CRatio(m_num+m_den , m_den);
}


/*CRatio CRatio::operator+=(const CRatio& C)
{
    m_num+=C.m_num;
    m_den+=C.m_den;
    return CRatio(*this);
}

CRatio CRatio::operator+(const CRatio& C)const
{
    return CRatio(*this)+=C;
}*/
CRatio CRatio::Somme(const CRatio& C)
{
    int pgcd =2;
    int d=pgcd;
    int N=0;
    int rest =0;
    int i=2;
    //int pgcd =2;
    rest=m_num%m_den;
    for(i=2;i<=N;i++)
        //while (i<N)
    {
        if (rest==0)
        {
            return pgcd=m_den;
        }
        else
            //rest= m_num;
            m_num=m_den;
            m_den=rest;
        //i++;
     }
    return CRatio((m_num*C.m_den + m_den*C.m_num)/d , (m_den*C.m_den)/d);
}



/*CRatio CRatio::operator-=(const CRatio& C)
{
    m_num-=C.m_num;
    m_den-=C.m_den;
    return CRatio(*this);
}

CRatio CRatio::operator-(const CRatio& C)const
{
    return CRatio(*this)-=C;
}*/
CRatio CRatio::Difference(const CRatio& C)
{
    //cout<<"la difference vaut "<<(m_num*C.m_den - m_den*C.m_num)<<"/"<<m_den*C.m_den<<endl;
    return CRatio(m_num*C.m_den - m_den*C.m_num , m_den*C.m_den);
}



/*CRatio CRatio::operator*=(const CRatio& C)
{
    m_num*=C.m_num;
    m_den*=C.m_den;
    return CRatio(*this);
}

CRatio CRatio::operator*(const CRatio& C)const
{
    return CRatio(*this)*=C;
}*/
CRatio CRatio::ProduitRatio(const CRatio& C)
{
    //cout<<"le produit vaut: "<<m_num*C.m_num<<"/"<<m_den*C.m_den<<endl;
    return CRatio(m_num*C.m_num , m_den*C.m_den);
}



CRatio CRatio::ProduitScal(int X)
{
    X=1;
    int pgcd =2;
    int d=pgcd;
    int N=0;
    int rest =0;
    int i=2;
    int num=m_num*X;
    rest=num%m_den;
    CRatio(num,m_den);
    for(i=2;i<=N;i++)
        //while (i<N)
    {
        if (rest==0)
        {
            return pgcd=m_den;
        }
        else
            //rest= m_num;
            num=m_den;
            m_den=rest;
        i++;
     }
    //cout<<"le ProduitScal: "<<m_num*x<<"/"<< m_den <<endl;
    return CRatio(num/d , (m_den)/d);
}


ostream& operator<<(ostream& cout,const CRatio& C)
{
    cout<<C.m_num<<"/"<<C.m_den<<endl;
    // cout<<"/"<<C.m_den<<endl;
    return cout;
}


istream& operator>>(istream& in,CRatio& C)
{
    cout<<"entrer le numerateur: \n";
    in>>C.m_num;
    cout<<"entrer le denominateur: \n";
    in>>C.m_den;
    return in;
}
