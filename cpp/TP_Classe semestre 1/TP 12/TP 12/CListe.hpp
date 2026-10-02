#ifndef CListe_hpp
#define CListe_hpp
#include <iostream>
#endif /* CListe_hpp */
#include "CNoeud.hpp"
using namespace std;
typedef double elmt;

class CListe
{
private:
    int m_N;               // nombre de noeud
    elmt* m_elmt;
    CNoeud* m_debut;
    CNoeud* m_fin;
    elmt* m_courent;
    double* m_Nnoeud;
public:
    CListe(int);
    ~CListe();
    elmt* Debut ();        // affecte l'adresse du premier noeud au pointeur courant
    elmt* Fin ();          // affecte l'adresse du dernier noeud au pointeur courant
    void Insere (elmt*);   // insère un élément en fin de liste
    elmt* Retire ();       // retire le dernier élément de la liste
    void Affi ();          // affiche tous les éléments de la liste
};




