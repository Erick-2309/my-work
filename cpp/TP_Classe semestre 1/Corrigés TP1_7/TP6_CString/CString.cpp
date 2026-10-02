  #include "CString.h"

CString::CString()
{
	m_nb = 0;
	m_tab = NULL;
}

CString::CString( char* tab)
{
	m_nb = strlen(tab);
	m_tab = new char[m_nb+1];
	strcpy_s(m_tab, m_nb+1, tab);
}

CString::CString(const CString& str)
{
	m_nb = strlen(str.m_tab);
	m_tab = new char[m_nb+1];
	strcpy_s(m_tab, m_nb+1, str.m_tab);

}

CString::~CString()
{
	if (m_tab != NULL)
	{
		m_nb = 0;
		delete [] m_tab;
		m_tab = NULL;
	}
}

CString::CString(char* tab1, char* tab2)
{
	m_nb = strlen(tab1) + strlen(tab2);
	m_tab = new char[m_nb+1];//m_nb+1 pour le caractère de fin de chaine de caractËres "\0"
	strcpy_s(m_tab,m_nb+1,tab1);
	strcat_s(m_tab, m_nb + 1,tab2);
}

CString& CString::operator=(const CString& str)
{
	m_nb = str.m_nb;
	m_tab = new char[m_nb+1];
	strcpy_s(m_tab, m_nb + 1, str.m_tab);
	return *this;
}

CString& CString::operator=(char* tab)
{
	m_nb = strlen(tab);
	m_tab = new char[m_nb+1];
	strcpy_s(m_tab, m_nb+1, tab);
	return *this;
}

CString CString::operator+=(const CString& str)
{
	CString test(m_tab, str.m_tab);
	*this = test;
	return *this;
	
}

CString CString::operator+=(char* tab)
{
	CString test(m_tab, tab);
	*this = test;
	return *this;
}

CString CString::operator+(const CString& str)
{
	CString test(m_tab, str.m_tab);
	*this = test;
	return *this;
}

CString CString::operator+(char* tab)
{
	CString test(m_tab, tab);
	*this = test;
	return *this;
}

void CString::lenght(int* L)
{
	*L = strlen(m_tab);
}

int CString::taille()
{
	return strlen(m_tab);
}

char CString::operator[](int i)
{
	return m_tab[i];
}

void CString::lire()
{
	char temp[100];
	cout << "saisir votre phrase:" << endl;
	//cin.ignore();
	cin.getline(temp, 100); 
	m_tab = new char[strlen(temp) + 1];
	strcpy_s(m_tab, strlen(temp) + 1, temp);
}

CString CString::scopy(int pos, int lng)
{
	CString test;
	test.m_nb = lng;
	test.m_tab = new char[lng + 1];
	for (int i = pos;  i <pos+lng+1; i++)
	{		
		test.m_tab[i-pos] = m_tab[i];
	}
	test.m_tab[lng] = '\0';
	return test;
}

void CString::sdelete(int pos, int lng)
{
	CString base(m_tab);
	CString part1, part2;
	part1 = base.scopy(0, pos);
	part2 = base.scopy(lng + pos, strlen(base.m_tab));
	part1 += part2;
	*this = part1;
}

void CString::sinsert(CString source, int pos)
{
	CString base(m_tab);
	CString part1, part2;
	part1 = base.scopy(0, pos);
	part2 = base.scopy( pos, strlen(base.m_tab));
	part1 += source.m_tab;
	part1 += part2;
	*this = part1;
}

short CString::spos(CString souschaine)
{
	int pos = 0;
	char* presence = strstr(m_tab, souschaine.m_tab);
	if ( presence != NULL)
	{
		pos = presence - m_tab+1;
	}

	return pos;
}

ostream& operator<<(ostream& os, const CString& str)
{	
	if (str.m_tab != NULL)
	{
		os << "la chaine de caractere est : ";
		os << str.m_tab << endl;
	}
	else
	{
		os << "la chaine est vide : ";
	}
	return os;
}

istream& operator>>(istream& is, CString& str)
{
	str.lire();
	return is;
}
