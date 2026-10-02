#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class CIndividu
{
private:
	// nom de l'individu
	char* m_nom;
	// age de l'individu
	int m_age;
public:
	CIndividu();//Constructeur par défaut
	CIndividu(char* nom, int age);//Constructeur avec nom et age
	~CIndividu();//destructeur par défaut
	//fonctions amies pour la surcharge d'opérateur
	friend istream& operator >> (istream& is, CIndividu& I);//"&" transmission par référence
	friend ostream& operator <<(ostream& os, const CIndividu& O);
	CIndividu(const CIndividu& Indi);//constructeur de copie
};
