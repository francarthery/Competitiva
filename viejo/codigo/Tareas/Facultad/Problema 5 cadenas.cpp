#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define TAM 1000
void cantidades(char cadena[], int &letras, int &palabras);

int main(int argc, char *argv[]) {
	
	char cadena[1000];
	int letras, palabras = 1;
	
	gets(cadena);
	
	cantidades(cadena, letras, palabras);
	
	cout << "La palabra tiene " << letras << " letras y " << palabras << " palabras" << endl;
	
	return 0;
}

void cantidades(char cadena[], int &letras, int &palabras){
	int cont = 0;
	letras = strlen(cadena);
	
	while(cadena[cont] != '\0'){
		if(cadena[cont] == ' ')
			palabras++;
		
		cont++;
	}
}



