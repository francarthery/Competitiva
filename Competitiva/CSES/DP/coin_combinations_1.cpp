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
    vector<int> v(n), dp(x + 1);
    forn(i, n) cin >> v[i];

    dp[0] = 1;
    forr(i, 1, x + 1){
        forn(j, n){
            if(i >= v[j]){
                dp[i] += dp[i - v[j]];
                dp[i] %= (int)1e9 + 7;
            }
        }
    }

    cout << dp[x] << '\n';

    
    return 0;
}