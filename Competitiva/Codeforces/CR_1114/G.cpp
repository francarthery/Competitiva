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
        vector<int> a(n);
        multiset<ll> free;
        forn(i, n) cin >> a[i], free.insert(a[i]);
        vector<vector<int>> g(n);
        forn(i, n-1) {
            int x; cin >> x; x--;
            g[x].push_back(i+1);
        }

        vector<multiset<int>> nodes(n);
        function<void(int)> dfs = [&](int s) {
            for(int u : g[s]) {
                dfs(u);
                if(sz(nodes[u]) > sz(nodes[s])) swap(nodes[u], nodes[s]);
                for(int i : nodes[u]) nodes[s].insert(i);
            }
            int elem = -1e9;
            nodes[s].insert(a[s]);
            if(sz(g[s])) nodes[s].erase(nodes[s].begin());
        };

        dfs(0);
        ll ans = 0;
        for(int i : nodes[0]) {
            free.erase(free.find(i));
            ans += i;
        }

        forr(i, 1, n+1) {
            if(i < sz(nodes[0])) {
                cout << -1 << ' ';
                continue;
            }
            if(i > sz(nodes[0])) {
                ans += *free.rbegin();
                free.erase(--free.end());
            }

            cout << ans << ' ';
        }

        cout << '\n';
    }



    return 0;
}