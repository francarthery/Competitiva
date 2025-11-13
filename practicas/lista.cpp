#include <iostream>
#include <list>

using namespace std;

//https://www.geeksforgeeks.org/list-cpp-stl/

int main(){

    //Lista doblemente enlazada
    list<int> l{1, 2, 3, 4, 5};

    //Es muy rapida para hacer insersiones y eliminaciones
    //No permite el acceso directo a una posicion cualquiera, solo secuencial

    l.push_front(0); //Insertar elemento al principio
    l.push_back(6); //Insertar elemento al final
    l.pop_back(); //Elimina el ultimo elemento de la lista
    l.pop_front(); //Elimina el primer elemento de la lista
    l.insert(next(l.begin(), 1), 2); //Insertamos un elemento
    l.erase(next(l.begin(), 2)); //Eliminamos elemento

    for(auto i: l)
        cout << i << " ";
    cout << endl;

    return 0;
}