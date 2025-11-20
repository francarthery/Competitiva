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

    int n; cin >> n;
    vector<ll> v(n), ans(n, 1e9);
    forn(i, n) cin >> v[i];

    vector<ii> st;
    forn(i, n){
        while(sz(st) and st.back().fr < v[i]) st.pop_back();
        if(sz(st)) ans[i] = min(ans[i], i - st.back().sc);
        st.pb({v[i], i});
    }

    st.clear();
    dfor(i, n){
        while(sz(st) and st.back().fr < v[i]) st.pop_back();
        if(sz(st)) ans[i] = min(ans[i], st.back().sc - i);
        st.pb({v[i], i});
    }

    ll rta = 0, ma = *max_element(all(v));
    forn(i, n) if(v[i] != ma) rta += ans[i];

    cout << rta << '\n';


    return 0;
}