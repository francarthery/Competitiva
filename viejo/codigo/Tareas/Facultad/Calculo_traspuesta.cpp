#include <iostream>
#include <iomanip>
using namespace std;

void traspuesta(int matriz[][5]);
void intercambiar(int &a, int &b);

int main(int argc, char *argv[]) {
	
	int matriz[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout << setfill(' ') << setw(3) << matriz[i][j];
		}
		cout << endl;
	}
	
	traspuesta(matriz);
	
	cout << endl << "Luego de trasponer:" << endl;
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout << setfill(' ') << setw(3) << matriz[i][j];
		}
		cout << endl;
	}
	
	return 0;
}

void traspuesta(int matriz[][5]){
	for(int i = 1; i < 5; i++){
		for(int j = 0; j < i; j++){
			intercambiar(matriz[i][j], matriz[j][i]);
		}
	}
}
	
void intercambiar(int &a, int &b){
	
	int aux = a;
	a = b;
	b = aux;
}

