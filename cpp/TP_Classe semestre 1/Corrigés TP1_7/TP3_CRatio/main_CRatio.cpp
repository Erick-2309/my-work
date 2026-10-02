#include <iostream>
#include "CRatio.h"
using namespace std;

int main()
{
	CRatio R(2, 3);
	R.Affiche();

    CRatio ratio1(1, 2);
    CRatio ratio2(3, 4);

    cout << "Ratio 1 : ";
    ratio1.Affiche();
    std::cout << std::endl;

    cout << "Opposé de Ratio 1 : ";
    ratio1.Oppose().Affiche();
    cout << endl;
    
    // Autrement
    CRatio R11 = ratio1.Oppose();
    R11.Affiche();

    cout << "Signe de Ratio 1 : " << ratio1.Signe() << endl;

    cout << "Incrément de Ratio 1 : ";
    ratio1.Incremente().Affiche();
    cout << endl;

    cout << "Somme de Ratio 1 et Ratio 2 : ";
    ratio1.Somme(ratio2).Affiche();
    cout << endl;

    cout << "Différence de Ratio 1 et Ratio 2 : ";
    ratio1.Difference(ratio2).Affiche();
    cout << endl;

    cout << "Produit de Ratio 1 et Ratio 2 : ";
    ratio1.ProduitRatio(ratio2).Affiche();
    cout << endl;

    cout << "Produit scalaire de Ratio 1 avec 3 : ";
    ratio1.ProduitScal(3).Affiche();
    cout << endl;

    return 0;
}