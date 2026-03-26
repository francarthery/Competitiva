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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
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

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n);
        int a, b;
        forn(i, m) {
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        vector<int> vis(n, -1);
        bool puedo = true;
        int rojo = 0; 
        function<int(int, bool)> dfs = [&](int s, bool col) -> int{
            vis[s] = col;
            if(col) rojo++;
            int tam = 1; 

            for(int u : g[s]) {
                if(vis[u] == -1) tam += dfs(u, !col);
                else if(vis[u] == col) puedo = false;
            }
            return tam;
        };

        int ans = 0;
        forn(i, n) if(vis[i] == -1) {
            puedo = true;
            rojo = 0;
            int tam = dfs(i, 0);
            if(puedo) ans += max(rojo, tam - rojo); //si no entra me retiro de cp
        }

        cout << ans << '\n';
    }



    return 0;
}