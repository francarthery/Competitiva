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
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, x = 1;
    cin >> t;
    vector<ll> cuad, cub;
    vector<ll> v;
    while(x * x < 1e9 + 5) {
        v.pb(x * x);
        x++;
    }
    x = 1;
    while(x * x * x < 1e9 + 5) {
        v.pb(x * x * x);
        x++;
    }
    sort(all(v));
    auto it = unique(all(v));

    while(t--){
        int n;
        cin >> n;
        auto pos = lower_bound(v.begin(), it, n);
        if(*pos == n) pos++;
        cout << pos - v.begin() << '\n';
    }
    
    return 0;
}