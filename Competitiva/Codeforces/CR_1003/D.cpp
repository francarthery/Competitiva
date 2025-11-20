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

    ll t, n, m, x;
    cin >> t;
    while(t--){
        cin >> m >> n;
        vector<pair<ll, ll>> sumas;
        
        forn(i, m) {
            ll sum = 0, sum2 = 0;
            forn(j, n){
                cin >> x;
                sum += x * (n - j);
                sum2 += x;
            }
            //dbg(sum); dbg(sum2);
            sumas.pb({sum2, sum});
        }

        sort(all(sumas));
        ll res = 0;
        forn(i, m) {
            res += sumas.back().fr * (m - i - 1) * n + sumas.back().sc;
            sumas.pop_back();
        }

        cout << res << '\n';
    }




    
    return 0;
}