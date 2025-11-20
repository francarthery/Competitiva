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
typedef pair<ll, ll> ii;

const int MOD = 1e9 + 7;

ll expMod(ll b, ll e, ll m = MOD) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
        b = b * b % m;                 // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

typedef ll Elem;
typedef ii Alt;
const Elem neutro = 0;
const Alt neutro2 = ii(1, 0);
Elem oper(const Elem& a, const Elem& b) { return a + b; }
struct ST {
    int sz;
    vector<Elem> t;
    vector<Alt> dirty;  // Alt and Elem could be different types
    ST(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<Elem>(2 * sz, neutro);
        dirty = vector<Alt>(2 * sz, neutro2);
    }
    Elem& operator[](int p) { return t[sz + p]; }
    void updall() { dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
    void push(int n, int a, int b) {  // push dirt to n's child nodes
        if (dirty[n] != neutro2) {      // n = node of range [a,b)
        t[n] = (t[n] * dirty[n].fr % MOD + dirty[n].sc * (ll)(b - a)) % MOD;   // CHANGE for your problem
        if (n < sz) {
            dirty[2 * n] = {dirty[2 * n].fr * dirty[n].fr % MOD, (dirty[2 * n].sc * dirty[n].fr % MOD + dirty[n].sc) % MOD};      // CHANGE for your problem
            dirty[2 * n + 1] = {dirty[2 * n + 1].fr * dirty[n].fr % MOD, (dirty[2 * n + 1].sc * dirty[n].fr % MOD + dirty[n].sc) % MOD};  // CHANGE for your problem
        }
        dirty[n] = neutro2;
        }
    }
    Elem get(int i, int j, int n, int a, int b) {  // O(lgn)
        if (j <= a || b <= i) return neutro;
        push(n, a, b);                      // adjust value before using it
        if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
        int c = (a + b) / 2;
        return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }
    Elem get(int i, int j) { return get(i, j, 1, 0, sz); }
    // altera los valores en [i, j) con una alteracion de val
    void update(Alt val, int i, int j, int n, int a, int b) {  // O(lgn)
        push(n, a, b);
        if (j <= a || b <= i) return;
        if (i <= a && b <= j) {
        dirty[n] = {dirty[n].fr * val.fr % MOD, (dirty[n].sc * val.fr % MOD + val.sc) % MOD};  // CHANGE for your problem
        push(n, a, b);
        return;
        }
        int c = (a + b) / 2;
        update(val, i, j, 2 * n, a, c), update(val, i, j, 2 * n + 1, c, b);
        t[n] = oper(t[2 * n], t[2 * n + 1]);
    }
    void update(Alt val, int i, int j) { update(val, i, j, 1, 0, sz); }
};  // Use: definir operacion, neutros, Alt, Elem, uso de dirty
// cin >> n; ST st(n); forn(i,n) cin >> st[i]; st.updall()


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int q, ind = 0; cin >> q;
    ST st(q);
    map<int, int> oper;
    forn(i, q){
        ll n, a, b; cin >> n;
        
        if(n == 1) {
            cin >> a;
            st.update(ii(1, a), ind, ind + 1);
            oper[i] = ind;
            ind++;
        }
        else if(n == 2){
            cin >> a;
            st.update(ii(1, a), 0, ind);
        }
        else if(n == 3){
            cin >> a >> b;
            st.update(ii(a * expMod(b, MOD - 2) % MOD, 0), 0, ind);
        }
        else {
            cin >> a; a--;
            cout << st.get(oper[a], oper[a] + 1) << '\n';
        }
    }

    return 0;
}