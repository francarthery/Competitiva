#include <iostream>

using namespace std;

#define TAM 600

int submatriz(int mat[][TAM], int i, int j, int N, int M){
	int mayor, p_col, p_fila = i, max_col = j;
	bool flag = true;
	
	while(mat[i][max_col] < mat[i][max_col + 1] and max_col < M - 1)
		max_col++;
	
	mayor = max_col - j + 1;
	p_col = max_col;

	while(flag){
		
		if(mat[p_fila][p_col] < mat[p_fila][p_col + 1] and p_col < max_col)
			p_col++;
		else{
			max_col = p_col;
			
			if(p_fila < N - 1 and mat[i][max_col] < mat[i + 1][j]){
				p_fila++;
				p_col = j;
			}
			else
				flag = false;
		}
		
		mayor = max(mayor, (p_col - j + 1) * (p_fila - i + 1));
	}

	return mayor;
}

int main(){
	
	int mayor = 0, N, M, mat[TAM][TAM];
	
	cin >> N >> M;
	
	while(N != 0 and M != 0){
		
		mayor = 0;
	
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cin >> mat[i][j];
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				mayor = max(mayor, submatriz(mat, i, j, N, M));
			}
		}
		
		cout << mayor << endl;
		cin >> N >> M;
	
	}
	
	return 0;
}

	
	
/*
	for(int i = 0; i < N; i++){
	for(int j = 1; j < M; j++){
	if(mat[i][j] > mat[i][j - 1]){
	if(aux[i][j - 1] == 0)
	aux[i][j - 1] = 1;
	
	aux[i][j] = aux[i][j - 1] + 1;
	}
	}
	}
	
	for(int j = 0; j < M; j++){
	for(int i = 1; i < N; i++){
	if(mat[i][j] > mat[i - 1][j]){
	if(aux2[i - 1][j] == 0)
	aux2[i - 1][j] = 1;
	
	aux2[i][j] = aux2[i - 1][j] + 1;
	}
	}
	}
	
	for(int i = 0; i < N; i++){
	for(int j = 0; j < M; j++){
	cout << aux[i][j] << "     ";
	}
	cout << endl;
	}
	cout << endl;
	
	for(int i = 0; i < N; i++){
	for(int j = 0; j < M; j++){
	cout << aux2[i][j] << "     ";
	}
	cout << endl;
	}
	
*/
