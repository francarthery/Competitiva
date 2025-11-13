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
typedef pair<ll, ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int b, n; cin >> b >> n;
    vector<int> c(n), w(n), idx(n);
    vector<tuple<string, string, string>> v(n);
    map<string, vector<int>> m;
    map<string, int> m2;

    int dist = 0;
    forn(i, n){
        auto &[x, y, z] = v[i];
        cin >> x >> y >> z >> c[i] >> w[i];
        m[x].pb(i);
        if(!m2.count(x)) {
            m2[x] = ++dist;
            idx[i] = dist;
        }
    }

    vector<vector<int>> g(n), g2(n); //g2 solo tiene padres distintos
    vector<int> gr(n);
    queue<int> q;
    vector<ii> chosen(dist);
    
    forn(i, n){
        auto &[x, y, z] = v[i];
        for(int s : m[y]) g[s].pb(i);
        for(int s : m[z]) g[s].pb(i);
        gr[i] += sz(m[y]) + sz(m[z]);
        g2[i].pb(m2[y]);
        g2[i].pb(m2[z]);
        if(gr[i] == 0) q.push(i);
    }

    while(sz(q)){
        int s = q.front();
        q.pop();
        if(gr[s]) continue;

        ll cost = c[s], prof = w[s];
        for(int u : g2[s]){
            cost += chosen[idx[u]].fr;
            prof += chosen[idx[u]].sc;
        }
        if(chosen[idx[s]] == ii(0, 0) or chosen[idx[s]].fr > cost or chosen[idx[s]].fr == cost and chosen[idx[s]].sc < prof) chosen[idx[s]] = {cost, prof};
        
        for(int u : g[s]){
            gr[u]--;
            q.push(u);
        }
    }

    vector<ll> dp(b + 1);
    forn(i, dist){
        dfor(j, b + 1 - chosen[i].fr){
            dp[i + chosen[i].fr] = max(dp[i + chosen[i].fr], dp[i] + chosen[i].sc);
        }
    }
    for(auto i : chosen) cout << i.fr << ' ' << i.sc << '\n';
    
    int tarasca = b;
    dfor(i, b){
        if(dp[i] == dp[b]) tarasca = i;
    }
    cout << tarasca << '\n' << dp[b] << '\n';


    return 0;
}