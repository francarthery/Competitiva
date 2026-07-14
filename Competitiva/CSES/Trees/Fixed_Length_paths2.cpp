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

typedef ll tipo;
struct FenwickTree {
  int N;            // maybe replace vector with unordered_map when "many 0s"
  vector<tipo> ft;  // for more dimensions, make ft multi-dimensional
  FenwickTree(int n) : N(n), ft(n + 1) {}
  void upd(int i0, tipo v) {  // add v to i0th element (0-based)
    // add extra fors for more dimensions
    for (int i = i0 + 1; i <= N; i += i & -i) ft[i] += v;
  }
  tipo get(int i0) {  // get sum of range [0,i0)
    tipo r = 0;       // add extra fors for more dimensions
    for (int i = i0; i; i -= i & -i) r += ft[i];
    return r;
  }
  tipo get_sum(int i0, int i1) {  // get sum of range [i0,i1) (0-based)
    return get(i1) - get(i0);
  }
};


ll ans = 0, k1, k2;

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
        FenwickTree dtot(szcomp);
        for(int u : g[s]) if(!vis[u]) { //Lo mismo que la V1 pero a la hora de mirar los nodos ya procesados en lugar
            vector<int> d2;             //de usar un array normal, usamos un FT para consultar por todo el rango 
            dists(u, s, 1, d2);         //de distancias validas

            for(int i : d2) {
                int l = max(0ll, k1 - i);
                int r = min((ll)szcomp-1, k2 - i);
                if(l < szcomp and r > 0) ans += dtot.get_sum(l, r+1);
            }
            for(int i : d2) dtot.upd(i, 1);            
        }
        int l = max(0ll, k1);
        int r = min((ll)szcomp-1, k2);
        if(l < szcomp and r > 0) ans += dtot.get_sum(l, r+1);

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

    int a, b, n; cin >> n >> k1 >> k2;
    Centroid cn(n);
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        cn.addEdge(a, b);
    }

    cn.run(0);
    cout << ans << '\n';

    return 0;
}