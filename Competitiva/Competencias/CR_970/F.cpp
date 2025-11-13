#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dforn(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1e9 + 7;

ll modpow(ll x, ll n, ll m = MOD){
    if(n == 0) return 1;

    ll u = modpow(x, n / 2, m);
    return (((u * u) % m) * (n % 2 ? x : 1)) % m;   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll rta = 0, sum = 0;
        vector<ll> v(n);
        forn(i, n){
            cin >> v[i];
            sum = (sum + v[i]) % MOD;
        }
        forn(i, n) rta = (rta + (sum - v[i] + MOD) * v[i]) % MOD;
        //dbg(sum); dbg(rta);
        ll inv2 = modpow(2, MOD - 2);
        ll invq = modpow(((n * (n - 1)) / 2) % MOD, MOD - 2);

        rta = (rta * inv2) % MOD;
        rta = (rta * invq) % MOD;
        cout << rta << '\n';
    }
    
    return 0;
}