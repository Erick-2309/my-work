#include "polym.hpp"


CVec2::CVec2(double x, double y)
:m_x1(x),m_x2(y)
{}

CVec2::~CVec2()
{}

void CVec2::aff()
{
    cout<<"X1: "<<m_x1<<endl;
    cout<<"X2: "<<m_x2<<endl;
}

ostream&operator<<(ostream& cout,const CVec2&V2)
{
    cout<<"X1: "<<V2.m_x1<<endl;
    cout<<"X2: "<<V2.m_x2<<endl;
    return cout;
}


CVec3::CVec3(double x, double y,double z)
:m_x3(z),CVec2(x,y)
{}

CVec3::~CVec3()
{}

  void CVec3::aff()
{
    CVec2::aff();
    cout<<"X3: "<<m_x3<<endl;
}


ostream&operator<<(ostream& cout,CVec3&V3)
{
    CVec2 *V2=&V3;
    cout<<*V2;
    cout<<"X3: "<<V3.m_x3<<endl;
    
    return cout;
}
