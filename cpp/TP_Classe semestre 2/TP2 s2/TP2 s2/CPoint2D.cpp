#include "CPoint2D.hpp"

CPoint2D::CPoint2D()
 : m_pcoord(NULL)
{
}

/*CPoint2D::CPoint2D(int a, int b)
 : m_pcoord(NULL)
{
    m_pcoord = new int[2];
    m_pcoord[0] = a;
    m_pcoord[1] = b;
}*/

CPoint2D::CPoint2D( int *coord)
: m_pcoord(NULL)
{
    m_pcoord = new int[2];
    m_pcoord[0] = coord[0];
    m_pcoord[1] = coord[1];
}

CPoint2D::CPoint2D(const CPoint2D &P)
    :  m_pcoord(NULL)
{
    m_pcoord = new int[2];
    m_pcoord[0] = P.m_pcoord[0];
    m_pcoord[1] = P.m_pcoord[1];
}

CPoint2D::~CPoint2D()
{
    if (m_pcoord != NULL)
        delete[] m_pcoord;
}


ostream &operator<<(ostream &cout, const CPoint2D &P)
{
    cout <<"_abscisse du centre : " << P.m_pcoord[0]<<endl;
    cout <<"_ordonée du centre : " << P.m_pcoord[1]<<endl;
    return cout;
}

istream &operator>>(istream &cin, CPoint2D &P)
{
    P.m_pcoord=new int[2];
    cout << "entrez l'abscisse: ";
    cin >> P.m_pcoord[0];
    cout << "entrez l'ordonée: ";
    cin >> P.m_pcoord[1];
    return cin;
}

void CPoint2D::translate(int dx, int dy)
{
    m_pcoord[0] += dx;
    m_pcoord[1] += dy;
}
