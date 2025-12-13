#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double euler(double aux, int contador);
int factorial(int N);

int main(int argc, char *argv[]) {
	
	double aux;
	
	cin >> aux;
	
	cout << fixed << setprecision(10) << euler(aux, 1) << endl;
	
	return 0;
}

double euler(double aux, int contador){
	
	double termino = pow(contador, 2) / (2 * factorial(contador));
	
	if(aux > termino) return 0;
	else return termino + euler(aux, contador + 1);
}
	
	int factorial(int N){
		
		if(N == 0) return 1;
		else return N * factorial(N - 1);
	}
		
