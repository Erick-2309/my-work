#include "CIndividu.h"

CIndividu::CIndividu():m_nom(NULL), m_age(0)
{
}

CIndividu::CIndividu(char* nom, int age) : m_age(age)
{
	//m_nom=NULL,donc je dois réserver la place mémoire
	m_nom = new char[strlen(nom) + 1];//strlen longueur chaine caractère
	//on copie
	strcpy_s(m_nom, strlen(nom) + 1, nom);//on met le nom dans le tableau
	//pour un entier
}

CIndividu::~CIndividu()
{
	if (m_nom != NULL)
	{
		delete m_nom;
		m_nom = NULL;
	}
}

CIndividu::CIndividu(const CIndividu& Indi):m_age(Indi.m_age)
{
	m_nom = new char[strlen(Indi.m_nom) + 1];
	strcpy_s(m_nom, strlen(Indi.m_nom) + 1, Indi.m_nom);
}

istream& operator >> (istream& is, CIndividu& I)
{
	cout << "Entrer le nom de l'individu" << endl;
	char* temp;
	temp = new char[50];
	is >> temp;
	I.m_nom = new char[strlen(temp) + 1];//prend la classe I et son attribut
	strcpy_s(I.m_nom, strlen(temp) + 1, temp);
	cout << "Entrer son age:" << endl;
	is >> I.m_age;
	if (temp != NULL)
	{
		delete[]temp;
	}
	return is;
}

ostream& operator << (ostream& os, const CIndividu& O)
{
	os << "le nom de l'individu est :" << O.m_nom << endl;
	os << "son age est:" << O.m_age << endl;
	return os;
}