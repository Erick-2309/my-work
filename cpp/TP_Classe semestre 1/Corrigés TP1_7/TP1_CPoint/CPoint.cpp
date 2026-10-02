#include "CPoint.h"


CPoint::CPoint()
{
	m_x = 0;
	m_y = 0;
	cout << "Passage dans le constructeur";
}

CPoint::CPoint(int x, int y)
{
	m_x = x;
	m_y = y;
	cout << "Passage dans le constructeur avec membre" << endl;
}

CPoint::~CPoint()
{
	cout << "Passage dans le destructeur" << endl;
}

void CPoint::Affiche()
{
	cout << "Position : (" << m_x << "," << m_y << ")" << endl;
}

void CPoint::Translate(int dx, int dy)
{
	m_x = dx;
	m_y = dy;
}

bool CPoint::Coincide(const CPoint& C)
{
	return ((m_x == C.m_x) && (m_y == C.m_y));
}
