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

    int n, m, a, b; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> vis(n);
    
    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    function<void(int)> dfs = [&](int s){
        if(vis[s]) return;
        vis[s] = true;
        for(int &u : g[s]) dfs(u);
    };

    function<int(int)> bfs = [&](int s) -> int{
        queue<int> q;
        q.push(s);
        vis[s] = 1;

        while(sz(q)){
            int s = q.front();
            q.pop();

            for(int &u : g[s]) if(!vis[u]){
                q.push(u);
                vis[u] = vis[s] + 1;
            }
        }
        
        int ma = 0, node;
        forn(i, n){
            if(vis[i] > ma){ 
                ma = vis[i];
                node = i;
            }
        }
        return node; //nodo mas lejano
    };

    int comp = 0;
    forn(i, n) if(!vis[i]) {
        dfs(i);
        comp++;
    }

    if(comp == 1){
        vis.assign(n, 0);
        int nodo = bfs(0);
        vis.assign(n, 0);
        int res = bfs(nodo);
        cout << ceil(log2(vis[res] - 1)) << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}