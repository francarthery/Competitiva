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

vector<int> ant;
vector<bool> vis;
vector<vector<int>> g;
unordered_set<int> compo;
bool flag = false;
int prim;

void dfs(int s){
    if(!compo.count(s)) return;
    if(vis[s]) {
        flag = true;
        prim = s;
        return;
    }
    
    vis[s] = true;
    for(int u : g[s]){
        if(flag) return;
        ant[u] = s;
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

    int n, m, a, b;
    cin >> n >> m;
    Kosaraju ks(n);
    ant.assign(n, -1);
    g.resize(n);
    vis.resize(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        ks.addEdge(a, b);
        g[a].pb(b);
    }

    ks.run();
    map<int, ii> mp; // (numero comp, (cantidad nodos, un nodo de la comp))
    forn(i, sz(ks.comp)) {
        mp[ks.comp[i]].fr++;
        mp[ks.comp[i]].sc = i;
    }
    
    bool valid = false;
    for(auto &i : mp){
        if(i.sc.fr > 1){
            forn(j, sz(ks.comp)) if(i.fr == ks.comp[j]) compo.insert(j);
            dfs(i.sc.sc);
            vector<int> res;
            int val = ant[prim];
            res.pb(prim);
            while(val != prim){
                res.pb(val);
                val = ant[val];
            }
            res.pb(prim);
            cout << sz(res) << '\n';
            dfor(j, sz(res)) cout << res[j] + 1 << ' ';
            cout << '\n';
            valid = true;
            break;
        }
    }

    if(!valid) cout << "IMPOSSIBLE\n";

    
    return 0;
}