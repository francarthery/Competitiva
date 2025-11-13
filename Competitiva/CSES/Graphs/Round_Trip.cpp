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
 
vector<vector<int>> g;
vector<int> dist;
int prim = -1;
 
void dfs(int s){
    
    for(int &u : g[s]){
        if(prim != -1) return;
        if(dist[s] == u) continue;
        if(dist[u] != -1){
            dist[u] = s;
            prim = s;
            return;
        }
        else {
            dist[u] = s;
            dfs(u);
        }        
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
 
    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, -1);
 
    forn(i, m){
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
 
    forn(i, n) if(dist[i] == -1) dfs(i);
 
    if(prim != -1){
        int ini = prim;
        vector<int> rta{prim};
        prim = dist[prim];
        while(prim != ini){ //Reconstruyo ruta
            rta.pb(prim);
            prim = dist[prim];
        }
        cout << sz(rta) + 1 << '\n' << rta.back() + 1 << ' ';
        for(int &i : rta) cout << i + 1 << ' ';
    }
    else cout << "IMPOSSIBLE\n";
 
 
    return 0;
}