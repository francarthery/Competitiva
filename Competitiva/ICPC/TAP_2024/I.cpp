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


// Euler [path/cycle] exists in a bidirectional graph iff the graph is
// connected and at most [2/0] nodes have odd degree. The path must
// start from an odd degree vertex when there are 2.
struct edge {
  int y;
  list<edge>::iterator rev;
  edge(int yy) : y(yy) {}
};
struct EulerPath {
  vector<list<edge>> g;
  EulerPath(int n) : g(n) {}

  void addEdge(int a, int b) {
    g[a].push_front(edge(b));
    auto ia = g[a].begin();
    g[b].push_front(edge(a));
    auto ib = g[b].begin();
    ia->rev=ib, ib->rev=ia;
  }
  vector<int> p;
  void go(int x) {
    while (sz(g[x])) {
      int y = g[x].front().y;
      g[y].erase(g[x].front().rev);
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

    int n, m; cin >> n >> m;
    EulerPath ep(n+m);
    vector<int> dg(n+m);
    int cant = 0, ini, tot = 0;
    forn(i, n) forn(j, m) {
        char c; cin >> c;
        if(c == '.') {
            ep.addEdge(i, j+n);
            dg[i]++;
            dg[j+n]++;
            ini = i; //por si son todos pares
            tot++;
        }
    }

    forn(i, n+m) if(dg[i] % 2) {
        cant++;
        ini = i;
    }

    if(cant != 2 and cant != 0) {
        cout << "*\n";
        return 0;
    }

    vector<int> path = ep.getPath(ini);

    if(sz(path) != tot+1) {
        cout << "*\n";
        return 0;
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));
    int sumo = 0;
    int i, j;
    if(path[0] >= n) j = path[0] - n;
    else i = path[0];
    forr(ind, 1, sz(path)) {
        if(path[ind] >= n) j = path[ind] - n;
        else i = path[ind];
        ans[i][j] = ++sumo;
    }

    forn(i, n) {
        for(int c : ans[i]) cout << c << ' ';
        cout << '\n';
    }

    return 0;
}