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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> v(n);
        forn(i, n) {
            int l; cin >> l;
            v[i].resize(l);
            dfor(j, l) cin >> v[i][j];

            set<int> s;
            vector<int> aux;
            forn(j, l) {
                if(!s.count(v[i][j])) {
                    aux.pb(v[i][j]);
                    s.insert(v[i][j]);
                }
            }
            v[i] = aux;
        }

        vector<int> ans;
        vector<bool> dead(1e6 + 1);
        while(true){
            forn(i, n) {
                if(v[i][0] == 1e9) continue;
                vector<int> aux;
                forn(j, sz(v[i])) if(!dead[v[i][j]]) aux.pb(v[i][j]);
                if(!sz(aux)) aux.pb(1e9);
                v[i] = aux;
            }

            sort(all(v), [&](vector<int> &a, vector<int> &b) {
                int l = -1, r = min(sz(a),sz(b));
                while(r - l > 1){
                    int m = (l + r) / 2;
                    if(a[m] == b[m]) l = m;
                    else r = m;
                }

                if(r == min(sz(a), sz(b))) return sz(a) < sz(b);
                else return a[r] < b[r];
            });

            if(v[0][0] == 1e9) break;

            forn(i, sz(v[0])){
                if(!dead[v[0][i]]) ans.pb(v[0][i]);
                dead[v[0][i]] = true;
            }
        }

        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }



    return 0;
}