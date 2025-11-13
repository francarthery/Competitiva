#include <iostream>

using namespace std;

int main() {
	
	int N,X;
	string RESPUESTA;
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> X;
		if(X%2==0)
			if(X<0)
				RESPUESTA=RESPUESTA+"EVEN NEGATIVE\n";
			else if(X==0)
				RESPUESTA=RESPUESTA+"NULL\n";
			else
				RESPUESTA=RESPUESTA+"EVEN POSITIVE\n";
		else
			if(X<0)
				RESPUESTA=RESPUESTA+"ODD NEGATIVE\n";
			else
				RESPUESTA=RESPUESTA+"ODD POSITIVE\n";}
	
	size_t tam= RESPUESTA.length(); //obtenemos el tamaño del string
	
	RESPUESTA.erase(tam-1); //con la funcion erase(), borramos los caracteres
	//desde la posicion que le damos como argumento hasta el final  
	//ahora la palabra tendra 1 caracter menos

	cout << RESPUESTA <<endl;
	

	return 0;
}
