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

unordered_map<ll, int> dp;
int n;
vector<int> v(2e5);
bool solve(ll x) {
    if(!x) return 0;
    if(dp.count(x)) return dp[x];
    dp[x] = 2; //Para no quedar en un bucle infinito
    bool val = false;

    forn(i, n) {
        forn(j, 3) if(v[i] >= (j+1)) {
            int ans = solve(x ^ v[i] ^ (v[i] - (j+1)));
            if(ans != 2) val = val or !ans; 
        }
    }

    return dp[x] = val;
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
        cin >> n;
        ll xo = 0;
        forn(i, n) cin >> v[i], xo ^= v[i];
        cout << (solve(xo) ? "first" : "second") << '\n';
    }

    // for(auto i : dp) cout << i.fr << ' ' << i.sc << '\n';


    return 0;
}