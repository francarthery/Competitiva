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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<int>> g;
vector<ll> dist1, dist2;

struct frac {
    ll p, q;
    frac(ll p = 0, ll q = 1) : p(p), q(q) { norm(); }
    void norm() {
      ll a = gcd(q, p);
      if (a) p /= a, q /= a;
      else q = 1;
      if (q < 0) q = -q, p = -p;
    }
    frac operator+(const frac& o) {
      ll a = gcd(o.q, q);
      return frac(p * (o.q / a) + o.p * (q / a), q * (o.q / a));
    }
    frac operator-(const frac& o) {
      ll a = gcd(o.q, q);
      return frac(p * (o.q / a) - o.p * (q / a), q * (o.q / a));
    }
    frac operator*(frac o) {
      ll a = gcd(o.p, q), b = gcd(p, o.q);
      return frac((p / b) * (o.p / a), (q / a) * (o.q / b));
    }
    frac operator/(frac o) {
      ll a = gcd(o.q, q), b = gcd(p, o.p);
      return frac((p / b) * (o.q / a), (q / a) * (o.p / b));
    }
    bool operator<(const frac& o) const { return p * o.q < o.p * q; }
    bool operator==(frac o) { return p == o.p && q == o.q; }
};
  

void bfs(int s, vector<ll> &dist){
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while(sz(q)){
        int u = q.front();
        q.pop();

        for(int &i : g[u]) {
            if(dist[i] == -1) {
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<int> v(k);
    g.resize(n);
    dist1.assign(n, -1);
    dist2.assign(n, -1);
    forn(i, k) cin >> v[i];
    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    bfs(0, dist1); //distancia desde origen al resto
    bfs(n - 1, dist2); //distancia desde destino a resto
    
    frac rta(dist1[n - 1], 1); //distancia sin usar tp
    ll tot = 0;
    forn(i, k) tot += dist2[v[i] - 1];
    

    forn(i, k){
        frac ini(dist1[v[i] - 1], 1), fin(tot - dist2[v[i] - 1], k - 1);
        frac d = ini + fin;
        rta = min(rta, d);
    }

    cout << rta.p << '/' << rta.q << '\n';

    
    return 0;
}