#include <iostream>
#include <iomanip>

using namespace std;

double precio_total(int, int, double, double);

int main(){

    int cod_1, cod_2, cant_1, cant_2;
    double precio_1, precio_2;

    cin >> cod_1 >> cant_1 >> precio_1 >> cod_2 >> cant_2 >> precio_2;

    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << precio_total(cant_1, cant_2, precio_1, precio_2) << endl;
    
    return 0;
}

double precio_total(int cant_1, int cant_2, double precio_1, double precio_2){

    double respuesta = cant_1 * precio_1 + cant_2 * precio_2;

    return respuesta;
}