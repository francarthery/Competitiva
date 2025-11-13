#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	string ** matriz = NULL;
	int filas;
	string cadena;
	
	cout << "Ingrese la cantidad de filas: ";
	cin >> filas;
	cin.ignore();
	
	matriz = new string*[filas];
	
	cout << "Ingrese las palabras: " << endl;
	for(int i = 0; i < filas; i++){
		getline(cin, cadena);
		matriz[i] = new string;
		*(matriz[i]) = cadena;
	}
	
	cout << endl;
	for(int i = 0; i < filas; i++){
		cout << *matriz[i] << endl;
	}
	
	
	return 0;
}

