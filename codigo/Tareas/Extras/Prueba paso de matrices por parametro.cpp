#include <iostream>

using namespace std;

const int filas = 3;
const int columnas = 4;
int matriz[filas][columnas] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

void imprimir_matriz(int (*matriz)[columnas], int filas, int columnas) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Llamada a la función

int main(){
imprimir_matriz(matriz, filas, columnas);

    return 0;
}