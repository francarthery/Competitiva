#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,MULTIPLICACION; 
	
	cin >> N;
	
	for(int i=1; i<=10; i++){
		MULTIPLICACION=N*i;
		cout << i << " x " << N << " = " << MULTIPLICACION << endl;}
	
	
	return 0;
}

