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

const ll MOD = 1e15 + 1;  // Change according to problem
// Only needed for MOD > 2^31
// Actually, for 2^31 < MOD < 2^63 it's usually better to use __int128
// and normal multiplication (* operator) instead of mulMod
// returns (a*b) %c, and minimize overfloor
ll mulMod(ll a, ll b, ll m = MOD) {  // O(log b)
  ll x = 0, y = a % m;
  while (b > 0) {
    if (b % 2 == 1) x = (x + y) % m;
    y = (y * 2) % m;
    b /= 2;
  }
  return x % m;
}
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

bool es_primo_prob(ll n, int a) {
  if (n == a) return true;
  ll s = 0, d = n - 1;
  while (d % 2 == 0) s++, d /= 2;
  ll x = expMod(a, d, n);
  if ((x == 1) || (x + 1 == n)) return true;
  forn(i, s - 1) {
    x = (x * x) % n; // mulMod(x, x, n); In most cases, it is necessary to use mulMod to avoid TLE
    if (x == 1) return false;
    if (x + 1 == n) return true;
  }
  return false;
}
bool rabin(ll n) {  // devuelve true si n es primo
  if (n == 1) return false;
  const int ar[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  forn(j, 9) if (!es_primo_prob(n, ar[j])) return false;
  return true;
}
ll rho(ll n) {
  if ((n & 1) == 0) return 2;
  ll x = 2, y = 2, d = 1;
  ll c = rand() % n + 1;
  while (d == 1) {
    // may want to avoid mulMod if possible
    // maybe replace with * operator using __int128?
    x = (mulMod(x, x, n) + c) % n;
    y = (mulMod(y, y, n) + c) % n;
    y = (mulMod(y, y, n) + c) % n;
    if (x - y >= 0) d = gcd(n, x - y);
    else d = gcd(n, y - x);
  }
  return d == n ? rho(n) : d;
}
void factRho(ll n, map<ll, ll>& f) {  // O ((n ^ 1/4) * logn)
  if (n == 1) return;
  if (rabin(n)) {
    f[n]++;
    return;
  }
  ll factor = rho(n);
  factRho(factor, f);
  factRho(n / factor, f);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int a, b, c, m, n, k; cin >> m >> n >> k;
    vector<ll> v(n);
    forn(i, n) cin >> v[i];

    vector<vector<ii>> g(n + m);
    forn(i, k){
        cin >> a >> b >> c; a--; b--;
        g[a].pb({b + m, c});
        g[b + m].pb({a, c});
    }

    forn(i, n + m) sort(all(g[i]));

    vector<ll> ans(m);
    forn(i, n){
        if(sz(g[i + m]) == 1) ans[g[i + m].back().fr] = powl(v[i], (long double)1 / g[i + m].back().sc);
        else{
            map<ll, ll> f;
            factRho(v[i], f);
            auto it = f.begin();
            for(ii &u : g[i + m]){
                assert(it != f.end());
                ans[u.fr] = it -> fr;
                it++;

                //for(ii k : g[u.fr]) v[k.fr] /= 
            }
        }
    }

    for(int i : ans) cout << i << ' ';

    return 0;
}