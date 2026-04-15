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

    int a, b, n; cin >> n;
    vector<vector<int>> g(n);
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<vector<int>> subt(n);
    vector<int> tam(n);
    function<int(int, int)> dfs1 = [&](int s, int f) -> int{
        tam[s] = 1;
        for(int u : g[s]){
            if(u == f) continue;
            subt[s].pb(dfs1(u, s));
            tam[s] += subt[s].back();
        }
        return tam[s];
    };

    int centroide = -1;
    function<void(int, int, int)> dfs2 = [&](int s, int f, int pad) {
        if(centroide != -1) return;
        int npad = 0;
        pad -= tam[s];
        subt[s].pb(pad);
        bool ok = true;
        for(int u : subt[s]) {
            npad += u;
            if(u > n/2) ok = false;
        }
        if(ok) {
            centroide = s;
            return;
        }    

        for(int u : g[s]) if(u != f) dfs2(u, s, npad);
    };

    dfs1(0, -1);
    dfs2(0, -1, 0);

    cout << centroide + 1 << '\n';

    return 0;
}