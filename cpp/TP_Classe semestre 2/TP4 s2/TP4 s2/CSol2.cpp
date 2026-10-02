#include "CSol2.hpp"


CSol2::CSol2(double a, double b, double c,double delta)
:m_a(a),m_b(b),m_c(c),m_delta(delta)
{
    delta=(b * b - 4 * a * c);
    m_x_1=(-b +sqrt(delta)) / (2*a);
    m_x_2=(-b -sqrt(delta)) / (2*a);
}
CSol2::~CSol2()
{}

void CSol2::aff()
{
    cout<<"solution double: X1 = "<<m_x_1<<", X2 = "<<m_x_2<<endl;
}




/*complex<double> racine = (-b +i*sqrt(-D0)) / (2*a);
 m_Sol=racine.real();
*/
