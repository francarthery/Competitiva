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
        int n; string s; 
        cin >> n >> s;

        bool pude = false;
        auto f = [&](string s) {
            int n = sz(s);
            vector<int> vals(n);
            forn(i, n) vals[i] = (s[i] == ')' ? -1 : 1);
            vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
            dp[0][0] = 1;

            forr(i, 1, n+1){
                forn(l, i+1){
                    int posr = n - (i-l), r = i-l; //pos real
                    int der = (i%2 ? -1e9 : 1e9), izq = (i%2 ? -1e9 : 1e9); //perdon
                    if(r) der = dp[l][r-1] + vals[posr-1];
                    if(l) izq = dp[l-1][r] + vals[l-1];
                    
                    if(i%2) dp[l][r] = max(der, izq);
                    else dp[l][r] = min(der, izq);

                    if(dp[l][r] <= 0) pude = true;
                }
            }
        };

        if(s[0] == '(') f(s.substr(1));
        if(s.back() == '(') {
            s.pop_back();
            f(s);
        }

        cout << (pude ? "Monocarp" : "Polycarp") << '\n';
    }



    return 0;
}