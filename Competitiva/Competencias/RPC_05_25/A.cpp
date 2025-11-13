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
        ll n; cin >> n;

        multiset<ll> s;

        forn(i, n){
            ll x; cin >> x;
            s.insert(x);
        }

        ll ans = 0;

        while(sz(s) > 1){
            ll elem1 = *s.begin();
            s.erase(s.begin());
            ll elem2 = *s.begin();
            s.erase(s.begin());
            ans += elem1 + elem2;
            s.insert(elem1 + elem2);
        }

        cout << ans << '\n';
    }



    return 0;
}