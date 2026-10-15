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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
int n;
map<vector<int>, bool> dp;
bool solve(vector<int> &x, ll sum) {
    if(!sum) return 0;
    if(dp.count(x)) return dp[x];

    bool ans = false;
    forr(i, 1, n) {
        forr(j, 1, x[i]+1) {
            x[i] -= j;
            x[i-1] += j;
            if(i == 1) sum -= j;
            ans = (ans or !solve(x, sum));
            if(i == 1) sum += j;
            x[i-1] -= j;
            x[i] += j;
        }
    }
    if(ans) return dp[x] = ans;
    vdbg(x);
    int xr = 0;
    forr(i, 1, n) xr += x[i];
    cout << "  " << ans << ' ' << xr << '\n';
    return dp[x] = ans;
}

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
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        ll sum = 0;
        forr(i, 1, n) sum += v[i]; 
        cout << (solve(v, sum) ? "first" : "second") << '\n';
    }



    return 0;
}