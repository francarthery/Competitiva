#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int A, B, C, X;
	double Y;
	
	cin >> A >> B >> C;
	
	if (A > B and A > C)
		X = A;
	else if(B > C)
		X = B;
	else
		X = C;
	
	X = X % 100;
	Y = (X % 10 + X / 10) / 18.0;
	
	if (0.1 < Y and Y < 0.12)
		cout << "Suma de digitos = 2" << endl;
	else if(Y < 0.04)
		cout << "Suma de digitos = 0" << endl;
	else if(Y > 0.999)
		cout << "Suma de digitos = 18" << endl;
	else
		cout << "Otro caso!" << endl;
	
	return 0;
}

