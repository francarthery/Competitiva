#include <iostream>
using namespace std;

struct NodoLista{
	int info;
	NodoLista * sig;
};

typedef NodoLista * NodoListaPtr;

void insertar_ordenado(NodoListaPtr * lista, int valor);
void imprimir_lista(NodoListaPtr lista);
void merge_listas(NodoListaPtr lista1, NodoListaPtr lista2, NodoListaPtr * lista3);
void insertar_final(NodoListaPtr * lista, int valor);

int main(){
	
	NodoListaPtr lista1 = NULL, lista2 = NULL, lista3 = NULL;
	int N;
	
	cout << "Ingrese lista 1: ";
	for(int i = 0; i < 10; i++){
		cin >> N;
		insertar_ordenado(&lista1, N);
	}
	
	cout << "Ingrese lista 2: ";
	for(int i = 0; i < 10; i++){
		cin >> N;
		insertar_ordenado(&lista2, N);
	}
	
	merge_listas(lista1, lista2, &lista3);
	
	imprimir_lista(lista3);
	
	return 0;
}

void insertar_ordenado(NodoListaPtr * lista, int valor){
	
	NodoListaPtr nuevo, actual = *lista, anterior = NULL;
	
	nuevo = new NodoLista;
	
	if(nuevo != NULL){
		
		nuevo -> info = valor;
		
		while(actual != NULL and actual -> info < valor){
			anterior = actual;
			actual = actual -> sig;
		}
		//Primer elemento
		if(anterior == NULL){
			nuevo -> sig = *lista;
			*lista = nuevo;
		}
		else{
			nuevo -> sig = actual;
			anterior -> sig = nuevo;
		}
	}
	else{
		cout << "No hay espacio en memoria" << endl;
	}
}
	
void imprimir_lista(NodoListaPtr lista){
	
	for(; lista != NULL; lista = lista -> sig){
		cout << lista -> info << endl;
	}
}
	
void merge_listas(NodoListaPtr lista1, NodoListaPtr lista2, NodoListaPtr * lista3){
	
	while(lista1 != NULL and lista2 != NULL){
		if(lista1 -> info < lista2 -> info){
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
	
void insertar_final(NodoListaPtr * lista, int valor){
	
	if(*lista == NULL){
		NodoListaPtr nuevo = new NodoLista;
		
		if(nuevo != NULL){
			nuevo -> info = valor;
			nuevo -> sig = NULL;
			*lista = nuevo;
		}
		else
			cout << "No hay espacio en memoria" << endl;
	}
	else{
		insertar_final(&((*lista) -> sig), valor);
	}
}
	








