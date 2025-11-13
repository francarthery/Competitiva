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
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, q, a, b; cin >> n >> q;
    vector<int> v(n);
    vector<vector<int>> g(n);
    
    forn(i, n) cin >> v[i];
    forn(i, n - 1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
    }

    map<int, vector<ii>> que; //las queries de cada persona
    vector<int> rta(q);
    forn(i, q){
        cin >> a >> b; a--;
        que[a].pb({b, i});
    }

    function<unordered_map<int, int>(int)> dfs = [&](int s) -> unordered_map<int, int>{
        unordered_map<int, int> ans;

        for(int &u : g[s]) {
            unordered_map<int, int> aux = dfs(u);
            if(sz(ans)) {
                if(sz(ans) > sz(aux)) for(auto &i : aux) ans[i.fr] += i.sc;
                else {
                    for(auto &i : ans) aux[i.fr] += i.sc;
                    ans.swap(aux);
                }
            }
            else ans.swap(aux);
        }
        
        ans[v[s]]++;
        for(ii &i : que[s]) rta[i.sc] = ans[i.fr];

        return ans;
    };
    dfs(0);

    for(int &i : rta) cout << i << '\n';


    return 0;
}