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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // #ifdef fran
    //     freopen("input.in", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    int n; cin >> n;
    int q, k; cin >> q;

    vector<vector<int>> v(10, vector<int>(1, 0));
    forr(i, 1, 10) {
        v[i] = v[i - 1];
        v[i].pb(i);
        v[i].insert(v[i].end(), v[i - 1].begin(), v[i - 1].end());
    }   

    auto f = [&](int i, int x) {
        cout << i << ' ' << i << endl;
        int ans1, ans2; cin >> ans1;
        if(ans1 == n) exit(0);
        cout << i << ' ' << i << endl;
        cin >> ans2;
        if(ans2 == n) exit(0);
        return ans1 == x - 1;
    };

    dfor(i, n) {

        if(f(n - i, q)) continue;

        forn(j, (1 << (i + 1))){
            cout << n - i << ' ' << v[9][j] + n - i << endl;
            cin >> k;
            if(k == n){
                return 0;
            }
            if(k > q and f(n - i, k)) {
                q = k;
                break;
            }
        }
    }

    // dbg(sz(v[9]));
    // vdbg(v[9]);
    return 0;
}