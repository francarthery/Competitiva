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

    int n, ant, cont = 0, x;
    cin >> n;
    vector<ii> v(n);
    vector<int> ans;
    forn(i, n){
        cin >> x;
        v[i] = {x, i + 1};
    }
    sort(all(v));
    forn(i, n){
        if(v[i].fr > ant) {
            ant = v[i].fr;
            cont++;
            ans.pb(v[i].sc);
        }
        if(cont == 3) break;
    }
    if(cont < 3) forn(i, 3) cout << -1 << ' ';
    else forn(i, 3) cout << ans[i] << ' ';
    cout << '\n';
    
    return 0;
}