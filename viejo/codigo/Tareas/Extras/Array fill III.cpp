#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
	
	double N, contador=0;
	double LISTA[100];
	
	cin >> N;
	
	for(int i=0; i<=99; i++){
		LISTA[i]=N;
		N/=2;}
	
	for(int i=0; i<=99; i++){
		cout << "N[" << i << "] = " << fixed << setprecision(4) << LISTA[i] << endl;}
	
	return 0;
}