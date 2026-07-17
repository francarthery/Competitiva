#include <bits/stdc++.h>
#define forr(i, a, n) for(ll i = a; i < n; i++)
#define forn(i, n) for(ll i = 0; i < n; i++)
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

const int MOD = 1e9+ 7;
ll expMod(ll b, ll e, ll m = MOD) {
    if(e < 0) return 0;
    ll ret = 1;
    while(e) {
        if(e&1) ret = ret * b % m;
        b = b * b % m;
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

    int k, n; cin >> k;
    vector<ll> pref1(1e6+1), pref2(1e6+1);
    ll inv2 = expMod(2, MOD - 2);
    forr(i, 2, 1e6+1) pref1[i] = (pref1[i-1] + (i * (i-1) % MOD) * inv2 % MOD) % MOD;
    forr(i, 2, 1e6+1) pref2[i] = (pref2[i-1] + (i / 2)) % MOD;

    //vdbg(pref1); vdbg(pref2);
    ll ans = 1;
    forn(i, k) {
        int n; cin >> n; n--;
        ans = (ans * pref2[n] % MOD) * expMod(pref1[n], MOD-2) % MOD;
        cout << ans << '\n';
    }





    return 0;
}