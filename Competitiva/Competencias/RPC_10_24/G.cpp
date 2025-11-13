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
typedef tuple<double, double, double> iii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, l, a, b, c;
    cin >> n >> l;
    vector<iii> v(n + 1);
    vector<double> dp(n + 1, 2e9);
    forn(i, n) {
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    v[n] = {l, 0, 0};
    sort(all(v));

    dp[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        int dist = get<1>(v[i]) * get<2>(v[i]), d = get<0>(v[i]);
        if(dist + d > l) dist = l - d;
        int lb = lower_bound(all(v), iii(dist + d, 0, 0)) - v.begin();
        dp[i] = dp[i + 1] + get<0>(v[i + 1]) - d;
        if(lb <= n) dp[i] = min(dp[i], dp[lb] + get<0>(v[lb]) - (dist + d) + dist / get<1>(v[i]));   
    }
    cout << fixed << setprecision(8) << dp[0] + get<0>(v[0]) << '\n';

    return 0;
} 
