#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x <<" = "; for(auto e  : x ) cout<<e<< ' ';}cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

// https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
// special case of gauss_jordan_mod with mod=2, bitset for efficiency
// finds lexicograhically minimal solution (0 < 1, False < True)
// for lexicographically maximal change your solution model accordingly
const int INF = 1e9;
const int N = 5e5+1; //Cuidadooooo
int gauss(vector<bitset<N>> a, int n, int m, bitset<N>& ans) {
  vector<int> where(m, -1);
  for (int col = m - 1, row = 0; col >= 0 && row < n; --col) {
    for (int i = row; i < n; ++i)
      if (a[i][col]) {
        swap(a[i], a[row]);
        break;
      }
    if (!a[row][col]) continue;
    where[col] = row;

    for (int i = 0; i < n; ++i)
      if (i != row && a[i][col]) a[i] ^= a[row];
    ++row;
  }
  ans.reset();
  forn(i, m) if (where[i] != -1) { ans[i] = a[where[i]][m] & a[where[i]][i]; }
  forn(i, n) if ((ans & a[i]).count() % 2 != a[i][m]) return -1;
//   forn(i, m) if (where[i] == -1) return INF;

  int rango = 0;
  forn(i, n) {
    bool ok = false;
    forn(j, m) ok |= a[i][j];
    rango += ok;
  }
  return rango;
} 


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out","w", stdout);
    #endif

    int n; cin >> n;
    vector<ll> a(n), b(n);
    ll xa = 0;
    forn(i, n) {
        cin >> a[i] >> b[i];
        xa ^= a[i];
    }

    vector<bitset<N>> mat(63);
    forn(i, n) {
        forn(j, 63) mat[j][i] = (((a[i] ^ b[i]) >> j) & 1);
    }
    forn(j, 63) mat[j][n] = ((xa >> j) & 1);

    bitset<N> ans;
    int resp = gauss(mat, 63, n, ans);

    if(resp == -1) {
        cout << "1/1\n";
        return 0;
    }
    cout << (1ll << resp) - 1 << '/' << (1ll << resp) << '\n';

    return 0;
}