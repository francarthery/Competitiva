#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ws <<" "<<
#define vdbg(x){cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}
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

    int n,m;cin>>n>>m;
    vector<ll> h(m+1);

    forn(i,n) {
        int x;cin>>x;
        h[x]++;
    }

    map<array<ll,4>, ll> dp;

    // vdbg(h);

    auto solve = [&] (auto &&ff, int i, ll a, ll b, ll c) -> void{
        if(i == m-2) {
            dp[{i,a,b,c}]=0;
            forn(d,min({a,b,c,3ll})+1)
                dp[{i,a,b,c}] = max(dp[{i,a,b,c}], d+(a-d)/3+(b-d)/3+(c-d)/3);
            return;
        }
        if(dp.count({i,a,b,c})) return;
        dp[{i,a,b,c}] = 0;
        // cout<<a ws b ws c<<endl;
        int mi = min({a,b,c});
        mi = min(mi, 3);
        forn(d, mi+1){
            ll sob = d;
            ff(ff,i+1, b-d, c-d, h[i+3]);
            dp[{i,a,b,c}] = max(dp[{i,a,b,c}], dp[{i+1, b-d, c-d, h[i+3]}] + sob + (a-d)/3);
        }
        return;
    };
    
    // dbg(su);
    int ans = 0;
    if(m >= 3){
        solve(solve, 1, h[1], h[2], h[3]);
        ans = dp[{1, h[1], h[2], h[3]}];
    }else{
        if(m >= 1) ans+= h[1]/3;
        if(m == 2) ans+= h[2]/3;
    }
    // dbg(x);

    cout<<ans<<endl;

    return 0;
}
