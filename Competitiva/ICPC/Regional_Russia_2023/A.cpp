#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i++)
#define sz(x) (int(x.size()));
#define all(x) x.begin(), x.end()
#define dbg(x) cout<< #x <<" = "<< x<< endl;

using namespace std;
typedef pair<int, int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef chichu
        freopen("in", "r", stdin);
        freopen("out" ,"w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<string> v(n);
    vector<vector<bool>> dead(n, vector<bool>(m));
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    forn(i, n) cin >> v[i];
    
    vector<ii> mov{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    bool ok = true;
    forn(i, n) forn(j, m){
        bool valid = v[i][j] == '#';
        forn(tt, 8){
            int ni = i + mov[tt].first, nj = j + mov[tt].second;
            if(ni < 0 or ni >= n or nj < 0 or nj >= m) continue;
            if(v[ni][nj] == '.') valid = false;
        }
        if(valid) forn(tt, 8){
            int ni = i + mov[tt].first, nj = j + mov[tt].second;
            if(ni < 0 or ni >= n or nj < 0 or nj >= m) continue;
            dead[ni][nj] = true;
        }
        if(valid) {
            ans[i][j] = '#';
            dead[i][j] = true;
        }
    }
    forn(i, n) forn(j, m) if(!dead[i][j] and v[i][j] == '#') ok = false;

    cout << (ok ? "Possible" : "Impossible") << '\n';
    if(ok) forn(i, n) {
        forn(j, m) cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}