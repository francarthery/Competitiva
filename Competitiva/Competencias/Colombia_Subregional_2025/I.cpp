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
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> v(n);
        forn(i, n) cin >> v[i];
        sort(all(v));

        ll l = -2e9 - 1, r = 2e9 + 1; //cambiarrrr
        while(r - l > 1){
            ll m = (r + l) / 2; //maxima suma
            ll cant = 0;
            forn(i, n){
                int fin = upper_bound(all(v), m - v[i]) - v.begin();
                cant += fin;
            }
            if(cant >= k) r = m;
            else l = m; 
        }

        cout << r << '\n';
    }



    return 0;
}