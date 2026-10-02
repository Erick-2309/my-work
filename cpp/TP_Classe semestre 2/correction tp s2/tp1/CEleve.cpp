#include "CEleve.h"

CEleve::CEleve(): CIndividu(), m_nbNote(0), m_note(NULL)
{//initialise tout à 0
}

CEleve::CEleve(char* nom, int age, int nb_Note, double* notes):CIndividu(nom,age), m_nbNote(nb_Note)//le nbre de notes
{
	//je réserve pour le tableau de notes
	m_note = new double[m_nbNote];
	for (int i = 0; i < nb_Note; i++)
	{
		m_note[i] = notes[i];
	}
}

CEleve::CEleve(const CEleve& E) : CIndividu(E),m_nbNote(E.m_nbNote)
{
	m_note = new double[m_nbNote];
	for (int i = 0; i < m_nbNote; i++)
	{
		m_note[i] = E.m_note[i];
	}
}

CEleve::~CEleve()
{
	if (m_note != NULL)
	{
		delete[] m_note;
		m_note = NULL;
	}
}

istream& operator >> (istream& is, CEleve& I)
{
	 CIndividu* O=&I;//on récupère l'adresse de l'objet I de type CEleve
	 is >> *O;//on réutilise l'opérateur d'insertion de CIndividu
	cout << "saisir le nombre de notes:" << endl;
	is >> I.m_nbNote;
	cout << endl;
	//réservation de l'espace mémoire
	if (I.m_note != NULL)
	{
		delete[] I.m_note; 
		I.m_note = NULL;
	}
	I.m_note = new double[I.m_nbNote];
	//saisi des notes
	for (int i = 0; i < I.m_nbNote; i++)
	{
		cout << "entrer la " << i + 1 << "note" << endl;
		is >> I.m_note[i];
		cout << endl;
	}

	return is;
}
ostream& operator << (ostream& os, CEleve& test)
{
	 CIndividu* ind=&test; //on récupère l'adresse de l'objet O de type CEleve
	 os << *ind; //on réutilise l'opérateur d'extraction de CIndividu
	os << "le nombre de note est :" << test.m_nbNote << endl;
	for (int i = 0; i < test.m_nbNote; i++)
	{
		os << "la note " << i + 1 << "est :" << test.m_note[i] << endl;
	}
	return os;
}