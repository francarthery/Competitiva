#include <bits/stdc++.h>

using namespace std;

//Subsecuencia comun mas larga entre dos cadenas

int LCS(string A, string B){
    int n = A.length(), m = B.length();
    vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return dp[n][m];
}

int main(){

    string A, B;

    while(getline(cin, A) and getline(cin, B))
        cout << LCS(A, B) << endl;

    return 0;
}