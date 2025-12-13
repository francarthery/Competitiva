#include <iostream>
using namespace std;

bool tiene4(int N){
	while(N > 10){
		if(N % 10 == 4) return true;
		N /= 10;
	}
	if(N % 10 == 4) return true;
	else return false;
}

int main(int argc, char *argv[]) {
	
	int suma = 0;
	
	for(int i = 0; i < 10000; i++){
		suma += tiene4(i);
	}
	
	cout << suma << endl;
	
	return 0;
}

