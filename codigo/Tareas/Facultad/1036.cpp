#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float raices(float A, float B, float C, bool signo);

int main() {
	
	float A, B, C;
	
	cin >> A >> B >> C; 
	
	if(A == 0 or (pow(B, 2) - 4*A*C) < 0)
		cout << "Impossivel calcular" << endl;
	else{
		cout << "R1 = " << fixed << setprecision(5) << raices(A, B, C, true) << endl;
		cout << "R2 = " << raices(A, B, C, false) << endl;
	}
	
	return 0;
}

float raices(float A, float B, float C, bool signo){
	float discriminante = -(sqrt(pow(B, 2) - 4*A*C));

	if (signo == true)
		discriminante = abs(discriminante);

	return (-B + discriminante) / (2 * A);
}


