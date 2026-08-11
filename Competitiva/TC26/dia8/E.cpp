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
typedef pair<int,int>ii;

typedef ii tipo;
const tipo neutro = ii(-1, -1);
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
    tipo search(int i, int j, int obj) { return search(i, j, 1, 0, sz, obj); }
    tipo search(int i, int j, int n, int a, int b, int obj) {
        if (j <= a || b <= i) return neutro;
        if (t[n].first < obj) return neutro;  // n = node of range [a,b)
        if(b-a == 1) return t[n];

        int c = (a+b)/2;
        tipo ans = search(i, j, 2*n, a, c, obj);
        if(ans != neutro) return ans;
        return search(i, j, 2*n+1, c, b, obj);
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
        freopen("in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<array<int, 5>> ev; //ini, tipo, fin, tiempo, indice. 
    vector<int> times;
    int a, b, t, cont = 0;

    forn(i, n) {
        cin >> a >> b >> t;
        times.push_back(t);
        ev.push_back({a, 0, b, t, i});
    }
    forn(i, m) {
        cin >> a >> b >> t;
        times.push_back(t);
        ev.push_back({a, 1, b, t, i});
    }

    sort(all(times));
    times.erase(unique(all(times)), times.end());

    sort(all(ev), [&](auto &a, auto &b){
        if(a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    });
    ST st(sz(times));
    vector<int> ans(m);

    forn(i, sz(ev)) {
        auto [l, tipo, r, t, ind] = ev[i];
        t = lower_bound(all(times), t) - times.begin();
        if(!tipo) {
            ii elem = {r, ind};
            if(st[t] < elem) st.set(t, elem);
        }
        else {
            ii resp = st.search(t, sz(times), r);
            if(resp == neutro) ans[ind] = -1;
            else ans[ind] = resp.second+1;
        }
    }

    for(int i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}
