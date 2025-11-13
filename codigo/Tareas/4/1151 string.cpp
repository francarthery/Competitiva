#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,X,anterior_1,anterior_2;
	string RESPUESTA="0 1 ";
	cin >> N;
	
	anterior_1=1;
	anterior_2=0;
	X=0;
	
	for(int i=2; i<N; i++){
		X=anterior_1+anterior_2;
		RESPUESTA=RESPUESTA+to_string(X)+" ";
		anterior_2=anterior_1;
		anterior_1=X;
	}
	
	size_t tam= RESPUESTA.length(); 
	RESPUESTA.erase(tam-1);
	cout << RESPUESTA <<endl;
	return 0;
}
