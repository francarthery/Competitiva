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
vector<int> vis, topo;

struct Kosaraju {
    vector<vector<int>> G, gt;
    // nodos 0...N-1 ; componentes 0...cantcomp-1
    int N, cantcomp;
    vector<int> comp, used;
    stack<int> pila;
    Kosaraju(int n) : G(n), gt(n), N(n), comp(n) {}
    void addEdge(int a, int b) { G[a].pb(b), gt[b].pb(a); }
    void dfs1(int nodo) {
      used[nodo] = 1;
      forall(it, G[nodo]) if (!used[*it]) dfs1(*it);
      pila.push(nodo);
    }
    void dfs2(int nodo) {
      used[nodo] = 2;
      comp[nodo] = cantcomp - 1;
      forall(it, gt[nodo]) if (used[*it] != 2) dfs2(*it);
    }
    void run() {
      cantcomp = 0;
      used = vector<int>(N, 0);
      forn(i, N) if (!used[i]) dfs1(i);
      while (!pila.empty()) {
        if (used[pila.top()] != 2) {
          cantcomp++;
          dfs2(pila.top());
        }
        pila.pop();
      }
    }
};

void dfs(int s){
    if(vis[s]) return;
    vis[s] = true;

    for(int &u : g[s]) dfs(u);
    topo.pb(s);
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
    Kosaraju ks(n);
    vector<int> v(n);
    vector<ii> ar(m);
    forn(i, n) cin >> v[i];

    forn(i, m){
        cin >> a >> b; a--; b--;
        ks.addEdge(a, b);
        ar[i] = {a, b};
    }

    ks.run();
    g.resize(ks.cantcomp);
    vis.resize(ks.cantcomp);
    vector<ll> dp(ks.cantcomp);

    for(ii &i : ar){
        if(ks.comp[i.fr] != ks.comp[i.sc]) g[ks.comp[i.fr]].pb(ks.comp[i.sc]); //Construyo grafo de SCC
    }

    forn(i, n) dp[ks.comp[i]] += v[i]; //Pesos de cada SCC
    forn(i, ks.cantcomp) if(vis[i] == 0) dfs(i); //Orden topologico del grafo

    forn(i, ks.cantcomp){
        ll ma = 0;
        for(int &u : g[topo[i]]) ma = max(ma, dp[u]); //Me fijo el hijo de topo[i] que suma mas
        dp[topo[i]] += ma;
    }

    cout << *max_element(all(dp)) << '\n';

    return 0;
}