#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ws <<" "<<
#define vdbg(x){cout<<#x<<" = "<<x; for(auto e : x) cout<<x<<' ';cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n, m;
vector<int> v;
int dp[1000010][3][3]; //posicion, cantidad sobrante del primero, cantidad sobrante del segundo
int solve(int i, int c0, int c1) {
    if(i <= 0) return 0;
    if(dp[i][c0][c1] != -1) return dp[i][c0][c1];
    dp[i][c0][c1] = -1e9;

    forn(j, 3) {
        int need = j + c0 + c1;
        if(need <= v[i]) {
            int win = (v[i] - need) / 3;
            dp[i][c0][c1] = max(dp[i][c0][c1], solve(i-1, j, c0) + c1 + win);
        }
    }

    return dp[i][c0][c1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    cin >> n >> m;
    v.resize(m+3);
    forn(i, n) {
        int x; cin >> x;
        v[x]++;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(m+2, 0, 0) << '\n'; //correcto?

    // forn(i, m+3) {
    //     forn(j, 3) {
    //         forn(k, 3) cout << dp[i][j][k] << ' ';
    //         cout << "  ";
    //     }
    //     cout << '\n';
    // }

    return 0;
}