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
        vector<vector<int>> g(n), dp(n, vector<int>(3));
        int a, b; 
        forn(i, n - 1){
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        function<void(int, int)> dfs = [&](int s, int f){
            bool flag = true;
            for(int u : g[s]){
                if(u == f) continue;
                if(flag) {
                    dp[s][0] = true;
                    flag = false;
                }
                
                dfs(u, s);
                vector<int> pos(3);
                forn(i, 3) forn(j, 3) {
                    if(dp[s][i] and dp[u][j]) pos[(i + j) % 3] = true;
                }       
                dp[s] = pos;         
            }
            dp[s][1] = true;
        };

        dfs(0, -1);
        if(dp[0][0]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}