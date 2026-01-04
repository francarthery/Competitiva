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

struct Edge {
  int u, v;
  ll cap, flow;
  Edge() {}
  Edge(int uu, int vv, ll c) : u(uu), v(vv), cap(c), flow(0) {}
};
struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  Dinic(int n) : N(n), g(n), d(n), pt(n) {}  // clear and init
  void addEdge(int u, int v, ll cap) {
    if (u != v) {
      g[u].pb(sz(E));
      E.pb({u, v, cap}); //Las aristas originales van a posiciones pares.
      g[v].pb(sz(E));
      E.pb({v, u, 0});
    }
  }
  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == T) break;
      for (int k : g[u]) {
        Edge& e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.push(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
  ll DFS(int u, int T, ll flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int& i = pt[u]; i < sz(g[u]); ++i) {
      Edge& e = E[g[u][i]];
      Edge& oe = E[g[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        ll amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (ll pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  ll maxFlow(int S, int T) {  // O(V^2*E), unit nets: O(sqrt(V)*E)
    ll total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (ll flow = DFS(S, T)) total += flow;
    }
    return total;
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
    vector<vector<string>> v(n, vector<string>(m));
    map<string, int> inds;
    vector<int> frec(2 * m);
    vector<set<int>> cands(2 * m);
    int cont = 0;
    forn(i, n) forn(j, m) {
        cin >> v[i][j];
        if(!inds.count(v[i][j])) {
            if(cont == 2 * m) {
                cout << "N\n";
                return 0;
            }
            inds[v[i][j]] = cont++;
        }
        frec[inds[v[i][j]]]++;
    }

    forn(i, 2*m) forn(j, 2*m) if(i != j) cands[i].insert(j);

    for(auto i : inds){
        string name = i.fr;
        forn(j, n) {
            bool ok = true;
            forn(k, m) if(v[j][k] == name) ok = false;
            if(!ok) forn(k, m) if(cands[i.sc].count(inds[v[j][k]])) cands[i.sc].erase(inds[v[j][k]]);
        }
    }

    Dinic dn(2*m + 2);
    set<int> primeros;
    forn(i, m) {
        int pos = inds[v[0][i]];
        primeros.insert(pos);
        for(auto j : cands[pos]) {
            if(frec[j] + frec[pos] == n) dn.addEdge(pos, j, 1);
        }
        dn.addEdge(2*m, pos, 1);
    }

    forn(i, cont) {
        if(!primeros.count(i)) dn.addEdge(i, 2*m + 1, 1);
    }
    
    int full = 0;
    for(auto j : frec) if(j == n) full++;

    cout << (dn.maxFlow(2*m, 2*m + 1) + full == m ? "S" : "N") << '\n';   


    return 0;
}