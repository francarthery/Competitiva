#include "Pila.h"
#include <iostream>

using namespace std;

void generarTextoOriginal(Oracion texto[], Pila pila1);
void ordenar_oraciones(Oracion texto[]);
void intercambiar(Oracion &X, Oracion &Y);

int main(){
	
	Pila pila1;
	
	Oracion texto[100];
	
	generarTextoOriginal(texto, pila1);
	
	return 0;
}
	
void generarTextoOriginal(Oracion texto[], Pila pila1){
	
	for(int i = 0; i < 100; i++){
		if(!desapilar(pila1, texto[i]))
		   cout << "La cola esta vacia" << endl;
	}
	
	ordenar_oraciones(texto);
}
	
void ordenar_oraciones(Oracion texto[]){
	
	int min;
	
	for(int i = 0; i < 100; i++){
		min = i;
		for(int j = i + 1; j < 100; j++){
			if(texto[j].ordinal < texto[min].ordinal){
				min = j;
			}
		}
		intercambiar(texto[i], texto[min]);
	}
}
	
void intercambiar(Oracion &X, Oracion &Y){
	
	Oracion aux = X;
	X = Y;
	Y = aux;
}
