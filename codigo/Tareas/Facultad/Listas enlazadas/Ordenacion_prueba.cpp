#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* sig;
};

void insertar_final(Nodo *& maestro, int valor);
void imprimir_lista(Nodo *maestro);
void mergesort(Nodo *& maestro, int inicio, int fin);
void merge(Nodo *& maestro, int inicio1, int fin1, int inicio2, int fin2);

int main(int argc, char *argv[]) {
	
	Nodo * maestro = NULL;
	int valor;
	
	for(int i = 0; i < 10; i++){
		cin >> valor;
		insertar_final(maestro, valor);
	}
	
	imprimir_lista(maestro);
	mergesort(maestro, 0, 9);
	imprimir_lista(maestro);
	
	return 0;
}

void mergesort(Nodo *& maestro, int inicio, int fin){
	if(inicio >= fin)
		return;
	else{
		mergesort(maestro, inicio, (inicio + fin) / 2);
		mergesort(maestro, (inicio + fin) / 2 + 1, fin);
		merge(maestro, inicio, (inicio + fin) / 2, (inicio + fin) / 2 + 1, fin);
	}
}
	
void merge(Nodo *& maestro, int inicio1, int fin1, int inicio2, int fin2){
	
	int i, j;
	
	Nodo *aux = NULL, *sublista1 = maestro, *sublista2 = maestro, *anterior = NULL;
	
	//Posicionamos un puntero al inicio de cada tramo
	for(i = 0; i < inicio1; i++){
		anterior = sublista1;
		sublista1 = sublista1 -> sig;
	}
	
	for(j = 0; j < inicio2; j++)
		sublista2 = sublista2 -> sig;
	
	while(i <= fin1 and j <= fin2 and sublista1 != NULL and sublista2 != NULL){
		if(sublista1 -> dato > sublista2 -> dato){
			insertar_final(aux, sublista1 -> dato);
			sublista1 = sublista1 -> sig;
			i++;
		}
		else{
			insertar_final(aux, sublista2 -> dato);
			sublista2 = sublista2 -> sig;
			j++;
		}
	}
	
	while(i <= fin1){
		insertar_final(aux, sublista1 -> dato);
		sublista1 = sublista1 -> sig;
		i++;
	}
	while(j <= fin2){
		insertar_final(aux, sublista2 -> dato);
		sublista2 = sublista2 -> sig;
		j++;
	}
	
	//Insertamos el vector ordenado en el original
	if(anterior != NULL)
		anterior -> sig = aux;
	else
		maestro = aux;
	
	for (aux; aux -> sig != NULL; aux = aux -> sig);
	aux->sig = sublista2;
}

void insertar_final(Nodo *& maestro, int valor){

Nodo *nuevo, *aux;

//Si la lista esta vacia, colocamos en el maestro
	if(maestro == NULL){
		maestro = new Nodo;
		maestro -> dato = valor;
		maestro -> sig = NULL;
	}
	else{
	//Nos vamos hasta el final de la lista
		for(aux = maestro; aux->sig != NULL; aux = aux->sig);

		nuevo = new Nodo;
		nuevo->dato = valor;
		nuevo->sig = NULL;
		aux->sig = nuevo;
		}
}

void imprimir_lista(Nodo *maestro){
	
	for(Nodo * aux = maestro; aux != NULL; aux = aux->sig){
		cout << aux->dato << endl;
	}
}
