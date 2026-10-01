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
typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<vector<ii>> g(n);
    int a, b;
    forn(i, m) {
        cin >> a >> b; a--; b--;
        g[a].pb({b, i});
        g[b].pb({a, i});
    }

    auto bfs = [&](int s, int lim) { // [0, lim) son 0, [lim, n] son 1
        vector<int> dist(n, 1e9);
        deque<ii> q;
        q.push_back({s, 0});
        dist[s] = 0;
        
        while(sz(q)) {
            auto [node, d] = q.front();
            q.pop_front();
            if(d > dist[node]) continue;

            for(auto u : g[node]) {
                int w = (u.second < lim ? 0 : 1);
                if(dist[u.first] > dist[node] + w) {
                    dist[u.first] = dist[node] + w;
                    if(w) q.push_back({u.first, dist[u.first]});
                    else q.push_front({u.first, dist[u.first]});
                }
            }
        }

        return dist[n-1];
    };

    vector<ld> best(m, 1e9);
    forn(i, m+1) {
        int d = bfs(0, i);
        forn(j, m) {
            int denom = max(0, j-i + 1);
            if(!denom) continue; //no es conveniente tener denom 0 y rompe todo
            // cout << d << '/' << denom << '\n';
            best[j] = min(best[j], (ld)d / denom);
        }
    }

    for(auto i : best) cout << fixed << setprecision(10) << i << '\n';


    return 0;
}