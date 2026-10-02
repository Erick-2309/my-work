#include <iostream>
using namespace std;

double moyenne(double* tab) {
	double result = 0;
	int compteur = 0;
	for (int i = 0; i < 31; i++) {
		if(tab[i]!=-1){
			result += tab[i];
			compteur++;
		}
	}
	result /= compteur;
	return result;
}

double max(double* tab) {
	double max = tab[0];
	for (int i = 0; i < 31; i++) {
		if (max < tab[i]) {
			max = tab[i];
		}
	}
	return max;
}

double min(double* tab) {
	double min = tab[0];
	for (int i = 0; i < 31; i++)
    {//on prend une valeur saisie (différente de -1) pour le première valeur de min
		if (tab[i] != -1) {
			min = tab[i];
			break;
		}
	}

	for (int i = 0; i < 31; i++) {
		if (min > tab[i] && tab[i] != -1) {
			min = tab[i];
		}
	}
	return min;
}

int nb_jours_ensoleilles(double* tab) {
	int nb_jours_soleil = 0;
	for (int i = 0; i < 31; i++) {
		if (tab[i]>8) {
			nb_jours_soleil++;
		}
	}
	return nb_jours_soleil;
}

void main() {

	//Saisie nom station balnéaire
	char temp[256];
	cout << "Saisir le nom de la station : ";
	cin >> temp;

	char* nom_station = new char[strlen(temp) + 1];
	strcpy_s(nom_station, strlen(temp) + 1, temp);

	//Saisie valeurs ensoleillement
	int premier_jour, nb_jours;
	double* tab = new double[31];
	for (int i = 0; i < 31; i++) { tab[i] = -1; } //on initialise le tableau avec -1 dans chaque case pour pouvoir différencier les jours saisis des jours non saisis
	bool continuer=true;

	while (continuer == true) {
		cout << "Saisir le premier jour de saisie : ";
		cin >> premier_jour;

		while (premier_jour > 31 && premier_jour <= 0) {//on verifie qu'il n'y a pas d'erreur dans la saisie
			cout << "La saisie est incorrecte, veuillez saisir le premier jour de nouveau : ";
			cin >> premier_jour;
		}

		premier_jour -= 1; //on part du principe que l'utilisateur considère le premier jour comme le jour 1
		cout << "Saisir la duree a saisir : ";
		cin >> nb_jours;

		while (nb_jours + premier_jour > 31) {//on verifie qu'il n'y a pas d'erreur dans la saisie
			cout << "La saisie est incorrecte, veuillez saisir le nombre de jours de nouveau : ";
			cin >> nb_jours;
		}

		for (int i = premier_jour; i < nb_jours + premier_jour; i++) {
			if (tab[i] != -1) { //on regarde le cas où une case a déjà été remplie
				cout << "Vous allez ecraser une donnee deja saisie, voulez-vous continuer ? oui:1 / non:0\n";
				cin >> continuer;
				if (continuer == true) {//on saisi une valeur écrasant l'ancienne valeur, sinon on ne fait rien (on garde l'ancienne valeur)
					cout << "Saisir la valeur du jour : ";
					cin >> tab[i];
					while (tab[i] > 24 || tab[i] < 0) {//on vérifie que la valeur saisie est bien positive et inférieur à 24h
						cout << "Saisie incorrecte, veuillez saisir la valeur de nouveau : ";
						cin >> tab[i];
					}
				}
			}
			else {//cas où la valeur n'a pas été saisie au préalable
				cout << "Saisir la valeur du jour : ";
				cin >> tab[i];
				while (tab[i] > 24 || tab[i] < 0) {//on vérifie que la valeur saisie est bien positive et inférieur à 24h
					cout << "Saisie incorrecte, veuillez saisir la valeur de nouveau : ";
					cin >> tab[i];
				}
			}
		}

		cout << "Voulez-vous saisir d'autres valeurs ? oui:1 / non:0\n";
		cin >> continuer;
	}
	//on fois le remplissage terminé, on teste les fonctions
	cout << "La station balneraire est : " << nom_station << endl;
	cout << "Ensoleillement moyen : " << moyenne(tab) << endl;
	cout << "Ensoleillement min : " << min(tab) << endl;
	cout << "Ensoleillement max : " << max(tab) << endl;
	cout << "Nombre de jours ensoleilles : " << nb_jours_ensoleilles(tab);
}
