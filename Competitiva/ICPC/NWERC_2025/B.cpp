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

int n; 
bool ok = true;
vector<int> coins{1,2,5,10,20,50,100,200,500};
vector<int> cants{1,4,1,1,4,1,1,50,20}, ans;

bool check(){
    if(n % 2) return false;

    vector<bool> dp(5005);
    dp[0] = 1;
    forn(i, sz(cants)){
        forn(j, cants[i]) {
            for(int k = 5000 - coins[i]; k >= 0; k--) dp[k + coins[i]] = dp[k + coins[i]] | dp[k];
        }
    }

    return dp[n / 2];
}

void f(int pos) {
    int sum = 0;
    forn(i, sz(coins)) sum += cants[i] * coins[i];
    if(sum == n) {
        if(!check() and !sz(ans)) ans = cants;
    }
    
    if(pos == sz(coins)) return;
    int orig = cants[pos];
    forn(i, orig) {
        f(pos + 1);
        cants[pos]--;
    }
    f(pos + 1);
    cants[pos] = orig;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n;
    f(0);

    if(ans.empty()) cout << "Splittable\n"; 
    else {
        cout << accumulate(all(ans), 0) << '\n';
        forn(i, sz(ans)) forn(j, ans[i]) cout << coins[i] << ' ';
        cout << '\n';
    }


    return 0;
}