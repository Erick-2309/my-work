#pragma once
#include "iostream"
using namespace std;
#include "CEleve.hpp"



// Implémentation d'une version de strcpy_s
errno_t strcpy_s(char *chaine, size_t longueur_chaine, const char *src)
{
    // Vérifier si la destination et la source sont valides
    if (!chaine || !src)
    {
        return -1; // Retourner une erreur si une des chaînes est nulle
    }

    size_t longueur_src = strlen(src);

    // Vérifier si la destination a suffisamment de place pour la chaîne source
    if (longueur_src >= longueur_chaine)
    {
        return -1; // Si pas assez de place, retourner une erreur
    }

    strcpy(chaine, src); // Si tout va bien, copier la chaîne source
    return 0;            // Succès
}

int main()
{
    int A=100;
    char*nom=new char[A];
    A=strlen("TCHITAE")+1;
    strcpy_s(nom,A+1,"TCHITAE");
    int age=18;
    CIndividu I(nom,age),I2;
    cout<<I;
    cin>>I2;
    cout<<I2;
    
    double T[]={12,16,19,14};
    int N=4;
    CEleve E(nom,age,T,N),E2;
    cout<<E;
    cin>>E2;
    cout<<E2;
    
    int Nb=5;
    CEleve*eleve;
    eleve=new CEleve[5];
    int n=0;
    double *note=new double[n];
    for(int i=0; i<Nb; i++)
    {
        cout<<"------eleve------"<<i+1<<":\n";
        cout<<" nom: ";
        int B=100;
        char*nom;
        nom=new char[B];
        cin.getline(nom, 100);
        nom=new char[strlen(nom)+1];
        strcpy_s(nom, B+1, nom);
        
        cout<<"age :";
        int age=0;
        cin>>age;
        
        cout<<"---notes---\n";
        
        cout<<"nombre de notes :";
        cin>>n;
        
        for(int i=0; i<n; i++)
        {
            cout<<"note "<<i+1<<" :";
            cin>>note[i];
        }
        
    }
    
    for(int i=0; i<Nb; i++)
    {
        cout<<"------eleve "<<i+1<<":------\n";
        cout<<" nom: "<<nom;
        cout<<"age: "<<age;
        cout<<"nombre de notes :"<<n<<endl;
        
        cout<<"---notes---\n";
        
        for(int i=0; i<Nb; i++)
        {
            cout<<"note "<<i+1<<" :"<<note[i];
        }
    }
        
    return 0;
}
