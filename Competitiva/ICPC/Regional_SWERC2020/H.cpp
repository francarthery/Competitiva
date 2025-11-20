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

typedef int tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return a + b; }
struct ST {
    int n;
    vector<tipo> st;
    vector<int> L, R;
    ST(int nn) : n(nn), st(1, neutro), L(1, 0), R(1, 0) {}
    int new_node(tipo v, int l = 0, int r = 0) {
        int id = sz(st);
        st.pb(v), L.pb(l), R.pb(r);
        return id;
    }
    int init(vector<tipo>& v, int l, int r) {
        if (l + 1 == r) return new_node(v[l]);
        int m = (l + r) / 2, a = init(v, l, m), b = init(v, m, r);
        return new_node(oper(st[a], st[b]), a, b);
    }
    int update(int cur, int pos, tipo val, int l, int r) {
        int id = new_node(st[cur], L[cur], R[cur]);
        if (l + 1 == r) {
        st[id] = val;
        return id;
        }
        int m = (l + r) / 2, ASD;  // MUST USE THE ASD!!!
        if (pos < m) ASD = update(L[id], pos, val, l, m), L[id] = ASD;
        else ASD = update(R[id], pos, val, m, r), R[id] = ASD;
        st[id] = oper(st[L[id]], st[R[id]]);
        return id;
    }
    tipo get(int cur, int from, int to, int l, int r) {
        if (to <= l || r <= from) return neutro;
        if (from <= l && r <= to) return st[cur];
        int m = (l + r) / 2;
        return oper(get(L[cur], from, to, l, m), get(R[cur], from, to, m, r));
    }
    int init(vector<tipo>& v) { return init(v, 0, n); }
    int update(int root, int pos, tipo val) {
        return update(root, pos, val, 0, n);
    }
    tipo get(int root, int from, int to) { return get(root, from, to, 0, n); }
};  // usage: ST st(n); root = st.init(v) (or root = 0);
// new_root = st.update(root,i,x); st.get(root,l,r);


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    ST st(n);
    vector<int> v(n), days(n + 1); //days[i] tiene en que raiz mirar el dia i

    cin.ignore();

    string linea, s;
    int root = 0;

    forn(i, n){
        getline(cin, linea);
        stringstream ss(linea);

        while(ss >> s){
            if(s[0] == '+') root = st.update(root, stoi(s.substr(1)), 1);
            else root = st.update(root, stoi(s.substr(1)), 0);
        }
        days[i + 1] = root;
    }
    
    int res = 0, x;
    forn(i, n){
        cin >> x;
        res = (res + st.get(days[x], res, n)) % n; //cant de elementos mayores que res en el dia x
    }

    cout << res << '\n';


    return 0;
}