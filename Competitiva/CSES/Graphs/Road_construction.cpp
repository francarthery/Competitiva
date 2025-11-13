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

vector<ii> g;
vector<int> padre, tam;

int find(int s){
    if(padre[s] == s) return s;
    return padre[s] = find(padre[s]);
}

int uni(int u, int v){
    int a = find(u), b = find(v);

    padre[a] = b;
    return tam[b] += tam[a];
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
    g.resize(m);
    padre.resize(n);
    tam.resize(n, 1);
    forn(i, n) padre[i] = i;

    forn(i, m){
        cin >> a >> b; a--; b--;
        g[i] = {a, b};
    }

    int ma = 0, comp = n;
    for(ii &i : g){
        if(find(i.fr) != find(i.sc)){
            comp--;
            ma = max(ma, uni(i.fr, i.sc));
        }
        cout << comp << ' ' << ma << '\n';
    }

    
    return 0;
}