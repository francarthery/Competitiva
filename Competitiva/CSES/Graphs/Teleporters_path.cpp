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

// Be careful with nodes with degree 0 when solving your problem, the
// comments below assume that there are no nodes with degree 0.
//
// Euler [path/cycle] exists in a bidirectional graph iff the graph is
// connected and at most [2/0] nodes have odd degree. The path must
// start from an odd degree vertex when there are 2.
//
// Euler [path/cycle] exists in a directed graph iff the graph is
// [connected when making edges bidirectional / a single SCC], and
// at most [1/0] node have indg - outdg = 1, at most [1/0] node have
// outdg - indg = 1, all the other nodes have indg = outdg. The path
// must start from the node with outdg - indg = 1, when there is one.
//
// Directed version (uncomment commented code for undirected)
struct edge {
    int y;
    //list<edge>::iterator rev;
    edge(int yy) : y(yy) {}
};

struct EulerPath {
    vector<list<edge>> g;
    EulerPath(int n) : g(n) {}
    void addEdge(int a, int b) {
        g[a].push_front(edge(b));
        //auto ia = g[a].begin();
        //g[b].push_front(edge(a));
        //auto ib = g[b].begin();
        //ia->rev=ib, ib->rev=ia;
    }
    vector<int> p;
    void go(int x) {
        while (sz(g[x])) {
            int y = g[x].front().y;
            //g[y].erase(g[x].front().rev);
            g[x].pop_front();
            go(y);
        }
        p.push_back(x);
    }
    vector<int> getPath(int x) {  // get a path that starts from x
      // you must check that a path exists from x before calling get_path!
      p.clear(), go(x);
      reverse(p.begin(), p.end());
      return p;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> degin(n), degout(n);
    vector<int> vis(n);
    EulerPath ep(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
        ep.addEdge(a, b);
        degout[a]++; degin[b]++;
    }

    function<void(int, int)> dfs = [&](int s, int c){
        if(vis[s]) return;
        vis[s] = c;

        for(int &u : g[s]) dfs(u, c);
    };

    int col = 1; 
    forn(i, n) if(!vis[i]) dfs(i, col++);

    int c_ma = 0, c_mi = 0, comp = 0;
    vector<int> cols(col); //cantidad nodos por comp
    forn(i, n) {
        if(degout[i] - degin[i] == 1) c_ma++;
        else if(degout[i] - degin[i] == -1) c_mi++;
        else if(abs(degout[i] - degin[i]) > 1) c_ma = 2; //No puede pasar
        cols[vis[i]]++;
    }
    for(int &i : cols) if(i > 1) comp++; //Solo una componente con aristas

    //el nodo 1 tiene que tener g_out - g_in = 1 y el nodo n g_in - g_out = 1 para que se cumple. tienen que estar en la misma comp
    if((c_ma == 1 and c_mi == 1) and cols[1] > 1 and vis[0] == vis[n - 1] and comp < 2 and degout[0] - degin[0] == 1 and degin[n - 1] - degout[n - 1] == 1){ 
        vector<int> path = ep.getPath(0);
        forn(i, sz(path)) cout << path[i] + 1 << ' ';
        cout << '\n'; 
    }
    else cout << "IMPOSSIBLE\n";


    
    return 0;
}