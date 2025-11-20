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
typedef tuple<int, int, int> iii;

int n, m;
vector<string> g;
bool valid(int &x, int &y, int &pos){
    if(pos == 0 and (x >= n or x < 0 or y >= m or y < 0 or g[x][y] == '#')) return false;
    else if(pos == 1 and (x >= n or x < 0 or y >= m - 1 or y < 0 or g[x][y] == '#' or g[x][y + 1] == '#')) return false;
    else if(pos == 2 and (x >= n or x < 1 or y >= m or y < 0 or g[x][y] == '#' or g[x - 1][y] == '#')) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> m;
    g.resize(n);
    vector dir(n, vector(m, vector<pair<int, iii>>(3, pair<int, iii>(-1, iii(0, 0, 0))))); //Movimiento, anterior
    string l = "RULD";
    vector<vector<iii>> mov{ //por cada posible posicion y movimiento guardo (desp_i, desp_j, pos)
        {{0, 1, 1}, {-1, 0, 2}, {0, -2, 1}, {2, 0, 2}},
        {{0, 2, 0}, {-1, 0, 1}, {0, -1, 0}, {1, 0, 1}},
        {{0, 1, 2}, {-2, 0, 0}, {0, -1, 2}, {1, 0, 0}}
    };
    forn(i, n) cin >> g[i];

    ii o, d;
    forn(i, n) forn(j, m) {
        if(g[i][j] == 'C') o = {i, j};
        else if(g[i][j] == 'E') d = {i, j};
    }
    queue<iii> q; //(x, y, pos) 0 parada, 1 horizontal, 2 vertical
    q.push({o.fr, o.sc, 0});

    while(sz(q)){
        iii elem = q.front();
        auto &[x, y, pos] = elem;
        q.pop();

        forn(i, 4){
            int nx = x + get<0>(mov[pos][i]), ny = y + get<1>(mov[pos][i]), npos = get<2>(mov[pos][i]);
            if(valid(nx, ny, npos) and dir[nx][ny][npos].fr == -1) {
                dir[nx][ny][npos] = {i, elem}; //(0-R, 1-U, 2-L 3-D)
                q.push({nx, ny, npos});
            }
        }
    }

    if(dir[d.fr][d.sc][0].fr != -1){
        string rta;
        iii pos = {d.fr, d.sc, 0};
        while(pos != iii(o.fr, o.sc, 0)){
            rta += l[dir[get<0>(pos)][get<1>(pos)][get<2>(pos)].fr];
            pos = dir[get<0>(pos)][get<1>(pos)][get<2>(pos)].sc;
        }

        reverse(all(rta));
        cout << sz(rta) << '\n';
        cout << rta << '\n';
    }   
    else cout << -1 << '\n';

    
    return 0;
}