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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;;
    vector<ll> v1(n), v2(n);
    forn(i, n - 1) {
        cin >> v1[i];
        v2[n - 2 - i] = v1[i];
    }
    v1[n - 1] = v2[n - 1] = 2e9;

    const int K = 20; //log2(cant_elementos) + 1
    vector<vector<ll>> st(K, vector<ll>(n));
    vector<vector<ii>> bl(K, vector<ii>(n));

    auto f = [&](vector<ll> &v) { 
        st[0] = v;
        forn(i, K - 1) for(int j = 0; j + (1 << (i + 1)) < n; j++){
            st[i + 1][j] = max(st[i][j], st[i][j + (1 << (i))]);
        }

        vector<ii> st;
        st.pb({2e9, n - 1});
        dfor(i, n - 1) {
            while(sz(st) and st.back().fr < v[i]) st.pop_back();
            bl[0][i].fr = st.back().sc;
            bl[0][i].sc = v[i] * (st.back().sc - i);
            st.pb({v[i], i});
        }
        bl[0][n - 1] = {n - 1, v[n - 2]};

        forn(i, K - 1) forn(j, n){
            bl[i + 1][j] = {bl[i][bl[i][j].fr].fr, bl[i][j].sc + bl[i][bl[i][j].fr].sc};
        }
    };

    auto query = [&](int l, int r) {
        int i = __lg(r - l + 1);
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    };

    auto solve = [&](int l, int r, vector<ll> &v) {
        int ma = query(l, r);

        ll pos = l, sum = 0;
        dfor(i, K) {
            if(v[bl[i][pos].fr] <= ma){
                sum += bl[i][pos].sc;
                pos = bl[i][pos].fr;
            }
        }

        sum += bl[0][pos].sc;
        return sum;
    };

    int t; cin >> t;
    vector<ii> q(t);
    vector<ll> ans(t);
    forn(i, t) {
        cin >> q[i].fr >> q[i].sc;
        q[i].fr--; q[i].sc--;
    }

    f(v1);
    forn(i, t) if(q[i].fr > q[i].sc) ans[i] = solve(q[i].sc, q[i].fr - 1, v1);
    f(v2);
    forn(i, t) if(q[i].fr < q[i].sc) ans[i] = solve(n - 1 - q[i].sc, n - 2 - q[i].fr, v2);
    
    for(ll i : ans) cout << i << '\n';

    return 0;
}