#include <iostream>

using namespace std;

int main() {
	
	int NUMERO, IMPARES;
	
	NUMERO=0;
	IMPARES=0;
	
	cin >> NUMERO;
	
	IMPARES=NUMERO;
	
	if(NUMERO%2==0)
		IMPARES=IMPARES+1;
	
	while((NUMERO+11)>=IMPARES){
		cout << IMPARES <<endl;
		IMPARES=IMPARES+2;
	}
	
	return 0;
}
