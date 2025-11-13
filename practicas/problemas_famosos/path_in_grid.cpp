#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n , x;
    cin >> n;
    vector<vector<int>> sum(n + 1, vector<int>(n + 1));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x; //Como siempre miro para arriba y la izquierda y eso ya esta en sum, no necesito guardar la cuadricula
            sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + x;
        }
    }

    cout << sum[n][n] << '\n';

    return 0;
}