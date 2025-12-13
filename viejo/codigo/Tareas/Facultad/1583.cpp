#include <iostream>
using namespace std;

void contaminador(char matriz[][50], int i, int j, int N, int M);

int main(int argc, char *argv[]) {
	
	int N, M;
	
	cin >> N >> M;
	
	while(N != 0 and M != 0){
	
		char matriz[50][50];
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cin >> matriz[i][j];
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(matriz[i][j] == 'T'){
					contaminador(matriz, i, j, N, M);
				}
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cout << matriz[i][j];
			}
			cout << endl;
		}
		
		cout << endl;
		cin >> N >> M;
	}
	
	return 0;
}

void contaminador(char matriz[][50], int i, int j, int N, int M){
	
	//De forma recursiva nos vamos expandiendo y convirtiendo a T las posiciones A
	if(i > 0 and matriz[i - 1][j] == 'A'){
		matriz[i - 1][j] = 'T';
		contaminador(matriz, i - 1, j, N, M);
	}
	if(i < N - 1 and matriz[i + 1][j] == 'A'){
		matriz[i + 1][j] = 'T';
		contaminador(matriz, i + 1, j, N, M);
	}
	if(j > 0 and matriz[i][j - 1] == 'A'){
		matriz[i][j - 1] = 'T';
		contaminador(matriz, i, j - 1, N, M);
	}
	if(j < M - 1 and matriz[i][j + 1] == 'A'){
		matriz[i][j + 1] = 'T';
		contaminador(matriz, i, j + 1, N, M);
	}
}


/*
6 7
XXAAXXX
XXAAXAX
XXXXAXX
XAAAAAX
TAAXAAA
XXXXXXX
*/
