#include "Ctab.hpp"
int main()
{
    bool ordre;
    double pnote[]={12.5,4.5,13.2};
    Cptab t1,t2,t3,t;
    cin>>t1;
    Cptab t4(5);
    cout<<t4;
    cout<<t1;
    cout<<"la moyenne vaut : "<<t1.Moyenne()<<"\n";
    cout<<"le minimun vaut : "<<t1.Min()<<"\n";;
    cout<<"la maximum vaut : "<<t1.Max()<<"\n";;
    cout<<"l'écart type de vaut :"<<t1.Ect()<<"\n";;
    cout<<" ordre de trie du tableau (0 pour decroissant et 1 pour croissant)? ";
    cin>> ordre;
    t1.Tri(ordre);
    cout<<t1;
    t1.Swap(1,2);
    Cptab note(3, pnote);
    cout<< note;
    note.Swap(1,2);
    cout<< note;
    t1.Random(1,2);
    cout<<t1;
    /*
    cin>>t2;
    cout<<t2;
    coiut<<"la moyenne vaut : "<<t2.Moyenne();
    cout<<"le minimun vaut : "<<t2.Min();
    cout<<"la maximum vaut : "<<t2.Max();
    cout<<"l'écart type de vaut :"<<t2.Ect()<<endl;
    cout<<" ordre de trie du tableau (0 pour decroissant et 1 pour croissant)? ";
    cin>> ordre;
    t2.Tri(ordre);
    cout<<t2;
     */
    

    //t1.Random(1,2);

}
