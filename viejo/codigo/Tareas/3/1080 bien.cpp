#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, MAYOR, i, POSICION;
	
	MAYOR=0;
	for(i=1; i<101; i++){
		cin >> N;
		
		if(N>MAYOR){
			MAYOR=N;
			POSICION=i;}}
	
	cout << MAYOR << endl;
	cout << POSICION << endl;
	
	
	return 0;
}


