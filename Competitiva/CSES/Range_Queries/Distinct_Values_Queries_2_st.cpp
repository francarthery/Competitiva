#include <bits/stdc++.h>
#define forr(i, a, b) for(int i = a; i < b; i++)
#define forn(i, b) forr(i, 0, b)
#define dfor(i, b) for(int i = b-1; i >= 0; i--)
#define sz(a) ((int)(a.size()))
#define vdbg(v) {cout << '['; for(auto i : v) cout << i << ' '; cout << "]\n";}
#define dbg(x) cout << #x << " = " << x << '\n';

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

typedef ll tipo;
tipo neutro = 1e9;
tipo oper(const tipo &a, const tipo &b) { return min(a, b); }

struct ST {
    vector<tipo> t;
    int sz;
    ST(int N) {
        sz = (1 << ((__lg(N))+1));
        t.assign(2*sz, neutro);
    }
    tipo& operator[](int i) {return t[i+sz];}
    void updall() {dfor(i, sz) t[i] = oper(t[2*i], t[2*i+1]);}
    tipo get(int i, int j, int n, int a, int b) { //a, b rango actual, i, j rango de busqueda
        if(j <= a or b <= i) return neutro;
        if(a >= i and b <= j) return t[n];
        int c = (a+b)/2;
        return oper(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    tipo get(int i, int j) {return get(i, j, 1, 0, sz); }
    void set(int p, tipo val) {
        p += sz;
        while(p) {
            t[p] = val;
            p >>= 1;
            val = oper(t[2*p], t[2*p+1]);
        } 
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, q; cin >> n >> q;
    vector<int> v(n);
    map<int, set<int>> pos;
    ST st(n);
    forn(i, n) {
        cin >> v[i];
        if(sz(pos[v[i]])) st[*pos[v[i]].rbegin()] = i;        
        pos[v[i]].insert(i);
    }
    for(auto i : pos) st[*i.second.rbegin()] = 1e9;
    st.updall();

    forn(t, q) {
        int tipo; cin >> tipo;
        if(tipo == 1) {
            int k, u; cin >> k >> u; k--;
            auto it = pos[v[k]].find(k);
            if(it != pos[v[k]].begin()) {
                auto ant = prev(it);
                st.set(*ant, st[k]);
            }
            pos[v[k]].erase(k);
            v[k] = u;

            pos[u].insert(k);
            it = pos[u].find(k);
            if(it != --pos[u].end()) {
                auto sig = next(it);
                st.set(k, *sig);
            }
            else st.set(k, 1e9);

            if(it != pos[u].begin()) {
                auto ant = prev(it);
                st.set(*ant, k);
            }
        }
        else {
            int a, b; cin >> a >> b; a--;
            
            int ans = st.get(a, b);
            cout << (ans < b ? "NO" : "YES") << '\n';
        }
    }

    return 0;
}