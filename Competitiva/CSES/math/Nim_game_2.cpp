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

int n;
// map<vector<int>, bool> dp;
// bool solve(vector<int> &x) {
//     if(x == vector<int>(n, 0)) return 0;
//     if(dp.count(x)) return dp[x];

//     bool ans = 0;
//     forn(i, n) {
//         forn(j, 3) {
//             if(x[i] - (j+1) < 0) continue;
//             x[i] -= j+1;
//             ans = ans | !solve(x);
//             x[i] += j+1;
//         }
//     }

//     int xr = 0;
//     forn(i, n) xr ^= x[i];
//     if(!ans) cout << xr << '\n';

//     return dp[x] = ans;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        cin >> n;
        ll xo = 0;
        vector<int> v(n);
        int xr = 0;
        forn(i, n) cin >> v[i], xr ^= v[i];
        cout << (xr % 4 != 0 ? "first" : "second") << '\n';
    }

    // for(auto i : dp) cout << i.fr << ' ' << i.sc << '\n';


    return 0;
}