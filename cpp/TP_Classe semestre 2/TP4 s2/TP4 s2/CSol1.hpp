#include<iostream>
#include "CSolution.hpp"
using namespace std;


class CSol1: public CSolution
{
private:
    double m_x_0;
    double m_b;
    double m_a;
public:
    CSol1();
    CSol1(double, double);
    ~CSol1();
  void aff();
};
