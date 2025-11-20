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
        int n; cin >> n;
        vector<int> v(2*n);
        forn(i, 2*n) cin >> v[i];
        sort(all(v));

        vector<int> may(v.begin() + n - 1, v.end() - 1), men(v.begin(), v.begin() + n - 1);
        vdbg(may); vdbg(men);

        cout << 1 << ' ';
        forn(i, n - 1){
            cout << may[i] << ' ' << men[i] << ' ';
        }
        cout << may.back() << ' ' << accumulate(all(may), 0ll) - accumulate(all(men), 0ll) - v[0] << '\n';
    }

    
    return 0;
}