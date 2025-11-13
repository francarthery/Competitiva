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

vector<vector<int>> g;
vector<int> vis, ant;
int prim = -1;

void dfs(int s){
    if(vis[s] == 2) return;
    if(vis[s] == 1){
        prim = s;
        return;
    }
    vis[s] = 1; 
    for(int u : g[s]){
        if(prim != -1) return;
        ant[u] = s;
        dfs(u);
    }

    vis[s] = 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    ant.resize(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
    }

    forn(i, n) if(!vis[i] and prim == -1) dfs(i);

    if(prim != -1){
        int val = ant[prim];
        vector<int> ans{prim};
        while(val != prim){
            ans.pb(val);
            val = ant[val];
        }
        ans.pb(prim);
        cout << sz(ans) << '\n';
        dfor(i, sz(ans)) cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    else cout << "IMPOSSIBLE\n";
    
    return 0;
}