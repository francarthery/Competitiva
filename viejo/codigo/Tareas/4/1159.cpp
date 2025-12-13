#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int X,suma,pares=0;
	
	cin >> X;
	
	while(X!=0){
		if(X%2==0)
			pares=X;
		else
			pares=(X+1);
		suma=pares;
		for(int i=1; i<5; i++){
			pares=pares+2;
			suma+=pares;}
		cout << suma << endl;
		cin >> X;
	}
	return 0;
}

/* Intruduzco número
Si el numero es distinto de 0:
	almaceno en variable la suma de los 5 consecutivos al numero*/
