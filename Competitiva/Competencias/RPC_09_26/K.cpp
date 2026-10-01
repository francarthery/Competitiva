#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define forall(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto  e : x) cout<<e<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF = 1e18;
struct Dijkstra{
    vector<vector<array<ll,4>>> G;
    vector<ll> dist;
    vector<array<ll, 4>> vp;
    int N;
    Dijkstra(int n) : G(n), N(n) {}
    void addEdge(int a, int b, ll w) {{
        int ta = sz(G[a]);
        int tb = sz(G[b]);
        G[a].push_back(array<ll, 4>{w, b, ta, tb});
        G[b].push_back(array<ll, 4>{w, a, tb, ta});
    }}
    void run(int src) {
        dist = vector<ll>(N, INF);
        vp = vector<array<ll, 4>>(N, array<ll, 4>{-1, -1, -1, -1});
        priority_queue<ii, vector<ii>, greater<ii>> Q;
        Q.push({0, src}), dist[src] = 0;
        while(sz(Q)) {
            int node = Q.top().second;
            ll d = Q.top().first;
            Q.pop();
            if(d > dist[node]) continue;

            for(auto [w, b, ia, ib] : G[node]) if(d + w < dist[b]) {
                dist[b] = d + w;
                vp[b] = {w, node, ib, ia}; //indice el, indice padre
                Q.push({dist[b], b});
            }
            // forall(it, G[node]) if(d + it->first < dist[it -> second]) {
            //     dist[it->second] = d + it->first;
            //     vp[it->second] = {it->first, node};
            //     Q.push({dist[it->second], it->second});
            // }
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int n, m, k, a, b; cin >> n >> m >> k >> a >> b; a--; b--;
    Dijkstra dj(n);
    forn(i, m) {
        int v, u, w; cin >> v >> u >> w; v--; u--;
        dj.addEdge(v, u, w);
    }

    forn(i, k-1) {
        dj.run(a);
        int node = b;
        while(node != -1) {
            auto [w, fat, iu, is] = dj.vp[node];
            if(fat != -1) dj.G[node][iu][0] = INF;
            if(fat != -1) dj.G[fat][is][0] = INF;
            node = fat;
        }
    }

    dj.run(a);
    vector<int> ans;
    int node = b;
    while(node != -1) {
        ans.push_back(node);
        auto [w, fat, iu, is] = dj.vp[node];
        node = fat;
    }

    cout << dj.dist[b] << '\n';
    dfor(i, sz(ans)) {
        cout << ans[i] + 1 << (i == 0 ? "\n" : " - ");
    }
    

    return 0;
}