#include <iostream>
#include <cmath>
using namespace std;

int r(int X, int Y);

int b(int X, int Y);
	
int c(int X, int Y);

int main(int argc, char *argv[]) {
	
	int X, Y, N;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> X >> Y;

		if(r(X, Y) > b(X, Y) and r(X, Y)>c(X, Y))
			cout << "Rafael ganhou" << endl;
		else if(b(X, Y) > c(X, Y))
			cout << "Beto ganhou" << endl;
		else
			cout << "Carlos ganhou" << endl;
	}
	
	return 0;
}

int r(int X, int Y){
	int resultado;
	resultado = pow(X * 3, 2) + pow(Y, 2);
	
	return resultado;
}

int b(int X, int Y){
	int resultado;
	resultado = 2 * pow(X, 2) + pow(5*Y, 2);
	
	return resultado;
}
	
int c(int X, int Y){
	int resultado;
	resultado = -100 * X + pow(Y, 3);
	
	return resultado;
}