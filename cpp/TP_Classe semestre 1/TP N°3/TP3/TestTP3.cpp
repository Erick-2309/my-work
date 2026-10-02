#include "CRatio.hpp"

int main()
{
    int a;
    CRatio C1,C2,C3;
    CRatio C(C1);
    CRatio S;
    int N=0;
    
    cin>>C1;
    cout<<"le ratio vaut: "<<C1<<endl;
    cout<<"l'opposé vaut: "<<C1.Oppose()<<endl;
    cout<<"le ratio de C1 incrementé de 1 vaut: "<<C1.Incremente()<<endl;
    cout<<"entrez un entier: "<<endl;
    cin>>a;
    cout<<"le ProduitScal avec "<<a<<" vaut: "<<C1.ProduitScal(a)<<endl;
    
    cin>>C2;
    cout<<"le ratio vaut: "<<C2<<endl;
    cout<<"l'opposé vaut: "<<C2.Oppose()<<endl;
    cout<<"la somme vaut "<<C1.Somme(C2)<<endl;
    cout<<"la difference vaut "<<C1.Difference(C2)<<endl;
    cout<<"le produit vaut: "<<C1.ProduitRatio(C2)<<endl;
    
    cin>>C3;
    cout<<"le ratio de  vaut: "<<C3<<endl;
    cout<<"l'opposé vaut: "<<C3.Oppose()<<endl;
   // C1.Affiche();
    C3.Signe();
    
  /*  cout<<"combient de valeur voulez vous additionner ?"<<endl;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cout<<"saisir la "<<i<<" valeur: "<<endl;
        cin>>C1;
        S=S+C1;
    }*/
    
    
    
    
    
    
    
    
    
    
    
    
    
}





/*
int m_num,m_num2=m_num2,m_num3;
int m_den,m_den2=m_den2,m_den3;
cout<<"veillez entrer le numerateur du premier point \n";
cin>>m_num;
cout<<"veillez entrer le denominateurdu premier point \n";
cin>>m_den;
CRatio C1(m_num,m_den),C2(m_num2,m_den2);
//CRatio C(C1);
C1.Affiche();
cout<<"veillez entrer le numerateur du deuxième point \n";
cin>>m_num2;
cout<<"veillez entrer le denominateurdu deuxième point \n";
cin>>m_den2;
*/
