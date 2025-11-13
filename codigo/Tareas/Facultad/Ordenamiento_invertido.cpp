#include <iostream>
using namespace std;

void ins_directa(int arr[], int tam);
void burbuja3(int arr[], int tam);
void sel_directa(int arr[], int cant);
void merge_sort(int arr[], int inicio, int fin);
void merge(int arr[], int inicio1, int fin1, int inicio2, int fin2);

int main(int argc, char *argv[]) {
	
	int numeros[] = {45,2,-65,36,124,2,1586,-25,0,-36,43,74,74,-145};
	
	//ins_directa(numeros, 14);
	//burbuja3(numeros, 14);
	//sel_directa(numeros, 14);
	merge_sort(numeros, 0, 13);
	
	for(int i = 0; i < 14; i++){
		cout << numeros[i] << " ";
	}
	
	return 0;
}

void ins_directa(int arr[], int tam){
	int j;
	
	for(int i = 1; i < tam; i++){
		j = i;
		
		while(j > 0 and arr[j] > arr[j - 1]){
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}
	
void burbuja3(int arr[], int tam){
	
	int pasadas = 1;
	bool flag = true;
	
	while(flag and pasadas < tam){
		flag = false;
		
		for(int i = 0; i < tam - pasadas; i++){
			if(arr[i] < arr[i + 1]){
				swap(arr[i], arr[i + 1]);
				flag = true;
			}
		}
		pasadas++;
	}
}
	
void sel_directa(int arr[], int cant){
	int max;
	
	for(int i = 0; i < cant; i++){
		max = i;
		
		for(int j = i + 1; j < cant; j++){
			if(arr[j] > arr[max])
				max = j;
		}
		swap(arr[i], arr[max]);
	}
}
	
void merge_sort(int arr[], int inicio, int fin){
	
	if(inicio == fin)
		return;
	else{
		merge_sort(arr, inicio, (inicio + fin) / 2);
		merge_sort(arr, (inicio + fin) / 2 + 1, fin);
		merge(arr, inicio, (inicio + fin) / 2, (inicio + fin) / 2 + 1, fin);
	}
}
	
void merge(int arr[], int inicio1, int fin1, int inicio2, int fin2){
	
	int i = inicio1, j = inicio2, k = 0;
	int c[100];
	
	while(i <= fin1 and j <= fin2){
		if(arr[i] > arr[j])
			c[k++] = arr[i++];
		else
			c[k++] = arr[j++];
	}
	
	while(i <= fin1)
		c[k++] = arr[i++];
	
	while(j <= fin2)
		c[k++] = arr[j++];
	
	
	for(int i = inicio1; i <= fin2; i++){
		arr[i] = c[i - inicio1];
	}
}







