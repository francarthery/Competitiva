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
        dp[0][0][0] = 0;

        forn(i, n) { 
            forn(j, k + 1) {
                forn(l, k + 1) {
                    dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + l * mate[i]); //Gasto 0
                    forr(w, l + 1, min(v[i], k - j) + 1){ //Aumento maximo
                        dp[i + 1][j + w][w] = max(dp[i + 1][j + w][w], dp[i][j][l] + w * mate[i]);
                    }
                }
            }
        }

        int ma = 0;
        forn(i, k + 1) ma = max(ma, *max_element(all(dp[n][i])));
        cout << ma << '\n';
    }

    return 0;
}