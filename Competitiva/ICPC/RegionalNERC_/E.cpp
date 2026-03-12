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

    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<string> g(n);
        vector<vector<int>> ps(n, vector<int>(m));
        forn(i, n) {
            cin >> g[i];
            forn(j, m) if(g[i][j] == '.') ps[i][j] = 1;
        } 

        forn(j, m) dfor(i, n - 1) {
            if(g[i][j] == '.') ps[i][j] = ps[i + 1][j] + 1;
        }

        int ma = k;
        vector<vector<bool>> vis(n, vector<bool>(m));
        vis[0][0] = true;
        queue<ii> q;
        q.push({0, 0});

        vector<ii> mov{{1, 0}, {0, 1}, {0, -1}};
        //forn(i, n) vdbg(ps[i]);

        while(sz(q)){
            ii s = q.front();
            q.pop();

            forn(i, 3) {
                int nx = s.fr + mov[i].fr, ny = s.sc + mov[i].sc;
                if(nx < 0 or nx >= n or ny < 0 or ny >= m or vis[nx][ny] or ps[nx][ny] < k) continue;
                
                ma = max(ma, nx + k);
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        cout << ma << '\n';
    }



    return 0;
}