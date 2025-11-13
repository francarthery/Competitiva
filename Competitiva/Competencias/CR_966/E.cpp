#include <bits/stdc++.h>
#define forr(i, a, n) for(ll i = a; i < n; i++)
#define forn(i, n) for(ll i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        ll n, m, k, w, x, y, rta = 0;
        cin >> n >> m >> k >> w;
        vector<ll> v(w), fac;
        forn(i, w) cin >> v[i];
        
        forn(i, n){
            forn(j, m){
                x = min(k - 1, j - 0) + min(k - 1, m - 1 - j) + 2 - k;
                y = min(k - 1, i - 0) + min(k - 1, n - 1 - i) + 2 - k;
                fac.pb(x * y);
            }
        }
        sort(rall(fac));
        sort(rall(v));
        forn(i, min(sz(fac), sz(v))){
            rta += fac[i] * v[i];
        }
        
        cout << rta << '\n';
    }
    
    return 0;
}