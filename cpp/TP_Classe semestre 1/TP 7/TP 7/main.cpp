#include "CRatio.hpp"
#include<iostream>
using namespace std;


int main()
{
    CRatio R1,R2,R,R3(5, 6),R4(7, 8),R5(9, 10);
    CRatio *ratios = new CRatio[5];
    ratios[0] = R1;
    ratios[1] = R2;
    ratios[2] = R3;
    ratios[3] = R4;
    ratios[4] = R5;
    cin>> R1;
    cout<<R1;
    cin>>R2;
    cout<<R2;
    cout<<"le ration incrémenté de 1vaut: "<<R1.operator++();
    cout<<"l'inverse vaut: "<<R1.operator-();
    cout<<"ceci est el produit de R1 par 4: "<<R1*4<<endl;
    cout<<"ceci est el produit de 4 par R2: "<<4*R2<<endl;
    cout<<"la somme vaut: "<<R1+R2<<endl;
    cout<<"la différence vaut: "<<R1-R2<<endl;
    cout<<"ceci est la copiee de R2 dans R1: "<<R1.operator=(R2)<<endl;
    cout<<"ceci est le produit de R1 par R2: "<<R1*R2;
    cout<<"ceci est le signe de R1: "<<R1.operator&()<<endl;
    
}
