#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

bool cmp (pair<ii, ll> &a, pair<ii, ll> &b){
    if(a.fr.fr != b.fr.fr) return a.fr.fr < b.fr.fr;
    else return a.fr.sc > b.fr.sc;
}

typedef ll tipo;
const tipo neutro = 0;
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

    int n; cin >> n;
    map<ii, ll> m;

    map<int, int> ma;
    vector<int> aux;
    forn(i, n){
        int a, b, c; cin >> a >> b >> c;
        aux.pb(b);
        ma[b]++;
        m[{a, b}]+= c;
    }

    sort(all(aux));
    aux.erase(unique(all(aux)), aux.end());
    
    forn(i, sz(aux)) ma[aux[i]] = i;
    vector<pair<ii, ll>> v(all(m));

    sort(all(v), cmp);

    ST st(n);
    st.updall();

    vector<ll> dp(n);
    forn(i, sz(v)){
        int b = v[i].fr.sc;
        ll val = v[i].sc;
        dp[i] = st.get(0, ma[b]) + val; 
        st.set(ma[b], dp[i]);
    }

    cout << *max_element(all(dp)) << '\n';



    
    return 0;
}