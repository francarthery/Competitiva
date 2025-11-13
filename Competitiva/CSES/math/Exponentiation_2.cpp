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

const ll MOD = 1e9 + 7;

ll modpow(ll x, ll n, ll m){
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

    ll n, a, b, c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        cout << modpow(a, modpow(b, c, MOD - 1), MOD) << '\n';
    }
    
    return 0;
}