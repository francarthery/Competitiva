#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
//#include "archivo.h"
#include <fstream>

using namespace std;


void espanol_juego();
void ingles_juego();
void portugues_juego();
void italiano_juego();
void frances_juego();

void grafico(int numero, int magnitud);
void magnitud (int);

int main(){

int opcion;

    /*lineas(8, 21, 48, '=');
    gotoxy(43, 10);*/
	cout << "Números en otro idioma" << endl;
	/*lineas(-1, 11, 28, '=');
    gotoxy(36, 12);*/
	cout << "1.- Espanol";
    //gotoxy(36, 13);
	cout << "2.- Inglés";
    //gotoxy(36, 14);
	cout << "3.- Italiano";
    //gotoxy(36, 15);
	cout << "4.- Portugués";
   // gotoxy(36, 16);
	cout << "5.- Francés";
    //gotoxy(36, 18);
	cout << "Ingrese una opción: ";

	cin >> opcion;
	
	switch(opcion){
	case '1':
		espanol_juego();
		break;
		
	case '2':
		ingles_juego();
		break;
		
	case '3':
		italiano_juego();
		break;
		
	case '4':
		portugues_juego();
		break;
		
	case '5':
		frances_juego();
		break;

	default:
		//gotoxy(26, 20);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "La opción ingresada no es correcta" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(3000);
		//numeros_en_otro_idioma();
		break;
	}
    return 0;
}

void espanol_juego(){
int numero;

cout << "Ingrese el número que desee conocer (del 0 al 9):";
cin >> numero;

switch(numero){
    case 0:
    cout << "Forma escrita en espanol:" << " Cero";
        magnitud(numero);
    break;

    case 1:
        cout << "Forma escrita en espanol:" << " Uno";
        magnitud(numero);
    break;

    case 2:
        cout << "Forma escrita en espanol:" << " Dos";
        magnitud(numero);
    break;

    case 3:
        cout << "Forma escrita en espanol:" << " Tres";
        magnitud(numero);
    break;

    case 4:
        cout << "Forma escrita en espanol:" << " Cuatro";
        magnitud(numero);
    break;

    case 5:
        cout << "Forma escrita en espanol:" << " Cinco";
        magnitud(numero);
    break;

    case 6:
        cout << "Forma escrita en espanol:" << " Seis";
        magnitud(numero);
    break;

    case 7:
        cout << "Forma escrita en espanol:" << " Siete";
        magnitud(numero);
    break;

    case 8:
        cout << "Forma escrita en espanol:" << " Ocho";
        magnitud(numero);
    break;

    case 9:
        cout << "Forma escrita en espanol:" << " Nueve";
        magnitud(numero);
    break;

    default:
        cout << "El numero ingresado no es valido";
        Sleep(600);
        system("cls");
        espanol_juego();
    break;
}
}

void ingles_juego(){
int numero;

cout << "Ingrese el número que desee conocer:";
cin >> numero;

switch(numero){
    case 0:
    cout << "Forma escrita en inglés:" << " Zero";
        magnitud(numero);
    break;

    case 1:
        cout << "Forma escrita en inglés:" << " One";
        magnitud(numero);
    break;

    case 2:
        cout << "Forma escrita en espanol:" << " Two";
        magnitud(numero);
    break;

    case 3:
        cout << "Forma escrita en espanol:" << " Three";
        magnitud(numero);
    break;

    case 4:
        cout << "Forma escrita en espanol:" << " Four";
        magnitud(numero);
    break;

    case 5:
        cout << "Forma escrita en espanol:" << " Five";
        magnitud(numero);
    break;

    case 6:
        cout << "Forma escrita en espanol:" << " Six";
        magnitud(numero);
    break;

    case 7:
        cout << "Forma escrita en espanol:" << " Seven";
        magnitud(numero);
    break;

    case 8:
        cout << "Forma escrita en espanol:" << " Eight";
        magnitud(numero);
    break;

    case 9:
        cout << "Forma escrita en espanol:" << " Nine";
        magnitud(numero);
    break;

    default:
        cout << "El numero ingresado no es valido";
        Sleep(600);
        system("cls");
        ingles_juego();
    break;
}
}

void portugues_juego(){
int numero;

cout << "Ingrese el número que desee conocer:";
cin >> numero;

switch(numero){
    case 0:
    cout << "Forma escrita en espanol:" << " Zero";
        magnitud(numero);
    break;

    case 1:
        cout << "Forma escrita en espanol:" << " Um";
        magnitud(numero);
    break;

    case 2:
        cout << "Forma escrita en espanol:" << " Dois";
        magnitud(numero);
    break;

    case 3:
        cout << "Forma escrita en espanol:" << " Três";
        magnitud(numero);
    break;

    case 4:
        cout << "Forma escrita en espanol:" << " Quatro";
        magnitud(numero);
    break;

    case 5:
        cout << "Forma escrita en espanol:" << " Cinco";
        magnitud(numero);
    break;

    case 6:
        cout << "Forma escrita en espanol:" << " Seis";
        magnitud(numero);
    break;

    case 7:
        cout << "Forma escrita en espanol:" << " Sete";
        magnitud(numero);
    break;

    case 8:
        cout << "Forma escrita en espanol:" << " Oito";
        magnitud(numero);
    break;

    case 9:
        cout << "Forma escrita en espanol:" << " Nove";
        magnitud(numero);
    break;

    default:
        cout << "El numero ingresado no es valido";
        Sleep(600);
        system("cls");
        portugues_juego();
    break;
}
}

void italiano_juego(){
int numero;

cout << "Ingrese el número que desee conocer:";
cin >> numero;

switch(numero){
    case 0:
    cout << "Forma escrita en espanol:" << " Zero";
        magnitud(numero);
    break;

    case 1:
        cout << "Forma escrita en espanol:" << " Uno";
        magnitud(numero);
    break;

    case 2:
        cout << "Forma escrita en espanol:" << " Due";
        magnitud(numero);
    break;

    case 3:
        cout << "Forma escrita en espanol:" << " Tre";
        magnitud(numero);
    break;

    case 4:
        cout << "Forma escrita en espanol:" << " Quattro";
        magnitud(numero);
    break;

    case 5:
        cout << "Forma escrita en espanol:" << " Cinque";
        magnitud(numero);
    break;

    case 6:
        cout << "Forma escrita en espanol:" << " Sei";
        magnitud(numero);
    break;

    case 7:
        cout << "Forma escrita en espanol:" << " Sette";
        magnitud(numero);
    break;

    case 8:
        cout << "Forma escrita en espanol:" << " Otto";
        magnitud(numero);
    break;

    case 9:
        cout << "Forma escrita en espanol:" << " Nove";
        magnitud(numero);
    break;

    default:
        cout << "El numero ingresado no es valido";
        Sleep(600);
        system("cls");
        italiano_juego();
    break;
}

}

void frances_juego(){
int numero;

cout << "Ingrese el número que desee conocer:";
cin >> numero;

switch(numero){
    case 0:
    cout << "Forma escrita en espanol:" << " Zéro";
        magnitud(numero);
    break;

    case 1:
        cout << "Forma escrita en espanol:" << " Un";
        magnitud(numero);
    break;

    case 2:
        cout << "Forma escrita en espanol:" << " Deux";
        magnitud(numero);
    break;

    case 3:
        cout << "Forma escrita en espanol:" << " Trois";
        magnitud(numero);
    break;

    case 4:
        cout << "Forma escrita en espanol:" << " Quatre";
        magnitud(numero);
    break;

    case 5:
        cout << "Forma escrita en espanol:" << " Cinq";
        magnitud(numero);
    break;

    case 6:
        cout << "Forma escrita en espanol:" << " Six";
        magnitud(numero);
    break;

    case 7:
        cout << "Forma escrita en espanol:" << " Sept";
        magnitud(numero);
    break;

    case 8:
        cout << "Forma escrita en espanol:" << " Huit";
        magnitud(numero);
    break;

    case 9:
        cout << "Forma escrita en espanol:" << " Neuf";
        magnitud(numero);
    break;

    default:
        cout << "El numero ingresado no es valido";
        Sleep(600);
        system("cls");
        frances_juego();
    break;
}

}

void magnitud(int n){
int m;
bool bandera=false;

do{
    cout << "En qué magnitud desea el gráfico (Magnitudes del 1 al 4)";
    cin >> m;

        if(m > 0 and m < 5){
            cout << "Gráfico:";
            grafico(n, m);
            bandera = true;
        }else{
                cout << "La magnitud ingresada no es correcta";
                Sleep(600);
                system("cls");
                magnitud(n);
        }

}while(!bandera);

}

void grafico(int n, int m){

}