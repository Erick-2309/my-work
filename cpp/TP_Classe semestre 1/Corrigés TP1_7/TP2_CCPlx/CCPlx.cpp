#include "CCPlx.h"

CCPlx::CCPlx()
{
	m_Re = 0;
	m_Im = 0;
	cout << "Passage dans le constructeur";
}

CCPlx::~CCPlx()
{
	cout << "Passage dans le destructeur" << endl;
}

CCPlx::CCPlx(int Re, int Im)
{
	m_Re = Re;
	m_Im = Im;
	cout << "Passage dans le constructeur avec paramètres" << endl;
}

void CCPlx::Affiche()
{
	cout << "La valeur du complexe est : " << endl;
	cout << m_Re << "+" << m_Im << "i" << endl;
}

CCPlx::CCPlx(const CCPlx& C)
{
	m_Re = C.m_Re;
	m_Im = C.m_Im;
	cout << "Passage dans le constructeur copie" << endl;
}

double CCPlx::Module()
{
	return sqrt(m_Re * m_Re + m_Im * m_Im);
}

CCPlx CCPlx::Addition(const CCPlx& C)
{
	CCPlx result;
	result.m_Re = m_Re + C.m_Re;
	result.m_Im = m_Im + C.m_Im;

	return result;
}

CCPlx CCPlx::Multiplication(const CCPlx& C)
{
	CCPlx result;
	result.m_Re = m_Re * C.m_Re - m_Im * C.m_Im;
	result.m_Im = m_Re * C.m_Im + m_Im * C.m_Re;

	return result;
}

