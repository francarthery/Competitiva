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
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, a, b;
    cin >> n >> a >> b;
    int x = n - 1, y = n - 1;
    while(gcd(x, a) != 1) x--;
    while(gcd(y, b) != 1) y--;

    ll cont = -2; //tengo dos 1 duplicados
    forr(i, 1, x + 1) cont += 1 + gcd(a, i);
    forr(i, 1, y + 1) cont += 1 + gcd(b, i);

    vector dp(n - x + 2, vector<ll>(n - y + 2, INF));
    dp[n - x][n - y + 1] = 0;

    dfor(i, n - x + 1){
        dfor(j, n - y + 1){
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + gcd(a, i + x) + gcd(b, j + y);
        }
    }

    cout << dp[0][0] + cont - 2 << '\n'; //la posicion (x, y) la considero dos veces

    
    return 0;
}