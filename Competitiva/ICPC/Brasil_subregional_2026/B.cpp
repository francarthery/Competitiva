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

ll expMod(ll b, ll e, ll m) {  // O(log e)
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

    const int MOD = 1e9+7;
    int n; cin >> n;
    vector<ii> v(n+1);
    vector<int> vals;
    forn(i, n) {
        cin >> v[i].first >> v[i].second; 
        v[i].second++;
        vals.push_back(v[i].first);
        vals.push_back(v[i].second);
    }
    v[n] = {0, 1e9+1};

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    int m = sz(vals);

    vector<vector<ll>> dp(n+1, vector<ll>(m));
    forn(i, m) dp[n][i] = 1;

    dfor(i, n) dfor(j, m-1) {
        int l = vals[j], r = vals[j+1];
        dp[i][j] = (dp[i][j] + dp[i][j+1]) % MOD; //que sea suffix sum;
        if(v[i].first > l or v[i].second < r) continue;
        
        ll comb = r-l;
        forr(k, i+1, n+1) {
            dp[i][j] += comb * dp[k][j+1] % MOD;
            int arriba = r-l, abajo = k-i;
            if(abajo > arriba) break;
            comb = (comb * (arriba-abajo) % MOD) * expMod(abajo+1, MOD-2, MOD) % MOD;
            if(v[k].first > l or v[k].second < r) break;
        }
        dp[i][j] %= MOD;
    }
    // forn(i, n+1) vdbg(dp[i]);

    
    cout << dp[0][0] << '\n';


    return 0;
}