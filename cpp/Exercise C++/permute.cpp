#include <iostream>
using namespace std;

/*int permute(int &a, int &b)
{
    int t;
    t = a, a = b, b = t;
    return 0;
}
*/
/*int matrice(int **, int *, int)
{
    int n = 0;

    int **mat;
    mat = new int *[n];
    int *tab;
    tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cout << "élément " << "(" << i + 1 << "," << j + 1 << ")";
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cout << "élément " << "(" << i + 1 << "," << j + 1 << ")" << endl;
            cout << mat[i][j];
        }
    }
    return matrice(mat, tab, n);
}
*/
int main()
{
    int c = 0;
    int l = 0;
    cout << "entre le ,nombre de ligne  \n";
    cin >> l;
    cout << "entre le ,nombre de colonne   \n";
    cin >> c;
    int **mat;
    mat = new int *[l];
    int *tab;
    tab = new int[c];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; i++)
        {
            cout << "élément: " << "(" << i + 1 << "," << j + 1 << "): ";
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; i++)
        {
            cout << "élément " << "(" << i + 1 << "," << j + 1 << ")" << endl;
            cout << mat[i][j];
        }
    }

    /*int x,y,z;
    cout<<"entrez deux entiers"<<endl;
    cin>>x;
    cin>>y;
    cout<<"avant"<<endl<<"x= "<<x<<endl<<"y= "<<y<<endl;
    cout<<"après: "<<endl;
    permute(x,y);
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;

    int n = 0;
    cout << "entre la taille du tableau \n";
    cin >> n;
    int **mat;

    int *tab;
    cout << matrice(mat, tab, n);



    */
    return 0;
}
