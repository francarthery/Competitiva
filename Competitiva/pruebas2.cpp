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

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<vector<ll>> g(n), dp(n, vector<ll>(2)); //0 es barato
        int x, y;
        forn(i, n - 1){
            cin >> x >> y; x--; y--;
            g[x].pb(y);
            g[y].pb(x);
        }

        vector<int> cols(k);
        int c0 = 2e9, c1 = 0, a = 0, b = 0;
        forn(i, k) {
            cin >> cols[i];
            c0 = min(c0, cols[i]);
            c1 = max(c1, cols[i]);
        }
        forn(i, k) {
            if(cols[i] == c0) a++;
            else b++;
        }

        auto fn = [&](vector<tuple<ll, int, int>> &elems, int a2, int b2) {
            ll sum = 0;
            set<int> hijo;
            for(auto &[val, b, c] : elems) {
                if(hijo.count(b)) continue;
                if((c == 0 and a2) or (c and b2)) {
                    hijo.insert(b);
                    sum += dp[b][c];
                    if(c == 0) a2--;
                    else b2--;
                }
            }
            return sum;
        };

        function<void(int, int)> dfs = [&](int s, int f) {
            vector<tuple<ll, int, int>> elems;
            for(int u : g[s]) {
                if(u == f) continue; 
                dfs(u, s);
                elems.pb({dp[u][0] - dp[u][1], u, 1});
                elems.pb({dp[u][1] - dp[u][0], u, 0});
            }
            sort(rall(elems));

            dp[s][0] = fn(elems, a - 1, b) + c0;
            dp[s][1] = fn(elems, a, b - 1) + c1;
        };
        
        dfs(0, -1);
        cout << min(dp[0][0], dp[0][1]) << '\n';
    }



    return 0;
}