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
        int n; cin >> n;
        vector<ll> a(n), b(n);
        forn(i, n) cin >> a[i];
        forn(i, n) cin >> b[i];

        ll mi = 0, ma = 0;

        forn(i, n){
            ll nmi = 1e18;
            nmi = min(nmi, mi - a[i]);
            nmi = min(nmi, b[i] - ma);

            ll nma = -1e18;
            nma = max(nma, ma - a[i]);
            nma = max(nma, b[i] - mi);

            mi = nmi;
            ma = nma;
            //dbg(mi); dbg(ma);
        }

        cout << ma << '\n';
    }



    return 0;
}