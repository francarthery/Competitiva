#include <iostream>

using namespace std;

int main() {
	
	int N,PARES,RESULTADO;
	
	cin >> N;
	
	PARES=2;
	
	for(PARES=2; PARES<=N; PARES=PARES+2){
		RESULTADO=PARES*PARES;
		cout << PARES << "^" << PARES << " = " << RESULTADO << endl;}
	
	return 0;
}

/* Recibo N debe ser 5<N<2000
Miro el intervalo de pares desde 1 hasta N
calculo el cuadrado de cada par y lo muestro

Comienzo en 2 y le voy sumando +2 y calculo el cuadrado de eso
hasta llegar a N

No puedo mostrar la salida en notación científica*/
