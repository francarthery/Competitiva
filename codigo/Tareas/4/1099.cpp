#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,X,Y,MAYOR,MENOR,IMPARES,SUMA;
	string RESPUESTA;
	
	cin >> N;
	
	//Se controla cuantos numeros se ingresarán
	for(int i=0; i<N; i++){
		cin >> X >> Y;
		//Se ordenan los valores de menor a mayor
		if(Y>X){
			MAYOR=Y;
			MENOR=X;
		}else{
			MAYOR=X;
			MENOR=Y;
		}
		//Se verifica que el primer impar de la lista sea el siguiente al menor N
		if(MENOR%2==0)
			IMPARES=MENOR+1;
		else
			IMPARES=MENOR+2;
		
		SUMA=0;
		while(IMPARES<MAYOR){
			SUMA+=IMPARES;
			IMPARES+=2;
		}
		RESPUESTA=RESPUESTA+to_string(SUMA)+"\n";
	}
	size_t tam= RESPUESTA.length(); 
	RESPUESTA.erase(tam-1);
	cout << RESPUESTA <<endl;
		
	
	return 0;
}


