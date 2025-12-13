#include <iostream>
#include <fstream>
#include <windows.h>
#include "Libro.h"
#include <iomanip>
#include <cstring>
using namespace std;

void est_caracteres(){
	
	Letras frecuencia[128];
	
	ifstream archivo("frecuencia.txt");
	
	//Si el archivo ya existe, cargamos el array desde ahi. Sino analizamos todo el libro.
	if(archivo)
		cargar_tabla(frecuencia);
	else{
		leer_libro(frecuencia);
		mergesort(frecuencia, 33, 127);
		guardar_tabla(frecuencia);
	}
	archivo.close();
	//Se muestra en pantalla la tabla.
	cout << setfill(' ') << setw(35) << "|Caracter|Cant. de apariciones|" << endl;
	
	for(int i = 33; i < 128; i++){
		cout << setw(8) << "|   " << frecuencia[i].letra << "    |";
		cout << setw(12) << frecuencia[i].cantidad << setw(9) << "|" << endl;
		Sleep(20);
	}
}


void leer_libro(Letras frecuencia[]){
	
	char letra;
	
	//Cargamos cada letra en su posicion del codigo ascii(los primeros 32 caracteres son especiales)
	for(int i = 33; i < 128; i++){
		frecuencia[i].letra = (char)i;
	}
	
	ifstream libro;
	
	libro.open("les_miserables.txt");
	
	if(!libro)
		cout << "Error al abrir el fichero" << endl;
	else{
		while (libro.get(letra)) {
			frecuencia[int(letra)].cantidad++;
		}
	}
	
	libro.close();
}
	
void mergesort(Letras frecuencia[], int inicio, int fin){
	if(fin - inicio == 0)
		return;
	else{
		mergesort(frecuencia, inicio, (inicio + fin) / 2);
		mergesort(frecuencia, (inicio + fin) / 2 + 1, fin);
		merge(frecuencia, inicio, (inicio + fin) / 2, (inicio + fin) / 2 + 1, fin);
	}
}
	
void merge(Letras frecuencia[], int inicio1, int fin1, int inicio2, int fin2){
	
	int i = inicio1, j = inicio2, k = 0;
	Letras c[100];
	
	while(i <= fin1 and j <= fin2){
		if(frecuencia[i].cantidad > frecuencia[j].cantidad){
			c[k] = frecuencia[i];
			i++;
		}
		else{
			c[k] = frecuencia[j];
			j++;
		}
		k++;
	}
	
	while(i <= fin1){
		c[k] = frecuencia[i];
		k++;
		i++;
	}
	while(j <= fin2){
		c[k] = frecuencia[j];
		k++;
		j++;
	}
	
	//Guardamos la parte ordenada en el vector original
	for(k = 0; k < fin2 - inicio1 + 1; k++){
		frecuencia[inicio1 + k] = c[k];
	}
}
	
void cargar_tabla(Letras frecuencia[]){
	
	ifstream tabla;
	
	tabla.open("frecuencia.txt");
	
	if(!tabla)
		cout << "Error al abrir el archivo" << endl;
	else{
		for(int i = 33; i < 128; i++){
			tabla >> frecuencia[i].letra >> frecuencia[i].cantidad;
		}
	}
	
	tabla.close();
}
	
void guardar_tabla(Letras frecuencia[]){
	
	ofstream tabla;
	
	tabla.open("frecuencia.txt");
	
	if(!tabla)
		cout << "Error al abrir el fichero" << endl;
	else{
		for(int i = 33; i < 128; i++){
			tabla << frecuencia[i].letra << setfill(' ') << setw(8) << frecuencia[i].cantidad << endl;
		}
	}
	
	tabla.close();
}
	


void est_palabras(){
	
	int Palabras[19][26] = {0};
	genera_matriz(Palabras);
	
	//cout << palabra_promedio(Palabras) << endl;
	//cout << vocal_consonante(Palabras) << "%" << endl;
}
	
void genera_matriz(int Palabras[][26]){
	char letra, letra_inicial;
	bool anterior_letra = false;
	int contador = 1;
	
	ifstream libro;
	
	libro.open("les_miserables.txt");
	
	if(!libro)
		cout << "Error al abrir el fichero" << endl;
	else{
		while(libro.get(letra)){
			if(isalpha(letra) and !anterior_letra){
				letra_inicial = letra;
				contador = 1;
				anterior_letra = true;
			}
			else if(isalpha(letra) and anterior_letra)
			   contador++;
			else if(!isalpha(letra) and anterior_letra){
				anterior_letra = false;
				Palabras[contador][tolower(letra_inicial) - 'a']++;
			}
		}
	}
	
	libro.close();
	
	cout << "    ";
	for(int i = 0; i < 26; i++){
		cout << setfill(' ') << setw(6) << char(i + 'a');
	}
	cout << endl;
	for(int i = 1; i < 19; i++){
		cout << setw(4) << i;
		for(int j = 0; j < 26; j++){
			cout << setw(6) << Palabras[i][j];
		}
		cout << endl;
	}
}
	
int palabra_promedio(int Palabras[][26]){
	
	int suma, mayor = 0, longitud;
	
	for(int i = 1; i < 19; i++){
		suma = 0;
		for(int j = 0; j < 26; j++){
			suma += Palabras[i][j];
		}
		if(suma > mayor){
			mayor = suma;
			longitud = i;
		}
	}
	
	return longitud;
}
	
int vocal_consonante(int Palabras[][26]){
	
	int suma_vocales = 0, suma_total = 0;
	
	for(int i = 1; i < 19; i++){
		
		for(int j = 0; j < 26; j++){
			suma_total += Palabras[i][j];
			if(es_vocal(j + 'a'))
				suma_vocales += Palabras[i][j];
		}
	}
	
	return (suma_vocales * 100) / suma_total;
}
	
bool es_vocal(char letra){
	
	bool rta = false;
	
	if(letra == 'a' or letra == 'e' or letra == 'i' or letra == 'o'  or letra == 'u')
		rta = true;
	
	return rta;
}


void frecuencia_palabras(){
	char palabra[20];
	bool anterior_letra= false;
	int contador = 0;
	char letra;
	Nodo * lista = NULL;
	
	ifstream libro;
	
	libro.open("les_miserables.txt");
	
	if(!libro)
		cout << "Error al abrir el fichero" << endl;
	else{
		while(libro.get(letra)){
			if(isalpha(letra) and !anterior_letra){
				contador = 1;
				palabra[0] = tolower(letra);
				anterior_letra = true;
			}
			else if(isalpha(letra) and anterior_letra)
			   palabra[contador++] = tolower(letra);
			else if(!isalpha(letra) and anterior_letra){
				anterior_letra = false;
				palabra[contador] = '\0';
				insercion_lista(lista, palabra);
			}
		}
		imprimir_lista(lista);
	}
	libro.close();
}
void insercion_lista(Nodo *&sPtr, char word[]){
	
	Nodo* actual = sPtr;
	
	
	while(actual != NULL){
		if (!strcmp(actual->palabra, word)){
			actual-> cantidad++;
			return;
		}
		actual = actual -> sig;
	}
	
	Nodo* nuevo = new Nodo();
	strcpy(nuevo->palabra, word);
	nuevo->cantidad = 1;
	nuevo->sig = sPtr;
	sPtr = nuevo;
	
}	
void imprimir_lista(Nodo *maestro){
	
	for(Nodo * aux = maestro; aux != NULL; aux = aux->sig){
		cout << aux->palabra << " " << aux->cantidad << endl;
	}
}
	
