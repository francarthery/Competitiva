#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int A, B, C, D, aux;
	
	cin >> A >> B >> C >> D;
	
	if(A > C){
		aux = A;
		A = C;
		C = aux;
	}
	if(B > D){
		aux = B;
		B = D;
		D = aux;
	}
	if(A > B){
		aux = A;
		A = B;
		B = aux;
	}
	if(C > D){
		aux = C;
		C = D;
		D = aux;
	}
	if(B > C){
		aux = B;
		B = C;
		C = aux;
	}
	
	cout << A << " " << B << " " << C << " " << D << endl;
	
	return 0;
}

