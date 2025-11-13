#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	ofstream archivo;
	
	archivo.open("pepe.txt");
	
	char cadena[20], salida[20];
	
	cin >> cadena;
	
	cout << *cadena << endl;
	
	archivo << cadena;
	//archivo.write(cadena, sizeof(cadena));
	
	archivo.close();
	
	
	ifstream sofia;
	
	sofia.open("pepe.txt");
	
	sofia.seekg(-1, ios::end);
	cout << sofia.tellg() << endl;
	
	sofia >> salida;
	
	cout << salida << endl;
	
	return 0;
}

