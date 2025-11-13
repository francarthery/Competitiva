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

ll expMod(ll b, ll e) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b;  // ret = mulMod(ret,b,m); //if needed
    b = b * b;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, k, l1, r1, l2, r2;
    cin >> t;
    while(t--){
        cin >> k >> l1 >> r1 >> l2 >> r2;

        int n = 0;
        ll sum = 0;
        while(1){
            ll kn = expMod(k, n);
            ll xl = (l2 + kn - 1) / kn, xr = r2 / kn; //cuidado redondeo

            if(xl > xr) break;

            if(r1 < xl){
                n++;
                continue;  
            }
            else if(l1 >= xl and l1 <= xr){
                sum += min(r1, xr) - l1 + 1;
            }
            else if(l1 <= xl and xl <= r1){
                sum += min(r1, xr) - xl + 1;
            }
            else break;

            n++;
        }

        cout << sum << '\n';

    }


    
    return 0;
}