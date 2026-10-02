#include "CSignal.hpp"
#include <stdlib.h>

/*CSignal::CSignal()
 :m_N(0),m_ptab(NULL)
{
    cout<<"passage dans le constructeur sans paramètre \n";
}
*/
CSignal::CSignal(int N)
  :m_N(N),m_ptab(NULL)
{
    if(m_N>0)
    {
        m_ptab=new double[m_N];
        if(m_ptab!=NULL)
            for(int i =0; i<m_N; i++)
                m_ptab[i]=N;
    }
}


CSignal::CSignal(int N,double* tab)
   :m_N(N),m_ptab(NULL)
{
    if(m_N>0)
        m_ptab=new double[m_N];
    if(m_ptab!=NULL)
    {  for(int i =0; i<m_N; i++)
        m_ptab[i]=tab[i];
    }
}

CSignal::CSignal(const CSignal&t)
  :m_N(t.m_N),m_ptab(NULL)
{
    if(m_N>0)
        m_ptab=new double[m_N];
    if(m_ptab!=NULL)
    for (int i=0; i<m_N; i++)
        m_ptab[i]=t.m_ptab[i];
}


void CSignal::FillRand()
{
    for (int i=0; i<m_N; i++)
    {
        m_ptab[i]=(double)rand()/RAND_MAX;
    }
    //return (double)rand()/RAND_MAX;
}


ostream&operator <<(ostream& cout, const CSignal&t)
{
    cout<<" nombre d'élement : "<<t.m_N<<endl;
    if(t.m_N>0)
        for(int i=0; i<t.m_N; i++)
        {
            cout<<"élement "<<i+1<<" : "<<t.m_ptab[i]<<endl;
        }
    return cout;
}

istream&operator>>(istream& cin,CSignal&t)
{
    int N;
    cout<<"entrez le nombre d'élement : ";
    cin>>N;
    if(N!=t.m_N)
     if(t.m_ptab!=NULL)
        delete []t.m_ptab;
     t.m_N=N;
    if(t.m_N>0)
    {
        t.m_ptab = new double [t.m_N];
    }
    for(int i=0; i<t.m_N; i++)
    {
        cout<<"valeur : "<<i+1<<endl;
        cin>>t.m_ptab[i];
    }
return cin;
    
}

CSignal CSignal::operator=(const CSignal& tab)
{
    if(this!=&tab)
    {
        if(m_N!=tab.m_N)
            if(m_ptab!=NULL) delete []m_ptab;
        m_N=tab.m_N;
        if(tab.m_N>0)
          m_ptab = new double[tab.m_N];
        for(int i=0; i<tab.m_N; i++)
            m_ptab[i]=tab.m_ptab[i];
        
    }
    return *this;
}

double CSignal::operator[](int i)
{
    return m_ptab[i];
}
 

void CSignal::multiplie(const CSignal& tab, double A)
{
    if(tab.m_N>0)
    {
        if(tab.m_ptab!=NULL)
           for(int i=0; i<m_N;i++)
            tab.m_ptab[i]*=A;
    }
}


CSignal CSignal::operator+=(const CSignal& S)
{
    CSignal T(m_N);
    if(m_N>0)
    {
        for(int i=0; i<m_N; i++)
         T.m_ptab[i] = m_ptab[i] + S.m_ptab[i];
    }
    return T;
}

CSignal CSignal::operator+(const CSignal& tab)
{
    return CSignal(*this)+=tab;
    
    //*this=*this+tab;
    // return *this;
    
    /* CSignal tableau(m_N);
     if (m_N>0)
     {
     for(int i=0; i<m_N; i++)
     tableau.m_ptab[i]=m_ptab[i]+tab.m_ptab[i];
     }
     return tableau;*/
}


CSignal CSignal:: operator+=(double A)
{
    //return CSignal(*this)+=A;
    //*this=*this+A;
   //return *this;
    
    CSignal tableau(m_N);
    if(m_N<0)
    {
        for(int i=0; i<m_N; i++)
           tableau.m_ptab[i]=m_ptab[i]+A;
    }
    return tableau;
}

double CSignal::operator*(const CSignal& tab)
{
    double somme=0;
    if(m_N>0)
    {
        for(int i=0; i<m_N; i++)
           somme+=m_ptab[i]*tab.m_ptab[i];
    }
    return somme;
}


CSignal CSignal::operator*(double A)
{
    CSignal S(m_N);
    if(m_N>0)
    {
        for(int i=0; i<m_N; i++)
            S.m_ptab[i]=m_ptab[i]*A;
    }
    return S;
}


CSignal operator*(double B,  const CSignal& tab)
{
    CSignal S(tab.m_N);
    if(tab.m_N>0)
    {
        for(int i=0; i<tab.m_N; i++)
          S.m_ptab[i]=B*tab.m_ptab[i];
    }
    return S;
}


double  CSignal::Moyenne()
{
    int N=m_N;
    double S=0.0;
    if(m_N>0)
    {
        for(int i=0; i<N; i++)
            S+=m_ptab[i];
    }
    return S/N;
}


double CSignal::Variance()
{
    int N=m_N;
    double V=0;
    double moy=Moyenne();
    if(m_N>0)
    {
        for(int i=0; i<N; i++)
            V+=(m_ptab[i]-moy)*(m_ptab[i]-moy);
    }
    return V/N;
    
}

double CSignal::Min()
{
    double mini=m_ptab[0];
    if(m_N>0)
    {
        for(int i=0; i<m_N; i++)
            if(m_ptab[i]<mini)
                mini=m_ptab[i];
    }
    return mini;
}

double CSignal::Max()
{
    double maxi=m_ptab[0];
    if(m_N>0)
    {
        for(int i=0; i<m_N; i++)
            if(m_ptab[i]>maxi)
                maxi=m_ptab[i];
    }
    return maxi;
}

void CSignal::Tri()
{
    double t=0.0;
    if(m_N>0)
    {
        for(int i=0; i<m_N; i++)
            for(int j=0; j<m_N-1; j++)
                if(m_ptab[i]>m_ptab[i+1])
                {
                    t=m_ptab[i];
                    m_ptab[i]=m_ptab[i+1];
                    m_ptab[i+1]=t;
                }
    }

}


