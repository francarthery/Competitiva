#include<bits/stdc++.h>

#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(a) ((int)(a.size()))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) <<endl;
#define vdbg(x) {cout <<"["; for(auto i:x){cout << i << ", "; cout << "]" <<endl; }}
#define ws <<' '<<
#define nl cout<<endl;
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b){
    return a + b;
}
struct ST{
    int sz;
    vector<tipo> t;
    ST(int n){
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo>(2 * sz, neutro);
    }
    tipo& operator[] (int p){ return t[sz + p];}
    void updall() {dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]);}
    tipo get(int i, int j) {return get(i, j, 1, 0, sz);}
    tipo get(int i, int j, int n, int a, int b){
        if(j <= a or b <= j) return neutro;
        if(i <= a and b <= j) return t[n];
        int c = (a + b)/2;
        return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }
    void set(int p, tipo val){
        p+= sz;
        while(p > 0 and t[p] != val){
            t[p] = val;
            p/=2;
            val = oper(t[p * 2], t[p * 2 + 1]);
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
    vector<ii> v(n);
    forn(i, n) cin >> v[i].first, v[i].second = i;

    vector<ll> dp(n);
    sort(all(v));
    reverse(all(v));

    
    cout << dp[0] << '\n';
    return 0;

}