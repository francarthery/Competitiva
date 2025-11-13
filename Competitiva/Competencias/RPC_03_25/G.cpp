#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
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

int n; 
string s;
const int MOD = 1e9 + 7;

vector<vector<int>> dp;

int solve(int i, int j){
    if(i >= n) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == '#') return 0;
    dp[i][j] = 0;

    dp[i][j] += solve(i + 1, j) % MOD + solve(i + j, j + 1) % MOD;
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> s;

    dp.resize(n + 1, vector<int> (451, 0));
    forn(i, 450) dp[n][i] = 1;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 450 - 1; j >= 1; j--){
            if(s[i] != '#'){
                dp[i][j] += (dp[i + 1][j] + dp[min(i + j, n)][j + 1]) % MOD;
                dp[i][j] %= MOD;
            }
        }   
    }

    cout << dp[0][2] << '\n';
    

    
    return 0;
}