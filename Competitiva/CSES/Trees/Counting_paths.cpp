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

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n), paths(n);
    int a, b; 
    forn(i, n-1) {
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn(i, m) {
        cin >> a >> b; a--; b--;
        paths[a].pb(i);
        paths[b].pb(i);
    }

    vector<set<int>> nodes(n);
    vector<int> ans(n);
    function<void(int, int)> dfs = [&](int s, int f) {
        for(int u : g[s]) {
            if(u == f) continue;
            dfs(u, s);
            if(sz(nodes[u]) > sz(nodes[s])) nodes[u].swap(nodes[s]);
            for(int i : nodes[u]) {
                if(!nodes[s].count(i)) nodes[s].insert(i);
                else { //Capaz yo soy el lca de los dos extremos del path
                    nodes[s].erase(i);
                    ans[s]++;
                }   
            } 
        }

        for(int i : paths[s]) {
            if(!nodes[s].count(i)) nodes[s].insert(i); //Empieza en mi el path
            else {
                nodes[s].erase(i);
                ans[s]++; //termina en mi el path
            }
        }
        ans[s] += sz(nodes[s]); //Los que actualmente siguen abiertos
    };

    dfs(0, -1);
    for(int i : ans) cout << i << ' ';
    cout << '\n';


    return 0;
}
