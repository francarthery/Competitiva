#include <iostream>
#include <cmath>
using namespace std;

int cant_d(int N, int pos){
	if(pos == -1 or N == -1)
		return 0;
	else if(pos == 1){
		if(N >= 4) return 1;
		else return 0;
	}
	else if(pos == 2){
		if(N > 4) return 10 + N - 1;
		else return N - 1;
	}
	else{
		if(N > 4) return pow(10, pos - 1) + cant_d(10, pos - 1) * abs(N - 1);
		else return cant_d(10, pos - 1) * abs(N - 1);
	}
	
}

int digitos(int N){
	
	int pos = 1, rta = 0, aux = N;
	
	while(aux > 1){
		aux /= 10;
		pos++;
	}
	
	for(int i = 0; i < pos - 1; i++){
		rta += cant_d((N / (int)pow(10, pos - 1 - i)) % 10 - 1, pos - i);
	}
	
	return rta;
}

int main() {
	
	int N;
	
	cin >> N;
	
	cout << digitos(N) << endl;
	
	return 0;
}

