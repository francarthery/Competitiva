#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(m + 1));
    forr(i, 1, m + 1) dp[0][i] = 1;

    forn(i, n){
        forr(j, 1, m + 1){
            if(v[i] == 0){
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
                if(j > 1) dp[i + 1][j] += dp[i][j - 1];
                dp[i + 1][j] %= MOD;
                if(j < m) dp[i + 1][j] += dp[i][j + 1];
                dp[i + 1][j] %= MOD;
            }
            else if(v[i] == j) dp[i][j] = 1;   
        }
    }

    ll rta = 0;
    forr(i, 1, m + 1) rta = (rta + dp[n - 1][i]) % MOD;
    cout << rta << '\n';
    
    return 0;
}