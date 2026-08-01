#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(x) (int(x.size()))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w", stdout);
    #endif

    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> col(n);
    int a, b; 
    forn(i, n-1) {
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    forn(i, n) cin >> col[i];

    int ini = -1;
    forn(i, n) if(sz(g[i]) == 1) ini = i;

    int ini1 = -1, ini2 = -1;
    function<void(int, int)> dfs = [&](int s, int f) {
        if(ini1 != -1) return;
        for(int u : g[s]) if(u != f) {
            if(col[s] != col[u]) {
                ini1 = s;
                ini2 = u;
            }
            else dfs(u, s);
        }
    };

    dfs(ini, -1);

    bool ok = true;
    ll ans = -1;
    // dbg(ini1);
    if(ini1 != -1) {
        int pos1 = ini1, pos2 = ini2;
        for(int u : g[pos1]) {
            ini1 = ini2 = -1;
            dfs(u, pos1);
            if(ini1 != -1 or ini2 != -1) ok = false;
        }
        if(ok) ans = pos1;
        
        ok = true;
        for(int u : g[pos2]) {
            ini1 = ini2 = -1;
            dfs(u, pos2);
            if(ini1 != -1 or ini2 != -1) ok = false;
        }
        if(ok) ans = pos2;
    } 

    cout << (!ok ? "NO":"YES") << '\n';
    if(ok) {
        if(ans == -1) cout << 1 << '\n';
        else cout << ans + 1 << '\n';

    }

    return 0;
}