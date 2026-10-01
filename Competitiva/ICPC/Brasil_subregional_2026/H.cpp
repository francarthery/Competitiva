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
    vector<int> v(n+1), diff(n+1);
    int ant = 0;
    forn(i, n) {
        cin >> v[i];
        diff[i] = (v[i] ^ ant);
        ant = v[i];
    }
    diff[n] = v[n-1];

    vector<vector<int>> g(n+1);
    forn(i, m) {
        int a, b; cin >> a >> b; a--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> vis(n+1);
    auto dfs = [&](auto &&f, int s) -> int {
        if(vis[s]) return 0;
        vis[s] = true;
        int cont = 0;
        if(diff[s]) cont++;
        for(int u : g[s]) {
            cont += f(f, u);
        }
        return cont;
    };
    
    bool ans = 1;
    forn(i, n) if(!vis[i]){
        if(dfs(dfs, i) & 1) ans = 0;
    }

    cout << (ans ? "YES" : "NO") << "\n";

    return 0;
}