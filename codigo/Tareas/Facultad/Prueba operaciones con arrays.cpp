#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TAM 100

void cargar_vector(int vector[], int N, bool op1);
void imprimir_vector(int vector[], int N);
void borrar_valor(int arreglo[], int &N, int indice);
void borrar_rango(int arreglo[], int &N, int indice, int aux);
void insertar_valor(int arreglo[], int &N, int indice, int aux);
void buscar_valor(int arreglo[], int N, int aux);
void promedio(int arreglo[], int N);

int main(int argc, char *argv[]) {
	
	bool op1;
	int N, op2, indice, aux;
	int arreglo[TAM];
	
	cout << "Indique cuantos valores quiere ingresar(el maximo es 100)" << endl;
	do{
		cin >> N;
		if(N > 100 or N <= 0)
			cout << "valor incorrecto. Pruebe de nuevo:" << endl;
	}while(N > 100 or N <= 0);
	
	cout << "Si desea cargar el arreglo manualmente presione 0 si lo quiere hacer aleatoriamente presione 1" << endl;
	cin >> op1;
	cargar_vector(arreglo, N, op1);
	
	imprimir_vector(arreglo, N);
	
	while(op2 != -1 and N > 0){
		cout << endl << "Elija que operacion quiere hacer: " << endl;
		cout << "1: borrar valor  2: borrar rango  3: insertar valor" << endl;
		cout << "4: buscar valor  5: calcular promedio   -1: ninguna operacion" << endl;
		
		cin >> op2;
		
		switch(op2){
			case 1:
				cout << "Que valor desea borrar?: ";
				cin >> indice;
				borrar_valor(arreglo, N, indice);
				break;
			case 2:
				cout << "Que valores desea borrar?(indique inicio y fin): ";
				cin >> indice >> aux;
				borrar_rango(arreglo, N, indice, aux);
				break;
			case 3:
				cout << "Que valor desea insertar y en que posicion?: ";
				cin >> aux >> indice;
				insertar_valor(arreglo, N, aux, indice);
				break;
			case 4:
				cout << "Que valor desea buscar?: ";
				cin >> aux;
				buscar_valor(arreglo, N, aux);
				break;
			case 5:
				promedio(arreglo, N);
				break;
			default:
				cout << "Numero incorrecto" << endl;
			
		}
	}
	
	return 0;
}

void cargar_vector(int vector[], int N, bool op1){
	
	if(!op1){
		for(int i = 0; i < N; i++){
			cin >> vector[i];
		}
	}
	else{
		srand(time(NULL));
		for(int i = 0; i < N; i++){
			vector[i] = rand() % 101;
		}
	}
}
	
void imprimir_vector(int vector[], int N){
	
	cout << "El vector es: " << endl;
	
	for(int i = 0; i < N; i++){
		cout << vector[i] << " ";
	}
	cout << endl;
}
	
void borrar_valor(int arreglo[], int &N, int indice){
	
	for(int i = indice; i < N - 1; i++)
		arreglo[i] = arreglo[i + 1];
	
	N--;
	imprimir_vector(arreglo, N);
}
	
void borrar_rango(int arreglo[], int &N, int indice, int aux){
	
	int dist = aux - indice + 1;
	
	for(int i = indice; i < N - dist; i++)
		arreglo[i] = arreglo[i + dist];
	
	N -= dist;
	imprimir_vector(arreglo, N);
}

void insertar_valor(int arreglo[], int &N, int aux, int indice){
	
	for(int i = N; i > indice; i--)
		arreglo[i] = arreglo[i - 1];
	
	arreglo[indice] = aux;
	
	N++;
	imprimir_vector(arreglo, N);
}
	
void buscar_valor(int arreglo[], int N, int aux){
	int posicion = -1;
	for(int i = 0; i < N; i++){
		if(arreglo[i] == aux){
			posicion = i;
			i = N;
		}
	}
	if (posicion != -1)
		cout << "El valor " << aux << " se encuentra en la posicion " << posicion << endl;
	else
		cout << "No se encontro el valor" << endl;
}
	
void promedio(int arreglo[], int N){
	
	int suma = 0;
	
	for(int i = 0; i < N; i++){
		suma += arreglo[i];
	}
	
	cout << "El promedio es: " << (float)suma / N << endl;
}

