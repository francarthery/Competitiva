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
        int n; cin >> n;
        vector<int> v(2*n);
        vector<ii> ap(n+1, ii(-1, -1));
        forn(i, 2*n) {
            cin >> v[i];
            if(ap[v[i]].first == -1) ap[v[i]].first = i;
            else ap[v[i]].second = i;
        }

        vector<ll> dp(2*n+1);
        forn(i, 2*n) {
            if(ap[v[i]].first == i) {
                dp[i+1] = dp[i]+1;
                continue;
            }

            ll cuad = ap[v[i]].second - ap[v[i]].first + 1;
            cuad *= cuad;
            dp[i+1] = max(dp[i] + 1, dp[ap[v[i]].first] + cuad);
        }

        cout << dp[2*n] << '\n';
    }



    return 0;
}