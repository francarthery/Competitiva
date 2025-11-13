#include <iostream>

using namespace std;

/*
Este metodo consiste en elejir un elemento pivote y mover todos los elementos mayores a la derecha
y los menores a la izquierda y repetir el proceso en cada subarray que se forma (a la derecha y la izquierda
del pivote) hasta que las sublistas tengan un solo elemento.
*/

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int pivot(int a[], int first, int last){
    //Elejimos como pivote el primer elemento del arreglo
    int p = first;
    int pivotElement = a[first];

    //Colocamos los elementos menores al pivote a la izquierda y los mayores a la derecha
    for(int i = first + 1; i <= last; i++){
        if(a[i] <= pivotElement){
            p++;
            swap(a[i], a[p]);   
        }
    }

    swap(a[p], a[first]);

    return p;
}

void quickSort(int a[], int first, int last){
    int pivotElement;
    if(first < last){
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement - 1);
        quickSort(a, pivotElement + 1, last);
    }
}

int main(){

    int lista[15] = {21,2,0,-1,69,1,-76,93,7,10,-102,983,54,-28,13};

    quickSort(lista, 0, 14);

    for(int i = 0; i < 15; i++){
        cout << lista[i] << " ";
    }

    return 0;
}