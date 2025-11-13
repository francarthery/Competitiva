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

    int n, m; cin >> n >> m;
    vector<int> v1(n), v2(m);
    forn(i, n) cin >> v1[i];
    forn(i, m) cin >> v2[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    forr(i, 1, n + 1) forr(j, 1, m + 1){
        dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
        if(v1[i - 1] == v2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
    }

    int i = n, j = m, ult = dp[n][m];
    vector<int> ans;
    while(ult){
        while(dp[i - 1][j - 1] == ult) i--, j--;
        while(dp[i - 1][j] == ult) i--;
        while(dp[i][j - 1] == ult) j--;
        ans.pb(v1[i - 1]);
        i--; j--; ult--;
    }   

    cout << dp[n][m] << '\n';
    dfor(i, sz(ans)) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}