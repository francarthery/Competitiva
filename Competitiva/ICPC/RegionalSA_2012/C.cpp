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

    ll n; 
    while(cin >> n and n) {
        vector<ll> v(n);
        ll mcd = 0;
        forn(i, n) {
            cin >> v[i];
            mcd = gcd(mcd, v[i]); 
        }
        
        vector<ll> divs;
        for(int i = 1; i * i <= mcd; i++){
            if(mcd % i == 0) {
                divs.pb(i);
                if(mcd / i != i) divs.pb(mcd / i);
            }
        }

        ll ans = 0, mi = *min_element(all(v));
        for(ll x : divs) {
            bool can = true;
            forn(i, n) if(v[i] % (x*n) != v[0] % (x*n)){
                can = false;
                break;
            } 
            
            if(can) ans += (mi - 1) / (x*n);
        }

        cout << ans << '\n';
    }



    return 0;
}