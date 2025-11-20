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
        ll k, sum = 0; cin >> k;
        ll val = 9, cont = 1;
        while(sum + val * cont <= k) {
            sum += val * cont;
            val *= 10;
            cont++;
        }

        ll ans = 0;
        ll x = (k - sum) / cont + pow(10, cont - 1) - 1;
        int digextra = (k - sum) % cont;
        string sig = to_string(x + 1);
        forn(i, digextra) ans += sig[i] - '0';
        
        ll r = 0, mult = 1;
        while(x){
            ll dig = x % 10;
            ans += dig * (r + 1);
            ans += ((dig * (dig - 1)) / 2) * mult;
            ans += (x / 10) * 45 * mult;

            x /= 10;
            r += mult * dig;
            mult *= 10;
        }

        cout << ans << '\n';
    }



    return 0;
}