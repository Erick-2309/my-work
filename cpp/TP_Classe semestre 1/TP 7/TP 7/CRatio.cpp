#include "CRatio.hpp"
#include <iostream>
using namespace std;
/*
 CRatio::CRatio(double N, double  D)
 :m_num(N),m_den(D)
 {
 //passage dans le constructeur avec paramètre par defaut;
 }

CRatio::~CRatio()
{
   // cout<<"passage dans le destructeur \n";
}

 
 CRatio CRatio:: operator - ()
{
     CRatio RA (m_den,m_den);
     if (m_num>0 && m_den>0)
     {
         RA.m_num = -1*m_num;      //m_num=R.m_den
         RA.m_den = m_den;     //m_den=R.m_num
     }
     else if (m_num<0 && m_den<0)
     {
         RA.m_num =  m_num;      //m_num=R.m_den
         RA.m_den = -1* m_den;
     }
     else if(m_num<0)
     {
         RA.m_num = -1* m_num;      //m_num=R.m_den
         RA.m_den = m_den;
     }
     else if (m_den<0)
         RA.m_num =  m_num;      //m_num=R.m_den
         RA.m_den = -1* m_den;
 return RA;        // *this
 }
 


 int CRatio::operator & ()
 {
 //int signe=R.m_num*R.m_den;
 
 if((m_num<0 && m_den<0) || (m_num>0 && m_den>0)) //signe>0;
 {
 return 1;
 }
 else if((m_num<0 && m_den>0) || (m_num>0 && m_den<0))  //signe<0;
 {
 return -1;
 }
 else
 {
 return 0;
 }
 
 }
 
 CRatio CRatio::operator ++ ()
 {
 return CRatio(m_num+m_den, m_den);
 }
 
 
 CRatio CRatio:: operator=(const CRatio&R)
 {
     CRatio RA(m_num,m_den);
     RA.m_num = R.m_num;
     RA.m_den = R.m_den;
     return RA;
 }
 
//CRatio CRatio:: operator=(const CRatio&R)
//{
 //   if(this!= &R)
  //      m_num = R.m_num;
  //      m_den = R.m_den;
 //   return *this;
//}
 CRatio CRatio::operator+(const CRatio&R)
 {
 CRatio RA(m_num,m_den);
 RA.m_num = m_num*R.m_den + R.m_num*m_den;
 RA.m_den = m_den*R.m_den;
 return RA;
 //ou directement: return CRatio(m_num*R.m_den + R.m_num*m_den, m_den*R.m_den)
 }
 
 
 CRatio CRatio:: operator - (const CRatio&R)
 {
 return CRatio(m_num*R.m_den - R.m_num*m_den, m_den*R.m_den);
 }
 
 
 CRatio CRatio::operator * (const CRatio&R)
 {
 return CRatio(m_num*R.m_num, m_den*R.m_den);
 }
 
 
 CRatio CRatio::operator * (int A)
 {
     CRatio RA(m_num,m_den);
     RA.m_num = A*m_num;
     RA.m_den = m_den;
     return RA;
 //return CRatio(m_num*A, m_den);
 }
 
 
  CRatio operator * (int A, const CRatio& R)
 {
     CRatio RA;//(m_num,m_den);
     RA.m_num = A*R.m_num;
     RA.m_den = R.m_den;
     return RA;
     
// return CRatio(A*R.m_num, R.m_den);
 }
 
 ostream& operator << (ostream& cout, const CRatio& R)
 {
 cout<<"la ratio vaut : "<<R.m_num<<"/"<<R.m_den<<endl;
 return cout;
 }
 
 istream& operator >> (istream& cin, CRatio& R)
 {
    cout<<"entrez le numerateur \n";
    cin>>R.m_num;
    cout<<"entrez le denominateur \n";
    cin>>R.m_den;
 return cin;
 }
 */






CRatio::CRatio(double  N, double D)
  : m_num(NULL),m_den(NULL)
{
   // if(N>0 && D>0)
    //if(m_num!=NULL)
   // if(m_den!=NULL)
    m_num = new double (N);
    m_den = new double (D);
//passage dans le constructeur avec paramètre par defaut;
}
//CRatio::CRatio()
//{//cout<<"passage dans le constructeur sans paramètre\n";}

CRatio::~CRatio()
{
    //if(m_num != NULL) delete m_num;
    if(m_den != NULL) delete m_den;
    //cout<<"passage dans le destructeur\n";
}


CRatio CRatio:: operator-()
{
   // if(m_num!=NULL)
   // if(m_den!=NULL)
    CRatio RA(*m_num,*m_den);
    if ((*m_num>0 && *m_den>0)|| (*m_num<0))
    {
        *RA.m_num = -1*(*m_num);
        *RA.m_den = *m_den;
    }
    else if( (*m_num<0 && *m_den<0) || (*m_den<0))
    {
        *RA.m_num =  *m_num;
        *RA.m_den = -1* *m_den;
    }
   
    //*RA.m_num = -1*(*m_num);
    //*RA.m_den = *m_den;
    return RA;
        
}


int CRatio::operator&()
{
    //int N=1;
    //double* Ratio;
   // m_num = new double(N) ;
   // m_den = new double(N) ;
    //Ratio=(m_num,m_den);
    //Ratio= new double (N);
   
double signe = (*m_num)*(*m_den);

if(signe>0) //if(((*m_num)<0.0 && (*m_den)<0.0) || ((*m_num)>0.0 &&(*m_den)>0.0))
{
  return 1;
}
else if(signe<0) //((m_num<0.0 && m_den>0.0) || (m_num>0.0 && m_den<0.0))  //;

  return -1;

else
{
   return 0;
}

}


CRatio CRatio::operator ++()
{
    CRatio RA;
    if((m_num!=NULL) && (m_den!=NULL))
    
    *RA.m_num=(*m_num)+(*m_den);
    *RA.m_den=(*m_den);
    
    return RA;
}


CRatio CRatio:: operator=(const CRatio&R)
{
    CRatio RA;
    if((m_num!=NULL) && (m_den!=NULL))
    *RA.m_num = (*R.m_num);
    *RA.m_den = (*R.m_den);
return RA;
}


CRatio CRatio::operator+(const CRatio&R)
{
    CRatio RA;//(m_num,m_den);
    if((m_num!=NULL) && (m_den!=NULL))
    *RA.m_num = (*m_num)*(*R.m_den) + (*R.m_num)*(*m_den);
*RA.m_den = (*m_den)*(*R.m_den);

return RA;
//ou directement: return CRatio(m_num*R.m_den + R.m_num*m_den, m_den*R.m_den)
}


CRatio CRatio :: operator -= (const CRatio&R)
{
    
    CRatio RA;//(m_num,m_den);
    if((m_num!=NULL) && (m_den!=NULL))
    *RA.m_num = (*m_num)*(*R.m_den) - (*R.m_num)*(*m_den);
    *RA.m_den = (*m_den)*(*R.m_den);
    
    return RA;
}

CRatio CRatio::operator - (const CRatio&R)
{
    return CRatio(*this)-=R;
}


CRatio CRatio:: operator*(const CRatio&R)
{
    CRatio RA ;//(m_num,m_den);
    if((m_num!=NULL) && (m_den!=NULL))
    *RA.m_num = (*m_num)*(*R.m_num);
    *RA.m_den = (*m_den)*(*R.m_den);
    return RA;
    
}


CRatio CRatio::operator * (int N)
{
    CRatio RA;//(m_num,m_den);
    if((m_num!=NULL) && (m_den!=NULL))
    *RA.m_num = (*m_num)*N;
    *RA.m_den = (*m_den);
    return RA;
    
}


CRatio operator * (int A,  CRatio&R)
{
    //double N;
    //double*N=m_num;
    //double*num;
  // *R.num; //= new double(num) ;
    //num=1.0;
    //double D;
    //double*D=m_den;
    //double*den;
   // den = new double(5) ;
    //den=1.0;
    
    CRatio RA;//(num,den);
    *RA.m_num = A *(*R.m_num);
    *RA.m_den = *R.m_den;
    return RA;
    
}


ostream& operator << (ostream& cout, const CRatio& R)
{
    cout<<" ratio: "<<*R.m_num<<"/"<<*R.m_den<<endl;
    return cout;
}


istream& operator >> (istream& cin, CRatio& R)
{
    int N,D;
    //if(N>0 && D>0)
    if(R.m_num!=NULL)
        if(*R.m_num>0)
    R.m_num = new double (*R.m_num);
    cout<<"entrez le numérateur\n";
    cin>>*R.m_num;
    
    if(R.m_den!=NULL)
        if(*R.m_den>0)
    R.m_den = new double (*R.m_den);
    cout<<"entrez le dénominateur\n";
    cin>>*R.m_den;
    return cin;
}

