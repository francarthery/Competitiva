#include <iostream>
using namespace std;

bool Incognita(int x, int y);

int main(int argc, char *argv[]) {
	
	int N;
	
	cin >> N;
	
	int generados = 0, numero = 2;
	
	while(generados < N){
		if(Incognita(numero, numero - 1))
			generados++;
		
		numero++;
	}
	
	cout << numero - 1 << endl;
	
	return 0;
}

bool Incognita(int x, int y){
	
	if(y == 1) return true;
	else{
		if(x % y == 0) return false;
		else return Incognita(x, y - 1);
	}
}
