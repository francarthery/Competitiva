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
    vector<ll> f, setsz;  // f[i] = parent of node i
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
        vector<int> v(n);
        vector<vector<int>> diff(n);
        cin >> v[0];
        forr(i, 1, n) {
            cin >> v[i];
            diff[abs(v[i] - v[i - 1])].pb(i - 1);
        } 

        ll sum = 0;
        vector<ll> ans(n); 
        UnionFind uf(n);
        dfor(i, n) {
            for(int j : diff[i]){
                sum -= (uf.setsz[uf.comp(j)] * (uf.setsz[uf.comp(j)] - 1)) / 2ll;
                sum -= (uf.setsz[uf.comp(j + 1)] * (uf.setsz[uf.comp(j + 1)] - 1)) / 2ll;
                uf.join(j, j + 1);
                sum += (uf.setsz[uf.comp(j)] * (uf.setsz[uf.comp(j)] - 1)) / 2ll;
            }
            ans[i] = sum;
        }

        forr(i, 1, n) cout << ans[i] << ' ';
        cout << '\n';
    }


    return 0;
}