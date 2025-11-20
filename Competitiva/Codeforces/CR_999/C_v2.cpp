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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, x; cin >> n;
        vector<int> v(n), dp(n + 1);
        forn(i, n) cin >> v[i];

        dp[0] = 1;
        
        forr(i, 1, n + 1){
            if(i > 1 and v[i - 1] == v[i - 2]) dp[i] = (dp[i] + dp[i - 1]) % MOD;
            if(i > 2 and v[i - 3] + 1 == v[i - 1]) dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }

        cout << (dp[n - 1] + dp[n]) % MOD << '\n';
    }

    return 0;
}