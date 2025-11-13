#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

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
void menu_abecedarios();
void menu_juegos();
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
	PlaySoundA((LPCSTR) "sonido_inicio.wav", NULL, SND_FILENAME | SND_ASYNC);   //Borrar comentario en zinjai
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
    gotoxy(25, 17);

    if (contador == 3 and !valido){
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
        cout << "Demasiados intentos incorrectos. Pruebe de nuevo mas tarde" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
    }
    else{
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
	cout << "Menu Principal";
    gotoxy(37, 11);
	cout << setfill('=') << setw(26) << "=";
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
		system("cls");
		menu_abecedarios();
		break;
		
	case '2':
		system("cls");
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
                Sleep(3000);
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
//------------------------------------------------- Menu abecedario ------------------------------------------------------------
void menu_abecedarios(){
	char opcion, confirmacion;
	bool c= false;
	
	cout << setw(20) << setfill(' ') << "Menu Abecedario" << endl;
	cout << setfill('=') << setw(25) << "=" << endl;
	
	cout << "1.- Espanol" << endl;
	cout << "2.- Ingles" << endl;
	cout << "3.- Italiano" << endl;
	cout << "4.- Portugues" << endl;
	cout << "5.- Frances" << endl;
	cout << "X.- Volver al menu principal" << endl;
	
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	
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
		cout << "Esta seguro que desea volver al menu principal? [S/N]" << endl;
		do{
			cin >> confirmacion;
			
			if(confirmacion == 'S'){
				system("cls");
				menu_principal();
				c = true;
				
			}else if(confirmacion == 'N'){
				system("cls");
				menu_abecedarios();
				c = true;
				
			}else{
				system("cls");
				cout << setw(20) << "Menu Abecedario" << endl;
				cout << setfill('=') << setw(25) << "=" << endl;
				
				cout << "1.- Espanol" << endl;
				cout << "2.- Ingles" << endl;
				cout << "3.- Italiano" << endl;
				cout << "4.- Portugues" << endl;
				cout << "5.- Frances" << endl;
				cout << "X.- Volver al menu principal" << endl;
				
				cout << "Caracter incorrecto. Ingrese confirmacion nuevamente: ";
				
			}
			
		}while(!c);    
		break;
		
	default:
		cout << "La opcion ingresada no es correcta" << endl;
        Sleep(3000);
		system("cls");
		menu_abecedarios();
		break;
	}
}

void espanol(){
	Sleep(2000);
	system("cls");
	
	//encabezado espanol
	
	cout << endl << "Letras minusculas:" << endl;
	letras_minusculas();
	
	cout << endl << "Letras mayusculas:" << endl;
	letras_mayusculas();
	
	cout << endl << "Letras acentuadas:" << endl;
	acento_agudo();
	
	cout << endl << "Letra con dieresis:" << endl;
	cout << "ü" << endl;
	
}
	
void ingles(){
	Sleep(2000);
	system("cls");
	
	//encabezado ingles
	
	cout << endl << "Lowercase letters (letras minusculas): " << endl;
	letras_minusculas();
	
	cout << endl << "Capital letters (letras mayusculas):" << endl;
	letras_mayusculas();
	
	cout << endl << "There are no accented letters (no existen letras acentuadas)" << endl;
}
	
void italiano(){
	Sleep(2000);
	system("cls");
	
	int contador=0;
	
	//encabezado italiano
	
	cout << endl << "Lettere minuscole (letras minusculas): " << endl;
	
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
	
	cout << endl << endl << "Lettere maiuscole (letras mayusculas):" << endl;
	
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
	Sleep(2000);
	system("cls");
	
	//encabezado portugues
	
	cout << endl << "Letras minusculas:" << endl;
	letras_minusculas();
	
	cout << endl << "Letras maiusculas (letras mayusculas):" << endl;
	letras_mayusculas();
	
	cout << endl << "Letras com acento agudo (letras con acento agudo):" << endl;
	acento_agudo();
	
	cout << endl << "Letras com acentos graves (letras con acento grave):" << endl;
	cout << "à" << endl;
	
	cout << endl << "Letras circunflexas (letras con circunflejo):" << endl;
	cout << "â ê ô" << endl;
}
	
void frances(){
	Sleep(200);
	system("cls");
	
	//encabezado frances
	
	cout << endl << "Lettres minuscules (letras minusculas):" << endl;
	letras_minusculas();
	
	cout << endl << "Lettres majuscules (letras mayusculas):" << endl;
	letras_mayusculas();
	
	cout << endl << "Lettres avec accent  aigu (letras con acento agudo):" << endl;
	cout << "é" << endl;
	
	cout << endl << "Lettres avec accent grave (letras con acento grave):" << endl;
	cout << "à è ù" << endl;
	
	cout << endl << "Lettres circonflexes (letras con circunflejo):" << endl;
	letras_circunflejo();
	
	cout << endl << "Lettres avec tréma (letras con dieresis):" << endl;
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
	



/*
centrar menúes
Borrar comentario línea 81
*/
