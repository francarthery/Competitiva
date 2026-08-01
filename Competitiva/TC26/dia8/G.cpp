#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ws <<" "<<
#define nl cout<<"\n";
#define dbg(x) cout<<#x ws "=" ws x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}

using namespace std;
typedef pair<int, int> ii;

void solve(){
    int n;cin>>n;
    vector<vector<int>>g(n);

    forn(i,n-1){
        int u,v;cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n<=3){
        cout<<n<<endl;
        return;
    }

    vector<int> dp(n), best(n);
    auto dfs1 = [&] (auto &&ff, int u, int f, int cnt1 = 2) -> void {
        dp[u] = 1;

        vector<int> rtas;
        for(auto v : g[u]) if(v != f){
            dp[u]++;
            ff(ff, v, u, 1);
            rtas.push_back(dp[v]);
        }

        sort(rall(rtas));
        forn(i, min(cnt1, sz(rtas))){
            dp[u] += rtas[i]-1;
        }
        return;
    };


    auto dfs2 = [&] (auto &&ff, int u, int f, int fat) -> void {
        best[u] = sz(g[u]) + 1;
        vector<ii> rtas{{fat, f}};
        for(auto v : g[u]) if(v != f) {
            rtas.push_back({dp[v], v});
        }
        
        sort(rall(rtas));
        forn(i, min(2, sz(rtas))){
            best[u] += rtas[i].first-1;
        }

        for(int v : g[u]) if(v != f) {
            int paso = 1;
            if(rtas[0].second == v) {
                if(sz(rtas) > 1) 
                    paso = rtas[1].first; 
            } else {
                paso = rtas[0].first;
            }
            paso += sz(g[u]) - 1;

            ff(ff, v, u, paso-1);
        }
    };

    forn(u,n){
        if(sz(g[u]) >= 2){
            dfs1(dfs1, u, -1);
            dfs2(dfs2, u, -1, 0);
            break;
        }
    }  

    // vdbg(dp);

    cout<<*max_element(all(dp));nl;


}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in","r",stdin);    
    freopen("out","w",stdout);
    #endif

    int q;cin>>q;
    while(q--){
        solve();
    }
    return 0;
}