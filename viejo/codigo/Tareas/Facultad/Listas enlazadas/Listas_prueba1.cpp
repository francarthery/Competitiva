#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Nodo{
	char palabra[20];
	int cantidad;
	Nodo *sig;
};

void insertar_final(Nodo *& maestro, char pal[], int cant);
void imprimir_lista(Nodo *maestro);
void insertar_ordenado(Nodo *& maestro, char pal_nuevo[]);
void mergesort(Nodo *& maestro, int inicio, int fin);
void merge(Nodo *& maestro, int inicio1, int fin1, int inicio2, int fin2);

int main(int argc, char *argv[]) {
	
	Nodo * maestro = NULL;
	char pal[20];
	
	cout << "ingrese un valor" << endl;
	
	for(int i = 0; i < 137; i++){
		gets(pal);
		//insertar_final(maestro, valor);
		insertar_ordenado(maestro, pal);
	}
	mergesort(maestro, 0, 99);
	imprimir_lista(maestro);
	
	return 0;
}

void insertar_ordenado(Nodo *& maestro, char pal_nuevo[]){
	
	Nodo *nuevo, *anterior, *actual;
	bool flag = false;
	
	anterior = NULL;
	actual = maestro;
	
	//Buscamos la posicion donde insertar
	while(actual != NULL and (strlen(pal_nuevo) > strlen(actual -> palabra) or (strlen(pal_nuevo) == strlen(actual -> palabra) and strcmp(pal_nuevo, actual -> palabra) < 0))){
		anterior = actual;
		actual = actual -> sig;
	}
	
	//Si las palabras son igulales, la condicion del while fallara justo ahi
	if(actual != NULL and strcmp(pal_nuevo, actual -> palabra) == 0)
		flag = true;
	
	if(flag)
		actual -> cantidad++;
	else{
		nuevo = new Nodo;
		strcpy(nuevo -> palabra, pal_nuevo);
		nuevo->cantidad = 1;
		nuevo -> sig = NULL;
		
		//Insercion al principio
		if(anterior == NULL){
			nuevo -> sig = maestro;
			maestro = nuevo;
		}
		else{
			anterior -> sig = nuevo;
			nuevo -> sig = actual;
		}
	}	
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
		if(sublista1 -> cantidad > sublista2 -> cantidad){
			insertar_final(aux, sublista1 -> palabra, sublista1 -> cantidad);
			sublista1 = sublista1 -> sig;
			i++;
		}
		else{
			insertar_final(aux, sublista2 -> palabra, sublista2 -> cantidad);
			sublista2 = sublista2 -> sig;
			j++;
		}
	}
	
	while(i <= fin1){
		insertar_final(aux, sublista1 -> palabra, sublista1 -> cantidad);
		sublista1 = sublista1 -> sig;
		i++;
	}
	while(j <= fin2){
		insertar_final(aux, sublista2 -> palabra, sublista2 -> cantidad);
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
	
void insertar_final(Nodo *& maestro, char pal[], int cant){
	
	Nodo *nuevo, *aux;
	
	//Si la lista esta vacia, colocamos en el maestro
	if(maestro == NULL){
		maestro = new Nodo;
		strcpy(maestro -> palabra, pal); 
		maestro -> cantidad = cant;
		maestro -> sig = NULL;
	}
	else{
		//Nos vamos hasta el final de la lista
		for(aux = maestro; aux->sig != NULL; aux = aux->sig);
		
		nuevo = new Nodo;
		strcpy(nuevo -> palabra, pal);
		nuevo -> cantidad = cant;
		nuevo -> sig = NULL;
		aux -> sig = nuevo;
	}
}

void imprimir_lista(Nodo *maestro){
	
	for(Nodo * aux = maestro; aux != NULL; aux = aux->sig){
		cout << aux->palabra << "  " << aux->cantidad << endl;
	}
}
