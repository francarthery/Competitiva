#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,H,M,S;
	cin >> N;
	
	string RESULTADO;
	
	H=N/3600;
	M=(N-(H*3600))/60;
	S=N-(H*3600)-(M*60);
	
	RESULTADO=to_string(H)+":"+to_string(M)+":"+to_string(S);
	
	cout << RESULTADO << endl;
	return 0;
}

