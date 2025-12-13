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

int main(){

    menu_principal();

    return 0;
}

void menu_principal(){
	char opcion, confirmacion;
	bool c = false;
    system("cls");

    lineas(8, 18, 40, '=');
    gotoxy(43, 10);
	cout << "Menu Principal";
	lineas(-1, 11, 26, '=');
    gotoxy(37, 12);
	cout << "1.- Abecedarios";
    gotoxy(37, 13);
	cout << "2.- Juegos";
    gotoxy(37, 14);
	cout << "X.- Salir de la aplicacion";
    gotoxy(37, 15);
	cout << "Ingrese una opcion: ";
	cin >> opcion;

	switch(opcion){
	case '1':
		//menu_abecedarios();
		break;
		
	case '2':
		//menu_juegos();
		break;
		
	case 'X':
        gotoxy(30, 17);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "¿Esta seguro que desea salir de la aplicacion? [S/N]: ";
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);

		do{
			cin >> confirmacion;

			if(confirmacion == 'S'){
                lineas(17, -1, 90, ' ');
                gotoxy(30, 17);
				cout << "Gracias por su visita. Hasta pronto!" << endl;
                Sleep(2000);
				c = true;
			}else if(confirmacion == 'N'){
				menu_principal();
				c = true;
			}else{
                gotoxy(30, 17);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
                cout << "Caracter incorrecto. Ingrese confirmacion nuevamente: " << endl;
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
                gotoxy(84, 17);
                cout << "         ";
                gotoxy(84, 17);
			}

		}while(!c);
		break;
		
	default:
        gotoxy(30, 17);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "La opcion ingresada no es correcta" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(2000);
		menu_principal();
		break;
	}
}