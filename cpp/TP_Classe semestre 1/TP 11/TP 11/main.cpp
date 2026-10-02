#include<iostream>
using namespace std;
#include "CTab2D.hpp"




int main()
{
    double T1[]={1,2,3,4,5};
    double T2[]={1,2,3,4,5};
    double T3[]={1,2,3,4,5};
    double T4[]={1,2,3,4,5};
    double*Tab[]={T1,T2,T3,T4};
    double tab =4;
    double tab2 =3;
    CTab2D T(4,4,tab),Ta(4,4,tab2),Tb;
    cout<<Tab[0][0]<<endl;
//  cout<<T.FillRand();
//  cout<<T+Ta;
//  cout<<T;
    cin>>Tb;
    cout<<Tb.T_inf();
    cout<<Ta.T_sup()<<endl;
    cout<<Ta.T_inf()<<endl;
    cout<<Ta.Diagonale()<<endl;
    cout<<T*Ta;
    T+=Ta;
    cout<<T;
    T+=4.0;
    cout<<T;
    3*T;
//  T*3;
    cout<<T;
    T=Tab;
    cout<<T;
    cout<<"la valeur pour la case est :"<<T.cellule()<<endl;
    T.set();
    cout<<T<<endl;
    
    
    
}
