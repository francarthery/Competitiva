#include <iostream>
#include <array>
#include <string.h>
#include <iomanip>

using namespace std;

int main() {
	
    //L:Line    O:Operation
	int FOR_C=11, INICIO_C=1;
    char O;
    float M[12][12], R=0, N=1;

    cin >> O;

    //Se rellena array por fila(primero 12 valores fila 0. Luego 12 valores fila 1...)
    for(int f=0; f<12; f++){
        for(int c=0; c<12; c++){
            //cin >> N;
            M[f][c]=N;
            N++;
            }}
    
    //Se suman todas las variables de la zona seleccionada
    for(int f=0; f<5; f++){
        for(int c=INICIO_C; c<FOR_C; c++)
            R+=M[f][c];
        FOR_C--;
        INICIO_C++;
            }
    //Si la operación pedida era promedio se divide la suma por los valores(12)
    if(O=='M')
        R/=30;

    cout << fixed << setprecision(1) << R << endl;
       
	return 0;
}
