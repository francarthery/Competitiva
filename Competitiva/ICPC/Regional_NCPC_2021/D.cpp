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

    ll n, w; cin >> n >> w;
    vector<vector<int>> g(n+1);
    vector<ll> c(n+1), wat(n+1);
    forr(i, 1, n+1) {
        int d; cin >> d >> c[i] >> wat[i];
        g[i].pb(d);
        g[d].pb(i);
    }

    vector<ll> need(n), sum(n);
    ll ans = w;
    function<void(int, int)> dfs = [&](int s, int f) {
        for(int u : g[s]) {
            if(u == f) continue;
            sum[u] = sum[s] + wat[u];
            need[u] = max(c[u] - wat[u], need[s] - wat[u]);
            dfs(u, s);
        }
        if(sum[s] + need[s] >= w) ans = min(ans, need[s]);
        else ans = min(ans, w - sum[s]);
    };

    dfs(0, -1);

    cout << ans << '\n';

    return 0;
}