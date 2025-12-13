#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int A,B,C,D,E;
	
	int N_PARES;
	
	N_PARES=0;
	
	cin >> A >> B >> C >> D >> E;
	
	if(A%2==0)
		N_PARES=N_PARES+1;
	if(B%2==0)
		N_PARES=N_PARES+1;
	if(C%2==0)
		N_PARES=N_PARES+1;	
	if(D%2==0)
		N_PARES=N_PARES+1;
	if(E%2==0)
		N_PARES=N_PARES+1;
	
	
	cout << N_PARES << " valores pares" << endl;
	return 0;
}
