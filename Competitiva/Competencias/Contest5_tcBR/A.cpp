#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;
int INF = 1e9;

struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
  vector<vector<ii>> G;  // ady. list with pairs (weight, dst)
  vector<ll> dist;
  // vector<int> vp; // for path reconstruction (parent of each node)
  int N;
  Dijkstra(int n) : G(n), N(n) {}
  void addEdge(int a, int b, ll w) { 
    G[a].pb({w, b});
    G[b].pb({w, a});
   }
  void run(int src) {  // O(|E| log |V|)
    dist = vector<ll>(N, INF);
    // vp = vector<int>(N, -1);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(make_pair(0, src)), dist[src] = 0;
    while (sz(Q)) {
      int node = Q.top().sc;
      ll d = Q.top().fr;
      Q.pop();
      if (d > dist[node]) continue;
      forall(it, G[node]) if (d + it->fr < dist[it->sc]) {
        dist[it->sc] = d + it->fr;
        // vp[it->snd] = node;
        Q.push(make_pair(dist[it->sc], it->sc));
      }
    }
  }
};

typedef ll tipo;
const tipo neutro = 1e18;
tipo oper(const tipo& a, const tipo& b) { return min(a, b); }
struct ST {
    int sz;
    vector<tipo> t;
    ST(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo>(2 * sz, neutro);
    }
    tipo& operator[](int p) { return t[sz + p]; }
    void updall() { dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
    tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
    tipo get(int i, int j, int n, int a, int b) {  // O(log n), [i, j)
        if (j <= a || b <= i) return neutro;
        if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
        int c = (a + b) / 2;
        return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }
    void set(int p, tipo val) {  // O(log n)
        p += sz;
        while (p > 0 && t[p] != val) {
            t[p] = val;
            p /= 2;
            val = oper(t[p * 2], t[p * 2 + 1]);
        }
    }
};  // Use: definir oper tipo neutro,
// cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    Dijkstra dj(n);
    
    forn(i, m){
        int a, b, g; cin >> a >> b >> g;
        dj.addEdge(a, b, g);
    }

    vector<array<ll, 3>> v(n);
    forn(i, 3) {
        dj.run(i);
        forn(j, n) v[j][i] = dj.dist[j];
    }

    vector<bool> malo(n);

    map<int, vector<array<ll, 3>>> mp;
    forn(i, n) mp[v[i][0]].pb({v[i][1], v[i][2], i});
    vector<int> ind(n);
    forn(i, n) ind[i] = v[i][1];
    sort(all(ind));

    ST st(n);

    for(auto i : mp) {
        for(auto j : i.sc) {
            int pos = lower_bound(all(ind), j[0]) - ind.begin();
            if(st.get(0, pos + 1) <= j[1]) malo[j[2]] = true;
        }
        for(auto j : i.sc) {
            int pos = lower_bound(all(ind), j[0]) - ind.begin();
            st.set(pos, min(st[pos], j[1]));
        }
        for(auto j : i.sc) {
            int pos = lower_bound(all(ind), j[0]) - ind.begin();
            if(st.get(0, pos + 1) < j[1] or st.get(0, pos) <= j[1]) malo[j[2]] = true;
        }
    }

    int res = 0;
    forn(i, n) if(malo[i] == 0) res++;
    cout << res << '\n';
    
    
    return 0;
}