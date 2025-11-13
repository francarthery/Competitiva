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

struct UnionFind {
    vector<int> f;  // f[i] = parent of node i
    UnionFind(int n) : f(n, -1) {}
    int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
    bool join(int i, int j) {  // returns true if already in the same set
        int a = comp(i), b = comp(j);
        if (a != b) f[a] = b;  // the bigger group (b) now represents the smaller (a)
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

    int n, m, a, b, c;
    cin >> n >> m;
    vector<iii> g(m);
    vector<UnionFind> trees(m / (n - 1), UnionFind(n));

    forn(i, m){
        cin >> a >> b >> c; a--, b--;
        g[i] = {c, a, b};
    }
    sort(all(g));

    vector<ll> nodos(m / (n - 1)), rta(m / (n - 1)); //cantidad de nodos que lleva un arbol
    int ini = 0;

    forn(i, sz(g)) {
        forr(j, ini, sz(trees)){ //pruebo esa arista con todos los arboles
            if(!trees[j].join(get<1>(g[i]), get<2>(g[i]))) {
                rta[j] += get<0>(g[i]);
                nodos[j]++;
                if(nodos[j] == n - 1) ini++; //ya termine con ese subarbol
                break; //ya use esa arista, sigo con otra
            }
        }    
    } 

    cout << ini << '\n';
    forn(i, ini) cout << rta[i] << '\n';

    return 0;
}