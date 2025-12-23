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
        int n, k; cin >> n >> k;
        vector<int> v, mate;
        set<int> s;
        forn(i, n){
            int x; cin >> x;
            if(!s.count(x)){
                v.pb(x);
                s.insert(x);
                mate.pb(1);
            }
            else mate.back()++;
        }

        n = sz(v);
        vector dp(n + 1, vector(k + 1, vector<int>(k + 1, -1e9)));
        vector<int> best(k + 1);
        dp[0][0][0] = 0;

        forr(i, 1, n + 1) { 
            vector<int> nbest(k + 1);
            forn(j, k + 1) {
                forn(l, k + 1) {
                    dp[i][j][l] = dp[i - 1][j][l] + l * mate[i - 1];
                    if(j >= l and l <= v[i - 1]) dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - l][best[j - l]] + l * mate[i - 1]);
                    
                    if(dp[i][j][l] > dp[i][j][nbest[j]]){
                        nbest[j] = l;
                    }
                }
            }
            best = nbest;
        }

        int ma = 0;
        forn(i, k + 1) ma = max(ma, *max_element(all(dp[n][i])));
        cout << ma << '\n';
    }

    return 0;
}