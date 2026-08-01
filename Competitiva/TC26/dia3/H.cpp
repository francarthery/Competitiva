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

    int n, m; cin >> n >> m;
    vector<vector<pair<char, int>>> g(n), g2(n);
    vector<pair<ii, char>> ar(m);
    int a, b;
    char c;
    forn(i, m) {
        cin >> a >> b >> c;
        a--; b--;
        ar[i] = {{a, b}, c};
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    vector<int> dist1(n, -1), dist2(n, -1);

    auto bfs = [&](int ini, vector<int> &vis) {
        queue<int> q;
        q.push(ini);
        vis[ini] = 0;

        while(sz(q)) {
            int s = q.front();
            q.pop();


            for(auto u : g[s]) {
                if(vis[u.second] == -1) {
                    vis[u.second] = vis[s] + 1;
                    q.push(u.second);
                }
            }
        }
    };

    bfs(0, dist1);
    bfs(n-1, dist2);

    forn(i, m) {
        int a = ar[i].first.first, b = ar[i].first.second;
        char c = ar[i].second;

        if(dist1[a] > dist1[b]) swap(a, b);
        if(dist1[a] + dist2[b] + 1 == dist1[n-1]) g2[a].push_back({c, b});
    }
    
    set<int> mi{0};
    vector<int> ans, fat(n, -1);
    vector<char> ans2;

    forn(i, dist1[n-1]) {
        map<char, set<int>> lvl2;
        char best = 'z';
        for(int j : mi) for(auto u : g2[j]) best = min(best, u.first);
        // vdbg(mi);
        for(int j : mi) {
            for(auto u : g2[j]) {
                lvl2[u.first].insert(u.second);
                if(u.first == best) fat[u.second] = j;
            }
        }
        
        ans2.push_back(lvl2.begin() -> first);
        mi = lvl2.begin() -> second;
    }
    // vdbg(fat);
    int fin = n-1;
    ans.push_back(n-1);
    while(fat[fin] != -1) {
        ans.push_back(fat[fin]);
        fin = fat[fin];
    }

    cout << sz(ans2) << '\n';
    dfor(i, sz(ans)) cout << ans[i] + 1 << ' ';
    cout << '\n';
    forn(i, sz(ans2)) cout << ans2[i];
    cout << '\n';

    return 0;
}