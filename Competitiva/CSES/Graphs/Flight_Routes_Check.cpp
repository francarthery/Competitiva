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
vector<bool> vis1, vis2;

void dfs1(int s){
    if(vis1[s]) return;
    vis1[s] = true;

    for(int &u : g[s]) dfs1(u);
}

void dfs2(int s){
    if(vis2[s]) return;
    vis2[s] = true;

    for(int &u : gt[s]) dfs2(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;

    g.resize(n);
    gt.resize(n);
    vis1.resize(n);
    vis2.resize(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        gt[b].pb(a);
    }

    dfs1(0);
    dfs2(0);

    a = -1, b = -1;
    forn(i, n){
        if(vis1[i] and vis2[i]) continue;
        
        if(vis1[i] == 0) a = 0, b = i;
        else a = i, b = 0;
        break;
    }

    if(a == -1 and b == -1) cout << "YES\n";
    else cout << "NO\n" << a + 1 << ' ' << b + 1 << '\n';
    
    return 0;
}