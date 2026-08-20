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

const int P = 1777771, MOD[2] = {999727999, 1070777777};
const int PI[2] = {325255434, 10018302};  // PI[i] = P^-1 % MOD[i]
struct Hash {
  vector<int> h[2], pi[2];
  vector<ll> vp[2];  // Only used if getChanged is used (delete it if not)
  Hash(string& s) {
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
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    string s, x, c; cin >> s;
    forn(i, m) {
        cin >> c;
        x += "#" + c;
    }

    s+=s;
    Hash hs(s), hx(x);

    int l = -1, r = n+1;
    while(r-l>1) {
        int m = (l+r)/2;
        unordered_set<ll> hashes;
        forn(i, sz(x)-m+1) hashes.insert(hx.get(i, i+m));
        
        bool ok = true;
        int cont = 0;
        forn(i, n-m+1) {
            cont += hashes.count(hs.get(i, i+m));
        }

        if(!cont) ok = false;

        forr(i, n-m+1, 2*n-m+1) {
            cont -= hashes.count(hs.get(i-n+m-1, i-n+2*m-1));
            cont += hashes.count(hs.get(i, i+m));
            if(!cont) ok = false;
        }

        if(ok) l = m;
        else r = m;
    }
    
    cout << l << '\n';

    return 0;
}