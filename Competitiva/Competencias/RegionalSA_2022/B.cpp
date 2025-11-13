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

vector<vector<int>> g, gt;
vector<bool> vis1, vis2, vis3;

void dfs(int s, int i){
    if(vis1[s] or s == i) return;
    vis1[s] = true;
    for(int u : gt[s])  dfs(u, i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, a, b;
    cin >> n;
    string s(n, 'N');
    g.resize(n);
    gt.resize(n);
    forn(i, n){
        cin >> a >> b;
        a--; b--;
        g[i].pb(a);
        g[i].pb(b);
        gt[b].pb(i);
        gt[a].pb(i);
    }

    forn(i, n){
        vis1.assign(n, 0);
        dfs(i, n);
        vis2 = vis1;
        vis1.assign(n, 0);
        dfs(g[i][0], i);
        vis3 = vis1;
        vis1.assign(n, 0);
        dfs(g[i][1], i);
        forn(j, n) if(vis1[j] and vis2[j] and vis3[j]) s[i] = 'Y';
    }
    cout << s << '\n';
    
    return 0;
}
