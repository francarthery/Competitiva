#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo * sig;
};

typedef Nodo * ptrNodo;

void insertar_final(ptrNodo & lista, int valor);
void borrar_decreciente(ptrNodo & lista);
void imprimir_lista(ptrNodo lista);

int main(int argc, char *argv[]) {
	
	int N;
	ptrNodo lista = NULL;
	
	for(int i = 0; i < 15; i++){
		cin >> N;
		insertar_final(lista, N);
	}
	
	//imprimir_lista(lista);
	borrar_decreciente(lista);
	imprimir_lista(lista);
	
	return 0;
}

void borrar_decreciente(ptrNodo & lista){
	ptrNodo actual = lista -> sig, anterior = lista, aux = NULL;
	
	while(actual != NULL){
		if(actual -> info <= anterior -> info){
			anterior -> sig = actual -> sig;
			aux = actual;
			actual = actual -> sig;
			delete aux;
		}
		else{
			anterior = actual;
			actual = actual -> sig;
		}
	}
}

void insertar_final(ptrNodo & lista, int valor){
	
	ptrNodo nuevo, aux;
	nuevo = new Nodo;
	nuevo -> info = valor;
	nuevo -> sig = NULL;
	
	if(lista == NULL)
		lista = nuevo;
	else{
		for(aux = lista; aux -> sig != NULL; aux = aux -> sig);
		aux -> sig = nuevo;
	}
}
	
void imprimir_lista(ptrNodo lista){
	for(; lista != NULL; lista = lista -> sig){
		cout << lista -> info << endl;
	}
}
	
