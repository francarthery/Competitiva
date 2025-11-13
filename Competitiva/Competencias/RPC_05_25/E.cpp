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

    int t, cont = 0; cin >> t;
    while(t--){
        cont++;
        int n, m, h;
        cin >> n >> m;
        string s, s2;
        unordered_map<string, int> nombres;
        vector<int> w(n), vis(n);
        vector<vector<int>> g(n);
        vector<string> reverso(n);

        forn(i, n){
            cin >> s >> h;
            w[i] = h;
            nombres[s] = i;
            reverso[i] = s;
        }

        forn(i, m){
            cin >> s >> s2;
            int n1 = nombres[s], n2 = nombres[s2]; 
            g[n1].pb(n2);
            g[n2].pb(n1);
        }

        int ind = 0, ma = 0;
        function<void(int)> dfs = [&](int s){
            if(vis[s]) return;
            vis[s] = true;
            if(w[s] > ma){
                ma = w[s];
                ind = s;
            }

            for(int &u : g[s]) dfs(u);
        };
        
        cout << "Case " << cont << ":\n";
        vector<string> res;
        forn(i, n){
            if(!vis[i]) {
                ma = 0, ind = 0;
                dfs(i);
                res.pb(reverso[ind]);
            }
        }
        sort(all(res));
        forn(i, sz(res)) cout << res[i] << '\n';
    }

    return 0;
}