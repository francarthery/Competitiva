#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> ii;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
 
    int n; cin >> n;
    vector<vector<int>> g(n);
    int a, b;
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
 
    vector<ii> ans(n);
    function<void(int, int)> dfs = [&](int s, int f){
        ans[s].sc = 1;
        for(int u : g[s]){
            if(u == f) continue;
            dfs(u, s);
            ans[s].fr += ans[u].fr + ans[u].sc; //res del hijo + cant nodos hijo (aumenta en 1 las dist a cada hijo)
            ans[s].sc += ans[u].sc;
        }
    };
 
    // function<void(int, int, ii)> dfs2 = [&](int s, int f, ii pad) -> void {
    //     ans[s].fr += pad.fr + pad.sc; //Mi idea
    //     ans[s].sc += pad.sc; //Calculo la suma total ruteado en ese nodo
    //     for(int u : g[s]) {
    //         if(u == f) continue;
    //         ii envio = ans[s]; //A mi hijo le paso mi ans - lo que aporto el a esta
    //         envio.fr -= ans[u].fr + ans[u].sc;
    //         envio.sc -= ans[u].sc;
    //         dfs2(u, s, envio);       
    //     }
    // };

    function<void(int, int)> dfs2 = [&](int s, int f) -> void { //Editorial
        for(int u : g[s]) { //Cuando avanzo a un nodo u, la respuesta decrece en cant nodos subarbol de u
            if(u == f) continue; //Pero crece en (n - cant nodos subarbol de u)
            ans[u].fr = ans[s].fr - ans[u].sc + (n - ans[u].sc);
            dfs2(u, s);       
        }
    };
 
    dfs(0, -1);
    dfs2(0, -1);
    for(ii i : ans) cout << i.fr << ' ';
    cout << '\n';
 
    return 0;
}