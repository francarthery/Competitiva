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
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, e;
    while(cin >> n >> e){
        vector<vector<int>> m(e, vector<int>(e)), g(n), dp(n, vector<int>(e));
        vector<int> eq(n, -1);
        forn(i, e) forn(j, e) cin >> m[i][j];

        forn(i, e){
            int k, x; cin >> k;
            forn(j, k){
                cin >> x; 
                eq[x - 1] = i; 
            }
        }

        forn(i, n - 1){
            int a, b; cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        function<void(int, int)> dfs = [&](int s, int f){
            
            if(eq[s] != -1) forn(i, e) if(i != eq[s]) dp[s][i] = INF;

            for(int u : g[s]){
                if(u == f) continue;
                dfs(u, s);

                forn(i, e){
                    int best = INF;
                    forn(j, e) best = min(best, dp[u][j] + m[i][j]);
                    dp[s][i] += best;
                }
            }
        };

        dfs(0, -1);

        cout << *min_element(all(dp[0])) << '\n';

    }


    
    return 0;
}