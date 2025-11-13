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

const ll INF = 1e18;
struct EdmondsKarp {
  int N;
  vector<unordered_map<int, ll>> g;
  vector<int> p;
  ll f;
  EdmondsKarp(int n) : N(n), g(n), p(n) {}
  void addEdge(int a, int b, int w) { g[a][b] = w; }
  void augment(int v, int SRC, ll minE) {
    if (v == SRC) f = minE;
    else if (p[v] != -1) {
      augment(p[v], SRC, min(minE, g[p[v]][v]));
      g[p[v]][v] -= f, g[v][p[v]] += f;
    }
  }
  ll maxflow(int SRC, int SNK) {  // O(min(VE^2,Mf*E))
    ll ret = 0;
    do {
      queue<int> q;
      q.push(SRC);
      fill(p.begin(), p.end(), -1);
      f = 0;
      while (sz(q)) {
        int node = q.front();
        q.pop();
        if (node == SNK) break;
        forall(it, g[node]) if (it->sc > 0 && p[it->fr] == -1) {
          q.push(it->fr), p[it->fr] = node;
        }
      }
      augment(SNK, SRC, INF);  // INF > max possible flow
      ret += f;
    } while (f);
    return ret;
  }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;
    EdmondsKarp ek(n);
    vector<vector<int>> g(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        ek.addEdge(a, b, 1);
        ek.addEdge(b, a, 1);
        g[a].pb(b);
        g[b].pb(a);
    }
    ek.maxflow(0, n - 1);

    vector<bool> vis(n);
    function<void(int)> dfs = [&](int s){ //aristas alcanzables desde 0 (source)
        if(vis[s]) return;
        vis[s] = true;

        for(int &u : g[s]) if(ek.g[s][u] > 0) dfs(u);
    };

    dfs(0);
    vector<ii> rta;
    forn(i, n){ //las aristas que van de un nodo alcanzable a un no alcanzable saturadas (capacidad maxima (= 0)) son el min cut
        for(int &u : g[i]) if(vis[i] and !vis[u] and !ek.g[i][u]) rta.pb({i, u}); 
    }

    cout << sz(rta) << '\n';
    for(ii i : rta) cout << i.fr + 1 << ' ' << i.sc + 1 << '\n';


    return 0;
}