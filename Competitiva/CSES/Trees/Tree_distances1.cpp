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

    int n; cin >> n;
    vector<vector<int>> g(n);
    int a, b;
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<int> best(n), ans(n);
    function<int(int, int)> dfs = [&](int s, int f) -> int {
        int may = 0;
        for(int u : g[s]){
            if(u == f) continue;
            may = max(may, dfs(u, s)+1);
        }

        return best[s] = may;
    };

    function<void(int, int, int)> dfs2 = [&](int s, int f, int ma) -> void {
        int may = 0;
        multiset<int> elems{ma};
        for(int u : g[s]){
            if(u == f) continue;
            elems.insert(best[u]+1);
        }

        for(int u : g[s]) {
            if(u == f) continue;
            elems.erase(elems.find(best[u]+1));
            int resp = 0;
            if(sz(elems)) resp = *elems.rbegin();
            dfs2(u, s, resp+1);
            elems.insert(best[u]+1);
        }

        ans[s] = max(ma, best[s]);
    };

    dfs(0, -1);
    dfs2(0, -1, 0);
    //vdbg(best);
    for(int i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}