#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

#define TAM 100

bool autentificacion(char usuario[]);

int main(int argc, char *argv[]) {
	
	char usuario[TAM];
	
	do{
		cout << "Ingrese un usuario. Debe comenzar con una letra: ";
		gets(usuario);
		
		if(!autentificacion(usuario)){
			cout << "Password incorrecta." << endl;
		}
		else
			cout << "Usuario correcto." << endl;
		
	} while(!autentificacion(usuario));
	
	return 0;
}

bool autentificacion(char usuario[]){
	
	bool rta = false;
	
	if(isalpha(usuario[0]) and usuario[8] == '\0')
		rta = true;
	
	return rta;
}

