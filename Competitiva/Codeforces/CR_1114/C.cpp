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
        string a, b; cin >> a >> b;
        vector<ll> par1, par2, impar1, impar2;
        ll cont1 = 0, cont2 = 0;
        forn(i, n) {
            if(a[i] == '1') {
                cont1++;
                if(i%2) impar1.push_back(i);
                else par1.push_back(i);
            }
        }
        forn(i, n) {
            if(b[i] == '1') {
                cont2++;
                if(i%2) impar2.push_back(i);
                else par2.push_back(i);
            }
        }
        
        if(cont1 != cont2 or sz(par1) != sz(par2) or sz(impar1) != sz(impar2)) {
            cout << -1 << '\n';
            continue;
        }
        
        ll ans = 0;
        forn(i, sz(par1)) {
            ans += abs(par1[i] - par2[i]) / 2ll;
        }
        forn(i, sz(impar1)) {
            ans += abs(impar1[i] - impar2[i]) / 2ll;
        }

        cout << ans << '\n';
    }


    return 0;
}