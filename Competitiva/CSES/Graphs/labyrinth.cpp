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
vector<vector<char>> vis; //mov

ii bfs(int x, int y){
    queue<ii> q;
    q.push({x, y});
    vis[x][y] = 'A';

    while(!q.empty()){
        ii u = q.front();
        q.pop();
        if(v[u.fr][u.sc] == 'B') return u; //Llegue al destino. Retorno posicion

        if(u.fr > 0 and v[u.fr - 1][u.sc] != '#' and vis[u.fr - 1][u.sc] == '#') {
            vis[u.fr - 1][u.sc] = 'U'; 
            q.push({u.fr - 1, u.sc}); 
        }
        if(u.fr < n - 1 and v[u.fr + 1][u.sc] != '#' and vis[u.fr + 1][u.sc] == '#') {
            vis[u.fr + 1][u.sc] = 'D'; 
            q.push({u.fr + 1, u.sc}); 
        }
        if(u.sc > 0 and v[u.fr][u.sc - 1] != '#' and vis[u.fr][u.sc - 1] == '#') {
            vis[u.fr][u.sc - 1] = 'L'; 
            q.push({u.fr, u.sc - 1}); 
        }
        if(u.sc < m - 1 and v[u.fr][u.sc + 1] != '#' and vis[u.fr][u.sc + 1] == '#') {
            vis[u.fr][u.sc + 1] = 'R'; 
            q.push({u.fr, u.sc + 1}); 
        }
    }
    return {-1, -1};
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    ii pos;
    string sol;
    cin >> n >> m;
    v.resize(n);
    vis.assign(n, vector<char>(m, '#'));
    forn(i, n) cin >> v[i];
    forn(i, n) forn(j, m) if(v[i][j] == 'A') pos = bfs(i, j);
    if(pos == ii(-1, -1)) cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        while(v[pos.fr][pos.sc] != 'A'){ //Reconstruyo respuesta
            if(vis[pos.fr][pos.sc] == 'L') {pos.sc++; sol.pb('L');}
            if(vis[pos.fr][pos.sc] == 'R') {pos.sc--; sol.pb('R');}
            if(vis[pos.fr][pos.sc] == 'D') {pos.fr--; sol.pb('D');}
            if(vis[pos.fr][pos.sc] == 'U') {pos.fr++; sol.pb('U');}
        }
        reverse(all(sol));
        cout << sz(sol) << '\n' << sol << '\n';
    }    
    
    return 0;
}