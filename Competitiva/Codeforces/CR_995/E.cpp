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

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;

        vector<int> v(n), v2(n);
        forn(i, n) cin >> v[i];
        forn(i, n) cin >> v2[i];
        sort(all(v));
        sort(all(v2));

        ll res = 0;
        forn(i, n){
            forn(j, 2){
                ll val;
                if(j == 0) val = v[i];
                else val = v2[i];

                int r = (v2.end() - lower_bound(all(v2), val)), l = (v.end() - lower_bound(all(v), val));
                if(r - l <= k) res = max(res, val * r);
            }
        }

        cout << res << '\n';
    }



    
    return 0;
}