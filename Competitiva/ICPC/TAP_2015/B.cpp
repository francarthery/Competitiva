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

    int n, k, val = 1;
    vector<ll> v;
    forn(i, 1e6 + 1) v.pb(val), val += 2;

    while(cin >> n >> k){
        ll l = 0, r = 1e12 + 1;

        while(r - l > 1){
            ll m = (l + r) / 2, cont = 0, rta = 0;
            forn(i, n){
                cont += v[i];
                if(cont >= m) rta++, cont = 0;
            }

            if(rta >= k) l = m;
            else r = m;
        }

        cout << l << '\n';  
    }


    
    return 0;
}