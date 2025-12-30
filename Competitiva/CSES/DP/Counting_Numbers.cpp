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

    ll a, b; cin >> a >> b;

    auto f = [&](int x) {
        string a = to_string(x);
        vector<vector<int>> dp(sz(a), vector<int>(10));
        forn(i, a[0] - '0' + 1) dp[0][i] = 1;

        forn(i, sz(a) - 1){
            forn(j, 10) {
                int maxn = 10;
                if(j == a[i] - '0') maxn = a[i + 1] - '0' + 1;

                forn(k, maxn){
                    if(j != k or j == 0) dp[i + 1][k] += dp[i][j];
                }
            }
        }

        forn(i, sz(dp)) vdbg(dp[i]);
        dbg(accumulate(all(dp[sz(a) - 1]), 0ll));

        return accumulate(all(dp[sz(a) - 1]), 0ll);
    };

    //ll a; cin >> a; f(a);
    //dbg(f(b)); dbg(f(max(0ll, a - 1)));
    if(b == 0) {
        cout << 0 << '\n';
        return 0;
    }
    cout << f(b - 1) - f(a) << '\n';

    return 0;
}