#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;

struct Renglon{
	char reng[100] = "\0";
};

struct Pagina{
	Renglon contenido[100];
	int numero;
	char encabezado[100] = "dodo";
	char pie[100] = "pepe";
};

void generar_texto(string nombre);
void cambiar_linea(string nombre, int pagina, int linea, char linea_nueva[]);
void mostrar_pagina(string nombre, int pagina);

int main(int argc, char *argv[]) {
	
	system("mode con: cols=100 lines=110");
	
	//generar_texto("Libro1.bin");
	
	char cadena[100] = "The most notable effect of CFCs on the environment...";
	cambiar_linea("Libro1.bin", 5, 32, cadena);
	mostrar_pagina("Libro1.bin", 1);
	
	return 0;
}

void generar_texto(string nombre){
	
	ofstream libro;
	
	libro.open(nombre, ios::out | ios::binary);
	
	for(int i = 0; i < 10; i++){
		Pagina aux;
		aux.numero = i + 1;
		libro.write((char*)(&aux), sizeof(Pagina));
	}
	
	libro.close();
}
	
void cambiar_linea(string nombre, int pagina, int linea, char linea_nueva[]){
	
	Pagina aux;
	fstream libro;
	
	libro.open(nombre, ios::in | ios::out| ios::binary);
	
	libro.seekg((pagina - 1) * sizeof(Pagina));
	libro.read((char*)(&aux), sizeof(Pagina));
	
	strcpy(aux.contenido[linea - 1].reng, linea_nueva);
	
	libro.seekp((pagina - 1) * sizeof(Pagina));
	libro.write((char*)(&aux), sizeof(Pagina));
	
	libro.close();
}
	
void mostrar_pagina(string nombre, int pagina){
	
	Pagina aux;
	ifstream libro;
	
	libro.open(nombre, ios::in | ios::binary);
	
	libro.seekg((pagina - 1) * sizeof(Pagina));
	libro.read((char*)(&aux), sizeof(aux));
	
	libro.close();
	
	cout << "Pagina " << aux.numero << endl << aux.encabezado << endl << endl;
	for(int i = 0; i < 100; i++){
		cout << aux.contenido[i].reng << endl;
	}
	cout << endl << aux.pie << endl;
}

