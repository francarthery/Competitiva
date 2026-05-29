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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<vector<int>> g(n);
    int a, b; 
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<bool> diam(n);
    function<ii(int, int)> dfs = [&](int s, int f) -> ii{
        ii best = {0, s};
        for(int u : g[s]) {
            if(u == f) continue;
            ii son = dfs(u, s);
            best = max(best, {son.fr+1, son.sc});
        }
        return best;
    };

    ii prim = dfs(0, -1);
    ii sec = dfs(prim.sc, -1);
    
    vector<int> perm;
    function<bool(int, int)> dfs2 = [&](int s, int f) -> bool {
        bool ans = s == sec.sc;
        for(int u : g[s]) {
            if(u == f) continue;
            ans |= dfs2(u, s);
        }   

        if(ans) perm.pb(s);
        diam[s] = ans;
        return ans;
    };

    vector<bool> vis;
    function<void(int, int)> dfs3 = [&](int s, int f) {
        if(vis[s]) return;
        vis[s] = true;
        perm.pb(s);
        for(int u : g[s]){
            if(u != f) dfs3(u, s);
        }
    };

    if(sec.fr <= 2) {
        cout << "NO\n";
        return 0;
    } 
    dfs2(prim.sc, -1);
    vector<int> aux;
    forr(i, 2, sz(perm)) aux.pb(perm[i]);
    aux.pb(perm[1]); aux.pb(perm[0]);
    perm = aux;
    
    vis = diam;
    forn(i, n) {
        if(vis[i]) continue;
        bool valid = false;
        for(int u : g[i]) if(diam[u]) valid = true; //tiene que estar pegado al chori del diametro
        if(valid) dfs3(i, -1);
    }

    cout << "YES\n";
    for(int i : perm) cout << i+1 << ' ';
    cout << '\n';

    
    return 0;
}