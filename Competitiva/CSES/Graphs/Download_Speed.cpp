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
const ll INF = 1e18;

struct EdmondsKarp {
    int N;
    vector<unordered_map<int, ll>> g;
    vector<int> p;
    ll f;
    EdmondsKarp(int n) : N(n), g(n), p(n) {}
    void addEdge(int a, int b, int w) { g[a][b] += w; }
    void augment(int v, int SRC, ll minE) {
        if (v == SRC) f = minE;
        else if (p[v] != -1) {
        augment(p[v], SRC, min(minE, g[p[v]][v]));
        g[p[v]][v] -= f, g[v][p[v]] += f;
        }
    }
    ll maxflow(int SRC, int SNK) {  // O(min(VE^2,Mf*E))
        ll ret = 0;
        do {
        queue<int> q;
        q.push(SRC);
        fill(p.begin(), p.end(), -1);
        f = 0;
        while (sz(q)) {
            int node = q.front();
            q.pop();
            if (node == SNK) break;
            forall(it, g[node]) if (it->sc > 0 && p[it->fr] == -1) {
            q.push(it->fr), p[it->fr] = node;
            }
        }
        augment(SNK, SRC, INF);  // INF > max possible flow
        ret += f;
        } while (f);
        return ret;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b, c;
    cin >> n >> m;
    EdmondsKarp ek(n);

    forn(i, m){
        cin >> a >> b >> c; a--; b--;
        ek.addEdge(a, b, c);
    }

    ll res = ek.maxflow(0, n - 1);
    cout << res << '\n';


    return 0;
}