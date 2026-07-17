#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<ld> v(n);

    forn(i, n) cin >> v[i];
    sort(rall(v));
    vector<ld> dp(2*n + 3);
    dp[n+1] = 1.0;

    ld ans = 0.0;
    forn(i, n) { //voy a contestar i preguntas
        vector<ld> nuevo_dp(2*n + 3);
        forr(j, 1, 2*n+1){
            nuevo_dp[j] = dp[j-1] * v[i] + dp[j+1] * (1 - v[i]);
        }
        dp = nuevo_dp;
        vdbg(dp);
        ld sum = 0;
        forr(j, n+1+k, 2*n+2){
            sum += dp[j];
        }
        ans = max(ans, sum);
    }

    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}