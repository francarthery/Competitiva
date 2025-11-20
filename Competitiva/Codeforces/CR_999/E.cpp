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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v(n), r(m), used(m), rest;
        forn(i, n) cin >> v[i];
        forn(i, m) cin >> r[i];

        forn(i, n){
            int elem = v[i];
            forn(j, m) {
                int mi = elem, ind = 0;
                forn(k, m) {
                    if(used[k] <= i and (elem & r[k]) < mi){
                        mi = elem & r[k];
                        ind = k;
                    }
                }
                used[ind]++;
                rest.pb(elem - mi);
                elem = mi;
            }
        }
        sort(rall(rest));
        dbg(accumulate(all(v), 0ll));
        vdbg(rest);
        cout << accumulate(all(v), 0ll) - accumulate(rest.begin(), rest.begin() + k, 0ll) << '\n';
    }


    
    return 0;
}