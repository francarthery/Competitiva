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
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
const ll INF = 1e18;

struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
  vector<vector<ii>> G;  // ady. list with pairs (weight, dst)
  vector<ll> dist;
  // vector<int> vp; // for path reconstruction (parent of each node)
  int N;
  Dijkstra(int n) : G(n), N(n) {}
  void addEdge(int a, int b, ll w) { G[a].pb({w, b}); }
  void run(int src) {  // O(|E| log |V|)
    dist = vector<ll>(N, INF);
    // vp = vector<int>(N, -1);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(make_pair(0, src)), dist[src] = 0;
    while (sz(Q)) {
      int node = Q.top().snd;
      ll d = Q.top().fst;
      Q.pop();
      if (d > dist[node]) continue;
      forall(it, G[node]) if (d + it->fst < dist[it->snd]) {
        dist[it->snd] = d + it->fst;
        // vp[it->snd] = node;
        Q.push({dist[it->snd], it->snd});
      }
    }
  }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, p, g, a, b, w;
    cin >> n >> m >> p >> g;
    Dijkstra dj1(n), dj2(n);
    p--; g--;

    forn(i, m){
        cin >> a >> b >> w;
        a--; b--;
        dj1.addEdge(a, b, w);
        dj1.addEdge(b, a, w);
        if(a != g and b != g){ //Cargo grafo sin destino
            dj2.addEdge(a, b, w);
            dj2.addEdge(b, a, w);
        }
    }

    dj1.run(g); dj2.run(p);
    //vdbg(dj1.dist); vdbg(dj2.dist);
    vector<ll> rta;
    forn(i, n){
        if(i != p and i != g and dj1.dist[p] == dj1.dist[i] and dj1.dist[p] + dj1.dist[i] < dj2.dist[i]) rta.pb(i + 1);
    }

    if(sz(rta)) forn(i, sz(rta)) cout << rta[i] << ' ';
    else cout << '*';
    cout << '\n';
    
    return 0;
}