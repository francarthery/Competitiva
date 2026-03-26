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

<<<<<<< HEAD
const int MAXN = 6001;
int n; 
vector<int> vals;
int dp[MAXN][MAXN];

int solve(int l, int r) {
    if(l + r == n) return dp[l][r] = vals[l];

    if(dp[l][r] != -1) return dp[l][r];

    int izq = vals[l] + solve(l+1, r);
    int der = solve(l, r-1) + vals[r];


}

=======
>>>>>>> e3308e078544d12f97ac7217ecf9f9eceb982eba
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n; string s; 
        cin >> n >> s;
        vector<int> vals(n);
        forn(i, n) vals[i] = (s[i] == '(' ? -1 : 1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        dfor(i, n) { //saque i = l+r
            forn(l, i+1) {
                int r = i-l;
                if(i%2) dp[l][r] = min(dp[l+1][r], dp[l][r+1]);
                else dp[l][r] = max({dp[l+1][r]+vals[l], dp[l][r+1]+vals[n-1-r],0});
            }
        }

        int der = -1e9, izq = -1e9;
        if(s[0] == '(') der = dp[1][0];
        if(s.back() == '(') izq = dp[0][1];
        cout << (der >= 1 or izq >= 1 ? "Monocarp" : "Polycarp") << '\n';
    }



    return 0;
}