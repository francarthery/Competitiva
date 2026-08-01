#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ws <<" "<<
#define nl cout<<"\n";
#define dbg(x) cout<<#x ws "=" ws x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct UnionFind {
    int nsets;
    vector<int> f, setsz;
    UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
    int comp (int x) { return (f[x] == -1 ? x : f[x] = comp(f[x]));}
    bool join(int i, int j) {
        int a = comp(i), b = comp(j);
        if(a != b) {
            if(setsz[a] > setsz[b]) swap(a, b);
            f[a] = b;
            nsets--, setsz[b] += setsz[a];
        }
        return a == b;
    }
};

#define lg(x) (31 - __builtin_clz(x))

struct LCA{
    int N, LOGN, ROOT;
    vector<int> L;
    vector<vector<ii>> vp, G;
    LCA(int n, int root) : N(n), LOGN(lg(n) + 1), ROOT(root), L(n), G(n){
        vp = vector<vector<ii>> (n, vector<ii>(LOGN, {root, root}));
    }
    void addEdge(int a, int b, int c) {G[a].push_back({b, c}), G[b].push_back({a, c});}

    void dfs(int node, int p, int lvl){
        L[node] = lvl;
        for(auto it = G[node].begin(); it != G[node].end(); it++) if(it -> first != p) {
            dfs(it -> first, node, lvl + 1);
            vp[it -> first][0] = {node, it -> second};
        }
    }

    void build(){
        dfs(ROOT, ROOT, 0);
        // forn(i, N) cout << i << ' ' << vp[i][0].second << '\n'; 
        forn(k, LOGN - 1) forn(i, N) {
            vp[i][k+1].first = vp[vp[i][k].first][k].first;
            vp[i][k+1].second = max(vp[i][k].second, vp[vp[i][k].first][k].second);
        }
    }

    ii climb(int a, int d){
        ii ans = {a, 0};
        if(!d) return ans;
        dfor(i, lg(L[ans.first]) + 1) if(1 << i <= d) {
            ans.second = max(ans.second, vp[ans.first][i].second);
            ans.first = vp[ans.first][i].first;
            d -= 1 << i;
        }
        return ans;
    }

    ii lca(int a, int b){
        if(L[a] < L[b]) swap(a, b);
        ii a2 = {a, 0}, b2 = {b, 0};
        a2 = climb(a, L[a] - L[b]);
        if(a2.first == b2.first) return a2;
        dfor(i, lg(L[a]) + 1) if(vp[a2.first][i].first != vp[b2.first][i].first) {
            a2 = {vp[a2.first][i].first, max(a2.second, vp[a2.first][i].second)};
            b2 = {vp[b2.first][i].first, max(b2.second, vp[b2.first][i].second)};
        }
        ii ans = {vp[a2.first][0].first, max({a2.second, b2.second, vp[b2.first][0].second, vp[a2.first][0].second})};
        return ans;
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
        freopen("in","r",stdin);
        freopen("out","w",stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<vector<array<int, 3>>> g(n); //vecino, peso, indice de la arista 
    vector<array<int, 4>> ar(m);
    vector<int> inds;
    forn(i, m) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        ar[i] = {c, a, b, i};
    }

    sort(all(ar));
    UnionFind uf(n);
    LCA lca(n, 0);
    forn(i, m){
        if(!uf.join(ar[i][1], ar[i][2])) {
            lca.addEdge(ar[i][1], ar[i][2], ar[i][0]);
            g[ar[i][1]].push_back({ar[i][2], ar[i][0], ar[i][3]});
            g[ar[i][2]].push_back({ar[i][1], ar[i][0], ar[i][3]});
        }
        else inds.push_back(i);
    } 
    lca.build();

    vector<int> ans(m); // 0 all, 1 some, 2 una basura
    vector<priority_queue<ii, vector<ii>, greater<ii>>> info(n), nodes(n); //Stack monotona (menor arista prescindible, altura a la que deja de ser valido)

    forn(i, sz(inds)) {
        auto [c, a, b, ind] = ar[inds[i]];
        ii path = lca.lca(a, b);
        // cout << a << ' ' << b << ' ' << path.first << ' ' << path.second << '\n';
        if(path.second < c) ans[ar[inds[i]][3]] = 2;
        else {
            info[a].push({c, -lca.L[path.first]});
            info[b].push({c, -lca.L[path.first]});
            ans[ar[inds[i]][3]] = 1;
        }
    }
    // forn(i, n) dbg(sz(info[i]));

    function<void(int, int, int)> dfs = [&](int s, int f, int lvl) {
        for(auto u : g[s]) if(u[0] != f) {
            dfs(u[0], s, lvl+1);

            while(sz(nodes[u[0]]) and -nodes[u[0]].top().second > lvl) nodes[u[0]].pop();
            int mi = 1e9;
            if(sz(nodes[u[0]])) mi = nodes[u[0]].top().first;
    
            if(u[1] >= mi) ans[u[2]] = 1;

            if(sz(nodes[u[0]]) > sz(nodes[s])) nodes[u[0]].swap(nodes[s]);
            while(sz(nodes[u[0]])) {
                nodes[s].push(nodes[u[0]].top());
                nodes[u[0]].pop();
            }
        }

        while(sz(info[s])) {
            nodes[s].push(info[s].top());
            info[s].pop();
        }
    };

    dfs(0, -1, 0);

    forn(i, m) {
        if(ans[i] == 0) cout << "any\n";
        else if(ans[i] == 1) cout << "at least one\n";
        else cout << "none\n";
    }
        
    return 0;
}