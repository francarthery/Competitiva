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
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        int xa = 0, xb = 0;
        forn(i, n) cin >> a[i], xa ^= a[i];
        forn(i, n) cin >> b[i], xb ^= b[i];

        sort(all(a));
        sort(all(b));
        if(a == b) {
            cout << "YES\n";
            continue;
        }

        int buscar = xa ^ xb;
        bool ok = binary_search(all(a), buscar), aparecio = false;
        forn(i, n) {
            if(aparecio or a[i] != buscar) a[i] ^= buscar;
            else aparecio = true;
        }
        sort(all(a));
        cout << (ok and a == b ? "YES" : "NO") << '\n';
    }



    return 0;
}