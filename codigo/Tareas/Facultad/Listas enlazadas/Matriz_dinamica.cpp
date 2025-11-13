#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int ** matriz;
	int filas;
	
	cout << "Ingrese la cantidad de filas: ";
	cin >> filas;
	
	matriz = new int*[filas];
	
	for(int i = 0; i < filas; i++){
		matriz[i] = new int[5];
		
		for(int j = 0; j < 5; j++){
			cin >> matriz[i][j];
		}
	}
	
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < 5; j++){
			cout << matriz[i][j] << "  ";
		}
		cout << endl;
	}
	
	return 0;
}

