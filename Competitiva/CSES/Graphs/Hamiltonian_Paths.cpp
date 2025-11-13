#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
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
 
const int MOD = 1e9 + 7;
int dp[(1 << 20)][20];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
 
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n);
    memset(dp, 0, sizeof(dp));
    forn(i, m){
        cin >> a >> b;
        g[b - 1].pb(a - 1);
    }
 
    dp[1][0] = 1; //inicialmente tengo el subconjunto con el 1 que termina en el nodo 1(0)
 
    forr(i, 2, 1 << n){
        if(!(i & 1)) continue; //tiene que tener la primer ciudad
        if((i & (1 << (n - 1))) and i != (1 << n) - 1) continue;

        forn(j, n){
            if(i & (1 << j)){ //si ese bit esta prendido
                int val = (i ^ (1 << j)); //subconjunto sin j
                for(int &k : g[j]){
                    if(val & (1 << k)) dp[i][j] = (dp[i][j] + dp[val][k]) % MOD;
                }
            }
        }
    }
 
    cout << dp[(1 << n) - 1][n - 1] << '\n';
    
    return 0;
}