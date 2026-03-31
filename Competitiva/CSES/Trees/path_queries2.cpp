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

typedef ll tipo;
const tipo neutro = -1e9;
tipo oper(const tipo& a, const tipo& b) { return max(a, b); }
struct ST {
    int sz;
    vector<tipo> t;
    ST(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo>(2 * sz, neutro);
    }
    tipo& operator[](int p) { return t[sz + p]; }
    void updall() { dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
    tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
    tipo get(int i, int j, int n, int a, int b) {  // O(log n), [i, j)
        if (j <= a || b <= i) return neutro;
        if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
        int c = (a + b) / 2;
        return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }
    void set(int p, tipo val) {  // O(log n)
        p += sz;
        while (p > 0 && t[p] != val) {
            t[p] = val;
            p /= 2;
            val = oper(t[p * 2], t[p * 2 + 1]);
        }
    }
};  // Use: definir oper tipo neutro,
// cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

struct HLD { //Heavy-Light Decomposition mio
    int n, timer = 0;
    vector<int> head, w, dist, pos, par, vals;
    vector<vector<int>> g;

    HLD(int N) : n(N), head(N), w(N), g(N), dist(N), par(N), pos(N){}
    void addEdge(int a, int b) {g[a].pb(b); g[b].pb(a);}

    void dfs1(int s, int f) {
        w[s] = 1;
        int ma = 0, pos = -1;
        forn(i, sz(g[s])) {
            if(g[s][i] == f) continue;
            par[g[s][i]] = s;
            dist[g[s][i]] = dist[s]+1;
            dfs1(g[s][i], s);
            w[s] += w[g[s][i]];
            if(w[g[s][i]] > ma) { //dejo primero al mas pesado
                ma = w[g[s][i]];
                pos = i;
            }
        }
        if(pos != -1) swap(g[s][0], g[s][pos]);
    }

    void dfs2(int s, int f, int pad) {
        head[s] = pad;
        pos[s] = timer++;

        forn(i, sz(g[s])){
            if(g[s][i] == f) continue;
            if(!i) dfs2(g[s][i], s, pad);   //prolongo por el mas gordito
            else dfs2(g[s][i], s, g[s][i]); //arranco nuevo camino por los light
        }
    }

    void build(int root) {
        dfs1(root, -1); dfs2(root, -1, root);
    }

    tipo get(int a, int b, ST &st) {
        tipo ans = neutro;
        while(head[a] != head[b]) { 
            if(dist[head[a]] < dist[head[b]]) swap(a, b); //subo por el seg de head mas profundo
            ans = oper(ans, st.get(pos[head[a]], pos[a] + 1));
            a = par[head[a]];
        }
        if(dist[a] > dist[b]) swap(a, b); //quedaron en el mismo segmento
        ans = oper(ans, st.get(pos[a], pos[b] + 1));
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    //https://cses.fi/problemset/task/2134
    int n, q, a, b; cin >> n >> q;
    vector<int> vals(n);
    forn(i, n) cin >> vals[i];
    HLD hld(n);
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        hld.addEdge(a, b);
    }

    ST st(n);
    hld.build(0);
    forn(i, n) st.set(hld.pos[i], vals[i]); 

    forn(tt, q) {
        char c; cin >> c;
        int a, b, x;
        if(c == '1') {
            cin >> a >> x; a--;
            st.set(hld.pos[a], x);
        }
        else {
            cin >> a >> b; a--; b--;
            cout << hld.get(a, b, st) << ' ';
        }
    }
    cout << '\n';


    return 0;
}