#include <iostream>
#include <array>
#include <string.h>
#include <iomanip>

using namespace std;

int main() {
	
    //C:Column    O:Operation
	int C;
    char O;
    float M[12][12], R=0, N;

    cin >> C;
    cin >> O;

    //Se rellena array por fila(primero 12 valores fila 0. Luego 12 valores fila 1...)
    for(int f=0; f<12; f++){
        for(int c=0; c<12; c++){
            cin >> N;
            M[c][f]=N;
            }}
    
    //Se suman todas las variables de la fila seleccionada
    for(int l=0; l<12; l++){
        R+=M[C][l];}

    //Si la operación pedida era promedio se divide la suma por los valores(12)
    if(O=='M')
        R/=12;

    cout << fixed << setprecision(1) << R << endl;
       
	return 0;
}