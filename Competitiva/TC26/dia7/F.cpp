#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    forn(i,n) cin>>s[i];
    vector<vector<int>> dp(n, vector<int>(m));

    vector<vector<int>> vst(n, vector<int>(m));
    vector<vector<int>> cmp(n, vector<int>(m));
    vector<ii> movs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    auto dfs1 = [&](auto &&ff, int i, int j, int com) {
        if(vst[i][j])return;
        dp[i][j] = 1;
        vst[i][j] = 1;
        cmp[i][j] = com;
        for(auto [di, dj] : movs){
            int ni = i + di;
            int nj = j + dj;
            if(ni < 0 || ni >= n) continue;
            if(nj < 0 || nj >= m) continue;
            if(vst[ni][nj] == 0 && s[ni][nj] == '.'){
                ff(ff,ni,nj,com);
                dp[i][j] += dp[ni][nj];
            }
        }
    };

    auto dfs2 = [&] (auto &&ff, int i, int j, int cnt) {
        if(vst[i][j] == 2)return;
        dp[i][j] = cnt;
        vst[i][j] = 2;
        for(auto [di, dj] : movs){
            int ni = i + di;
            int nj = j + dj;
            if(ni < 0 || ni >= n) continue;
            if(nj < 0 || nj >= m) continue;
            if(vst[ni][nj] == 1){
                ff(ff,ni,nj,cnt);
            }
        }
    };

    int pedazos = 0;
    forn(i,n) forn(j,m) if(s[i][j] == '.'){
        dfs1(dfs1,i,j,pedazos);
        int cnt = dp[i][j];
        dfs2(dfs2,i,j,cnt);
        pedazos++;
    }

    // forn(i,n) vdbg(dp[i]);
    // forn(i,n) vdbg(cmp[i]);

    auto rtaf = s;
    forn(i,n) forn(j,m) if(s[i][j] == '*'){
        int rta = 1;
        set<int> cmps;
        for(auto [di, dj] : movs){
            int ni = i + di;
            int nj = j + dj;
            if(ni < 0 || ni >= n) continue;
            if(nj < 0 || nj >= m) continue;
            if(s[ni][nj] == '.' && cmps.count(cmp[ni][nj]) == 0){
                // cout<<i ws j ws ni ws nj;nl;
                cmps.insert(cmp[ni][nj]);
                rta += dp[ni][nj];
            }
        }
        rta %= 10;
        rtaf[i][j] = rta+'0';
    }

    forn(i,n) {cout<<rtaf[i];nl;}

    
    return 0;
}