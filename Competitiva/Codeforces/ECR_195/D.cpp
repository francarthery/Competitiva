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
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> dg(n);
        int a, b; 
        forn(i, m) {
            cin >> a >> b; a--; b--;
            g[a].push_back(b); 
            g[b].push_back(a);
            dg[a]++;
            dg[b]++;
        }

        vector<int> vis(n);
        auto dfs = [&](auto &&f, int s) -> int {
            if(vis[s]) return 0;
            vis[s] = 1;
            int cont = 1;
            for(int u : g[s]) cont += f(f, u);
            return cont;
        };

        bool flag = true;
        int ccomp = 0;
        forn(i, n) if(!vis[i]) {
            ccomp++;
            int tam = dfs(dfs, i);
            if(tam < 2) flag = false;
        }
        
        if(!flag) {
            cout << "Brain Melt\n";
            continue;
        }

        bool ismore = ccomp > 1, lovi = false;
        forn(i, n) {
            if(dg[i] > 1) {
                if(lovi) ismore = true;
                lovi = true;
            }
        }

        cout << (ismore ? "Many" : "2") << '\n';
    }



    return 0;
}