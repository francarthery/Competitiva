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

// Usage:
// 1. Create with n = number of variables (0-indexed)
// 2. Add restrictions through the existing methods, using ~X for
//    negating variable X for example.
// 3. Call satisf() to check whether there is a solution or not.
// 4. Find a valid assigment by looking at verdad[cmp[2*X]] for each
//    variable X
struct Sat2 {
  // We have a vertex representing a variable and other for its
  // negation. Every edge stored in G represents an implication.
  vector<vector<int>> G;
  // idx[i]=index assigned in the dfs
  // lw[i]=lowest index(closer from the root) reachable from i
  // verdad[cmp[2*i]]=valor de la variable i
  int N, qidx, qcmp;
  vector<int> lw, idx, cmp, verdad;
  stack<int> q;
  Sat2(int n) : G(2 * n), N(n) {}
  void tjn(int v) {
    lw[v] = idx[v] = ++qidx;
    q.push(v), cmp[v] = -2;
    forall(it, G[v]) if (!idx[*it] || cmp[*it] == -2) {
      if (!idx[*it]) tjn(*it);
      lw[v] = min(lw[v], lw[*it]);
    }
    if (lw[v] == idx[v]) {
      int x;
      do { x = q.top(), q.pop(), cmp[x] = qcmp; } while (x != v);
      verdad[qcmp] = (cmp[v ^ 1] < 0);
      qcmp++;
    }
  }
  bool satisf() {  // O(N)
    idx = lw = verdad = vector<int>(2 * N, 0);
    cmp = vector<int>(2 * N, -1);
    qidx = qcmp = 0;
    forn(i, N) {
      if (!idx[2 * i]) tjn(2 * i);
      if (!idx[2 * i + 1]) tjn(2 * i + 1);
    }
    forn(i, N) if (cmp[2 * i] == cmp[2 * i + 1]) return false;
    return true;
  }
  // a -> b, here ids are transformed to avoid negative numbers
  void addimpl(int a, int b) {
    a = a >= 0 ? 2 * a : 2 * (~a) + 1;
    b = b >= 0 ? 2 * b : 2 * (~b) + 1;
    G[a].pb(b), G[b ^ 1].pb(a ^ 1);
  }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        n*=2;
        vector<int> v(n);
        forn(i, n) cin >> v[i], v[i]--;
        vector<vector<int>> g(n);

        int a, b;
        forn(i, n - 1){
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        vector<ii> cols(n/2, ii(-1, -1));
        forn(i, n) {
            if(cols[v[i]].fr == -1) cols[v[i]].fr = i;
            else cols[v[i]].sc = i;
        }

        Sat2 st(n/2);
        function<void(int s, int f)> dfs = [&](int s, int f) {
            for(int u : g[s]){
                if(u == f) continue;
                int vu = (cols[v[u]].fr == u ? v[u] : ~v[u]);
                int vs = (cols[v[s]].fr == s ? v[s] : ~v[s]);

                st.addimpl(vu, vs);
                dfs(u, s);
            }
        };

        dfs(cols[0].fr, -1);
        bool ok = st.satisf();
        if(!ok) {
            st = Sat2(n/2);
            dfs(cols[0].sc, -1);
            ok = st.satisf();
        }

        if(!ok) cout << -1 << '\n';
        else {
            forn(i, n/2) {
                if(st.verdad[st.cmp[2*i]]) cout << cols[i].fr + 1 << ' ';
                else cout << cols[i].sc + 1 << ' ';
            }
            cout << '\n';
        }

    }



    return 0;
}