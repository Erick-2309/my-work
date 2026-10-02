#include "Cvect.h"
using namespace std;

int main()
{
    bool ordre=0;
    double vect[]={5,1,6,2,9,12,0,15,3};
    double tab[]={5,6,7};
    Cvect V1(9,vect),V2(3,tab);
    V1.TriInsertion();
   // V1.TriSelection();
    //V1.TriInsertion();
    cout<<V1<<endl;
    V1.TriBulles(ordre);
    cout<<V1<<endl;
    cin>>V2;
    cout<<V2<<endl;
    /*V1.Permute(1,2);
    cout<<V1<<endl;
    cout<<V1+V2<<endl;
    V1+=V2;
    cout<<V1<<endl;
    cout<<V1*V2<<endl;
     */
}






























/* double pliste[]={2.1,3.6,4.0,8,1};
 Cvect t1(5),t4(5);
 cin>>t1;
 cout<<t1;
 Cvect t(5,pliste);
 //Cvect t3(t);
 cout<<t;
 cout<<"le produit scalaire vaut :"<< t1.Prod_Scal(t)<<endl;;
 cout<<"la somme vaut : "<<t1.operator+=(t)<<endl;
 cout<<"le produit simple vaut"<<t4.Prod_Simpl(3);
 //cout<<t4;
 return 0;*/
