#include <iostream>
#include "Cola.h"
using namespace std;

bool encolar(Cola & aux, int elemento){
	
	if((aux.ultimo + 1) % 10 == aux.primero)
		return false;
	else{
		aux.info[aux.ultimo] = elemento;
		aux.ultimo = (aux.ultimo + 1) % 10;
		return true;
	}
}
	
bool desencolar(Cola &aux, int & elemento){
	if(!vacia(aux)){
		elemento = aux.info[aux.primero];
		aux.primero = (aux.primero + 1) % 10;
		return true;
	}
	else
		return false;
}
	
bool vacia(Cola &aux){
	return aux.primero == aux.ultimo;
}
	
void inicializar(Cola &aux){
	aux.primero = aux.ultimo = 0;
}
	
void mostrar_cola(const Cola & aux){
	for(int i = aux.primero; i != aux.ultimo; i++){
		cout << aux.info[i] << " - ";
	}
	cout << endl;
}
