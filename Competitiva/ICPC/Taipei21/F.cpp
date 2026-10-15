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
typedef pair<short, short> ii;

struct UnionFind {
    vector<int> f;  // f[i] = parent of node i
    UnionFind(int n) :  f(n, -1) {}
    int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
    bool join(int i, int j) {  // returns true if already in the same set
        int a = comp(i), b = comp(j);
        if (a > b) swap(a, b);
        f[a] = b;  // the bigger group (b) now represents the smaller (a)
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
    vector<array<int, 5>> q(n);
    vector<int> compy, compx;
    forn(i, n) {
        cin >> q[i][0] >> q[i][3] >> q[i][2] >> q[i][1] >> q[i][4];
        compx.push_back(q[i][0]);
        compy.push_back(q[i][1]);
        compx.push_back(q[i][2]);
        compy.push_back(q[i][3]);
    }

    sort(all(compx));
    compx.erase(unique(all(compx)), compx.end());
    sort(all(compy));
    compy.erase(unique(all(compy)), compy.end());

    forn(i, n) {
        q[i][0] = lower_bound(all(compx), q[i][0]) - compx.begin();
        q[i][1] = lower_bound(all(compy), q[i][1]) - compy.begin();
        q[i][2] = lower_bound(all(compx), q[i][2]) - compx.begin();
        q[i][3] = lower_bound(all(compy), q[i][3]) - compy.begin();
    }
    // vdbg(compx);
    unordered_set<short> ans;
    forn(i, sz(compx)){
        UnionFind uf(sz(compy));
        dfor(j, n) {
            if(q[j][0] >= i or q[j][2] < i) continue;
            int fat = uf.comp(q[j][1]);
            if(fat < q[j][3]) ans.insert(q[j][4]);

            while(fat < q[j][3]) {
                uf.join(fat, fat+1);
                fat = uf.comp(fat);
            }
        }
        // vdbg(ans);
    }

    cout << sz(ans) << '\n';

    return 0;
}