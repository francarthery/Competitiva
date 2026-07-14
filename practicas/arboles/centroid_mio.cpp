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

ll ans = 0, k;

struct LCA{
    int root, N, lgn;
    vector<int> lv;
    vector<vector<int>> vp, g;

    LCA(int n, int rt) : N(n), root(rt), g(n), lv(n) {
        lgn = __lg(n) + 1;
        vp.assign(lgn, vector<int>(n));
    }  
    void addEdge(int a, int b) { g[a].pb(b); g[b].pb(a); }

    void dfs(int s, int f, int l){
        lv[s] = l; vp[0][s] = f;
        for(int u : g[s]) if(u != f) dfs(u, s, l + 1);
    }

    void build(){
        vp[0][root] = root; //buclecito en la raiz
        dfs(root, root, 0);
        forn(i, lgn - 1) forn(j, N) vp[i + 1][j] = vp[i][vp[i][j]];
    }

    int climb(int a, int d){
        while(d){
            a = vp[__builtin_ctz(d)][a]; d &= (d - 1);
        }    
        return a;
    }

    int lca(int a, int b){
        if(lv[a] < lv[b]) swap(a, b);
        a = climb(a, lv[a] - lv[b]);
        if(a == b) return a;
        dfor(i, lgn) if(vp[i][a] != vp[i][b]){
            a = vp[i][a], b = vp[i][b];
        }
        return vp[0][a];
    }

    int dist(int a, int b){
        return lv[a] + lv[b] - 2 * lv[lca(a, b)];
    }
};

struct Centroid {
    int n;
    vector<vector<int>> g;
    vector<int> tam, fat;
    vector<bool> vis;

    Centroid(int N) : n(N) {
        g.resize(N);
        tam.resize(n);
        vis.resize(n);
        fat.resize(n);
    }

    void addEdge(int a, int b) {g[a].pb(b), g[b].pb(a);}
    
    void dfs(int s, int f) {
        tam[s] = 1;
        for(int u : g[s]) if(u != f and !vis[u]) {
            dfs(u, s);
            tam[s] += tam[u];
        }
    }

    void centroide(int s, int p, int szcomp) {
        if(szcomp == -1) { //Entre por primera vez, necesito tam de subarboles
            dfs(s, -1);
            szcomp = tam[s];
        }
        tam[s] = 0; //Con esto me evito llevar el padre
        for(int u : g[s]) if(!vis[u] and tam[u] > szcomp / 2) { //Si el nodo no tiene hijos con mas de floor(n/2) nodos, es el centroide
            centroide(u, p, szcomp);
            return;
        }
        vis[s] = true; fat[s] = p; //Marco el centroide y el padre
        
        //Parte tuneable
       

        for(int u : g[s]) if(!vis[u]) { centroide(u, s, -1); }
    }

    void run(int root) { centroide(root, -1, -1); }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int a, b, n; cin >> n >> k;
    Centroid cn(n);
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        cn.addEdge(a, b);
    }

    cn.run(0);
    cout << ans << '\n';

    return 0;
}