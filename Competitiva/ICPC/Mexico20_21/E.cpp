#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x <<" = "<< x<<endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto i : x) cout<<i<<", "; cout<<"] \n";}
#define ws <<" "<<
#define nl cout<<"\n";


using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int main(){
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w",stdout);
    #endif

    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> g(n);
    int root = 0;
    forn(i, n) {
        int x; cin >> x; x--;
        if(x != -1) g[x].push_back(i);
        else root = i;
    }

    vector<ll> p(n), temp(n), son(n);
    int t, e, v;
    forn(i, m) {
        cin >> t >> e >> v; e--;
        if(t == 1) p[e] += v;
        else temp[e] += v;
    }

    function<void(int)> dfs = [&](int s) {
        for(int u : g[s]) {
            dfs(u);
            temp[s] += temp[u];
            son[s] += son[u];
        }
        p[s] += temp[s];
        son[s] += p[s];
    };

    dfs(root);
    forn(i, q) {
        cin >> t >> e; e--;
        if(t == 1) cout << p[e] << '\n';
        else cout << son[e] << '\n';
    }

    return 0;
}