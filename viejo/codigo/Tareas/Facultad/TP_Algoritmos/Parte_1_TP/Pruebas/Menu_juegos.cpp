#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void menu_principal();
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

void menu_juegos();

int main(){

    menu_juegos();

    return 0;
}

void menu_juegos(){
	char seleccion;
	bool c= false;
	system("cls");

	lineas(8, 20, 48, '=');
    gotoxy(43, 10);
	cout << "Menú juegos" << endl; // Centrar el texto
	lineas(-1, 11, 28, '=');
    gotoxy(36, 12);
	cout << "1.- Ahorcado";
	gotoxy(36, 13);
	cout << "2.- Palabra cifrada";
	gotoxy(36, 14);
	cout << "3.- Números en otro idioma";
	gotoxy(36, 15);
	cout << "4.- Memoria";
	gotoxy(36, 16);
	cout << "X.- Volver al menú principal";
	gotoxy(36, 17);
	cout << "Ingrese una opción: ";
	
	cin >> seleccion;
	cin.ignore();
	
	
	switch (seleccion) {
		
	case '1':
		//ahorcado();
		break;
		
	case '2':
		//palabra_cifrada();
		break;

	case '3':
		//numeros_en_otro_idioma();
		break;

	case '4':
		//memoria();
		break;

	case 'X':
		gotoxy(26, 19);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Está seguro que desea volver al menú principal? [S/N]: ";
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		do{
			cin >> seleccion;

			if(seleccion == 'S'){
				//menu_principal();
				c = true;

			}else if(seleccion == 'N'){
				menu_juegos();
				c = true;

			}else {
				gotoxy(26, 19);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
                cout << "Caracter incorrecto. Ingrese confirmación nuevamente: " << endl;
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
                gotoxy(80, 19);
                cout << "         ";
                gotoxy(80, 19);
			}

		}while(!c);
		break;

	default:
		gotoxy(26, 19);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "La opción ingresada no es correcta" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(3000);
		menu_juegos();
		break;
	}
	
}