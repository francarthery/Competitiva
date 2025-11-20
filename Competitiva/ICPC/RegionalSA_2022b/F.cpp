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
    
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    int a, b;
    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<int> vis(n);
    map<int, vector<int>> comps;
    map<int, int> w;
    function<void(int, int)> dfs = [&](int s, int col){
        comps[col].pb(s);
        if(s != n - 1) w[col] = max(w[col], s); //OJO

        for(int u : g[s]){
            if(!vis[u]) {
                vis[u] = col;
                dfs(u, col);
            }
        }
    };

    int col = 1;
    vis[n - 1] = 1;
    for(int u : g[n - 1]){
        if(!vis[u]) {
            vis[u] = ++col;
            dfs(u, col);
        }
    }
    //vdbg(vis);

    int maxcol = 0, cant = -1;
    for(auto i : w){
        //cout << i.fr << ' ' << i.sc << '\n';
        if(i.sc > cant){
            cant = i.sc;
            maxcol = i.fr;
        }
    }
    //dbg(col); dbg(cant);

    string ans;
    forn(i, n){
        if(vis[i] == maxcol) ans += 'B';
        else ans += 'A';
    }

    cout << ans << '\n';

    return 0;
}