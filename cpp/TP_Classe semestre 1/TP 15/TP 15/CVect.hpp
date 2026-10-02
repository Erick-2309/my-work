#include <iostream>
using namespace std;
#pragma once
class CVect
{
private:
    int m_N;
    double *m_ptab;

public:
    CVect();
    CVect(int, double *);
    CVect(const CVect &);
    ~CVect();
    CVect operator=(const CVect &);
    CVect operator+(const CVect &);
    double operator[](int);
    friend ostream &operator<<(ostream &, const CVect &);
    friend istream &operator>>(istream &, CVect &);
};
