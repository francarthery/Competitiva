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

const int MOD = 1e9+7;
typedef ll Elem;
typedef ll Alt;
typedef Elem tipo;
const Elem neutro = 0;
const Alt neutro2 = 1;
Elem oper(const Elem& a, const Elem& b) { return (a + b) % MOD; }
struct ST {
  int sz;
  vector<Elem> t;
  vector<Alt> dirty;  // Alt and Elem could be different types
  ST(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    t = vector<Elem>(2 * sz, neutro);
    dirty = vector<Alt>(2 * sz, neutro2);
  }
  Elem& operator[](int p) { return t[sz + p]; }
  void updall() { dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
  void push(int n, int a, int b) {  // push dirt to n's child nodes
    if (dirty[n] != neutro2) {      // n = node of range [a,b)
      t[n] = t[n] * dirty[n] % MOD;   // CHANGE for your problem
      if (n < sz) {
        dirty[2 * n] = dirty[2*n] * dirty[n] % MOD;      // CHANGE for your problem
        dirty[2 * n + 1] = dirty[2*n + 1] * dirty[n] % MOD;  // CHANGE for your problem
      }
      dirty[n] = neutro2;
    }
  }
  Elem get(int i, int j, int n, int a, int b) {  // O(lgn)
    if (j <= a || b <= i) return neutro;
    push(n, a, b);                      // adjust value before using it
    if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
    int c = (a + b) / 2;
    return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  Elem get(int i, int j) { return get(i, j, 1, 0, sz); }
  // altera los valores en [i, j) con una alteracion de val
  void update(Alt val, int i, int j, int n, int a, int b) {  // O(lgn)
    push(n, a, b);
    if (j <= a || b <= i) return;
    if (i <= a && b <= j) {
      dirty[n] = dirty[n] * val % MOD;  // CHANGE for your problem
      push(n, a, b);
      return;
    }
    int c = (a + b) / 2;
    update(val, i, j, 2 * n, a, c), update(val, i, j, 2 * n + 1, c, b);
    t[n] = oper(t[2 * n], t[2 * n + 1]);
  }
  void update(Alt val, int i, int j) { update(val, i, j, 1, 0, sz); }
};  // Use: definir operacion, neutros, Alt, Elem, uso de dirty
// cin >> n; ST st(n); forn(i,n) cin >> st[i]; st.updall()


// Usage: 1. HLD(# nodes) 2. add tree edges 3. build() 4. use it
struct HLD {
  vector<int> w, p, dep;  // weight,father,depth
  vector<vector<int>> g;
  HLD(int n) : w(n), p(n), dep(n), g(n), pos(n), head(n) {}
  void addEdge(int a, int b) { g[a].pb(b), g[b].pb(a); }
  void build() { p[0] = -1, dep[0] = 0, dfs1(0), curpos = 0, hld(0, -1); }
  void dfs1(int x) {
    w[x] = 1;
    for (int y : g[x]) if (y != p[x]) {
        p[y] = x, dep[y] = dep[x] + 1, dfs1(y);
        w[x] += w[y];
      }
  }
  int curpos;
  vector<int> pos, head;
  void hld(int x, int c) {
    if (c < 0) c = x;
    pos[x] = curpos++, head[x] = c;
    int mx = -1;
    for (int y : g[x]) if (y != p[x] && (mx < 0 || w[mx] < w[y])) mx = y;
    if (mx >= 0) hld(mx, c);
    for (int y : g[x]) if (y != mx && y != p[x]) hld(y, -1);
  }
  // Here ST is segtree static/dynamic/lazy or other DS according to problem
  tipo query(int x, int y, ST& st) {  // ST tipo
    tipo r = neutro;
    while (head[x] != head[y]) {
      if (dep[head[x]] > dep[head[y]]) swap(x, y);
      r = oper(r, st.get(pos[head[y]], pos[y] + 1));  // ST oper
      y = p[head[y]];
    }
    if (dep[x] > dep[y]) swap(x, y);          // now x is lca
    r = oper(r, st.get(pos[x]+1, pos[y] + 1));  // ST oper
    return r;
  }

  void upd(int x, int y, Alt elem, ST& st) {
    while (head[x] != head[y]) {
        if (dep[head[x]] > dep[head[y]]) swap(x, y);
        st.update(elem, pos[head[y]], pos[y] + 1);  // ST oper
        y = p[head[y]];
    }
    if (dep[x] > dep[y]) swap(x, y);          // now x is lca
    st.update(elem, pos[x]+1, pos[y] + 1);  // ST oper
  }
};
// for point updates: st.set(pos[x], v) (x = node, v = new value)
// for lazy range updates: something similar to the query method
// for queries on edges: - assign values of edges to "child" node
//                       - change pos[x] to pos[x]+1 in query (line 34)


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int a, b, c, n, q; cin >> n >> q;
    HLD hld(n);
    ST lazy(n);
    vector<array<int, 3>> ar(n-1);

    forn(i, n-1) {
        cin >> a >> b >> c; a--; b--;
        hld.addEdge(a, b);
        ar[i] = {a, b, c}; 
    }

    hld.build();
    forn(i, n-1) {
        if(hld.dep[ar[i][0]] > hld.dep[ar[i][1]]) lazy[hld.pos[ar[i][0]]] = ar[i][2];
        else lazy[hld.pos[ar[i][1]]] = ar[i][2];
    }

    lazy.updall();

    int u, v;
    forn(i, q) {
        cin >> u >> v >> c; u--; v--;
        hld.upd(u, v, c, lazy);
        cout << hld.query(u, v, lazy) << '\n';
    }

    return 0;
}