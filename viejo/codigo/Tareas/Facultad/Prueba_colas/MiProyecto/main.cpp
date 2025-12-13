#include <iostream>
#include "Cola.h"

using namespace std;

int main(){
	
	Cola cola1;
	int aux;
	
	inicializar(cola1);
	
	if(encolar(cola1, 3))
	   cout << "Se encolo el 3" << endl;
	else
		cout << "Error, la cola esta llena" << endl;
	
	if(encolar(cola1, 5))
	   cout << "Se encolo el 5" << endl;
	else
		cout << "Error, la cola esta llena" << endl;
	
	if(encolar(cola1, 90))
	   cout << "Se encolo el 90" << endl;
	else
		cout << "Error, la cola esta llena" << endl;
	
	if(desencolar(cola1, aux))
		cout << "Se desencolo el " << aux << endl;
	else
		cout << "Error, la cola esta vacia" << endl;
	
	mostrar_cola(cola1);
	
	return 0;
}
