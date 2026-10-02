#include <iostream>
using namespace std;
double enso_moyen(int* tab, int n_j) //n_j nombre de jour
{
	double S_en = 0.0;
	int cpt = 0;
	for (int i = 0; i < 31; i++)
	{
		if (tab[i] != -1)
		{
			S_en += tab[i];
			cpt++;
		}
	}
	if (cpt != n_j)
		cout << "erreur dans les donnees " << endl;
	return S_en / n_j;
}

int enso_min(int* tab, int n_j)
{
	int min = tab[0];
	int cpt = 0;
	for (int i = 1; i < 31; i++)
	{
		if (tab[i] != -1)
		{
			if (min > tab[i])
			{
				min = tab[i];
			}
			cpt++;
		}
	}
	if (cpt != n_j)
		cout << "erreur dans les donnees " << endl;

	return min;
}

int enso_max(int* tab, int n_j)
{
	int max = tab[0];
	int cpt = 0;

	for (int i = 1; i < 31; i++)
	{
		if (tab[i] != -1)
		{
			if (max < tab[i])
			{
				max = tab[i];
			}
			cpt++;
		}
	}
	if (cpt != n_j)
		cout << "erreur dans les donnees " << endl;
	return max;
}

int njour_enso(int* tab, int n_j)
{
	int t = 0;  //t le nombre de jour ensoleillé
	int cpt = 0;
	for (int i = 0; i < 31; i++)
	{
		if (tab[i] != -1)
		{
			cpt++;
			if (tab[i] >= 8)
			{
				t++;
			}
		}
	}
	if (cpt != n_j)
		cout << "erreur dans les donnees " << endl;
	return t;
}

int main(void)
{
	int n_j = 1;
	int nj = 0; // numéro du jour
	int nbj = 0; // nombre de jours souhaites
	int* tab;
	tab = new int[31];
	char nom[50];
	char reponse[5];

	//initialisation de tab
	for (int i = 0;i < 31;i++)
		tab[i] = -1;

	bool verif = true;
	int a = 0; // nombre  de jour total souhaité
	cout << "Saisir le nom de la station balneaire : ";
	cin >> nom;
	do
	{
		do
		{
			cout << "Indiquer le nombre de jours que vous souhaitez saisir : ";
			cin >> nbj;
		} while ((nbj < 1) || (nbj > 31));
		a = a + nbj;

		for (int i = 0; i < nbj; i++)
		{
			cout << i + 1 << ". Quel est le(s) ou les numéro(s) du (des) jour(s) concernes: ";
			cin >> nj;
			while ((nj < 1) || (nj > 31))
			{
				cout << i + 1 << ". Le numéro du jour doit être compris entre " << 1 << " et " << 31 << "; réessayer: ";
				cin >> nj;
			}
			cout << "Saisir la valeur de l'ensoleillement du jour " << nj << ": ";
			cin >> tab[nj - 1];
		}
		cout << "Le nom de la station est : " << nom << endl;
		cout << "L'ensoleillement moyen est : " << enso_moyen(tab, a) << endl;
		cout << "L'ensoleillemnent minimum est " << enso_min(tab, a) << " et maximum " << enso_max(tab, a) << endl;
		cout << "Le nombre de journée ensoleillée est " << njour_enso(tab, a) << endl;
		if (a < 31)
		{
			cout << "Voudriez vous effectuer une nouvelle saisir: 'oui' ou non ? ";
			cin >> reponse;
			if (reponse == "oui")
				verif = true;
			else
				verif = false;
		}
	} while (verif == true);
}

