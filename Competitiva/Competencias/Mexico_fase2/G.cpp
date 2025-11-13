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
vector<bool> vis;
map<ii, ll> ar;
ll ma = 0, rta = 0, n, x, y, aux;

int dfs(int s){
    int cont = 1;
    vis[s] = true;
    for(auto u : g[s]){
        if(!vis[u]) {
            aux = dfs(u);
            cont += aux;
            ar[{min(s, u), max(s, u)}] = aux * (n - aux);
        }
    }

    return cont;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n;
    g.resize(n);
    vis.assign(n, 0);
    forn(i, n - 1){
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(0);

    for(auto &i : ar) {
        if(i.sc > ma){
            ma = i.sc; rta = 1;
        }
        else if(i.sc == ma) rta++;
    }

    cout << ma << ' ' << rta << '\n';

    return 0;
}