#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ws <<" "<<
#define nl cout<<"\n";
#define dbg(x) cout<<#x ws "=" ws x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}


using namespace std;
typedef pair<int, int> ii;

struct Hopcroftkarp {
    int n, m; 
    vector<vector<int>> g;
    vector<int> mt, mt2, ds;
    Hopcroftkarp(int nn, int mm) : n(nn), m(mm), g(n) {}
    void add(int a, int b) {g[a].push_back(b);}
    bool bfs() {
        queue<int> q;
        ds = vector<int>(n, -1);
        forn(i, n) if(mt2[i] < 0) ds[i] = 0, q.push(i);
        bool r = false;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int y : g[x]) {
                if(mt[y] >= 0 && ds[mt[y]] < 0) {
                    ds[mt[y]] = ds[x] + 1, q.push(mt[y]);
                } else if(mt[y] < 0) r = true;
            }
        }
        return r;
    }
    bool dfs(int x) {
        for(int y : g[x]) {
            if(mt[y] < 0 || ds[mt[y]] == ds[x] + 1 && dfs(mt[y])) {
                mt[y] = x, mt2[x] = y;
                return true;
            }
        }
        ds[x] = 1 << 30;
        return false;
    }
    int nm() {
        int r = 0;
        mt = vector<int>(m, -1);
        mt2 = vector<int>(n, -1);
        while(bfs()) forn(i, n) if(mt2[i] < 0) r += dfs(i);
        return r;
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<array<int, 3>> ar(m);
    forn(i, m) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        ar[i] = {c, a, b};
    }
    sort(all(ar));

    int l = 0, r = 1e9+10;
    while(r-l > 1) {
        int mid = (r+l) / 2;

        Hopcroftkarp hk(n, n);
        forn(i, m) {
            if(ar[i][0] > mid) break;
            hk.add(ar[i][1], ar[i][2]);
        }

        if(hk.nm() == n) r = mid;
        else l = mid;
    }

    if(r == 1e9+10) cout << -1 << '\n';
    else cout << r << '\n';
        
    return 0;
}