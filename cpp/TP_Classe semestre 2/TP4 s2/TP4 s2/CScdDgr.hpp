#pragma once
#include <iostream>
#include <Cmath>
using namespace std;
#include "CSolution.hpp"
#include "CSol0.hpp"
#include "CSol1.hpp"
#include "CSol2.hpp"

class CScdDgr
{
protected:
    double m_a;
    double m_b;
    double m_c;
    CSolution* m_pSol;
public:
    CScdDgr(double=0.0,double=0.0,double=0.0);
    CScdDgr(const CScdDgr&);
    virtual~CScdDgr();
     void aff();
    friend ostream& operator<<(ostream&,const CScdDgr&);
    friend istream& operator>>(istream&, CScdDgr&);
};





