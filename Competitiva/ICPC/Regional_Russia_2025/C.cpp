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

int n;
vector<vector<int>> g2;
vector<bool> visited; //Controla los nodos que fueron visitados
vector<int> tin, low, ma; //Contienen el tiempo de visita y el nodo mas bajo al que llegamos con un backedge
vector<bool> art1, art2;
int timer;

void dfs(int v, int p = -1){ //p indica el padre de v. En el caso de la raiz es -1 (no hay)
    visited[v] = true;
    tin[v] = low[v] = timer++;
    ma[v] = v;
    int children = 0;

    for(int to : g2[v]){
        if(to == p) continue; //Que el hijo vuelva al padre es redundante
        if(visited[to]){ //Si el hijo ya fue visitado nos fijamos que si tiene un backedge menor al de v 
            low[v] = min(low[v], tin[to]);
            ma[v] = max(ma[v], ma[to]);
        }
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]); //Nos fijamos si alguna de las ramas tiene un backedge menor al de v
            ma[v] = max(ma[v], ma[to]);
            if(low[to] >= tin[v] and ma[to] == n-1 and p != -1){ //Si el menor backedge es mayor o igual al descubrimiento de v, v es un ap
                art1[v] = true;
            }
            ++children;
        }
    }

    if(p == -1 and children > 1) //Si v es la raiz y tiene dos hijos, v es un ap
        art1[v] = true;
}

void find_cutpoints(){
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    ma.resize(n);
    art1.resize(n);
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i); //Hacemos el recorrido en todas las componentes conexas del grafo
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int m; cin >> n >> m;
    vector<string> v(n);
    forn(i, n) cin >> v[i];
    vector<vector<int>> g(n*m);
    vector<ii> ar; 

    forn(i, n) forn(j, m) {
        if(v[i][j] == 'X') continue;
        if(i>0 and v[i-1][j]=='.'){
            g[i*m+j].pb((i-1)*m+j);
            ar.pb({i*m+j, (i-1)*m+j});
        }
        if(i<n-1 and v[i+1][j]=='.') {
            g[i*m+j].pb((i+1)*m+j);
            ar.pb({i*m+j, (i+1)*m+j});
        }
        if(j>0 and v[i][j-1]=='.') {
            g[i*m+j].pb(i*m+j-1);
            ar.pb({i*m+j, i*m+j-1});
        }
        if(j<m-1 and v[i][j+1]=='.') {
            g[i*m+j].pb(i*m+j+1);
            ar.pb({i*m+j, i*m+j+1});
        }
    }

    n = n*m;
    vector<int> dist1(n, 1e9), dist2(n, 1e9);
    auto bfs = [&](int s) {
        dist1[s] = 0;
        queue<int> q;
        q.push(s);

        while(sz(q)){
            int s = q.front();
            q.pop();

            for(int u : g[s]) {
                if(dist1[u] == 1e9){
                    q.push(u);
                    dist1[u] = dist1[s]+1;
                }
            }
        }
    };

    bfs(n-1);
    dist2.swap(dist1);
    bfs(0);

    g2.resize(n);
    for(auto &[s, u] : ar) {
        if(min(dist1[s] + dist2[u], dist1[u] + dist2[s]) + 1 == dist1[n-1]) { //Pertenece a camino minimo
            g2[u].pb(s);
        }
    }

    find_cutpoints();
    art2.swap(art1); //En art2 quedan los del grafo de caminos minimos
    g2.swap(g);
    find_cutpoints();

    forn(i, n) {
        if(art2[i] and !art1[i]) v[i/m][i%m] = '*';
    }

    for(auto i : v) cout << i << '\n';

    return 0;
}