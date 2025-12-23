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

    int n, m, k, x; cin >> n >> m >> k;
    vector<bool> v(n);
    forn(i, k) cin >> x, v[--x] = true;

    vector<vector<int>> g(n);
    vector<ii> ar(m);
    int a, b;
    forn(i, m){
        cin >> a >> b; a--; b--;
        ar[i] = {a, b};
        g[a].pb(b);
        g[b].pb(a);
    }

    queue<ii> q; 
    vector<ii> dist(n, {-1, -1}); 
    vector<int> rta(n, 1e9);

    forn(i, n) if(v[i]) {
        dist[i] = {0, i};
        q.push({i, i}); 
    }
    
    while(sz(q)){
        auto [nodo, orig] = q.front();
        q.pop();

        for(int u : g[nodo]) {
            if(dist[u].fr == -1){
                dist[u] = {dist[nodo].fr + 1, orig};
                q.push({u, orig});
            }
        }
    }

    forn(i, n) if(!v[i]) rta[i] = dist[i].fr;

    forn(i, m){
        if(dist[ar[i].fr].sc != dist[ar[i].sc].sc) {
            rta[dist[ar[i].fr].sc] = min(rta[dist[ar[i].fr].sc], dist[ar[i].fr].fr + dist[ar[i].sc].fr + 1);
            rta[dist[ar[i].sc].sc] = min(rta[dist[ar[i].sc].sc], dist[ar[i].fr].fr + dist[ar[i].sc].fr + 1);
        }
    }

    for(int i : rta) cout << (i == 1e9 ? -1 : i) << ' ';
    cout << '\n';


    return 0;
}