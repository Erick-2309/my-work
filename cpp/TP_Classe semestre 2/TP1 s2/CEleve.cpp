#include "CEleve.hpp"

CEleve::CEleve()
: m_note(NULL), m_N(0)
{
}

CEleve::CEleve(char *nom, int N, double *note, int age)
: m_note(NULL), m_N(N),CIndividu(nom, age)
{
    if(m_N>0)
    {
        m_note=new double[N];
        for (int i = 0; i < m_N; i++)
        {
            m_note[i] = note[i];
        }
    }
}

CEleve::CEleve(const CEleve &E)
    : m_note(NULL), m_N(E.m_N), CIndividu(E)
{
    for (int i = 0; i < m_N; i++)
    {
        m_note[i] = E.m_note[i];
    }
}

CEleve::~CEleve()
{
    if (m_note != NULL)
        delete[] m_note;
}

ostream &operator<<(ostream &cout, CEleve &E)
{
    
    CIndividu *I = &E;
    cout << *I;
    for (int i = 0; i < E.m_N; i++)
    {
        cout << "note " << i + 1 << " : " << E.m_note[i]<<endl;
    }
    return cout;
}

istream &operator>>(istream &cin, CEleve &E)
{
    
    CIndividu *I = &E;
    cin >> *I;
    int N=0;
    cout<<"entrez le nombre de note: ";
    cin>>N;
    if(E.m_N!=N)
    {
        if(E.m_note!=NULL)
        delete []E.m_note;
    }
    E.m_N=N;
    
    if(E.m_N>0)
    {
        E.m_note = new double[E.m_N];
        for (int i = 0; i < E.m_N; i++)
        {
            cout << "note " << i + 1 << " : ";
            cin>>E.m_note[i];cout<<endl;
        }
    }
    else
    {
        cout<<"le nombre de note doit etre >0";
    }
    return cin;
}

