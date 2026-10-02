#include "CTab2D.h"


void CTab2D::Alloc(int l, int c)
{
	m_nL = l;
	m_nC = c;
	m_pTab = new double*[m_nL];
	for (int i = 0; i < m_nL; i++)
	{
		m_pTab[i] = new double[m_nC];
	}
}

void CTab2D::Init(int l, int c, double val)
{
	m_nL = l;
	m_nC = c;
	for (int i = 0; i < m_nL; i++)
	{
		for (int j = 0; j < m_nC; j++)
		{
			m_pTab[i][j] = val;
		}
	}
}

void CTab2D::free()
{
	if (m_pTab != NULL)
	{
		for (int i = 0; i < m_nL; i++)
		{
			if (m_pTab[i] != NULL)
			{
				delete[]m_pTab[i];
				m_pTab[i] = NULL;
			}
		}
		delete[]m_pTab;
		m_pTab = NULL;
	}
}

CTab2D::CTab2D( int l, int c, double val)
{
	Alloc(l, c);
	Init(l,c, val);
}

CTab2D::CTab2D(const CTab2D & T)
{
	//free();
	Alloc(T.m_nL, T.m_nC);
	for (int i = 0; i < m_nL; i++)
	{
		for (int j = 0; j < m_nC; j++)
		{
			m_pTab[i][j] = T.m_pTab[i][j];
		}
	}
}

void CTab2D::FillRand()
{
	int a = 0;
	int b = 1;
	srand((unsigned)time(NULL));
	for (int i = 0; i < m_nL; i++)
	{
		for (int j = 0; j < m_nC; j++)
		{
			m_pTab[i][j] = (a + (b - a)*(double)rand() / RAND_MAX);
		}
	}
}

ostream& operator <<(ostream &os, const CTab2D & T)
{
	for (int i = 0; i < T.m_nL; i++)
	{
		for (int j = 0; j < T.m_nC; j++)
		{
			os<<T.m_pTab[i][j]<<" ";
		}
		os << endl;
	}
	return (os);
}

CTab2D CTab2D::operator=(double**T)
{
	Alloc(T[0][0], T[0][1]);
	m_nL = T[0][0];
	m_nC = T[0][1];
	for (int i = 1; i < m_nL; i++)
	{
		for (int j = 1; j < m_nC; j++)
		{
			m_pTab[i][j] += T[i][j];
		}
	}

	for (int i = 2; i < m_nL; i++)
	{
		m_pTab[0][i] += T[0][i + 2];
	}

	for (int i = 1; i < m_nL; i++)
	{
		m_pTab[i][0] += T[i + 1][0];
	}

	return *this;

}

CTab2D CTab2D::operator=(const CTab2D &T)
{
	Alloc(T.m_nL, T.m_nC);
	for (int i = 0; i < m_nL; i++)
	{
		for (int j = 0; j < m_nC; j++)
		{
			m_pTab[i][j] = T.m_pTab[i][j];
		}
	}
	return(*this);
}

void CTab2D::set(int i, int j, double val)
{
	m_pTab[i-1][j-1] = val;
}

double* CTab2D::operator[](int j)
{
	return(m_pTab[j]);
	
}

cout << T[2][3];

double CTab2D::operator()(int i, int j)
{
	return(m_pTab[i][j]);
}

CTab2D CTab2D::operator+(const CTab2D& T)
{
	CTab2D Res(T.m_nL,T.m_nC);
	for (int i = 0; i < m_nL; i++) {
		for (int j = 0; j < m_nC; j++)
		{
			Res[i][j] = m_pTab[i][j] + T.m_pTab[i][j];
		}
	}
	return (Res);
}

CTab2D CTab2D::operator+=(const CTab2D& T)
{
	for (int i = 0; i < m_nL; i++) {
		for (int j = 0; j < m_nC; j++)
		{
			m_pTab[i][j] = m_pTab[i][j] + T.m_pTab[i][j];
		}
	}
	return(*this);
}

CTab2D CTab2D::operator+=(double a)
{
	for (int i = 0; i < m_nL; i++) {
		for (int j = 0; j < m_nC; j++)
		{
			m_pTab[i][j] = m_pTab[i][j] + a;
		}
	}
	return(*this);
}

CTab2D CTab2D::operator*(double a)
{
	CTab2D Res(m_nL, m_nC);
	for (int i = 0; i < m_nL; i++) {
		for (int j = 0; j < m_nC; j++)
		{
			Res[i][j] = m_pTab[i][j]*a;
		}
	}
	return (Res);
}

CTab2D operator*(double a, const CTab2D& T)
{
	CTab2D Res(T.m_nL, T.m_nC);
	for (int i = 0; i < T.m_nL; i++) {
		for (int j = 0; j < T.m_nC; j++)
		{
			Res[i][j] = T.m_pTab[i][j] * a;
		}
	}
	return (Res);
}

CTab2D CTab2D::operator*(const CTab2D & T)
{
	if (T.m_nL != m_nC)
	{
		return(NULL);
	}
	CTab2D Res(T.m_nL, T.m_nC);
	for (int i = 0; i < T.m_nL; i++) 
	{
		for (int j = 0; j < T.m_nC; j++)
		{
			for (int k = 0; k < m_nC; k++) 
			{
				Res.m_pTab[i][j] += m_pTab[i][k] * T.m_pTab[k][j];
			}
		}
	}
	return (Res);
}

CTab2D::~CTab2D()
{
	free();
}
