#include <iostream>
using namespace std;

#define TAM 1000

int main(int argc, char *argv[]) {
	
	int N, K, pos = -1;
	int arr[TAM];
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i]; 
	}
	
	cin >> K;
	
	for(int i = 0; i < N; i++){
		if(arr[i] == K){
			pos = i;
			i = N;
		}
	}
	
	if(pos != -1)
		cout << pos << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}

