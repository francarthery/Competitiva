#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

vector<int> dist, ant;
vector<vector<int>> g;

void bfs(int s){
    dist[0] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i : g[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                ant[i] = u;
                q.push(i);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, -1);
    ant.resize(n, -1);
    forn(i, m){
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    bfs(0);

    vector<int> ruta{n - 1};
    int prev = ant[n - 1];
    while(prev != -1) {
        ruta.pb(prev);
        prev = ant[prev];
    }
    reverse(all(ruta));

    if(ant[n - 1] != -1) {
        cout << sz(ruta) << '\n';
        for(int &i : ruta) cout << i + 1 << ' ';
    }
    else cout << "IMPOSSIBLE\n";
    
    return 0;
}