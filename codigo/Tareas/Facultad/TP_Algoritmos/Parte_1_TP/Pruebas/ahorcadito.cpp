#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include "archivo.h"

using namespace std;

void seleccionar_juego(char& seleccion);
void ahorcado();
void palabra_cifrada();
void numeros_en_otro_idioma();
void memoria();
bool en_palabra(char guess, string palabra, int& posicion);
void felicitaciones(int puntos);
void buen_intento(string palabra_elegida);
void mostrar_hombrecito(int puntos);
bool ganaste(char adivinado[], string palabra);
void mostrar_hombrecito(int puntos);
string palabra_aleatoria(string linea[]);

void gotoxy(USHORT x, USHORT y) {
	COORD cp = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
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

    for(int i=0; i<100; i++)
        cout << linea[i] << endl;
    }

    cierre(Entrada);
}

void ahorcado(){
	
	int puntos = 100;
    string linea[100];
    
	leer_texto(linea);
	string palabra_elegida = palabra_aleatoria(linea);
    string letras= palabra_elegida;

	char guess, adivinado[15];
	
	for (unsigned int i = 0; i < palabra_elegida.length(); i++) {
		
		adivinado[i] = '_';
		
	}

	int posicion;
	bool victoria = false, encontrada = false;
	
	system("cls");

	string todas_las_letras = "", letras_malas = "";
	
	cout << "Ingrese una letra: ";
	
	while(puntos > 30 and !victoria) {
		
		gotoxy(19,0);
		
		cin >> guess;
		
		cout << endl;
		
		unsigned int cont = 0;
		
		while (cont < palabra_elegida.length()) {
			
			if (en_palabra(guess, letras, posicion)) {
				
				adivinado[posicion] = guess; 
				letras[posicion] = '.';
				encontrada = true;
				
			}
       
			cont++;
		}
		
		gotoxy(41,3);
		
		for (unsigned int i = 0; i < palabra_elegida.length(); i++) {
			
			cout << adivinado[i] << " ";
			
		}
		cout << endl;
		
		int aux = 0;
		
		if (!en_palabra(guess, letras_malas, aux) and !en_palabra(guess, palabra_elegida, aux))
			letras_malas += guess;
		
		gotoxy(70,3);
		cout << "Letras usadas: ";
		gotoxy(70,5);
		
		for(unsigned int i = 0; i < letras_malas.length(); i++){
			cout << letras_malas[i] << "-";
		}
		
		cout << endl;
		
		if (en_palabra(guess, todas_las_letras, posicion) and !encontrada) {
			
			gotoxy(41,5);
			
			cout << "Ese caracter ya fue usado, intente nuevamente" << endl;
			
		}
		
		else if (!en_palabra(guess, palabra_elegida, posicion)) {
			
			puntos -= 10;
			
			gotoxy(41,5);
			
			cout << "Caracter incorrecto" << endl;
			
		}

		todas_las_letras += guess;

		mostrar_hombrecito(puntos);
		
		if (ganaste(adivinado, palabra_elegida))
			victoria = true;
		
		gotoxy(0,0);
		
		cout << "Ingrese una letra: " << endl;
		
		encontrada = false;
		
	}
	
	if (victoria) {
		
		felicitaciones(puntos); //falta esto
		
	}
	else { //falta esto
		
		buen_intento(palabra_elegida); // mostrar la palabra
		
	}
	
}
	
	bool en_palabra(char guess, string palabra, int& posicion) {
		
		bool flag = false;
		unsigned int i = 0;
		
		while(!flag and palabra.length() > i){
			if(palabra[i] == guess){
				posicion = i;
				flag = true;
			}
			i++;
		}
		
		return flag;
		
	}
	
	
	bool ganaste(char adivinado[], string palabra) {
		
		bool result = true;
		
		for (unsigned int i = 0; i < palabra.length(); i++) {
			
			if (adivinado[i] != palabra[i])
				result = false;
			
		}
		
		return result;
		
	}
	
	void felicitaciones(int puntos) {
		
		system("cls");
		
		gotoxy(41,0);
		
		mostrar_hombrecito(puntos);
		
		cout << "ganaste!" << endl;
		
	}
	
	void buen_intento(string palabra_elegida) {
		
		cout << "Cerca!" << endl << "La palabra era: " << palabra_elegida << endl;
		
	}
	
	
	void mostrar_hombrecito(int puntos) {
		
		string palito[] = {
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||",
			"| |/ ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"\"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
		};
		
		string cabeza[] = {
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||.-''.",
			"| |/         |/  _  \\",
			"| |          ||  `/,|",
			"| |          (\\\\`_.'",
			"| |         .-`--'.",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"\"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
		};
		
		
		string cuerpo[] = {
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||.-''.",
			"| |/         |/  _  \\",
			"| |          ||  `/,|",
			"| |          (\\\\`_.'",
			"| |         .-`--'.",
			"| |        /Y . . Y\\",
			"| |          |   | ",
			"| |          | . |  ",
			"| |          |   |   ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"\"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
		};
		
		string brazoIzquierdo[] = {
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||.-''.",
			"| |/         |/  _  \\",
			"| |          ||  `/,|",
			"| |          (\\\\`_.'",
			"| |         .-`--'.",
			"| |        /Y . . Y\\",
			"| |       // |   | ",
			"| |      //  | . |  ",
			"| |     ')   |   |   ",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"\"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
		};
		
		string brazoDerecho[] = {
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||.-''.",
			"| |/         |/  _  \\",
			"| |          ||  `/,|",
			"| |          (\\\\`_.'",
			"| |         .-`--'.",
			"| |        /Y . . Y\\",
			"| |       // |   | \\\\",
			"| |      //  | . |  \\\\",
			"| |     ')   |   |   (`",
			"| |  ",
			"| |  ",
			"| |  ",
			"| |  ",
			"\"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
				
		};
		
		string piernaIzquierda[] = {
			
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||.-''.",
			"| |/         |/  _  \\",
			"| |          ||  `/,|",
			"| |          (\\\\`_.'",
			"| |         .-`--'.",
			"| |        /Y . . Y\\",
			"| |       // |   | \\\\",
			"| |      //  | . |  \\\\",
			"| |     ')   |   |   (`",
			"| |          || ",
			"| |          || ",
			"| |          || ",
			"| |         / | ",
			"\"\"\"\"\"\"\"\"\"\"|_`-'     |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
		};
		
		string piernaDerecha[] = {
			
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||.-''.",
			"| |/         |/  _  \\",
			"| |          ||  `/,|",
			"| |          (\\\\`_.'",
			"| |         .-`--'.",
			"| |        /Y . . Y\\",
			"| |       // |   | \\\\",
			"| |      //  | . |  \\\\",
			"| |     ')   |   |   (`",
			"| |          || ||",
			"| |          || ||",
			"| |          || ||",
			"| |         / | | \\",
			"\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
				
		};
		
		string muerto[] = {
			
			" ___________.._______",
			"| .__________))______|",
			"| | / /      ||",
			"| |/ /       ||",
			"| | /        ||.-''.",
			"| |/         |/  _  \\",
			"| |          ||  `/,|",
			"| |          (\\\\`_.'",
			"| |         .-`--'.",
			"| | ",
			"| | ",
			"     / / / | \\ \\ \\   ",
			"| |",
			"| | ",
			"  / / / / | | |  \\ \\ \\ \\         ",
			"| | ",
			"| |        /Y . . Y\\",
			"| |       // |   | \\\\",
			"| |      //  | . |  \\\\",
			"| |     ')   |   |   (`",
			"| |          || ||",
			"| |          || ||",
			"| |          || ||",
			"| |         / | | \\",
			"\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|",
			"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|",
			"| |        \\ \\        | |",
			": :         \\ \\       : :",
			". .          `'       . ."
				
		};
		
		int ejex = 40, ejey = 7;
		
		switch (puntos) {
			
		case 100:
			
			for (int i = 0; i < 22; i++) {
				
				gotoxy(ejex,ejey+i);
				cout << palito[i] << endl;
				
			}
			break;
			
		case 90: 
			
			for (int i = 0; i < 22; i++) {
				
				gotoxy(ejex,ejey+i);
				cout << cabeza[i] << endl;
				
			}
			
			break;
			
		case 80:
			
			for (int i = 0; i < 22; i++) {
				
				gotoxy(ejex,ejey+i);
				cout << cuerpo[i] << endl;
				
			}
			break;
			
		case 70:
			
			for (int i = 0; i < 22; i++) {
				
				gotoxy(ejex,ejey+i);
				cout << brazoIzquierdo[i] << endl;
			}
			break;
			
		case 60:
			
			for (int i = 0; i < 22; i++) {
				
				gotoxy(ejex,ejey+i);
				cout << brazoDerecho[i] << endl;
				
			}
			break;
			
		case 50:
			
			for (int i = 0; i < 22; i++) {
				
				gotoxy(ejex,ejey+i);
				cout << piernaIzquierda[i] << endl;
				
			}
			break;
			
		case 40:
			
			for (int i = 0; i < 22; i++) {
				
				gotoxy(ejex,ejey+i);
				cout << piernaDerecha[i] << endl;
				
			}
			break;
			
		case 30:
			
			for (int i = 0; i < 29; i++) {
				
				gotoxy(ejex,ejey+i);
				
				if (i == 11){
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
					gotoxy(ejex+4,ejey+i-1);
					
				}
				if (i > 11)
					gotoxy(ejex,ejey+i-1);
				
				if (i == 14){
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
					gotoxy(ejex+3,ejey+i-2);
					
				}
				if (i > 14)
					gotoxy(ejex,ejey+i-2);
				
				cout << muerto[i];
				
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
				
			}	
			break;
			
		default:
			
			break;
			
		}
    }

int main() {

    ahorcado();

    return 0;
}

string palabra_aleatoria(string linea[]){
	srand(time(NULL));
	
	int palabra_aleatoria = rand() % 100 + 1;
	
	string palabra_elegida = linea[palabra_aleatoria];
	
	return palabra_elegida;
}		
		
