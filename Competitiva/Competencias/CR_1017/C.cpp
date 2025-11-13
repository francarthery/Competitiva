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
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        forn(i, n) forn(j, n) cin >> v[i][j];

        vector<int> res(n + 1);
        vector<bool> use(2 * n + 1);
        forn(i, n) {
            res[i + 1] = v[0][i];
            use[v[0][i]] = true;
        }

        forr(i, 1, n) {
            res.pb(v[i][n - 1]);
            use[v[i][n - 1]] = true;
        }

        forr(i, 1, 2 * n + 1) {
            if(use[i] == false) res[0] = i;
        }

        forn(i, sz(res)) cout << res[i] << ' ';
        cout << '\n';
        

    }



    return 0;
}