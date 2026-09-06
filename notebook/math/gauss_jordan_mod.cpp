//a es de n*(m+1). En la columna m van los valores de los terminos independientes
int Gauss(vector<vector<int>> a, vector<int> &ans){
  int n = sz(a), m = sz(a[0]) - 1;
  vector<int> pos(m, -1);
  int free_var = 0;
  const ll MODSQ = (ll)MOD * MOD;
  int det = 1, rank = 0;
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int mx = row;
    forr(k, row, n) if (a[k][col] > a[mx][col]) mx = k;
    if (a[mx][col] == 0) {det = 0; continue;}
    forr(j, col, m+1) swap(a[mx][j], a[row][j]);
    if (row != mx) det = det == 0 ? 0 : MOD - det;
    det = 1LL * det * a[row][col] % MOD;
    pos[col] = row;
    int inv = expMod(a[row][col], MOD - 2, MOD);
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
  forn(i, m) {
    if (pos[i] == -1) free_var++;
    else ans[i] = ((ll)a[pos[i]][m] * expMod(a[pos[i]][i], MOD - 2, MOD)) % MOD;
  }
  forn(i, n) {
    ll val = 0;
    forn(j, m) val = (val + ((ll)ans[j] * a[i][j])) % MOD;
    if (val != a[i][m]) return -1; //no solution
  }
  return free_var; //has solution
}
