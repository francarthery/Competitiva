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

    int t, cont = 0; cin >> t;
    while(t--){
        cont++;
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        vector<vector<bool>> vis(n, vector<bool>(m));
        forn(i, n) cin >> v[i];

        vector<ii> mov{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        function<bool(int&, int&)> in = [&](int &x, int &y) -> bool {return x >= 0 and x < n and y >= 0 and y < m;};
        
        int ma = 0;
        function<int(int, int, int, int)> dfs = [&](int i, int j, int ai, int aj) -> int { //diametro arbol
            int ma1 = 0, ma2 = 0, val;

            forn(tt, 4){
                int nx = i + mov[tt].fr, ny = j + mov[tt].sc;
                if(in(nx, ny) and v[nx][ny] == '.' and (nx != ai or ny != aj)){
                    val = dfs(nx, ny, i, j);
                    if(val > ma1) {
                        ma2 = ma1;
                        ma1 = val;
                    }
                    else if(val > ma2) ma2 = val;
                }    
            }
            ma = max(ma, ma1 + ma2);
            return ma1 + 1;
        };

        function<int(int, int, int, int)> dfs1 = [&](int i, int j, int ai, int aj) -> int {
            if(vis[i][j]) return 0;
            vis[i][j] = true;
            int tot = 1;
            forn(tt, 4){
                int nx = i + mov[tt].fr, ny = j + mov[tt].sc;
                if(in(nx, ny) and v[nx][ny] == '.' and (nx != ai or ny != aj)) tot += dfs1(nx, ny, i, j);
            }
            return tot;
        };

        int maxcomp = 0, color = 1;
        vector<ii> colmax;
        forn(i, n) forn(j, m){
            if(!vis[i][j] and v[i][j] == '.'){
                int tam = dfs1(i, j, -1, -1); //calculo tam de componentes
                if(tam > maxcomp){
                    maxcomp = tam;
                    colmax = vector<ii> {{i, j}};
                }
                else if(tam == maxcomp) colmax.pb({i, j});
                color++;
            }
        }

        int maxpath = 0;
        forn(i, sz(colmax)){
            ma = 0;
            dfs(colmax[i].fr, colmax[i].sc, -1, -1); //calculo diametro componente
            maxpath = max(maxpath, ma);
        }

        cout << "Case " << cont << ": " << color - 1 << ' ' << maxcomp << ' ' << maxpath << '\n';
    }

    return 0;
}