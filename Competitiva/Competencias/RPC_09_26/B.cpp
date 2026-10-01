#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
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

    int n, m; 
    while(cin >> n >> m and (n or m)){
        vector<string> v(n);
        ii ini;
        forn(i, n) {
            cin >> v[i];
            forn(j, m) if(v[i][j] == '*') ini = {i, j};
        }

        vector<ii> mov{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<ii> q;
        vector<vector<int>> vis(n, vector<int>(m));
        vis[ini.first][ini.second] = 1;

        q.push(ini);
        int cont = 1;
        while(sz(q)) {
            ii s = q.front();
            q.pop();
            forn(t, 4) {
                int ni = s.first + mov[t].first, nj = s.second + mov[t].second;
                if(ni >= 0 and ni < n and nj >= 0 and nj < m and !vis[ni][nj] and v[ni][nj] != '#') {
                    cont++;
                    q.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }
        }

        cout << cont << '\n';
    }

    return 0;
}