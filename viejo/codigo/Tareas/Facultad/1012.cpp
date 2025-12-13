#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;

#define PI 3.14159

double triangulo(float A, float C);
double circulo(float C);
double trapecio(float A, float B, float C);
double cuadrado(float B);
double rectangulo(float A, float B);
 
int main() {
 
    float A, B, C;

    cin >> A >> B >> C;

    cout << fixed << setprecision(3) << "TRIANGULO: " << triangulo(A, C) << endl;
    cout << "CIRCULO: " << circulo(C) << endl;
    cout << "TRAPEZIO: " << trapecio(A, B, C) << endl;
    cout << "QUADRADO: " << cuadrado(B) << endl;
    cout << "RETANGULO: " << rectangulo(A, B) << endl;
 
    return 0;
}

double triangulo(float A, float C){

    double area = (A * C) / 2.0;

    return area;
}
double circulo(float C){
    double area = PI * pow(C, 2);

    return area;
}
double trapecio(float A, float B, float C){
    double area = ((A + B) / 2.0) * C;

    return area;
}
double cuadrado(float B){
    double area = pow(B, 2);

    return area;
}
double rectangulo(float A, float B){
    double area = A * B;

    return area;
}