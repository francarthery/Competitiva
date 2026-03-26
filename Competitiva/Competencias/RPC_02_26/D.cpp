#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    
    int n; cin >> n;
    string cod; cin >> cod;
    vector<vector<int>> g(n);
    int a, b;
    forn(i, n - 1) {
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    vector<ll> sec;
    const int a1 = 31, a2 = 23, b1 = 1e9 + 7, b2 = 1e9 + 9;
    function<void(int, int, ll, ll)> dfs = [&](int s, int f, ll hash1, ll hash2) {
        if(f != -1) hash1 = (hash1 * a1 + cod[s]) % b1;
        if(f != -1) hash2 = (hash2 * a2 + cod[s]) % b2;
        sec.pb((hash1 << 32 | hash2));
        
        for(int &u : g[s]){
            if(u == f) continue;
            dfs(u, s, hash1, hash2);
        }

    };  

    forn(i, n) dfs(i, -1, cod[i], cod[i]);
    sort(all(sec));
    sec.erase(unique(all(sec)), sec.end());
    cout << sz(sec) << '\n';

    return 0;
}