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
typedef pair<ll, int> ii;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
    vector<vector<ii>> G;  // ady. list with pairs (weight, dst)
    vector<vector<int>> vp;
    vector<ll> dist;
    vector<bool> calc;

    int N;
    Dijkstra(int n) : G(n), N(n), vp(n), calc(n){}
    void addEdge(int a, int b, ll w) { G[a].pb({w, b}); }
    void run(int src) {  // O(|E| log |V|)
        dist = vector<ll>(N, INF);

        priority_queue<ii, vector<ii>, greater<ii>> Q;
        Q.push({0, src}), dist[src] = 0;
        while (sz(Q)) {
            auto [d, node] = Q.top();
            Q.pop();
            if (d > dist[node] or calc[node]) continue; 
            calc[node] = true;
            forall(it, G[node]) {
                if(d + it->fr < dist[it->sc]) {
                    dist[it->sc] = d + it->fr;
                    vp[it->sc] = vector<int>{node};
                    Q.push({dist[it->sc], it->sc});
                }
                else if(d + it->fr == dist[it->sc]) vp[it->sc].pb(node);                
            }      
        }
    }

    vector<vector<int>> paths(){
        vector<vector<int>> g(N);
        forn(i, N){
            for(int &u : vp[i]) g[u].pb(i);
        }

        return g;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b, c;
    cin >> n >> m;

    Dijkstra dj(n);
    vector<vector<int>> g;
    vector<int> vis(n), to, dp1(n), dp2(n, 1e6), dp3(n);
    forn(i, m){
        cin >> a >> b >> c; a--; b--;
        dj.addEdge(a, b, c);
    }

    function<void(int)> dfs = [&](int s){
        if(vis[s]) return;
        vis[s] = true;

        for(int &u : g[s]){
            dfs(u);
        }
        to.pb(s);
    };


    dj.run(0);
    g = dj.paths();
    dfs(0);

    //forn(i, n) { vdbg(g[i])}
    //forn(i, n) { vdbg(dj.vp[i])}
    //vdbg(to);

    dp1[0] = 1;
    dfor(i, sz(to)){ //Cantidad rutas
        for(int &u : dj.vp[to[i]]) dp1[to[i]] = (dp1[to[i]] + dp1[u]) % MOD;
    }

    dp2[0] = 0;
    dfor(i, sz(to)){ //Ruta con minima cantidad de nodos
        for(int &u : dj.vp[to[i]]) dp2[to[i]] = min(dp2[to[i]], dp2[u] + 1);
    }

    dfor(i, sz(to)){ //Ruta con maxima cantidad de nodos
        for(int &u : dj.vp[to[i]]) dp3[to[i]] = max(dp3[to[i]], dp3[u] + 1);
    }

    cout << dj.dist[n - 1] << ' ' << dp1[n - 1] << ' ' << dp2[n - 1] << ' ' << dp3[n - 1] << '\n';

    
    return 0;
}