#include <windows.h>
#include <iostream>
#include <chrono>
#include "archivo.h"
#include <cstdlib>
#include <iomanip>

#include <cctype>
using namespace std;

void cifrado(string palabra, int tamano, string &palabra_cifrada);
void cesar_feliz(int X, int Y);
void cesar_triste(int X, int Y);
void palabra_cifrada(string linea[]);
bool letra_ya_ingresada(int letras[], char letra);
bool en_palabra(char guess, string palabra, int& posicion);

char pedir_opciones(){

    char rta;
    char ingreso[15];

    gets(ingreso);
	
    if(strlen(ingreso) != 1){
        rta = '?';
    }
    else{
        rta = ingreso[0];
    }

    return rta;
}
	
void gotoxy(USHORT x, USHORT y) {
	COORD cp = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void lineas(int x1, int x2, int tamx, char c){
	if(tamx > 100)
		tamx = 100;
	
	int inicio = (100 - tamx) / 2;
	
	if(x1 != -1){
		gotoxy(inicio, x1);
		cout << setfill(c) << setw(tamx) << c << endl;
	}
	if(x2 != -1){
		gotoxy(inicio, x2);
		cout << setfill(c) << setw(tamx) << c << endl;
	}
}

void leer_texto(string linea[]){
		int contador=0;

		archivo Entrada;
		Entrada=setup("PalabrasJuegos", "palabras-1.txt");

		if (apertura(Entrada) == false){
			cout << "Error en apertura de archivo" << endl;
		}
		else{
			bool final=false;
		do{
			linea[contador]= leerLinea(Entrada,final);
			contador++;

		}while(!final);

		}

    cierre(Entrada);
}

string palabra_aleatoria(string linea[]){
	
	//Se utiliza la hora en milisegundos en lugar de time(NULL) para evitar demora por la actualizaciÃ³n de la semilla
	srand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	
	int palabra_aleatoria = rand() % 100 + 1;
	
	string palabra_elegida = linea[palabra_aleatoria];
	
	return palabra_elegida;
}

int main (){
	system("color F1");
	system("mode con: cols=100 lines=30");
	string linea[105];
	leer_texto(linea);
	palabra_cifrada(linea);
}


void palabra_cifrada(string linea[]) {
	system("cls");
	system("mode con: cols=100 lines=30");
	
	//La palabra del usuario se escoge al azar mediante la funcion palabra aleatoria
	string palabra_elegida = palabra_aleatoria(linea);
	string adivinado, palabra_cifrada;
	int tamanio = palabra_elegida.length();
	char letra;
	int letras_ingresadas[124] = {0};
	
	//Con esta funcion ciframos la palabra seleccionada de forma al azar
	cifrado(palabra_elegida, tamanio, palabra_cifrada);
	
	adivinado.resize(tamanio, '_');
	
	lineas(10, 16, 90, '-');
	gotoxy(45,12);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
	cout << "Aclaracion" << endl;
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
	gotoxy(10,14);
	cout << "Debido a limitaciones tecnicas, se usara el 4 para referenciar a la ñ en el juego";
	Sleep(5000);
	
	int intentos= 0;
	
	//Definimos la cantidad de intentos de acuerdo al tamaño de la palabra
	if(tamanio <= 5){
		intentos = tamanio*2;
	}else if(tamanio <= 10){
		intentos = tamanio;
	}else
		intentos = tamanio - 2;
	
	int contador= tamanio;
	
	bool letra_ingresada=false;
	
	do{
		system("cls");
		lineas(3, 25, 90, '-');
		gotoxy(5, 5);
		cout << "Cantidad de intentos: " << intentos;
		gotoxy(5, 7);
		cout << "Palabra cifrada:" << palabra_cifrada;
		gotoxy(5, 9);
		cout << "Letras adivinadas:" << adivinado;
		
		
		if (letra_ingresada){
			cesar_triste(52, 8);
		}else{
			cesar_feliz(52, 9);
		}
		
		gotoxy(52, 22);
		cout << "JULIO CESAR (o un intento)";
		
		int k=0;
		
		gotoxy(5, 20);
		cout << "Letras ya utilizadas:";
		
		//Este bucle contabiliza las letras que ya fueron usadas y se las muestra al usuario
		for(int i=97; i < 124; i++){
			if(letras_ingresadas[123] >= 1){
				gotoxy(5 + k, 22);
				cout << "4 (ñ)" << " "; 
				k+=2;
			}else if(letras_ingresadas[i] >= 1){
			   gotoxy(5+k, 22);
				cout << (char) i << " ";
				k+=2;
			}
		}
		
		gotoxy(55, 5);
		cout << "Ingrese una letra: ";
		letra = pedir_opciones();
		
		//Pasamos la letra a minuscula para evitar inconvenientes
		letra= tolower(letra); 
	
		//Ingresamos la letra a una cadena de caracteres con subindices de acuerdo al ASCII para llevar un control  
		for(int i=97; i < 124; i++){
			if(letra == i){
				letras_ingresadas[i]++;
			//En caso de que la letra sea el 4 (ñ) la almacenaremos en la posicion 123
			}else if(letra == '4'){
				letras_ingresadas[123]++;
			}
		}
		
		//Verificamos por medio de una funcion y de la cadena anterior si la letra ya fue ingresada antes o no
		if(letra_ya_ingresada(letras_ingresadas, letra)){
			//Verificamos si la letra ingresada pertenece al rango en el que estamos trabajando
			if((letra >= 'a' and letra <= 'z') or letra=='4'){
				
				letra_ingresada = true;
				//En este bucle se recorre la palabra original para saber si reemplazar sus letras en el string de letras adivinadas
				for (int i = 0; i < tamanio; i++) {
					//Si el usuario adivina se cambiaran las letras adivinadas en el string de adivinadas
					if (palabra_elegida[i] == letra){
						adivinado[i] = palabra_elegida[i];
						contador--;
						cesar_feliz(52, 9);
						letra_ingresada = false;
					}
				}
				gotoxy(0, 40);
				//Si el usuario no adivina la cantidad de intentos disminuye en 1 unidad
				if (letra_ingresada){
					cesar_triste(52, 8);
					intentos--;
				}
				
			}else{
				gotoxy(5, 11);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
				cout << "Recuerde que debe ingresar una LETRA" << endl;
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
				Sleep(2500);
				lineas(-1, 7, 98, ' ');
			}
			
		}else{
			gotoxy(5,11);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
			cout << "Esa letra ya fue ingresada" << endl;
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
			Sleep(1000);
			lineas(-1, 7, 98, ' ');
		}
		
	}while (intentos > 0 and contador > 0);
	
	system("cls");
	lineas(2, 24, 50, '-');
	
	//Mensaje de victoria
	if(contador == 0){
		cesar_feliz(37, 11);
		
		gotoxy(44, 4);
		cout << "GANASTE :)";
		gotoxy(37, 6);
		cout << "No serás pariente de Cesar?";
		gotoxy(37,8);
		cout << "Palabra ganadora: " << palabra_elegida;
		
	//Mensaje de derrota
	}else{
		cesar_triste(37, 10);
		
		gotoxy(44, 4);
		cout << "PERDISTE :(";
		gotoxy(39, 6);
		cout << "Más suerte la próxima!";
		gotoxy(37, 8);
		cout << "La palabra era: " << palabra_elegida;
	}
	
	gotoxy(35, 26);
	cout << "Presione enter para continuar";
	cin.ignore();
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		break;
		cin.ignore();
	}
}

void cifrado(string palabra, int tamano, string &palabra_cifrada) {
	//En este bucle se trabaja con los casos que se dificulta su trabajo por la ñ
	for (int i = 0; i < tamano; i++) {
		if (palabra[i] == 'a') {
			palabra_cifrada += '4';
		}else if (palabra[i] == 'm'){
			palabra_cifrada += 'z';
		}else if (palabra[i] == '4'){
			palabra_cifrada+= 'b';
		}else if (palabra[i] == 'n'){
			palabra_cifrada+= 'a';
			
		//Una vez que superamos a la ñ las letras que posteriores necesitan que el registro sea circular
		}else if (palabra[i] > 'n') {
			palabra_cifrada += 'a' + (13 - ('z' - palabra[i]));
		//Las anteriores a la ñ no necesitan ello 
		}else{
			palabra_cifrada += palabra[i] + 13;
		}
		//Nuestro offset era de 14 pero al trabajar en el ASCII sin la ñ esto implicaria que debamos movernos 13 posiciones en lugar de 14
	}
}
void cesar_feliz(int X, int Y){
	
	string cesar1[12] = {
		"     oooooooooooooo ",
		"   oo   ________   oo",
		"  oo     ______     oo",
		" |   ___         ___  |",
		"|  -/ O           O \\- |",
		"|          |           |",
		"|          |           |",
		"|         /_           |",
		"|                      |",
		"|      \\_________/     |",
		" \\                    /",
		"  \\__________________/ "
	};
	
	for(int i = 0; i < 12; i++){
		gotoxy(X, Y + i);
		cout << cesar1[i];
	}
	
}
void cesar_triste(int X, int Y){
	
	string cesar2[13] = {
		"     oooooooooooooo ",
		"   oo   ________   oo",
		"  oo     ______     oo",
		" |   ___         ___  |",
		"|  -/ O           O \\- |",
		"|          |           |",
		"|          |           |",
		"|         /_           |",	
		"|                      |",
		"|       _________      |",
		"|     //         \\     |",
		" \\                    /",
		"  \\__________________/ "
	};
	
	for(int i = 0; i < 13; i++){
		gotoxy(X, Y + i);
		cout << cesar2[i];
	}
	
}
	
bool letra_ya_ingresada(int letras[], char letra){
	bool rta=true;
	
	//Verificamos si la letra ya fue ingresada anteriormente o no
	for (int i=97; i < 124; i++){
		if (i == letra and letras[i] > 1){
			rta=false;
		}
	}
	return rta;
}

