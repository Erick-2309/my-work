#include <iostream>
#include "CVect.hpp"
#include "CRAtio.hpp"
using namespace std;

/*class CMat
{
private:
    int m_NO;
    CVect *m_vect;

public:
    CMat();
    CMat(int, CVect *);
    CMat(const CMat &);
    ~CMat();
    CMat operator=(const CMat &);
    CMat operator+(const CMat &);
    CVect operator[](int);
    friend ostream &operator<<(ostream &, const CMat &);
    friend istream &operator>>(istream &, CMat &);
};*/

class CMatr
{
private:
    int m_NO;
    CRatio *m_ratio;

public:
    CMatr(int);
    CMatr(int, CRatio *);
    CMatr(const CMatr &);
    ~CMatr();
    CMatr operator=(const CMatr &);
    CMatr operator+(const CMatr &);
    CRatio operator[](int);
    friend ostream &operator<<(ostream &, const CMatr &);
    friend istream &operator>>(istream &, CMatr &);
};
