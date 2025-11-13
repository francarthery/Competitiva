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

vector<tuple<int, int, int>> g;
vector<int> padre;

int find(int s){
    if(padre[s] == s) return s;
    return padre[s] = find(padre[s]);
}

void uni(int u, int v){
    int a = find(u), b = find(v);
    if(a != b) padre[a] = b;
}

ll kruskal(int n){
    sort(rall(g));
    ll res = 0, comp = n;

    while(sz(g) and comp > 1){
        if(find(get<1>(g.back())) != find(get<2>(g.back()))) {
            uni(get<1>(g.back()), get<2>(g.back()));
            res += get<0>(g.back());
            comp--;
        }
        g.pop_back();
    }

    return (comp == 1 ? res : -1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b, c;
    cin >> n >> m;
    g.resize(m);
    padre.resize(n);
    forn(i, n) padre[i] = i;

    forn(i, m){
        cin >> a >> b >> c; a--; b--;
        g[i] = {c, a, b};
    }

    ll res = kruskal(n);

    if(res == -1) cout << "IMPOSSIBLE\n";
    else cout << res << '\n';

    
    return 0;
}