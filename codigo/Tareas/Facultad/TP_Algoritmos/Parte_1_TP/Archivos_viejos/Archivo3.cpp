#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>

#define TAM 6

using namespace std;

void bienvenida();
void gotoxy(USHORT x, USHORT y);
void lineas(int, int, int);
bool login();
void ingresodatos(char [], char [], bool);
bool verificacion_user(char [], int &);
bool verificacion_password(int, char []);
int inversoR (int, int);
void menu_principal();
void menu_abecedarios();
void menu_juegos();

int main(){
    
    bienvenida();

    if (login()) 
        menu_principal();
    
    Sleep(5000);

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

	lineas(8, 19, 100);
	
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
	//Desvanecimiento. Utilizo 47 como límite ya que es la mitad del ancho en caracteres del cartel.
	for(int i = 0; i < 47; i++){
		lineas(8, 19, 100 - i*2);
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


void lineas(int x1, int x2, int tamx){
    if(tamx > 100)
        tamx = 100;
    
    int inicio = (100 - tamx) / 2;
	
    gotoxy(inicio, x1);
    cout << setfill('-') << setw(tamx) << "-" << endl;
    
    gotoxy(inicio, x2);
    cout << setfill('-') << setw(tamx) << "-" << endl;
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
        cout << "                                                                                ";
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
    
    lineas(9, 18, 50);
    gotoxy(34, 12);
    cout << "Ingrese su ID de usuario: ";
    gotoxy(34, 14);
    cout << "Ingrese su contrasena: ";
    //Pedimos el usuario como cadena de caracteres para que no falle el programa si por error se manda un caracter
    gotoxy(60, 12);
    gets(usuario);
    gotoxy(57, 14);
    gets(password);
}

bool verificacion_user (char usuario[], int &usuarionum) {
    bool rta = true;
    usuarionum = 0;
    
    for(int i = 0; i < TAM - 1; i++){

        if(!isdigit(usuario[i]))
            rta = false;
        else
            //Si el usuario es correcto, generamos un int con el número para procesarlo luego en verificacion_password
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

    //Almacenamos el valor que debería tener la contraseña para luego comparar con la ingresada
    contra_correcta = inversoR(usuario, 0) - primer_num + (primer_num + ultimo_num) % 10;
    
    for(int i = 4; i >= 0; i--){
        if(contrasena[i] - '0' != (contra_correcta % 10))
            rta = false;
        
        contra_correcta /= 10;
    }
    return rta;
}

//Funcion recursiva que calcula el inverso de un número
int inversoR(int numero, int numero_inverso){
	int digito = numero % 10;

	if (numero == 0){
		return numero_inverso;
	}else{
		numero_inverso = numero_inverso * 10 + digito;
		return inversoR(numero / 10, numero_inverso);
	}
}

//------------------------------------------------- Menú principal ------------------------------------------------------------
void menu_principal(){
	char opcion, confirmacion;
	bool c = false;
	cout << setw(20) << setfill(' ') << "Menú Principal" << endl;
	cout << setfill('=') << setw(26) << "=" << endl;
	
	cout << "1.- Abecedarios" << endl;
	cout << "2.- Juegos" << endl;
	cout << "X.- Salir de la aplicación" << endl;
	
	cout << "Ingrese una opción: ";
	cin >> opcion;
	
	switch(opcion){
	case '1':
		//menu_abecedarios();
		break;
		
	case '2':
		//menu_juegos();
		break;
		
	case 'X':	
		cout << "¿Está seguro que desea salir de la aplicación? [S/N]" << endl;

		do{
			cin >> confirmacion;

			if(confirmacion == 'S'){
				cout << "Gracias por su visita. Hasta pronto!" << endl;
				c = true;

			}else if(confirmacion == 'N'){
				menu_principal();
				c = true;

			}else{
				cout << "Caracter incorrecto. Ingrese confirmación nuevamente: ";
			}

		}while(!c);
		
		break;
		
	default:
		cout << "La opción ingresada no es correcta"<< endl;
		    menu_principal();
		break;
		
	}
}
//------------------------------------------------- Menú abecedario ------------------------------------------------------------