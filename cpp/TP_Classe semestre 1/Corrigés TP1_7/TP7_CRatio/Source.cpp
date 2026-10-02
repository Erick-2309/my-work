#include"CRatio.h"

int main()
{
	CRatio r1(-1,2);
	CRatio r2(-r1);
	cout << &r2<<endl;
	++r1;
	CRatio r3 = r1 + r2;
	CRatio r4 = r1 - r2;
	CRatio r5 = r1 * r2;
	CRatio r6 = 2 * r2;
	CRatio r7 = r2 * 2;
	CRatio r8 ;
	cin >> r8;
	cout << r1 << r2 << r3 << r4 << r5 << r6 << r7<<r8;
}