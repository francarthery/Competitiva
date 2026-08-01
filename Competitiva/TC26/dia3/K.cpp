#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x <<" = "; for(auto e  : x ) cout<<e<< ' ';}cout<<endl;
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

    while(t--){
        int n, k; cin >> n >> k;

        vector<int> a(n), b(n);
        forn(i, n) cin >> a[i]; 
        forn(i, n) cin >> b[i];
        vector<ll> dp(n, -1);
        
        auto solve = [&](auto &&f,int i, int ma) -> ll{
            if(i >= n) return (k - i) * ma;
            if(i >= k) return 0;
            if(dp[i] != -1) return dp[i];

            ma = max(ma, b[i]);
            dp[i] = a[i] + max((ll) (k - i - 1) * ma, f(f, i + 1, ma));
            return dp[i];
        };

        cout << solve(solve, 0, 0) << '\n';
    }

    return 0;
}

// 4
// 4 7
// 4 3 1 2
// 1 1 1 1
// 3 2
// 1 2 5
// 3 1 8
// 5 5
// 3 2 4 1 4
// 2 3 1 4 7
// 6 4
// 1 4 5 4 5 10
// 1 5 1 2 5 1


// 13
// 4
// 15
// 19
