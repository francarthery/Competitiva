#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define forall(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto  e : x) cout<<e<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int dp[151][151][151][2];
int n, m, k, t;
vector<int> a, b;
int solve(int ant, int mov, int i, int j, int pos) { 
    if(i + j >= t) return 0;
    if(dp[mov][i][j][pos] != -1) return dp[mov][i][j][pos];

    if(!pos) {
        dp[mov][i][j][pos] = solve(a[i], mov, i+1, j, 0) + (a[i]==ant);
        if(mov < k) dp[mov][i][j][pos] = max(dp[mov][i][j][pos], solve(b[j], mov+1, i, j+1, 1) + (b[j]==ant));
    }
    else {
        dp[mov][i][j][pos] = solve(b[j], mov, i, j+1, 1) + (b[j]==ant);
        if(mov < k) dp[mov][i][j][pos] = max(dp[mov][i][j][pos], solve(a[i], mov+1, i+1, j, 0) + (a[i]==ant));
    }

    return dp[mov][i][j][pos];
}

int main(){ 
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    
    cin >> k >> t;
    cin >> n;
    a.resize(t);
    forn(i, n) {
        cin >> a[i];
        for(int j = i+n; j<t; j+=n) a[j] = a[i];
    }
    
    cin >> m;
    b.resize(t);
    forn(i, m) {
        cin >> b[i];
        for(int j = i+m; j<t; j+=m) b[j] = b[i];
    }
    // vdbg(a); vdbg(b);

    memset(dp, -1, sizeof(dp));
    cout << solve(a[0], 0, 1, 0, 0) << '\n';    

    return 0;
}