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

vector<vector<ii>> g;
vector<pair<bool, int>> vis;
vector<bool> col;
vector<ii> inp;
bool flag = 1;

void dfs(int s, bool c){
    if(!flag) return;
    if(vis[s].fr){  
        if(vis[s].sc == !c) flag = false;
        return;
    }
    vis[s] = {true, c};

    for(auto u : g[s]){
        dfs(u.fr, !c);
        if(inp[u.sc].fr == s and inp[u.sc].sc == u.fr) col[u.sc] = 0;
        else col[u.sc] = 1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, m, x, y;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    col.resize(m);
    inp.resize(m);

    forn(i, m){
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
        inp[i] = {x, y};
    }
    dfs(1, 0); //nodo inicial, de donde vengo, color inicial

    cout << (flag ? "YES" : "NO") << '\n';
    if(flag) {
        forr(i, 1, n) cout << col[i];
        cout << '\n';
    }
    
    return 0;
}