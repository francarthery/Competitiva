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

    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        list<int> v;
        vector<bool> vivo(n, 1);
        vector<list<int>::iterator> pos(n);
        vector<int> p(n);
        forn(i, n) {
            int x; cin >> x;
            p[i] = x;
            v.pb(--x);
            pos[x] = --v.end();
        }
        UnionFind uf(n);
    
        bool flag = true;
        priority_queue<int> pq;
 
        dfor(i, n){
            pq.push(p[i]);
            if(pq.top() == n - i and i != 0) flag = false;
        }
        vector<ii> resp;

        if(flag) forn(i, n - 1){
            if(!vivo[i]) continue; 
            auto rec = next(pos[i]); 
            int ma = 0;

            while(rec != v.end()){
                ma = max(ma, *rec);
                if(*rec > i and !uf.join(i, *rec)){
                    resp.pb({i, *rec});
                }
                vivo[*rec] = false;
                rec++;
            }

            if(ma < i) break;
            else{
                v.erase(pos[i], v.end());
                v.pb(ma);
                pos[ma] = --v.end();
            }
        }

        cout << (flag ? "Yes" : "No") << '\n';
        if(flag) for(auto i : resp) cout << i.fr + 1 << ' ' << i.sc + 1 << '\n';
    }



    return 0;
}