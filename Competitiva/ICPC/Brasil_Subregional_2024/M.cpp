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

const ll INF = 1e15;

struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
    vector<vector<ll>> G;  // ady. list with pairs (weight, dst)
    vector<ll> dist;
    // vector<int> vp; // for path reconstruction (parent of each node)
    int N;
    Dijkstra(int n) : N(n) {
        G.assign(n, vector<ll>(n));
    }
    void addEdge(int a, int b, ll w) { G[a][b] = G[b][a] = w; }
    void run(int src) {  // O(|E| log |V|)
        dist = vector<ll>(N, INF);
        // vp = vector<int>(N, -1);
        priority_queue<ii, vector<ii>, greater<ii>> Q;
        Q.push({0, src}), dist[src] = 0;
        while (sz(Q)) {
            auto [d, node] = Q.top();
            Q.pop();
            if (d > dist[node]) continue;
            forn(i, G[node].size()) 
                if(G[node][i] != 0 and d + G[node][i] < dist[i]) {
                    dist[i] = d + G[node][i];
                    Q.push({dist[i], i});
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

    int n, c; cin >> n;
    Dijkstra dj(n);
    
    forn(i, n) forn(j, n){
        cin >> c;
        dj.addEdge(i, j, c);
    }

    bool flag = true;
    int num = 0, rta = 0;
    forn(i, n) forr(j, i + 1, n){ // que vaya por el triangulo de arriba
        num = dj.G[i][j];
        dj.G[i][j] = INF; //descartamos arista
        dj.run(i);
        
        if(dj.dist[j] < num) flag = false;
        else if(dj.dist[j] == num) rta++; // la ruta alternativa tiene el mismo precio
        
        dj.G[i][j] = num; //La vuelvo a poner
    }

    if(!flag) rta = -1;
    cout << rta << '\n';


    return 0;
}
