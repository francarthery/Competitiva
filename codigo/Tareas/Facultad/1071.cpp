#include <iostream>

using namespace std;

void sum_impares(int X, int Y, int &resultado);

int main() {
	
	int X, Y, resultado=0;
	
	cin >> X >> Y;

    sum_impares(X, Y, resultado);
	
	cout << resultado << endl;
	
		return 0;
}

void sum_impares(int X, int Y, int &resultado){

    int aux;

    if(X > Y){
		aux = X;}
		X = Y;
		Y = aux;
	
	if(Y % 2==0)
	    Y--;
	else
		Y-=2;
	
	if(X % 2==0)
		X++;
	else
		X+=2;
	
	for(int i = X; i <= Y; i += 2)
		resultado += i;
}