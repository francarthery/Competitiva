#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<int>> g, grev;
vector<int> grado, gr;
vector<bool> vis;
int tot = 0;

void dfs(int s){ //Root = true si vengo de la raiz
    if(vis[s]) return;
    vis[s] = true;
    tot++;
    for(int &u : g[s]){
        gr[u]++;
        if(gr[u] == grado[u]) dfs(u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, x, y;
    cin >> n >> m;
    g.resize(n);
    grev.resize(n);
    grado.assign(n, 1);
    gr.resize(n);
    vis.resize(n);

    forn(i, m){
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        grev[y].pb(x);
        grado[y]++;
    }

    forn(i, n){
        cin >> x;
        x--;
        gr[x]++;
        bool pad = true;
        for(int &u : grev[x]) pad &= vis[u]; //Si los padres ya estan enchufados
        if(pad) dfs(x);
        
        cout << tot << '\n';
    }
    
    return 0;
}