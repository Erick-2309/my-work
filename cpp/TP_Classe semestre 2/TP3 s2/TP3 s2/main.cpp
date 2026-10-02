#include "polym.hpp"


int main()
{ 
    
    CVec2 vct21(1.0,2.0);
    CVec2*pvct21=&vct21;
    vct21.aff();
    vct21=*pvct21;
    vct21.aff();
    cout<<endl<<endl;
    //cout<<*pvct21<<endl<<endl;
    
    CVec3 vct31(4.0,5.0,6.0);
    CVec3*pvct31=&vct31;
    vct31.aff();
    vct31=*pvct31;
    vct31.aff();
   // cout<<*pvct31<<endl;
    cout<<endl<<endl;
    
    cout<<"affiche 4(pointeur +virtuel)\n";
    CVec2* pvct22=&vct31;
    pvct22 ->aff();
    
    cout<<"affiche 4biss(virtuel sans pointeur)\n";
    CVec2 vct22=vct31;
    vct22 .aff();
    
    cout<<endl;
    //cout<<*pvct22;
    //en initialisant un pointeur sur objet CVec2 avec l'adresse d'un objet CVec3
    //on obtien un objet CVec2 si la fonction affiche est en virtuel et en automatique(sans pointeur)
    //on obtien un objet CVec3 si la fonction affiche est en virtuel et en dynamique(pointeur)
    
    //DONC LE POLYMORPHISME FONCTION SI ON TRAVAIL AVEC DES POINTEUR ET SI ON EST EN VIRTUEL POUR LES FONCTION AFFICHE 
    
    cout<<"virtuel sans pointeur\n";
    cout<<"on obtient que des objets de type CVec2\n";
    CVec2 tvec[6];
    tvec[0]=vct21;
    tvec[1]=vct31;
    tvec[2]=vct21;
    tvec[3]=vct31;
    tvec[4]=vct21;
    tvec[5]=vct31;
    for(int i=0; i<6; i++)
    {
        tvec[i].aff();
        cout<<endl;
    }
    //on obtient que des objets de type CVec2
    cout<<endl;
    cout<<endl;
    
    cout<<"virtuel avec pointeur\n";
    cout<<"on obtient  des objets de type CVec2 et CVect3 en fonction de l'allocation faite\n";
    CVec2* tpvec[6];
    tpvec[0]=&vct21;
    tpvec[1]=&vct31;
    tpvec[2]=&vct21;
    tpvec[3]=&vct31;
    tpvec[4]=&vct21;
    tpvec[5]=&vct31;
    for(int i=0; i<6; i++)
    {
        tpvec[i]->aff();
        cout<<endl;
    }
    //on obtient  des objets de type CVec2 et CVect3 en fonction de l'allocation faite
    return 0;
}

/*
+-------------------------+
|     Pointeur pvct21     |
|      (adresse 0x100)    |
+-------------------------+
       |
       v
+-------------------------+
|      Objet vct21         |
|  m_x1 = 1.0, m_x2 = 2.0  |   <-- mémoire pour l'objet CVec2
+-------------------------+

+-------------------------+
|     Pointeur pvct31     |
|      (adresse 0x200)    |
+-------------------------+
       |
       v
+-------------------------+
|      Objet vct31         |
|  m_x1 = 4.0, m_x2 = 5.0  |   <-- mémoire pour l'objet CVec3
|  m_x3 = 6.0              |
+-------------------------+
*/
