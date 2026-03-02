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
        ll s, m; cin >> s >> m;
        if(__builtin_ctz(s) < __builtin_ctz(m)){
            cout << -1 << '\n';
            continue;
        }
        ll ans = 0;
        vector<int> sts, stm;
        forn(i, 63) if(s & (1ll << i)) sts.pb(i);
        forn(i, 63) if(m & (1ll << i)) stm.pb(i);

        while(sz(sts)){
            while(sz(stm) and stm.back() > sts.back()) {
                m &= ~(1ll << stm.back());
                stm.pop_back();
            }
            ans = max(ans, (s + m - 1) / m);
            m &= ~(1ll << stm.back());
            
            while(sz(sts) and sts.back() >= stm.back()){
                s ^= (1ll << sts.back());
                sts.pop_back();
            }
        }

        cout << ans << '\n';
    }


    return 0;
}