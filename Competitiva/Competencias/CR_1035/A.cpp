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
        ll a, b, x, y; cin >> a >> b >> x >> y;
        if(a - b >= 2 or (a - b == 1 and a % 2 == 0)) cout << -1 << '\n';
        else if(a - b == 1 and a % 2) cout << y << '\n';
        else {
            ll ans = 0;
            if(y < x) {
                if(a % 2 == 0) ans = ((b - a + 1) / 2) * y + ((b - a) / 2) * x;
                else ans = ((b - a + 1) / 2) * x + ((b - a) / 2) * y;
            }
            else ans = (b - a) * x;
            cout << ans << '\n';
        }

    }



    return 0;
}