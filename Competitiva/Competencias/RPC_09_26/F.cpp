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
typedef array<ll, 3> iii;

struct cmp {
    bool operator()(const iii &a, const iii &b) const {
        if(a[0] * b[1] == a[1] * b[0]) return a[2] > b[2]; //para que no me los vuele. nose si es necesario
        return a[0] * b[1] > a[1] * b[0]; //OJOOOO
    }
};

struct UnionFind {
    int nsets;
    vector<ll> f, psum, wsum;  // f[i] = parent of node i
    UnionFind(int n) : nsets(n), f(n, -1), psum(n), wsum(n) {}
    int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
    bool join(int i, int j) {  // returns true if already in the same set
        int a = comp(i), b = comp(j);
        if (a != b) {
            f[a] = b; 
            psum[b] += psum[a];
            wsum[b] += wsum[a];
        }
        return a == b;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<ll> p(n), w(n), f(n, -1);
    forn(i, n) cin >> p[i];
    forn(i, n) cin >> w[i];

    int a, b, m; cin >> m;
    forn(i, m) {
        cin >> a >> b; a--; b--;
        f[a] = b;
    }

    UnionFind uf(n);
    priority_queue<iii, vector<iii>, cmp> bag; 
    
    ll ans = 0, sump = 0;
    forn(i, n) {
        bag.push({p[i], w[i], i}); //atributos, representante
        ans += p[i] * w[i]; //esto es invariante
        uf.psum[i] = p[i];
        uf.wsum[i] = w[i];
    }
    
    vector<bool> salio(n);
    while(sz(bag)) {
        auto [pi, wi, rep] = bag.top();
        bag.pop();
        if(pi != uf.psum[uf.comp(rep)]) continue; //si no coincide ya lo use y no lo habia borrado.

        int fat = -1;
        if(f[rep] != -1) fat = uf.comp(f[rep]);

        if(fat == -1 or salio[fat]) {
            ans += sump * wi;
            sump += pi;
            salio[rep] = true;
        }
        else {        
            ans += uf.psum[fat] * wi; //ya que se que van a ir pegados y que los de fat van primero
            
            uf.join(rep, fat); //fat tiene que quedar de padre si o si
            int nfat = uf.comp(rep);
            bag.push({uf.psum[nfat], uf.wsum[nfat], nfat});
        }
    }

    cout << ans << '\n';


    return 0;
}