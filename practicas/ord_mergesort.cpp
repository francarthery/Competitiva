#include <iostream>

using namespace std;

//Consiste en dividir el array en mitades y luego hacer merge de estas empezando por elementos individuales.

void merge(int lista[], int inicio, int mitad, int fin){

    int i = inicio;
    int j = mitad + 1;
    int k = 0;
    int *aux = new int[fin - inicio + 1];

    while(i <= mitad and j <= fin){
        if(lista[i] <= lista[j]){
            aux[k++] = lista[i++];
        }
        else{
            aux[k++] = lista[j++];
        }
    }

    while(i <= mitad){
        aux[k++] = lista[i++];
    }

    while(j <= fin){
        aux[k++] = lista[j++];
    }

    for(int i = inicio; i <= fin; i++){
        lista[i] = aux[i - inicio];
    }
}

void mergeSort(int lista[], int inicio, int fin){

    if(inicio < fin){
        int mitad = (inicio + fin) / 2;
        mergeSort(lista, inicio, mitad);
        mergeSort(lista, mitad + 1, fin);
        merge(lista, inicio, mitad, fin);
    }
}

int main(){

    int lista[15] = {21,2,0,-1,69,1,-76,93,7,10,-102,983,54,-28,13};

    mergeSort(lista, 0, 14);

    for(int i = 0; i < 15; i++){
        cout << lista[i] << " ";
    }

    return 0;
}