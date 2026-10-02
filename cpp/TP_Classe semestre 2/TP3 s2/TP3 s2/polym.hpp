#pragma once
#include <iostream>
using namespace std;


class CVec2
{
private:
    double m_x1, m_x2;
public:
    CVec2(double=0.0, double=0.0);
    virtual~CVec2();
    virtual void aff();
    friend ostream&operator<<(ostream&, const CVec2&);
};

 
class CVec3:public CVec2
{
private:
    double m_x3;
public:
    CVec3(double=0,double=0,double=0.0);
     virtual~CVec3() ;
     virtual void aff();
    friend ostream&operator<<(ostream&,CVec3&);
};





