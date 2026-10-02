#include "CCercle.hpp"


CCercle::CCercle()
:m_r(0)
{}

CCercle::CCercle(int r,int*coord)
: m_r(r),CPoint2D(coord)
{}

CCercle::CCercle(const CCercle&C)
: m_r(C.m_r),CPoint2D(C)
{}


CCercle::~CCercle()
{}

ostream&operator<<(ostream&cout, CCercle& C)
{
    CPoint2D *P = &C;
    cout<< *P;
    cout<<"_longueur du rayon: "<<C.m_r<<endl;
    return cout;
}

istream& operator>>(istream&cin,CCercle&C)
{
    CPoint2D *P = &C;
    cin>> *P;
    cout<<"entrez le rayon : ";
    cin>>C.m_r;
    return cin;
}

void CCercle::redimensionne(int k)
{
    m_r*=k;
}
