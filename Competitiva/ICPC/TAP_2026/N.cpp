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

const int MOD = 998244353;
const int MAXN = 1e6+1;
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

ll fact[MAXN], ifact[MAXN];
void build_facts() {  // O(MAXN)
  fact[0] = 1;
  forr(i, 1, MAXN) fact[i] = fact[i - 1] * i % MOD;
  ifact[MAXN - 1] = expMod(fact[MAXN-1], MOD-2, MOD);
  dfor(i, MAXN - 1) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
  return;
}

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

    build_facts();
    int n, k, a; cin >> n >> k >> a;
    
    if(n == 1 and k == 0) {
        cout << a << '\n';
        return 0;
    }
    
    if(k >= n-1) {
        cout << 0 << '\n'; 
        return 0; 
    }
    
    int n1 = (n+1)/2;
    int n2 = n/2;

    ll ans = 0;
    forn(i, k+1) {
        int k1 = i, k2 = (k-i);
        if(k1 >= n1 or k2 >= n2) continue; 
        ll sumo = a;
        sumo = sumo * expMod(a-1, n1-k1-1, MOD) % MOD;
        sumo = sumo * comb(n1 - 1, k1) % MOD;

        sumo = sumo * a % MOD;
        sumo = sumo * expMod(a-1, n2-k2-1, MOD) % MOD;
        sumo = sumo * comb(n2 - 1, k2) % MOD;

        ans = (ans + sumo) % MOD;
    }

    cout << ans << '\n';

    return 0;
}