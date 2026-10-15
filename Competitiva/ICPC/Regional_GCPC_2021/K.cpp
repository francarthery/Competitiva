#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end();
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "<<;for(auto e : x) cout<<e<<" ";cout<<endl;}

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int n, m, p; cin >> n >> m >> p;
    vector<vector<int>> g(n);
    int a, b; 
    forn(i, m) {
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vis(n, -1);
    bool puedo = true;
    auto dfs = [&](auto &&f, int s, bool col) -> void {
        if(vis[s] != -1) {
            if(vis[s] != col) puedo = false;
            return;
        }
        vis[s] = col;
        for(int u : g[s]) {
            f(f, u, !col);
        }
    };

    bool invalido = false;
    int cant = 0;
    forn(i, n) if(vis[i] == -1) {
        puedo = true;
        dfs(dfs, i, 0);
        if(puedo) cant++;
        else invalido = true;
    }
    // dbg(cant);
    ll ans = 1;
    forn(i, cant-1) ans = ans * 2ll % p;
    if(invalido) cout << "impossible" << '\n';
    else cout << (ans+1)%p << '\n';

    return 0;
}