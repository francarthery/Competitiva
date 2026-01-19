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

    int n; cin >> n;
    vector<array<int, 3>> v(n);
    set<iii> ar;

    forn(i, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][1] -= v[i][0];
        v[i][2] -= v[i][0];
    }

    auto f = [&]() {
        set<ii> h;
        h.insert({0, n}); //piso
        h.insert({1e9 + 10, n + 1}); //techo (eliminar del grafo)
        map<int, vector<ii>> ev; // (pos, (tipo, indice))
        forn(i, n) {
            ev[v[i][1]].pb({0, i});
            ev[v[i][2]].pb({1, i});
        }

        for(auto &i : ev) {
            auto &seg = i.sc;
            sort(all(seg));

            int cont = 0;
            for(int j = 0; j < sz(seg) and !seg[j].fr; j++) h.insert({v[seg[j].sc][0], seg[j].sc});
            for(int j = 0; j < sz(seg) and !seg[j].fr; j++) {
                auto it = h.find({v[seg[j].sc][0], seg[j].sc});
                auto piso = prev(it);
                auto techo = next(it);

                ar.insert({it -> fr - piso -> fr, min(it -> sc, piso -> sc), max(it -> sc, piso -> sc)});
                ar.insert({techo -> fr - it -> fr, min(it -> sc, techo -> sc), max(it -> sc, techo -> sc)});
                cont++;
            }

            forr(j, cont, sz(seg)) h.erase({v[seg[j].sc][0], seg[j].sc});
            forr(j, cont, sz(seg)) {
                auto techo = h.upper_bound({v[seg[j].sc][0], 1e9});
                auto piso = prev(techo);
                ar.insert({techo -> fr - piso -> fr, min(techo -> sc, piso -> sc), max(techo -> sc, piso -> sc)});
            }
        }
    };

    f();
    forn(i, n) {
        v[i][1] += 2*v[i][0];
        v[i][2] += 2*v[i][0];
    }
    f();

    UnionFind uf(n + 1);
    ll cost = 0;
    for(auto i : ar) {
        auto &[w, a, b] = i;
        if(a == n + 1 or b == n + 1) continue;
        if(!uf.join(a, b)) cost += w;
    }

    cout << cost << '\n';

    return 0;
}