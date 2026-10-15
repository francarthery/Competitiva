#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "<<;for(auto e : x) cout<<e<<" ";cout<<endl;}

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef array<int, 3> iii;

const ll INF = 1e18;
struct Dijkstra {
    vector<vector<ii>> G;
    vector<ll> dist;
    int N;
    Dijkstra(int n) : G(n), N(n) {}
    void addEdge(int a, int b, ll w) { G[a].push_back({w, b});}
    void run(int src) {
        dist = vector<ll>(N, INF);
        priority_queue<ii, vector<ii>, greater<ii>> Q;
        Q.push({0, src}), dist[src] = 0;
        while(sz(Q)){
            int node = Q.top().second;
            ll d = Q.top().first;
            Q.pop();
            if(d > dist[node]) continue;
            for(auto &[w, b] : G[node]) if(d+w < dist[b]) {
                dist[b] = d + w;
                Q.push({dist[b], b});
            }
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> cols(m);
    vector<vector<iii>> g(n);
    int a, b, c;
    forn(i, m) {
        cin >> a >> b >> c; a--; b--;
        g[a].push_back({c, b, i});
        int l; cin >> l;
        cols[i].resize(l);
        forn(j, l) cin >> cols[i][j];
    }

    Dijkstra dj(n);
    forn(i, n) {
        map<int, int> color;
        for(iii u : g[i]) {
            for(int c : cols[u[2]]) color[c] = max(color[c], u[0]);
        }
        for(iii u : g[i]) {
            for(int c : cols[u[2]]) if(color[c] == u[0]) dj.addEdge(u[1], i, u[0]);
        }
    }

    dj.run(n-1);
    if(dj.dist[0] != INF) cout << dj.dist[0] << '\n';
    else cout << "impossible\n";

    return 0;
}