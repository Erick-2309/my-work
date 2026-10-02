
#include "CIndividu.hpp"


class CEleve : public CIndividu
{
private:
    double *m_note;
    int m_N;

public:
    CEleve();
    CEleve(char *, int, double *, int);
    CEleve(const CEleve &);
    ~CEleve();
    friend ostream& operator<<(ostream&,CEleve&);
    friend istream& operator>>(istream&,CEleve&);
};


