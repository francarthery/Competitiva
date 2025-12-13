#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, resultado = 0;
	char A[201], B[201];
	
	cin >> N;
	
	cin.ignore(); 
	cin.getline(A, sizeof(A));  
	cin.getline(B, sizeof(B));
	
	for(int i = 0; i < N; i++){
		
		if(abs((int)(A[i]-B[i])) <= 5)
			resultado += abs((int)(A[i]-B[i]));
		else
			resultado += 10 - abs((int)(A[i]-B[i]));
	}
	
	cout << resultado << endl;
	
	return 0;
}


