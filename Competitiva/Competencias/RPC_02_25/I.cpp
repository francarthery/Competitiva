#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

const ll INF = 1e11;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<int> dias(n), tarifa(n);
    forn(i, n) cin >> dias[i] >> tarifa[i]; //dias, tarifa de ese dia

    vector<tuple<int, int, int>> inter(k); 
    for (auto &[x, y, z] : inter) cin >> x >> y >> z;

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    forr(i, 1, n + 1) {
        dp[i] = dp[i - 1] + tarifa[i - 1]; //dia anterior + tarifa de hoy

        for (auto &[x, y, z] : inter){
            int j = max((ll) i - y - 1, upper_bound(all(dias), dias[i - 1] - x) - dias.begin() - 1);
            j = max(j, -1);
            dp[i] = min(dp[i], dp[j + 1] + z);
        }
    }
    
    cout << dp[n];
    
    return 0;
}