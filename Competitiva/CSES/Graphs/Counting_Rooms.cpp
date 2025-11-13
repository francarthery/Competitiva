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

int n, m;
vector<string> v;
vector<vector<bool>> vis;

void dfs(int x, int y){
    if(vis[x][y]) return;
    vis[x][y] = true;
    if(x > 0 and v[x - 1][y] == '.') dfs(x - 1, y);
    if(x < n - 1 and v[x + 1][y] == '.') dfs(x + 1, y);
    if(y > 0 and v[x][y - 1] == '.') dfs(x, y - 1);
    if(y < m - 1 and v[x][y + 1] == '.') dfs(x, y + 1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    cin >> n >> m;
    int cont = 0;
    v.resize(n);
    forn(i, n) cin >> v[i];
    vis.assign(n, vector<bool>(m));
    forn(i, n) forn(j, m){
        if(v[i][j] == '.' and !vis[i][j]){
            dfs(i, j);
            cont++;
        }
    }

    cout << cont << '\n';
    
    return 0;
}