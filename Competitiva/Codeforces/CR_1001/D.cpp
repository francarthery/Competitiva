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

vector<int> l, r, ans, vis;
vector<vector<int>> g;
ll resp = 0;

void dfs(int s){

    int val = l[s];
    for(int &u : g[s]){
        if(vis[u] == 0) {
            vis[u] = vis[s] + 1;
            dfs(u);
            val = max(val, ans[u]);
        }
    }
    ans[s] = min(val, r[s]);

    for(int &u : g[s]){
        if(vis[u] == vis[s] + 1 and ans[u] > ans[s]) resp += ans[u] - ans[s];
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, a, b;
    cin >> t;
    while(t--){
        cin >> n;
        l.resize(n);
        r.resize(n);
        g.assign(n, vector<int>());
        vis.assign(n, 0);
        ans.assign(n, 0);
        resp = 0;

        forn(i, n) cin >> l[i] >> r[i];
        forn(i, n - 1){
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        vis[0] = 1;
        dfs(0);
        cout << ans[0] + resp << '\n';
    }
    
    return 0;
}