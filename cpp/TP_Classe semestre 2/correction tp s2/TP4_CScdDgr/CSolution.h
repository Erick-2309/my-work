#pragma once
#include<iostream>
using namespace std;

class CSolution
{
public:
	CSolution();
	virtual void Affiche()=0; // Fonction virtuelle pure qui rend la classe abstraite
	virtual ~CSolution();
};


