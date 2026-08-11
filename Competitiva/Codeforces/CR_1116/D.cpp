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

    const int MOD = 998244353;
    const int MAXN = 2e6;
    vector<ll> fact(MAXN), ifact(MAXN);
    fact[0] = 1;
    forr(i, 1, MAXN) fact[i] = (fact[i-1] * i) % MOD;
    ifact[MAXN-1] = expMod(fact[MAXN-1], MOD-2, MOD);
    dfor(i, MAXN-1) ifact[i] = (ifact[i+1] * (i+1)) % MOD;

    auto comb = [&](int n, int k) -> ll {
        if(k < 0 or n < 0) return 1;
        return (fact[n] * ifact[k] % MOD) * ifact[n-k] % MOD; 
    };

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int inter0 = 0, inter1 = 0, c0 = 0, c1 = 0;
        char ant = '#';
        for(char c : s) {
            if(c == '0') {
                c0++;
                if(ant != c) inter0++;
            }
            else {
                c1++;
                if(ant != c) inter1++;
            }
            ant = c;
        }

        int stars1 = c1 - inter1, stars0 = c0 - inter0;
        ll ans = comb(inter1 + stars1 - 1, stars1);
        ans = ans * comb(inter0 + stars0 - 1, stars0) % MOD;

        cout << ans << '\n';
    }



    return 0;
}