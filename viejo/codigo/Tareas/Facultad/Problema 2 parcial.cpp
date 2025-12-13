#include <iostream>
using namespace std;

#define TAM 25

double promedioProcesamiento(double [], int);
bool procesadorDanado(double tiempos[]);

int main(int argc, char *argv[]) {
	
	double tiempos[25];
	
	for(int i = 0; i < TAM; i++)
		cin >> tiempos[i];
	
	cout << "El promedio de tiempos de procesamiento es: " << promedioProcesamiento(tiempos, TAM) << endl;
	if(procesadorDanado(tiempos))
		cout << "El procesador esta dañado" << endl;
	else
		cout << "El procesador esta optimo" << endl;
	
	return 0;
}

double promedioProcesamiento(double tiempos[], int contador){
	
	if(contador == 0) return 0;
	else return (tiempos[contador - 1] / 25.0) + promedioProcesamiento(tiempos, --contador);
}
	
bool procesadorDanado(double tiempos[]){
	
	bool igual = false;
	int contador = 0, max_cont = 0;
	
	
	for(int i = 0; i < TAM - 1; i++){
		if(tiempos[i] == tiempos[i + 1]){
			if(igual){
				contador++;
				if(contador > max_cont)
					max_cont = contador;
			}
			else{
				igual = true;
				contador = 1;
			}
		}
		else
			igual = false;
	}
	return max_cont;
}
