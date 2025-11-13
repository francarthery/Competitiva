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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n"};
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

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

    int l, r, n, m; cin >> n >> m;
    vector<iii> v;
    vector<int> rta(m);
    unordered_set<int> ev;

    forn(i, n){ // 0 entra mesa, 1 sale mesa, 2 entra mozo, 3 sale mozo
        cin >> l >> r;
        v.pb({l, 0, -1});
        v.pb({r, 1, -1});
        ev.insert(l);
        ev.insert(r);
    }

    forn(i, m){ // 0 entra mesa, 1 sale mesa, 2 entra mozo, 3 sale mozo
        cin >> l >> r;
        v.pb({l, 2, i});
        v.pb({r, 3, i});
        ev.insert(l);
        ev.insert(r);
    }

    ST st(2 * sz(ev) + 1); // cantidad maxima de eventos
    sort(all(v));
    int cont = 0, mozos = 0, mesas = 0, temp_mesas = 0;
    unordered_map<int, int> mozo; // por cada mozo laburando guardo evento de inicio
    vector<int> cierran;

    forn(i, 2 * (n + m)){
        int ini = get<0>(v[i]), tipo = get<1>(v[i]), moz = get<2>(v[i]);

        if(moz == -1){
            if(tipo == 0) mesas++;
            else temp_mesas--;
        }
        else{
            if(tipo == 2) {
                mozos++;
                mozo[moz] = cont;
            }
            else cierran.pb(moz);      
        }

        if(i == (2 * (n + m) -1) or ini != get<0>(v[i + 1])){
            if(mozos > 0) st.set(cont, (mesas + mozos - 1) / mozos);
            forn(j, sz(cierran)){
                rta[cierran[j]] = st.get(mozo[cierran[j]], cont + 1);
                mozos--;
            }
            mesas += temp_mesas;
            temp_mesas = 0;
            cierran.clear();
            cont++;

            if(!ev.count(ini + 1) and mozos > 0) {
                st.set(cont, (mesas + mozos - 1) / mozos);
                cont++;
            }
        }
        
    }

    forn(i, m) cout << rta[i] << ' ';
    cout << '\n';



    return 0;
}