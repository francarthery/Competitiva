#include <iostream>

using namespace std;

int cantidad;

int* array = new int[cantidad];

int* llenarArray (int numero, int cantidad) {

	for (int i = 0; i < cantidad; i++) {

		array[i] = numero * i + numero;

	}

	return array;
}


int main(int argc, char *argv[]) {
	
    int numero;

    cout << "Introduce un número: ";
	cin >> numero;
    cout << "Introduce la cantidad de múltiplos: ";
    cin >> cantidad;

	llenarArray(numero,cantidad);

	cout << "Array de multiplos: ";

	for (int i = 0; i < cantidad; i++) {

		cout << array[i] << " ";

	}

	delete[] array;

	return 0; 

}