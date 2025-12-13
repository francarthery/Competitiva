#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int arr[6] = {1, 2, 3, 4, 5, 6};

    //Analizar si se cumple una propiedad en todos los elementos
    if(all_of(arr, arr + 6, [](int x){ return x > 0; })) //Son todos los elementos positivos?
        cout << "Todos los elementos son positivos" << endl;
    else
        cout << "No todos los elementos son positivos" << endl;
    

    //Analizar si se cumple una propiedada en alguno de los elementos
    if(any_of(arr, arr + 6, [](int x){ return x < 0; })) //Hay algun elemento negativo?
        cout << "Hay elementos negativos" << endl;
    else
        cout << "No hay elementos negativos" << endl;

    
    //Analizar una propiedad no se cumple en ningun elemento
    if(none_of(arr, arr + 6, [](int x){ return x < 0; })) //Ningun elemento es negativo?
        cout << "No hay elementos negativos" << endl;
    else
        cout << "Hay elementos negativos" << endl;


    cout << count_if(arr, arr + 6, [](int x){ return x > 0;}) << endl; //Cuenta cant de elementos que cumplen condicion
    
    int arr2[6];
    copy_n(arr, 6, arr2); //Copio elementos de arr a arr2

    for(int i : arr2)
        cout << i << " ";
    cout << endl;

    return 0;
}