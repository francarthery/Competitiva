#include <iostream>
using namespace std;

void borrar(int arr[], int pos, int &N);

#define TAM 100

int main(int argc, char *argv[]) {
	
	int N, X, mayor = 0;
	
	cin >> N;
	
	int arr[TAM];
	
	for(int i = 0; i < N; i++){
		cin >> X;
		
		arr[i] = X;
		
		if(mayor < X)
			mayor = X;
	}
	
	for(int i = 0; i < N; i++){
		if(arr[i] == mayor){
			borrar(arr, i, N);
			i--;
		}
	}
	
	cout << N << endl;
	
	for(int i = 0; i < N; i++){
		cout << arr[i];
		if(N > i + 1)
			cout << " ";
	}
	
	
	return 0;
}

void borrar(int arr[], int pos, int &N){
	
	for(int i = pos; i < N; i++)
		arr[i] = arr[i + 1];
	
	N--;
}

