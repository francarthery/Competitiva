#include <iostream>
#include <cstring>
using namespace std;

int v[1000];
int dp[1000];

int f(int i){
	
	if(dp[i] != -1) return dp[i];
	
	int sol = 1;
	for(int j = 0; j < i; j++)
		if(v[j] < v[i])
			sol = max(sol, 1 + f(j));
	
	return dp[i] = sol;
	
}

int main() {
	
	int N, sol;
	
	while(cin >> N){
		
		sol = 0;
		memset(dp, -1, sizeof(dp)); //Inicializamos en -1 a dp
		for(int i = 0; i < N; i++){
			cin >> v[i];
			sol = max(sol, f(i)); //Calculamos la maxima subsecuencia con i como ultimo elemento.
		}
		
		cout << sol << endl;
	}
	
	return 0;
}

