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

vector<bool> vis; //Se controlan los nodos visitados
vector<vector<vector<int>>> v;
bool flag = false;

void dfs(int s, int d, int col){
    if(vis[s] or flag) return;
    vis[s] = true;
    if(s == d){
        flag = true;
        return;
    }

    for(auto &i : v[col][s]){
        dfs(i, d, col);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, x, y, z, q, cont;
    cin >> n >> m;
    v.assign(m, vector<vector<int>>(n + 1));
    
    forn(i, m){
        cin >> x >> y >> z;
        v[z - 1][x].pb(y);
        v[z - 1][y].pb(x);
    }
    cin >> q;
    forn(t, q){
        cin >> x >> y;
        cont = 0;
        forn(i, m){
            flag = false;
            vis.assign(n + 1, 0);
            dfs(x, y, i);
            cont += flag;
        }
        cout << cont << '\n';
    }
    
    return 0;
}