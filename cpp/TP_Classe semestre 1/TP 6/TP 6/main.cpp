#include <iostream>
#include "CSignal.hpp"
using namespace std;

int main()
{
    CSignal t1,t2,t,l;
    cin>>t1;
    cout<<t1<<"\n";
    //t1.FillRand();
    //cin>>t1;
    cin>>t2;
    cout<<t2;
    //t1=t2;                //opérateur =
    //cout<<t1<<"\n";
    cout<<t1+t2<<endl;  //opérateur +
    
    //t=t1+t2;            //opérateur +=
    //cout<<t;
    //t=t1+3.0;
   // cout<<t;
    //t1.multiplie(t1,3.0);
    //cout<<t1<<"\n";
    
    cout<<"la moyenne vaut : "<<t1.Moyenne()<<"\n";
    cout<<"la variance vaut : "<<t1.Variance()<<"\n";
    cout<<"la min vaut : "<<t1.Min()<<"\n";
    cout<<"la max vaut : "<<t1.Max()<<"\n";
    
    
    
    cout<<"le produit scalaire vaut : "<<t1*t2<<"\n";
    cout<<"le produit simple  vaut : "<<t1*2.0<<"\n";
    l=3.0*t1;
    cout<<"le produit simple vaut : "<<l<<"\n";
    
    t1.Tri();
    cout<<"le tableau trié renvoie : "<<t1<<"\n";
    
    return 0;
}




