#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> //Para accumulate solo

using namespace std;

void printVec(vector<int> v1){
    for(int i: v1)
        cout << i << " ";
    cout << endl;
}

int main(){

    vector v1{1, 5, -2, 8, 0, 91, 7, 12, -55, 83, 7, 54, -64};
    printVec(v1);
    
    sort(v1.begin(), v1.end()); //Ordenar vector ascendentemente;
    printVec(v1);

    sort(v1.begin(), v1.end(), greater<int>()); //Ordenar vector descendentemente;
    printVec(v1);

    stable_sort(v1.begin(), v1.end()); //Ordena manteniendo orden relativo de elementos iguales.

    reverse(v1.begin(), v1.end()); //Invertir elementos vector
    printVec(v1);

    cout << *max_element(v1.begin(), v1.end()) << endl; //Maximo elemento vector

    cout << *min_element(v1.begin(), v1.end()) << endl; //Minimo elemento vector

    cout << accumulate(v1.begin(), v1.end(), 0) << endl; //Suma elementos vector

    cout << binary_search(v1.begin(), v1.end(), 5) << endl; //Devuelve true or false si esta o no el valor.

    cout << *lower_bound(v1.begin(), v1.end(), 91) << endl; //Devuelve iterador a primer elemento no menor.

    cout << *upper_bound(v1.begin(), v1.end(), 12) << endl; //Devuelve iterador a primer elemento mayor

    cout << count(v1.begin(), v1.end(), 7) << endl; //Muestra cantidad de apariciones de x

    cout << *find(v1.begin(), v1.end(), 7) << endl; //Devuelve iterador a primer aparicion de x

    v1.erase(find(v1.begin(), v1.end(), 0)); //Elimina elemento al que apunta un iterador
    printVec(v1);

    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    printVec(v1); //Elimina los elementos duplicados en el vector

    cout << distance(v1.begin(), max_element(v1.begin(), v1.end())) << endl; //Calcula distancia entre dos iteradores

    return 0;
}