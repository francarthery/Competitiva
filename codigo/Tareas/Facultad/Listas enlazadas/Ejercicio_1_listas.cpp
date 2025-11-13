#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo * sig;
};

typedef Nodo * ptrNodo;

void insertar_ordenado(ptrNodo & lista, int valor);
void insertar_final(ptrNodo & lista, int valor);
void merge_listas(ptrNodo lista1, ptrNodo lista2, ptrNodo & lista3);
void unir_listas(ptrNodo & destino, ptrNodo & origen);
void imprimir_lista(ptrNodo lista);

int main() {
	
	ptrNodo lista1 = NULL, lista2 = NULL, lista3 = NULL;
	int N;
	
	cout << "Ingrese 10 elementos: ";
	for(int i = 0; i < 10; i++){
		cin >> N;
		insertar_ordenado(lista1, N);
	}
	cout << endl << "Ingrese 10 elementos: ";
	for(int i = 0; i < 10; i++){
		cin >> N;
		insertar_ordenado(lista2, N);
	}
	
	//unir_listas(lista1, lista2);
	merge_listas(lista1, lista2, lista3);
	imprimir_lista(lista3);
	
	return 0;
}

void insertar_ordenado(ptrNodo & lista, int valor){
	
	ptrNodo actual = lista, anterior = NULL, nuevo;
	
	nuevo = new Nodo;
	
	if(nuevo != NULL){
		nuevo -> info = valor;
		
		while(actual != NULL and actual -> info > valor){
			anterior = actual;
			actual = actual -> sig;
		}
		
		if(anterior == NULL){
			nuevo -> sig = lista;
			lista = nuevo;
		}
		else{
			anterior -> sig = nuevo;
			nuevo -> sig = actual;
		}
	}
	else
	   cout << "No hay memoria suficiente" << endl;
	
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
	
void merge_listas(ptrNodo lista1, ptrNodo lista2, ptrNodo & lista3){
	
	while(lista1 != NULL and lista2 != NULL){
		if(lista1 -> info > lista2 -> info){
			insertar_final(lista3, lista1 -> info);
			lista1 = lista1 -> sig;
		}
		else{
			insertar_final(lista3, lista2 -> info);
			lista2 = lista2 -> sig;
		}
	}
	
	while(lista1 != NULL){
		insertar_final(lista3, lista1 -> info);
		lista1 = lista1 -> sig;
	}
	
	while(lista2 != NULL){
		insertar_final(lista3, lista2 -> info);
		lista2 = lista2 -> sig;
	}
}

void unir_listas(ptrNodo & destino, ptrNodo & origen){
	
	ptrNodo aux;
	
	if(destino != NULL and origen != NULL){
		for(aux = destino; aux -> sig != NULL; aux = aux -> sig);
		aux -> sig = origen;
	}
}
	
void imprimir_lista(ptrNodo lista){
	for(; lista != NULL; lista = lista -> sig){
		cout << lista -> info << endl;
	}
}

