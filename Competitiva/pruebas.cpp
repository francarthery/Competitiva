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
typedef pair<ll, ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> v(n);
    vector<vector<int>> g(n);
    forr(i, 1, n) cin >> v[i];
    
    int a, b;
    forn(i, n - 1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<deque<ll>> nodos(n);
    ii ans = {-1e9, -1e9};

    function<void(int, int)> dfs = [&](int s, int f){
        for(int u : g[s]){
            if(u == f) continue;
            dfs(u, s);
            if(sz(nodos[u]) > sz(nodos[s])) swap(nodos[u], nodos[s]);

            forn(i, sz(nodos[u])) {
                nodos[s][i] += nodos[u][i];
                ans = max(ans, {nodos[s][i], -(i + 2)});
            }
        }
        nodos[s].push_front(v[s]); //Inserto al principio para mantener lo mas cercano primero (mas facil)
        ans = max(ans, {v[s], -1}); //AAAAAAAAAAAA
    };

    for(int u : g[0]) dfs(u, 0);
    cout << ans.fr << ' ' << -ans.sc << '\n';

    return 0;
}