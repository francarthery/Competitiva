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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n"};
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<int>> g;
vector<int> vis;

int cont = 0;
void dfs(int s, int evil, int col){ //evito pasar por evil.
    if(vis[s] == col) return;
    vis[s] = col;  
    cont++;
    for(int &u : g[s]) if(u != evil) dfs(u, evil, col);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int a, b, n, m, num = 0;
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    bool solo = false;
    forn(i, n){
        if(!vis[i]) { //me fijo que no tenga mas de una componente
            dfs(i, -1, ++num);
            if(!sz(g[i])) solo = true;
        }
    }
    if(!(num == 1 or num == 2 and solo)) { //si tiene una componente o tiene 2 y una de grado 0 estamos bien
        cout << "no\n";
        return 0;
    }

    unordered_map<int, int> ma;
    forn(i, n) ma[sz(g[i])]++;
    
    forn(i, n){
        ma[sz(g[i])]--;
        for(int &u : g[i]){
            ma[sz(g[u])]--;
            ma[sz(g[u]) - 1]++;
        }

        bool dif = 0;
        forall(it, ma) if(it -> fr != 1 and it -> fr != 2 and it -> sc) dif = true;
            
        if(ma[1] == 2 and !dif){
            cont = 0;
            num++;
            if(i == 0) dfs(1, i, num); //me fijo si sacando el nodo i sigue siendo una sola componente (i no es punto de art.)
            else dfs(0, i, num);
            if(cont == n - 1){
                cout << "yes\n";
                return 0;
            }
        }

        for(int &u : g[i]){
            ma[sz(g[u])]++;
            ma[sz(g[u]) - 1]--;
        }
        ma[sz(g[i])]++;

    }

    cout << "no\n";

    return 0;
}