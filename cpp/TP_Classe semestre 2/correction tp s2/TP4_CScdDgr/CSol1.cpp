#include"CSol1.h"

CSol1::CSol1(double a, double b)
{
	m_x1 = -b / (2 * a);
}

void CSol1::Affiche()
{
	cout << "Une seule solution : " << m_x1 << endl;
}

CSol1::~CSol1()
{
}