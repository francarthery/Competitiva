#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" ";cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef tuple<ll, ll, ll> iii;
const ll INF = 1e15;

struct Dijkstra {
    vector<vector<iii>> G;
    vector<vector<ll>> dist;
    int N, K;
    Dijkstra(int n, int k) : G(n), N(n), K(k) {}
    void addEdge(int a, int b, ll f, ll w) {G[a].push_back({f, w, b}); G[b].push_back({f, w, a});}
    void run(int src) {
        dist.assign(N, vector<ll>(K+1, INF));
        priority_queue<iii, vector<iii>, greater<iii>> Q;
        Q.push({0, 0, src}), dist[0][0] = 0;
        while(sz(Q)) {
            auto [d, use, node] = Q.top();
            Q.pop();
            if(d > dist[node][use]) continue;
            for(auto [f, w, dest] : G[node]) {
                if(d + f < dist[dest][use]) {
                    dist[dest][use] = d+f;
                    Q.push({dist[dest][use], use, dest});
                }
                if(use < K and w != -1 and d+w < dist[dest][use+1]) {
                    dist[dest][use+1] = d+w;
                    Q.push({dist[dest][use+1], use+1, dest});
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, m, k; cin >> n >> m >> k;
    Dijkstra dj(n, k);
    ll a, b, f, w;
    forn(i, m) {
        cin >> a >> b >> f >> w; a--; b--;
        dj.addEdge(a, b, f, w);
    }

    dj.run(0);
    // forn(i, n) vdbg(dj.dist[i]);
    ll mi = INF;
    forn(i, k+1) mi = min(mi, dj.dist[n-1][i]);

    cout << mi << '\n';
    

    return 0;
}