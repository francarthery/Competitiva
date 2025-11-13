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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<vector<ll>> vvi;
const int MOD = 1e9 + 7;

typedef ll tipo;  // maybe use double or other depending on the problem
struct Mat {
    int N;  // square matrix
    vector<vector<tipo>> m;
    Mat(int n) : N(n), m(n, vector<tipo>(n, 0)) {}
    vector<tipo>& operator[](int p) { return m[p]; }
    Mat operator*(Mat& b) {  // O(N^3), multiplication
        assert(N == b.N);
        Mat res(N);
        forn(i, N) forn(j, N) forn(k, N)  // remove MOD if not needed
            res[i][j] = (res[i][j] + m[i][k] * b[k][j]) % MOD;
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

    int n, m, k, a, b;
    cin >> n >> m >> k;
    Mat v(n);
    forn(i, m) {
        cin >> a >> b; a--; b--;
        v[a][b] = 1;
    }

    Mat ans = v ^ k;
    ll cont = 0;
    forn(i, n) forn(j, n) cont = (cont + ans[i][j]) % MOD;
    
    cout << cont << '\n';
    
    return 0;
}