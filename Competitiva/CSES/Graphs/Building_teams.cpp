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

vector<vector<int>> g;
vector<int> vis;
bool flag = true;

void dfs(int s, bool col){
    if(vis[s] != -1){
        if(vis[s] == !col) flag = false;
        return;
    }
    vis[s] = col;
    for(int &u : g[s]){
        dfs(u, col ^ 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    vis.resize(n, -1);
    forn(i, m){
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    forn(i, n)
        if(vis[i] == -1) dfs(i, 0);
    //vdbg(vis);
    if(!flag) cout << "IMPOSSIBLE\n";
    else forn(i, n) cout << vis[i] + 1 << ' ';
    
    return 0;
}