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

const int MOD = 998244353;
const int MAXN = 1e6 + 1;
#define MAXMOD 15485867
ll inv[MAXMOD];     // inv[i]*i=1 mod MOD
void calc(int p) {  // O(p)
  inv[1] = 1;
  forr(i, 2, p) inv[i] = p - ((p / i) * inv[p % i]) % p;
}
int inverso(int x) {                    // O(log MOD)
  return expMod(x, MOD - 2, MOD);            // si mod es primo
}

// fact[i] = i!%MOD and ifact[i] = 1/(i!)%MOD
// inv is modular inverse function
ll fact[MAXN], ifact[MAXN];
void build_facts() {  // O(MAXN)
  fact[0] = 1;
  forr(i, 1, MAXN) fact[i] = fact[i - 1] * i % MOD;
  ifact[MAXN - 1] = inverso(fact[MAXN - 1]);
  dfor(i, MAXN - 1) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
  return;
}
// n! / k!*(n-k)!
// assumes 0 <= n < MAXN
ll comb(ll n, ll k) {
  if (k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    build_facts();

    while(t--){
        ll n; cin >> n;
        vector<ll> v(n);
        ll wild; cin >> wild;
        ll sum = wild;
        forn(i, n) {
            cin >> v[i];
            sum += v[i];
        }

        int s = sum / n, r = sum % n;
        int need = 0;
        bool flag = false;

        forn(i, n){
            if(v[i] > s + 1) flag = true;
            else if(v[i] == s + 1) need++;
        }

        if(flag or need > r) {
            cout << 0 << '\n';
            continue;
        }

        ll ans = (fact[r] * fact[n - r] % MOD) * comb(n - need, r - need) % MOD;          
        cout << ans << '\n';        
    }



    return 0;
}