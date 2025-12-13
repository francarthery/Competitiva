#include <iostream>
#include "Pila.h"

using namespace std;

bool vacia(Pila & pila1){
	return(pila1.final == 0);
}

bool desapilar(Pila & pila1, Oracion & valor){
	
	if(!vacia(pila1))
		return false;
	else{
		valor = pila1.contenido[pila1.final];
		pila1.final--;
		return true;
	}
}
