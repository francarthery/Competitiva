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

string s;
const int MOD = 1e9+7;
ll dp[64][4][2][2]; //estado: 0 -> 00, 1 -> 01, 2 -> 10, 2 -> 11
ll solve(int i, int estado, bool tight0, bool tight1) {
    if(i == sz(s)) {
        if(estado == 1 or estado == 2) return 0;
        else return 1;
    }
    if(dp[i][estado][tight0][tight1] != -1) return dp[i][estado][tight0][tight1];

    dp[i][estado][tight0][tight1] = 0;
    int lim0 = (tight0 and s[i] == '0' ? 0 : 1);
    forn(nbit0, lim0+1) {
        int lim1 = (tight1 and !nbit0 ? 0 : 1);
        forn(nbit1, lim1+1) {
            bool ntight0 = tight0 and (nbit0 == s[i] - '0');
            bool ntight1 = tight1 and (nbit1 == nbit0);
            int nestado = ((nbit0 << 1) | nbit1);

            if((estado == 1 or estado == 2) and nestado == 3 or 
            ((estado == 0 or estado == 3) and nestado != 3)) {
                dp[i][estado][tight0][tight1] += solve(i+1, nestado, ntight0, ntight1);
                dp[i][estado][tight0][tight1] %= MOD;
            } 
        }
    }

    return dp[i][estado][tight0][tight1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        s = "";
        dfor(i, 62) s += ((n >> i) & 1) + '0';
        // dbg(s);
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 1, 1) - 1 << '\n';
    }

    return 0;
}