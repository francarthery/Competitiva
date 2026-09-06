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

// P should be a prime number, could be randomly generated,
// sometimes is good to make it close to alphabet size
// MOD[i] must be a prime of this order, could be randomly generated
const int P = 1777771, MOD1[2] = {999727999, 1070777777};
const int MOD2[2] = {1000000007, 998244353};
const int PI1[2] = {325255434, 10018302};  // PI[i] = P^-1 % MOD[i]
const int PI2[2] = {420604794, 333787294};
struct Hash {
  vector<int> h[2], pi[2];
  vector<ll> vp[2];  // Only used if getChanged is used (delete it if not)
  int PI[2];
  int MOD[2];
  Hash(string& s, const int p[2], const int m[2]) {
    forn(i, 2) PI[i] = p[i];
    forn(i, 2) MOD[i] = m[i];
    forn(k, 2) h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1),
        vp[k].resize(s.size() + 1);
    forn(k, 2) {
      h[k][0] = 0;
      vp[k][0] = pi[k][0] = 1;
      ll p = 1;
      forr(i, 1, sz(s) + 1) {
        h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
        pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
        vp[k][i] = p = (p * P) % MOD[k];
      }
    }
  }
  ll get(int s, int e) {  // get hash value of the substring [s, e)
    ll H[2];
    forn(i, 2) {
      H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
      H[i] = (1LL * H[i] * pi[i][s]) % MOD[i];
    }
    return (H[0] << 32) | H[1];
  }
  // get hash value of [s, e) if origVal in pos is changed to val
  // Assumes s <= pos < e. If multiple changes are needed,
  // do what is done in the for loop for every change
  ll getChanged(int s, int e, int pos, int val, int origVal) {
    ll hv = get(s, e), hh[2];
    hh[1] = hv & ((1LL << 32) - 1);
    hh[0] = hv >> 32;
    forn(i, 2) hh[i] = (hh[i] + vp[i][pos] * (val - origVal + MOD[i])) % MOD[i];
    return (hh[0] << 32) | hh[1];
  }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    string s; cin >> s;
    Hash hs1(s, PI1, MOD1);
    Hash hs2(s, PI2, MOD2);

    int r, m; cin >> r >> m;
    vector<string> v(r);
    forn(i, n) cin >> v[i];

    map<ii, int> f; //cuidado con el TLE
    forn(i, n-m+1) f[{hs1.get(i, i+m), hs2.get(i, i+m)}]++;

    ll cont = 0;
    vector<char> pos{'_', '.', ','};
    forn(i, 26) pos.push_back('a'+i);
    forn(i, r) {
        Hash hi1(v[i], PI1, MOD1), hi2(v[i], PI2, MOD2);
        cont += f[{hi1.get(0, m), hi2.get(0, m)}]; //no cambio nada
        forn(j, m){
            forn(k, sz(pos)) if(pos[k] != v[i][j]) {
                cont += f[{hi1.getChanged(0, m, j, pos[k], v[i][j]), hi2.getChanged(0, m, j, pos[k], v[i][j])}]; //si o si cambio algo
            }
        }   
    }
    
    cout << cont << '\n';

    return 0;
}