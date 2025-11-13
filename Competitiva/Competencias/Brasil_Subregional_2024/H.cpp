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
typedef tuple<int, int, int> iii;

const int INF = 1e9;
typedef ii tipo;
const tipo neutro = ii(0, 0);
tipo oper(const tipo& a, const tipo& b) { return max(a, b); }
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

    int n, k; cin >> n >> k;
    vector<iii> v(n);
    for(auto &[l, r, c] : v) cin >> l >> r >> c;
    sort(all(v));
    ST dp(n), dp2(n);

    int mayor = get<0>(v.back());

    dfor(i, n){
        auto &[l, r, c] = v[i];
        int pos = (upper_bound(all(v), iii(r, INF, INF)) - v.begin()); //abierto
        ii best = dp.get(i, pos);
        
        int uso = best.fr - c; //uso parte del intervalo. Miro la interseccion
        int sin = dp2.get(i, n + 1).fr - (mayor - l) * k; //no use al intervalo i. Tengo que mirar el mayor de todos
        if(i != n - 1 and get<0>(v[i + 1]) > get<1>(v[i])) uso = sin = -INF;
        int yo = (r - l + 1) * k - c - (mayor - l) * k + max(0, dp2.get(pos, n + 1).fr); //Use todo el intervalo. Miro el mejor de los que siguen

        dp.set(i, {max({uso, sin, yo}), l});
        dp2.set(i, {max({uso, sin, yo}) + (mayor - l) * k, l}); //cargo el valor original sin el desfase.
    }

    cout << dp2[0].fr << '\n';


    return 0;
}