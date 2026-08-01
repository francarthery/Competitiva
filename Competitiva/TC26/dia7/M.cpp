#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<__int128_t, __int128_t> ii;

typedef ii tipo;
const tipo neutro = ii(0, 0);
tipo oper(const tipo &a, const tipo&b) {return ii(a.first + b.first, a.second + b.second);}
struct ST{
    int sz;
    vector<tipo> t;
    ST(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo>(2*sz, neutro);
    }
    tipo &operator[](int p) {return t[sz+p];}
    void updall() { dfor(i, sz) t[i] = oper(t[2*i], t[2*i+1]);}
    tipo get(int i, int j) {return get(i, j, 1, 0, sz);}
    tipo get(int i, int j, int n, int a, int b) {
        if(j <= a || b <= i) return neutro;
        if(i <= a && b <= j) return t[n];
        int c = (a+b)/2;
        return oper(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, tipo val) {
        p += sz;
        while(p>0 && t[p] != val) {
            t[p] = val;
            p /= 2;
            val = oper(t[p*2], t[p*2+1]);
        }
    }
};

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> v(n);
    map<int, vector<int>> elems;
    set<ii> pend;
    ST st(n);

    forn(i, n) {
        cin >> v[i];
        elems[v[i]].push_back(i);
    }

    __int128_t ans = 0;
    for(auto i : elems) {
        while(sz(pend) and pend.begin() -> first < i.first - 1){
            st.set(pend.begin() -> second, {pend.begin() -> first, 1});
            pend.erase(pend.begin());
        }

        for(auto j : i.second){
            ii i1 = st.get(0, j);
            ii i2 = st.get(j+1, n); 
            ans += i.first * i1.second - i1.first;
            ans += i2.first - i.first * i2.second;
            pend.insert({i.first, j});
        }
    }

    vector<int> dig;
    if(ans < 0) {
        cout << '-';
        ans = -ans;
    }
    if(!ans) dig.push_back(0);
    while(ans) {
        // cout << (ll)ans << '\n';
        __int128_t d = ans % (__int128_t)10;
        dig.push_back(d);
        ans /= (__int128)10;
        
    }
    dfor(i, sz(dig)) cout << dig[i];
    cout << '\n';

    
    return 0;
}