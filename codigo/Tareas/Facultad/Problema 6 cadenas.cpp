#include <iostream>
using namespace std;

#define TAM1 1000
#define TAM2 50
	
int main(int argc, char *argv[]) {
	
	char frase[1000], palabra[50];
	
	cout << "Introduce una frase: " << endl;
	gets(frase);
	
	cout << "Introduce la palabra prohibida: " << endl;
	gets(palabra);
	
	ocurrencias(frase, palabra);
	
	cout << "La frase resultante es: " << frase << endl;
	
	return 0;
}

void ocurrencias(frase[], palabra[]){
	int cont = 0, contpalabra;
	bool aparecio, flag;
	
	while(frase[cont] != '\0'){
		contpalabra = 0;
		aparecio = false;
		
		while(contpalabra < strlen(palabra) and cont + strlen(palabra) < strlen(frase) and flag){
			if(frase[cont + contpalabra] != palabra[contpalabra])
				flag = false;
			
			contpalabra++;
		}
	}
	
}


