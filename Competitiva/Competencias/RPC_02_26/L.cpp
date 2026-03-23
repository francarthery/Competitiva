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

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    ll a, b, p, t;
    forn(i, n - 1) {
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<ll> spd(m), beg(m), dist(n, -1), pos(n, -1);
    vector<bool> chk(n), fallecio(m);

    forn(i, m) {
        cin >> p >> t; p--;
        pos[p] = i;
        spd[i] = t;
        beg[i] = p;
    }

    int ini, c; cin >> ini >> c; ini--;
    forn(i, c) {
        cin >> a; a--;
        chk[a] = true;
    }

    vector<vector<ii>> jug(n); //pos, dist

    function<void(int)> dfs = [&](int s) {
        for(int u : g[s]) { 
            if(dist[u] != -1) continue;
            dist[u] = dist[s] + 1;
            dfs(u);

            if(sz(jug[u]) > sz(jug[s])) jug[u].swap(jug[s]);
            forn(i, sz(jug[u])) jug[s].pb(jug[u][i]);
        }

        if(pos[s] != -1) jug[s].pb({pos[s], dist[s]});
        
        if(chk[s]) {
            sort(all(jug[s]), [&](ii &a, ii &b) {
                if((a.sc - dist[s]) * spd[a.fr] != (b.sc - dist[s]) * spd[b.fr])
                    return (a.sc - dist[s]) * spd[a.fr] < (b.sc - dist[s]) * spd[b.fr];
                else return spd[a.fr] < spd[b.fr];
            });
            
            while(sz(jug[s]) > k) {
                fallecio[jug[s].back().fr] = true;
                jug[s].pop_back();
            }
        }
    };

    dist[ini] = 0;
    dfs(ini);

    forn(i, m) {
        if(fallecio[i]) cout << -1 << '\n';
        else cout << dist[beg[i]] * spd[i] << '\n';
    }

    return 0;
}