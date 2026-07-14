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
        int x, n, k; cin >> n >> k;
        
        map<int, int> m;
        forn(i, n) cin >> x, m[x]++;

        int ans = 0, mi = 1e9;
        for(auto i : m) mi = min(mi, i.sc);

        if(n >= k and sz(m) and (n - k) % sz(m) == 0 and (n - k) / sz(m) < mi) ans++; //resto
        if(n < k and sz(m) and (k - n) % sz(m) == 0) ans++; //Sumo

        while(sz(m)) {
            bool flag = false;
            vector<int> del;
            int cont = 0, mi = 1e9;
            for(auto &i : m) {
                i.sc--;
                cont += i.sc;
                if(i.sc == 0) {
                    del.pb(i.fr);
                    flag = true;
                }
                else mi = min(mi, i.sc);
            }
            forn(i, sz(del)) m.erase(del[i]);
            
            if(flag and cont >= k and sz(m) and (cont - k) % sz(m) == 0 and (cont - k) / sz(m) < mi) ans++;
            if(flag and cont < k and sz(m) and (k - cont) % sz(m) == 0) ans++;
        }

        cout << ans << '\n';
    }



    return 0;
}