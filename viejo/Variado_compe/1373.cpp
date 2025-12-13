#include <bits/stdc++.h>

using namespace std;

/*
Resolucion basada en algoritmo para calcular subsecuencia comun mas larga entre dos cadenas
extraido del libro "Introduccion en C++ a la programacion competitiva", pagina 124"
*/

int k;

//Subsecuencia comun mas larga entre dos cadenas. Bottom-up. O(n * m)
int LCS(string A, string B){
    int n = A.length(), m = B.length(), aux;
    if(k > min(m, n) + 2 or min(m, n) == 0) return 0;
    if(A == B) return A.size();

    vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            aux = 0;
            while(0 <= i - 1 - aux and 0 <= j - 1 - aux and A[i - 1 - aux] == B[j - 1 - aux]) {
                aux++;    
                if(aux >= k) 
                    dp[i][j] = max(dp[i][j], dp[i - aux][j - aux] + aux);
            }
        }

    return dp[n][m];
}

int main(){

    string A, B;

    while(cin >> k and k != 0){
        cin.ignore();
        getline(cin, A);
        getline(cin, B);
        cout << LCS(A, B) << endl;
    }

    return 0;
}