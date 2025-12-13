#include <iostream>
 
using namespace std;

#define M 2000
#define N 2

void ordenar_arreglo(int (&numeros)[M][N], int contador);
 
int main() {
 
    int X, n, contador = 0, posicion;
    bool aparecio = false;

    cin >> n;

    int numeros[M][N];

    for(int i = 0; i < n; i++){
        cin >> X;
        //Nos fijamos si el número ya está en la lista
        for(int j = 0; j < contador; j++){
            if(X == numeros[j][0]){
                aparecio = true;
                posicion = j;
            }
        }
        //Si aparecio sumamos 1, sino lo agregamos a la ultima posición
        if(aparecio == true){
            numeros[posicion][1] += 1;
            aparecio = false;
        }
        else{
            numeros[contador][0] = X;
            numeros[contador][1] = 1;
            contador++;
        }
    }

    ordenar_arreglo(numeros, contador);

    for(int i = 0; i < contador; i++){
        cout << numeros[i][0] << " aparece " << numeros[i][1] << " vez(es)" << endl;
    }
 
    return 0;
}

void ordenar_arreglo(int (&numeros)[M][N], int contador){
    int aux;

    for(int i = 0; i < contador; i++){
        for(int j = i + 1; j < contador; j++){
            if(numeros[i][0] > numeros[j][0]){
                aux = numeros[i][0];
                numeros[i][0] = numeros[j][0];
                numeros[j][0] = aux;

                aux = numeros[i][1];
                numeros[i][1] = numeros[j][1];
                numeros[j][1] = aux;
            }
        }
    }
}