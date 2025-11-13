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
#define fsp(x) fixed << setprecision((x))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;

    vector<int> v(n);
    int val = 4000;
    forn(i, n) cin >> v[i], v[i] += val;

    vector<vector<ll>> dp(5, vector<ll>(2 * val + 1));
    dp[0][val] = 1;

    forn(i, n){ //recorro elementos
        for(int j = 4; j >= 1; j--){ //recorro posicion en la que soy usado
            for(int k = val; k >= -val; k--){ //recorro valores de la query
                if((k + val) - (v[i] - val) >= 0 and (k + val) - (v[i] - val) <= 2 * val) {
                    dp[j][k + val] += dp[j - 1][(k + val) - (v[i] - val)];
                }
            }
        }
    }

    int q; cin >> q;
    forn(i, q){
        int x; cin >> x;
        cout << dp[4][x + val] << '\n';
    }

    return 0;
}
