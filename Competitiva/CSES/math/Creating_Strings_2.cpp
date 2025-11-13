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

ll expMod(ll b, ll e, ll m) {  // O(log e)
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

    const int MOD = 1e9 + 7;
    const int MAXN = 1e6 + 1;
    vector<ll> fact(MAXN), ifact(MAXN);
    fact[0] = 1;
    forr(i, 1, MAXN) fact[i] = fact[i - 1] * i % MOD;
    ifact[MAXN - 1] = expMod(fact[MAXN - 1], MOD - 2, MOD);
    dfor(i, MAXN - 1) ifact[i] = ifact[i + 1] * (i + 1) % MOD;

    string s; cin >> s;
    map<int, int> m;
    for(char c : s) m[c]++;

    ll ans = fact[sz(s)];
    for(auto i : m) ans = ans * ifact[i.sc] % MOD;

    cout << ans << '\n';


    return 0;
}