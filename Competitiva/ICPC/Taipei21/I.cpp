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
#define vdbg(x) {cout << '['; forn(i, sz(x)) cout << x[i] << ", "; cout << "]\n";}
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
        vector<int> a, b;
        int x;
        ll sa = 0, sb = 0;
        forn(i, n) {
            cin >> x;
            sa += x * (i+1);
            if(x == 1) a.pb(i+1);
        }
        forn(i, n) {
            cin >> x;
            sb += x * (i+1);
            if(x == 2) b.pb(i+1);
        }

        ll diff = sb - sa;
        const int MAXN = 2e4+1; //OJOO
        int n1 = sz(a);
        int m1 = sz(b);
        vector<vector<bitset<MAXN>>> dp1(n1+1, vector<bitset<MAXN>>(n1+1)), dp2(m1+1, vector<bitset<MAXN>>(m1+1));

        forn(i, n1) dp1[0][i] = 1;
        forn(i, m1) dp2[0][i] = 1;

        forn(i, n1) forn(j, n1) dp1[i+1][j+1] = (dp1[i+1][j] | (dp1[i][j] << a[j]));
        forn(i, m1) forn(j, m1) dp2[i+1][j+1] = (dp2[i+1][j] | (dp2[i][j] << b[j]));

        ll ans = -1;
        if(!diff) ans = 0;
        forr(i, 1, min(n1, m1)+1) {
            if(ans != -1) break;
            forn(j, min(diff+1, (ll)MAXN)) {
                if(dp1[i][n1][j] and dp2[i][m1][diff-j]) ans = i; 
            } 
        }

        cout << ans << '\n';
    }

    return 0;
}