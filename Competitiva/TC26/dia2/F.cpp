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

const int MOD = 1e6+3;

ll expMod(ll b, ll e, ll m = MOD) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % m;  // ret = mulMOD(ret,b,m); //if needed
        b = b * b % m;                 // b = mulMOD(b,b,m);
        e >>= 1;
    }
    return ret;
}

int Gauss(vector<vector<int>> a, vector<int> &ans){
  int n = a.size(), m = (int)a[0].size() - 1;
  vector <int> pos(m, -1);
  int free_var = 0;
  const ll MODSQ = (ll)MOD * MOD;
  int det = 1, rank = 0;
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int mx = row;
    for (int k = row; k < n; k++) if (a[k][col] > a[mx][col]) mx = k;
    if (a[mx][col] == 0) {det = 0; continue;}
    for (int j = col; j <= m; j++) swap(a[mx][j], a[row][j]);
    if (row != mx) det = det == 0 ? 0 : MOD - det;
    det = 1LL * det * a[row][col] % MOD;
    pos[col] = row;
    int inv = expMod(a[row][col], MOD - 2);
    for (int i = 0; i < n && inv; i++){
      if (i != row && a[i][col]) {
        int x = ((ll)a[i][col] * inv) % MOD;
        for (int j = col; j <= m && x; j++){
          if (a[row][j]) a[i][j] = (MODSQ + a[i][j] - ((ll)a[row][j] * x)) % MOD;
        }
      }
    }
    row++; ++rank;
  }
  ans.assign(m, 0);
  for (int i = 0; i < m; i++){
    if (pos[i] == -1) free_var++;
    else ans[i] = ((ll)a[pos[i]][m] * expMod(a[pos[i]][i], MOD - 2)) % MOD;
  }
  for (int i = 0; i < n; i++) {
    ll val = 0;
    for (int j = 0; j < m; j++) val = (val + ((ll)ans[j] * a[i][j])) % MOD;
    if (val != a[i][m]) return -1; //no solution
  }
  return free_var; //has solution
}

int main(){

    auto query = [&](ll x) {
        cout << "? " << x << endl;
        int ans; cin >> ans;
        return ans;
    };

    vector<int> ans(11);
    vector<vector<int>> a(11, vector<int>(12));
    forn(i, 11) {
        ll num = i;
        ll coef = 1;
        a[i][11] = query(num);
        forn(j, 11) {
            a[i][j] = coef;
            coef = coef * num % MOD;
        }
    }

    int out = Gauss(a, ans); //siempre tiene sol?

    auto check = [&](int num) {
        ll resp = 0, coef = 1;
        forn(i, 11) {   
            resp = (resp + coef * ans[i] % MOD) % MOD;
            coef = coef * num % MOD;
        }
        return resp;
    };

    forn(i, MOD+1) {
        if(!check(i)) {
            cout << "! " << i << endl;
            return 0;
        }
    }

    cout << "! " << -1 << endl;



    return 0;
}