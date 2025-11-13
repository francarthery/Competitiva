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

    int t; cin >> t;
    while(t--){
        int n, k, x; cin >> n >> k;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        ll l = -1, r = n + 1;
        while(r - l > 1){
            ll m = (r + l) / 2;
            ll cont = 0, cont2 = 0;
            vector<bool> use(m);
            
            forn(i, n){
                if(v[i] < m and !use[v[i]]){
                    use[v[i]] = true;
                    cont2++;
                }
                if(cont2 == m) {
                    cont++;
                    cont2 = 0;
                    use.assign(m, 0);
                }
            }

            if(cont >= k) l = m;
            else r = m;
        }

        cout << l << '\n';
    }


    
    return 0;
}