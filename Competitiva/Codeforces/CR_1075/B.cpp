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
typedef pair<ll, ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        vector<ll> a(n), b(n), c(n);
        forn(i, n) cin >> a[i] >> b[i] >> c[i];

        ll neto = 0;
        forn(i, n) {
            x -= a[i] * (b[i] - 1);
            neto = max(neto, a[i] * b[i] - c[i]);
        }

        if(x <= 0) {
            cout << 0 << '\n';
            continue;
        }
        
        if(neto <= 0) {
            cout << -1 << '\n';
            continue;
        }

        cout << (x + neto - 1) / neto << '\n';
    }

    return 0;
}