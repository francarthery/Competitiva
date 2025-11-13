#include <bits/stdc++.h>
#define forr(i, a, n) for(ll i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
 
    const int MOD = 1e9 + 7;
    const ll MAXN = 1e6 + 1;
    ll n; cin >> n;
    ll res = 0;
 
    forr(i, 2, MAXN){
        if(i > n) break;
        res += (n / i) * i - i; //Sumo la cantidad de numeros que tienen a i como divisor, excepto el mismo i (lo sumo al final)
        res %= MOD;
 
        if(n > MAXN){
            __int128_t ma = n / i;
            if(ma < MAXN) continue;
            res += ((MAXN + ma) * (ma - MAXN + 1) / 2) % MOD; //Sumo los divisores mayores a MAXN (MAXN, MAXN + 1, ... , n / i)
            res %= MOD;
        }
    }

    n %= MOD;
    res += (n + n * (n + 1) / 2 - 1) % MOD; // Cada numero es divisor de si mismo y todos son divisibles por 1 (el -1 va por el 1 que es caso especial)

    cout << res << '\n';
    
    return 0;
}