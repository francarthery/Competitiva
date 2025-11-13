#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

vector<int> v;
vector<vector<int>> g;

int dfs(int s){
    int mi = INT_MAX;
    
    for(auto &u : g[s]) mi = min(mi, dfs(u));
    
    if(mi != INT_MAX and s != 0){
        v[s] += mi > v[s] ? (mi - v[s]) / 2 : 0;
        mi = min(mi, v[s]);
    }
    else if(mi == INT_MAX) mi = v[s];

    return mi;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(n);
        g.assign(n, vector<int>());

        forn(i, n) cin >> v[i];

        forn(i, n - 1){
            cin >> x;
            g[x - 1].pb(i + 1);
        }

        cout << v[0] + dfs(0) << '\n';
    }
    
    return 0;
}