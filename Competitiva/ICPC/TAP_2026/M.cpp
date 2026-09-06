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

vector<ll> v, ps;

typedef ll Elem;
typedef ii Alt;
const Elem neutro = 0;
const Alt neutro2 = {2, 0};
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

            if(dirty[n].first == 0) t[n] = dirty[n].second * (b - a);
            else if(dirty[n].first == 1) t[n] = ps[b] - ps[a] + dirty[n].second * (b-a);
            else t[n] += dirty[n].second * (b-a);
            // t[n] += dirty[n] * (b - a);   // CHANGE for your problem
            if (n < sz) {
                if(dirty[n].first != 2) {
                    dirty[2*n] = dirty[n];
                    dirty[2*n+1] = dirty[n];
                }
                else {
                    dirty[2*n].second += dirty[n].second;
                    dirty[2*n+1].second += dirty[n].second;
                }
                // dirty[2 * n] += dirty[n];      // CHANGE for your problem
                // dirty[2 * n + 1] += dirty[n];  // CHANGE for your problem
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
            if(val.first != 2) dirty[n] = val;
            else dirty[n].second += val.second;    
            
            // dirty[n] += val;  // CHANGE for your problem
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

    int n, m; cin >> n >> m;
    v.resize(n);
    ps.resize(n+1);
    forn(i, n) cin >> v[i];
    forn(i, n) ps[i+1] = ps[i] + v[i];

    ST st(n);
    forn(i, m) {
        int tipo, a, b; cin >> tipo >> a >> b;
        if(tipo == 1) {
            a--;
            int l = -1, r = a+1;
            while(r-l>1) {
                int m = (r+l)/2;
                if(ps[a+1]-ps[m]-st.get(m, a+1) >= b) l = m;
                else r = m;
            }

            int sumo = 0;
            if(l != a) {
                sumo = ps[a+1] - ps[l+1] - st.get(l+1, a+1);
                st.update({1, 0}, l+1, a+1);
            }
            st.update({2, b-sumo}, l, l+1);
        }
        else {
            a--;
            cout << st.get(a, b) << '\n';
            st.update({0, 0}, a, b);
        }
        
        // forn(i, n) cout << st.get(i, i+1) << ' ';
        // cout << '\n';
    }


    return 0;
}