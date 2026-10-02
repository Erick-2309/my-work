#include "CNoeud.hpp"
#include <iostream>
using namespace std;

CNoeud::CNoeud()
:m_p(NULL),m_s(NULL),m_elmt(NULL)
{
    m_s = new CNoeud();
    m_p = new CNoeud();
    m_elmt = new double();
}



CNoeud::~CNoeud()
{
    if(m_p!=NULL && m_s!=NULL && m_elmt!=NULL)
    {
        delete[]m_s;
        delete[]m_p;
        delete[]m_elmt;
    }
}

void CNoeud::SetElm (elmt*Element)
{
    if( m_elmt!=NULL)
    *m_elmt=*Element;
}

 elmt* CNoeud:: GetElm ()
{
     return m_elmt;
}

void CNoeud::Affi ()
{
    cout<<"l'element est: "<<*m_elmt<<endl;
}

void CNoeud::Precedent (CNoeud*noeud)
{
    *m_p=*noeud;
}


CNoeud*CNoeud:: Precedent()
{
    return m_p;
}

void CNoeud::Suivant(CNoeud*noeud)
{
    *m_s=*noeud;
}


CNoeud*CNoeud:: Suivant()
{
    return m_s;
}
