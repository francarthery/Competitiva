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
void mostrar_tabla(Letras frecuencia[]);
void leer_libro(Letras frecuencia[]);
void mergesort(Letras frecuencia[], int inicio, int fin);
void merge(Letras frecuencia[], int inicio1, int fin1, int inicio2, int fin2);
void guardar_tabla(Letras frecuencia[]);
void cargar_tabla(Letras frecuencia[]);

void est_palabras();
void genera_matriz(int [][26]);
void ver_matriz(int Palabras[][26]);
void consultas(int Palabras[][26], Nodo * lista);
int palabra_promedio(int [][26]);
int vocal_consonante(int [][26]);
void palabras_mas_frecuencia(Nodo * lista);
bool es_vocal(char letra);
void frecuencia_palabras(Nodo *&);
void insertar_ordenado(Nodo *& maestro, char pal_nuevo[], int & tam);
void mergesort_lista(Nodo *& maestro, int inicio, int fin);
void merge_lista(Nodo *& maestro, int inicio1, int fin1, int inicio2, int fin2);
void insertar_final(Nodo *& maestro, char pal[], int cant);
void imprimir_lista(Nodo *maestro);
void palabra_lista(Nodo *);
void borrar_lista(Nodo *& lista);
void gotoxy(USHORT x, USHORT y);
void lineas(int x1, int x2, int tamx, char c);
char pedir_opciones();
