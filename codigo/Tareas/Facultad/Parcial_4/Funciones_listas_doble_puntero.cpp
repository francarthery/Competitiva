#include <iostream>
using namespace std;

struct NodoLista{
	int info;
	NodoLista * sig;
};

typedef NodoLista * NodoListaPtr;

void insertar_final(NodoListaPtr * lista, int valor);
void insertar_final_rec(NodoListaPtr * lista, int valor);
void insertar_ordenado(NodoListaPtr * lista, int valor);
void borrar_elemento(NodoListaPtr * lista, int valor);
void imprimir_lista(NodoListaPtr lista);
void ordenar_lista(NodoListaPtr lista);
void menor_elem(NodoListaPtr aux, NodoListaPtr *menor);
void intercambiar(NodoListaPtr * nod1, NodoListaPtr * nod2);
void imprimir_inverso(NodoListaPtr lista);

int main(int argc, char *argv[]) {
	
	NodoListaPtr lista = NULL;
	int N;
	
	for(int i = 0; i < 10; i++){
		cin >> N;
		//insertar_final_rec(&lista, N);
		insertar_ordenado(&lista, N);
	}
	//ordenar_lista(lista);
	imprimir_lista(lista);
	cout << endl;
	
	cout << "Ingrese un elemento para eliminar" << endl;
	cin >> N;
	
	borrar_elemento(&lista, N);
	imprimir_inverso(lista);
	
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
	
void borrar_elemento(NodoListaPtr * lista, int valor){
	
	NodoListaPtr actual = *lista, anterior = NULL;
	
	for(; actual != NULL and actual -> info != valor; actual = actual -> sig){
		anterior = actual;
	}
	
	if(actual == NULL){
		cout << "El elemento no se encuentra en la lista" << endl;
	}
	else{
		//Si el elemento a borrar es el primero
		if(anterior == NULL){
			*lista = actual -> sig;
		}
		else{
			anterior -> sig = actual -> sig;
		}
		
		delete actual;
	}
}


void insertar_final(NodoListaPtr * lista, int valor){
	
	NodoListaPtr nuevo, aux;
	
	nuevo = new NodoLista;
	nuevo -> info = valor;
	nuevo -> sig = NULL;
	
	if(*lista == NULL){
		*lista = nuevo;
	}
	else{
		for(aux = *lista; aux -> sig != NULL; aux = aux -> sig);
		aux -> sig = nuevo;
	}
}
	
void insertar_final_rec(NodoListaPtr * lista, int valor){
	
	if(*lista == NULL){
		*lista = new NodoLista;
		(*lista) -> info = valor;
		(*lista) -> sig = NULL;
	}
	else{
		insertar_final_rec(&((*lista) -> sig), valor);
	}
}
	
void imprimir_lista(NodoListaPtr lista){
	
	for(; lista != NULL; lista = lista -> sig){
		cout << lista -> info << endl;
	}
}
	
void ordenar_lista(NodoListaPtr lista){
	
	NodoListaPtr menor;
 	
	for(NodoListaPtr aux = lista; aux != NULL; aux = aux -> sig){
		menor = aux;
		menor_elem(aux, &menor);
		intercambiar(&aux, &menor);
	}
}

void menor_elem(NodoListaPtr aux, NodoListaPtr *menor){
	
	for(; aux != NULL; aux = aux -> sig){
		if((*menor) -> info > aux -> info)
			*menor = aux;
	}
}
	
void intercambiar(NodoListaPtr * nod1, NodoListaPtr * nod2){
	int aux = (*nod1) -> info;
	(*nod1) -> info = (*nod2) -> info;
	(*nod2) -> info = aux;
}

void imprimir_inverso(NodoListaPtr lista){
	if(lista != NULL){
		imprimir_inverso(lista -> sig);
		cout << lista -> info << endl;
	}
}






