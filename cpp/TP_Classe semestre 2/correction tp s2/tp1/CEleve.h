#pragma once
#include"CIndividu.h"
//héritage réutilise les propriétés de la classe de base dans classe dérivée
class CEleve : public CIndividu
{
private:
	// tableau de double(les notes)
	double* m_note;
	// nombre de notes
	int m_nbNote;
public:
	CEleve();//Constructeur par défaut
	CEleve(const CEleve& E);
	CEleve(char* nom, int age, int nb_Note, double* notes);//Constructeur avec nom,âge,nb de notes et notes
	~CEleve();//destructeur par défaut
	//fonction amie pour la surcharge d'opérateurs
	friend istream& operator >> (istream& is, CEleve& I);
	friend ostream& operator <<(ostream& os, CEleve& O);
};

