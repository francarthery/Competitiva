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

    int n, m, r, e, a, b;

    while(cin >> n >> m >> r >> e){
        vector<vector<int>> g(n);
        vector<int> gr(n), vis(n);

        forn(i, m){
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
            gr[a]++;
            gr[b]++;
        }

        function<void(int, int)> dfs = [&](int s, int col){
            if(vis[s]) return;
            vis[s] = col;

            for(int u : g[s]) dfs(u, col);
        };

        ll col = 1, rta = 0;
        forn(i, n){
            if(vis[i] == 0){ 
                dfs(i, col);
                int ar = 0, node = 0;
                forn(j, n){
                    if(vis[j] == col) ar += gr[j], node++; // sumo grados
                }
                rta += min(((node * (node - 1)) / 2 - (ar / 2)) * r, node * e); //sumo lo que salga menos
                col++;
            }    
        }

        cout << rta << '\n';
    }
    
    return 0;
}