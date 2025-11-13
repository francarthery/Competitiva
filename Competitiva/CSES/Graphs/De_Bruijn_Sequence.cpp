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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n"};
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct edge {
    int y;
    edge(int yy) : y(yy) {}
};
struct EulerPath {
    vector<list<edge>> g;
    EulerPath(int n) : g(n) {}
    void addEdge(int a, int b) {
    g[a].push_front(edge(b));
    }
    vector<int> p;
    void go(int x) {
    while (sz(g[x])) {
        int y = g[x].front().y;
        g[x].pop_front();
        go(y);
    }
    p.push_back(x);
    }
    vector<int> getPath(int x) {  // get a path that starts from x
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

    int n; cin >> n;
    if(n == 1){
        cout << "10\n";
        return 0;
    }
    EulerPath ep(1 << (n - 1));

    int mask = (1 << (n - 1)) - 1;
    forn(i, (1 << (n - 1))) {
        ep.addEdge(i, (((i << 1) | 1) & mask));
        ep.addEdge(i, (((i << 1)) & mask));
    }

    vector<int> euler = ep.getPath(0);
    string res(n - 1, '0');
    forr(i, 1, sz(euler)){
        res.pb((euler[i] & 1) + '0');
    }

    cout << res << '\n';



    /* forn(i, (1 << (n - 1))) {
        for(auto j : g[i]) cout << j.fr << ' ' << j.sc << "       ";
        cout << '\n';
    } */



    return 0;
}