#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define forall(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto  e : x) cout<<e<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
        freopen("input.in","r",stdin);
        freopen("output.out","w",stdout);
    #endif
    
    int n, m, h, d; cin >> n >> m >> h >> d;
    vector<string> g(n);
    forn(i, n) cin >> g[i];

    vector<ii> mov{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    vector<vector<int>> viss, visi, viso;

    auto bfs = [&](set<char> inis, int movs, vector<vector<int>> &vis) {
        int isla = inis.count('A');
        queue<ii> q;
        vis.assign(n, vector<int>(m, 1e9));
        forn(i, n) forn(j, m) if(inis.count(g[i][j]) and viss[i][j] > h) {
            q.push({i, j});
            vis[i][j] = 0;
        }

        while(sz(q)) {
            ii s = q.front();
            q.pop();

            forn(i, movs) {
                int ni = s.first + mov[i].first, nj = s.second + mov[i].second;
                if(ni >= 0 and ni < n and nj >= 0 and nj < m and vis[ni][nj] == 1e9) {
                    if(isla and viss[ni][nj] <= h) continue;
                    q.push({ni, nj});
                    vis[ni][nj] = vis[s.first][s.second] + 1;
                }
            }
        }
    };

    bfs(set<char>{'S', 'B'}, 8, viss);
    bfs(set<char>{'R', 'Y', 'A'}, 4, visi);

    queue<ii> q;
    viso.assign(n, vector<int>(m, 1e9));
    forn(i, n) forn(j, m) if(g[i][j] == 'Y') {
        q.push({i, j});
        viso[i][j] = 0;
    }

    while(sz(q)) {
        ii s = q.front();
        q.pop();

        forn(i, 4) {
            int ni = s.first + mov[i].first, nj = s.second + mov[i].second;
            if(ni >= 0 and ni < n and nj >= 0 and nj < m and viso[ni][nj] == 1e9 
                and viss[ni][nj] > h and visi[ni][nj] <= d and (g[ni][nj] == '.' or g[ni][nj] == 'A')) {
                q.push({ni, nj});
                viso[ni][nj] = viso[s.first][s.second] + 1;
            }
        }
    }

    forn(i, n) forn(j, m) if(g[i][j] == 'A') {
        if(viso[i][j] == 1e9) cout << "OSIDEO WILL DIE\n";
        else cout << viso[i][j] << '\n';
    }


    return 0;
}