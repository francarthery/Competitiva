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
    while(t--) {
        int x, n; cin >> n;
        vector<vector<int>> g(n);
        forn(i, n-1) {
            cin >> x; x--;
            g[x].pb(i+1);
        }
        vector<int> col(n);
        forn(i, n) cin >> col[i];

        bool ok = true;

        vector<int> mi(n), ma(n);
        function<void(int)> dfs = [&](int s) {
            if(col[s]) { //es hoja
                mi[s] = ma[s] = col[s];
                return;
            }

            vector<ii> ext;
            int mae = 0, mie = 1e9;
            for(int u : g[s]) {
                dfs(u);
                ext.pb({mi[u], ma[u]});

                mae = max(mae, ma[u]);
                mie = min(mie, mi[u]);
            }
            
            forn(i, sz(ext) - 1) {
                if(ext[i].sc != mae and ext[i].sc + 1 != ext[i+1].fr) ok = false;
                if(ext[i].sc == mae and ext[i+1].fr != mie) ok = false;
            }

            mi[s] = mie;
            ma[s] = mae;
        };

        dfs(0);

        cout << (ok ? "YES" : "NO") << '\n';

    }



    return 0;
}