#include <iostream>
using namespace std;

int funcion(int arr[], int N);
int maximo(int arr[]);
int cifras(int arr[]);
int sumacifras(int N);

int main(int argc, char *argv[]) {
	
	int arr[20];
	int N;
	
	cin >> N;
	
	for(int i = 0; i < 20; i++){
		cin >> arr[i];
	}
	
	cout << endl << funcion(arr, N);
	
	return 0;
}

int funcion(int arr[], int N){
	
	int rta = 0;
	if(N % 2 == 0)
		rta = maximo(arr);
	else
		rta = cifras(arr);
	
	for(int i = 0; i < 20; i++){
		cout << "Diferencia con " << arr[i] << ": " << abs(N - arr[i]) << endl;
	}
	
	return rta;
}
	
int maximo(int arr[]){
	int max = arr[0];
	
	for(int i = 0; i < 20; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

int cifras(int arr[]){
	bool flag = true;
	int contador = 0;
	
	while(flag and contador < 20){
		if(arr[contador] > 9)
			flag = false;
		else
			contador++;
	}
	if(contador == 20){
		cout << "No hay ningun numero de dos cifras o mas" << endl;
		return -1;
	}
	else
		return sumacifras(arr[contador]);
}

int sumacifras(int N){
	if(N < 10) return N;
	else return (N % 10) + sumacifras(N / 10);
}

