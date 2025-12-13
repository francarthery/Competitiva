#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int r(int X, int Y){
	int resultado;
	resultado=pow(X*3, 2)+pow(Y, 2);
	
	return resultado;
}

int b(int X, int Y){
	int resultado;
	resultado=2*pow(X, 2)+pow(5*Y, 2);
	
	return resultado;
}
	
int c(int X, int Y){
	int resultado;
	resultado=-100*X+pow(Y, 3);
	
	return resultado;
}

int main(int argc, char *argv[]) {
	
	int X,Y,N;
	string RESPUESTA;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> X >> Y;
		if(r(X,Y)>b(X,Y) and r(X,Y)>c(X,Y))
			RESPUESTA+="Rafael ganhou\n";
		else if(r(X,Y)<b(X,Y) and b(X,Y)>c(X,Y))
			RESPUESTA+="Beto ganhou\n";
		else
			RESPUESTA+="Carlos ganhou\n";
	}
	size_t tam= RESPUESTA.length(); 
	RESPUESTA.erase(tam-1);
	cout << RESPUESTA <<endl;
	
	return 0;
}

