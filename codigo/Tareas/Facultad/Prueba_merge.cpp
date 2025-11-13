#include <iostream>
using namespace std;

#define TAM 15

void mostrar_vector(int arr[], int cant);
void merge_vec(int arr1[], int arr2[], int arr3[], int cant1, int cant2);
	

int main(int argc, char *argv[]) {
	
	int arr1[TAM], arr2[TAM], arr3[TAM * 2];
	int cant1, cant2, cant3;
	
	cin >> cant1;
	for(int i = 0; i < cant1; i++){
		cin >> arr1[i];
	}
	
	cin >> cant2;
	for(int i = 0; i < cant2; i++){
		cin >> arr2[i];
	}
	
	mostrar_vector(arr1, cant1);
	mostrar_vector(arr2, cant2);
	
	cant3 = cant1 + cant2;
	
	merge_vec(arr1, arr2, arr3, cant1, cant2);
	
	mostrar_vector(arr3, cant3);
	
	return 0;
}

void mostrar_vector(int arr[], int cant){
	
	for(int i = 0; i < cant; i++){
		cout << arr[i] << "  ";
	}
	cout << endl;
}
	
void merge_vec(int arr1[], int arr2[], int arr3[], int cant1, int cant2){
	
	int i = 0, j = 0, k = 0;
	
	while(i < cant1 and j < cant2){
		if(arr1[i] < arr2[j]){
			arr3[k] = arr1[i];
			i++;
		}
		else{
			arr3[k] = arr2[j];
			j++;
		}
		
		k++;
	}
	
	while(i < cant1){
		arr3[k] = arr1[i];
		i++;
		k++;
	}
	
	while(j < cant2){
		arr3[k] = arr2[j];
		j++;
		k++;
	}
}
