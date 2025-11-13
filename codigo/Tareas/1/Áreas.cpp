#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	
	double A,B,C,TRIANGULO,CIRCULO,TRAPECIO,CUADRADO,RECTANGULO;
	
	cin >> A >> B >> C;
	
	TRIANGULO=(A*C)/2;
	CIRCULO=3.14159*C*C;
	TRAPECIO=(A+B)/2*C;
	CUADRADO=B*B;
	RECTANGULO=A*B;
	
	cout << fixed << setprecision(3);
	cout << "TRIANGULO: " << TRIANGULO <<endl;
	cout << "CIRCULO: " << CIRCULO <<endl;
	cout << "TRAPEZIO: " << TRAPECIO <<endl;
	cout << "QUADRADO: " << CUADRADO <<endl;
	cout << "RETANGULO: " << RECTANGULO <<endl;
	
	
	return 0;
}

