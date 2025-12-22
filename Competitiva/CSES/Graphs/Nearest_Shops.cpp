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

    int n, m, k, x; cin >> n >> m >> k;
    vector<bool> v(n);
    forn(i, k) cin >> x, v[--x] = true;

    vector<vector<int>> g(n);
    int a, b;
    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    queue<array<int, 3>> q; //nodo donde estoy parado, distancia minima, origen
    vector<vector<ii>> dist(n, vector<ii>(2, {-1, -1})); //Dos distancias minimas, de cada una (minimo, origen)

    forn(i, n) if(v[i]) {
        dist[i][0] = {0, i};
        q.push({i, 0, i}); 
    }
    
    while(sz(q)){
        auto [nodo, dis, orig] = q.front();
        q.pop();

        for(int u : g[nodo]) {
            if(dist[u][0].fr == -1) {
                dist[u][0] = {dis + 1, orig};
                q.push({u, dis + 1, orig});
            }
            else if(dist[u][0].sc != orig and dist[u][1].fr == -1) {
                dist[u][1] = {dis + 1, orig};
                q.push({u, dis + 1, orig});
            }
        }
    }

    forn(i, n){
        if(v[i]) cout << dist[i][1].fr << ' ';
        else cout << dist[i][0].fr << ' ';
    }
    cout << '\n';


    return 0;
}