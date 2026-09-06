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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<int> v(n);
    map<int, vector<int>> frec;
    forn(i, n) {
        cin >> v[i];
        frec[-v[i]].push_back(i);
    }
    frec[-2e9].push_back(n);

    vector<ii> len(n+1);
    vector<int> best(m+1);

    for(auto it = ++frec.begin(); it != frec.end(); it++) {
        for(int ind : it -> second) {
            len[ind] = {1, 1};

            auto &ant = prev(it) -> second;
            auto sig = upper_bound(all(ant), ind);
            if(sig != ant.end()) len[ind].second += len[*sig].second;
            if(sig != ant.begin()) len[ind].first += len[*prev(sig)].first;

            best[-it -> first] = max({best[-it -> first], len[ind].first, len[ind].second});
        }
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int ind = 0, ans = 0;
    while(ind < sz(v)) {
        ind += best[v[ind]];
        ans++;        
    }

    cout << sz(v) << ' ' << ans << '\n';

    return 0;
}