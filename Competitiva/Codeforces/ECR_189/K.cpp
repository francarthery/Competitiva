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

    int n, m;
    while(cin >> n >> m) {
        vector<string> g(n);
        forn(i, n) cin >> g[i];
        vector<ii> mov{{0,1},{0,-1},{-1,0},{1,0}};

        vector<vector<bool>> blocked(n, vector<bool>(m)), vis(n, vector<bool>(m));
        queue<ii> q;
        forn(i, n) forn(j, m) {
            if(g[i][j] == 'S') {
                q.push({i, j});
                vis[i][j] = 0;
            }
            else if(g[i][j] == 'T') {
                forn(t, 4) {
                    int ni = i + mov[t].fr, nj = j + mov[t].sc;
                    if(ni < n and ni >= 0 and nj < m and nj >= 0) blocked[ni][nj] = true;
                }
            }
        }

        ll ans = 0;
        while(sz(q)){
            ii s = q.front();
            q.pop();

            if(g[s.fr][s.sc] <= '9' and g[s.fr][s.sc] >= '0') ans += g[s.fr][s.sc] - '0';
            
            if(!blocked[s.fr][s.sc]) forn(t, 4) { //No tengo una trampa cerca.
                int ni = s.fr + mov[t].fr, nj = s.sc + mov[t].sc;
                if(ni < n and ni >= 0 and nj < m and nj >= 0 and g[ni][nj] != '#' and vis[ni][nj] != true) {
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                } 
            }
        }

        cout << ans << '\n';
    }

    return 0;
}