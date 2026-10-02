#include<iostream>
using namespace std;
#include "CSolution.hpp"
#include<cmath>

class CSol2: public CSolution
{
private:
    double m_x_1;
    double m_x_2;
    double m_a;
    double m_b;
    double m_c;
    double m_delta;
public:
    CSol2();
    CSol2(double, double, double, double);
    ~CSol2();
     void aff();
};
