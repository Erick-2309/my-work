#include <iostream>
using namespace std;

int s (int t, int z) {
	int s = t * z;
	return s;
}

int main(){
	int a, b;
	cout << "saisir a"<< endl;
	cin >> a;
	cout << "saisir b" << endl;
	cin >> b;
	cout << "la surfacevaut:" << s(a,b) ;
	return 0;
}


