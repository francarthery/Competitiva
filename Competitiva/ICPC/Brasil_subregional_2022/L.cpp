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

    const int MOD = 1e9+7;
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int k = __lg(n);
    vector<UnionFind> st(k, UnionFind(2*n)); //n bloques en un sentido, n en el otro

    forn(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        int tam = b-a+1;
        int pot = (1<<__lg(tam));
        st[pot].join(a, 2*n + b-pot+1); //junto la primera mitad leida en un sentido con la segunda leida en el otro
        st[pot].join(a+tam-pot, n + b-tam+1);
    }

    for(int lvl = k; lvl > 0; lvl--) {
        forn(i, 2*n - (1<<lvl)+1) {
            int fat = st[lvl].comp(i);
            if(fat != i) {
                st[lvl-1].join(i, fat);
                st[lvl-1].join(i+(1<<(lvl-1)), fat+(1<<(lvl-1)));
            }
        }
    }

    forn(i, n) st[0].join(i, i+n);
    vector<int> hay(2*n, 1e9);
    bool ok = true;
    forn(i, n) {
        int fat = st[0].comp(i);
        if(s[i] != '?') {
            if(hay[fat] != 1e9 and s[i] - '0' != hay[fat]) ok = false;
            hay[fat] = s[i] - '0';
        }
        else hay[fat] = -1;
    }

    ll libres = 0, rta = 1;
    for(int i : hay) libres += i == -1;
    forn(i, libres) rta = (rta * 2) % MOD;
    cout << rta << '\n';

    return 0;
}