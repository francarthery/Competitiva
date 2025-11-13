#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

struct NodoLista{
	int info;
	NodoLista * sig;
};

typedef NodoLista * NodoListaPtr;

void insertarFinal(NodoListaPtr * sPtr, int valor);
void printLista(NodoListaPtr actual);
int Parcial3(NodoListaPtr *sPtr);

int main(int argc, char *argv[]) {
	
	NodoListaPtr startPtr = NULL;
	int item;
	
	while(cin >> item)
		insertarFinal(&startPtr, item);
	
	cout << Parcial3(&startPtr) << endl;
	printLista(startPtr);
	
	return 0;
}

void insertarFinal(NodoListaPtr *sPtr, int valor){
	
	NodoListaPtr nuevo;
	
	if(*sPtr == NULL){
		nuevo = new NodoLista;
		
		if(nuevo != NULL){
			nuevo -> info = valor;
			nuevo -> sig = NULL;
			*sPtr = nuevo;
		}
		else
		   cout << "No hay espacio";
	}
	else
	   insertarFinal(&(*sPtr) -> sig, valor);
	
}
	
int Parcial3(NodoListaPtr * sPtr){
	
	int contador = 0;
	NodoListaPtr anterior = NULL, actual = *sPtr, nuevo;
	
	while(actual != NULL){
		//Si el elemento actual es impar
		if(actual -> info % 2 != 0){
			nuevo = new NodoLista;
			
			if(nuevo != NULL){
				nuevo -> info = -1;
				
				//Si el primer elemento es impar
				if(anterior == NULL){
					nuevo -> sig = *sPtr;
					*sPtr = nuevo;
				}
				else{
					anterior -> sig = nuevo;
					nuevo -> sig = actual;
				}
				contador++;
			}
			else
			   cout << "No hay espacio";
			
		}
		anterior = actual;
		actual = actual -> sig;
	}
	return contador;
}

void printLista(NodoListaPtr actual){
	while(actual != NULL){
		cout << actual -> info << " -> ";
		actual = actual -> sig;
	}
	
	cout << "NULL" << endl;
}
