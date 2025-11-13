#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,INTENTOS,DIVISORES;
	string RESPUESTA;
	cin >> INTENTOS;
	
	for(int i=0; i<INTENTOS; i++){
		cin >> N;
		DIVISORES=2;
		while(N%DIVISORES!=0 and DIVISORES!=N)
			DIVISORES++;
	
		if(DIVISORES==N)
			RESPUESTA=RESPUESTA+to_string(N)+" eh primo\n";
		else
			RESPUESTA=RESPUESTA+to_string(N)+" nao eh primo\n";
	}	 
	size_t tam= RESPUESTA.length(); 
	RESPUESTA.erase(tam-1);
	cout << RESPUESTA <<endl;
	
	return 0;
}

