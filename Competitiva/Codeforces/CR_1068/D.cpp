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

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;

        if(k > 32){
            cout << popcount((unsigned int)(n)) + k - 1 << '\n';
            continue;
        }

        vector dp(63, vector(k + 1, vector<int>(2, 1e9)));
        dp[0][0][0] = 0;

        forn(i, 62) {
            forn(j, k + 1) {
                forn(c, 2) {
                    int val = ((n >> i) & 1) + c; 
                    int car = val / 2;
                    int res = val % 2;
                    dp[i + 1][j][car] = min(dp[i + 1][j][car], dp[i][j][c] + res);

                    if(j >= k) continue;
                    val++; //Gasto operacion
                    car = val / 2;
                    res = val % 2;
                    dp[i + 1][j + 1][car] = min(dp[i + 1][j + 1][car], dp[i][j][c] + res);
                }
            }
        }
        
        cout << popcount((unsigned int)(n)) + k - min(dp[62][k][0], dp[62][k][1]) << '\n';
    }

    return 0;
}