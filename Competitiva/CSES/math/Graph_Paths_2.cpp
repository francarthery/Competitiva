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

mat f(mat &a, mat &b) {
    int n = sz(a), m = sz(b[0]);
    mat res(n, vector<ll>(m, 2e18));
    if(sz(a[0]) != sz(b)) return res;
    forn(i, n) forn(j, m) forn(k, sz(b)) res[i][j] = min(res[i][j], a[i][k] + b[k][j]);   
    return res;
}

mat expMod(mat b, ll e) {  // O(log e)
    mat ret(sz(b), vector<ll>(sz(b), 2e18)); //Identidad especial para este caso
    if (e < 0 or sz(b) != sz(b[0])) return ret; //Si no es cuadrada
    forn(i, sz(b)) ret[i][i] = 0;
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

    int n, m, k; cin >> n >> m >> k;
    mat exp(n, vector<ll>(n, 2e18));
    ll a, b, c;

    forn(i, m){
        cin >> a >> b >> c; a--; b--;
        exp[a][b] = min(exp[a][b], c);
    }

    mat prod = expMod(exp, k);

    cout << (prod[0][n - 1] == 2e18 ? -1 : prod[0][n - 1]) << '\n';

    return 0;
}