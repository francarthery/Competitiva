#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define forall(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);    
    freopen("out","w",stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<string> v(n);
    ii ini;
    forn(i, n) {
        cin >> v[i];
        forn(j, m) if(v[i][j] == 'S') ini = {i, j};
    }

    vector<vector<int>> vis(n, vector<int>(m)), vis2(n, vector<int>(m));
    vector<ii> mov{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    queue<ii> q;
    q.push(ini);
    while(sz(q)){
        ii s = q.front();
        q.pop();

        forn(t, 4) {
            int ni = s.first + mov[t].first, nj = s.second + mov[t].second;
            if(ni >= 0 and ni < n and nj >= 0 and nj < m and !vis[ni][nj] and v[ni][nj] != '#') {
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
    // forn(i, n) {
    //     forn(j, m) cout << vis[i][j] << ' ';
    //     cout << '\n';
    // }

    queue<array<int, 4>> q2;
    q2.push({ini.first, ini.second, 0, 0});
    bool ok = false;
    while(sz(q2)) {
        auto [i, j, ti, tj] = q2.front();
        // cout << i << ' ' << j << ' ' << ti << ' ' << tj << '\n';
        q2.pop();
        if(vis[i][j] and (ti or tj)) {
            ok = true;
        }

        forn(t, 4) {
            int ni = i + mov[t].first, nj = j + mov[t].second;
            int nti = ti, ntj = tj;
            if(ni >= n) nti++;
            if(ni < 0) nti--;
            if(nj >= m) ntj++;
            if(nj < 0) ntj--;
            ni = (ni + n) % n;
            nj = (nj + m) % m;

            if(!vis2[ni][nj] and v[ni][nj] != '#') {
                vis2[ni][nj] = true;
                q2.push({ni, nj, nti, ntj});
            }   
        }
    } 
    // forn(i, n) {
    //     forn(j, m) cout << vis2[i][j] << ' ';
    //     cout << '\n';
    // }
    

    cout << (ok ? "Yes" : "No") << '\n';

    
    return 0;
}