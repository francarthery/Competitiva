#include <iostream>
using namespace std;

#define TAM 1000

int busqueda_binaria(int arr[], int N, int buscar);

int main(int argc, char *argv[]) {
	
	int arr[TAM];
	int N, indice, buscar;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	cout << "\nQue valor deseas buscar?" << endl;
	
	cin >> buscar;
	
	indice = busqueda_binaria(arr, N, buscar);
	
	cout << "El valor se encuentra en el indice: " << indice << endl;
	
	return 0;
}

int busqueda_binaria(int arr[], int N, int buscar){
	
	int inicio = 0, fin = N - 1;
	int centro = (inicio + fin) / 2;
	
	while(arr[centro] != buscar and inicio <= fin){
		if(arr[centro] > buscar)
			fin = centro - 1;
		else
			inicio = centro + 1;
		
		centro = (inicio + fin) / 2;
	}
	if(inicio > fin)
		centro = -1;
	
	return centro;
}

