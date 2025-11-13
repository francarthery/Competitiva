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

    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> inter{n};
        ll r = n, res = 0;
        while(r >= k){
            int m = (r + 1) / 2;
            if(r % 2 == 0){
                inter.pb(m);
                r = m;
            }
            else{
                if(sz(inter) > 1){
                    ll temp = inter[sz(inter) - 2] + 1;
                    for(int i = sz(inter) - 2; i >= 1; i--)
                        temp += temp + 2 * (inter[i] + 1);
                    res += temp;
                } 
                else res += m;  

                inter.pb(m - 1);
                r = m - 1;
            }
        }
        cout << res << '\n';

    }

    return 0;
}