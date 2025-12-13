#include <iostream>
#include <cstring>

using namespace std;

void borrarespacios(char palabra[], int &contador);

#define TAM 1000

int main(int argc, char *argv[]) {
	
	char palabra[TAM];
	int contador = 0;
	bool flag = true, capi = true;
	
	gets(palabra);
	
	while(flag){
		if(palabra[contador] == '\0')
			flag = 0;
		
		contador++;
	}
	contador--;
	
	borrarespacios(palabra, contador);
	
	for(int i = 0; i < contador / 2; i++){
		if(palabra[i] != palabra[contador - i - 1])
			capi = false;
	}
	
	if(capi)
		cout << "Es capicua" << endl;
	else
		cout << "No es capicua" << endl;
	
	return 0;
}

void borrarespacios(char palabra[], int &contador){
	
	for(int i = 0; i < contador; i++){
		if(palabra[i] == ' '){
			for(int j = i; j < contador - 1; j++)
				palabra[j] = palabra[j + 1];
			contador--;
			i--;
		}
	}
}
	
