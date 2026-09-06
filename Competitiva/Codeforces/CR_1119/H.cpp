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
    const int MAXN = 2e5;
    vector<array<int, 2>> dp(MAXN+1);
    dp[1][0] = dp[1][1] = 1;
    forr(i, 1, MAXN) {
        dp[i+1][0] = dp[i][1];
        dp[i+1][1] = (dp[i][0] + dp[i][1]) % MOD;
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        
        vector<int> diff(n+1), ps(n+1);
        forn(i, n) if(v[i] != -1 and v[i] != 0) {
            diff[max(0, i-v[i]+1)]++;
            diff[min(n, i+v[i])]--;
        }
        forn(i, n) ps[i+1] = ps[i]+diff[i];
        forn(i, n+1) if(ps[i]) ps[i] = 1;
        
        bool ok = true;
        forn(i, n) if(v[i] != -1){
            int l = 1, r = 1;
            if(i-v[i] >= 0) l = ps[i-v[i]+1];
            if(i+v[i] < n) r = ps[i+v[i]+1];

            if(l==1 and r==1) ok = false;
            else if(l!=1 and r==1 or !v[i]) ps[i-v[i]+1] = 2; //decision unica
            else if(l==1 and r!=1) ps[i+v[i]+1] = 2;
        }

        UnionFind uf(n);
        forn(i, n) if(v[i] != -1) {
            int l = 1, r = 1;
            if(i-v[i] >= 0) l = ps[i-v[i]+1];
            if(i+v[i] < n) r = ps[i+v[i]+1];
            if(!l and !r) uf.join(i-v[i], i+v[i]);
        }

        set<int> comps;
        ll ans = 1;
        forn(i, n) if(ps[i+1] == 0) {
            if(comps.count(uf.comp(i))) continue;
            int tam = uf.setsz[uf.comp(i)];
            ans = ans * (dp[tam][0] + dp[tam][1]) % MOD;
            comps.insert(uf.comp(i));
        }

        bool todocero = true;
        forn(i, n) if(v[i]!=-1) todocero = false;
        if(todocero) ans--;

        if(!ok) ans = 0;
        cout << ans << '\n';
    }

    return 0;
}