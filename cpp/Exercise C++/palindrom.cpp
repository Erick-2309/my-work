#include <iostream>
using namespace std;

/*int palindrome(char* ch)
{
	int debut = 0;
	int A = strlen(ch);
	int fin = A - 1;
	while (debut < fin)
	{
		if (ch[debut] !=ch[fin])
		{
			return 0;
		}

		debut += 1;
		fin -= 1;
	}
	return 1;
}*/

int palindrome(char *mot)
{
	bool test = true;
	int N = strlen(mot);
	// mot =new char[N+1];
	for (int i = 0; i < N; i++)
	{
		if (mot[i] != mot[N - 1 - i])
		{
			test = false;
		}
	}
	return test;
}

int main()
{
	char mot[256];
	//char*mot;
	// int N = 256;
	// mot = new char[N+1];  //pour un tableau dynamique
	cout << "entrez un mot" << endl;
	cin >> mot;
	cout << palindrome(mot);
	if (palindrome(mot))
	{
		cout << " c'est un palindrome\n";
	}
	else
	{
		cout << " c'est pas un palindrome\n";
	}
	return 0;
}

/*if (strlen(mot)>7)
	{
		cout<<"la longueur de votre mot est superieur a la taille du tableau\n";
	}
	*/
