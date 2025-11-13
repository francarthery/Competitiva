#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	
	int N, X, R = 0;
	bool bajando = true;
	 
	for(;;){
	cin >> N;
	
	if(N == 0)break;
	
	R = 0; bajando = true;
	
	int lista[(N*2)+2];
	
	for (int i = 1, j = N+1; i <= N; i++, j++){
		cin >> X;
		lista[i] = X;
		lista[j] = X;
	}

    lista[0] = lista[N];
    lista[(N*2)+1] = lista[1];
		
	for (int i = 1; i < (N*2)+1; i++){
       
        if(lista[i] > lista[i+1] and lista[i] > lista[i-1]){
			R++;
        }
	}
		cout << R << endl;
	}
		
	return 0;
}

/*
10
-4 8 9 5 2 1 0 -4 -5 -6 -4 8 9 5 2 1 0 -4 -5 -6

10
50 6 70 9000 8000 -1000 1 2 3 4 50 6 70 9000 8000 -1000 1 2 3 4

4 50 6 70 9000 8000 -1000 1 2 3 4 50 6 70 9000 8000 -1000 1 2 3 4 50
*/