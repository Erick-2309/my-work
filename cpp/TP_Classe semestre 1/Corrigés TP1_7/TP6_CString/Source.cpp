#include"CString.h"
int main()
{
	CString test;
	cin>>test;
	CString test2;
	 cin>>test2;
	cout << test<<endl;
	cout << test2 << endl;
	test += test2;
	cout << test << endl; 
	cout << test2 << endl;
	CString test11;
	cin >> test11;
	cout << test11 << endl;
	CString test12;
	cin >> test12;
	cout << test12<<endl;
	int pos=test11.spos(test12);
	cout << "la position dans la chaine de caractere est: "<<pos<<endl;

	system("pause");
	return 0;
}
