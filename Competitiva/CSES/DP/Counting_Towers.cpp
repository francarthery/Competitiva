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
 
const int MOD = 1e9 + 7;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int t, n, sum = 1;
    vector<int> dp(1e6 + 1);
    dp[0] = 1;
    dp[1] = 2;

    forr(i, 2, 1e6 + 1){
        dp[i] = (dp[i] + 2LL * dp[i - 1]) % MOD; //Empiezo desde 0
        dp[i] = (dp[i] + (3LL * (((dp[i - 1] - sum) + MOD) % MOD)) % MOD) % MOD; //Prolongo los anteriores
        dp[i] = (dp[i] + sum) % MOD; //Uso los dobles
 
        sum = (sum + dp[i - 1]) % MOD;
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}