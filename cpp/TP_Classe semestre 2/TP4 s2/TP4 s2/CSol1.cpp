#include "CSol1.hpp"



CSol1::CSol1(double a, double b)
:m_a(a),m_b(b)
{
    m_x_0 = (-b)/(2*a);
}
CSol1::~CSol1()
{}

void CSol1::aff()
{
    cout<<"solution unique: X0 = "<<m_x_0<<endl;
}
