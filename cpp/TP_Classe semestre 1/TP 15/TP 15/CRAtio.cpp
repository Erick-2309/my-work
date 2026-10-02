#include "CRAtio.hpp"
#include <iostream>
using namespace std;

CRatio::CRatio()
    : m_den(NULL), m_num(NULL), m_NB(0) {}

CRatio::CRatio(int N, int *num, int *den)
    : m_den(NULL), m_num(NULL), m_NB(N)
{
    if (m_NB > 0)
    {
        m_den = new int[N];
        m_num = new int[N];
        for (int i = 0; i < m_NB; i++)
        {
            m_num[i] = num[i];
            m_den[i] = den[i];
        }
    }
}

CRatio::CRatio(const CRatio &R)
    : m_den(NULL), m_num(NULL), m_NB(R.m_NB)
{
    if (R.m_NB > 0)
    {
        m_den = new int[R.m_NB];
        m_num = new int[R.m_NB];
        for (int i = 0; i < R.m_NB; i++)
        {
            m_num[i] = R.m_num[i];
            m_den[i] = R.m_den[i];
        }
    }
}

CRatio::~CRatio()
{
    if (m_den != NULL)
        delete[] m_den;
    if (m_num != NULL)
        delete[] m_num;
}

CRatio CRatio::operator=(const CRatio &R)
{
    if (this != &R)
    {
        if (m_NB != R.m_NB)
        {
            delete[] m_den;
            delete[] m_den;
            m_NB = R.m_NB;
            if (R.m_NB > 0)
            {
                m_num=new int[m_NB];
                m_den=new int[m_NB];
                for (int i = 0; i < R.m_NB; i++)
                {
                    m_num[i] = R.m_num[i];
                    m_den[i] = R.m_den[i];
                }
            }
        }
    }
    return *this;
}

CRatio CRatio::operator+(const CRatio &R)
{
    int *N;
    int *D;
    N = new int[m_NB];
    D = new int[m_NB];
    CRatio(m_NB, N, D);
    for (int i = 0; i < m_NB; i++)
    {
        N[i] = m_num[i] * m_den[i + 1] + m_den[i] * m_num[i + 1];
        D[i] = m_den[i] * m_den[i + 1];
    }

    return CRatio(1, N, D);
}

ostream &operator<<(ostream &cout, const CRatio &R)
{
    for (int i = 0; i < R.m_NB; i++)
    {
        cout << R.m_num[i] <<"/" <<R.m_den[i] <<" ";
    }
    return cout;
}

istream &operator>>(istream &cin, CRatio &R)
{
    int N=0;
    cout << "nombre de ratio: ";
    cin >> N;

    if (R.m_NB != N)
    {
        delete[] R.m_den;
        delete[] R.m_den;
    }
    R.m_NB = N;
    if (R.m_NB > 0)
    {
        R.m_num=new int[R.m_NB];
        R.m_den=new int[R.m_NB];
        for (int i = 0; i < R.m_NB; i++)
        {
            cout<<"numerateur"<<"("<<i+1<<"): ";
            cin >> R.m_num[i];
            cout<<"denominateur"<<"("<<i+1<<"): ";
            cin >> R.m_den[i];
        }
    }
    return cin;
}
