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
    
    int n, m; cin >> n >> m;
    vector<string> v(n);
    forn(i, n) cin >> v[i];
    ii x1, x2;
    cin >> x1.first >> x1.second;
    cin >> x2.first >> x2.second;
    x1.first--; x1.second--; x2.first--; x2.second--;

    int vis[n][m][n][m];
    memset(vis, -1, sizeof(vis));

    auto chk = [&](int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m and v[i][j] != 'O';
    };

    queue<array<int, 4>> q;
    q.push({x1.first, x1.second, x2.first, x2.second});
    vis[x1.first][x1.second][x2.first][x2.second] = 0;
    vector<ii> mov{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = -1;

    if(v[x1.first][x1.second] == 'G' and v[x2.first][x2.second] == 'G') ans = 0;

    while(ans == -1 and sz(q)) {
        auto [i1, j1, i2, j2] = q.front();
        q.pop();

        forn(t, 4) {
            int ni1 = i1, nj1 = j1, ni2 = i2, nj2 = j2;
            
            while(1) {
                bool sw = false;
                if(t == 0 and ni1 > ni2 or t == 1 and ni1 < ni2 or t == 2 and nj1 > nj2 or t == 3 and nj1 < nj2) {
                    swap(ni1, ni2); //Primero muevo la que va adelante para que no se traben
                    swap(nj1, nj2);
                    sw = true;
                }
                ni1+=mov[t].first, nj1+=mov[t].second;
                ni2+=mov[t].first, nj2+=mov[t].second;

                bool move1 = true, move2 = true;
                if(!chk(ni1, nj1) or !chk(ni2, nj2)) break;
                if(v[ni1][nj1] == '#') ni1-=mov[t].first, nj1-=mov[t].second, move1 = false;
                if(v[ni2][nj2] == '#' or ni2 == ni1 and nj2 == nj1) ni2-=mov[t].first, nj2-=mov[t].second, move2 = false;

                if(!move1 and !move2) break; //me choque dos paredes
                
                if(sw) {
                    swap(ni1, ni2); 
                    swap(nj1, nj2);
                }
                if(vis[ni1][nj1][ni2][nj2] != -1) continue;
                
                q.push({ni1, nj1, ni2, nj2});
                vis[ni1][nj1][ni2][nj2] = vis[i1][j1][i2][j2] + 1;
                if(ans == -1 and v[ni1][nj1] == 'G' and v[ni2][nj2] == 'G') {
                    ans = vis[ni1][nj1][ni2][nj2];
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}