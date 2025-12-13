#include <iostream>
#include <iomanip>
using namespace std;

double euler(double aux, int contador);
int factorial(int N);

int main(int argc, char *argv[]) {
	
	double aux;
	
	cin >> aux;
	
	cout << fixed << setprecision(10) << euler(aux, 0) << endl;
	
	return 0;
}

double euler(double aux, int contador){
	
	double fact = 1.0 / factorial(contador);
	
	if(aux > fact) return 0;
	else return fact + euler(aux, contador + 1);
}

int factorial(int N){
	
	if(N == 0) return 1;
	else return N * factorial(N - 1);
}
