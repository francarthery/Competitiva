#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "archivo.h"

using namespace std;

int main(){
string linea[100];
int contador=0;

archivo Entrada;
Entrada=setup("PalabrasJuegos", "palabras-1.txt");

if (apertura(Entrada) == false){
    cout << "Error en apertura de archivo" << endl;
}
else{
    bool final=false;
do{
    linea[contador]= leerLinea(Entrada,final);
    contador++;

}while(!final);

for(int i=0; i<100; i++)
    cout << linea[i] << endl;
}

cierre(Entrada);

    return 0;
}
