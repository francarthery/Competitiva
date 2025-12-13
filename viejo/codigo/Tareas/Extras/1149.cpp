#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int A,N,SUMA;
	
	cin >> A >> N;
	
	while(N<=0)
		cin >> N;
	
	SUMA=N*(A+(A+(N-1)))/2;
	cout << SUMA << endl;
	
	return 0;
}



/*
Debo introducir un numero A y sumar la cantidad de consecutivos N desde
A+(A+1)+(A+2)...

((((Y-X)/2)+1)*(X+Y))/2
Cantidad de numeros*(X+Y)/2

X=Inicio intervalo
Y=Fin intervalo


N*(A+(A+(N-1)))/2

N                  *(A             +(A+(N-1))   )/2
Cantidad de numeros*(primer numero+ultimo numero)/2

3 7

3 4 5 6 7 8 9
9 8 7 6 5 4 3


*/

