#include "CMat.hpp"
#include <iostream>
using namespace std;



/*CMat::CMat()
:m_NO(0),m_vect(NULL){}

CMat::CMat(int N, CVect*mat)
:m_NO(N),m_vect(NULL)
{
    if(N>0)
    {
        m_vect=new CVect[m_NO];
        for(int i=0; i<m_NO; i++)
        {
            m_vect[i]=mat[i];
        }
    }
}

CMat::CMat(const CMat&M)
:m_NO(M.m_NO),m_vect(NULL)
{
    if(M.m_NO>0)
    {
        m_vect=new CVect[M.m_NO];
        for(int i=0; i<M.m_NO; i++)
        {
            m_vect[i]=M.m_vect[i];
        }
        
    }
}

CMat::~CMat()
{
    if(m_vect!=NULL)delete[]m_vect;
}

CMat CMat:: operator=(const CMat&M)
{
    if(this !=&M)
        if(m_vect!=NULL)
        {
            delete []m_vect;
        }
    m_NO=M.m_NO;
    if(m_NO>0)
    {
        m_vect=new CVect[m_NO];
        for(int i=0; i<m_NO; i++)
        {
            m_vect[i]=M.m_vect[i];
        }
    }
    return *this;
}

CMat CMat:: operator+(const CMat&M)
{
    CMat result;
    if(m_NO==M.m_NO)
    {
        if(m_NO>0)
        {
            m_vect=new CVect[M.m_NO];
            for(int i=0; i<M.m_NO; i++)
            {
                result.m_vect[i]=m_vect[i]+M.m_vect[i];
            }
        }
        
    }
    else
    {
        cout<<"les tailles ne correspondent pas";
    }
    return result;
}

CVect CMat:: operator[](int a)
{
 if(a>0 && i<m_NO)
    {
        return m_vect[a];
    }
 else
 return CVect()
}


ostream & operator<<(ostream& cout, const CMat& M)
{
    cout<<"taille de la matrice:"<<M.m_NO<<endl;
    cout<<"la matrice est la suivante:\n";
    for(int i=0; i<M.m_NO; i++)
    {
        cout<<"ligne" <<i+1<<": "<<M.m_vect[i]<<endl;
    }
    return cout;
    
}

istream& operator>>(istream& cin, CMat& M)
{
    int N=0;
    cout<<"la taille de votre matrice :\n";
    cin>>N;
    
    if(M.m_NO!=N)
    {
        if(M.m_vect!=NULL)delete[]M.m_vect;
        M.m_NO=N;
    }
     if(M.m_NO>0)
     {
         M.m_vect=new CVect[M.m_NO];
         for(int i=0; i<M.m_NO; i++)
         {
             cout<<"ligne "<<i+1<<", ";
             cin>>M.m_vect[i];
         }
     }
    return cin;
}
*/





#include <iostream>

CMatr::CMatr(int N)
:m_NO(0),m_ratio(NULL)
{
    cout<<"taille de la matrice a construire:";
    cin>>N;
    m_NO=N;
    //m_ratio=new CRatio[m_NO];
}

CMatr::CMatr(int N, CRatio*ratio)
:m_NO(N),m_ratio(NULL)
{
    if(N>0)
    {
        m_ratio=new CRatio[m_NO];
        for(int i=0; i<m_NO; i++)
        {
            m_ratio[i]=ratio[i];
        }
    }
}

CMatr::CMatr(const CMatr&M)
:m_NO(M.m_NO),m_ratio(NULL)
{
    if(M.m_NO>0)
    {
        m_ratio=new CRatio[M.m_NO];
        for(int i=0; i<M.m_NO; i++)
        {
            m_ratio[i]=M.m_ratio[i];
        }
     }
    else
            {
                m_ratio = nullptr;
            }
}

CMatr::~CMatr()
{
    if(m_ratio!=NULL)delete[]m_ratio;
}

CMatr CMatr:: operator=(const CMatr&M)
{
    if(this !=&M)
        if(m_ratio!=NULL)
        {
            delete []m_ratio;
        }
    m_NO=M.m_NO;
    if(m_NO>0)
    {
        m_ratio=new CRatio[M.m_NO];
        for(int i=0; i<M.m_NO; i++)
        {
            m_ratio[i]=M.m_ratio[i];
        }
     }
    else
            {
                m_ratio = nullptr;
            }
    return *this;
}

CMatr CMatr:: operator+(const CMatr&M)
{
    CMatr result(M.m_NO);
    if(m_NO==M.m_NO)
    {
        if(m_NO>0)
        {
            m_ratio=new CRatio[M.m_NO];
            for(int i=0; i<M.m_NO; i++)
            {
                result.m_ratio[i]=m_ratio[i]+M.m_ratio[i];
            }
        }
        
    }
    else
    {
        cout<<"les tailles ne correspondent pas";
    }
    return result;
}

CRatio CMatr:: operator[](int a)
{
   // if (a >= 0 && a < m_NO)
        
    return m_ratio[a];
    
}


ostream & operator<<(ostream& cout, const CMatr& M)
{
    cout<<"taille de la matrice:"<<M.m_NO<<endl;
    cout<<"la matrice est la suivante:\n";
    for(int i=0; i<M.m_NO; i++)
    {
        cout<<"ligne" <<i+1<<": "<<M.m_ratio[i]<<endl;
    }
    return cout;
    
}

istream& operator>>(istream& cin, CMatr& M)
{
    int N=0;
    cout<<"la taille de votre matrice :\n";
    cin>>N;
    
    if(M.m_NO!=N)
    {
        if(M.m_ratio!=NULL)delete[]M.m_ratio;
    }
     N=M.m_NO;
     if(M.m_NO>0)
     {
         M.m_ratio=new CRatio[M.m_NO];
         for(int i=0; i<M.m_NO; i++)
         {
             cout<<"ligne "<<i+1<<", ";
             cin >> M.m_ratio[i];
         }
     }
    return cin;
}
