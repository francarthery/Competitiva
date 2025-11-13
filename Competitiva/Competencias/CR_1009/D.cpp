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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second
#define sq(a) ((a) * (a))

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll f(ll x, ll ra, ll xi){
    ll l = -1, r = ra + 1;
    while(r - l > 1){
        ll m = (l + r) / 2;
        if(sq(xi - x) + sq(m) <= sq(ra)) l = m;
        else r = m;
    }

    return l;
}
    
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
        ll n, m;
        cin >> n >> m;
        vector<ii> v(n);

        forn(i, n) cin >> v[i].fr;
        forn(i, n) cin >> v[i].sc;
        map<ll, ll> ma;

        forn(i, n) {
            forr(j, v[i].fr - v[i].sc, v[i].fr + v[i].sc + 1)
                ma[j] = max(ma[j], f(v[i].fr, v[i].sc, j));
        }

        ll sum = 0;
        for(auto i: ma) sum += 2 * i.sc;
        cout << sum + (ll)sz(ma) << '\n'; 
    }


    return 0;
}