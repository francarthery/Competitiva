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

    int t, n, m1, m2;
    cin >> t;
    while(t--){
        cin >> n >> m1 >> m2;
        int a, b, cont = 0;
        vector<ii> v, v1, v2;

        UnionFind dsu1(n), dsu2(n);

        forn(i, m1){
            cin >> a >> b; a--; b--;
            v1.pb({a, b});
        }

        forn(i, m2){
            cin >> a >> b; a--; b--;
            dsu1.join(a, b);
            v2.pb({a, b});
        }

        forn(i, m1){
            if(dsu1.comp(v1[i].fr) == dsu1.comp(v1[i].sc)){
                v.pb(v1[i]);
                dsu2.join(v1[i].fr, v1[i].sc);
            }
            else cont++;
        }

        //dbg(sz(v));

        forn(i, sz(v2)){
            if(dsu2.comp(v2[i].fr) != dsu2.comp(v2[i].sc)){
                dsu2.join(v2[i].fr, v2[i].sc);
                cont++;
            }
        }

        cout << cont << '\n';
    }


    
    return 0;
}