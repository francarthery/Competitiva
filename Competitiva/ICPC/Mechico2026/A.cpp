#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int(x.begin()))
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {for(auto e : x) cout<<e<<' '; cout<<endl;}

using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
const ll mod = 998244353;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<ll> dp(n+1);
    dp[0]=-1;
    int j=-1;
    forn(i,n){
        while(j>=0 && s[i] != s[j]) j = dp[j];
        dp[i+1]=++j;
    }

    // vdbg(dp);a

    vector<ll>cn, f(k+1);
    forn(i,n+1) if(dp[i]==0){
        cn.push_back(i);
    }
    f[0]=1;
    for(int i=0;i<=k;i++){
        for(auto &e : cn){
            if(i+e > k) continue;
            f[i+e] = (f[i+e] + f[i]) % mod;
        }
    }

    cout<<f[k]<<endl;
}

int main(){
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;cin>>t;
    while(t--){
        solve();
    }



    return 0;
}
