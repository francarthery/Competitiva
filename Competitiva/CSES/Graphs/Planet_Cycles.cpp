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

vector<int> g, vis, bucles, info;
vector<vector<int>> gt;
int val = -1, comp = 1; 

void dfs(int s, int &col){
    if(vis[s] == col) {
        val = s;
        return;
    }
    vis[s] = col;
    dfs(g[s], col); 
}

void dfs2(int s, int d){
    for(auto &u : gt[s]){ //Al estar invertido puede haber mas de un hijo
        if(u == val) continue;
        else if(vis[s] == -2 and vis[u] != -2) {
            info[u] = 1;
            dfs2(u, 1);
        }
        else if(vis[s] != -2 and vis[u] != -2) {
            info[u] = {d + 1};
            dfs2(u, d + 1);
        }
        else {
            bucles[comp - 1]++; //guardo bucle 
            dfs2(u, 0);
        }
    }
    vis[s] = comp;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, x;
    cin >> n;
    g.resize(n);
    gt.resize(n);
    vis.resize(n);
    info.resize(n);

    forn(i, n) {
        cin >> x; x--;
        g[i] = x;
        gt[x].pb(i);
    }

    forn(i, n){
        if(vis[i] == 0) {
            val = -1;
            int col = -1;
            dfs(i, col); //Busco bucle
            col = -2;
            dfs(val, col); //pinto solo bucle
            
            bucles.pb(1); 
            dfs2(val, 0);
            vis[val] = comp;
            comp++;
        }
    }

    forn(i, n) cout << info[i] + bucles[vis[i] - 1] << ' ';
    cout << '\n';
    
    return 0;
}