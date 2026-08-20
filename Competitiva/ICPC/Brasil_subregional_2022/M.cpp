#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(int)(a);i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=0;i>=0;i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
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
    freopen("input.in","r", stdin);
    freopen("output.out","w", stdout);
    #endif

    int q; cin >> q;
    vector<vector<int>> g(q+1);
    int cont = 1;
    vector<ii> queries(q);
    forn(i, q) {
        int t, a; cin >> t >> a; a--;
        if(t==1) {
            g[a].push_back(cont);
            g[cont].push_back(a);
            queries[i] = {t, cont};
            cont++;
        }
        else queries[i] = {t, a};
    }
    
    vector<int> euler, pos(q+1);
    auto func = [&](auto &&dfs, int s, int f) -> void {
        euler.push_back(s);
        for(int u : g[s]) if(u != f) dfs(dfs, u, s);
    };

    func(func, 0, -1);
    forn(i, sz(euler)) {
        pos[euler[i]] = i;
    }

    // vdbg(euler); vdbg(pos);
    set<int> vivos{0};
    // forn(i, q) cout << queries[i].first << ' ' << queries[i].second << '\n';
    forn(i, q) {
        auto [t, a] = queries[i];
        if(t == 1) vivos.insert(pos[a]);
        else {
            vivos.erase(pos[a]);
            cout << euler[*vivos.begin()] + 1 << '\n';
        }
        // vdbg(vivos);
    }


    return 0;
}