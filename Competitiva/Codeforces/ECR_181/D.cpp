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
typedef pair<ll, ll> ii;
const int MOD = 998244353;
const int MAXN = 2e5 + 1;

ll expMod(ll b, ll e, ll m = MOD) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
        b = b * b % m;                 // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, l, r, p, q; cin >> n >> m;
    vector<vector<ii>> fin(MAXN);
    vector<ll> acum(MAXN, 1);

    forn(i, n){
        cin >> l >> r >> p >> q;
        int prob = p * expMod(q, MOD - 2) % MOD;
        fin[r].pb({l, prob});
        acum[l] = acum[l] * (1 - prob + MOD) % MOD;
    }
    forn(i, MAXN - 1) acum[i + 1] = acum[i + 1] * acum[i] % MOD;

    vector<ll> dp(MAXN);
    dp[0] = 1;
    forn(i, MAXN){
        if(fin[i].empty()) continue;
        for(auto j : fin[i]){
            int prob = acum[i] * expMod(acum[j.fr - 1], MOD - 2) % MOD;
            prob = ((ll)prob * expMod((1 - j.sc + MOD) % MOD, MOD - 2)) % MOD; //Me saco a mi mismo de la ps
            dp[i] += (j.sc * prob % MOD) * dp[j.fr - 1] % MOD;
            dp[i] %= MOD;
        }
    }

    cout << dp[m] << '\n';


    return 0;
}