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
    while(t--){
        int n; cin >> n;
        vector<int> criba(n + 1), resto, v2, v3;
        criba[1] = 1;
        for(int j = 2; j <= n; j += 2) {
            criba[j] = 2;
            v2.pb(j);
        }
        for(int j = 3; j <= n; j += 3) if(!criba[j]) {
            criba[j] = 3;
            v3.pb(j);
        }
        forr(i, 2, n + 1) if(!criba[i]) resto.pb(i);
        //vdbg(v2); vdbg(v3); vdbg(resto);

        vector<int> ans{1};
        forn(i, sz(v2)){
            ans.pb(v2[i]);
            if(i % 2 and sz(resto)) {
                ans.pb(resto.back());
                resto.pop_back();
            }
        }
        
        forn(i, sz(v3)){
            ans.pb(v3[i]);
            if(i % 2 and sz(resto)) {
                ans.pb(resto.back());
                resto.pop_back();
            }
        }

        forn(i, sz(resto)) ans.pb(resto[i]);

        #ifdef fran
            int cont = 0;
            forn(i, n - 2){
                if(gcd(ans[i], ans[i + 1]) == 1 and gcd(ans[i], ans[i + 2]) == 1 and gcd(ans[i + 1], ans[i + 2]) == 1) cont++;
            }
            cout << cont << '\n';
        #endif

        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}