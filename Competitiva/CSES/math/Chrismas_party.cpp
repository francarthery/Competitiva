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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    //https://en.wikipedia.org/wiki/Derangement 
    const int MOD = 1e9 + 7;
    int n; cin >> n;
    vector<ll> dp(n + 1);
    dp[1] = 0, dp[2] = 1;

    forr(i, 3, n + 1){
        dp[i] = (ll)(i - 1) * (dp[i - 1] + dp[i - 2]); //Por cada posicion tenemos (n - 1) posibles valores. Por cada valor posible i
        dp[i] %= MOD; //podemos reemplazar el elemento i por 1 o no, si lo hacemos nos quedan dp[n - 2] posibilidades, sino dp[n - 1];
    }

    cout << dp[n] << '\n';


    return 0;
}