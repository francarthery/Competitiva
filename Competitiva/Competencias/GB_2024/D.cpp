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
const int MOD = 998244353;

ll modpow(int x, int n, int m){
    if(n == 0) return 1;

    long long u = modpow(x, n / 2, m);
    return (((u * u) % m) * (n % 2 ? x : 1)) % m;   
}

ll inv(ll n){
    return modpow(n, MOD - 2, MOD);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, q, x, y;
    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<vector<int>> v(2, vector<int>(n));
        forn(i, n) cin >> v[0][i];
        forn(i, n) cin >> v[1][i];
        auto v2 = v;
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());

        ll prod = 1;
        forn(i, n) {
            prod *= min(v[0][i], v[1][i]);
            prod %= MOD;
        }
        cout << prod << ' ';

        forn(i, q){
            cin >> x >> y;
            if(x == 1){
                int ind = upper_bound(v[0].begin(), v[0].end(), v2[0][y - 1]) - v[0].begin();
                prod = (prod * inv(min(v[0][ind - 1], v[1][ind - 1]))) % MOD;
                prod = (prod * min(v[0][ind - 1] + 1, v[1][ind - 1])) % MOD;
                v[0][ind - 1]++;
                v2[0][y - 1]++;
            }
            else{
                int ind = upper_bound(v[1].begin(), v[1].end(), v2[1][y - 1]) - v[1].begin();
                prod = (prod * inv(min(v[1][ind - 1], v[0][ind - 1]))) % MOD;
                prod = (prod * min(v[1][ind - 1] + 1, v[0][ind - 1])) % MOD;
                v[1][ind - 1]++;
                v2[1][y - 1]++;
            }
            cout << prod << ' ';
        }

        cout << '\n';
    }
    
    return 0;
}