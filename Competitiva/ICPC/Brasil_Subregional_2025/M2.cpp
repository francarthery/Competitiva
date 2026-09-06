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
typedef ll tipo;

struct RMQ {
    const int LVL = 18;
    // tipo vec[LVL][1 << (LVL+1)];
    vector<vector<ll>> vec;
    RMQ(int n) {
        vec.assign(LVL, vector<tipo>(1 << (LVL+1)));
    }

    tipo &operator[](int p) {return vec[0][p];}
    tipo get(int i, int j) {
        int p = 31 - __builtin_clz(j-i);
        return min(vec[p][i], vec[p][j - (1 << p)]);
    }
    void build(int n) {
        int mp = 31 - __builtin_clz(n);
        forn(p, mp) forn(x, n - (1 << p)) vec[p+1][x] =
            min(vec[p][x], vec[p][x+(1<<p)]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w", stdout);
    #endif

    int n, k; cin >> n >> k;
    RMQ orig(n), st(n);
    forn(i, n) {
        cin >> orig[i];
        st[i] = orig[i];
    }
    int cont = k;
    forn(i, n) st[i] += cont++;

    orig.build(n);
    st.build(n);

    ll ans = 0;
    forn(i, n) {
        ll izq = 1e10, centro = 1e10, der = 1e10;
        if(i-k>=0) izq = orig.get(0, i-k+1);
        centro = st.get(max(0, i-k+1), i+1) - i;
        if(i+1 < n) der = orig.get(i+1, n);
        // cout << izq << ' ' << centro << ' ' << der << '\n';
        ans = max(ans, min({izq, centro, der}));
    }

    cout << ans << '\n';

}