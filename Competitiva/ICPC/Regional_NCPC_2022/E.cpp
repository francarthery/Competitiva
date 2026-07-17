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

const int a1 = 31, a2 = 23, b1 = 1e9 + 7, b2 = 1e9 + 9;
vector<pair<ll, ll>> p, h;

void Hash(vector<int> &s){ //Preprocesa hash en O(n)
    p.resize(s.size());
    h.resize(s.size());

    p[0] = {1, 1};
    h[0] = {s[0], s[0]};
    for(int i = 1; i < s.size(); i++) {
        h[i].fr = (h[i - 1].fr * a1 + s[i]) % b1;
        p[i].fr = (p[i - 1].fr * a1) % b1;
        h[i].sc = (h[i - 1].sc * a2 + s[i]) % b2;
        p[i].sc = (p[i - 1].sc * a2) % b2;
    }
}

ll gethash(int l, int r){ //Devuelve hash del substring [l...r]
    pair<ll, ll> hashval({h[r].fr, h[r].sc});
    if(l > 0){
        hashval.fr = ((hashval.fr - h[l - 1].fr * p[r - l + 1].fr) % b1 + b1) % b1;
        hashval.sc = ((hashval.sc - h[l - 1].sc * p[r - l + 1].sc) % b2 + b2) % b2;
    }
    return (hashval.fr << 32 | hashval.sc);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    int a, b; 
    forn(i, m) {
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    int mi = 1e9;
    forn(i, n) {
        queue<ii> q;
        vector<int> dist(n, 1e9);
        dist[i] = 0;
        q.push({i, -1});
        while(sz(q)){
            auto [s, f] = q.front();
            q.pop();

            for(int u : g[s]) {
                if(dist[u] != 1e9) {
                    if(u != f) mi = min(mi, dist[s] + dist[u] + 1); // Correcto????
                }
                else {
                    dist[u] = dist[s] + 1;
                    q.push({u, s});
                }
            }
        }
    }

    //dbg(mi);
    set<ll> loops;
    vector<int> st, vis(n); //Reiniciaaaar;
    function<void(int, int)> dfs = [&](int s, int d) {
        if(d > mi) return;
        st.pb(s);
        if(vis[s]) {
            st.pop_back();
            if(d == mi){
                vector<int> ord = st;
                sort(all(ord));
                Hash(ord);
                //vdbg(ord);
                // dbg(gethash(0, sz(ord)-1));
                loops.insert(gethash(0, sz(ord)-1));
            }
            return;
        }
        vis[s] = true;
        for(int u : g[s]) {
            dfs(u, d+1);
        }
        st.pop_back();
        vis[s] = false;
    };

    forn(i, n) {
        dfs(i, 0);
        vis.assign(n, 0);
    }
    cout << sz(loops) << '\n';


    return 0;
}