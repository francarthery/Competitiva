#include <iostream>
using namespace std;

struct Direccion{
	char calle[20];
	int numero;
	char ciudad[20];
	char provincia[20];
};

struct Informacion{
	char nombre[20];
	char apellido[20];
	int DNI;
	Direccion residencia;
};

struct Paquete{
	int ancho, largo, alto;
	bool fragil;
	int peso;
};

struct Envio{
	int numero;
	Paquete paq;
	Informacion origen, destino;
};

struct Nodo{
	Envio info;
	Nodo *sig;
};

void insertar(Nodo *& lista, Envio valor);
int EnviosNoEntregados(Nodo * lista);
void imprimir_inverso(Nodo * lista);

int main(int argc, char *argv[]) {
	
	Nodo * lista = NULL;
	
	for(int i = 0; i < 17; i++){
		Envio pepe;
		pepe.numero = i;
		insertar(lista, pepe);
	}
	
	cout << EnviosNoEntregados(lista) << endl;
	imprimir_inverso(lista);
	
	return 0;
}

void insertar(Nodo *& lista, Envio valor){
	
	Nodo * aux = lista;
	lista = new Nodo;
	lista -> info = valor;
	lista -> sig = aux;
}
	
int EnviosNoEntregados(Nodo * lista){
	if(lista == NULL) return 0;
	else return 1 + EnviosNoEntregados(lista -> sig);
}
	
void imprimir_inverso(Nodo * lista){
	if(lista != NULL){
		imprimir_inverso(lista -> sig);
		cout << lista -> info.numero << endl;
	}
}
