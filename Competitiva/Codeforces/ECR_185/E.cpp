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

    int t; cin >> t;
    const int MOD = 998244353;
    while(t--){
        int n, m; cin >> n >> m;
        vector<ll> dp(n + 1), pss(n + 1), psm(n + 1);
        vector<ii> v(m);
        
        forn(i, m) cin >> v[i].sc >> v[i].fr;
        sort(rall(v));
        int ma = 0;
        forn(i, n + 1){
            while(sz(v) and v.back().fr == i){
                ma = max(ma, v.back().sc);
                v.pop_back();
            }    
            psm[i] = ma;
        }
        
        dp[0] = dp[1] = 2;
        pss[0] = 2; pss[1] = 4;
        forr(i, 2, n + 1) {
            dp[i] = (pss[i - 1] - (!psm[i] ? 0 : pss[psm[i] - 1]) + MOD) % MOD;
            pss[i] = (pss[i - 1] + dp[i]) % MOD;
        }

        cout << dp[n] << '\n';        
    }



    return 0;
}