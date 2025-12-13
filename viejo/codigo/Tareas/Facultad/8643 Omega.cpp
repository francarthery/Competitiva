#include <iostream>
using namespace std;

void amigos(int X, int Y, int divisores[], int &cont);
int suma_divisores(int X);

#define TAM 50

int main(int argc, char *argv[]) {
	
	int X, Y, cont = 0;
	
	int divisores[TAM];
	
	cin >> X >> Y;
	
	amigos(X, Y, divisores, cont);
	
	for(int i = 0; i < cont; i++){
		
		cout << divisores[i] << endl;
	}
	
	return 0;
}

void amigos(int X, int Y, int divisores[], int &cont){
	
	int divisores_x = suma_divisores(X);
	
	for(int i = X + 1; i < Y; i++){
		
		if(divisores_x == i and suma_divisores(i) == X){
			divisores[cont] = i;
			cont++;
		}
	}
}
	
int suma_divisores(int N){
	
	int suma = 0;
	
	if(N % 2 == 0){
		for(int j = 1; j <= N / 2; j++){
			if(N % j == 0)
				suma += j;
		}
	}
	else{
		for(int j = 1; j < N / 2; j += 2){
			if(N % j == 0)
				suma += j;
		}
	}
	
	return suma;
}
