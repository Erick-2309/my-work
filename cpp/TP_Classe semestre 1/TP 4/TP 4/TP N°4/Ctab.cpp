#include "Ctab.hpp"
using namespace std;
#include <random>
#include<math.h>

Cptab::Cptab()
  :m_ptab(NULL),m_N(0)
 {
    //m_ptab(NULL);
    // m_N=0;
    //cout<<"passage dans le constructeur sans paramètre :\n";
 }

Cptab::Cptab(int N)
  //:m_ptab(NULL),m_N(N)
{
    m_ptab=NULL;
    m_N=N;
    if(m_N>0)
        m_ptab=new double [N];
    if ( m_ptab!=NULL)
    {
        for(int i=0;i<m_N;i++)
            m_ptab[i]=4.0;
    }
    
}

Cptab::Cptab(int N , double* pt)
  :m_N(N)//,m_ptab(NULL)
{
    if (m_N>0)
        m_ptab = new double[m_N];
    if(m_ptab!=NULL)
    {
        for (int i=0;i<m_N;i++)
        m_ptab[i]=pt[i];
    }
}

Cptab::Cptab(const Cptab &t)
  :m_N(t.m_N),m_ptab(NULL)
{
    if (m_N>0)
        m_ptab=new double[m_N];
    if(m_ptab!=NULL)
    {
        for(int i=0;i<m_N;i++)
            m_ptab[i]=t.m_ptab[i];
    }
}

Cptab::~Cptab()
{
    if( m_ptab!=NULL)
        delete []m_ptab;
  //  cout<<"passage dans le destructeur \n";
}

ostream &operator<<(ostream &cout,const Cptab &t)
{
    cout<<"nombre d'élement :"<<t.m_N<<endl;
    for (int i=0;i<t.m_N;i++)
    {
        cout<<"élement "<<i+1<<": "<<t.m_ptab[i]<<endl;
    }
    return cout;
}

istream &operator>>(istream &cin,Cptab &t)
{
    int N=0;
    cout<<"entrez le nombre d'élement :";
    cin>>N;
    if(N!=t.m_N)
    { if(t.m_ptab!=NULL)
        delete[]t.m_ptab;
        t.m_N=N;
        if(t.m_N>0)
            t.m_ptab = new double[t.m_N];
    }
    for (int i=0;i<t.m_N;i++)
    {
        cout<<"entrez la valeur numéro "<<i+1<<endl;
        cin>>t.m_ptab[i];
    }
    return cin;
}

void Cptab::Random(int a , int b)
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<m_N; i++)
    {
        m_ptab[i]=a+(b-a)*(double)rand()/RAND_MAX;
    }
    
}


double Cptab::Moyenne()
{
    int N=m_N;
    double S=0.0;
    for(int i=0;i<N;i++)
    {
        S+=m_ptab[i];
    }
    
    //cout<<"la moyenne vaut :"<<S/(N)<<endl;
    return S/(N);
}


double Cptab::Ect()
{
    double E=0;
    double Moy = Moyenne();
    for(int i=0;i<m_N;i++)
    {
        E+=(m_ptab[i]-Moy)*(m_ptab[i]-Moy);
    }
    return sqrt(E/m_N);
}

double Cptab::Max()
{
   
    double maxi= m_ptab[0];
    for(int i=0;i<m_N;i++)
    {
        if(m_ptab[i]>maxi)
        {
        maxi = m_ptab[i];
        }
    }
    //cout<<"la max vaut: "<<maxi<<endl;
    return maxi;
}

double Cptab::Min()
{
    double mini=m_ptab[0];
    for(int i=0;i<m_N;i++)
    {
        if(m_ptab[i]<mini)
        {
        mini = m_ptab[i];
        }
    }
   // cout<<"la min vaut: "<<mini<<endl;
    return mini;
}



void Cptab::Swap (int i, int j)
{
    double  t;
    t=m_ptab[i];
    m_ptab[i]=m_ptab[j];
    m_ptab[j]=t;
    
}
    

void Cptab::Tri(bool ordre)
{
    if(ordre==0)
    {
        for(int j=0;j<m_N;j++)
            for(int i=0;i<m_N-1;i++)
                if(m_ptab[i]<m_ptab[i+1])
                {
                    Swap(i,i+1);
                }
    }
    else if(ordre == 1)
    {
        for(int j=0;j<m_N;j++)
            for(int i=0;i<m_N-1;i++)
                if(m_ptab[i]>m_ptab[i+1])
                {
                    Swap(i,i+1);
                }
                    
     }
}
        
    
    
    
   

