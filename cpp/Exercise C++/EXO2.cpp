#include<iostream>
using namespace std;

float A_F_T_F(float X) {
	return ((9.0 / 5) * X + 32);
}

int main() {
	float T;
	cout << "saisir la temperature en degré:" << endl;
	cin >> T;
	cout <<"cette temperature est égale à: "<<A_F_T_F(T)<<" farad"<< endl;
	return 0;
}