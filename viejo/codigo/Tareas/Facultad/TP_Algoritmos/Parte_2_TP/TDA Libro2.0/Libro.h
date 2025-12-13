#include <iostream>
#include <fstream>
#include <string> 

struct Letras{
    char letra;
    int cantidad = 0;
};

struct Nodo{
	char palabra[20]= {0};
	int cantidad;
	Nodo * sig;
};

void est_caracteres();
void leer_libro(Letras frecuencia[]);
void mergesort(Letras frecuencia[], int inicio, int fin);
void merge(Letras frecuencia[], int inicio1, int fin1, int inicio2, int fin2);
void guardar_tabla(Letras frecuencia[]);
void cargar_tabla(Letras frecuencia[]);

void est_palabras();
void genera_matriz(int [][26]);
int palabra_promedio(int [][26]);
int vocal_consonante(int [][26]);
bool es_vocal(char letra);
void frecuencia_palabras();
void insercion_lista(Nodo *&, char[]);
void imprimir_lista(Nodo *maestro);
