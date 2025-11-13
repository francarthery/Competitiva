#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo *sig;
};

typedef Nodo * NodoPtr;

void insertar_final(Nodo *& maestro, int valor);
void insertar_principio(Nodo ** aux, int valor);
void insertar_ordenado(Nodo *& maestro, int valor);
void borrar(Nodo *& maestro, int valor);
void imprimir(Nodo * maestro);
void imprimir_inverso(Nodo * maestro);

int main(int argc, char *argv[]) {
	
	Nodo * maestro = NULL;
	int N;
	
	
	for(int i = 0; i < 10; i++){
		cin >> N;
		//Uso de pasaje por doble puntero
		//insertar_principio(&maestro, N);
		insertar_ordenado(maestro, N);
	}
	
	imprimir(maestro);
	imprimir_inverso(maestro);
	
	cout << endl;
	
	cout << "Ingrese un elemento a eliminar: ";
	cin >> N;
	
	borrar(maestro, N);
	imprimir(maestro);
	
	return 0;
}

void insertar_final(Nodo *& maestro, int valor){
	
	if(maestro == NULL){
		maestro = new Nodo;
		maestro -> info = valor;
		maestro -> sig = NULL;
	}
	else{
		Nodo * aux, * nuevo;
		for(aux = maestro; aux -> sig != NULL; aux = aux -> sig);
		nuevo = new Nodo;
		nuevo -> info = valor;
		nuevo -> sig = NULL;
		aux -> sig = nuevo;
	}
}
	
void insertar_principio(Nodo ** maestro, int valor){
	
	Nodo * aux = *maestro;
	*maestro = new Nodo;
	(*maestro) -> info = valor;
	(*maestro) -> sig = aux;
}
	
void borrar(Nodo *& maestro, int valor){
	
	Nodo *aux = maestro, *anterior = NULL;
	
	while(aux != NULL and aux -> info != valor){
		anterior = aux;
		aux = aux -> sig;
	}
	
	if(aux != NULL){
		//Es el primer elemento
		if(anterior == NULL)
			maestro = aux -> sig;
		else
			anterior -> sig = aux -> sig;
		
		delete aux;
	}
	else
		cout << "No se encontro el elemento" << endl;
}

void insertar_ordenado(Nodo *& maestro, int valor){
	Nodo *anterior = NULL, *actual = maestro, *nuevo;
	
	nuevo = new Nodo;
	
	if(nuevo != NULL){
		
		nuevo -> info = valor;
		
		while(actual != NULL and actual -> info > valor){
			anterior = actual;
			actual = actual -> sig;
		}
		
		//Es el primer elemento
		if(anterior == NULL){
			nuevo -> sig = maestro;
			maestro = nuevo;
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
	
void imprimir_inverso(Nodo * maestro){
	
	if(maestro != NULL){
		imprimir_inverso(maestro -> sig);
		cout << maestro -> info << endl;
	}
}
	
void imprimir(Nodo * maestro){
	for(Nodo * aux = maestro; aux != NULL; aux = aux -> sig){
		cout << aux -> info << endl;
	}
}

