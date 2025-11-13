#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int numero;
	
	/*
	ofstream archivo;
	
	archivo.open("prueba.bin", ios::binary);
	
	for(int i = 0; i < 100; i++){
		numero = rand();
		archivo.write((char*)(&numero), 4);
	}
	
	archivo.close();
	*/
	
	cout << "Ingrese una posicion: ";
	cin >> numero;
	
	ifstream archivo;
	
	archivo.open("prueba.bin", ios::binary);
	
	if(numero * 4 >= archivo.seekg(0, ios::end).tellg())
		cout << "Esa posicion no existe amigo" << endl;
	else{
		archivo.seekg(numero * 4);
		archivo.read((char*)(&numero), 4);
		cout << "En esa posicion esta el numero: " << numero << endl;
	}
	
	
	return 0;
}

