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

ll f(ll l, ll r, ll num){
    return r / num - (l - 1) / num;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;
        ll ans = r - l + 1;

        vector<int> prim{2,3,5,7};
        forr(i, 1, (1 << 4)){
            int cont = 0, elem = 1;
            forn(j, 4) {
                if(i & (1 << j)) {
                    cont++;
                    elem *= prim[j];
                }
            }

            if(cont % 2) ans -= f(l, r, elem);
            else ans += f(l, r, elem);
        }

        cout << ans << '\n';
    }



    return 0;
}