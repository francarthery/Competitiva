#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=(a); i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<< "\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

typedef ll Elem;
typedef ll Alt;
const ll INF = 1000000000000;
const Elem neutro = INF;
const Alt neutro2 = 0;
Elem oper(const Elem& a, const Elem& b){ return min(a, b);}
struct ST{
    int sz;
    vector<Elem> t;
    vector<Alt> dirty;
    ST(int n){
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<Elem>(2 * sz, neutro);
        dirty = vector<Alt> (2 * sz, neutro2);
    }
    Elem& operator[](int p){ return t[sz + p];}
    void updall(){dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]);}
    void push(int n, int a, int b){
        if(dirty[n] != neutro2){
            t[n] += dirty[n]; //estaba bien esto?
            if(n < sz){
                dirty[2 * n] += dirty[n];
                dirty[2 * n + 1] += dirty[n];
            }
            dirty[n] = neutro2;
        }
    }
    Elem get(int i, int j, int n, int a, int b){
        if(j <= a || b <= i) return neutro;
        push(n, a, b);
        if(i <= a && b <= j) return t[n];
        int c = (a + b)/2;
        return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }
    Elem get(int i, int j){ return get(i, j, 1, 0, sz);}
    void update(Alt val, int i, int j, int n, int a, int b){
        push(n, a, b);
        if(j <= a || b <= i) return;
        if(i <= a and b <= j){
            dirty[n] += val;
            push(n, a, b);
            return;
        }
        int c = (a + b)/2;
        update(val, i, j, 2 * n, a, c), update(val, i, j, 2 * n  + 1, c, b);
        t[n] = oper(t[2 * n], t[2 * n + 1]);
    }
    void update(Alt val, int i, int j){ update(val, i, j, 1, 0, sz);}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w", stdout);
    #endif

    int n, k; cin >> n >> k;
    ST st(n);

    forn(i, n) cin >> st[i];

    st.updall();

    
    ll ans = 0;
    
    forn(i, n){
        st.update(-1, max(i - k + 1, 0), i);
        ll mi = st.get(i + 1, n);
        if(i - k >= 0) mi = min(mi, st.get(0, i - k + 1));
        mi = min(mi, st.get(max(0, i - k + 1), i + 1) + k);
        ans = max(ans, mi);
        if(i - k >= 0) st.update(k - 1, i - k, i - k + 1);
    }

    cout << ans << '\n';
}