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
typedef tuple<int, int, int> iii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<iii> v(n);
    vector<ll> dp(n + 1);
    for(auto &[a, b, p] : v) cin >> a >> b >> p;

    sort(all(v));
    v.pb({1e9 + 1, 0, 0});

    dfor(i, n){
        int indice = upper_bound(all(v), iii(get<1>(v[i]), 2e9, 2e9)) - v.begin();
        dp[i] = max(dp[i + 1], get<2>(v[i]) + dp[indice]);
    }

    cout << dp[0] << '\n';
    
    return 0;
}