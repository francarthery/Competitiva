#include <iostream>
#include <array>

using namespace std;

int main() {
	
	//Declarar array
	int LISTA[10];
	int N;
	
	for(int i=0; i<=9; i++){
		cin >> N;
		if(N>0)
			LISTA[i]=N;
		else
			LISTA[i]=1;}
	
	for(int i=0; i<=9; i++){
		cout << "X[" << i << "] = " << LISTA[i] << endl;
	
	}
	//Con bucle for usar i como ìndice y agregar 10 valores
	//Si el valor es >0 colocar valor real. Sino colocar 1.
	
	return 0;
}