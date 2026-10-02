#include "CScdDgr.hpp"

    
CScdDgr::CScdDgr(double a, double b, double c)
: m_a(a), m_b(b), m_c(c)
{
    double D = (b * b - 4 * a * c);
    if (D < 0)
    {
        m_pSol=new CSol0();
    }
    
    if (D > 0)
    {
        m_pSol= new CSol2(a,b,c,D);
    }
    
    if (D == 0)
    {
        m_pSol= new  CSol1(a,b);
        
    }     
 
}


CScdDgr::CScdDgr(const CScdDgr&Sc)
    : m_a(Sc.m_a), m_b(Sc.m_b), m_c(Sc.m_c), m_pSol(NULL)
{
    
    double D = (m_a * m_b - 4 * m_a * m_c);
    if (D < 0)
    {
        m_pSol= Sc.m_pSol;
    }
   
    else if (D > 0)
    {
        m_pSol= Sc.m_pSol;
    }
    else if (D == 0)
    {
        m_pSol= Sc.m_pSol;
    }
}
     
CScdDgr::~CScdDgr()
{
    if(m_pSol!=NULL)delete[]m_pSol;
}

void CScdDgr::aff()
{
    m_pSol->aff();
}












/*
istream&operator>>(istream&cin, CScdDgr&Sc)
{
    cout<<"eentrez les coeff:\n";
    cout<<"a: ";
    cin>>Sc.m_a;
    cout<<", b: ";
    cin>>Sc.m_b;
    cout<<", c: ";
    cin>>Sc.m_c;
return cin;
}
ostream&operator<<(ostream&cout,const CScdDgr&Sc)
{
   // CSolution* m_pSol;
    //m_pSol=new CSolution[2];
    cout<<"---solution---\n";
    cout<<"delta négatif "<<Sc.m_pSol[0];
    cout<<"delta positif "<<Sc.m_pSol[1];
    cout<<"delta null "<<Sc.m_pSol[2];
}
*/






