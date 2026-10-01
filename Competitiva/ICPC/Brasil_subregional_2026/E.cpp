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

struct HopcroftKarp {  
  int n, m;
  vector<vector<int>> g;
  vector<int> mt, mt2, ds;
  HopcroftKarp(int nn, int mm) : n(nn), m(mm), g(n) {}
  void add(int a, int b) { g[a].pb(b); }
  bool bfs() {
    queue<int> q;
    ds = vector<int>(n, -1);
    forn(i, n) if (mt2[i] < 0) ds[i] = 0, q.push(i);
    bool r = false;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : g[x]) {
        if (mt[y] >= 0 && ds[mt[y]] < 0) {
          ds[mt[y]] = ds[x] + 1, q.push(mt[y]);
        } else if (mt[y] < 0) r = true;
      }
    }
    return r;
  }
  bool dfs(int x) {
    for (int y : g[x]) {
      if (mt[y] < 0 || ds[mt[y]] == ds[x] + 1 && dfs(mt[y])) {
        mt[y] = x, mt2[x] = y;
        return true;
      }
    }
    ds[x] = 1 << 30;
    return false;
  }
  int mm() {  
    int r = 0;
    mt = vector<int>(m, -1);
    mt2 = vector<int>(n, -1);
    while (bfs()) forn(i, n) if (mt2[i] < 0) r += dfs(i);
    return r;
  }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m1, m2; cin >> n >> m1 >> m2;
    if(m1 != m2) {
        cout << -1 << '\n';
        return 0;
    }
    // cout << "pasa\n";
    HopcroftKarp hk(n*n, n*n);

    vector<vector<int>> g1(n, vector<int>(n)), g2(n, vector<int>(n));
    int a, b;
    forn(i, m1) {
        cin >> a >> b; a--; b--;
        g1[b][a] = 1;
        g1[a][b] = 1;
    }

    forn(i, m2) {
        cin >> a >> b; a--; b--;
        if(a > b) swap(a, b);
        g2[a][b] = 1;
    }

    int cant2 = m1;
    forn(i, n) forn(j, n) {
        if(g1[i][j] and g2[i][j]) {
            cant2--;
            g1[i][j] = g1[j][i] = g2[i][j] = g2[j][i] = 0; //saque esas aristas
        }
    }
    // forn(i, n) vdbg(g1[i]);
    // forn(i, n) vdbg(g2[i]);

    forn(i, n) forn(j, n) {
        if(g2[i][j]) {
            forn(k, n) if(g1[i][k]) hk.add(min(i,k)*n+max(i,k), i*n+j)/* , cout << i*n+k << ' ' << i*n+j << '\n' */;
            forn(k, n) if(g1[j][k]) hk.add(min(i,j)*n+max(j,k), i*n+j)/* , cout << k*n+j << ' ' << i*n+j << '\n' */;
        }
    }

    int ans = hk.mm();
    // dbg(ans);
    cout << ans + (cant2 - ans) * 2 << '\n';

    return 0;
}