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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    ll sum = accumulate(all(v), 0ll);
    ll may = sum / 2 + 1, rta = 0;
    sort(all(v));

    forn(i, n){ //empiezo desde v[i] tomando a v[i]
        vector<ll> dp(may + 1);
        dp[0] = 1;
        forr(j, i + 1, n){ //pruebo la suma del resto de elementos
            dfor(k, may - v[j] + 1){
                dp[k + v[j]] += dp[k];
            }
        }
        
        forr(j, max(0ll, may - v[i]), may) rta += dp[j];
    }

    cout << rta << '\n';
    
    return 0;
}