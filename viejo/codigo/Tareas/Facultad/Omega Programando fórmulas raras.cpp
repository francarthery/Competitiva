#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define PI 3.14159

double ecuacion(double x, double y, double z){

    double resultado;

    resultado= (x + x * (y + pow(z, 2))) / ((x + PI) * (y + PI));

    return resultado;
}

int main(){

    double x, y, z;

    cin >> x >> y >> z;

    cout << fixed << setprecision(6) << ecuacion(x, y, z);

    return 0;
}