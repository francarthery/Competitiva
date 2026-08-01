#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<< " = " <<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w",stdout);
    #endif
    
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    forn(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vis(n);
    int ma = -1, nodo = -1, medio = -1;
    function<void(int, int, int)> dfs = [&](int s, int f, int d) {
        vis[s] = true;
        if(d > ma) {
            nodo = s;
            ma = d;
        }
        for(int u : g[s]) if(u != f) dfs(u, s, d+1);
    };

    function<bool(int, int, int)> dfs2 = [&](int s, int f, int d) -> bool{
        bool llegue = false;
        if(s == nodo) llegue = true;
        for(int u : g[s]) if(u != f) llegue |= dfs2(u, s, d+1);
        if(llegue and d == ma / 2) medio = s;
        return llegue;
    };

    set<ii> trees;

    forn(i, n) if(!vis[i]) {
        ma = -1, nodo = -1, medio = -1;
        dfs(i, -1, 0);
        int ext1 = nodo;
        ma = nodo = -1;
        dfs(ext1, -1, 0); //nodo queda con el extremo del diametro
        dfs2(ext1, -1, 0);
        trees.insert({-ma, medio});
    }

    vector<ii> ans;
    while(sz(trees) > 1) {
        ii prim = *trees.begin();
        trees.erase(trees.begin());
        ii sec = *trees.begin();
        trees.erase(trees.begin());
        g[prim.second].push_back(sec.second);
        g[sec.second].push_back(prim.second);
        ans.push_back({prim.second, sec.second});

        ma = -1, nodo = -1, medio = -1;
        dfs(prim.second, -1, 0);
        int ext1 = nodo;
        ma = nodo = -1;
        dfs(ext1, -1, 0); //nodo queda con el extremo del diametro
        dfs2(ext1, -1, 0);
        trees.insert({-ma, medio});
    }

    cout << -trees.begin() -> first << '\n';
    for(auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    

    return 0;
}
