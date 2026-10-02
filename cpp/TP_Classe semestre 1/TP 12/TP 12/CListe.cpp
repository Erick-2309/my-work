#include "CListe.hpp"
using namespace std;



CListe::CListe(int N)
:m_N(N),m_elmt(NULL),m_debut(NULL),m_fin(NULL),m_courent(NULL)
{
    m_elmt =new elmt();
    m_debut=new CNoeud();
    m_fin=new CNoeud();
    m_courent=new elmt();
}

elmt* CListe::Debut()
{
    m_courent=m_debut;
    return m_elmt;
}
