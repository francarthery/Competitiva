#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<< " = " <<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define lg(x) (31 - __builtin_clz(x))

struct LCA {
    int N, LOGN, ROOT;

    vector<int> L;
    vector<vector<int>> vp, G;
    LCA(int n, int root) : N(n), LOGN(lg(n) + 1), ROOT(root), L(n), G(n) {
        vp = vector<vector<int>>(n, vector<int>(LOGN, root));
    }
    void addEdge(int a, int b) {G[a].push_back(b), G[b].push_back(a);}
    void dfs(int node, int p, int lvl) {
        vp[node][0] = p, L[node] = lvl;
        forall(it, G[node]) if(*it != p) dfs(*it, node, lvl+1);
    }
    void build(){
        dfs(ROOT, ROOT, 0);
        forn(k, LOGN -1) forn(i, N) vp[i][k+1] = vp[vp[i][k]][k];
    }
    int climb(int a, int d) {
        if(!d) return a;
        dfor(i, lg(L[a]) + 1) if(1 << i <= d) a = vp[a][i], d -= (1<<i);
        return a;
    }
    int lca(int a, int b) {
        if(L[a] < L[b]) swap(a, b);
        a = climb(a, L[a] - L[b]);
        if(a == b) return a;
        dfor(i, lg(L[a]) + 1) if(vp[a][i] != vp[b][i]) a = vp[a][i], b = vp[b][i];
        return vp[a][0];
    }
    int dist (int a, int b){
        return L[a] + L[b] - 2 * L[lca(a, b)];
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w",stdout);
    #endif
    
    int n, a, b; cin >> n;
    LCA lca(n, 0);
    vector<vector<int>> g(n);
    forn(i, n-1) {
        cin >> a >> b; a--; b--;
        lca.addEdge(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> tam(n);
    function<void(int, int)> dfs = [&](int s, int f) {
        tam[s] = 1;
        for(int u : g[s]) if(u != f) {
            dfs(u, s);
            tam[s] += tam[u];
        }
    };

    dfs(0, -1);
    // vdbg(tam);

    lca.build();
    int q; cin >> q;
    forn(tt, q) {
        cin >> a >> b; a--; b--;

        if(a == b) {
            cout << n << '\n';
            continue;
        }

        int l = lca.lca(a, b);
        int d = lca.dist(a, b);
        int ans = 0;
        if(d % 2 == 0) {
            int d1 = lca.dist(l, a);
            int d2 = lca.dist(l, b);
            
            if(d1 < d2) {
                swap(d1, d2);
                swap(a, b);
            }
            int nodo = lca.climb(a, d / 2);

            if(d1 == d2) {
                int proh1 = lca.climb(a, d/2-1);
                int proh2 = lca.climb(b, d/2-1);
                ans = n - tam[proh1] - tam[proh2];
            }
            else {
                int proh1 = lca.climb(a, d/2-1);
                ans = tam[nodo];
                ans -= tam[proh1];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}