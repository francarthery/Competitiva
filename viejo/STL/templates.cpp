#include <iostream>

using namespace std;

template<typename T> //El tipo de dato viene especificado como un parametro a la funcion
T myMax(T x, T y)
{
    return (x > y ? x : y);
}

template<class T>
void bubbleSort(T a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; i < j; j--){
            if(a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}

int main(){

    cout << myMax<int>(3, 7) << endl;
    cout << myMax<char>('e', 'a') << endl;
    cout << myMax(1.2232, 0.9378) << endl; //No es necesario indicar el tipo de dato ya que lo deduce el compilador

    //int a[5] = {2, 0, 52, -36, 12};
    char a[6] = {'a', 'y', 'r', 'w', 'e', 'j'};

    int n = sizeof(a) / sizeof(a[0]);

    bubbleSort<char>(a, n); //Se puede ordenar un array de cualquier tipo

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}