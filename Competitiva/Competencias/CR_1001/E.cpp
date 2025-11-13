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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, a, b, x;
    cin >> t;
    while(t--){
        cin >> n;
        multiset<int> w;
        vector<int> p(n);
        vector<bool> vis(n);
        vector<vector<int>> g(n);
        ll elem = -1, ma = -1;

        forn(i, n) cin >> p[i], w.insert(p[i]);
        forn(i, n - 1){
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        function<int(int, int)> dfs = [&](int s, int ma2) -> int{
            vis[s] = true;

            int masub = ma2;
            for(int &u : g[s]){
                if(vis[u]) continue;
                masub = max(masub, dfs(u, masub));
            }
            masub = max(masub, p[s]);
            
            // ma2: maximo entre elementos ya visitados sin los del subarbol de s
            if(max(ma2, *w.rbegin()) > p[s] and p[s] > ma){
                ma = p[s];
                elem = s;
            }

            w.erase(w.find(p[s]));
            return masub;
        };
        
        dfs(0, 0);
        cout << elem + 1 << '\n';

    }

    return 0;
}