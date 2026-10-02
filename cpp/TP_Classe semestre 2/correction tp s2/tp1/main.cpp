#include<iostream>
#include"CIndividu.h"
#include"CEleve.h"

int main(void)
{//je vais déclarer un objet de type CIndividu
	CIndividu toto;//appelle le constructeur par défaut
	cin >> toto;//saisi des variables
	cout << toto;//afficher le contenu des variables saisies
//je vais déclarer un objet de type CEleve
	CEleve toto2;
	cin >> toto2;
	cout << toto2;
	int N = 3;
	CEleve* mpe = new CEleve[N];
	for (int i = 0; i < N; i++)
	{
		cin >> mpe[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << mpe[i];
	}
	system("pause");
}