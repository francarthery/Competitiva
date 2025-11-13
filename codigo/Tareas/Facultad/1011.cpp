#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;

#define PI 3.14159

double volumen(int R);
 
int main() {
 
    int R;

    cin >> R;

    cout << "VOLUME: " << fixed << setprecision(3) << volumen(R) << endl;
 
    return 0;
}

double volumen(int R){

    double respuesta = (4.0/3) * PI * pow(R, 3);

    return respuesta;
}