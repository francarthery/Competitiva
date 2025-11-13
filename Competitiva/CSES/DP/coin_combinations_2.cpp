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

const int mod = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);    
        freopen("output.out", "w", stdout);
    #endif

    int n, x;
    cin >> n >> x;
    vector<int> v(n + 1);
    vector<int> dp(vector<int>(x + 1));
    forr(i, 1, n + 1) cin >> v[i];

    forr(i, 1, n + 1){
        if(v[i] <= x) dp[v[i]]++;
        forr(j, 1, x + 1){
            if(j >= v[i] and dp[j - v[i]]){
                dp[j] = (dp[j] + dp[j - v[i]]) % mod;
            }    
        }    
    }

    cout << dp[x] << '\n';

    return 0;
}