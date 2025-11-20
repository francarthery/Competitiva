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
    void addEdge(int a, int b, ll w) { G[a].pb({w, b}); G[b].pb({w, a}); }
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

    int n, m, a, b, c, k;
    double prob, p = 1, res = 0;
    cin >> n >> m >> k;
    Dijkstra dj(n);
    vector<pair<double, int>> t(k);
    
    forn(i, m){
        cin >> a >> b >> c; a--; b--;
        dj.addEdge(a, b, c);
    }

    forn(i, k){
        cin >> a >> prob;
        t[i] = {prob, a - 1};
    }

    dj.run(0);
    vector<ll> dist0 = dj.dist;
    dj.run(n - 1);

    if(abs(max_element(all(t)) -> fr - 1) < 1e-9){
        vector<ii> v(k);
        forn(i, k) v[i] = {dist0[t[i].sc] + dj.dist[t[i].sc], i};
        sort(all(v)); //ordeno por menor distancia pasando por kioskito

        forn(i, k){
            res += p * t[v[i].sc].fr * v[i].fr;
            p *= (1 - t[v[i].sc].fr);
            if(abs(t[v[i].sc].fr - 1) <= 1e-9) break;
        }
        cout << fixed << setprecision(6) << res << '\n';
    }
    else cout << "impossible\n";
    
    return 0;
}