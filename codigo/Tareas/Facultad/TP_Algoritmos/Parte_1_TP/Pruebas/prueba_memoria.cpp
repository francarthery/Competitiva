#include <iostream>
#include "archivo.h"
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

void memoria();
bool evita_repetida(string palabra, string palabras[], int tam);
void las_repetidas(string palabras[], char letras_mas_repetidas[], int cantidad_repetidas);
void repeticiones();
void palabra_mas_grande(string palabras[], int indices_palabras_mayores[], int& contador);
bool esVocal(char letra);
int cuantas_vocales(string palabras[]);
void letras_mas_repetidas(string palabras[], char letras_mas_repetidas[]);

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


string palabra_aleatoria(string linea[]){
	
	//Se utiliza la hora en milisegundos en lugar de time(NULL) para evitar demora por la actualización de la semilla
	srand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	
	int palabra_aleatoria = rand() % 100 + 1;
	
	string palabra_elegida = linea[palabra_aleatoria];
	
	return palabra_elegida;
}

int main(){

    string linea[105];
    memoria(linea);
}

void memoria(string linea[]){
    
    int indice = 0, contador, num_vocales = 0, puntaje = 0, puntos_vocales = 0, indices_palabras_mayores[5] = {0};
    string palabras[5];
    char letra_repetida, letras_repetidas[10];
    string palabra_mas_larga, vocales;
	
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

    gotoxy(35, 26);
    cout << "Presione enter para continuar";
	cin.ignore();
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		break;
		cin.ignore();
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
	
	for (int i = 0; i < 5; i++) {
		
		for (unsigned int j = 0; j < palabras[i].length(); j++) {
			
			frec[palabras[i][j] - 'a']++;
			
		}
	}
	
	for (int i = 0; i < 10; i++) {
		
		mas_repetidos[i] = -1;
		
		letras_repetidas[i] = '=';
		
	}
	
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
	
	for (int i = 1; i < 10; i++) {
		
		if (mas_repetidos[0] > mas_repetidos[i])
			mas_repetidos[i] = -1;
		
	}
	
	for (int i = 0; i < 9; i++) {
		
		if (mas_repetidos[i] < mas_repetidos[i + 1]) {
			
			int aux = mas_repetidos[i + 1];
			mas_repetidos[i + 1] = mas_repetidos[i];
			mas_repetidos[i] = aux;
			
		}
		
	}
	
	for (int i = 0; i < 10; i++) {
		
		if (mas_repetidos[i] != -1) {
			letras_repetidas[cont] = (char)mas_repetidos[i] + 'a';
			cont++;
		}
	}
	
}
