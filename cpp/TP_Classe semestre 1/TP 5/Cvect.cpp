#include "Cvect.h"
using namespace std;

Cvect::Cvect(int N)
 :m_N(N),m_ptab(NULL)
{
    if(m_N>0)
    {
        m_ptab=new double[N];
    }
    if(m_ptab!= NULL)
    {
      for(int i=0; i<N; i++)
        {
            m_ptab[i]=0.0;
        }
       
    }
}


Cvect::Cvect(int N,double*vect)
 :m_N(N),m_ptab(NULL)
{
    if(m_N>0)
    {
        m_ptab=new double[m_N];
        for(int i=0;i<m_N; i++)
        {
            m_ptab[i]=vect[i];
        }
    }
}

Cvect::Cvect(const Cvect& vect)
:m_N(vect.m_N),m_ptab(NULL)
{
    if(vect.m_N>0)
    {
        m_ptab=new double [vect.m_N];
    }
   if(vect.m_ptab!=NULL)
    {
        for(int i=0; i<m_N; i++)
           m_ptab[i]= vect.m_ptab[i];
    }
}
Cvect::~Cvect()
{
  //if(m_ptab!=NULL) delete[]m_ptab;
}


ostream& operator<<(ostream& cout, const Cvect& vect)
{
    cout<<"longueur du tableau "<<vect.m_N<<endl;
    for(int i=0; i<vect.m_N; i++)
    {
        cout<<" élement "<<i+1<<" :"<<vect.m_ptab[i]<<endl;
    }
    return cout;
}
istream& operator>>(istream& cin, Cvect& vect)
{
    int N;
    cout<<"entrez la longueur du tableau: \n";
    cin>>N;
    
    if(vect.m_N!=N)
    {
        delete []vect.m_ptab;
        N=vect.m_N;
    }
    if(vect.m_N>0)
    {
        if(vect.m_ptab!=NULL)
        {
            for(int i=0; i<N; i++)
            {
                cout<<"élement "<<i+1<<" :";
                cin>>vect.m_ptab[i];
            }
        }
    }
    return cin;
}

void Cvect::Random()
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<m_N; i++)
        m_ptab[i]= 10+(20-10)*(double)rand()/RAND_MAX;
}


Cvect Cvect:: operator+=(const Cvect& vect)
{
    //Cvect result(vect.m_N);
    if(vect.m_N!=m_N)
    {
        cout<<"les tailles des deux tableaux ne correspondent pas\n";
    }
    else //if(vect.m_N==m_N)
    {
        for(int i=0; i<m_N; i++)
           m_ptab[i]+=vect.m_ptab[i];
    }
    return *this;
}

Cvect Cvect::operator+(const Cvect& vect)
{
    if(vect.m_N==m_N)
    {
         Cvect(*this)+=vect;
    }
    return Cvect(*this);
}

Cvect Cvect::operator*(const Cvect& vect)
{
    Cvect tab(m_N);
    if(vect.m_N!=m_N)
    {
        cout<<"les tailles des tableaux ne corresponde pas\n";
    }
    else if(vect.m_N==m_N)
    {
        
        for(int i=0; i<m_N; i++)
        {
            tab.m_ptab[i]=vect.m_ptab[i]*m_ptab[i];
        }
    }
    return tab;
}


void Cvect::Permute (int i, int j)

{
    int memoire;
    memoire=m_ptab[i];
    m_ptab[i]=m_ptab[j];
    m_ptab[j]=memoire;
}

/*int Cvect::min()
{
    int mini=m_ptab[0];
    for(int i=0; i<m_N; i++)
    {
        if(m_ptab[i]<mini)
            mini=m_ptab[i];
    }
    return mini;
}*/

void Cvect::TriSelection()
{
    
    for(int i=0; i<=m_N; i++)
    {
        double mini=m_ptab[i];
        for(int j=i+1; j<m_N; j++)
        {
            if(m_ptab[j]<mini)
            {
                mini=m_ptab[j];
                Permute(i,j);
            }
        }
    }
}


void Cvect:: TriBulles(bool ordre )
{
    cout<<"ordre de tri: entrez 0 pour croissant et 1 pour decroissant\n";
    cin>> ordre;
    
   /* if((ordre!=1) || (ordre!=0))
    {
        cout<<"vous devez saisir 0 ou 1 !!";
    }
    cin>> ordre;*/
    if(ordre==0)
    {
        for(int i=0; i<m_N; i++)
            for(int j=0; j<m_N-1; j++)
            {
                if(m_ptab[j]>m_ptab[j+1])
                {
                    Permute(j, j+1);
                }
            }
    }
    else
    {
        for(int i=0; i<m_N; i++)
            for(int j=0; j<m_N; j++)
            {
                if(m_ptab[j]<m_ptab[j+1])
                {
                    Permute(j, j+1);
                }

            }
    }
}


void Cvect::TriInsertion()
{
    int I=0;//l'element que je dois inserer
    for(int i=1; i<m_N; i++)
    {
        I=m_ptab[i];
        int j=i-1;
        while (j>=0 && m_ptab[j]>I)
        {
            m_ptab[j+1]=m_ptab[j];
            j--;
        }
        m_ptab[j + 1] = I;
    }
}
    
    
    /*
     void Cvect::TriInsertion() {
     for (int i = 1; i < m_N; i++) {
     int key = m_ptab[i];  // L'élément à insérer
     int j = i - 1;
     
     // Décalage des éléments plus grands que 'key' à une position vers la droite
     while (j >= 0 && m_ptab[j] > key) {
     m_ptab[j + 1] = m_ptab[j];
     j--;
     }
     
     // Insertion de l'élément 'key' à sa position correcte
     m_ptab[j + 1] = key;
     }
     }
     */
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
     Cvect::Cvect(int N)
     :m_nN(N),m_ptab(NULL)
     {
     //cout<<"passage dans le contructeur avec paramètre\n";
     if(m_nN>0)
     m_ptab = new double[m_nN];
     for(int i=0;i<m_nN;i++)
     m_ptab[i]=0.0;
     }
     
     Cvect::Cvect(const Cvect &t)
     :m_nN(0),m_ptab(NULL)
     {
     if (m_nN>0)
     m_ptab = new double[m_nN];
     if(m_ptab!=NULL)
     {
     for(int i=0;i<m_nN;i++)
     m_ptab[i]=t.m_ptab[i];
     }
     }
     
     Cvect::~Cvect()
     {
     //if(m_nN>0)
     if(m_ptab!= NULL)
     delete[]m_ptab;
     //cout<<"passage dans le destructeur \n";
     }
     
     Cvect::Cvect(int N, double* pt)
     :m_nN(N),m_ptab(NULL)
     {
     if(m_nN>0)
     m_ptab= new double[m_nN];
     if(m_ptab!= NULL)
     for (int i = 0; i < m_nN; i++)
     {
     m_ptab[i]=pt[i];
     }
     }
     
     ostream &operator<<(ostream &cout , const Cvect &t)
     {
     cout<<"nombre de valeur du tableau : "<<t.m_nN<<endl;
     for(int i=0;i<t.m_nN;i++)
     cout<<"élement"<<i+1<<" : "<<t.m_ptab[i]<<endl;
     return cout;
     }
     
     istream &operator>>(istream &cin,  Cvect &t)
     {
     int N = 0;
     cout<<"entrez le nombre de valeur du tableau :";
     cin>>N;
     if(N != t.m_nN)
     {
     if(t.m_ptab!=NULL)
     delete[]t.m_ptab;
     t.m_nN = N;
     if((t.m_nN)>0)
     t.m_ptab = new double[t.m_nN];
     }
     for(int i=0;i<t.m_nN;i++)
     {
     cout<<"valeur numéro "<<i+1<<endl;
     cin >>t.m_ptab[i];
     }
     return cin ;
     }
     
     double Cvect::Prod_Scal(const Cvect &t)
     {
     double  S=0;
     for(int i=0; i<m_nN; i++)
     S+=t.m_ptab[i]*m_ptab[i];
     return S;
     }
     
     Cvect Cvect::Prod_Simpl(int A)
     {
     Cvect prod(m_nN);
     for (int i=0; i<m_nN; i++)
     {
     prod.m_ptab[i]=m_ptab[i]*A;
     }
     return prod;
     }
     
     Cvect Cvect::operator+=(const Cvect&vec)
     {
     //Cvect som(m_nN);
     if(m_nN==vec.m_nN)
     {
     for(int i=0; i<m_nN;i++)
     m_ptab[i]+=vec.m_ptab[i];   //som.m_ptab[i]=m_ptab[i]+vec.m_ptab[i];
     }//return som
     return *this;
     }
     
     Cvect Cvect::operator+(const Cvect&vec)
     {
     if(m_nN==vec.m_nN)
     {
     Cvect(*this)+=vec;
     }
     return Cvect(*this)+=vec;
     }*/
    

