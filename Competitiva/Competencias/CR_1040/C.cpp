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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        vector<vector<int>> g(2 * n);
        map<ii, int> ar;
        vector<ii> ari(n);
        
        forn(i, n){
            int a, b; cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
            ar[{a, b}] = 1;
            ari[i] = {a, b};
        }

        bool flag = false;
        vector<int> vis(2 * n);

        function<void(int, int)> dfs = [&](int s, int fa){
            if(!flag) return;
            vis[s] = true;

            for(int u : g[s]) {
                if(u == fa or ar[{min(u, s), max(u, s)}] == 0) continue;

                if(vis[u]) {
                    ar[{min(u, s), max(u, s)}] = 0;
                    flag = false;
                    return;
                }

                dfs(u, s);
            }
        };

        while(!flag) {
            flag = true;
            vis.assign(2 * n, 0);
            forn(i, 2 * n){
                if(!vis[i]) dfs(i, -1);
            }
        }
        
        vector<int> ans;
        forn(i, n){
            if(ar[ari[i]]) ans.pb(i + 1);
        }

        cout << sz(ans) << '\n';
        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }



    return 0;
}