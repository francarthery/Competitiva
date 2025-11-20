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

    ll t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<ll> v(n);
        forn(i, n) cin >> v[i];
        ll sum = 0, ma = 0, ans = 0;
        forn(i, n){
            sum += v[i];
            ma = max(v[i], (ll)ma);
        }

        forr(i, 1, n + 1){
            ll aux = sum % i ? i - sum % i : 0;
            if(i * ma - sum <= k and aux <= k) ans = i;
        }

        cout << ans << '\n';
    }
    
    return 0;
}