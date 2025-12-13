#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include "archivo.h"
#include <fstream>
#include <chrono>

#define TAM 6

using namespace std;

void bienvenida();
void gotoxy(USHORT x, USHORT y);
void lineas(int, int, int, char);
bool login();
void ingresodatos(char [], char [], bool);
void ingreso_contra(char []);
bool verificacion_user(char [], int &);
bool verificacion_password(int, char []);
int inversoR (int, int);
void creditos();

void menu_principal();
char pedir_opciones();

void menu_abecedarios();
void espanol();
void ingles();
void italiano();
void portugues();
void frances();
void letras_minusculas(int, int);
void letras_mayusculas(int, int);
void acento_agudo();
void acento_grave();
void letras_circunflejo();

void menu_juegos();
void leer_texto(string []);
string palabra_aleatoria(string []);

void ahorcado(string []);
bool en_palabra(char, string, int&);
void felicitaciones();
void buen_intento(string, int );
void mostrar_hombrecito(int );
bool ganaste(char [], string );
void mostrar_hombrecito(int );

void palabra_cifrada(string []);
void cifrado(string , int, string &);
bool letra_ya_ingresada(int [], char);
void cesar_triste(int, int);
void cesar_feliz(int, int);
	
void numeros_en_otro_idioma();
void apariencia(int, int);
void graficos(int, int , int , int );
int magnitud();
void linea_h(int);
void linea_v(int, int, int);

void memoria(string []);
bool evita_repetida(string , string [], int);
void palabra_mas_grande(string [], int [], int&);
bool esVocal(char);
int cuantas_vocales(string []);
void letras_mas_repetidas(string [], char []);


int main(){
    
    bienvenida();

    if (login()) 
		menu_principal();

    return 0;
}

//------------------------------------------------- Bienvenida ------------------------------------------------------------

void bienvenida() {
    
    system("color F1");
	system("mode con: cols=100 lines=30");
	
	string texto[7] = { 
		
		" _______  ___   _______  __    _  __   __  _______  __    _  ___   ______   _______  _______    ",
		"|  _    ||   | |       ||  |  | ||  | |  ||       ||  |  | ||   | |      | |       ||       |   ",
		"| |_|   ||   | |    ___||   |_| ||  |_|  ||    ___||   |_| ||   | |  _    ||   _   ||  _____|   ",
		"|       ||   | |   |___ |       ||       ||   |___ |       ||   | | | |   ||  | |  || |_____    ",
		"|  _   | |   | |    ___||  _    ||       ||    ___||  _    ||   | | |_|   ||  |_|  ||_____  |   ",
		"| |_|   ||   | |   |___ | | |   | |     | |   |___ | | |   ||   | |       ||       | _____| |   ",
		"|_______||___| |_______||_|  |__|  |___|  |_______||_|  |__||___| |______| |_______||_______|   "};
		
	string cartel1[12] = {
		"   ___                   _                                    _                    \n",
		"  / _ \\ _ __   ___  ___ (_)  ___   _ __    ___    ___  _ __  | |_   ___  _ __      \n",
		" / /_)/| '__| / _ \\/ __|| | / _ \\ | '_ \\  / _ \\  / _ \\| '_ \\ | __| / _ \\| '__|     \n",
		"/ ___/ | |   |  __/\\__ \\| || (_) || | | ||  __/ |  __/| | | || |_ |  __/| |        \n",
		"\\/     |_|    \\___||___/|_| \\___/ |_| |_| \\___|  \\___||_| |_| \\__| \\___||_|        \n",
		"                                                                                \n",
		"                                                 _    _                            \n",
		" _ __    __ _  _ __   __ _    ___   ___   _ __  | |_ (_) _ __   _   _   __ _  _ __ \n",
		"| '_ \\  / _` || '__| / _` |  / __| / _ \\ | '_ \\ | __|| || '_ \\ | | | | / _` || '__|\n",
		"| |_) || (_| || |   | (_| | | (__ | (_) || | | || |_ | || | | || |_| || (_| || |   \n",
		"| .__/  \\__,_||_|    \\__,_|  \\___| \\___/ |_| |_| \\__||_||_| |_| \\__,_| \\__,_||_|   \n",
		"|_|                                                                                "};

	lineas(8, 19, 100, '-');
	PlaySoundA((LPCSTR) "sonido_inicio.wav", NULL, SND_FILENAME | SND_ASYNC); 

	//Deslizamiento cartel bienvenidos. Columnas:
	for(int j = 0; j < 97; j++){
		//Filas
		for(int i = 0; i < 7; i++){
			gotoxy(99 - j, 10 + i);
			
			//Cargamos cada renglon hasta donde permite el tamaño de la terminal
			for(int k = 0; k <= j; k++){
				cout << texto[i][k];
			}
		}
		//Manejo frames animación
		Sleep(15);
	}
	
	Sleep(1000);
	//Desvanecimiento. Utilizo 47 como limite ya que es la mitad del ancho en caracteres del cartel.
	for(int i = 0; i < 47; i++){
		lineas(8, 19, 100 - i*2, '-');
		for(int j = 0; j < 7; j++){
			gotoxy(3 + i, 10+ j);
			for(int k = i; k < 94 - i; k++){
				cout << texto[j][k];
			}
		}
		//Aceleramos el desvanecimiento progresivamente usando la variable i para acortar los frames.
		Sleep(50 - i);
		system("cls");
	}
	
	Sleep(500);
	
	//Segundo cartel con parpadeos.
	for(int j = 0; j < 2; j++){
		system("cls");
		Sleep(600);
		
		for(int i = 0; i < 12; i++){
			gotoxy(8, 7 + i);
			cout << cartel1[i];
		}
		Sleep(1000);
	}
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
            system("cls");
            cin.ignore();
            break;
        }
}

void gotoxy(USHORT x, USHORT y) {
	COORD cp = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

//Se utiliza para crear líneas centradas en una fila específica de la consola. 
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

//------------------------------------------------- Creditos ---------------------------------------------------------

void creditos(){

	system("cls");
	Sleep(1200);

	string creditos[5] = {
		"     Créditos",
		"                   ",
		"Carthery, Francisco",
		" González, Lautaro",
		" Hassan, Gerónimo"
	};
	
	//Deslizamiento de abajo para arriba
	for(int i = 30; i > 0; i--){
		for(int j = 0; j < 5; j++){
			if(i + j < 30){
				gotoxy(40, i + j);
				cout << creditos[j];
			}
		}
		Sleep(100);
		system("cls");
	}
	
	//Desvanecimiento parte superior pantalla
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5 - i; j++){
			gotoxy(40, (4 - i) - j);
			cout << creditos[4 - j];
			
		}
		Sleep(100);
		system("cls");
	}

	Sleep(2000);
}

//------------------------------------------------- Login ------------------------------------------------------------

bool login() {
    int contador = 0, usuarionum = 0;
    char password[TAM], usuario[TAM];
    bool valido = false;

	//Se utliza la siguiente función para los pedir datos de forma segura.
    ingresodatos(usuario, password, 0);
    
    while(!valido and contador < 3){
        
        contador++;
        if(verificacion_user(usuario, usuarionum) and verificacion_password(usuarionum, password))
            valido = true;
        else{
            if(contador < 3){
                ingresodatos(usuario, password, 1);
            }
        }
    }
    gotoxy(25, 17);
    lineas(17, -1, 90, ' ');
    

    if (contador == 3 and !valido){
		gotoxy(25, 17);
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Demasiados intentos incorrectos. Pruebe de nuevo mas tarde" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
    }
    else{
		gotoxy(45, 17);
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),250);
        cout << "Bienvenido" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
    }

    Sleep(2000);
    system("cls");
    return valido;
}


void ingresodatos(char usuario[], char password[], bool codigo){
    system("cls");
    
	//Si el ingreso anterior fue incorrecto, se le informa al usuario.
    if(codigo == 1){
        gotoxy(25, 17);
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Usuario o contrasena incorrecta. Intente nuevamente" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
    }
    
    lineas(9, 18, 50, '-');
    gotoxy(34, 12);
    cout << "Ingrese su ID de usuario: ";
    gotoxy(34, 14);
    cout << "Ingrese su contrasena: ";
    //Pedimos el usuario como cadena de caracteres para que no falle el programa si por error se manda un caracter
    gotoxy(60, 12);
    gets(usuario);
    gotoxy(57, 14);
    ingreso_contra(password);
}

void ingreso_contra(char password[]){
 
    int contador = 0, caracter;

    while(true){
        //Pedimos un caracter sin mostrarlo en consola
        caracter = _getch();

        //Si es un enter salimos del bucle y colocamos caracter de fin de línea
        if(caracter == 13){
            password[contador + 1] = '\0';
            break;
        }
        //Si es retroceso borramos el últmo caracter
        else if(caracter == 8 and contador > 0){
            cout << "\b \b";
            contador--;
        }
        //Si es un caracter normal lo almacenamos y mostramos un "*"
        else{
            password[contador] = caracter;
            cout << "*";
            contador++;
        }
    }
}

bool verificacion_user (char usuario[], int &usuarionum) {
    bool rta = true;
    usuarionum = 0;
    
    for(int i = 0; i < TAM - 1; i++){

        if(!isdigit(usuario[i]))
            rta = false;
        else
            //Si el usuario es correcto, generamos un int con el numero para procesarlo luego en verificacion_password
            usuarionum = usuarionum * 10 + (usuario[i] - '0');
    }
    if(rta and (usuarionum < 10000 or usuarionum >= 90000))
        rta = false;
   
    return rta;
}

bool verificacion_password (int usuario, char contrasena[]) {
    bool rta = true;
    int contra_correcta;
    int primer_num = usuario / 10000;
    int ultimo_num = usuario % 10;

    //Almacenamos el valor que deberia tener la contraseña para luego comparar con la ingresada
    contra_correcta = inversoR(usuario, 0) - primer_num + (primer_num + ultimo_num) % 10;
    
    for(int i = 4; i >= 0; i--){
        if(contrasena[i] - '0' != (contra_correcta % 10))
            rta = false;
        
        contra_correcta /= 10;
    }
    return rta;
}

//Funcion recursiva que invierte los digitos de un número
int inversoR(int numero, int numero_inverso){
	int digito = numero % 10;

	if (numero == 0){
		return numero_inverso;
	}else{
		numero_inverso = numero_inverso * 10 + digito;
		return inversoR(numero / 10, numero_inverso);
	}
}

//------------------------------------------------- Menu principal ------------------------------------------------------------

void menu_principal(){
	char opcion, confirmacion;
	bool c = false;
    system("cls");
    lineas(8, 18, 40, '=');
    gotoxy(43, 10);
	cout << "Menú Principal";
    gotoxy(37, 11);
	cout << setfill('=') << setw(26) << "=";
    gotoxy(37, 12);
	cout << "1.- Abecedarios";
    gotoxy(37, 13);
	cout << "2.- Juegos";
    gotoxy(37, 14);
	cout << "X.- Salir de la aplicación";
    gotoxy(37, 15);
	cout << "Ingrese una opción: ";
	opcion = pedir_opciones();

    
	switch(opcion){
	case '1':
		system("cls");
		menu_abecedarios();
		break;
		
	case '2':
		system("cls");
		menu_juegos();
		break;
		
	case 'X':
        gotoxy(30, 17);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "¿Está seguro que desea salir de la aplicación? [S/N]: ";
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);

		do{
			confirmacion = pedir_opciones();

			if(confirmacion == 'S'){
                lineas(17, -1, 90, ' ');
                gotoxy(30, 17);
				cout << "Gracias por su visita. Hasta pronto!" << endl;
                Sleep(2500);
				creditos();
				exit(0);
			}else if(confirmacion == 'N'){
				menu_principal();
				c = true;
			}else{
                gotoxy(30, 17);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
                cout << "Caracter incorrecto. Ingrese confirmación nuevamente: " << endl;
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
        cout << "La opción ingresada no es correcta" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(2000);
		menu_principal();
		break;
	}
}

//Ingresan los datos a un array de caracteres para evitar errores en el caso de que el usuario ingrese mas de un dígito.
char pedir_opciones(){

    char rta;
    char ingreso[15];

    gets(ingreso);

	//Si el largo del ingreso es mayor a un caracter. Se retorna un caracter '?' el cual no representa ninguna opción posible.
    if(strlen(ingreso) != 1){
        rta = '?';
    }
    else{
		//Si el largo es 1, se retorna el caracter que ingresó el usuario.
        rta = ingreso[0];
    }

    return rta;
}

//------------------------------------------------- Menu abecedario ------------------------------------------------------------
void menu_abecedarios(){
	char opcion, confirmacion;
	bool c = false;
    system("cls");
	
    lineas(8, 21, 48, '=');
    gotoxy(43, 10);
	cout << "Menú Abecedario" << endl;
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
	cout << "X.- Volver al menú principal";
    gotoxy(36, 18);
	cout << "Ingrese una opción: ";
	opcion = pedir_opciones();
	
	switch(opcion){
	case '1':
		espanol();
		break;
		
	case '2':
		ingles();
		break;
		
	case '3':
		italiano();
		break;
		
	case '4':
		portugues();
		break;
		
	case '5':
		frances();
		break;
		
	case 'X':	
		gotoxy(26, 20);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Está seguro que desea volver al menú principal? [S/N]: ";
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		do{
			confirmacion = pedir_opciones();
			
			if(confirmacion == 'S'){
				menu_principal();
				c = true;
				
			}else if(confirmacion == 'N'){
				menu_abecedarios();
				c = true;
				
			}else{
				gotoxy(26, 20);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
                cout << "Caracter incorrecto. Ingrese confirmación nuevamente: " << endl;
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
        cout << "La opción ingresada no es correcta" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
        Sleep(3000);
		menu_abecedarios();
		break;
	}
	
	gotoxy(35, 28);
	cout << "Presione enter para continuar";
	
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		cin.ignore();
		break;
	}
		
	if(opcion != 'X'){
		menu_abecedarios();
	}
}

void espanol(){
	Sleep(1000);
	system("cls");

	gotoxy(40, 2);
	cout << "Abecedario español";
	
	lineas(3, 23, 80, '=');
	gotoxy(10, 4);
	cout << "Letras minúsculas:";
	letras_minusculas(10, 5);
	
	gotoxy(10, 9);
	cout <<"Letras mayúsculas:";
	letras_mayusculas(10,10);
	
	gotoxy(10, 14);
	cout << "Letras acentuadas:";
	gotoxy(10, 15);
	acento_agudo();
	
	gotoxy(10, 17);
	cout << "Letra con diéresis:";
	gotoxy(10, 18);
	cout << "ü";

	gotoxy(10, 20);
	cout << "Caracteres especiales:";
	gotoxy(10, 21);
	cout << "ñ";
}
	
void ingles(){
	Sleep(1000);
	system("cls");

	gotoxy(41, 2);
	cout << "Abecedario inglés";
	
	lineas(3, 16, 80, '=');
	gotoxy(10, 4);
	cout << "Lowercase letters (letras minúsculas):";
	letras_minusculas(10, 5);
	
	gotoxy(10, 9);
	cout << "Capital letters (letras mayúsculas):";
	letras_mayusculas(10,10);
	
	gotoxy(10, 14);
	cout << "There are no accented letters (no existen letras acentuadas)" << endl;
}
	
void italiano(){
	Sleep(1000);
	system("cls");
	
	int contador=0;
	
	gotoxy(40, 2);
	cout << "Abecedario italiano";
	
	lineas(3, 23, 80, '=');
	gotoxy(10, 4);
	cout << "Lettere minuscole (letras minúsculas): ";
	gotoxy(10, 5);
	for(char i = 'a'; i <= 'z'; i++){
		cout << i << " ";
		contador++;
		
		if(i == 'i'){
			i+=2;
		}
		if(i == 'v'){
			i+=3;
		}
		if(contador%10 == 0)
		   gotoxy(10, 5 + contador / 10);        
	}
	
	gotoxy(10, 9);
	cout << "Lettere maiuscole (letras mayúsculas):" << endl;
	
	contador=0; 
	gotoxy(10, 10);
	for(char i = 'A'; i <= 'Z'; i++){
		cout << i << " ";
		contador++;
		
		if(i == 'I')
			i+=2;
		
		if(i == 'V')
			i+=3;
		
		if(contador%10 == 0)
			gotoxy(10, 10 + contador / 10);
	}
	
	gotoxy(10, 14);
	cout << "lettere con accento acuto (letras con acento agudo):";
	gotoxy(10, 15);
	cout << "é í ó ú";
	
	gotoxy(10, 17);
	cout << "Lettere gravemente accentate (letras con acento grave):";
	gotoxy(10, 18);
	acento_grave();
	
	gotoxy(10, 20);
	cout << "lettere circonflesse (letras con circunflejo):";
	gotoxy(10, 21);
	cout << "î" << endl;
	
}
void portugues(){
	Sleep(1000);
	system("cls");
	
	gotoxy(40, 2);
	cout << "Abecedario portugués";

	lineas(3, 26, 80, '=');
	gotoxy(10, 4);
	cout << "Letras minúsculas:";
	letras_minusculas(10,5);
	
	gotoxy(10, 9);
	cout << "Letras maiusculas (letras mayúsculas):";
	letras_mayusculas(10,10);
	
	gotoxy(10, 14);
	cout << "Letras com acento agudo (letras con acento agudo):";
	gotoxy(10,15);
	acento_agudo();
	
	gotoxy(10, 17);
	cout << "Letras com acentos graves (letras con acento grave):";
	gotoxy(10, 18);
	cout << "à";
	
	gotoxy(10, 20);
	cout << "Letras circunflexas (letras con circunflejo):";
	gotoxy(10, 21);
	cout << "â ê ô";
	
	gotoxy(10, 23);
	cout << "Caracteres especiales";
	gotoxy(10, 24);
	cout << "ç";
}
	
void frances(){
	Sleep(1000);
	system("cls");
	
	gotoxy(40, 2);
	cout << "Abecedario francés";
	
	lineas(3, 26, 80, '=');
	gotoxy(10, 4);
	cout << "Lettres minuscules (letras minúsculas):";
	letras_minusculas(10,5);
	
	gotoxy(10, 9);
	cout << "Lettres majuscules (letras mayúsculas):";
	letras_mayusculas(10,10);
	
	gotoxy(10, 14);
	cout << "Lettres avec accent  aigu (letras con acento agudo):";
	gotoxy(10, 15);
	cout << "é";
	
	gotoxy(10,17);
	cout << "Lettres avec accent grave (letras con acento grave):";
	gotoxy(10, 18);
	cout << "à è ù";
	
	gotoxy(10, 20);
	cout << "Lettres circonflexes (letras con circunflejo):";
	gotoxy(10, 21);
	letras_circunflejo();
	
	gotoxy(10, 23);
	cout << "Lettres avec tréma (letras con diéresis):";
	gotoxy(10, 24);
	cout << "ë ï ü ÿ";
	
}
	
void letras_minusculas(int X, int Y){
	
	int contador=0;
	gotoxy(X, Y);

	for(char i = 'a'; i <= 'z'; i++){
		cout << i << " ";
		contador++;
		
		if(contador%10 == 0)
			gotoxy(X, Y + contador / 10);
	}
}
	
void letras_mayusculas(int X, int Y){
	
	int contador=0;
	gotoxy(X, Y);
	
	for(char i= 'A'; i <= 'Z'; i++){
		cout << i << " ";
		contador++;
		
		if(contador%10 == 0)
			gotoxy(X, Y + (contador / 10));
	}
}
	
void acento_agudo(){
	cout << "á é í ó ú" << endl;
}
	
void acento_grave(){
	cout << "à è ì ò ù" << endl;
}
	
void letras_circunflejo(){
	cout << "â ê î ô û" << endl;
}
	
//------------------------------------------------- Menu juegos ------------------------------------------------------------

void menu_juegos(){
	char seleccion;
	bool c= false;
	system("cls");

	//Se cargan 100 palabras al array línea desde un archivo externo
	string linea[105];
	leer_texto(linea);

	lineas(8, 20, 48, '=');
    gotoxy(43, 10);
	cout << "Menú juegos";
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
	
	seleccion = pedir_opciones();
	
	switch (seleccion) {
		
	case '1':
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), 7);
		ahorcado(linea);
		break;
		
	case '2':
		palabra_cifrada(linea);
		break;

	case '3':
		numeros_en_otro_idioma();
		break;

	case '4':
		memoria(linea);
		break;

	case 'X':
		gotoxy(26, 19);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Está seguro que desea volver al menú principal? [S/N]: ";
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		do{
			seleccion = pedir_opciones();

			if(seleccion == 'S'){
				menu_principal();
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
	
	if(seleccion != 'X'){
		menu_juegos();
	}
}
//Retorna una palabra de forma aleatoria del array linea
string palabra_aleatoria(string linea[]){
	
	//Se utiliza la hora en milisegundos en lugar de time(NULL) para evitar demora por la actualización de la semilla
	srand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	
	int palabra_aleatoria = rand() % 100 + 1;
	
	string palabra_elegida = linea[palabra_aleatoria];
	
	return palabra_elegida;
}
//Utiliza un TDA para extraer información de un archivo .txt
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

//------------------------------------------------- Ahorcado ------------------------------------------------------------
void ahorcado(string linea[]){
	
	system("mode con: cols=100 lines=40");
	
	int puntos = 100;
	
	string palabra_elegida = palabra_aleatoria(linea);
    string letras= palabra_elegida;

	char guess, adivinado[15];

	// se llena el array de las letras que se van adivinando con _
	for (unsigned int i = 0; i < palabra_elegida.length(); i++) {
		
		adivinado[i] = '_';
		
	}
	
	int posicion;
	bool victoria = false, encontrada = false;
	
	system("cls");

	string todas_las_letras = "", letras_malas = "";
	
	gotoxy(35,3);

	// se muestran todo el armado del juego sin haber comenzado a jugarlo
	for (unsigned int i = 0; i < palabra_elegida.length(); i++) {
		
		cout << adivinado[i] << " ";
		
	}
	
	gotoxy(70,2);
	cout << "Letras incorrectas: ";
	gotoxy(70,3);
	
	mostrar_hombrecito(puntos);
	
	gotoxy(0,0);
	
	cout << "Ingrese una letra: ";
	
	// comienza el juego
	while(puntos > 30 and !victoria) {
		
		// ingreso letras
		do{
			gotoxy(19,0);
			cout << "                 ";
			gotoxy(19,0);
			guess = tolower(pedir_opciones());

			if((tolower(guess) < 'a' or tolower(guess) > 'z') and tolower(guess) != 'ñ'){
				gotoxy(35, 5);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
                cout << "Ingreso incorrecto. Pruebe nuevamente " << endl;
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
			}
		}while((tolower(guess) < 'a' or tolower(guess) > 'z') and tolower(guess) != 'ñ');
		
		system("cls");
		
		unsigned int cont = 0;
		
		// se buscan todas las posiciones de la palabra que tengan la letra elegida y se tiene una palabra igual a la seleccionada pero que se reemplaza con puntos para saber donde ya se adivino una letra
		while (cont < palabra_elegida.length()) {
			
			if (en_palabra(guess, letras, posicion)) {
				
				adivinado[posicion] = guess; 
				letras[posicion] = '.';
				encontrada = true;
				PlaySoundA((LPCSTR) "respuesta_correcta.wav", NULL, SND_FILENAME | SND_ASYNC); 
				
			}
       
			cont++;
		}

		gotoxy(35,3);
		
		// se muestra como vienen las letras adivinadaa
		for (unsigned int i = 0; i < palabra_elegida.length(); i++) {
			
			cout << adivinado[i] << " ";
			
		}
		cout << endl;
		
		int aux = 0;
		
		// se buscan las letras incorrectas
		if (!en_palabra(guess, letras_malas, aux) and !en_palabra(guess, palabra_elegida, aux))
			letras_malas += guess;
		
		gotoxy(70,3);
		cout << "Letras incorrectas: ";
		gotoxy(70,4);
		
		// se muestran las letras incorrectas
		for(unsigned int i = 0; i < letras_malas.length(); i++){
			cout << letras_malas[i] << "-";
		}
		
		// si la letra ya fue ingresada (sea parte de la palabra o no) se notifica al usuario y no cuenta el intento en los puntos
		if (en_palabra(guess, todas_las_letras, posicion) and !encontrada) {
			
			gotoxy(35,5);
			
			cout << "Ese caracter ya fue usado, intente nuevamente" << endl;
			
		}
		
		// si la letra no esta en la palabra se cuenta como un error
		else if (!en_palabra(guess, palabra_elegida, posicion)) {
			
			puntos -= 10;
			
			gotoxy(35,5);
			
			cout << "Caracter incorrecto" << endl;

			PlaySoundA((LPCSTR) "sonido_letramal_ahorcado.wav", NULL, SND_FILENAME | SND_ASYNC); 
			
		}

		// en este string se guardan todas las letras intentadas
		todas_las_letras += guess;

		// se muestra el ahorcado con los puntos actuales
		mostrar_hombrecito(puntos);
		
		// si lo adivinado es igual a la palabra que se tenia que adivinar, ya ganaste
		if (ganaste(adivinado, palabra_elegida))
			victoria = true;
		
		gotoxy(0,0);
		
		cout << "Ingrese una letra: " << endl;
		
		encontrada = false;
		
	}
	
	// si se salio del bucle porque ganaste
	if (victoria) {
		
		felicitaciones(); 
		
	}

	// si se salio del bucle porque perdiste
	else { 
		
		buen_intento(palabra_elegida, puntos); 
		
	}
	
	gotoxy(35, 35);
	
	// se espera a que se presione enter para continuar
	cout << "Presione enter para continuar";
	cin.ignore();
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		break;
		cin.ignore();
	}
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), 241);
	system("mode con: cols=100 lines=30");
}

bool en_palabra(char guess, string palabra, int& posicion) {
	
	bool flag = false;
	unsigned int i = 0;
	
	// se busca si hay alguna letra de la palabra que sea igual al caracter ingresado y se toma la posicion del mismo
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
	
	// se pregunta si las palabras son exactamente iguales
	for (unsigned int i = 0; i < palabra.length(); i++) {
		
		if (adivinado[i] != palabra[i])
			result = false;
		
	}
	
	return result;
	
}

void felicitaciones() {
	
	system("cls");
	
	gotoxy(41,0);

	// se muestra el ahorcado con el caso especial ganador
	
	mostrar_hombrecito(110);
	
}

void buen_intento(string palabra_elegida, int puntos) {
	
	system("cls");

	// se muestra el ahorcado perdido

	mostrar_hombrecito(puntos);
		
	gotoxy(45,3);
	cout << "Cerca!" << endl;
		
	gotoxy(35,4);
	cout << "La palabra era: " << palabra_elegida << endl;
	
}

void mostrar_hombrecito(int puntos) {
	
	// se crean todos los dibujos del ahorcado para cada caso de los puntos que tenga el usuario

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
	
	string salto_brazo_abajo[] = {
			
			" ___________.._______",
				"| .__________))______|", 
				"| | / /      ",
				"| |/ /       ",
				"| | /        .-''.",
				"| |/        / -  -\\",
				"| |         | ^  ^ |",
				"| |         \\ ---  /",
				"| |          `----'.",
				"| |        /Y . . Y\\",
				"| |       // |   | \\\\",
				"| |      //  | . |  \\\\",
				"| |     ')   |   |   (`",
				"| |          || ||",
				"| |          || ||",
				"| |          || ||",
				"| |         / | | \\",
				"| |         `-' `-'",
				"|\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"|\"|\"\"\"\"\"\"|\"|\"\"\"\"\"\"\"|",
				"|\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"|\"|\"\"\"\"\"\"|\"|\"\"\"\"\"\"\"|",
				"| |                \\ \\      | |",
				": :                 \\ \\     : :",
				". .                  `'     . ."
		};
		
		string salto_brazo_arriba[] = {
			
			" ___________.._______",
				"| .__________))______|", 
				"| | / /      ",
				"| |/ /       ",
				"| | /        .-''.",
				"| |/        / -  -\\",
				"| |   (.   | ^  ^ |    .) ",
				"| |    \\\\  \\ ---  /   //   ",
				"| |     \\\\  `----'.  //   ",
				"| |      \\\\/Y . . Y\\//",
				"| |       v  |   |  v",
				"| |          | . | ",
				"| |          |   |  ",
				"| |          || ||",
				"| |          || ||",
				"| |          || ||",
				"| |         / | | \\",
				"| |         `-' `-'",
				"|\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"|\"|\"\"\"\"\"\"|\"|\"\"\"\"\"\"\"|",
				"|\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"|\"|\"\"\"\"\"\"|\"|\"\"\"\"\"\"\"|",
				"| |                \\ \\      | |",
				": :                 \\ \\     : :",
				". .                  `'     . ."
		};
		
		string cartel_ganaste[] = {
			"  _____            _   _             _____  _______  ______  _ ",
			" / ____|    /\\    | \\ | |    /\\     / ____||__   __||  ____|| |",
			"| |  __    /  \\   |  \\| |   /  \\   | (___     | |   | |__   | |",
			"| | |_ |  / /\\ \\  | . ` |  / /\\ \\   \\___ \\    | |   |  __|  | |",
			"| |__| | / ____ \\ | |\\  | / ____ \\  ____) |   | |   | |____ |_|",
			" \\_____|/_/    \\_\\|_| \\_|/_/    \\_\\|_____/    |_|   |______|(_)",
		};

	int ejex = 35, ejey = 7;
	
	switch (puntos) {

	case 110:
		
		PlaySoundA((LPCSTR) "celebracion.wav", NULL, SND_FILENAME | SND_ASYNC); 
		
		// se meustra el cartel de ganaste en rojo y azul cinco veces y debajo el hombresito saltando
		for (int j = 0; j < 5; j++) {
			
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
			for (int i = 0; i < 6; i++) {
				
				gotoxy(20,i + 1);
				cout <<  cartel_ganaste[i] << endl;
				
			}
			
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
			for (int i = 0; i < 23; i++) {
				
				gotoxy(ejex,ejey+i);
				cout <<  salto_brazo_abajo[i] << endl;
				
			}
			Sleep(600);
			system("cls");
			
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),1);
			for (int i = 0; i < 6; i++) {
				
				gotoxy(20,i + 1);
				cout <<  cartel_ganaste[i] << endl;
				
			}
			
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
			for (int i = 0; i < 23; i++) {
				
				gotoxy(ejex,ejey+i);
				cout <<  salto_brazo_arriba[i] << endl;
				
			}
			Sleep(600);
			
			// si es la ultima iteracion el hombrecito se deja para esperar que el usuario presione enter
			if (j != 4)
				system("cls");
			
		}
		
		break;
		
	case 100:
		
		// se meustra solo el palito del ahorcado
		for (int i = 0; i < 22; i++) {
			
			gotoxy(ejex,ejey+i);
			cout << palito[i] << endl;
			
		}
		break;
		
	case 90: 
		
		// se agrega la cabeza al ahorcado
		for (int i = 0; i < 22; i++) {
			
			gotoxy(ejex,ejey+i);
			cout << cabeza[i] << endl;
			
		}
		
		break;
		
	case 80:
		
		// se agrega el cuerpo al ahorcado
		for (int i = 0; i < 22; i++) {
			
			gotoxy(ejex,ejey+i);
			cout << cuerpo[i] << endl;
			
		}
		break;
		
	case 70:
		
		// se agrega el brazo izquierdo al ahorcado
		for (int i = 0; i < 22; i++) {
			
			gotoxy(ejex,ejey+i);
			cout << brazoIzquierdo[i] << endl;
		}
		break;
		
	case 60:
		
		// se agrega el brazo derecho al ahorcado
		for (int i = 0; i < 22; i++) {
			
			gotoxy(ejex,ejey+i);
			cout << brazoDerecho[i] << endl;
			
		}
		break;
		
	case 50:
		
		// se agrega la pierna izquierda al ahorcado
		for (int i = 0; i < 22; i++) {
			
			gotoxy(ejex,ejey+i);
			cout << piernaIzquierda[i] << endl;
			
		}
		break;
		
	case 40:
		
		// se agrega la pierna derecha al ahorcado
		for (int i = 0; i < 22; i++) {
			
			gotoxy(ejex,ejey+i);
			cout << piernaDerecha[i] << endl;
			
		}
		break;
		
	case 30:
		
		// se muere el ahorcado
		for (int i = 0; i < 29; i++) {
			
			gotoxy(ejex,ejey+i);
			
			// se hace que la sangre sea roja y que el palo del ahorcado quede en la misma linea pero sin ser de color rojo

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
			PlaySoundA((LPCSTR) "sonido_muerte_ahorcado.wav", NULL, SND_FILENAME | SND_ASYNC); 
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
			
		}	
		break;
		
	}
	
}


//------------------------------------------------- Palabra Cifrada ------------------------------------------------------------

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
	cout << "Aclaración" << endl;
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
	gotoxy(10,14);
	cout << "Debido a limitaciones técnicas, se usará el 4 para referenciar a la ñ en el juego";
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
		
		gotoxy(5, 20);
		cout << "Letras ya utilizadas:";
		
		bool validacion = false;
		gotoxy(5, 22);
		//Este bucle contabiliza las letras que ya fueron usadas y se las muestra al usuario
		for(int i=97; i < 124; i++){
			if(letras_ingresadas[123] >= 1 and !validacion){
				cout << "4(ñ) ";
				validacion = true;
			}
			if(letras_ingresadas[i] >= 1 and i != 123){
				cout << (char)i << " ";
			}
		}
		
		gotoxy(55, 5);
		cout << "Ingrese una letra: ";
		letra = pedir_opciones();
		
		//Pasamos la letra a minuscula para evitar inconvenientes
		letra= tolower(letra); 
	
		//Ingresamos la letra a una cadena de caracteres con subindices de acuerdo al ASCII para llevar un control  
		for(int i=97; i < 124; i++){
			if(letra == i)
				letras_ingresadas[i]++;
		}
		//En caso de que la letra sea el 4 (ñ) la almacenaremos en la posicion 123
		if(letra == '4')
			letras_ingresadas[123]++;
			
		
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
	bool rta = true;
	int i = 97;
	//Verificamos si la letra ya fue ingresada anteriormente o no

	if(letra == '4' and letras[123] > 1){
		rta = false;
	}

	while(i < 124 and rta){
		if (i == letra and letras[i] > 1){
			rta=false;
		}
		i++;
	}
	
	return rta;
}



//----------------------------------------------Numeros en otro idioma--------------------------------------------------------

void numeros_en_otro_idioma(){
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
        numeros_en_otro_idioma();
		break;
	}
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
	
	gotoxy(35, 25);
	cout << "Presione enter para continuar";
	
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		cin.ignore();
		break;
	}
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
		lineas(7, -1, 90, ' ');
        numero = magnitud();
    }

    return numero;

}

//-----------------------------------------------Memoria-------------------------------------------------


void memoria(string linea[]){
    
    int indice = 0, contador, num_vocales = 0, puntaje = 0, puntos_vocales = 0, indices_palabras_mayores[5] = {0};
    string palabras[5];
    char letra_repetida, letras_repetidas[10];
    string palabra_mas_larga, vocales;
	
	system("cls");
	
    //Se cargan 5 palabras aleatorias
    while(indice < 5){

        palabras[indice] = palabra_aleatoria(linea);
        //Si la palabra ya apareció antes se busca otra
        if(evita_repetida(palabras[indice], palabras, indice)){
            palabras[indice] = palabra_aleatoria(linea);
        }
        else{
            indice++;
        }
    }
	

    lineas(4, 8, 82, '~');
    gotoxy(29, 5);
    cout << "Bienvenido a la prueba de memoria.";
    gotoxy(9, 6);
    cout << "A continuación se le mostrarán 5 palabras por dos segundos, recuerdelas para ganar";
    Sleep(5000);
    lineas(5, 6, 95, ' ');
    

    gotoxy(40, 5);
    cout << "Las palabras son";
    for(int i = 0; i < 3; i++){
		Sleep(600);
        cout << ".";
	}
    gotoxy(20, 6);
    for(int i = 0; i < 5; i++){
        cout << palabras[i] << "     ";
    }
    Sleep(2000);
    system("cls");
	

	lineas(4, 10, 82, '~');
	gotoxy(38, 6);
	cout << "¿Recordas las palabras?";
    Sleep(1800);
    lineas(-1, 6, 90, ' ');
    gotoxy(33, 6);
	cout << "Responde las siguientes preguntas para ganar";


    gotoxy(20, 6);
	cout << "a-) ¿Cuál es la letra que más se repitió en las palabras?: ";
    letra_repetida = pedir_opciones();
    
    letras_mas_repetidas(palabras, letras_repetidas);

    //Verificamos si el usuario introdujo alguna de las letras que más se repitieron(puede haber más de una)
    unsigned int i = 0;
    while(i < 10){
        if(letra_repetida == letras_repetidas[i] and letras_repetidas[i] != '='){
            puntaje += 15;
            i = 10;
        }
        i++;
    }


    gotoxy(20, 7);
	cout << "b-) ¿Cuantas vocales hay en total?: ";

    //Se pide como un string el numero de vocales para evitar problemas si por error el usuario introduce un caracter o numero negativo
    cin >> vocales;
    i = 0;
    while(i < vocales.length()){
        num_vocales *= 10;
        //Si la entrada es correcta se la convierte a entero, sino se la descarta.
        if(vocales[i] >= '0' and vocales[i] <= '9')
            num_vocales += vocales[i] - '0';
        else{
            num_vocales = -1;
            i = vocales.length();
        }
        i++;
    }
    //Si el usuario introduce el numero exacto de vocales se suman 30 puntos. Si no lo hace se suma 30 - (2 * distancia a rta correcta).
    if(num_vocales == cuantas_vocales(palabras)){
        puntaje += 30;
    }
    else{
        puntos_vocales = 30 - abs(cuantas_vocales(palabras) - num_vocales) * 2;

        if(puntos_vocales > 0)
            puntaje += puntos_vocales;
    }


    gotoxy(20, 8);
	cout << "c-) ¿Cuál es la palabra de mayor longitud?: ";
    cin >> palabra_mas_larga;

    palabra_mas_grande(palabras, indices_palabras_mayores, contador);
    i = 0;
    //Si hay mas de una palabra de un largo máximo, el usuario puede introducir cualquiera de las opciones.
    while(i < contador){
        if(palabra_mas_larga == palabras[indices_palabras_mayores[i]]){
            puntaje += 10;
            i = contador;
        }
        i++;
    }

    //Muestra puntaje:
    system("cls");
    lineas(4, 10, 82, '~');
	gotoxy(41, 6);
	cout << "Su puntaje fue";
    for(int i = 0; i < 3; i++){
		Sleep(600);
        cout << ".";
	}
    
    graficos(puntaje / 10, 4, 42, 14);
    graficos(puntaje % 10, 4, 50, 14);

    Sleep(1500);
    gotoxy(30, 9);
    if(puntaje > 25){
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),250);
        cout << "¡Felicitaciones! Tenés muy buena memoria " << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
    }
    else{
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Tu memoria no es muy buena. ¡Seguí practicando!" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
    }

    gotoxy(34, 26);
    cout << "Presione enter para continuar";
	cin.ignore();
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		cin.ignore();
		break;
	}
}

bool evita_repetida(string palabra, string palabras[], int tam) {
	
	bool flag = false;
	int i = 0;

	while(!flag and i < tam){

        if(palabras[i] == palabra){
            flag = true;
        }
        i++;
    }
	
	return flag;
	
}

void palabra_mas_grande(string palabras[], int indices_palabras_mayores[], int & contador){
	unsigned int tamanio_mayor = 0, palabra_mayor=0;
	contador = 1;

	for(int i = 0; i < 5; i++){
		if(palabras[i].length() > tamanio_mayor){
			tamanio_mayor = palabras[i].length();
			palabra_mayor = i;
		}
	}
    indices_palabras_mayores[0] = palabra_mayor;

    //Se busca si hay mas de una palabra del largo máximo
    for(int i = 0; i < 5; i++){
        if(palabras[i] != palabras[palabra_mayor] and palabras[i].length() == palabras[palabra_mayor].length()){
            indices_palabras_mayores[contador] = i;
            contador++;
        }
    }
}

int cuantas_vocales(string palabras[]){
	int vocales = 0;
	
	for(int i = 0; i < 5; i++){
		int tamanio = palabras[i].length();
		
		for(int j = 0; j < tamanio; j++){
				if(esVocal(palabras[i][j])){
				   vocales++;
				}
		}
	}
	return vocales;
}

bool esVocal(char letra){
	bool rta = false;
	
	if(letra == 'a' or letra == 'e' or letra == 'i' or letra == 'o' or letra == 'u'){
		rta = true;
	}
	
	return rta;
}

void letras_mas_repetidas(string palabras[], char letras_repetidas[]) {
    
    int frec[26] = {}, mas_repetidos[10];
	
	int aux = 0, proxima_pos = 1, cont = 0;

	// se cuenta la cantidad de veces que aparece cada letra y se guarda en frec dependiendo de la posicion de la letra en el abecedario
	for (int i = 0; i < 5; i++) {
		
		for (unsigned int j = 0; j < palabras[i].length(); j++) {
			
			frec[palabras[i][j] - 'a']++;
			
		}
	}
	
	// se llenan los arrays con caracteres que conocemos para no tenerlos en cuenta
	for (int i = 0; i < 10; i++) {
		
		mas_repetidos[i] = -1;
		
		letras_repetidas[i] = '=';
		
	}
	
	// se guarda cual es la posicion de los caracteres que tuvieron la repeticion mas alta
	for (int i = 0; i < 26; i++) {
		
		if (frec[i] > aux){
			mas_repetidos[0] = i;
			aux = frec[i];
		}
		else if (frec[i] == aux and frec[i] != 0) {
			
			mas_repetidos[proxima_pos] = i;
			proxima_pos++;
			
		}
		
	}
	
	// si luego de encontrar una repeticion grande se encuentra una mayor, se la descarta y se la reemplaza por -1
	for (int i = 1; i < 10; i++) {
		
		if (mas_repetidos[0] > mas_repetidos[i])
			mas_repetidos[i] = -1;
		
	}

	// se dejan las posiciones de las repetidas delante en el array y se dejan los -1 detras de estas
	for (int i = 0; i < 9; i++) {
		
		if (mas_repetidos[i] < mas_repetidos[i + 1]) {
			
			int aux = mas_repetidos[i + 1];
			mas_repetidos[i + 1] = mas_repetidos[i];
			mas_repetidos[i] = aux;
			
		}
		
	}

	//se llena el array final que contiene el/los caracteres que tuvieron la mayor cantidad de repeticiones
	for (int i = 0; i < 10; i++) {
		
		if (mas_repetidos[i] != -1) {
			letras_repetidas[cont] = (char)mas_repetidos[i] + 'a';
			cont++;
		}
	}
}
