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
    forn(i, n-1) {
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    int ans = 0;
    function<bool(int, int)> dfs = [&](int s, int f) -> bool {
        bool use = false;
        for(int u : g[s]) {
            if(u == f) continue;
            if(!dfs(u, s) and !use) {
                use = true;
                ans++;
            }
        }
        return use;
    };
    dfs(0, -1);
    cout << ans << '\n';

    return 0;
}