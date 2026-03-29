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
 
    vector<ii> best(n);
    function<void(int, int)> dfs = [&](int s, int f){
        for(int u : g[s]){
            if(u == f) continue;
            dfs(u, s);
            if(best[u].fr+1 > best[s].fr) {
                best[s].sc = best[s].fr;
                best[s].fr = best[u].fr+1;
            }
            else if(best[u].fr+1 > best[s].sc) best[s].sc = best[u].fr+1;
        }
    };
 
    function<void(int, int, int)> dfs2 = [&](int s, int f, int ma) -> void {
        if(ma > best[s].fr) {
            best[s].sc = best[s].fr;
            best[s].fr = ma;
        }
        else if(ma > best[s].sc) best[s].sc = ma;
        for(int u : g[s]) {
            if(u == f) continue;
            if(best[u].fr + 1 == best[s].fr) dfs2(u, s, best[s].sc+1);    
            else dfs2(u, s, best[s].fr+1);    
        }
    };
 
    dfs(0, -1);
    dfs2(0, -1, 0);
    for(ii i : best) cout << i.fr << ' ';
    cout << '\n';
 
    return 0;
}