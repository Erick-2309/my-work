#include<iostream>
using namespace std;
#include "CTab2D.hpp"




void CTab2D::Alloc(int l,int c)
{
    m_nL=l;
    m_nC=c;
    m_pTab=NULL;
    if((l>0) && (c>0))
    {
        m_pTab=new double*[m_nL];
        for(int i=0; i<m_nL; i++)
            {
                //if(m_pTab[i]!=NULL)
                m_pTab[i]=new double[m_nC];
            }
    }
}


void CTab2D:: Free()
{
    m_pTab=NULL;
    if(m_pTab!=NULL)
    {
        for(int i=0; i<m_nL; i++)
        {
            //if(m_pTab[i]!=NULL)
            delete[]m_pTab[i];
        }
        delete []m_pTab;
       // m_pTab = nullptr;
    }
}


void CTab2D::Init(int l, int c, double val)
{
    m_nL=l;
    m_nC=c;
    m_pTab=NULL;
    Alloc(l,c);
    if((l>0) && (c>0))
    {
        if(m_pTab!=NULL)
        {
            for (int i=0; i<l;i++)
            {
                  if(m_pTab[i]!=NULL)
                  {
                    for (int j=0; j<c; j++)
                         m_pTab[i][j]=val;
                  }
            }
        }
    }
}


CTab2D::CTab2D (int l, int c, double val)
:m_nL(l),m_nC(c),m_pTab(NULL)
{
    Init(m_nL, m_nC, val);
}


CTab2D::~CTab2D()
{
    Free();
    //if(m_pTab!=NULL) delete[]m_pTab;
}


CTab2D::CTab2D (const CTab2D& T)
:m_nL(T.m_nL),m_nC(T.m_nC),m_pTab(NULL)
{
    Alloc(T.m_nL, T.m_nC);
    if(T.m_nL>0 && T.m_nC>0)
    {
        if(m_pTab!=NULL)
            {
                for(int i=0; i<m_nL; i++)
                    {
                        if(m_pTab[i]!=NULL)
                        {
                            for(int j=0; j<m_nC; j++)
                                m_pTab[i][j]=T.m_pTab[i][j];
                        }
                    }
            }
    }
}


CTab2D CTab2D :: FillRand()
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<m_nL; i++)
    {
        for(int j=0; j<m_nC; j++)
        {
            m_pTab[i][j] = 0 +(1+0)*(double)rand()/RAND_MAX;
        }
    }
    return *this;
}


ostream& operator <<(ostream &cout ,const CTab2D & T)
{
    cout<<"Matrice "<<T.m_nL<<" ligne, "<<T.m_nC<<" colones\n";
    for(int i=0; i<T.m_nL; i++)
    {
        for(int j=0; j<T.m_nC; j++)
            {
                 cout<<T.m_pTab[i][j]<<"|";
            }
        cout<<endl;
    }
    return cout;
}


istream& operator>>(istream &cin, CTab2D& T)
{
    int L=0,C=0;
    do
    {
        cout<<"entrez le ,nombre de ligne: ";
        cin>>L;
        cout<<"entrez le nombre de colone: ";
        cin>>C;
    }
    while (L<=0 || C<=0);
    
    if(L!=T.m_nL || C!=T.m_nC)
    {
        T.Free();
        T.m_nL=L;
        T.m_nC=C;
        T.Alloc(T.m_nL, T.m_nC);
    }
    for(int i=0; i<T.m_nL; i++)
    {
        for(int j=0; j<T.m_nC; j++)
        {
            cout<<"case ("<<i+1<<","<<j+1<<") :";
            cin>>T.m_pTab[i][j];
        }
    }
    return cin;
}


CTab2D CTab2D::operator=(double** matrice)
{
        for(int i=0; i<m_nL; i++)
        {
            if(m_pTab[i]!=NULL)
                for(int j=0; j<m_nC; j++)
                    m_pTab[i][j]=matrice[i][j];
        }
    return *this;
   
}


CTab2D CTab2D::operator=(const CTab2D& T)
{
    if(m_nL==T.m_nL && m_nC==T.m_nC)
    {
        for(int i=0; i<T.m_nL; i++)
        {
            for(int j=0; j<T.m_nC; j++)
                m_pTab[i][j]=T.m_pTab[i][j];
        }
    }
    else
    {
        cout<<"les tailles ne correspondent pas!! \n";
    }
    return *this;
}


double CTab2D::cellule(int i, int j)
{
    double valeur=0;
    valeur=m_pTab[i][j];
    return valeur;
}


void CTab2D::set (int i, int j, double v)
{
    v=0;
    cout<<"entrez une  valeur pour la case: ("<<i<<","<<j<<") :";
    cin>>v;
    m_pTab[i][j]=v;
   
}


CTab2D  CTab2D:: operator()(int i, int j)
{
   // int k=i+j;
    return  0;// m_pTab[k];
}


CTab2D CTab2D:: operator+(const CTab2D&T)
{
    CTab2D Tab(m_nL,m_nC);
    if(m_nL==T.m_nL && m_nC==T.m_nC)
    {
        for(int i=0; i<m_nL; i++)
        {
            for(int j=0; j<m_nC; j++)
            {
                Tab.m_pTab[i][j]=m_pTab[i][j]+T.m_pTab[i][j];
            }
        }
    }
    else
    {
        cout<<"les tailles ne correspondent pas!! \n";
    }
    
    return Tab;
}


CTab2D CTab2D:: operator+=(const CTab2D&T)
{
    *this=*this + T;
    return *this;
}


CTab2D CTab2D:: operator+=(double val)
{
    for(int i=0; i<m_nL; i++)
        {
            for(int j=0; j<m_nC; j++)
            {
               m_pTab[i][j]=m_pTab[i][j]+val;
            }
        }
    return *this;
}


CTab2D CTab2D::operator*(double val)
{
   // CTab2D Tab(m_nL,m_nC); 
    for(int i=0; i<m_nL; i++)
    {
        for(int j=0; j<m_nC; j++)
        {
            m_pTab[i][j]=m_pTab[i][j]*val;
        }
    }
    return *this;
}


CTab2D operator*(double val, const CTab2D& T)
{
    for(int i=0; i<T.m_nL; i++)
    {
        for(int j=0; j<T.m_nC; j++)
        {
            T.m_pTab[i][j]=val*T.m_pTab[i][j];
        }
    }
    return CTab2D(T.m_nL, T.m_nC);
}


CTab2D CTab2D::operator*(const CTab2D&T)
{
    if(m_nC==T.m_nL) //il faur que le nombre de collonne de la matrice 1 coincide avec le nombre de ligne de la matrice 2
    {
        CTab2D Tab(m_nL, T.m_nC);
        for(int i=0; i<m_nL;i++)
        {
            for(int j=0; j<T.m_nC; j++)
            {
                Tab.m_pTab[i][j]=0;
                int k=i+1;
                for(k=0; k<T.m_nC; k++)
                {
                    Tab.m_pTab[i][j]=((m_pTab[i][j]*T.m_pTab[i][j])+(m_pTab[i][k]*T.m_pTab[k][j]));
                }
            }
        }
        return Tab;
    }
    else
    {
        cout<<"les taolles ne correspondent pas!! \n";
    }
    return CTab2D();
}


CTab2D CTab2D::Diagonale()
{
    CTab2D Tab(m_nL,m_nC);
    for(int i=0; i<m_nL; i++)
    {
        for(int j=0; j<m_nC; j++)
        {
            if(i==j)
            {
                Tab.m_pTab[i][j]=m_pTab[i][j];
            }
            else
            {
                Tab.m_pTab[i][j]=0;
            }
        }
    }
    return Tab;
}


CTab2D CTab2D:: T_sup()
{
    CTab2D Tab(m_nL,m_nC);
    for(int i=0; i<m_nL;i++)
    {
        for(int j=0; j<m_nC; j++)
        {
            if(i<=j) Tab.m_pTab[i][j]=m_pTab[i][j];
            else Tab.m_pTab[i][j]=0;
        }
    }
    return Tab;
}


CTab2D CTab2D::T_inf()
{
    CTab2D Tab(m_nL,m_nC);
    for(int i=0; i<m_nL;i++)
    {
        for(int j=0; j<m_nC; j++)
        {
            if(i>=j) Tab.m_pTab[i][j]=m_pTab[i][j];
            else Tab.m_pTab[i][j]=0;
        }
    }
    return Tab;
}
