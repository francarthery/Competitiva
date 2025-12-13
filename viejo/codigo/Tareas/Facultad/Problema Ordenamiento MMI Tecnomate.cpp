#include <iostream>
using namespace std;

#define TAM 1000

int main(int argc, char *argv[]) {
	
	int N, contador = 0, pases = 0, aux;
	
	cin >> N;
	
	int lista[TAM];
	
	for(int i = 0; i < N; i++){
		cin >> lista[i];
	}
	
	while(contador < N - 1){
		for(int i = 0; i < N - 1; i++){
			if(lista[i] > lista[i + 1]){
				contador = 0;
				pases++;
				aux = lista[i];
				lista[i] = lista[i + 1];
				lista[i + 1] = aux;
			}
			contador++;
		}
	}
	
	cout << pases << endl;
	
	for(int i = 0; i < N; i++){
		cout << lista[i] << " ";
	}
	
	return 0;
}

