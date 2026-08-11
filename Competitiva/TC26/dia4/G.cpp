#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<< " = " <<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


const int MOD = 3;

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

int Gauss(vector<vector<int>> a, vector<int> &ans){
  int n = a.size(), m = (int)a[0].size() - 1;
  vector <int> pos(m, -1);
  int free_var = 0;
  const long long MODSQ = (long long)MOD * MOD;
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
        int x = ((long long)a[i][col] * inv) % MOD;
        for (int j = col; j <= m && x; j++){
          if (a[row][j]) a[i][j] = (MODSQ + a[i][j] - ((long long)a[row][j] * x)) % MOD;
        }
      }
    }
    row++; ++rank;
  }
  ans.assign(m, 0);
  for (int i = 0; i < m; i++){
    if (pos[i] == -1) free_var++;
    else ans[i] = ((long long)a[pos[i]][m] * expMod(a[pos[i]][i], MOD - 2)) % MOD;
  }
  for (int i = 0; i < n; i++) {
    long long val = 0;
    for (int j = 0; j < m; j++) val = (val + ((long long)ans[j] * a[i][j])) % MOD;
    if (val != a[i][m]) return -1; //no solution
  }
  return free_var; //has solution
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w",stdout);
    #endif
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<ii>> g(n, vector<ii>(n));
        vector<vector<int>> a;
        forn(i, m) {
            int u, v, c; cin >> u >> v >> c; u--; v--;
            g[u][v] = g[v][u] = {c, i};
            if(c != -1) {
                a.push_back(vector<int>(m+1));
                a.back()[i] = 1;
                a.back().back() = c - 1;
            }
        }

        forn(i, n) forr(j, i+1, n) forr(k, j+1, n) {
            if(g[i][j].first and g[i][k].first and g[j][k].first) {
                a.push_back(vector<int>(m+1));
                a.back()[g[i][j].second] = a.back()[g[i][k].second] = a.back()[g[j][k].second] = 1;
            }
        }

        // forn(i, sz(a)) vdbg(a[i]);

        vector<int> ans;
        if(sz(a) and Gauss(a, ans) == -1) cout << -1 << '\n';
        else {
            if(!sz(a)) forn(i, m) cout << 1 << ' '; 
            else for(int i : ans) cout << i+1 << ' ';
            cout << '\n';
        }
        
    }
    

    return 0;
}