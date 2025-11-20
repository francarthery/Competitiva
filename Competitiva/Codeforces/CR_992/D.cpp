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

vector<vector<int>> g;
vector<int> vis;
int dfs(int s){
    int num = vis[s];

    for(int &u : g[s]){
        if(vis[u] == -1){
            if(num == vis[s]) vis[u] = num + 1;
            else vis[u] = num + 2 + ((num - vis[s]) & 1);
            num = dfs(u);
        }
    }

    return num;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, a, b;
    cin >> t;
    while(t--){
        cin >> n;
        g.assign(n, vector<int>());
        vis.assign(n, -1);

        forn(i, n - 1){
            cin >> a >> b;
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        vis[0] = 1;
        dfs(0);

        forn(i, n) cout << vis[i] << ' ';
        cout << '\n';
    }
  
    return 0;
}