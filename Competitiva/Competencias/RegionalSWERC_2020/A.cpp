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
typedef tuple<int, int, int> iii;

const ll INF = 1e9;
int B, car, T, n;
vector<vector<int>> g;

struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
    vector<vector<int>> G;  // ady. list with pairs (weight, dst)
    vector<int> dist;
    vector<int> vp; // for path reconstruction (parent of each node)

    int N;
    Dijkstra(int n) : G(n, vector<int>(n, INF)), N(n) {}
    void addEdge(int a, int b, int w) { 
        G[a][b] = min(G[a][b], w);
        G[b][a] = min(G[b][a], w);
     }
    void run(int src) {  // O(|E| log |V|)
        dist = vector<int>(N, INF);
        vp = vector<int>(N, -1);


        priority_queue<iii, vector<iii>, greater<iii>> Q;
        Q.push({0, 0, src}), dist[src] = 0;
        while (sz(Q)) {
            auto [d, dreal, node] = Q.top();
            Q.pop();
            if (d > dist[node]) continue;
            forn(i, N) if(G[node][i] != INF and dreal + g[node][i] <= B and d + G[node][i] < dist[i]) {
                dist[i] = d + G[node][i];
                vp[i] = node;

                Q.push({dist[i], dreal + g[node][i], i});
            }   
        }
    }
};

void rec(vector<int> vp){
    int nodo = n + 1;
    while(nodo != n){
        cout << nodo << ' ';
        nodo = vp[nodo];
    }
    cout << n << '\n';
}

int dist(ii &a, ii &b){
    return ceil(sqrt((a.fr - b.fr) * (a.fr - b.fr) + (a.sc - b.sc) * (a.sc - b.sc)));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ii orig, dest;
    cin >> orig.fr >> orig.sc;
    cin >> dest.fr >> dest.sc;
    cin >> B >> car >> T;
    vector<int> trans(T);
    forn(i, T) cin >> trans[i];
    cin >> n;
    vector<ii> nodos(n + 2);
    g.assign(n + 2, vector<int>(n + 2));
    Dijkstra dj(n + 2);
    nodos[n] = orig; nodos[n + 1] = dest;


    vector<vector<ii>> ady(n);
    forn(i, n){
        cin >> nodos[i].fr >> nodos[i].sc;
        int l; cin >> l;
        forn(j, l){
            int e, m; cin >> e >> m;
            ady[i].pb({e, m});
        }
    }

    forn(i, n){
        forn(j, sz(ady[i])){
            int distancia = dist(nodos[i], nodos[ady[i][j].fr]);
            dj.addEdge(i, ady[i][j].fr, distancia * trans[ady[i][j].sc - 1]);
            g[i][ady[i][j].fr] = g[ady[i][j].fr][i] = distancia;
        }
    }

    forn(i, n){
        int dist1 = dist(nodos[n], nodos[i]);
        int dist2 = dist(nodos[n + 1], nodos[i]);
        dj.addEdge(i, n, dist1 * car);
        dj.addEdge(i, n + 1, dist2 * car);
        g[i][n] = g[n][i] = dist1;
        g[i][n + 1] = g[n + 1][i] = dist2;
    }
    dj.addEdge(n, n + 1, dist(nodos[n], nodos[n + 1]) * car);
    g[n][n + 1] = g[n + 1][n] = dist(nodos[n], nodos[n + 1]);

    dj.run(n);
    rec(dj.vp); // BORRAR

    forn(i, n + 2) vdbg(dj.G[i]);
    vdbg(dj.dist);
    
    cout << (dj.dist[n + 1] == INF ? -1 : dj.dist[n + 1]) << '\n';

    return 0;
}