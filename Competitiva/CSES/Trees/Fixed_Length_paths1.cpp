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

ll ans = 0, k;

struct Centroid {
    int n;
    vector<vector<int>> g;
    vector<int> tam;
    vector<bool> vis;

    Centroid(int N) : n(N) {
        g.resize(N);
        tam.resize(n);
        vis.resize(n);
    }

    void addEdge(int a, int b) {g[a].pb(b), g[b].pb(a);}
    
    void dfs(int s, int f) {
        tam[s] = 1;
        for(int u : g[s]) if(u != f and !vis[u]) {
            dfs(u, s);
            tam[s] += tam[u];
        }
    }

    void dists(int s, int f, int d, vector<int> &d2) {
        d2.push_back(d);
        for(int u : g[s]) if(!vis[u] and u != f) dists(u, s, d+1, d2);
    }

    void centroide(int s, int szcomp) {
        if(szcomp == -1) { //Entre por primera vez, necesito tam de subarboles
            dfs(s, -1);
            szcomp = tam[s];
        }
        tam[s] = 0; //Con esto me evito llevar el padre
        for(int u : g[s]) if(!vis[u] and tam[u] > szcomp / 2) { //Si el nodo no tiene hijos con mas de floor(n/2) nodos, es el centroide
            centroide(u, szcomp);
            return;
        }
        vis[s] = true; //Marco el centroide
        
        //Parte tuneable
        vector<int> dtot(szcomp); //Basicamente llevamos una frecuencia de las distancias de los nodos ya visitados
        for(int u : g[s]) if(!vis[u]) { //Cada vez que visitamos una nueva rama desde el centroide actual
            vector<int> d2;             //Miramos que caminos podriamos formar con los nodos ya procesados.
            dists(u, s, 1, d2);

            for(int i : d2) if(i < k and k - i < szcomp) ans += dtot[k - i];
            for(int i : d2) dtot[i]++;            
        }
        if(szcomp > k) ans += dtot[k];

        for(int u : g[s]) if(!vis[u]) { centroide(u, -1); }
    }

    void run(int root) { centroide(root, -1); }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int a, b, n; cin >> n >> k;
    Centroid cn(n);
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        cn.addEdge(a, b);
    }

    cn.run(0);
    cout << ans << '\n';

    return 0;
}