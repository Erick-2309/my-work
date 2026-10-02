#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class CFlx
{
private:
    char*m_nom;
    fstream* m_fr;
public:
    CFlx(char*);
};
