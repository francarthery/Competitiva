#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

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

void menu_abecedarios(){
	char opcion, confirmacion;
	bool c= false;
    system("cls");
	
    lineas(8, 21, 48, '=');
    gotoxy(43, 10);
	cout << "Menu Abecedario" << endl;
	lineas(-1, 11, 28, '=');
    gotoxy(36, 12);
	cout << "1.- Espanol";
    gotoxy(36, 13);
	cout << "2.- Ingles";
    gotoxy(36, 14);
	cout << "3.- Italiano";
    gotoxy(36, 15);
	cout << "4.- Portugues";
    gotoxy(36, 16);
	cout << "5.- Frances";
    gotoxy(36, 17);
	cout << "X.- Volver al menu principal";
    gotoxy(36, 18);
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	
	switch(opcion){
	case '1':
		//espanol();
		break;
		
	case '2':
		//ingles();
		break;
		
	case '3':
		//italiano();
		break;
		
	case '4':
		//portugues();
		break;
		
	case '5':
		//frances();
		break;
		
	case 'X':	
		gotoxy(26, 20);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Esta seguro que desea volver al menu principal? [S/N]: ";
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		do{
			cin >> confirmacion;
			
			if(confirmacion == 'S'){
				//menu_principal();
				c = true;
				
			}else if(confirmacion == 'N'){
				menu_abecedarios();
				c = true;
				
			}else{
				gotoxy(26, 20);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
                cout << "Caracter incorrecto. Ingrese confirmacion nuevamente: " << endl;
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
                gotoxy(80, 20);
                cout << "         ";
                gotoxy(80, 20);
			}
			
		}while(!c);    
		break;
		
	default:
		gotoxy(26, 20);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "La opcion ingresada no es correcta" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(3000);
		menu_abecedarios();
		break;
	}
}

int main(){
    menu_abecedarios();
}
