struct LCA{
    int root, N, lgn;
    vector<int> lv;
    vector<vector<int>> vp, g;

    LCA(int n, int rt) : N(n), root(rt), g(n), lv(n) {
        lgn = __lg(n) + 1;
        vp.assign(lgn, vector<int>(n));
    }  
    void addEdge(int a, int b) { g[a].pb(b); g[b].pb(a); }

    void dfs(int s, int f, int l){
        lv[s] = l; vp[0][s] = f;
        for(int u : g[s]) if(u != f) dfs(u, s, l + 1);
    }

    void build(){
        vp[0][root] = root; //buclecito en la raiz
        dfs(root, root, 0);
        forn(i, lgn - 1) forn(j, N) vp[i + 1][j] = vp[i][vp[i][j]];
    }

    int climb(int a, int d){
        while(d){
            a = vp[__builtin_ctz(d)][a]; d &= (d - 1);
        }    
        return a;
    }

    int lca(int a, int b){
        if(lv[a] < lv[b]) swap(a, b);
        a = climb(a, lv[a] - lv[b]);
        if(a == b) return a;
        dfor(i, lgn) if(vp[i][a] != vp[i][b]){
            a = vp[i][a], b = vp[i][b];
        }
        return vp[0][a];
    }

    int dist(int a, int b){
        return lv[a] + lv[b] - 2 * lv[lca(a, b)];
    }
};