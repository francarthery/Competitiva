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

const ll INF = 1e18;

struct BellmanFord {
    vector<vector<ii>> G;  // ady. list with pairs (weight, dst)
    vector<ll> dist;
    vector<int> ant, ruta;
    vector<bool> crec, vis;
    int N;
    BellmanFord(int n) : G(n), N(n), crec(n), vis(n) {}
    void addEdge(int a, int b, ll w) { G[a].pb({w, b}); }
    void run(int src) {  // O(VE)
        dist = vector<ll>(N, INF);
        dist[src] = 0;
        forn(i, N - 1) forn(j, N) 
                //if (dist[j] != INF) 
                    forall(it, G[j])
                        dist[it->snd] = min(dist[it->snd], dist[j] + it->fst);
    }

    vector<int> hasNegCycle() {
        ant = vector<int>(N, -1);
        forn(i, N) forn(j, N) 
                forall(it, G[j])
                if(dist[it->snd] > dist[j] + it->fst){ //Si hay un bucle despues de N - 1 rondas sigue creciendo
                    crec[j] = true;
                    dist[it -> snd] = dist[j] + it -> fst; 
                    ant[it -> snd] = j; //guardo los predecesores de los nodos
                }
        
        forn(i, N) if(crec[i]) {
            ruta.pb(i);
            dfs(i);
            forn(i, sz(ruta)) if(ruta[i] == ruta.back()){
                ruta.erase(ruta.begin(), ruta.begin() + i);
                break;
            }
            if(sz(ruta)) break;
        }
        return ruta;
    }

    void dfs(int s){ //Expando desde 1 en el grafo normal
        if(s == -1 or vis[s]) return;
        vis[s] = true;
        ruta.pb(ant[s]);
        dfs(ant[s]);
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
    vector<int> rta;
    forn(i, m){
        cin >> a >> b >> c;
        a--; b--;
        bf.addEdge(a, b, c);
    }
    bf.run(0);
    rta = bf.hasNegCycle();
    if(rta.empty()) cout << "NO\n";
    else{
        cout << "YES\n";
        reverse(all(rta));
        for(int &i : rta) cout << i + 1 << ' ';
        cout << '\n';
    }
    
    return 0;
}