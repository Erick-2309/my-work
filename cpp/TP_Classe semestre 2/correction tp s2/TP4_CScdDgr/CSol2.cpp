#include"CSol2.h"

CSol2::CSol2(double a, double b, double discriminant)
{
	m_x1 = (-b + pow(discriminant, 0.5)) / (2 * a);
	m_x2 = (-b - pow(discriminant, 0.5)) / (2 * a);
}

void CSol2::Affiche()
{
	cout << "Deux solutions : " << m_x1 << " et " << m_x2 << endl;
}

CSol2::CSol2()
{
	m_x1 = 0;
	m_x2 = 0;
}