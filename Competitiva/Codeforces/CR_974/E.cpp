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
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

const ll INF = 1e18;

struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
    vector<vector<ii>> G;  // ady. list with pairs (weight, dst)
    vector<ll> dist;
    // vector<int> vp; // for path reconstruction (parent of each node)
    int N;
    Dijkstra(int n) : G(n), N(n) {}
    void addEdge(int a, int b, ll w) { G[a].pb({w, b}); G[b].pb({w, a});}
    void run(int src) {  // O(|E| log |V|)
        dist = vector<ll>(N, INF);
        // vp = vector<int>(N, -1);
        priority_queue<ii, vector<ii>, greater<ii>> Q;
        Q.push({0, src}), dist[src] = 0;
        while (sz(Q)) {
            auto [d, node] = Q.top();
            Q.pop();
            if (d > dist[node]) continue;
            forall(it, G[node]) if(d + it->fr < dist[it->sc]) {
                dist[it->sc] = d + it->fr;
                // vp[it->snd] = node;
                Q.push({dist[it->sc], it->sc});
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

    int n, m, h, t, a, b, w;
    cin >> t;
    while(t--){
        cin >> n >> m >> h;
        ll mi = LLONG_MAX;
        Dijkstra dj(2 * n);
        forn(i, h){
            cin >> a; a--;
            dj.addEdge(a, a + n, 0);
        }
        forn(i, m){
            cin >> a >> b >> w;
            a--; b--;
            dj.addEdge(a, b, w);
            dj.addEdge(a + n, b + n, w / 2);
        }

        dj.run(0);
        vector<ll> dist1 = dj.dist;
        dj.run(n - 1);

        forn(i, n) mi = min(mi, max(min(dist1[i], dist1[i + n]), min(dj.dist[i], dj.dist[i + n])));
        cout << (mi == INF ? -1 : mi) << '\n';
    }

    
    return 0;
}