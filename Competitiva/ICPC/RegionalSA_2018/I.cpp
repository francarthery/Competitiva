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

#define lg(x) (31 - __builtin_clz(x))  

struct LCA {
    int N, LOGN, ROOT;
    vector<int> L;
    vector<vector<ii>> G;
    vector<vector<ii>> vp;
    LCA(int n, int root) : N(n), LOGN(lg(n) + 1), ROOT(root), L(n), G(n) {
        vp = vector<vector<ii>>(LOGN, vector<ii>(n, ii(root, root)));
    }
    
    void addEdge(int a, int b, int c) { G[a].pb({b, c}), G[b].pb({a, c}); }
    void dfs(int node, int p, int ar, int lvl) {
        vp[0][node] = {p, ar}, L[node] = lvl;
        forall(it, G[node]) if (it -> fr != p) dfs(it -> fr, node, it -> sc, lvl + 1);
    }

    void build() {
        dfs(ROOT, ROOT, 0, 0);
        forn(k, LOGN - 1) forn(i, N) {
            vp[k + 1][i].fr = vp[k][vp[k][i].fr].fr;
            vp[k + 1][i].sc = max(vp[k][i].sc, vp[k][vp[k][i].fr].sc); //Calculo el maximo del camino
        }
    }

    int climb(int &a, int d) {  // O(lgn)
        int ma = 0;
        dfor(i, lg(L[a]) + 1) if (1 << i <= d) {
            ma = max(ma, vp[i][a].sc);
            a = vp[i][a].fr, d -= 1 << i;
        }
        return ma;
    }

    int lca(int a, int b) {  // O(lgn)
        if (L[a] < L[b]) swap(a, b);
        int ma2 = 0, ma1 = climb(a, L[a] - L[b]); //El a se actualiza por referencia
        if (a == b) return ma1;
        dfor(i, lg(L[a]) + 1) if (vp[i][a].fr != vp[i][b].fr) {
            ma1 = max(ma1, vp[i][a].sc); //Maximo entre los dos brazos
            ma2 = max(ma2, vp[i][b].sc);
            a = vp[i][a].fr, b = vp[i][b].fr;
        }
        ma1 = max(ma1, vp[0][a].sc);
        ma2 = max(ma2, vp[0][b].sc);
        return max(ma1, ma2);
    }
};

struct UnionFind {
    int nsets;
    vector<int> f, setsz;  // f[i] = parent of node i
    UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
    int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
    bool join(int i, int j) {  // returns true if already in the same set
        int a = comp(i), b = comp(j);
        if (a != b) {
            if (setsz[a] > setsz[b]) swap(a, b);
            f[a] = b;  // the bigger group (b) now represents the smaller (a)
            nsets--, setsz[b] += setsz[a];
        }
        return a == b;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<pair<int, ii>> v(m);
    map<ii, int> costos;
    forn(i, m){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        v[i] = {c, {a, b}};
        if(a > b) swap(a, b);
        costos[{a, b}] = c;
    }

    LCA lca(n, 0);
    ll cost = 0; 
    sort(all(v)); 
    UnionFind uf(n);
    for(auto i : v) if(!uf.join(i.sc.fr, i.sc.sc)){
        cost += i.fr;
        lca.addEdge(i.sc.fr, i.sc.sc, i.fr);
    }

    lca.build();

    int q; cin >> q;
    forn(i, q){
        int a, b; cin >> a >> b; a--; b--;
        if(a > b) swap(a, b);
        cout << cost - lca.lca(a, b) + costos[{a, b}] << '\n'; //MST - arista mas gorda del MST + costo de la que agrego
    }


    return 0;
}