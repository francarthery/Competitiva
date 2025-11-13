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
typedef pair<int, int> ii;

vector<int> g, vis;
vector<unordered_map<int, int>> bucles;
vector<vector<int>> gt, sp;
vector<ii> info; //(dist a bucle, numero camino, por que elemento entro al bucle)
int val = -1, comp = 1, cont = 2; 

void dfs(int s, int &col){
    if(vis[s] == col) {
        val = s;
        return;
    }
    vis[s] = col;
    dfs(g[s], col); 
}

void dfs2(int s, int d, int elem){
    for(auto &u : gt[s]){ //Al estar invertido puede haber mas de un hijo
        if(u == val) continue;
        else if(vis[s] == -2 and vis[u] != -2) {
            info[u] = {1, s};
            dfs2(u, 1, s);
        }
        else if(vis[s] != -2 and vis[u] != -2) {
            info[u] = {d + 1, elem};
            dfs2(u, d + 1, elem);
        }
        else {
            bucles[comp - 1][u] = cont++; //guardo bucle 
            dfs2(u, 0, 0);
        }
    }
    vis[s] = comp;
}

int avanzar(int x, int d){
    int pot = 20;
    while(d > 0){
        while((1 << pot) > d) pot--;
        x = sp[pot][x];
        d -= (1 << pot);
    }

    return x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, q, x, a, b, k = 20;
    cin >> n >> q;
    g.resize(n);
    gt.resize(n);
    vis.resize(n);
    info.resize(n);
    sp.assign(k, vector<int>(n));

    forn(i, n) {
        cin >> x; x--;
        g[i] = x;
        gt[x].pb(i);
        sp[0][i] = x;
    }

    forn(i, n){
        if(vis[i] == 0) {
            val = -1;
            int col = -1;
            dfs(i, col); //Busco bucle
            col = -2;
            dfs(val, col); //pinto solo bucle
            
            unordered_map<int, int> aux;
            aux[val] = 1;
            bucles.pb(aux); //Meto un map vacio para guardar el bucle
            cont = 2;
            dfs2(val, 0, 0);
            vis[val] = comp;
            comp++;
        }
    }

    forr(i, 1, k){ //Precalculo avanzar k en el grafo
        for(int j = 0; j < n; j++){
            sp[i][j] = sp[i - 1][sp[i - 1][j]];
        }
    }

    forn(i, q){
        cin >> a >> b; a--; b--;
        int ans;
        if(vis[a] != vis[b]) ans = -1;
        else{
            if(!info[a].fr and info[b].fr) ans = -1; //de bucle a path.
            else if(!info[a].fr and !info[b].fr){ //de bucle a bucle
                if(bucles[vis[a] - 1][a] >= bucles[vis[b] - 1][b]) ans = bucles[vis[a] - 1][a] - bucles[vis[b] - 1][b];
                else ans = bucles[vis[a] - 1][a] + sz(bucles[vis[a] - 1]) - bucles[vis[b] - 1][b];
            }
            else if(info[a].fr and info[b].fr){ //de path a path
                if(avanzar(a, max(0, info[a].fr - info[b].fr)) != b) ans = -1; 
                else ans = info[a].fr - info[b].fr;
            }
            else { //de path a bucle
                ans = info[a].fr;
                a = info[a].sc;

                if(bucles[vis[a] - 1][a] >= bucles[vis[b] - 1][b]) ans += bucles[vis[a] - 1][a] - bucles[vis[b] - 1][b];
                else ans += bucles[vis[a] - 1][a] + sz(bucles[vis[a] - 1]) - bucles[vis[b] - 1][b];
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}