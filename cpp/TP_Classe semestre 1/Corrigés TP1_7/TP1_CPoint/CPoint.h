#pragma once
#include <iostream>
using namespace std;

class CPoint
{
private :
	int m_x;
	int m_y;

public :
	CPoint();
	CPoint(int x, int y);
	~CPoint();
	void Affiche();
	void Translate(int dx, int dy); 
	CPoint(int nX) { m_x = m_y = nX;} // Constructeur inline
	bool Coincide(const CPoint& C);
};

