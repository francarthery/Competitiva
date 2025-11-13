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

    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 2e9), v(n);
    forn(i, n) cin >> v[i];

    
    dp[0] = 0;
    forr(i, 1, x + 1){
        forn(j, n){
            if(i >= v[j]) dp[i] = min(dp[i - v[j]] + 1, dp[i]);
        }
    }

    cout << (dp[x] == 2e9 ? -1 : dp[x]) << '\n';
    
    return 0;
}