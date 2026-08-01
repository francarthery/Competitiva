#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x){cout<<#x<<" = "<<x; for(auto e : x) cout<<x<<' ';cout<<endl;}
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

    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> gr(n);
    int a, b, ma = 0;
    forn(i, n-1) {
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        gr[a]++; gr[b]++;
        ma = max({ma, gr[a], gr[b]});
    }

    vector<int> color(n);
    function<void(int, int, int)> dfs = [&](int s, int f, int proh) {
        int col = 0;
        for(int u : g[s]) if(u != f) {
            while(col == proh or col == color[s]) col++;
            color[u] = col;
            col++;
        }
        for(int u : g[s]) if(u != f) dfs(u, s, color[s]);
    };

    color[0] = 0;
    dfs(0, -1, -1);

    cout << ma+1 << '\n';
    for(int i : color) cout << i+1 << ' ';
    cout << '\n';


    return 0;
}