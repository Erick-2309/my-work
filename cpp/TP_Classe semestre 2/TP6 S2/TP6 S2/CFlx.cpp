#include "CFlx.hpp"


CFlx::CFlx(char*nom)
:m_nom(NULL),m_fr(NULL)
{
    m_nom=new char[100];
    strcpy(m_nom, nom);
    m_fr=new fstream(nom,ios::out|ios::in);
   // m_fr.open(nom,ios::out|ios::in);
}
