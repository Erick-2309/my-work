#include "CIndividu.hpp"
using namespace std;
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

CIndividu::CIndividu()
    : m_nom(NULL), m_age(0)
{
}

CIndividu::CIndividu(char *nom, int age)
    : m_nom(NULL), m_age(age)
{
    long A = strlen(nom);
    m_nom = new char[A + 1];
    strcpy_s(m_nom, A + 1, nom);
}

CIndividu::CIndividu(const CIndividu &I)
    : m_nom(NULL), m_age(I.m_age)
{
    long A = strlen(I.m_nom);
    m_nom = new char[A + 1];
    strcpy_s(m_nom, A + 1, I.m_nom);
}

CIndividu::~CIndividu()
{
    if (m_nom != NULL)
        delete[] m_nom;
}

ostream &operator<<(ostream &cout, CIndividu &I)
{
    cout << "entrez le nom :" << I.m_nom << endl;
    cout << "entrez l'age :" << I.m_age << endl;
    return cout;
}

istream &operator>>(istream &, CIndividu &I)
{
    cout<<"entrez le nom: ";
    char*nom;
    nom=new char[100];
    cin.getline(I.m_nom, 100);
    I.m_nom=new char[strlen(nom)+1];
    strcpy_s(I.m_nom, strlen(nom)+1, nom);
    //cin>>*I.m_nom;
    cout<<"entrez l'age: ";
    cin>>I.m_age;
    
    return cin;
}
