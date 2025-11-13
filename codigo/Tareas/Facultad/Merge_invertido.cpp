#include <iostream>
using namespace std;

void merge(int vector1[], int vector2[], int vector3[], int cant1, int cant2);

int main(int argc, char *argv[]) {
	
	int vector1[10] = {1,5,6,9,34,56,76,543,765,971};
	int vector2[10] = {2,5,7,10,33,35,63,123,345,600};
	int vector3[20];
	
	merge(vector1, vector2, vector3, 10, 10);
	
	for(int i = 0; i < 20; i++){
		cout << vector3[i] << " ";
	}
	
	return 0;
}

void merge(int vector1[], int vector2[], int vector3[], int cant1, int cant2){
	
	int i, j, k = 0;
	i = j = 9;
	
	while(i >= 0 and j >= 0){
		if(vector1[i] > vector2[j])
			vector3[k++] = vector1[i--];
		else
			vector3[k++] = vector2[j--];
	}
	
	while(i >= 0)
		vector3[k++] = vector1[i--];
	
	while(j >= 0)
		vector3[k++] = vector1[j--];
	
}

