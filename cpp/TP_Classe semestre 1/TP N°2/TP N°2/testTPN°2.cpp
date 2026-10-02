#include"CCPlx (1).h"
#include<iostream>
using namespace std;

int main()
{
    CCPlx C1,C2;
    //C2.Affiche();
	//C1.Affiche();
    cin>>C1;
    cout<<"le point vaut C1: "<<C1<<endl;
    cin>>C2;
    cout<<"le point vaut C2: "<<C2<<endl;
   
    
    //CCPlx C3(C2);
    cout << "le module vaut: "<<C1.Module()<<endl;
    cout << "le module vaut: "<<C2.Module()<< endl;
    CCPlx C;
    //C=C1;
    cout<<C<<endl;
    //C=(C2+C1);
    //C=(C2+C1+C2);
    cout<<"la somme vaut: "<<C.operator+=(C2+C1+C1)<<endl;  //ou
    cout <<C;
    //C2.operator+(C1)<<endl;
    cout<<"la somme vaut: "<<C.operator+(C+C2+C1)<<endl;
    cout <<C;
    cout<<"la difference vaut "<<C2-C1<<endl;      //ou C2.operator-(C1)<<endl;
    cout<<"le produit vaut: "<<C1.operator*=(C2)<<endl;       //ou
    cout <<C1;//C1.operator*(C2)<<endl;
    cout<<"le ratio vaut: "<<C1.operator/(C2)<<endl;
	return 0;
}
