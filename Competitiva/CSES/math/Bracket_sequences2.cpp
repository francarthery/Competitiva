#include <bits/stdc++.h>
#define forr(i, a, n) for(ll i = a; i < n; i++)
#define forn(i, n) for(ll i = 0; i < n; i++)
#define dfor(i, n) for(ll i = n - 1; i >= 0; i--)
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

const int MOD = 1e9+7;
const int MAXN = 1e6 + 1;
ll fact[MAXN], ifact[MAXN];

ll expMod(ll b, ll e, ll m){
    if(e < 0) return 0;
    ll r = 1;
    while(e) {
        if(e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    fact[0] = 1;
    forr(i, 1, MAXN) fact[i] = fact[i - 1] * i % MOD;
    ifact[MAXN - 1] = expMod(fact[MAXN - 1], MOD - 2, MOD);
    dfor(i, MAXN - 1) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    
    auto ncr = [&](int n, int r) {
        return (fact[n] * ifact[r] % MOD) * ifact[n - r] % MOD;
    };

    int n;
    string s;
    cin >> n >> s;
    int sum = 0;
    int k = n - sz(s);
    for(char c : s) {
        if(c == '(') sum++;
        else sum--;
        if(sum < 0) sum = -1e9;
    }
    if(n % 2 or sum < 0 or sum > k) {
        cout << 0 << '\n';
        return 0;
    }
    
    // Cantidad total: tengo k posiciones y (k - sum) / 2 parentesis que abren.
    // Cantidad invalidas: tengo k posiciones y si reflejo en el primer prefijo invalido donde tengo
    // sum + 1 mas cierres que aperturas, me quedan en total (k - sum) / 2 + sum + 1 parentesis que abren.
    cout << (ncr(k, (k - sum) / 2) - ncr(k, (k - sum) / 2 + sum + 1) + MOD) % MOD << '\n';
    
    return 0;
}