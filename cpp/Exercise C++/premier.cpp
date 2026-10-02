#include <iostream>
using namespace std;

int est_premier(int a, int &ind)
{
    bool premier = true;
    int i = 2;
    // while (i<a && premier == true)
    for (i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            premier = false;
            ind = i;
        }
        // i++;
    }

    return premier;
}

int main()
{
    int b = 0;
    int c = 0;
    cout << "entrez un entier " << endl;
    cin >> b;
    if (est_premier(b, c) == true)
    {
        cout << b << " est premier  " << endl;
        // cout << 1 << endl;
    }
    else
        cout << b << " n'est pas premier " << endl;
    cout << "il est divisible par " << c << endl;
    return 0;
}
