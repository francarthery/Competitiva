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

typedef ll tipo;
struct FenwickTree {
  int N;            // maybe replace vector with unordered_map when "many 0s"
  vector<tipo> ft;  // for more dimensions, make ft multi-dimensional
  FenwickTree(int n) : N(n), ft(n + 1) {}
  void upd(int i0, tipo v) {  // add v to i0th element (0-based)
    // add extra fors for more dimensions
    for (int i = i0 + 1; i <= N; i += i & -i) ft[i] += v;
  }
  tipo get(int i0) {  // get sum of range [0,i0)
    tipo r = 0;       // add extra fors for more dimensions
    for (int i = i0; i; i -= i & -i) r += ft[i];
    return r;
  }
  tipo get_sum(int i0, int i1) {  // get sum of range [i0,i1) (0-based)
    return get(i1) - get(i0);
  }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    //Solucion de acuerdo a la editorial

    int n, q; cin >> n >> q;
    vector<int> vals(n);
    vector<vector<int>> g(n);
    forn(i, n) cin >> vals[i];
    int a, b, x; 
    forn(i, n-1){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<int> preorden, tam(n), inv(n);
    function<int(int, int)> dfs = [&](int s, int f) -> int {
        inv[s] = sz(preorden);
        preorden.pb(s);
        for(int u : g[s]) {
            if(u == f) continue;
            tam[s] += dfs(u, s);
        }
        return ++tam[s];
    };

    dfs(0, -1);
    //Intersante, si haces fenwick/st sobre el difference array podes hacer updates en rangos
    //y consultas sobre elementos individuales sin tocar la estructura original
    FenwickTree ft(n+1); 
    forn(i, n) {
        ft.upd(i, vals[preorden[i]]);
        ft.upd(i + tam[preorden[i]], -vals[preorden[i]]);
    }

    forn(tt, q) {
        char c; cin >> c;
        if(c == '1'){
            cin >> a >> x; a--;
            int val = vals[a];
            ft.upd(inv[a], x - val);
            ft.upd(inv[a] + tam[a], val - x);
            vals[a] = x;
        }
        else {
            cin >> a; a--;
            cout << ft.get(inv[a] + 1) << '\n';
        }
    }

    return 0;
}