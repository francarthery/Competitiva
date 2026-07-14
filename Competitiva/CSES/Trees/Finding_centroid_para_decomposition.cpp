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

    int a, b, n; cin >> n;
    vector<vector<int>> g(n);
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> tam(n);

    function<void(int, int)> dfs = [&](int s, int f) {
        tam[s] = 1;
        for(int u : g[s]) if(u != f) {
            dfs(u, s);
            tam[s] += tam[u];
        }
    };

    function<int(int, int)> centroide = [&](int s, int szcomp) -> int{
        tam[s] = 0; //Con esto me evito llevar el padre
        for(int u : g[s]) if(tam[u] > szcomp / 2) { //Si el nodo no tiene hijos con mas de piso(n/2) nodos, es el centroide
            return centroide(u, szcomp);
        }
        return s; 
    };
    
    dfs(0, -1);
    cout << centroide(0, tam[0]) + 1 << '\n';

    return 0;
}