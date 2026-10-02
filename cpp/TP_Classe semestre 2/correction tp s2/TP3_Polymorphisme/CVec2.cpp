#include "CVec2.h"

CVec2::CVec2(double x1, double x2)
	:m_x1(x1),m_x2(x2)
{
}

CVec2::~CVec2()
{
}

void CVec2::aff()
{
	cout  << "("<<m_x1 << ","<< m_x2 ;
}
