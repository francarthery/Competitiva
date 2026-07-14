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
        int n, a, b; cin >> n >> a >> b;
        bool ok = true;
        int g = gcd(a, b);
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        vector<vector<int>> ord1(g), ord2(g);
        forn(i, g) {
            for(int j = i; j < n; j+=g) {
                ord1[i].pb(v[j]);
                ord2[i].pb(j+1);
            }
            sort(all(ord1[i]));
            sort(all(ord2[i]));

            if(ord1[i] != ord2[i]) ok = false;
        }
      
        cout << (ok ? "YES" : "NO") << '\n';
    }



    return 0;
}