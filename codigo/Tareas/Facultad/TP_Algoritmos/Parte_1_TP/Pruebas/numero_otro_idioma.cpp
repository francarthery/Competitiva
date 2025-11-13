#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

char pedir_opciones();

void apariencia(int idioma, int numero);
void graficos(int num, int magnitud, int X, int Y);
int magnitud();
void linea_h(int magnitud);
void linea_v(int magnitud, int X, int Y);

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


void numero_en_otro_idioma(){
    system("cls");
    char opcion, numero;

    lineas(8, 21, 48, '=');
    gotoxy(39, 10);
	cout << "Números en otro idioma" << endl;
	lineas(-1, 11, 28, '=');
    gotoxy(36, 12);
	cout << "1.- Espanol";
    gotoxy(36, 13);
	cout << "2.- Inglés";
    gotoxy(36, 14);
	cout << "3.- Italiano";
    gotoxy(36, 15);
	cout << "4.- Portugués";
    gotoxy(36, 16);
	cout << "5.- Francés";
    gotoxy(36, 17);
	cout << "Ingrese una opción: ";
    gotoxy(36, 18);
	cout << "Ingrese un numero del 1 al 9: ";

	gotoxy(56, 17);
    opcion = pedir_opciones();
    
    gotoxy(66, 18);
    numero = pedir_opciones();

    if(numero < '0' or numero > '9'){
        opcion = 0;
    }

	switch(opcion){
	case '1':
		apariencia(1, int(numero - '0'));
		break;
		
	case '2':
		apariencia(2, int(numero - '0'));
		break;
		
	case '3':
		apariencia(3, int(numero - '0'));
		break;
		
	case '4':
		apariencia(4, int(numero - '0'));
		break;
		
	case '5':
		apariencia(5, int(numero - '0'));
		break;

	default:
		gotoxy(26, 20);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Ingreso de datos incorrecto" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(2000);
        numero_en_otro_idioma();
		break;
	}
}
//Ingresan los datos a un array de caracteres para evitar errores en el caso de que el usuario ingrese mas de un dígito.
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

void apariencia(int idioma, int numero){

    system("cls");
    string numeros[5][10] = {
        {"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve"},
        {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
        {"Zero", "Uno", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove"},
        {"Zero", "Um", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"},
        {"Zéro", "Un", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf"}
    };
    string idiomas[5] = {"español", "inglés", "italiano", "portugués", "francés"};

    lineas(3, 8, 70, '~');
    gotoxy(20, 5);
    cout << "Forma escrita en " << idiomas[idioma - 1] << ": " << numeros[idioma - 1][numero];

    int mag = magnitud();
    graficos(numero, mag, 46, 11);
}

void graficos(int num, int magnitud, int X, int Y){
    
    if(num == 0 or num == 2 or num == 3 or num == 5 or num == 6 or num == 7 or num == 8 or num == 9){
        gotoxy(X + 1, Y);
        linea_h(magnitud);
    }
    if(num == 2 or num == 3 or num == 4 or num == 5 or num == 6 or num == 8 or num == 9){
        gotoxy(X + 1, Y + magnitud + 1);
        linea_h(magnitud);
        }
    if(num == 0 or num == 2 or num == 3 or num == 5 or num == 6 or num == 8 or num == 9){
        gotoxy(X + 1, Y + 2 * magnitud + 2);
        linea_h(magnitud);
    }

    if(num == 0 or num == 4 or num == 5 or num == 6 or num == 8 or num == 9){ 
        linea_v(magnitud, X, Y);
    }
    if(num == 0 or num == 2 or num == 6 or num == 8){
        linea_v(magnitud, X, Y + magnitud + 1);
    }
    if(num == 0 or num == 1 or num == 2 or num == 3 or num == 4 or num == 7 or num == 8 or num == 9){
        linea_v(magnitud, X + magnitud + 1, Y);
    }
    if(num == 0 or num == 1 or num == 3 or num == 4 or num == 5 or num == 6 or num == 7 or num == 8 or num == 9){
        linea_v(magnitud, X + magnitud + 1, Y + magnitud + 1);
    }
}

void linea_h(int magnitud){
    for(int i = 0; i < magnitud; i++){
        cout << "-";
    }
}

void linea_v(int magnitud, int X, int Y){
    Y++;
    for(int i = Y; i < Y + magnitud; i++){
        gotoxy(X, i);
        cout << "|";
    }
}
    
int magnitud(){

    int numero;
    gotoxy(78, 6);
    cout << "            ";
    gotoxy(20, 6);
    cout << "En qué magnitud desea el gráfico (Magnitudes del 1 al 4): ";
    numero = pedir_opciones() - '0';

    if(numero < 0 or numero > 4){
        gotoxy(15, 7);
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "La magnitud ingresada no es correcta";
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(1800);
        numero = magnitud();
    }

    return numero;

}

int main(){

    numero_en_otro_idioma();
    Sleep(5000);

    return 0;
}