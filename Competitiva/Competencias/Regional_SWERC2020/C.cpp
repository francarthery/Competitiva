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
#define fsp(x) fixed << setprecision((x))
#define sqr(a) ((a)*(a))

using namespace std;

typedef long long ll;
typedef pair<double, double> ii;
typedef long double T; // double could be faster but less precise

const int MOD = 1e9 + 7;

struct UnionFind {
    int nsets;
    vector<int> f, setsz;  // f[i] = parent of node i
    UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
    int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
    bool join(int i, int j) {  // returns true if already in the same set
        int a = comp(i), b = comp(j);
        if (a != b) {
            if (setsz[a] > setsz[b]) swap(a, b);
            f[a] = b;  // the bigger group (b) now represents the smaller (a)
            nsets--, setsz[b] += setsz[a];
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

    T x, y; cin >> x >> y;

    int n; cin >> n;
    vector<ii> v(n);

    forn(i, n) {
        cin >> v[i].fr >> v[i].sc;
    }

    function<bool(ii, ii, ii&, T&)> precta = [&](ii a, ii b, ii& centro, T& radio) -> bool{
        ll area = (a.fr - b.fr) * (a.sc - centro.sc) - (a.sc - b.sc) * (a.fr - centro.fr);
        T base = sqrtl(sqr(a.fr - b.fr) + sqr(a.sc - b.sc));
        return (abs((T)area) / base < radio); 
    };
    
    function<bool(T, UnionFind&)> f = [&](T m, UnionFind &uf){
        
        forn(i, n) {
            forr(j, i + 1, n){
                if(sqrtl(sqr(v[i].fr - v[j].fr) + sqr(v[i].sc - v[j].sc)) < 2 * m) uf.join(i, j);
            }
            if(precta(ii(0, 0), ii(0, y), v[i], m)) uf.join(i, n);
            if(precta(ii(0, 0), ii(x, 0), v[i], m)) uf.join(i, n + 3);
            if(precta(ii(x, 0), ii(x, y), v[i], m)) uf.join(i, n + 1);
            if(precta(ii(0, y), ii(x, y), v[i], m)) uf.join(i, n + 2);
        }
        if(uf.comp(n) == uf.comp(n + 1) 
        or uf.comp(n) == uf.comp(n + 3) 
        or uf.comp(n + 1) == uf.comp(n + 2) 
        or uf.comp(n + 2) == uf.comp(n + 3)) return false;
        
        return true;
    };
    
    T l = 0, r = 1e6 + 10;
    while(r - l > 1e-9){
        T m = (r + l) / 2.0;
        UnionFind uf(n + 4); //n circulos, n + 1 Pizquierda, n + 2 Pderecha, n + 3 Techo, n + 4 Suelo
        if(f(m, uf)) l = m;
        else r = m;
    }
    
    cout << fsp(6) << l << '\n'; 

    return 0;
}