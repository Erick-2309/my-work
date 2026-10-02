#include "CEllipse.hpp"


CEllipse::CEllipse()
:m_pr(0)
{}

CEllipse::CEllipse(int pr,int r,int*coord)
: m_pr(pr),CCercle(r,coord)
{}

CEllipse::CEllipse(const CEllipse&E)
: m_pr(E.m_pr),CCercle(E)
{}


CEllipse::~CEllipse()
{}

ostream&operator<<(ostream&cout, CEllipse& E)
{
    cout<<"---elipse----\n";
    CCercle *C = &E;
    cout<< *C;
    cout<<"_longueur du petit rayon: "<<E.m_pr<<endl;
    cout<<"_elipse centrée au point ("<<E.m_pcoord[0]<<","<<E.m_pcoord[1]<<") et de rayons "<<E.m_pr<<" et "<<E.m_r<<endl;
    
    return cout;
}

istream& operator>>(istream&cin,CEllipse&E)
{
    CCercle *C = &E;
    cin>> *C;
    cout<<"entrez le petit rayon : ";
    cin>>E.m_pr;
    return cin;
}

void CEllipse::redimensionne(int k)
{
    CCercle::redimensionne(k);
    m_pr*=k;
}
