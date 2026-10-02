#include "CVect.hpp"

int main()
{
    double vect[4]={1,2,3,4};
    CVect V(vect,4),V1,V2(5),V3,V4(3),V5,V6;
    V.remplir();
    V2.remplir();
    V4.remplir();
    cout<<V;
    cout<<V2;
    //cout<<V4;
//fichier text
    char nom_t[100];
    cout<<"entrez le nom du fichier\n";
    cin>>nom_t;//txt
    V.Ecrit(nom_t);
    V1.Lit(nom_t);
    cout<<V1;
    
//fichier binaire
    char nom_b[100];
    cout<<"entrez le nom du fichier\n";
    cin>>nom_b;//bin
    V2.Ecrit_Bin(nom_b);
    V3.Lit_Bin(nom_b);
    cout<<V3;
   
    V4.Add_Flux(nom_t);
    V5.Lit(nom_t);
    cout<<V5;
    
    V4.Add_Flux(nom_b);
    V6.Lit_Bin(nom_b);
    cout<<V6;
   
    
    return 0;
}
