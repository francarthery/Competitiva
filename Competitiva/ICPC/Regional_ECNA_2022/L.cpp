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

typedef ll td;
typedef vector<int> vi;
typedef vector<td> vd;
const ll INF = 1e18;
bool zz(td x) { return x == 0; }  // change to x==0, for ints/ll
struct Hungarian {
    int n;
    vector<vd> cs;
    vi L, R;
    Hungarian(int N, int M) : n(max(N, M)), cs(n, vd(n)), L(n), R(n) {
        forn(x, N) forn(y, M) cs[x][y] = INF;
    }
    void set(int x, int y, td c) { cs[x][y] = c; }
    td assign() {  // O(n^3)
        int mat = 0;
        vd ds(n), u(n), v(n);
        vi dad(n), sn(n);
        forn(i, n) u[i] = *min_element(cs[i].begin(), cs[i].end());
        forn(j, n) {
        v[j] = cs[0][j] - u[0];
        forr(i, 1, n) v[j] = min(v[j], cs[i][j] - u[i]);
        }
        L = R = vi(n, -1);
        forn(i, n) forn(j, n) if (R[j] == -1 && zz(cs[i][j] - u[i] - v[j])) {
        L[i] = j, R[j] = i, mat++;
        break;
        }
        for (; mat < n; mat++) {
        int s = 0, j = 0, i;
        while (L[s] != -1) s++;
        fill(dad.begin(), dad.end(), -1);
        fill(sn.begin(), sn.end(), 0);
        forn(k, n) ds[k] = cs[s][k] - u[s] - v[k];
        while (1) {
            j = -1;
            forn(k, n) if (!sn[k] && (j == -1 || ds[k] < ds[j])) j = k;
            sn[j] = 1, i = R[j];
            if (i == -1) break;
            forn(k, n) if (!sn[k]) {
            td new_ds = ds[j] + cs[i][k] - u[i] - v[k];
            if (ds[k] > new_ds) ds[k] = new_ds, dad[k] = j;
            }
        }
        forn(k, n) if (k != j && sn[k]) {
            td w = ds[k] - ds[j];
            v[k] += w, u[R[k]] -= w;
        }
        u[s] += ds[j];
        while (dad[j] >= 0) {
            int d = dad[j];
            R[j] = R[d], L[R[j]] = j, j = d;
        }
        R[j] = s, L[s] = j;
        }
        td ret = 0;
        forn(i, n) ret += cs[i][L[i]];
        return ret;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b; cin >> n >> m;
    Hungarian hg(m, n);
    vector<vector<ll>> g(n, vector<ll>(n)), prod(n, vector<ll>(m));
    
    forn(i, n) forn(j, m) cin >> prod[i][j];
    forn(i, n) forn(j, n) {
        cin >> a;
        g[i][j] = (a == -1 ? INF : a);
    }
    forn(i, n) g[i][i] = 0;

    forn(k, n) forn(i, n) if (g[i][k] != INF) forn(j, n) if (g[k][j] != INF)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    forn(i, n){
        forn(j, m) {
            ll cost = 0;
            forn(k, n) cost += g[k][i] * prod[k][j]; //costo de llevar el prod j desde k hasta i
            hg.set(j, i, cost);
        }
    }

    cout << hg.assign() << '\n';

    return 0;
}