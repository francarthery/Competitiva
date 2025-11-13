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

const int MOD = 998244353;

vector<vector<int>> g;
vector<int> dist;

void dfs(int s){
    for(int &u : g[s]){
        dist[u] = dist[s] + 1;
        dfs(u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        g.assign(n, vector<int>());
        dist.assign(n, 0);

        forn(i, n - 1){
            cin >> x; x--;
            g[x].pb(i + 1);
        }

        dfs(0);
        map<int, vector<int>> m;
        forn(i, n) m[dist[i]].pb(i);

        vector<ll> dp(n);
        dp[0] = 1;
        ll ant = 0;
        for(auto v : m){
            if(v.fr == 0) continue;
            if(v.fr == 1) for(auto i : v.sc) {
                dp[i] = 1;
                ant += 1;
                continue;
            }
            ll nant = 0;

            for(int i : v.sc){
                for(int u : g[i]) {
                    dp[u] = (ant - dp[i] + MOD) % MOD;
                    nant = (nant + dp[u]) % MOD;
                }
            }
         
            ant = nant;
        }

        ll res = 0;
        forn(i, n) res = (res + dp[i]) % MOD;
        cout << res << '\n';
    }


    
    return 0;
}