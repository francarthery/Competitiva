#include <iostream>
#include <array>

using namespace std;

int main() {
	
	int N;
	int LISTA[10];
	
	cin >> N;
	
	for(int i=0; i<=9; i++){
		LISTA[i]=N;
		N*=2;}
	
	for(int i=0; i<=9; i++){
		cout << "N[" << i << "] = " << LISTA[i] << endl;}
	
	return 0;
}