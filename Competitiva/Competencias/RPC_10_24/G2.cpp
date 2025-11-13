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
vector<iii> v;
int n, l;
vector<double> dp;

double solve(int i){
    if(get<0>(v[i]) == l) return 0;
    if(dp[i] != 2e9) return dp[i];

    int dist = get<1>(v[i]) * get<2>(v[i]), d = get<0>(v[i]);
    if(dist + d > l) dist = l - d;

    int lb = (lower_bound(all(v), iii(d + dist, 0, 0)) - v.begin());

    if(i < n) dp[i] = solve(i + 1) + (get<0>(v[i + 1]) - get<0>(v[i])); //No agarro
    if(lb <= n) {
        double ti = dist / get<1>(v[i]) + (get<0>(v[lb]) - (d + dist)); //t speedup + t hasta siguiente speed up
        dp[i] = min(dp[i], solve(lb) + ti); //Agarro
    }    
    return dp[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> l;
    v.resize(n + 1);
    dp.assign(n + 1, 2e9);
    for(auto &[a, b, c] : v) cin >> a >> b >> c;
    v[n] = {l, 0, 0};
    sort(all(v));
    cout << fixed << setprecision(8) << solve(0) + get<0>(v[0]) << '\n';

    return 0;
} 

