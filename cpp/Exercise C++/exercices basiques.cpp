#include <iostream>
using namespace std;



//---------------------------EXERCICE 1-----------------------------



int* init_tab(int* tab1, int n) {
    cout << "Tableau :\n";
    for (int i = 0; i < n; i++) {
        tab1[i] = i;
        cout << "Case " << i << " : " << tab1[i] << endl;
    }
    int* tab2 = new int[n];
    cout << "\nTableau inverse:\n";
    for (int i = 0; i < n; i++) {
        tab2[i] = tab1[n-1-i];
        cout << "Case " << i << " : " << tab2[i] << endl;
    }
    return tab2;
}

double moyenne(int* tab, int n) {
    double moyenne = 0;
    for (int i = 0; i < n; i++) {
        moyenne += tab[i];
    }
    return moyenne / n;
}

void main() {
    int* tab1=new int[11];
    cout << "\nMoyenne : " << moyenne(init_tab(tab1, 11), 11);

}


/*
//-----------------------------EXERCICE 2-----------------------------------



char* saisie() {
    char temp[256];
    cout << "Saisir un nom : ";
    cin >> temp;
    char* tab = new char[strlen(temp)+1];
    strcpy_s(tab, strlen(temp) + 1, temp);
    cout << tab << endl;
    return tab;
}

char* modif(char* tab) {
    
    char temp[256];
    cout << "Modifier le nom : ";
    cin >> temp;
    tab = new char[strlen(temp) + 1];
    strcpy_s(tab, strlen(temp) + 1, temp);
    return tab;
}

void nombre(char* tab) {
    int len = strlen(tab);
    cout << "Longueur : " << len << endl;
    
    char test[26];
    bool deja_fait = false;
    int compteur;
    for (int i = 0; i < len; i++)
    {
        compteur = 0;
        for (int j = 0; j < 27; j++)
        {
            if (test[j] == tab[i])
                deja_fait = true;
        }
        if (deja_fait == false)
        {
            for (int j = 0; j < len; j++)
            {
                if (tab[j] == tab[i])
                    compteur++;
            }
            cout << "Il y a " << compteur << " '" << tab[i] << "' dans " << tab<<".\n\n";
            test[i] = tab[i];
        }
        deja_fait = false;
    }
}

void main() {
    nombre(modif(saisie()));
}



//-----------------------------EXERCICE 3-----------------------------------



bool comp(int* tab1, int* tab2, int n1, int n2) {
    bool result = true;
    if (n1 == n2) {
        for (int i = 0; i < n1; i++) {
            if (tab1[i] != tab2[i]) {
                result = false;
                break;
            }
        }
    }
    else
        result = false;
    return result;
}

int* random(int* tab, int n) {
    int min = tab[0], max = tab[0];
    //min
    for (int i = 0; i < n; i++) {
        if (min > tab[i])
            min = tab[i];
    }
    cout << "Minimum : " << min << endl;
    //max
    for (int i = 0; i < n; i++) {
        if (max < tab[i])
            max = tab[i];
    }
    cout << "Maximum : " << max << endl;
    //rand
    for (int i = 0; i < n; i++) {
        tab[i] = (int)(((double)rand() / RAND_MAX) * (max - min) + min);
    }
    return tab;
}

void main() {
    int n1, n2;
    //tab1
    cout << "Longueur du tableau 1? ";
    cin >> n1;
    int* tab1 = new int[n1];
    for (int i = 0; i < n1; i++) {
        cout << "\nCase " << i + 1 << " ? ";
        cin >> tab1[i];
    }
    //tab2
    cout << "\n\nLongueur du tableau 2? ";
    cin >> n2;
    int* tab2 = new int[n2];
    for (int i = 0; i < n2; i++) {
        cout << "\nCase " << i + 1 << " ? ";
        cin >> tab2[i];
    }
    if (comp(tab1, tab2, n1, n2) == true)
        cout << "Victoire !!!";
    else
        cout << "Defaite :,(";
    cout << endl << endl << "Tableau 1 :\n";
    for (int i = 0; i < n1; i++) {
        cout << tab1[i] << endl;
    }
    cout << endl << endl;
    int* tab3 = new int[n1];
    tab3 = random(tab1, n1);
    cout << endl << "Tableau aleatoire compris entre min et max :\n";
    for (int i = 0; i < n1; i++) {
        cout << tab3[i] << endl;
    }
}



//-----------------------------EXERCICE 4-----------------------------------



bool palindrome(char* tab, int n) {
    bool test = true;
    for (int i = 0; i < n; i++) {
        if (tab[i] != tab[n - 1 - i])
            test = false;
    }
    return test;
}

void main() {
    char temp[256];
    cout << "Saisir le mot : ";
    cin >> temp;

    char* tab = new char[strlen(temp) + 1];
    for (int i = 0; i < strlen(temp); i++) {
        tab[i] = temp[i];
    }

    if (palindrome(tab, strlen(temp)))
        cout << "C'est un palindrome.";
    else
        cout << "Ce n'est pas un palindrome.";
}

//-----------------------------FONCTION SWAP-----------------------------------

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void main() {
    int a = 0, b = 1;
    swap(a, b);
    cout << a << b;
}*/

