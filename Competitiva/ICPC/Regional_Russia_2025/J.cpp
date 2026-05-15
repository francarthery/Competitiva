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
typedef pair<int, vector<int>> iv;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];

    vector dp(n, vector(n+1, iv(-1, vector<int>())));
    forn(i, n) {
        dp[i][0].fr = dp[i][1].fr = 0;
        dp[i][0].sc.pb(i);
        dp[i][1].sc.pb(i);
    }

    forn(i, n-1) {
        if(v[i] % v[i+1] == 0 or v[i+1] % v[i] == 0) dp[i][2].fr = 2;
        else {
            dp[i][2].fr = 0;
            dp[i][2].sc.pb(i);
            dp[i][2].sc.pb(i+1);
        }
    }

    forr(r, 3, n+1) {
        forn(i, n - r + 1) {
            forr(k, 1, r) {
                if(dp[i][k].fr + dp[i+k][r-k].fr > dp[i][r].fr){
                    dp[i][r].fr = dp[i][k].fr + dp[i+k][r-k].fr;
                    dp[i][r].sc = dp[i][k].sc;
                    dp[i][r].sc.insert(dp[i][r].sc.end(), all(dp[i+k][r-k].sc));
                }
            } 

            int sumo = 2 * (v[i] % v[i+r-1] == 0 or v[i+r-1] % v[i] == 0);
            if(dp[i][r].fr < dp[i+1][r-2].fr + sumo) {
                dp[i][r] = {dp[i+1][r-2].fr + sumo, dp[i+1][r-2].sc};

                if(!sumo) {
                    dp[i][r].sc.pb(i);
                    dp[i][r].sc.pb(i-r+1);
                }
            }

        }
    }

    cout << sz(dp[0][n].sc) << '\n';
    for(int i : dp[0][n].sc) cout << i+1 << ' ';
    cout << '\n';
    
    return 0;
}