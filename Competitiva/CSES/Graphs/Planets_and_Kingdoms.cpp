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

struct Kosaraju {
    vector<vector<int>> G, gt;
    // nodos 0...N-1 ; componentes 0...cantcomp-1
    int N, cantcomp;
    vector<int> comp, used;
    stack<int> pila;
    Kosaraju(int n) : G(n), gt(n), N(n), comp(n) {}
    void addEdge(int a, int b) { G[a].pb(b), gt[b].pb(a); }
    void dfs1(int nodo) {
        used[nodo] = 1;
        forall(it, G[nodo]) if (!used[*it]) dfs1(*it);
        pila.push(nodo);
    }
    void dfs2(int nodo) {
        used[nodo] = 2;
        comp[nodo] = cantcomp - 1;
        forall(it, gt[nodo]) if (used[*it] != 2) dfs2(*it);
    }
    void run() {
        cantcomp = 0;
        used = vector<int>(N, 0);
        forn(i, N) if (!used[i]) dfs1(i);
        while (!pila.empty()) {
            if (used[pila.top()] != 2) {
                cantcomp++;
                dfs2(pila.top());
            }
            pila.pop();
        }
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
    Kosaraju ks(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        ks.addEdge(a, b);
    }

    ks.run();

    cout << ks.cantcomp << '\n';
    forn(i, n) cout << ks.comp[i] + 1 << ' ';
    cout << '\n';

    
    return 0;
}