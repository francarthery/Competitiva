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
#include <ctime>


#define TAM 6

using namespace std;

void bienvenida();
void gotoxy(USHORT x, USHORT y);
void lineas(int, int, int, char);
bool login();
void ingresodatos(char [], char [], bool);
void ingreso_contra(char password[]);
bool verificacion_user(char [], int &);
bool verificacion_password(int, char []);
int inversoR (int, int);

void menu_principal();
char pedir_opciones();

void menu_abecedarios();
void espanol();
void ingles();
void italiano();
void portugues();
void frances();
void letras_minusculas();
void letras_mayusculas();
void acento_agudo();
void acento_grave();
void letras_circunflejo();

void menu_juegos();
void leer_texto(string linea[]);
string palabra_aleatoria(string linea[]);

void ahorcado(string linea[]);
bool en_palabra(char guess, string palabra, int& posicion);
void felicitaciones();
void buen_intento(string palabra_elegida, int puntos);
void mostrar_hombrecito(int puntos);
bool ganaste(char adivinado[], string palabra);
void mostrar_hombrecito(int puntos);

void palabra_cifrada(string linea[]);
void cifrado(string palabra, int, string &);

void numeros_en_otro_idioma();
void apariencia(int, int);
void graficos(int, int , int , int );
int magnitud();
void linea_h(int);
void linea_v(int, int, int);

void memoria();




int main(){
    
    //bienvenida();

    //if (login()) 
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
			
			//Cargamos cada renglon hasta donde permite el tama�o de la terminal
			for(int k = 0; k <= j; k++){
				cout << texto[i][k];
			}
		}
		//Manejo frames animaci�n
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

//------------------------------------------------- Login ------------------------------------------------------------

bool login() {
    int contador = 0, usuarionum = 0;
    char password[TAM], usuario[TAM];
    bool valido = false;

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
        //Pedimos caracter sin mostrarlo
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

//Funcion recursiva que calcula el inverso de un numero
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
                Sleep(3000);
				c = true;
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
	if(opcion != 'X'){
		menu_principal();
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
	
	gotoxy(35, 25);
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
	
	//encabezado espanol
	
	cout << endl << "Letras minúsculas:" << endl;
	letras_minusculas();
	
	cout << endl << "Letras mayúsculas:" << endl;
	letras_mayusculas();
	
	cout << endl << "Letras acentuadas:" << endl;
	acento_agudo();
	
	cout << endl << "Letra con diéresis:" << endl;
	cout << "ü" << endl;
	
}
	
void ingles(){
	Sleep(1000);
	system("cls");
	
	//encabezado ingles
	
	cout << endl << "Lowercase letters (letras minúsculas): " << endl;
	letras_minusculas();
	
	cout << endl << "Capital letters (letras mayúsculas):" << endl;
	letras_mayusculas();
	
	cout << endl << "There are no accented letters (no existen letras acentuadas)" << endl;
}
	
void italiano(){
	Sleep(1000);
	system("cls");
	
	int contador=0;
	
	//encabezado italiano
	
	cout << endl << "Lettere minuscole (letras minúsculas): " << endl;
	
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
		   cout << endl;        
	}
	
	cout << endl << endl << "Lettere maiuscole (letras mayúsculas):" << endl;
	
	contador=0; 
	
	for(char i = 'A'; i <= 'Z'; i++){
		cout << i << " ";
		contador++;
		
		if(i == 'I')
			i+=2;
		
		if(i == 'V')
			i+=3;
		
		if(contador%10 == 0)
			cout << endl;
	}
	
	cout << endl << endl << "lettere con accento acuto (letras con acento agudo):" << endl;
	cout << "é í ó ú" << endl;
	
	cout << endl << "Lettere gravemente accentate (letras con acento grave):" << endl;
		acento_grave();
	
	cout << endl << "lettere circonflesse (letras con circunflejo):" << endl;
		cout << "î" << endl;
	
}
void portugues(){
	Sleep(1000);
	system("cls");
	
	//encabezado portugues
	
	cout << endl << "Letras minúsculas:" << endl;
	letras_minusculas();
	
	cout << endl << "Letras maiusculas (letras mayúsculas):" << endl;
	letras_mayusculas();
	
	cout << endl << "Letras com acento agudo (letras con acento agudo):" << endl;
	acento_agudo();
	
	cout << endl << "Letras com acentos graves (letras con acento grave):" << endl;
	cout << "à" << endl;
	
	cout << endl << "Letras circunflexas (letras con circunflejo):" << endl;
	cout << "â ê ô" << endl;
}
	
void frances(){
	Sleep(1000);
	system("cls");
	
	//encabezado frances
	
	cout << endl << "Lettres minuscules (letras minúsculas):" << endl;
	letras_minusculas();
	
	cout << endl << "Lettres majuscules (letras mayúsculas):" << endl;
	letras_mayusculas();
	
	cout << endl << "Lettres avec accent  aigu (letras con acento agudo):" << endl;
	cout << "é" << endl;
	
	cout << endl << "Lettres avec accent grave (letras con acento grave):" << endl;
	cout << "à è ù" << endl;
	
	cout << endl << "Lettres circonflexes (letras con circunflejo):" << endl;
	letras_circunflejo();
	
	cout << endl << "Lettres avec tréma (letras con diéresis):" << endl;
	cout << "ë ï ü ÿ" << endl;
	
}
	
void letras_minusculas(){
	
	int contador=0;
	
	for(char i = 'a'; i <= 'z'; i++){
		cout << i << " ";
		contador++;
		
		if(contador%10 == 0)
			cout << endl;
	}
	cout << endl;
}
	
void letras_mayusculas(){
	
	int contador=0;
	
	for(char i= 'A'; i <= 'Z'; i++){
		cout << i << " ";
		contador++;
		
		if(contador%10 == 0)
			cout << endl;
	}
	cout << endl;
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
		//memoria();
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

string palabra_aleatoria(string linea[]){
	srand(time(NULL));
	
	int palabra_aleatoria = rand() % 100 + 1;
	
	string palabra_elegida = linea[palabra_aleatoria];
	
	return palabra_elegida;
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


//------------------------------------------------- Ahorcado ------------------------------------------------------------
void ahorcado(string linea[]){
	
	system("mode con: cols=100 lines=40");
	
	int puntos = 100;
	
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
	
	gotoxy(35,3);
	
	for (unsigned int i = 0; i < palabra_elegida.length(); i++) {
		
		cout << adivinado[i] << " ";
		
	}
	
	gotoxy(70,2);
	cout << "Letras incorrectas: ";
	gotoxy(70,3);
	
	mostrar_hombrecito(puntos);
	
	gotoxy(0,0);
	
	cout << "Ingrese una letra: ";
	
	while(puntos > 30 and !victoria) {
		
		//Ingreso letras
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
		
		while (cont < palabra_elegida.length()) {
			
			if (en_palabra(guess, letras, posicion)) {
				
				adivinado[posicion] = guess; 
				letras[posicion] = '.';
				encontrada = true;
				
			}
       
			cont++;
		}

		gotoxy(35,3);
		
		for (unsigned int i = 0; i < palabra_elegida.length(); i++) {
			
			cout << adivinado[i] << " ";
			
		}
		cout << endl;
		
		int aux = 0;
		
		if (!en_palabra(guess, letras_malas, aux) and !en_palabra(guess, palabra_elegida, aux))
			letras_malas += guess;
		
		gotoxy(70,3);
		cout << "Letras incorrectas: ";
		gotoxy(70,4);
		
		for(unsigned int i = 0; i < letras_malas.length(); i++){
			cout << letras_malas[i] << "-";
		}
		
		if (en_palabra(guess, todas_las_letras, posicion) and !encontrada) {
			
			gotoxy(35,5);
			
			cout << "Ese caracter ya fue usado, intente nuevamente" << endl;
			
		}
		
		else if (!en_palabra(guess, palabra_elegida, posicion)) {
			
			puntos -= 10;
			
			gotoxy(35,5);
			
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
		
		felicitaciones(); 
		
	}
	else { 
		
		buen_intento(palabra_elegida, puntos); 
		
	}
	
	gotoxy(35, 35);
	
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

void felicitaciones() {
	
	system("cls");
	
	gotoxy(41,0);
	
	mostrar_hombrecito(110);
	
}

void buen_intento(string palabra_elegida, int puntos) {
	
	system("cls");

	mostrar_hombrecito(puntos);
		
	gotoxy(45,3);
	cout << "Cerca!" << endl;
		
	gotoxy(35,4);
	cout << "La palabra era: " << palabra_elegida << endl;
	
	gotoxy(35,4);
	
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
			
			if (j != 4)
				system("cls");
			
		}
		
		break;
		
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
		
	}
	
}


//------------------------------------------------- Palabra Cifrada ------------------------------------------------------------
void palabra_cifrada(string linea[]) {
	system("cls");
	
	string palabra_elegida = palabra_aleatoria(linea);
	string adivinado;
	int tamanio = palabra_elegida.length();
	char letra;
	string palabra_cifrada;
	
	cifrado(palabra_elegida, tamanio, palabra_cifrada);
	
	adivinado.resize(tamanio, '_');
	
	int intentos= 0;

	if(tamanio <= 6){
		intentos = tamanio*2;
	}else if(tamanio <= 10){
		tamanio-=1;
	}else
		tamanio-= 3;
	
	int contador= tamanio;
	
	do{
		cout << "Ingrese una letra: ";
		letra = pedir_opciones();

		tolower(letra); 

		if(letra >= 'a' and letra <= 'z'){
			for (int i = 0; i < tamanio; i++) {
				if (palabra_elegida[i] == letra) {
					adivinado[i] = palabra_elegida[i];
					contador--;
				}
			}
		}else{
			system("cls");
			cout << "Recuerde que debe ingresar una sola letra";
			Sleep(2500);
		}
		Sleep(500);
		system("cls");
		cout << palabra_cifrada << endl;
		cout << adivinado << endl;
		
		intentos--;
		
	}while (intentos > 0 and contador > 0);
	
	if(intentos == '0'){
		cout << "Perdiste :(";
	}else{
		cout << "Ganaste :)";
	}
}

void cifrado(string palabra, int tamano, string &palabra_cifrada) {
	for (int i = 0; i < tamano; i++) {
		if (palabra[i] == 'a')
			palabra_cifrada += 'ñ'   ;
		
		else if (palabra[i] == 'ñ')
			palabra_cifrada += 'b';
		
		else if (palabra[i] == 'n')
			palabra_cifrada += 'a';
		
		else if (palabra[i] > 'm')
			palabra_cifrada += 'a' + (13-('z' - palabra[i]));
		
		else
			palabra_cifrada += palabra[i] + 13;
	}
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


/*
centrar menúes
Borrar comentario línea 81
*/
