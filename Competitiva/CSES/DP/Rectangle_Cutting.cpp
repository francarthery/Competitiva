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

vector<vector<int>> dp;
const int INF = 2e9;

int solve(int n, int m){
    if(n < m) swap(n, m);
    if(n == m) return 0;
    if(dp[n][m] != INF) return dp[n][m];

    forr(i, 1, n){
        int cant = n / i - (n % i == 0);
        dp[n][m] = min(dp[n][m], cant + (n / i) * solve(i, m) + (n % i ? solve(n % i, m) : 0));
    }
    forr(i, 1, m){
        int cant = m / i - (m % i == 0);
        dp[n][m] = min(dp[n][m], cant + (m / i) * solve(i, n) + (m % i ? solve(m % i, n) : 0));
    }

    return dp[n][m];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    if(n < m) swap(n, m);
    dp.assign(n + 1, vector<int>(m + 1, INF));
    cout << solve(n, m) << '\n';
    
    return 0;
}