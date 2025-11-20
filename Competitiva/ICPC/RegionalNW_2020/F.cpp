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
typedef tuple<long double, int, int> iii;

const int INF = 1e9 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, x, ve;
    cin >> n;

    set<iii> s;
    vector<ii> v(n), adj(n);
    forn(i, n){
        cin >> x >> ve;
        v[i] = {x, ve};
        adj[i].fr = i - 1;
        adj[i].sc = i + 1;
    }

    adj[n - 1].sc = -1;
    forn(i, n - 1){
        if(v[i].sc > v[i + 1].sc) s.insert({(long double)(v[i + 1].fr - v[i].fr) / (v[i].sc - v[i + 1].sc), i, i + 1});
    }

    while(sz(s)){
        auto [t, x, y] = *s.begin();
        s.erase(s.begin());
        if(v[x].fr == INF or v[y].fr == INF) continue; //Uno de los drones ya choco

        v[x].fr = v[y].fr = INF; //Los marco chocados
        int l = adj[x].fr, r = adj[y].sc;

        if(l == -1 and r != -1) adj[r].fr = -1; //No quedo ninguno a la izq
        else if(l != -1 and r == -1) adj[l].sc = -1;
        else if(l != -1 and r != -1){
            adj[r].fr = l;
            adj[l].sc = r;
            if(v[l].sc > v[r].sc) s.insert({(long double)(v[r].fr - v[l].fr) / (v[l].sc - v[r].sc), l, r});
        }
    }

    vector<int> rta;
    forn(i, n) if(v[i].fr != INF) rta.pb(i + 1);
    cout << sz(rta) << '\n';
    for(int &i : rta) cout << i << ' ';
    cout << '\n';

    
    return 0;
}