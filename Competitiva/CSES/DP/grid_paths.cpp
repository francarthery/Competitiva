#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<string> v(n);
    forn(i, n) cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(n));
    
    if(v[0][0] != '*') dp[0][0] = 1;

    forn(i, n){
        forn(j, n){
            dp[i][j] += (j > 0 and v[i][j - 1] == '.' ? dp[i][j - 1] : 0);
            dp[i][j] += (i > 0 and v[i - 1][j] == '.' ? dp[i - 1][j] : 0);
            dp[i][j] %= (int)(1e9 + 7);
        }
    }

    cout << (v[n - 1][n - 1] == '.' ? dp[n - 1][n - 1] : 0) << '\n';
    
    return 0;
}