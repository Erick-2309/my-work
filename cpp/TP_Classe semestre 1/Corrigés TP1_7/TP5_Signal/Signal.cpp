#include "Signal.h"
#include <time.h>

CSignal::CSignal(int nN)
{
	m_nN = nN;
	if (m_nN != 0)
	{
		m_ptab = new double[nN];
		for (int i = 0; i < m_nN; i++)
		{
			m_ptab[i] = 0;
		}
	}
}

CSignal::CSignal(int nN, double * tab)
{
	m_nN = nN;
	m_ptab = new double[m_nN];
	for (int i = 0; i < m_nN; i++)
	{
		m_ptab[i] = tab[i];
	}
}

CSignal::CSignal(const CSignal & c)
{
	m_nN = c.m_nN;
	m_ptab = new double[m_nN];
	for (int i = 0; i < m_nN; i++)
	{
		m_ptab[i] = c.m_ptab[i];
	}
}

CSignal CSignal::operator=(const CSignal & c)
{
	m_nN = c.m_nN;
	m_ptab = new double[m_nN];
	for (int i = 0; i < m_nN; i++)
	{
		m_ptab[i] = c.m_ptab[i];
	}
	return *this;
}

CSignal CSignal::operator=(double* tab)
{
    m_nN = tab[0];
    m_ptab = new double[m_nN];
    for (int i = 1; i <= m_nN; i++)
    {
        m_ptab[i-1] = m_ptab[i];
    }
    return *this;
}

double CSignal::operator[](int)
{
    return m_ptab[i];
}

CSignal CSignal::operator*(double d)
{
    CSignal Res(m_nN);
    for (int i = 0; i < m_nN; i++)
    {
        Res.m_ptab[i] = d * m_ptab[i];
    }
    return Res;
}

CSignal CSignal::operator+(const CSignal& S)
{
    // Pour simplifier, je suppose quel les objets ont la même taille
    CSignal Res(m_nN);
    for (int i = 0; i < m_nN; i++)
    {
        Res.m_ptab[i] = m_ptab[i] + S.m_ptab[i];
    }
    return Res;
}

CSignal CSignal::operator+=(const CSignal& S)
{
    // Pour simplifier, je suppose quel les objets ont la même taille
    *this = *this + S;
    return *this;
}

CSignal CSignal::operator+=(double d)
{
    for (int i = 0; i < m_nN; i++)
    {
        m_ptab[i] = d + m_ptab[i];
    }
    return *this;
}

CSignal CSignal::operator*(const CSignal& S)
{
    // Pour simplifier, je suppose quel les objets ont la même taille
    CSignal Res(m_nN);
    for (int i = 0; i < m_nN; i++)
    {
        Res.m_ptab[i] = m_ptab[i] * S.m_ptab[i];
    }
    return Res;
}

CSignal CSignal::operator*(double d)
{
    CSignal Res(m_nN);
    for (int i = 0; i < m_nN; i++)
    {
        Res.m_ptab[i] = d * S.m_ptab[i];
    }
    return Res;
}

CSignal operator*(double d, const CSignal& S)
{
    CSignal Res(m_nN);
    for (int i = 0; i < m_nN; i++)
    {
        Res.m_ptab[i] = d * S.m_ptab[i];
    }
    return Res;
}

void CSignal::Permute(int i, int j)
{
	double temp = m_ptab[i];
	m_ptab[i] = m_ptab[j];
	m_ptab[j] = temp;
}
void CSignal::Random(int a,int b)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < m_nN; i++)
	{
		m_ptab[i] = a + (b - a)*(double)rand() / RAND_MAX;
	}
}
void CSignal::Tri_Sel()
{
	
	for (int i = 0; i < m_nN; i++)
	{
		double min = m_ptab[i];
		int index = i;
		for (int j = i; j < m_nN; j++)
		{
			if (m_ptab[j]<min)
			{
				index = j;
				min = m_ptab[index];
			}
		}
		Permute(i,index);
	}

}
void CSignal::Tri_Bulle()
{
	int order = 1;
	cout << "1 pour croissant, 2 pour decroissant: "; cin >> order;
	if((order!=1)&&(order!=2))
	{
		cout << "Saisir la valeur 1 ou 2:"; cin >> order;
	}
	if (order == 1)
	{
		for (int i = 0; i < m_nN; i++)
		{
			for (int j = (i + 1); j < m_nN; j++)
			{
				if (m_ptab[j] < m_ptab[i])
				{
					Permute(i, j);
				}
			}
		}
	}
	if (order == 2)
	{
		for (int i = 0; i < m_nN; i++)
		{
			for (int j = (i + 1); j < m_nN; j++)
			{
				if (m_ptab[j] > m_ptab[i])
				{
					Permute(i, j);
				}
			}
		}
	}
}

void CSignal::Tri_Insert()
{
	int order = 1;
	cout << "1 pour croissant, 2 pour decroissant: "; cin >> order;
	if ((order != 1) && (order != 2))
	{
		cout << "Saisir la valeur 1 ou 2:"; cin >> order;
	}
	if (order == 2)
	{
		for (int i = 0; i < m_nN; i++)
		{
			for (int j = 0; j < m_nN; j++)
			{
				if (m_ptab[j] < m_ptab[i])
				{
					Permute(i, j);
				}
			}

		}
	}
	if (order == 1)
	{
		for (int i = 0; i < m_nN; i++)
		{
			for (int j = 0; j < m_nN; j++)
			{
				if (m_ptab[j] > m_ptab[i])
				{
					Permute(i, j);
				}
			}

		}
	}
}

CSignal::~CSignal()
{
    if(m_ptab != NULL)
    {
        delete[] m_ptab;
        m_ptab = NULL;
    }
}

ostream& operator<<(ostream & os, CSignal & v)
{
	os << "La taille du tableau est: " << v.m_nN <<endl;
	os << "Les composantes sont : " << endl;
	for (int i = 0; i < v.m_nN; i++)
	{
		os << "La composante n " << i + 1 << ": " << v.m_ptab[i]<<endl;
	}
	return os;
}
