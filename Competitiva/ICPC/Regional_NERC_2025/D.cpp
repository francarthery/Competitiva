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

const ll MOD = 1e9 + 7;

ll expMod(ll b, ll e, ll m = 1e9+7) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
        b = b * b % m;                 // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        
        auto check = [&](int r) {
            bool valid = true;
            vector<ll> b(n), a(n);
            a[0] = 1;
            forr(i, 1, n) {
                b[i] = ((v[i-1] - r - 2*b[i-1]) % MOD + MOD) % MOD;
                a[i] = ((-2)*a[i-1] % MOD + MOD) % MOD;
            }

            int misterioso = ((v[n-1] - r - 2*b[n-1]) % MOD + MOD) % MOD;
            misterioso = misterioso * expMod((1+2*a[n-1]) % MOD, MOD - 2) % MOD;

            ll post = misterioso;
            dfor(i, n) {
                ll xi = (a[i]*misterioso + b[i]) % MOD;
                if(v[i] - 2*xi - post != r) valid = false;
                post = xi;
            }

            return valid;
        };

        auto binaria = [&](int resto) {
            ll l = -1, r = 5e8;
            while(r-l>1) {
                ll m = (r+l) / 2;
                if(check(3*m + resto)) l = m;
                else r = m;
            }

            if(l == -1) return 0ll;
            return 3*l+resto;
        };

        ll ans = 0;
        forn(i, 3) ans = max(ans, binaria(i));
        cout << ans << '\n';

    }

    return 0;
}