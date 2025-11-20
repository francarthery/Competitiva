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
typedef tuple<int, int, int> iii;

const int MAX_N = 100;
const ll INF = 1e14;
int N;
vector<vector<ll>> G;
void floyd() {  // O(N^3)
  forn(k, N) forn(i, N) if (G[i][k] != INF) forn(j, N) if (G[k][j] != INF)
      G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll m, a, b, x, y, c; cin >> N >> m >> a >> b;
    a--; b--;
    G.assign(N, vector<ll>(N, INF));
    vector<iii> v(m);
    //forn(i, N) vdbg(G[i]);
    forn(i, m){
        cin >> x >> y >> c; x--; y--;
        G[x][y] = G[y][x] = c;
        v[i] = {x, y, c};
    }
    forn(i, N) G[i][i] = 0;

    floyd();
    ll mi = G[a][b];

    set<int> borro;
    ll res = 0;
    for(auto [x1, y1, c1] : v){
        bool ok = true;
        if(G[x1][a] + c1 + G[y1][b] == mi) ok = false;
        if(G[y1][a] + c1 + G[x1][b] == mi) ok = false;
        if(ok) res+= c1;
    }
    
    cout << res << '\n';


    return 0;
}