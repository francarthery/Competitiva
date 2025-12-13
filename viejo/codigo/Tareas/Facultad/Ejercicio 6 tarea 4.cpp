#include <iostream>

using namespace std;

void escalera_ascendente(int k, char C);

void escalera_descendente(int k, char C);

void cubo(int k, char C);

int main(){

    int k, T;
    char C;

    cout << "Ingrese el tamaño de la escalera y el caracter" << endl;

    cin >> k >> C;

    cout << "Ingrese el tipo de escalera: 1: cubo, 2: descendente, 3: ascendente" << endl;

    cin >> T;

    switch(T){
        case(1):
            cubo(k, C);
            break;
        case(2):
            escalera_descendente(k, C);
            break;
        case(3):
            escalera_ascendente(k, C);
            break;
        default:
            cout << "Código incorrecto" << endl;

    }

    return 0;
}

void escalera_ascendente(int k, char C){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < i + 1; j++){
            cout << C << " ";
        }
        cout << endl;
    }
}

void escalera_descendente(int k, char C){
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < 6 - i; j++){
            cout << C << " ";
        }
        cout << endl;
    }
}

void cubo(int k, char C){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cout << C << " ";
        }
        cout << endl;
    }
}