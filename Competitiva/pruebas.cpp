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
        map<int, int> mex;
        vector<vector<int>> v(n);
        vector<int> vmex(n);

        ll summex = 0;
        forn(i, n){
            int l, cont = 0; cin >> l;
            v[i].resize(l);
            forn(j, l) cin >> v[i][j];
            
            bool falto = true;
            sort(all(v[i]));
            for(int &j : v[i]) {
                if(j == cont) cont++;
                else if(j > cont and falto) {
                    vmex[i] = cont;
                    cont++;
                    if(j == cont) cont++;
                    falto = false;
                }
            }
            if(falto) {
                vmex[i] = cont;
                cont++;
            }

            mex[vmex[i]] += cont - vmex[i];
            summex += vmex[i];
        }

        ll ans = 0;

        forn(i, n) {
            forn(j, sz(v[i])){
                int resto = 0;
                if((j == 0 or v[i][j - 1] != v[i][j]) and (j == sz(v[i]) - 1 or v[i][j + 1] != v[i][j]) and vmex[i] > v[i][j]) resto = vmex[i] - v[i][j];
                
                ans += (summex - resto) * (n - 1);
                ans += mex[v[i][j]]; //Mejoro el total con v[i][j];
            }
        }

        cout << ans << '\n';
    }



    return 0;
}