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

int n, m, k, max_comp = 0, comp, tot_comp = 0, totar = 0;
vector<vector<int>> g;
vector<bool> vis;

void dfs(int s){
    if(vis[s]) return;
    vis[s] = true;
    comp++; //Cuento cantidad de componentes

    for(auto &i : g[s]){
        dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int x, y;
    cin >> n >> m >> k;
    g.resize(n);
    vector<int> dir(k);
    vis.assign(n, 0);
    forn(i, k) cin >> dir[i]; //Pido directores
    forn(i, m){
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    forn(i, k){
        comp = 0;
        dfs(dir[i] - 1);
        max_comp = max(max_comp, comp); //Calculo la componente mas grande que tiene a un gov
        totar += (comp * (comp - 1)) / 2;
    }

    forn(i, n){
        if(!vis[i]){ //Si no visite esa componente
            comp = 0;
            dfs(i);
            tot_comp += comp;
        }
    }

    totar += (tot_comp * (tot_comp - 1)) / 2;
    totar += tot_comp * max_comp;

    cout << totar - m << '\n';
    
    return 0;
}