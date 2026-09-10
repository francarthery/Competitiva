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

typedef long double ld;
typedef ld tipo;  // maybe use double or other depending on the problem
struct Mat {
  int N;  // square matrix
  vector<vector<tipo>> m;
  Mat(int n) : N(n), m(n, vector<tipo>(n, 0)) {}
  vector<tipo>& operator[](int p) { return m[p]; }
  Mat operator*(Mat& b) {  // O(N^3), multiplication
    assert(N == b.N);
    Mat res(N);
    forn(i, N) forn(j, N) forn(k, N)  // remove MOD if not needed
        res[i][j] = (res[i][j] + m[i][k] * b[k][j]);
    return res;
  }
  Mat operator^(int k) {  // O(N^3 * logk), exponentiation
    Mat res(N), aux = *this;
    forn(i, N) res[i][i] = 1;
    while (k)
      if (k & 1) res = res * aux, k--;
      else aux = aux * aux, k /= 2;
    return res;
  }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int k; cin >> k;
    Mat m(64);
    vector<ii> mov{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    forn(t, 64) {
        int i = t/8, j = t%8;
        int cwall = 4;
        if(i == 0 or i == 7) cwall--;
        if(j == 0 or j == 7) cwall--;
        forn(tt, 4) {
            int ni = i + mov[tt].first, nj = j + mov[tt].second;
            if(ni >= 0 and ni < 8 and nj >= 0 and nj < 8) m[t][ni*8+nj] = 1.0/cwall;
        } 
    }

    m = m^k;
    ld ans = 0;
    vector<vector<ld>> exp(8, vector<ld>(8, 1));
    forn(i, 8) forn(j, 8) {
        int p1 = i*8+j;
        forn(k, 8) forn(l, 8) {
            int p2 = k*8+l;
            exp[i][j] *= (1 - m[p2][p1]);
        }
        if(exp[i][j] < 1) ans += exp[i][j];
    }

    // forn(i, 8) vdbg(exp[i]);

    cout << fixed << setprecision(6) << ans << '\n';


    return 0;
}