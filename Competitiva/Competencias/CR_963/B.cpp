
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> v(n), pares, impares;
        forn(i, n) cin >> v[i];

        forn(i, n){
            if(v[i] % 2) impares.pb(v[i]);
            else pares.pb(v[i]);
        }
        if(impares.size() == 0 or pares.size() == 0) cout << 0 << '\n';
        else{
            sort(all(pares));
            sort(all(impares));
            ll maimp = impares.back(), rta = 0;

            forn(i, pares.size()){
                if(pares[i] < maimp){
                    rta++;
                    maimp += pares[i];
                }
                else{
                    rta += 2;
                    maimp += 2 * pares.back();
                    pares.pop_back();
                    i--;
                }
            }
            cout << rta << '\n';
        }

    }
    
    return 0;
}