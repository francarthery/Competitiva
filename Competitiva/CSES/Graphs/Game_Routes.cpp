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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> g(n), gt(n);
    vector<int> vis(n), to, dp(n), ant(n, -1);
    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        gt[b].pb(a);
    }

    function<void(int)> dfs = [&](int s){
        if(vis[s] != 0) return;
        vis[s] = 1;

        for(int &u : g[s]){
            dfs(u);
        }

        to.pb(s);
    };

    dfs(0);

    dp[0] = 1;
    dfor(i, sz(to)){ //Recorro nodos en orden topologico
        for(int &u : gt[to[i]]) dp[to[i]] = (dp[to[i]] + dp[u]) % MOD;
    }

    cout << dp[n - 1] << '\n';

    
    return 0;
}