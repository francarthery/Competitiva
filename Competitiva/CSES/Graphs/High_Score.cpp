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
typedef pair<int, int> ii;
const ll INF = -1e18;

struct BellmanFord {
    vector<vector<ii>> G, gt;  // ady. list with pairs (weight, dst)
    vector<ll> dist;
    vector<bool> crec, ini, fin;
    int N;
    BellmanFord(int n) : G(n), gt(n), N(n), crec(n), ini(n), fin(n) {}
    void addEdge(int a, int b, ll w) { G[a].pb({w, b}); gt[b].pb({w, a}); }
    void run(int src) {  // O(VE)
        dist = vector<ll>(N, INF);
        dist[src] = 0;
        forn(i, N - 1) forn(j, N) if (dist[j] != INF) forall(it, G[j])
            dist[it->snd] = max(dist[it->snd], dist[j] + it->fst);
    }

    bool hasNegCycle() {
        forn(i, N) forn(j, N) if (dist[j] != INF) forall(it, G[j])
            if(dist[it->snd] < dist[j] + it->fst){ //Si hay un bucle despues de N - 1 rondas sigue creciendo
                crec[j] = true;
                dist[it -> snd] = dist[j] + it -> fst; 
            }
        
        dfs2(N - 1);
        forn(i, N) if(fin[i] and crec[i]) return true;
        return false;
    }

    void dfs2(int s){ //Expando desde N en el grafo invertido
        if(fin[s]) return;
        fin[s] = true;
        for(auto &u : gt[s]) dfs2(u.snd);
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
    cin >> n >> m;
    BellmanFord bf(n);
    forn(i, m){
        cin >> a >> b >> c;
        a--; b--;
        bf.addEdge(a, b, c);
    }
    bf.run(0);
    //vdbg(bf.dist);
    if(bf.hasNegCycle()) cout << "-1\n";
    else cout << bf.dist[n - 1] << '\n';    
    

    return 0;
}