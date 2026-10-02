#include <iostream>
using namespace std;
#pragma once
class CRatio
{
private:
    int m_NB;
    int *m_num;
    int *m_den;

public:
    CRatio();
    CRatio(int, int *, int *);
    CRatio(const CRatio &);
    ~CRatio();
    CRatio operator=(const CRatio &);
    CRatio operator+(const CRatio &);
    CRatio operator[](int);
    friend ostream &operator<<(ostream &, const CRatio &);
    friend istream &operator>>(istream &, CRatio &);
};
