#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo * sig;
};

typedef Nodo * NodoPtr;

void insertar(NodoPtr * lista, int N);
void imprimir_lista(NodoPtr lista);
void eliminar(NodoPtr * lista, int N);

int main(int argc, char *argv[]) {
	
	NodoPtr lista = NULL;
	int N;
	
	for(int i = 0; i < 8; i++){
		cin >> N;
		insertar(&lista, N);
	}
	
	imprimir_lista(lista);
	
	cout << "Que elemento desea eliminar: ";
	cin >> N;
    eliminar(&lista, N);
	imprimir_lista(lista);
	
	return 0;
}

void insertar(NodoPtr * lista, int N){
	
	NodoPtr aux, nuevo;
	
	nuevo = new Nodo;
	nuevo -> info = N;
	nuevo -> sig = NULL;
	
	if(*lista == NULL){
		*lista = nuevo;
	}
	else{
		for(aux = *lista; aux -> sig != NULL; aux = aux -> sig);
		aux -> sig = nuevo;
	}
}
	
void eliminar(NodoPtr * lista, int N){
	NodoPtr actual = *lista, anterior = NULL;
	
	while(actual -> info != N and actual != NULL){
		anterior = actual;
		actual = actual -> sig;
	}
	
	if(actual == NULL)
		cout << "El elemento no se encuentra en la lista" << endl;
	else{
		if(anterior == NULL){
			*lista = actual -> sig;
		}
		else
		   anterior -> sig = actual -> sig;
		
		delete actual;
	}
}

void imprimir_lista(NodoPtr lista){
	
	for(;lista != NULL; lista = lista -> sig)
		cout << lista -> info << endl;
}

	
	
	
	
	
	
	
	
