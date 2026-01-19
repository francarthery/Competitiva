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

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n), g2(n);
    vector<ii> ar(m);
    int a, b, q, ans = -2;
    forn(i, m) {
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
        ar[i] = {a, b};
    }

    vector<int> dist(n, -1), lay, din(n), dout(n), vis(n); 
    auto bfs = [&](int s, bool flag, vector<vector<int>> &g){
        queue<int> q;
        q.push(s);
        dist[s] = 0;

        while(sz(q)) {
            int s = q.front();
            q.pop();
            if(flag) lay[dist[s]]++;

            for(int u : g[s]) {
                if(dist[u] == -1) {
                    dist[u] = dist[s] + 1;
                    q.push(u);
                }
            }
        }
    };

    function<void(int)> dfs = [&](int s) {
        if(s != 0 and s != n - 1 and (!din[s] or !dout[s])) {
            vis[s] = true; //Fallecio
            lay[dist[s]]--;
            if(lay[dist[s]] == 1) ans++;
            else if(!lay[dist[s]]) ans = -1;
        }
        else return;

        for(int u : g2[s]) {
            if(vis[u]) continue;
            if(dist[u] > dist[s]) din[u]--;
            else dout[u]--;
            dfs(u);
        }
    };

    bfs(n - 1, false, g);
    vector<int> dist2 = dist;
    dist = vector<int>(n, -1);
    bfs(0, false, g);

    forn(i, m) {
        a = ar[i].fr, b = ar[i].sc;
        if(dist[a] > dist[b]) swap(a, b);
        if(dist[a] + dist2[b] + 1 == dist[n - 1]) {
            g2[a].pb(b);
            g2[b].pb(a);
            dout[a]++; din[b]++;
        } 
    }

    lay.resize(dist[n - 1] + 1);
    dist = vector<int>(n, -1);
    bfs(0, true, g2);

    forn(i, sz(lay)) if(lay[i] == 1) ans++;
    forn(i, k) {
        cin >> q; q--;
        cout << ans << ' ';
        if(ans != -1 and din[q] and dout[q]) {
            din[q] = dout[q] = 0;
            dfs(q);  
        }      
    }

    cout << ans << '\n';


    return 0;
}