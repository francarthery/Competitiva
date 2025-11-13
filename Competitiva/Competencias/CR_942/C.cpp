#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define dbg(x) cout << '"' << x << '"' << '\n';

using namespace std;

typedef long long ll;

ll t, n, k;
vector<ll> v;

bool f(ll m){
    ll k2 = k;
    forn(i, n){
        if(v[i] < m){
            k2 -= m - v[i];
        }
        if(k2 < 0) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        v.resize(n);
        forn(i, n) cin >> v[i];

        ll l = 0, r = (ll)1e14, m;
        while(l < r){
            m = (l + r) / 2;
            if(f(m)) l = m + 1;
            else r = m;
            //dbg(m)
        }

        int ma = 0;
        forn(i, n){
            if(v[i] < r - 1){
                k -= (r - 1) - v[i];
            }
            else if(v[i] > r - 1) ma++;
        } 

        cout << (ll)n * (r - 1) - (n - 1) + ma + k << '\n';
    }

    return 0;
}