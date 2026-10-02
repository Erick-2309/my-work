#include <iostream>
using namespace std;
#include "CMat.hpp"

int main()
{
    // double tab[] = {1, 2, 3, 4, 5, 6};
    // CVect T(6, tab);
    // CVect mat[] = {T, T, T, T, T, T};
    // CMat M(6, mat);
    int num[] = {1, 2, 5};
    int den[] = {1, 2, 3};
    CRatio M(5, num, den);
    CRatio R[] = {M, M, M,M,M};
    CMatr MA(5, R);
    cin >> MA;
    cout << MA;

    return 0;
}
