#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n; cin >> n;
    const int MOD = 1e9 + 7;
    vector<ll> cols(3);
    forn(i, n) cin >> cols[i];

    vector<vector<ll>> dp(n+1, vector<ll>(3));
    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    forr(i, 2, n+1) {
        ll sum = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        forn(j, 3) {
            ll resto = 0;
            if(i - cols[j] - 1 > 0) forn(k, 3) {
                if(k != j) resto = (resto + dp[i - cols[j] - 1][k]) % MOD;
            }
            else if(i - cols[j] - 1 == 0) resto = 1;
            dp[i][j] = (sum - resto + MOD) % MOD;
        }
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << '\n'; 

    return 0;
}