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

    string s, comp; cin >> s;
    int n = sz(s);
    map<char, char> inv{{'A', 'T'}, {'T', 'A'}, {'G', 'C'}, {'C', 'G'}};
    for(char c : s) comp += inv[c];
    reverse(all(comp));
    Hash hs(s), hcomp(comp);

    int l = -1, r = n + 1, tam = 0, ini;
    while(r-l>1){
        int m = (l+r)/2;
        bool ok = false;
        vector<ll> hashes;
        forn(i, n-m+1) hashes.pb(hs.get(i, i+m));
        sort(all(hashes));
        forn(i, n-m+1) if(binary_search(all(hashes), hcomp.get(i, i+m))) {
            ok = true;
            if(m > tam) {
                tam = m;
                ini = i;
            }
            break;
        }

        if(ok) l = m;
        else r = m;
    }

    cout << tam << '\n';
    if(tam) cout << comp.substr(ini, tam) << '\n';

    return 0;
}