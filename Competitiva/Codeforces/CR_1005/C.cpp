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

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> v(n), ps(n + 1), ss(n + 1);
        forn(i, n) cin >> v[i];

        forn(i, n){
            ps[i + 1] = ps[i];
            if(v[i] > 0) ps[i + 1] += v[i];
        }  

        dfor(i, n){
            ss[i] = ss[i + 1];
            if(v[i] < 0) ss[i] -= v[i];
        }

        //vdbg(ps); vdbg(ss);

        ll ans = 0;
        forn(i, n + 1) ans = max(ans, ps[i] + ss[i]);

        cout << ans << '\n';
    }

    return 0;
}