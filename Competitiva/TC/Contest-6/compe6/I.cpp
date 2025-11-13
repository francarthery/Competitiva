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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n, k, m, x, y, rta = 0;
    cin >> n >> k >> m;
    vector<pair<string, int>> v(n);
    vector<prq<int, vector<int>, greater<int>>> g(k);
    vector<string> pal(m);

    for(auto &[x, y] : v) cin >> x;
    for(auto &[x, y] : v) cin >> y;

    forn(i, k){
        cin >> x;
        forn(j, x){
            cin >> y;
            g[i].push(v[y - 1].sc);
            v[y - 1].sc = i;
        }
    }

    forn(i, m) cin >> pal[i];
    sort(all(pal));
    sort(all(v));

    ll ind = 0;
    forn(i, n){
        while(v[i].fr == pal[ind]){
            rta += (ll)g[v[i].sc].top();
            ind++;
        }
    }

    cout << rta << '\n';
    
    return 0;
}