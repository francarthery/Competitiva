#include <iostream>

using namespace std;

int main() {
	
	int NUMERO, IMPARES;
	cin >> NUMERO;
	
	IMPARES=NUMERO;
	
	//Si el número es par, lo volvemos impar
	if(NUMERO%2==0)
		IMPARES=IMPARES+1;
	
	/*Sumamos 2 al numero original sin dejar que la suma exceda al
	numero+11 (Para lograr que se muestren solo 6 valores impares consecutivos)*/
	while((NUMERO+11)>=IMPARES){
		cout << IMPARES <<endl;
		IMPARES=IMPARES+2;
		}
	
	return 0;
}
