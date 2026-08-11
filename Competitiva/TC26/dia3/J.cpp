#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x <<" = "; for(auto e  : x ) cout<<e<< ' '; cout<<'\n';}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("in", "r", stdin);
        freopen("out","w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<ll>> dp(k+2, vector<ll>(3, -1e16));
        vector<ll> a(n);
        ll ma = -1e9;
        forn(i, n) {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        
        forn(elem, n) {
            dp[1][0] = 0;
            vector<vector<ll>> dp2(k+2, vector<ll>(3, -1e16));
            forr(i, 1, k+2) {
                dp2[i][0] = max({dp[i-1][0] + a[elem], dp[i][0]});

                dp2[i][1] = max({dp[i-1][1], dp[i][0] + a[elem], dp[i][1] + a[elem]});

                dp2[i][2] = max({dp[i-1][2] + a[elem], dp[i][1], dp[i][2]});
            }
            dp.swap(dp2);
        }

        if(ma < 0) cout << ma << '\n';
        else{
            ll best = -1e16;
            forn(i, k+2) forn(j, 3) best = max(best, dp[i][j]);
            cout << best << '\n';
        }    
    }

    return 0;
}