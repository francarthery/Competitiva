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
    while(t--) {
        string a, b; cin >> a >> b;
        int n = sz(a), m = sz(b);
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        vector<int> pfa(n + 1), pfb(m + 1);
        forn(i, n) pfa[i+1] = (pfa[i+1] + pfa[i] + a[i] - '0') % 10;
        forn(i, m) pfb[i+1] = (pfb[i+1] + pfb[i] + b[i] - '0') % 10;

        if(pfa[n] != pfb[m]) {
            cout << -1 << '\n';
            continue;
        }

        forr(i, 1, n+1) {
            forr(j, 1, m+1) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(pfa[i] == pfb[j]) dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
        }

        cout << dp[n][m] << '\n';
    }



    return 0;
}