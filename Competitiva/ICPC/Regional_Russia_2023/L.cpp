#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define dbg(x) cout<< #x <<" = "<< x<< endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef chichu
        freopen("in", "r", stdin);
        freopen("out" ,"w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<string> g(n);
    forn(i, n) cin >> g[i];

    vector<vector<ii>> mov{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}},
                            {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}}};
    deque<ii> q;
    
    vector<vector<int>> vis(n, vector<int>(m, 1e9));
    forn(i, m) {
        if(g[0][i] == '.') q.push_back({0, i}); 
        else q.push_front({0, i});
        vis[0][i] = g[0][i] == '.';
    }

    while(sz(q)){
        ii s = q.front();
        q.pop_front();
        int fila = s.first % 2;

        forn(tt, 5) {
            int ni = s.first + mov[fila][tt].first, nj = s.second + mov[fila][tt].second;
            if(ni < 0 or ni >= n or nj < 0 or nj >= m or vis[ni][nj] != 1e9) continue;

            if(vis[ni][nj] > vis[s.first][s.second] + (g[ni][nj] == '.' ? 1 : 0)){
                vis[ni][nj] = vis[s.first][s.second] + (g[ni][nj] == '.' ? 1 : 0);
                if(g[ni][nj] == '#') q.push_front({ni, nj});
                else q.push_back({ni, nj});
            }
        }
    }

    int best = 1e9;
    forn(i, m) best = min(best, vis[n-1][i]);
    cout << best << '\n';


    return 0;
}