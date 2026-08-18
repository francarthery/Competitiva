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

struct comp {
    vector<int> frec;
    ll inv;
};

typedef comp tipo;
const tipo neutro = comp{vector<int>(41), 0};

tipo oper(const tipo& a, const tipo& b) { 
    tipo res = neutro;
    forn(i, 41) {
        res.frec[i] = a.frec[i] + b.frec[i];
        if(res.frec[i]) res.inv++;
    }
    return res;
}
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
        while (p > 0) {
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

    int n, q; cin >> n >> q;
    ST st(n);
    forn(i, n) {
        int x; cin >> x;
        st[i].frec[x]++;
    }
    st.updall();

    forn(tt, q) {
        int t, a, b; cin >> t >> a >> b; a--;
        if(t == 1) cout << st.get(a, b).inv << '\n';
        else {
            tipo val = neutro;
            val.frec[b]++;
            st.set(a, val);
        }
    }

    return 0;
}