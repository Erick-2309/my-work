#define CNoeud_hpp
#include<iostream>
using namespace std;
typedef double elmt ;

class CNoeud
{
private:
    int N;     //nombre d'élement
    CNoeud* m_p;
    CNoeud* m_s;
    elmt* m_elmt;
public:
    CNoeud();
    ~CNoeud();
    void SetElm (elmt*);       // initialise l'élément associé au noeud
    elmt* GetElm ();           // retourne l'élément associé au noeud
    void Affi ();              // affiche l'élément associé au noeud
    void Precedent (CNoeud*);  // initialise le pointeur sur le noeud précédent
    CNoeud* Precedent();       // retourne le pointeur sur le noeud précédent
    void Suivant (CNoeud*);    // initialise le pointeur sur le noeud suivant
    CNoeud* Suivant ();        // retourne le pointeur sur le noeud suivant
    
    
};
