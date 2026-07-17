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

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo &a, const tipo &b) {return max(a, b);}
struct ST {
    int sz; 
    vector<tipo> t;
    ST(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo> (2*sz, neutro);
    }
    tipo& operator[](int p) { return  t[sz + p];}
    void updall() {dfor(i, sz) t[i] = oper(t[2*i], t[2*i+1]);}
    tipo get(int i, int j) { return get(i, j, 1, 0, sz);}
    tipo get(int i, int j, int n, int a, int b) {
        if(j <= a || b <= i) return neutro;
        if(i <= a && b <= j) return t[n];
        int c = (a+b) / 2;
        return oper(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, tipo val){
        p += sz;
        while(p > 0 && t[p] != val) {
            t[p] = val;
            p /= 2;
            val = oper(t[p*2], t[p*2+1]);
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    ST st(1e5+1);
    vector<ll> r(n), k(n);
    forn(i, n) cin >> r[i];
    forn(i, n) cin >> k[i];

    ll time = 0;
    forn(i, n) {
        ll ma = st.get(0, r[i]+1);
        
        st.set(r[i], max(time, ma) + r[i] + k[i]);
        
        time = max(time, ma) + 1;
    }

    cout << st.get(0, 1e5+1) << '\n';



    return 0;
}