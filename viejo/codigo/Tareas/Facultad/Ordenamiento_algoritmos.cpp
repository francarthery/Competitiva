#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void intercambiar(int &a, int &b);
void merge(int v[], int inicio1, int fin1, int inicio2, int fin2);
void sel_directa(int arr[], int cant);
void inser_directa(int arr[], int cant);
void burbuja1(int arr[], int cant);
void burbuja2(int arr[], int cant);
void burbuja3(int arr[], int cant);
void mergesort(int v[], int inicio, int fin);


int main(int argc, char *argv[]) {
	
	int arr[100];
	int aux;
	
	srand(time(NULL));
	for(int i = 0; i < 100; i++){
		aux = rand() % 300;
		
		if(aux % 2 == 1)
			arr[i] = aux;
		else
			arr[i] = -aux;
	}
	
	
	
	cout << "Antes de ordenarlos" << endl;
	for(int i = 1; i <= 100; i++){
		cout << setfill(' ') << setw(5) << arr[i - 1];
		if(i % 15 == 0) cout << endl;
	}
	
	//Seleccionar algoritmo
	mergesort(arr,0,99);
	
	cout << endl << endl << "Despues de ordenarlos" << endl;
	for(int i = 1; i <= 100; i++){
		cout << setfill(' ') << setw(5) << arr[i - 1];
		if(i % 15 == 0) cout << endl;
	}
	
	return 0;
}

void sel_directa(int arr[], int cant){
	
	int min;
	
	for(int i = 0; i < cant; i++){
		min = i;
		
		for(int j = i + 1; j < cant; j++)
			if(arr[j] < arr[min])
				min = j;
		
		intercambiar(arr[i], arr[min]);
	}
}
	
void inser_directa(int arr[], int cant){
	
	int j;
	
	for(int i = 1; i < cant; i++){
		j = i;
		
		while(j > 0 and arr[j] < arr[j - 1]){
			
			intercambiar(arr[j], arr[j - 1]);
			j--;
		}
	}
}
	
void burbuja1(int arr[], int cant){
	
	for(int i = 1; i < cant; i++){
		
		for(int j = 0; j < cant - 1; j++){
			
			if(arr[j] > arr[j + 1])
				intercambiar(arr[j], arr[j + 1]);
		}
	}
}
	
void burbuja2(int arr[], int cant){
	
	for(int i = 1; i < cant; i++){
		
		for(int j = 0; j < cant - i; j++){
			
			if(arr[j] > arr[j + 1]){
				intercambiar(arr[j], arr[j + 1]);
			}
		}
	}
}
	
void burbuja3(int arr[], int cant){
	bool intercambios;
	int pasadas = 1;
	
	while(intercambios and pasadas < cant){
		
		intercambios = 0;
		for(int i = 0; i < cant - pasadas; i++){
			
			if(arr[i] > arr[i + 1]){
				
				intercambiar(arr[i], arr[i + 1]);
				intercambios = 1;
			}
		}
		pasadas++;
	}
}
	
void mergesort(int v[], int inicio, int fin){
	if(fin - inicio == 0)
		return;
	else{
		mergesort(v, inicio, (inicio + fin) / 2);
		mergesort(v, (inicio + fin) / 2 + 1, fin);
		merge(v, inicio, (inicio + fin) / 2, (inicio + fin) / 2 + 1, fin);
	}
}
	
void merge(int v[], int inicio1, int fin1, int inicio2, int fin2){
	
	int i = inicio1, j = inicio2, k = 0;
	int c[100];
	
	while(i <= fin1 and j <= fin2){
		if(v[i] < v[j]){
			c[k] = v[i];
			i++;
		}
		else{
			c[k] = v[j];
			j++;
		}
		k++;
	}
	
	while(i <= fin1){
		c[k] = v[i];
		k++;
		i++;
	}
	while(j <= fin2){
		c[k] = v[j];
		k++;
		j++;
	}
	
	//Guardamos la parte ordenada en el vector original
	for(k = 0; k < fin2 - inicio1 + 1; k++){
		v[inicio1 + k] = c[k];
	}
}
	
void intercambiar(int &a, int &b){
	
	int aux = a;
	a = b;
	b = aux;
}

