#include <iostream>
#include <array>

using namespace std;

int main() {
	
	int N, contador=0;
	int LISTA[1000];
	
	cin >> N;
	
	for(int i=0; i<=999; i++){
		if(contador==(N))
			contador=0;
		LISTA[i]=contador;
		contador++;}
	
	for(int i=0; i<=999; i++){
		cout << "N[" << i << "] = " << LISTA[i] << endl;}
	
	return 0;
}