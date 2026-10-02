#include "ecrfic.h"

void main (void)
{
	CVect V(5), V1, V2, V3(3), V4, V5;
	V.Remplir();
	V3.Remplir();
	cout << V;

	// flux texte
	V.Ecrit("c:\temp\toto.txt");
	V1.Lit("c:\temp\toto.txt");
	cout << "lecture en mode texte " << endl;
	cout << V1 << endl << endl;

	// flux binaire
	V.Ecrit_Bin("c:\temp\toto1.bin");
	V2.Lit_Bin("c:\temp\toto1.bin");
	cout << "lecture en mode binaire" << endl;
	cout << V2;

	// ajout mode text
	V3.Add_Flux("c:\temp\toto.txt");
	cout << V3;
	V4.Lit("toto.txt");
	cout << V4;

	// ajout mode binaire
	V3.Add_Flux("c:\temp\toto1.bin");
	V5.Lit_Bin("c:\temp\toto1.bin");
	cout << V5;

}