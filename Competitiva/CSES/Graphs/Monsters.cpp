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
 
const int inf = 1e9;
int n, m;
vector<string> g;
vector<vector<pair<ii, char>>> ant;
vector<vector<int>> dist1, dist2;
vector<int> px{1, 0, -1, 0}, py{0, 1, 0, -1};
vector<char> mov{'D', 'R', 'U', 'L'};
queue<ii> q;
bool adentro(int &i, int &j) {return (i >= 0 and i < n and j >= 0 and j < m);}
 
void bfs1(){
    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
 
        forn(i, 4){
            int nx = x + px[i], ny = y + py[y];
            if(adentro(nx, ny) and g[nx][ny] != '#' and dist1[nx][ny] == inf){
                q.push({nx, ny});
                dist1[nx][ny] = dist1[x][y] + 1;
            }
        }
    }
}
 
ii bfs2(int x, int y){
    dist2[x][y] = 0;
    queue<ii> q;
    q.push({x, y});
 
    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        if(x == 0 or x == n - 1 or y == 0 or y == m - 1) return {x, y};
 
        forn(i, 4){
            int nx = x + px[i], ny = y + py[i];
            if(adentro(nx, ny) and g[nx][ny] == '.' and dist2[x][y] + 1 < dist1[nx][ny] and dist2[x][y] + 1 < dist2[nx][ny]){
                q.push({nx, ny});
                dist2[nx][ny] = dist2[x][y] + 1;
                ant[nx][ny] = {{x, y}, mov[i]};
            }
        }
    }
    return {-1, -1};
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    cin >> n >> m;
    ii fin, ini;
    g.resize(n);
    ant.assign(n, vector<pair<ii, char>>(m));
    dist1.assign(n, vector<int>(m, inf));
    dist2.assign(n, vector<int>(m, inf));
 
    forn(i, n) cin >> g[i];
    forn(i, n) forn(j, m){
        if(g[i][j] == 'M') {
            q.push({i, j});
            dist1[i][j] = 0;
        }
        else if(g[i][j] == 'A') {
            ini = {i, j};
        }
    }
    bfs1();
    fin = bfs2(ini.fr, ini.sc);
 
    if(fin == make_pair(-1, -1)) cout << "NO\n";
    else{
        string ans;
        while(fin != ini){
            ans.pb(ant[fin.fr][fin.sc].sc);
            fin = ant[fin.fr][fin.sc].fr;
        }
        reverse(all(ans));
        cout << "YES\n" << sz(ans) << '\n' << ans << '\n';
    }
 
    
    return 0;
}