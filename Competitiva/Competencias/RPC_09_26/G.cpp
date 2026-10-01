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

#define lg(x) (31 - __builtin_clz(x))  //=floor(log2(x))
// Usage: 1) Create 2) Add edges 3) Call build 4) Use
struct LCA {
  int N, LOGN, ROOT;
  // vp[k][node] holds the 2^k ancestor of node
  // L[v] holds the level of v
  vector<int> L;
  vector<vector<int>> vp, G;
  LCA(int n) : N(n), LOGN(lg(n) + 1), L(n), G(n) {
    // Here you may want to replace the default from root to other
    // value, like maybe -1.
  }
  void addEdge(int a, int b) { G[a].pb(b), G[b].pb(a); }
  void dfs(int node, int p, int lvl) {
    vp[0][node] = p, L[node] = lvl;
    forall(it, G[node]) if (*it != p) dfs(*it, node, lvl + 1);
  }
  void build(int root) {
    // Here you may also want to change the 2nd param to -1
    ROOT = root;
    vp = vector<vector<int>>(LOGN, vector<int>(N, ROOT));
    dfs(ROOT, ROOT, 0);
    forn(k, LOGN - 1) forn(i, N) vp[k + 1][i] = vp[k][vp[k][i]];
  }
  int climb(int a, int d) {  // O(lgn)
    if (!d) return a;
    dfor(i, lg(L[a]) + 1) if (1 << i <= d) a = vp[i][a], d -= 1 << i;
    return a;
  }
  int lca(int a, int b) {  // O(lgn)
    if (L[a] < L[b]) swap(a, b);
    a = climb(a, L[a] - L[b]);
    if (a == b) return a;
    dfor(i, lg(L[a]) + 1) if (vp[i][a] != vp[i][b]) a = vp[i][a], b = vp[i][b];
    return vp[0][a];
  }
  int dist(int a, int b) {  // returns distance between nodes
    return L[a] + L[b] - 2 * L[lca(a, b)];
  }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<vector<int>> g(3e5);
    LCA lca(3e5);
    int a, b; 
    forn(i, n-1) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        lca.addEdge(a, b);
    }

    int dist = 0, ma = -1;
    auto dfs = [&](auto &&f, int s, int fat, int d) -> void {
        if(d > dist) {
            dist = d; 
            ma = s;
        }
        for(int u : g[s]) if(u != fat) f(f, u, s, d+1);
    };

    dfs(dfs, a, -1, 0);
    int ext1 = ma;
    ma = -1, dist = 0;
    dfs(dfs, ext1, -1, 0);
    int ext2 = ma;

    int q; cin >> q;
    vector<ii> queries(q);
    forn(i, q) {
        cin >> a >> b;
        lca.addEdge(a, b);
        queries[i] = {a, b};
    }

    lca.build(ext1);

    cout << dist << '\n';
    forn(i, q) {
        int a = queries[i].first;
        int d1 = lca.dist(a, ext1);
        int d2 = lca.dist(a, ext2);
        if(d1 > dist) {
            dist = d1;
            ext2 = a;
        }
        else if(d2 > dist) {
            dist = d2;
            ext1 = a;
        }

        cout << dist << '\n';
    }


    return 0;
}