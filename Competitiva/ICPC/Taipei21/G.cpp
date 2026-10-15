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
typedef array<int, 3> iii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--) {
        int m, n; cin >> m >> n;
        vector<vector<int>> g(n, vector<int>(m));
        forn(i, n) forn(j, m) cin >> g[i][j];
        ii ini;
        cin >> ini.second >> ini.first;

        int gn; cin >> gn;
        vector<vector<ii>> p(gn);
        int MAXT = 1;
        forn(i, gn) {
            int k; cin >> k;
            MAXT = lcm(MAXT, k);
            p[i].resize(k);
            forn(j, k) cin >> p[i][j].second >> p[i][j].first;
        }

        vector<ii> mov{{0,0},{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<vector<int>>> vis(MAXT, vector(n, vector<int>(m)));

        queue<iii> q;
        vis[0][ini.first][ini.second] = 0;
        q.push({0, ini.first, ini.second});

        ll ans = -1;
        while(sz(q)) {
            auto [t, i, j] = q.front();
            q.pop();
            if(g[i][j] == 0) {
                ans = t;
                break;
            }
            
            forn(tt, 5) {
                int ni = i + mov[tt].first, nj = j + mov[tt].second;
                int nt = t+1;
                if(ni < 0 or ni >= n or nj < 0 or nj >= m or g[ni][nj] > g[i][j]) continue;
                if(vis[nt%MAXT][ni][nj]) continue;

                bool poli = false;
                forn(i, gn) {
                    if(p[i][nt%sz(p[i])] == ii(ni, nj)) poli = true;
                    if(p[i][(nt-1+sz(p[i]))%sz(p[i])] == ii(ni, nj)) poli = true;
                }
                if(poli) continue; //cayo la policia

                q.push({nt, ni, nj});
                vis[nt%MAXT][ni][nj] = true;
            }
        }

        cout << ans << '\n';
    }   



    return 0;
}