#include "CVec3.h"

CVec3::CVec3(double x1, double x2, double x3)
	:CVec2(x1,x2),m_x3(x3)
{
}

CVec3::~CVec3()
{
}

 void CVec3::aff()
{
	 CVec2::aff();
	cout << "," << m_x3<<endl;
}
