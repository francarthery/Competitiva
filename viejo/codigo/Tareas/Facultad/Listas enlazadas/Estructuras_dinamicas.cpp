#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	
	//Creamos en tiempo de ejecucion una nueva variable. Recibimos un puntero a esta.
	int *Ptr = new int;
	
	if(Ptr == NULL)
		cout << "No hay memoria suficiente" << endl;
	else{
		//Liberamos un puntero
		delete Ptr;
	}

//---------------------------------------------------------------------
	
	//Vector dinamico
	int * array;
	int N;
	
	cin >> N;
	
	//Array sera un puntero a la primer posicion del arreglo
	array = new int[N];
	
	for(int i = 0; i < N; i++)
		array[i] = rand();
	
	delete []array;
	array = NULL;
	
//---------------------------------------------------------------------
	
	//Vector dinamico de arreglos dinamicos
	
	//Puntero a un puntero string
	string ** matriz = NULL;
	int row;
	
	cout << "Indique cantidad de filas: ";
	cin >> row;
	cin.ignore();
	string cadena;
	
	//Creamos un arreglo de punteros
	matriz = new string * [row];
	
	for(int i = 0; i < row; i++){
		getline(cin, cadena);
		matriz[i] = new string;
		//En cada puntero guardamos la direccion de la cadena dinamica
		*(matriz[i]) = cadena;
	}
	
	for(int i = 0; i < row; i++){
		cout << *(matriz[i]) << "   ";
	}
	
	return 0;
}

