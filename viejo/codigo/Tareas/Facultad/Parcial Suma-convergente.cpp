#include <iostream>
#include <iomanip>
using namespace std;

int MayorMultiplode3o5Impar(int num);

float Sumatoria(float E);

int main(int argc, char *argv[]) {
	
	float E;
	
	cin >> E;
	
	cout << fixed << setprecision(7) << endl;
	cout << "SA=" << Sumatoria(E) << endl;
	
	return 0;
}

int MayorMultiplode3o5Impar(int num){
	
	if(num == 1) return 2;
	else{
		if(num % 3 == 0 or num % 5 == 0) return num;
		else return MayorMultiplode3o5Impar(num - 2);
	}
}

float Sumatoria(float E){
	float rta = 1;
	int num = 2;
	double termino = 1.0 / MayorMultiplode3o5Impar(num - 1);
	
	while(termino >= E){
		rta += termino;
		num *= 2;
		termino = 1.0 / MayorMultiplode3o5Impar(num - 1);
	}
	
	return rta;
}

