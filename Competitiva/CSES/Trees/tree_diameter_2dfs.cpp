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

    int n, a, b;
    cin >> n;

    vector<vector<int>> g(n);

    forn(i, n - 1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    int ma = 0;
    function<int(int, int)> dfs = [&](int s, int f) -> int {
        vector<int> v;
        for(int u : g[s]){
            if(u != f) v.pb(dfs(u, s));
        }
        sort(rall(v));
        ma = max(ma, accumulate(v.begin(), v.begin() + min(2, sz(v)), 0));

        return (sz(v) ? v[0] : 0) + 1;
    };

    ma = max(ma, dfs(0, -1) - 1);
    cout << ma << '\n';

	return 0;
}