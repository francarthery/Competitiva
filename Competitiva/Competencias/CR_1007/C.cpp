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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, ini, fin, a, b;
        cin >> n >> ini >> fin;
        vector<vector<int>> g(n);
        vector<int> dist(n, -1);
        
        forn(i, n - 1){
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        function<void(int)> dfs = [&](int s){
            for(int &u : g[s]) {
                if(dist[u] == -1) {
                    dist[u] = dist[s] + 1;
                    dfs(u);
                }
            }
        };

        dist[fin - 1] = 0;
        dfs(fin - 1);
        
        vector<ii> res;
        forn(i, n) res.pb({dist[i], i + 1});
        sort(rall(res));
        forn(i, n) cout << res[i].sc << ' ';
        cout << '\n';
    }


    
    return 0;
}