#include <iostream>
#include <conio.h>

using namespace std;

int main(){

    char contra[5];
    int contador = 0, caracter;

    while(true){
        //Pedimos caracter sin mostrarlo
        caracter = _getch();

        //Si es un enter salimos del bucle y colocamos caracter de fin de línea
        if(caracter == 13){
            contra[contador + 1] = '\0';
            break;
        }
        //Si es retroceso borramos el últmo caracter
        else if(caracter == 8 and contador > 0){
            cout << "\b \b";
            contador--;
        }
        //Si es un caracter normal lo almacenamos y mostramos un "*"
        else{
            contra[contador] = caracter;
            cout << "*";
            contador++;
        }
    }

    cout << endl << contra << endl;

    return 0;
}