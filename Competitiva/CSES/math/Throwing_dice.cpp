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
typedef vector<vector<ll>> mat;

const int MOD = 1e9 + 7;

mat f(mat &a, mat &b) {
    int n = sz(a), m = sz(b[0]);
    mat res(n, vector<ll>(m));
    if(sz(a[0]) != sz(b)) return res;
    forn(i, n) forn(j, m) forn(k, sz(b)) res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;   
    return res;
}

mat expMod(mat b, ll e, ll m = MOD) {  // O(log e)
    mat ret(sz(b), vector<ll>(sz(b)));
    if (e < 0 or sz(b) != sz(b[0])) return ret; //Si no es cuadrada
    forn(i, sz(b)) ret[i][i] = 1;
    while (e) {
        if (e & 1) ret = f(ret, b);  // ret = mulMod(ret,b,m); //if needed
        b = f(b, b);                 // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n; cin >> n;
    mat exp(6, vector<ll>(6));
    mat base{{0}, {0}, {0}, {0}, {0}, {1}};
    forn(i, 5) exp[i][i + 1] = 1; // f(n) = f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)
    forn(i, 6) exp[5][i] = 1;

    mat prod = expMod(exp, n);
    mat res = f(prod, base);

    cout << res[5][0] << '\n';

    return 0;
}