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

struct UnionFind {
    int nsets;
    vector<int> f, setsz;  // f[i] = parent of node i
    UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
    int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
    int join(int i, int j) {  // returns true if already in the same set
        int a = comp(i), b = comp(j);
        if (a != b) {
            if (setsz[a] > setsz[b]) swap(a, b);
            f[a] = b;  // the bigger group (b) now represents the smaller (a)
            nsets--, setsz[b] += setsz[a];
        }
        return b;
    }
};
  

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> ma(n);
    unordered_set<int> cc;
    UnionFind uf(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        if(a > b) swap(a, b);
        ma[b].pb(a);
    }

    int ant = 0;
    forn(i, n){
        unordered_map<int, int> comp;
        for(int &j : ma[i]) comp[uf.comp(j)]++;

        unordered_set<int> junto, ok;
        for(int j : cc){
            if(uf.setsz[j] > comp[j]) junto.insert(j); //No conecte con todas las aristas. Puedo juntarlas
            else ok.insert(j); //Conecte con todas. Guardo las componentes que permanecen aisladas.
        }

        int cfinal = i;
        for(int j : junto) cfinal = uf.join(cfinal, j);
        ok.insert(cfinal);
        cc = ok;
    }
    
    cout << uf.nsets - 1 << '\n';
    
    return 0;
}
