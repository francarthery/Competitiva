#include <iostream>
using namespace std;

#define TAM 100

bool picos_valles(int H[], int N);

int main(int argc, char *argv[]) {
	
	int N;
	int H[TAM];
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
		cin >> H[i];
	
	cout << picos_valles(H, N) << endl;
	
	return 0;
}

bool picos_valles(int H[], int N){
	
	bool prox = true, rta = true;
	int contador = 0;
	
	if(H[0] > H[1])
		prox = false;
	
	while(rta and contador <= N - 2){
		if(prox == true and H[contador] <= H[contador + 1])
		    prox = false;
		else if(prox == false and H[contador] >= H[contador + 1])
			prox = true;
		else
			rta = false;
		contador++;
	}
	
	return rta;
}

