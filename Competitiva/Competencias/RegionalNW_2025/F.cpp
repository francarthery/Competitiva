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
        f[a] = b;  // the bigger group (b) now represents the smaller (a)
      }
      return a == b;
    }
};

int main(){
    
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, q, x, y, padre; cin >> n >> q;
    char c; 
    vector<int> v(n), g(n), cap;

    forn(i, n) cin >> v[i];
    cap = v;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    forn(i, n){ 
        int elem = v[i];
        while(!pq.empty() and pq.top().fr < elem){
            g[pq.top().sc] = i;
            pq.pop();
        }    
        pq.push({elem, i});
    }
    while(!pq.empty()) g[pq.top().sc] = -1, pq.pop();

    UnionFind uf(n);

    forn(t, q){
        cin >> c;
        if(c == '+') {
            cin >> x >> y;
            int band = uf.comp(x - 1);
            while(band != -1 and y > 0){
                int rest = min(cap[band], y);
                cap[band] -= rest;
                y -= rest;

                if(y){
                    if(g[band] != -1) padre = uf.comp(g[band]);
                    else padre = -1;
                    if(padre != -1) {
                        uf.join(band, padre);
                        band = padre;
                    }
                    else break;
                }
            }
        }
        else {
            cin >> x;
            cout << v[x - 1] - cap[x - 1] << endl;
        }
    }

    
    return 0;
}