#include<iostream>
#include "CVect.hpp"
using namespace std;


CVect::CVect()
:m_N(0),m_ptab(NULL)
{}



CVect::CVect(int N, double* tab)
:m_N(N),m_ptab(NULL)
{
    if(m_N>0)
    {
        m_ptab= new double[m_N];
        for(int i=0; i<m_N; i++)
        {
            m_ptab[i]=tab[i];
        }
    }
}

CVect::CVect(const CVect&V)
:m_N(V.m_N),m_ptab(NULL)
{
    if(V.m_N>0)
    {
        m_ptab= new double[V.m_N];
        if(m_ptab!=NULL)
        {
            for(int i=0; i<V.m_N; i++)
            {
                m_ptab[i]=V.m_ptab[i];
            }
        }
    }
}


CVect::~CVect()
{
    if(m_ptab!= NULL) delete[]m_ptab;
}


CVect CVect:: operator=(const CVect&V)
{
    if(this!=&V)
    if (m_ptab != NULL)
    {
        delete[]m_ptab;  // Liberation de mémoire
        m_N = V.m_N;
    }
       
    if(V.m_N>0)
    {
        m_ptab= new double[V.m_N];
        for(int i=0; i<V.m_N; i++)
        m_ptab[i]=V.m_ptab[i];
        
    }
    else
    {
       m_ptab = NULL;
    }
    return *this;
}

CVect CVect:: operator+(const CVect&V)
{
    CVect result(V.m_N,NULL);
    if(V.m_N>0)
    {
        result.m_ptab= new double[V.m_N];
        for(int i=0; i<V.m_N; i++)
        {
            result.m_ptab[i]=m_ptab[i]+V.m_ptab[i];
        }
    }
    return result;
}

double CVect::operator[](int a)
{
    return m_ptab[a];
}

ostream& operator<<(ostream& cout, const CVect&V)
{
   // cout<<"taille du tableau :"<<V.m_N<<endl;
   // cout<<"le tableau est le suivant:\n";
    for(int i=0; i<V.m_N; i++)
    {
        cout<<V.m_ptab[i]<<" ";  /*"élement" <<i+1<<": "<<*/
    }
    return cout;
}

istream& operator>>(istream& cin, CVect& V)
{
     int N=0;
    cout<<"nombre d'element:";
    cin>>N;
    
    if(V.m_N!=N)
    {
        if(V.m_ptab!=NULL)delete[]V.m_ptab;
        V.m_N=N;
    }
     if(V.m_N>0)
     {
         V.m_ptab=new double[V.m_N];
     
         for(int i=0; i<V.m_N; i++)
         {
             cout<<"entrez l'élement "<<i+1<<": ";
             cin>>V.m_ptab[i];
         }
     }
    return cin;
}

