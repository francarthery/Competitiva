#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
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

    ll t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> v(n);
        forn(i, n) cin >> v[i];
        sort(all(v));
        ll rta = 0, costo = 0, l = 0, r = 0;

        while(r < n){
            if(r < n and v[r] - v[l] < 2 and costo <= m){
                costo += v[r++];
                if(costo <= m) rta = max(rta, costo);
            }

            if(l <= r and (v[r] - v[l] > 1 or costo > m)) costo -= v[l++];
            if(costo <= m) rta = max(rta, costo);
            
            if(l > r) break;
        }

        cout << rta << '\n';
    }
    
    return 0;
}