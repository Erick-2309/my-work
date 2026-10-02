#include<iostream>
#include <cstring>
using namespace std;

class CString
{
private:
    long m_N;
    char* m_str;
public:
    CString();
    CString(long=0);
    CString( long , char*);
    CString( char*, char*);
    ~CString();
    friend ostream& operator<<(ostream&, const CString&);
    void lire();
    friend istream& operator>>(istream&, CString&);
    CString(const CString&);
    CString operator=(const CString&);
    CString operator=(char*);
    CString operator+=(const CString&);
    CString operator+=(char*);
    void length(long *);
    long taille();
    int operator[](int);
    CString operator+(const CString&);
    CString operator+(char*);
    CString scopy (int , long );
    void sdelete (int , int );
    void sinsert (CString , int);
    short spos (CString);
};
