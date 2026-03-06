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
    vector<vector<ii>> g(n);
    int a, b, c;
    forn(i, n - 1) {
        cin >> a >> b >> c; a--; b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }

    int m; cin >> m;
    vector<int> dg(n);
    forn(i, m) {
        cin >> a >> b; a--; b--;
        dg[a]++; dg[b]++;
    }

    ll ans = 0;
    function<bool(int, int)> dfs = [&](int s, int f) -> bool {
        int par = dg[s];
        for(auto [u, c] : g[s]){
            if(u == f) continue;
            int uso = dfs(u, s);
            if(uso) ans += c;
            par += uso; 
        }
        return par & 1;
    };

    dfs(0, -1);
    cout << ans << '\n';

    return 0;
}