#include <bits/stdc++.h>
#define forr(i, a, n) for(ll i = a; i < n; i++)
#define forn(i, n) for(ll i = 0; i < n; i++)
#define dfor(i, n) for(ll i = n - 1; i >= 0; i--)
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

    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        vector<ll> a(n), b(m);

        forn(i, n) cin >> a[i];
        forn(i, m) cin >> b[i];

        vector dp(m + 1, vector(n + 1, vector<int>(2))); //0 fus, 1 buscar
        dp[0][0][1] = 1;

        forn(i, m) {
            forr(j, i, n) {
                dp[i][j + 1][0] |= dp[i][j][0]; //Agrando el intervalo
                if(j + b[i] <= n) dp[i + 1][j + b[i]][0] |= dp[i][j][0] || dp[i][j][1];
                if(b[i] == a[j]) dp[i + 1][j + 1][1] |= dp[i][j][0] || dp[i][j][1];
            }
        }
        forn(i, n) dp[m][i + 1][0] |= dp[m][i][0];

        if(dp[m][n][0] or dp[m][n][1]) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}