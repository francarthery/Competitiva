#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> vec = {2, 1, 5, 6, 8, 7};

    //Se usa para dividir un vector de acuerdo a determinada condicion
    //partition(vec.begin(), vec.end(), [](int x){ return x % 2 == 0; }); //Dividimos vector en pares e impares

    cout << is_partitioned(vec.begin(), vec.end(), [](int x){ return x % 2 == 0; }) << endl; //Verificamos si esta particionado

    stable_partition(vec.begin(), vec.end(), [](int x){ return x % 2 == 0; }); //Mantiene orden relativo de elementos iguales

    cout << "Elementos luego de particion: ";
    for(int i : vec) cout << i << " ";
    cout << endl;

    cout << *partition_point(vec.begin(), vec.end(), [](int x){ return x % 2 == 0; }) << endl; //Devuelve iterador a punto de particion

    


    int n = count_if(vec.begin(), vec.end(), [](int x){ return x % 2 == 0; }); //Contamos elementos que cumplen condicion

    vector<int> vec1(n);
    vector<int> vec2(vec.size() - n);

    partition_copy(vec.begin(), vec.end(), vec1.begin(), vec2.begin(),
    [](int x){ return x % 2 == 0;}); //Mandamos los elementos a dos vectores distintos segun cumplen o no condicion

    for(int i : vec1) cout << i << " ";
    cout << endl;
    for(int i : vec2) cout << i << " ";

    return 0;
}