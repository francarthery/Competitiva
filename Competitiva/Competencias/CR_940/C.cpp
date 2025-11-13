#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    long long t, k, n, x, y, m;
    cin >> t;

    while(t--){
        cin >> n >> k;
        m = n;
        forn(i, k){ 
            cin >> x >> y;
            if(x != y) m -= 2;
            else m--;
        }
        vector<long long> dp(n + 1);
        dp[0] = dp[1] = 1;

        for(int i = 2; i <= m; i++){
            dp[i] = (dp[i - 1] + 2 * (i - 1) * dp[i - 2] % MOD) % MOD;
        }
        /*
        dp[i - 1] Solo tengo una posibilidad de poner un elemento en la diagonal principal si me fijo en la ult fila y columna
        Reduzco solamente una columna y una fila la matriz
        2 * (i - 1) * dp[i - 2] Tengo 2 * (i - 1) posibilidades para ubicar la torre fuera de la diagonal principal, y
        eliminaría 2 filas y dos columnas
        */

        cout << dp[m] << '\n';
    }

    return 0;
}