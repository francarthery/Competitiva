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

typedef ii tipo;
const int INF = 1e9;
const tipo neutro = ii(INF, INF);
tipo oper(const tipo& a, const tipo& b) { return min(a, b); }
struct ST {
    int sz;
    vector<tipo> t;
    ST(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo>(2 * sz, neutro);
    }
    tipo& operator[](int p) { return t[sz + p]; }
    void updall() { dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
    tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
    tipo get(int i, int j, int n, int a, int b) {  // O(log n), [i, j)
        if (j <= a || b <= i) return neutro;
        if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
        int c = (a + b) / 2;
        return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }
    void set(int p, tipo val) {  // O(log n)
        p += sz;
        while (p > 0 && t[p] != val) {
            t[p] = val;
            p /= 2;
            val = oper(t[p * 2], t[p * 2 + 1]);
        }
    }
};  // Use: definir oper tipo neutro,
// cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<bool> pase(n);
    ST gr(n);
    string s;

    forn(i, n) gr[i] = {0, i};
    forn(i, n - 1){
        cin >> s;
        forn(j, i + 1) {
            if(s[j] == '1') {
                gr[j].fr++; //st de grados entrantes de nodos
                g[i + 1].pb(j);
                g[j].pb(i + 1);
            }
            else {
                g[j].pb(i + 1);
                g[i + 1].pb(j);
                gr[i + 1].fr++;
            }
        }
    }
    gr.updall();
    //forn(i, n) vdbg(g[i]);

    ll k = 0, ma = 0;
    forn(i, n){
        ii mi = gr.get(0, n);
        k += mi.fr;
        ma = max(ma, k);
        //dbg(mi.sc);

        for(int u : g[mi.sc]) {
            gr.set(u, {gr[u].fr - 1, u}); //bajo los grados de los que quedan
        }

        gr.set(mi.sc, {INF, mi.sc});
        pase[mi.sc] = 1;
    }

    cout << ma << '\n';

    return 0;
}