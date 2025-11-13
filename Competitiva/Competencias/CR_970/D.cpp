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

vector<int> v, vis;
string s;
int cont;
void dfs(int i){
    if(vis[i] != -1) return;

    vis[i] = 0;
    if(s[i] == '0') cont++;
    dfs(v[i] - 1);
    vis[i] = cont;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(n);
        vis.assign(n, -1);
        forn(i, n) cin >> v[i];
        cin >> s;
        forn(i, n){
            dfs(i);
            cont = 0;
        }
        forn(i, n) cout << vis[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}