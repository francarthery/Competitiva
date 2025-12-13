#include <iostream>
using namespace std;

int main() {
	
	double X,Y,Z,A,B,C;
	
	cin >> X >> Y >> Z;
	
	//Ordenamos valores
	if(X>Y and X>Z)
		if(Y>Z){
			A=X;
			B=Y;
			C=Z;
		}else{
			A=X;
			B=Z;
			C=Y;}
	else if(Y>X and Y>Z)
		if(X>Z){
			A=Y;
			B=X;
			C=Z;}
		else{
			A=Y;
			B=Z;
			C=X;}
	else
		if(X>Y){
			A=Z;
			B=X;
			C=Y;}
		else{
			A=Z;
			B=Y;
			C=X;}
		

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
