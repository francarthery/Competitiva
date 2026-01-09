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

typedef long long ll;
typedef pair<int, int> ii;

int n, k, mod;
int dp[513][501][501];

int solve(int valX, int piedras, int num){
    if(!piedras) return !valX;
    if(piedras < num) return 0;
    if(dp[valX][piedras][num] != -1) return dp[valX][piedras][num];
    
    dp[valX][piedras][num] = 0;
    
    for(int i = num; i <= piedras; i++){
        dp[valX][piedras][num] = (dp[valX][piedras][num] + solve(valX ^ i, piedras - i, i)) % mod;
    }   

    return dp[valX][piedras][num];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> k >> mod;
    memset(dp, -1, sizeof(dp));

    cout << solve(k, n - k, 1) << '\n';
    
    return 0;
}