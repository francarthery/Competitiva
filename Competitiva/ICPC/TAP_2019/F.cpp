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

    const int MOD = 1e9+7;
    int n, m, k; cin >> n >> m >> k; //van a estar al reves
    vector<string> vtras(n), v(m);
    forn(i, n) cin >> vtras[i];
    forn(i, m) dfor(j, n) v[i] += vtras[j][i];

    vector<string> valid;
    auto gen = [&](auto &&f, string &pal, int len, int ant) {
        if(len == n) {
            valid.push_back(pal);
            return;
        }
        forn(i, k) if(ant != i+1) {
            pal += (i+1+'0');
            f(f, pal, len+1, i+1);
            pal.pop_back();
        }
    };

    string pal;
    gen(gen, pal, 0, -1);

    vector<vector<int>> trans(sz(valid)); //transiciones, no lizy tagliani
    forn(i, sz(valid)) {
        forn(j, sz(valid)) {
            bool ok = true;
            forn(k, n) if(valid[i][k] == valid[j][k]) ok = false;
            if(ok) trans[i].push_back(j);
        }
    }

    vector<vector<int>> dp(m, vector<int>(sz(valid)));
    forn(i, sz(valid)) {
        bool ok = true;
        forn(j, n) if(v[0][j] != '-' and v[0][j] != valid[i][j]) ok = false;
        if(ok) dp[0][i] = 1;
    }
    forr(i, 1, m) {
        forn(j, sz(valid)) {
            bool ok = true;
            forn(k, n) if(v[i][k] != '-' and v[i][k] != valid[j][k]) ok = false;
            if(!ok) continue;
            
            forn(k, sz(trans[j])) dp[i][j] = (dp[i][j] + dp[i-1][trans[j][k]]) % MOD; 
        }
    }

    ll ans = 0;
    forn(i, sz(valid)) ans = (ans + dp[m-1][i]) % MOD;
    cout << ans << '\n';

    return 0;
}