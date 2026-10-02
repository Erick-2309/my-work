#include <iostream>
using namespace std;

/*int est_premier(int a)
{
    bool premier =true;
    int i=2;
    while(i<a && premier==true)
   // for(i=2;i<a;i++)
    {
        if (a%i==0)
        {
            premier =false;
        }
        i++;
    }
    return premier;
}
int main()
{
    int x;
    cout<<"entrez un entier:\n"<<endl;
    cin>>x;
    if (est_premier(x)==true)
    {
        cout<<x<<" est premier\n"<<endl;
    }
    else
        cout<<x<<" n'est pas premier\n"<<endl;

    return 0;
}*/

/*int permute(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
    return 0;
}
*/
int factoriel(int c)
{
    int res = 1;
    for (int i = 1; i <= c; i++)
    {
        res = res * i;
    }
    return res;
}

int main()
{
    /*int i, j;
    i = 2;
    j = 5;
    cout << "avant:\n";
    cout << "i=" << i << endl;
    cout << "j=" << j << endl;
    permute(i, j);
    cout << "après:\n";
    cout << "i=" << i << endl;
    cout << "j=" << j << endl;
*/
    int k;
    k = 10;
    cout << factoriel(k);

    return 0;
}
