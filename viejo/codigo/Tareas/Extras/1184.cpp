#include <iostream>
#include <array>
#include <string.h>
#include <iomanip>

using namespace std;

int main() {
	
    //L:Line    O:Operation
	int L, C_DIAG, FOR_C=0;
    char O;
    float M[12][12], R=0, N=1;

    cin >> O;

    //Se rellena array por fila(primero 12 valores fila 0. Luego 12 valores fila 1...)
    for(int f=0; f<12; f++){
        for(int c=0; c<12; c++){
            cin >> N;
            M[f][c]=N;
            }}
    
    //Se suman todas las variables de la zona seleccionada
    for(int f=0; f<12; f++){
        for(int c=0; c<FOR_C; c++)
            R+=M[f][c];
        FOR_C++;
            }
    //Si la operación pedida era promedio se divide la suma por los valores(12)
    if(O=='M')
        R/=66;

    cout << fixed << setprecision(1) << R << endl;
       
	return 0;
}