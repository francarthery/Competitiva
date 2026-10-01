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
    vector<vector<int>> g(n), tokens(n);
    forn(i, n-1) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    set<int> nodes;
    forn(i, n) nodes.insert(i);

    auto dfs = [&](auto &&ff, int s, int f) -> void {
        nodes.erase(s);
        tokens[s].push_back(s+n);
        for(int u : g[s]) if(u != f) {
            tokens[u] = tokens[s];
            ff(ff, u, s);
        }
        tokens[s].insert(tokens[s].end(), all(nodes));
        nodes.insert(s);
    };

    dfs(dfs, 0, -1);
    map<int, int> comp;
    int cont = 0;
    forn(i, n) forn(j, sz(tokens[i])) {
        if(comp.count(tokens[i][j])) tokens[i][j] = comp[tokens[i][j]];
        else tokens[i][j] = comp[tokens[i][j]] = ++cont;
    }
    
    cout << cont << '\n';
    forn(i, n) {
        cout << sz(tokens[i]) << ' ';
        for(int i : tokens[i]) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}