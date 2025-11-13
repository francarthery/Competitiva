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

bool compare(ii &a, ii &b){
    if(a.fr != b.fr) return a.fr > b.fr;
    else return a.sc < b.sc;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, m, x, y;
    cin >> n;
    vector<ii> v(n), ans;
    forn(i, n){
        cin >> x;
        v[i] = {x, i};
    }
    sort(all(v), compare);
    cin >> m;
    forn(i, m){
        cin >> x >> y;
        forn(i, x) ans.pb({v[i].sc, v[i].fr});
        sort(all(ans));
        cout << ans[y - 1].sc << ' ';
        cout << '\n';
        ans.clear();
    }
    
    
    return 0;
}