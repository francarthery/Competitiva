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

    int n, x; cin >> n;
    vector<vector<int>> g(n);
    vector<ll> w(n), leafs(n);

    forn(i, n - 1){
        cin >> x;
        g[x - 1].pb(i + 1);
    }
    forn(i, n) cin >> w[i];


    bool imposible = false;
    function<ll(int)> dfs1 = [&](int s) -> ll {
        if(!sz(g[s])) return leafs[s] = max(1ll, w[s]); //si no tengo el valor de la hoja le meto 1 para que la sol sea unica
        ll nose = 0, sum = 0, hojas = 0;
        for(int &u : g[s]){
            hojas += dfs1(u);
            if(w[u]) sum += w[u];
            else nose++;
        }

        if(!nose and !w[s]) w[s] = sum;
        return leafs[s] = (!w[s] ? hojas : w[s]);
    };

    function<ll(int)> dfs2 = [&](int s) -> ll{
        ll sum = 0;
        vector<int> nose;
        for(int &u : g[s]) {
            if(!w[u]) nose.pb(u);
            else sum += w[u];
        }
        if(sz(nose) == 1) w[nose[0]] = w[s] - sum; //si no se un hijo despejo el valor
        else if(sz(nose) > 0) for(int &u : nose) w[u] = leafs[u]; //si no se mas de uno coloco la suma de las hojas de ese subarbol

        sum = 0;
        for(int &u : g[s]) sum += dfs2(u);
        if(sz(g[s]) and sum != w[s] or w[s] <= 0) imposible = true; //chequeo consistencia
        return w[s];
    };

    dfs1(0);
    dfs2(0);

    if(imposible) cout << "impossible\n";
    else for(ll i : w) cout << i << '\n';


    return 0;
}