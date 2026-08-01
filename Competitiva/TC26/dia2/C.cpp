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
typedef pair<int, ll> ii;

typedef ll Elem;
typedef ll Alt;
const Elem neutro = 1e17;
const Alt neutro2 = 0;
Elem oper(const Elem& a, const Elem& b) { return min(a, b); }
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
      t[n] += dirty[n];   // CHANGE for your problem
      if (n < sz) {
        dirty[2 * n] += dirty[n];      // CHANGE for your problem
        dirty[2 * n + 1] += dirty[n];  // CHANGE for your problem
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
      dirty[n] += val;  // CHANGE for your problem
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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    int n, q; cin >> n >> q;
    vector<vector<ii>> g(n);
    int x, w;
    forn(i, n-1) {
        cin >> x >> w; x--;
        g[x].pb({i+1, w});
    }

    ST st(n);
    vector<ii> inter(n); //hojas que cuelgan del subarbol de i
    forn(i, n) inter[i] = {1e9, -1e9};
    map<int, vector<array<int, 3>>> queries;
    function<void(int, int, ll)> dfs1 = [&](int s, int f, ll dist) {
        if(!sz(g[s])) {
            st[s] = dist;
            inter[s] = {s, s};
        }
        for(auto u : g[s]) if(u.fr != f) {
            dfs1(u.fr, s, dist + u.second);
            inter[s].first = min(inter[s].first, inter[u.first].first);
            inter[s].second = max(inter[s].second, inter[u.first].second);
        }
    };

    vector<ll> ans(q);
    function<void(int s, int f)> dfs2 = [&](int s, int f) {
        for(auto i : queries[s]) {
            ans[i[2]] = st.get(i[0], i[1] + 1);
        }
        for(auto u : g[s]) if(u.first != f) {
            st.update(u.second, 0, n);
            st.update(-2*u.second, inter[u.first].first, inter[u.first].second + 1);
            dfs2(u.first, s);
            st.update(2*u.second, inter[u.first].first, inter[u.first].second + 1);
            st.update(-u.second, 0, n);
        }
    };

    dfs1(0, -1, 0);
    st.updall();
    
    int l, r;
    forn(i, q) {
        cin >> x >> l >> r; x--; l--; r--;
        queries[x].push_back({l, r, i});
    }

    dfs2(0, -1);

    for(ll i : ans) cout << i << '\n';


    return 0;
}