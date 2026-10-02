#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class CString
{
private:
	int m_nb;
	char* m_tab;
public:
	CString( );
	CString( char* t);
	CString(const CString& a);
	~CString();
	CString(char* tab1, char* tab2);
	CString& operator=(const CString& str);
	CString& operator=( char* t);
	CString operator+=(const CString& str);
	CString operator+=( char* t);
	CString operator +(const CString& tab);
	CString operator +(char* str);
	friend istream& operator>>(istream& is, CString& a);
	friend ostream& operator<<(ostream& os,const CString& a);
	void lenght(int* a);
	int taille();
	char operator [](int i);
	void lire();
	CString scopy(int pos, int lng);
	void sdelete(int pos, int lng);
	void sinsert(CString source, int pos);
	short spos(CString souschaine);
};

