#include<iostream>
using namespace std;

double moyenne(double* tab, int N)
{

	int somme = 0;
	for (int i = 0; i < N; i++)
	{
		somme += tab[i];
	}
	return somme / N;
}
int main()
{
	int A = 0;
	//int N;
	double* tab;
	tab =new double [A];
	cout << "saisir un entier\n";
	cin >>A;
	
	for (int i = 0; i < A; i++)
	{
		cout << "saisir les valeurs\n";
		cin >> tab[i];
	}

	cout << "la moyenne vaut:" << moyenne(tab,A) << endl;
	return 0;

}
/*
double moyenne(double tab[], int N)
{

	int somme = 0;
	for (int i = 0; i < N; i++)
	{
		somme += tab[i];
	}
	return somme / N;
}
int main()
{
	int A;
	double tab[5];
	cout << "saisir un entier(taille du tableau)\n";
	cin >>A;
	
	for (int i = 0; i < A; i++)
	{
		cout << "saisir les valeurs du tableau\n";
		cin >>tab[i];
	}

	cout << "la moyenne vaut:" << moyenne(tab,A) << endl;
	return 0;

}
*/