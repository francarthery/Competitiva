#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	string cadena;
	
	int N, max = 0;
	string candidatos[1000];
	int cantidades[1000] = {0};
	
	cin >> cadena;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> candidatos[i];
	}
	
	for(int i = 0; i < N; i++){
		string cad = cadena;
		
		while(cad.find(candidatos[i]) <= cad.length()){
			cantidades[i]++;
			cad.erase(cad.find(candidatos[i]), 1);
		}
		
		if(cantidades[i] > max)
			max = cantidades[i];
		
	}

	for(int i = 0; i < N; i++){
		if(cantidades[i] == max)
			cout << candidatos[i] << endl;
	}
	
	
	return 0;
}

