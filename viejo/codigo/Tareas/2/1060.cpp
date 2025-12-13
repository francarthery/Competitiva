#include <iostream>

using namespace std;

int main() {
	
	float A,B,C,D,E,F;
	
	int N_POSITIVOS;
	
	N_POSITIVOS=0;
	
	cin >> A >> B >> C >> D >> E >> F;
	
	if(A>0)
		N_POSITIVOS=N_POSITIVOS+1;
	if (B>0)
		N_POSITIVOS=N_POSITIVOS+1;
	if (C>0)
		N_POSITIVOS=N_POSITIVOS+1;	
	if (D>0)
		N_POSITIVOS=N_POSITIVOS+1;
	if (E>0)
		N_POSITIVOS=N_POSITIVOS+1;
	if (F>0)
		N_POSITIVOS=N_POSITIVOS+1;
	
	cout << N_POSITIVOS << " valores positivos" << endl;
	return 0;
}
