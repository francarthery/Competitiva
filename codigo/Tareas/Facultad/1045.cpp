#include <iostream>
using namespace std;

int main() {
	
	double A, B, C, aux;
	
	cin >> A >> B >> C;
	
	//Ordenamos valores
	if (B > A and B > C){
        aux = A;
        A = B;
        B = aux;
    }
    else if(C > A and C > A){
        aux = A;
        A = C;
        C = aux;
    }

	if(A>=(B+C))
		cout << "NAO FORMA TRIANGULO" <<endl;
	else if(A*A==B*B+C*C)
		cout << "TRIANGULO RETANGULO" <<endl;
	else if(A*A>B*B+C*C)
		cout << "TRIANGULO OBTUSANGULO" <<endl;	
	else if(A*A<B*B+C*C)
		cout << "TRIANGULO ACUTANGULO" <<endl;

	if(A==B and A==C)
		cout << "TRIANGULO EQUILATERO" <<endl;
	else if(A==B or A==C or B==C)
		cout << "TRIANGULO ISOSCELES" <<endl;
	
	return 0;
}