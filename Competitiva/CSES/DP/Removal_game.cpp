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
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
 
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    vector dp(n, vector<ll>(n));
 
    forn(i, n) dp[i][i] = v[i];
    forr(i, 1, n) dp[i - 1][i] = max(v[i], v[i - 1]);
 
    forr(i, 2, n){
        forn(j, n - i){
            dp[j][j + i] = max(v[j] + min(dp[j + 1][j + i - 1], dp[j + 2][j + i]), v[j + i] + min(dp[j][j + i - 2], dp[j + 1][j + i - 1]));
        }
    }
 
    cout << dp[0][n - 1] << '\n';
    
    return 0;
}