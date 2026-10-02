#include <iostream>
#include "CEllipse.hpp"
int main()
{
    int r=1;
    int R=2;
    int*centre=new int[2];
    CEllipse E(r,R,centre),E1;
    cin>>E1;
    cout<<E1;
    E1.redimensionne(2);
    cout<<E1;
    return 0;
}
