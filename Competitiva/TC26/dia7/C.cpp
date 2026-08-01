#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<vector<ii>> g(n);
    vector<array<int, 3>> ar(m);
    int a, b, c;
    forn(i, m) {
        cin >> a >> b >> c; a--; b--;
        ar[i] = {a, b, c};
        g[a].push_back({b, c});
    }

    vector<int> vis;
    bool ok;
    function<void(int, int)> dfs = [&](int s, int ma) {
        if(vis[s] == 2) return;
        else if(vis[s] == 1) {
            ok = false;
            return;
        }
        vis[s] = 1;
        for(auto u : g[s]) if(u.second > ma) dfs(u.first, ma);
        vis[s] = 2;
    };

    auto f = [&](int m) {
        vis.assign(n, 0);
        ok = true;
        forn(i, n) if(!vis[i]) dfs(i, m);
        return ok; 
    };

    int l = -1, r = 1e9+1;
    while(r-l>1) {
        int m = (r+l)/2;
        if(f(m)) r = m;
        else l = m;
    }

    vector<int> dgin(n), topo(n, 1e9);
    queue<int> q;
    forn(s, n) for(auto u : g[s]) if(u.second > r) dgin[u.first]++; 
    forn(i, n) if(dgin[i] == 0) q.push(i);
    // vdbg(dgin);

    int cont = 0;
    while(sz(q)) {
        int s = q.front();
        topo[s] = cont++;
        q.pop();
        for(auto u : g[s]) if(u.second > r) {
            dgin[u.first]--;
            if(!dgin[u.first]){
                q.push(u.first);
            }
        }    
    }
    // dbg(r); vdbg(topo);
    vector<int> ans;
    forn(i, m) {
        if(topo[ar[i][0]] > topo[ar[i][1]] and ar[i][2] <= r) ans.push_back(i);
    }
    cout << r << ' ' << sz(ans) << '\n';
    for(int i : ans) cout << i+1 << ' ';
    cout << '\n';
    
    return 0;
}