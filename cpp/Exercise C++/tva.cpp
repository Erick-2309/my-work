#include<iostream>
using namespace std;


int calcul_TTC(double p,double TVA)
{
    TVA =0.20*p;
    return p+TVA;
}
int main()
{
    double TVA = 0;
    double p = 0;
    double remise;
    double prix;
    cout<<"veillez Saisir le prix hors taxe"<<endl;
    cin>>p;
    if(p<300)
    {
        remise =0;
    }
     else if(p>=300 && p<450)
    {
      remise =0.1;
    }
    else if(p>=450 && p<750)
    {
        remise =0.3;
    }
     else if (p>700)
     {
         remise =0.5; 
     }
    cout<<"prix TTC: "<<calcul_TTC(p,TVA)<<endl;     
    cout<<"prix à payer: "<<calcul_TTC(p,TVA)-(remise*calcul_TTC(p,TVA))<<endl;
    
         return 0;
}

/*
int calcul_TTC(double p,double TVA)
{
    return p+(0.20 * p);
}
int main()
{
    float TVA=0;
    float p=0;
    float A;
    float remise;
    
    cout<<"vayllez Saisir le prix hors taxe"<<endl;
    cin>>p;
    if(p<300)
    {
        remise =0;
    }
     else if(p>=300 && p<450)
    {
       remise =0.1;
    }
    else if(p>=450 && p<750)
    {
        remise =0.3;
    }
    else
    {
        remise =0.5;
    }
    A=calcul_TTC(p,TVA);
    cout<<"prix hors taxe: "<<p<<endl;
    cout<<"prix TTC: "<<A<<endl;
    cout<<"prix à payer: "<<A-remise<<endl;
return 0;
}
*/