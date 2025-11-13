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
typedef pair<ll, int> ii;
const ll INF = 1e18;
int k;
vector<ll> ans;

struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
    vector<vector<ii>> G;  // ady. list with pairs (weight, dst)
    vector<ll> dist;
    vector<int> cant;

    int N;
    Dijkstra(int n) : G(n), N(n) {}
    void addEdge(int a, int b, ll w) { G[a].pb({w, b}); }
    void run(int src) {  // O(|E| log |V|)
        dist = vector<ll>(N, INF);
        cant = vector<int>(N);
        multiset<ii> Q;
        Q.insert({0, src}), dist[src] = 0;

        while (sz(Q)) {
            int node = (*Q.begin()).snd;
            ll d = (*Q.begin()).fst;
            Q.erase(Q.begin());
            if (cant[node] >= k) continue;
            cant[node]++;
            if(node == N - 1) ans.pb(d);
            forall(it, G[node]) {
                dist[it->snd] = d + it->fst;
                Q.insert({dist[it->snd], it->snd});
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

    int n, m, a, b, c;
    cin >> n >> m >> k;
 
    Dijkstra dj(n);
    forn(i, m){
        cin >> a >> b >> c; a--; b--;
        dj.addEdge(a, b, c);
    }

    dj.run(0);

    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    
    return 0;
}