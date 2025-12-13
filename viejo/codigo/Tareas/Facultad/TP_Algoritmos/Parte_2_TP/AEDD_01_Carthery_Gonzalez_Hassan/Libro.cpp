#include <iostream>
#include <fstream>
#include <windows.h>
#include "Libro.h"
#include <iomanip>
#include <cstring>

using namespace std;

void est_caracteres(){
	
	Letras frecuencia[30];
	
	ifstream archivo("frecuencia.txt");
	
	//Si el archivo ya existe, cargamos el array desde ahi para no procesar de nuevo el texto. Sino analizamos todo el libro.
	if(archivo)
		cargar_tabla(frecuencia);
	else{
		leer_libro(frecuencia);
		mergesort(frecuencia, 0, 25);
		guardar_tabla(frecuencia);
	}
	archivo.close();
	
	mostrar_tabla(frecuencia);
}
	
void leer_libro(Letras frecuencia[]){
	
	char letra;
	
	//Cargamos cada letra en su posicion del codigo ascii(los primeros 32 caracteres son especiales)
	for(int i = 0; i < 30; i++){
		frecuencia[i].letra = i + 'a';
	}
	
	ifstream libro;
	
	libro.open("les_miserables.txt");
	
	if(!libro)
		cout << "Error al abrir el fichero" << endl;
	else{
		while (libro.get(letra)) {
			if(isalpha(letra))
				frecuencia[int(tolower(letra) - 'a')].cantidad++;
		}
	}
	
	libro.close();
}
	
void mostrar_tabla(Letras frecuencia[]){
	
	system("cls");
	system("mode con: cols=70 lines=40");
	
	gotoxy(15, 1);
	cout << "=====================================";
	gotoxy(23, 2);
	cout << "Frecuencia caracteres";
	gotoxy(15, 3);
	cout << "=====================================";
	
	
	gotoxy(18, 5);
	cout << "_______________________________";
	gotoxy(18, 6);
	cout << "|Caracter|  Cant. apariciones |";
	
	
	for(int i = 0; i < 26; i++){
		gotoxy(18, i + 7);
		cout << "|   " << frecuencia[i].letra << "    |";
		cout << setfill(' ') << setw(12) << frecuencia[i].cantidad << setw(9) << "|";
		Sleep(25);
	}
	gotoxy(18, 33);
	cout << "-------------------------------";
	
	gotoxy(20, 36);
	cout << "Presione enter para continuar";
	
	while(true){
		if(GetAsyncKeyState(VK_RETURN)){
		cin.ignore();
		break;
		}
	}
		
		system("mode con: cols=100 lines=30");
}
	
void mergesort(Letras frecuencia[], int inicio, int fin){
	if(fin - inicio == 0)
		return;
	else{
		mergesort(frecuencia, inicio, (inicio + fin) / 2);
		mergesort(frecuencia, (inicio + fin) / 2 + 1, fin);
		merge(frecuencia, inicio, (inicio + fin) / 2, (inicio + fin) / 2 + 1, fin);
	}
}
	
void merge(Letras frecuencia[], int inicio1, int fin1, int inicio2, int fin2){
	
	int i = inicio1, j = inicio2, k = 0;
	Letras c[100];
	
	while(i <= fin1 and j <= fin2){
		if(frecuencia[i].cantidad > frecuencia[j].cantidad){
			c[k] = frecuencia[i];
			i++;
		}
		else{
			c[k] = frecuencia[j];
			j++;
		}
		k++;
	}
	
	while(i <= fin1){
		c[k] = frecuencia[i];
		k++;
		i++;
	}
	while(j <= fin2){
		c[k] = frecuencia[j];
		k++;
		j++;
	}
	
	//Guardamos la parte ordenada en el vector original
	for(k = 0; k < fin2 - inicio1 + 1; k++){
		frecuencia[inicio1 + k] = c[k];
	}
}
	
void cargar_tabla(Letras frecuencia[]){
	
	ifstream tabla;
	
	tabla.open("frecuencia.txt");
	
	if(!tabla)
		cout << "Error al abrir el archivo" << endl;
	else{
		for(int i = 0; i < 26; i++){
			tabla >> frecuencia[i].letra >> frecuencia[i].cantidad;
		}
	}
	
	tabla.close();
}
	
void guardar_tabla(Letras frecuencia[]){
	
	ofstream tabla;
	
	tabla.open("frecuencia.txt");
	
	if(!tabla)
		cout << "Error al abrir el fichero" << endl;
	else{
		for(int i = 0; i < 26; i++){
			tabla << frecuencia[i].letra << setfill(' ') << setw(8) << frecuencia[i].cantidad << endl;
		}
	}
	
	tabla.close();
}



void est_palabras(){
	
	char seleccion;
	int opcion = 0;
	Nodo * lista = NULL;
	int Palabras[19][26] = {0};
	
	system("cls");
	gotoxy(35, 10);
	cout << "Procesando informacion...";
	
	//Cargamos todos los datos. Con dos lecturas al libro obtenemos toda la informacion necesaria.
	//Item 1
	genera_matriz(Palabras);
	//Item 3
	frecuencia_palabras(lista);
	
	while(opcion != 1){
		opcion = 0;
		system("cls");
		
		lineas(8, 19, 48, '=');
		gotoxy(38, 10);
		cout << "Estad" << char(161) << "sticas Palabras";
		lineas(-1, 11, 36, '=');
		gotoxy(32, 12);
		cout << "1.- Mostrar tabla de frecuencia";
		gotoxy(32, 13);
		cout << "2.- Mostrar informaci" << char(162) << "n libro";
		gotoxy(32, 14);
		cout << "3.- Mostrar palabras con letra X inicial";
		gotoxy(32, 15);
		cout << "X.- Volver al men" << (char)163 << " Procesador de texto";
		gotoxy(32, 16);
		cout << "Ingrese una opci" << (char)162 << "n: ";
		
		seleccion = pedir_opciones();
		
		switch (seleccion) {
			
		case '1':
			ver_matriz(Palabras);
			break;
			
		case '2':
			//Item 2
			consultas(Palabras, lista);
			break;
			
		case '3':
			//Item 4
			palabra_lista(lista);
			break;
			
		case 'X':
			gotoxy(26, 18);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
			cout << "Est" << (char)160 << " seguro que desea volver al men" << (char)163 << " principal? [S/N]: ";
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
			do{
				seleccion = pedir_opciones();
				
				if(seleccion == 'S'){
					opcion = 1;
					
				}else if(seleccion == 'N'){
					opcion = 2;
					
				}else {
					gotoxy(26, 18);
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
					cout << "Caracter incorrecto. Ingrese confirmaci" << (char)162 << "n nuevamente: " << endl;
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
					gotoxy(80, 18);
					cout << "         ";
					gotoxy(80, 18);
				}
				
			}while(!opcion);
			break;
			
		default:
			gotoxy(26, 18);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),244);
			cout << "La opci" << (char)162 << "n ingresada no es correcta" << endl;
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
			Sleep(3000);
			break;
		}
	}
	
	//Antes de salir libreramos lista
	borrar_lista(lista);
	
}
	
void genera_matriz(int Palabras[][26]){
	char letra, letra_inicial;
	bool anterior_letra = false;
	int contador = 1;
	
	ifstream libro;
	
	libro.open("les_miserables.txt");
	
	if(!libro)
		cout << "Error al abrir el fichero" << endl;
	else{
		//Leemos caracter a caracter y si encontramos un caracter que no es letra cortamos la palabra ahi
		while(libro.get(letra)){
			if(isalpha(letra) and !anterior_letra){
				letra_inicial = letra;
				contador = 1;
				anterior_letra = true;
			}
			else if(isalpha(letra) and anterior_letra)
			   contador++;
			else if(!isalpha(letra) and anterior_letra){
				anterior_letra = false;
				Palabras[contador][tolower(letra_inicial) - 'a']++;
			}
		}
	}
	
	libro.close();
	
}
	
void ver_matriz(int Palabras[][26]){
	
	system("mode con: cols=166 lines=25");
	
	cout << "    ";
	for(int i = 0; i < 26; i++){
	cout << setfill(' ') << setw(6) << char(i + 'a');
	}
	
	gotoxy(0, 1);
	for(int i = 0; i < 164; i++) 
		cout << "-";
	
	cout << endl;
	for(int i = 1; i < 19; i++){
		cout << setw(4) << setfill(' ') << i << " |";
		for(int j = 0; j < 26; j++){
			cout << setw(6) << Palabras[i][j];
		}
		cout << endl;
	}
	
	gotoxy(65, 22);
	cout << "Presione enter para continuar";
	
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		cin.ignore();
		break;
	}
	
	system("mode con: cols=100 lines=30");
}
	
void consultas(int Palabras[][26], Nodo * lista){
	
	system("cls");
	lineas(6, 22, 56, '~');
	gotoxy(24, 7);
	cout << "--La longitud de palabra promedio es: " << palabra_promedio(Palabras) << endl;
	gotoxy(24, 9);
	palabras_mas_frecuencia(lista);
	gotoxy(24, 20);
	cout << "--El porcentaje de palabras que comienzan por vocal es: " << vocal_consonante(Palabras) << "%" << endl;
	
	cin.ignore();
	gotoxy(35, 27);
	cout << "Presione enter para continuar";
	
	while(true)
		if(GetAsyncKeyState(VK_RETURN)){
		cin.ignore();
		break;
	}
}
	
int palabra_promedio(int Palabras[][26]){
	
	//promedio
	int suma_letras = 0, suma_palabras = 0;
	for(int i = 1; i < 19; i++){
		for(int j = 0; j < 26; j++){
			suma_letras += i * Palabras[i][j];
			suma_palabras += Palabras[i][j];
		}
		
	}
	
	return (suma_letras / suma_palabras);
}
	
int vocal_consonante(int Palabras[][26]){
	
	int suma_vocales = 0, suma_total = 0;
	
	for(int i = 1; i < 19; i++){
		
		for(int j = 0; j < 26; j++){
			suma_total += Palabras[i][j];
			if(es_vocal(j + 'a'))
				suma_vocales += Palabras[i][j];
		}
	}
	
	return (suma_vocales * 100) / suma_total;
}
	
void palabras_mas_frecuencia(Nodo * lista){
	
	char letra;
	cout << "Ingrese una letra: ";
	cin >> letra;
	gotoxy(24, 10);
	cout << "--Palabras comenzadas en '" << letra << "' con mayor frecuencia:";
	
	gotoxy(36, 11);
	cout << "_______________________";
	
	for(int i = 0; lista != NULL and i < 5; lista = lista -> sig){
		if(lista -> palabra[0] == letra){
			gotoxy(36, 12 + i);
			cout << "|" << setfill(' ') << setw(14) << lista -> palabra << "|" << setw(6) << lista -> cantidad << "|" << endl;
			i++;
		}
	}
	gotoxy(36, 17);
	cout << "-----------------------";
}
	
bool es_vocal(char letra){
	
	bool rta = false;
	
	if(letra == 'a' or letra == 'e' or letra == 'i' or letra == 'o'  or letra == 'u')
		rta = true;
	
	return rta;
}


void frecuencia_palabras(Nodo *& lista){
	char palabra[20], letra;
	bool anterior_letra= false;
	int contador = 0, tam = 0;
	
	ifstream libro;
	
	libro.open("les_miserables.txt");
	
	if(!libro)
		cout << "Error al abrir el fichero" << endl;
	else{
		while(libro.get(letra)){
			if(isalpha(letra) and !anterior_letra){
				contador = 1;
				palabra[0] = tolower(letra);
				anterior_letra = true;
			}
			else if(isalpha(letra) and anterior_letra)
			   palabra[contador++] = tolower(letra);
			else if(!isalpha(letra) and anterior_letra){
				anterior_letra = false;
				palabra[contador] = '\0';
				insertar_ordenado(lista, palabra, tam);
			}
		}
		mergesort_lista(lista, 0, tam-1);
	}
	libro.close();
	
}
void insertar_ordenado(Nodo *& maestro, char pal_nuevo[], int & tam){
	
	Nodo *nuevo, *anterior, *actual;
	bool flag = false;
	
	anterior = NULL;
	actual = maestro;
	
	//Buscamos la posicion donde insertar. Seguimos los criterios 2 y 3 de ordenacion de la lista
	while(actual != NULL and (strlen(pal_nuevo) > strlen(actual -> palabra) or (strlen(pal_nuevo) == strlen(actual -> palabra) and strcmp(pal_nuevo, actual -> palabra) < 0))){
		anterior = actual;
		actual = actual -> sig;
	}
	
	//Si las palabras son igulales, la condicion del while fallara justo ahi
	if(actual != NULL and strcmp(pal_nuevo, actual -> palabra) == 0)
		flag = true;
	
	if(flag)
		actual -> cantidad++;
	else{
		nuevo = new Nodo;
		strcpy(nuevo -> palabra, pal_nuevo);
		nuevo->cantidad = 1;
		nuevo -> sig = NULL;
		tam++;
		
		//Insercion al principio
		if(anterior == NULL){
			nuevo -> sig = maestro;
			maestro = nuevo;
		}
		else{
			anterior -> sig = nuevo;
			nuevo -> sig = actual;
		}
	}	
}
//Aplicamos criterio 1 de ordenacion (por cantidad) lista.
void mergesort_lista(Nodo *& maestro, int inicio, int fin){
	if(inicio >= fin)
		return;
	else{
		mergesort_lista(maestro, inicio, (inicio + fin) / 2);
		mergesort_lista(maestro, (inicio + fin) / 2 + 1, fin);
		merge_lista(maestro, inicio, (inicio + fin) / 2, (inicio + fin) / 2 + 1, fin);
	}
}
	
void merge_lista(Nodo *& maestro, int inicio1, int fin1, int inicio2, int fin2){
	
	int i, j;
	
	Nodo *aux = NULL, *sublista1 = maestro, *sublista2 = maestro, *anterior = NULL;
	
	//Posicionamos un puntero al inicio de cada tramo
	for(i = 0; i < inicio1; i++){
		anterior = sublista1;
		sublista1 = sublista1 -> sig;
	}
	
	for(j = 0; j < inicio2; j++)
		sublista2 = sublista2 -> sig;
	
	//Insertamos los elementos de mayor a menor en una lista auxiliar
	while(i <= fin1 and j <= fin2 and sublista1 != NULL and sublista2 != NULL){
		if(sublista1 -> cantidad > sublista2 -> cantidad){
			insertar_final(aux, sublista1 -> palabra, sublista1 -> cantidad);
			sublista1 = sublista1 -> sig;
			i++;
		}
		else{
			insertar_final(aux, sublista2 -> palabra, sublista2 -> cantidad);
			sublista2 = sublista2 -> sig;
			j++;
		}
	}
	
	while(i <= fin1){
		insertar_final(aux, sublista1 -> palabra, sublista1 -> cantidad);
		sublista1 = sublista1 -> sig;
		i++;
	}
	while(j <= fin2){
		insertar_final(aux, sublista2 -> palabra, sublista2 -> cantidad);
		sublista2 = sublista2 -> sig;
		j++;
	}
	
	//Insertamos la sublista ordenada en el original
	if(anterior != NULL)
		anterior -> sig = aux;
	else
		maestro = aux;
	
	for (; aux -> sig != NULL; aux = aux -> sig);
	aux->sig = sublista2;
}
	
void insertar_final(Nodo *& maestro, char pal[], int cant){
	
	Nodo *nuevo, *aux;
	
	//Si la lista esta vacia, colocamos en el maestro
	if(maestro == NULL){
		maestro = new Nodo;
		strcpy(maestro -> palabra, pal); 
		maestro -> cantidad = cant;
		maestro -> sig = NULL;
	}
	else{
		//Nos vamos hasta el final de la lista
		for(aux = maestro; aux->sig != NULL; aux = aux->sig);
		
		nuevo = new Nodo;
		strcpy(nuevo -> palabra, pal);
		nuevo -> cantidad = cant;
		nuevo -> sig = NULL;
		aux -> sig = nuevo;
	}
}
	
void palabra_lista(Nodo * lista){
	
	char letra;
	int cont = 0;
	system("cls");
	lineas(3, 9, 60, '-');
	gotoxy(25, 5);
	cout << "Ingrese una letra: ";
	cin >> letra;
	gotoxy(25, 7);
	Sleep(500);
	cout << "Se ha generado un archivo con las palabras iniciadas en '" << letra << "'";
	Sleep(2500);
	
	system("cls");
	system("mode con: cols=100 lines=1500");
	lineas(3, 5, 50, '=');
	gotoxy(38, 4);
	cout << "Palabras iniciadas en '" << letra << "'";
	
	gotoxy(29, 7);
	cout << "________________________________________";
	gotoxy(29, 8);
	cout << "|            Palabra| Cant. apariciones|";
	gotoxy(29, 9);
	cout << "|-------------------|------------------|";
	
	ofstream palabras;
	
	palabras.open("palabrasX.txt");
	
	for(; lista != NULL; lista = lista -> sig){
		if(lista -> palabra[0] == tolower(letra)){
			palabras << setfill(' ') << setw(19) << lista -> palabra << setw(6) << lista -> cantidad << endl;
			
			gotoxy(29, 10 + cont);
			cout << "|" << setfill(' ') << setw(19) << lista -> palabra << "|" << setw(18) << lista -> cantidad << "|";
			cont++;
		}
	}
	
	palabras.close();
	
	gotoxy(29, 10 + cont);
	cout << "----------------------------------------";
	gotoxy(34, 13 + cont);
	cout << "Presione enter para continuar";
	
	gotoxy(0,0);
	
	cin.ignore();
	while(true){
		if(GetAsyncKeyState(VK_RETURN)){
		cin.ignore();
		break;
		}
	}
		system("mode con: cols=100 lines=30");
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
	
char pedir_opciones(){
	
	char rta;
	string ingreso;
	
	getline(cin, ingreso);
	
	//Si el largo del ingreso es mayor a un caracter. Se retorna un caracter '?' el cual no representa ninguna opción posible.
	if(ingreso.length() != 1){
		rta = '?';
	}
	else{
		//Si el largo es 1, se retorna el caracter que ingresó el usuario.
		rta = ingreso[0];
	}
	
	return rta;
}

void borrar_lista(Nodo *& lista){
	Nodo * aux;
	
	while(lista != NULL){
		aux = lista;
		lista = lista -> sig;
		delete aux;
	}
}
	
	
	
	
