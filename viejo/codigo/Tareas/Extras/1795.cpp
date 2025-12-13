#include <iostream>

using namespace std;
	
int main (){
	
	int N, cont = 0;
	
	cin >> N;
	
	int Arr[N];
	
	for (int i = 1; i < N+1; i++){
		cin >> Arr[i];
	}
	
	Arr[0] = Arr[N];
	Arr[N+1] = Arr[1];
	
	for (int i = 0; i < 2; i++){
		for (int j = 1; j < N+1; j++){
			if (Arr[j] > Arr[j-1] and Arr[j] > Arr[j+1]) cont++;
			
		}
	}
	cout << cont << endl;

	return 0;
}