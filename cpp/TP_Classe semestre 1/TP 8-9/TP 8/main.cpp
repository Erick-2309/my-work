#include<iostream>
using namespace std;
#include "CString.hpp"


int main()
{
    char* st;
    st=new char[5];
    int A = 5;
    A=strlen("hello");
    strcpy(st,"hello");
    CString test(30),test2(30),test3(5,st);
    //cout<<test3 <<endl;
    cin>>test;
    cin>>test2;

    test += test2;
   // test.sinsert(test3,2);
    cout << test << endl;
    //cout << test2 + test << endl;
   // long pos=test.spos(test2);
   //cout <<"la position est :"<<pos << endl;
  
  
    return 0;
}
