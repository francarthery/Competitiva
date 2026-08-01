#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x <<" = "; for(auto e  : x ) cout<<e<< ' ';}cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out","w", stdout);
    #endif

    int n, m, k; cin >> n >> m >> k;
    vector<string> v(n);
    forn(i, n) cin >> v[i];

    vector<vector<int>> vis(n, vector<int>(m));
    vector<ii> mov{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    function<void(int, int)> dfs = [&](int i, int j) {
        forn(t, 4) {
            int ni = i + mov[t].first, nj = j + mov[t].second;
            if(ni >= 0 and ni < n and nj >= 0 and nj < m and !vis[ni][nj] and v[ni][nj] != '#') {
                vis[ni][nj] = true;
                dfs(ni, nj);
            }
        }
        if(k) {
            v[i][j] = 'X';
            k--;
        }
    };  

    bool ok = false;
    forn(i, n) forn(j, m) if(!ok and v[i][j] != '#') {
        dfs(i, j);
        ok = true;
    }

    forn(i, n) cout << v[i] << '\n';
    

    
    return 0;
}