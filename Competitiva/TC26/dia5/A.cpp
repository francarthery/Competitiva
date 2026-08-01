#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    ll n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    ll a, b; 
    forn(i, m) {
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> tam(n, -1);
    function<void(int)> dfs = [&](int s) {
        for(int u : g[s]) {
            if(tam[u] == -1) {
                tam[u] = 1;
                dfs(u);
                tam[s] += tam[u];
            } 
        }
    };

    ll ans = 1;
    forn(i, n) if(tam[i] == -1) {
        tam[i] = 1;
        dfs(i);
        ans <<= (tam[i] - 1);
    }

    cout << ans << '\n';

    return 0;
}