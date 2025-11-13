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

    int a, b, n, m, t; cin >> n >> m >> t;
    vector<vector<int>> g(n);
    set<int> vecinos, visite, rta;
    forn(i, m){
        cin >> a >> b;
        if(b == t) vecinos.insert(a);
        else g[b].pb(a); //cargo grafo traverso
    }

    vector<ii> vis(n);
	bool flag = true;
    function<void(int, int)> dfs = [&](int s, int col){
        if(vis[s].fr == col or vis[s].sc == col or vis[s].fr and vis[s].sc) return;
        if(vis[s].fr == 0) vis[s].fr = col;
        else vis[s].sc = col;

        for(int &u : g[s]) dfs(u, col);
    };

    for(auto i : vecinos) dfs(i, i + 1);
    for(auto i : vecinos) if(!vis[i].sc) rta.insert(i);

    cout << sz(rta) << '\n';
    for(int i : rta) cout << i << '\n';

    return 0;
}